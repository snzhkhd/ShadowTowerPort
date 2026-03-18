#include "recomp.h"
#include "disable_warnings.h"

void sub_80060334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sh          $zero, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = 0;
    // jal         0x80057A3C
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
    sub_80057A3C(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
    after_0:
    // addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s2, $v0, -0x2E80
    ctx->r18 = ADD32(ctx->r2, -0X2E80);
    // addiu       $s6, $zero, 0x5
    ctx->r22 = ADD32(0, 0X5);
    // addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // addiu       $s5, $zero, 0xD
    ctx->r21 = ADD32(0, 0XD);
L_80060384:
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // nop

    // bne         $v0, $s4, L_80060610
    if (ctx->r2 != ctx->r20) {
        // nop
    
        goto L_80060610;
    }
    // nop

    // lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(0X4, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // beq         $v0, $zero, L_800603B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800603B8;
    }
    // nop

    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_80060B78
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    goto L_80060B78;
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
L_800603B8:
    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_800603F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800603F4;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // bne         $v0, $zero, L_800603EC
    if (ctx->r2 != 0) {
        // sh          $zero, 0xC($s2)
        MEM_H(0XC, ctx->r18) = 0;
        goto L_800603EC;
    }
    // sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
    // j           L_800603F4
    // sh          $s6, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r22;
    goto L_800603F4;
    // sh          $s6, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r22;
L_800603EC:
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_800603F4:
    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_80060438
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80060438;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lhu         $v1, 0x2E0($s0)
    ctx->r3 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $s6, L_80060430
    if (ctx->r2 != ctx->r22) {
        // sh          $zero, 0xC($s2)
        MEM_H(0XC, ctx->r18) = 0;
        goto L_80060430;
    }
    // sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
    // j           L_80060438
    // sh          $zero, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = 0;
    goto L_80060438;
    // sh          $zero, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = 0;
L_80060430:
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_80060438:
    // lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(0X4, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // beq         $v0, $zero, L_80060548
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80060548;
    }
    // nop

    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $s6, L_80060548
    if (ctx->r2 != ctx->r22) {
        // sh          $zero, 0x4($s2)
        MEM_H(0X4, ctx->r18) = 0;
        goto L_80060548;
    }
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // jal         0x80057CC8
    // addiu       $s1, $s2, 0x22
    ctx->r17 = ADD32(ctx->r18, 0X22);
    sub_80057CC8(rdram, ctx);
    goto after_4;
    // addiu       $s1, $s2, 0x22
    ctx->r17 = ADD32(ctx->r18, 0X22);
    after_4:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80060474:
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // nop

    // andi        $v0, $v1, 0x1000
    ctx->r2 = ctx->r3 & 0X1000;
    // beq         $v0, $zero, L_80060490
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x2000
        ctx->r2 = ctx->r3 & 0X2000;
        goto L_80060490;
    }
    // andi        $v0, $v1, 0x2000
    ctx->r2 = ctx->r3 & 0X2000;
    // j           L_80060520
    // sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    goto L_80060520;
    // sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
L_80060490:
    // beq         $v0, $zero, L_800604A0
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x8000
        ctx->r2 = ctx->r3 & 0X8000;
        goto L_800604A0;
    }
    // andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // j           L_80060520
    // sb          $s4, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r20;
    goto L_80060520;
    // sb          $s4, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r20;
L_800604A0:
    // bne         $v0, $zero, L_8006051C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8006051C;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // andi        $v0, $v1, 0x4000
    ctx->r2 = ctx->r3 & 0X4000;
    // bne         $v0, $zero, L_8006051C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8006051C;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // bne         $v0, $zero, L_8006051C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_8006051C;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // bne         $v0, $zero, L_8006051C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_8006051C;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // bne         $v0, $zero, L_8006051C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
        goto L_8006051C;
    }
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // bne         $v0, $zero, L_8006051C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
        goto L_8006051C;
    }
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // bne         $v0, $zero, L_8006051C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_8006051C;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // bne         $v0, $zero, L_8006051C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
        goto L_8006051C;
    }
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // nop

    // andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // bne         $v0, $zero, L_8006051C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
        goto L_8006051C;
    }
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // beq         $v0, $zero, L_80060520
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
        goto L_80060520;
    }
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_8006051C:
    // sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
