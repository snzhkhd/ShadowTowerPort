#include "recomp.h"
#include "disable_warnings.h"

void sub_80060018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // sw          $s1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r17;
    // lui         $s1, 0x1F80
    ctx->r17 = S32(0X1F80 << 16);
    // addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x29DC
    ctx->r6 = ADD32(ctx->r2, 0X29DC);
    // addiu       $t0, $a2, 0x80
    ctx->r8 = ADD32(ctx->r6, 0X80);
    // sw          $ra, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r31;
    // sw          $s3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r19;
    // sw          $s2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r18;
    // sw          $s0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r16;
L_80060044:
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
    // bne         $a2, $t0, L_80060044
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_80060044;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // jal         0x80057A3C
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    sub_80057A3C(rdram, ctx);
    goto after_0;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_0:
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addiu       $t3, $zero, 0x63
    ctx->r11 = ADD32(0, 0X63);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $t2, $v0, -0x45F8
    ctx->r10 = ADD32(ctx->r2, -0X45F8);
    // addiu       $t1, $zero, 0x59
    ctx->r9 = ADD32(0, 0X59);
    // addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $a3, $v0, 0x5920
    ctx->r7 = ADD32(ctx->r2, 0X5920);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a2, $sp, 0x9C
    ctx->r6 = ADD32(ctx->r29, 0X9C);
    // addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
L_800600C4:
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // slti        $v0, $v1, 0x5A
    ctx->r2 = SIGNED(ctx->r3) < 0X5A ? 1 : 0;
    // bne         $v0, $zero, L_800600F8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800600F8;
    }
    // nop

    // beq         $s0, $zero, L_800600EC
    if (ctx->r16 == 0) {
        // nop
    
        goto L_800600EC;
    }
    // nop

    // bne         $a1, $zero, L_800600EC
    if (ctx->r5 != 0) {
        // nop
    
        goto L_800600EC;
    }
    // nop

    // sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
L_800600EC:
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // j           L_8006014C
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    goto L_8006014C;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800600F8:
    // addu        $v0, $v1, $t2
    ctx->r2 = ADD32(ctx->r3, ctx->r10);
    // lbu         $v0, 0x1478($v0)
    ctx->r2 = MEM_BU(0X1478, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80060118
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80060118;
    }
    // nop

    // j           L_8006011C
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    goto L_8006011C;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80060118:
    // sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
L_8006011C:
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // bne         $v0, $t0, L_8006014C
    if (ctx->r2 != ctx->r8) {
        // nop
    
        goto L_8006014C;
    }
    // nop

    // lbu         $v1, 0x9($a3)
    ctx->r3 = MEM_BU(0X9, ctx->r7);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // nop

    // bne         $v0, $v1, L_8006014C
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8006014C;
    }
    // nop

    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
L_8006014C:
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // slt         $v0, $a0, $a2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // bne         $v0, $zero, L_800600C4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800600C4;
    }
    // nop

    // bne         $a1, $zero, L_8006016C
    if (ctx->r5 != 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_8006016C;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_8006016C:
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80060174:
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // bne         $v0, $zero, L_80060174
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_80060174;
    }
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s0, $v0, -0x2E80
    ctx->r16 = ADD32(ctx->r2, -0X2E80);
    // addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // addiu       $s2, $sp, 0x10
    ctx->r18 = ADD32(ctx->r29, 0X10);
L_800601A0:
    // lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(0X4, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // beq         $v0, $zero, L_800601CC
    if (ctx->r2 == 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_800601CC;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $zero, -0x7E58($at)
    MEM_H(-0X7E58, ctx->r1) = 0;
    // jal         0x80057CEC
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    sub_80057CEC(rdram, ctx);
    goto after_1;
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    after_1:
    // j           L_8006030C
    // nop

    goto L_8006030C;
    // nop

L_800601CC:
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lhu         $v0, -0x7E58($v0)
    ctx->r2 = MEM_HU(-0X7E58, ctx->r2);
    // nop

    // bne         $v0, $s3, L_80060270
    if (ctx->r2 != ctx->r19) {
        // nop
    
        goto L_80060270;
    }
    // nop

    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8006021C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006021C;
    }
    // nop

    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // blez        $v0, L_8006021C
    if (SIGNED(ctx->r2) <= 0) {
        // sh          $zero, 0xC($s0)
        MEM_H(0XC, ctx->r16) = 0;
        goto L_8006021C;
    }
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_8006021C:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_8006025C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006025C;
    }
    // nop

    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // slti        $v0, $v0, 0x19
    ctx->r2 = SIGNED(ctx->r2) < 0X19 ? 1 : 0;
    // beq         $v0, $zero, L_8006025C
    if (ctx->r2 == 0) {
        // sh          $zero, 0xC($s0)
        MEM_H(0XC, ctx->r16) = 0;
        goto L_8006025C;
    }
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_8006025C:
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sw          $v0, -0x7E74($at)
    MEM_W(-0X7E74, ctx->r1) = ctx->r2;
    // j           L_80060278
    // nop

    goto L_80060278;
    // nop

L_80060270:
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sw          $zero, -0x7E74($at)
    MEM_W(-0X7E74, ctx->r1) = 0;
L_80060278:
    // beq         $v1, $zero, L_800602B4
    if (ctx->r3 == 0) {
        // nop
    
        goto L_800602B4;
    }
    // nop

    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80060288:
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // bne         $v0, $zero, L_80060288
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_80060288;
    }
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_800602B4:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // beq         $v0, $zero, L_800602D4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800602D4;
    }
    // nop

    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $zero, -0x7E58($at)
    MEM_H(-0X7E58, ctx->r1) = 0;
L_800602D4:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // beq         $v0, $zero, L_800602F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800602F4;
    }
    // nop

    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $s3, -0x7E58($at)
    MEM_H(-0X7E58, ctx->r1) = ctx->r19;
L_800602F4:
    // jal         0x800164B4
    // nop

    sub_800164B4(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x8002A954
    // nop

    sub_8002A954(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // j           L_800601A0
    // nop

    goto L_800601A0;
    // nop

L_8006030C:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lw          $ra, 0xB0($sp)
    ctx->r31 = MEM_W(0XB0, ctx->r29);
    // lw          $s3, 0xAC($sp)
    ctx->r19 = MEM_W(0XAC, ctx->r29);
    // lw          $s2, 0xA8($sp)
    ctx->r18 = MEM_W(0XA8, ctx->r29);
    // lw          $s1, 0xA4($sp)
    ctx->r17 = MEM_W(0XA4, ctx->r29);
    // lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(0XA0, ctx->r29);
    // addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // jr          $ra
    // nop

    return;
    // nop

;}
