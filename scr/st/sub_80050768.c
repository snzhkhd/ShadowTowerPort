#include "recomp.h"
#include "disable_warnings.h"

void sub_80050768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // sw          $s5, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r21;
    // addiu       $s5, $v0, 0x2230
    ctx->r21 = ADD32(ctx->r2, 0X2230);
    // addiu       $t2, $zero, 0xF0
    ctx->r10 = ADD32(0, 0XF0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sw          $s6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r22;
    // addiu       $s6, $v0, -0x70D8
    ctx->r22 = ADD32(ctx->r2, -0X70D8);
    // sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
    // addiu       $s1, $s5, 0x50
    ctx->r17 = ADD32(ctx->r21, 0X50);
    // addiu       $t3, $s5, 0x24
    ctx->r11 = ADD32(ctx->r21, 0X24);
    // sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r30;
    // sw          $s7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r23;
    // sw          $s4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r20;
    // sw          $s3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r19;
    // sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
    // sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    // sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
L_800507B8:
    // lhu         $v1, -0x46($s1)
    ctx->r3 = MEM_HU(-0X46, ctx->r17);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_8005279C
    if (ctx->r3 == ctx->r2) {
        // lui         $t2, 0x801C
        ctx->r10 = S32(0X801C << 16);
        goto L_8005279C;
    }
    // lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // addiu       $t2, $t2, 0x310
    ctx->r10 = ADD32(ctx->r10, 0X310);
    // lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // sw          $s5, 0x71B0($t2)
    MEM_W(0X71B0, ctx->r10) = ctx->r21;
    // lhu         $v1, -0x46($s1)
    ctx->r3 = MEM_HU(-0X46, ctx->r17);
    // addiu       $t3, $t3, 0x310
    ctx->r11 = ADD32(ctx->r11, 0X310);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $s3, $v0, $t3
    ctx->r19 = ADD32(ctx->r2, ctx->r11);
    // sw          $s3, 0x71AC($t2)
    MEM_W(0X71AC, ctx->r10) = ctx->r19;
    // lw          $v1, -0x2C($s1)
    ctx->r3 = MEM_W(-0X2C, ctx->r17);
    // lw          $v0, 0x248($s6)
    ctx->r2 = MEM_W(0X248, ctx->r22);
    // lw          $a1, -0x28($s1)
    ctx->r5 = MEM_W(-0X28, ctx->r17);
    // lw          $a0, -0x24($s1)
    ctx->r4 = MEM_W(-0X24, ctx->r17);
    // subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
    // lw          $v1, 0x24C($s6)
    ctx->r3 = MEM_W(0X24C, ctx->r22);
    // lw          $v0, 0x250($s6)
    ctx->r2 = MEM_W(0X250, ctx->r22);
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // subu        $s0, $a0, $v0
    ctx->r16 = SUB32(ctx->r4, ctx->r2);
    // ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    // addu        $v1, $s2, $a0
    ctx->r3 = ADD32(ctx->r18, ctx->r4);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8005085C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x4000
        ctx->r2 = S32(0X4000 << 16);
        goto L_8005085C;
    }
    // lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_8005085C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x4000
        ctx->r2 = S32(0X4000 << 16);
        goto L_8005085C;
    }
    // lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // slti        $v0, $a1, -0x8000
    ctx->r2 = SIGNED(ctx->r5) < -0X8000 ? 1 : 0;
    // bne         $v0, $zero, L_8005085C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x4000
        ctx->r2 = S32(0X4000 << 16);
        goto L_8005085C;
    }
    // lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // slt         $v0, $a0, $s0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r16) ? 1 : 0;
    // bne         $v0, $zero, L_8005085C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x4000
        ctx->r2 = S32(0X4000 << 16);
        goto L_8005085C;
    }
    // lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // slti        $v0, $s0, -0x8000
    ctx->r2 = SIGNED(ctx->r16) < -0X8000 ? 1 : 0;
    // beq         $v0, $zero, L_80050868
    if (ctx->r2 == 0) {
        // lui         $v0, 0x4000
        ctx->r2 = S32(0X4000 << 16);
        goto L_80050868;
    }
    // lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
L_8005085C:
    // sw          $v0, -0x38($s1)
    MEM_W(-0X38, ctx->r17) = ctx->r2;
    // j           L_800508A4
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    goto L_800508A4;
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
L_80050868:
    // mult        $s2, $s2
    result = S64(S32(ctx->r18)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // mult        $s0, $s0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // nop

    // mult        $a1, $a1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x800746C4
    // sw          $v0, -0x38($s1)
    MEM_W(-0X38, ctx->r17) = ctx->r2;
    SquareRoot0(rdram, ctx);
    goto after_0;
    // sw          $v0, -0x38($s1)
    MEM_W(-0X38, ctx->r17) = ctx->r2;
    after_0:
L_800508A4:
    // sw          $v0, -0x34($s1)
    MEM_W(-0X34, ctx->r17) = ctx->r2;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80076EA4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    ratan2(rdram, ctx);
    goto after_1;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_1:
    // addiu       $v0, $v0, -0x400
    ctx->r2 = ADD32(ctx->r2, -0X400);
    // lhu         $v1, -0x1A($s1)
    ctx->r3 = MEM_HU(-0X1A, ctx->r17);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sh          $v0, -0x30($s1)
    MEM_H(-0X30, ctx->r17) = ctx->r2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // slti        $v0, $v1, 0x801
    ctx->r2 = SIGNED(ctx->r3) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_800508E4
    if (ctx->r2 != 0) {
        // sh          $v1, -0x2E($s1)
        MEM_H(-0X2E, ctx->r17) = ctx->r3;
        goto L_800508E4;
    }
    // sh          $v1, -0x2E($s1)
    MEM_H(-0X2E, ctx->r17) = ctx->r3;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, -0x2E($s1)
    MEM_H(-0X2E, ctx->r17) = ctx->r2;
L_800508E4:
    // lbu         $v0, -0x4B($s1)
    ctx->r2 = MEM_BU(-0X4B, ctx->r17);
    // addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // beq         $v0, $t2, L_8005279C
    if (ctx->r2 == ctx->r10) {
        // addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8005279C;
    }
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // beq         $a0, $a3, L_80051F90
    if (ctx->r4 == ctx->r7) {
        // slti        $v0, $a0, 0x8
        ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
        goto L_80051F90;
    }
    // slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_80050948
    if (ctx->r2 == 0) {
        // addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
        goto L_80050948;
    }
    // addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // beq         $a0, $t3, L_800518DC
    if (ctx->r4 == ctx->r11) {
        // slti        $v0, $a0, 0x4
        ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
        goto L_800518DC;
    }
    // slti        $v0, $a0, 0x4
    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_80050930
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_80050930;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bltz        $a0, L_8005277C
    if (SIGNED(ctx->r4) < 0) {
        // slti        $v0, $a0, 0x2
        ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
        goto L_8005277C;
    }
    // slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80051780
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80051780;
    }
    // nop

    // j           L_800509B4
    // nop

    goto L_800509B4;
    // nop

L_80050930:
    // beq         $a0, $v0, L_80051BA0
    if (ctx->r4 == ctx->r2) {
        // slti        $v0, $a0, 0x6
        ctx->r2 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
        goto L_80051BA0;
    }
    // slti        $v0, $a0, 0x6
    ctx->r2 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_80051BC0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80051BC0;
    }
    // nop

    // j           L_800518FC
    // nop

    goto L_800518FC;
    // nop

L_80050948:
    // addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
    // beq         $a0, $v0, L_800514F8
    if (ctx->r4 == ctx->r2) {
        // slti        $v0, $a0, 0x35
        ctx->r2 = SIGNED(ctx->r4) < 0X35 ? 1 : 0;
        goto L_800514F8;
    }
    // slti        $v0, $a0, 0x35
    ctx->r2 = SIGNED(ctx->r4) < 0X35 ? 1 : 0;
    // beq         $v0, $zero, L_80050974
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_80050974;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // beq         $a0, $v0, L_800518FC
    if (ctx->r4 == ctx->r2) {
        // slti        $v0, $a0, 0x32
        ctx->r2 = SIGNED(ctx->r4) < 0X32 ? 1 : 0;
        goto L_800518FC;
    }
    // slti        $v0, $a0, 0x32
    ctx->r2 = SIGNED(ctx->r4) < 0X32 ? 1 : 0;
    // bne         $v0, $zero, L_80052780
    if (ctx->r2 != 0) {
        // lui         $t2, 0x801B
        ctx->r10 = S32(0X801B << 16);
        goto L_80052780;
    }
    // lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // j           L_80051000
    // addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    goto L_80051000;
    // addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
L_80050974:
    // addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // beq         $a0, $v0, L_8005279C
    if (ctx->r4 == ctx->r2) {
        // slti        $v0, $a0, 0xE2
        ctx->r2 = SIGNED(ctx->r4) < 0XE2 ? 1 : 0;
        goto L_8005279C;
    }
    // slti        $v0, $a0, 0xE2
    ctx->r2 = SIGNED(ctx->r4) < 0XE2 ? 1 : 0;
    // beq         $v0, $zero, L_80050998
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xE0
        ctx->r2 = ADD32(0, 0XE0);
        goto L_80050998;
    }
    // addiu       $v0, $zero, 0xE0
    ctx->r2 = ADD32(0, 0XE0);
    // beq         $a0, $v0, L_80051FB0
    if (ctx->r4 == ctx->r2) {
        // lui         $t2, 0x801B
        ctx->r10 = S32(0X801B << 16);
        goto L_80051FB0;
    }
    // lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // j           L_80052784
    // addiu       $t2, $t2, 0x5920
    ctx->r10 = ADD32(ctx->r10, 0X5920);
    goto L_80052784;
    // addiu       $t2, $t2, 0x5920
    ctx->r10 = ADD32(ctx->r10, 0X5920);
L_80050998:
    // addiu       $v0, $zero, 0xED
    ctx->r2 = ADD32(0, 0XED);
    // beq         $a0, $v0, L_80052338
    if (ctx->r4 == ctx->r2) {
        // addiu       $v0, $zero, 0xEF
        ctx->r2 = ADD32(0, 0XEF);
        goto L_80052338;
    }
    // addiu       $v0, $zero, 0xEF
    ctx->r2 = ADD32(0, 0XEF);
    // beq         $a0, $v0, L_80052338
    if (ctx->r4 == ctx->r2) {
        // lui         $t2, 0x801B
        ctx->r10 = S32(0X801B << 16);
        goto L_80052338;
    }
    // lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // j           L_80052784
    // addiu       $t2, $t2, 0x5920
    ctx->r10 = ADD32(ctx->r10, 0X5920);
    goto L_80052784;
    // addiu       $t2, $t2, 0x5920
    ctx->r10 = ADD32(ctx->r10, 0X5920);
L_800509B4:
    // lbu         $v1, -0x8($s1)
    ctx->r3 = MEM_BU(-0X8, ctx->r17);
    // lhu         $a1, -0x44($s1)
    ctx->r5 = MEM_HU(-0X44, ctx->r17);
    // sll         $a2, $v1, 2
    ctx->r6 = S32(ctx->r3) << 2;
    // beq         $a1, $a3, L_80050F84
    if (ctx->r5 == ctx->r7) {
        // addu        $s0, $a2, $zero
        ctx->r16 = ADD32(ctx->r6, 0);
        goto L_80050F84;
    }
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // slti        $v0, $a1, 0x8
    ctx->r2 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_80050A10
    if (ctx->r2 == 0) {
        // addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
        goto L_80050A10;
    }
    // addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // beq         $a1, $t2, L_80050ACC
    if (ctx->r5 == ctx->r10) {
        // slti        $v0, $a1, 0x2
        ctx->r2 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
        goto L_80050ACC;
    }
    // slti        $v0, $a1, 0x2
    ctx->r2 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_800509F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800509F4;
    }
    // nop

    // beq         $a1, $zero, L_80050A50
    if (ctx->r5 == 0) {
        // addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
        goto L_80050A50;
    }
    // addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_800509F4:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $a1, $v0, L_80050D7C
    if (ctx->r5 == ctx->r2) {
        // addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
        goto L_80050D7C;
    }
    // addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // beq         $a1, $t3, L_80050DDC
    if (ctx->r5 == ctx->r11) {
        // nop
    
        goto L_80050DDC;
    }
    // nop

    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_80050A10:
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // beq         $a1, $v0, L_8005279C
    if (ctx->r5 == ctx->r2) {
        // slti        $v0, $a1, 0xC
        ctx->r2 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
        goto L_8005279C;
    }
    // slti        $v0, $a1, 0xC
    ctx->r2 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // beq         $v0, $zero, L_80050A34
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_80050A34;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // beq         $a1, $v0, L_80050F98
    if (ctx->r5 == ctx->r2) {
        // addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
        goto L_80050F98;
    }
    // addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_80050A34:
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // beq         $a1, $v0, L_80051480
    if (ctx->r5 == ctx->r2) {
        // addiu       $t2, $zero, 0xFF
        ctx->r10 = ADD32(0, 0XFF);
        goto L_80051480;
    }
    // addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // beq         $a1, $t2, L_800514F0
    if (ctx->r5 == ctx->r10) {
        // addiu       $v0, $zero, 0xFFF
        ctx->r2 = ADD32(0, 0XFFF);
        goto L_800514F0;
    }
    // addiu       $v0, $zero, 0xFFF
    ctx->r2 = ADD32(0, 0XFFF);
    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_80050A50:
    // lbu         $v0, -0x4B($s1)
    ctx->r2 = MEM_BU(-0X4B, ctx->r17);
    // nop

    // bne         $v0, $t3, L_80050A94
    if (ctx->r2 != ctx->r11) {
        // lui         $v1, 0x8016
        ctx->r3 = S32(0X8016 << 16);
        goto L_80050A94;
    }
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // ori         $v1, $zero, 0x874C
    ctx->r3 = 0 | 0X874C;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80050A90
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_80050A90;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // j           L_80050A94
    // sb          $zero, 0x0($s5)
    MEM_B(0X0, ctx->r21) = 0;
    goto L_80050A94;
    // sb          $zero, 0x0($s5)
    MEM_B(0X0, ctx->r21) = 0;
L_80050A90:
    // sb          $v0, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r2;
L_80050A94:
    // lbu         $v0, -0x7($s1)
    ctx->r2 = MEM_BU(-0X7, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8005279C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005279C;
    }
    // nop

    // lw          $v0, -0x34($s1)
    ctx->r2 = MEM_W(-0X34, ctx->r17);
    // nop

    // slti        $v0, $v0, 0x2001
    ctx->r2 = SIGNED(ctx->r2) < 0X2001 ? 1 : 0;
    // beq         $v0, $zero, L_8005279C
    if (ctx->r2 == 0) {
        // addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
        goto L_8005279C;
    }
    // addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // j           L_8005279C
    // sh          $t2, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r10;
    goto L_8005279C;
    // sh          $t2, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r10;
L_80050ACC:
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80050BA4
    if (ctx->r2 != 0) {
        // sll         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3) << 2;
        goto L_80050BA4;
    }
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // blez        $v0, L_80050BA4
    if (SIGNED(ctx->r2) <= 0) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80050BA4;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lbu         $a3, -0x2($s1)
    ctx->r7 = MEM_BU(-0X2, ctx->r17);
    // nop

    // addiu       $v1, $a3, -0x1
    ctx->r3 = ADD32(ctx->r7, -0X1);
    // addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // beq         $v1, $v0, L_80050B78
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
        goto L_80050B78;
    }
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $t0, $v0, -0x4130
    ctx->r8 = ADD32(ctx->r2, -0X4130);
    // ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
