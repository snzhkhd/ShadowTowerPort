#include "recomp.h"
#include "disable_warnings.h"

void sub_8003025C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
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
    // sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1BE
    ctx->r2 = ADD32(0, 0X1BE);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x230
    ctx->r2 = ADD32(0, 0X230);
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1F2
    ctx->r2 = ADD32(0, 0X1F2);
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x9A
    ctx->r2 = ADD32(0, 0X9A);
    // sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7FA8
    ctx->r6 = ADD32(ctx->r2, 0X7FA8);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r3);
    // swr         $v1, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r3);
    // swl         $a0, 0x37($sp)
    do_swl(rdram, 0X37, ctx->r29, ctx->r4);
    // swr         $a0, 0x34($sp)
    do_swr(rdram, 0X34, ctx->r29, ctx->r4);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7FB0
    ctx->r6 = ADD32(ctx->r2, 0X7FB0);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x3B($sp)
    do_swl(rdram, 0X3B, ctx->r29, ctx->r3);
    // swr         $v1, 0x38($sp)
    do_swr(rdram, 0X38, ctx->r29, ctx->r3);
    // swl         $a0, 0x3F($sp)
    do_swl(rdram, 0X3F, ctx->r29, ctx->r4);
    // swr         $a0, 0x3C($sp)
    do_swr(rdram, 0X3C, ctx->r29, ctx->r4);
    // addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x1388
    ctx->r6 = ADD32(ctx->r2, 0X1388);
    // andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // beq         $v0, $zero, L_80030370
    if (ctx->r2 == 0) {
        // lui         $s5, 0x1F80
        ctx->r21 = S32(0X1F80 << 16);
        goto L_80030370;
    }
    // lui         $s5, 0x1F80
    ctx->r21 = S32(0X1F80 << 16);
    // addiu       $t0, $a2, 0x20
    ctx->r8 = ADD32(ctx->r6, 0X20);
L_8003031C:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lwl         $a0, 0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r6);
    // lwr         $a0, 0x8($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r6);
    // lwl         $a1, 0xF($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r6);
    // lwr         $a1, 0xC($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r6);
    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // swl         $v1, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r3);
    // swr         $v1, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r3);
    // swl         $a0, 0xB($a3)
    do_swl(rdram, 0XB, ctx->r7, ctx->r4);
    // swr         $a0, 0x8($a3)
    do_swr(rdram, 0X8, ctx->r7, ctx->r4);
    // swl         $a1, 0xF($a3)
    do_swl(rdram, 0XF, ctx->r7, ctx->r5);
    // swr         $a1, 0xC($a3)
    do_swr(rdram, 0XC, ctx->r7, ctx->r5);
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_8003031C
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8003031C;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // j           L_800303A0
    // nop

    goto L_800303A0;
    // nop

L_80030370:
    // addiu       $t0, $a2, 0x20
    ctx->r8 = ADD32(ctx->r6, 0X20);
L_80030374:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_80030374
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_80030374;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_800303A0:
    // lh          $v0, 0x0($a2)
    ctx->r2 = MEM_HS(0X0, ctx->r6);
    // nop

    // sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // lhu         $v1, 0x2E2($s5)
    ctx->r3 = MEM_HU(0X2E2, ctx->r21);
    // lhu         $a0, 0x2E0($s5)
    ctx->r4 = MEM_HU(0X2E0, ctx->r21);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x8($s5)
    ctx->r3 = MEM_W(0X8, ctx->r21);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $s0, 0x0($v1)
    ctx->r16 = MEM_BU(0X0, ctx->r3);
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $a1, $v1, -0x2E80
    ctx->r5 = ADD32(ctx->r3, -0X2E80);
    // lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(0X0, ctx->r21);
    // lhu         $a0, 0x4($a1)
    ctx->r4 = MEM_HU(0X4, ctx->r5);
    // sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16) << 1;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s4, $v1, $v0
    ctx->r20 = ADD32(ctx->r3, ctx->r2);
    // andi        $v0, $a0, 0x800
    ctx->r2 = ctx->r4 & 0X800;
    // beq         $v0, $zero, L_80030418
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80030418;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E56($at)
    MEM_H(-0X7E56, ctx->r1) = ctx->r2;
L_80030418:
    // andi        $v0, $a0, 0x400
    ctx->r2 = ctx->r4 & 0X400;
    // beq         $v0, $zero, L_8003042C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003042C;
    }
    // nop

    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $zero, -0x7E56($at)
    MEM_H(-0X7E56, ctx->r1) = 0;
