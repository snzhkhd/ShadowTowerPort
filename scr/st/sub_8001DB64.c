#include "recomp.h"
#include "disable_warnings.h"

void sub_8001DB64(uint8_t* rdram, recomp_context* ctx) 
{
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x388
    ctx->r29 = ADD32(ctx->r29, -0X388);
    // sw          $fp, 0x380($sp)
    MEM_W(0X380, ctx->r29) = ctx->r30;
    // addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lhu         $v0, -0x61EC($v0)
    ctx->r2 = MEM_HU(-0X61EC, ctx->r2);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // sw          $ra, 0x384($sp)
    MEM_W(0X384, ctx->r29) = ctx->r31;
    // sw          $s7, 0x37C($sp)
    MEM_W(0X37C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x378($sp)
    MEM_W(0X378, ctx->r29) = ctx->r22;
    // sw          $s5, 0x374($sp)
    MEM_W(0X374, ctx->r29) = ctx->r21;
    // sw          $s4, 0x370($sp)
    MEM_W(0X370, ctx->r29) = ctx->r20;
    // sw          $s3, 0x36C($sp)
    MEM_W(0X36C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x368($sp)
    MEM_W(0X368, ctx->r29) = ctx->r18;
    // sw          $s1, 0x364($sp)
    MEM_W(0X364, ctx->r29) = ctx->r17;
    // sw          $s0, 0x360($sp)
    MEM_W(0X360, ctx->r29) = ctx->r16;
    // sw          $a0, 0x388($sp)
    MEM_W(0X388, ctx->r29) = ctx->r4;
    // sw          $v0, 0x348($sp)
    MEM_W(0X348, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x6DFC($v0)
    ctx->r3 = MEM_BU(0X6DFC, ctx->r2);
    // nop

    // andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // beq         $v0, $zero, L_8001DBD8
    if (ctx->r2 == 0) {
        // lui         $s0, 0x1F80
        ctx->r16 = S32(0X1F80 << 16);
        goto L_8001DBD8;
    }
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // j           L_8001DBE8
    // addiu       $fp, $v0, -0x2520
    ctx->r30 = ADD32(ctx->r2, -0X2520);
    goto L_8001DBE8;
    // addiu       $fp, $v0, -0x2520
    ctx->r30 = ADD32(ctx->r2, -0X2520);
L_8001DBD8:
    // andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // beq         $v0, $zero, L_8001DBE8
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8002
        ctx->r2 = S32(0X8002 << 16);
        goto L_8001DBE8;
    }
    // lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // addiu       $fp, $v0, -0x24E0
    ctx->r30 = ADD32(ctx->r2, -0X24E0);
L_8001DBE8:
    // lw          $a3, 0x348($sp)
    ctx->r7 = MEM_W(0X348, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // beq         $a3, $v0, L_8001E4E8
    if (ctx->r7 == ctx->r2) {
        // sw          $a3, 0x348($sp)
        MEM_W(0X348, ctx->r29) = ctx->r7;
        goto L_8001E4E8;
    }
    // sw          $a3, 0x348($sp)
    MEM_W(0X348, ctx->r29) = ctx->r7;
    // addiu       $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // addiu       $t1, $sp, 0x4C
    ctx->r9 = ADD32(ctx->r29, 0X4C);
    // addiu       $a3, $sp, 0x64
    ctx->r7 = ADD32(ctx->r29, 0X64);
    // sw          $t0, 0x350($sp)
    MEM_W(0X350, ctx->r29) = ctx->r8;
    // addiu       $t0, $sp, 0x7C
    ctx->r8 = ADD32(ctx->r29, 0X7C);
    // sw          $t1, 0x354($sp)
    MEM_W(0X354, ctx->r29) = ctx->r9;
    // sw          $a3, 0x358($sp)
    MEM_W(0X358, ctx->r29) = ctx->r7;
    // sw          $t0, 0x35C($sp)
    MEM_W(0X35C, ctx->r29) = ctx->r8;
L_8001DC1C:
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // lw          $t1, 0x348($sp)
    ctx->r9 = MEM_W(0X348, ctx->r29);
    // addiu       $v1, $v1, 0x5948
    ctx->r3 = ADD32(ctx->r3, 0X5948);
    // sll         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9) << 1;
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
    // bne         $v0, $zero, L_8001DC94
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001DC94;
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
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r3;
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // j           L_8001E4C4
    // nop

    goto L_8001E4C4;
    // nop

L_8001DC94:
    // lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(0X3, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v0, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r2;
    // lw          $v0, 0x3C4($s0)
    ctx->r2 = MEM_W(0X3C4, ctx->r16);
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
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r3;
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(0XC, ctx->r16);
    // lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(0X20, ctx->r16);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(0X8, ctx->r4);
    // lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(0XC, ctx->r16);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(0X10, ctx->r4);
    // lhu         $a3, 0x1C($a0)
    ctx->r7 = MEM_HU(0X1C, ctx->r4);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // sw          $a3, 0x34C($sp)
    MEM_W(0X34C, ctx->r29) = ctx->r7;
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // lhu         $a0, 0x18($a0)
    ctx->r4 = MEM_HU(0X18, ctx->r4);
    // addu        $s5, $v1, $v0
    ctx->r21 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // lw          $v1, 0x1B4($s0)
    ctx->r3 = MEM_W(0X1B4, ctx->r16);
    // addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // sw          $a3, 0x34C($sp)
    MEM_W(0X34C, ctx->r29) = ctx->r7;
    // beq         $v0, $zero, L_8001E4B8
    if (ctx->r2 == 0) {
        // sw          $v1, 0x1B4($s0)
        MEM_W(0X1B4, ctx->r16) = ctx->r3;
        goto L_8001E4B8;
    }
    // sw          $v1, 0x1B4($s0)
    MEM_W(0X1B4, ctx->r16) = ctx->r3;
    // addiu       $s2, $s5, 0xC
    ctx->r18 = ADD32(ctx->r21, 0XC);
L_8001DD7C:
    // lhu         $v1, 0x6($s2)
    ctx->r3 = MEM_HU(0X6, ctx->r18);
    // lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(0X34, ctx->r16);
    // lhu         $a0, 0xA($s2)
    ctx->r4 = MEM_HU(0XA, ctx->r18);
    // addu        $s4, $v0, $v1
    ctx->r20 = ADD32(ctx->r2, ctx->r3);
    // addu        $s6, $v0, $a0
    ctx->r22 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v1, 0x8($s2)
    ctx->r3 = MEM_HU(0X8, ctx->r18);
    // lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(0X0, ctx->r20);
    // lw          $a3, 0x0($s6)
    ctx->r7 = MEM_W(0X0, ctx->r22);
    // addu        $s3, $v0, $v1
    ctx->r19 = ADD32(ctx->r2, ctx->r3);
    // lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(0X0, ctx->r19);
    // mtc2        $t0, $12
    gte_mtc2(ctx, 8, 12);
    // mtc2        $a3, $14
    gte_mtc2(ctx, 7, 14);
    // mtc2        $t1, $13
    gte_mtc2(ctx, 9, 13);
    // nop

    // nop

    // .word       0x4B400006                   # INVALID     $k0, $zero, 0x6 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B400006);
    // lbu         $v0, -0x1($s2)
    ctx->r2 = MEM_BU(-0X1, ctx->r18);
    // nop

    // ori         $v0, $v0, 0x3C
    ctx->r2 = ctx->r2 | 0X3C;
    // sb          $v0, 0x47($s0)
    MEM_B(0X47, ctx->r16) = ctx->r2;
    // addiu       $v0, $s0, 0x70
    ctx->r2 = ADD32(ctx->r16, 0X70);
    // swc2        $24, 0x0($v0)
    gte_swc2(rdram, ctx, 24, 2, 0);
    // lhu         $v1, 0xC($s2)
    ctx->r3 = MEM_HU(0XC, ctx->r18);
    // lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(0X34, ctx->r16);
    // lw          $t0, 0x10($s0)
    ctx->r8 = MEM_W(0X10, ctx->r16);
    // addu        $s7, $v0, $v1
    ctx->r23 = ADD32(ctx->r2, ctx->r3);
    // swc2        $12, 0x8($t0)
    gte_swc2(rdram, ctx, 12, 8, 8);
    // swc2        $13, 0x14($t0)
    gte_swc2(rdram, ctx, 13, 8, 20);
    // swc2        $14, 0x20($t0)
    gte_swc2(rdram, ctx, 14, 8, 32);
    // lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(0X0, ctx->r23);
    // nop

    // mtc2        $t1, $12
    gte_mtc2(ctx, 9, 12);
    // nop

    // nop

    // .word       0x4B400006                   # INVALID     $k0, $zero, 0x6 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B400006);
    // addiu       $v0, $s0, 0x74
    ctx->r2 = ADD32(ctx->r16, 0X74);
    // swc2        $24, 0x0($v0)
    gte_swc2(rdram, ctx, 24, 2, 0);
    // lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(0X70, ctx->r16);
    // nop

    // bgtz        $v0, L_8001DE30
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8001DE30;
    }
    // nop

    // lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(0X74, ctx->r16);
    // nop

    // bgez        $v0, L_8001E498
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8001E498;
    }
    // nop

L_8001DE30:
    // lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(0X10, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
    // swc2        $12, 0x0($v0)
    gte_swc2(rdram, ctx, 12, 2, 0);
    // lh          $v0, 0x4($s4)
    ctx->r2 = MEM_HS(0X4, ctx->r20);
    // nop

    // sw          $v0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r2;
    // sw          $v0, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r2;
    // lh          $v1, 0x4($s3)
    ctx->r3 = MEM_HS(0X4, ctx->r19);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8001DE6C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001DE6C;
    }
    // nop

    // sw          $v1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r3;
    // lh          $v1, 0x4($s3)
    ctx->r3 = MEM_HS(0X4, ctx->r19);
L_8001DE6C:
    // lw          $v0, 0x80($s0)
    ctx->r2 = MEM_W(0X80, ctx->r16);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8001DE84
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001DE84;
    }
    // nop

    // sw          $v1, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r3;
