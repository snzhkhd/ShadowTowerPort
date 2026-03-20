#define SDL_MAIN_HANDLED
#define _CRT_SECURE_NO_WARNINGS
#include <AL/al.h>
#include <string>
#include <thread>
#include <unordered_map>

#include "st/funcs.h" 
#include "kf_cd.h"
#include "recomp.h"

extern "C"
{
#include "PsyX/PsyX_public.h"
#include "gpu/PsyX_GPU.h"
#include "pad/PsyX_pad.h"

#include "psx/libcd.h"
#include "psx/libspu.h"

#include "psx/libetc.h"
#include "PsyX/PsyX_render.h"

#include "audio/PsyX_SPUAL.h"


}
#include "CrashHandler.h"

#include <SDL2/SDL.h>




/////////


std::unordered_map<uint32_t, uint32_t> g_stream_file_sizes;;
bool g_pendingType10 = false;
uint8_t rdram[2 * 1024 * 1024] = { 0 };   // 2 MB Основной RAM
//gamepad
uint8_t g_pad1_buf[34];
uint8_t g_pad2_buf[34];

//mem card
std::string g_redirectFrom = "";  // оригинальный путь
std::string g_redirectTo = "";    // перенаправленный путь

const char* MC_SAVE_DIR = "memcard/";
FILE* g_mcFiles[16] = {};
int g_mcNextFd = 1;

int main(int argc, char* argv[])
{
    InstallCrashHandler();

    char appName[] = "Shadow Tower";
    recomp_context ctx = { 0 };
    g_ctx = &ctx;
    KFCD_Init("Shadow_Tower.bin");

    if (!LoadGameEXEFromCD(&ctx))
    {
        printf("[ERROR] Failed to load GAME.EXE from CD\n");
        system("PAUSE");
        return 1;
    }

    init_function_table();

    // Стек (растет вниз от конца памяти)
    ctx.r29 = 0x801F0000;

    // Глобальный указатель 0x800762C0
    ctx.r28 = 0x80087EC0;
    // Начальное состояние GPU: Готов, бит 31 установлен
    *(uint32_t*)GET_PTR(0x1F801814) = 0x9C000000;


    PsyX_Initialise(appName, 640, 480, 0);


    PsyX_SetMemoryPointer(rdram);

    WRITE_W(0x1F801814, 0x1C000000);

    PsyX_UpdateInput();


    memset(GET_PTR(0x801CD130), 0xFF, 34);
    memset(GET_PTR(0x801CD152), 0xFF, 34);

    /*uint8_t* pad1_ptr = (uint8_t*)GET_PTR(0x801CD130);
    uint8_t* pad2_ptr = (uint8_t*)GET_PTR(0x801CD152);

    memset(pad1_ptr, 0xFF, 34);
    memset(pad2_ptr, 0xFF, 34);
    pad1_ptr[0] = 0x00;
    pad1_ptr[1] = 0x41;

    PsyX_Pad_InitPad(1, pad1_ptr);
    PsyX_Pad_InitPad(0, pad2_ptr);*/

    ResetGraph(0);


    PsyX_BeginScene();

    //старт игры!
    start(rdram, &ctx);



    PsyX_Shutdown();
    return 0;
}

