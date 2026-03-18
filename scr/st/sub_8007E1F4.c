#include "recomp.h"
#include "disable_warnings.h"

void sub_8007E1F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // sb          $v0, 0x36($a0)
    MEM_B(0X36, ctx->r4) = ctx->r2;
    // addiu       $v0, $a0, 0x24
    ctx->r2 = ADD32(ctx->r4, 0X24);
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $a1, 0x24($a0)
    MEM_B(0X24, ctx->r4) = ctx->r5;
    // jr          $ra
    // sb          $v0, 0x35($a0)
    MEM_B(0X35, ctx->r4) = ctx->r2;
    return;
    // sb          $v0, 0x35($a0)
    MEM_B(0X35, ctx->r4) = ctx->r2;
;}
