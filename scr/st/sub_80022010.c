#include "recomp.h"
#include "disable_warnings.h"

void sub_80022010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // sw          $s3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r19;
    // lui         $s3, 0x1F80
    ctx->r19 = S32(0X1F80 << 16);
    // sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r30;
    // sw          $s7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r23;
    // sw          $s6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r22;
    // sw          $s5, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r20;
    // sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
    // sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    // sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // lw          $v0, 0xA4($s3)
    ctx->r2 = MEM_W(0XA4, ctx->r19);
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(0X0, ctx->r2);
    // lw          $s2, 0x4($v0)
    ctx->r18 = MEM_W(0X4, ctx->r2);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x1010
    ctx->r6 = ADD32(ctx->r2, 0X1010);
    // lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(0X0, ctx->r6);
    // lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(0X4, ctx->r6);
    // lw          $a1, 0x8($a2)
    ctx->r5 = MEM_W(0X8, ctx->r6);
    // sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(0XC, ctx->r6);
    // lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(0X10, ctx->r6);
    // lw          $a1, 0x14($a2)
    ctx->r5 = MEM_W(0X14, ctx->r6);
    // sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // lw          $v1, 0x18($a2)
    ctx->r3 = MEM_W(0X18, ctx->r6);
    // lw          $a0, 0x1C($a2)
    ctx->r4 = MEM_W(0X1C, ctx->r6);
    // sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // beq         $s2, $v0, L_800220C4
    if (ctx->r18 == ctx->r2) {
        // nop
    
        goto L_800220C4;
    }
    // nop

    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_800220B0:
    // lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(0X4, ctx->r7);
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // bne         $s2, $v1, L_800220B0
    if (ctx->r18 != ctx->r3) {
        // sh          $zero, 0x0($v0)
        MEM_H(0X0, ctx->r2) = 0;
        goto L_800220B0;
    }
    // sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_800220C4:
    // lw          $v0, 0xA4($s3)
    ctx->r2 = MEM_W(0XA4, ctx->r19);
    // nop

    // lw          $s2, 0x4($v0)
    ctx->r18 = MEM_W(0X4, ctx->r2);
    // lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(0X0, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // beq         $s2, $v0, L_80022644
    if (ctx->r18 == ctx->r2) {
        // addu        $fp, $v0, $zero
        ctx->r30 = ADD32(ctx->r2, 0);
        goto L_80022644;
    }
    // addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
    // addiu       $s5, $sp, 0x50
    ctx->r21 = ADD32(ctx->r29, 0X50);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s7, $v0, -0x70D8
    ctx->r23 = ADD32(ctx->r2, -0X70D8);
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // addiu       $s6, $v0, 0x5090
    ctx->r22 = ADD32(ctx->r2, 0X5090);
    // addiu       $s1, $a3, 0x8
    ctx->r17 = ADD32(ctx->r7, 0X8);
L_800220FC:
    // lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(-0X4, ctx->r17);
    // nop

    // sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // beq         $v0, $fp, L_80022634
    if (ctx->r2 == ctx->r30) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80022634;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // nop

    // beq         $v1, $v0, L_80022634
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_80022634;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // lbu         $v1, 0x2($s1)
    ctx->r3 = MEM_BU(0X2, ctx->r17);
    // nop

    // bne         $v1, $v0, L_80022338
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_80022338;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x1010
    ctx->r6 = ADD32(ctx->r2, 0X1010);
    // lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(0X0, ctx->r6);
    // lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(0X4, ctx->r6);
    // lw          $a1, 0x8($a2)
    ctx->r5 = MEM_W(0X8, ctx->r6);
    // sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    // sw          $a1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r5;
    // lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(0XC, ctx->r6);
    // lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(0X10, ctx->r6);
    // lw          $a1, 0x14($a2)
    ctx->r5 = MEM_W(0X14, ctx->r6);
    // sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    // sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // lw          $v1, 0x18($a2)
    ctx->r3 = MEM_W(0X18, ctx->r6);
    // lw          $a0, 0x1C($a2)
    ctx->r4 = MEM_W(0X1C, ctx->r6);
    // sw          $v1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r3;
    // sw          $a0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r4;
    // lhu         $v0, 0x268($s7)
    ctx->r2 = MEM_HU(0X268, ctx->r23);
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sh          $v0, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x26A($s7)
    ctx->r2 = MEM_HU(0X26A, ctx->r23);
    // lhu         $v1, 0x26C($s7)
    ctx->r3 = MEM_HU(0X26C, ctx->r23);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // sh          $v0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r2;
    // jal         0x800753E4
    // sh          $v1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r3;
    RotMatrixX(rdram, ctx);
    goto after_0;
    // sh          $v1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r3;
    after_0:
    // lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(0XA4, ctx->r29);
    // lh          $v0, 0x72($sp)
    ctx->r2 = MEM_HS(0X72, ctx->r29);
    // lh          $a0, 0x2($t3)
    ctx->r4 = MEM_HS(0X2, ctx->r11);
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // jal         0x80075584
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    RotMatrixY(rdram, ctx);
    goto after_1;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_1:
    // lh          $a0, 0x74($sp)
    ctx->r4 = MEM_HS(0X74, ctx->r29);
    // jal         0x80075724
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    RotMatrixZ(rdram, ctx);
    goto after_2;
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_2:
    // lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(-0X4, ctx->r17);
    // nop

    // lw          $a1, 0x48($v0)
    ctx->r5 = MEM_W(0X48, ctx->r2);
    // nop

    // lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(0X2, ctx->r5);
    // nop

    // bne         $v0, $zero, L_80022204
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80022204;
    }
    // nop

    // lw          $a0, 0x44($a1)
    ctx->r4 = MEM_W(0X44, ctx->r5);
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // jal         0x80074EC4
    // addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    RotMatrix(rdram, ctx);
    goto after_3;
    // addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_3:
