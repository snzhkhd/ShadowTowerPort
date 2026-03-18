#include "recomp.h"
#include "disable_warnings.h"

void sub_800177A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // bne         $a3, $zero, L_800177B0
    if (ctx->r7 != 0) {
        // addu        $t5, $a0, $zero
        ctx->r13 = ADD32(ctx->r4, 0);
        goto L_800177B0;
    }
    // addu        $t5, $a0, $zero
    ctx->r13 = ADD32(ctx->r4, 0);
    // lw          $a3, 0x8($t5)
    ctx->r7 = MEM_W(0X8, ctx->r13);
L_800177B0:
    // nop

    // addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a3, $v0, L_80017C54
    if (ctx->r7 == ctx->r2) {
        // nop
    
        goto L_80017C54;
    }
    // nop

    // addu        $t4, $v0, $zero
    ctx->r12 = ADD32(ctx->r2, 0);
    // addiu       $t3, $t5, 0x32
    ctx->r11 = ADD32(ctx->r13, 0X32);
L_800177CC:
    // lw          $v0, -0x16($t3)
    ctx->r2 = MEM_W(-0X16, ctx->r11);
    // lhu         $t1, -0xE($t3)
    ctx->r9 = MEM_HU(-0XE, ctx->r11);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // beq         $t1, $t4, L_800178B8
    if (ctx->r9 == ctx->r12) {
        // addu        $t2, $t5, $v0
        ctx->r10 = ADD32(ctx->r13, ctx->r2);
        goto L_800178B8;
    }
    // addu        $t2, $t5, $v0
    ctx->r10 = ADD32(ctx->r13, ctx->r2);
    // addiu       $t0, $t2, 0x9
    ctx->r8 = ADD32(ctx->r10, 0X9);
