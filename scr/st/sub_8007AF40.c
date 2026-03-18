#include "recomp.h"
#include "disable_warnings.h"

void sub_8007AF40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $a1, $a1, 0x7FF
    ctx->r5 = ctx->r5 & 0X7FF;
    // sll         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) << 11;
    // andi        $v0, $a0, 0x7FF
    ctx->r2 = ctx->r4 & 0X7FF;
    // lui         $v1, 0xE500
    ctx->r3 = S32(0XE500 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // jr          $ra
    // or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    return;
    // or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
;}
