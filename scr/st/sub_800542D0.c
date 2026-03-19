#include "recomp.h"
#include "disable_warnings.h"

void sub_800542D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // jal         0x80015AD4
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_0;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    after_0:
    // bne         $s0, $zero, L_80054310
    if (ctx->r16 != 0) {
        // addiu       $v0, $zero, 0x3C0
        ctx->r2 = ADD32(0, 0X3C0);
        goto L_80054310;
    }
    // addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x230
    ctx->r2 = ADD32(0, 0X230);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // j           L_80054320
    // addiu       $v0, $zero, 0x1EF
    ctx->r2 = ADD32(0, 0X1EF);
    goto L_80054320;
    // addiu       $v0, $zero, 0x1EF
    ctx->r2 = ADD32(0, 0X1EF);
L_80054310:
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1FF
    ctx->r2 = ADD32(0, 0X1FF);
    // sh          $zero, 0x12($sp)
    MEM_H(0X12, ctx->r29) = 0;
    // sh          $zero, 0x18($sp)
    MEM_H(0X18, ctx->r29) = 0;
L_80054320:
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // addiu       $s0, $s0, -0x7378
    ctx->r16 = ADD32(ctx->r16, -0X7378);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_1;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_2;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
