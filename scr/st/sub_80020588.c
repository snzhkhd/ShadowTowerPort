#include "recomp.h"
#include "disable_warnings.h"

void sub_80020588(uint8_t* rdram, recomp_context* ctx) {
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
    // beq         $t3, $v0, L_80020A68
    if (ctx->r11 == ctx->r2) {
        // lui         $t0, 0x1F80
        ctx->r8 = S32(0X1F80 << 16);
        goto L_80020A68;
    }
    // lui         $t0, 0x1F80
    ctx->r8 = S32(0X1F80 << 16);
    // addu        $t9, $v1, $zero
    ctx->r25 = ADD32(ctx->r3, 0);
    // addu        $t8, $v0, $zero
    ctx->r24 = ADD32(ctx->r2, 0);
    // lui         $t7, 0xFF
    ctx->r15 = S32(0XFF << 16);
    // ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
L_800205C4:
    // sll         $v0, $t3, 1
    ctx->r2 = S32(ctx->r11) << 1;
    // addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // lhu         $v0, 0x45CE($v0)
    ctx->r2 = MEM_HU(0X45CE, ctx->r2);
    // nop

    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x4130
    ctx->r2 = ADD32(ctx->r2, -0X4130);
    // addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(0X4, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // beq         $v0, $zero, L_80020630
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80020630;
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
    // lw          $v1, 0xC($t0)
    ctx->r3 = MEM_W(0XC, ctx->r8);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r3;
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // j           L_80020A50
    // nop

    goto L_80020A50;
    // nop

L_80020630:
    // lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(0X3, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v0, 0x1E4($t0)
    MEM_W(0X1E4, ctx->r8) = ctx->r2;
    // lw          $v0, 0x3C4($t0)
    ctx->r2 = MEM_W(0X3C4, ctx->r8);
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
    // lw          $v1, 0xC($t0)
    ctx->r3 = MEM_W(0XC, ctx->r8);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r3;
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // lw          $v0, 0xC($t0)
    ctx->r2 = MEM_W(0XC, ctx->r8);
    // lw          $a0, 0x20($t0)
    ctx->r4 = MEM_W(0X20, ctx->r8);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // sw          $v0, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r2;
    // lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(0X8, ctx->r4);
    // lw          $v0, 0xC($t0)
    ctx->r2 = MEM_W(0XC, ctx->r8);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r2;
    // lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(0X10, ctx->r5);
    // lw          $v1, 0xC($t0)
    ctx->r3 = MEM_W(0XC, ctx->r8);
    // lhu         $a0, 0x18($a1)
    ctx->r4 = MEM_HU(0X18, ctx->r5);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $t1, $v1, $v0
    ctx->r9 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // lhu         $v1, 0x1C($a1)
    ctx->r3 = MEM_HU(0X1C, ctx->r5);
    // lhu         $a0, 0x1E($a1)
    ctx->r4 = MEM_HU(0X1E, ctx->r5);
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lhu         $v1, 0x1A($a1)
    ctx->r3 = MEM_HU(0X1A, ctx->r5);
    // addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // sw          $a0, 0x184($t0)
    MEM_W(0X184, ctx->r8) = ctx->r4;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // lw          $v0, 0x1B4($t0)
    ctx->r2 = MEM_W(0X1B4, ctx->r8);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sw          $v1, 0x184($t0)
    MEM_W(0X184, ctx->r8) = ctx->r3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // beq         $v1, $t8, L_80020A44
    if (ctx->r3 == ctx->r24) {
        // sw          $v0, 0x1B4($t0)
        MEM_W(0X1B4, ctx->r8) = ctx->r2;
        goto L_80020A44;
    }
    // sw          $v0, 0x1B4($t0)
    MEM_W(0X1B4, ctx->r8) = ctx->r2;
    // addiu       $a3, $t1, 0xC
    ctx->r7 = ADD32(ctx->r9, 0XC);
L_80020744:
    // lhu         $v1, 0x6($a3)
    ctx->r3 = MEM_HU(0X6, ctx->r7);
    // lw          $v0, 0x34($t0)
    ctx->r2 = MEM_W(0X34, ctx->r8);
    // lhu         $a0, 0xE($a3)
    ctx->r4 = MEM_HU(0XE, ctx->r7);
    // addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v1, 0xA($a3)
    ctx->r3 = MEM_HU(0XA, ctx->r7);
    // lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(0X0, ctx->r6);
    // lw          $s2, 0x0($a0)
    ctx->r18 = MEM_W(0X0, ctx->r4);
    // addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // lw          $s1, 0x0($a1)
    ctx->r17 = MEM_W(0X0, ctx->r5);
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
    // lbu         $v0, -0x1($a3)
    ctx->r2 = MEM_BU(-0X1, ctx->r7);
    // nop

    // ori         $v0, $v0, 0x3C
    ctx->r2 = ctx->r2 | 0X3C;
    // sb          $v0, 0x47($t0)
    MEM_B(0X47, ctx->r8) = ctx->r2;
    // addiu       $v0, $t0, 0x70
    ctx->r2 = ADD32(ctx->r8, 0X70);
    // swc2        $24, 0x0($v0)
    gte_swc2(rdram, ctx, 24, 2, 0);
    // lhu         $v1, 0x12($a3)
    ctx->r3 = MEM_HU(0X12, ctx->r7);
    // lw          $v0, 0x34($t0)
    ctx->r2 = MEM_W(0X34, ctx->r8);
    // lw          $s0, 0x10($t0)
    ctx->r16 = MEM_W(0X10, ctx->r8);
    // addu        $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // swc2        $12, 0x8($s0)
    gte_swc2(rdram, ctx, 12, 16, 8);
    // swc2        $13, 0x14($s0)
    gte_swc2(rdram, ctx, 13, 16, 20);
    // swc2        $14, 0x20($s0)
    gte_swc2(rdram, ctx, 14, 16, 32);
    // lw          $s1, 0x0($t2)
    ctx->r17 = MEM_W(0X0, ctx->r10);
    // nop

    // mtc2        $s1, $12
    gte_mtc2(ctx, 17, 12);
    // nop

    // nop

    // .word       0x4B400006                   # INVALID     $k0, $zero, 0x6 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B400006);
    // addiu       $v0, $t0, 0x74
    ctx->r2 = ADD32(ctx->r8, 0X74);
    // swc2        $24, 0x0($v0)
    gte_swc2(rdram, ctx, 24, 2, 0);
    // lw          $v0, 0x70($t0)
    ctx->r2 = MEM_W(0X70, ctx->r8);
    // nop

    // bgtz        $v0, L_800207F8
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_800207F8;
    }
    // nop

    // lw          $v0, 0x74($t0)
    ctx->r2 = MEM_W(0X74, ctx->r8);
    // nop

    // bgez        $v0, L_800208EC
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800208EC;
    }
    // nop

