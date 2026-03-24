#include "recomp.h"
#include "disable_warnings.h"

void sub_80024004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // addu        $fp, $a3, $s1
    ctx->r30 = ADD32(ctx->r7, ctx->r17);
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // lui         $s7, 0x1F80
    ctx->r23 = S32(0X1F80 << 16);
    // lw          $s7, 0xF0($s7)
    ctx->r23 = MEM_W(0XF0, ctx->r23);
    // slt         $v0, $s1, $fp
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r30) ? 1 : 0;
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // beq         $v0, $zero, L_8002419C
    if (ctx->r2 == 0) {
        // sw          $a0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r4;
        goto L_8002419C;
    }
    // sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // sll         $v1, $s4, 2
    ctx->r3 = S32(ctx->r20) << 2;
    // addu        $s6, $v1, $v0
    ctx->r22 = ADD32(ctx->r3, ctx->r2);
    // sll         $s3, $s1, 3
    ctx->r19 = S32(ctx->r17) << 3;
    // sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17) << 1;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // addiu       $s2, $v0, 0x1
    ctx->r18 = ADD32(ctx->r2, 0X1);
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
L_80024074:
    // lbu         $v1, 0x0($s7)
    ctx->r3 = MEM_BU(0X0, ctx->r23);
    // ori         $v0, $zero, 0x834C
    ctx->r2 = 0 | 0X834C;
    // addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(0X0, ctx->r2);
    // beq         $v1, $zero, L_80024124
    if (ctx->r3 == 0) {
        // addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
        goto L_80024124;
    }
    // addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // bne         $s0, $zero, L_800240A8
    if (ctx->r16 != 0) {
        // addu        $a1, $s5, $zero
        ctx->r5 = ADD32(ctx->r21, 0);
        goto L_800240A8;
    }
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(0X38, ctx->r29);
    // jal         0x80023BC4
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);

    sub_80023BC4(rdram, ctx);

    goto after_0;
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_0:
    // j           L_800240C8
    // nop

    goto L_800240C8;
    // nop

L_800240A8:
    // jal         0x80015258
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80015258(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // bne         $v0, $t0, L_800240C8
    if (ctx->r2 != ctx->r8) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_800240C8;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80015250
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    sub_80015250(rdram, ctx);
    goto after_2;
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
L_800240C8:
    // lhu         $a0, 0x38($sp)
    ctx->r4 = MEM_HU(0X38, ctx->r29);
    // jal         0x80015EC8
    // andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    sub_80015EC8(rdram, ctx);
    goto after_3;
    // andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    after_3:
    // beq         $v0, $zero, L_8002417C
    if (ctx->r2 == 0) {
        // lui         $t0, 0x801E
        ctx->r8 = S32(0X801E << 16);
        goto L_8002417C;
    }
    // lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // addiu       $t0, $t0, -0x2D58
    ctx->r8 = ADD32(ctx->r8, -0X2D58);
    // addu        $v0, $s3, $t0
    ctx->r2 = ADD32(ctx->r19, ctx->r8);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002410C
    if (ctx->r2 != 0) {
        // addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8002410C;
    }
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(0X38, ctx->r29);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // jal         0x80058A0C
    // addiu       $a2, $s1, 0x18
    ctx->r6 = ADD32(ctx->r17, 0X18);
    StartAudioStream(rdram, ctx);
    goto after_4;
    // addiu       $a2, $s1, 0x18
    ctx->r6 = ADD32(ctx->r17, 0X18);
    after_4:
    // j           L_80024180
    // addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    goto L_80024180;
    // addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
L_8002410C:
    // lh          $v1, 0x4($a0)
    ctx->r3 = MEM_HS(0X4, ctx->r4);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_8002417C
    if (ctx->r3 != ctx->r2) {
        // addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
        goto L_8002417C;
    }
    // addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // j           L_8002417C
    // sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
    goto L_8002417C;
    // sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
L_80024124:
    // beq         $s0, $zero, L_80024150
    if (ctx->r16 == 0) {
        // lui         $t0, 0x801E
        ctx->r8 = S32(0X801E << 16);
        goto L_80024150;
    }
    // lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // jal         0x80015258
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80015258(rdram, ctx);
    goto after_5;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // beq         $v0, $v1, L_8002414C
    if (ctx->r2 == ctx->r3) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8002414C;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80015250
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sub_80015250(rdram, ctx);
    goto after_6;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
L_8002414C:
    // lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
L_80024150:
    // addiu       $t0, $t0, -0x2D58
    ctx->r8 = ADD32(ctx->r8, -0X2D58);
    // addu        $v0, $s3, $t0
    ctx->r2 = ADD32(ctx->r19, ctx->r8);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8002417C
    if (ctx->r2 == 0) {
        // addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
        goto L_8002417C;
    }
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // lh          $v0, 0x4($a0)
    ctx->r2 = MEM_HS(0X4, ctx->r4);
    // addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // bne         $v0, $t0, L_8002417C
    if (ctx->r2 != ctx->r8) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8002417C;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
L_8002417C:
    // addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
L_80024180:
    // addiu       $s2, $s2, 0x3
    ctx->r18 = ADD32(ctx->r18, 0X3);
    // addiu       $s5, $s5, 0x3
    ctx->r21 = ADD32(ctx->r21, 0X3);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // slt         $v0, $s1, $fp
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r30) ? 1 : 0;
    // bne         $v0, $zero, L_80024074
    if (ctx->r2 != 0) {
        // addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_80024074;
    }
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8002419C:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(0X30, ctx->r29);
    // lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(0X2C, ctx->r29);
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
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
