#include "recomp.h"
#include "disable_warnings.h"

void sub_80025E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v1, 0x304($t0)
    ctx->r3 = MEM_W(0X304, ctx->r8);
    // nop

    // lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $a0, $a1, 0x28
    ctx->r4 = ADD32(ctx->r5, 0X28);
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_8002600C
    if (ctx->r2 != 0) {
        // addu        $t2, $t1, $zero
        ctx->r10 = ADD32(ctx->r9, 0);
        goto L_8002600C;
    }
    // addu        $t2, $t1, $zero
    ctx->r10 = ADD32(ctx->r9, 0);
    // sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // lw          $v0, 0x328($t0)
    ctx->r2 = MEM_W(0X328, ctx->r8);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($t0)
    MEM_W(0X328, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x6($a3)
    ctx->r2 = MEM_HU(0X6, ctx->r7);
    // nop

    // sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x8($a3)
    ctx->r2 = MEM_HU(0X8, ctx->r7);
    // nop

    // sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x6($a3)
    ctx->r2 = MEM_HU(0X6, ctx->r7);
    // lhu         $v1, 0xA($a3)
    ctx->r3 = MEM_HU(0XA, ctx->r7);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x8($a3)
    ctx->r2 = MEM_HU(0X8, ctx->r7);
    // nop

    // sh          $v0, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x6($a3)
    ctx->r2 = MEM_HU(0X6, ctx->r7);
    // nop

    // sh          $v0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x8($a3)
    ctx->r2 = MEM_HU(0X8, ctx->r7);
    // lhu         $v1, 0xC($a3)
    ctx->r3 = MEM_HU(0XC, ctx->r7);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x6($a3)
    ctx->r2 = MEM_HU(0X6, ctx->r7);
    // lhu         $v1, 0xA($a3)
    ctx->r3 = MEM_HU(0XA, ctx->r7);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x20($a1)
    MEM_H(0X20, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x8($a3)
    ctx->r2 = MEM_HU(0X8, ctx->r7);
    // lhu         $v1, 0xC($a3)
    ctx->r3 = MEM_HU(0XC, ctx->r7);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x22($a1)
    MEM_H(0X22, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xE($a3)
    ctx->r2 = MEM_HU(0XE, ctx->r7);
    // nop

    // sh          $v0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x2($a3)
    ctx->r2 = MEM_BU(0X2, ctx->r7);
    // nop

    // sb          $v0, 0xC($a1)
    MEM_B(0XC, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x3($a3)
    ctx->r2 = MEM_BU(0X3, ctx->r7);
    // nop

    // sb          $v0, 0xD($a1)
    MEM_B(0XD, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x2($a3)
    ctx->r2 = MEM_BU(0X2, ctx->r7);
    // lbu         $v1, 0x4($a3)
    ctx->r3 = MEM_BU(0X4, ctx->r7);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x14($a1)
    MEM_B(0X14, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x3($a3)
    ctx->r2 = MEM_BU(0X3, ctx->r7);
    // nop

    // sb          $v0, 0x15($a1)
    MEM_B(0X15, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x2($a3)
    ctx->r2 = MEM_BU(0X2, ctx->r7);
    // nop

    // sb          $v0, 0x1C($a1)
    MEM_B(0X1C, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x3($a3)
    ctx->r2 = MEM_BU(0X3, ctx->r7);
    // lbu         $v1, 0x5($a3)
    ctx->r3 = MEM_BU(0X5, ctx->r7);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x1D($a1)
    MEM_B(0X1D, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x2($a3)
    ctx->r2 = MEM_BU(0X2, ctx->r7);
    // lbu         $v1, 0x4($a3)
    ctx->r3 = MEM_BU(0X4, ctx->r7);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x24($a1)
    MEM_B(0X24, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x3($a3)
    ctx->r2 = MEM_BU(0X3, ctx->r7);
    // lbu         $v1, 0x5($a3)
    ctx->r3 = MEM_BU(0X5, ctx->r7);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x25($a1)
    MEM_B(0X25, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(0X0, ctx->r6);
    // nop

    // sb          $v0, 0x4($a1)
    MEM_B(0X4, ctx->r5) = ctx->r2;
    // lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(0X1, ctx->r6);
    // nop

    // sb          $v0, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r2;
    // lbu         $v1, 0x2($a2)
    ctx->r3 = MEM_BU(0X2, ctx->r6);
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // sb          $v0, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r2;
    // addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // sb          $v0, 0x7($a1)
    MEM_B(0X7, ctx->r5) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v1, 0x6($a1)
    MEM_B(0X6, ctx->r5) = ctx->r3;
    // andi        $v1, $t2, 0xFFFF
    ctx->r3 = ctx->r10 & 0XFFFF;
    // beq         $v1, $v0, L_80025FC4
    if (ctx->r3 == ctx->r2) {
        // andi        $v0, $t1, 0x3
        ctx->r2 = ctx->r9 & 0X3;
        goto L_80025FC4;
    }
    // andi        $v0, $t1, 0x3
    ctx->r2 = ctx->r9 & 0X3;
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // lhu         $v1, 0x10($a3)
    ctx->r3 = MEM_HU(0X10, ctx->r7);
    // lbu         $a0, 0x7($a1)
    ctx->r4 = MEM_BU(0X7, ctx->r5);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // sh          $v1, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r3;
    // j           L_80025FD8
    // sb          $a0, 0x7($a1)
    MEM_B(0X7, ctx->r5) = ctx->r4;
    goto L_80025FD8;
    // sb          $a0, 0x7($a1)
    MEM_B(0X7, ctx->r5) = ctx->r4;
L_80025FC4:
    // lbu         $v0, 0x7($a1)
    ctx->r2 = MEM_BU(0X7, ctx->r5);
    // lhu         $v1, 0x10($a3)
    ctx->r3 = MEM_HU(0X10, ctx->r7);
    // andi        $v0, $v0, 0xFD
    ctx->r2 = ctx->r2 & 0XFD;
    // sh          $v1, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r3;
    // sb          $v0, 0x7($a1)
    MEM_B(0X7, ctx->r5) = ctx->r2;
L_80025FD8:
    // lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // addiu       $s0, $s0, -0x2F70
    ctx->r16 = ADD32(ctx->r16, -0X2F70);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lh          $a0, 0x12($a3)
    ctx->r4 = MEM_HS(0X12, ctx->r7);
    // lw          $v0, 0xE4($s0)
    ctx->r2 = MEM_W(0XE4, ctx->r16);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // jal         0x8007C764
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    AddPrim(rdram, ctx);
    goto after_0;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // lw          $v0, 0x324($s0)
    ctx->r2 = MEM_W(0X324, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x324($s0)
    MEM_W(0X324, ctx->r16) = ctx->r2;
L_8002600C:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
