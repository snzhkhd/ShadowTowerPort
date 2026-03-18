#include "recomp.h"
#include "disable_warnings.h"

void sub_8001F954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v1, $v0, 0x5948
    ctx->r3 = ADD32(ctx->r2, 0X5948);
    // sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // lhu         $t3, 0x44CC($v1)
    ctx->r11 = MEM_HU(0X44CC, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // beq         $t3, $v0, L_8001FCE8
    if (ctx->r11 == ctx->r2) {
        // lui         $a1, 0x1F80
        ctx->r5 = S32(0X1F80 << 16);
        goto L_8001FCE8;
    }
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // addu        $t9, $v1, $zero
    ctx->r25 = ADD32(ctx->r3, 0);
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $t8, $v0, -0x4130
    ctx->r24 = ADD32(ctx->r2, -0X4130);
    // lui         $t7, 0xFF
    ctx->r15 = S32(0XFF << 16);
    // ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
L_8001F994:
    // sll         $v0, $t3, 1
    ctx->r2 = S32(ctx->r11) << 1;
    // addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // lhu         $v1, 0x45CE($v0)
    ctx->r3 = MEM_HU(0X45CE, ctx->r2);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a0, $v0, $t8
    ctx->r4 = ADD32(ctx->r2, ctx->r24);
    // lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(0X4, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // beq         $v0, $zero, L_8001F9F8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001F9F8;
    }
    // nop

    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // nop

    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lw          $v1, 0xC($a1)
    ctx->r3 = MEM_W(0XC, ctx->r5);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r3;
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // j           L_8001FCCC
    // nop

    goto L_8001FCCC;
    // nop

L_8001F9F8:
    // lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(0X3, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v0, 0x1E4($a1)
    MEM_W(0X1E4, ctx->r5) = ctx->r2;
    // lw          $v0, 0x3C4($a1)
    ctx->r2 = MEM_W(0X3C4, ctx->r5);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(0X0, ctx->r2);
    // lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(0X4, ctx->r2);
    // ctc2        $t4, $8
    gte_ctc2(ctx, 12, 8);
    // ctc2        $t5, $9
    gte_ctc2(ctx, 13, 9);
    // lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(0X8, ctx->r2);
    // lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(0XC, ctx->r2);
    // lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(0X10, ctx->r2);
    // ctc2        $t4, $10
    gte_ctc2(ctx, 12, 10);
    // ctc2        $t5, $11
    gte_ctc2(ctx, 13, 11);
    // ctc2        $t6, $12
    gte_ctc2(ctx, 14, 12);
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // nop

    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lw          $v1, 0xC($a1)
    ctx->r3 = MEM_W(0XC, ctx->r5);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r3;
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(0XC, ctx->r5);
    // lw          $a0, 0x20($a1)
    ctx->r4 = MEM_W(0X20, ctx->r5);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->r2;
    // lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(0X8, ctx->r4);
    // lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(0XC, ctx->r5);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r2;
    // lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(0X10, ctx->r4);
    // lhu         $t2, 0x18($a0)
    ctx->r10 = MEM_HU(0X18, ctx->r4);
    // lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(0XC, ctx->r5);
    // lw          $v1, 0x1B4($a1)
    ctx->r3 = MEM_W(0X1B4, ctx->r5);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $t1, $a0, $v0
    ctx->r9 = ADD32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // addu        $v0, $t2, $zero
    ctx->r2 = ADD32(ctx->r10, 0);
    // addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // beq         $v0, $zero, L_8001FCC0
    if (ctx->r2 == 0) {
        // sw          $v1, 0x1B4($a1)
        MEM_W(0X1B4, ctx->r5) = ctx->r3;
        goto L_8001FCC0;
    }
    // sw          $v1, 0x1B4($a1)
    MEM_W(0X1B4, ctx->r5) = ctx->r3;
    // addiu       $a2, $t1, 0x8
    ctx->r6 = ADD32(ctx->r9, 0X8);
