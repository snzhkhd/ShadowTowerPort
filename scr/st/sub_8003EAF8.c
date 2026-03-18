#include "recomp.h"
#include "disable_warnings.h"

void sub_8003EAF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // sw          $zero, 0x23C($v0)
    MEM_W(0X23C, ctx->r2) = 0;
    // sb          $v1, 0x21C($v0)
    MEM_B(0X21C, ctx->r2) = ctx->r3;
    // sb          $zero, 0x239($v0)
    MEM_B(0X239, ctx->r2) = 0;
    // sh          $zero, 0x2D4($v0)
    MEM_H(0X2D4, ctx->r2) = 0;
    // jal         0x8003EAD0
    // sb          $zero, 0x218($v0)
    MEM_B(0X218, ctx->r2) = 0;
    sub_8003EAD0(rdram, ctx);
    goto after_0;
    // sb          $zero, 0x218($v0)
    MEM_B(0X218, ctx->r2) = 0;
    after_0:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
