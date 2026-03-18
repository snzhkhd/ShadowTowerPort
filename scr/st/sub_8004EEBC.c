#include "recomp.h"
#include "disable_warnings.h"

void sub_8004EEBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // lw          $s6, -0x7DFC($v1)
    ctx->r22 = MEM_W(-0X7DFC, ctx->r3);
    // addiu       $v0, $v0, 0x310
    ctx->r2 = ADD32(ctx->r2, 0X310);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addiu       $s3, $v0, 0x1F20
    ctx->r19 = ADD32(ctx->r2, 0X1F20);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // addiu       $s5, $zero, 0xEF
    ctx->r21 = ADD32(0, 0XEF);
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $v0, 0x1F25
    ctx->r16 = ADD32(ctx->r2, 0X1F25);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addiu       $s1, $s4, 0xA
    ctx->r17 = ADD32(ctx->r20, 0XA);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sh          $zero, 0x71A8($v0)
    MEM_H(0X71A8, ctx->r2) = 0;
    // sh          $zero, 0x71A6($v0)
    MEM_H(0X71A6, ctx->r2) = 0;
    // sh          $zero, 0x71A4($v0)
    MEM_H(0X71A4, ctx->r2) = 0;
L_8004EF18:
    // lhu         $a0, -0x6($s1)
    ctx->r4 = MEM_HU(-0X6, ctx->r17);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // bne         $v1, $v0, L_8004EF34
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004EF34;
    }
    // nop

    // j           L_8004EF38
    // sh          $v1, 0x5($s0)
    MEM_H(0X5, ctx->r16) = ctx->r3;
    goto L_8004EF38;
    // sh          $v1, 0x5($s0)
    MEM_H(0X5, ctx->r16) = ctx->r3;
L_8004EF34:
    // sh          $a0, 0x5($s0)
    MEM_H(0X5, ctx->r16) = ctx->r4;
