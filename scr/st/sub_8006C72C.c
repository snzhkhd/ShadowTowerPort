#include "recomp.h"
#include "disable_warnings.h"

void sub_8006C72C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xD54($a0)
    ctx->r4 = MEM_W(0XD54, ctx->r4);
    // lui         $v1, 0xF0FF
    ctx->r3 = S32(0XF0FF << 16);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $v1, 0x2000
    ctx->r3 = S32(0X2000 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // jr          $ra
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
