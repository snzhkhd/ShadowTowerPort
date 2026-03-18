#include "../PsyX_main.h"

#include "psx/libspu.h"
#include "psx/libetc.h"
#include "psx/libmath.h"
#include "PsyX_SPUAL.h"

#include <string.h>
#include <assert.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>

#include <cmath> //std::pow

#ifndef __EMSCRIPTEN__
#include <AL/efx.h>
#endif

// TODO: implement XA, implement ADSR

static const char* getALCErrorString(int err)
{
	switch (err)
	{
	case ALC_NO_ERROR:
		return "AL_NO_ERROR";
	case ALC_INVALID_DEVICE:
		return "ALC_INVALID_DEVICE";
	case ALC_INVALID_CONTEXT:
		return "ALC_INVALID_CONTEXT";
	case ALC_INVALID_ENUM:
		return "ALC_INVALID_ENUM";
	case ALC_INVALID_VALUE:
		return "ALC_INVALID_VALUE";
	case ALC_OUT_OF_MEMORY:
		return "ALC_OUT_OF_MEMORY";
	default:
		return "AL_UNKNOWN";
	}
}

static const char* getALErrorString(int err)
{
	switch (err)
	{
	case AL_NO_ERROR:
		return "AL_NO_ERROR";
	case AL_INVALID_NAME:
		return "AL_INVALID_NAME";
	case AL_INVALID_ENUM:
		return "AL_INVALID_ENUM";
	case AL_INVALID_VALUE:
		return "AL_INVALID_VALUE";
	case AL_INVALID_OPERATION:
		return "AL_INVALID_OPERATION";
	case AL_OUT_OF_MEMORY:
		return "AL_OUT_OF_MEMORY";
	default:
		return "AL_UNKNOWN";
	}
}

#define SPU_REALMEMSIZE			(512 * 1024)
#define SPU_MEMSIZE				SPU_REALMEMSIZE//(2048*1024)		// SPU_REALMEMSIZE

typedef struct
{
	u_char samplemem[SPU_MEMSIZE];
	u_char* writeptr;
} SPUMemory;

static SPUMemory s_SpuMemory;
static SDL_mutex* g_SpuMutex = NULL;
static int g_spuInit = 0;
static int s_spuMallocVal = 0;

typedef struct
{
	SpuVoiceAttr attr;	// .voice is Id of this channel

	ALuint alBuffer;
	ALuint alSource;
	ushort sampledirty;
	ushort reverb;

	uint32_t sampleSize;

	//ADSR
	AdsrSettings adsr_settings; // Переведенные в секунды тайминги
	AdsrState env_state;        // Текущая фаза (Attack, Decay и т.д.)
	float env_time;             // Время в секундах, прошедшее в текущей фазе
	float current_env_level;    // Текущий уровень громкости конверта (от 0.0 до 1.0)
} SPUALVoice;

const int s_spuVoiceCount = 24;

SPUALVoice	g_SpuVoices[s_spuVoiceCount];
ALCdevice*	g_ALCdevice = NULL;
ALCcontext* g_ALCcontext = NULL;
int			g_SPUMuted = 0;
ALuint		g_ALEffectSlots[2];
int			g_currEffectSlotIdx = 0;
ALuint		g_nAlReverbEffect = 0;
int			g_enableSPUReverb = 0;
int			g_ALEffectsSupported = 0;


void SetSpuSampleSize(int index, uint32_t  size)
{
	g_SpuVoices[index].sampleSize = size;
}

static bool SsPause = false;

void PsyX_SsSeqPlay()
{
	SsPause = false;
}

bool PsyX_SsIsPause()
{
	return SsPause;
}

void PsyX_SsSeqPause()
{
	for (int i = 0; i < 24; i++) 
	{
		SPUALVoice* voice = &g_SpuVoices[i];
		if (voice->alSource == AL_NONE) continue;

		alSourceStop(voice->alSource);
		/*ALint looping;
		alGetSourcei(voice->alSource, AL_LOOPING, &looping);
		if (looping == AL_TRUE) 
		{
			voice->env_state = ENV_STATE_RELEASE;
			voice->env_time = 0.0f;
			alSourcei(voice->alSource, AL_LOOPING, AL_FALSE);
		}*/
	}
	SsPause = true;
}
//--------------------------------------ADSR--------------------------------------
unsigned long RateTable[160];


void initADSR()
{
	// build the rate table according to Neill's rules
	memset(RateTable, 0, sizeof(unsigned long) * 160);

	uint32_t r = 3;
	uint32_t rs = 1;
	uint32_t rd = 0;

	// we start at pos 32 with the real values... everything before is 0
	for (int i = 32; i < 160; i++) {
		if (r < 0x3FFFFFFF) {
			r += rs;
			rd++;
			if (rd == 5) {
				rd = 1;
				rs *= 2;
			}
		}
		if (r > 0x3FFFFFFF)
			r = 0x3FFFFFFF;

		RateTable[i] = r;
	}
}
inline int roundToZero(int val) {
	if (val < 0)
		val = 0;
	return val;
}


double linearAmpDecayTimeToLinDBDecayTime(double secondsToFullAtten, double targetDb_LeastSquares = 70, double targetDb_InitialSlope = 140)
{
	if (secondsToFullAtten <= 0.0) return 0.0;

	const double ln10 = 2.302585092994046;
	const double k_short = targetDb_InitialSlope / (20.0 / ln10);
	const double k_long = targetDb_LeastSquares * ln10 / 45.0;

	// Knee near temporal integration (100–150 ms). p controls sharpness.
	const double T_knee = 0.12; // seconds
	const double p = 2.0;

	const double x = secondsToFullAtten / T_knee;
	const double w = 1.0 / (1.0 + std::pow(x, p)); // w≈1 for very short; →0 for long

	return secondsToFullAtten * (w * k_short + (1.0 - w) * k_long);
}