L_8004EF38:
    // lhu         $v1, 0x5($s0)
    ctx->r3 = MEM_HU(0X5, ctx->r16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_8004F4F0
    if (ctx->r3 == ctx->r2) {
        // sb          $s7, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r23;
        goto L_8004F4F0;
    }
    // sb          $s7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r23;
    // lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(0X4, ctx->r17);
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sh          $zero, 0x7($s0)
    MEM_H(0X7, ctx->r16) = 0;
    // sh          $zero, 0x9($s0)
    MEM_H(0X9, ctx->r16) = 0;
    // sb          $v0, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r2;
    // sh          $zero, 0xB($s0)
    MEM_H(0XB, ctx->r16) = 0;
    // sb          $zero, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = 0;
    // sh          $zero, 0x33($s0)
    MEM_H(0X33, ctx->r16) = 0;
    // sh          $zero, 0x2F($s0)
    MEM_H(0X2F, ctx->r16) = 0;
    // sh          $v1, 0x3($s0)
    MEM_H(0X3, ctx->r16) = ctx->r3;
    // lhu         $v1, -0x4($s1)
    ctx->r3 = MEM_HU(-0X4, ctx->r17);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x3B($s0)
    MEM_H(0X3B, ctx->r16) = ctx->r2;
    // sh          $v0, 0x39($s0)
    MEM_H(0X39, ctx->r16) = ctx->r2;
    // sh          $v0, 0x37($s0)
    MEM_H(0X37, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x5($s0)
    ctx->r2 = MEM_HU(0X5, ctx->r16);
    // andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // sh          $v1, 0x31($s0)
    MEM_H(0X31, ctx->r16) = ctx->r3;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x310
    ctx->r2 = ADD32(ctx->r2, 0X310);
    // addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    // sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // lbu         $v0, 0x3($s2)
    ctx->r2 = MEM_BU(0X3, ctx->r18);
    // nop

    // sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
    // lhu         $v1, 0xA($s2)
    ctx->r3 = MEM_HU(0XA, ctx->r18);
    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // sb          $s7, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r23;
    // sh          $zero, 0x11($s0)
    MEM_H(0X11, ctx->r16) = 0;
    // beq         $v0, $zero, L_8004F008
    if (ctx->r2 == 0) {
        // sh          $v1, 0xF($s0)
        MEM_H(0XF, ctx->r16) = ctx->r3;
        goto L_8004F008;
    }
    // sh          $v1, 0xF($s0)
    MEM_H(0XF, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x8($s2)
    ctx->r3 = MEM_HU(0X8, ctx->r18);
    // lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(0X6, ctx->r17);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // sra         $v0, $t2, 7
    ctx->r2 = S32(ctx->r10) >> 7;
    // sh          $v0, 0xD($s0)
    MEM_H(0XD, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x6($s1)
    ctx->r2 = MEM_BU(0X6, ctx->r17);
    // nop

    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // sh          $v0, 0x3B($s0)
    MEM_H(0X3B, ctx->r16) = ctx->r2;
    // sh          $v0, 0x39($s0)
    MEM_H(0X39, ctx->r16) = ctx->r2;
    // j           L_8004F014
    // sh          $v0, 0x37($s0)
    MEM_H(0X37, ctx->r16) = ctx->r2;
    goto L_8004F014;
    // sh          $v0, 0x37($s0)
    MEM_H(0X37, ctx->r16) = ctx->r2;
L_8004F008:
    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // nop

    // sh          $v0, 0xD($s0)
    MEM_H(0XD, ctx->r16) = ctx->r2;
L_8004F014:
    // addiu       $a0, $s3, 0x48
    ctx->r4 = ADD32(ctx->r19, 0X48);
    // addiu       $a1, $s4, 0x10
    ctx->r5 = ADD32(ctx->r20, 0X10);
    // addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(0X0, ctx->r20);
    // lh          $v1, -0x2($s1)
    ctx->r3 = MEM_HS(-0X2, ctx->r17);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x1F($s0)
    MEM_W(0X1F, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x9($s1)
    ctx->r2 = MEM_BU(-0X9, ctx->r17);
    // lh          $v1, 0x0($s1)
    ctx->r3 = MEM_HS(0X0, ctx->r17);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x23($s0)
    MEM_W(0X23, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x8($s1)
    ctx->r2 = MEM_BU(-0X8, ctx->r17);
    // lh          $v1, 0x2($s1)
    ctx->r3 = MEM_HS(0X2, ctx->r17);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80014CFC
    // sw          $v0, 0x27($s0)
    MEM_W(0X27, ctx->r16) = ctx->r2;
    sub_80014CFC(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x27($s0)
    MEM_W(0X27, ctx->r16) = ctx->r2;
    after_0:
    // addiu       $a0, $s3, 0x50
    ctx->r4 = ADD32(ctx->r19, 0X50);
    // addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    sub_80014D5C(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // nop

    // slti        $v0, $a0, 0x34
    ctx->r2 = SIGNED(ctx->r4) < 0X34 ? 1 : 0;
    // beq         $v0, $zero, L_8004F0F0
    if (ctx->r2 == 0) {
        // slti        $v0, $a0, 0x32
        ctx->r2 = SIGNED(ctx->r4) < 0X32 ? 1 : 0;
        goto L_8004F0F0;
    }
    // slti        $v0, $a0, 0x32
    ctx->r2 = SIGNED(ctx->r4) < 0X32 ? 1 : 0;
    // beq         $v0, $zero, L_8004F25C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8004F25C;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $a0, $v0, L_8004F4CC
    if (ctx->r4 == ctx->r2) {
        // slti        $v0, $a0, 0x4
        ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
        goto L_8004F4CC;
    }
    // slti        $v0, $a0, 0x4
    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8004F0B4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
        goto L_8004F0B4;
    }
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // bltz        $a0, L_8004F4D4
    if (SIGNED(ctx->r4) < 0) {
        // slti        $v0, $a0, 0x2
        ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
        goto L_8004F4D4;
    }
    // slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8004F178
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_8004F178;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // j           L_8004F310
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    goto L_8004F310;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8004F0B4:
    // beq         $a0, $v0, L_8004F340
    if (ctx->r4 == ctx->r2) {
        // slti        $v0, $a0, 0x8
        ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
        goto L_8004F340;
    }
    // slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_8004F0D4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_8004F0D4;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // beq         $a0, $v0, L_8004F4CC
    if (ctx->r4 == ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8004F4CC;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // j           L_8004F4D8
    // nop

    goto L_8004F4D8;
    // nop

L_8004F0D4:
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // beq         $a0, $v0, L_8004F4CC
    if (ctx->r4 == ctx->r2) {
        // addiu       $v0, $zero, 0x1F
        ctx->r2 = ADD32(0, 0X1F);
        goto L_8004F4CC;
    }
    // addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
    // beq         $a0, $v0, L_8004F494
    if (ctx->r4 == ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8004F494;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // j           L_8004F4D8
    // nop

    goto L_8004F4D8;
    // nop

L_8004F0F0:
    // addiu       $v0, $zero, 0xEC
    ctx->r2 = ADD32(0, 0XEC);
    // beq         $a0, $v0, L_8004F480
    if (ctx->r4 == ctx->r2) {
        // slti        $v0, $a0, 0xED
        ctx->r2 = SIGNED(ctx->r4) < 0XED ? 1 : 0;
        goto L_8004F480;
    }
    // slti        $v0, $a0, 0xED
    ctx->r2 = SIGNED(ctx->r4) < 0XED ? 1 : 0;
    // beq         $v0, $zero, L_8004F138
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xE0
        ctx->r2 = ADD32(0, 0XE0);
        goto L_8004F138;
    }
    // addiu       $v0, $zero, 0xE0
    ctx->r2 = ADD32(0, 0XE0);
    // beq         $a0, $v0, L_8004F350
    if (ctx->r4 == ctx->r2) {
        // slti        $v0, $a0, 0xE1
        ctx->r2 = SIGNED(ctx->r4) < 0XE1 ? 1 : 0;
        goto L_8004F350;
    }
    // slti        $v0, $a0, 0xE1
    ctx->r2 = SIGNED(ctx->r4) < 0XE1 ? 1 : 0;
    // beq         $v0, $zero, L_8004F124
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x34
        ctx->r2 = ADD32(0, 0X34);
        goto L_8004F124;
    }
    // addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
    // beq         $a0, $v0, L_8004F2FC
    if (ctx->r4 == ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8004F2FC;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // j           L_8004F4D8
    // nop

    goto L_8004F4D8;
    // nop

L_8004F124:
    // addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // beq         $a0, $v0, L_8004F4CC
    if (ctx->r4 == ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8004F4CC;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // j           L_8004F4D8
    // nop

    goto L_8004F4D8;
    // nop

L_8004F138:
    // addiu       $v0, $zero, 0xEF
    ctx->r2 = ADD32(0, 0XEF);
    // beq         $a0, $v0, L_8004F470
    if (ctx->r4 == ctx->r2) {
        // slti        $v0, $a0, 0xF0
        ctx->r2 = SIGNED(ctx->r4) < 0XF0 ? 1 : 0;
        goto L_8004F470;
    }
    // slti        $v0, $a0, 0xF0
    ctx->r2 = SIGNED(ctx->r4) < 0XF0 ? 1 : 0;
    // beq         $v0, $zero, L_8004F15C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xED
        ctx->r2 = ADD32(0, 0XED);
        goto L_8004F15C;
    }
    // addiu       $v0, $zero, 0xED
    ctx->r2 = ADD32(0, 0XED);
    // beq         $a0, $v0, L_8004F470
    if (ctx->r4 == ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8004F470;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // j           L_8004F4D8
    // nop

    goto L_8004F4D8;
    // nop

L_8004F15C:
    // addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // beq         $a0, $v0, L_8004F4C0
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_8004F4C0;
    }
    // nop

    // beq         $a0, $s7, L_8004F4F0
    if (ctx->r4 == ctx->r23) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8004F4F0;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // j           L_8004F4D8
    // nop

    goto L_8004F4D8;
    // nop

L_8004F178:
    // lbu         $a3, 0x49($s0)
    ctx->r7 = MEM_BU(0X49, ctx->r16);
    // nop

    // addiu       $v1, $a3, -0x1
    ctx->r3 = ADD32(ctx->r7, -0X1);
    // addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // beq         $v1, $v0, L_8004F208
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
        goto L_8004F208;
    }
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $t0, $v0, -0x4130
    ctx->r8 = ADD32(ctx->r2, -0X4130);
    // ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
L_8004F19C:
    // andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    // lhu         $v0, 0x47($s0)
    ctx->r2 = MEM_HU(0X47, ctx->r16);
    // lhu         $v1, 0x45($s0)
    ctx->r3 = MEM_HU(0X45, ctx->r16);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // lbu         $a2, 0x0($a0)
    ctx->r6 = MEM_BU(0X0, ctx->r4);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // addiu       $a0, $a3, -0x1
    ctx->r4 = ADD32(ctx->r7, -0X1);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // lhu         $v1, 0x45($s0)
    ctx->r3 = MEM_HU(0X45, ctx->r16);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bne         $a0, $t1, L_8004F19C
    if (ctx->r4 != ctx->r9) {
        // sb          $a2, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r6;
        goto L_8004F19C;
    }
    // sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
L_8004F208:
    // lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(0X0, ctx->r18);
    // lbu         $v1, 0x44($s0)
    ctx->r3 = MEM_BU(0X44, ctx->r16);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // bne         $v0, $zero, L_8004F228
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004F228;
    }
    // nop

    // j           L_8004F22C
    // sb          $v1, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r3;
    goto L_8004F22C;
    // sb          $v1, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r3;
L_8004F228:
    // sb          $zero, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = 0;
L_8004F22C:
    // lbu         $v1, 0x44($s0)
    ctx->r3 = MEM_BU(0X44, ctx->r16);
    // addiu       $v0, $zero, 0xFC
    ctx->r2 = ADD32(0, 0XFC);
    // beq         $v1, $v0, L_8004F4C4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xFA
        ctx->r2 = ADD32(0, 0XFA);
        goto L_8004F4C4;
    }
    // addiu       $v0, $zero, 0xFA
    ctx->r2 = ADD32(0, 0XFA);
    // beq         $v1, $v0, L_8004F4C4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xF9
        ctx->r2 = ADD32(0, 0XF9);
        goto L_8004F4C4;
    }
    // addiu       $v0, $zero, 0xF9
    ctx->r2 = ADD32(0, 0XF9);
    // beq         $v1, $v0, L_8004F4C4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xF8
        ctx->r2 = ADD32(0, 0XF8);
        goto L_8004F4C4;
    }
    // addiu       $v0, $zero, 0xF8
    ctx->r2 = ADD32(0, 0XF8);
    // bne         $v1, $v0, L_8004F4C4
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
        goto L_8004F4C4;
    }
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // j           L_8004F4F0
    // sh          $v0, 0x7($s0)
    MEM_H(0X7, ctx->r16) = ctx->r2;
    goto L_8004F4F0;
    // sh          $v0, 0x7($s0)
    MEM_H(0X7, ctx->r16) = ctx->r2;
L_8004F25C:
    // lbu         $v1, 0x44($s0)
    ctx->r3 = MEM_BU(0X44, ctx->r16);
    // nop

    // andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // bne         $v0, $zero, L_8004F278
    if (ctx->r2 != 0) {
        // sb          $a0, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r4;
        goto L_8004F278;
    }
    // sb          $a0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r4;
    // j           L_8004F27C
    // sb          $v1, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r3;
    goto L_8004F27C;
    // sb          $v1, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r3;
L_8004F278:
    // sb          $zero, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = 0;
L_8004F27C:
    // lbu         $v1, 0x44($s0)
    ctx->r3 = MEM_BU(0X44, ctx->r16);
    // addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // bne         $v1, $v0, L_8004F298
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0xFD
        ctx->r2 = ADD32(0, 0XFD);
        goto L_8004F298;
    }
    // addiu       $v0, $zero, 0xFD
    ctx->r2 = ADD32(0, 0XFD);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // j           L_8004F2F4
    // sh          $v0, 0x7($s0)
    MEM_H(0X7, ctx->r16) = ctx->r2;
    goto L_8004F2F4;
    // sh          $v0, 0x7($s0)
    MEM_H(0X7, ctx->r16) = ctx->r2;
