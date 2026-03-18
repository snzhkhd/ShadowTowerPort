#include "recomp.h"
#include "disable_warnings.h"

void sub_80028C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x304($t1)
    ctx->r3 = MEM_W(0X304, ctx->r9);
    // nop

    // lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $t0, $a3, 0x24
    ctx->r8 = ADD32(ctx->r7, 0X24);
    // sltu        $v0, $v0, $t0
    ctx->r2 = ctx->r2 < ctx->r8 ? 1 : 0;
    // bne         $v0, $zero, L_80028DB0
    if (ctx->r2 != 0) {
        // addu        $t2, $a0, $zero
        ctx->r10 = ADD32(ctx->r4, 0);
        goto L_80028DB0;
    }
    // addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
    // lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // lw          $v0, 0x328($t1)
    ctx->r2 = MEM_W(0X328, ctx->r9);
    // lw          $v1, 0xE4($t1)
    ctx->r3 = MEM_W(0XE4, ctx->r9);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($t1)
    MEM_W(0X328, ctx->r9) = ctx->r2;
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // nop

    // sb          $v0, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r2;
    // lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(0X1, ctx->r5);
    // nop

    // sb          $v0, 0x5($a3)
    MEM_B(0X5, ctx->r7) = ctx->r2;
    // lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(0X2, ctx->r5);
    // nop

    // sb          $v0, 0x6($a3)
    MEM_B(0X6, ctx->r7) = ctx->r2;
    // lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(0X4, ctx->r5);
    // nop

    // sb          $v0, 0xC($a3)
    MEM_B(0XC, ctx->r7) = ctx->r2;
    // lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(0X5, ctx->r5);
    // nop

    // sb          $v0, 0xD($a3)
    MEM_B(0XD, ctx->r7) = ctx->r2;
    // lbu         $v0, 0x6($a1)
    ctx->r2 = MEM_BU(0X6, ctx->r5);
    // nop

    // sb          $v0, 0xE($a3)
    MEM_B(0XE, ctx->r7) = ctx->r2;
    // lbu         $v0, 0x8($a1)
    ctx->r2 = MEM_BU(0X8, ctx->r5);
    // nop

    // sb          $v0, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r2;
    // lbu         $v0, 0x9($a1)
    ctx->r2 = MEM_BU(0X9, ctx->r5);
    // nop

    // sb          $v0, 0x15($a3)
    MEM_B(0X15, ctx->r7) = ctx->r2;
    // lbu         $v0, 0xA($a1)
    ctx->r2 = MEM_BU(0XA, ctx->r5);
    // nop

    // sb          $v0, 0x16($a3)
    MEM_B(0X16, ctx->r7) = ctx->r2;
    // lbu         $v0, 0xC($a1)
    ctx->r2 = MEM_BU(0XC, ctx->r5);
    // nop

    // sb          $v0, 0x1C($a3)
    MEM_B(0X1C, ctx->r7) = ctx->r2;
    // lbu         $v0, 0xD($a1)
    ctx->r2 = MEM_BU(0XD, ctx->r5);
    // nop

    // sb          $v0, 0x1D($a3)
    MEM_B(0X1D, ctx->r7) = ctx->r2;
    // lbu         $v0, 0xE($a1)
    ctx->r2 = MEM_BU(0XE, ctx->r5);
    // nop

    // sb          $v0, 0x1E($a3)
    MEM_B(0X1E, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(0X0, ctx->r10);
    // nop

    // sh          $v0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x2($t2)
    ctx->r2 = MEM_HU(0X2, ctx->r10);
    // nop

    // sh          $v0, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x4($t2)
    ctx->r2 = MEM_HU(0X4, ctx->r10);
    // nop

    // sh          $v0, 0x10($a3)
    MEM_H(0X10, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x6($t2)
    ctx->r2 = MEM_HU(0X6, ctx->r10);
    // nop

    // sh          $v0, 0x12($a3)
    MEM_H(0X12, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x8($t2)
    ctx->r2 = MEM_HU(0X8, ctx->r10);
    // nop

    // sh          $v0, 0x18($a3)
    MEM_H(0X18, ctx->r7) = ctx->r2;
    // lhu         $v0, 0xA($t2)
    ctx->r2 = MEM_HU(0XA, ctx->r10);
    // nop

    // sh          $v0, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r2;
    // lhu         $v0, 0xC($t2)
    ctx->r2 = MEM_HU(0XC, ctx->r10);
    // nop

    // sh          $v0, 0x20($a3)
    MEM_H(0X20, ctx->r7) = ctx->r2;
    // lhu         $v0, 0xE($t2)
    ctx->r2 = MEM_HU(0XE, ctx->r10);
    // bne         $a2, $zero, L_80028D84
    if (ctx->r6 != 0) {
        // sh          $v0, 0x22($a3)
        MEM_H(0X22, ctx->r7) = ctx->r2;
        goto L_80028D84;
    }
    // sh          $v0, 0x22($a3)
    MEM_H(0X22, ctx->r7) = ctx->r2;
    // j           L_80028D88
    // addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    goto L_80028D88;
    // addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
L_80028D84:
    // addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
L_80028D88:
    // sb          $v0, 0x7($a3)
    MEM_B(0X7, ctx->r7) = ctx->r2;
    // lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0xE4($v0)
    ctx->r2 = MEM_W(0XE4, ctx->r2);
    // and         $a0, $a3, $a0
    ctx->r4 = ctx->r7 & ctx->r4;
    // sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_80028DB0:
    // jr          $ra
    // nop

    return;
    // nop

;}