AdsrSettings MakeADSR(uint16_t ADSR1, uint16_t ADSR2)
{
	const int SPU_SAMPLE_RATE = 44100;

	uint8_t Am = (ADSR1 & 0x8000) >> 15;    // if 1, then Exponential, else linear
	uint8_t Ar = (ADSR1 & 0x7F00) >> 8;
	uint8_t Dr = (ADSR1 & 0x00F0) >> 4;
	uint8_t Sl = ADSR1 & 0x000F;
	uint8_t Rm = (ADSR2 & 0x0020) >> 5;
	uint8_t Rr = ADSR2 & 0x001F;

	// The following are unimplemented in conversion (because DLS and SF2 do not support Sustain Rate)
	uint8_t Sm = (ADSR2 & 0x8000) >> 15;
	uint8_t Sd = (ADSR2 & 0x4000) >> 14;
	uint8_t Sr = (ADSR2 >> 6) & 0x7F;


	if (((Am & ~0x01) != 0) ||
		((Ar & ~0x7F) != 0) ||
		((Dr & ~0x0F) != 0) ||
		((Sl & ~0x0F) != 0) ||
		((Rm & ~0x01) != 0) ||
		((Rr & ~0x1F) != 0) ||
		((Sm & ~0x01) != 0) ||
		((Sd & ~0x01) != 0) ||
		((Sr & ~0x7F) != 0)) {
		eprintf("PSX ADSR parameter(s) out of range"
			"({:#x}, {:#x}, {:#x}, {:#x}, {:#x}, {:#x}, {:#x}, {:#x}, {:#x})",
			Am, Ar, Dr, Sl, Rm, Rr, Sm, Sd, Sr);
		return AdsrSettings();
	}

	// int rateIncTable[8] = {0, 4, 6, 8, 9, 10, 11, 12};
	double samples{ 0 };
	int l;


	// to get the dls 32 bit time cents, take log base 2 of number of seconds * 1200 * 65536
	// (dls1v11a.pdf p25).

  //	if (RateTable[(Ar^0x7F)-0x10 + 32] == 0)
  //		realADSR->attack_time = 0;
  //	else
  //	{
	if ((Ar ^ 0x7F) < 0x10)
		Ar = 0;
	// if linear Ar Mode
	if (Am == 0) {
		uint32_t rate = RateTable[roundToZero((Ar ^ 0x7F) - 0x10) + 32];
		samples = ceil(0x7FFFFFFF / static_cast<double>(rate));
	}
	else if (Am == 1) {
		uint32_t rate = RateTable[roundToZero((Ar ^ 0x7F) - 0x10) + 32];
		samples = 0x60000000 / rate;
		uint32_t remainder = 0x60000000 % rate;
		rate = RateTable[roundToZero((Ar ^ 0x7F) - 0x18) + 32];
		samples += ceil(fmax(0, 0x1FFFFFFF - remainder) / static_cast<double>(rate));
	}


	AdsrSettings adsr;

	adsr.attack = samples / SPU_SAMPLE_RATE;
	//	}

	  // Decay Time

	long envelope_level = 0x7FFFFFFF;

	bool bSustainLevFound = false;
	uint32_t realSustainLevel{ 0 };
	// DLS decay rate value is to -96db (silence) not the sustain level
	for (l = 0; envelope_level > 0; l++) {
		if (4 * (Dr ^ 0x1F) < 0x18)
			Dr = 0;
		switch ((envelope_level >> 28) & 0x7) {
		case 0: envelope_level -= RateTable[roundToZero((4 * (Dr ^ 0x1F)) - 0x18 + 0) + 32]; break;
		case 1: envelope_level -= RateTable[roundToZero((4 * (Dr ^ 0x1F)) - 0x18 + 4) + 32]; break;
		case 2: envelope_level -= RateTable[roundToZero((4 * (Dr ^ 0x1F)) - 0x18 + 6) + 32]; break;
		case 3: envelope_level -= RateTable[roundToZero((4 * (Dr ^ 0x1F)) - 0x18 + 8) + 32]; break;
		case 4: envelope_level -= RateTable[roundToZero((4 * (Dr ^ 0x1F)) - 0x18 + 9) + 32]; break;
		case 5: envelope_level -= RateTable[roundToZero((4 * (Dr ^ 0x1F)) - 0x18 + 10) + 32]; break;
		case 6: envelope_level -= RateTable[roundToZero((4 * (Dr ^ 0x1F)) - 0x18 + 11) + 32]; break;
		case 7: envelope_level -= RateTable[roundToZero((4 * (Dr ^ 0x1F)) - 0x18 + 12) + 32]; break;
		default: break;
		}
		if (!bSustainLevFound && ((envelope_level >> 27) & 0xF) <= Sl) {
			realSustainLevel = envelope_level;
			bSustainLevFound = true;
		}
	}
	samples = l;
	adsr.decay = samples / SPU_SAMPLE_RATE;

	// Sustain Rate

	envelope_level = 0x7FFFFFFF;
	// increasing... we won't even bother
	if (Sd == 0) {
		adsr.sustain = -1;
	}
	else {
		if (Sr == 0x7F)
			adsr.sustain = -1;        // this is actually infinite
		else {
			// linear
			if (Sm == 0) {
				uint32_t rate = RateTable[roundToZero((Sr ^ 0x7F) - 0x0F) + 32];
				samples = ceil(0x7FFFFFFF / static_cast<double>(rate));
			}
			else {
				l = 0;
				// DLS decay rate value is to -96db (silence) not the sustain level
				while (envelope_level > 0) {
					long envelope_level_diff{ 0 };
					long envelope_level_target{ 0 };

					switch ((envelope_level >> 28) & 0x7) {
					case 0: envelope_level_target = 0x00000000; envelope_level_diff = RateTable[roundToZero((Sr ^ 0x7F) - 0x1B + 0) + 32]; break;
					case 1: envelope_level_target = 0x0fffffff; envelope_level_diff = RateTable[roundToZero((Sr ^ 0x7F) - 0x1B + 4) + 32]; break;
					case 2: envelope_level_target = 0x1fffffff; envelope_level_diff = RateTable[roundToZero((Sr ^ 0x7F) - 0x1B + 6) + 32]; break;
					case 3: envelope_level_target = 0x2fffffff; envelope_level_diff = RateTable[roundToZero((Sr ^ 0x7F) - 0x1B + 8) + 32]; break;
					case 4: envelope_level_target = 0x3fffffff; envelope_level_diff = RateTable[roundToZero((Sr ^ 0x7F) - 0x1B + 9) + 32]; break;
					case 5: envelope_level_target = 0x4fffffff; envelope_level_diff = RateTable[roundToZero((Sr ^ 0x7F) - 0x1B + 10) + 32]; break;
					case 6: envelope_level_target = 0x5fffffff; envelope_level_diff = RateTable[roundToZero((Sr ^ 0x7F) - 0x1B + 11) + 32]; break;
					case 7: envelope_level_target = 0x6fffffff; envelope_level_diff = RateTable[roundToZero((Sr ^ 0x7F) - 0x1B + 12) + 32]; break;
					default: break;
					}

					long steps = (envelope_level - envelope_level_target + (envelope_level_diff - 1)) / envelope_level_diff;
					envelope_level -= (envelope_level_diff * steps);
					l += steps;
				}
				samples = l;
			}
			double timeInSecs = samples / SPU_SAMPLE_RATE;
			adsr.sustain = timeInSecs;// /*Sm ? timeInSecs : */linearAmpDecayTimeToLinDBDecayTime(timeInSecs);
		}
	}

	// Sustain Level
	//realADSR->sustain_level = (double)envelope_level/(double)0x7FFFFFFF;//(long)ceil((double)envelope_level * 0.030517578139210854);	//in DLS, sustain level is measured as a percentage
	if (Sl == 0)
		realSustainLevel = 0x07FFFFFF;
	adsr.sustain = realSustainLevel / static_cast<double>(0x7FFFFFFF);

	// If decay is going unused, and there's a sustain rate with sustain level close to max...
	//  we'll put the sustain_rate in place of the decay rate.
	if ((adsr.decay < 2 || (Dr >= 0x0E && Sl >= 0x0C)) && Sr < 0x7E && Sd == 1) {
		adsr.sustain = 0;
		adsr.decay = adsr.sustain;
		//realADSR->decay_time = 0.5;
	}

	// Release Time

	//sustain_envelope_level = envelope_level;

	// We do this because we measure release time from max volume to 0, not from sustain level to 0
	envelope_level = 0x7FFFFFFF;

	// if linear Rr Mode
	if (Rm == 0) {
		uint32_t rate = RateTable[roundToZero((4 * (Rr ^ 0x1F)) - 0x0C) + 32];

		if (rate != 0)
			samples = ceil(static_cast<double>(envelope_level) / rate);
		else
			samples = 0;
	}
	else if (Rm == 1) {
		if ((Rr ^ 0x1F) * 4 < 0x18)
			Rr = 0;
		for (l = 0; envelope_level > 0; l++) {
			switch ((envelope_level >> 28) & 0x7) {
			case 0: envelope_level -= RateTable[roundToZero((4 * (Rr ^ 0x1F)) - 0x18 + 0) + 32]; break;
			case 1: envelope_level -= RateTable[roundToZero((4 * (Rr ^ 0x1F)) - 0x18 + 4) + 32]; break;
			case 2: envelope_level -= RateTable[roundToZero((4 * (Rr ^ 0x1F)) - 0x18 + 6) + 32]; break;
			case 3: envelope_level -= RateTable[roundToZero((4 * (Rr ^ 0x1F)) - 0x18 + 8) + 32]; break;
			case 4: envelope_level -= RateTable[roundToZero((4 * (Rr ^ 0x1F)) - 0x18 + 9) + 32]; break;
			case 5: envelope_level -= RateTable[roundToZero((4 * (Rr ^ 0x1F)) - 0x18 + 10) + 32]; break;
			case 6: envelope_level -= RateTable[roundToZero((4 * (Rr ^ 0x1F)) - 0x18 + 11) + 32]; break;
			case 7: envelope_level -= RateTable[roundToZero((4 * (Rr ^ 0x1F)) - 0x18 + 12) + 32]; break;
			default: break;
			}
		}
		samples = l;
	}
	double timeInSecs = samples / SPU_SAMPLE_RATE;

	//theRate = timeInSecs / sustain_envelope_level;
	//timeInSecs = 0x7FFFFFFF * theRate;	//the release time value is more like a rate.  It is the time from max value to 0, not from sustain level.
	//if (Rm == 0) // if it's linear
	//	timeInSecs *=  LINEAR_RELEASE_COMPENSATION;

	adsr.release = timeInSecs;	// /*Rm ? timeInSecs : */linearAmpDecayTimeToLinDBDecayTime(timeInSecs);


	return adsr;
}