L_8001DE84:
    // lh          $v1, 0x4($s6)
    ctx->r3 = MEM_HS(0X4, ctx->r22);
    // lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(0X84, ctx->r16);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8001DEA4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001DEA4;
    }
    // nop

    // sw          $v1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r3;
    // lh          $v1, 0x4($s6)
    ctx->r3 = MEM_HS(0X4, ctx->r22);
L_8001DEA4:
    // lw          $v0, 0x80($s0)
    ctx->r2 = MEM_W(0X80, ctx->r16);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8001DEBC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001DEBC;
    }
    // nop

    // sw          $v1, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r3;
L_8001DEBC:
    // lh          $v1, 0x4($s7)
    ctx->r3 = MEM_HS(0X4, ctx->r23);
    // lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(0X84, ctx->r16);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8001DEDC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001DEDC;
    }
    // nop

    // sw          $v1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r3;
    // lh          $v1, 0x4($s7)
    ctx->r3 = MEM_HS(0X4, ctx->r23);
L_8001DEDC:
    // lw          $v0, 0x80($s0)
    ctx->r2 = MEM_W(0X80, ctx->r16);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8001DEF4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001DEF4;
    }
    // nop

    // sw          $v1, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r3;
L_8001DEF4:
    // lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(0X84, ctx->r16);
    // lb          $v1, -0x2($s2)
    ctx->r3 = MEM_BS(-0X2, ctx->r18);
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // slti        $v0, $v1, 0x1000
    ctx->r2 = SIGNED(ctx->r3) < 0X1000 ? 1 : 0;
    // beq         $v0, $zero, L_8001E498
    if (ctx->r2 == 0) {
        // sw          $v1, 0x88($s0)
        MEM_W(0X88, ctx->r16) = ctx->r3;
        goto L_8001E498;
    }
    // sw          $v1, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r3;
    // lw          $v0, 0x8C($s0)
    ctx->r2 = MEM_W(0X8C, ctx->r16);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8001E498
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001E498;
    }
    // nop

    // lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(0X70, ctx->r16);
    // nop

    // slti        $v0, $v0, 0x4001
    ctx->r2 = SIGNED(ctx->r2) < 0X4001 ? 1 : 0;
    // beq         $v0, $zero, L_8001DF4C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8001DF4C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(0X74, ctx->r16);
    // nop

    // slti        $v0, $v0, -0x4000
    ctx->r2 = SIGNED(ctx->r2) < -0X4000 ? 1 : 0;
    // beq         $v0, $zero, L_8001E304
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8001E304;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001DF4C:
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v1, 0x70($s0)
    ctx->r3 = MEM_W(0X70, ctx->r16);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8001DF78
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8001DF78;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(0X74, ctx->r16);
    // nop

    // slti        $v0, $v0, -0x8000
    ctx->r2 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // beq         $v0, $zero, L_8001DF7C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8001DF7C;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8001DF78:
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_8001DF7C:
    // addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lhu         $v0, -0xA($s2)
    ctx->r2 = MEM_HU(-0XA, ctx->r18);
    // nop

    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, -0x6($s2)
    ctx->r2 = MEM_HU(-0X6, ctx->r18);
    // nop

    // sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(0X4, ctx->r18);
    // lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(0X24, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // addiu       $v0, $s0, 0x44
    ctx->r2 = ADD32(ctx->r16, 0X44);
    // lwc2        $6, 0x0($v0)
    gte_lwc2(rdram, ctx, 6, 2, 0);
    // nop

    // nop

    // .word       0x4B08041B                   # INVALID     $t8, $t0, 0x41B # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B08041B);
    // addiu       $v0, $s0, 0x2C
    ctx->r2 = ADD32(ctx->r16, 0X2C);
    // swc2        $22, 0x0($v0)
    gte_swc2(rdram, ctx, 22, 2, 0);
    // lwc2        $6, 0x0($v0)
    gte_lwc2(rdram, ctx, 6, 2, 0);
    // lhu         $a3, 0x6($s4)
    ctx->r7 = MEM_HU(0X6, ctx->r20);
    // nop

    // mtc2        $a3, $8
    gte_mtc2(ctx, 7, 8);
    // nop

    // nop

    // .word       0x4A780010                   # INVALID     $s3, $t8, 0x10 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A780010);
    // lw          $t0, 0x350($sp)
    ctx->r8 = MEM_W(0X350, ctx->r29);
    // nop

    // swc2        $22, 0x0($t0)
    gte_swc2(rdram, ctx, 22, 8, 0);
    // lhu         $t1, 0x6($s3)
    ctx->r9 = MEM_HU(0X6, ctx->r19);
    // nop

    // mtc2        $t1, $8
    gte_mtc2(ctx, 9, 8);
    // nop

    // nop

    // .word       0x4A780010                   # INVALID     $s3, $t8, 0x10 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A780010);
    // lw          $a3, 0x354($sp)
    ctx->r7 = MEM_W(0X354, ctx->r29);
    // nop

    // swc2        $22, 0x0($a3)
    gte_swc2(rdram, ctx, 22, 7, 0);
    // lhu         $t0, 0x6($s6)
    ctx->r8 = MEM_HU(0X6, ctx->r22);
    // nop

    // mtc2        $t0, $8
    gte_mtc2(ctx, 8, 8);
    // nop

    // nop

    // .word       0x4A780010                   # INVALID     $s3, $t8, 0x10 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A780010);
    // lw          $t1, 0x358($sp)
    ctx->r9 = MEM_W(0X358, ctx->r29);
    // nop

    // swc2        $22, 0x0($t1)
    gte_swc2(rdram, ctx, 22, 9, 0);
    // lhu         $a3, 0x6($s7)
    ctx->r7 = MEM_HU(0X6, ctx->r23);
    // nop

    // mtc2        $a3, $8
    gte_mtc2(ctx, 7, 8);
    // nop

    // nop

    // .word       0x4A780010                   # INVALID     $s3, $t8, 0x10 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A780010);
    // lw          $t0, 0x35C($sp)
    ctx->r8 = MEM_W(0X35C, ctx->r29);
    // nop

    // swc2        $22, 0x0($t0)
    gte_swc2(rdram, ctx, 22, 8, 0);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // addiu       $t1, $t1, -0x2F70
    ctx->r9 = ADD32(ctx->r9, -0X2F70);
    // addu        $s1, $t1, $v0
    ctx->r17 = ADD32(ctx->r9, ctx->r2);
    // lbu         $v0, 0x6DFC($s1)
    ctx->r2 = MEM_BU(0X6DFC, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // beq         $v0, $zero, L_8001E0C4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001E0C4;
    }
    // nop

    // lw          $a0, 0x350($sp)
    ctx->r4 = MEM_W(0X350, ctx->r29);
    // jalr        $fp
    // nop

    LOOKUP_FUNC(ctx->r30)(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $a0, 0x354($sp)
    ctx->r4 = MEM_W(0X354, ctx->r29);
    // jalr        $fp
    // nop

    LOOKUP_FUNC(ctx->r30)(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $a0, 0x358($sp)
    ctx->r4 = MEM_W(0X358, ctx->r29);
    // jalr        $fp
    // nop

    LOOKUP_FUNC(ctx->r30)(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $a0, 0x35C($sp)
    ctx->r4 = MEM_W(0X35C, ctx->r29);
    // jalr        $fp
    // nop

    LOOKUP_FUNC(ctx->r30)(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_8001E0C4:
    // lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(0X1E4, ctx->r16);
    // addiu       $v1, $s1, 0x6D28
    ctx->r3 = ADD32(ctx->r17, 0X6D28);
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
    // lw          $a3, 0x348($sp)
    ctx->r7 = MEM_W(0X348, ctx->r29);
    // lw          $t0, 0x388($sp)
    ctx->r8 = MEM_W(0X388, ctx->r29);
    // sll         $v0, $a3, 4
    ctx->r2 = S32(ctx->r7) << 4;
    // addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
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
    // lwl         $v0, 0x47($s0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X47, ctx->r16);
    // lwr         $v0, 0x44($s0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X44, ctx->r16);
    // nop

    // swl         $v0, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r2);
    // swr         $v0, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r2);
    // addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // sw          $v0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $v0, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // sw          $v0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x70
    ctx->r2 = ADD32(ctx->r29, 0X70);
    // sw          $v0, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r2;
    // lw          $v0, 0x88($s0)
    ctx->r2 = MEM_W(0X88, ctx->r16);
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // lwl         $v0, 0x3($s4)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r20);
    // lwr         $v0, 0x0($s4)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r20);
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
    // lwl         $v0, 0x3($s7)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r23);
    // lwr         $v0, 0x0($s7)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r23);
    // nop

    // swl         $v0, 0x83($sp)
    do_swl(rdram, 0X83, ctx->r29, ctx->r2);
    // swr         $v0, 0x80($sp)
    do_swr(rdram, 0X80, ctx->r29, ctx->r2);
    // lh          $v0, 0x4($s4)
    ctx->r2 = MEM_HS(0X4, ctx->r20);
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
    // lh          $v0, 0x4($s7)
    ctx->r2 = MEM_HS(0X4, ctx->r23);
    // nop

    // sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // lhu         $v1, 0x6($s2)
    ctx->r3 = MEM_HU(0X6, ctx->r18);
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
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
    // lhu         $v1, 0x8($s2)
    ctx->r3 = MEM_HU(0X8, ctx->r18);
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
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
    // lhu         $v1, 0xA($s2)
    ctx->r3 = MEM_HU(0XA, ctx->r18);
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
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
    // lhu         $v1, 0xC($s2)
    ctx->r3 = MEM_HU(0XC, ctx->r18);
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
    // lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(0X10, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a1, 0x7($v0)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X7, ctx->r2);
    // lwr         $a1, 0x4($v0)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X4, ctx->r2);
    // swl         $v1, 0x73($sp)
    do_swl(rdram, 0X73, ctx->r29, ctx->r3);
    // swr         $v1, 0x70($sp)
    do_swr(rdram, 0X70, ctx->r29, ctx->r3);
    // swl         $a1, 0x77($sp)
    do_swl(rdram, 0X77, ctx->r29, ctx->r5);
    // swr         $a1, 0x74($sp)
    do_swr(rdram, 0X74, ctx->r29, ctx->r5);
    // lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(0X0, ctx->r21);
    // nop

    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lw          $v0, -0x8($s2)
    ctx->r2 = MEM_W(-0X8, ctx->r18);
    // addiu       $s5, $s5, 0x1C
    ctx->r21 = ADD32(ctx->r21, 0X1C);
    // sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // lw          $v0, -0x4($s2)
    ctx->r2 = MEM_W(-0X4, ctx->r18);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // jal         0x80076884
    // sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    RCpolyGT4(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    after_4:
    // sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(0X10, ctx->r29);
    // lw          $v1, 0x1C0($s0)
    ctx->r3 = MEM_W(0X1C0, ctx->r16);
    // sllv        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2) << (ctx->r4 & 31);
    // sllv        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2) << (ctx->r4 & 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // j           L_8001E4A0
    // sw          $v1, 0x1C0($s0)
    MEM_W(0X1C0, ctx->r16) = ctx->r3;
    goto L_8001E4A0;
    // sw          $v1, 0x1C0($s0)
    MEM_W(0X1C0, ctx->r16) = ctx->r3;
L_8001E304:
    // lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(0X10, ctx->r16);
    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // addiu       $v1, $a1, 0x34
    ctx->r3 = ADD32(ctx->r5, 0X34);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8001E4E8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001E4E8;
    }
    // nop

    // lw          $v0, 0x1BC($s0)
    ctx->r2 = MEM_W(0X1BC, ctx->r16);
    // sw          $v1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r3;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x1BC($s0)
    MEM_W(0X1BC, ctx->r16) = ctx->r2;
    // lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(0X4, ctx->r18);
    // lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(0X24, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // addiu       $v0, $s0, 0x44
    ctx->r2 = ADD32(ctx->r16, 0X44);
    // lwc2        $6, 0x0($v0)
    gte_lwc2(rdram, ctx, 6, 2, 0);
    // nop

    // nop

    // .word       0x4B08041B                   # INVALID     $t8, $t0, 0x41B # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B08041B);
    // lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(0X0, ctx->r21);
    // nop

    // sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // lw          $v0, -0x8($s2)
    ctx->r2 = MEM_W(-0X8, ctx->r18);
    // nop

    // sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    // addiu       $v0, $s0, 0x2C
    ctx->r2 = ADD32(ctx->r16, 0X2C);
    // swc2        $22, 0x0($v0)
    gte_swc2(rdram, ctx, 22, 2, 0);
    // lwc2        $6, 0x0($v0)
    gte_lwc2(rdram, ctx, 6, 2, 0);
    // lhu         $s4, 0x6($s4)
    ctx->r20 = MEM_HU(0X6, ctx->r20);
    // nop

    // mtc2        $s4, $8
    gte_mtc2(ctx, 20, 8);
    // nop

    // nop

    // .word       0x4A780010                   # INVALID     $s3, $t8, 0x10 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A780010);
    // lhu         $v0, -0x4($s2)
    ctx->r2 = MEM_HU(-0X4, ctx->r18);
    // addiu       $a2, $a1, 0x4
    ctx->r6 = ADD32(ctx->r5, 0X4);
    // sh          $v0, 0x24($a1)
    MEM_H(0X24, ctx->r5) = ctx->r2;
    // swc2        $22, 0x0($a2)
    gte_swc2(rdram, ctx, 22, 6, 0);
    // lhu         $s3, 0x6($s3)
    ctx->r19 = MEM_HU(0X6, ctx->r19);
    // nop

    // mtc2        $s3, $8
    gte_mtc2(ctx, 19, 8);
    // nop

    // nop

    // .word       0x4A780010                   # INVALID     $s3, $t8, 0x10 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A780010);
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // addiu       $s4, $a1, 0x10
    ctx->r20 = ADD32(ctx->r5, 0X10);
    // sh          $v0, 0x30($a1)
    MEM_H(0X30, ctx->r5) = ctx->r2;
    // swc2        $22, 0x0($s4)
    gte_swc2(rdram, ctx, 22, 20, 0);
    // lhu         $s6, 0x6($s6)
    ctx->r22 = MEM_HU(0X6, ctx->r22);
    // nop

    // mtc2        $s6, $8
    gte_mtc2(ctx, 22, 8);
    // nop

    // nop

    // .word       0x4A780010                   # INVALID     $s3, $t8, 0x10 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A780010);
    // lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // addiu       $s3, $a1, 0x1C
    ctx->r19 = ADD32(ctx->r5, 0X1C);
    // lw          $v0, 0x88($s0)
    ctx->r2 = MEM_W(0X88, ctx->r16);
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0xC00
    ctx->r3 = S32(0XC00 << 16);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // swc2        $22, 0x0($s3)
    gte_swc2(rdram, ctx, 22, 19, 0);
    // lhu         $s7, 0x6($s7)
    ctx->r23 = MEM_HU(0X6, ctx->r23);
    // nop

    // mtc2        $s7, $8
    gte_mtc2(ctx, 23, 8);
    // nop

    // nop

    // .word       0x4A780010                   # INVALID     $s3, $t8, 0x10 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A780010);
    // and         $a0, $a1, $a0
    ctx->r4 = ctx->r5 & ctx->r4;
    // addiu       $s1, $a1, 0x28
    ctx->r17 = ADD32(ctx->r5, 0X28);
    // lw          $v0, 0x88($s0)
    ctx->r2 = MEM_W(0X88, ctx->r16);
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // swc2        $22, 0x0($s1)
    gte_swc2(rdram, ctx, 22, 17, 0);
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
    // beq         $v0, $zero, L_8001E498
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001E498;
    }
    // nop

    // jalr        $fp
    // addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    LOOKUP_FUNC(ctx->r30)(rdram, ctx);
    goto after_5;
    // addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    after_5:
    // jalr        $fp
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    LOOKUP_FUNC(ctx->r30)(rdram, ctx);
    goto after_6;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_6:
    // jalr        $fp
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    LOOKUP_FUNC(ctx->r30)(rdram, ctx);
    goto after_7;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_7:
    // jalr        $fp
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r30)(rdram, ctx);
    goto after_8;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_8:
L_8001E498:
    // addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
    // addiu       $s5, $s5, 0x1C
    ctx->r21 = ADD32(ctx->r21, 0X1C);
L_8001E4A0:
    // lw          $v0, 0x34C($sp)
    ctx->r2 = MEM_W(0X34C, ctx->r29);
    // nop

    // addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // bne         $v0, $zero, L_8001DD7C
    if (ctx->r2 != 0) {
        // sw          $t0, 0x34C($sp)
        MEM_W(0X34C, ctx->r29) = ctx->r8;
        goto L_8001DD7C;
    }
    // sw          $t0, 0x34C($sp)
    MEM_W(0X34C, ctx->r29) = ctx->r8;
L_8001E4B8:
    // lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(0X20, ctx->r16);
    // nop

    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
L_8001E4C4:
    // lw          $v1, 0x34($s0)
    ctx->r3 = MEM_W(0X34, ctx->r16);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
    // lw          $t1, 0x348($sp)
    ctx->r9 = MEM_W(0X348, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // bne         $t1, $v0, L_8001DC1C
    if (ctx->r9 != ctx->r2) {
        // sw          $t1, 0x348($sp)
        MEM_W(0X348, ctx->r29) = ctx->r9;
        goto L_8001DC1C;
    }
    // sw          $t1, 0x348($sp)
    MEM_W(0X348, ctx->r29) = ctx->r9;
L_8001E4E8:
    // lw          $ra, 0x384($sp)
    ctx->r31 = MEM_W(0X384, ctx->r29);
    // lw          $fp, 0x380($sp)
    ctx->r30 = MEM_W(0X380, ctx->r29);
    // lw          $s7, 0x37C($sp)
    ctx->r23 = MEM_W(0X37C, ctx->r29);
    // lw          $s6, 0x378($sp)
    ctx->r22 = MEM_W(0X378, ctx->r29);
    // lw          $s5, 0x374($sp)
    ctx->r21 = MEM_W(0X374, ctx->r29);
    // lw          $s4, 0x370($sp)
    ctx->r20 = MEM_W(0X370, ctx->r29);
    // lw          $s3, 0x36C($sp)
    ctx->r19 = MEM_W(0X36C, ctx->r29);
    // lw          $s2, 0x368($sp)
    ctx->r18 = MEM_W(0X368, ctx->r29);
    // lw          $s1, 0x364($sp)
    ctx->r17 = MEM_W(0X364, ctx->r29);
    // lw          $s0, 0x360($sp)
    ctx->r16 = MEM_W(0X360, ctx->r29);
    // addiu       $sp, $sp, 0x388
    ctx->r29 = ADD32(ctx->r29, 0X388);
    // jr          $ra
    // nop

    return;
    // nop

;}
