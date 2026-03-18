#include "recomp.h"
#include "disable_warnings.h"

void sub_800779D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // addiu       $a0, $a0, 0x7BB0
    ctx->r4 = ADD32(ctx->r4, 0X7BB0);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7BD4($v1)
    ctx->r3 = MEM_W(0X7BD4, ctx->r3);
    // addiu       $v0, $zero, 0x107
    ctx->r2 = ADD32(0, 0X107);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x7BD0($at)
    MEM_W(0X7BD0, ctx->r1) = 0;
    // jal         0x80077AC4
    // addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    sub_80077AC4(rdram, ctx);
    goto after_0;
    // addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, 0x7A2C
    ctx->r5 = ADD32(ctx->r5, 0X7A2C);
    // jal         0x80077344
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    InterruptCallback(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // addiu       $v0, $v0, 0x7A98
    ctx->r2 = ADD32(ctx->r2, 0X7A98);
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
