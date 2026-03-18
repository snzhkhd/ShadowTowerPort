#include "recomp.h"
#include "disable_warnings.h"

void CD_initintr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x9DC($at)
    MEM_W(0X9DC, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x9D8($at)
    MEM_W(0X9D8, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x9EC($at)
    MEM_W(0X9EC, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // jal         0x80077314
    // sw          $zero, 0x9E8($at)
    MEM_W(0X9E8, ctx->r1) = 0;
    ResetCallback(rdram, ctx);
    goto after_0;
    // sw          $zero, 0x9E8($at)
    MEM_W(0X9E8, ctx->r1) = 0;
    after_0:
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, -0x56B4
    ctx->r5 = ADD32(ctx->r5, -0X56B4);
    // jal         0x80077344
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    InterruptCallback(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
