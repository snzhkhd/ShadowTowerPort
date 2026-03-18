#include "recomp.h"
#include "disable_warnings.h"

void SsUtKeyOnV(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(0X58, ctx->r29);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(0X5C, ctx->r29);
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // lhu         $s5, 0x50($sp)
    ctx->r21 = MEM_HU(0X50, ctx->r29);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x79AC($v0)
    ctx->r2 = MEM_W(-0X79AC, ctx->r2);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // addu        $s7, $a2, $zero
    ctx->r23 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // lhu         $fp, 0x54($sp)
    ctx->r30 = MEM_HU(0X54, ctx->r29);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sh          $a1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r5;
    // addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    // bne         $v0, $v1, L_8006F210
    if (ctx->r2 != ctx->r3) {
        // addu        $s6, $s1, $zero
        ctx->r22 = ADD32(ctx->r17, 0);
        goto L_8006F210;
    }
    // addu        $s6, $s1, $zero
    ctx->r22 = ADD32(ctx->r17, 0);
    // j           L_8006F4D4
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8006F4D4;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006F210:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v1, -0x79AC($at)
    MEM_W(-0X79AC, ctx->r1) = ctx->r3;
    // andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
    // sltiu       $v0, $v0, 0x18
    ctx->r2 = ctx->r2 < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_8006F3C8
    if (ctx->r2 == 0) {
        // sll         $a0, $a1, 16
        ctx->r4 = S32(ctx->r5) << 16;
        goto L_8006F3C8;
    }
    // sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6) << 16;
    // jal         0x800734A4
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    _SsVmVSetUp(rdram, ctx);
    goto after_0;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_0:
    // bne         $v0, $zero, L_8006F3C8
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x21
        ctx->r2 = ADD32(0, 0X21);
        goto L_8006F3C8;
    }
    // addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // addiu       $a1, $a1, -0x68F2
    ctx->r5 = ADD32(ctx->r5, -0X68F2);
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // sb          $s5, -0x14($a1)
    MEM_B(-0X14, ctx->r5) = ctx->r21;
    // sb          $fp, -0x13($a1)
    MEM_B(-0X13, ctx->r5) = ctx->r30;
    // bne         $v1, $a0, L_8006F27C
    if (ctx->r3 != ctx->r4) {
        // sb          $s4, -0xA($a1)
        MEM_B(-0XA, ctx->r5) = ctx->r20;
        goto L_8006F27C;
    }
    // sb          $s4, -0xA($a1)
    MEM_B(-0XA, ctx->r5) = ctx->r20;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sb          $v0, -0x11($a1)
    MEM_B(-0X11, ctx->r5) = ctx->r2;
    // j           L_8006F2FC
    // sb          $s3, -0x12($a1)
    MEM_B(-0X12, ctx->r5) = ctx->r19;
    goto L_8006F2FC;
    // sb          $s3, -0x12($a1)
    MEM_B(-0X12, ctx->r5) = ctx->r19;
L_8006F27C:
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8006F2BC
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 6
        ctx->r2 = S32(ctx->r4) << 6;
        goto L_8006F2BC;
    }
    // sll         $v0, $a0, 6
    ctx->r2 = S32(ctx->r4) << 6;
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_8006F298
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8006F298;
    }
    // nop

    // break       7
    do_break(2147938964);
L_8006F298:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8006F2B0
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8006F2B0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8006F2B0
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8006F2B0;
    }
    // nop

    // break       6
    do_break(2147938988);
L_8006F2B0:
    // mflo        $v0
    ctx->r2 = lo;
    // j           L_8006F2F8
    // sb          $s3, -0x12($a1)
    MEM_B(-0X12, ctx->r5) = ctx->r19;
    goto L_8006F2F8;
    // sb          $s3, -0x12($a1)
    MEM_B(-0X12, ctx->r5) = ctx->r19;
L_8006F2BC:
    // sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3) << 6;
    // div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // bne         $a0, $zero, L_8006F2D0
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8006F2D0;
    }
    // nop

    // break       7
    do_break(2147939020);
L_8006F2D0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_8006F2E8
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8006F2E8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8006F2E8
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8006F2E8;
    }
    // nop

    // break       6
    do_break(2147939044);
L_8006F2E8:
    // mflo        $v1
    ctx->r3 = lo;
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sb          $s6, -0x12($a1)
    MEM_B(-0X12, ctx->r5) = ctx->r22;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8006F2F8:
    // sb          $v0, -0x11($a1)
    MEM_B(-0X11, ctx->r5) = ctx->r2;
