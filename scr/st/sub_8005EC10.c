#include "recomp.h"
#include "disable_warnings.h"

void sub_8005EC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x29AC
    ctx->r6 = ADD32(ctx->r2, 0X29AC);
    // sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // lui         $s4, 0x1F80
    ctx->r20 = S32(0X1F80 << 16);
    // andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // beq         $v0, $zero, L_8005ECC0
    if (ctx->r2 == 0) {
        // sw          $zero, 0x50($sp)
        MEM_W(0X50, ctx->r29) = 0;
        goto L_8005ECC0;
    }
    // sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // addiu       $t0, $a2, 0x30
    ctx->r8 = ADD32(ctx->r6, 0X30);
L_8005EC5C:
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
    // bne         $a2, $t0, L_8005EC5C
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8005EC5C;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // j           L_8005ECF4
    // addiu       $a0, $zero, 0x5400
    ctx->r4 = ADD32(0, 0X5400);
    goto L_8005ECF4;
    // addiu       $a0, $zero, 0x5400
    ctx->r4 = ADD32(0, 0X5400);
L_8005ECB0:
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_8005F2D8
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    goto L_8005F2D8;
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
L_8005ECC0:
    // addiu       $t0, $a2, 0x30
    ctx->r8 = ADD32(ctx->r6, 0X30);
L_8005ECC4:
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
    // bne         $a2, $t0, L_8005ECC4
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8005ECC4;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // addiu       $a0, $zero, 0x5400
    ctx->r4 = ADD32(0, 0X5400);