L_80060520:
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0xC
    ctx->r2 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // bne         $v0, $zero, L_80060474
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
        goto L_80060474;
    }
    // addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sh          $zero, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = 0;
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
    // sh          $zero, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = 0;
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_80060548:
    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_800605AC
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_800605AC;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // jal         0x80057D10
    // addiu       $s1, $v0, -0x2EDF
    ctx->r17 = ADD32(ctx->r2, -0X2EDF);
    sub_80057D10(rdram, ctx);
    goto after_5;
    // addiu       $s1, $v0, -0x2EDF
    ctx->r17 = ADD32(ctx->r2, -0X2EDF);
    after_5:
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bgtz        $v1, L_8006059C
    if (SIGNED(ctx->r3) > 0) {
        // sh          $zero, 0xC($s2)
        MEM_H(0XC, ctx->r18) = 0;
        goto L_8006059C;
    }
    // sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
    // addu        $a0, $v1, $s1
    ctx->r4 = ADD32(ctx->r3, ctx->r17);
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // nop

    // sltiu       $v0, $v1, 0x3F
    ctx->r2 = ctx->r3 < 0X3F ? 1 : 0;
    // beq         $v0, $zero, L_800605AC
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_800605AC;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // j           L_800605AC
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    goto L_800605AC;
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
L_8006059C:
    // slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_800605AC
    if (ctx->r2 == 0) {
        // addu        $v0, $v1, $s1
        ctx->r2 = ADD32(ctx->r3, ctx->r17);
        goto L_800605AC;
    }
    // addu        $v0, $v1, $s1
    ctx->r2 = ADD32(ctx->r3, ctx->r17);
    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_800605AC:
    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_80060B20
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80060B20;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // jal         0x80057D10
    // addiu       $s1, $v0, -0x2EDF
    ctx->r17 = ADD32(ctx->r2, -0X2EDF);
    sub_80057D10(rdram, ctx);
    goto after_6;
    // addiu       $s1, $v0, -0x2EDF
    ctx->r17 = ADD32(ctx->r2, -0X2EDF);
    after_6:
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bgtz        $v1, L_800605FC
    if (SIGNED(ctx->r3) > 0) {
        // sh          $zero, 0xC($s2)
        MEM_H(0XC, ctx->r18) = 0;
        goto L_800605FC;
    }
    // sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
    // addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80060B20
    if (ctx->r2 == 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80060B20;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // j           L_80060B20
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    goto L_80060B20;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_800605FC:
    // slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_80060B20
    if (ctx->r2 == 0) {
        // addu        $v0, $v1, $s1
        ctx->r2 = ADD32(ctx->r3, ctx->r17);
        goto L_80060B20;
    }
    // addu        $v0, $v1, $s1
    ctx->r2 = ADD32(ctx->r3, ctx->r17);
    // j           L_80060B20
    // sb          $s4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r20;
    goto L_80060B20;
    // sb          $s4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r20;
L_80060610:
    // lhu         $v0, 0x2E2($s0)
    ctx->r2 = MEM_HU(0X2E2, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80060928
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80060928;
    }
    // nop

    // lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(0X4, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // beq         $v0, $zero, L_80060674
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80060674;
    }
    // nop

    // lh          $v0, 0x0($s0)
    ctx->r2 = MEM_HS(0X0, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80060668
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80060668;
    }
    // nop

    // jal         0x8005738C
    // nop

    sub_8005738C(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // sh          $s4, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r20;
    // j           L_80060674
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
    goto L_80060674;
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_80060668:
    // jal         0x80057D34
    // nop

    sub_80057D34(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
L_80060674:
    // lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(0X4, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // beq         $v0, $zero, L_80060778
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80060778;
    }
    // nop

    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0xC
    ctx->r2 = SIGNED(ctx->r3) < 0XC ? 1 : 0;
    // beq         $v0, $zero, L_800606B8
    if (ctx->r2 == 0) {
        // sh          $zero, 0x4($s2)
        MEM_H(0X4, ctx->r18) = 0;
        goto L_800606B8;
    }
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // sb          $zero, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = 0;
    // j           L_80060778
    // sh          $s4, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = ctx->r20;
    goto L_80060778;
    // sh          $s4, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = ctx->r20;
L_800606B8:
    // bne         $v1, $s3, L_80060738
    if (ctx->r3 != ctx->r19) {
        // nop
    
        goto L_80060738;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // jal         0x800573BC
    // nop

    sub_800573BC(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // jal         0x8005738C
    // nop

    sub_8005738C(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // sb          $v0, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
    // sb          $s4, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r20;
    // j           L_80060778
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    goto L_80060778;
    // sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
L_80060738:
    // lh          $v0, 0x0($s0)
    ctx->r2 = MEM_HS(0X0, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8006076C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006076C;
    }
    // nop

    // jal         0x8005738C
    // nop

    sub_8005738C(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // sh          $s4, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r20;
    // j           L_80060778
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
    goto L_80060778;
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_8006076C:
    // jal         0x80057D34
    // nop

    sub_80057D34(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
L_80060778:
    // lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(0X4, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // beq         $v0, $zero, L_8006079C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006079C;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // sh          $s5, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r21;
L_8006079C:
    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_800607FC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800607FC;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_18;
    // nop

    after_18:
    // lhu         $a0, 0x2E0($s0)
    ctx->r4 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bne         $v1, $zero, L_800607D8
    if (ctx->r3 != 0) {
        // sh          $zero, 0xC($s2)
        MEM_H(0XC, ctx->r18) = 0;
        goto L_800607D8;
    }
    // sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
    // j           L_800607FC
    // sh          $s3, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r19;
    goto L_800607FC;
    // sh          $s3, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r19;
L_800607D8:
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // beq         $v1, $v0, L_800607F8
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
        goto L_800607F8;
    }
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // beq         $v1, $s3, L_800607F8
    if (ctx->r3 == ctx->r19) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_800607F8;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bne         $v1, $s5, L_800607F8
    if (ctx->r3 != ctx->r21) {
        // addiu       $v0, $a0, -0x1
        ctx->r2 = ADD32(ctx->r4, -0X1);
        goto L_800607F8;
    }
    // addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_800607F8:
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_800607FC:
    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_80060860
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80060860;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_19;
    // nop

    after_19:
    // lhu         $a0, 0x2E0($s0)
    ctx->r4 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bne         $v1, $s3, L_80060838
    if (ctx->r3 != ctx->r19) {
        // sh          $zero, 0xC($s2)
        MEM_H(0XC, ctx->r18) = 0;
        goto L_80060838;
    }
    // sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
    // j           L_80060860
    // sh          $zero, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = 0;
    goto L_80060860;
    // sh          $zero, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = 0;
L_80060838:
    // bne         $v1, $s6, L_80060848
    if (ctx->r3 != ctx->r22) {
        // addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
        goto L_80060848;
    }
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // j           L_80060860
    // sh          $s3, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r19;
    goto L_80060860;
    // sh          $s3, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r19;
L_80060848:
    // beq         $v1, $v0, L_8006085C
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
        goto L_8006085C;
    }
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // bne         $v1, $s5, L_8006085C
    if (ctx->r3 != ctx->r21) {
        // addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
        goto L_8006085C;
    }
    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8006085C:
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_80060860:
    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_800608BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800608BC;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_20;
    // nop

    after_20:
    // lhu         $a0, 0x2E0($s0)
    ctx->r4 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0x6
    ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_800608A0
    if (ctx->r2 == 0) {
        // sh          $zero, 0xC($s2)
        MEM_H(0XC, ctx->r18) = 0;
        goto L_800608A0;
    }
    // sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
    // j           L_800608B8
    // addiu       $v0, $a0, 0x6
    ctx->r2 = ADD32(ctx->r4, 0X6);
    goto L_800608B8;
    // addiu       $v0, $a0, 0x6
    ctx->r2 = ADD32(ctx->r4, 0X6);
L_800608A0:
    // beq         $v1, $s3, L_800608B8
    if (ctx->r3 == ctx->r19) {
        // addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
        goto L_800608B8;
    }
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // bne         $v1, $s5, L_800608B8
    if (ctx->r3 != ctx->r21) {
        // addiu       $v0, $a0, -0x6
        ctx->r2 = ADD32(ctx->r4, -0X6);
        goto L_800608B8;
    }
    // addiu       $v0, $a0, -0x6
    ctx->r2 = ADD32(ctx->r4, -0X6);
    // j           L_800608BC
    // sh          $s3, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r19;
    goto L_800608BC;
    // sh          $s3, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r19;
L_800608B8:
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_800608BC:
    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_80060B20
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80060B20;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_21;
    // nop

    after_21:
    // lhu         $a0, 0x2E0($s0)
    ctx->r4 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0x7
    ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_80060900
    if (ctx->r2 == 0) {
        // sh          $zero, 0xC($s2)
        MEM_H(0XC, ctx->r18) = 0;
        goto L_80060900;
    }
    // sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
    // addiu       $v0, $a0, 0x6
    ctx->r2 = ADD32(ctx->r4, 0X6);
    // j           L_80060B20
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
    goto L_80060B20;
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_80060900:
    // bne         $v1, $s3, L_80060910
    if (ctx->r3 != ctx->r19) {
        // addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
        goto L_80060910;
    }
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // j           L_80060B20
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
    goto L_80060B20;
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_80060910:
    // bne         $v1, $s5, L_80060920
    if (ctx->r3 != ctx->r21) {
        // addiu       $v0, $a0, -0x6
        ctx->r2 = ADD32(ctx->r4, -0X6);
        goto L_80060920;
    }
    // addiu       $v0, $a0, -0x6
    ctx->r2 = ADD32(ctx->r4, -0X6);
    // j           L_80060B20
    // sh          $s3, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r19;
    goto L_80060B20;
    // sh          $s3, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r19;
L_80060920:
    // j           L_80060B20
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
    goto L_80060B20;
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_80060928:
    // lhu         $a0, 0x4($s2)
    ctx->r4 = MEM_HU(0X4, ctx->r18);
    // nop

    // beq         $a0, $zero, L_80060B20
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80060B20;
    }
    // nop

    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5) << 1;
    // addiu       $v0, $s2, 0x22
    ctx->r2 = ADD32(ctx->r18, 0X22);
    // addu        $a2, $v1, $v0
    ctx->r6 = ADD32(ctx->r3, ctx->r2);
    // andi        $v0, $a0, 0x1000
    ctx->r2 = ctx->r4 & 0X1000;
    // beq         $v0, $zero, L_8006096C
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $a1
        ctx->r2 = ADD32(ctx->r16, ctx->r5);
        goto L_8006096C;
    }
    // addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // j           L_80060AC0
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    goto L_80060AC0;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
L_8006096C:
    // andi        $v0, $a0, 0x2000
    ctx->r2 = ctx->r4 & 0X2000;
    // beq         $v0, $zero, L_80060984
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $a1
        ctx->r2 = ADD32(ctx->r16, ctx->r5);
        goto L_80060984;
    }
    // addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // sb          $s4, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r20;
    // j           L_80060AC0
    // addiu       $v0, $zero, 0x2000
    ctx->r2 = ADD32(0, 0X2000);
    goto L_80060AC0;
    // addiu       $v0, $zero, 0x2000
    ctx->r2 = ADD32(0, 0X2000);
