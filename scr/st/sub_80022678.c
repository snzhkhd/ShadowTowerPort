#include "recomp.h"
#include "disable_warnings.h"

void sub_80022678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // sw          $s1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sw          $s0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r16;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // sw          $s7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r23;
    // lw          $s7, 0xE0($sp)
    ctx->r23 = MEM_W(0XE0, ctx->r29);
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // sw          $fp, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r30;
    // lw          $fp, 0xE8($sp)
    ctx->r30 = MEM_W(0XE8, ctx->r29);
    // lw          $t2, 0xFC($sp)
    ctx->r10 = MEM_W(0XFC, ctx->r29);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // sw          $s5, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r21;
    // lhu         $s5, 0xEC($sp)
    ctx->r21 = MEM_HU(0XEC, ctx->r29);
    // lhu         $t3, 0xF0($sp)
    ctx->r11 = MEM_HU(0XF0, ctx->r29);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // sw          $s2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r18;
    // lhu         $s2, 0xF4($sp)
    ctx->r18 = MEM_HU(0XF4, ctx->r29);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $ra, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r31;
    // sw          $s6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r22;
    // sw          $s4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r20;
    // sw          $s3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r19;
    // sw          $a3, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r7;
    // sh          $t3, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r11;
    // lw          $a2, 0x31C($v1)
    ctx->r6 = MEM_W(0X31C, ctx->r3);
    // lw          $a3, 0x320($v1)
    ctx->r7 = MEM_W(0X320, ctx->r3);
    // lw          $t0, 0x324($v1)
    ctx->r8 = MEM_W(0X324, ctx->r3);
    // lw          $t1, 0x328($v1)
    ctx->r9 = MEM_W(0X328, ctx->r3);
    // lw          $v0, 0x304($v1)
    ctx->r2 = MEM_W(0X304, ctx->r3);
    // addiu       $a0, $a0, 0x7BCC
    ctx->r4 = ADD32(ctx->r4, 0X7BCC);
    // sw          $a0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r4;
    // sw          $a0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r4;
    // sw          $a2, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r6;
    // sw          $a3, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r7;
    // sw          $t0, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r8;
    // sw          $t1, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r9;
    // lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(0X8, ctx->r2);
    // nop

    // sw          $a0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r4;
    // lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(0X4, ctx->r2);
    // addu        $s4, $t2, $zero
    ctx->r20 = ADD32(ctx->r10, 0);
    // addiu       $v0, $v1, -0x7800
    ctx->r2 = ADD32(ctx->r3, -0X7800);
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // beq         $v0, $zero, L_8002273C
    if (ctx->r2 == 0) {
        // sh          $a1, 0x9C($sp)
        MEM_H(0X9C, ctx->r29) = ctx->r5;
        goto L_8002273C;
    }
    // sh          $a1, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r5;
    // andi        $s4, $t2, 0xBF
    ctx->r20 = ctx->r10 & 0XBF;
L_8002273C:
    // sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // beq         $v0, $zero, L_80022764
    if (ctx->r2 == 0) {
        // ori         $a0, $zero, 0xFFFF
        ctx->r4 = 0 | 0XFFFF;
        goto L_80022764;
    }
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x8003F12C
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_8003F12C(rdram, ctx);
    goto after_0;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_0:
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // jal         0x8003F12C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_8003F12C(rdram, ctx);
    goto after_1;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
