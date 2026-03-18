#include "recomp.h"
#include "disable_warnings.h"

void sub_8007EEA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0x1128
    ctx->r2 = ADD32(ctx->r2, -0X1128);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7E30($at)
    MEM_W(0X7E30, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0xD14
    ctx->r2 = ADD32(ctx->r2, -0XD14);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7E34($at)
    MEM_W(0X7E34, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0x1054
    ctx->r2 = ADD32(ctx->r2, -0X1054);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // jr          $ra
    // sw          $v0, 0x7E38($at)
    MEM_W(0X7E38, ctx->r1) = ctx->r2;
    return;
    // sw          $v0, 0x7E38($at)
    MEM_W(0X7E38, ctx->r1) = ctx->r2;
;}