L_8005ECF4:
    // addiu       $v1, $zero, 0x380
    ctx->r3 = ADD32(0, 0X380);
    // addiu       $v0, $zero, 0x1B8
    ctx->r2 = ADD32(0, 0X1B8);
    // addiu       $a1, $zero, 0x398
    ctx->r5 = ADD32(0, 0X398);
    // sh          $v0, 0x6($s4)
    MEM_H(0X6, ctx->r20) = ctx->r2;
    // sh          $v0, 0xA($s4)
    MEM_H(0XA, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x1D0
    ctx->r2 = ADD32(0, 0X1D0);
    // sh          $v0, 0xE($s4)
    MEM_H(0XE, ctx->r20) = ctx->r2;
    // sh          $v0, 0x12($s4)
    MEM_H(0X12, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x1E8
    ctx->r2 = ADD32(0, 0X1E8);
    // sh          $v1, 0x4($s4)
    MEM_H(0X4, ctx->r20) = ctx->r3;
    // sh          $a1, 0x8($s4)
    MEM_H(0X8, ctx->r20) = ctx->r5;
    // sh          $v1, 0xC($s4)
    MEM_H(0XC, ctx->r20) = ctx->r3;
    // sh          $a1, 0x10($s4)
    MEM_H(0X10, ctx->r20) = ctx->r5;
    // sh          $v1, 0x14($s4)
    MEM_H(0X14, ctx->r20) = ctx->r3;
    // jal         0x800152D0
    // sh          $v0, 0x16($s4)
    MEM_H(0X16, ctx->r20) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x16($s4)
    MEM_H(0X16, ctx->r20) = ctx->r2;
    after_1:
    // lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // addiu       $s0, $s1, -0x7378
    ctx->r16 = ADD32(ctx->r17, -0X7378);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x80016030
    // sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    sub_80016030(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    after_2:
    // addiu       $s2, $s0, 0x4
    ctx->r18 = ADD32(ctx->r16, 0X4);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    // lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(0X0, ctx->r20);
    // jal         0x80014CFC
    // addiu       $s3, $zero, 0x10C
    ctx->r19 = ADD32(0, 0X10C);
    sub_80014CFC(rdram, ctx);
    goto after_3;
    // addiu       $s3, $zero, 0x10C
    ctx->r19 = ADD32(0, 0X10C);
    after_3:
    // ori         $a1, $s4, 0x2EE
    ctx->r5 = ctx->r20 | 0X2EE;
    // ori         $a2, $s4, 0x2F2
    ctx->r6 = ctx->r20 | 0X2F2;
    // lw          $v0, -0x7378($s1)
    ctx->r2 = MEM_W(-0X7378, ctx->r17);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $v0, $s0
    ctx->r16 = ADD32(ctx->r2, ctx->r16);
    // jal         0x8003EC5C
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    sub_8003EC5C(rdram, ctx);
    goto after_4;
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_4:
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    // addiu       $s1, $s1, -0x7378
    ctx->r17 = ADD32(ctx->r17, -0X7378);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // jal         0x80016030
    // sw          $a2, -0x8($s2)
    MEM_W(-0X8, ctx->r18) = ctx->r6;
    sub_80016030(rdram, ctx);
    goto after_5;
    // sw          $a2, -0x8($s2)
    MEM_W(-0X8, ctx->r18) = ctx->r6;
    after_5:
    // jal         0x800152D0
    // addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    sub_800152D0(rdram, ctx);
    goto after_6;
    // addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    after_6:
    // addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $a1, $v1, 0x7590
    ctx->r5 = ADD32(ctx->r3, 0X7590);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x76F8
    ctx->r3 = ADD32(ctx->r3, 0X76F8);
    // addiu       $a0, $v1, 0x2E10
    ctx->r4 = ADD32(ctx->r3, 0X2E10);
    // sw          $v0, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->r2;
    // sh          $zero, 0x18($s4)
    MEM_H(0X18, ctx->r20) = 0;
L_8005EDCC:
    // lbu         $v0, 0x13E($a0)
    ctx->r2 = MEM_BU(0X13E, ctx->r4);
    // nop

    // beq         $v0, $a3, L_8005EDE4
    if (ctx->r2 == ctx->r7) {
        // nop
    
        goto L_8005EDE4;
    }
    // nop

    // bne         $v0, $a2, L_8005EE28
    if (ctx->r2 != ctx->r6) {
        // nop
    
        goto L_8005EE28;
    }
    // nop

L_8005EDE4:
    // addu        $v0, $s3, $a1
    ctx->r2 = ADD32(ctx->r19, ctx->r5);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 & 0X7F;
    // beq         $v0, $zero, L_8005EE28
    if (ctx->r2 == 0) {
        // srl         $v0, $v1, 7
        ctx->r2 = S32(U32(ctx->r3) >> 7);
        goto L_8005EE28;
    }
    // srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
    // bne         $v0, $zero, L_8005EE28
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005EE28;
    }
    // nop

    // lhu         $v0, 0x18($s4)
    ctx->r2 = MEM_HU(0X18, ctx->r20);
    // nop

    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sh          $v1, 0x18($s4)
    MEM_H(0X18, ctx->r20) = ctx->r3;
    // lw          $v1, 0x1C($s4)
    ctx->r3 = MEM_W(0X1C, ctx->r20);
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $s3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r19;
L_8005EE28:
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // slti        $v0, $s3, 0x13A
    ctx->r2 = SIGNED(ctx->r19) < 0X13A ? 1 : 0;
    // bne         $v0, $zero, L_8005EDCC
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x2C
        ctx->r4 = ADD32(ctx->r4, 0X2C);
        goto L_8005EDCC;
    }
    // addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    // lhu         $v0, 0x18($s4)
    ctx->r2 = MEM_HU(0X18, ctx->r20);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_8005EE58
    if (ctx->r2 == 0) {
        // addiu       $s1, $zero, 0x5
        ctx->r17 = ADD32(0, 0X5);
        goto L_8005EE58;
    }
    // addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_8005EE58:
    // blez        $s1, L_8005EEE8
    if (SIGNED(ctx->r17) <= 0) {
        // addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
        goto L_8005EEE8;
    }
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
    // addu        $s0, $s4, $zero
    ctx->r16 = ADD32(ctx->r20, 0);
