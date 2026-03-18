#include "recomp.h"
#include "disable_warnings.h"

void sub_8001E5A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x260
    ctx->r29 = ADD32(ctx->r29, -0X260);
    // sw          $s7, 0x254($sp)
    MEM_W(0X254, ctx->r29) = ctx->r23;
    // addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // sw          $fp, 0x258($sp)
    MEM_W(0X258, ctx->r29) = ctx->r30;
    // lhu         $fp, -0x61EC($v0)
    ctx->r30 = MEM_HU(-0X61EC, ctx->r2);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $ra, 0x25C($sp)
    MEM_W(0X25C, ctx->r29) = ctx->r31;
    // sw          $s6, 0x250($sp)
    MEM_W(0X250, ctx->r29) = ctx->r22;
    // sw          $s5, 0x24C($sp)
    MEM_W(0X24C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r20;
    // sw          $s3, 0x244($sp)
    MEM_W(0X244, ctx->r29) = ctx->r19;
    // sw          $s2, 0x240($sp)
    MEM_W(0X240, ctx->r29) = ctx->r18;
    // sw          $s1, 0x23C($sp)
    MEM_W(0X23C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x238($sp)
    MEM_W(0X238, ctx->r29) = ctx->r16;
    // sw          $a0, 0x260($sp)
    MEM_W(0X260, ctx->r29) = ctx->r4;
    // lbu         $v1, 0x6DFC($v0)
    ctx->r3 = MEM_BU(0X6DFC, ctx->r2);
    // nop

    // andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // beq         $v0, $zero, L_8001E610
    if (ctx->r2 == 0) {
        // lui         $s2, 0x1F80
        ctx->r18 = S32(0X1F80 << 16);
        goto L_8001E610;
    }
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // j           L_8001E620
    // addiu       $s7, $v0, -0x1AE4
    ctx->r23 = ADD32(ctx->r2, -0X1AE4);
    goto L_8001E620;
    // addiu       $s7, $v0, -0x1AE4
    ctx->r23 = ADD32(ctx->r2, -0X1AE4);
L_8001E610:
    // andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // beq         $v0, $zero, L_8001E620
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8002
        ctx->r2 = S32(0X8002 << 16);
        goto L_8001E620;
    }
    // lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // addiu       $s7, $v0, -0x1AA4
    ctx->r23 = ADD32(ctx->r2, -0X1AA4);
L_8001E620:
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $fp, $v0, L_8001EDF4
    if (ctx->r30 == ctx->r2) {
        // addiu       $a3, $sp, 0x34
        ctx->r7 = ADD32(ctx->r29, 0X34);
        goto L_8001EDF4;
    }
    // addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // addiu       $t0, $sp, 0x4C
    ctx->r8 = ADD32(ctx->r29, 0X4C);
    // addiu       $t1, $sp, 0x64
    ctx->r9 = ADD32(ctx->r29, 0X64);
    // sw          $a3, 0x228($sp)
    MEM_W(0X228, ctx->r29) = ctx->r7;
    // sw          $t0, 0x22C($sp)
    MEM_W(0X22C, ctx->r29) = ctx->r8;
    // sw          $t1, 0x230($sp)
    MEM_W(0X230, ctx->r29) = ctx->r9;
L_8001E644:
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // addiu       $v1, $v1, 0x5948
    ctx->r3 = ADD32(ctx->r3, 0X5948);
    // sll         $v0, $fp, 1
    ctx->r2 = S32(ctx->r30) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
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
    // bne         $v0, $zero, L_8001E6B8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001E6B8;
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
    // lw          $v1, 0xC($s2)
    ctx->r3 = MEM_W(0XC, ctx->r18);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r3;
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // j           L_8001EDD8
    // nop

    goto L_8001EDD8;
    // nop

L_8001E6B8:
    // lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(0X3, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v0, 0x1E4($s2)
    MEM_W(0X1E4, ctx->r18) = ctx->r2;
    // lw          $v0, 0x3C4($s2)
    ctx->r2 = MEM_W(0X3C4, ctx->r18);
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
    // lw          $v1, 0xC($s2)
    ctx->r3 = MEM_W(0XC, ctx->r18);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r3;
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(0XC, ctx->r18);
    // lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(0X20, ctx->r18);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // sw          $v0, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->r2;
    // lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(0X8, ctx->r4);
    // lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(0XC, ctx->r18);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r2;
    // lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(0X10, ctx->r5);
    // lw          $v1, 0xC($s2)
    ctx->r3 = MEM_W(0XC, ctx->r18);
    // lhu         $a0, 0x18($a1)
    ctx->r4 = MEM_HU(0X18, ctx->r5);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $s4, $v1, $v0
    ctx->r20 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s4, $s4, $v0
    ctx->r20 = ADD32(ctx->r20, ctx->r2);
    // lhu         $v1, 0x1C($a1)
    ctx->r3 = MEM_HU(0X1C, ctx->r5);
    // lhu         $a0, 0x1A($a1)
    ctx->r4 = MEM_HU(0X1A, ctx->r5);
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s4, $s4, $v0
    ctx->r20 = ADD32(ctx->r20, ctx->r2);
    // sw          $a0, 0x184($s2)
    MEM_W(0X184, ctx->r18) = ctx->r4;
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // lw          $v0, 0x1B4($s2)
    ctx->r2 = MEM_W(0X1B4, ctx->r18);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sw          $v1, 0x184($s2)
    MEM_W(0X184, ctx->r18) = ctx->r3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, 0x1B4($s2)
    MEM_W(0X1B4, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_8001EDCC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8001EDCC;
    }
    // nop

    // addiu       $s1, $s4, 0x14
    ctx->r17 = ADD32(ctx->r20, 0X14);
L_8001E7C0:
    // lhu         $v1, -0x6($s1)
    ctx->r3 = MEM_HU(-0X6, ctx->r17);
    // lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(0X34, ctx->r18);
    // lhu         $a0, 0x2($s1)
    ctx->r4 = MEM_HU(0X2, ctx->r17);
    // addu        $s5, $v0, $v1
    ctx->r21 = ADD32(ctx->r2, ctx->r3);
    // addu        $s6, $v0, $a0
    ctx->r22 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v1, -0x2($s1)
    ctx->r3 = MEM_HU(-0X2, ctx->r17);
    // lw          $a3, 0x0($s5)
    ctx->r7 = MEM_W(0X0, ctx->r21);
    // lw          $t1, 0x0($s6)
    ctx->r9 = MEM_W(0X0, ctx->r22);
    // addu        $s3, $v0, $v1
    ctx->r19 = ADD32(ctx->r2, ctx->r3);
    // lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(0X0, ctx->r19);
    // mtc2        $a3, $12
    gte_mtc2(ctx, 7, 12);
    // mtc2        $t1, $14
    gte_mtc2(ctx, 9, 14);
    // mtc2        $t0, $13
    gte_mtc2(ctx, 8, 13);
    // nop

    // nop

    // .word       0x4B400006                   # INVALID     $k0, $zero, 0x6 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B400006);
    // lbu         $v0, -0x9($s1)
    ctx->r2 = MEM_BU(-0X9, ctx->r17);
    // nop

    // ori         $v0, $v0, 0x34
    ctx->r2 = ctx->r2 | 0X34;
    // sb          $v0, 0x47($s2)
    MEM_B(0X47, ctx->r18) = ctx->r2;
    // addiu       $v0, $s2, 0x70
    ctx->r2 = ADD32(ctx->r18, 0X70);
    // swc2        $24, 0x0($v0)
    gte_swc2(rdram, ctx, 24, 2, 0);
    // lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(0X70, ctx->r18);
    // nop

    // blez        $v0, L_8001EDB0
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8001EDB0;
    }
    // nop

    // lw          $a3, 0x10($s2)
    ctx->r7 = MEM_W(0X10, ctx->r18);
    // nop

    // swc2        $12, 0x8($a3)
    gte_swc2(rdram, ctx, 12, 7, 8);
    // swc2        $13, 0x14($a3)
    gte_swc2(rdram, ctx, 13, 7, 20);
    // swc2        $14, 0x20($a3)
    gte_swc2(rdram, ctx, 14, 7, 32);
    // lh          $v0, 0x4($s5)
    ctx->r2 = MEM_HS(0X4, ctx->r21);
    // nop

    // sw          $v0, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r2;
    // sw          $v0, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r2;
    // lh          $v1, 0x4($s3)
    ctx->r3 = MEM_HS(0X4, ctx->r19);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8001E868
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001E868;
    }
    // nop

    // sw          $v1, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r3;
    // lh          $v1, 0x4($s3)
    ctx->r3 = MEM_HS(0X4, ctx->r19);
