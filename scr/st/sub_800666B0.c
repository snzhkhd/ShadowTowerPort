#include "recomp.h"
#include "disable_warnings.h"

void sub_800666B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // sw          $ra, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r31;
    // sw          $s7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r23;
    // sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // sh          $zero, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = 0;
    // addiu       $a2, $v0, 0x38A0
    ctx->r6 = ADD32(ctx->r2, 0X38A0);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // lwl         $a1, 0xB($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XB, ctx->r6);
    // lwr         $a1, 0x8($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X8, ctx->r6);
    // swl         $v1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r3);
    // swr         $v1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r3);
    // swl         $a0, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r4);
    // swr         $a0, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r4);
    // swl         $a1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r5);
    // swr         $a1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r5);
    // lwl         $v1, 0xF($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0XF, ctx->r6);
    // lwr         $v1, 0xC($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0XC, ctx->r6);
    // lwl         $a0, 0x13($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X13, ctx->r6);
    // lwr         $a0, 0x10($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X10, ctx->r6);
    // lwl         $a1, 0x17($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X17, ctx->r6);
    // lwr         $a1, 0x14($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X14, ctx->r6);
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a0, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r4);
    // swr         $a0, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r4);
    // swl         $a1, 0x37($sp)
    do_swl(rdram, 0X37, ctx->r29, ctx->r5);
    // swr         $a1, 0x34($sp)
    do_swr(rdram, 0X34, ctx->r29, ctx->r5);
    // lb          $v1, 0x18($a2)
    ctx->r3 = MEM_BS(0X18, ctx->r6);
    // lb          $a0, 0x19($a2)
    ctx->r4 = MEM_BS(0X19, ctx->r6);
    // sb          $v1, 0x38($sp)
    MEM_B(0X38, ctx->r29) = ctx->r3;
    // sb          $a0, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r4;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x38BC
    ctx->r6 = ADD32(ctx->r2, 0X38BC);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // lwl         $a1, 0xB($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XB, ctx->r6);
    // lwr         $a1, 0x8($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X8, ctx->r6);
    // swl         $v1, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r3);
    // swr         $v1, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r3);
    // swl         $a0, 0x47($sp)
    do_swl(rdram, 0X47, ctx->r29, ctx->r4);
    // swr         $a0, 0x44($sp)
    do_swr(rdram, 0X44, ctx->r29, ctx->r4);
    // swl         $a1, 0x4B($sp)
    do_swl(rdram, 0X4B, ctx->r29, ctx->r5);
    // swr         $a1, 0x48($sp)
    do_swr(rdram, 0X48, ctx->r29, ctx->r5);
    // lwl         $v1, 0xF($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0XF, ctx->r6);
    // lwr         $v1, 0xC($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0XC, ctx->r6);
    // lwl         $a0, 0x13($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X13, ctx->r6);
    // lwr         $a0, 0x10($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X10, ctx->r6);
    // lwl         $a1, 0x17($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X17, ctx->r6);
    // lwr         $a1, 0x14($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X14, ctx->r6);
    // swl         $v1, 0x4F($sp)
    do_swl(rdram, 0X4F, ctx->r29, ctx->r3);
    // swr         $v1, 0x4C($sp)
    do_swr(rdram, 0X4C, ctx->r29, ctx->r3);
    // swl         $a0, 0x53($sp)
    do_swl(rdram, 0X53, ctx->r29, ctx->r4);
    // swr         $a0, 0x50($sp)
    do_swr(rdram, 0X50, ctx->r29, ctx->r4);
    // swl         $a1, 0x57($sp)
    do_swl(rdram, 0X57, ctx->r29, ctx->r5);
    // swr         $a1, 0x54($sp)
    do_swr(rdram, 0X54, ctx->r29, ctx->r5);
    // lb          $v1, 0x18($a2)
    ctx->r3 = MEM_BS(0X18, ctx->r6);
    // lb          $a0, 0x19($a2)
    ctx->r4 = MEM_BS(0X19, ctx->r6);
    // sb          $v1, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r3;
    // sb          $a0, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r4;
    // jal         0x80057A3C
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    sub_80057A3C(rdram, ctx);
    goto after_0;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    after_0:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s4, $v0, -0x2E80
    ctx->r20 = ADD32(ctx->r2, -0X2E80);
    // addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // lui         $s5, 0x801E
    ctx->r21 = S32(0X801E << 16);
    // addiu       $s2, $s5, 0xD38
    ctx->r18 = ADD32(ctx->r21, 0XD38);
    // addiu       $s6, $zero, 0x68
    ctx->r22 = ADD32(0, 0X68);
    // addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800667F8:
    // lhu         $v0, 0x4($s4)
    ctx->r2 = MEM_HU(0X4, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // beq         $v0, $zero, L_8006683C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006683C;
    }
    // nop

    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lhu         $v1, 0x2DC($s0)
    ctx->r3 = MEM_HU(0X2DC, ctx->r16);
    // nop

    // andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // beq         $v0, $zero, L_80066830
    if (ctx->r2 == 0) {
        // sh          $zero, 0x4($s4)
        MEM_H(0X4, ctx->r20) = 0;
        goto L_80066830;
    }
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    // j           L_80066838
    // andi        $v0, $v1, 0x7FFF
    ctx->r2 = ctx->r3 & 0X7FFF;
    goto L_80066838;
    // andi        $v0, $v1, 0x7FFF
    ctx->r2 = ctx->r3 & 0X7FFF;
