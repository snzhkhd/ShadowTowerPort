#include "recomp.h"
#include "disable_warnings.h"

void SsUtKeyOn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(0X4C, ctx->r29);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(0X50, ctx->r29);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x79AC($v0)
    ctx->r2 = MEM_W(-0X79AC, ctx->r2);
    // sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // lhu         $s7, 0x48($sp)
    ctx->r23 = MEM_HU(0X48, ctx->r29);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // bne         $v0, $v1, L_8006ED5C
    if (ctx->r2 != ctx->r3) {
        // addu        $s4, $s1, $zero
        ctx->r20 = ADD32(ctx->r17, 0);
        goto L_8006ED5C;
    }
    // addu        $s4, $s1, $zero
    ctx->r20 = ADD32(ctx->r17, 0);
    // j           L_8006F024
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8006F024;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006ED5C:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v1, -0x79AC($at)
    MEM_W(-0X79AC, ctx->r1) = ctx->r3;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // jal         0x800734A4
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    _SsVmVSetUp(rdram, ctx);
    goto after_0;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_0:
    // bne         $v0, $zero, L_8006EF2C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x21
        ctx->r2 = ADD32(0, 0X21);
        goto L_8006EF2C;
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
    // sb          $s7, -0x13($a1)
    MEM_B(-0X13, ctx->r5) = ctx->r23;
    // bne         $v1, $a0, L_8006EDBC
    if (ctx->r3 != ctx->r4) {
        // sb          $s3, -0xA($a1)
        MEM_B(-0XA, ctx->r5) = ctx->r19;
        goto L_8006EDBC;
    }
    // sb          $s3, -0xA($a1)
    MEM_B(-0XA, ctx->r5) = ctx->r19;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sb          $v0, -0x11($a1)
    MEM_B(-0X11, ctx->r5) = ctx->r2;
    // j           L_8006EE3C
    // sb          $s2, -0x12($a1)
    MEM_B(-0X12, ctx->r5) = ctx->r18;
    goto L_8006EE3C;
    // sb          $s2, -0x12($a1)
    MEM_B(-0X12, ctx->r5) = ctx->r18;
L_8006EDBC:
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8006EDFC
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 6
        ctx->r2 = S32(ctx->r4) << 6;
        goto L_8006EDFC;
    }
    // sll         $v0, $a0, 6
    ctx->r2 = S32(ctx->r4) << 6;
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_8006EDD8
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8006EDD8;
    }
    // nop

    // break       7
    do_break(2147937748);
L_8006EDD8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8006EDF0
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8006EDF0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8006EDF0
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8006EDF0;
    }
    // nop

    // break       6
    do_break(2147937772);
L_8006EDF0:
    // mflo        $v0
    ctx->r2 = lo;
    // j           L_8006EE38
    // sb          $s2, -0x12($a1)
    MEM_B(-0X12, ctx->r5) = ctx->r18;
    goto L_8006EE38;
    // sb          $s2, -0x12($a1)
    MEM_B(-0X12, ctx->r5) = ctx->r18;
L_8006EDFC:
    // sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3) << 6;
    // div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // bne         $a0, $zero, L_8006EE10
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8006EE10;
    }
    // nop

    // break       7
    do_break(2147937804);
L_8006EE10:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_8006EE28
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8006EE28;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8006EE28
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8006EE28;
    }
    // nop

    // break       6
    do_break(2147937828);
L_8006EE28:
    // mflo        $v1
    ctx->r3 = lo;
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sb          $s4, -0x12($a1)
    MEM_B(-0X12, ctx->r5) = ctx->r20;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8006EE38:
    // sb          $v0, -0x11($a1)
    MEM_B(-0X11, ctx->r5) = ctx->r2;
L_8006EE3C:
    // sll         $v1, $s6, 16
    ctx->r3 = S32(ctx->r22) << 16;
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
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sb          $v1, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r3;
    // lbu         $v0, 0x7($v0)
    ctx->r2 = MEM_BU(0X7, ctx->r2);
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // beq         $a0, $zero, L_8006EF2C
    if (ctx->r4 == 0) {
        // sb          $v0, 0x9($s0)
        MEM_B(0X9, ctx->r16) = ctx->r2;
        goto L_8006EF2C;
    }
    // sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // jal         0x80070414
    // nop

    _SsVmAlloc(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lb          $v0, -0x690C($v0)
    ctx->r2 = MEM_BS(-0X690C, ctx->r2);
    // addu        $v1, $s1, $zero
    ctx->r3 = ADD32(ctx->r17, 0);
    // bne         $v1, $v0, L_8006EF3C
    if (ctx->r3 != ctx->r2) {
        // sll         $v0, $v1, 3
        ctx->r2 = S32(ctx->r3) << 3;
        goto L_8006EF3C;
    }
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
L_8006EF2C:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $zero, -0x79AC($at)
    MEM_W(-0X79AC, ctx->r1) = 0;
    // j           L_8006F024
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8006F024;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006EF3C:
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $v1, $zero, 0x21
    ctx->r3 = ADD32(0, 0X21);
    // sh          $s1, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r17;
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
    // sh          $fp, -0x70E8($at)
    MEM_H(-0X70E8, ctx->r1) = ctx->r30;
    // lbu         $v1, -0x3($s0)
    ctx->r3 = MEM_BU(-0X3, ctx->r16);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $s6, -0x70EC($at)
    MEM_H(-0X70EC, ctx->r1) = ctx->r22;
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
    goto after_2;
    // sh          $a0, -0x70EA($at)
    MEM_H(-0X70EA, ctx->r1) = ctx->r4;
    after_2:
    // lh          $v1, 0xE($s0)
    ctx->r3 = MEM_HS(0XE, ctx->r16);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // bne         $v1, $v0, L_8006F004
    if (ctx->r3 != ctx->r2) {
        // andi        $a0, $s5, 0xFFFF
        ctx->r4 = ctx->r21 & 0XFFFF;
        goto L_8006F004;
    }
    // andi        $a0, $s5, 0xFFFF
    ctx->r4 = ctx->r21 & 0XFFFF;
    // jal         0x800721C4
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_800721C4(rdram, ctx);
    goto after_3;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
    // j           L_8006F018
    // nop

    goto L_8006F018;
    // nop

L_8006F004:
    // jal         0x80071FD8
    // addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    sub_80071FD8(rdram, ctx);
    goto after_4;
    // addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    after_4:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // jal         0x800728A4
    // andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    sub_800728A4(rdram, ctx);
    goto after_5;
    // andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_5:
L_8006F018:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $zero, -0x79AC($at)
    MEM_W(-0X79AC, ctx->r1) = 0;
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_8006F024:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(0X30, ctx->r29);
    // lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(0X2C, ctx->r29);
    // lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
