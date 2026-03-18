#include "recomp.h"
#include "disable_warnings.h"

void sub_80023C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // lui         $s7, 0x1F80
    ctx->r23 = S32(0X1F80 << 16);
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // addu        $a3, $a3, $s6
    ctx->r7 = ADD32(ctx->r7, ctx->r22);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // lw          $fp, 0xF0($s7)
    ctx->r30 = MEM_W(0XF0, ctx->r23);
    // slt         $v0, $s6, $a3
    ctx->r2 = SIGNED(ctx->r22) < SIGNED(ctx->r7) ? 1 : 0;
    // beq         $v0, $zero, L_80023EA4
    if (ctx->r2 == 0) {
        // sw          $a3, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r7;
        goto L_80023EA4;
    }
    // sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // sll         $v0, $s6, 2
    ctx->r2 = S32(ctx->r22) << 2;
    // addu        $s5, $v0, $s6
    ctx->r21 = ADD32(ctx->r2, ctx->r22);
L_80023CC4:
    // lbu         $a1, 0x0($fp)
    ctx->r5 = MEM_BU(0X0, ctx->r30);
    // andi        $s3, $s4, 0xFFFF
    ctx->r19 = ctx->r20 & 0XFFFF;
    // sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19) << 2;
    // lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // addiu       $t0, $t0, -0x2F70
    ctx->r8 = ADD32(ctx->r8, -0X2F70);
    // addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // ori         $a0, $zero, 0x834C
    ctx->r4 = 0 | 0X834C;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // ori         $v0, $zero, 0x830C
    ctx->r2 = 0 | 0X830C;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(0X0, ctx->r4);
    // lw          $s2, 0x0($v1)
    ctx->r18 = MEM_W(0X0, ctx->r3);
    // beq         $a1, $zero, L_80023E04
    if (ctx->r5 == 0) {
        // addiu       $fp, $fp, 0x1
        ctx->r30 = ADD32(ctx->r30, 0X1);
        goto L_80023E04;
    }
    // addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // bne         $s0, $zero, L_80023D18
    if (ctx->r16 != 0) {
        // andi        $v0, $s4, 0xF
        ctx->r2 = ctx->r20 & 0XF;
        goto L_80023D18;
    }
    // andi        $v0, $s4, 0xF
    ctx->r2 = ctx->r20 & 0XF;
    // addu        $v0, $s7, $v0
    ctx->r2 = ADD32(ctx->r23, ctx->r2);
    // lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(0X40, ctx->r29);
    // lbu         $a3, 0xC8($v0)
    ctx->r7 = MEM_BU(0XC8, ctx->r2);
    // j           L_80023D64
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    goto L_80023D64;
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
L_80023D18:
    // jal         0x80015258
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80015258(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // bne         $v0, $t0, L_80023D7C
    if (ctx->r2 != ctx->r8) {
        // nop
    
        goto L_80023D7C;
    }
    // nop

    // jal         0x8001526C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8001526C(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // andi        $v1, $s4, 0xF
    ctx->r3 = ctx->r20 & 0XF;
    // addu        $s1, $s7, $v1
    ctx->r17 = ADD32(ctx->r23, ctx->r3);
    // lbu         $v1, 0xC8($s1)
    ctx->r3 = MEM_BU(0XC8, ctx->r17);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // beq         $v0, $v1, L_80023D74
    if (ctx->r2 == ctx->r3) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80023D74;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80015230
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80015230(rdram, ctx);
    goto after_2;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(0X40, ctx->r29);
    // lbu         $a3, 0xC8($s1)
    ctx->r7 = MEM_BU(0XC8, ctx->r17);
L_80023D64:
    // jal         0x800237A8
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_800237A8(rdram, ctx);
    goto after_3;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_3:
    // j           L_80023D7C
    // nop

    goto L_80023D7C;
    // nop

L_80023D74:
    // jal         0x80015250
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    sub_80015250(rdram, ctx);
    goto after_4;
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
L_80023D7C:
    // bne         $s2, $zero, L_80023D98
    if (ctx->r18 != 0) {
        // andi        $v0, $s4, 0xF
        ctx->r2 = ctx->r20 & 0XF;
        goto L_80023D98;
    }
    // andi        $v0, $s4, 0xF
    ctx->r2 = ctx->r20 & 0XF;
    // addu        $v0, $s7, $v0
    ctx->r2 = ADD32(ctx->r23, ctx->r2);
    // lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(0X40, ctx->r29);
    // lbu         $a3, 0xC8($v0)
    ctx->r7 = MEM_BU(0XC8, ctx->r2);
    // j           L_80023DE4
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    goto L_80023DE4;
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
L_80023D98:
    // jal         0x80015258
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_80015258(rdram, ctx);
    goto after_5;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_5:
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // bne         $v0, $t0, L_80023E88
    if (ctx->r2 != ctx->r8) {
        // nop
    
        goto L_80023E88;
    }
    // nop

    // jal         0x8001526C
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_8001526C(rdram, ctx);
    goto after_6;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_6:
    // andi        $v1, $s4, 0xF
    ctx->r3 = ctx->r20 & 0XF;
    // addu        $s0, $s7, $v1
    ctx->r16 = ADD32(ctx->r23, ctx->r3);
    // lbu         $v1, 0xC8($s0)
    ctx->r3 = MEM_BU(0XC8, ctx->r16);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // beq         $v0, $v1, L_80023DF4
    if (ctx->r2 == ctx->r3) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80023DF4;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x80015230
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_80015230(rdram, ctx);
    goto after_7;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_7:
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(0X40, ctx->r29);
    // lbu         $a3, 0xC8($s0)
    ctx->r7 = MEM_BU(0XC8, ctx->r16);
L_80023DE4:
    // jal         0x800239EC
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
    sub_800239EC(rdram, ctx);
    goto after_8;
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
    after_8:
    // j           L_80023E8C
    // addiu       $s5, $s5, 0x5
    ctx->r21 = ADD32(ctx->r21, 0X5);
    goto L_80023E8C;
    // addiu       $s5, $s5, 0x5
    ctx->r21 = ADD32(ctx->r21, 0X5);
L_80023DF4:
    // jal         0x80015250
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    sub_80015250(rdram, ctx);
    goto after_9;
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // j           L_80023E8C
    // addiu       $s5, $s5, 0x5
    ctx->r21 = ADD32(ctx->r21, 0X5);
    goto L_80023E8C;
    // addiu       $s5, $s5, 0x5
    ctx->r21 = ADD32(ctx->r21, 0X5);
L_80023E04:
    // beq         $s0, $zero, L_80023E2C
    if (ctx->r16 == 0) {
        // nop
    
        goto L_80023E2C;
    }
    // nop

    // jal         0x80015258
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80015258(rdram, ctx);
    goto after_10;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_10:
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // beq         $v0, $v1, L_80023E2C
    if (ctx->r2 == ctx->r3) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80023E2C;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80015250
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sub_80015250(rdram, ctx);
    goto after_11;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
L_80023E2C:
    // beq         $s2, $zero, L_80023E58
    if (ctx->r18 == 0) {
        // sll         $v1, $s6, 3
        ctx->r3 = S32(ctx->r22) << 3;
        goto L_80023E58;
    }
    // sll         $v1, $s6, 3
    ctx->r3 = S32(ctx->r22) << 3;
    // jal         0x80015258
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_80015258(rdram, ctx);
    goto after_12;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_12:
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // beq         $v0, $v1, L_80023E54
    if (ctx->r2 == ctx->r3) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_80023E54;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x80015250
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sub_80015250(rdram, ctx);
    goto after_13;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
L_80023E54:
    // sll         $v1, $s6, 3
    ctx->r3 = S32(ctx->r22) << 3;
L_80023E58:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, -0x2DD8
    ctx->r2 = ADD32(ctx->r2, -0X2DD8);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // nop

    // beq         $v1, $zero, L_80023E88
    if (ctx->r3 == 0) {
        // addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
        goto L_80023E88;
    }
    // addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // lh          $v0, 0x4($v1)
    ctx->r2 = MEM_HS(0X4, ctx->r3);
    // nop

    // bne         $v0, $t0, L_80023E88
    if (ctx->r2 != ctx->r8) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_80023E88;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
L_80023E88:
    // addiu       $s5, $s5, 0x5
    ctx->r21 = ADD32(ctx->r21, 0X5);
L_80023E8C:
    // addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(0X10, ctx->r29);
    // nop

    // slt         $v0, $s6, $t0
    ctx->r2 = SIGNED(ctx->r22) < SIGNED(ctx->r8) ? 1 : 0;
    // bne         $v0, $zero, L_80023CC4
    if (ctx->r2 != 0) {
        // addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_80023CC4;
    }
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_80023EA4:
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(0X38, ctx->r29);
    // lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
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
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