L_80066830:
    // bne         $v1, $s7, L_800674A8
    if (ctx->r3 != ctx->r23) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_800674A8;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80066838:
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
L_8006683C:
    // lhu         $v0, 0x4($s4)
    ctx->r2 = MEM_HU(0X4, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // beq         $v0, $zero, L_80066C34
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80066C34;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // beq         $v0, $zero, L_80066AE0
    if (ctx->r2 == 0) {
        // sh          $zero, 0x4($s4)
        MEM_H(0X4, ctx->r20) = 0;
        goto L_80066AE0;
    }
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    // lbu         $v0, 0xD38($s5)
    ctx->r2 = MEM_BU(0XD38, ctx->r21);
    // nop

    // bne         $v0, $s6, L_800669A0
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_800669A0;
    }
    // nop

    // lbu         $v0, 0x4($s2)
    ctx->r2 = MEM_BU(0X4, ctx->r18);
    // nop

    // bne         $v0, $zero, L_800668A8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800668A8;
    }
    // nop

    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // lh          $v1, 0x0($s0)
    ctx->r3 = MEM_HS(0X0, ctx->r16);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r3;
    // sw          $v1, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r3;
L_800668A8:
    // lw          $a3, 0x8($s2)
    ctx->r7 = MEM_W(0X8, ctx->r18);
    // lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(0XC, ctx->r18);
    // nop

    // slt         $v0, $v0, $a3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_80066AC4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80066AC4;
    }
    // nop

    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $t1, $v0, 0xD38
    ctx->r9 = ADD32(ctx->r2, 0XD38);
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
L_800668CC:
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
    // nop

    // beq         $v0, $s3, L_80066984
    if (ctx->r2 == ctx->r19) {
        // addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
        goto L_80066984;
    }
    // addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // lhu         $a0, 0xE($s0)
    ctx->r4 = MEM_HU(0XE, ctx->r16);
    // nop

    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
    // blez        $a2, L_80066934
    if (SIGNED(ctx->r6) <= 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_80066934;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_8006690C:
    // lh          $v0, 0x0($a2)
    ctx->r2 = MEM_HS(0X0, ctx->r6);
    // nop

    // bne         $v0, $s3, L_80066924
    if (ctx->r2 != ctx->r19) {
        // nop
    
        goto L_80066924;
    }
    // nop

    // j           L_80066934
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    goto L_80066934;
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_80066924:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a1, $t0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // bne         $v0, $zero, L_8006690C
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_8006690C;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_80066934:
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 15
    ctx->r4 = S32(ctx->r4) >> 15;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 15
    ctx->r3 = S32(ctx->r3) >> 15;
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(0X8, ctx->r16);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $s3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r19;
    // lhu         $v0, 0xE($s0)
    ctx->r2 = MEM_HU(0XE, ctx->r16);
    // lhu         $v1, 0xC($s0)
    ctx->r3 = MEM_HU(0XC, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // sh          $v1, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r3;
L_80066984:
    // lw          $v0, 0xC($t1)
    ctx->r2 = MEM_W(0XC, ctx->r9);
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // slt         $v0, $v0, $a3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_80066AC4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80066AC4;
    }
    // nop

    // j           L_800668CC
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
    goto L_800668CC;
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
L_800669A0:
    // lbu         $v0, 0x4($s2)
    ctx->r2 = MEM_BU(0X4, ctx->r18);
    // nop

    // bne         $v0, $zero, L_800669D4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800669D4;
    }
    // nop

    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // lhu         $v1, 0x2E0($s0)
    ctx->r3 = MEM_HU(0X2E0, ctx->r16);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r2;
    // sw          $v0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r2;
L_800669D4:
    // lw          $a3, 0x8($s2)
    ctx->r7 = MEM_W(0X8, ctx->r18);
    // lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(0XC, ctx->r18);
    // nop

    // slt         $v0, $v0, $a3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_80066AC4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80066AC4;
    }
    // nop

    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $t1, $v0, 0xD38
    ctx->r9 = ADD32(ctx->r2, 0XD38);
