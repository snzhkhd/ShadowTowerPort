#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libspu.h"

void SpuGetVoiceEnvelope(uint8_t* rdram, recomp_context* ctx) 
{
    //short level = 0;
    //// PsyX signature: void SpuGetAllKeysStatus(char* status)
    //// or per-voice: check PsyX API
    //uint16_t* out = (uint16_t*)GET_PTR(ctx->r5);
    //SpuGetVoiceEnvelope((int)ctx->r4, &level);
    //*out = level;
    // voice = ctx->r4, out_ptr = ctx->r5
    uint16_t* out = (uint16_t*)GET_PTR(ctx->r5);
    if (out) *out = 0x7FFF;  // max level = still playing

    return;
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4) << 4;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(0XC, ctx->r4);
    // jr          $ra
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    return;
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
;}