L_8005EE68:
    // lw          $v1, 0x1C($s4)
    ctx->r3 = MEM_W(0X1C, ctx->r20);
    // sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
    // nop

    // addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // lbu         $v1, -0xFA($v0)
    ctx->r3 = MEM_BU(-0XFA, ctx->r2);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a1, $v0, -0x7378
    ctx->r5 = ADD32(ctx->r2, -0X7378);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // beq         $v1, $v0, L_8005EEB0
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8005EEB0;
    }
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8005EE9C:
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // bne         $v1, $a0, L_8005EE9C
    if (ctx->r3 != ctx->r4) {
        // addu        $a1, $a1, $v0
        ctx->r5 = ADD32(ctx->r5, ctx->r2);
        goto L_8005EE9C;
    }
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
L_8005EEB0:
    // addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(0X4, ctx->r16);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // sh          $s2, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r18;
    // sh          $s2, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r18;
    // jal         0x80079D0C
    // sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    LoadImage(rdram, ctx);
    goto after_7;
    // sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    after_7:
    // slt         $v0, $s3, $s1
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r17) ? 1 : 0;
    // bne         $v0, $zero, L_8005EE68
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005EE68;
    }
    // nop

L_8005EEE8:
    // sh          $zero, 0x2E2($s4)
    MEM_H(0X2E2, ctx->r20) = 0;
    // jal         0x80057A3C
    // sh          $zero, 0x2E0($s4)
    MEM_H(0X2E0, ctx->r20) = 0;
    sub_80057A3C(rdram, ctx);
    goto after_8;
    // sh          $zero, 0x2E0($s4)
    MEM_H(0X2E0, ctx->r20) = 0;
    after_8:
    // addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s7, $v0, -0x45F8
    ctx->r23 = ADD32(ctx->r2, -0X45F8);
    // lui         $s5, 0x801D
    ctx->r21 = S32(0X801D << 16);
    // addiu       $s2, $s5, -0x2E80
    ctx->r18 = ADD32(ctx->r21, -0X2E80);
    // addiu       $s6, $zero, 0x18
    ctx->r22 = ADD32(0, 0X18);
L_8005EF0C:
    // lhu         $v0, 0x2E2($s4)
    ctx->r2 = MEM_HU(0X2E2, ctx->r20);
    // lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(0X4, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // andi        $v1, $v1, 0x4000
    ctx->r3 = ctx->r3 & 0X4000;
    // beq         $v1, $zero, L_8005F028
    if (ctx->r3 == 0) {
        // sra         $s1, $v0, 16
        ctx->r17 = S32(ctx->r2) >> 16;
        goto L_8005F028;
    }
    // sra         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2) >> 16;
    // lhu         $a0, 0x2E2($s4)
    ctx->r4 = MEM_HU(0X2E2, ctx->r20);
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // lhu         $v1, 0x2E0($s4)
    ctx->r3 = MEM_HU(0X2E0, ctx->r20);
    // lhu         $v0, 0x18($s4)
    ctx->r2 = MEM_HU(0X18, ctx->r20);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8005EF7C
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4) << 1;
        goto L_8005EF7C;
    }
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // lw          $v1, 0x1C($s4)
    ctx->r3 = MEM_W(0X1C, ctx->r20);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $a0, 0x0($v0)
    ctx->r4 = MEM_HS(0X0, ctx->r2);
    // jal         0x80054A54
    // nop

    sub_80054A54(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // j           L_8005EF84
    // nop

    goto L_8005EF84;
    // nop

L_8005EF7C:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sw          $v0, 0x16D8($s7)
    MEM_W(0X16D8, ctx->r23) = ctx->r2;
L_8005EF84:
    // lw          $v1, 0x16D8($s7)
    ctx->r3 = MEM_W(0X16D8, ctx->r23);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8005EFA4
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8005EFA4;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // j           L_8005EFC4
    // nop

    goto L_8005EFC4;
    // nop

L_8005EFA4:
    // bne         $v1, $v0, L_8005EFBC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005EFBC;
    }
    // nop

    // jal         0x80057D34
    // nop

    sub_80057D34(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // j           L_8005EFC4
    // nop

    goto L_8005EFC4;
    // nop

L_8005EFBC:
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_12;
    // nop

    after_12:
L_8005EFC4:
    // lw          $v1, 0x16D8($s7)
    ctx->r3 = MEM_W(0X16D8, ctx->r23);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $v1, $v0, L_8005F028
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8005F028;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8005F2D8
    if (ctx->r3 != ctx->r2) {
        // sw          $v1, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r3;
        goto L_8005F2D8;
    }
    // sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // lhu         $v0, 0x2E2($s4)
    ctx->r2 = MEM_HU(0X2E2, ctx->r20);
    // lhu         $v1, 0x2E0($s4)
    ctx->r3 = MEM_HU(0X2E0, ctx->r20);
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
    // lw          $v1, 0x1C($s4)
    ctx->r3 = MEM_W(0X1C, ctx->r20);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // nop

    // slti        $v0, $v1, 0x136
    ctx->r2 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // beq         $v0, $zero, L_8005F020
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x120
        ctx->r2 = ADD32(0, 0X120);
        goto L_8005F020;
    }
    // addiu       $v0, $zero, 0x120
    ctx->r2 = ADD32(0, 0X120);
    // bne         $v1, $v0, L_8005F2D8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005F2D8;
    }
    // nop

