#include "recomp.h"
#include "disable_warnings.h"

void sub_80050468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // andi        $s2, $a1, 0xFFFF
    ctx->r18 = ctx->r5 & 0XFFFF;
    // addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // addiu       $s1, $zero, 0x400
    ctx->r17 = ADD32(0, 0X400);
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // addiu       $s0, $zero, 0x500
    ctx->r16 = ADD32(0, 0X500);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // jal         0x80050288
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    sub_80050288(rdram, ctx);
    goto after_0;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_0:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // jal         0x80050288
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    sub_80050288(rdram, ctx);
    goto after_1;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_1:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // jal         0x80050288
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    sub_80050288(rdram, ctx);
    goto after_2;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_2:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addiu       $a1, $zero, 0xAF
    ctx->r5 = ADD32(0, 0XAF);
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // jal         0x80050288
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    sub_80050288(rdram, ctx);
    goto after_3;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_3:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x5($s3)
    MEM_B(0X5, ctx->r19) = ctx->r2;
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