L_80060984:
    // andi        $v0, $a0, 0x8000
    ctx->r2 = ctx->r4 & 0X8000;
    // beq         $v0, $zero, L_800609A0
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $a1
        ctx->r2 = ADD32(ctx->r16, ctx->r5);
        goto L_800609A0;
    }
    // addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // j           L_80060AC0
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    goto L_80060AC0;
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
L_800609A0:
    // andi        $v0, $a0, 0x4000
    ctx->r2 = ctx->r4 & 0X4000;
    // beq         $v0, $zero, L_800609BC
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $a1
        ctx->r2 = ADD32(ctx->r16, ctx->r5);
        goto L_800609BC;
    }
    // addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // j           L_80060AC0
    // addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    goto L_80060AC0;
    // addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
L_800609BC:
    // andi        $v0, $a0, 0x80
    ctx->r2 = ctx->r4 & 0X80;
    // beq         $v0, $zero, L_800609D8
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $a1
        ctx->r2 = ADD32(ctx->r16, ctx->r5);
        goto L_800609D8;
    }
    // addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // j           L_80060AC0
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    goto L_80060AC0;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_800609D8:
    // andi        $v0, $a0, 0x10
    ctx->r2 = ctx->r4 & 0X10;
    // beq         $v0, $zero, L_800609F4
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $a1
        ctx->r2 = ADD32(ctx->r16, ctx->r5);
        goto L_800609F4;
    }
    // addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // j           L_80060AC0
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    goto L_80060AC0;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_800609F4:
    // andi        $v0, $a0, 0x20
    ctx->r2 = ctx->r4 & 0X20;
    // beq         $v0, $zero, L_80060A10
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $a1
        ctx->r2 = ADD32(ctx->r16, ctx->r5);
        goto L_80060A10;
    }
    // addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // j           L_80060AC0
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    goto L_80060AC0;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_80060A10:
    // andi        $v0, $a0, 0x40
    ctx->r2 = ctx->r4 & 0X40;
    // beq         $v0, $zero, L_80060A2C
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $a1
        ctx->r2 = ADD32(ctx->r16, ctx->r5);
        goto L_80060A2C;
    }
    // addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // j           L_80060AC0
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    goto L_80060AC0;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_80060A2C:
    // andi        $v0, $a0, 0x400
    ctx->r2 = ctx->r4 & 0X400;
    // beq         $v0, $zero, L_80060A48
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $a1
        ctx->r2 = ADD32(ctx->r16, ctx->r5);
        goto L_80060A48;
    }
    // addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // j           L_80060AC0
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    goto L_80060AC0;
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
L_80060A48:
    // andi        $v0, $a0, 0x100
    ctx->r2 = ctx->r4 & 0X100;
    // beq         $v0, $zero, L_80060A64
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $a1
        ctx->r2 = ADD32(ctx->r16, ctx->r5);
        goto L_80060A64;
    }
    // addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // j           L_80060AC0
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    goto L_80060AC0;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
L_80060A64:
    // lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(0X4, ctx->r18);
    // nop

    // andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // beq         $v0, $zero, L_80060A98
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80060A98;
    }
    // nop

    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // j           L_80060AC0
    // addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    goto L_80060AC0;
    // addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
