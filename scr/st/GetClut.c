#include "recomp.h"
#include "disable_warnings.h"
#include "psx/libgte.h" 
#include "psx/libgpu.h"

void GetClut(uint8_t* rdram, recomp_context* ctx) 
{
    ctx->r2 = (uint32_t)GetClut((int)ctx->r4, (int)ctx->r5);

    //uint64_t hi = 0, lo = 0, result = 0;
    //unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    //int c1cs = 0; 
    //// sll         $v0, $a1, 6
    //ctx->r2 = S32(ctx->r5) << 6;
    //// sra         $a0, $a0, 4
    //ctx->r4 = S32(ctx->r4) >> 4;
    //// andi        $a0, $a0, 0x3F
    //ctx->r4 = ctx->r4 & 0X3F;
    //// or          $v0, $v0, $a0
    //ctx->r2 = ctx->r2 | ctx->r4;
    //// jr          $ra
    //// andi        $v0, $v0, 0xFFFF
    //ctx->r2 = ctx->r2 & 0XFFFF;
    //return;
    //// andi        $v0, $v0, 0xFFFF
    //ctx->r2 = ctx->r2 & 0XFFFF;
;}