L_800669F4:
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
    // lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(0X8, ctx->r16);
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
    // nop

    // beq         $v0, $s3, L_80066AB0
    if (ctx->r2 == ctx->r19) {
        // addu        $v1, $a3, $zero
        ctx->r3 = ADD32(ctx->r7, 0);
        goto L_80066AB0;
    }
    // addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(0XC, ctx->r16);
    // nop

    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
    // blez        $a2, L_80066A60
    if (SIGNED(ctx->r6) <= 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_80066A60;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_80066A38:
    // lh          $v0, 0x0($a2)
    ctx->r2 = MEM_HS(0X0, ctx->r6);
    // nop

    // bne         $v0, $s3, L_80066A50
    if (ctx->r2 != ctx->r19) {
        // nop
    
        goto L_80066A50;
    }
    // nop

    // j           L_80066A60
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    goto L_80066A60;
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_80066A50:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a1, $t0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // bne         $v0, $zero, L_80066A38
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_80066A38;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_80066A60:
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 15
    ctx->r4 = S32(ctx->r4) >> 15;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 15
    ctx->r3 = S32(ctx->r3) >> 15;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(0X4, ctx->r16);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $s3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r19;
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // lhu         $v1, 0xE($s0)
    ctx->r3 = MEM_HU(0XE, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // sh          $v1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r3;
L_80066AB0:
    // lw          $v0, 0xC($t1)
    ctx->r2 = MEM_W(0XC, ctx->r9);
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // slt         $v0, $v0, $a3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // beq         $v0, $zero, L_800669F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800669F4;
    }
    // nop

L_80066AC4:
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // sb          $zero, 0x4($s2)
    MEM_B(0X4, ctx->r18) = 0;
    // sw          $s3, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r19;
    // sw          $s3, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r19;
    // sw          $s3, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r19;
    // j           L_80066C30
    // andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    goto L_80066C30;
    // andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
L_80066AE0:
    // lbu         $v0, 0x4($s2)
    ctx->r2 = MEM_BU(0X4, ctx->r18);
    // nop

    // bne         $v0, $zero, L_80066B74
    if (ctx->r2 != 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_80066B74;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lbu         $v0, 0xD38($s5)
    ctx->r2 = MEM_BU(0XD38, ctx->r21);
    // nop

    // bne         $v0, $s6, L_80066B34
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_80066B34;
    }
    // nop

    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // lh          $v1, 0x0($s0)
    ctx->r3 = MEM_HS(0X0, ctx->r16);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
    // nop

    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // j           L_80066C1C
    // sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    goto L_80066C1C;
    // sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
L_80066B34:
    // lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(0X2, ctx->r16);
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(0X8, ctx->r16);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
    // nop

    // bne         $v0, $s3, L_80066C1C
    if (ctx->r2 != ctx->r19) {
        // nop
    
        goto L_80066C1C;
    }
    // nop

    // j           L_80066C1C
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    goto L_80066C1C;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80066B74:
    // lbu         $v0, 0xD38($s5)
    ctx->r2 = MEM_BU(0XD38, ctx->r21);
    // nop

    // bne         $v0, $s6, L_80066BD8
    if (ctx->r2 != ctx->r22) {
        // addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
        goto L_80066BD8;
    }
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // lw          $t0, 0x8($s2)
    ctx->r8 = MEM_W(0X8, ctx->r18);
    // lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(0XC, ctx->r18);
    // nop

    // slt         $v0, $v0, $t0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // bne         $v0, $zero, L_80066C1C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80066C1C;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $a0, 0xD44($v0)
    ctx->r4 = MEM_W(0XD44, ctx->r2);
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8) << 1;
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
L_80066BAC:
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_HS(0X0, ctx->r3);
    // nop

    // bne         $v0, $s3, L_80066BD0
    if (ctx->r2 != ctx->r19) {
        // addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_80066BD0;
    }
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // slt         $v0, $a0, $t0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // beq         $v0, $zero, L_80066BAC
    if (ctx->r2 == 0) {
        // addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
        goto L_80066BAC;
    }
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // j           L_80066C1C
    // nop

    goto L_80066C1C;
    // nop

L_80066BD0:
    // j           L_80066C1C
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    goto L_80066C1C;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80066BD8:
    // lw          $t0, 0x8($s2)
    ctx->r8 = MEM_W(0X8, ctx->r18);
    // lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(0XC, ctx->r18);
    // nop

    // slt         $v0, $v0, $t0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // bne         $v0, $zero, L_80066C1C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80066C1C;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $a0, 0xD44($v0)
    ctx->r4 = MEM_W(0XD44, ctx->r2);
    // lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(0X8, ctx->r16);
    // sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8) << 1;
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
L_80066C00:
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_HS(0X0, ctx->r3);
    // nop

    // bne         $v0, $s3, L_80066BD0
    if (ctx->r2 != ctx->r19) {
        // addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_80066BD0;
    }
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // slt         $v0, $a0, $t0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // beq         $v0, $zero, L_80066C00
    if (ctx->r2 == 0) {
        // addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
        goto L_80066C00;
    }
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_80066C1C:
    // bne         $a1, $zero, L_80066C34
    if (ctx->r5 != 0) {
        // nop
    
        goto L_80066C34;
    }
    // nop

    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // nop

    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