L_80022764:
    // lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // addiu       $t3, $t3, -0x4288
    ctx->r11 = ADD32(ctx->r11, -0X4288);
    // lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(0X0, ctx->r11);
    // lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(0X4, ctx->r11);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(0X8, ctx->r11);
    // lw          $t5, 0xC($t3)
    ctx->r13 = MEM_W(0XC, ctx->r11);
    // lw          $t6, 0x10($t3)
    ctx->r14 = MEM_W(0X10, ctx->r11);
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
    // lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(0X14, ctx->r11);
    // lw          $t5, 0x18($t3)
    ctx->r13 = MEM_W(0X18, ctx->r11);
    // ctc2        $t4, $5
    gte_ctc2(ctx, 12, 5);
    // lw          $t6, 0x1C($t3)
    ctx->r14 = MEM_W(0X1C, ctx->r11);
    // ctc2        $t5, $6
    gte_ctc2(ctx, 13, 6);
    // ctc2        $t6, $7
    gte_ctc2(ctx, 14, 7);
    // beq         $fp, $zero, L_8002288C
    if (ctx->r30 == 0) {
        // lui         $a1, 0x801A
        ctx->r5 = S32(0X801A << 16);
        goto L_8002288C;
    }
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x70D8
    ctx->r5 = ADD32(ctx->r5, -0X70D8);
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // lw          $a0, 0x248($a1)
    ctx->r4 = MEM_W(0X248, ctx->r5);
    // lh          $a2, 0x2CE($a1)
    ctx->r6 = MEM_HS(0X2CE, ctx->r5);
    // lw          $v1, 0x24C($a1)
    ctx->r3 = MEM_W(0X24C, ctx->r5);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lh          $a0, 0x2D2($a1)
    ctx->r4 = MEM_HS(0X2D2, ctx->r5);
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(0X8, ctx->r17);
    // lw          $v1, 0x250($a1)
    ctx->r3 = MEM_W(0X250, ctx->r5);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lhu         $a2, 0x2CE($a1)
    ctx->r6 = MEM_HU(0X2CE, ctx->r5);
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // lhu         $v1, 0x248($a1)
    ctx->r3 = MEM_HU(0X248, ctx->r5);
    // lhu         $a0, 0x24C($a1)
    ctx->r4 = MEM_HU(0X24C, ctx->r5);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x2D2($a1)
    ctx->r2 = MEM_HU(0X2D2, ctx->r5);
    // lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(0X4, ctx->r17);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sh          $v1, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r3;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // lhu         $v1, 0x250($a1)
    ctx->r3 = MEM_HU(0X250, ctx->r5);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // nop

    // nop

    // .word       0x4A480012                   # INVALID     $s2, $t0, 0x12 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A480012);
    // lui         $t3, 0x1F80
    ctx->r11 = S32(0X1F80 << 16);
    // ori         $t3, $t3, 0xBC
    ctx->r11 = ctx->r11 | 0XBC;
    // swc2        $25, 0x0($t3)
    gte_swc2(rdram, ctx, 25, 11, 0);
    // swc2        $26, 0x4($t3)
    gte_swc2(rdram, ctx, 26, 11, 4);
    // swc2        $27, 0x8($t3)
    gte_swc2(rdram, ctx, 27, 11, 8);
    // addiu       $v0, $sp, 0x98
    ctx->r2 = ADD32(ctx->r29, 0X98);
    // cfc2        $t4, $31
    ctx->r12 = gte_cfc2(ctx, 31);
    // nop

    // sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // j           L_800228B4
    // addiu       $s1, $s0, 0xA8
    ctx->r17 = ADD32(ctx->r16, 0XA8);
    goto L_800228B4;
    // addiu       $s1, $s0, 0xA8
    ctx->r17 = ADD32(ctx->r16, 0XA8);
L_8002288C:
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // sw          $v0, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // sw          $v0, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->r2;
    // lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(0X8, ctx->r17);
    // nop

    // sw          $v0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->r2;
    // addiu       $s1, $s0, 0xA8
    ctx->r17 = ADD32(ctx->r16, 0XA8);