void PsyX_Update_ADSR_Voice(SPUALVoice* voice, float deltaTime)
{
	if (voice->alSource == AL_NONE || voice->env_state == ENV_STATE_OFF)
		return;

	voice->env_time += deltaTime;
	AdsrSettings* adsr = &voice->adsr_settings;

	switch (voice->env_state)
	{
	case ENV_STATE_ATTACK:
		if (adsr->attack <= 0.0f) {
			voice->current_env_level = 1.0f;
			voice->env_state = ENV_STATE_DECAY;
			voice->env_time = 0.0f;
		}
		else {
			voice->current_env_level = voice->env_time / adsr->attack;
			if (voice->env_time >= adsr->attack) {
				voice->current_env_level = 1.0f;
				voice->env_state = ENV_STATE_DECAY;
				voice->env_time = 0.0f;
			}
		}
		break;
	case ENV_STATE_DECAY:
		if (adsr->decay <= 0.0f) {
			voice->current_env_level = adsr->sustain;
			voice->env_state = ENV_STATE_SUSTAIN;
			voice->env_time = 0.0f;
		}
		else {
			float progress = voice->env_time / adsr->decay;
			voice->current_env_level = 1.0f - (progress * (1.0f - adsr->sustain));
			if (voice->env_time >= adsr->decay) {
				voice->current_env_level = adsr->sustain;
				voice->env_state = ENV_STATE_SUSTAIN;
				voice->env_time = 0.0f;
			}
		}
		break;
	case ENV_STATE_SUSTAIN:
		voice->current_env_level = adsr->sustain;
		break;
	case ENV_STATE_RELEASE:
		if (adsr->release <= 0.0f) {
			voice->current_env_level = 0.0f;
			voice->env_state = ENV_STATE_OFF;
			alSourceStop(voice->alSource);
		}
		else {
			float progress = voice->env_time / adsr->release;
			voice->current_env_level = adsr->sustain * (1.0f - progress);
			if (voice->env_time >= adsr->release) {
				voice->current_env_level = 0.0f;
				voice->env_state = ENV_STATE_OFF;
				alSourceStop(voice->alSource);
			}
		}
		break;
	}
}

