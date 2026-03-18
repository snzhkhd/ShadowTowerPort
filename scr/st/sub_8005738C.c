#include "recomp.h"
#include "disable_warnings.h"

void sub_8005738C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x2E80
    ctx->r2 = ADD32(ctx->r2, -0X2E80);
    // lhu         $a1, 0x32($v0)
    ctx->r5 = MEM_HU(0X32, ctx->r2);
    // lhu         $v1, 0x34($v0)
    ctx->r3 = MEM_HU(0X34, ctx->r2);
    // nop

    // or          $a1, $a1, $v1
    ctx->r5 = ctx->r5 | ctx->r3;
    // lhu         $v1, 0x36($v0)
    ctx->r3 = MEM_HU(0X36, ctx->r2);
    // lhu         $a0, 0x38($v0)
    ctx->r4 = MEM_HU(0X38, ctx->r2);
    // or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    // jr          $ra
    // sh          $a0, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r4;
    return;
    // sh          $a0, 0x3A($v0)
    MEM_H(0X3A, ctx->r2) = ctx->r4;
;}