L_8001FAC4:
    // lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(0X6, ctx->r6);
    // lw          $v0, 0x34($a1)
    ctx->r2 = MEM_W(0X34, ctx->r5);
    // lhu         $a0, 0xA($a2)
    ctx->r4 = MEM_HU(0XA, ctx->r6);
    // addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v1, 0x8($a2)
    ctx->r3 = MEM_HU(0X8, ctx->r6);
    // lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(0X0, ctx->r8);
    // lw          $s2, 0x0($a0)
    ctx->r18 = MEM_W(0X0, ctx->r4);
    // addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
    // lw          $s1, 0x0($a3)
    ctx->r17 = MEM_W(0X0, ctx->r7);
    // mtc2        $s0, $12
    gte_mtc2(ctx, 16, 12);
    // mtc2        $s2, $14
    gte_mtc2(ctx, 18, 14);
    // mtc2        $s1, $13
    gte_mtc2(ctx, 17, 13);
    // nop

    // nop

    // .word       0x4B400006                   # INVALID     $k0, $zero, 0x6 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B400006);
    // lbu         $v0, 0x3($a2)
    ctx->r2 = MEM_BU(0X3, ctx->r6);
    // nop

    // ori         $v0, $v0, 0x24
    ctx->r2 = ctx->r2 | 0X24;
    // sb          $v0, 0x47($a1)
    MEM_B(0X47, ctx->r5) = ctx->r2;
    // addiu       $v0, $a1, 0x70
    ctx->r2 = ADD32(ctx->r5, 0X70);
    // swc2        $24, 0x0($v0)
    gte_swc2(rdram, ctx, 24, 2, 0);
    // lw          $v0, 0x70($a1)
    ctx->r2 = MEM_W(0X70, ctx->r5);
    // nop

    // blez        $v0, L_8001FBEC
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8001FBEC;
    }
    // nop

    // lw          $s0, 0x10($a1)
    ctx->r16 = MEM_W(0X10, ctx->r5);
    // nop

    // swc2        $12, 0x8($s0)
    gte_swc2(rdram, ctx, 12, 16, 8);
    // swc2        $13, 0x10($s0)
    gte_swc2(rdram, ctx, 13, 16, 16);
    // swc2        $14, 0x18($s0)
    gte_swc2(rdram, ctx, 14, 16, 24);
    // lh          $v0, 0x4($t0)
    ctx->r2 = MEM_HS(0X4, ctx->r8);
    // nop

    // sw          $v0, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->r2;
    // sw          $v0, 0x80($a1)
    MEM_W(0X80, ctx->r5) = ctx->r2;
    // lh          $v1, 0x4($a3)
    ctx->r3 = MEM_HS(0X4, ctx->r7);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8001FB6C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001FB6C;
    }
    // nop

    // sw          $v1, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->r3;
    // lh          $v1, 0x4($a3)
    ctx->r3 = MEM_HS(0X4, ctx->r7);
L_8001FB6C:
    // lw          $v0, 0x80($a1)
    ctx->r2 = MEM_W(0X80, ctx->r5);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8001FB84
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001FB84;
    }
    // nop

    // sw          $v1, 0x80($a1)
    MEM_W(0X80, ctx->r5) = ctx->r3;
L_8001FB84:
    // lh          $v1, 0x4($a0)
    ctx->r3 = MEM_HS(0X4, ctx->r4);
    // lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(0X84, ctx->r5);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8001FBA4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001FBA4;
    }
    // nop

    // sw          $v1, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->r3;
    // lh          $v1, 0x4($a0)
    ctx->r3 = MEM_HS(0X4, ctx->r4);
L_8001FBA4:
    // lw          $v0, 0x80($a1)
    ctx->r2 = MEM_W(0X80, ctx->r5);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8001FBBC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001FBBC;
    }
    // nop

    // sw          $v1, 0x80($a1)
    MEM_W(0X80, ctx->r5) = ctx->r3;