L_8003042C:
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lhu         $v0, -0x7E56($v0)
    ctx->r2 = MEM_HU(-0X7E56, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80030450
    if (ctx->r2 != 0) {
        // sh          $zero, 0x4($a1)
        MEM_H(0X4, ctx->r5) = 0;
        goto L_80030450;
    }
    // sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // ori         $a1, $s5, 0x32C
    ctx->r5 = ctx->r21 | 0X32C;
    // j           L_8003045C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    goto L_8003045C;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80030450:
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // ori         $a1, $s5, 0x32C
    ctx->r5 = ctx->r21 | 0X32C;
    // addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
L_8003045C:
    // jal         0x8002916C
    // nop

    sub_8002916C(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_1;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_1:
    // addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // lbu         $v0, 0x303($s5)
    ctx->r2 = MEM_BU(0X303, ctx->r21);
    // lw          $v1, 0x4($s5)
    ctx->r3 = MEM_W(0X4, ctx->r21);
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sb          $v0, 0x303($s5)
    MEM_B(0X303, ctx->r21) = ctx->r2;
    // sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $s0, $s5, 0x300
    ctx->r16 = ADD32(ctx->r21, 0X300);
    // lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(0X0, ctx->r2);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_2;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_2:
    // lui         $v1, 0xF
    ctx->r3 = S32(0XF << 16);
    // ori         $v1, $v1, 0x5
    ctx->r3 = ctx->r3 | 0X5;
    // addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // lbu         $v0, 0x303($s5)
    ctx->r2 = MEM_BU(0X303, ctx->r21);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // jal         0x8002F1F8
    // sb          $v0, 0x303($s5)
    MEM_B(0X303, ctx->r21) = ctx->r2;
    sub_8002F1F8(rdram, ctx);
    goto after_3;
    // sb          $v0, 0x303($s5)
    MEM_B(0X303, ctx->r21) = ctx->r2;
    after_3:
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lhu         $v0, -0x7E56($v0)
    ctx->r2 = MEM_HU(-0X7E56, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80030568
    if (ctx->r2 == 0) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_80030568;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xD50
    ctx->r2 = ADD32(ctx->r2, 0XD50);
    // addiu       $s6, $v0, 0xC00
    ctx->r22 = ADD32(ctx->r2, 0XC00);
    // addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // addiu       $a1, $zero, 0x150
    ctx->r5 = ADD32(0, 0X150);
L_80030504:
    // andi        $s0, $s3, 0xFFFF
    ctx->r16 = ctx->r19 & 0XFFFF;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addiu       $a3, $s5, 0x300
    ctx->r7 = ADD32(ctx->r21, 0X300);
    // addiu       $s3, $s3, 0xF
    ctx->r19 = ADD32(ctx->r19, 0XF);
    // lhu         $a0, 0xC8($s2)
    ctx->r4 = MEM_HU(0XC8, ctx->r18);
    // addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // jal         0x8002732C
    // addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    sub_8002732C(rdram, ctx);
    goto after_4;
    // addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    after_4:
    // addiu       $a1, $zero, 0x246
    ctx->r5 = ADD32(0, 0X246);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addiu       $a3, $s5, 0x310
    ctx->r7 = ADD32(ctx->r21, 0X310);
    // addu        $v0, $s4, $s1
    ctx->r2 = ADD32(ctx->r20, ctx->r17);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // lbu         $a0, 0x1C($v0)
    ctx->r4 = MEM_BU(0X1C, ctx->r2);
    // lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4) << 24;
    // sra         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4) >> 24;
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // jal         0x80027440
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    sub_80027440(rdram, ctx);
    goto after_5;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    after_5:
    // slti        $v0, $s1, 0xE
    ctx->r2 = SIGNED(ctx->r17) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_80030504
    if (ctx->r2 != 0) {
        // addiu       $a1, $zero, 0x150
        ctx->r5 = ADD32(0, 0X150);
        goto L_80030504;
    }
    // addiu       $a1, $zero, 0x150
    ctx->r5 = ADD32(0, 0X150);
    // j           L_80030A04
    // addiu       $s0, $s5, 0x350
    ctx->r16 = ADD32(ctx->r21, 0X350);
    goto L_80030A04;
    // addiu       $s0, $s5, 0x350
    ctx->r16 = ADD32(ctx->r21, 0X350);
L_80030568:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xD50
    ctx->r2 = ADD32(ctx->r2, 0XD50);
    // addiu       $s3, $v0, 0xC00
    ctx->r19 = ADD32(ctx->r2, 0XC00);
    // addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $a1, $zero, 0x150
    ctx->r5 = ADD32(0, 0X150);
L_80030580:
    // andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    // addiu       $a3, $s5, 0x300
    ctx->r7 = ADD32(ctx->r21, 0X300);
    // addiu       $s2, $s2, 0xF
    ctx->r18 = ADD32(ctx->r18, 0XF);
    // lhu         $a0, 0xEA($s0)
    ctx->r4 = MEM_HU(0XEA, ctx->r16);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // jal         0x8002732C
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    sub_8002732C(rdram, ctx);
    goto after_6;
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    after_6:
    // slti        $v0, $s1, 0xA
    ctx->r2 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // bne         $v0, $zero, L_80030580
    if (ctx->r2 != 0) {
        // addiu       $a1, $zero, 0x150
        ctx->r5 = ADD32(0, 0X150);
        goto L_80030580;
    }
    // addiu       $a1, $zero, 0x150
    ctx->r5 = ADD32(0, 0X150);
    // lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(0X0, ctx->r20);
    // nop

    // sltiu       $v0, $v0, 0x11
    ctx->r2 = ctx->r2 < 0X11 ? 1 : 0;
    // beq         $v0, $zero, L_800305FC
    if (ctx->r2 == 0) {
        // addiu       $a2, $zero, 0x10
        ctx->r6 = ADD32(0, 0X10);
        goto L_800305FC;
    }
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lbu         $v1, 0x0($s4)
    ctx->r3 = MEM_BU(0X0, ctx->r20);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v0, $v1, $a0
    ctx->r2 = ADD32(ctx->r3, ctx->r4);
    // lhu         $v0, 0x12C($v0)
    ctx->r2 = MEM_HU(0X12C, ctx->r2);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // addu        $v0, $sp, $v1
    ctx->r2 = ADD32(ctx->r29, ctx->r3);
    // lhu         $v0, 0x40($v0)
    ctx->r2 = MEM_HU(0X40, ctx->r2);
    // addiu       $a1, $zero, 0x25E
    ctx->r5 = ADD32(0, 0X25E);
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // jal         0x8002732C
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_8002732C(rdram, ctx);
    goto after_7;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_7:
L_800305FC:
    // addiu       $a1, $zero, 0x22E
    ctx->r5 = ADD32(0, 0X22E);
    // addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // addiu       $s2, $s5, 0x310
    ctx->r18 = ADD32(ctx->r21, 0X310);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // lhu         $a0, 0x2($s4)
    ctx->r4 = MEM_HU(0X2, ctx->r20);
    // lui         $s1, 0x400
    ctx->r17 = S32(0X400 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_80027440(rdram, ctx);
    goto after_8;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_8:
    // addiu       $a1, $zero, 0x246
    ctx->r5 = ADD32(0, 0X246);
    // addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // lbu         $a0, 0x1($s4)
    ctx->r4 = MEM_BU(0X1, ctx->r20);
    // lui         $s0, 0x200
    ctx->r16 = S32(0X200 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    sub_80027440(rdram, ctx);
    goto after_9;
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    after_9:
    // lui         $a0, 0x2B00
    ctx->r4 = S32(0X2B00 << 16);
    // lh          $v1, 0x4($s4)
    ctx->r3 = MEM_HS(0X4, ctx->r20);
    // ori         $a0, $a0, 0xAC03
    ctx->r4 = ctx->r4 | 0XAC03;
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $zero, 0x20A
    ctx->r5 = ADD32(0, 0X20A);
    // addiu       $a2, $zero, 0x3D
    ctx->r6 = ADD32(0, 0X3D);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $v1
    ctx->r3 = hi;
    // sra         $v1, $v1, 9
    ctx->r3 = S32(ctx->r3) >> 9;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v1, -0x7E62($at)
    MEM_H(-0X7E62, ctx->r1) = ctx->r3;
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // lhu         $a0, -0x7E62($a0)
    ctx->r4 = MEM_HU(-0X7E62, ctx->r4);
    // lui         $s3, 0x300
    ctx->r19 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    sub_80027440(rdram, ctx);
    goto after_10;
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    after_10:
    // addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // addiu       $a1, $zero, 0x22F
    ctx->r5 = ADD32(0, 0X22F);
    // addiu       $a2, $zero, 0x3D
    ctx->r6 = ADD32(0, 0X3D);
    // jal         0x80026ECC
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_80026ECC(rdram, ctx);
    goto after_11;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_11:
    // lh          $v0, 0x4($s4)
    ctx->r2 = MEM_HS(0X4, ctx->r20);
    // nop

    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lhu         $v0, -0x7E62($v0)
    ctx->r2 = MEM_HU(-0X7E62, ctx->r2);
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // lui         $v0, 0x8102
    ctx->r2 = S32(0X8102 << 16);
    // ori         $v0, $v0, 0x409
    ctx->r2 = ctx->r2 | 0X409;
    // multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $zero, 0x23A
    ctx->r5 = ADD32(0, 0X23A);
    // addiu       $a2, $zero, 0x3D
    ctx->r6 = ADD32(0, 0X3D);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // mfhi        $v0
    ctx->r2 = hi;
    // srl         $a0, $v0, 6
    ctx->r4 = S32(U32(ctx->r2) >> 6);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // jal         0x80027440
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    sub_80027440(rdram, ctx);
    goto after_12;
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    after_12:
    // addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // addiu       $a1, $zero, 0x253
    ctx->r5 = ADD32(0, 0X253);
    // addiu       $a2, $zero, 0x3D
    ctx->r6 = ADD32(0, 0X3D);
    // jal         0x80026ECC
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_80026ECC(rdram, ctx);
    goto after_13;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_13:
    // lui         $a1, 0x2416
    ctx->r5 = S32(0X2416 << 16);
    // lh          $v0, 0x6($s4)
    ctx->r2 = MEM_HS(0X6, ctx->r20);
    // ori         $a1, $a1, 0x8E19
    ctx->r5 = ctx->r5 | 0X8E19;
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2) << 5;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a2, $zero, 0x4C
    ctx->r6 = ADD32(0, 0X4C);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // addiu       $a1, $zero, 0x20A
    ctx->r5 = ADD32(0, 0X20A);
    // sra         $v0, $t0, 6
    ctx->r2 = S32(ctx->r8) >> 6;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E62($at)
    MEM_H(-0X7E62, ctx->r1) = ctx->r2;
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // lhu         $a0, -0x7E62($a0)
    ctx->r4 = MEM_HU(-0X7E62, ctx->r4);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v0, $t2, 6
    ctx->r2 = S32(ctx->r10) >> 6;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E78($at)
    MEM_H(-0X7E78, ctx->r1) = ctx->r2;
    // jal         0x80027440
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_80027440(rdram, ctx);
    goto after_14;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_14:
    // addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // addiu       $a1, $zero, 0x23E
    ctx->r5 = ADD32(0, 0X23E);
    // addiu       $a2, $zero, 0x4C
    ctx->r6 = ADD32(0, 0X4C);
    // jal         0x80026ECC
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_80026ECC(rdram, ctx);
    goto after_15;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_15:
    // addiu       $a1, $zero, 0x246
    ctx->r5 = ADD32(0, 0X246);
    // addiu       $a2, $zero, 0x4C
    ctx->r6 = ADD32(0, 0X4C);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E62($v1)
    ctx->r3 = MEM_HU(-0X7E62, ctx->r3);
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // lhu         $a0, -0x7E78($a0)
    ctx->r4 = MEM_HU(-0X7E78, ctx->r4);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    sub_80027440(rdram, ctx);
    goto after_16;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    after_16:
    // addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // addiu       $a1, $zero, 0x252
    ctx->r5 = ADD32(0, 0X252);
    // addiu       $a2, $zero, 0x4C
    ctx->r6 = ADD32(0, 0X4C);
    // jal         0x80026ECC
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_80026ECC(rdram, ctx);
    goto after_17;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_17:
    // lh          $v0, 0xA($s4)
    ctx->r2 = MEM_HS(0XA, ctx->r20);
    // nop

    // beq         $v0, $zero, L_80030840
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x20A
        ctx->r5 = ADD32(0, 0X20A);
        goto L_80030840;
    }
    // addiu       $a1, $zero, 0x20A
    ctx->r5 = ADD32(0, 0X20A);
    // addiu       $a2, $zero, 0x5B
    ctx->r6 = ADD32(0, 0X5B);
    // lhu         $a0, 0xA($s4)
    ctx->r4 = MEM_HU(0XA, ctx->r20);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    sub_80027440(rdram, ctx);
    goto after_18;
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    after_18:
    // addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // addiu       $a1, $zero, 0x22E
    ctx->r5 = ADD32(0, 0X22E);
    // addiu       $a2, $zero, 0x5B
    ctx->r6 = ADD32(0, 0X5B);
    // jal         0x80026ECC
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_80026ECC(rdram, ctx);
    goto after_19;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_19:
L_80030840:
    // addiu       $a1, $zero, 0x23A
    ctx->r5 = ADD32(0, 0X23A);
    // addiu       $a2, $zero, 0x5B
    ctx->r6 = ADD32(0, 0X5B);
    // lhu         $a0, 0x8($s4)
    ctx->r4 = MEM_HU(0X8, ctx->r20);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    sub_80027440(rdram, ctx);
    goto after_20;
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    after_20:
    // lh          $v0, 0xE($s4)
    ctx->r2 = MEM_HS(0XE, ctx->r20);
    // nop

    // beq         $v0, $zero, L_80030890
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x20A
        ctx->r5 = ADD32(0, 0X20A);
        goto L_80030890;
    }
    // addiu       $a1, $zero, 0x20A
    ctx->r5 = ADD32(0, 0X20A);
    // addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    // lhu         $a0, 0xE($s4)
    ctx->r4 = MEM_HU(0XE, ctx->r20);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    sub_80027440(rdram, ctx);
    goto after_21;
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    after_21:
    // addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // addiu       $a1, $zero, 0x22E
    ctx->r5 = ADD32(0, 0X22E);
    // addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    // jal         0x80026ECC
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_80026ECC(rdram, ctx);
    goto after_22;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_22:
L_80030890:
    // addiu       $a1, $zero, 0x23A
    ctx->r5 = ADD32(0, 0X23A);
    // addiu       $a2, $zero, 0x6A
    ctx->r6 = ADD32(0, 0X6A);
    // lhu         $a0, 0xC($s4)
    ctx->r4 = MEM_HU(0XC, ctx->r20);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    sub_80027440(rdram, ctx);
    goto after_23;
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    after_23:
    // lh          $v0, 0x12($s4)
    ctx->r2 = MEM_HS(0X12, ctx->r20);
    // nop

    // beq         $v0, $zero, L_800308E0
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x20A
        ctx->r5 = ADD32(0, 0X20A);
        goto L_800308E0;
    }
    // addiu       $a1, $zero, 0x20A
    ctx->r5 = ADD32(0, 0X20A);
    // addiu       $a2, $zero, 0x79
    ctx->r6 = ADD32(0, 0X79);
    // lhu         $a0, 0x12($s4)
    ctx->r4 = MEM_HU(0X12, ctx->r20);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    sub_80027440(rdram, ctx);
    goto after_24;
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    after_24:
    // addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // addiu       $a1, $zero, 0x22E
    ctx->r5 = ADD32(0, 0X22E);
    // addiu       $a2, $zero, 0x79
    ctx->r6 = ADD32(0, 0X79);
    // jal         0x80026ECC
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_80026ECC(rdram, ctx);
    goto after_25;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_25:
L_800308E0:
    // addiu       $a1, $zero, 0x23A
    ctx->r5 = ADD32(0, 0X23A);
    // addiu       $a2, $zero, 0x79
    ctx->r6 = ADD32(0, 0X79);
    // lhu         $a0, 0x10($s4)
    ctx->r4 = MEM_HU(0X10, ctx->r20);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    sub_80027440(rdram, ctx);
    goto after_26;
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    after_26:
    // lh          $v0, 0x16($s4)
    ctx->r2 = MEM_HS(0X16, ctx->r20);
    // nop

    // beq         $v0, $zero, L_80030930
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x20A
        ctx->r5 = ADD32(0, 0X20A);
        goto L_80030930;
    }
    // addiu       $a1, $zero, 0x20A
    ctx->r5 = ADD32(0, 0X20A);
    // addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // lhu         $a0, 0x16($s4)
    ctx->r4 = MEM_HU(0X16, ctx->r20);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    sub_80027440(rdram, ctx);
    goto after_27;
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    after_27:
    // addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // addiu       $a1, $zero, 0x22E
    ctx->r5 = ADD32(0, 0X22E);
    // addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // jal         0x80026ECC
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_80026ECC(rdram, ctx);
    goto after_28;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_28:
L_80030930:
    // addiu       $a1, $zero, 0x23A
    ctx->r5 = ADD32(0, 0X23A);
    // addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // lhu         $a0, 0x14($s4)
    ctx->r4 = MEM_HU(0X14, ctx->r20);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    sub_80027440(rdram, ctx);
    goto after_29;
    // or          $a0, $a0, $s3
    ctx->r4 = ctx->r4 | ctx->r19;
    after_29:
    // lw          $v0, 0x18($s4)
    ctx->r2 = MEM_W(0X18, ctx->r20);
    // nop

    // andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // beq         $v0, $zero, L_80030984
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x150
        ctx->r5 = ADD32(0, 0X150);
        goto L_80030984;
    }
    // addiu       $a1, $zero, 0x150
    ctx->r5 = ADD32(0, 0X150);
    // addiu       $a2, $zero, 0xB5
    ctx->r6 = ADD32(0, 0XB5);
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v0, 0x102($v0)
    ctx->r2 = MEM_HU(0X102, ctx->r2);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_30;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_30:
L_80030984:
    // lw          $v0, 0x18($s4)
    ctx->r2 = MEM_W(0X18, ctx->r20);
    // nop

    // srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // beq         $v0, $zero, L_800309C4
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x150
        ctx->r5 = ADD32(0, 0X150);
        goto L_800309C4;
    }
    // addiu       $a1, $zero, 0x150
    ctx->r5 = ADD32(0, 0X150);
    // addiu       $a2, $zero, 0xC4
    ctx->r6 = ADD32(0, 0XC4);
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v0, 0x102($v0)
    ctx->r2 = MEM_HU(0X102, ctx->r2);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_31;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_31:
L_800309C4:
    // lhu         $v0, 0x1A($s4)
    ctx->r2 = MEM_HU(0X1A, ctx->r20);
    // nop

    // andi        $v0, $v0, 0xF
    ctx->r2 = ctx->r2 & 0XF;
    // beq         $v0, $zero, L_80030A00
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x150
        ctx->r5 = ADD32(0, 0X150);
        goto L_80030A00;
    }
    // addiu       $a1, $zero, 0x150
    ctx->r5 = ADD32(0, 0X150);
    // addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v0, 0x102($v0)
    ctx->r2 = MEM_HU(0X102, ctx->r2);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_32;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_32:
L_80030A00:
    // addiu       $s0, $s5, 0x350
    ctx->r16 = ADD32(ctx->r21, 0X350);
L_80030A04:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $s5, 0x300
    ctx->r5 = ctx->r21 | 0X300;
    // addiu       $a2, $zero, 0x201
    ctx->r6 = ADD32(0, 0X201);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
    // sh          $v0, 0x350($s5)
    MEM_H(0X350, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sh          $v0, 0x352($s5)
    MEM_H(0X352, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0xE6
    ctx->r2 = ADD32(0, 0XE6);
    // sh          $v0, 0x354($s5)
    MEM_H(0X354, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x73
    ctx->r2 = ADD32(0, 0X73);
    // jal         0x80027D18
    // sh          $v0, 0x356($s5)
    MEM_H(0X356, ctx->r21) = ctx->r2;
    sub_80027D18(rdram, ctx);
    goto after_33;
    // sh          $v0, 0x356($s5)
    MEM_H(0X356, ctx->r21) = ctx->r2;
    after_33:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // jal         0x800286A8
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    sub_800286A8(rdram, ctx);
    goto after_34;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_34:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $s5, 0x50
    ctx->r5 = ctx->r21 | 0X50;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_35;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_35:
    // addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // addiu       $a2, $zero, 0x124
    ctx->r6 = ADD32(0, 0X124);
    // jal         0x80029548
    // addiu       $a3, $zero, 0xD8
    ctx->r7 = ADD32(0, 0XD8);
    sub_80029548(rdram, ctx);
    goto after_36;
    // addiu       $a3, $zero, 0xD8
    ctx->r7 = ADD32(0, 0XD8);
    after_36:
    // addiu       $a0, $zero, 0x144
    ctx->r4 = ADD32(0, 0X144);
    // addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // addiu       $a2, $zero, 0x124
    ctx->r6 = ADD32(0, 0X124);
    // jal         0x80029548
    // addiu       $a3, $zero, 0xD8
    ctx->r7 = ADD32(0, 0XD8);
    sub_80029548(rdram, ctx);
    goto after_37;
    // addiu       $a3, $zero, 0xD8
    ctx->r7 = ADD32(0, 0XD8);
    after_37:
    // lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(0X84, ctx->r29);
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
    // addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // jr          $ra
    // nop

    return;
    // nop

;}