L_800177E8:
    // lhu         $a0, 0x0($a1)
    ctx->r4 = MEM_HU(0X0, ctx->r5);
    // lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(0X2, ctx->r5);
    // lhu         $v1, -0x3($t0)
    ctx->r3 = MEM_HU(-0X3, ctx->r8);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 22
    ctx->r4 = S32(ctx->r4) >> 22;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v1, -0x3($t0)
    MEM_H(-0X3, ctx->r8) = ctx->r3;
    // lhu         $a0, 0x2($a2)
    ctx->r4 = MEM_HU(0X2, ctx->r6);
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // lhu         $v1, -0x7($t0)
    ctx->r3 = MEM_HU(-0X7, ctx->r8);
    // sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4) << 6;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 20
    ctx->r2 = S32(ctx->r2) >> 20;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v1, -0x7($t0)
    MEM_H(-0X7, ctx->r8) = ctx->r3;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, 0x0($t2)
    ctx->r3 = MEM_BU(0X0, ctx->r10);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r3;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // lbu         $v0, -0x8($t0)
    ctx->r2 = MEM_BU(-0X8, ctx->r8);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, -0x8($t0)
    MEM_B(-0X8, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, -0x5($t0)
    ctx->r3 = MEM_BU(-0X5, ctx->r8);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, -0x5($t0)
    MEM_B(-0X5, ctx->r8) = ctx->r3;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // lbu         $v0, -0x4($t0)
    ctx->r2 = MEM_BU(-0X4, ctx->r8);
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, -0x4($t0)
    MEM_B(-0X4, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, -0x1($t0)
    ctx->r3 = MEM_BU(-0X1, ctx->r8);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r3;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(0X0, ctx->r8);
    // addiu       $t2, $t2, 0x14
    ctx->r10 = ADD32(ctx->r10, 0X14);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r2;
    // bne         $t1, $t4, L_800177E8
    if (ctx->r9 != ctx->r12) {
        // addiu       $t0, $t0, 0x14
        ctx->r8 = ADD32(ctx->r8, 0X14);
        goto L_800177E8;
    }
    // addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
L_800178B8:
    // lhu         $t1, -0xA($t3)
    ctx->r9 = MEM_HU(-0XA, ctx->r11);
    // nop

    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // beq         $t1, $t4, L_800179C8
    if (ctx->r9 == ctx->r12) {
        // nop
    
        goto L_800179C8;
    }
    // nop

    // addiu       $t0, $t2, 0xD
    ctx->r8 = ADD32(ctx->r10, 0XD);
L_800178D0:
    // lhu         $a0, 0x0($a1)
    ctx->r4 = MEM_HU(0X0, ctx->r5);
    // lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(0X2, ctx->r5);
    // lhu         $v1, -0x7($t0)
    ctx->r3 = MEM_HU(-0X7, ctx->r8);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 22
    ctx->r4 = S32(ctx->r4) >> 22;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v1, -0x7($t0)
    MEM_H(-0X7, ctx->r8) = ctx->r3;
    // lhu         $a0, 0x2($a2)
    ctx->r4 = MEM_HU(0X2, ctx->r6);
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // lhu         $v1, -0xB($t0)
    ctx->r3 = MEM_HU(-0XB, ctx->r8);
    // sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4) << 6;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 20
    ctx->r2 = S32(ctx->r2) >> 20;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v1, -0xB($t0)
    MEM_H(-0XB, ctx->r8) = ctx->r3;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, 0x0($t2)
    ctx->r3 = MEM_BU(0X0, ctx->r10);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r3;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // lbu         $v0, -0xC($t0)
    ctx->r2 = MEM_BU(-0XC, ctx->r8);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, -0xC($t0)
    MEM_B(-0XC, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, -0x9($t0)
    ctx->r3 = MEM_BU(-0X9, ctx->r8);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, -0x9($t0)
    MEM_B(-0X9, ctx->r8) = ctx->r3;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // lbu         $v0, -0x8($t0)
    ctx->r2 = MEM_BU(-0X8, ctx->r8);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, -0x8($t0)
    MEM_B(-0X8, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, -0x5($t0)
    ctx->r3 = MEM_BU(-0X5, ctx->r8);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, -0x5($t0)
    MEM_B(-0X5, ctx->r8) = ctx->r3;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // lbu         $v0, -0x4($t0)
    ctx->r2 = MEM_BU(-0X4, ctx->r8);
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, -0x4($t0)
    MEM_B(-0X4, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, -0x1($t0)
    ctx->r3 = MEM_BU(-0X1, ctx->r8);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r3;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(0X0, ctx->r8);
    // addiu       $t2, $t2, 0x1C
    ctx->r10 = ADD32(ctx->r10, 0X1C);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r2;
    // bne         $t1, $t4, L_800178D0
    if (ctx->r9 != ctx->r12) {
        // addiu       $t0, $t0, 0x1C
        ctx->r8 = ADD32(ctx->r8, 0X1C);
        goto L_800178D0;
    }
    // addiu       $t0, $t0, 0x1C
    ctx->r8 = ADD32(ctx->r8, 0X1C);
L_800179C8:
    // lhu         $t1, -0xC($t3)
    ctx->r9 = MEM_HU(-0XC, ctx->r11);
    // nop

    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // beq         $t1, $t4, L_80017AB0
    if (ctx->r9 == ctx->r12) {
        // nop
    
        goto L_80017AB0;
    }
    // nop

    // addiu       $t0, $t2, 0x9
    ctx->r8 = ADD32(ctx->r10, 0X9);
L_800179E0:
    // lhu         $a0, 0x0($a1)
    ctx->r4 = MEM_HU(0X0, ctx->r5);
    // lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(0X2, ctx->r5);
    // lhu         $v1, -0x3($t0)
    ctx->r3 = MEM_HU(-0X3, ctx->r8);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 22
    ctx->r4 = S32(ctx->r4) >> 22;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v1, -0x3($t0)
    MEM_H(-0X3, ctx->r8) = ctx->r3;
    // lhu         $a0, 0x2($a2)
    ctx->r4 = MEM_HU(0X2, ctx->r6);
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // lhu         $v1, -0x7($t0)
    ctx->r3 = MEM_HU(-0X7, ctx->r8);
    // sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4) << 6;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 20
    ctx->r2 = S32(ctx->r2) >> 20;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v1, -0x7($t0)
    MEM_H(-0X7, ctx->r8) = ctx->r3;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, 0x0($t2)
    ctx->r3 = MEM_BU(0X0, ctx->r10);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r3;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // lbu         $v0, -0x8($t0)
    ctx->r2 = MEM_BU(-0X8, ctx->r8);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, -0x8($t0)
    MEM_B(-0X8, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, -0x5($t0)
    ctx->r3 = MEM_BU(-0X5, ctx->r8);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, -0x5($t0)
    MEM_B(-0X5, ctx->r8) = ctx->r3;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // lbu         $v0, -0x4($t0)
    ctx->r2 = MEM_BU(-0X4, ctx->r8);
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, -0x4($t0)
    MEM_B(-0X4, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, -0x1($t0)
    ctx->r3 = MEM_BU(-0X1, ctx->r8);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r3;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(0X0, ctx->r8);
    // addiu       $t2, $t2, 0x18
    ctx->r10 = ADD32(ctx->r10, 0X18);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r2;
    // bne         $t1, $t4, L_800179E0
    if (ctx->r9 != ctx->r12) {
        // addiu       $t0, $t0, 0x18
        ctx->r8 = ADD32(ctx->r8, 0X18);
        goto L_800179E0;
    }
    // addiu       $t0, $t0, 0x18
    ctx->r8 = ADD32(ctx->r8, 0X18);
L_80017AB0:
    // lhu         $t1, -0x8($t3)
    ctx->r9 = MEM_HU(-0X8, ctx->r11);
    // nop

    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // beq         $t1, $t4, L_80017BC0
    if (ctx->r9 == ctx->r12) {
        // nop
    
        goto L_80017BC0;
    }
    // nop

    // addiu       $t0, $t2, 0xD
    ctx->r8 = ADD32(ctx->r10, 0XD);
L_80017AC8:
    // lhu         $a0, 0x0($a1)
    ctx->r4 = MEM_HU(0X0, ctx->r5);
    // lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(0X2, ctx->r5);
    // lhu         $v1, -0x7($t0)
    ctx->r3 = MEM_HU(-0X7, ctx->r8);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 22
    ctx->r4 = S32(ctx->r4) >> 22;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v1, -0x7($t0)
    MEM_H(-0X7, ctx->r8) = ctx->r3;
    // lhu         $a0, 0x2($a2)
    ctx->r4 = MEM_HU(0X2, ctx->r6);
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // lhu         $v1, -0xB($t0)
    ctx->r3 = MEM_HU(-0XB, ctx->r8);
    // sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4) << 6;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 20
    ctx->r2 = S32(ctx->r2) >> 20;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v1, -0xB($t0)
    MEM_H(-0XB, ctx->r8) = ctx->r3;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, 0x0($t2)
    ctx->r3 = MEM_BU(0X0, ctx->r10);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r3;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // lbu         $v0, -0xC($t0)
    ctx->r2 = MEM_BU(-0XC, ctx->r8);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, -0xC($t0)
    MEM_B(-0XC, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, -0x9($t0)
    ctx->r3 = MEM_BU(-0X9, ctx->r8);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, -0x9($t0)
    MEM_B(-0X9, ctx->r8) = ctx->r3;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // lbu         $v0, -0x8($t0)
    ctx->r2 = MEM_BU(-0X8, ctx->r8);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, -0x8($t0)
    MEM_B(-0X8, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, -0x5($t0)
    ctx->r3 = MEM_BU(-0X5, ctx->r8);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, -0x5($t0)
    MEM_B(-0X5, ctx->r8) = ctx->r3;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // lbu         $v0, -0x4($t0)
    ctx->r2 = MEM_BU(-0X4, ctx->r8);
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, -0x4($t0)
    MEM_B(-0X4, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lbu         $v1, -0x1($t0)
    ctx->r3 = MEM_BU(-0X1, ctx->r8);
    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r3;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(0X0, ctx->r8);
    // addiu       $t2, $t2, 0x20
    ctx->r10 = ADD32(ctx->r10, 0X20);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r2;
    // bne         $t1, $t4, L_80017AC8
    if (ctx->r9 != ctx->r12) {
        // addiu       $t0, $t0, 0x20
        ctx->r8 = ADD32(ctx->r8, 0X20);
        goto L_80017AC8;
    }
    // addiu       $t0, $t0, 0x20
    ctx->r8 = ADD32(ctx->r8, 0X20);
L_80017BC0:
    // lhu         $t1, -0x6($t3)
    ctx->r9 = MEM_HU(-0X6, ctx->r11);
    // nop

    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // beq         $t1, $t4, L_80017BE0
    if (ctx->r9 == ctx->r12) {
        // addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
        goto L_80017BE0;
    }
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017BD8:
    // bne         $t1, $v0, L_80017BD8
    if (ctx->r9 != ctx->r2) {
        // addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
        goto L_80017BD8;
    }
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
L_80017BE0:
    // lhu         $t1, -0x2($t3)
    ctx->r9 = MEM_HU(-0X2, ctx->r11);
    // nop

    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // beq         $t1, $t4, L_80017C00
    if (ctx->r9 == ctx->r12) {
        // addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
        goto L_80017C00;
    }
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017BF8:
    // bne         $t1, $v0, L_80017BF8
    if (ctx->r9 != ctx->r2) {
        // addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
        goto L_80017BF8;
    }
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
L_80017C00:
    // lhu         $t1, -0x4($t3)
    ctx->r9 = MEM_HU(-0X4, ctx->r11);
    // nop

    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // beq         $t1, $t4, L_80017C20
    if (ctx->r9 == ctx->r12) {
        // addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
        goto L_80017C20;
    }
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80017C18:
    // bne         $t1, $v0, L_80017C18
    if (ctx->r9 != ctx->r2) {
        // addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
        goto L_80017C18;
    }
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
L_80017C20:
    // lhu         $t1, 0x0($t3)
    ctx->r9 = MEM_HU(0X0, ctx->r11);
    // nop

    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // beq         $t1, $t4, L_80017C48
    if (ctx->r9 == ctx->r12) {
        // nop
    
        goto L_80017C48;
    }
    // nop

    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
L_80017C3C:
    // bne         $t1, $v0, L_80017C3C
    if (ctx->r9 != ctx->r2) {
        // addiu       $t1, $t1, -0x1
        ctx->r9 = ADD32(ctx->r9, -0X1);
        goto L_80017C3C;
    }
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_80017C48:
    // addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // bne         $a3, $t4, L_800177CC
    if (ctx->r7 != ctx->r12) {
        // addiu       $t3, $t3, 0x28
        ctx->r11 = ADD32(ctx->r11, 0X28);
        goto L_800177CC;
    }
    // addiu       $t3, $t3, 0x28
    ctx->r11 = ADD32(ctx->r11, 0X28);
L_80017C54:
    // jr          $ra
    // nop

    return;
    // nop

;}
