#include "recomp.h"
#include "disable_warnings.h"

void sub_80054278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addiu       $v0, $zero, 0xA0
    ctx->r2 = ADD32(0, 0XA0);
    // addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jal         0x80068F50
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    CdControlB(rdram, ctx);
    goto after_0;
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    after_0:
    // jal         0x80068CCC
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    CdReadyCallback(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // jal         0x8006E874
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    SsSetSerialVol(rdram, ctx);
    goto after_2;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_2:
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80068CE0
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    CdControl(rdram, ctx);
    goto after_3;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_3:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