L_80060A98:
    // andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // beq         $v0, $zero, L_80060AC4
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0xB
        ctx->r3 = ADD32(0, 0XB);
        goto L_80060AC4;
    }
    // addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
L_80060AC0:
    // sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
L_80060AC4:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a2, $v0, -0x2E5E
    ctx->r6 = ADD32(ctx->r2, -0X2E5E);
    // addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80060AD8:
    // lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(0X0, ctx->r6);
    // nop

    // and         $v0, $v1, $a1
    ctx->r2 = ctx->r3 & ctx->r5;
    // beq         $v0, $zero, L_80060B00
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80060B00;
    }
    // nop

    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // j           L_80060B04
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    goto L_80060B04;
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_80060B00:
    // or          $a1, $a1, $v1
    ctx->r5 = ctx->r5 | ctx->r3;
L_80060B04:
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v0, $a0, 0xC
    ctx->r2 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
    // bne         $v0, $zero, L_80060AD8
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_80060AD8;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
    // sh          $zero, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = 0;
L_80060B20:
    // jal         0x800164B4
    // nop

    sub_800164B4(rdram, ctx);
    goto after_22;
    // nop

    after_22:
    // lhu         $v1, 0x2DC($s0)
    ctx->r3 = MEM_HU(0X2DC, ctx->r16);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_80060B48
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80060B48;
    }
    // nop

    // jal         0x8002B84C
    // nop

    sub_8002B84C(rdram, ctx);
    goto after_23;
    // nop

    after_23:
    // j           L_80060B50
    // nop

    goto L_80060B50;
    // nop

L_80060B48:
    // jal         0x8002B2E8
    // nop

    sub_8002B2E8(rdram, ctx);
    goto after_24;
    // nop

    after_24:
L_80060B50:
    // lbu         $a0, 0x2E4($s0)
    ctx->r4 = MEM_BU(0X2E4, ctx->r16);
    // nop

    // addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // bgez        $v1, L_80060B68
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80060B68;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_80060B68:
    // andi        $v0, $v0, 0x1E0
    ctx->r2 = ctx->r2 & 0X1E0;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // j           L_80060384
    // sb          $v0, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = ctx->r2;
    goto L_80060384;
    // sb          $v0, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = ctx->r2;
L_80060B78:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_25;
    // nop

    after_25:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
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
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