L_80050B0C:
    // andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    // lhu         $v0, -0x4($s1)
    ctx->r2 = MEM_HU(-0X4, ctx->r17);
    // lhu         $v1, -0x6($s1)
    ctx->r3 = MEM_HU(-0X6, ctx->r17);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // lbu         $a2, 0x0($a0)
    ctx->r6 = MEM_BU(0X0, ctx->r4);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // addiu       $a0, $a3, -0x1
    ctx->r4 = ADD32(ctx->r7, -0X1);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // lhu         $v1, -0x6($s1)
    ctx->r3 = MEM_HU(-0X6, ctx->r17);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bne         $a0, $t1, L_80050B0C
    if (ctx->r4 != ctx->r9) {
        // sb          $a2, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r6;
        goto L_80050B0C;
    }
    // sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
L_80050B78:
    // lbu         $v0, -0x4B($s1)
    ctx->r2 = MEM_BU(-0X4B, ctx->r17);
    // addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // bne         $v0, $t3, L_80050B8C
    if (ctx->r2 != ctx->r11) {
        // addu        $t2, $t3, $zero
        ctx->r10 = ADD32(ctx->r11, 0);
        goto L_80050B8C;
    }
    // addu        $t2, $t3, $zero
    ctx->r10 = ADD32(ctx->r11, 0);
    // sb          $t2, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r10;
L_80050B8C:
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8004ED54
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    sub_8004ED54(rdram, ctx);
    goto after_2;
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    after_2:
L_80050BA4:
    // lhu         $v1, -0x40($s1)
    ctx->r3 = MEM_HU(-0X40, ctx->r17);
    // nop

    // addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // slti        $v0, $v0, 0xFFF
    ctx->r2 = SIGNED(ctx->r2) < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_80050BD0
    if (ctx->r2 != 0) {
        // addu        $v0, $v1, $s0
        ctx->r2 = ADD32(ctx->r3, ctx->r16);
        goto L_80050BD0;
    }
    // addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
    // addiu       $v0, $zero, 0xFFF
    ctx->r2 = ADD32(0, 0XFFF);
    // sh          $v0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // j           L_80050BD8
    // sh          $v0, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r2;
    goto L_80050BD8;
    // sh          $v0, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r2;
L_80050BD0:
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sh          $v0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r2;
L_80050BD8:
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0xC00
    ctx->r2 = ctx->r2 < 0XC00 ? 1 : 0;
    // beq         $v0, $zero, L_80050C1C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80050C1C;
    }
    // nop

    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // slti        $v0, $v0, 0xC00
    ctx->r2 = SIGNED(ctx->r2) < 0XC00 ? 1 : 0;
    // bne         $v0, $zero, L_80050C1C
    if (ctx->r2 != 0) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_80050C1C;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
    // nop

    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8004ED54
    // addiu       $a1, $a1, 0xD2
    ctx->r5 = ADD32(ctx->r5, 0XD2);
    sub_8004ED54(rdram, ctx);
    goto after_3;
    // addiu       $a1, $a1, 0xD2
    ctx->r5 = ADD32(ctx->r5, 0XD2);
    after_3:
L_80050C1C:
    // beq         $s0, $zero, L_80050C54
    if (ctx->r16 == 0) {
        // nop
    
        goto L_80050C54;
    }
    // nop

    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x801
    ctx->r2 = ctx->r2 < 0X801 ? 1 : 0;
    // beq         $v0, $zero, L_80050C54
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80050C54;
    }
    // nop

    // lw          $v0, -0x38($s1)
    ctx->r2 = MEM_W(-0X38, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x801
    ctx->r2 = ctx->r2 < 0X801 ? 1 : 0;
    // beq         $v0, $zero, L_80050C54
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80050C54;
    }
    // nop

    // jal         0x8003EAD0
    // nop

    sub_8003EAD0(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_80050C54:
    // lw          $v0, -0x34($s1)
    ctx->r2 = MEM_W(-0X34, ctx->r17);
    // nop

    // slti        $v0, $v0, 0x801
    ctx->r2 = SIGNED(ctx->r2) < 0X801 ? 1 : 0;
    // beq         $v0, $zero, L_8005279C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005279C;
    }
    // nop

    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x801
    ctx->r2 = ctx->r2 < 0X801 ? 1 : 0;
    // beq         $v0, $zero, L_8005279C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005279C;
    }
    // nop

    // lhu         $v1, 0x12($s3)
    ctx->r3 = MEM_HU(0X12, ctx->r19);
    // nop

    // sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_80050CFC
    if (ctx->r2 == 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80050CFC;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x2720
    ctx->r2 = ADD32(ctx->r2, 0X2720);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_80050CA8;
    jr_addend_80050CA8 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80050CA8 >> 2) {
        case 0: goto L_80050CB0; break;
        case 1: goto L_80050CC8; break;
        case 2: goto L_80050CD4; break;
        case 3: goto L_80050CE0; break;
        case 4: goto L_80050CFC; break;
        case 5: goto L_80050CF8; break;
        default: switch_error(__func__, 0x80050CA8, 0x80012720);
    }
    // nop

L_80050CB0:
    // lhu         $v0, -0x2E($s1)
    ctx->r2 = MEM_HU(-0X2E, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // j           L_80050CF0
    // sltiu       $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 < 0X7FF ? 1 : 0;
    goto L_80050CF0;
    // sltiu       $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 < 0X7FF ? 1 : 0;
L_80050CC8:
    // lhu         $v0, -0x2E($s1)
    ctx->r2 = MEM_HU(-0X2E, ctx->r17);
    // j           L_80050CEC
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    goto L_80050CEC;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80050CD4:
    // lhu         $v0, -0x2E($s1)
    ctx->r2 = MEM_HU(-0X2E, ctx->r17);
    // j           L_80050CEC
    // addiu       $v0, $v0, -0x401
    ctx->r2 = ADD32(ctx->r2, -0X401);
    goto L_80050CEC;
    // addiu       $v0, $v0, -0x401
    ctx->r2 = ADD32(ctx->r2, -0X401);
L_80050CE0:
    // lhu         $v0, -0x2E($s1)
    ctx->r2 = MEM_HU(-0X2E, ctx->r17);
    // nop

    // addiu       $v0, $v0, -0x801
    ctx->r2 = ADD32(ctx->r2, -0X801);
L_80050CEC:
    // sltiu       $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 < 0X7FF ? 1 : 0;
L_80050CF0:
    // beq         $v0, $zero, L_80050CFC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80050CFC;
    }
    // nop

L_80050CF8:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80050CFC:
    // beq         $s0, $zero, L_8005279C
    if (ctx->r16 == 0) {
        // nop
    
        goto L_8005279C;
    }
    // nop

    // beq         $a0, $zero, L_8005279C
    if (ctx->r4 == 0) {
        // nop
    
        goto L_8005279C;
    }
    // nop

    // lhu         $s0, -0x30($s1)
    ctx->r16 = MEM_HU(-0X30, ctx->r17);
    // jal         0x8003EAD0
    // addiu       $s0, $s0, -0x400
    ctx->r16 = ADD32(ctx->r16, -0X400);
    sub_8003EAD0(rdram, ctx);
    goto after_5;
    // addiu       $s0, $s0, -0x400
    ctx->r16 = ADD32(ctx->r16, -0X400);
    after_5:
    // sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) << 16;
    // sra         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) >> 16;
    // jal         0x800744C4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rcos(rdram, ctx);
    goto after_6;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // bgez        $v1, L_80050D38
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80050D38;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $v1, $v1, 0x1F
    ctx->r3 = ADD32(ctx->r3, 0X1F);
L_80050D38:
    // lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // addiu       $t3, $t3, 0x310
    ctx->r11 = ADD32(ctx->r11, 0X310);
    // lhu         $v0, 0x71A4($t3)
    ctx->r2 = MEM_HU(0X71A4, ctx->r11);
    // sra         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) >> 5;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x800743F4
    // sh          $v0, 0x71A4($t3)
    MEM_H(0X71A4, ctx->r11) = ctx->r2;
    rsin(rdram, ctx);
    goto after_7;
    // sh          $v0, 0x71A4($t3)
    MEM_H(0X71A4, ctx->r11) = ctx->r2;
    after_7:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // bgez        $v1, L_80050D64
    if (SIGNED(ctx->r3) >= 0) {
        // lui         $t2, 0x801C
        ctx->r10 = S32(0X801C << 16);
        goto L_80050D64;
    }
    // lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x1F
    ctx->r3 = ADD32(ctx->r3, 0X1F);
L_80050D64:
    // addiu       $t2, $t2, 0x310
    ctx->r10 = ADD32(ctx->r10, 0X310);
    // lhu         $v0, 0x71A8($t2)
    ctx->r2 = MEM_HU(0X71A8, ctx->r10);
    // sra         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) >> 5;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_8005279C
    // sh          $v0, 0x71A8($t2)
    MEM_H(0X71A8, ctx->r10) = ctx->r2;
    goto L_8005279C;
    // sh          $v0, 0x71A8($t2)
    MEM_H(0X71A8, ctx->r10) = ctx->r2;
L_80050D7C:
    // lbu         $a0, -0x7($s1)
    ctx->r4 = MEM_BU(-0X7, ctx->r17);
    // addiu       $v0, $zero, 0xFC
    ctx->r2 = ADD32(0, 0XFC);
    // andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // beq         $v1, $v0, L_80050D98
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xFA
        ctx->r2 = ADD32(0, 0XFA);
        goto L_80050D98;
    }
    // addiu       $v0, $zero, 0xFA
    ctx->r2 = ADD32(0, 0XFA);
    // bne         $v1, $v0, L_80050DA4
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80050DA4;
    }
    // nop

L_80050D98:
    // addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // j           L_8005279C
    // sh          $t3, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r11;
    goto L_8005279C;
    // sh          $t3, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r11;
L_80050DA4:
    // lw          $v0, -0x34($s1)
    ctx->r2 = MEM_W(-0X34, ctx->r17);
    // nop

    // slti        $v0, $v0, 0x2000
    ctx->r2 = SIGNED(ctx->r2) < 0X2000 ? 1 : 0;
    // bne         $v0, $zero, L_8005279C
    if (ctx->r2 != 0) {
        // andi        $v0, $a0, 0x80
        ctx->r2 = ctx->r4 & 0X80;
        goto L_8005279C;
    }
    // andi        $v0, $a0, 0x80
    ctx->r2 = ctx->r4 & 0X80;
    // bne         $v0, $zero, L_80050DCC
    if (ctx->r2 != 0) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_80050DCC;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // sltiu       $v0, $v1, 0x1
    ctx->r2 = ctx->r3 < 0X1 ? 1 : 0;
    // sb          $v0, -0x4E($s1)
    MEM_B(-0X4E, ctx->r17) = ctx->r2;
    // sh          $zero, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = 0;
L_80050DCC:
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
    // addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // j           L_8005141C
    // sh          $t2, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r10;
    goto L_8005141C;
    // sh          $t2, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r10;
L_80050DDC:
    // lbu         $v0, -0x7($s1)
    ctx->r2 = MEM_BU(-0X7, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_80050E9C
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_80050E9C;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lhu         $a0, -0x40($s1)
    ctx->r4 = MEM_HU(-0X40, ctx->r17);
    // nop

    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_80051774
    if (ctx->r2 != 0) {
        // subu        $v0, $a0, $a2
        ctx->r2 = SUB32(ctx->r4, ctx->r6);
        goto L_80051774;
    }
    // subu        $v0, $a0, $a2
    ctx->r2 = SUB32(ctx->r4, ctx->r6);
    // lbu         $a3, -0x2($s1)
    ctx->r7 = MEM_BU(-0X2, ctx->r17);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // addiu       $v1, $a3, -0x1
    ctx->r3 = ADD32(ctx->r7, -0X1);
    // addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // beq         $v1, $v0, L_80050F5C
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
        goto L_80050F5C;
    }
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $t0, $v0, -0x4130
    ctx->r8 = ADD32(ctx->r2, -0X4130);
    // ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
L_80050E28:
    // andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    // lhu         $v0, -0x4($s1)
    ctx->r2 = MEM_HU(-0X4, ctx->r17);
    // lhu         $v1, -0x6($s1)
    ctx->r3 = MEM_HU(-0X6, ctx->r17);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // lbu         $a2, 0x0($a0)
    ctx->r6 = MEM_BU(0X0, ctx->r4);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // addiu       $a0, $a3, -0x1
    ctx->r4 = ADD32(ctx->r7, -0X1);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // lhu         $v1, -0x6($s1)
    ctx->r3 = MEM_HU(-0X6, ctx->r17);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bne         $a0, $t1, L_80050E28
    if (ctx->r4 != ctx->r9) {
        // sb          $a2, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r6;
        goto L_80050E28;
    }
    // sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
    // j           L_80050F5C
    // nop

    goto L_80050F5C;
    // nop

L_80050E9C:
    // lhu         $a0, -0x40($s1)
    ctx->r4 = MEM_HU(-0X40, ctx->r17);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // slti        $v0, $v0, 0xFFF
    ctx->r2 = SIGNED(ctx->r2) < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_80051774
    if (ctx->r2 != 0) {
        // addu        $v0, $a0, $a2
        ctx->r2 = ADD32(ctx->r4, ctx->r6);
        goto L_80051774;
    }
    // addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // lbu         $a3, -0x2($s1)
    ctx->r7 = MEM_BU(-0X2, ctx->r17);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // addiu       $v1, $a3, -0x1
    ctx->r3 = ADD32(ctx->r7, -0X1);
    // addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // beq         $v1, $v0, L_80050F44
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
        goto L_80050F44;
    }
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $t0, $v0, -0x4130
    ctx->r8 = ADD32(ctx->r2, -0X4130);
    // ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
L_80050ED8:
    // andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    // lhu         $v0, -0x4($s1)
    ctx->r2 = MEM_HU(-0X4, ctx->r17);
    // lhu         $v1, -0x6($s1)
    ctx->r3 = MEM_HU(-0X6, ctx->r17);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // lbu         $a2, 0x0($a0)
    ctx->r6 = MEM_BU(0X0, ctx->r4);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // addiu       $a0, $a3, -0x1
    ctx->r4 = ADD32(ctx->r7, -0X1);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // lhu         $v1, -0x6($s1)
    ctx->r3 = MEM_HU(-0X6, ctx->r17);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bne         $a0, $t1, L_80050ED8
    if (ctx->r4 != ctx->r9) {
        // sb          $a2, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r6;
        goto L_80050ED8;
    }
    // sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
L_80050F44:
    // lbu         $v1, -0x7($s1)
    ctx->r3 = MEM_BU(-0X7, ctx->r17);
    // nop

    // andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // bne         $v0, $zero, L_80050F5C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80050F5C;
    }
    // nop

    // sb          $v1, -0x4E($s1)
    MEM_B(-0X4E, ctx->r17) = ctx->r3;
