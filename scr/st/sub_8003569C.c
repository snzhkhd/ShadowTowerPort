#include "recomp.h"
#include "disable_warnings.h"

void sub_8003569C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // ori         $v0, $zero, 0x834C
    ctx->r2 = 0 | 0X834C;
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(0X0, ctx->r18);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(0X0, ctx->r3);
    // bne         $a0, $zero, L_80035824
    if (ctx->r4 != 0) {
        // addu        $s4, $a3, $zero
        ctx->r20 = ADD32(ctx->r7, 0);
        goto L_80035824;
    }
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // jal         0x80035190
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    sub_80035190(rdram, ctx);
    goto after_0;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // nop

    // bne         $v0, $zero, L_80035714
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80035714;
    }
    // nop

    // j           L_80035A84
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80035A84;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80035710:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
L_80035714:
    // nop

    // lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(0X28, ctx->r2);
    // sh          $s1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r17;
    // beq         $a0, $zero, L_8003573C
    if (ctx->r4 == 0) {
        // sw          $s2, 0x38($v0)
        MEM_W(0X38, ctx->r2) = ctx->r18;
        goto L_8003573C;
    }
    // sw          $s2, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r18;
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // nop

    // sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
L_8003573C:
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x800152D0
    // nop

    sub_800152D0(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(0X18, ctx->r29);
    // nop

    // sw          $v0, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r2;
    // lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(0X6, ctx->r16);
    // nop

    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r2;
    // lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(0X6, ctx->r16);
    // nop

    // sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) << 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r2;
    // lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(0X6, ctx->r16);
    // nop

    // sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) << 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // lw          $a0, 0x28($a1)
    ctx->r4 = MEM_W(0X28, ctx->r5);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // bne         $a0, $zero, L_800357EC
    if (ctx->r4 != 0) {
        // sw          $v0, 0x34($a1)
        MEM_W(0X34, ctx->r5) = ctx->r2;
        goto L_800357EC;
    }
    // sw          $v0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r2;
    // jal         0x800341A0
    // nop

    sub_800341A0(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x8003509C
    // nop

    sub_8003509C(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x80034224
    // nop

    sub_80034224(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // jal         0x80035120
    // nop

    sub_80035120(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // j           L_80035A84
    // sh          $v1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r3;
    goto L_80035A84;
    // sh          $v1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r3;
L_800357EC:
    // sw          $a1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r5;
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(0X6, ctx->r16);
    // jal         0x800346DC
    // nop

    sub_800346DC(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(0XC, ctx->r16);
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(0X10, ctx->r16);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // j           L_8003584C
    // sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    goto L_8003584C;
    // sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_80035824:
    // lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(0X2, ctx->r4);
    // nop

    // beq         $v0, $s1, L_8003584C
    if (ctx->r2 == ctx->r17) {
        // nop
    
        goto L_8003584C;
    }
    // nop

    // jal         0x80035008
    // nop

    sub_80035008(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // j           L_80035710
    // sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    goto L_80035710;
    // sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
L_8003584C:
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // nop

    // lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(0X4, ctx->r4);
    // nop

    // beq         $v0, $s3, L_80035900
    if (ctx->r2 == ctx->r19) {
        // sll         $v1, $s3, 2
        ctx->r3 = S32(ctx->r19) << 2;
        goto L_80035900;
    }
    // sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19) << 2;
    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // sw          $v1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r3;
    // lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(0X4, ctx->r2);
    // addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // sw          $v0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r2;
    // sw          $v0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r2;
    // addiu       $v0, $v1, -0x2
    ctx->r2 = ADD32(ctx->r3, -0X2);
    // sw          $v1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r3;
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // beq         $v1, $zero, L_800358D8
    if (ctx->r3 == 0) {
        // sw          $v0, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r2;
        goto L_800358D8;
    }
    // sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
L_800358B0:
    // lw          $v0, 0x14($a2)
    ctx->r2 = MEM_W(0X14, ctx->r6);
    // lw          $a0, 0x24($a2)
    ctx->r4 = MEM_W(0X24, ctx->r6);
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(0X0, ctx->r4);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // bne         $a1, $zero, L_800358B0
    if (ctx->r5 != 0) {
        // sw          $a0, 0x24($a2)
        MEM_W(0X24, ctx->r6) = ctx->r4;
        goto L_800358B0;
    }
    // sw          $a0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r4;
L_800358D8:
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // nop

    // lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(0X24, ctx->r3);
    // lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(0X10, ctx->r3);
    // lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(0X4, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $a0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r4;
    // sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // sw          $v0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r2;
    // sw          $a1, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r5;
L_80035900:
    // lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(0X18, ctx->r29);
    // nop

    // lw          $v0, 0x1C($a1)
    ctx->r2 = MEM_W(0X1C, ctx->r5);
    // nop

    // mult        $v0, $s4
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x20($a1)
    ctx->r3 = MEM_W(0X20, ctx->r5);
    // mflo        $t0
    ctx->r8 = lo;
    // srl         $s1, $t0, 12
    ctx->r17 = S32(U32(ctx->r8) >> 12);
    // sltu        $v0, $s1, $v1
    ctx->r2 = ctx->r17 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_800359D0
    if (ctx->r2 == 0) {
        // sh          $s3, 0x4($a1)
        MEM_H(0X4, ctx->r5) = ctx->r19;
        goto L_800359D0;
    }
    // sh          $s3, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r19;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_800359D0
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_800359D0;
    }
    // nop

    // lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(0X14, ctx->r5);
    // lw          $a0, 0x18($a1)
    ctx->r4 = MEM_W(0X18, ctx->r5);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sltu        $v1, $v1, $a0
    ctx->r3 = ctx->r3 < ctx->r4 ? 1 : 0;
    // beq         $v1, $zero, L_800359BC
    if (ctx->r3 == 0) {
        // sw          $v0, 0x14($a1)
        MEM_W(0X14, ctx->r5) = ctx->r2;
        goto L_800359BC;
    }
    // sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
L_80035954:
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // nop

    // lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(0XC, ctx->r3);
    // lw          $a0, 0x24($v1)
    ctx->r4 = MEM_W(0X24, ctx->r3);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(0X4, ctx->r4);
    // lw          $a1, 0x24($v1)
    ctx->r5 = MEM_W(0X24, ctx->r3);
    // lw          $a2, 0x34($v1)
    ctx->r6 = MEM_W(0X34, ctx->r3);
    // lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(0X8, ctx->r3);
    // jal         0x80034E68
    // nop

    sub_80034E68(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // nop

    // lw          $v1, 0x14($a0)
    ctx->r3 = MEM_W(0X14, ctx->r4);
    // lw          $a1, 0x18($a0)
    ctx->r5 = MEM_W(0X18, ctx->r4);
    // sw          $v0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r2;
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // bne         $v0, $zero, L_80035954
    if (ctx->r2 != 0) {
        // sw          $v1, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r3;
        goto L_80035954;
    }
    // sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
L_800359BC:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // nop

    // lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(0X10, ctx->r2);
    // sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // sw          $v1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r3;
L_800359D0:
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // nop

    // lw          $v0, 0x34($v1)
    ctx->r2 = MEM_W(0X34, ctx->r3);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sw          $v0, 0xA4($at)
    MEM_W(0XA4, ctx->r1) = ctx->r2;
    // lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(0X24, ctx->r3);
    // nop

    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // bne         $v0, $zero, L_80035A74
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80035A74;
    }
    // nop

L_80035A00:
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // nop

    // lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(0XC, ctx->r3);
    // nop

    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $a1, 0x24($v1)
    ctx->r5 = MEM_W(0X24, ctx->r3);
    // lw          $a2, 0x34($v1)
    ctx->r6 = MEM_W(0X34, ctx->r3);
    // lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(0X8, ctx->r3);
    // jal         0x80034E68
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_80034E68(rdram, ctx);
    goto after_10;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_10:
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // jal         0x80035604
    // sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
    sub_80035604(rdram, ctx);
    goto after_11;
    // sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
    after_11:
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // nop

    // lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(0X14, ctx->r3);
    // lw          $a0, 0x24($v1)
    ctx->r4 = MEM_W(0X24, ctx->r3);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_80035A00
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80035A00;
    }
    // nop

L_80035A74:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // sw          $s1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r17;
    // sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_80035A84:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
