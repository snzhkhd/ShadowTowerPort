#include "recomp.h"
#include "disable_warnings.h"

void sub_80034364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // sll         $v1, $s0, 2
    ctx->r3 = S32(ctx->r16) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // ori         $v0, $zero, 0x834C
    ctx->r2 = 0 | 0X834C;
    // sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(0X0, ctx->r18);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // lw          $s1, 0x0($v1)
    ctx->r17 = MEM_W(0X0, ctx->r3);
    // bne         $a0, $zero, L_8003446C
    if (ctx->r4 != 0) {
        // lui         $s3, 0x1F80
        ctx->r19 = S32(0X1F80 << 16);
        goto L_8003446C;
    }
    // lui         $s3, 0x1F80
    ctx->r19 = S32(0X1F80 << 16);
    // jal         0x80034294
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    sub_80034294(rdram, ctx);
    goto after_0;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // nop

    // bne         $v0, $zero, L_800343E4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800343E4;
    }
    // nop

    // j           L_800345DC
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_800345DC;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800343E0:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
L_800343E4:
    // nop

    // lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(0X10, ctx->r2);
    // sh          $s0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r16;
    // beq         $a0, $zero, L_8003440C
    if (ctx->r4 == 0) {
        // sw          $s2, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->r18;
        goto L_8003440C;
    }
    // sw          $s2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r18;
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // nop

    // sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
L_8003440C:
    // lw          $v0, 0x20($s3)
    ctx->r2 = MEM_W(0X20, ctx->r19);
    // nop

    // lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(0X4, ctx->r2);
    // jal         0x800152D0
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    sub_800152D0(rdram, ctx);
    goto after_2;
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    after_2:
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // bne         $v0, $zero, L_80034464
    if (ctx->r2 != 0) {
        // sw          $v0, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->r2;
        goto L_80034464;
    }
    // sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // jal         0x800341A0
    // nop

    sub_800341A0(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x8003509C
    // nop

    sub_8003509C(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x80034224
    // nop

    sub_80034224(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // jal         0x80035120
    // nop

    sub_80035120(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // j           L_800345DC
    // sh          $v1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r3;
    goto L_800345DC;
    // sh          $v1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r3;
L_80034464:
    // j           L_80034494
    // sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
    goto L_80034494;
    // sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
L_8003446C:
    // lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(0X2, ctx->r4);
    // nop

    // beq         $v0, $s0, L_80034494
    if (ctx->r2 == ctx->r16) {
        // nop
    
        goto L_80034494;
    }
    // nop

    // jal         0x8003413C
    // nop

    sub_8003413C(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // j           L_800343E0
    // sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    goto L_800343E0;
    // sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
L_80034494:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    // addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // jal         0x80033CFC
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80033CFC(rdram, ctx);
    goto after_8;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(0X18, ctx->r29);
    // nop

    // lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(0X4, ctx->r5);
    // nop

    // bne         $v1, $s4, L_800344DC
    if (ctx->r3 != ctx->r20) {
        // addu        $s2, $v0, $zero
        ctx->r18 = ADD32(ctx->r2, 0);
        goto L_800344DC;
    }
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // lhu         $v1, 0x6($a1)
    ctx->r3 = MEM_HU(0X6, ctx->r5);
    // lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(0X1C, ctx->r29);
    // nop

    // beq         $v1, $v0, L_80034568
    if (ctx->r3 == ctx->r2) {
        // lui         $s0, 0x8017
        ctx->r16 = S32(0X8017 << 16);
        goto L_80034568;
    }
    // lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
L_800344DC:
    // lw          $v1, 0xC($s3)
    ctx->r3 = MEM_W(0XC, ctx->r19);
    // nop

    // addiu       $v0, $v1, 0xC
    ctx->r2 = ADD32(ctx->r3, 0XC);
    // sw          $v0, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r2;
    // lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(0XC, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->r3;
    // lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(0XC, ctx->r17);
    // lbu         $v0, 0x3($s2)
    ctx->r2 = MEM_BU(0X3, ctx->r18);
    // addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x2($s2)
    ctx->r2 = MEM_BU(0X2, ctx->r18);
    // nop

    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(0X0, ctx->r2);
    // lw          $a0, 0x10($a1)
    ctx->r4 = MEM_W(0X10, ctx->r5);
    // addu        $a2, $s1, $a2
    ctx->r6 = ADD32(ctx->r17, ctx->r6);
    // sw          $a2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r6;
    // lw          $v0, 0x20($s3)
    ctx->r2 = MEM_W(0X20, ctx->r19);
    // lw          $a1, 0x8($a1)
    ctx->r5 = MEM_W(0X8, ctx->r5);
    // lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(0X4, ctx->r2);
    // jal         0x80033A84
    // lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    sub_80033A84(rdram, ctx);
    goto after_9;
    // lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    after_9:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // lhu         $v1, 0x1C($sp)
    ctx->r3 = MEM_HU(0X1C, ctx->r29);
    // sh          $s4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r20;
    // sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
L_80034568:
    // addiu       $s0, $s0, -0x4430
    ctx->r16 = ADD32(ctx->r16, -0X4430);
    // lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(0XC, ctx->r17);
    // lbu         $v0, 0x3($s2)
    ctx->r2 = MEM_BU(0X3, ctx->r18);
    // addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(0X0, ctx->r2);
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // addu        $a2, $s1, $a2
    ctx->r6 = ADD32(ctx->r17, ctx->r6);
    // sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
    // lw          $v0, 0x20($s3)
    ctx->r2 = MEM_W(0X20, ctx->r19);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(0X4, ctx->r2);
    // lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(0X0, ctx->r2);
    // lw          $v0, 0xC($s3)
    ctx->r2 = MEM_W(0XC, ctx->r19);
    // addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // jal         0x80033B00
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    sub_80033B00(rdram, ctx);
    goto after_10;
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    after_10:
    // lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(0X20, ctx->r29);
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // lw          $v1, 0x20($s3)
    ctx->r3 = MEM_W(0X20, ctx->r19);
    // lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(0X10, ctx->r2);
    // lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(0X4, ctx->r3);
    // jal         0x80074A04
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    gteMIMefunc(rdram, ctx);
    goto after_11;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_11:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // sw          $s0, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->r16;
    // sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_800345DC:
    // lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(0X40, ctx->r29);
    // lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(0X3C, ctx->r29);
    // lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