L_8004F298:
    // bne         $v1, $v0, L_8004F2AC
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0xFC
        ctx->r2 = ADD32(0, 0XFC);
        goto L_8004F2AC;
    }
    // addiu       $v0, $zero, 0xFC
    ctx->r2 = ADD32(0, 0XFC);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // j           L_8004F2F4
    // sh          $v0, 0x7($s0)
    MEM_H(0X7, ctx->r16) = ctx->r2;
    goto L_8004F2F4;
    // sh          $v0, 0x7($s0)
    MEM_H(0X7, ctx->r16) = ctx->r2;
L_8004F2AC:
    // beq         $v1, $v0, L_8004F2F0
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xFA
        ctx->r2 = ADD32(0, 0XFA);
        goto L_8004F2F0;
    }
    // addiu       $v0, $zero, 0xFA
    ctx->r2 = ADD32(0, 0XFA);
    // beq         $v1, $v0, L_8004F2F0
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xF9
        ctx->r2 = ADD32(0, 0XF9);
        goto L_8004F2F0;
    }
    // addiu       $v0, $zero, 0xF9
    ctx->r2 = ADD32(0, 0XF9);
    // beq         $v1, $v0, L_8004F2F0
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xFB
        ctx->r2 = ADD32(0, 0XFB);
        goto L_8004F2F0;
    }
    // addiu       $v0, $zero, 0xFB
    ctx->r2 = ADD32(0, 0XFB);
    // bne         $v1, $v0, L_8004F2E0
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0xF8
        ctx->r2 = ADD32(0, 0XF8);
        goto L_8004F2E0;
    }
    // addiu       $v0, $zero, 0xF8
    ctx->r2 = ADD32(0, 0XF8);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // j           L_8004F2F4
    // sh          $v0, 0x7($s0)
    MEM_H(0X7, ctx->r16) = ctx->r2;
    goto L_8004F2F4;
    // sh          $v0, 0x7($s0)
    MEM_H(0X7, ctx->r16) = ctx->r2;
