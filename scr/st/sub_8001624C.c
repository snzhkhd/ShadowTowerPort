#include "recomp.h"
#include "disable_warnings.h"

void sub_8001624C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // jal         0x80068CE0
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    CdControl(rdram, ctx);
    goto after_0;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_0:
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80068F50
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    CdControlB(rdram, ctx);
    goto after_1;
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    after_1:
    // jal         0x80077104
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    VSync(rdram, ctx);
    goto after_2;
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