L_8001FBBC:
    // lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(0X84, ctx->r5);
    // lb          $v1, 0x2($a2)
    ctx->r3 = MEM_BS(0X2, ctx->r6);
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // slti        $v0, $v1, 0x1000
    ctx->r2 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
    // beq         $v0, $zero, L_8001FBEC
    if (ctx->r2 == 0) {
        // sw          $v1, 0x88($a1)
        MEM_W(0X88, ctx->r5) = ctx->r3;
        goto L_8001FBEC;
    }
    // sw          $v1, 0x88($a1)
    MEM_W(0X88, ctx->r5) = ctx->r3;
    // lw          $v0, 0x8C($a1)
    ctx->r2 = MEM_W(0X8C, ctx->r5);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8001FBF8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001FBF8;
    }
    // nop

L_8001FBEC:
    // addiu       $a2, $a2, 0x14
    ctx->r6 = ADD32(ctx->r6, 0X14);
    // j           L_8001FCB4
    // addiu       $t1, $t1, 0x14
    ctx->r9 = ADD32(ctx->r9, 0X14);
    goto L_8001FCB4;
    // addiu       $t1, $t1, 0x14
    ctx->r9 = ADD32(ctx->r9, 0X14);
L_8001FBF8:
    // lw          $a0, 0x10($a1)
    ctx->r4 = MEM_W(0X10, ctx->r5);
    // lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(0X14, ctx->r5);
    // addiu       $v1, $a0, 0x20
    ctx->r3 = ADD32(ctx->r4, 0X20);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8001FCE8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001FCE8;
    }
    // nop

    // lw          $v0, 0x1BC($a1)
    ctx->r2 = MEM_W(0X1BC, ctx->r5);
    // sw          $v1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r3;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x1BC($a1)
    MEM_W(0X1BC, ctx->r5) = ctx->r2;
    // lhu         $v1, 0x4($a2)
    ctx->r3 = MEM_HU(0X4, ctx->r6);
    // lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(0X24, ctx->r5);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // addiu       $v0, $a1, 0x44
    ctx->r2 = ADD32(ctx->r5, 0X44);
    // lwc2        $6, 0x0($v0)
    gte_lwc2(rdram, ctx, 6, 2, 0);
    // lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(0X0, ctx->r9);
    // nop

    // sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // lw          $v0, -0x4($a2)
    ctx->r2 = MEM_W(-0X4, ctx->r6);
    // nop

    // sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // .word       0x4B08041B                   # INVALID     $t8, $t0, 0x41B # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B08041B);
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // nop

    // sh          $v0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r2;
    // lw          $v0, 0x88($a1)
    ctx->r2 = MEM_W(0X88, ctx->r5);
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // and         $v0, $v0, $t7
    ctx->r2 = ctx->r2 & ctx->r15;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // swc2        $22, 0x0($v0)
    gte_swc2(rdram, ctx, 22, 2, 0);
    // addiu       $a2, $a2, 0x14
    ctx->r6 = ADD32(ctx->r6, 0X14);
    // addiu       $t1, $t1, 0x14
    ctx->r9 = ADD32(ctx->r9, 0X14);
    // lw          $v0, 0x88($a1)
    ctx->r2 = MEM_W(0X88, ctx->r5);
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // and         $v1, $a0, $t7
    ctx->r3 = ctx->r4 & ctx->r15;
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_8001FCB4:
    // addu        $v0, $t2, $zero
    ctx->r2 = ADD32(ctx->r10, 0);
    // bne         $v0, $zero, L_8001FAC4
    if (ctx->r2 != 0) {
        // addiu       $t2, $t2, -0x1
        ctx->r10 = ADD32(ctx->r10, -0X1);
        goto L_8001FAC4;
    }
    // addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
L_8001FCC0:
    // lw          $v0, 0x20($a1)
    ctx->r2 = MEM_W(0X20, ctx->r5);
    // nop

    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
L_8001FCCC:
    // lw          $v1, 0x34($a1)
    ctx->r3 = MEM_W(0X34, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $t3, $v0, L_8001F994
    if (ctx->r11 != ctx->r2) {
        // sw          $v1, 0x34($a1)
        MEM_W(0X34, ctx->r5) = ctx->r3;
        goto L_8001F994;
    }
    // sw          $v1, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r3;
L_8001FCE8:
    // lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(0X8, ctx->r29);
    // lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(0X4, ctx->r29);
    // lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(0X0, ctx->r29);
    // addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // jr          $ra
    // nop

    return;
    // nop

;}