L_800207F8:
    // lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(0X10, ctx->r8);
    // nop

    // addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
    // swc2        $12, 0x0($v0)
    gte_swc2(rdram, ctx, 12, 2, 0);
    // lh          $v0, 0x4($a2)
    ctx->r2 = MEM_HS(0X4, ctx->r6);
    // nop

    // sw          $v0, 0x84($t0)
    MEM_W(0X84, ctx->r8) = ctx->r2;
    // sw          $v0, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->r2;
    // lh          $v1, 0x4($a1)
    ctx->r3 = MEM_HS(0X4, ctx->r5);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80020834
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80020834;
    }
    // nop

    // sw          $v1, 0x84($t0)
    MEM_W(0X84, ctx->r8) = ctx->r3;
    // lh          $v1, 0x4($a1)
    ctx->r3 = MEM_HS(0X4, ctx->r5);
L_80020834:
    // lw          $v0, 0x80($t0)
    ctx->r2 = MEM_W(0X80, ctx->r8);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8002084C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002084C;
    }
    // nop

    // sw          $v1, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->r3;
L_8002084C:
    // lh          $v1, 0x4($a0)
    ctx->r3 = MEM_HS(0X4, ctx->r4);
    // lw          $v0, 0x84($t0)
    ctx->r2 = MEM_W(0X84, ctx->r8);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8002086C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002086C;
    }
    // nop

    // sw          $v1, 0x84($t0)
    MEM_W(0X84, ctx->r8) = ctx->r3;
    // lh          $v1, 0x4($a0)
    ctx->r3 = MEM_HS(0X4, ctx->r4);
