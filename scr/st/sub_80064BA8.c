#include "recomp.h"
#include "disable_warnings.h"

void sub_80064BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, 0x3880
    ctx->r6 = ADD32(ctx->r2, 0X3880);
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
    // swl         $v1, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r3);
    // swr         $v1, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r3);
    // swl         $a0, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r4);
    // swr         $a0, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r4);
    // swl         $a1, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r5);
    // swr         $a1, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r5);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s0, $v0, -0x2E80
    ctx->r16 = ADD32(ctx->r2, -0X2E80);
    // lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(0X4, ctx->r16);
    // nop

    // andi        $v0, $a0, 0x2000
    ctx->r2 = ctx->r4 & 0X2000;
    // beq         $v0, $zero, L_80064C3C
    if (ctx->r2 == 0) {
        // lui         $s1, 0x1F80
        ctx->r17 = S32(0X1F80 << 16);
        goto L_80064C3C;
    }
    // lui         $s1, 0x1F80
    ctx->r17 = S32(0X1F80 << 16);
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // lhu         $v1, 0x328($gp)
    ctx->r3 = MEM_HU(0X328, ctx->r28);
    // lhu         $a0, 0x32A($gp)
    ctx->r4 = MEM_HU(0X32A, ctx->r28);
    // andi        $v0, $v0, 0xFFFD
    ctx->r2 = ctx->r2 & 0XFFFD;
    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // sh          $v0, 0x2DC($s1)
    MEM_H(0X2DC, ctx->r17) = ctx->r2;
    // sh          $v1, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = ctx->r3;
    // j           L_80064ECC
    // sh          $a0, 0x2E0($s1)
    MEM_H(0X2E0, ctx->r17) = ctx->r4;
    goto L_80064ECC;
    // sh          $a0, 0x2E0($s1)
    MEM_H(0X2E0, ctx->r17) = ctx->r4;
L_80064C3C:
    // lhu         $v1, 0xC($s0)
    ctx->r3 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // beq         $v0, $zero, L_80064C84
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x40
        ctx->r2 = ctx->r3 & 0X40;
        goto L_80064C84;
    }
    // andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lhu         $v0, 0x2E0($s1)
    ctx->r2 = MEM_HU(0X2E0, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80064DA0
    if (ctx->r2 != 0) {
        // sh          $zero, 0xC($s0)
        MEM_H(0XC, ctx->r16) = 0;
        goto L_80064DA0;
    }
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // lhu         $v1, 0x2E2($s1)
    ctx->r3 = MEM_HU(0X2E2, ctx->r17);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // blez        $v0, L_80064ECC
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_80064ECC;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // j           L_80064ECC
    // sh          $v0, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = ctx->r2;
    goto L_80064ECC;
    // sh          $v0, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = ctx->r2;
L_80064C84:
    // beq         $v0, $zero, L_80064D0C
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x800
        ctx->r2 = ctx->r3 & 0X800;
        goto L_80064D0C;
    }
    // andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lhu         $a1, 0x2E0($s1)
    ctx->r5 = MEM_HU(0X2E0, ctx->r17);
    // nop

    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // bne         $a0, $v0, L_80064CDC
    if (ctx->r4 != ctx->r2) {
        // sh          $zero, 0xC($s0)
        MEM_H(0XC, ctx->r16) = 0;
        goto L_80064CDC;
    }
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $a0, 0x2E2($s1)
    ctx->r4 = MEM_HU(0X2E2, ctx->r17);
    // lw          $v1, 0xD0C($v1)
    ctx->r3 = MEM_W(0XD0C, ctx->r3);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $v1, -0x5
    ctx->r3 = ADD32(ctx->r3, -0X5);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80064ECC
    if (ctx->r2 == 0) {
        // addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
        goto L_80064ECC;
    }
    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // j           L_80064ECC
    // sh          $v0, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = ctx->r2;
    goto L_80064ECC;
    // sh          $v0, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = ctx->r2;
L_80064CDC:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $v0, 0x2E2($s1)
    ctx->r2 = MEM_HU(0X2E2, ctx->r17);
    // lw          $v1, 0xD0C($v1)
    ctx->r3 = MEM_W(0XD0C, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80064ECC
    if (ctx->r2 == 0) {
        // addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
        goto L_80064ECC;
    }
    // addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // j           L_80064ECC
    // sh          $v0, 0x2E0($s1)
    MEM_H(0X2E0, ctx->r17) = ctx->r2;
    goto L_80064ECC;
    // sh          $v0, 0x2E0($s1)
    MEM_H(0X2E0, ctx->r17) = ctx->r2;
L_80064D0C:
    // beq         $v0, $zero, L_80064D58
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x200
        ctx->r2 = ctx->r3 & 0X200;
        goto L_80064D58;
    }
    // andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lhu         $v1, 0x2E2($s1)
    ctx->r3 = MEM_HU(0X2E2, ctx->r17);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $zero, L_80064D3C
    if (ctx->r2 != 0) {
        // sh          $zero, 0xC($s0)
        MEM_H(0XC, ctx->r16) = 0;
        goto L_80064D3C;
    }
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // j           L_80064ECC
    // sh          $zero, 0x2E0($s1)
    MEM_H(0X2E0, ctx->r17) = 0;
    goto L_80064ECC;
    // sh          $zero, 0x2E0($s1)
    MEM_H(0X2E0, ctx->r17) = 0;
L_80064D3C:
    // slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80064D50
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, -0x5
        ctx->r2 = ADD32(ctx->r3, -0X5);
        goto L_80064D50;
    }
    // addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // j           L_80064ECC
    // sh          $v0, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = ctx->r2;
    goto L_80064ECC;
    // sh          $v0, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = ctx->r2;