void PsyX_Update_ADSR(float deltaTime)
{
	if (!g_spuInit) return;
	SDL_LockMutex(g_SpuMutex);
	for (int i = 0; i < s_spuVoiceCount; i++)
	{
		SPUALVoice* voice = &g_SpuVoices[i];
		PsyX_Update_ADSR_Voice(voice, deltaTime);

		// Apply volume
		if (voice->alSource != AL_NONE && voice->env_state != ENV_STATE_OFF) {
			float left_gain = (float)(voice->attr.volume.left) / 16384.0f;
			float right_gain = (float)(voice->attr.volume.right) / 16384.0f;
			if (left_gain > 1.0f) left_gain = 1.0f;
			if (right_gain > 1.0f) right_gain = 1.0f;
			float base_vol = (left_gain + right_gain) * 0.5f;
			alSourcef(voice->alSource, AL_GAIN, base_vol * voice->current_env_level);
		}
	}
	SDL_UnlockMutex(g_SpuMutex);
}
//----------------------------------------------------------------------------
#ifndef __EMSCRIPTEN__

LPALGENEFFECTS alGenEffects = NULL;
LPALDELETEEFFECTS alDeleteEffects = NULL;
LPALEFFECTI alEffecti = NULL;
LPALEFFECTF alEffectf = NULL;
LPALGENAUXILIARYEFFECTSLOTS alGenAuxiliaryEffectSlots = NULL;
LPALDELETEAUXILIARYEFFECTSLOTS alDeleteAuxiliaryEffectSlots = NULL;
LPALAUXILIARYEFFECTSLOTI alAuxiliaryEffectSloti = NULL;

#endif // __EMSCRIPTEN__

uint8_t* PsyX_SPUAL_GetMemory() { return s_SpuMemory.samplemem; }

static void InitOpenAlEffects()
{
	g_ALEffectsSupported = 0;
#ifndef __EMSCRIPTEN__
	if (!alcIsExtensionPresent(g_ALCdevice, ALC_EXT_EFX_NAME))
	{
		eprintf("PSX SPU effects are NOT supported!\n");
		return;
	}

	alGenEffects = (LPALGENEFFECTS)alGetProcAddress("alGenEffects");
	alDeleteEffects = (LPALDELETEEFFECTS)alGetProcAddress("alDeleteEffects");
	alEffecti = (LPALEFFECTI)alGetProcAddress("alEffecti");
	alEffectf = (LPALEFFECTF)alGetProcAddress("alEffectf");
	alGenAuxiliaryEffectSlots = (LPALGENAUXILIARYEFFECTSLOTS)alGetProcAddress("alGenAuxiliaryEffectSlots");
	alDeleteAuxiliaryEffectSlots = (LPALDELETEAUXILIARYEFFECTSLOTS)alGetProcAddress("alDeleteAuxiliaryEffectSlots");
	alAuxiliaryEffectSloti = (LPALAUXILIARYEFFECTSLOTI)alGetProcAddress("alAuxiliaryEffectSloti");

	int max_sends = 0;
	alcGetIntegerv(g_ALCdevice, ALC_MAX_AUXILIARY_SENDS, 1, &max_sends);

	// make reverb effect slot
	g_currEffectSlotIdx = 0;
	alGenAuxiliaryEffectSlots(1, g_ALEffectSlots);

	// make reverb effect
	alGenEffects(1, &g_nAlReverbEffect);
	alEffecti(g_nAlReverbEffect, AL_EFFECT_TYPE, AL_EFFECT_REVERB);

	// setup defaults of effect
	alEffectf(g_nAlReverbEffect, AL_REVERB_GAIN, 0.45f);
	alEffectf(g_nAlReverbEffect, AL_REVERB_GAINHF, 0.25f);
	alEffectf(g_nAlReverbEffect, AL_REVERB_DECAY_TIME, 2.0f);
	alEffectf(g_nAlReverbEffect, AL_REVERB_DECAY_HFRATIO, 0.9f);
	alEffectf(g_nAlReverbEffect, AL_REVERB_REFLECTIONS_DELAY, 0.08f);
	alEffectf(g_nAlReverbEffect, AL_REVERB_REFLECTIONS_GAIN, 0.2f);
	alEffectf(g_nAlReverbEffect, AL_REVERB_DIFFUSION, 0.9f);
	alEffectf(g_nAlReverbEffect, AL_REVERB_DENSITY, 0.1f);
	alEffectf(g_nAlReverbEffect, AL_REVERB_AIR_ABSORPTION_GAINHF, 0.1f);

	g_ALEffectsSupported = 1;

	eprintf("PSX SPU effects are supported and initialized\n");

	alAuxiliaryEffectSloti(g_ALEffectSlots[g_currEffectSlotIdx], AL_EFFECTSLOT_EFFECT, g_nAlReverbEffect);
#endif // __EMSCRIPTEN__
}