L_8005F020:
    // j           L_8005F2D8
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    goto L_8005F2D8;
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_8005F028:
    // lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(0X4, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // bne         $v0, $zero, L_8005ECB0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005ECB0;
    }
    // nop

    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8005F094
    if (ctx->r2 == 0) {
        // addiu       $s0, $s5, -0x2E80
        ctx->r16 = ADD32(ctx->r21, -0X2E80);
        goto L_8005F094;
    }
    // addiu       $s0, $s5, -0x2E80
    ctx->r16 = ADD32(ctx->r21, -0X2E80);
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // lhu         $v0, 0x2E0($s4)
    ctx->r2 = MEM_HU(0X2E0, ctx->r20);
    // nop

    // bne         $v0, $zero, L_8005F084
    if (ctx->r2 != 0) {
        // sh          $zero, 0xC($s2)
        MEM_H(0XC, ctx->r18) = 0;
        goto L_8005F084;
    }
    // sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
    // lhu         $v1, 0x2E2($s4)
    ctx->r3 = MEM_HU(0X2E2, ctx->r20);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // blez        $v0, L_8005F08C
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8005F08C;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // j           L_8005F08C
    // sh          $v0, 0x2E2($s4)
    MEM_H(0X2E2, ctx->r20) = ctx->r2;
    goto L_8005F08C;
    // sh          $v0, 0x2E2($s4)
    MEM_H(0X2E2, ctx->r20) = ctx->r2;
L_8005F084:
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x2E0($s4)
    MEM_H(0X2E0, ctx->r20) = ctx->r2;
L_8005F08C:
    // sb          $zero, 0x2E4($s4)
    MEM_B(0X2E4, ctx->r20) = 0;
    // addiu       $s0, $s5, -0x2E80
    ctx->r16 = ADD32(ctx->r21, -0X2E80);
L_8005F094:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_8005F104
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005F104;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // lhu         $a0, 0x2E0($s4)
    ctx->r4 = MEM_HU(0X2E0, ctx->r20);
    // addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_8005F0F8
    if (ctx->r2 != ctx->r3) {
        // sh          $zero, 0xC($s0)
        MEM_H(0XC, ctx->r16) = 0;
        goto L_8005F0F8;
    }
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // lhu         $a0, 0x2E2($s4)
    ctx->r4 = MEM_HU(0X2E2, ctx->r20);
    // lhu         $v0, 0x18($s4)
    ctx->r2 = MEM_HU(0X18, ctx->r20);
    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8005F100
    if (ctx->r3 == 0) {
        // addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
        goto L_8005F100;
    }
    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // j           L_8005F100
    // sh          $v0, 0x2E2($s4)
    MEM_H(0X2E2, ctx->r20) = ctx->r2;
    goto L_8005F100;
    // sh          $v0, 0x2E2($s4)
    MEM_H(0X2E2, ctx->r20) = ctx->r2;
L_8005F0F8:
    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // sh          $v0, 0x2E0($s4)
    MEM_H(0X2E0, ctx->r20) = ctx->r2;
L_8005F100:
    // sb          $zero, 0x2E4($s4)
    MEM_B(0X2E4, ctx->r20) = 0;