L_80066C30:
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
L_80066C34:
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // bne         $v0, $zero, L_80067470
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80067470;
    }
    // nop

    // lhu         $v0, 0x4($s4)
    ctx->r2 = MEM_HU(0X4, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80066D84
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80066D84;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lbu         $v0, 0xD38($s5)
    ctx->r2 = MEM_BU(0XD38, ctx->r21);
    // nop

    // bne         $v0, $s6, L_80066D00
    if (ctx->r2 != ctx->r22) {
        // sh          $zero, 0x4($s4)
        MEM_H(0X4, ctx->r20) = 0;
        goto L_80066D00;
    }
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addu        $t1, $t0, $zero
    ctx->r9 = ADD32(ctx->r8, 0);
L_80066C7C:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
    // nop

    // bne         $v0, $s3, L_80066CE8
    if (ctx->r2 != ctx->r19) {
        // slti        $v0, $t0, 0x13A
        ctx->r2 = SIGNED(ctx->r8) < 0X13A ? 1 : 0;
        goto L_80066CE8;
    }
    // slti        $v0, $t0, 0x13A
    ctx->r2 = SIGNED(ctx->r8) < 0X13A ? 1 : 0;
    // beq         $v0, $zero, L_80066CE8
    if (ctx->r2 == 0) {
        // addu        $a1, $t0, $zero
        ctx->r5 = ADD32(ctx->r8, 0);
        goto L_80066CE8;
    }
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // addu        $t2, $t1, $zero
    ctx->r10 = ADD32(ctx->r9, 0);
L_80066CA4:
    // lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(0X4, ctx->r16);
    // sll         $a3, $a1, 1
    ctx->r7 = S32(ctx->r5) << 1;
    // addu        $v0, $a3, $a2
    ctx->r2 = ADD32(ctx->r7, ctx->r6);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(0X0, ctx->r2);
    // beq         $v1, $s3, L_80066CD8
    if (ctx->r3 == ctx->r19) {
        // addu        $v0, $t2, $a2
        ctx->r2 = ADD32(ctx->r10, ctx->r6);
        goto L_80066CD8;
    }
    // addu        $v0, $t2, $a2
    ctx->r2 = ADD32(ctx->r10, ctx->r6);
    // sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // j           L_80066CE8
    // sh          $s3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r19;
    goto L_80066CE8;
    // sh          $s3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r19;
L_80066CD8:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x13A
    ctx->r2 = SIGNED(ctx->r5) < 0X13A ? 1 : 0;
    // bne         $v0, $zero, L_80066CA4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80066CA4;
    }
    // nop

L_80066CE8:
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // slti        $v0, $t0, 0x13A
    ctx->r2 = SIGNED(ctx->r8) < 0X13A ? 1 : 0;
    // bne         $v0, $zero, L_80066C7C
    if (ctx->r2 != 0) {
        // addiu       $t1, $t1, 0x2
        ctx->r9 = ADD32(ctx->r9, 0X2);
        goto L_80066C7C;
    }
    // addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // j           L_80066D84
    // nop

    goto L_80066D84;
    // nop

L_80066D00:
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addu        $t1, $t0, $zero
    ctx->r9 = ADD32(ctx->r8, 0);
L_80066D08:
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // nop

    // addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
    // nop

    // bne         $v0, $s3, L_80066D74
    if (ctx->r2 != ctx->r19) {
        // slti        $v0, $t0, 0x13A
        ctx->r2 = SIGNED(ctx->r8) < 0X13A ? 1 : 0;
        goto L_80066D74;
    }
    // slti        $v0, $t0, 0x13A
    ctx->r2 = SIGNED(ctx->r8) < 0X13A ? 1 : 0;
    // beq         $v0, $zero, L_80066D74
    if (ctx->r2 == 0) {
        // addu        $a1, $t0, $zero
        ctx->r5 = ADD32(ctx->r8, 0);
        goto L_80066D74;
    }
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // addu        $t2, $t1, $zero
    ctx->r10 = ADD32(ctx->r9, 0);
L_80066D30:
    // lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(0X8, ctx->r16);
    // sll         $a3, $a1, 1
    ctx->r7 = S32(ctx->r5) << 1;
    // addu        $v0, $a3, $a2
    ctx->r2 = ADD32(ctx->r7, ctx->r6);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(0X0, ctx->r2);
    // beq         $v1, $s3, L_80066D64
    if (ctx->r3 == ctx->r19) {
        // addu        $v0, $t2, $a2
        ctx->r2 = ADD32(ctx->r10, ctx->r6);
        goto L_80066D64;
    }
    // addu        $v0, $t2, $a2
    ctx->r2 = ADD32(ctx->r10, ctx->r6);
    // sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // nop

    // addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // j           L_80066D74
    // sh          $s3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r19;
    goto L_80066D74;
    // sh          $s3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r19;
L_80066D64:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x13A
    ctx->r2 = SIGNED(ctx->r5) < 0X13A ? 1 : 0;
    // bne         $v0, $zero, L_80066D30
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80066D30;
    }
    // nop

L_80066D74:
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // slti        $v0, $t0, 0x13A
    ctx->r2 = SIGNED(ctx->r8) < 0X13A ? 1 : 0;
    // bne         $v0, $zero, L_80066D08
    if (ctx->r2 != 0) {
        // addiu       $t1, $t1, 0x2
        ctx->r9 = ADD32(ctx->r9, 0X2);
        goto L_80066D08;
    }
    // addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