int PsyX_SPUAL_InitSound()
{
	if (!g_SpuMutex)
		g_SpuMutex = SDL_CreateMutex();

	if (!g_spuInit)
		memset(&s_SpuMemory, 0, sizeof(s_SpuMemory));

	g_spuInit = 1;

	int numDevices, alErr, i;
	const char* devices;
	const char* devStrptr;

	// out_channel_formats snd_outputchannels
	static int al_context_params[] =
	{
		ALC_FREQUENCY, 44100,
#ifndef __EMSCRIPTEN__
		ALC_MAX_AUXILIARY_SENDS, 2,
#endif
		0
	};

	if (g_ALCdevice)
		return 1;

	numDevices = 0;

	// Init openAL
	// check devices list

	devStrptr = alcGetString(NULL, ALC_DEVICE_SPECIFIER);
	devices = devStrptr;

	// go through device list (each device terminated with a single NULL, list terminated with double NULL)
	while ((*devStrptr) != '\0')
	{
		eprintinfo("found sound device: %s\n", devStrptr);
		devStrptr += strlen(devStrptr) + 1;
		numDevices++;
	}

	if(numDevices == 0)
		return 0;
	
	g_ALCdevice = alcOpenDevice(NULL);

	alErr = AL_NO_ERROR;

	if (!g_ALCdevice)
	{
		alErr = alcGetError(NULL);
		eprinterr("alcOpenDevice: NULL DEVICE error: %s\n", getALCErrorString(alErr));
		return 0;
	}

#ifndef __EMSCRIPTEN__
	g_ALCcontext = alcCreateContext(g_ALCdevice, al_context_params);
#else
	g_ALCcontext = alcCreateContext(g_ALCdevice, NULL);
#endif

	alErr = alcGetError(g_ALCdevice);
	if (alErr != AL_NO_ERROR)
	{
		eprinterr("alcCreateContext error: %s\n", getALCErrorString(alErr));
		return 0;
	}

	alcMakeContextCurrent(g_ALCcontext);

	alErr = alcGetError(g_ALCdevice);
	if (alErr != AL_NO_ERROR)
	{
		eprinterr("alcMakeContextCurrent error: %s\n", getALCErrorString(alErr));
		return 0;
	}

	// Setup defaults
	alListenerf(AL_GAIN, 1.0f);
	alDistanceModel(AL_NONE);

	// create channels
	for (i = 0; i < s_spuVoiceCount; i++)
	{
		SPUALVoice* voice = &g_SpuVoices[i];
		memset(voice, 0, sizeof(SPUALVoice));

		alGenSources(1, &voice->alSource);
		alGenBuffers(1, &voice->alBuffer);
#ifdef AL_SOFT_source_resampler
		alSourcei(voice->alSource, AL_SOURCE_RESAMPLER_SOFT, 2);	// Use cubic resampler
#endif
		alSourcei(voice->alSource, AL_SOURCE_RELATIVE, AL_TRUE);
	}


	InitOpenAlEffects();

	initADSR();

	return 1;
}

void PsyX_SPUAL_ShutdownSound()
{
	g_spuInit = 0;

#ifndef __EMSCRIPTEN__
	if (!g_ALCcontext)
		return;

	for (int i = 0; i < s_spuVoiceCount; i++)
	{
		SPUALVoice* voice = &g_SpuVoices[i];
		alDeleteSources(1, &voice->alSource);
		alDeleteBuffers(1, &voice->alBuffer);
	}

	if (g_ALEffectsSupported)
	{
		alDeleteEffects(1, &g_nAlReverbEffect);
		g_ALEffectsSupported = AL_NONE;
		alDeleteAuxiliaryEffectSlots(1, g_ALEffectSlots);
	}

	alcDestroyContext(g_ALCcontext);
	alcCloseDevice(g_ALCdevice);

	g_ALCcontext = NULL;
	g_ALCdevice = NULL;
#endif // __EMSCRIPTEN__
}

//--------------------------------------------------------------------------------

int PsyX_SPUAL_Alloc(int size)
{
	int addr = s_spuMallocVal;
	s_spuMallocVal += size;

	if (s_spuMallocVal > SPU_MEMSIZE)
		return -1;

	return addr;
}

int PsyX_SPUAL_InitAlloc(int num, char* top)
{
	s_spuMallocVal = 0x1010;
	return 0;
}

void PsyX_SPUAL_Free(u_int addr)
{
	s_spuMallocVal = 0;
}

u_int PsyX_SPUAL_SetTransferStartAddr(u_int addr)
{
	s_SpuMemory.writeptr = s_SpuMemory.samplemem + addr;

	if (addr > SPU_MEMSIZE)
		return 0;

	if (addr < 0x1010)
		return 0;

	return 1;
}

u_int PsyX_SPUAL_Write(u_char* addr, u_int size)
{
	volatile int wptr_ofs = s_SpuMemory.writeptr - s_SpuMemory.samplemem;

	if (wptr_ofs + size > SPU_REALMEMSIZE)
	{
		eprintf("SPU WARNING: SpuWrite exceeded SPU_REALMEMSIZE by %d bytes!\n",
			wptr_ofs + size - SPU_REALMEMSIZE);
	}
	assert(size > 0 && wptr_ofs + size < SPU_MEMSIZE);
	memcpy(s_SpuMemory.writeptr, addr, size);

	return size;
}

u_int PsyX_SPUAL_Read(u_char* addr, u_int size)
{
	volatile int rptr_ofs = s_SpuMemory.writeptr - s_SpuMemory.samplemem;

	if (rptr_ofs + size > SPU_REALMEMSIZE)
	{
		eprintf("SPU WARNING: SpuRead exceeded SPU_REALMEMSIZE by %d bytes!\n", rptr_ofs + size - SPU_REALMEMSIZE);
	}
	assert(size > 0 && rptr_ofs + size < SPU_MEMSIZE);

	// simply copy to the writeptr
	memcpy(addr, s_SpuMemory.writeptr, size);

	return size;
}

// PSX ADPCM coefficients
static const float K0[5] = { 0, 0.9375, 1.796875, 1.53125, 1.90625 };
static const float K1[5] = { 0, 0, -0.8125, -0.859375, -0.9375 };

