#include "recomp.h"
#include "disable_warnings.h"

void sub_80058EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
    // addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sh          $v0, 0x2E6($s2)
    MEM_H(0X2E6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1EF
    ctx->r2 = ADD32(0, 0X1EF);
    // sh          $v0, 0x2EC($s2)
    MEM_H(0X2EC, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
    // sh          $v0, 0x2EE($s2)
    MEM_H(0X2EE, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1F1
    ctx->r2 = ADD32(0, 0X1F1);
    // sh          $v0, 0x2F4($s2)
    MEM_H(0X2F4, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // sh          $v1, 0x2E8($s2)
    MEM_H(0X2E8, ctx->r18) = ctx->r3;
    // sh          $a0, 0x2EA($s2)
    MEM_H(0X2EA, ctx->r18) = ctx->r4;
    // sh          $v1, 0x2F0($s2)
    MEM_H(0X2F0, ctx->r18) = ctx->r3;
    // sh          $a0, 0x2F2($s2)
    MEM_H(0X2F2, ctx->r18) = ctx->r4;
    // sh          $v0, 0x2F6($s2)
    MEM_H(0X2F6, ctx->r18) = ctx->r2;
    // jal         0x80015AD4
    // sh          $v1, 0x2F8($s2)
    MEM_H(0X2F8, ctx->r18) = ctx->r3;
    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_0;
    // sh          $v1, 0x2F8($s2)
    MEM_H(0X2F8, ctx->r18) = ctx->r3;
    after_0:
    // lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // addiu       $s0, $s1, -0x7378
    ctx->r16 = ADD32(ctx->r17, -0X7378);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_1;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    sub_80014CFC(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    after_2:
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // ori         $a1, $a1, 0x2E6
    ctx->r5 = ctx->r5 | 0X2E6;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // ori         $a2, $a2, 0x2EA
    ctx->r6 = ctx->r6 | 0X2EA;
    // lw          $v0, -0x7378($s1)
    ctx->r2 = MEM_W(-0X7378, ctx->r17);
    // addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $v0, $s0
    ctx->r16 = ADD32(ctx->r2, ctx->r16);
    // jal         0x8003EC5C
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    sub_8003EC5C(rdram, ctx);
    goto after_3;
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // jal         0x80058C04
    // nop

    PadChkVsync(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x80057A3C
    // sh          $zero, 0x2DE($s2)
    MEM_H(0X2DE, ctx->r18) = 0;
    sub_80057A3C(rdram, ctx);
    goto after_5;
    // sh          $zero, 0x2DE($s2)
    MEM_H(0X2DE, ctx->r18) = 0;
    after_5:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ST_DrawSync(rdram, ctx);
    goto after_6;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_6:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s0, $v0, -0x2E80
    ctx->r16 = ADD32(ctx->r2, -0X2E80);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s3, $v0, -0x70D8
    ctx->r19 = ADD32(ctx->r2, -0X70D8);
L_80058FD8:
    // lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(0X4, ctx->r16);
    // nop

    // andi        $v0, $v1, 0x2000
    ctx->r2 = ctx->r3 & 0X2000;
    // beq         $v0, $zero, L_80058FFC
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x1000
        ctx->r2 = ctx->r3 & 0X1000;
        goto L_80058FFC;
    }
    // andi        $v0, $v1, 0x1000
    ctx->r2 = ctx->r3 & 0X1000;
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // j           L_800591D4
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    goto L_800591D4;
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
L_80058FFC:
    // beq         $v0, $zero, L_80059018
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80059018;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // jal         0x80060018
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    sub_80060018(rdram, ctx);
    goto after_9;
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    after_9:
L_80059018:
    // lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(0X4, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // beq         $v0, $zero, L_8005913C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005913C;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // lhu         $v0, 0x2DE($s2)
    ctx->r2 = MEM_HU(0X2DE, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bne         $v1, $zero, L_8005905C
    if (ctx->r3 != 0) {
        // sh          $zero, 0x4($s0)
        MEM_H(0X4, ctx->r16) = 0;
        goto L_8005905C;
    }
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // jal         0x8005EC10
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    sub_8005EC10(rdram, ctx);
    goto after_11;
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    after_11:
    // j           L_80059134
    // nop

    goto L_80059134;
    // nop

L_8005905C:
    // bne         $v1, $s1, L_80059074
    if (ctx->r3 != ctx->r17) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_80059074;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // jal         0x80064FF0
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    SsInitHot(rdram, ctx);
    goto after_12;
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    after_12:
    // j           L_8005913C
    // nop

    goto L_8005913C;
    // nop

L_80059074:
    // bne         $v1, $v0, L_800590B0
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_800590B0;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // sb          $s1, 0x21D($s3)
    MEM_B(0X21D, ctx->r19) = ctx->r17;
    // andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // beq         $v0, $zero, L_800590A0
    if (ctx->r2 == 0) {
        // sb          $s1, 0x2E5($s2)
        MEM_B(0X2E5, ctx->r18) = ctx->r17;
        goto L_800590A0;
    }
    // sb          $s1, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = ctx->r17;
    // jal         0x8005D25C
    // nop

    sub_8005D25C(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // j           L_8005913C
    // nop

    goto L_8005913C;
    // nop

L_800590A0:
    // jal         0x800675F4
    // nop

    SsInitHot_0(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // j           L_8005913C
    // nop

    goto L_8005913C;
    // nop

L_800590B0:
    // bne         $v1, $v0, L_800590CC
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_800590CC;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // sb          $s1, 0x21D($s3)
    MEM_B(0X21D, ctx->r19) = ctx->r17;
    // jal         0x8005C7FC
    // sb          $s1, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = ctx->r17;
    sub_8005C7FC(rdram, ctx);
    goto after_15;
    // sb          $s1, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = ctx->r17;
    after_15:
    // j           L_8005913C
    // nop

    goto L_8005913C;
    // nop

L_800590CC:
    // bne         $v1, $v0, L_800590E8
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_800590E8;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sb          $s1, 0x21D($s3)
    MEM_B(0X21D, ctx->r19) = ctx->r17;
    // jal         0x8005AD00
    // sb          $s1, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = ctx->r17;
    sub_8005AD00(rdram, ctx);
    goto after_16;
    // sb          $s1, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = ctx->r17;
    after_16:
    // j           L_8005913C
    // nop

    goto L_8005913C;
    // nop

L_800590E8:
    // bne         $v1, $v0, L_80059100
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
        goto L_80059100;
    }
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // jal         0x80060334
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    sub_80060334(rdram, ctx);
    goto after_17;
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    after_17:
    // j           L_8005913C
    // nop

    goto L_8005913C;
    // nop

L_80059100:
    // bne         $v1, $v0, L_80059124
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
        goto L_80059124;
    }
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // sh          $s1, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r17;
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    // jal         0x80062C28
    // sh          $s1, 0x206($s2)
    MEM_H(0X206, ctx->r18) = ctx->r17;
    sub_80062C28(rdram, ctx);
    goto after_18;
    // sh          $s1, 0x206($s2)
    MEM_H(0X206, ctx->r18) = ctx->r17;
    after_18:
    // j           L_80059134
    // nop

    goto L_80059134;
    // nop

L_80059124:
    // bne         $v1, $v0, L_8005913C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005913C;
    }
    // nop

    // jal         0x80063078
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    sub_80063078(rdram, ctx);
    goto after_19;
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    after_19:
L_80059134:
    // beq         $v0, $s1, L_800591D4
    if (ctx->r2 == ctx->r17) {
        // nop
    
        goto L_800591D4;
    }
    // nop

L_8005913C:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_80059180
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80059180;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_20;
    // nop

    after_20:
    // lhu         $v0, 0x2DE($s2)
    ctx->r2 = MEM_HU(0X2DE, ctx->r18);
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0x2DE($s2)
    MEM_H(0X2DE, ctx->r18) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x8
    ctx->r2 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_80059180
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80059180;
    }
    // nop

    // sh          $zero, 0x2DE($s2)
    MEM_H(0X2DE, ctx->r18) = 0;
L_80059180:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_800591BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800591BC;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_21;
    // nop

    after_21:
    // lhu         $v0, 0x2DE($s2)
    ctx->r2 = MEM_HU(0X2DE, ctx->r18);
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x2DE($s2)
    MEM_H(0X2DE, ctx->r18) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_800591BC
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
        goto L_800591BC;
    }
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // sh          $v0, 0x2DE($s2)
    MEM_H(0X2DE, ctx->r18) = ctx->r2;
L_800591BC:
    // jal         0x800164B4
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    sub_800164B4(rdram, ctx);
    goto after_22;
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    after_22:
    // jal         0x80029B74
    // nop

    sub_80029B74(rdram, ctx);
    goto after_23;
    // nop

    after_23:
    // j           L_80058FD8
    // nop

    goto L_80058FD8;
    // nop

L_800591D4:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_24;
    // nop

    after_24:
    // jal         0x80058C24
    // nop

    PadStartCom(rdram, ctx);
    goto after_25;
    // nop

    after_25:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
