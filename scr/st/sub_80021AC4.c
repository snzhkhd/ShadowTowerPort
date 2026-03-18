#include "recomp.h"
#include "disable_warnings.h"

void sub_80021AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // addiu       $s2, $v0, -0x70D8
    ctx->r18 = ADD32(ctx->r2, -0X70D8);
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // andi        $s1, $s3, 0xFF
    ctx->r17 = ctx->r19 & 0XFF;
    // sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17) << 1;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // lh          $v1, 0x130($v0)
    ctx->r3 = MEM_HS(0X130, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_80021FF0
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80021FF0;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80017D28
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    sub_80017D28(rdram, ctx);
    goto after_0;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_0:
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // lw          $v0, 0x394($s0)
    ctx->r2 = MEM_W(0X394, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(0X0, ctx->r2);
    // lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(0X4, ctx->r2);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(0X8, ctx->r2);
    // lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(0XC, ctx->r2);
    // lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(0X10, ctx->r2);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // addiu       $t3, $t3, -0x4288
    ctx->r11 = ADD32(ctx->r11, -0X4288);
    // lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(0X0, ctx->r11);
    // lhu         $t5, 0x6($t3)
    ctx->r13 = MEM_HU(0X6, ctx->r11);
    // lhu         $t6, 0xC($t3)
    ctx->r14 = MEM_HU(0XC, ctx->r11);
    // mtc2        $t4, $9
    gte_mtc2(ctx, 12, 9);
    // mtc2        $t5, $10
    gte_mtc2(ctx, 13, 10);
    // mtc2        $t6, $11
    gte_mtc2(ctx, 14, 11);
    // nop

    // nop

    // .word       0x4A49E012                   # INVALID     $s2, $t1, -0x1FEE # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A49E012);
    // addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // mfc2        $t4, $9
    ctx->r12 = gte_mfc2(ctx, 9);
    // mfc2        $t5, $10
    ctx->r13 = gte_mfc2(ctx, 10);
    // mfc2        $t6, $11
    ctx->r14 = gte_mfc2(ctx, 11);
    // sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // sh          $t5, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r13;
    // sh          $t6, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r14;
    // lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // addiu       $t3, $t3, -0x4286
    ctx->r11 = ADD32(ctx->r11, -0X4286);
    // lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(0X0, ctx->r11);
    // lhu         $t5, 0x6($t3)
    ctx->r13 = MEM_HU(0X6, ctx->r11);
    // lhu         $t6, 0xC($t3)
    ctx->r14 = MEM_HU(0XC, ctx->r11);
    // mtc2        $t4, $9
    gte_mtc2(ctx, 12, 9);
    // mtc2        $t5, $10
    gte_mtc2(ctx, 13, 10);
    // mtc2        $t6, $11
    gte_mtc2(ctx, 14, 11);
    // nop

    // nop

    // .word       0x4A49E012                   # INVALID     $s2, $t1, -0x1FEE # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A49E012);
    // addiu       $v0, $sp, 0x12
    ctx->r2 = ADD32(ctx->r29, 0X12);
    // mfc2        $t4, $9
    ctx->r12 = gte_mfc2(ctx, 9);
    // mfc2        $t5, $10
    ctx->r13 = gte_mfc2(ctx, 10);
    // mfc2        $t6, $11
    ctx->r14 = gte_mfc2(ctx, 11);
    // sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // sh          $t6, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r14;
    // lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // addiu       $t3, $t3, -0x4284
    ctx->r11 = ADD32(ctx->r11, -0X4284);
    // lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(0X0, ctx->r11);
    // lhu         $t5, 0x6($t3)
    ctx->r13 = MEM_HU(0X6, ctx->r11);
    // lhu         $t6, 0xC($t3)
    ctx->r14 = MEM_HU(0XC, ctx->r11);
    // mtc2        $t4, $9
    gte_mtc2(ctx, 12, 9);
    // mtc2        $t5, $10
    gte_mtc2(ctx, 13, 10);
    // mtc2        $t6, $11
    gte_mtc2(ctx, 14, 11);
    // nop

    // nop

    // .word       0x4A49E012                   # INVALID     $s2, $t1, -0x1FEE # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A49E012);
    // addiu       $v0, $sp, 0x14
    ctx->r2 = ADD32(ctx->r29, 0X14);
    // mfc2        $t4, $9
    ctx->r12 = gte_mfc2(ctx, 9);
    // mfc2        $t5, $10
    ctx->r13 = gte_mfc2(ctx, 10);
    // mfc2        $t6, $11
    ctx->r14 = gte_mfc2(ctx, 11);
    // sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // sh          $t6, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r14;
    // lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(0X0, ctx->r3);
    // lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(0X4, ctx->r3);
    // ctc2        $t4, $8
    gte_ctc2(ctx, 12, 8);
    // ctc2        $t5, $9
    gte_ctc2(ctx, 13, 9);
    // lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(0X8, ctx->r3);
    // lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(0XC, ctx->r3);
    // lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(0X10, ctx->r3);
    // ctc2        $t4, $10
    gte_ctc2(ctx, 12, 10);
    // ctc2        $t5, $11
    gte_ctc2(ctx, 13, 11);
    // ctc2        $t6, $12
    gte_ctc2(ctx, 14, 12);
    // sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17) << 2;
    // addu        $a1, $v0, $s2
    ctx->r5 = ADD32(ctx->r2, ctx->r18);
    // lw          $v0, 0xE8($a1)
    ctx->r2 = MEM_W(0XE8, ctx->r5);
    // nop

    // lh          $v0, 0xC($v0)
    ctx->r2 = MEM_HS(0XC, ctx->r2);
    // nop

    // sw          $v0, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = ctx->r2;
    // lw          $v0, 0xE8($a1)
    ctx->r2 = MEM_W(0XE8, ctx->r5);
    // nop

    // lh          $v0, 0xE($v0)
    ctx->r2 = MEM_HS(0XE, ctx->r2);
    // nop

    // sw          $v0, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->r2;
    // lw          $v0, 0xE8($a1)
    ctx->r2 = MEM_W(0XE8, ctx->r5);
    // nop

    // lh          $v0, 0x10($v0)
    ctx->r2 = MEM_HS(0X10, ctx->r2);
    // nop

    // sw          $v0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->r2;
    // lhu         $v1, 0x58($s2)
    ctx->r3 = MEM_HU(0X58, ctx->r18);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_80021CF0
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80021CF0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // beq         $s1, $zero, L_80021CF0
    if (ctx->r17 == 0) {
        // addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
        goto L_80021CF0;
    }
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // lw          $v0, 0xE8($a1)
    ctx->r2 = MEM_W(0XE8, ctx->r5);
    // lhu         $v1, 0x2DE($s2)
    ctx->r3 = MEM_HU(0X2DE, ctx->r18);
    // lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(0X14, ctx->r2);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r2;
    // lw          $v0, 0xE8($a1)
    ctx->r2 = MEM_W(0XE8, ctx->r5);
    // lhu         $v1, 0x2E0($s2)
    ctx->r3 = MEM_HU(0X2E0, ctx->r18);
    // lhu         $v0, 0x16($v0)
    ctx->r2 = MEM_HU(0X16, ctx->r2);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
    // lw          $v0, 0xE8($a1)
    ctx->r2 = MEM_W(0XE8, ctx->r5);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lhu         $v1, 0x2E2($s2)
    ctx->r3 = MEM_HU(0X2E2, ctx->r18);
    // lhu         $v0, 0x18($v0)
    ctx->r2 = MEM_HU(0X18, ctx->r2);
    // ori         $a1, $a1, 0xA8
    ctx->r5 = ctx->r5 | 0XA8;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_80021D0C
    // sh          $v0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r2;
    goto L_80021D0C;
    // sh          $v0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r2;
L_80021CF0:
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $a0, 0xE8($v1)
    ctx->r4 = MEM_W(0XE8, ctx->r3);
    // ori         $a1, $s0, 0xA8
    ctx->r5 = ctx->r16 | 0XA8;
    // addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
L_80021D0C:
    // jal         0x80074EC4
    // nop

    RotMatrix(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $t2, $v0, -0x2F70
    ctx->r10 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $v1, $t2, $v1
    ctx->r3 = ADD32(ctx->r10, ctx->r3);
    // lw          $a0, 0x2E8($v1)
    ctx->r4 = MEM_W(0X2E8, ctx->r3);
    // lw          $a1, 0x31C($v1)
    ctx->r5 = MEM_W(0X31C, ctx->r3);
    // lw          $a2, 0x320($v1)
    ctx->r6 = MEM_W(0X320, ctx->r3);
    // lw          $a3, 0x324($v1)
    ctx->r7 = MEM_W(0X324, ctx->r3);
    // lw          $t0, 0x328($v1)
    ctx->r8 = MEM_W(0X328, ctx->r3);
    // lw          $t1, 0x304($v1)
    ctx->r9 = MEM_W(0X304, ctx->r3);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // sw          $v0, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r2;
    // sw          $a1, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r5;
    // andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    // sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // sw          $a2, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r6;
    // sw          $a3, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r7;
    // sw          $t0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r8;
    // lw          $v0, 0x8($t1)
    ctx->r2 = MEM_W(0X8, ctx->r9);
    // sll         $a2, $a1, 2
    ctx->r6 = S32(ctx->r5) << 2;
    // sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // lw          $v1, 0x304($v1)
    ctx->r3 = MEM_W(0X304, ctx->r3);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(0X4, ctx->r3);
    // addiu       $v0, $v0, 0x7BCC
    ctx->r2 = ADD32(ctx->r2, 0X7BCC);
    // sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a3, $v0, -0x70D8
    ctx->r7 = ADD32(ctx->r2, -0X70D8);
    // addu        $v0, $a2, $a3
    ctx->r2 = ADD32(ctx->r6, ctx->r7);
    // sh          $zero, 0x98($s0)
    MEM_H(0X98, ctx->r16) = 0;
    // sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // lw          $v0, 0xF8($v0)
    ctx->r2 = MEM_W(0XF8, ctx->r2);
    // lw          $v1, 0x28($gp)
    ctx->r3 = MEM_W(0X28, ctx->r28);
    // lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(0X6, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80021F50
    if (ctx->r2 != 0) {
        // sw          $v1, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->r3;
        goto L_80021F50;
    }
    // sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
    // addiu       $v0, $s0, 0xA8
    ctx->r2 = ADD32(ctx->r16, 0XA8);
    // lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(0X0, ctx->r2);
    // lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(0X4, ctx->r2);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(0X8, ctx->r2);
    // lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(0XC, ctx->r2);
    // lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(0X10, ctx->r2);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(0X14, ctx->r2);
    // lw          $t5, 0x18($v0)
    ctx->r13 = MEM_W(0X18, ctx->r2);
    // ctc2        $t4, $5
    gte_ctc2(ctx, 12, 5);
    // lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(0X1C, ctx->r2);
    // ctc2        $t5, $6
    gte_ctc2(ctx, 13, 6);
    // ctc2        $t6, $7
    gte_ctc2(ctx, 14, 7);
    // addu        $v0, $a2, $t2
    ctx->r2 = ADD32(ctx->r6, ctx->r10);
    // ori         $v1, $zero, 0x83CC
    ctx->r3 = 0 | 0X83CC;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // addiu       $a0, $a3, 0x108
    ctx->r4 = ADD32(ctx->r7, 0X108);
    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // addu        $a0, $a2, $a0
    ctx->r4 = ADD32(ctx->r6, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // lbu         $a2, 0x150($v0)
    ctx->r6 = MEM_BU(0X150, ctx->r2);
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // lh          $a3, 0x130($v0)
    ctx->r7 = MEM_HS(0X130, ctx->r2);
    // jal         0x80034604
    // addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    sub_80034604(rdram, ctx);
    goto after_2;
    // addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_2:
    // beq         $v0, $zero, L_80021FA4
    if (ctx->r2 == 0) {
        // lui         $v1, 0x8016
        ctx->r3 = S32(0X8016 << 16);
        goto L_80021FA4;
    }
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // lw          $a3, 0x40($s0)
    ctx->r7 = MEM_W(0X40, ctx->r16);
    // lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(0X20, ctx->r16);
    // lw          $v0, 0x88($s0)
    ctx->r2 = MEM_W(0X88, ctx->r16);
    // lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(0X20, ctx->r16);
    // lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(0X4, ctx->r3);
    // lw          $t0, 0x48($s0)
    ctx->r8 = MEM_W(0X48, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
    // lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(0X4, ctx->r4);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // beq         $a2, $v0, L_80021F3C
    if (ctx->r6 == ctx->r2) {
        // addiu       $t2, $zero, 0xFE1
        ctx->r10 = ADD32(0, 0XFE1);
        goto L_80021F3C;
    }
    // addiu       $t2, $zero, 0xFE1
    ctx->r10 = ADD32(0, 0XFE1);
    // addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // addiu       $a1, $a3, 0x6
    ctx->r5 = ADD32(ctx->r7, 0X6);
L_80021E80:
    // lwc2        $0, 0x0($t0)
    gte_lwc2(rdram, ctx, 0, 8, 0);
    // lwc2        $1, 0x4($t0)
    gte_lwc2(rdram, ctx, 1, 8, 4);
    // nop

    // nop

    // .word       0x4A180001                   # INVALID     $s0, $t8, 0x1 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A180001);
    // swc2        $14, 0x0($a3)
    gte_swc2(rdram, ctx, 14, 7, 0);
    // addiu       $v0, $a3, 0x4
    ctx->r2 = ADD32(ctx->r7, 0X4);
    // swc2        $19, 0x0($v0)
    gte_swc2(rdram, ctx, 19, 2, 0);
    // lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(0X64, ctx->r16);
    // lw          $v1, 0x68($s0)
    ctx->r3 = MEM_W(0X68, ctx->r16);
    // nop

    // beq         $a0, $v1, L_80021EF8
    if (ctx->r4 == ctx->r3) {
        // subu        $v1, $v1, $a0
        ctx->r3 = SUB32(ctx->r3, ctx->r4);
        goto L_80021EF8;
    }
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // lh          $v0, -0x2($a1)
    ctx->r2 = MEM_HS(-0X2, ctx->r5);
    // nop

    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_80021ED4
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80021ED4;
    }
    // nop

    // break       7
    do_break(2147622608);
L_80021ED4:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_80021EEC
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80021EEC;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80021EEC
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80021EEC;
    }
    // nop

    // break       6
    do_break(2147622632);
L_80021EEC:
    // mflo        $v0
    ctx->r2 = lo;
    // j           L_80021EFC
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    goto L_80021EFC;
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_80021EF8:
    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_80021EFC:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // slti        $v0, $v0, 0xFE2
    ctx->r2 = SIGNED(ctx->r2) < 0XFE2 ? 1 : 0;
    // bne         $v0, $zero, L_80021F14
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80021F14;
    }
    // nop

    // sh          $t2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r10;
L_80021F14:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // bgez        $v0, L_80021F28
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80021F28;
    }
    // nop

    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_80021F28:
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // bne         $a2, $t1, L_80021E80
    if (ctx->r6 != ctx->r9) {
        // addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
        goto L_80021E80;
    }
    // addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_80021F3C:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80019DC8
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    sub_80019DC8(rdram, ctx);
    goto after_3;
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_3:
    // j           L_80021FA4
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    goto L_80021FA4;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
L_80021F50:
    // addu        $v0, $a2, $t2
    ctx->r2 = ADD32(ctx->r6, ctx->r10);
    // ori         $v1, $zero, 0x83CC
    ctx->r3 = 0 | 0X83CC;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // addiu       $a0, $a3, 0x108
    ctx->r4 = ADD32(ctx->r7, 0X108);
    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // addu        $a0, $a2, $a0
    ctx->r4 = ADD32(ctx->r6, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // lbu         $a2, 0x150($v0)
    ctx->r6 = MEM_BU(0X150, ctx->r2);
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // lh          $a3, 0x130($v0)
    ctx->r7 = MEM_HS(0X130, ctx->r2);
    // jal         0x80035AA8
    // addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    sub_80035AA8(rdram, ctx);
    goto after_4;
    // addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_4:
    // beq         $v0, $zero, L_80021FA0
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x80
        ctx->r4 = ADD32(0, 0X80);
        goto L_80021FA0;
    }
    // addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // jal         0x80022010
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_80022010(rdram, ctx);
    goto after_5;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
L_80021FA0:
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
L_80021FA4:
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $a0, 0x304($v1)
    ctx->r4 = MEM_W(0X304, ctx->r3);
    // lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(0X10, ctx->r16);
    // nop

    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // lw          $a0, 0x304($v1)
    ctx->r4 = MEM_W(0X304, ctx->r3);
    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // nop

    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // lw          $v0, 0x88($s0)
    ctx->r2 = MEM_W(0X88, ctx->r16);
    // lw          $a0, 0x8C($s0)
    ctx->r4 = MEM_W(0X8C, ctx->r16);
    // lw          $a1, 0x94($s0)
    ctx->r5 = MEM_W(0X94, ctx->r16);
    // lw          $a2, 0x90($s0)
    ctx->r6 = MEM_W(0X90, ctx->r16);
    // sw          $v0, 0x31C($v1)
    MEM_W(0X31C, ctx->r3) = ctx->r2;
    // sw          $a0, 0x320($v1)
    MEM_W(0X320, ctx->r3) = ctx->r4;
    // sw          $a1, 0x328($v1)
    MEM_W(0X328, ctx->r3) = ctx->r5;
    // sw          $a2, 0x324($v1)
    MEM_W(0X324, ctx->r3) = ctx->r6;
L_80021FF0:
    // lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(0X48, ctx->r29);
    // lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(0X44, ctx->r29);
    // lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(0X40, ctx->r29);
    // lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(0X3C, ctx->r29);
    // lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
