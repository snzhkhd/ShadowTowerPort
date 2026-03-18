#include "recomp.h"
#include "disable_warnings.h"

void SsSetSerialAttr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4) << 24;
    // bne         $a0, $zero, L_8006CC64
    if (ctx->r4 != 0) {
        // addu        $t0, $a2, $zero
        ctx->r8 = ADD32(ctx->r6, 0);
        goto L_8006CC64;
    }
    // addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5) << 24;
    // sra         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2) >> 24;
    // bne         $v1, $zero, L_8006CC48
    if (ctx->r3 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8006CC48;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006CC48:
    // bne         $v1, $v0, L_8006CC68
    if (ctx->r3 != ctx->r2) {
        // sll         $v0, $a3, 24
        ctx->r2 = S32(ctx->r7) << 24;
        goto L_8006CC68;
    }
    // sll         $v0, $a3, 24
    ctx->r2 = S32(ctx->r7) << 24;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sll         $v0, $a2, 24
    ctx->r2 = S32(ctx->r6) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_8006CC64:
    // sll         $v0, $a3, 24
    ctx->r2 = S32(ctx->r7) << 24;
L_8006CC68:
    // sra         $a0, $v0, 24
    ctx->r4 = S32(ctx->r2) >> 24;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $a0, $v0, L_8006CCAC
    if (ctx->r4 != ctx->r2) {
        // sll         $v0, $t1, 24
        ctx->r2 = S32(ctx->r9) << 24;
        goto L_8006CCAC;
    }
    // sll         $v0, $t1, 24
    ctx->r2 = S32(ctx->r9) << 24;
    // sra         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2) >> 24;
    // bne         $v1, $zero, L_8006CC94
    if (ctx->r3 != 0) {
        // addiu       $v0, $zero, 0x2000
        ctx->r2 = ADD32(0, 0X2000);
        goto L_8006CC94;
    }
    // addiu       $v0, $zero, 0x2000
    ctx->r2 = ADD32(0, 0X2000);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sll         $v0, $t0, 24
    ctx->r2 = S32(ctx->r8) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_8006CC94:
    // bne         $v1, $a0, L_8006CCAC
    if (ctx->r3 != ctx->r4) {
        // addiu       $v0, $zero, 0x1000
        ctx->r2 = ADD32(0, 0X1000);
        goto L_8006CCAC;
    }
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sll         $v0, $t0, 24
    ctx->r2 = S32(ctx->r8) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_8006CCAC:
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