L_80064D50:
    // j           L_80064ECC
    // sh          $zero, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = 0;
    goto L_80064ECC;
    // sh          $zero, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = 0;
L_80064D58:
    // beq         $v0, $zero, L_80064DD4
    if (ctx->r2 == 0) {
        // andi        $v0, $a0, 0x4000
        ctx->r2 = ctx->r4 & 0X4000;
        goto L_80064DD4;
    }
    // andi        $v0, $a0, 0x4000
    ctx->r2 = ctx->r4 & 0X4000;
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $a2, 0x2E2($s1)
    ctx->r6 = MEM_HU(0X2E2, ctx->r17);
    // addiu       $v1, $v1, 0xD08
    ctx->r3 = ADD32(ctx->r3, 0XD08);
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(0X4, ctx->r3);
    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $a0, $v0, 0x5
    ctx->r4 = ADD32(ctx->r2, 0X5);
    // slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_80064DAC
    if (ctx->r2 != 0) {
        // addiu       $v0, $a1, -0x5
        ctx->r2 = ADD32(ctx->r5, -0X5);
        goto L_80064DAC;
    }
    // addiu       $v0, $a1, -0x5
    ctx->r2 = ADD32(ctx->r5, -0X5);
    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // nop

    // subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
L_80064DA0:
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // j           L_80064ECC
    // sh          $v0, 0x2E0($s1)
    MEM_H(0X2E0, ctx->r17) = ctx->r2;
    goto L_80064ECC;
    // sh          $v0, 0x2E0($s1)
    MEM_H(0X2E0, ctx->r17) = ctx->r2;
L_80064DAC:
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80064DC0
    if (ctx->r2 == 0) {
        // addiu       $v0, $a2, 0x5
        ctx->r2 = ADD32(ctx->r6, 0X5);
        goto L_80064DC0;
    }
    // addiu       $v0, $a2, 0x5
    ctx->r2 = ADD32(ctx->r6, 0X5);
    // j           L_80064ECC
    // sh          $v0, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = ctx->r2;
    goto L_80064ECC;
    // sh          $v0, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = ctx->r2;
L_80064DC0:
    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // nop

    // addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // j           L_80064ECC
    // sh          $v0, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = ctx->r2;
    goto L_80064ECC;
    // sh          $v0, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = ctx->r2;
L_80064DD4:
    // beq         $v0, $zero, L_80064ECC
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80064ECC;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // lw          $v0, 0xCF8($v0)
    ctx->r2 = MEM_W(0XCF8, ctx->r2);
    // addiu       $v1, $v1, -0x7094
    ctx->r3 = ADD32(ctx->r3, -0X7094);
    // bne         $v0, $v1, L_80064E00
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80064E00;
    }
    // nop

    // lhu         $v0, -0xC($v1)
    ctx->r2 = MEM_HU(-0XC, ctx->r3);
    // j           L_80064E08
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    goto L_80064E08;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
L_80064E00:
    // lhu         $v0, 0xE($v1)
    ctx->r2 = MEM_HU(0XE, ctx->r3);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
L_80064E08:
    // lw          $v1, 0xD08($v1)
    ctx->r3 = MEM_W(0XD08, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v0, $v0, -0x310
    ctx->r2 = ADD32(ctx->r2, -0X310);
    // addu        $a1, $v1, $v0
    ctx->r5 = ADD32(ctx->r3, ctx->r2);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $s0, $v1, 0xD08
    ctx->r16 = ADD32(ctx->r3, 0XD08);
    // lhu         $v0, 0x2E2($s1)
    ctx->r2 = MEM_HU(0X2E2, ctx->r17);
    // lhu         $v1, 0x2E0($s1)
    ctx->r3 = MEM_HU(0X2E0, ctx->r17);
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
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // lbu         $a0, 0x8($v0)
    ctx->r4 = MEM_BU(0X8, ctx->r2);
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // sllv        $v1, $v1, $a0
    ctx->r3 = S32(ctx->r3) << (ctx->r4 & 31);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_80064E6C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80064E6C;
    }
    // nop

    // jal         0x80057D34
    // nop

    sub_80057D34(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // j           L_80064ECC
    // nop

    goto L_80064ECC;
    // nop

L_80064E6C:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lhu         $v0, 0x2E2($s1)
    ctx->r2 = MEM_HU(0X2E2, ctx->r17);
    // lhu         $v1, 0x2E0($s1)
    ctx->r3 = MEM_HU(0X2E0, ctx->r17);
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
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lw          $v1, 0xCF8($a0)
    ctx->r3 = MEM_W(0XCF8, ctx->r4);
    // lbu         $v0, 0x8($v0)
    ctx->r2 = MEM_BU(0X8, ctx->r2);
    // nop

    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x2DC($s1)
    ctx->r2 = MEM_HU(0X2DC, ctx->r17);
    // lhu         $v1, 0x328($gp)
    ctx->r3 = MEM_HU(0X328, ctx->r28);
    // lhu         $a0, 0x32A($gp)
    ctx->r4 = MEM_HU(0X32A, ctx->r28);
    // andi        $v0, $v0, 0xFFFD
    ctx->r2 = ctx->r2 & 0XFFFD;
    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // sh          $v0, 0x2DC($s1)
    MEM_H(0X2DC, ctx->r17) = ctx->r2;
    // sh          $v1, 0x2E2($s1)
    MEM_H(0X2E2, ctx->r17) = ctx->r3;
    // jal         0x80063BDC
    // sh          $a0, 0x2E0($s1)
    MEM_H(0X2E0, ctx->r17) = ctx->r4;
    sub_80063BDC(rdram, ctx);
    goto after_7;
    // sh          $a0, 0x2E0($s1)
    MEM_H(0X2E0, ctx->r17) = ctx->r4;
    after_7:
L_80064ECC:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