L_80050F5C:
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // sh          $zero, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = 0;
    // sh          $zero, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = 0;
    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8004ED54
    // addiu       $a1, $a1, 0xD1
    ctx->r5 = ADD32(ctx->r5, 0XD1);
    sub_8004ED54(rdram, ctx);
    goto after_8;
    // addiu       $a1, $a1, 0xD1
    ctx->r5 = ADD32(ctx->r5, 0XD1);
    after_8:
    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_80050F84:
    // addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // bne         $a0, $t3, L_8005279C
    if (ctx->r4 != ctx->r11) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8005279C;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // j           L_8005279C
    // sb          $v0, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r2;
    goto L_8005279C;
    // sb          $v0, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r2;
L_80050F98:
    // sb          $t2, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r10;
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80050FD0
    if (ctx->r2 != 0) {
        // sll         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3) << 2;
        goto L_80050FD0;
    }
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // blez        $v0, L_80050FD0
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_80050FD0;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
    // nop

    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8004ED54
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    sub_8004ED54(rdram, ctx);
    goto after_9;
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    after_9:
L_80050FD0:
    // lhu         $v1, -0x40($s1)
    ctx->r3 = MEM_HU(-0X40, ctx->r17);
    // nop

    // addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // slti        $v0, $v0, 0xFFF
    ctx->r2 = SIGNED(ctx->r2) < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_80051774
    if (ctx->r2 != 0) {
        // addu        $v0, $v1, $s0
        ctx->r2 = ADD32(ctx->r3, ctx->r16);
        goto L_80051774;
    }
    // addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
    // addiu       $v0, $zero, 0xFFF
    ctx->r2 = ADD32(0, 0XFFF);
    // sb          $zero, 0x0($s5)
    MEM_B(0X0, ctx->r21) = 0;
    // addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // sh          $v0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r2;
    // j           L_8005279C
    // sh          $t3, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r11;
    goto L_8005279C;
    // sh          $t3, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r11;
L_80051000:
    // lbu         $v1, -0x8($s1)
    ctx->r3 = MEM_BU(-0X8, ctx->r17);
    // lhu         $a0, -0x44($s1)
    ctx->r4 = MEM_HU(-0X44, ctx->r17);
    // sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3) << 2;
    // beq         $a0, $a2, L_80051324
    if (ctx->r4 == ctx->r6) {
        // addu        $s0, $a1, $zero
        ctx->r16 = ADD32(ctx->r5, 0);
        goto L_80051324;
    }
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // slti        $v0, $a0, 0x7
    ctx->r2 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_80051064
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_80051064;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $a0, $v0, L_800511C8
    if (ctx->r4 == ctx->r2) {
        // slti        $v0, $a0, 0x3
        ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
        goto L_800511C8;
    }
    // slti        $v0, $a0, 0x3
    ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // beq         $v0, $zero, L_80051048
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80051048;
    }
    // nop

    // beq         $a0, $zero, L_800510B4
    if (ctx->r4 == 0) {
        // addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
        goto L_800510B4;
    }
    // addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // beq         $a0, $t3, L_80051108
    if (ctx->r4 == ctx->r11) {
        // nop
    
        goto L_80051108;
    }
    // nop

    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_80051048:
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $a0, $v0, L_80051278
    if (ctx->r4 == ctx->r2) {
        // slti        $v0, $a0, 0x5
        ctx->r2 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
        goto L_80051278;
    }
    // slti        $v0, $a0, 0x5
    ctx->r2 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_800512D4
    if (ctx->r2 == 0) {
        // lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
        goto L_800512D4;
    }
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // j           L_8005121C
    // nop

    goto L_8005121C;
    // nop

L_80051064:
    // addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // beq         $a0, $s2, L_80051448
    if (ctx->r4 == ctx->r18) {
        // slti        $v0, $a0, 0xB
        ctx->r2 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
        goto L_80051448;
    }
    // slti        $v0, $a0, 0xB
    ctx->r2 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
    // beq         $v0, $zero, L_80051090
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_80051090;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // beq         $a0, $v0, L_80051358
    if (ctx->r4 == ctx->r2) {
        // slti        $v0, $a0, 0x9
        ctx->r2 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
        goto L_80051358;
    }
    // slti        $v0, $a0, 0x9
    ctx->r2 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
    // beq         $v0, $zero, L_800513B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800513B8;
    }
    // nop

    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_80051090:
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // beq         $a0, $v0, L_80051480
    if (ctx->r4 == ctx->r2) {
        // slti        $v0, $a0, 0xC
        ctx->r2 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
        goto L_80051480;
    }
    // slti        $v0, $a0, 0xC
    ctx->r2 = SIGNED(ctx->r4) < 0XC ? 1 : 0;
    // bne         $v0, $zero, L_8005279C
    if (ctx->r2 != 0) {
        // addiu       $t2, $zero, 0xFF
        ctx->r10 = ADD32(0, 0XFF);
        goto L_8005279C;
    }
    // addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // beq         $a0, $t2, L_800514F0
    if (ctx->r4 == ctx->r10) {
        // addiu       $v0, $zero, 0xFFF
        ctx->r2 = ADD32(0, 0XFFF);
        goto L_800514F0;
    }
    // addiu       $v0, $zero, 0xFFF
    ctx->r2 = ADD32(0, 0XFFF);
    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_800510B4:
    // lbu         $v1, -0x4B($s1)
    ctx->r3 = MEM_BU(-0X4B, ctx->r17);
    // addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // bne         $v1, $v0, L_800510D0
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800510D0;
    }
    // nop

    // lbu         $a0, -0x4($s1)
    ctx->r4 = MEM_BU(-0X4, ctx->r17);
    // jal         0x8004EE48
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_8004EE48(rdram, ctx);
    goto after_10;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_10:
L_800510D0:
    // lbu         $v0, -0x7($s1)
    ctx->r2 = MEM_BU(-0X7, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8005279C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005279C;
    }
    // nop

    // lw          $v0, -0x34($s1)
    ctx->r2 = MEM_W(-0X34, ctx->r17);
    // nop

    // slti        $v0, $v0, 0x2001
    ctx->r2 = SIGNED(ctx->r2) < 0X2001 ? 1 : 0;
    // beq         $v0, $zero, L_8005279C
    if (ctx->r2 == 0) {
        // addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
        goto L_8005279C;
    }
    // addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // j           L_8005279C
    // sh          $t3, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r11;
    goto L_8005279C;
    // sh          $t3, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r11;
L_80051108:
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8005115C
    if (ctx->r2 != 0) {
        // sll         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3) << 2;
        goto L_8005115C;
    }
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // blez        $v0, L_80051158
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_80051158;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
    // nop

    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8004ED54
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    sub_8004ED54(rdram, ctx);
    goto after_11;
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    after_11:
    // lbu         $v1, -0x4B($s1)
    ctx->r3 = MEM_BU(-0X4B, ctx->r17);
    // addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // bne         $v1, $v0, L_80051158
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80051158;
    }
    // nop

    // lbu         $a0, -0x4($s1)
    ctx->r4 = MEM_BU(-0X4, ctx->r17);
    // jal         0x8004EE48
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sub_8004EE48(rdram, ctx);
    goto after_12;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
L_80051158:
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
L_8005115C:
    // nop

    // sltiu       $v0, $v0, 0xC00
    ctx->r2 = ctx->r2 < 0XC00 ? 1 : 0;
    // beq         $v0, $zero, L_8005119C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005119C;
    }
    // nop

    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // slti        $v0, $v0, 0xC00
    ctx->r2 = SIGNED(ctx->r2) < 0XC00 ? 1 : 0;
    // bne         $v0, $zero, L_8005119C
    if (ctx->r2 != 0) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_8005119C;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
    // nop

    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8004ED54
    // addiu       $a1, $a1, 0xD2
    ctx->r5 = ADD32(ctx->r5, 0XD2);
    sub_8004ED54(rdram, ctx);
    goto after_13;
    // addiu       $a1, $a1, 0xD2
    ctx->r5 = ADD32(ctx->r5, 0XD2);
    after_13:
L_8005119C:
    // lhu         $v1, -0x40($s1)
    ctx->r3 = MEM_HU(-0X40, ctx->r17);
    // nop

    // addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // slti        $v0, $v0, 0xFFF
    ctx->r2 = SIGNED(ctx->r2) < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_80051774
    if (ctx->r2 != 0) {
        // addu        $v0, $v1, $s0
        ctx->r2 = ADD32(ctx->r3, ctx->r16);
        goto L_80051774;
    }
    // addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
    // addiu       $v0, $zero, 0xFFF
    ctx->r2 = ADD32(0, 0XFFF);
    // sh          $v0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // j           L_8005279C
    // sh          $v0, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r2;
    goto L_8005279C;
    // sh          $v0, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r2;
L_800511C8:
    // lbu         $a0, -0x7($s1)
    ctx->r4 = MEM_BU(-0X7, ctx->r17);
    // addiu       $v0, $zero, 0xFC
    ctx->r2 = ADD32(0, 0XFC);
    // andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // beq         $v1, $v0, L_800514E4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xFA
        ctx->r2 = ADD32(0, 0XFA);
        goto L_800514E4;
    }
    // addiu       $v0, $zero, 0xFA
    ctx->r2 = ADD32(0, 0XFA);
    // beq         $v1, $v0, L_800514E8
    if (ctx->r3 == ctx->r2) {
        // addiu       $t2, $zero, 0xFF
        ctx->r10 = ADD32(0, 0XFF);
        goto L_800514E8;
    }
    // addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // lw          $v0, -0x34($s1)
    ctx->r2 = MEM_W(-0X34, ctx->r17);
    // nop

    // slti        $v0, $v0, 0x2000
    ctx->r2 = SIGNED(ctx->r2) < 0X2000 ? 1 : 0;
    // bne         $v0, $zero, L_8005279C
    if (ctx->r2 != 0) {
        // andi        $v0, $a0, 0x80
        ctx->r2 = ctx->r4 & 0X80;
        goto L_8005279C;
    }
    // andi        $v0, $a0, 0x80
    ctx->r2 = ctx->r4 & 0X80;
    // bne         $v0, $zero, L_8005120C
    if (ctx->r2 != 0) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_8005120C;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // sltiu       $v0, $v1, 0x1
    ctx->r2 = ctx->r3 < 0X1 ? 1 : 0;
    // sb          $v0, -0x4E($s1)
    MEM_B(-0X4E, ctx->r17) = ctx->r2;
    // sh          $zero, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = 0;
L_8005120C:
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
    // addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // j           L_8005141C
    // sh          $t3, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r11;
    goto L_8005141C;
    // sh          $t3, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r11;
L_8005121C:
    // lbu         $a0, -0x7($s1)
    ctx->r4 = MEM_BU(-0X7, ctx->r17);
    // nop

    // andi        $v0, $a0, 0x80
    ctx->r2 = ctx->r4 & 0X80;
    // beq         $v0, $zero, L_80051250
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80051250;
    }
    // nop

    // lhu         $v1, -0x40($s1)
    ctx->r3 = MEM_HU(-0X40, ctx->r17);
    // nop

    // slt         $v0, $s0, $v1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8005126C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005126C;
    }
    // nop

    // lbu         $v0, -0x8($s1)
    ctx->r2 = MEM_BU(-0X8, ctx->r17);
    // j           L_80051774
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    goto L_80051774;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
L_80051250:
    // lhu         $v1, -0x40($s1)
    ctx->r3 = MEM_HU(-0X40, ctx->r17);
    // nop

    // addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // slti        $v0, $v0, 0xFFF
    ctx->r2 = SIGNED(ctx->r2) < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_80051774
    if (ctx->r2 != 0) {
        // addu        $v0, $v1, $s0
        ctx->r2 = ADD32(ctx->r3, ctx->r16);
        goto L_80051774;
    }
    // addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
    // sb          $a0, -0x4E($s1)
    MEM_B(-0X4E, ctx->r17) = ctx->r4;
L_8005126C:
    // sh          $zero, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = 0;
    // j           L_8005279C
    // sh          $zero, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = 0;
    goto L_8005279C;
    // sh          $zero, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = 0;
L_80051278:
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // bne         $v0, $zero, L_800512AC
    if (ctx->r2 != 0) {
        // sll         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3) << 2;
        goto L_800512AC;
    }
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // blez        $v0, L_800512AC
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_800512AC;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
    // nop

    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8004ED54
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    sub_8004ED54(rdram, ctx);
    goto after_14;
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    after_14:
L_800512AC:
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // addu        $v1, $v0, $s0
    ctx->r3 = ADD32(ctx->r2, ctx->r16);
    // andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // sltiu       $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_8005279C
    if (ctx->r2 != 0) {
        // sh          $v1, -0x40($s1)
        MEM_H(-0X40, ctx->r17) = ctx->r3;
        goto L_8005279C;
    }
    // sh          $v1, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r3;
    // andi        $v0, $v1, 0xFFF
    ctx->r2 = ctx->r3 & 0XFFF;
    // j           L_8005279C
    // sh          $v0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r2;
    goto L_8005279C;
    // sh          $v0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r2;
L_800512D4:
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x6DF8($v1)
    ctx->r2 = MEM_W(0X6DF8, ctx->r3);
    // nop

    // slti        $v0, $v0, 0x36
    ctx->r2 = SIGNED(ctx->r2) < 0X36 ? 1 : 0;
    // bne         $v0, $zero, L_8005130C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005130C;
    }
    // nop

    // lh          $v0, 0x0($s1)
    ctx->r2 = MEM_HS(0X0, ctx->r17);
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // slti        $v0, $v0, 0x258
    ctx->r2 = SIGNED(ctx->r2) < 0X258 ? 1 : 0;
    // bne         $v0, $zero, L_8005131C
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_8005131C;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
L_8005130C:
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // j           L_80051418
    // sh          $a2, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r6;
    goto L_80051418;
    // sh          $a2, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r6;
L_8005131C:
    // j           L_8005279C
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    goto L_8005279C;
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_80051324:
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $v0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r2;
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, 0xFFF
    ctx->r2 = SIGNED(ctx->r2) < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_8005279C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_8005279C;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sh          $zero, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = 0;
    // j           L_8005279C
    // sh          $v0, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r2;
    goto L_8005279C;
    // sh          $v0, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r2;
L_80051358:
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8005138C
    if (ctx->r2 != 0) {
        // sll         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3) << 2;
        goto L_8005138C;
    }
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // blez        $v0, L_8005138C
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_8005138C;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
    // nop

    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8004ED54
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    sub_8004ED54(rdram, ctx);
    goto after_15;
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    after_15:
L_8005138C:
    // lhu         $v1, -0x40($s1)
    ctx->r3 = MEM_HU(-0X40, ctx->r17);
    // nop

    // addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // slti        $v0, $v0, 0xFFF
    ctx->r2 = SIGNED(ctx->r2) < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_80051774
    if (ctx->r2 != 0) {
        // addu        $v0, $v1, $s0
        ctx->r2 = ADD32(ctx->r3, ctx->r16);
        goto L_80051774;
    }
    // addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
    // addiu       $v0, $zero, 0xFFF
    ctx->r2 = ADD32(0, 0XFFF);
    // addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // sh          $v0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r2;
    // j           L_8005279C
    // sh          $t2, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r10;
    goto L_8005279C;
    // sh          $t2, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r10;
