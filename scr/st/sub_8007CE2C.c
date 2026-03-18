#include "recomp.h"
#include "disable_warnings.h"

void sub_8007CE2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addiu       $v0, $v0, -0x4D44
    ctx->r2 = ADD32(ctx->r2, -0X4D44);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, -0x3140
    ctx->r3 = ADD32(ctx->r3, -0X3140);
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, -0x31A8
    ctx->r3 = ADD32(ctx->r3, -0X31A8);
    // sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // jr          $ra
    // sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    return;
    // sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
;}