L_8004F2E0:
    // bne         $v1, $v0, L_8004F2F0
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
        goto L_8004F2F0;
    }
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // j           L_8004F2F4
    // sh          $v0, 0x7($s0)
    MEM_H(0X7, ctx->r16) = ctx->r2;
    goto L_8004F2F4;
    // sh          $v0, 0x7($s0)
    MEM_H(0X7, ctx->r16) = ctx->r2;
L_8004F2F0:
    // sh          $zero, 0x7($s0)
    MEM_H(0X7, ctx->r16) = 0;
L_8004F2F4:
    // j           L_8004F4F0
    // sh          $zero, 0x4B($s0)
    MEM_H(0X4B, ctx->r16) = 0;
    goto L_8004F4F0;
    // sh          $zero, 0x4B($s0)
    MEM_H(0X4B, ctx->r16) = 0;
L_8004F2FC:
    // sb          $a0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r4;
    // sh          $zero, 0x7($s0)
    MEM_H(0X7, ctx->r16) = 0;
    // sh          $zero, 0xB($s0)
    MEM_H(0XB, ctx->r16) = 0;
    // j           L_8004F4F0
    // sb          $zero, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = 0;
    goto L_8004F4F0;
    // sb          $zero, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = 0;
L_8004F310:
    // lbu         $v1, -0x1($s0)
    ctx->r3 = MEM_BU(-0X1, ctx->r16);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sh          $zero, 0x7($s0)
    MEM_H(0X7, ctx->r16) = 0;
    // sh          $zero, 0x37($s0)
    MEM_H(0X37, ctx->r16) = 0;
    // sh          $zero, 0x39($s0)
    MEM_H(0X39, ctx->r16) = 0;
    // sh          $zero, 0x3B($s0)
    MEM_H(0X3B, ctx->r16) = 0;
    // sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
    // sb          $zero, 0x4B($s0)
    MEM_B(0X4B, ctx->r16) = 0;
    // ori         $v1, $v1, 0x40
    ctx->r3 = ctx->r3 | 0X40;
    // j           L_8004F4F0
    // sb          $v1, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r3;
    goto L_8004F4F0;
    // sb          $v1, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r3;