L_800513B8:
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // bne         $v0, $zero, L_80051434
    if (ctx->r2 != 0) {
        // lui         $v1, 0x6666
        ctx->r3 = S32(0X6666 << 16);
        goto L_80051434;
    }
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t3
    ctx->r11 = hi;
    // sra         $v1, $t3, 3
    ctx->r3 = S32(ctx->r11) >> 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // bne         $a0, $zero, L_8005279C
    if (ctx->r4 != 0) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_8005279C;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // sh          $s2, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r18;
    // sb          $zero, 0x0($s5)
    MEM_B(0X0, ctx->r21) = 0;
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
L_80051418:
    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_8005141C:
    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8004ED54
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    sub_8004ED54(rdram, ctx);
    goto after_17;
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    after_17:
    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_80051434:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8005279C
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    goto L_8005279C;
    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_80051448:
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $v0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r2;
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_8005279C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
        goto L_8005279C;
    }
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // sh          $zero, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = 0;
    // sb          $zero, 0x0($s5)
    MEM_B(0X0, ctx->r21) = 0;
    // j           L_8005279C
    // sh          $v0, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r2;
    goto L_8005279C;
    // sh          $v0, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r2;
L_80051480:
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // bne         $v0, $zero, L_800514B4
    if (ctx->r2 != 0) {
        // sll         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3) << 2;
        goto L_800514B4;
    }
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // blez        $v0, L_800514B4
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_800514B4;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
    // nop

    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8004ED54
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    sub_8004ED54(rdram, ctx);
    goto after_18;
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    after_18:
L_800514B4:
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sh          $v0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r2;
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // slti        $v0, $v0, 0xFFF
    ctx->r2 = SIGNED(ctx->r2) < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_8005279C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0xFFF
        ctx->r2 = ADD32(0, 0XFFF);
        goto L_8005279C;
    }
    // addiu       $v0, $zero, 0xFFF
    ctx->r2 = ADD32(0, 0XFFF);
    // sh          $v0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r2;
    // sb          $zero, 0x0($s5)
    MEM_B(0X0, ctx->r21) = 0;
L_800514E4:
    // addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
L_800514E8:
    // j           L_8005279C
    // sh          $t2, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r10;
    goto L_8005279C;
    // sh          $t2, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r10;
L_800514F0:
    // j           L_8005279C
    // sh          $v0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r2;
    goto L_8005279C;
    // sh          $v0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r2;
L_800514F8:
    // addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // lbu         $v1, -0x8($s1)
    ctx->r3 = MEM_BU(-0X8, ctx->r17);
    // lhu         $a0, -0x44($s1)
    ctx->r4 = MEM_HU(-0X44, ctx->r17);
    // nop

    // beq         $a0, $t3, L_8005152C
    if (ctx->r4 == ctx->r11) {
        // sll         $s0, $v1, 2
        ctx->r16 = S32(ctx->r3) << 2;
        goto L_8005152C;
    }
    // sll         $s0, $v1, 2
    ctx->r16 = S32(ctx->r3) << 2;
    // slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8005279C
    if (ctx->r2 != 0) {
        // addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
        goto L_8005279C;
    }
    // addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // beq         $a0, $t2, L_80051660
    if (ctx->r4 == ctx->r10) {
        // nop
    
        goto L_80051660;
    }
    // nop

    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_8005152C:
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80051560
    if (ctx->r2 != 0) {
        // sll         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3) << 2;
        goto L_80051560;
    }
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // blez        $v0, L_80051560
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_80051560;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
    // nop

    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8004ED54
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    sub_8004ED54(rdram, ctx);
    goto after_19;
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    after_19:
L_80051560:
    // lhu         $v1, -0x40($s1)
    ctx->r3 = MEM_HU(-0X40, ctx->r17);
    // nop

    // addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // slti        $v0, $v0, 0xFFF
    ctx->r2 = SIGNED(ctx->r2) < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_80051774
    if (ctx->r2 != 0) {
        // addu        $v0, $v1, $s0
        ctx->r2 = ADD32(ctx->r3, ctx->r16);
        goto L_80051774;
    }
    // addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
    // lbu         $v1, -0x7($s1)
    ctx->r3 = MEM_BU(-0X7, ctx->r17);
    // addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // beq         $v1, $t3, L_80051598
    if (ctx->r3 == ctx->r11) {
        // addiu       $v0, $zero, 0xFC
        ctx->r2 = ADD32(0, 0XFC);
        goto L_80051598;
    }
    // addiu       $v0, $zero, 0xFC
    ctx->r2 = ADD32(0, 0XFC);
    // beq         $v1, $v0, L_80051598
    if (ctx->r3 == ctx->r2) {
        // addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
        goto L_80051598;
    }
    // addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // sb          $t2, -0x4E($s1)
    MEM_B(-0X4E, ctx->r17) = ctx->r10;
    // sh          $zero, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = 0;
L_80051598:
    // addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // lbu         $v0, -0x5($s1)
    ctx->r2 = MEM_BU(-0X5, ctx->r17);
    // addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // beq         $v0, $t2, L_8005279C
    if (ctx->r2 == ctx->r10) {
        // sh          $t3, -0x44($s1)
        MEM_H(-0X44, ctx->r17) = ctx->r11;
        goto L_8005279C;
    }
    // sh          $t3, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r11;
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s2, $v0, 0x2230
    ctx->r18 = ADD32(ctx->r2, 0X2230);
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // addiu       $s0, $s2, 0xA
    ctx->r16 = ADD32(ctx->r18, 0XA);
L_800515C0:
    // lbu         $v1, -0x5($s0)
    ctx->r3 = MEM_BU(-0X5, ctx->r16);
    // nop

    // beq         $v1, $zero, L_800515D8
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x32
        ctx->r2 = ADD32(0, 0X32);
        goto L_800515D8;
    }
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // bne         $v1, $v0, L_80051644
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80051644;
    }
    // nop

L_800515D8:
    // lbu         $v0, 0x45($s0)
    ctx->r2 = MEM_BU(0X45, ctx->r16);
    // nop

    // bne         $v0, $s4, L_80051644
    if (ctx->r2 != ctx->r20) {
        // nop
    
        goto L_80051644;
    }
    // nop

    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80051614
    if (ctx->r2 != 0) {
        // addiu       $t2, $zero, 0xFF
        ctx->r10 = ADD32(0, 0XFF);
        goto L_80051614;
    }
    // addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // addiu       $v0, $zero, 0xFC
    ctx->r2 = ADD32(0, 0XFC);
    // addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // sb          $v0, 0x3F($s0)
    MEM_B(0X3F, ctx->r16) = ctx->r2;
    // sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // sb          $zero, -0x8($s0)
    MEM_B(-0X8, ctx->r16) = 0;
    // j           L_80051644
    // sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    goto L_80051644;
    // sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
L_80051614:
    // bne         $v0, $t2, L_80051644
    if (ctx->r2 != ctx->r10) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80051644;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // sb          $t2, -0x8($s0)
    MEM_B(-0X8, ctx->r16) = ctx->r10;
    // sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8004ED54
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    sub_8004ED54(rdram, ctx);
    goto after_20;
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    after_20:
L_80051644:
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // slti        $v0, $s3, 0xF0
    ctx->r2 = SIGNED(ctx->r19) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_800515C0
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x58
        ctx->r18 = ADD32(ctx->r18, 0X58);
        goto L_800515C0;
    }
    // addiu       $s2, $s2, 0x58
    ctx->r18 = ADD32(ctx->r18, 0X58);
    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_80051660:
    // lhu         $v0, -0x40($s1)
    ctx->r2 = MEM_HU(-0X40, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80051694
    if (ctx->r2 != 0) {
        // sll         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3) << 2;
        goto L_80051694;
    }
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // blez        $v0, L_80051694
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_80051694;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lhu         $v0, -0x46($s1)
    ctx->r2 = MEM_HU(-0X46, ctx->r17);
    // nop

    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8004ED54
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    sub_8004ED54(rdram, ctx);
    goto after_21;
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    after_21:
L_80051694:
    // lhu         $v1, -0x40($s1)
    ctx->r3 = MEM_HU(-0X40, ctx->r17);
    // nop

    // addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // slti        $v0, $v0, 0xFFF
    ctx->r2 = SIGNED(ctx->r2) < 0XFFF ? 1 : 0;
    // bne         $v0, $zero, L_80051774
    if (ctx->r2 != 0) {
        // addu        $v0, $v1, $s0
        ctx->r2 = ADD32(ctx->r3, ctx->r16);
        goto L_80051774;
    }
    // addu        $v0, $v1, $s0
    ctx->r2 = ADD32(ctx->r3, ctx->r16);
    // lbu         $v0, -0x5($s1)
    ctx->r2 = MEM_BU(-0X5, ctx->r17);
    // addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // sb          $zero, -0x4E($s1)
    MEM_B(-0X4E, ctx->r17) = 0;
    // sh          $zero, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = 0;
    // beq         $v0, $t3, L_8005279C
    if (ctx->r2 == ctx->r11) {
        // sh          $zero, -0x44($s1)
        MEM_H(-0X44, ctx->r17) = 0;
        goto L_8005279C;
    }
    // sh          $zero, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = 0;
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s2, $v0, 0x2230
    ctx->r18 = ADD32(ctx->r2, 0X2230);
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // addiu       $s0, $s2, 0xA
    ctx->r16 = ADD32(ctx->r18, 0XA);
L_800516D8:
    // lbu         $v0, -0x5($s0)
    ctx->r2 = MEM_BU(-0X5, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80051758
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80051758;
    }
    // nop

    // lbu         $v0, 0x45($s0)
    ctx->r2 = MEM_BU(0X45, ctx->r16);
    // nop

    // bne         $v0, $s4, L_80051758
    if (ctx->r2 != ctx->r20) {
        // nop
    
        goto L_80051758;
    }
    // nop

    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80051724
    if (ctx->r2 != 0) {
        // addiu       $t3, $zero, 0xFF
        ctx->r11 = ADD32(0, 0XFF);
        goto L_80051724;
    }
    // addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // addiu       $v0, $zero, 0xFC
    ctx->r2 = ADD32(0, 0XFC);
    // addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // sb          $v0, 0x3F($s0)
    MEM_B(0X3F, ctx->r16) = ctx->r2;
    // sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // sb          $zero, -0x8($s0)
    MEM_B(-0X8, ctx->r16) = 0;
    // j           L_80051758
    // sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    goto L_80051758;
    // sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
L_80051724:
    // bne         $v0, $t3, L_80051758
    if (ctx->r2 != ctx->r11) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80051758;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // sb          $zero, 0x3F($s0)
    MEM_B(0X3F, ctx->r16) = 0;
    // sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // sb          $t3, -0x8($s0)
    MEM_B(-0X8, ctx->r16) = ctx->r11;
    // sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x8004ED54
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    sub_8004ED54(rdram, ctx);
    goto after_22;
    // addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, 0XD0);
    after_22:
L_80051758:
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // slti        $v0, $s3, 0xF0
    ctx->r2 = SIGNED(ctx->r19) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_800516D8
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x58
        ctx->r18 = ADD32(ctx->r18, 0X58);
        goto L_800516D8;
    }
    // addiu       $s2, $s2, 0x58
    ctx->r18 = ADD32(ctx->r18, 0X58);
    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_80051774:
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // j           L_8005279C
    // sh          $v0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r2;
    goto L_8005279C;
    // sh          $v0, -0x40($s1)
    MEM_H(-0X40, ctx->r17) = ctx->r2;
L_80051780:
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_23;
    // nop

    after_23:
    // jal         0x80078AC4
    // srl         $s0, $v0, 8
    ctx->r16 = S32(U32(ctx->r2) >> 8);
    rand_recomp(rdram, ctx);
    goto after_24;
    // srl         $s0, $v0, 8
    ctx->r16 = S32(U32(ctx->r2) >> 8);
    after_24:
    // jal         0x80078AC4
    // srl         $s3, $v0, 6
    ctx->r19 = S32(U32(ctx->r2) >> 6);
    rand_recomp(rdram, ctx);
    goto after_25;
    // srl         $s3, $v0, 6
    ctx->r19 = S32(U32(ctx->r2) >> 6);
    after_25:
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // nop

    // beq         $v1, $zero, L_800517B0
    if (ctx->r3 == 0) {
        // srl         $s2, $v0, 8
        ctx->r18 = S32(U32(ctx->r2) >> 8);
        goto L_800517B0;
    }
    // srl         $s2, $v0, 8
    ctx->r18 = S32(U32(ctx->r2) >> 8);
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
L_800517B0:
    // lhu         $v0, -0x44($s1)
    ctx->r2 = MEM_HU(-0X44, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80051894
    if (ctx->r2 != 0) {
        // addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
        goto L_80051894;
    }
    // addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // lw          $v0, -0x34($s1)
    ctx->r2 = MEM_W(-0X34, ctx->r17);
    // nop

    // slti        $v0, $v0, 0x400
    ctx->r2 = SIGNED(ctx->r2) < 0X400 ? 1 : 0;
    // beq         $v0, $zero, L_80051814
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80051814;
    }
    // nop

    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80051814
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
        goto L_80051814;
    }
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    memset_recomp(rdram, ctx);
    goto after_26;
    // addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_26:
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(0X70, ctx->r29);
    // addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // jal         0x8003DBE0
    // sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    sub_8003DBE0(rdram, ctx);
    goto after_27;
    // sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    after_27:
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
L_80051814:
    // lh          $v0, -0x12($s1)
    ctx->r2 = MEM_HS(-0X12, ctx->r17);
    // nop

    // slti        $v0, $v0, 0x1001
    ctx->r2 = SIGNED(ctx->r2) < 0X1001 ? 1 : 0;
    // bne         $v0, $zero, L_80051844
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80051844;
    }
    // nop

    // lhu         $v0, -0x14($s1)
    ctx->r2 = MEM_HU(-0X14, ctx->r17);
    // lhu         $v1, -0x10($s1)
    ctx->r3 = MEM_HU(-0X10, ctx->r17);
    // addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // addiu       $v1, $v1, -0x200
    ctx->r3 = ADD32(ctx->r3, -0X200);
    // j           L_8005185C
    // subu        $v1, $v1, $s2
    ctx->r3 = SUB32(ctx->r3, ctx->r18);
    goto L_8005185C;
    // subu        $v1, $v1, $s2
    ctx->r3 = SUB32(ctx->r3, ctx->r18);
L_80051844:
    // lhu         $v0, -0x14($s1)
    ctx->r2 = MEM_HU(-0X14, ctx->r17);
    // lhu         $v1, -0x10($s1)
    ctx->r3 = MEM_HU(-0X10, ctx->r17);
    // addiu       $v0, $v0, 0x200
    ctx->r2 = ADD32(ctx->r2, 0X200);
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // addiu       $v1, $v1, 0x200
    ctx->r3 = ADD32(ctx->r3, 0X200);
    // addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
