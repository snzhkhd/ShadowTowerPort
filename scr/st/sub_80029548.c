#include "recomp.h"
#include "disable_warnings.h"

void sub_80029548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // addu        $t2, $a2, $zero
    ctx->r10 = ADD32(ctx->r6, 0);
    // lui         $a0, 0x1F80
    ctx->r4 = S32(0X1F80 << 16);
    // ori         $a0, $a0, 0x348
    ctx->r4 = ctx->r4 | 0X348;
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // ori         $a1, $a1, 0x344
    ctx->r5 = ctx->r5 | 0X344;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
    // addiu       $v1, $zero, 0x50
    ctx->r3 = ADD32(0, 0X50);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // sb          $v1, 0x339($v0)
    MEM_B(0X339, ctx->r2) = ctx->r3;
    // sb          $v1, 0x338($v0)
    MEM_B(0X338, ctx->r2) = ctx->r3;
    // addiu       $v1, $zero, 0x60
    ctx->r3 = ADD32(0, 0X60);
    // sb          $v1, 0x33A($v0)
    MEM_B(0X33A, ctx->r2) = ctx->r3;
    // addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
    // sb          $v1, 0x345($v0)
    MEM_B(0X345, ctx->r2) = ctx->r3;
    // sb          $v1, 0x344($v0)
    MEM_B(0X344, ctx->r2) = ctx->r3;
    // addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // sh          $t0, 0x33C($v0)
    MEM_H(0X33C, ctx->r2) = ctx->r8;
    // addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // sh          $t1, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r9;
    // addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // sh          $t2, 0x340($v0)
    MEM_H(0X340, ctx->r2) = ctx->r10;
    // addiu       $t2, $t2, -0x4
    ctx->r10 = ADD32(ctx->r10, -0X4);
    // sh          $a3, 0x342($v0)
    MEM_H(0X342, ctx->r2) = ctx->r7;
    // addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    // sb          $v1, 0x346($v0)
    MEM_B(0X346, ctx->r2) = ctx->r3;
    // sh          $t0, 0x348($v0)
    MEM_H(0X348, ctx->r2) = ctx->r8;
    // sh          $t1, 0x34A($v0)
    MEM_H(0X34A, ctx->r2) = ctx->r9;
    // sh          $t2, 0x34C($v0)
    MEM_H(0X34C, ctx->r2) = ctx->r10;
    // jal         0x80028220
    // sh          $a3, 0x34E($v0)
    MEM_H(0X34E, ctx->r2) = ctx->r7;
    sub_80028220(rdram, ctx);
    goto after_0;
    // sh          $a3, 0x34E($v0)
    MEM_H(0X34E, ctx->r2) = ctx->r7;
    after_0:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_1;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_1:
    // lui         $a0, 0x1F80
    ctx->r4 = S32(0X1F80 << 16);
    // ori         $a0, $a0, 0x33C
    ctx->r4 = ctx->r4 | 0X33C;
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // ori         $a1, $a1, 0x338
    ctx->r5 = ctx->r5 | 0X338;
    // jal         0x80028220
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sub_80028220(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // jal         0x800286A8
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    sub_800286A8(rdram, ctx);
    goto after_3;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_3:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