L_800228B4:
    // lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(0XDC, ctx->r29);
    // jal         0x80049E30
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    sub_80049E30(rdram, ctx);
    goto after_2;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
    // sll         $a0, $s2, 16
    ctx->r4 = S32(ctx->r18) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // andi        $s6, $s4, 0xFF
    ctx->r22 = ctx->r20 & 0XFF;
    // jal         0x80017D28
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    sub_80017D28(rdram, ctx);
    goto after_3;
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_3:
    // lw          $t3, 0x394($s0)
    ctx->r11 = MEM_W(0X394, ctx->r16);
    // nop

    // lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(0X0, ctx->r11);
    // lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(0X4, ctx->r11);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(0X8, ctx->r11);
    // lw          $t5, 0xC($t3)
    ctx->r13 = MEM_W(0XC, ctx->r11);
    // lw          $t6, 0x10($t3)
    ctx->r14 = MEM_W(0X10, ctx->r11);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lhu         $t4, 0x0($s1)
    ctx->r12 = MEM_HU(0X0, ctx->r17);
    // lhu         $t5, 0x6($s1)
    ctx->r13 = MEM_HU(0X6, ctx->r17);
    // lhu         $t6, 0xC($s1)
    ctx->r14 = MEM_HU(0XC, ctx->r17);
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
    // addiu       $v1, $sp, 0x58
    ctx->r3 = ADD32(ctx->r29, 0X58);
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
    // addiu       $s3, $s0, 0xAA
    ctx->r19 = ADD32(ctx->r16, 0XAA);
    // lhu         $t4, 0x0($s3)
    ctx->r12 = MEM_HU(0X0, ctx->r19);
    // lhu         $t5, 0x6($s3)
    ctx->r13 = MEM_HU(0X6, ctx->r19);
    // lhu         $t6, 0xC($s3)
    ctx->r14 = MEM_HU(0XC, ctx->r19);
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
    // addiu       $v0, $sp, 0x5A
    ctx->r2 = ADD32(ctx->r29, 0X5A);
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
    // addiu       $s2, $s0, 0xAC
    ctx->r18 = ADD32(ctx->r16, 0XAC);
    // lhu         $t4, 0x0($s2)
    ctx->r12 = MEM_HU(0X0, ctx->r18);
    // lhu         $t5, 0x6($s2)
    ctx->r13 = MEM_HU(0X6, ctx->r18);
    // lhu         $t6, 0xC($s2)
    ctx->r14 = MEM_HU(0XC, ctx->r18);
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
    // addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
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
    // beq         $s7, $zero, L_80022A24
    if (ctx->r23 == 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_80022A24;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lh          $v0, 0x0($s7)
    ctx->r2 = MEM_HS(0X0, ctx->r23);
    // nop

    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lh          $v0, 0x2($s7)
    ctx->r2 = MEM_HS(0X2, ctx->r23);
    // nop

    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // lh          $v0, 0x4($s7)
    ctx->r2 = MEM_HS(0X4, ctx->r23);
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // jal         0x80074D84
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    ScaleMatrix(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_4:
L_80022A24:
    // beq         $fp, $zero, L_80022B08
    if (ctx->r30 == 0) {
        // nop
    
        goto L_80022B08;
    }
    // nop

    // lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(0X0, ctx->r30);
    // lw          $t5, 0x4($fp)
    ctx->r13 = MEM_W(0X4, ctx->r30);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($fp)
    ctx->r12 = MEM_W(0X8, ctx->r30);
    // lw          $t5, 0xC($fp)
    ctx->r13 = MEM_W(0XC, ctx->r30);
    // lw          $t6, 0x10($fp)
    ctx->r14 = MEM_W(0X10, ctx->r30);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lhu         $t4, 0x0($s1)
    ctx->r12 = MEM_HU(0X0, ctx->r17);
    // lhu         $t5, 0x6($s1)
    ctx->r13 = MEM_HU(0X6, ctx->r17);
    // lhu         $t6, 0xC($s1)
    ctx->r14 = MEM_HU(0XC, ctx->r17);
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
    // sh          $t4, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r12;
    // sh          $t5, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r13;
    // sh          $t6, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r14;
    // lhu         $t4, 0x0($s3)
    ctx->r12 = MEM_HU(0X0, ctx->r19);
    // lhu         $t5, 0x6($s3)
    ctx->r13 = MEM_HU(0X6, ctx->r19);
    // lhu         $t6, 0xC($s3)
    ctx->r14 = MEM_HU(0XC, ctx->r19);
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
    // sh          $t4, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r12;
    // sh          $t5, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r13;
    // sh          $t6, 0xC($s3)
    MEM_H(0XC, ctx->r19) = ctx->r14;
    // lhu         $t4, 0x0($s2)
    ctx->r12 = MEM_HU(0X0, ctx->r18);
    // lhu         $t5, 0x6($s2)
    ctx->r13 = MEM_HU(0X6, ctx->r18);
    // lhu         $t6, 0xC($s2)
    ctx->r14 = MEM_HU(0XC, ctx->r18);
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
    // sh          $t4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r12;
    // sh          $t5, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r13;
    // sh          $t6, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r14;
L_80022B08:
    // lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(0X0, ctx->r17);
    // lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(0X4, ctx->r17);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($s1)
    ctx->r12 = MEM_W(0X8, ctx->r17);
    // lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(0XC, ctx->r17);
    // lw          $t6, 0x10($s1)
    ctx->r14 = MEM_W(0X10, ctx->r17);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lw          $t4, 0x14($s1)
    ctx->r12 = MEM_W(0X14, ctx->r17);
    // lw          $t5, 0x18($s1)
    ctx->r13 = MEM_W(0X18, ctx->r17);
    // ctc2        $t4, $5
    gte_ctc2(ctx, 12, 5);
    // lw          $t6, 0x1C($s1)
    ctx->r14 = MEM_W(0X1C, ctx->r17);
    // ctc2        $t5, $6
    gte_ctc2(ctx, 13, 6);
    // ctc2        $t6, $7
    gte_ctc2(ctx, 14, 7);
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // lhu         $a1, 0x9C($sp)
    ctx->r5 = MEM_HU(0X9C, ctx->r29);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // ori         $v1, $zero, 0x834C
    ctx->r3 = 0 | 0X834C;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // nop

    // lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(0X6, ctx->r3);
    // nop

    // bne         $v0, $zero, L_80022BD4
    if (ctx->r2 != 0) {
        // andi        $a2, $s5, 0xFFFF
        ctx->r6 = ctx->r21 & 0XFFFF;
        goto L_80022BD4;
    }
    // andi        $a2, $s5, 0xFFFF
    ctx->r6 = ctx->r21 & 0XFFFF;
    // lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(0X8, ctx->r3);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sltiu       $v0, $a2, 0x80
    ctx->r2 = ctx->r6 < 0X80 ? 1 : 0;
    // beq         $v0, $zero, L_80022C40
    if (ctx->r2 == 0) {
        // sw          $v1, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r3;
        goto L_80022C40;
    }
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // addiu       $v0, $v1, 0xC
    ctx->r2 = ADD32(ctx->r3, 0XC);
    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // lhu         $t3, 0xA0($sp)
    ctx->r11 = MEM_HU(0XA0, ctx->r29);
    // lw          $a0, 0xE4($sp)
    ctx->r4 = MEM_W(0XE4, ctx->r29);
    // jal         0x80034604
    // addu        $a3, $t3, $zero
    ctx->r7 = ADD32(ctx->r11, 0);
    sub_80034604(rdram, ctx);
    goto after_5;
    // addu        $a3, $t3, $zero
    ctx->r7 = ADD32(ctx->r11, 0);
    after_5:
    // bne         $v0, $zero, L_80022C74
    if (ctx->r2 != 0) {
        // andi        $v0, $s4, 0x40
        ctx->r2 = ctx->r20 & 0X40;
        goto L_80022C74;
    }
    // andi        $v0, $s4, 0x40
    ctx->r2 = ctx->r20 & 0X40;
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // nop

    // addiu       $v0, $v1, 0xC
    ctx->r2 = ADD32(ctx->r3, 0XC);
    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(0XC, ctx->r3);
    // j           L_80022C68
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    goto L_80022C68;
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_80022BD4:
    // lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(0X8, ctx->r3);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sltiu       $v0, $a2, 0x80
    ctx->r2 = ctx->r6 < 0X80 ? 1 : 0;
    // beq         $v0, $zero, L_80022C40
    if (ctx->r2 == 0) {
        // sw          $v1, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r3;
        goto L_80022C40;
    }
    // sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // lhu         $t3, 0xA0($sp)
    ctx->r11 = MEM_HU(0XA0, ctx->r29);
    // lw          $a0, 0xE4($sp)
    ctx->r4 = MEM_W(0XE4, ctx->r29);
    // jal         0x80035AA8
    // addu        $a3, $t3, $zero
    ctx->r7 = ADD32(ctx->r11, 0);
    sub_80035AA8(rdram, ctx);
    goto after_6;
    // addu        $a3, $t3, $zero
    ctx->r7 = ADD32(ctx->r11, 0);
    after_6:
    // bne         $v0, $zero, L_80022C2C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80022C2C;
    }
    // nop

    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // nop

    // addiu       $v0, $v1, 0xC
    ctx->r2 = ADD32(ctx->r3, 0XC);
    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(0XC, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // j           L_80023184
    // sw          $v1, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r3;
    goto L_80023184;
    // sw          $v1, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r3;
L_80022C2C:
    // lw          $a1, 0xDC($sp)
    ctx->r5 = MEM_W(0XDC, ctx->r29);
    // jal         0x80022010
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    sub_80022010(rdram, ctx);
    goto after_7;
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_7:
    // j           L_80023188
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    goto L_80023188;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
L_80022C40:
    // andi        $s1, $s5, 0x7F
    ctx->r17 = ctx->r21 & 0X7F;
    // sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17) << 2;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_80022C68:
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r3;
    // andi        $v0, $s4, 0x40
    ctx->r2 = ctx->r20 & 0X40;
L_80022C74:
    // beq         $v0, $zero, L_80022E28
    if (ctx->r2 == 0) {
        // andi        $v0, $s4, 0x80
        ctx->r2 = ctx->r20 & 0X80;
        goto L_80022E28;
    }
    // andi        $v0, $s4, 0x80
    ctx->r2 = ctx->r20 & 0X80;
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
    // beq         $a2, $v0, L_80022D74
    if (ctx->r6 == ctx->r2) {
        // addiu       $a1, $a3, 0x6
        ctx->r5 = ADD32(ctx->r7, 0X6);
        goto L_80022D74;
    }
    // addiu       $a1, $a3, 0x6
    ctx->r5 = ADD32(ctx->r7, 0X6);
    // addiu       $t2, $zero, 0xFE1
    ctx->r10 = ADD32(0, 0XFE1);
    // addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
L_80022CB8:
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

    // beq         $a0, $v1, L_80022D30
    if (ctx->r4 == ctx->r3) {
        // subu        $v1, $v1, $a0
        ctx->r3 = SUB32(ctx->r3, ctx->r4);
        goto L_80022D30;
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
    // bne         $v1, $zero, L_80022D0C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80022D0C;
    }
    // nop

    // break       7
    do_break(2147626248);
L_80022D0C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_80022D24
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80022D24;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80022D24
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80022D24;
    }
    // nop

    // break       6
    do_break(2147626272);
L_80022D24:
    // mflo        $v0
    ctx->r2 = lo;
    // j           L_80022D34
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    goto L_80022D34;
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_80022D30:
    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_80022D34:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // slti        $v0, $v0, 0xFE2
    ctx->r2 = SIGNED(ctx->r2) < 0XFE2 ? 1 : 0;
    // bne         $v0, $zero, L_80022D4C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80022D4C;
    }
    // nop

    // sh          $t2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r10;
