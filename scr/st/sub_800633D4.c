#include "recomp.h"
#include "disable_warnings.h"

void sub_800633D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, -0x7F54
    ctx->r6 = ADD32(ctx->r2, -0X7F54);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r3);
    // swr         $v1, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r3);
    // swl         $a0, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r4);
    // swr         $a0, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r4);
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // sh          $v0, 0x2E6($s2)
    MEM_H(0X2E6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $v0, 0x2E8($s2)
    MEM_H(0X2E8, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x230
    ctx->r2 = ADD32(0, 0X230);
    // sh          $v0, 0x2EA($s2)
    MEM_H(0X2EA, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1EF
    ctx->r2 = ADD32(0, 0X1EF);
    // jal         0x80015AD4
    // sh          $v0, 0x2EC($s2)
    MEM_H(0X2EC, ctx->r18) = ctx->r2;
    sub_80015AD4(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x2EC($s2)
    MEM_H(0X2EC, ctx->r18) = ctx->r2;
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
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // lw          $v0, -0x7378($s1)
    ctx->r2 = MEM_W(-0X7378, ctx->r17);
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
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
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x80079BE4
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    ClearImage(rdram, ctx);
    goto after_4;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_4:
    // sh          $zero, 0x2DE($s2)
    MEM_H(0X2DE, ctx->r18) = 0;
    // jal         0x80057A3C
    // sb          $zero, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = 0;
    sub_80057A3C(rdram, ctx);
    goto after_5;
    // sb          $zero, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = 0;
    after_5:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s1, $v0, -0x2E80
    ctx->r17 = ADD32(ctx->r2, -0X2E80);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $s4, $v0, 0x5920
    ctx->r20 = ADD32(ctx->r2, 0X5920);
    // addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // sh          $v0, 0x340($s2)
    MEM_H(0X340, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // sh          $zero, 0x33C($s2)
    MEM_H(0X33C, ctx->r18) = 0;
    // sh          $zero, 0x33E($s2)
    MEM_H(0X33E, ctx->r18) = 0;
    // sh          $v0, 0x342($s2)
    MEM_H(0X342, ctx->r18) = ctx->r2;
L_800634E0:
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // beq         $v0, $zero, L_80063578
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063578;
    }
    // nop

    // jal         0x80057CC8
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    sub_80057CC8(rdram, ctx);
    goto after_6;
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    after_6:
    // lhu         $v0, 0x2DE($s2)
    ctx->r2 = MEM_HU(0X2DE, ctx->r18);
    // nop

    // bne         $v0, $zero, L_800635F8
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_800635F8;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x80079BE4
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    ClearImage(rdram, ctx);
    goto after_7;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_7:
    // jal         0x80015AD4
    // nop

    sub_80015AD4(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // lbu         $a0, 0x4($s4)
    ctx->r4 = MEM_BU(0X4, ctx->r20);
    // jal         0x80055CF4
    // nop

    sub_80055CF4(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // jal         0x80042CFC
    // nop

    sub_80042CFC(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // jal         0x80057A68
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80057A68(rdram, ctx);
    goto after_12;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_12:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // jal         0x80058DC4
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_80058DC4(rdram, ctx);
    goto after_13;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_13:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80062C28
    // sw          $s3, 0x208($s2)
    MEM_W(0X208, ctx->r18) = ctx->r19;
    sub_80062C28(rdram, ctx);
    goto after_14;
    // sw          $s3, 0x208($s2)
    MEM_W(0X208, ctx->r18) = ctx->r19;
    after_14:
    // jal         0x80057A3C
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    sub_80057A3C(rdram, ctx);
    goto after_15;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_15:
    // jal         0x80058ED4
    // nop

    sub_80058ED4(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // beq         $s0, $s3, L_800635F8
    if (ctx->r16 == ctx->r19) {
        // nop
    
        goto L_800635F8;
    }
    // nop

L_80063578:
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8006359C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006359C;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // sh          $zero, 0x2DE($s2)
    MEM_H(0X2DE, ctx->r18) = 0;
L_8006359C:
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_800635C0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800635C0;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_18;
    // nop

    after_18:
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // sh          $s3, 0x2DE($s2)
    MEM_H(0X2DE, ctx->r18) = ctx->r19;
L_800635C0:
    // jal         0x800164B4
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    sub_800164B4(rdram, ctx);
    goto after_19;
    // sb          $zero, 0x2E5($s2)
    MEM_B(0X2E5, ctx->r18) = 0;
    after_19:
    // jal         0x8002D0B0
    // nop

    sub_8002D0B0(rdram, ctx);
    goto after_20;
    // nop

    after_20:
    // lbu         $a0, 0x2E4($s2)
    ctx->r4 = MEM_BU(0X2E4, ctx->r18);
    // nop

    // addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // bgez        $v1, L_800635E8
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_800635E8;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_800635E8:
    // andi        $v0, $v0, 0x1E0
    ctx->r2 = ctx->r2 & 0X1E0;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // j           L_800634E0
    // sb          $v0, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = ctx->r2;
    goto L_800634E0;
    // sb          $v0, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = ctx->r2;
L_800635F8:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_21;
    // nop

    after_21:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x80079BE4
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    ClearImage(rdram, ctx);
    goto after_22;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_22:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
