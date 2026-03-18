#include "recomp.h"
#include "disable_warnings.h"

void sub_80015DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // lw          $s2, -0x742C($v0)
    ctx->r18 = MEM_W(-0X742C, ctx->r2);
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // jal         0x80015B2C
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_80015B2C(rdram, ctx);
    goto after_0;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // sh          $zero, 0xA($s2)
    MEM_H(0XA, ctx->r18) = 0;
    // sb          $zero, 0x10($s2)
    MEM_B(0X10, ctx->r18) = 0;
    // jal         0x80015CD0
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    sub_80015CD0(rdram, ctx);
    goto after_1;
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_1:
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // srl         $v1, $a2, 11
    ctx->r3 = S32(U32(ctx->r6) >> 11);
    // sh          $v1, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r3;
    // lh          $v0, 0xE($s2)
    ctx->r2 = MEM_HS(0XE, ctx->r18);
    // nop

    // slti        $v0, $v0, 0x11
    ctx->r2 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // bne         $v0, $zero, L_80015E8C
    if (ctx->r2 != 0) {
        // sh          $v1, 0xC($s2)
        MEM_H(0XC, ctx->r18) = ctx->r3;
        goto L_80015E8C;
    }
    // sh          $v1, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r3;
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // addiu       $v0, $v1, -0x10
    ctx->r2 = ADD32(ctx->r3, -0X10);
    // j           L_80015E9C
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
    goto L_80015E9C;
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
L_80015E8C:
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // sh          $zero, 0xE($s2)
    MEM_H(0XE, ctx->r18) = 0;
L_80015E9C:
    // jal         0x80015BCC
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    sub_80015BCC(rdram, ctx);
    goto after_2;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