// PSX ADPCM decoding routine - decodes a single sample
static short vagToPcm(u_char soundParameter, int soundData, float* vagPrev1, float* vagPrev2)
{
	int resultInt = 0;

	float dTmp1 = 0.0;
	float dTmp2 = 0.0;
	float dTmp3 = 0.0;

	if (soundData > 7)
		soundData -= 16;

	dTmp1 = (float)soundData * pow(2, (float)(12 - (soundParameter & 0x0F)));

	dTmp2 = (*vagPrev1) * K0[(soundParameter >> 4) & 0x0F];
	dTmp3 = (*vagPrev2) * K1[(soundParameter >> 4) & 0x0F];

	(*vagPrev2) = (*vagPrev1);
	(*vagPrev1) = dTmp1 + dTmp2 + dTmp3;

	resultInt = (int)round((*vagPrev1));

	if (resultInt > 32767)
		resultInt = 32767;

	if (resultInt < -32768)
		resultInt = -32768;

	return (short)resultInt;
}

typedef enum 
{
	LoopEnd = 1 << 0,		// Jump to repeat address after this block
							// 1 - Copy repeatAddress to currentAddress AFTER this block
							//     set ENDX (TODO: Immediately or after this block?)
							// 0 - Nothing

	Repeat = 1 << 1,		// Takes an effect only with LoopEnd bit set.
							// 1 - Loop normally
							// 0 - Loop and force Release

	LoopStart = 1 << 2,		// Mark current address as the beginning of repeat
							// 1 - Load currentAddress to repeatAddress
							// 0 - Nothing
} ADPCM_FLAGS;


 //Main decoding routine - Takes PSX ADPCM formatted audio data and converts it to PCM. It also extracts the looping information if used.
//static int decodeSound(u_char* iData, int soundSize, short* oData, int* loopStart, int* loopLength, int breakOnEnd /*= 0*/)
//{
//	u_char sp;
//	u_char flag;
//	int sd = 0;
//	float vagPrev1 = 0.0;
//	float vagPrev2 = 0.0;
//	int k = 0;
//
//	int loopStrt = 0, loopEnd = 0;
//	int breakOn = -1;
//
//	for (int i = 0; i < soundSize; i++)
//	{
//		if (i % 16 == 0)
//		{
//			sp = iData[i];
//			flag = iData[i+1];
//			i += 2;
//		}
//
//		sd = (int)iData[i] & 0xF;
//		oData[k++] = vagToPcm(sp, sd, &vagPrev1, &vagPrev2);
//
//		sd = ((int)iData[i] >> 4) & 0xF;
//		oData[k++] = vagToPcm(sp, sd, &vagPrev1, &vagPrev2);
//
//		if (breakOnEnd && k == breakOn)
//			return k;
//
//		if (breakOn == -1)
//		{
//			// flags parsed
//			if (flag & LoopStart)
//			{
//				loopStrt = k + 26; // FIXME: is that correct?
//			}
//
//			if (flag & LoopEnd)
//			{
//				loopEnd = k + 26;
//
//				if (flag & Repeat)
//				{
//					*loopStart = loopStrt;
//					*loopLength = loopEnd - loopStrt;
//				}
//
//				if (breakOnEnd)
//					breakOn = k + 26;
//			}
//		}
//	}
//
//	return soundSize;
//}


static int decodeSound(u_char* iData, int soundSize, short* oData, int* loopStart, int* loopLength, int breakOnEnd)
{
	double s_1 = 0.0;
	double s_2 = 0.0;
	int k = 0;
	int loopStrt = 0;

	for (int i = 0; i < soundSize; i += 16)
	{
		if (i + 16 > soundSize) break;

		int shift = iData[i] & 0x0F;
		int filter = (iData[i] >> 4) & 0x0F;
		u_char flag = iData[i + 1];

		if (filter >= 5) filter = 0;

		if (flag & LoopStart)
			loopStrt = k;

		for (int j = 2; j < 16; j++)
		{
			u_char byte = iData[i + j];

			for (int n = 0; n < 2; n++)
			{
				int8_t nibble = (n == 0) ? (byte & 0x0F) : (byte >> 4);
				if (nibble & 0x08) nibble |= 0xF0;

				double sample = (double)((int)nibble << (12 - (shift > 12 ? 12 : shift)));
				if (shift > 12)
					sample /= (double)(1 << (shift - 12));

				double output = sample + s_1 * K0[filter] + s_2 * K1[filter];
				s_2 = s_1;
				s_1 = output;

				int result = (int)output;
				if (result > 32767) result = 32767;
				if (result < -32768) result = -32768;
				oData[k++] = (short)result;
			}
		}

		if (breakOnEnd && (flag & LoopEnd))
		{
			if (flag & Repeat)
			{
				*loopStart = loopStrt;
				*loopLength = k - loopStrt;
			}
			break;
		}
	}
	return k;
}

static void UpdateVoiceSample(SPUALVoice* voice)
{



	static short waveBuffer[SPU_REALMEMSIZE];
	int loopStart, loopLen, count;
	ALuint alSource, alBuffer;

	if (!voice->sampledirty) 
		return;


	voice->sampledirty = 0;

	alSource = voice->alSource;
	alBuffer = voice->alBuffer;

	if (alSource == AL_NONE)
		return;

	loopStart = 0;
	loopLen = 0;

	int voiceIdx = (int)(voice - g_SpuVoices);
	//int maxSize = SPU_MEMSIZE - voice->attr.addr;
	int maxSize = voice->sampleSize;
	if (maxSize <= 0 || maxSize > (int)(SPU_MEMSIZE - voice->attr.addr))
		maxSize = SPU_MEMSIZE - voice->attr.addr;

	count = decodeSound(s_SpuMemory.samplemem + voice->attr.addr, maxSize, waveBuffer, &loopStart, &loopLen, 1);

	uint32_t addr = voice->attr.addr;

	if (count == 0)
		return;


	alSourcei(alSource, AL_BUFFER, 0);
	alBufferData(alBuffer, AL_FORMAT_MONO16, waveBuffer, count * sizeof(short), 44100);

	if (loopLen > 0)
	{
		// Не корректируем по loop_addr — декодер уже дал правильные позиции
		if (loopStart >= 0 && loopStart + loopLen <= count)
		{
			int sampleOffs[] = { loopStart, loopStart + loopLen };
			alBufferiv(alBuffer, AL_LOOP_POINTS_SOFT, sampleOffs);
			alSourcei(alSource, AL_LOOPING, AL_TRUE);
		}
		else
		{
			// Loop points невалидные — не лупим
			alSourcei(alSource, AL_LOOPING, AL_FALSE);
		}
	}
	else
	{

		alSourcei(alSource, AL_LOOPING, AL_FALSE);
	}

	// set the buffer
	alSourcei(alSource, AL_BUFFER, alBuffer);
}

