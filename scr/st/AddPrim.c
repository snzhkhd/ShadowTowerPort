#include "recomp.h"
#include "disable_warnings.h"

void AddPrim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a2, 0xFF
    ctx->r6 = S32(0XFF << 16);
    // ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // lui         $a3, 0xFF00
    ctx->r7 = S32(0XFF00 << 16);
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // and         $v1, $v1, $a3
    ctx->r3 = ctx->r3 & ctx->r7;
    // and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // and         $a1, $a1, $a2
    ctx->r5 = ctx->r5 & ctx->r6;
    // and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // or          $v0, $v0, $a1
    ctx->r2 = ctx->r2 | ctx->r5;
    // jr          $ra
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
