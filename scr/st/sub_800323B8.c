#include "recomp.h"
#include "disable_warnings.h"

void sub_800323B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // andi        $v0, $s5, 0x1
    ctx->r2 = ctx->r21 & 0X1;
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // beq         $v0, $zero, L_80032428
    if (ctx->r2 == 0) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_80032428;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $s1, $v0, -0x48C4
    ctx->r17 = ADD32(ctx->r2, -0X48C4);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // sll         $s2, $a2, 16
    ctx->r18 = S32(ctx->r6) << 16;
L_800323FC:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x80032210
    // sra         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18) >> 16;
    sub_80032210(rdram, ctx);
    goto after_0;
    // sra         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18) >> 16;
    after_0:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x30
    ctx->r2 = SIGNED(ctx->r16) < 0X30 ? 1 : 0;
    // bne         $v0, $zero, L_800323FC
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x6C
        ctx->r17 = ADD32(ctx->r17, 0X6C);
        goto L_800323FC;
    }
    // addiu       $s1, $s1, 0x6C
    ctx->r17 = ADD32(ctx->r17, 0X6C);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, -0x492E($v1)
    MEM_B(-0X492E, ctx->r3) = ctx->r2;
L_80032428:
    // andi        $v0, $s5, 0x2
    ctx->r2 = ctx->r21 & 0X2;
    // beq         $v0, $zero, L_80032460
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8019
        ctx->r2 = S32(0X8019 << 16);
        goto L_80032460;
    }
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $s1, $v0, -0x48C4
    ctx->r17 = ADD32(ctx->r2, -0X48C4);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // sll         $s2, $s4, 16
    ctx->r18 = S32(ctx->r20) << 16;
L_80032440:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x80032244
    // sra         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18) >> 16;
    sub_80032244(rdram, ctx);
    goto after_1;
    // sra         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18) >> 16;
    after_1:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x30
    ctx->r2 = SIGNED(ctx->r16) < 0X30 ? 1 : 0;
    // bne         $v0, $zero, L_80032440
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x6C
        ctx->r17 = ADD32(ctx->r17, 0X6C);
        goto L_80032440;
    }
    // addiu       $s1, $s1, 0x6C
    ctx->r17 = ADD32(ctx->r17, 0X6C);
L_80032460:
    // andi        $v0, $s5, 0x4
    ctx->r2 = ctx->r21 & 0X4;
    // beq         $v0, $zero, L_80032498
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8019
        ctx->r2 = S32(0X8019 << 16);
        goto L_80032498;
    }
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $s1, $v0, -0x48C4
    ctx->r17 = ADD32(ctx->r2, -0X48C4);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // sll         $s2, $s4, 16
    ctx->r18 = S32(ctx->r20) << 16;
L_80032478:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x8003227C
    // sra         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18) >> 16;
    sub_8003227C(rdram, ctx);
    goto after_2;
    // sra         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18) >> 16;
    after_2:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x30
    ctx->r2 = SIGNED(ctx->r16) < 0X30 ? 1 : 0;
    // bne         $v0, $zero, L_80032478
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x6C
        ctx->r17 = ADD32(ctx->r17, 0X6C);
        goto L_80032478;
    }
    // addiu       $s1, $s1, 0x6C
    ctx->r17 = ADD32(ctx->r17, 0X6C);
L_80032498:
    // andi        $v0, $s5, 0x8
    ctx->r2 = ctx->r21 & 0X8;
    // beq         $v0, $zero, L_800324D0
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8019
        ctx->r2 = S32(0X8019 << 16);
        goto L_800324D0;
    }
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $s1, $v0, -0x48C4
    ctx->r17 = ADD32(ctx->r2, -0X48C4);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // sll         $s2, $s4, 16
    ctx->r18 = S32(ctx->r20) << 16;
L_800324B0:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x800322F8
    // sra         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18) >> 16;
    sub_800322F8(rdram, ctx);
    goto after_3;
    // sra         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18) >> 16;
    after_3:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x30
    ctx->r2 = SIGNED(ctx->r16) < 0X30 ? 1 : 0;
    // bne         $v0, $zero, L_800324B0
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x6C
        ctx->r17 = ADD32(ctx->r17, 0X6C);
        goto L_800324B0;
    }
    // addiu       $s1, $s1, 0x6C
    ctx->r17 = ADD32(ctx->r17, 0X6C);
L_800324D0:
    // andi        $v0, $s5, 0x10
    ctx->r2 = ctx->r21 & 0X10;
    // beq         $v0, $zero, L_80032508
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8019
        ctx->r2 = S32(0X8019 << 16);
        goto L_80032508;
    }
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $s1, $v0, -0x48C4
    ctx->r17 = ADD32(ctx->r2, -0X48C4);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // sll         $s2, $s4, 16
    ctx->r18 = S32(ctx->r20) << 16;
L_800324E8:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x80032358
    // sra         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18) >> 16;
    sub_80032358(rdram, ctx);
    goto after_4;
    // sra         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18) >> 16;
    after_4:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x30
    ctx->r2 = SIGNED(ctx->r16) < 0X30 ? 1 : 0;
    // bne         $v0, $zero, L_800324E8
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x6C
        ctx->r17 = ADD32(ctx->r17, 0X6C);
        goto L_800324E8;
    }
    // addiu       $s1, $s1, 0x6C
    ctx->r17 = ADD32(ctx->r17, 0X6C);
L_80032508:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
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