L_8005185C:
    // sh          $v0, -0x14($s1)
    MEM_H(-0X14, ctx->r17) = ctx->r2;
    // sh          $v1, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r3;
    // lhu         $v0, -0x12($s1)
    ctx->r2 = MEM_HU(-0X12, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x4E8
    ctx->r2 = ADD32(ctx->r2, 0X4E8);
    // addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // sh          $v0, -0x12($s1)
    MEM_H(-0X12, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x2001
    ctx->r2 = SIGNED(ctx->r2) < 0X2001 ? 1 : 0;
    // bne         $v0, $zero, L_8005279C
    if (ctx->r2 != 0) {
        // addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
        goto L_8005279C;
    }
    // addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // j           L_8005279C
    // sh          $t2, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r10;
    goto L_8005279C;
    // sh          $t2, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r10;
L_80051894:
    // bne         $v0, $t3, L_800518B0
    if (ctx->r2 != ctx->r11) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_800518B0;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sh          $zero, -0x14($s1)
    MEM_H(-0X14, ctx->r17) = 0;
    // sh          $zero, -0x12($s1)
    MEM_H(-0X12, ctx->r17) = 0;
    // sh          $zero, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = 0;
    // j           L_8005279C
    // sh          $v0, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r2;
    goto L_8005279C;
    // sh          $v0, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r2;
L_800518B0:
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_28;
    // nop

    after_28:
    // slti        $v0, $v0, 0x800
    ctx->r2 = SIGNED(ctx->r2) < 0X800 ? 1 : 0;
    // beq         $v0, $zero, L_8005279C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005279C;
    }
    // nop

    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8005279C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005279C;
    }
    // nop

    // j           L_8005279C
    // sh          $zero, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = 0;
    goto L_8005279C;
    // sh          $zero, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = 0;
L_800518DC:
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(0X60, ctx->r29);
    // addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // subu        $a1, $a1, $t2
    ctx->r5 = SUB32(ctx->r5, ctx->r10);
    // jal         0x80050468
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_80050468(rdram, ctx);
    goto after_29;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_29:
    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_800518FC:
    // lbu         $v0, -0x8($s1)
    ctx->r2 = MEM_BU(-0X8, ctx->r17);
    // nop

    // beq         $v0, $zero, L_80051910
    if (ctx->r2 == 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80051910;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sb          $v0, -0x8($s1)
    MEM_B(-0X8, ctx->r17) = ctx->r2;
L_80051910:
    // lh          $v1, -0x14($s1)
    ctx->r3 = MEM_HS(-0X14, ctx->r17);
    // nop

    // bgez        $v1, L_80051924
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80051924;
    }
    // nop

    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_80051924:
    // lw          $v0, -0x34($s1)
    ctx->r2 = MEM_W(-0X34, ctx->r17);
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_800519C4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800519C4;
    }
    // nop

    // lbu         $v0, -0x8($s1)
    ctx->r2 = MEM_BU(-0X8, ctx->r17);
    // nop

    // bne         $v0, $zero, L_800519C4
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_800519C4;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // lbu         $v1, -0x4B($s1)
    ctx->r3 = MEM_BU(-0X4B, ctx->r17);
    // nop

    // bne         $v1, $v0, L_80051984
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_80051984;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    memset_recomp(rdram, ctx);
    goto after_30;
    // addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_30:
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(0X70, ctx->r29);
    // addiu       $v0, $zero, 0xB4
    ctx->r2 = ADD32(0, 0XB4);
    // j           L_800519B4
    // sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    goto L_800519B4;
    // sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
L_80051984:
    // bne         $v1, $v0, L_800519C4
    if (ctx->r3 != ctx->r2) {
        // addiu       $s0, $sp, 0x48
        ctx->r16 = ADD32(ctx->r29, 0X48);
        goto L_800519C4;
    }
    // addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    memset_recomp(rdram, ctx);
    goto after_31;
    // addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_31:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // addiu       $a2, $zero, 0x1400
    ctx->r6 = ADD32(0, 0X1400);
    // lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(0X70, ctx->r29);
    // addiu       $v0, $zero, 0x87
    ctx->r2 = ADD32(0, 0X87);
    // sh          $v0, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r2;
L_800519B4:
    // jal         0x8003DBE0
    // nop

    sub_8003DBE0(rdram, ctx);
    goto after_32;
    // nop

    after_32:
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // sb          $v0, -0x8($s1)
    MEM_B(-0X8, ctx->r17) = ctx->r2;
L_800519C4:
    // lhu         $v1, -0x44($s1)
    ctx->r3 = MEM_HU(-0X44, ctx->r17);
    // nop

    // sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80051A70
    if (ctx->r2 != 0) {
        // sltiu       $v0, $v1, 0x3
        ctx->r2 = ctx->r3 < 0X3 ? 1 : 0;
        goto L_80051A70;
    }
    // sltiu       $v0, $v1, 0x3
    ctx->r2 = ctx->r3 < 0X3 ? 1 : 0;
    // lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // lh          $v1, 0x0($s1)
    ctx->r3 = MEM_HS(0X0, ctx->r17);
    // addiu       $t3, $t3, 0x310
    ctx->r11 = ADD32(ctx->r11, 0X310);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // lw          $v1, 0x1F44($v0)
    ctx->r3 = MEM_W(0X1F44, ctx->r2);
    // lw          $a0, 0x1F48($v0)
    ctx->r4 = MEM_W(0X1F48, ctx->r2);
    // lw          $a1, 0x1F4C($v0)
    ctx->r5 = MEM_W(0X1F4C, ctx->r2);
    // lw          $a2, 0x1F50($v0)
    ctx->r6 = MEM_W(0X1F50, ctx->r2);
    // sw          $v1, -0x2C($s1)
    MEM_W(-0X2C, ctx->r17) = ctx->r3;
    // sw          $a0, -0x28($s1)
    MEM_W(-0X28, ctx->r17) = ctx->r4;
    // sw          $a1, -0x24($s1)
    MEM_W(-0X24, ctx->r17) = ctx->r5;
    // sw          $a2, -0x20($s1)
    MEM_W(-0X20, ctx->r17) = ctx->r6;
    // lh          $a0, -0x1A($s1)
    ctx->r4 = MEM_HS(-0X1A, ctx->r17);
    // lw          $v0, -0x28($s1)
    ctx->r2 = MEM_W(-0X28, ctx->r17);
    // sh          $zero, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = 0;
    // sh          $zero, -0x12($s1)
    MEM_H(-0X12, ctx->r17) = 0;
    // sh          $zero, -0x14($s1)
    MEM_H(-0X14, ctx->r17) = 0;
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // addiu       $v0, $v0, -0x500
    ctx->r2 = ADD32(ctx->r2, -0X500);
    // jal         0x800744C4
    // sw          $v0, -0x28($s1)
    MEM_W(-0X28, ctx->r17) = ctx->r2;
    rcos(rdram, ctx);
    goto after_33;
    // sw          $v0, -0x28($s1)
    MEM_W(-0X28, ctx->r17) = ctx->r2;
    after_33:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
    // bgez        $v0, L_80051A58
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051A58;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80051A58:
    // lh          $a0, -0x1A($s1)
    ctx->r4 = MEM_HS(-0X1A, ctx->r17);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // j           L_80051D44
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    goto L_80051D44;
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
L_80051A70:
    // bne         $v0, $zero, L_80051B58
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80051B58;
    }
    // nop

    // lh          $a0, -0x1A($s1)
    ctx->r4 = MEM_HS(-0X1A, ctx->r17);
    // jal         0x800744C4
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    rcos(rdram, ctx);
    goto after_34;
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    after_34:
    // lhu         $v1, -0x44($s1)
    ctx->r3 = MEM_HU(-0X44, ctx->r17);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80051AA0
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051AA0;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80051AA0:
    // lh          $a0, -0x1A($s1)
    ctx->r4 = MEM_HS(-0X1A, ctx->r17);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // lhu         $v0, -0x44($s1)
    ctx->r2 = MEM_HU(-0X44, ctx->r17);
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // jal         0x800743F4
    // sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
    rsin(rdram, ctx);
    goto after_35;
    // sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
    after_35:
    // lhu         $v1, -0x44($s1)
    ctx->r3 = MEM_HU(-0X44, ctx->r17);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80051ADC
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051ADC;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80051ADC:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // jal         0x80078AC4
    // sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_36;
    // sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    after_36:
    // lh          $a0, 0x2($s1)
    ctx->r4 = MEM_HS(0X2, ctx->r17);
    // bgez        $v0, L_80051AF8
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051AF8;
    }
    // nop

    // addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
L_80051AF8:
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // lw          $v1, -0x2C($s1)
    ctx->r3 = MEM_W(-0X2C, ctx->r17);
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80078AC4
    // sw          $v1, -0x2C($s1)
    MEM_W(-0X2C, ctx->r17) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_37;
    // sw          $v1, -0x2C($s1)
    MEM_W(-0X2C, ctx->r17) = ctx->r3;
    after_37:
    // lh          $a0, 0x4($s1)
    ctx->r4 = MEM_HS(0X4, ctx->r17);
    // bgez        $v0, L_80051B20
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051B20;
    }
    // nop

    // addiu       $v0, $v0, 0x7FF
    ctx->r2 = ADD32(ctx->r2, 0X7FF);
L_80051B20:
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // lw          $v1, -0x28($s1)
    ctx->r3 = MEM_W(-0X28, ctx->r17);
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80078AC4
    // sw          $v1, -0x28($s1)
    MEM_W(-0X28, ctx->r17) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_38;
    // sw          $v1, -0x28($s1)
    MEM_W(-0X28, ctx->r17) = ctx->r3;
    after_38:
    // lh          $a0, 0x6($s1)
    ctx->r4 = MEM_HS(0X6, ctx->r17);
    // bgez        $v0, L_80051B48
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051B48;
    }
    // nop

    // addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
L_80051B48:
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // lw          $v1, -0x24($s1)
    ctx->r3 = MEM_W(-0X24, ctx->r17);
    // j           L_80051F54
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    goto L_80051F54;
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
L_80051B58:
    // lh          $a0, -0x1A($s1)
    ctx->r4 = MEM_HS(-0X1A, ctx->r17);
    // jal         0x800744C4
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    rcos(rdram, ctx);
    goto after_39;
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    after_39:
    // lhu         $v1, -0x44($s1)
    ctx->r3 = MEM_HU(-0X44, ctx->r17);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80051B80
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051B80;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80051B80:
    // lh          $a0, -0x1A($s1)
    ctx->r4 = MEM_HS(-0X1A, ctx->r17);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // lhu         $v0, -0x44($s1)
    ctx->r2 = MEM_HU(-0X44, ctx->r17);
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // j           L_80051EB8
    // sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
    goto L_80051EB8;
    // sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
L_80051BA0:
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(0X60, ctx->r29);
    // addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // subu        $a1, $a1, $t2
    ctx->r5 = SUB32(ctx->r5, ctx->r10);
    // jal         0x80050564
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_80050564(rdram, ctx);
    goto after_40;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_40:
    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_80051BC0:
    // lbu         $v0, -0x8($s1)
    ctx->r2 = MEM_BU(-0X8, ctx->r17);
    // nop

    // beq         $v0, $zero, L_80051BD4
    if (ctx->r2 == 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80051BD4;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sb          $v0, -0x8($s1)
    MEM_B(-0X8, ctx->r17) = ctx->r2;
L_80051BD4:
    // lh          $v1, -0x14($s1)
    ctx->r3 = MEM_HS(-0X14, ctx->r17);
    // nop

    // bgez        $v1, L_80051BE8
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80051BE8;
    }
    // nop

    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_80051BE8:
    // lw          $v0, -0x34($s1)
    ctx->r2 = MEM_W(-0X34, ctx->r17);
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80051C3C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80051C3C;
    }
    // nop

    // lbu         $v0, -0x8($s1)
    ctx->r2 = MEM_BU(-0X8, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80051C3C
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
        goto L_80051C3C;
    }
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    memset_recomp(rdram, ctx);
    goto after_41;
    // addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_41:
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(0X70, ctx->r29);
    // addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // jal         0x8003DBE0
    // sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    sub_8003DBE0(rdram, ctx);
    goto after_42;
    // sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    after_42:
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // sb          $v0, -0x8($s1)
    MEM_B(-0X8, ctx->r17) = ctx->r2;
L_80051C3C:
    // lhu         $v1, -0x44($s1)
    ctx->r3 = MEM_HU(-0X44, ctx->r17);
    // nop

    // sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80051D94
    if (ctx->r2 != 0) {
        // sltiu       $v0, $v1, 0x3
        ctx->r2 = ctx->r3 < 0X3 ? 1 : 0;
        goto L_80051D94;
    }
    // sltiu       $v0, $v1, 0x3
    ctx->r2 = ctx->r3 < 0X3 ? 1 : 0;
    // lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // lh          $v1, 0x0($s1)
    ctx->r3 = MEM_HS(0X0, ctx->r17);
    // addiu       $t3, $t3, 0x310
    ctx->r11 = ADD32(ctx->r11, 0X310);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // lw          $v1, 0x1F44($v0)
    ctx->r3 = MEM_W(0X1F44, ctx->r2);
    // lw          $a0, 0x1F48($v0)
    ctx->r4 = MEM_W(0X1F48, ctx->r2);
    // lw          $a1, 0x1F4C($v0)
    ctx->r5 = MEM_W(0X1F4C, ctx->r2);
    // lw          $a2, 0x1F50($v0)
    ctx->r6 = MEM_W(0X1F50, ctx->r2);
    // sw          $v1, -0x2C($s1)
    MEM_W(-0X2C, ctx->r17) = ctx->r3;
    // sw          $a0, -0x28($s1)
    MEM_W(-0X28, ctx->r17) = ctx->r4;
    // sw          $a1, -0x24($s1)
    MEM_W(-0X24, ctx->r17) = ctx->r5;
    // sw          $a2, -0x20($s1)
    MEM_W(-0X20, ctx->r17) = ctx->r6;
    // lh          $a0, -0x1A($s1)
    ctx->r4 = MEM_HS(-0X1A, ctx->r17);
    // jal         0x800744C4
    // nop

    rcos(rdram, ctx);
    goto after_43;
    // nop

    after_43:
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) << 8;
    // bgez        $v1, L_80051CBC
    if (SIGNED(ctx->r3) >= 0) {
        // sra         $a1, $v1, 12
        ctx->r5 = S32(ctx->r3) >> 12;
        goto L_80051CBC;
    }
    // sra         $a1, $v1, 12
    ctx->r5 = S32(ctx->r3) >> 12;
    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
    // sra         $a1, $v1, 12
    ctx->r5 = S32(ctx->r3) >> 12;
L_80051CBC:
    // lh          $a0, -0x1A($s1)
    ctx->r4 = MEM_HS(-0X1A, ctx->r17);
    // lw          $v0, -0x2C($s1)
    ctx->r2 = MEM_W(-0X2C, ctx->r17);
    // lw          $v1, -0x28($s1)
    ctx->r3 = MEM_W(-0X28, ctx->r17);
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // addiu       $v1, $v1, -0x7D0
    ctx->r3 = ADD32(ctx->r3, -0X7D0);
    // sw          $v0, -0x2C($s1)
    MEM_W(-0X2C, ctx->r17) = ctx->r2;
    // jal         0x800743F4
    // sw          $v1, -0x28($s1)
    MEM_W(-0X28, ctx->r17) = ctx->r3;
    rsin(rdram, ctx);
    goto after_44;
    // sw          $v1, -0x28($s1)
    MEM_W(-0X28, ctx->r17) = ctx->r3;
    after_44:
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) << 8;
    // bgez        $v1, L_80051CF4
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80051CF4;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80051CF4:
    // lh          $a0, -0x1A($s1)
    ctx->r4 = MEM_HS(-0X1A, ctx->r17);
    // lw          $v0, -0x24($s1)
    ctx->r2 = MEM_W(-0X24, ctx->r17);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // sh          $zero, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = 0;
    // sh          $zero, -0x12($s1)
    MEM_H(-0X12, ctx->r17) = 0;
    // sh          $zero, -0x14($s1)
    MEM_H(-0X14, ctx->r17) = 0;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x800744C4
    // sw          $v0, -0x24($s1)
    MEM_W(-0X24, ctx->r17) = ctx->r2;
    rcos(rdram, ctx);
    goto after_45;
    // sw          $v0, -0x24($s1)
    MEM_W(-0X24, ctx->r17) = ctx->r2;
    after_45:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
    // bgez        $v0, L_80051D30
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051D30;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80051D30:
    // lh          $a0, -0x1A($s1)
    ctx->r4 = MEM_HS(-0X1A, ctx->r17);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