L_80022D4C:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // bgez        $v0, L_80022D60
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80022D60;
    }
    // nop

    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_80022D60:
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // bne         $a2, $t1, L_80022CB8
    if (ctx->r6 != ctx->r9) {
        // addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
        goto L_80022CB8;
    }
    // addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_80022D74:
    // beq         $fp, $zero, L_80022D8C
    if (ctx->r30 == 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_80022D8C;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x8001BF10
    // andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    sub_8001BF10(rdram, ctx);
    goto after_8;
    // andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    after_8:
    // j           L_80023188
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    goto L_80023188;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
L_80022D8C:
    // lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(0X40, ctx->r16);
    // lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(0X20, ctx->r16);
    // lw          $v0, 0x88($s0)
    ctx->r2 = MEM_W(0X88, ctx->r16);
    // lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(0X20, ctx->r16);
    // lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(0X4, ctx->r3);
    // lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(0X48, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
    // lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(0X4, ctx->r4);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // beq         $a0, $v0, L_80023178
    if (ctx->r4 == ctx->r2) {
        // addiu       $a3, $s0, 0x50
        ctx->r7 = ADD32(ctx->r16, 0X50);
        goto L_80023178;
    }
    // addiu       $a3, $s0, 0x50
    ctx->r7 = ADD32(ctx->r16, 0X50);
    // addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // addiu       $v1, $a1, 0x4
    ctx->r3 = ADD32(ctx->r5, 0X4);
L_80022DC8:
    // lwc2        $0, 0x0($a2)
    gte_lwc2(rdram, ctx, 0, 6, 0);
    // lwc2        $1, 0x4($a2)
    gte_lwc2(rdram, ctx, 1, 6, 4);
    // nop

    // nop

    // .word       0x4A480012                   # INVALID     $s2, $t0, 0x12 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A480012);
    // swc2        $25, 0x0($a3)
    gte_swc2(rdram, ctx, 25, 7, 0);
    // swc2        $26, 0x4($a3)
    gte_swc2(rdram, ctx, 26, 7, 4);
    // swc2        $27, 0x8($a3)
    gte_swc2(rdram, ctx, 27, 7, 8);
    // addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // lhu         $v0, 0x50($s0)
    ctx->r2 = MEM_HU(0X50, ctx->r16);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x54($s0)
    ctx->r2 = MEM_HU(0X54, ctx->r16);
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // sh          $v0, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(0X58, ctx->r16);
    // lhu         $t3, 0x100($sp)
    ctx->r11 = MEM_HU(0X100, ctx->r29);
    // nop

    // sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // bne         $a0, $t0, L_80022DC8
    if (ctx->r4 != ctx->r8) {
        // addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_80022DC8;
    }
    // addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // j           L_8002317C
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    goto L_8002317C;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80022E28:
    // beq         $v0, $zero, L_80022FDC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80022FDC;
    }
    // nop

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
    // beq         $a2, $v0, L_80022F28
    if (ctx->r6 == ctx->r2) {
        // addiu       $a1, $a3, 0x6
        ctx->r5 = ADD32(ctx->r7, 0X6);
        goto L_80022F28;
    }
    // addiu       $a1, $a3, 0x6
    ctx->r5 = ADD32(ctx->r7, 0X6);
    // addiu       $t2, $zero, 0xFE1
    ctx->r10 = ADD32(0, 0XFE1);
    // addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
