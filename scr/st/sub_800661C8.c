#include "recomp.h"
#include "disable_warnings.h"

void sub_800661C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // addiu       $a0, $a0, -0x7378
    ctx->r4 = ADD32(ctx->r4, -0X7378);
    // addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // jal         0x8003EC5C
    // sh          $zero, 0x12($sp)
    MEM_H(0X12, ctx->r29) = 0;
    sub_8003EC5C(rdram, ctx);
    goto after_0;
    // sh          $zero, 0x12($sp)
    MEM_H(0X12, ctx->r29) = 0;
    after_0:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
