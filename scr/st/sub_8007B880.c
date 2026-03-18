#include "recomp.h"
#include "disable_warnings.h"

void sub_8007B880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x1000
    ctx->r2 = S32(0X1000 << 16);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DC8($v1)
    ctx->r3 = MEM_W(0X7DC8, ctx->r3);
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DC4($v0)
    ctx->r2 = MEM_W(0X7DC4, ctx->r2);
    // lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // jr          $ra
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    return;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
;}