L_80051D44:
    // jal         0x800743F4
    // nop

    rsin(rdram, ctx);
    goto after_46;
    // nop

    after_46:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
    // bgez        $v0, L_80051D64
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051D64;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80051D64:
    // lh          $a0, 0x2($s1)
    ctx->r4 = MEM_HS(0X2, ctx->r17);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    // lw          $v0, -0x2C($s1)
    ctx->r2 = MEM_W(-0X2C, ctx->r17);
    // lh          $a1, 0x6($s1)
    ctx->r5 = MEM_HS(0X6, ctx->r17);
    // lw          $v1, -0x24($s1)
    ctx->r3 = MEM_W(-0X24, ctx->r17);
    // sh          $zero, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = 0;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v0, -0x2C($s1)
    MEM_W(-0X2C, ctx->r17) = ctx->r2;
    // j           L_8005279C
    // sw          $v1, -0x24($s1)
    MEM_W(-0X24, ctx->r17) = ctx->r3;
    goto L_8005279C;
    // sw          $v1, -0x24($s1)
    MEM_W(-0X24, ctx->r17) = ctx->r3;
L_80051D94:
    // bne         $v0, $zero, L_80051E78
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80051E78;
    }
    // nop

    // lh          $a0, -0x1A($s1)
    ctx->r4 = MEM_HS(-0X1A, ctx->r17);
    // jal         0x800744C4
    // nop

    rcos(rdram, ctx);
    goto after_47;
    // nop

    after_47:
    // lhu         $v1, -0x44($s1)
    ctx->r3 = MEM_HU(-0X44, ctx->r17);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80051DC4
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051DC4;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80051DC4:
    // lh          $a0, -0x1A($s1)
    ctx->r4 = MEM_HS(-0X1A, ctx->r17);
    // lhu         $v1, -0x44($s1)
    ctx->r3 = MEM_HU(-0X44, ctx->r17);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3) << 6;
    // jal         0x800743F4
    // sh          $v1, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r3;
    rsin(rdram, ctx);
    goto after_48;
    // sh          $v1, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r3;
    after_48:
    // lhu         $v1, -0x44($s1)
    ctx->r3 = MEM_HU(-0X44, ctx->r17);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80051DFC
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051DFC;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80051DFC:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // jal         0x80078AC4
    // sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_49;
    // sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    after_49:
    // lh          $a0, 0x2($s1)
    ctx->r4 = MEM_HS(0X2, ctx->r17);
    // bgez        $v0, L_80051E18
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051E18;
    }
    // nop

    // addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
L_80051E18:
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // lw          $v1, -0x2C($s1)
    ctx->r3 = MEM_W(-0X2C, ctx->r17);
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80078AC4
    // sw          $v1, -0x2C($s1)
    MEM_W(-0X2C, ctx->r17) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_50;
    // sw          $v1, -0x2C($s1)
    MEM_W(-0X2C, ctx->r17) = ctx->r3;
    after_50:
    // lh          $a0, 0x4($s1)
    ctx->r4 = MEM_HS(0X4, ctx->r17);
    // bgez        $v0, L_80051E40
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051E40;
    }
    // nop

    // addiu       $v0, $v0, 0x7FF
    ctx->r2 = ADD32(ctx->r2, 0X7FF);
L_80051E40:
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // lw          $v1, -0x28($s1)
    ctx->r3 = MEM_W(-0X28, ctx->r17);
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80078AC4
    // sw          $v1, -0x28($s1)
    MEM_W(-0X28, ctx->r17) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_51;
    // sw          $v1, -0x28($s1)
    MEM_W(-0X28, ctx->r17) = ctx->r3;
    after_51:
    // lh          $a0, 0x6($s1)
    ctx->r4 = MEM_HS(0X6, ctx->r17);
    // bgez        $v0, L_80051E68
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051E68;
    }
    // nop

    // addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
L_80051E68:
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // lw          $v1, -0x24($s1)
    ctx->r3 = MEM_W(-0X24, ctx->r17);
    // j           L_80051F54
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    goto L_80051F54;
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
L_80051E78:
    // lh          $a0, -0x1A($s1)
    ctx->r4 = MEM_HS(-0X1A, ctx->r17);
    // jal         0x800744C4
    // nop

    rcos(rdram, ctx);
    goto after_52;
    // nop

    after_52:
    // lhu         $v1, -0x44($s1)
    ctx->r3 = MEM_HU(-0X44, ctx->r17);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80051EA0
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051EA0;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80051EA0:
    // lh          $a0, -0x1A($s1)
    ctx->r4 = MEM_HS(-0X1A, ctx->r17);
    // lhu         $v1, -0x44($s1)
    ctx->r3 = MEM_HU(-0X44, ctx->r17);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // sll         $v1, $v1, 7
    ctx->r3 = S32(ctx->r3) << 7;
    // sh          $v1, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r3;
L_80051EB8:
    // jal         0x800743F4
    // nop

    rsin(rdram, ctx);
    goto after_53;
    // nop

    after_53:
    // lhu         $v1, -0x44($s1)
    ctx->r3 = MEM_HU(-0X44, ctx->r17);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80051EDC
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051EDC;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80051EDC:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // jal         0x80078AC4
    // sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_54;
    // sh          $v0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r2;
    after_54:
    // lh          $a0, 0x2($s1)
    ctx->r4 = MEM_HS(0X2, ctx->r17);
    // bgez        $v0, L_80051EF8
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051EF8;
    }
    // nop

    // addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
L_80051EF8:
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // lw          $v1, -0x2C($s1)
    ctx->r3 = MEM_W(-0X2C, ctx->r17);
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80078AC4
    // sw          $v1, -0x2C($s1)
    MEM_W(-0X2C, ctx->r17) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_55;
    // sw          $v1, -0x2C($s1)
    MEM_W(-0X2C, ctx->r17) = ctx->r3;
    after_55:
    // lh          $a0, 0x4($s1)
    ctx->r4 = MEM_HS(0X4, ctx->r17);
    // bgez        $v0, L_80051F20
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051F20;
    }
    // nop

    // addiu       $v0, $v0, 0x7FF
    ctx->r2 = ADD32(ctx->r2, 0X7FF);
L_80051F20:
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // lw          $v1, -0x28($s1)
    ctx->r3 = MEM_W(-0X28, ctx->r17);
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jal         0x80078AC4
    // sw          $v1, -0x28($s1)
    MEM_W(-0X28, ctx->r17) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_56;
    // sw          $v1, -0x28($s1)
    MEM_W(-0X28, ctx->r17) = ctx->r3;
    after_56:
    // lh          $a0, 0x6($s1)
    ctx->r4 = MEM_HS(0X6, ctx->r17);
    // bgez        $v0, L_80051F48
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80051F48;
    }
    // nop

    // addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
L_80051F48:
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // lw          $v1, -0x24($s1)
    ctx->r3 = MEM_W(-0X24, ctx->r17);
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
L_80051F54:
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, -0x14($s1)
    ctx->r2 = MEM_HU(-0X14, ctx->r17);
    // sw          $v1, -0x24($s1)
    MEM_W(-0X24, ctx->r17) = ctx->r3;
    // lhu         $v1, -0x12($s1)
    ctx->r3 = MEM_HU(-0X12, ctx->r17);
    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // sh          $v0, -0x14($s1)
    MEM_H(-0X14, ctx->r17) = ctx->r2;
    // lhu         $v0, -0x10($s1)
    ctx->r2 = MEM_HU(-0X10, ctx->r17);
    // addiu       $v1, $v1, 0x400
    ctx->r3 = ADD32(ctx->r3, 0X400);
    // sh          $v1, -0x12($s1)
    MEM_H(-0X12, ctx->r17) = ctx->r3;
    // lhu         $v1, -0x44($s1)
    ctx->r3 = MEM_HU(-0X44, ctx->r17);
    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sh          $v0, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r2;
    // j           L_8005279C
    // sh          $v1, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r3;
    goto L_8005279C;
    // sh          $v1, -0x44($s1)
    MEM_H(-0X44, ctx->r17) = ctx->r3;
L_80051F90:
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(0X60, ctx->r29);
    // addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // subu        $a1, $a1, $t2
    ctx->r5 = SUB32(ctx->r5, ctx->r10);
    // jal         0x8005066C
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_8005066C(rdram, ctx);
    goto after_57;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_57:
    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_80051FB0:
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // lw          $a0, -0x2C($s1)
    ctx->r4 = MEM_W(-0X2C, ctx->r17);
    // lw          $a1, -0x24($s1)
    ctx->r5 = MEM_W(-0X24, ctx->r17);
    // lw          $v0, -0x28($s1)
    ctx->r2 = MEM_W(-0X28, ctx->r17);
    // sra         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4) >> 12;
    // sra         $a1, $a1, 12
    ctx->r5 = S32(ctx->r5) >> 12;
    // jal         0x8004FC94
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8004FC94(rdram, ctx);
    goto after_58;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_58:
    // bne         $v0, $zero, L_80051FF0
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80051FF0;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lh          $v0, 0x5920($v0)
    ctx->r2 = MEM_HS(0X5920, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8005279C
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_8005279C;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_80051FF0:
    // addiu       $v0, $v0, -0x2E80
    ctx->r2 = ADD32(ctx->r2, -0X2E80);
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // lhu         $v0, 0x36($v0)
    ctx->r2 = MEM_HU(0X36, ctx->r2);
    // nop

    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // beq         $v1, $zero, L_80052058
    if (ctx->r3 == 0) {
        // lui         $t3, 0x801C
        ctx->r11 = S32(0X801C << 16);
        goto L_80052058;
    }
    // lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // addiu       $t3, $t3, -0x5EC8
    ctx->r11 = ADD32(ctx->r11, -0X5EC8);
    // lbu         $v0, 0x6169($t3)
    ctx->r2 = MEM_BU(0X6169, ctx->r11);
    // nop

    // bne         $v0, $zero, L_80052058
    if (ctx->r2 != 0) {
        // lui         $v1, 0xFF
        ctx->r3 = S32(0XFF << 16);
        goto L_80052058;
    }
    // lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $v1, L_80052058
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_80052058;
    }
    // nop

    // lw          $v0, -0x8($s1)
    ctx->r2 = MEM_W(-0X8, ctx->r17);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $v1, L_80052058
    if (ctx->r2 == ctx->r3) {
        // addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
        goto L_80052058;
    }
    // addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // jal         0x8003EAD0
    // sb          $t2, 0x6169($t3)
    MEM_B(0X6169, ctx->r11) = ctx->r10;
    sub_8003EAD0(rdram, ctx);
    goto after_59;
    // sb          $t2, 0x6169($t3)
    MEM_B(0X6169, ctx->r11) = ctx->r10;
    after_59:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_60;
    // nop

    after_60:
L_80052058:
    // lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // addiu       $t3, $t3, -0x5EC8
    ctx->r11 = ADD32(ctx->r11, -0X5EC8);
    // lbu         $v0, 0x6169($t3)
    ctx->r2 = MEM_BU(0X6169, ctx->r11);
    // addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // bne         $v0, $t2, L_80052160
    if (ctx->r2 != ctx->r10) {
        // lui         $t2, 0x801C
        ctx->r10 = S32(0X801C << 16);
        goto L_80052160;
    }
    // lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // addiu       $t3, $t3, -0x5EC8
    ctx->r11 = ADD32(ctx->r11, -0X5EC8);
    // addiu       $s3, $t3, 0x2E60
    ctx->r19 = ADD32(ctx->r11, 0X2E60);
    // jal         0x80015AD4
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_61;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    after_61:
    // addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // sb          $t2, 0x21E($s6)
    MEM_B(0X21E, ctx->r22) = ctx->r10;
    // addiu       $s4, $zero, 0x7
    ctx->r20 = ADD32(0, 0X7);
    // lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // addiu       $t3, $t3, -0x5EC8
    ctx->r11 = ADD32(ctx->r11, -0X5EC8);
    // addiu       $s0, $t3, 0x2EB6
    ctx->r16 = ADD32(ctx->r11, 0X2EB6);
L_8005209C:
    // sh          $zero, -0x2C($s0)
    MEM_H(-0X2C, ctx->r16) = 0;
    // lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(0X0, ctx->r19);
    // addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // beq         $v0, $t2, L_80052134
    if (ctx->r2 == ctx->r10) {
        // nop
    
        goto L_80052134;
    }
    // nop

    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_62;
    // nop

    after_62:
    // addiu       $a1, $s3, 0x74
    ctx->r5 = ADD32(ctx->r19, 0X74);
    // addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // sll         $a3, $v0, 2
    ctx->r7 = S32(ctx->r2) << 2;
    // addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // sra         $a3, $a3, 15
    ctx->r7 = S32(ctx->r7) >> 15;
    // lbu         $v0, -0x4B($s0)
    ctx->r2 = MEM_BU(-0X4B, ctx->r16);
    // addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // jal         0x80058220
    // addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    sub_80058220(rdram, ctx);
    goto after_63;
    // addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_63:
    // lh          $a0, 0x0($s0)
    ctx->r4 = MEM_HS(0X0, ctx->r16);
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // jal         0x800744C4
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    rcos(rdram, ctx);
    goto after_64;
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    after_64:
    // bgez        $v0, L_80052108
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80052108;
    }
    // nop

    // addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
L_80052108:
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // sh          $v0, 0x320($gp)
    MEM_H(0X320, ctx->r28) = ctx->r2;
    // lh          $a0, 0x0($s0)
    ctx->r4 = MEM_HS(0X0, ctx->r16);
    // jal         0x800743F4
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    rsin(rdram, ctx);
    goto after_65;
    // addiu       $a0, $a0, -0x400
    ctx->r4 = ADD32(ctx->r4, -0X400);
    after_65:
    // bgez        $v0, L_80052128
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80052128;
    }
    // nop

    // addiu       $v0, $v0, 0xFF
    ctx->r2 = ADD32(ctx->r2, 0XFF);
