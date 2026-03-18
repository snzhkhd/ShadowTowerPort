#include "recomp.h"
#include "disable_warnings.h"

void sub_80057744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $s1, -0x2E80
    ctx->r16 = ADD32(ctx->r17, -0X2E80);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(0X10, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80057A10
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80057A10;
    }
    // nop

    // jal         0x800575A0
    // nop

    sub_800575A0(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lbu         $v0, 0xE($s0)
    ctx->r2 = MEM_BU(0XE, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80057A10
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80057A10;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v1, -0x2ED0($v0)
    ctx->r3 = MEM_BU(-0X2ED0, ctx->r2);
    // nop

    // bne         $v1, $zero, L_80057A10
    if (ctx->r3 != 0) {
        // addiu       $v0, $v0, -0x2ED0
        ctx->r2 = ADD32(ctx->r2, -0X2ED0);
        goto L_80057A10;
    }
    // addiu       $v0, $v0, -0x2ED0
    ctx->r2 = ADD32(ctx->r2, -0X2ED0);
    // lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(0X2, ctx->r2);
    // lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(0X2, ctx->r16);
    // nor         $a0, $zero, $v0
    ctx->r4 = ~(0 | ctx->r2);
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // sh          $v1, -0x2E80($s1)
    MEM_H(-0X2E80, ctx->r17) = ctx->r3;
    // beq         $v0, $a1, L_800577EC
    if (ctx->r2 == ctx->r5) {
        // sh          $a0, 0x2($s0)
        MEM_H(0X2, ctx->r16) = ctx->r4;
        goto L_800577EC;
    }
    // sh          $a0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r4;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x13($s0)
    MEM_B(0X13, ctx->r16) = ctx->r2;
    // or          $v0, $a0, $v1
    ctx->r2 = ctx->r4 | ctx->r3;
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sb          $zero, 0x11($s0)
    MEM_B(0X11, ctx->r16) = 0;
    // beq         $v0, $a1, L_80057874
    if (ctx->r2 == ctx->r5) {
        // sh          $zero, 0xC($s0)
        MEM_H(0XC, ctx->r16) = 0;
        goto L_80057874;
    }
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // nor         $v0, $zero, $v1
    ctx->r2 = ~(0 | ctx->r3);
    // lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(0X4, ctx->r16);
    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // j           L_80057874
    // sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    goto L_80057874;
    // sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
L_800577EC:
    // lbu         $v0, 0x11($s0)
    ctx->r2 = MEM_BU(0X11, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80057818
    if (ctx->r2 == 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80057818;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sb          $v0, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // bne         $v0, $zero, L_8005781C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_8005781C;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // nop

    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
L_80057818:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_8005781C:
    // addiu       $v1, $v0, -0x2E80
    ctx->r3 = ADD32(ctx->r2, -0X2E80);
    // lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(0X2, ctx->r3);
    // lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(0X6, ctx->r3);
    // nop

    // beq         $a0, $v0, L_80057854
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80057854;
    }
    // nop

    // lbu         $v0, 0x11($v1)
    ctx->r2 = MEM_BU(0X11, ctx->r3);
    // nop

    // bne         $v0, $zero, L_80057874
    if (ctx->r2 != 0) {
        // sh          $a0, 0x6($v1)
        MEM_H(0X6, ctx->r3) = ctx->r4;
        goto L_80057874;
    }
    // sh          $a0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r4;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v0, -0x2ED9($v0)
    ctx->r2 = MEM_BU(-0X2ED9, ctx->r2);
    // j           L_80057874
    // sb          $v0, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r2;
    goto L_80057874;
    // sb          $v0, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r2;
L_80057854:
    // lbu         $v0, 0x11($v1)
    ctx->r2 = MEM_BU(0X11, ctx->r3);
    // nop

    // bne         $v0, $zero, L_80057878
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80057878;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v0, -0x2EDA($v0)
    ctx->r2 = MEM_BU(-0X2EDA, ctx->r2);
    // nop

    // sb          $v0, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r2;
L_80057874:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_80057878:
    // addiu       $a1, $v0, -0x2E80
    ctx->r5 = ADD32(ctx->r2, -0X2E80);
    // lhu         $a2, 0x2($a1)
    ctx->r6 = MEM_HU(0X2, ctx->r5);
    // lhu         $a0, -0x2E80($v0)
    ctx->r4 = MEM_HU(-0X2E80, ctx->r2);
    // lhu         $v1, 0x3A($a1)
    ctx->r3 = MEM_HU(0X3A, ctx->r5);
    // or          $v0, $a2, $a0
    ctx->r2 = ctx->r6 | ctx->r4;
    // and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // and         $v1, $a0, $v1
    ctx->r3 = ctx->r4 & ctx->r3;
    // beq         $v0, $v1, L_800579DC
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_800579DC;
    }
    // nop

    // lbu         $v0, 0x12($a1)
    ctx->r2 = MEM_BU(0X12, ctx->r5);
    // nop

    // bne         $v0, $zero, L_800578C4
    if (ctx->r2 != 0) {
        // nor         $v0, $zero, $a0
        ctx->r2 = ~(0 | ctx->r4);
        goto L_800578C4;
    }
    // nor         $v0, $zero, $a0
    ctx->r2 = ~(0 | ctx->r4);
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // lbu         $v1, -0x2ED8($v1)
    ctx->r3 = MEM_BU(-0X2ED8, ctx->r3);
    // and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // j           L_80057A10
    // sb          $v1, 0x12($a1)
    MEM_B(0X12, ctx->r5) = ctx->r3;
    goto L_80057A10;
    // sb          $v1, 0x12($a1)
    MEM_B(0X12, ctx->r5) = ctx->r3;
L_800578C4:
    // lhu         $v0, 0xA($a1)
    ctx->r2 = MEM_HU(0XA, ctx->r5);
    // nop

    // bne         $v0, $zero, L_80057A10
    if (ctx->r2 != 0) {
        // nor         $v1, $zero, $a0
        ctx->r3 = ~(0 | ctx->r4);
        goto L_80057A10;
    }
    // nor         $v1, $zero, $a0
    ctx->r3 = ~(0 | ctx->r4);
    // lhu         $v0, 0x8($a1)
    ctx->r2 = MEM_HU(0X8, ctx->r5);
    // lhu         $a0, 0x38($a1)
    ctx->r4 = MEM_HU(0X38, ctx->r5);
    // and         $v1, $a2, $v1
    ctx->r3 = ctx->r6 & ctx->r3;
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // beq         $v0, $zero, L_80057910
    if (ctx->r2 == 0) {
        // sh          $v1, 0xA($a1)
        MEM_H(0XA, ctx->r5) = ctx->r3;
        goto L_80057910;
    }
    // sh          $v1, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r3;
    // and         $v0, $a0, $v1
    ctx->r2 = ctx->r4 & ctx->r3;
    // beq         $v0, $zero, L_80057910
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80057910;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x14($a1)
    MEM_B(0X14, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(0X4, ctx->r5);
    // nor         $v1, $zero, $a0
    ctx->r3 = ~(0 | ctx->r4);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // j           L_800579C4
    // sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    goto L_800579C4;
    // sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
L_80057910:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a0, $v0, -0x2E80
    ctx->r4 = ADD32(ctx->r2, -0X2E80);
    // lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(0X8, ctx->r4);
    // lhu         $a2, 0x36($a0)
    ctx->r6 = MEM_HU(0X36, ctx->r4);
    // nop

    // and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // beq         $v0, $zero, L_80057960
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80057960;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lhu         $a1, 0xA($a0)
    ctx->r5 = MEM_HU(0XA, ctx->r4);
    // lhu         $v1, 0x32($a0)
    ctx->r3 = MEM_HU(0X32, ctx->r4);
    // nop

    // and         $v0, $a1, $v1
    ctx->r2 = ctx->r5 & ctx->r3;
    // bne         $v0, $zero, L_800579A8
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_800579A8;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // lhu         $v1, 0x34($a0)
    ctx->r3 = MEM_HU(0X34, ctx->r4);
    // nop

    // and         $v0, $a1, $v1
    ctx->r2 = ctx->r5 & ctx->r3;
    // bne         $v0, $zero, L_800579A8
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_800579A8;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_80057960:
    // addiu       $a0, $v0, -0x2E80
    ctx->r4 = ADD32(ctx->r2, -0X2E80);
    // lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(0X8, ctx->r4);
    // lhu         $a2, 0x38($a0)
    ctx->r6 = MEM_HU(0X38, ctx->r4);
    // nop

    // and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // beq         $v0, $zero, L_800579C8
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_800579C8;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lhu         $a1, 0xA($a0)
    ctx->r5 = MEM_HU(0XA, ctx->r4);
    // lhu         $v1, 0x32($a0)
    ctx->r3 = MEM_HU(0X32, ctx->r4);
    // nop

    // and         $v0, $a1, $v1
    ctx->r2 = ctx->r5 & ctx->r3;
    // bne         $v0, $zero, L_800579A8
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_800579A8;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // lhu         $v1, 0x34($a0)
    ctx->r3 = MEM_HU(0X34, ctx->r4);
    // nop

    // and         $v0, $a1, $v1
    ctx->r2 = ctx->r5 & ctx->r3;
    // beq         $v0, $zero, L_800579C4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_800579C4;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800579A8:
    // sb          $v0, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(0X4, ctx->r4);
    // nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // nor         $v1, $zero, $a2
    ctx->r3 = ~(0 | ctx->r6);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
L_800579C4:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_800579C8:
    // addiu       $v0, $v0, -0x2E80
    ctx->r2 = ADD32(ctx->r2, -0X2E80);
    // sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // j           L_80057A10
    // sb          $zero, 0x12($v0)
    MEM_B(0X12, ctx->r2) = 0;
    goto L_80057A10;
    // sb          $zero, 0x12($v0)
    MEM_B(0X12, ctx->r2) = 0;
L_800579DC:
    // lbu         $v1, 0x12($a1)
    ctx->r3 = MEM_BU(0X12, ctx->r5);
    // nop

    // beq         $v1, $zero, L_80057A10
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80057A10;
    }
    // nop

    // lhu         $v0, 0xA($a1)
    ctx->r2 = MEM_HU(0XA, ctx->r5);
    // nop

    // bne         $v0, $zero, L_80057A10
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_80057A10;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sb          $v0, 0x12($a1)
    MEM_B(0X12, ctx->r5) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // bne         $v0, $zero, L_80057A10
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80057A10;
    }
    // nop

    // sh          $zero, 0x8($a1)
    MEM_H(0X8, ctx->r5) = 0;
L_80057A10:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