L_80022E6C:
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

    // beq         $a0, $v1, L_80022EE4
    if (ctx->r4 == ctx->r3) {
        // subu        $v1, $v1, $a0
        ctx->r3 = SUB32(ctx->r3, ctx->r4);
        goto L_80022EE4;
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
    // bne         $v1, $zero, L_80022EC0
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80022EC0;
    }
    // nop

    // break       7
    do_break(2147626684);
L_80022EC0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_80022ED8
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80022ED8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80022ED8
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80022ED8;
    }
    // nop

    // break       6
    do_break(2147626708);
L_80022ED8:
    // mflo        $v0
    ctx->r2 = lo;
    // j           L_80022EE8
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    goto L_80022EE8;
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_80022EE4:
    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_80022EE8:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // slti        $v0, $v0, 0xFE2
    ctx->r2 = SIGNED(ctx->r2) < 0XFE2 ? 1 : 0;
    // bne         $v0, $zero, L_80022F00
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80022F00;
    }
    // nop

    // sh          $t2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r10;
L_80022F00:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // bgez        $v0, L_80022F14
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80022F14;
    }
    // nop

    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_80022F14:
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // bne         $a2, $t1, L_80022E6C
    if (ctx->r6 != ctx->r9) {
        // addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
        goto L_80022E6C;
    }
    // addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_80022F28:
    // beq         $fp, $zero, L_80022F40
    if (ctx->r30 == 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_80022F40;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x800192D4
    // andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    sub_800192D4(rdram, ctx);
    goto after_9;
    // andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    after_9:
    // j           L_80023188
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    goto L_80023188;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
L_80022F40:
    // lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(0X40, ctx->r16);
    // lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(0X20, ctx->r16);
    // lw          $v0, 0x88($s0)
    ctx->r2 = MEM_W(0X88, ctx->r16);
    // lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(0X20, ctx->r16);
    // lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(0X4, ctx->r3);
    // lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(0X48, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
    // lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(0X4, ctx->r4);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // beq         $a0, $v0, L_80023178
    if (ctx->r4 == ctx->r2) {
        // addiu       $a3, $s0, 0x50
        ctx->r7 = ADD32(ctx->r16, 0X50);
        goto L_80023178;
    }
    // addiu       $a3, $s0, 0x50
    ctx->r7 = ADD32(ctx->r16, 0X50);
    // addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // addiu       $v1, $a1, 0x4
    ctx->r3 = ADD32(ctx->r5, 0X4);
L_80022F7C:
    // lwc2        $0, 0x0($a2)
    gte_lwc2(rdram, ctx, 0, 6, 0);
    // lwc2        $1, 0x4($a2)
    gte_lwc2(rdram, ctx, 1, 6, 4);
    // nop

    // nop

    // .word       0x4A480012                   # INVALID     $s2, $t0, 0x12 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A480012);
    // swc2        $25, 0x0($a3)
    gte_swc2(rdram, ctx, 25, 7, 0);
    // swc2        $26, 0x4($a3)
    gte_swc2(rdram, ctx, 26, 7, 4);
    // swc2        $27, 0x8($a3)
    gte_swc2(rdram, ctx, 27, 7, 8);
    // addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // lhu         $v0, 0x50($s0)
    ctx->r2 = MEM_HU(0X50, ctx->r16);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x54($s0)
    ctx->r2 = MEM_HU(0X54, ctx->r16);
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // sh          $v0, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(0X58, ctx->r16);
    // lhu         $t3, 0x100($sp)
    ctx->r11 = MEM_HU(0X100, ctx->r29);
    // nop

    // sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // bne         $a0, $t0, L_80022F7C
    if (ctx->r4 != ctx->r8) {
        // addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_80022F7C;
    }
    // addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // j           L_8002317C
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    goto L_8002317C;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80022FDC:
    // beq         $fp, $zero, L_800230E4
    if (ctx->r30 == 0) {
        // nop
    
        goto L_800230E4;
    }
    // nop

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
    // beq         $a2, $v0, L_80023178
    if (ctx->r6 == ctx->r2) {
        // addiu       $t2, $zero, 0xFE1
        ctx->r10 = ADD32(0, 0XFE1);
        goto L_80023178;
    }
    // addiu       $t2, $zero, 0xFE1
    ctx->r10 = ADD32(0, 0XFE1);
    // addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // addiu       $a1, $a3, 0x6
    ctx->r5 = ADD32(ctx->r7, 0X6);
L_80023020:
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

    // beq         $a0, $v1, L_80023098
    if (ctx->r4 == ctx->r3) {
        // subu        $v1, $v1, $a0
        ctx->r3 = SUB32(ctx->r3, ctx->r4);
        goto L_80023098;
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
    // bne         $v1, $zero, L_80023074
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80023074;
    }
    // nop

    // break       7
    do_break(2147627120);
L_80023074:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8002308C
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8002308C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8002308C
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8002308C;
    }
    // nop

    // break       6
    do_break(2147627144);
