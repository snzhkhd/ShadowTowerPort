#include "recomp.h"
#include "disable_warnings.h"

void SsSetSerialVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4) << 24;
    // bne         $a0, $zero, L_8006E8F0
    if (ctx->r4 != 0) {
        // addu        $t0, $a2, $zero
        ctx->r8 = ADD32(ctx->r6, 0);
        goto L_8006E8F0;
    }
    // addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // addiu       $v0, $zero, 0xC0
    ctx->r2 = ADD32(0, 0XC0);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x80
    ctx->r2 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_8006E8B0
    if (ctx->r2 != 0) {
        // sll         $v0, $a2, 16
        ctx->r2 = S32(ctx->r6) << 16;
        goto L_8006E8B0;
    }
    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
    // addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
L_8006E8B0:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x80
    ctx->r2 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_8006E8C4
    if (ctx->r2 != 0) {
        // sll         $v1, $a3, 16
        ctx->r3 = S32(ctx->r7) << 16;
        goto L_8006E8C4;
    }
    // sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7) << 16;
    // addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
L_8006E8C4:
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
L_8006E8F0:
    // sll         $v0, $t1, 24
    ctx->r2 = S32(ctx->r9) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // bne         $v0, $v1, L_8006E960
    if (ctx->r2 != ctx->r3) {
        // addiu       $v0, $zero, 0xC00
        ctx->r2 = ADD32(0, 0XC00);
        goto L_8006E960;
    }
    // addiu       $v0, $zero, 0xC00
    ctx->r2 = ADD32(0, 0XC00);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x80
    ctx->r2 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_8006E920
    if (ctx->r2 != 0) {
        // sll         $v0, $t0, 16
        ctx->r2 = S32(ctx->r8) << 16;
        goto L_8006E920;
    }
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
L_8006E920:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x80
    ctx->r2 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_8006E934
    if (ctx->r2 != 0) {
        // sll         $v1, $a3, 16
        ctx->r3 = S32(ctx->r7) << 16;
        goto L_8006E934;
    }
    // sll         $v1, $a3, 16
    ctx->r3 = S32(ctx->r7) << 16;
    // addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
L_8006E934:
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // sll         $v1, $t0, 16
    ctx->r3 = S32(ctx->r8) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
L_8006E960:
    // jal         0x8006CCC4
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    SpuSetCommonAttr(rdram, ctx);
    goto after_0;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_0:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