L_8005F104:
    // addiu       $s0, $s5, -0x2E80
    ctx->r16 = ADD32(ctx->r21, -0X2E80);
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_8005F174
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005F174;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // lhu         $v1, 0x2E2($s4)
    ctx->r3 = MEM_HU(0X2E2, ctx->r20);
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // lhu         $a1, 0x18($s4)
    ctx->r5 = MEM_HU(0X18, ctx->r20);
    // addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
    // sh          $v1, 0x2E2($s4)
    MEM_H(0X2E2, ctx->r20) = ctx->r3;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // addiu       $v0, $a0, -0x5
    ctx->r2 = ADD32(ctx->r4, -0X5);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8005F16C
    if (ctx->r2 == 0) {
        // slti        $v0, $a0, 0x5
        ctx->r2 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
        goto L_8005F16C;
    }
    // slti        $v0, $a0, 0x5
    ctx->r2 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_8005F168
    if (ctx->r2 == 0) {
        // addiu       $v0, $a1, -0x5
        ctx->r2 = ADD32(ctx->r5, -0X5);
        goto L_8005F168;
    }
    // addiu       $v0, $a1, -0x5
    ctx->r2 = ADD32(ctx->r5, -0X5);
    // j           L_8005F16C
    // sh          $zero, 0x2E2($s4)
    MEM_H(0X2E2, ctx->r20) = 0;
    goto L_8005F16C;
    // sh          $zero, 0x2E2($s4)
    MEM_H(0X2E2, ctx->r20) = 0;
L_8005F168:
    // sh          $v0, 0x2E2($s4)
    MEM_H(0X2E2, ctx->r20) = ctx->r2;
L_8005F16C:
    // sb          $zero, 0x2E4($s4)
    MEM_B(0X2E4, ctx->r20) = 0;
    // addiu       $s0, $s5, -0x2E80
    ctx->r16 = ADD32(ctx->r21, -0X2E80);
L_8005F174:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8005F1B4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005F1B4;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // lhu         $v0, 0x2E2($s4)
    ctx->r2 = MEM_HU(0X2E2, ctx->r20);
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // sh          $v0, 0x2E2($s4)
    MEM_H(0X2E2, ctx->r20) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_8005F1B0
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8005F1B0;
    }
    // nop

    // sh          $zero, 0x2E2($s4)
    MEM_H(0X2E2, ctx->r20) = 0;
L_8005F1B0:
    // sb          $zero, 0x2E4($s4)
    MEM_B(0X2E4, ctx->r20) = 0;
L_8005F1B4:
    // lhu         $v0, 0x2E2($s4)
    ctx->r2 = MEM_HU(0X2E2, ctx->r20);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // beq         $v1, $s1, L_8005F2A0
    if (ctx->r3 == ctx->r17) {
        // slt         $v0, $s1, $v1
        ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_8005F2A0;
    }
    // slt         $v0, $s1, $v1
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8005F1DC
    if (ctx->r2 == 0) {
        // addiu       $v0, $s1, 0x5
        ctx->r2 = ADD32(ctx->r17, 0X5);
        goto L_8005F1DC;
    }
    // addiu       $v0, $s1, 0x5
    ctx->r2 = ADD32(ctx->r17, 0X5);
    // j           L_8005F1E4
    // addiu       $s0, $v1, 0x5
    ctx->r16 = ADD32(ctx->r3, 0X5);
    goto L_8005F1E4;
    // addiu       $s0, $v1, 0x5
    ctx->r16 = ADD32(ctx->r3, 0X5);
L_8005F1DC:
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
L_8005F1E4:
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // slt         $v0, $s3, $s0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r16) ? 1 : 0;
    // beq         $v0, $zero, L_8005F2A0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005F2A0;
    }
    // nop