L_8001E868:
    // lw          $v0, 0x80($s2)
    ctx->r2 = MEM_W(0X80, ctx->r18);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8001E880
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001E880;
    }
    // nop

    // sw          $v1, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r3;
L_8001E880:
    // lh          $v1, 0x4($s6)
    ctx->r3 = MEM_HS(0X4, ctx->r22);
    // lw          $v0, 0x84($s2)
    ctx->r2 = MEM_W(0X84, ctx->r18);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8001E8A0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001E8A0;
    }
    // nop

    // sw          $v1, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r3;
    // lh          $v1, 0x4($s6)
    ctx->r3 = MEM_HS(0X4, ctx->r22);
L_8001E8A0:
    // lw          $v0, 0x80($s2)
    ctx->r2 = MEM_W(0X80, ctx->r18);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8001E8B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001E8B8;
    }
    // nop

    // sw          $v1, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r3;
L_8001E8B8:
    // lw          $v0, 0x84($s2)
    ctx->r2 = MEM_W(0X84, ctx->r18);
    // lb          $v1, -0xA($s1)
    ctx->r3 = MEM_BS(-0XA, ctx->r17);
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // slti        $v0, $v1, 0x1000
    ctx->r2 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
    // beq         $v0, $zero, L_8001EDB0
    if (ctx->r2 == 0) {
        // sw          $v1, 0x88($s2)
        MEM_W(0X88, ctx->r18) = ctx->r3;
        goto L_8001EDB0;
    }
    // sw          $v1, 0x88($s2)
    MEM_W(0X88, ctx->r18) = ctx->r3;
    // lw          $v0, 0x8C($s2)
    ctx->r2 = MEM_W(0X8C, ctx->r18);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8001EDB0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001EDB0;
    }
    // nop

    // lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(0X70, ctx->r18);
    // nop

    // slti        $v0, $v0, 0x4001
    ctx->r2 = SIGNED(ctx->r2) < 0X4001 ? 1 : 0;
    // bne         $v0, $zero, L_8001EC3C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8001EC3C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v1, 0x70($s2)
    ctx->r3 = MEM_W(0X70, ctx->r18);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8001E930
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8001E930;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v1, 0x70($s2)
    ctx->r3 = MEM_W(0X70, ctx->r18);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8001E930
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8001E930;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_8001E930:
    // addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lhu         $v0, -0x12($s1)
    ctx->r2 = MEM_HU(-0X12, ctx->r17);
    // nop

    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, -0xE($s1)
    ctx->r2 = MEM_HU(-0XE, ctx->r17);
    // nop

    // sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // addiu       $v0, $s2, 0x44
    ctx->r2 = ADD32(ctx->r18, 0X44);
    // lwc2        $6, 0x0($v0)
    gte_lwc2(rdram, ctx, 6, 2, 0);
    // lhu         $v1, -0x8($s1)
    ctx->r3 = MEM_HU(-0X8, ctx->r17);
    // lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(0X24, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // lhu         $t0, 0x6($s5)
    ctx->r8 = MEM_HU(0X6, ctx->r21);
    // nop

    // mtc2        $t0, $8
    gte_mtc2(ctx, 8, 8);
    // nop

    // nop

    // .word       0x4AE80413                   # INVALID     $s7, $t0, 0x413 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AE80413);
    // lw          $t1, 0x228($sp)
    ctx->r9 = MEM_W(0X228, ctx->r29);
    // nop

    // swc2        $22, 0x0($t1)
    gte_swc2(rdram, ctx, 22, 9, 0);
    // lhu         $v1, -0x4($s1)
    ctx->r3 = MEM_HU(-0X4, ctx->r17);
    // lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(0X24, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // lhu         $a3, 0x6($s3)
    ctx->r7 = MEM_HU(0X6, ctx->r19);
    // nop

    // mtc2        $a3, $8
    gte_mtc2(ctx, 7, 8);
    // nop

    // nop

    // .word       0x4AE80413                   # INVALID     $s7, $t0, 0x413 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AE80413);
    // lw          $t0, 0x22C($sp)
    ctx->r8 = MEM_W(0X22C, ctx->r29);
    // nop

    // swc2        $22, 0x0($t0)
    gte_swc2(rdram, ctx, 22, 8, 0);
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(0X24, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // lhu         $t1, 0x6($s6)
    ctx->r9 = MEM_HU(0X6, ctx->r22);
    // nop

    // mtc2        $t1, $8
    gte_mtc2(ctx, 9, 8);
    // nop

    // nop

    // .word       0x4AE80413                   # INVALID     $s7, $t0, 0x413 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AE80413);
    // lw          $a3, 0x230($sp)
    ctx->r7 = MEM_W(0X230, ctx->r29);
    // nop

    // swc2        $22, 0x0($a3)
    gte_swc2(rdram, ctx, 22, 7, 0);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // addiu       $t0, $t0, -0x2F70
    ctx->r8 = ADD32(ctx->r8, -0X2F70);
    // addu        $s0, $t0, $v0
    ctx->r16 = ADD32(ctx->r8, ctx->r2);
    // lbu         $v0, 0x6DFC($s0)
    ctx->r2 = MEM_BU(0X6DFC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // beq         $v0, $zero, L_8001EA60
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001EA60;
    }
    // nop

    // lw          $a0, 0x228($sp)
    ctx->r4 = MEM_W(0X228, ctx->r29);
    // jalr        $s7
    // nop

    LOOKUP_FUNC(ctx->r23)(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $a0, 0x22C($sp)
    ctx->r4 = MEM_W(0X22C, ctx->r29);
    // jalr        $s7
    // nop

    LOOKUP_FUNC(ctx->r23)(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $a0, 0x230($sp)
    ctx->r4 = MEM_W(0X230, ctx->r29);
    // jalr        $s7
    // nop

    LOOKUP_FUNC(ctx->r23)(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_8001EA60:
    // lw          $v0, 0x1E4($s2)
    ctx->r2 = MEM_W(0X1E4, ctx->r18);
    // addiu       $v1, $s0, 0x6D28
    ctx->r3 = ADD32(ctx->r16, 0X6D28);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(0X0, ctx->r2);
    // lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(0X4, ctx->r2);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(0X8, ctx->r2);
    // lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(0XC, ctx->r2);
    // lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(0X10, ctx->r2);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lw          $t1, 0x260($sp)
    ctx->r9 = MEM_W(0X260, ctx->r29);
    // sll         $v0, $fp, 4
    ctx->r2 = S32(ctx->r30) << 4;
    // addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(0X0, ctx->r2);
    // lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(0X4, ctx->r2);
    // lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(0X8, ctx->r2);
    // ctc2        $t4, $5
    gte_ctc2(ctx, 12, 5);
    // ctc2        $t5, $6
    gte_ctc2(ctx, 13, 6);
    // ctc2        $t6, $7
    gte_ctc2(ctx, 14, 7);
    // lwl         $v0, 0x47($s2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X47, ctx->r18);
    // lwr         $v0, 0x44($s2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X44, ctx->r18);
    // nop

    // swl         $v0, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r2);
    // swr         $v0, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r2);
    // addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // sw          $v0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // sw          $v0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r2;
    // lw          $v0, 0x88($s2)
    ctx->r2 = MEM_W(0X88, ctx->r18);
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // lwl         $v0, 0x3($s5)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r21);
    // lwr         $v0, 0x0($s5)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r21);
    // nop

    // swl         $v0, 0x3B($sp)
    do_swl(rdram, 0X3B, ctx->r29, ctx->r2);
    // swr         $v0, 0x38($sp)
    do_swr(rdram, 0X38, ctx->r29, ctx->r2);
    // lwl         $v0, 0x3($s3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r19);
    // lwr         $v0, 0x0($s3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r19);
    // nop

    // swl         $v0, 0x53($sp)
    do_swl(rdram, 0X53, ctx->r29, ctx->r2);
    // swr         $v0, 0x50($sp)
    do_swr(rdram, 0X50, ctx->r29, ctx->r2);
    // lwl         $v0, 0x3($s6)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r22);
    // lwr         $v0, 0x0($s6)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r22);
    // nop

    // swl         $v0, 0x6B($sp)
    do_swl(rdram, 0X6B, ctx->r29, ctx->r2);
    // swr         $v0, 0x68($sp)
    do_swr(rdram, 0X68, ctx->r29, ctx->r2);
    // lh          $v0, 0x4($s5)
    ctx->r2 = MEM_HS(0X4, ctx->r21);
    // nop

    // sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // lh          $v0, 0x4($s3)
    ctx->r2 = MEM_HS(0X4, ctx->r19);
    // nop

    // sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // lh          $v0, 0x4($s6)
    ctx->r2 = MEM_HS(0X4, ctx->r22);
    // nop

    // sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // lhu         $v1, -0x6($s1)
    ctx->r3 = MEM_HU(-0X6, ctx->r17);
    // lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(0X3C, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r3);
    // swr         $v1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r3);
    // swl         $a0, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r4);
    // swr         $a0, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r4);
    // lhu         $v1, -0x2($s1)
    ctx->r3 = MEM_HU(-0X2, ctx->r17);
    // lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(0X3C, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r3);
    // swr         $v1, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r3);
    // swl         $a0, 0x47($sp)
    do_swl(rdram, 0X47, ctx->r29, ctx->r4);
    // swr         $a0, 0x44($sp)
    do_swr(rdram, 0X44, ctx->r29, ctx->r4);
    // lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(0X2, ctx->r17);
    // lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(0X3C, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x5B($sp)
    do_swl(rdram, 0X5B, ctx->r29, ctx->r3);
    // swr         $v1, 0x58($sp)
    do_swr(rdram, 0X58, ctx->r29, ctx->r3);
    // swl         $a0, 0x5F($sp)
    do_swl(rdram, 0X5F, ctx->r29, ctx->r4);
    // swr         $a0, 0x5C($sp)
    do_swr(rdram, 0X5C, ctx->r29, ctx->r4);
    // lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(0X0, ctx->r20);
    // addiu       $s4, $s4, 0x18
    ctx->r20 = ADD32(ctx->r20, 0X18);
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(0X10, ctx->r18);
    // lw          $v0, -0x10($s1)
    ctx->r2 = MEM_W(-0X10, ctx->r17);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // lw          $v0, -0xC($s1)
    ctx->r2 = MEM_W(-0XC, ctx->r17);
    // addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // jal         0x80075EC4
    // sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    RCpolyGT3(rdram, ctx);
    goto after_3;
    // sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    after_3:
    // sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(0X10, ctx->r29);
    // lw          $v1, 0x1C0($s2)
    ctx->r3 = MEM_W(0X1C0, ctx->r18);
    // sllv        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2) << (ctx->r4 & 31);
    // sllv        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2) << (ctx->r4 & 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // j           L_8001EDB8
    // sw          $v1, 0x1C0($s2)
    MEM_W(0X1C0, ctx->r18) = ctx->r3;
    goto L_8001EDB8;
    // sw          $v1, 0x1C0($s2)
    MEM_W(0X1C0, ctx->r18) = ctx->r3;
L_8001EC3C:
    // lw          $a1, 0x10($s2)
    ctx->r5 = MEM_W(0X10, ctx->r18);
    // lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(0X14, ctx->r18);
    // addiu       $v1, $a1, 0x28
    ctx->r3 = ADD32(ctx->r5, 0X28);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8001EDF4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001EDF4;
    }
    // nop

    // lw          $v0, 0x1BC($s2)
    ctx->r2 = MEM_W(0X1BC, ctx->r18);
    // sw          $v1, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r3;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x1BC($s2)
    MEM_W(0X1BC, ctx->r18) = ctx->r2;
    // addiu       $v0, $s2, 0x44
    ctx->r2 = ADD32(ctx->r18, 0X44);
    // lwc2        $6, 0x0($v0)
    gte_lwc2(rdram, ctx, 6, 2, 0);
    // lhu         $v1, -0x8($s1)
    ctx->r3 = MEM_HU(-0X8, ctx->r17);
    // lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(0X24, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // lhu         $s5, 0x6($s5)
    ctx->r21 = MEM_HU(0X6, ctx->r21);
    // nop

    // mtc2        $s5, $8
    gte_mtc2(ctx, 21, 8);
    // lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(0X0, ctx->r20);
    // nop

    // sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // .word       0x4AE80413                   # INVALID     $s7, $t0, 0x413 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AE80413);
    // lw          $v0, -0x10($s1)
    ctx->r2 = MEM_W(-0X10, ctx->r17);
    // nop

    // sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    // lhu         $v0, -0xC($s1)
    ctx->r2 = MEM_HU(-0XC, ctx->r17);
    // addiu       $a2, $a1, 0x4
    ctx->r6 = ADD32(ctx->r5, 0X4);
    // sh          $v0, 0x24($a1)
    MEM_H(0X24, ctx->r5) = ctx->r2;
    // swc2        $22, 0x0($a2)
    gte_swc2(rdram, ctx, 22, 6, 0);
    // lhu         $v1, -0x4($s1)
    ctx->r3 = MEM_HU(-0X4, ctx->r17);
    // lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(0X24, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // lhu         $s3, 0x6($s3)
    ctx->r19 = MEM_HU(0X6, ctx->r19);
    // nop

    // mtc2        $s3, $8
    gte_mtc2(ctx, 19, 8);
    // nop

    // nop

    // .word       0x4AE80413                   # INVALID     $s7, $t0, 0x413 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AE80413);
    // lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // addiu       $s3, $a1, 0x10
    ctx->r19 = ADD32(ctx->r5, 0X10);
    // lw          $v0, 0x88($s2)
    ctx->r2 = MEM_W(0X88, ctx->r18);
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x900
    ctx->r3 = S32(0X900 << 16);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // swc2        $22, 0x0($s3)
    gte_swc2(rdram, ctx, 22, 19, 0);
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(0X24, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // lhu         $s6, 0x6($s6)
    ctx->r22 = MEM_HU(0X6, ctx->r22);
    // nop

    // mtc2        $s6, $8
    gte_mtc2(ctx, 22, 8);
    // nop

    // nop

    // .word       0x4AE80413                   # INVALID     $s7, $t0, 0x413 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AE80413);
    // and         $a0, $a1, $a0
    ctx->r4 = ctx->r5 & ctx->r4;
    // addiu       $s0, $a1, 0x1C
    ctx->r16 = ADD32(ctx->r5, 0X1C);
    // lw          $v0, 0x88($s2)
    ctx->r2 = MEM_W(0X88, ctx->r18);
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // swc2        $22, 0x0($s0)
    gte_swc2(rdram, ctx, 22, 16, 0);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // addiu       $a3, $a3, -0x2F70
    ctx->r7 = ADD32(ctx->r7, -0X2F70);
    // addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // lbu         $v0, 0x6DFC($v0)
    ctx->r2 = MEM_BU(0X6DFC, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // beq         $v0, $zero, L_8001EDB0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001EDB0;
    }
    // nop

    // jalr        $s7
    // addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    LOOKUP_FUNC(ctx->r23)(rdram, ctx);
    goto after_4;
    // addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    after_4:
    // jalr        $s7
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    LOOKUP_FUNC(ctx->r23)(rdram, ctx);
    goto after_5;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_5:
    // jalr        $s7
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r23)(rdram, ctx);
    goto after_6;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
L_8001EDB0:
    // addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // addiu       $s4, $s4, 0x18
    ctx->r20 = ADD32(ctx->r20, 0X18);
L_8001EDB8:
    // lw          $v1, 0x184($s2)
    ctx->r3 = MEM_W(0X184, ctx->r18);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bne         $v1, $v0, L_8001E7C0
    if (ctx->r3 != ctx->r2) {
        // sw          $v1, 0x184($s2)
        MEM_W(0X184, ctx->r18) = ctx->r3;
        goto L_8001E7C0;
    }
    // sw          $v1, 0x184($s2)
    MEM_W(0X184, ctx->r18) = ctx->r3;
L_8001EDCC:
    // lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(0X20, ctx->r18);
    // nop

    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
L_8001EDD8:
    // lw          $v1, 0x34($s2)
    ctx->r3 = MEM_W(0X34, ctx->r18);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $fp, $v0, L_8001E644
    if (ctx->r30 != ctx->r2) {
        // sw          $v1, 0x34($s2)
        MEM_W(0X34, ctx->r18) = ctx->r3;
        goto L_8001E644;
    }
    // sw          $v1, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r3;
L_8001EDF4:
    // lw          $ra, 0x25C($sp)
    ctx->r31 = MEM_W(0X25C, ctx->r29);
    // lw          $fp, 0x258($sp)
    ctx->r30 = MEM_W(0X258, ctx->r29);
    // lw          $s7, 0x254($sp)
    ctx->r23 = MEM_W(0X254, ctx->r29);
    // lw          $s6, 0x250($sp)
    ctx->r22 = MEM_W(0X250, ctx->r29);
    // lw          $s5, 0x24C($sp)
    ctx->r21 = MEM_W(0X24C, ctx->r29);
    // lw          $s4, 0x248($sp)
    ctx->r20 = MEM_W(0X248, ctx->r29);
    // lw          $s3, 0x244($sp)
    ctx->r19 = MEM_W(0X244, ctx->r29);
    // lw          $s2, 0x240($sp)
    ctx->r18 = MEM_W(0X240, ctx->r29);
    // lw          $s1, 0x23C($sp)
    ctx->r17 = MEM_W(0X23C, ctx->r29);
    // lw          $s0, 0x238($sp)
    ctx->r16 = MEM_W(0X238, ctx->r29);
    // addiu       $sp, $sp, 0x260
    ctx->r29 = ADD32(ctx->r29, 0X260);
    // jr          $ra
    // nop

    return;
    // nop

;}