L_80052128:
    // sra         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) >> 8;
    // sh          $v0, 0x324($gp)
    MEM_H(0X324, ctx->r28) = ctx->r2;
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80052134:
    // addiu       $s0, $s0, 0xD4
    ctx->r16 = ADD32(ctx->r16, 0XD4);
    // addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s4, $v0, L_8005209C
    if (ctx->r20 != ctx->r2) {
        // addiu       $s3, $s3, 0xD4
        ctx->r19 = ADD32(ctx->r19, 0XD4);
        goto L_8005209C;
    }
    // addiu       $s3, $s3, 0xD4
    ctx->r19 = ADD32(ctx->r19, 0XD4);
    // beq         $s2, $zero, L_8005215C
    if (ctx->r18 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8005215C;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // addiu       $t3, $t3, -0x5EC8
    ctx->r11 = ADD32(ctx->r11, -0X5EC8);
    // sb          $v0, 0x6169($t3)
    MEM_B(0X6169, ctx->r11) = ctx->r2;
L_8005215C:
    // lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
L_80052160:
    // addiu       $t2, $t2, -0x5EC8
    ctx->r10 = ADD32(ctx->r10, -0X5EC8);
    // lbu         $v1, 0x6169($t2)
    ctx->r3 = MEM_BU(0X6169, ctx->r10);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_80052210
    if (ctx->r3 != ctx->r2) {
        // addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
        goto L_80052210;
    }
    // addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // addiu       $t3, $t3, -0x5EC8
    ctx->r11 = ADD32(ctx->r11, -0X5EC8);
    // jal         0x8003EAD0
    // addiu       $s3, $t3, 0x2E60
    ctx->r19 = ADD32(ctx->r11, 0X2E60);
    sub_8003EAD0(rdram, ctx);
    goto after_66;
    // addiu       $s3, $t3, 0x2E60
    ctx->r19 = ADD32(ctx->r11, 0X2E60);
    after_66:
    // addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
    // addiu       $s4, $zero, 0xFFF
    ctx->r20 = ADD32(0, 0XFFF);
    // lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // addiu       $t2, $t2, -0x5EC8
    ctx->r10 = ADD32(ctx->r10, -0X5EC8);
    // addiu       $s0, $t2, 0x2E8A
    ctx->r16 = ADD32(ctx->r10, 0X2E8A);
    // lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // lhu         $v0, 0x320($gp)
    ctx->r2 = MEM_HU(0X320, ctx->r28);
    // lhu         $v1, 0x324($gp)
    ctx->r3 = MEM_HU(0X324, ctx->r28);
    // addiu       $t3, $t3, 0x310
    ctx->r11 = ADD32(ctx->r11, 0X310);
    // sh          $v0, 0x71A4($t3)
    MEM_H(0X71A4, ctx->r11) = ctx->r2;
    // sh          $v1, 0x71A8($t3)
    MEM_H(0X71A8, ctx->r11) = ctx->r3;
L_800521B0:
    // lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(0X0, ctx->r19);
    // addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // beq         $v0, $t2, L_800521F4
    if (ctx->r2 == ctx->r10) {
        // nop
    
        goto L_800521F4;
    }
    // nop

    // lh          $v0, 0x0($s0)
    ctx->r2 = MEM_HS(0X0, ctx->r16);
    // lh          $v1, 0x86($s0)
    ctx->r3 = MEM_HS(0X86, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, 0xE01
    ctx->r2 = SIGNED(ctx->r2) < 0XE01 ? 1 : 0;
    // bne         $v0, $zero, L_800521F4
    if (ctx->r2 != 0) {
        // addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
        goto L_800521F4;
    }
    // addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // sh          $zero, 0x86($s0)
    MEM_H(0X86, ctx->r16) = 0;
    // sh          $s4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r20;
    // lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // addiu       $t3, $t3, -0x5EC8
    ctx->r11 = ADD32(ctx->r11, -0X5EC8);
    // jal         0x80057A3C
    // sb          $t2, 0x6169($t3)
    MEM_B(0X6169, ctx->r11) = ctx->r10;
    sub_80057A3C(rdram, ctx);
    goto after_67;
    // sb          $t2, 0x6169($t3)
    MEM_B(0X6169, ctx->r11) = ctx->r10;
    after_67:
L_800521F4:
    // addiu       $s0, $s0, 0xD4
    ctx->r16 = ADD32(ctx->r16, 0XD4);
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s2, $v0, L_800521B0
    if (ctx->r18 != ctx->r2) {
        // addiu       $s3, $s3, 0xD4
        ctx->r19 = ADD32(ctx->r19, 0XD4);
        goto L_800521B0;
    }
    // addiu       $s3, $s3, 0xD4
    ctx->r19 = ADD32(ctx->r19, 0XD4);
    // j           L_800527A0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    goto L_800527A0;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_80052210:
    // beq         $v1, $t3, L_80052234
    if (ctx->r3 == ctx->r11) {
        // lui         $v1, 0xFF
        ctx->r3 = S32(0XFF << 16);
        goto L_80052234;
    }
    // lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $v1, L_8005279C
    if (ctx->r2 != ctx->r3) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_8005279C;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // j           L_80052244
    // lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    goto L_80052244;
    // lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
L_80052234:
    // sh          $zero, 0x320($gp)
    MEM_H(0X320, ctx->r28) = 0;
    // sh          $zero, 0x324($gp)
    MEM_H(0X324, ctx->r28) = 0;
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
L_80052244:
    // addiu       $t2, $t2, -0x5EC8
    ctx->r10 = ADD32(ctx->r10, -0X5EC8);
    // sb          $v0, 0x6169($t2)
    MEM_B(0X6169, ctx->r10) = ctx->r2;
    // lbu         $a0, -0x3($s1)
    ctx->r4 = MEM_BU(-0X3, ctx->r17);
    // nop

    // sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // lb          $v0, 0x0($s1)
    ctx->r2 = MEM_BS(0X0, ctx->r17);
    // nop

    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lb          $v0, 0x2($s1)
    ctx->r2 = MEM_BS(0X2, ctx->r17);
    // nop

    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lb          $v0, 0x1($s1)
    ctx->r2 = MEM_BS(0X1, ctx->r17);
    // nop

    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lb          $v0, -0x5($s1)
    ctx->r2 = MEM_BS(-0X5, ctx->r17);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lb          $v0, -0x1($s1)
    ctx->r2 = MEM_BS(-0X1, ctx->r17);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lb          $v0, -0x4($s1)
    ctx->r2 = MEM_BS(-0X4, ctx->r17);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // jal         0x80045044
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    sub_80045044(rdram, ctx);
    goto after_68;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_68:
    // lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // lw          $v0, -0x8($s1)
    ctx->r2 = MEM_W(-0X8, ctx->r17);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $v1, L_80052314
    if (ctx->r2 == ctx->r3) {
        // lui         $t3, 0x801C
        ctx->r11 = S32(0X801C << 16);
        goto L_80052314;
    }
    // lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // addiu       $t3, $t3, 0x310
    ctx->r11 = ADD32(ctx->r11, 0X310);
    // lh          $v0, 0x320($gp)
    ctx->r2 = MEM_HS(0X320, ctx->r28);
    // lh          $v1, 0x324($gp)
    ctx->r3 = MEM_HS(0X324, ctx->r28);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // sh          $v0, 0x71A4($t3)
    MEM_H(0X71A4, ctx->r11) = ctx->r2;
    // sh          $v1, 0x71A8($t3)
    MEM_H(0X71A8, ctx->r11) = ctx->r3;
    // lw          $v0, -0x2C($s1)
    ctx->r2 = MEM_W(-0X2C, ctx->r17);
    // nop

    // addiu       $v0, $v0, -0x800
    ctx->r2 = ADD32(ctx->r2, -0X800);
    // sw          $v0, 0x248($s6)
    MEM_W(0X248, ctx->r22) = ctx->r2;
    // lw          $v0, -0x28($s1)
    ctx->r2 = MEM_W(-0X28, ctx->r17);
    // nop

    // addiu       $v0, $v0, -0x640
    ctx->r2 = ADD32(ctx->r2, -0X640);
    // sw          $v0, 0x24C($s6)
    MEM_W(0X24C, ctx->r22) = ctx->r2;
    // lw          $v0, -0x24($s1)
    ctx->r2 = MEM_W(-0X24, ctx->r17);
    // sw          $zero, 0x2B8($s6)
    MEM_W(0X2B8, ctx->r22) = 0;
    // sw          $zero, 0x2C0($s6)
    MEM_W(0X2C0, ctx->r22) = 0;
    // addiu       $v0, $v0, -0x800
    ctx->r2 = ADD32(ctx->r2, -0X800);
    // sw          $v0, 0x250($s6)
    MEM_W(0X250, ctx->r22) = ctx->r2;
L_80052314:
    // lbu         $v0, -0x2($s1)
    ctx->r2 = MEM_BU(-0X2, ctx->r17);
    // addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // beq         $v0, $t2, L_8005279C
    if (ctx->r2 == ctx->r10) {
        // sll         $v0, $v0, 10
        ctx->r2 = S32(ctx->r2) << 10;
        goto L_8005279C;
    }
    // sll         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) << 10;
    // lhu         $v1, 0x27A($s6)
    ctx->r3 = MEM_HU(0X27A, ctx->r22);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // j           L_8005279C
    // sh          $v1, 0x27A($s6)
    MEM_H(0X27A, ctx->r22) = ctx->r3;
    goto L_8005279C;
    // sh          $v1, 0x27A($s6)
    MEM_H(0X27A, ctx->r22) = ctx->r3;
L_80052338:
    // lw          $v0, -0x28($s1)
    ctx->r2 = MEM_W(-0X28, ctx->r17);
    // addiu       $a2, $zero, 0xC00
    ctx->r6 = ADD32(0, 0XC00);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a0, -0x2C($s1)
    ctx->r4 = MEM_W(-0X2C, ctx->r17);
    // lw          $a1, -0x24($s1)
    ctx->r5 = MEM_W(-0X24, ctx->r17);
    // jal         0x8004FD28
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    sub_8004FD28(rdram, ctx);
    goto after_69;
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    after_69:
    // beq         $v0, $zero, L_80052774
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052774;
    }
    // nop

    // lhu         $v0, 0x26A($s6)
    ctx->r2 = MEM_HU(0X26A, ctx->r22);
    // lhu         $v1, -0x30($s1)
    ctx->r3 = MEM_HU(-0X30, ctx->r17);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
    // slti        $v0, $v1, 0x801
    ctx->r2 = SIGNED(ctx->r3) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_80052380
    if (ctx->r2 != 0) {
        // addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
        goto L_80052380;
    }
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // ori         $a0, $v1, 0xF000
    ctx->r4 = ctx->r3 | 0XF000;
L_80052380:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x2E80
    ctx->r2 = ADD32(ctx->r2, -0X2E80);
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // lhu         $v0, 0x36($v0)
    ctx->r2 = MEM_HU(0X36, ctx->r2);
    // nop

    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // beq         $v1, $zero, L_800523B8
    if (ctx->r3 == 0) {
        // sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4) << 16;
        goto L_800523B8;
    }
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, -0x18F
    ctx->r2 = SIGNED(ctx->r3) < -0X18F ? 1 : 0;
    // bne         $v0, $zero, L_800523B8
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, 0x190
        ctx->r2 = SIGNED(ctx->r3) < 0X190 ? 1 : 0;
        goto L_800523B8;
    }
    // slti        $v0, $v1, 0x190
    ctx->r2 = SIGNED(ctx->r3) < 0X190 ? 1 : 0;
    // bne         $v0, $zero, L_800523C8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800523C8;
    }
    // nop

L_800523B8:
    // lbu         $v1, -0x4B($s1)
    ctx->r3 = MEM_BU(-0X4B, ctx->r17);
    // addiu       $v0, $zero, 0xEF
    ctx->r2 = ADD32(0, 0XEF);
    // bne         $v1, $v0, L_80052774
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80052774;
    }
    // nop

L_800523C8:
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8005279C
    if (ctx->r2 != 0) {
        // lui         $t3, 0x801B
        ctx->r11 = S32(0X801B << 16);
        goto L_8005279C;
    }
    // lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // addiu       $t3, $t3, 0x5920
    ctx->r11 = ADD32(ctx->r11, 0X5920);
    // lw          $v0, 0x248($s6)
    ctx->r2 = MEM_W(0X248, ctx->r22);
    // lbu         $v1, 0x4($t3)
    ctx->r3 = MEM_BU(0X4, ctx->r11);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sb          $v0, 0x221($s6)
    MEM_B(0X221, ctx->r22) = ctx->r2;
    // lw          $v0, 0x24C($s6)
    ctx->r2 = MEM_W(0X24C, ctx->r22);
    // sb          $v1, 0x220($s6)
    MEM_B(0X220, ctx->r22) = ctx->r3;
    // lw          $v1, 0x250($s6)
    ctx->r3 = MEM_W(0X250, ctx->r22);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sb          $v0, 0x222($s6)
    MEM_B(0X222, ctx->r22) = ctx->r2;
    // lbu         $v0, 0x221($s6)
    ctx->r2 = MEM_BU(0X221, ctx->r22);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // sb          $v1, 0x223($s6)
    MEM_B(0X223, ctx->r22) = ctx->r3;
    // lhu         $v1, 0x248($s6)
    ctx->r3 = MEM_HU(0X248, ctx->r22);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x222($s6)
    ctx->r2 = MEM_BU(0X222, ctx->r22);
    // sh          $v1, 0x224($s6)
    MEM_H(0X224, ctx->r22) = ctx->r3;
    // lhu         $v1, 0x24C($s6)
    ctx->r3 = MEM_HU(0X24C, ctx->r22);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x223($s6)
    ctx->r2 = MEM_BU(0X223, ctx->r22);
    // addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // sh          $v1, 0x226($s6)
    MEM_H(0X226, ctx->r22) = ctx->r3;
    // lhu         $v1, 0x250($s6)
    ctx->r3 = MEM_HU(0X250, ctx->r22);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x2230
    ctx->r2 = ADD32(ctx->r2, 0X2230);
    // sh          $v1, 0x228($s6)
    MEM_H(0X228, ctx->r22) = ctx->r3;
    // lhu         $v1, -0x1A($s1)
    ctx->r3 = MEM_HU(-0X1A, ctx->r17);
    // addiu       $a0, $v0, 0x50
    ctx->r4 = ADD32(ctx->r2, 0X50);
    // addiu       $v1, $v1, 0x800
    ctx->r3 = ADD32(ctx->r3, 0X800);
    // sh          $v1, 0x22A($s6)
    MEM_H(0X22A, ctx->r22) = ctx->r3;
L_80052460:
    // lbu         $v1, -0x4B($a0)
    ctx->r3 = MEM_BU(-0X4B, ctx->r4);
    // lbu         $v0, -0x4B($s1)
    ctx->r2 = MEM_BU(-0X4B, ctx->r17);
    // nop

    // bne         $v1, $v0, L_80052478
    if (ctx->r3 != ctx->r2) {
        // addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
        goto L_80052478;
    }
    // addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
L_80052478:
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // bne         $a1, $zero, L_80052460
    if (ctx->r5 != 0) {
        // addiu       $a0, $a0, 0x58
        ctx->r4 = ADD32(ctx->r4, 0X58);
        goto L_80052460;
    }
    // addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // lbu         $v0, -0x7($s1)
    ctx->r2 = MEM_BU(-0X7, ctx->r17);
    // lbu         $v1, -0x5($s1)
    ctx->r3 = MEM_BU(-0X5, ctx->r17);
    // addiu       $s3, $v0, 0x40
    ctx->r19 = ADD32(ctx->r2, 0X40);
    // lbu         $v0, -0x6($s1)
    ctx->r2 = MEM_BU(-0X6, ctx->r17);
    // addiu       $s4, $v1, 0x40
    ctx->r20 = ADD32(ctx->r3, 0X40);
    // jal         0x80057C54
    // addiu       $s7, $v0, 0x40
    ctx->r23 = ADD32(ctx->r2, 0X40);
    sub_80057C54(rdram, ctx);
    goto after_70;
    // addiu       $s7, $v0, 0x40
    ctx->r23 = ADD32(ctx->r2, 0X40);
    after_70:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    // jal         0x800500AC
    // addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    sub_800500AC(rdram, ctx);
    goto after_71;
    // addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    after_71:
    // lbu         $s2, -0x8($s1)
    ctx->r18 = MEM_BU(-0X8, ctx->r17);
    // lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // addu        $fp, $s2, $zero
    ctx->r30 = ADD32(ctx->r18, 0);
    // sb          $s2, 0x68($sp)
    MEM_B(0X68, ctx->r29) = ctx->r18;
