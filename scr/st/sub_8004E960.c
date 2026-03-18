#include "recomp.h"
#include "disable_warnings.h"

void sub_8004E960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // addiu       $s0, $s0, -0x5EC8
    ctx->r16 = ADD32(ctx->r16, -0X5EC8);
    // sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // sh          $zero, 0x6164($s0)
    MEM_H(0X6164, ctx->r16) = 0;
    // sh          $zero, 0x6162($s0)
    MEM_H(0X6162, ctx->r16) = 0;
    // jal         0x80014D5C
    // sh          $zero, 0x6160($s0)
    MEM_H(0X6160, ctx->r16) = 0;
    sub_80014D5C(rdram, ctx);
    goto after_0;
    // sh          $zero, 0x6160($s0)
    MEM_H(0X6160, ctx->r16) = 0;
    after_0:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    sub_80014D5C(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    // addiu       $s7, $zero, 0x3F
    ctx->r23 = ADD32(0, 0X3F);
    // addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // addiu       $s6, $sp, 0x10
    ctx->r22 = ADD32(ctx->r29, 0X10);
    // ori         $fp, $zero, 0xFFFF
    ctx->r30 = 0 | 0XFFFF;
    // addiu       $s0, $s3, 0x6E
    ctx->r16 = ADD32(ctx->r19, 0X6E);
    // addiu       $s1, $s4, 0xA
    ctx->r17 = ADD32(ctx->r20, 0XA);
L_8004E9E0:
    // lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(0X0, ctx->r20);
    // nop

    // sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
    // sb          $zero, -0x69($s0)
    MEM_B(-0X69, ctx->r16) = 0;
    // lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(0X0, ctx->r19);
    // nop

    // beq         $v0, $s5, L_8004ECEC
    if (ctx->r2 == ctx->r21) {
        // lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
        goto L_8004ECEC;
    }
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lbu         $v0, -0x9($s1)
    ctx->r2 = MEM_BU(-0X9, ctx->r17);
    // addiu       $a0, $a0, -0x29C8
    ctx->r4 = ADD32(ctx->r4, -0X29C8);
    // sb          $v0, -0x6C($s0)
    MEM_B(-0X6C, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x6C($s0)
    ctx->r2 = MEM_BU(-0X6C, ctx->r16);
    // lbu         $a1, -0x9($s1)
    ctx->r5 = MEM_BU(-0X9, ctx->r17);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3) << 6;
    // addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // addu        $a2, $v0, $a1
    ctx->r6 = ADD32(ctx->r2, ctx->r5);
    // lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(0X0, ctx->r6);
    // nop

    // bne         $v0, $s5, L_8004EA6C
    if (ctx->r2 != ctx->r21) {
        // addu        $s2, $v1, $a0
        ctx->r18 = ADD32(ctx->r3, ctx->r4);
        goto L_8004EA6C;
    }
    // addu        $s2, $v1, $a0
    ctx->r18 = ADD32(ctx->r3, ctx->r4);
    // srl         $a0, $a1, 2
    ctx->r4 = S32(U32(ctx->r5) >> 2);
    // addu        $v0, $s6, $a0
    ctx->r2 = ADD32(ctx->r22, ctx->r4);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addu        $a0, $s6, $a0
    ctx->r4 = ADD32(ctx->r22, ctx->r4);
    // sb          $v0, -0x62($s0)
    MEM_B(-0X62, ctx->r16) = ctx->r2;
    // sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // lbu         $v1, 0x4($s2)
    ctx->r3 = MEM_BU(0X4, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // j           L_8004EA70
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    goto L_8004EA70;
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8004EA6C:
    // sb          $v0, -0x62($s0)
    MEM_B(-0X62, ctx->r16) = ctx->r2;
L_8004EA70:
    // lhu         $v0, -0x8($s1)
    ctx->r2 = MEM_HU(-0X8, ctx->r17);
    // lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // sh          $v0, -0x46($s0)
    MEM_H(-0X46, ctx->r16) = ctx->r2;
    // lhu         $v1, -0x46($s0)
    ctx->r3 = MEM_HU(-0X46, ctx->r16);
    // addiu       $t0, $t0, -0x4130
    ctx->r8 = ADD32(ctx->r8, -0X4130);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(0X1, ctx->r2);
    // addiu       $t0, $t0, -0x4130
    ctx->r8 = ADD32(ctx->r8, -0X4130);
    // sb          $v0, -0x68($s0)
    MEM_B(-0X68, ctx->r16) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lbu         $v0, 0x7($v0)
    ctx->r2 = MEM_BU(0X7, ctx->r2);
    // nop

    // sb          $v0, -0x67($s0)
    MEM_B(-0X67, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x6C($s0)
    ctx->r2 = MEM_BU(-0X6C, ctx->r16);
    // lbu         $v1, 0x4($s2)
    ctx->r3 = MEM_BU(0X4, ctx->r18);
    // sb          $zero, -0x6B($s0)
    MEM_B(-0X6B, ctx->r16) = 0;
    // sb          $v0, -0x63($s0)
    MEM_B(-0X63, ctx->r16) = ctx->r2;
    // sb          $v1, -0x65($s0)
    MEM_B(-0X65, ctx->r16) = ctx->r3;
    // lhu         $v0, -0x6($s1)
    ctx->r2 = MEM_HU(-0X6, ctx->r17);
    // nop

    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // sh          $v0, -0x5E($s0)
    MEM_H(-0X5E, ctx->r16) = ctx->r2;
    // lhu         $v0, -0x4($s1)
    ctx->r2 = MEM_HU(-0X4, ctx->r17);
    // nop

    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // sh          $v0, -0x5C($s0)
    MEM_H(-0X5C, ctx->r16) = ctx->r2;
    // lhu         $v0, -0x2($s1)
    ctx->r2 = MEM_HU(-0X2, ctx->r17);
    // nop

    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // sh          $v0, -0x5A($s0)
    MEM_H(-0X5A, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x1($s1)
    ctx->r2 = MEM_BU(0X1, ctx->r17);
    // nop

    // sb          $v0, -0x9($s0)
    MEM_B(-0X9, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(0X2, ctx->r17);
    // nop

    // sb          $v0, -0x8($s0)
    MEM_B(-0X8, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(0X3, ctx->r17);
    // nop

    // sb          $v0, -0x7($s0)
    MEM_B(-0X7, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // nop

    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sh          $v0, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // sh          $v0, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r2;
    // lhu         $v0, 0xA($s1)
    ctx->r2 = MEM_HU(0XA, ctx->r17);
    // nop

    // sh          $v0, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r2;
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x8004ACEC
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    sub_8004ACEC(rdram, ctx);
    goto after_2;
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    after_2:
    // sb          $zero, -0x66($s0)
    MEM_B(-0X66, ctx->r16) = 0;
    // sh          $zero, -0x44($s0)
    MEM_H(-0X44, ctx->r16) = 0;
    // sb          $zero, -0x53($s0)
    MEM_B(-0X53, ctx->r16) = 0;
    // sw          $zero, 0x3E($s0)
    MEM_W(0X3E, ctx->r16) = 0;
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // sb          $v0, -0x61($s0)
    MEM_B(-0X61, ctx->r16) = ctx->r2;
    // lbu         $v1, 0x5($s2)
    ctx->r3 = MEM_BU(0X5, ctx->r18);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, -0x5F($s0)
    MEM_B(-0X5F, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $zero, -0x58($s0)
    MEM_H(-0X58, ctx->r16) = 0;
    // sb          $s5, -0x54($s0)
    MEM_B(-0X54, ctx->r16) = ctx->r21;
    // sw          $zero, 0x3A($s0)
    MEM_W(0X3A, ctx->r16) = 0;
    // sb          $v0, -0x4C($s0)
    MEM_B(-0X4C, ctx->r16) = ctx->r2;
    // sb          $v1, -0x60($s0)
    MEM_B(-0X60, ctx->r16) = ctx->r3;
    // lbu         $v0, 0x3($s2)
    ctx->r2 = MEM_BU(0X3, ctx->r18);
    // nop

    // sb          $v0, -0x4D($s0)
    MEM_B(-0X4D, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x10($s2)
    ctx->r2 = MEM_BU(0X10, ctx->r18);
    // nop

    // sb          $v0, -0x64($s0)
    MEM_B(-0X64, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x16($s2)
    ctx->r2 = MEM_HU(0X16, ctx->r18);
    // nop

    // sh          $v0, -0x40($s0)
    MEM_H(-0X40, ctx->r16) = ctx->r2;
    // lhu         $v1, 0x18($s2)
    ctx->r3 = MEM_HU(0X18, ctx->r18);
    // addiu       $v0, $zero, 0xB2
    ctx->r2 = ADD32(0, 0XB2);
    // sw          $v0, -0x1E($s0)
    MEM_W(-0X1E, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x3F
    ctx->r2 = ADD32(0, 0X3F);
    // sh          $v1, -0x3E($s0)
    MEM_H(-0X3E, ctx->r16) = ctx->r3;
    // andi        $v1, $s7, 0xFFFF
    ctx->r3 = ctx->r23 & 0XFFFF;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, 0x38
    ctx->r2 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
    // bne         $v0, $zero, L_8004EBF4
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8004EBF4;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // j           L_8004EBF8
    // sb          $v0, -0x4F($s0)
    MEM_B(-0X4F, ctx->r16) = ctx->r2;
    goto L_8004EBF8;
    // sb          $v0, -0x4F($s0)
    MEM_B(-0X4F, ctx->r16) = ctx->r2;
L_8004EBF4:
    // sb          $zero, -0x4F($s0)
    MEM_B(-0X4F, ctx->r16) = 0;
L_8004EBF8:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // sb          $zero, -0x52($s0)
    MEM_B(-0X52, ctx->r16) = 0;
    // jal         0x8004AC38
    // sb          $zero, -0xA($s0)
    MEM_B(-0XA, ctx->r16) = 0;
    sub_8004AC38(rdram, ctx);
    goto after_3;
    // sb          $zero, -0xA($s0)
    MEM_B(-0XA, ctx->r16) = 0;
    after_3:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a2, $v0, 0x7810
    ctx->r6 = ADD32(ctx->r2, 0X7810);
    // addiu       $a3, $a2, -0x118
    ctx->r7 = ADD32(ctx->r6, -0X118);
    // lw          $v0, 0xA($s0)
    ctx->r2 = MEM_W(0XA, ctx->r16);
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // sw          $v0, 0x16($s0)
    MEM_W(0X16, ctx->r16) = ctx->r2;
L_8004EC24:
    // lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(0X18, ctx->r4);
    // nop

    // beq         $v1, $fp, L_8004EC78
    if (ctx->r3 == ctx->r30) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_8004EC78;
    }
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(0X4, ctx->r2);
    // nop

    // addu        $v1, $v0, $a3
    ctx->r3 = ADD32(ctx->r2, ctx->r7);
    // lbu         $v0, 0x94($v1)
    ctx->r2 = MEM_BU(0X94, ctx->r3);
    // nop

    // bne         $v0, $s5, L_8004EC78
    if (ctx->r2 != ctx->r21) {
        // nop
    
        goto L_8004EC78;
    }
    // nop

    // lw          $v0, -0x4($a2)
    ctx->r2 = MEM_W(-0X4, ctx->r6);
    // nop

    // sb          $v0, 0x94($v1)
    MEM_B(0X94, ctx->r3) = ctx->r2;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r2;
L_8004EC78:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_8004EC24
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_8004EC24;
    }
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // lw          $v0, 0x2($s0)
    ctx->r2 = MEM_W(0X2, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8004ECEC
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8004ECEC;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // lbu         $v1, 0x0($s2)
    ctx->r3 = MEM_BU(0X0, ctx->r18);
    // nop

    // bne         $v1, $v0, L_8004ECE4
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8004ECE4;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lh          $v0, -0x2($s0)
    ctx->r2 = MEM_HS(-0X2, ctx->r16);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8004ECC8
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8004ECC8;
    }
    // nop

    // lhu         $v0, 0x32($s2)
    ctx->r2 = MEM_HU(0X32, ctx->r18);
    // nop

    // sh          $v0, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r2;
L_8004ECC8:
    // lh          $v0, 0x0($s0)
    ctx->r2 = MEM_HS(0X0, ctx->r16);
    // nop

    // bne         $v0, $v1, L_8004ECEC
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8004ECEC;
    }
    // nop

    // lbu         $v0, 0x8($s2)
    ctx->r2 = MEM_BU(0X8, ctx->r18);
    // j           L_8004ECEC
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    goto L_8004ECEC;
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_8004ECE4:
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_8004ECEC:
    // addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // addiu       $s4, $s4, 0x18
    ctx->r20 = ADD32(ctx->r20, 0X18);
    // addiu       $s0, $s0, 0xD4
    ctx->r16 = ADD32(ctx->r16, 0XD4);
    // addiu       $v0, $s7, -0x1
    ctx->r2 = ADD32(ctx->r23, -0X1);
    // addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $fp, L_8004E9E0
    if (ctx->r2 != ctx->r30) {
        // addiu       $s3, $s3, 0xD4
        ctx->r19 = ADD32(ctx->r19, 0XD4);
        goto L_8004E9E0;
    }
    // addiu       $s3, $s3, 0xD4
    ctx->r19 = ADD32(ctx->r19, 0XD4);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x5EC8
    ctx->r2 = ADD32(ctx->r2, -0X5EC8);
    // sw          $zero, 0x6130($v0)
    MEM_W(0X6130, ctx->r2) = 0;
    // sw          $zero, 0x612C($v0)
    MEM_W(0X612C, ctx->r2) = 0;
    // sw          $zero, 0x6128($v0)
    MEM_W(0X6128, ctx->r2) = 0;
    // lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(0X5C, ctx->r29);
    // lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(0X58, ctx->r29);
    // lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(0X54, ctx->r29);
    // lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(0X50, ctx->r29);
    // lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(0X4C, ctx->r29);
    // lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(0X48, ctx->r29);
    // lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(0X44, ctx->r29);
    // lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(0X40, ctx->r29);
    // lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(0X3C, ctx->r29);
    // lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // jr          $ra
    // nop

    return;
    // nop

;}