L_8006F2FC:
    // sll         $v1, $s7, 16
    ctx->r3 = S32(ctx->r23) << 16;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x691C($v0)
    ctx->r2 = MEM_W(-0X691C, ctx->r2);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(0X1, ctx->r3);
    // lui         $s0, 0x801F
    ctx->r16 = S32(0X801F << 16);
    // addiu       $s0, $s0, -0x68FE
    ctx->r16 = ADD32(ctx->r16, -0X68FE);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(0X2, ctx->r16);
    // lbu         $a0, 0x4($v1)
    ctx->r4 = MEM_BU(0X4, ctx->r3);
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sb          $a0, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r4;
    // lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(0X0, ctx->r3);
    // lb          $v1, -0x3($s0)
    ctx->r3 = MEM_BS(-0X3, ctx->r16);
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sb          $a0, -0xA($s0)
    MEM_B(-0XA, ctx->r16) = ctx->r4;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lw          $v1, -0x6910($v1)
    ctx->r3 = MEM_W(-0X6910, ctx->r3);
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // nop

    // sb          $v1, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r3;
    // lhu         $a0, 0x16($v0)
    ctx->r4 = MEM_HU(0X16, ctx->r2);
    // nop

    // sh          $a0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r4;
    // lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(0X2, ctx->r2);
    // nop

    // sb          $v1, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r3;
    // lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(0X3, ctx->r2);
    // nop

    // sb          $v1, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r3;
    // lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(0X4, ctx->r2);
    // nop

    // sb          $v1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r3;
    // lbu         $v1, 0x5($v0)
    ctx->r3 = MEM_BU(0X5, ctx->r2);
    // nop

    // sb          $v1, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r3;
    // lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(0X1, ctx->r2);
    // nop

    // sb          $v1, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r3;
    // lbu         $v1, 0x6($v0)
    ctx->r3 = MEM_BU(0X6, ctx->r2);
    // nop

    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // lbu         $v0, 0x7($v0)
    ctx->r2 = MEM_BU(0X7, ctx->r2);
    // bne         $a0, $zero, L_8006F3D8
    if (ctx->r4 != 0) {
        // sb          $v0, 0x9($s0)
        MEM_B(0X9, ctx->r16) = ctx->r2;
        goto L_8006F3D8;
    }
    // sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
L_8006F3C8:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $zero, -0x79AC($at)
    MEM_W(-0X79AC, ctx->r1) = 0;
    // j           L_8006F4D4
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8006F4D4;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006F3D8:
    // sll         $v1, $s2, 16
    ctx->r3 = S32(ctx->r18) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // sh          $s2, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r18;
    // lhu         $t0, 0x10($sp)
    ctx->r8 = MEM_HU(0X10, ctx->r29);
    // addiu       $v1, $zero, 0x21
    ctx->r3 = ADD32(0, 0X21);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, -0x70F0($at)
    MEM_H(-0X70F0, ctx->r1) = ctx->r3;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $t0, -0x70E8($at)
    MEM_H(-0X70E8, ctx->r1) = ctx->r8;
    // lbu         $v1, -0x3($s0)
    ctx->r3 = MEM_BU(-0X3, ctx->r16);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $s7, -0x70EC($at)
    MEM_H(-0X70EC, ctx->r1) = ctx->r23;
    // sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3) << 24;
    // sra         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3) >> 24;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, -0x70EE($at)
    MEM_H(-0X70EE, ctx->r1) = ctx->r3;
    // lhu         $v1, 0xE($s0)
    ctx->r3 = MEM_HU(0XE, ctx->r16);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, -0x7100($at)
    MEM_H(-0X7100, ctx->r1) = ctx->r3;
    // lbu         $a0, 0x2($s0)
    ctx->r4 = MEM_BU(0X2, ctx->r16);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $s5, -0x70F2($at)
    MEM_H(-0X70F2, ctx->r1) = ctx->r21;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $v1, -0x70E3($at)
    MEM_B(-0X70E3, ctx->r1) = ctx->r3;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x70FE($at)
    MEM_H(-0X70FE, ctx->r1) = 0;
    // sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4) << 24;
    // sra         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4) >> 24;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // jal         0x800706A4
    // sh          $a0, -0x70EA($at)
    MEM_H(-0X70EA, ctx->r1) = ctx->r4;
    sub_800706A4(rdram, ctx);
    goto after_1;
    // sh          $a0, -0x70EA($at)
    MEM_H(-0X70EA, ctx->r1) = ctx->r4;
    after_1:
    // lh          $v1, 0xE($s0)
    ctx->r3 = MEM_HS(0XE, ctx->r16);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // bne         $v1, $v0, L_8006F4B0
    if (ctx->r3 != ctx->r2) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_8006F4B0;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // jal         0x800721C4
    // andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    sub_800721C4(rdram, ctx);
    goto after_2;
    // andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    after_2:
    // j           L_8006F4C4
    // nop

    goto L_8006F4C4;
    // nop

L_8006F4B0:
    // jal         0x80071FD8
    // addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    sub_80071FD8(rdram, ctx);
    goto after_3;
    // addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    after_3:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // jal         0x800728A4
    // andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    sub_800728A4(rdram, ctx);
    goto after_4;
    // andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_4:
L_8006F4C4:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $zero, -0x79AC($at)
    MEM_W(-0X79AC, ctx->r1) = 0;
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
L_8006F4D4:
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(0X38, ctx->r29);
    // lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