int PsyX_SPUAL_SetMute(int on_off)
{
	int old_state = g_SPUMuted;
	g_SPUMuted = on_off;
	return old_state;
}

void PsyX_SPUAL_GetVoiceVolume(int vNum, short* volL, short* volR)
{
	if (volL)
		*volL = g_SpuVoices[vNum].attr.volume.left;

	if (volR)
		*volR = g_SpuVoices[vNum].attr.volume.right;
}

void PsyX_SPUAL_GetVoicePitch(int vNum, u_short* pitch)
{
	*pitch = g_SpuVoices[vNum].attr.pitch;
}

void PsyX_SPUAL_SetVoiceAttr(SpuVoiceAttr* psxAttrib)
{
	if (!g_spuInit)
		return;

	const float STEREO_FACTOR = 3.0f;
	
	SDL_LockMutex(g_SpuMutex);

	for (int i = 0; i < s_spuVoiceCount; i++)
	{
		if ((psxAttrib->voice & SPU_VOICECH(i)) == 0)
			continue;

		SPUALVoice* voice = &g_SpuVoices[i];
		ALuint alSource = voice->alSource;

		if (alSource == AL_NONE)
			continue;
		
		// update sample
		if ((psxAttrib->mask & SPU_VOICE_WDSA) || (psxAttrib->mask & SPU_VOICE_LSAX))
		{
			if (psxAttrib->mask & SPU_VOICE_WDSA)
			{
				if (voice->attr.addr != psxAttrib->addr)
					voice->sampledirty++;

				voice->attr.addr = psxAttrib->addr;
			}
			
			if (psxAttrib->mask & SPU_VOICE_LSAX)
			{
				if(voice->attr.loop_addr != psxAttrib->loop_addr)
					voice->sampledirty++;

				voice->attr.loop_addr = psxAttrib->loop_addr;
			}			
		}

		// update volume
		if ((psxAttrib->mask & SPU_VOICE_VOLL) || (psxAttrib->mask & SPU_VOICE_VOLR))
		{
			if (psxAttrib->mask & SPU_VOICE_VOLL)
				voice->attr.volume.left = psxAttrib->volume.left;

			if (psxAttrib->mask & SPU_VOICE_VOLR)
				voice->attr.volume.right = psxAttrib->volume.right;

			float left_gain = (float)(voice->attr.volume.left) / (float)(16384);
			float right_gain = (float)(voice->attr.volume.right) / (float)(16384);

			if(left_gain > 1.0f)
				left_gain = 1.0f;

			if(right_gain > 1.0f)
				right_gain = 1.0f;

			float pan = (acosf(left_gain) + asinf(right_gain)) / ((float)(M_PI)); // average angle in [0,1]
			pan = 2.0f * pan - 1.0f; // convert to [-1, 1]
			pan = pan * 0.5f; // 0.5 = sin(30') for a +/- 30 degree arc
			alSource3f(alSource, AL_POSITION, pan * STEREO_FACTOR, 0, -sqrtf(1.0f - pan * pan));
			alSourcef(alSource, AL_GAIN, (left_gain+right_gain)*0.5f);
		}

		// update pitch
		if (psxAttrib->mask & SPU_VOICE_PITCH)
		{
			ALint state;
			alGetSourcei(alSource, AL_SOURCE_STATE, &state);

			if (psxAttrib->pitch == 0 && state == AL_PLAYING)
				alSourcePause(alSource);
			else if (voice->attr.pitch == 0 && state == AL_PAUSED)
				alSourcePlay(alSource);

			voice->attr.pitch = psxAttrib->pitch;

			const float pitch = (float)(voice->attr.pitch) / 4096.0f;
			alSourcef(alSource, AL_PITCH, pitch);

		}
		
		// ADSR 
		if (psxAttrib->mask & (SPU_VOICE_ADSR_AMODE | SPU_VOICE_ADSR_AR |
			SPU_VOICE_ADSR_DR | SPU_VOICE_ADSR_SR | SPU_VOICE_ADSR_RR |
			SPU_VOICE_ADSR_SL | SPU_VOICE_ADSR_ADSR1 | SPU_VOICE_ADSR_ADSR2))
		{
			// Обновляем сырые значения
			voice->attr.adsr1 = psxAttrib->adsr1;
			voice->attr.adsr2 = psxAttrib->adsr2;


			voice->adsr_settings = MakeADSR(voice->attr.adsr1, voice->attr.adsr2);
		}
		/*else
		{
			printf("ADSR skip v=%d adsr1=%04X adsr2=%04X, mask=%04X\n", i, voice->attr.adsr1, voice->attr.adsr2, psxAttrib->mask);
		}*/
	}
	SDL_UnlockMutex(g_SpuMutex);
}