L_80066D84:
    // lhu         $v0, 0x4($s4)
    ctx->r2 = MEM_HU(0X4, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // beq         $v0, $zero, L_80066E0C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80066E0C;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lbu         $v0, 0x4($s2)
    ctx->r2 = MEM_BU(0X4, ctx->r18);
    // nop

    // beq         $v0, $zero, L_80066DC4
    if (ctx->r2 == 0) {
        // sh          $zero, 0x4($s4)
        MEM_H(0X4, ctx->r20) = 0;
        goto L_80066DC4;
    }
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    // sb          $zero, 0x4($s2)
    MEM_B(0X4, ctx->r18) = 0;
    // sw          $s3, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r19;
    // sw          $s3, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r19;
    // j           L_80066E0C
    // sw          $s3, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r19;
    goto L_80066E0C;
    // sw          $s3, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r19;
L_80066DC4:
    // lbu         $v1, 0xD38($s5)
    ctx->r3 = MEM_BU(0XD38, ctx->r21);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $s6, L_80066DE4
    if (ctx->r3 != ctx->r22) {
        // sb          $v0, 0x4($s2)
        MEM_B(0X4, ctx->r18) = ctx->r2;
        goto L_80066DE4;
    }
    // sb          $v0, 0x4($s2)
    MEM_B(0X4, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // lh          $v1, 0x0($s0)
    ctx->r3 = MEM_HS(0X0, ctx->r16);
    // j           L_80066DF8
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    goto L_80066DF8;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
L_80066DE4:
    // lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(0X2, ctx->r16);
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
L_80066DF8:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r3;
    // sw          $v1, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r3;
    // sw          $v1, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r3;
L_80066E0C:
    // lhu         $v0, 0x4($s4)
    ctx->r2 = MEM_HU(0X4, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // beq         $v0, $zero, L_80066E50
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80066E50;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $v1, L_80066E44
    if (ctx->r2 != ctx->r3) {
        // sh          $zero, 0x4($s4)
        MEM_H(0X4, ctx->r20) = 0;
        goto L_80066E44;
    }
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    // j           L_80066E50
    // sh          $s7, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r23;
    goto L_80066E50;
    // sh          $s7, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r23;
L_80066E44:
    // bne         $v0, $s7, L_80066E50
    if (ctx->r2 != ctx->r23) {
        // nop
    
        goto L_80066E50;
    }
    // nop

    // sh          $v1, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r3;
L_80066E50:
    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_80066E94
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80066E94;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lbu         $v0, 0xD38($s5)
    ctx->r2 = MEM_BU(0XD38, ctx->r21);
    // nop

    // bne         $v0, $s6, L_80066E94
    if (ctx->r2 != ctx->r22) {
        // sh          $zero, 0xC($s4)
        MEM_H(0XC, ctx->r20) = 0;
        goto L_80066E94;
    }
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
    // addiu       $v0, $zero, 0x62
    ctx->r2 = ADD32(0, 0X62);
    // sb          $v0, 0xD38($s5)
    MEM_B(0XD38, ctx->r21) = ctx->r2;
    // sb          $zero, 0x4($s2)
    MEM_B(0X4, ctx->r18) = 0;
    // sw          $s3, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r19;
    // sw          $s3, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r19;
    // sw          $s3, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r19;
L_80066E94:
    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_80066ED8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80066ED8;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
    // lbu         $v1, 0xD38($s5)
    ctx->r3 = MEM_BU(0XD38, ctx->r21);
    // addiu       $v0, $zero, 0x62
    ctx->r2 = ADD32(0, 0X62);
    // bne         $v1, $v0, L_80066ED8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80066ED8;
    }
    // nop

    // sb          $s6, 0xD38($s5)
    MEM_B(0XD38, ctx->r21) = ctx->r22;
    // sb          $zero, 0x4($s2)
    MEM_B(0X4, ctx->r18) = 0;
    // sw          $s3, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r19;
    // sw          $s3, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r19;
    // sw          $s3, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r19;
L_80066ED8:
    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_80066FE8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80066FE8;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // lhu         $v0, 0x2($s4)
    ctx->r2 = MEM_HU(0X2, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // beq         $v0, $zero, L_80066F88
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80066F88;
    }
    // nop

    // lbu         $v0, 0xD38($s5)
    ctx->r2 = MEM_BU(0XD38, ctx->r21);
    // nop

    // bne         $v0, $s6, L_80066F50
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_80066F50;
    }
    // nop

    // lh          $v0, 0x0($s0)
    ctx->r2 = MEM_HS(0X0, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80066F2C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80066F2C;
    }
    // nop

    // sh          $zero, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = 0;
L_80066F2C:
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0xB
    ctx->r2 = ADD32(ctx->r2, -0XB);
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_80066FE4
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80066FE4;
    }
    // nop

    // j           L_80066FE4
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    goto L_80066FE4;
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_80066F50:
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80066F70
    if (ctx->r2 != 0) {
        // addiu       $v0, $v0, -0xB
        ctx->r2 = ADD32(ctx->r2, -0XB);
        goto L_80066F70;
    }
    // addiu       $v0, $v0, -0xB
    ctx->r2 = ADD32(ctx->r2, -0XB);
    // sh          $zero, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = 0;
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0xB
    ctx->r2 = ADD32(ctx->r2, -0XB);
L_80066F70:
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_80066FE4
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80066FE4;
    }
    // nop

    // j           L_80066FE4
    // sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    goto L_80066FE4;
    // sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