L_8005F1F4:
    // lw          $v1, 0x1C($s4)
    ctx->r3 = MEM_W(0X1C, ctx->r20);
    // sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
    // nop

    // addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // lbu         $v1, -0xFA($v0)
    ctx->r3 = MEM_BU(-0XFA, ctx->r2);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a1, $v0, -0x7378
    ctx->r5 = ADD32(ctx->r2, -0X7378);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // beq         $v1, $v0, L_8005F23C
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8005F23C;
    }
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8005F228:
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // bne         $v1, $a0, L_8005F228
    if (ctx->r3 != ctx->r4) {
        // addu        $a1, $a1, $v0
        ctx->r5 = ADD32(ctx->r5, ctx->r2);
        goto L_8005F228;
    }
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
L_8005F23C:
    // lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // mult        $s3, $v0
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // sra         $v0, $s3, 31
    ctx->r2 = S32(ctx->r19) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v1, $t1, 1
    ctx->r3 = S32(ctx->r9) >> 1;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $v0, $s3, $v0
    ctx->r2 = SUB32(ctx->r19, ctx->r2);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(0X4, ctx->r2);
    // addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // sh          $v1, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r3;
    // lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(0X6, ctx->r2);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // sh          $s6, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r22;
    // sh          $s6, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r22;
    // jal         0x80079D0C
    // sh          $v0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r2;
    LoadImage(rdram, ctx);
    goto after_17;
    // sh          $v0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r2;
    after_17:
    // slt         $v0, $s3, $s0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r16) ? 1 : 0;
    // bne         $v0, $zero, L_8005F1F4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005F1F4;
    }
    // nop

L_8005F2A0:
    // jal         0x800164B4
    // nop

    sub_800164B4(rdram, ctx);
    goto after_18;
    // nop

    after_18:
    // jal         0x8002A1D0
    // nop

    sub_8002A1D0(rdram, ctx);
    goto after_19;
    // nop

    after_19:
    // lbu         $a0, 0x2E4($s4)
    ctx->r4 = MEM_BU(0X2E4, ctx->r20);
    // nop

    // addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // bgez        $v1, L_8005F2C8
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005F2C8;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_8005F2C8:
    // andi        $v0, $v0, 0x1E0
    ctx->r2 = ctx->r2 & 0X1E0;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // j           L_8005EF0C
    // sb          $v0, 0x2E4($s4)
    MEM_B(0X2E4, ctx->r20) = ctx->r2;
    goto L_8005EF0C;
    // sb          $v0, 0x2E4($s4)
    MEM_B(0X2E4, ctx->r20) = ctx->r2;
L_8005F2D8:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_20;
    // nop

    after_20:
    // lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(0X0, ctx->r20);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_21;
    // nop

    after_21:
    // lw          $a0, 0x1C($s4)
    ctx->r4 = MEM_W(0X1C, ctx->r20);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_22;
    // nop

    after_22:
    // beq         $fp, $zero, L_8005F30C
    if (ctx->r30 == 0) {
        // lui         $s1, 0x8009
        ctx->r17 = S32(0X8009 << 16);
        goto L_8005F30C;
    }
    // lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // jal         0x8005A3A8
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8005A3A8(rdram, ctx);
    goto after_23;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_23:
    // lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
L_8005F30C:
    // addiu       $s0, $s1, -0x7378
    ctx->r16 = ADD32(ctx->r17, -0X7378);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_24;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_24:
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x8003EC5C
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    sub_8003EC5C(rdram, ctx);
    goto after_25;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_25:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // lw          $v0, -0x7378($s1)
    ctx->r2 = MEM_W(-0X7378, ctx->r17);
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $v0, $s0
    ctx->r16 = ADD32(ctx->r2, ctx->r16);
    // jal         0x8003EC5C
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    sub_8003EC5C(rdram, ctx);
    goto after_26;
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_26:
    // lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(0X50, ctx->r29);
    // lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(0X7C, ctx->r29);
    // lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(0X78, ctx->r29);
    // lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(0X74, ctx->r29);
    // lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(0X70, ctx->r29);
    // lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(0X6C, ctx->r29);
    // lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(0X68, ctx->r29);
    // lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(0X64, ctx->r29);
    // lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(0X60, ctx->r29);
    // lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(0X5C, ctx->r29);
    // lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(0X58, ctx->r29);
    // addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // jr          $ra
    // nop

    return;
    // nop

;}