L_8002308C:
    // mflo        $v0
    ctx->r2 = lo;
    // j           L_8002309C
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    goto L_8002309C;
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_80023098:
    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_8002309C:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // slti        $v0, $v0, 0xFE2
    ctx->r2 = SIGNED(ctx->r2) < 0XFE2 ? 1 : 0;
    // bne         $v0, $zero, L_800230B4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800230B4;
    }
    // nop

    // sh          $t2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r10;
L_800230B4:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // bgez        $v0, L_800230C8
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800230C8;
    }
    // nop

    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_800230C8:
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // bne         $a2, $t1, L_80023020
    if (ctx->r6 != ctx->r9) {
        // addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
        goto L_80023020;
    }
    // addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // j           L_8002317C
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    goto L_8002317C;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_800230E4:
    // lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(0X40, ctx->r16);
    // lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(0X20, ctx->r16);
    // lw          $v0, 0x88($s0)
    ctx->r2 = MEM_W(0X88, ctx->r16);
    // lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(0X20, ctx->r16);
    // lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(0X4, ctx->r3);
    // lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(0X48, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r2;
    // lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(0X4, ctx->r4);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // beq         $a0, $v0, L_80023178
    if (ctx->r4 == ctx->r2) {
        // addiu       $a3, $s0, 0x50
        ctx->r7 = ADD32(ctx->r16, 0X50);
        goto L_80023178;
    }
    // addiu       $a3, $s0, 0x50
    ctx->r7 = ADD32(ctx->r16, 0X50);
    // addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // addiu       $v1, $a1, 0x4
    ctx->r3 = ADD32(ctx->r5, 0X4);