void PsyX_SPUAL_SetKey(int on_off, u_int voice_bit)
{
	if (!g_spuInit)
		return;

	SDL_LockMutex(g_SpuMutex);
	for (int i = 0; i < s_spuVoiceCount; i++)
	{
		if ((voice_bit & SPU_VOICECH(i)) == 0)
			continue;

		SPUALVoice* voice = &g_SpuVoices[i];
		ALuint alSource = voice->alSource;

		if (alSource == AL_NONE)
			continue;

		if (on_off && !g_SPUMuted) // Key On
		{
			//if (voice->attr.addr == 0x25090 || voice->attr.addr == 0x3BD50) {
			//	printf("[PROBLEM KeyOn] voice=%d addr=%08X pitch=%04X\n",
			//		i, voice->attr.addr, voice->attr.pitch);
			//	printf("  Other active voices with same addr: ");
			//	for (int j = 0; j < s_spuVoiceCount; j++) {
			//		if (j == i) continue;
			//		SPUALVoice* other = &g_SpuVoices[j];
			//		if (other->alSource == AL_NONE) continue;
			//		ALint state;
			//		alGetSourcei(other->alSource, AL_SOURCE_STATE, &state);
			//		if (other->attr.addr == voice->attr.addr && state == AL_PLAYING) {
			//			printf("v%d(pitch=%04X env=%d) ", j, other->attr.pitch,
			//				other->env_state);
			//		}
			//	}
			//	printf("\n");
			//}

			alSourceStop(alSource);
			UpdateVoiceSample(voice);

			voice->env_state = ENV_STATE_ATTACK;
			voice->env_time = 0.0f;
			voice->current_env_level = 0.0f;

			// Сразу прогоняем attack до слышимого уровня
			float step = 0.001f;
			for (int j = 0; j < 20; j++) {
				PsyX_Update_ADSR_Voice(voice, step);
				if (voice->current_env_level >= 0.9f)
					break;
			}

			// Применяем громкость ДО play
			float left_gain = (float)(voice->attr.volume.left) / 16384.0f;
			float right_gain = (float)(voice->attr.volume.right) / 16384.0f;
			if (left_gain > 1.0f) left_gain = 1.0f;
			if (right_gain > 1.0f) right_gain = 1.0f;
			float base_vol = (left_gain + right_gain) * 0.5f;
			alSourcef(alSource, AL_GAIN, base_vol * voice->current_env_level);

			alSourcePlay(alSource);
		}
		else // Key Off
		{
			uint16_t addr = voice->attr.addr / 8;
			if (addr == 0x25090 || addr == 0x3BD50) {
				printf("[PROBLEM KeyOff] voice=%d addr=%08X\n", i, addr);
			}
			// Release
			if (voice->env_state != ENV_STATE_OFF)
			{
				voice->env_state = ENV_STATE_RELEASE;
				voice->env_time = 0.0f;

				alSourcei(alSource, AL_LOOPING, AL_FALSE);
			}
		}
	}
	SDL_UnlockMutex(g_SpuMutex);
}

int PsyX_SPUAL_GetKeyStatus(u_int voice_bit)
{
	int state = AL_STOPPED;
	SDL_LockMutex(g_SpuMutex);

	for (int i = 0; i < s_spuVoiceCount; i++)
	{
		if (voice_bit != SPU_VOICECH(i))
			continue;

		SPUALVoice* voice = &g_SpuVoices[i];
		ALuint alSource = voice->alSource;

		if (alSource == AL_NONE)
			break; // SpuOff?

		alGetSourcei(alSource, AL_SOURCE_STATE, &state);
		break;
	}

	SDL_UnlockMutex(g_SpuMutex);

	return (state == AL_PLAYING);	// simple as this?
}

void PsyX_SPUAL_GetAllKeysStatus(char* status)
{
	SDL_LockMutex(g_SpuMutex);
	for (int i = 0; i < s_spuVoiceCount; i++)
	{
		SPUALVoice* voice = &g_SpuVoices[i];
		ALuint alSource = voice->alSource;
		if (alSource == AL_NONE)
		{
			status[i] = 0; // SpuOff?
			continue;
		}

		int state;
		alGetSourcei(alSource, AL_SOURCE_STATE, &state);
		status[i] = (state == AL_PLAYING);
	}
	SDL_UnlockMutex(g_SpuMutex);
}

int PsyX_SPUAL_SetReverb(int on_off)
{
	int old_state = g_enableSPUReverb;
	g_enableSPUReverb = on_off;

	if (!g_spuInit)
		return old_state;
#ifndef __EMSCRIPTEN__
	// switch if needed
	if (g_ALEffectsSupported && old_state != g_enableSPUReverb)
	{
		if (g_enableSPUReverb)
		{
			alAuxiliaryEffectSloti(g_ALEffectSlots[g_currEffectSlotIdx], AL_EFFECTSLOT_EFFECT, g_nAlReverbEffect);
		}
		else
		{
			g_currEffectSlotIdx = 0;
			alAuxiliaryEffectSloti(g_ALEffectSlots[0], AL_EFFECTSLOT_EFFECT, AL_EFFECT_NULL);
			alAuxiliaryEffectSloti(g_ALEffectSlots[1], AL_EFFECTSLOT_EFFECT, AL_EFFECT_NULL);
		}
	}
#endif // __EMSCRIPTEN__
	return old_state;
}

int PsyX_SPUAL_GetReverbState()
{
	return g_enableSPUReverb;
}

u_int PsyX_SPUAL_SetReverbVoice(int on_off, u_int voice_bit)
{
	if (!g_spuInit)
		return 0;

	if (!g_ALEffectsSupported)
		return 0;

	SDL_LockMutex(g_SpuMutex);

	for (int i = 0; i < s_spuVoiceCount; i++)
	{
		if ((voice_bit & SPU_VOICECH(i)) == 0)
			continue;

		SPUALVoice* voice = &g_SpuVoices[i];
		ALuint alSource = voice->alSource;
		if (alSource == AL_NONE)
			continue;

		voice->reverb = on_off > 0;
#ifndef __EMSCRIPTEN__
		if (on_off)
			alSource3i(alSource, AL_AUXILIARY_SEND_FILTER, g_ALEffectSlots[g_currEffectSlotIdx], 0, AL_FILTER_NULL);
		else
			alSource3i(alSource, AL_AUXILIARY_SEND_FILTER, AL_EFFECTSLOT_NULL, 0, AL_FILTER_NULL);
#endif // __EMSCRIPTEN__
	}

	SDL_UnlockMutex(g_SpuMutex);

	return 0;
}

u_int PsyX_SPUAL_GetReverbVoice()
{
	u_int bits = 0;
	for (int i = 0; i < s_spuVoiceCount; i++)
	{
		SPUALVoice* voice = &g_SpuVoices[i];
		if (voice->reverb)
			bits |= SPU_KEYCH(i);
	}
	return bits;
}