L_80066F88:
    // lhu         $v1, 0x2E0($s0)
    ctx->r3 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // blez        $v0, L_80066FA4
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_80066FA4;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // j           L_80066FE4
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
    goto L_80066FE4;
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_80066FA4:
    // lbu         $v0, 0xD38($s5)
    ctx->r2 = MEM_BU(0XD38, ctx->r21);
    // nop

    // bne         $v0, $s6, L_80066FCC
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_80066FCC;
    }
    // nop

    // lh          $v0, 0x0($s0)
    ctx->r2 = MEM_HS(0X0, ctx->r16);
    // lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(0X0, ctx->r16);
    // blez        $v0, L_80066FE4
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_80066FE4;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // j           L_80066FE4
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    goto L_80066FE4;
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_80066FCC:
    // lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(0X2, ctx->r16);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // blez        $v0, L_80066FE4
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_80066FE4;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
L_80066FE4:
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
L_80066FE8:
    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_80067124
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80067124;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lhu         $v0, 0x2($s4)
    ctx->r2 = MEM_HU(0X2, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // beq         $v0, $zero, L_800670B0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800670B0;
    }
    // nop

    // lbu         $v0, 0xD38($s5)
    ctx->r2 = MEM_BU(0XD38, ctx->r21);
    // nop

    // bne         $v0, $s6, L_80067068
    if (ctx->r2 != ctx->r22) {
        // addiu       $v1, $zero, 0x12F
        ctx->r3 = ADD32(0, 0X12F);
        goto L_80067068;
    }
    // addiu       $v1, $zero, 0x12F
    ctx->r3 = ADD32(0, 0X12F);
    // lh          $v0, 0x0($s0)
    ctx->r2 = MEM_HS(0X0, ctx->r16);
    // nop

    // bne         $v0, $v1, L_8006703C
    if (ctx->r2 != ctx->r3) {
        // addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
        goto L_8006703C;
    }
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_8006703C:
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0xB
    ctx->r2 = ADD32(ctx->r2, 0XB);
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x130
    ctx->r2 = SIGNED(ctx->r2) < 0X130 ? 1 : 0;
    // bne         $v0, $zero, L_80067120
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80067120;
    }
    // nop

    // j           L_80067120
    // sh          $v1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r3;
    goto L_80067120;
    // sh          $v1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r3;
L_80067068:
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_80067084
    if (ctx->r2 != ctx->r3) {
        // addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
        goto L_80067084;
    }
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_80067084:
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0xB
    ctx->r2 = ADD32(ctx->r2, 0XB);
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x130
    ctx->r2 = SIGNED(ctx->r2) < 0X130 ? 1 : 0;
    // bne         $v0, $zero, L_80067120
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80067120;
    }
    // nop

    // j           L_80067120
    // sh          $v1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r3;
    goto L_80067120;
    // sh          $v1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r3;
L_800670B0:
    // lhu         $v1, 0x2E0($s0)
    ctx->r3 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_800670D4
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_800670D4;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // j           L_80067120
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
    goto L_80067120;
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_800670D4:
    // lbu         $v0, 0xD38($s5)
    ctx->r2 = MEM_BU(0XD38, ctx->r21);
    // nop

    // bne         $v0, $s6, L_80067100
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_80067100;
    }
    // nop

    // lh          $v0, 0x0($s0)
    ctx->r2 = MEM_HS(0X0, ctx->r16);
    // lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(0X0, ctx->r16);
    // slti        $v0, $v0, 0x12F
    ctx->r2 = SIGNED(ctx->r2) < 0X12F ? 1 : 0;
    // beq         $v0, $zero, L_80067120
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_80067120;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // j           L_80067120
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    goto L_80067120;
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_80067100:
    // lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(0X2, ctx->r16);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x12F
    ctx->r2 = SIGNED(ctx->r2) < 0X12F ? 1 : 0;
    // beq         $v0, $zero, L_80067120
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_80067120;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
L_80067120:
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
L_80067124:
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // nop

    // bne         $v0, $s7, L_80067144
    if (ctx->r2 != ctx->r23) {
        // nop
    
        goto L_80067144;
    }
    // nop

    // lbu         $v0, 0xD38($s5)
    ctx->r2 = MEM_BU(0XD38, ctx->r21);
    // nop

    // bne         $v0, $s6, L_8006721C
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_8006721C;
    }
    // nop

L_80067144:
    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // beq         $v0, $zero, L_800671A4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800671A4;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // lbu         $v0, 0xD38($s5)
    ctx->r2 = MEM_BU(0XD38, ctx->r21);
    // nop

    // bne         $v0, $s6, L_80067184
    if (ctx->r2 != ctx->r22) {
        // sh          $zero, 0xC($s4)
        MEM_H(0XC, ctx->r20) = 0;
        goto L_80067184;
    }
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
    // lh          $v0, 0x0($s0)
    ctx->r2 = MEM_HS(0X0, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80067184
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80067184;
    }
    // nop

    // sh          $zero, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = 0;