L_8002086C:
    // lw          $v0, 0x80($t0)
    ctx->r2 = MEM_W(0X80, ctx->r8);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80020884
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80020884;
    }
    // nop

    // sw          $v1, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->r3;
L_80020884:
    // lh          $v1, 0x4($t2)
    ctx->r3 = MEM_HS(0X4, ctx->r10);
    // lw          $v0, 0x84($t0)
    ctx->r2 = MEM_W(0X84, ctx->r8);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_800208A4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800208A4;
    }
    // nop

    // sw          $v1, 0x84($t0)
    MEM_W(0X84, ctx->r8) = ctx->r3;
    // lh          $v1, 0x4($t2)
    ctx->r3 = MEM_HS(0X4, ctx->r10);
L_800208A4:
    // lw          $v0, 0x80($t0)
    ctx->r2 = MEM_W(0X80, ctx->r8);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800208BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800208BC;
    }
    // nop

    // sw          $v1, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->r3;
L_800208BC:
    // lw          $v0, 0x84($t0)
    ctx->r2 = MEM_W(0X84, ctx->r8);
    // lb          $v1, -0x2($a3)
    ctx->r3 = MEM_BS(-0X2, ctx->r7);
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // slti        $v0, $v1, 0x1000
    ctx->r2 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
    // beq         $v0, $zero, L_800208EC
    if (ctx->r2 == 0) {
        // sw          $v1, 0x88($t0)
        MEM_W(0X88, ctx->r8) = ctx->r3;
        goto L_800208EC;
    }
    // sw          $v1, 0x88($t0)
    MEM_W(0X88, ctx->r8) = ctx->r3;
    // lw          $v0, 0x8C($t0)
    ctx->r2 = MEM_W(0X8C, ctx->r8);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800208F8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800208F8;
    }
    // nop

L_800208EC:
    // addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // j           L_80020A30
    // addiu       $t1, $t1, 0x20
    ctx->r9 = ADD32(ctx->r9, 0X20);
    goto L_80020A30;
    // addiu       $t1, $t1, 0x20
    ctx->r9 = ADD32(ctx->r9, 0X20);