L_80022204:
    // lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(-0X4, ctx->r17);
    // nop

    // lw          $v0, 0x48($v0)
    ctx->r2 = MEM_W(0X48, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
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
    // lhu         $t4, 0x0($s5)
    ctx->r12 = MEM_HU(0X0, ctx->r21);
    // lhu         $t5, 0x6($s5)
    ctx->r13 = MEM_HU(0X6, ctx->r21);
    // lhu         $t6, 0xC($s5)
    ctx->r14 = MEM_HU(0XC, ctx->r21);
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
    // addiu       $v0, $sp, 0x52
    ctx->r2 = ADD32(ctx->r29, 0X52);
    // lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(0X0, ctx->r2);
    // lhu         $t5, 0x6($v0)
    ctx->r13 = MEM_HU(0X6, ctx->r2);
    // lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(0XC, ctx->r2);
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
    // lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(-0X4, ctx->r17);
    // nop

    // lw          $v0, 0x48($v0)
    ctx->r2 = MEM_W(0X48, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
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
    // addiu       $v0, $sp, 0x54
    ctx->r2 = ADD32(ctx->r29, 0X54);
    // lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(0X0, ctx->r2);
    // lhu         $t5, 0x6($v0)
    ctx->r13 = MEM_HU(0X6, ctx->r2);
    // lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(0XC, ctx->r2);
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
    // lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(-0X4, ctx->r17);
    // nop

    // lw          $v0, 0x48($v0)
    ctx->r2 = MEM_W(0X48, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
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
    // lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(-0X4, ctx->r17);
    // nop

    // lw          $v0, 0x48($v0)
    ctx->r2 = MEM_W(0X48, ctx->r2);
    // nop

    // sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
L_80022338:
    // lw          $a0, -0x4($s1)
    ctx->r4 = MEM_W(-0X4, ctx->r17);
    // jal         0x80035260
    // nop

    sub_80035260(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lbu         $v1, 0x2($s1)
    ctx->r3 = MEM_BU(0X2, ctx->r17);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_800223F4
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_800223F4;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // lui         $v0, 0x2AAA
    ctx->r2 = S32(0X2AAA << 16);
    // ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // mult        $s2, $v0
    result = S64(S32(ctx->r18)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v1
    ctx->r3 = hi;
    // lbu         $a1, 0x6CC0($s6)
    ctx->r5 = MEM_BU(0X6CC0, ctx->r22);
    // lui         $v0, 0xAAAA
    ctx->r2 = S32(0XAAAA << 16);
    // ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // multu       $a1, $v0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $s2, 31
    ctx->r2 = S32(ctx->r18) >> 31;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // subu        $v1, $s2, $v1
    ctx->r3 = SUB32(ctx->r18, ctx->r3);
    // mfhi        $a0
    ctx->r4 = hi;
    // srl         $a0, $a0, 2
    ctx->r4 = S32(U32(ctx->r4) >> 2);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // bne         $v1, $a1, L_80022634
    if (ctx->r3 != ctx->r5) {
        // addiu       $s0, $sp, 0x30
        ctx->r16 = ADD32(ctx->r29, 0X30);
        goto L_80022634;
    }
    // addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(-0X4, ctx->r17);
    // nop

    // lw          $a1, 0x44($v0)
    ctx->r5 = MEM_W(0X44, ctx->r2);
    // jal         0x80074D84
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    ScaleMatrix(rdram, ctx);
    goto after_5;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(0X0, ctx->r16);
    // lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(0X4, ctx->r16);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(0X8, ctx->r16);
    // lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(0XC, ctx->r16);
    // lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(0X10, ctx->r16);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // j           L_800224D4
    // nop

    goto L_800224D4;
    // nop

L_800223F4:
    // bne         $v1, $v0, L_80022468
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_80022468;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // bgez        $s2, L_80022408
    if (SIGNED(ctx->r18) >= 0) {
        // addu        $v1, $s2, $zero
        ctx->r3 = ADD32(ctx->r18, 0);
        goto L_80022408;
    }
    // addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
    // addiu       $v1, $s2, 0x3
    ctx->r3 = ADD32(ctx->r18, 0X3);
L_80022408:
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lbu         $v0, 0x6CC0($s6)
    ctx->r2 = MEM_BU(0X6CC0, ctx->r22);
    // subu        $v1, $s2, $v1
    ctx->r3 = SUB32(ctx->r18, ctx->r3);
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // bne         $v1, $v0, L_80022634
    if (ctx->r3 != ctx->r2) {
        // addiu       $s0, $sp, 0x30
        ctx->r16 = ADD32(ctx->r29, 0X30);
        goto L_80022634;
    }
    // addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(-0X4, ctx->r17);
    // nop

    // lw          $a1, 0x44($v0)
    ctx->r5 = MEM_W(0X44, ctx->r2);
    // jal         0x80074D84
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    ScaleMatrix(rdram, ctx);
    goto after_6;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(0X0, ctx->r16);
    // lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(0X4, ctx->r16);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(0X8, ctx->r16);
    // lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(0XC, ctx->r16);
    // lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(0X10, ctx->r16);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // j           L_800224D4
    // nop

    goto L_800224D4;
    // nop

L_80022468:
    // bne         $v1, $v0, L_800224D4
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800224D4;
    }
    // nop

    // bgez        $s2, L_8002247C
    if (SIGNED(ctx->r18) >= 0) {
        // addu        $v1, $s2, $zero
        ctx->r3 = ADD32(ctx->r18, 0);
        goto L_8002247C;
    }
    // addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
    // addiu       $v1, $s2, 0x7
    ctx->r3 = ADD32(ctx->r18, 0X7);
L_8002247C:
    // sra         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) >> 3;
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // lbu         $v0, 0x6CC0($s6)
    ctx->r2 = MEM_BU(0X6CC0, ctx->r22);
    // subu        $v1, $s2, $v1
    ctx->r3 = SUB32(ctx->r18, ctx->r3);
    // andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // bne         $v1, $v0, L_80022634
    if (ctx->r3 != ctx->r2) {
        // addiu       $s0, $sp, 0x30
        ctx->r16 = ADD32(ctx->r29, 0X30);
        goto L_80022634;
    }
    // addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // lw          $v0, -0x4($s1)
    ctx->r2 = MEM_W(-0X4, ctx->r17);
    // nop

    // lw          $a1, 0x44($v0)
    ctx->r5 = MEM_W(0X44, ctx->r2);
    // jal         0x80074D84
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    ScaleMatrix(rdram, ctx);
    goto after_7;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(0X0, ctx->r16);
    // lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(0X4, ctx->r16);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(0X8, ctx->r16);
    // lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(0XC, ctx->r16);
    // lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(0X10, ctx->r16);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
L_800224D4:
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // lw          $a3, 0x40($s3)
    ctx->r7 = MEM_W(0X40, ctx->r19);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lw          $v1, 0xC($s3)
    ctx->r3 = MEM_W(0XC, ctx->r19);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r3;
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // lw          $v0, 0xC($s3)
    ctx->r2 = MEM_W(0XC, ctx->r19);
    // lw          $a0, 0x20($s3)
    ctx->r4 = MEM_W(0X20, ctx->r19);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->r2;
    // lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(0X4, ctx->r4);
    // nop

    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // beq         $a2, $fp, L_800225EC
    if (ctx->r6 == ctx->r30) {
        // addu        $t0, $v0, $zero
        ctx->r8 = ADD32(ctx->r2, 0);
        goto L_800225EC;
    }
    // addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // addiu       $t2, $zero, 0xFE1
    ctx->r10 = ADD32(0, 0XFE1);
    // addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // addiu       $a1, $a3, 0x6
    ctx->r5 = ADD32(ctx->r7, 0X6);
L_80022530:
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
    // lw          $a0, 0x64($s3)
    ctx->r4 = MEM_W(0X64, ctx->r19);
    // lw          $v0, 0x68($s3)
    ctx->r2 = MEM_W(0X68, ctx->r19);
    // nop

    // beq         $a0, $v0, L_800225A8
    if (ctx->r4 == ctx->r2) {
        // subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
        goto L_800225A8;
    }
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // lh          $v1, -0x2($a1)
    ctx->r3 = MEM_HS(-0X2, ctx->r5);
    // nop

    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80022584
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80022584;
    }
    // nop

    // break       7
    do_break(2147624320);
L_80022584:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8002259C
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8002259C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8002259C
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8002259C;
    }
    // nop

    // break       6
    do_break(2147624344);
L_8002259C:
    // mflo        $v1
    ctx->r3 = lo;
    // j           L_800225AC
    // sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    goto L_800225AC;
    // sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_800225A8:
    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_800225AC:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // slti        $v0, $v0, 0xFE2
    ctx->r2 = SIGNED(ctx->r2) < 0XFE2 ? 1 : 0;
    // bne         $v0, $zero, L_800225C4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800225C4;
    }
    // nop

    // sh          $t2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r10;
L_800225C4:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // bgez        $v0, L_800225D8
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800225D8;
    }
    // nop

    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_800225D8:
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // bne         $a2, $t1, L_80022530
    if (ctx->r6 != ctx->r9) {
        // addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
        goto L_80022530;
    }
    // addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_800225EC:
    // andi        $v0, $s4, 0x40
    ctx->r2 = ctx->r20 & 0X40;
    // beq         $v0, $zero, L_8002260C
    if (ctx->r2 == 0) {
        // andi        $v0, $s4, 0x80
        ctx->r2 = ctx->r20 & 0X80;
        goto L_8002260C;
    }
    // andi        $v0, $s4, 0x80
    ctx->r2 = ctx->r20 & 0X80;
    // lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(0X0, ctx->r17);
    // jal         0x8001BF10
    // andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    sub_8001BF10(rdram, ctx);
    goto after_8;
    // andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    after_8:
    // j           L_80022638
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    goto L_80022638;
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_8002260C:
    // beq         $v0, $zero, L_80022628
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80022628;
    }
    // nop

    // lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(0X0, ctx->r17);
    // jal         0x800192D4
    // andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    sub_800192D4(rdram, ctx);
    goto after_9;
    // andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    after_9:
    // j           L_80022638
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    goto L_80022638;
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_80022628:
    // lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(0X0, ctx->r17);
    // jal         0x80019DC8
    // andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    sub_80019DC8(rdram, ctx);
    goto after_10;
    // andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    after_10:
L_80022634:
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_80022638:
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // bne         $s2, $fp, L_800220FC
    if (ctx->r18 != ctx->r30) {
        // nop
    
        goto L_800220FC;
    }
    // nop

L_80022644:
    // lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(0X9C, ctx->r29);
    // lw          $fp, 0x98($sp)
    ctx->r30 = MEM_W(0X98, ctx->r29);
    // lw          $s7, 0x94($sp)
    ctx->r23 = MEM_W(0X94, ctx->r29);
    // lw          $s6, 0x90($sp)
    ctx->r22 = MEM_W(0X90, ctx->r29);
    // lw          $s5, 0x8C($sp)
    ctx->r21 = MEM_W(0X8C, ctx->r29);
    // lw          $s4, 0x88($sp)
    ctx->r20 = MEM_W(0X88, ctx->r29);
    // lw          $s3, 0x84($sp)
    ctx->r19 = MEM_W(0X84, ctx->r29);
    // lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(0X80, ctx->r29);
    // lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(0X7C, ctx->r29);
    // lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(0X78, ctx->r29);
    // addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // jr          $ra
    // nop

    return;
    // nop

;}
