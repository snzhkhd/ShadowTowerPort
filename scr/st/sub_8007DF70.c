#include "recomp.h"
#include "disable_warnings.h"

void sub_8007DF70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(0X20, ctx->r4);
    // addiu       $v0, $zero, 0x4D
    ctx->r2 = ADD32(0, 0X4D);
    // sb          $v0, 0x36($a0)
    MEM_B(0X36, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // sb          $v0, 0x35($a0)
    MEM_B(0X35, ctx->r4) = ctx->r2;
    // jr          $ra
    // sw          $v1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r3;
    return;
    // sw          $v1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r3;
;}