L_80067184:
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0xB
    ctx->r2 = ADD32(ctx->r2, -0XB);
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_800671A4
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800671A4;
    }
    // nop

    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800671A4:
    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // beq         $v0, $zero, L_8006720C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006720C;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // lbu         $v0, 0xD38($s5)
    ctx->r2 = MEM_BU(0XD38, ctx->r21);
    // nop

    // bne         $v0, $s6, L_800671E4
    if (ctx->r2 != ctx->r22) {
        // sh          $zero, 0xC($s4)
        MEM_H(0XC, ctx->r20) = 0;
        goto L_800671E4;
    }
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
    // lh          $v1, 0x0($s0)
    ctx->r3 = MEM_HS(0X0, ctx->r16);
    // addiu       $v0, $zero, 0x12F
    ctx->r2 = ADD32(0, 0X12F);
    // bne         $v1, $v0, L_800671E4
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
        goto L_800671E4;
    }
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_800671E4:
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0xB
    ctx->r2 = ADD32(ctx->r2, 0XB);
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x130
    ctx->r2 = SIGNED(ctx->r2) < 0X130 ? 1 : 0;
    // bne         $v0, $zero, L_8006720C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x12F
        ctx->r2 = ADD32(0, 0X12F);
        goto L_8006720C;
    }
    // addiu       $v0, $zero, 0x12F
    ctx->r2 = ADD32(0, 0X12F);
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_8006720C:
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // nop

    // bne         $v0, $s7, L_8006723C
    if (ctx->r2 != ctx->r23) {
        // nop
    
        goto L_8006723C;
    }
    // nop

L_8006721C:
    // lbu         $v1, 0xD38($s5)
    ctx->r3 = MEM_BU(0XD38, ctx->r21);
    // addiu       $v0, $zero, 0x62
    ctx->r2 = ADD32(0, 0X62);
    // beq         $v1, $v0, L_8006723C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8006723C;
    }
    // nop

    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // nop

    // beq         $v0, $s7, L_80067314
    if (ctx->r2 == ctx->r23) {
        // nop
    
        goto L_80067314;
    }
    // nop

L_8006723C:
    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // beq         $v0, $zero, L_800672A0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800672A0;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
    // lbu         $v1, 0xD38($s5)
    ctx->r3 = MEM_BU(0XD38, ctx->r21);
    // addiu       $v0, $zero, 0x62
    ctx->r2 = ADD32(0, 0X62);
    // bne         $v1, $v0, L_80067280
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80067280;
    }
    // nop

    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8006728C
    if (ctx->r2 != 0) {
        // addiu       $v0, $v0, -0xB
        ctx->r2 = ADD32(ctx->r2, -0XB);
        goto L_8006728C;
    }
    // addiu       $v0, $v0, -0xB
    ctx->r2 = ADD32(ctx->r2, -0XB);
    // sh          $zero, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = 0;
L_80067280:
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0xB
    ctx->r2 = ADD32(ctx->r2, -0XB);
L_8006728C:
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_800672A0
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800672A0;
    }
    // nop

    // sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
L_800672A0:
    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // beq         $v0, $zero, L_80067314
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80067314;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
    // lbu         $v1, 0xD38($s5)
    ctx->r3 = MEM_BU(0XD38, ctx->r21);
    // addiu       $v0, $zero, 0x62
    ctx->r2 = ADD32(0, 0X62);
    // bne         $v1, $v0, L_800672EC
    if (ctx->r3 != ctx->r2) {
        // addiu       $v1, $zero, 0x12F
        ctx->r3 = ADD32(0, 0X12F);
        goto L_800672EC;
    }
    // addiu       $v1, $zero, 0x12F
    ctx->r3 = ADD32(0, 0X12F);
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_800672EC
    if (ctx->r2 != ctx->r3) {
        // addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
        goto L_800672EC;
    }
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_800672EC:
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0xB
    ctx->r2 = ADD32(ctx->r2, 0XB);
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x130
    ctx->r2 = SIGNED(ctx->r2) < 0X130 ? 1 : 0;
    // bne         $v0, $zero, L_80067314
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x12F
        ctx->r2 = ADD32(0, 0X12F);
        goto L_80067314;
    }
    // addiu       $v0, $zero, 0x12F
    ctx->r2 = ADD32(0, 0X12F);
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
L_80067314:
    // lbu         $v0, 0x4($s2)
    ctx->r2 = MEM_BU(0X4, ctx->r18);
    // nop

    // beq         $v0, $zero, L_80067398
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80067398;
    }
    // nop

    // lbu         $v0, 0xD38($s5)
    ctx->r2 = MEM_BU(0XD38, ctx->r21);
    // nop

    // bne         $v0, $s6, L_80067344
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_80067344;
    }
    // nop

    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // lh          $v1, 0x0($s0)
    ctx->r3 = MEM_HS(0X0, ctx->r16);
    // j           L_80067358
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    goto L_80067358;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
L_80067344:
    // lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(0X2, ctx->r16);
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
L_80067358:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(0X10, ctx->r18);
    // nop

    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80067380
    if (ctx->r2 == 0) {
        // slt         $v0, $v1, $a0
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
        goto L_80067380;
    }
    // slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // sw          $a0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r4;
    // j           L_80067398
    // sw          $v1, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r3;
    goto L_80067398;
    // sw          $v1, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r3;
L_80067380:
    // beq         $v0, $zero, L_80067390
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80067390;
    }
    // nop

    // j           L_80067394
    // sw          $v1, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r3;
    goto L_80067394;
    // sw          $v1, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r3;
