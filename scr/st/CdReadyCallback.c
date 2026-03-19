#include "kf_cd.h"
#include "recomp.h"
#include "disable_warnings.h"

void CdReadyCallback(uint8_t* rdram, recomp_context* ctx) 
{
    KFCD_CdReadyCallback(rdram, ctx);

    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// lui         $v0, 0x8008
    //ctx->r2 = S32(0X8008 << 16);
    //// lw          $v0, 0x9DC($v0)
    //ctx->r2 = MEM_W(0X9DC, ctx->r2);
    //// lui         $at, 0x8008
    //ctx->r1 = S32(0X8008 << 16);
    //// jr          $ra
    //// sw          $a0, 0x9DC($at)
    //MEM_W(0X9DC, ctx->r1) = ctx->r4;
    //return;
    //// sw          $a0, 0x9DC($at)
    //MEM_W(0X9DC, ctx->r1) = ctx->r4;
;}
