#include "recomp.h"
#include "disable_warnings.h"

void sub_80028220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    // lw          $a0, 0x304($t1)
    ctx->r4 = MEM_W(0X304, ctx->r9);
    // addu        $t2, $a1, $zero
    ctx->r10 = ADD32(ctx->r5, 0);
    // lw          $a3, 0x8($a0)
    ctx->r7 = MEM_W(0X8, ctx->r4);
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // addiu       $a1, $a3, 0x18
    ctx->r5 = ADD32(ctx->r7, 0X18);
    // sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // bne         $v0, $zero, L_8002835C
    if (ctx->r2 != 0) {
        // andi        $v1, $a2, 0xFFFF
        ctx->r3 = ctx->r6 & 0XFFFF;
        goto L_8002835C;
    }
    // andi        $v1, $a2, 0xFFFF
    ctx->r3 = ctx->r6 & 0XFFFF;
    // sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    // lw          $v0, 0x328($t1)
    ctx->r2 = MEM_W(0X328, ctx->r9);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($t1)
    MEM_W(0X328, ctx->r9) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80028278
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x28
        ctx->r2 = ADD32(0, 0X28);
        goto L_80028278;
    }
    // addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
L_80028278:
    // sb          $v0, 0x7($a3)
    MEM_B(0X7, ctx->r7) = ctx->r2;
    // lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // addiu       $a0, $a0, -0x2F70
    ctx->r4 = ADD32(ctx->r4, -0X2F70);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // lw          $v0, 0xE4($a0)
    ctx->r2 = MEM_W(0XE4, ctx->r4);
    // ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x500
    ctx->r3 = S32(0X500 << 16);
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(0X0, ctx->r8);
    // nop

    // sh          $v0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x2($t0)
    ctx->r2 = MEM_HU(0X2, ctx->r8);
    // nop

    // sh          $v0, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(0X0, ctx->r8);
    // lhu         $v1, 0x4($t0)
    ctx->r3 = MEM_HU(0X4, ctx->r8);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0xC($a3)
    MEM_H(0XC, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x2($t0)
    ctx->r2 = MEM_HU(0X2, ctx->r8);
    // nop

    // sh          $v0, 0xE($a3)
    MEM_H(0XE, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(0X0, ctx->r8);
    // nop

    // sh          $v0, 0x10($a3)
    MEM_H(0X10, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x2($t0)
    ctx->r2 = MEM_HU(0X2, ctx->r8);
    // lhu         $v1, 0x6($t0)
    ctx->r3 = MEM_HU(0X6, ctx->r8);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x12($a3)
    MEM_H(0X12, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(0X0, ctx->r8);
    // lhu         $v1, 0x4($t0)
    ctx->r3 = MEM_HU(0X4, ctx->r8);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x14($a3)
    MEM_H(0X14, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x2($t0)
    ctx->r2 = MEM_HU(0X2, ctx->r8);
    // lhu         $v1, 0x6($t0)
    ctx->r3 = MEM_HU(0X6, ctx->r8);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x16($a3)
    MEM_H(0X16, ctx->r7) = ctx->r2;
    // lbu         $v0, 0x0($t2)
    ctx->r2 = MEM_BU(0X0, ctx->r10);
    // nop

    // sb          $v0, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r2;
    // lbu         $v0, 0x1($t2)
    ctx->r2 = MEM_BU(0X1, ctx->r10);
    // nop

    // sb          $v0, 0x5($a3)
    MEM_B(0X5, ctx->r7) = ctx->r2;
    // lbu         $v0, 0x2($t2)
    ctx->r2 = MEM_BU(0X2, ctx->r10);
    // nop

    // sb          $v0, 0x6($a3)
    MEM_B(0X6, ctx->r7) = ctx->r2;
    // lw          $v0, 0xE4($a0)
    ctx->r2 = MEM_W(0XE4, ctx->r4);
    // and         $a1, $a3, $a1
    ctx->r5 = ctx->r7 & ctx->r5;
    // sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_8002835C:
    // jr          $ra
    // nop

    return;
    // nop

;}