L_80067390:
    // sw          $a0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r4;
L_80067394:
    // sw          $a0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r4;
L_80067398:
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // nop

    // bne         $v0, $s7, L_80067470
    if (ctx->r2 != ctx->r23) {
        // nop
    
        goto L_80067470;
    }
    // nop

    // jal         0x8006616C
    // nop

    sub_8006616C(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bne         $v0, $zero, L_80067470
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80067470;
    }
    // nop

    // lbu         $v0, 0xD38($s5)
    ctx->r2 = MEM_BU(0XD38, ctx->r21);
    // nop

    // bne         $v0, $s6, L_800673F8
    if (ctx->r2 != ctx->r22) {
        // nop
    
        goto L_800673F8;
    }
    // nop

    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // lh          $v1, 0x0($s0)
    ctx->r3 = MEM_HS(0X0, ctx->r16);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $s1, 0x0($v1)
    ctx->r17 = MEM_HU(0X0, ctx->r3);
    // j           L_80067424
    // nop

    goto L_80067424;
    // nop

L_800673F8:
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // lhu         $v1, 0x2E0($s0)
    ctx->r3 = MEM_HU(0X2E0, ctx->r16);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(0X8, ctx->r16);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $s1, 0x0($v0)
    ctx->r17 = MEM_HU(0X0, ctx->r2);
L_80067424:
    // lh          $v1, 0x2($s2)
    ctx->r3 = MEM_HS(0X2, ctx->r18);
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // beq         $v1, $a0, L_80067470
    if (ctx->r3 == ctx->r4) {
        // nop
    
        goto L_80067470;
    }
    // nop

    // beq         $a0, $s3, L_80067470
    if (ctx->r4 == ctx->r19) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_80067470;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x76F8
    ctx->r2 = ADD32(ctx->r2, 0X76F8);
    // sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4) << 1;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $a1, 0x11D($v1)
    ctx->r5 = MEM_BU(0X11D, ctx->r3);
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // jal         0x8006620C
    // addiu       $a1, $a1, 0xC8
    ctx->r5 = ADD32(ctx->r5, 0XC8);
    sub_8006620C(rdram, ctx);
    goto after_15;
    // addiu       $a1, $a1, 0xC8
    ctx->r5 = ADD32(ctx->r5, 0XC8);
    after_15:
    // sh          $s1, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r17;
L_80067470:
    // jal         0x800164B4
    // nop

    sub_800164B4(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // jal         0x80068258
    // nop

    sub_80068258(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // lbu         $a0, 0x2E4($s0)
    ctx->r4 = MEM_BU(0X2E4, ctx->r16);
    // nop

    // addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // bgez        $v1, L_80067498
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80067498;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_80067498:
    // andi        $v0, $v0, 0x1E0
    ctx->r2 = ctx->r2 & 0X1E0;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // j           L_800667F8
    // sb          $v0, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = ctx->r2;
    goto L_800667F8;
    // sb          $v0, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = ctx->r2;
L_800674A8:
    // lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(0XC, ctx->r16);
    // nop

    // beq         $a0, $zero, L_800674FC
    if (ctx->r4 == 0) {
        // addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
        goto L_800674FC;
    }
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a1, $v0, 0x7590
    ctx->r5 = ADD32(ctx->r2, 0X7590);
L_800674C4:
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // nop

    // beq         $v1, $a2, L_800674F0
    if (ctx->r3 == ctx->r6) {
        // addu        $v1, $v1, $a1
        ctx->r3 = ADD32(ctx->r3, ctx->r5);
        goto L_800674F0;
    }
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_800674F0:
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // bne         $v0, $zero, L_800674C4
    if (ctx->r2 != 0) {
        // addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_800674C4;
    }
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800674FC:
    // lhu         $a0, 0xE($s0)
    ctx->r4 = MEM_HU(0XE, ctx->r16);
    // nop

    // beq         $a0, $zero, L_80067550
    if (ctx->r4 == 0) {
        // addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
        goto L_80067550;
    }
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a1, $v0, 0x7590
    ctx->r5 = ADD32(ctx->r2, 0X7590);
L_80067518:
    // lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(0X8, ctx->r16);
    // sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // nop

    // beq         $v1, $a2, L_80067544
    if (ctx->r3 == ctx->r6) {
        // addu        $v1, $v1, $a1
        ctx->r3 = ADD32(ctx->r3, ctx->r5);
        goto L_80067544;
    }
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_80067544:
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // bne         $v0, $zero, L_80067518
    if (ctx->r2 != 0) {
        // addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_80067518;
    }
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80067550:
    // lw          $ra, 0x88($sp)
    ctx->r31 = MEM_W(0X88, ctx->r29);
    // lw          $s7, 0x84($sp)
    ctx->r23 = MEM_W(0X84, ctx->r29);
    // lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(0X80, ctx->r29);
    // lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(0X7C, ctx->r29);
    // lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(0X78, ctx->r29);
    // lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(0X74, ctx->r29);
    // lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(0X70, ctx->r29);
    // lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(0X6C, ctx->r29);
    // lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(0X68, ctx->r29);
    // addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // jr          $ra
    // nop

    return;
    // nop

;}
