#include "recomp.h"
#include "disable_warnings.h"

void sub_8003EC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // addiu       $s1, $sp, 0x28
    ctx->r17 = ADD32(ctx->r29, 0X28);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // jal         0x80078AB4
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    memset_recomp(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    after_0:
    // addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    memset_recomp(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
    // beq         $s3, $zero, L_8003ECC8
    if (ctx->r19 == 0) {
        // addu        $s1, $s0, $zero
        ctx->r17 = ADD32(ctx->r16, 0);
        goto L_8003ECC8;
    }
    // addu        $s1, $s0, $zero
    ctx->r17 = ADD32(ctx->r16, 0);
    // addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
L_8003ECC8:
    // beq         $s4, $zero, L_8003ECD4
    if (ctx->r20 == 0) {
        // addu        $s0, $s5, $zero
        ctx->r16 = ADD32(ctx->r21, 0);
        goto L_8003ECD4;
    }
    // addu        $s0, $s5, $zero
    ctx->r16 = ADD32(ctx->r21, 0);
    // addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
L_8003ECD4:
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // bne         $v1, $v0, L_8003EE0C
    if (ctx->r3 != ctx->r2) {
        // addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_8003EE0C;
    }
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // beq         $v0, $zero, L_8003ED80
    if (ctx->r2 == 0) {
        // addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_8003ED80;
    }
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // bne         $s6, $zero, L_8003ED3C
    if (ctx->r22 != 0) {
        // sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
        goto L_8003ED3C;
    }
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x14($sp)
    ctx->r2 = MEM_HU(0X14, ctx->r29);
    // lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(0X0, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x16($sp)
    ctx->r2 = MEM_HU(0X16, ctx->r29);
    // lhu         $v1, 0x2($s2)
    ctx->r3 = MEM_HU(0X2, ctx->r18);
    // j           L_8003ED4C
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    goto L_8003ED4C;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8003ED3C:
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // nop

    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
L_8003ED4C:
    // nop

    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(0X1A, ctx->r29);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // jal         0x80079D0C
    // sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    LoadImage(rdram, ctx);
    goto after_2;
    // sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    after_2:
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, -0xC
    ctx->r2 = ADD32(ctx->r2, -0XC);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_8003ED80:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // bne         $s6, $zero, L_8003EDC4
    if (ctx->r22 != 0) {
        // sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
        goto L_8003EDC4;
    }
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x14($sp)
    ctx->r2 = MEM_HU(0X14, ctx->r29);
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x16($sp)
    ctx->r2 = MEM_HU(0X16, ctx->r29);
    // lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(0X2, ctx->r17);
    // j           L_8003EDD4
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    goto L_8003EDD4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8003EDC4:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
L_8003EDD4:
    // nop

    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(0X1A, ctx->r29);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // jal         0x80079D0C
    // sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    LoadImage(rdram, ctx);
    goto after_3;
    // sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    after_3:
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // addiu       $v0, $v0, -0xC
    ctx->r2 = ADD32(ctx->r2, -0XC);
    // j           L_8003ECD4
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    goto L_8003ECD4;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_8003EE0C:
    // lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(0X54, ctx->r29);
    // lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(0X50, ctx->r29);
    // lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(0X4C, ctx->r29);
    // lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(0X48, ctx->r29);
    // lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(0X44, ctx->r29);
    // lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(0X40, ctx->r29);
    // lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(0X3C, ctx->r29);
    // lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // jr          $ra
    // nop

    return;
    // nop

;}
