#include "recomp.h"
#include "disable_warnings.h"

void sub_8007AB80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // lh          $a0, 0x0($s0)
    ctx->r4 = MEM_HS(0X0, ctx->r16);
    // lh          $a1, 0x2($s0)
    ctx->r5 = MEM_HS(0X2, ctx->r16);
    // jal         0x8007AE10
    // nop

    sub_8007AE10(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(0X4, ctx->r16);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(0X2, ctx->r16);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // jal         0x8007AEA8
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8007AEA8(rdram, ctx);
    goto after_1;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_1:
    // sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // lh          $a0, 0x8($s0)
    ctx->r4 = MEM_HS(0X8, ctx->r16);
    // lh          $a1, 0xA($s0)
    ctx->r5 = MEM_HS(0XA, ctx->r16);
    // jal         0x8007AF40
    // nop

    sub_8007AF40(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // lbu         $a0, 0x17($s0)
    ctx->r4 = MEM_BU(0X17, ctx->r16);
    // lbu         $a1, 0x16($s0)
    ctx->r5 = MEM_BU(0X16, ctx->r16);
    // lhu         $a2, 0x14($s0)
    ctx->r6 = MEM_HU(0X14, ctx->r16);
    // jal         0x8007ADF0
    // nop

    sub_8007ADF0(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // jal         0x8007AF5C
    // sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    sub_8007AF5C(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    after_4:
    // sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // lui         $v0, 0xE600
    ctx->r2 = S32(0XE600 << 16);
    // sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(0X18, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8007ADD4
    if (ctx->r2 == 0) {
        // addiu       $t0, $zero, 0x7
        ctx->r8 = ADD32(0, 0X7);
        goto L_8007ADD4;
    }
    // addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(0X4, ctx->r16);
    // nop

    // sh          $a0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r4;
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // nop

    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bltz        $v1, L_8007AC9C
    if (SIGNED(ctx->r3) < 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007AC9C;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lh          $v0, 0x7CC4($v0)
    ctx->r2 = MEM_HS(0X7CC4, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lhu         $v1, 0x7CC4($v1)
    ctx->r3 = MEM_HU(0X7CC4, ctx->r3);
    // bne         $v0, $zero, L_8007AC9C
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8007AC9C;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_8007AC9C:
    // lh          $v1, 0x16($sp)
    ctx->r3 = MEM_HS(0X16, ctx->r29);
    // lhu         $a0, 0x16($sp)
    ctx->r4 = MEM_HU(0X16, ctx->r29);
    // bltz        $v1, L_8007ACD8
    if (SIGNED(ctx->r3) < 0) {
        // sh          $v0, 0x14($sp)
        MEM_H(0X14, ctx->r29) = ctx->r2;
        goto L_8007ACD8;
    }
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lh          $v0, 0x7CC6($v0)
    ctx->r2 = MEM_HS(0X7CC6, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lhu         $v1, 0x7CC6($v1)
    ctx->r3 = MEM_HU(0X7CC6, ctx->r3);
    // bne         $v0, $zero, L_8007ACDC
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8007ACDC;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // j           L_8007ACDC
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    goto L_8007ACDC;
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_8007ACD8:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007ACDC:
    // lhu         $v1, 0x10($sp)
    ctx->r3 = MEM_HU(0X10, ctx->r29);
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // andi        $v0, $v1, 0x3F
    ctx->r2 = ctx->r3 & 0X3F;
    // bne         $v0, $zero, L_8007AD04
    if (ctx->r2 != 0) {
        // sll         $a2, $t0, 2
        ctx->r6 = S32(ctx->r8) << 2;
        goto L_8007AD04;
    }
    // sll         $a2, $t0, 2
    ctx->r6 = S32(ctx->r8) << 2;
    // lhu         $v0, 0x14($sp)
    ctx->r2 = MEM_HU(0X14, ctx->r29);
    // nop

    // andi        $v0, $v0, 0x3F
    ctx->r2 = ctx->r2 & 0X3F;
    // beq         $v0, $zero, L_8007AD7C
    if (ctx->r2 == 0) {
        // sll         $a1, $t0, 2
        ctx->r5 = S32(ctx->r8) << 2;
        goto L_8007AD7C;
    }
    // sll         $a1, $t0, 2
    ctx->r5 = S32(ctx->r8) << 2;
L_8007AD04:
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // sll         $a3, $t0, 2
    ctx->r7 = S32(ctx->r8) << 2;
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // sll         $a1, $t0, 2
    ctx->r5 = S32(ctx->r8) << 2;
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // addu        $a2, $a2, $s1
    ctx->r6 = ADD32(ctx->r6, ctx->r17);
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x12($sp)
    ctx->r2 = MEM_HU(0X12, ctx->r29);
    // lhu         $v1, 0xA($s0)
    ctx->r3 = MEM_HU(0XA, ctx->r16);
    // lui         $a0, 0x6000
    ctx->r4 = S32(0X6000 << 16);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x1B($s0)
    ctx->r2 = MEM_BU(0X1B, ctx->r16);
    // lbu         $v1, 0x1A($s0)
    ctx->r3 = MEM_BU(0X1A, ctx->r16);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) << 8;
    // or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // lbu         $a0, 0x19($s0)
    ctx->r4 = MEM_BU(0X19, ctx->r16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // addu        $a3, $a3, $s1
    ctx->r7 = ADD32(ctx->r7, ctx->r17);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(0X14, ctx->r29);
    // addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // j           L_8007ADD4
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    goto L_8007ADD4;
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_8007AD7C:
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // sll         $a2, $t0, 2
    ctx->r6 = S32(ctx->r8) << 2;
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // sll         $a3, $t0, 2
    ctx->r7 = S32(ctx->r8) << 2;
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // lbu         $v0, 0x1B($s0)
    ctx->r2 = MEM_BU(0X1B, ctx->r16);
    // lbu         $v1, 0x1A($s0)
    ctx->r3 = MEM_BU(0X1A, ctx->r16);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) << 8;
    // or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // lbu         $a0, 0x19($s0)
    ctx->r4 = MEM_BU(0X19, ctx->r16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // addu        $a2, $a2, $s1
    ctx->r6 = ADD32(ctx->r6, ctx->r17);
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(0X14, ctx->r29);
    // addu        $a3, $a3, $s1
    ctx->r7 = ADD32(ctx->r7, ctx->r17);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
L_8007ADD4:
    // addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // sb          $v0, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r2;
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