L_800524C4:
    // jal         0x8001531C
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_72;
    // nop

    after_72:
    // jal         0x800456F8
    // nop

    sub_800456F8(rdram, ctx);
    goto after_73;
    // nop

    after_73:
    // lh          $v0, 0x5920($s0)
    ctx->r2 = MEM_HS(0X5920, ctx->r16);
    // nop

    // bne         $v0, $zero, L_800524C4
    if (ctx->r2 != 0) {
        // lui         $t3, 0x801B
        ctx->r11 = S32(0X801B << 16);
        goto L_800524C4;
    }
    // lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // lbu         $v0, -0x1($s1)
    ctx->r2 = MEM_BU(-0X1, ctx->r17);
    // addiu       $t3, $t3, 0x5920
    ctx->r11 = ADD32(ctx->r11, 0X5920);
    // sh          $zero, 0x278($s6)
    MEM_H(0X278, ctx->r22) = 0;
    // sll         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) << 10;
    // sh          $v0, 0x27A($s6)
    MEM_H(0X27A, ctx->r22) = ctx->r2;
    // lbu         $v0, 0x4($t3)
    ctx->r2 = MEM_BU(0X4, ctx->r11);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // beq         $a2, $v0, L_80052540
    if (ctx->r6 == ctx->r2) {
        // addu        $a0, $a2, $zero
        ctx->r4 = ADD32(ctx->r6, 0);
        goto L_80052540;
    }
    // addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // addu        $t2, $a3, $zero
    ctx->r10 = ADD32(ctx->r7, 0);
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // jal         0x80045044
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    sub_80045044(rdram, ctx);
    goto after_74;
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_74:
    // j           L_800525A4
    // sb          $zero, 0x218($s6)
    MEM_B(0X218, ctx->r22) = 0;
    goto L_800525A4;
    // sb          $zero, 0x218($s6)
    MEM_B(0X218, ctx->r22) = 0;
L_80052540:
    // addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // jal         0x80045044
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    sub_80045044(rdram, ctx);
    goto after_75;
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_75:
    // addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // jal         0x8004E2D8
    // sb          $t2, 0x21C($s6)
    MEM_B(0X21C, ctx->r22) = ctx->r10;
    sub_8004E2D8(rdram, ctx);
    goto after_76;
    // sb          $t2, 0x21C($s6)
    MEM_B(0X21C, ctx->r22) = ctx->r10;
    after_76:
    // addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // addiu       $t3, $t3, -0x5EC8
    ctx->r11 = ADD32(ctx->r11, -0X5EC8);
    // sh          $t2, 0x615E($t3)
    MEM_H(0X615E, ctx->r11) = ctx->r10;
    // sh          $t2, 0x615C($t3)
    MEM_H(0X615C, ctx->r11) = ctx->r10;
    // sh          $t2, 0x615A($t3)
    MEM_H(0X615A, ctx->r11) = ctx->r10;
    // sh          $t2, 0x6158($t3)
    MEM_H(0X6158, ctx->r11) = ctx->r10;
    // sb          $t2, 0x6103($t3)
    MEM_B(0X6103, ctx->r11) = ctx->r10;
    // sb          $zero, 0x218($s6)
    MEM_B(0X218, ctx->r22) = 0;
L_800525A4:
    // sh          $zero, 0x28C($s6)
    MEM_H(0X28C, ctx->r22) = 0;
    // sh          $zero, 0x28A($s6)
    MEM_H(0X28A, ctx->r22) = 0;
    // sh          $zero, 0x288($s6)
    MEM_H(0X288, ctx->r22) = 0;
    // lwl         $v0, 0x27B($s6)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X27B, ctx->r22);
    // lwr         $v0, 0x278($s6)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X278, ctx->r22);
    // lwl         $v1, 0x27F($s6)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X27F, ctx->r22);
    // lwr         $v1, 0x27C($s6)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X27C, ctx->r22);
    // swl         $v0, 0x26B($s6)
    do_swl(rdram, 0X26B, ctx->r22, ctx->r2);
    // swr         $v0, 0x268($s6)
    do_swr(rdram, 0X268, ctx->r22, ctx->r2);
    // swl         $v1, 0x26F($s6)
    do_swl(rdram, 0X26F, ctx->r22, ctx->r3);
    // swr         $v1, 0x26C($s6)
    do_swr(rdram, 0X26C, ctx->r22, ctx->r3);
    // andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // lb          $v0, -0x4($s1)
    ctx->r2 = MEM_BS(-0X4, ctx->r17);
    // lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x248($s6)
    MEM_W(0X248, ctx->r22) = ctx->r3;
    // andi        $v1, $s4, 0xFF
    ctx->r3 = ctx->r20 & 0XFF;
    // lb          $v0, -0x2($s1)
    ctx->r2 = MEM_BS(-0X2, ctx->r17);
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // sw          $v1, 0x250($s6)
    MEM_W(0X250, ctx->r22) = ctx->r3;
    // lb          $v1, -0x3($s1)
    ctx->r3 = MEM_BS(-0X3, ctx->r17);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // sw          $zero, 0x2F0($s6)
    MEM_W(0X2F0, ctx->r22) = 0;
    // sw          $zero, 0x2EC($s6)
    MEM_W(0X2EC, ctx->r22) = 0;
    // sll         $v1, $v1, 7
    ctx->r3 = S32(ctx->r3) << 7;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, -0x640
    ctx->r2 = ADD32(ctx->r2, -0X640);
    // jal         0x8003EAD0
    // sw          $v0, 0x24C($s6)
    MEM_W(0X24C, ctx->r22) = ctx->r2;
    sub_8003EAD0(rdram, ctx);
    goto after_77;
    // sw          $v0, 0x24C($s6)
    MEM_W(0X24C, ctx->r22) = ctx->r2;
    after_77:
    // lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // addiu       $t3, $t3, 0x310
    ctx->r11 = ADD32(ctx->r11, 0X310);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v0, $v0, 0x5948
    ctx->r2 = ADD32(ctx->r2, 0X5948);
    // lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // addiu       $t2, $t2, -0x5EC8
    ctx->r10 = ADD32(ctx->r10, -0X5EC8);
    // sh          $zero, 0x71A8($t3)
    MEM_H(0X71A8, ctx->r11) = 0;
    // sh          $zero, 0x71A6($t3)
    MEM_H(0X71A6, ctx->r11) = 0;
    // sh          $zero, 0x71A4($t3)
    MEM_H(0X71A4, ctx->r11) = 0;
    // sh          $zero, 0x47D2($v0)
    MEM_H(0X47D2, ctx->r2) = 0;
    // sh          $zero, 0x47D0($v0)
    MEM_H(0X47D0, ctx->r2) = 0;
    // sh          $zero, 0x47CE($v0)
    MEM_H(0X47CE, ctx->r2) = 0;
    // sh          $zero, 0x6164($t2)
    MEM_H(0X6164, ctx->r10) = 0;
    // sh          $zero, 0x6162($t2)
    MEM_H(0X6162, ctx->r10) = 0;
    // sh          $zero, 0x6160($t2)
    MEM_H(0X6160, ctx->r10) = 0;
    // sh          $zero, 0x1D0($s6)
    MEM_H(0X1D0, ctx->r22) = 0;
    // sh          $zero, 0x1CE($s6)
    MEM_H(0X1CE, ctx->r22) = 0;
    // sh          $zero, 0x1CC($s6)
    MEM_H(0X1CC, ctx->r22) = 0;
L_80052674:
    // jal         0x8001531C
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_78;
    // nop

    after_78:
    // jal         0x800456F8
    // nop

    sub_800456F8(rdram, ctx);
    goto after_79;
    // nop

    after_79:
    // lh          $v0, 0x5920($s0)
    ctx->r2 = MEM_HS(0X5920, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80052674
    if (ctx->r2 != 0) {
        // lui         $a0, 0x801A
        ctx->r4 = S32(0X801A << 16);
        goto L_80052674;
    }
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x6E90
    ctx->r4 = ADD32(ctx->r4, -0X6E90);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $s0, $v0, 0x5948
    ctx->r16 = ADD32(ctx->r2, 0X5948);
    // jal         0x80046270
    // sh          $zero, 0x44CA($s0)
    MEM_H(0X44CA, ctx->r16) = 0;
    sub_80046270(rdram, ctx);
    goto after_80;
    // sh          $zero, 0x44CA($s0)
    MEM_H(0X44CA, ctx->r16) = 0;
    after_80:
    // lhu         $v0, 0x44CA($s0)
    ctx->r2 = MEM_HU(0X44CA, ctx->r16);
    // nop

    // beq         $v0, $zero, L_800526E4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800526E4;
    }
    // nop

    // lhu         $v0, 0x44CE($s0)
    ctx->r2 = MEM_HU(0X44CE, ctx->r16);
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
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x174($s6)
    MEM_W(0X174, ctx->r22) = ctx->r3;
L_800526E4:
    // jal         0x8004E324
    // nop

    sub_8004E324(rdram, ctx);
    goto after_81;
    // nop

    after_81:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x800500AC
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_800500AC(rdram, ctx);
    goto after_82;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_82:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_83;
    // nop

    after_83:
    // jal         0x80057C54
    // nop

    sub_80057C54(rdram, ctx);
    goto after_84;
    // nop

    after_84:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x800500AC
    // addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    sub_800500AC(rdram, ctx);
    goto after_85;
    // addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    after_85:
    // sltiu       $v0, $fp, 0x2C
    ctx->r2 = ctx->r30 < 0X2C ? 1 : 0;
    // beq         $v0, $zero, L_80052764
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
        goto L_80052764;
    }
    // addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // lbu         $t3, 0x68($sp)
    ctx->r11 = MEM_BU(0X68, ctx->r29);
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // jal         0x80045044
    // addu        $a3, $t3, $zero
    ctx->r7 = ADD32(ctx->r11, 0);
    sub_80045044(rdram, ctx);
    goto after_86;
    // addu        $a3, $t3, $zero
    ctx->r7 = ADD32(ctx->r11, 0);
    after_86:
L_80052764:
    // jal         0x800330F0
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    sub_800330F0(rdram, ctx);
    goto after_87;
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
    after_87:
    // j           L_800527A4
    // addiu       $s5, $s5, 0x58
    ctx->r21 = ADD32(ctx->r21, 0X58);
    goto L_800527A4;
    // addiu       $s5, $s5, 0x58
    ctx->r21 = ADD32(ctx->r21, 0X58);
L_80052774:
    // j           L_8005279C
    // sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    goto L_8005279C;
    // sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
L_8005277C:
    // lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
L_80052780:
    // addiu       $t2, $t2, 0x5920
    ctx->r10 = ADD32(ctx->r10, 0X5920);
L_80052784:
    // lw          $v0, 0xC($t2)
    ctx->r2 = MEM_W(0XC, ctx->r10);
    // nop

    // lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(0X24, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_88;
    // nop

    after_88:
L_8005279C:
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
L_800527A0:
    // addiu       $s5, $s5, 0x58
    ctx->r21 = ADD32(ctx->r21, 0X58);
L_800527A4:
    // lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(0X70, ctx->r29);
    // lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(0X60, ctx->r29);
    // addiu       $t3, $t3, 0x58
    ctx->r11 = ADD32(ctx->r11, 0X58);
    // addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    // bne         $t2, $zero, L_800507B8
    if (ctx->r10 != 0) {
        // sw          $t2, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r10;
        goto L_800507B8;
    }
    // sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a2, $v0, 0x310
    ctx->r6 = ADD32(ctx->r2, 0X310);
    // lhu         $v0, 0x71A4($a2)
    ctx->r2 = MEM_HU(0X71A4, ctx->r6);
    // lhu         $v1, 0x71A8($a2)
    ctx->r3 = MEM_HU(0X71A8, ctx->r6);
    // sw          $zero, 0x71B0($a2)
    MEM_W(0X71B0, ctx->r6) = 0;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sra         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) >> 1;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sh          $a1, 0x71A4($a2)
    MEM_H(0X71A4, ctx->r6) = ctx->r5;
    // addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // lhu         $v0, 0x71A6($a2)
    ctx->r2 = MEM_HU(0X71A6, ctx->r6);
    // sltiu       $a1, $a1, 0x7
    ctx->r5 = ctx->r5 < 0X7 ? 1 : 0;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sra         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) >> 1;
    // sra         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) >> 16;
    // srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) >> 1;
    // sh          $a0, 0x71A6($a2)
    MEM_H(0X71A6, ctx->r6) = ctx->r4;
    // beq         $a1, $zero, L_80052834
    if (ctx->r5 == 0) {
        // sh          $v1, 0x71A8($a2)
        MEM_H(0X71A8, ctx->r6) = ctx->r3;
        goto L_80052834;
    }
    // sh          $v1, 0x71A8($a2)
    MEM_H(0X71A8, ctx->r6) = ctx->r3;
    // sh          $zero, 0x71A4($a2)
    MEM_H(0X71A4, ctx->r6) = 0;
L_80052834:
    // addiu       $v0, $a0, 0x3
    ctx->r2 = ADD32(ctx->r4, 0X3);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x7
    ctx->r2 = ctx->r2 < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_8005284C
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x3
        ctx->r2 = ADD32(ctx->r3, 0X3);
        goto L_8005284C;
    }
    // addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // sh          $zero, 0x71A6($a2)
    MEM_H(0X71A6, ctx->r6) = 0;
L_8005284C:
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x7
    ctx->r2 = ctx->r2 < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_80052860
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80052860;
    }
    // nop

    // sh          $zero, 0x71A8($a2)
    MEM_H(0X71A8, ctx->r6) = 0;
L_80052860:
    // lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(0X9C, ctx->r29);
    // lw          $fp, 0x98($sp)
    ctx->r30 = MEM_W(0X98, ctx->r29);
    // lw          $s7, 0x94($sp)
    ctx->r23 = MEM_W(0X94, ctx->r29);
    // lw          $s6, 0x90($sp)
    ctx->r22 = MEM_W(0X90, ctx->r29);
    // lw          $s5, 0x8C($sp)
    ctx->r21 = MEM_W(0X8C, ctx->r29);
    // lw          $s4, 0x88($sp)
    ctx->r20 = MEM_W(0X88, ctx->r29);
    // lw          $s3, 0x84($sp)
    ctx->r19 = MEM_W(0X84, ctx->r29);
    // lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(0X80, ctx->r29);
    // lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(0X7C, ctx->r29);
    // lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(0X78, ctx->r29);
    // addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // jr          $ra
    // nop

    return;
    // nop

;}