L_8004F340:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $a0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r4;
    // j           L_8004F4F0
    // sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
    goto L_8004F4F0;
    // sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
L_8004F350:
    // lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // lw          $v0, 0x43($s0)
    ctx->r2 = MEM_W(0X43, ctx->r16);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // sh          $zero, 0x31($s0)
    MEM_H(0X31, ctx->r16) = 0;
    // sb          $a0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r4;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $v1, L_8004F3C8
    if (ctx->r2 != ctx->r3) {
        // sb          $zero, -0x4($s0)
        MEM_B(-0X4, ctx->r16) = 0;
        goto L_8004F3C8;
    }
    // sb          $zero, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = 0;
    // lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(0X0, ctx->r20);
    // lh          $v1, -0x2($s1)
    ctx->r3 = MEM_HS(-0X2, ctx->r17);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // sw          $v0, 0x1F($s0)
    MEM_W(0X1F, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x9($s1)
    ctx->r2 = MEM_BU(-0X9, ctx->r17);
    // lh          $v1, 0x0($s1)
    ctx->r3 = MEM_HS(0X0, ctx->r17);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x23($s0)
    MEM_W(0X23, ctx->r16) = ctx->r2;
    // lbu         $v1, -0x8($s1)
    ctx->r3 = MEM_BU(-0X8, ctx->r17);
    // lh          $a0, 0x2($s1)
    ctx->r4 = MEM_HS(0X2, ctx->r17);
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sb          $v0, 0x4D($s0)
    MEM_B(0X4D, ctx->r16) = ctx->r2;
    // sb          $v0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r2;
    // sb          $v0, 0x4B($s0)
    MEM_B(0X4B, ctx->r16) = ctx->r2;
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // addiu       $v1, $v1, 0x800
    ctx->r3 = ADD32(ctx->r3, 0X800);
    // j           L_8004F4F0
    // sw          $v1, 0x27($s0)
    MEM_W(0X27, ctx->r16) = ctx->r3;
    goto L_8004F4F0;
    // sw          $v1, 0x27($s0)
    MEM_W(0X27, ctx->r16) = ctx->r3;
L_8004F3C8:
    // lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(0X0, ctx->r20);
    // lh          $v1, -0x2($s1)
    ctx->r3 = MEM_HS(-0X2, ctx->r17);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // sw          $v0, 0x1F($s0)
    MEM_W(0X1F, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x9($s1)
    ctx->r2 = MEM_BU(-0X9, ctx->r17);
    // lh          $v1, 0x0($s1)
    ctx->r3 = MEM_HS(0X0, ctx->r17);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x23($s0)
    MEM_W(0X23, ctx->r16) = ctx->r2;
    // lbu         $v0, -0x8($s1)
    ctx->r2 = MEM_BU(-0X8, ctx->r17);
    // lh          $v1, 0x2($s1)
    ctx->r3 = MEM_HS(0X2, ctx->r17);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // sw          $v0, 0x27($s0)
    MEM_W(0X27, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(0X0, ctx->r20);
    // lbu         $v1, 0x43($s0)
    ctx->r3 = MEM_BU(0X43, ctx->r16);
    // addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sb          $v1, 0x4B($s0)
    MEM_B(0X4B, ctx->r16) = ctx->r3;
    // lbu         $v0, -0x9($s1)
    ctx->r2 = MEM_BU(-0X9, ctx->r17);
    // lbu         $v1, 0x44($s0)
    ctx->r3 = MEM_BU(0X44, ctx->r16);
    // addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sb          $v1, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r3;
    // lbu         $v0, -0x8($s1)
    ctx->r2 = MEM_BU(-0X8, ctx->r17);
    // lbu         $v1, 0x45($s0)
    ctx->r3 = MEM_BU(0X45, ctx->r16);
    // addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sb          $v1, 0x4D($s0)
    MEM_B(0X4D, ctx->r16) = ctx->r3;
    // lh          $v1, 0x0($s1)
    ctx->r3 = MEM_HS(0X0, ctx->r17);
    // nop

    // bgez        $v1, L_8004F45C
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8004F45C;
    }
    // nop

    // addiu       $v1, $v1, 0x7F
    ctx->r3 = ADD32(ctx->r3, 0X7F);
L_8004F45C:
    // lbu         $v0, 0x4A($s0)
    ctx->r2 = MEM_BU(0X4A, ctx->r16);
    // sra         $v1, $v1, 7
    ctx->r3 = S32(ctx->r3) >> 7;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // j           L_8004F4F0
    // sb          $v0, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r2;
    goto L_8004F4F0;
    // sb          $v0, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r2;
L_8004F470:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $a0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r4;
    // j           L_8004F4F0
    // sb          $v0, 0x4B($s0)
    MEM_B(0X4B, ctx->r16) = ctx->r2;
    goto L_8004F4F0;
    // sb          $v0, 0x4B($s0)
    MEM_B(0X4B, ctx->r16) = ctx->r2;
L_8004F480:
    // lhu         $v1, 0x49($s0)
    ctx->r3 = MEM_HU(0X49, ctx->r16);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sb          $a0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r4;
    // j           L_8004F4A8
    // sh          $v0, 0x4F($s0)
    MEM_H(0X4F, ctx->r16) = ctx->r2;
    goto L_8004F4A8;
    // sh          $v0, 0x4F($s0)
    MEM_H(0X4F, ctx->r16) = ctx->r2;
L_8004F494:
    // lhu         $v1, 0x49($s0)
    ctx->r3 = MEM_HU(0X49, ctx->r16);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sb          $zero, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = 0;
    // sh          $v0, 0x4F($s0)
    MEM_H(0X4F, ctx->r16) = ctx->r2;
    // sb          $a0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r4;
L_8004F4A8:
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // j           L_8004F4F0
    // sw          $v0, 0x4B($s0)
    MEM_W(0X4B, ctx->r16) = ctx->r2;
    goto L_8004F4F0;
    // sw          $v0, 0x4B($s0)
    MEM_W(0X4B, ctx->r16) = ctx->r2;
L_8004F4C0:
    // sb          $a0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r4;
L_8004F4C4:
    // j           L_8004F4F0
    // sh          $zero, 0x7($s0)
    MEM_H(0X7, ctx->r16) = 0;
    goto L_8004F4F0;
    // sh          $zero, 0x7($s0)
    MEM_H(0X7, ctx->r16) = 0;
L_8004F4CC:
    // j           L_8004F4F0
    // sb          $a0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r4;
    goto L_8004F4F0;
    // sb          $a0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r4;
L_8004F4D4:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_8004F4D8:
    // lw          $v0, 0x592C($v0)
    ctx->r2 = MEM_W(0X592C, ctx->r2);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(0X20, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_2:
L_8004F4F0:
    // addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // addiu       $s4, $s4, 0x18
    ctx->r20 = ADD32(ctx->r20, 0X18);
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s5, $v0, L_8004EF18
    if (ctx->r21 != ctx->r2) {
        // addiu       $s3, $s3, 0x58
        ctx->r19 = ADD32(ctx->r19, 0X58);
        goto L_8004EF18;
    }
    // addiu       $s3, $s3, 0x58
    ctx->r19 = ADD32(ctx->r19, 0X58);
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
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
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