L_80023120:
    // lwc2        $0, 0x0($a2)
    gte_lwc2(rdram, ctx, 0, 6, 0);
    // lwc2        $1, 0x4($a2)
    gte_lwc2(rdram, ctx, 1, 6, 4);
    // nop

    // nop

    // .word       0x4A480012                   # INVALID     $s2, $t0, 0x12 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A480012);
    // swc2        $25, 0x0($a3)
    gte_swc2(rdram, ctx, 25, 7, 0);
    // swc2        $26, 0x4($a3)
    gte_swc2(rdram, ctx, 26, 7, 4);
    // swc2        $27, 0x8($a3)
    gte_swc2(rdram, ctx, 27, 7, 8);
    // addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // lhu         $v0, 0x50($s0)
    ctx->r2 = MEM_HU(0X50, ctx->r16);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x54($s0)
    ctx->r2 = MEM_HU(0X54, ctx->r16);
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // sh          $v0, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(0X58, ctx->r16);
    // lhu         $t3, 0x100($sp)
    ctx->r11 = MEM_HU(0X100, ctx->r29);
    // nop

    // sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // bne         $a0, $t0, L_80023120
    if (ctx->r4 != ctx->r8) {
        // addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_80023120;
    }
    // addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80023178:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8002317C:
    // jal         0x80019DC8
    // andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    sub_80019DC8(rdram, ctx);
    goto after_10;
    // andi        $a1, $s4, 0xFF
    ctx->r5 = ctx->r20 & 0XFF;
    after_10:
L_80023184:
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
L_80023188:
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
    // lw          $a1, 0x90($s0)
    ctx->r5 = MEM_W(0X90, ctx->r16);
    // lw          $a2, 0x94($s0)
    ctx->r6 = MEM_W(0X94, ctx->r16);
    // sw          $v0, 0x31C($v1)
    MEM_W(0X31C, ctx->r3) = ctx->r2;
    // sw          $a0, 0x320($v1)
    MEM_W(0X320, ctx->r3) = ctx->r4;
    // sw          $a1, 0x324($v1)
    MEM_W(0X324, ctx->r3) = ctx->r5;
    // sw          $a2, 0x328($v1)
    MEM_W(0X328, ctx->r3) = ctx->r6;
    // lw          $ra, 0xCC($sp)
    ctx->r31 = MEM_W(0XCC, ctx->r29);
    // lw          $fp, 0xC8($sp)
    ctx->r30 = MEM_W(0XC8, ctx->r29);
    // lw          $s7, 0xC4($sp)
    ctx->r23 = MEM_W(0XC4, ctx->r29);
    // lw          $s6, 0xC0($sp)
    ctx->r22 = MEM_W(0XC0, ctx->r29);
    // lw          $s5, 0xBC($sp)
    ctx->r21 = MEM_W(0XBC, ctx->r29);
    // lw          $s4, 0xB8($sp)
    ctx->r20 = MEM_W(0XB8, ctx->r29);
    // lw          $s3, 0xB4($sp)
    ctx->r19 = MEM_W(0XB4, ctx->r29);
    // lw          $s2, 0xB0($sp)
    ctx->r18 = MEM_W(0XB0, ctx->r29);
    // lw          $s1, 0xAC($sp)
    ctx->r17 = MEM_W(0XAC, ctx->r29);
    // lw          $s0, 0xA8($sp)
    ctx->r16 = MEM_W(0XA8, ctx->r29);
    // addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    // jr          $ra
    // nop

    return;
    // nop

;}