L_800208F8:
    // lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(0X10, ctx->r8);
    // lw          $v0, 0x14($t0)
    ctx->r2 = MEM_W(0X14, ctx->r8);
    // addiu       $v1, $a2, 0x34
    ctx->r3 = ADD32(ctx->r6, 0X34);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80020A68
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80020A68;
    }
    // nop

    // lw          $v0, 0x1BC($t0)
    ctx->r2 = MEM_W(0X1BC, ctx->r8);
    // sw          $v1, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r3;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x1BC($t0)
    MEM_W(0X1BC, ctx->r8) = ctx->r2;
    // lhu         $v0, -0xA($a3)
    ctx->r2 = MEM_HU(-0XA, ctx->r7);
    // nop

    // sh          $v0, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r2;
    // lhu         $v0, -0x6($a3)
    ctx->r2 = MEM_HU(-0X6, ctx->r7);
    // nop

    // sh          $v0, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r2;
    // lhu         $a1, 0x4($a3)
    ctx->r5 = MEM_HU(0X4, ctx->r7);
    // lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(0X24, ctx->r8);
    // lhu         $v1, 0x8($a3)
    ctx->r3 = MEM_HU(0X8, ctx->r7);
    // lhu         $a0, 0xC($a3)
    ctx->r4 = MEM_HU(0XC, ctx->r7);
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lwc2        $0, 0x0($a1)
    gte_lwc2(rdram, ctx, 0, 5, 0);
    // lwc2        $1, 0x4($a1)
    gte_lwc2(rdram, ctx, 1, 5, 4);
    // lwc2        $2, 0x0($v1)
    gte_lwc2(rdram, ctx, 2, 3, 0);
    // lwc2        $3, 0x4($v1)
    gte_lwc2(rdram, ctx, 3, 3, 4);
    // lwc2        $4, 0x0($v0)
    gte_lwc2(rdram, ctx, 4, 2, 0);
    // lwc2        $5, 0x4($v0)
    gte_lwc2(rdram, ctx, 5, 2, 4);
    // addiu       $v0, $t0, 0x44
    ctx->r2 = ADD32(ctx->r8, 0X44);
    // lwc2        $6, 0x0($v0)
    gte_lwc2(rdram, ctx, 6, 2, 0);
    // nop

    // nop

    // .word       0x4B18043F                   # INVALID     $t8, $t8, 0x43F # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B18043F);
    // addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    // addiu       $v1, $a2, 0x10
    ctx->r3 = ADD32(ctx->r6, 0X10);
    // addiu       $v0, $a2, 0x1C
    ctx->r2 = ADD32(ctx->r6, 0X1C);
    // swc2        $20, 0x0($a0)
    gte_swc2(rdram, ctx, 20, 4, 0);
    // swc2        $21, 0x0($v1)
    gte_swc2(rdram, ctx, 21, 3, 0);
    // swc2        $22, 0x0($v0)
    gte_swc2(rdram, ctx, 22, 2, 0);
    // lhu         $v1, 0x10($a3)
    ctx->r3 = MEM_HU(0X10, ctx->r7);
    // lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(0X24, ctx->r8);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // nop

    // nop

    // .word       0x4B08041B                   # INVALID     $t8, $t0, 0x41B # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B08041B);
    // addiu       $v0, $a2, 0x28
    ctx->r2 = ADD32(ctx->r6, 0X28);
    // swc2        $22, 0x0($v0)
    gte_swc2(rdram, ctx, 22, 2, 0);
    // lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(0X0, ctx->r9);
    // nop

    // sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // lw          $v0, -0x8($a3)
    ctx->r2 = MEM_W(-0X8, ctx->r7);
    // nop

    // sw          $v0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r2;
    // lhu         $v0, -0x4($a3)
    ctx->r2 = MEM_HU(-0X4, ctx->r7);
    // addiu       $t1, $t1, 0x20
    ctx->r9 = ADD32(ctx->r9, 0X20);
    // sh          $v0, 0x24($a2)
    MEM_H(0X24, ctx->r6) = ctx->r2;
    // lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(0X0, ctx->r7);
    // addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // sh          $v0, 0x30($a2)
    MEM_H(0X30, ctx->r6) = ctx->r2;
    // lw          $v0, 0x88($t0)
    ctx->r2 = MEM_W(0X88, ctx->r8);
    // lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(0X0, ctx->r8);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0xC00
    ctx->r3 = S32(0XC00 << 16);
    // and         $v0, $v0, $t7
    ctx->r2 = ctx->r2 & ctx->r15;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // lw          $v0, 0x88($t0)
    ctx->r2 = MEM_W(0X88, ctx->r8);
    // lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(0X0, ctx->r8);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // and         $v1, $a2, $t7
    ctx->r3 = ctx->r6 & ctx->r15;
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_80020A30:
    // lw          $v0, 0x184($t0)
    ctx->r2 = MEM_W(0X184, ctx->r8);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $v0, $t8, L_80020744
    if (ctx->r2 != ctx->r24) {
        // sw          $v0, 0x184($t0)
        MEM_W(0X184, ctx->r8) = ctx->r2;
        goto L_80020744;
    }
    // sw          $v0, 0x184($t0)
    MEM_W(0X184, ctx->r8) = ctx->r2;
L_80020A44:
    // lw          $v0, 0x20($t0)
    ctx->r2 = MEM_W(0X20, ctx->r8);
    // nop

    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
L_80020A50:
    // lw          $v1, 0x34($t0)
    ctx->r3 = MEM_W(0X34, ctx->r8);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // bne         $t3, $t8, L_800205C4
    if (ctx->r11 != ctx->r24) {
        // sw          $v1, 0x34($t0)
        MEM_W(0X34, ctx->r8) = ctx->r3;
        goto L_800205C4;
    }
    // sw          $v1, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r3;
L_80020A68:
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
