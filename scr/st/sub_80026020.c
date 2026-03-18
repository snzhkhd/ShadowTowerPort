#include "recomp.h"
#include "disable_warnings.h"

void sub_80026020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lw          $v1, 0x304($a1)
    ctx->r3 = MEM_W(0X304, ctx->r5);
    // nop

    // lw          $s2, 0x8($v1)
    ctx->r18 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $a0, $s2, 0xC
    ctx->r4 = ADD32(ctx->r18, 0XC);
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_8002620C
    if (ctx->r2 != 0) {
        // addu        $t0, $a3, $zero
        ctx->r8 = ADD32(ctx->r7, 0);
        goto L_8002620C;
    }
    // addu        $t0, $a3, $zero
    ctx->r8 = ADD32(ctx->r7, 0);
    // sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // lw          $v0, 0x328($a1)
    ctx->r2 = MEM_W(0X328, ctx->r5);
    // lw          $v1, 0x304($a1)
    ctx->r3 = MEM_W(0X304, ctx->r5);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($a1)
    MEM_W(0X328, ctx->r5) = ctx->r2;
    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_8002620C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002620C;
    }
    // nop

    // sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // lw          $v0, 0x328($a1)
    ctx->r2 = MEM_W(0X328, ctx->r5);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($a1)
    MEM_W(0X328, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // nop

    // sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // lhu         $v1, 0xA($s1)
    ctx->r3 = MEM_HU(0XA, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // nop

    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // lhu         $v1, 0xC($s1)
    ctx->r3 = MEM_HU(0XC, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // lhu         $v1, 0xA($s1)
    ctx->r3 = MEM_HU(0XA, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // lhu         $v1, 0xC($s1)
    ctx->r3 = MEM_HU(0XC, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(0X0, ctx->r6);
    // nop

    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(0X1, ctx->r6);
    // nop

    // sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
    // lbu         $v1, 0x2($a2)
    ctx->r3 = MEM_BU(0X2, ctx->r6);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r3;
    // andi        $v1, $t0, 0xFFFF
    ctx->r3 = ctx->r8 & 0XFFFF;
    // beq         $v1, $v0, L_80026198
    if (ctx->r3 == ctx->r2) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_80026198;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // lhu         $v0, 0x10($s1)
    ctx->r2 = MEM_HU(0X10, ctx->r17);
    // sll         $a3, $a3, 5
    ctx->r7 = S32(ctx->r7) << 5;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x8007A934
    // or          $a3, $v0, $a3
    ctx->r7 = ctx->r2 | ctx->r7;
    sub_8007A934(rdram, ctx);
    goto after_0;
    // or          $a3, $v0, $a3
    ctx->r7 = ctx->r2 | ctx->r7;
    after_0:
    // lbu         $v0, 0x7($s0)
    ctx->r2 = MEM_BU(0X7, ctx->r16);
    // j           L_800261B8
    // ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    goto L_800261B8;
    // ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
L_80026198:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // lhu         $a3, 0x10($s1)
    ctx->r7 = MEM_HU(0X10, ctx->r17);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // jal         0x8007A934
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sub_8007A934(rdram, ctx);
    goto after_1;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // lbu         $v0, 0x7($s0)
    ctx->r2 = MEM_BU(0X7, ctx->r16);
    // nop

    // andi        $v0, $v0, 0xFD
    ctx->r2 = ctx->r2 & 0XFD;
L_800261B8:
    // sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // addiu       $s0, $s0, -0x2F70
    ctx->r16 = ADD32(ctx->r16, -0X2F70);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lh          $a0, 0x12($s1)
    ctx->r4 = MEM_HS(0X12, ctx->r17);
    // lw          $v0, 0xE4($s0)
    ctx->r2 = MEM_W(0XE4, ctx->r16);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // jal         0x8007C764
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    AddPrim(rdram, ctx);
    goto after_2;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_2:
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // lh          $a0, 0x12($s1)
    ctx->r4 = MEM_HS(0X12, ctx->r17);
    // lw          $v0, 0xE4($s0)
    ctx->r2 = MEM_W(0XE4, ctx->r16);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // jal         0x8007C764
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    AddPrim(rdram, ctx);
    goto after_3;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_3:
    // lw          $v0, 0x324($s0)
    ctx->r2 = MEM_W(0X324, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // sw          $v0, 0x324($s0)
    MEM_W(0X324, ctx->r16) = ctx->r2;
L_8002620C:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
