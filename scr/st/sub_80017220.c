#include "recomp.h"
#include "disable_warnings.h"

void sub_80017220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $a0, $s0, 0xB8
    ctx->r4 = ADD32(ctx->r16, 0XB8);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // addiu       $a3, $zero, 0x280
    ctx->r7 = ADD32(0, 0X280);
    // jal         0x800796A8
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    sub_800796A8(rdram, ctx);
    goto after_0;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_0:
    // addiu       $s1, $s0, 0x5C
    ctx->r17 = ADD32(ctx->r16, 0X5C);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // addiu       $a3, $zero, 0x280
    ctx->r7 = ADD32(0, 0X280);
    // jal         0x800795F4
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    sub_800795F4(rdram, ctx);
    goto after_1;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_1:
    // addiu       $a0, $s0, 0xCC
    ctx->r4 = ADD32(ctx->r16, 0XCC);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // addiu       $a3, $zero, 0x280
    ctx->r7 = ADD32(0, 0X280);
    // jal         0x800796A8
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    sub_800796A8(rdram, ctx);
    goto after_2;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_2:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0xC8($s0)
    MEM_B(0XC8, ctx->r16) = ctx->r2;
    // sb          $zero, 0x17($s0)
    MEM_B(0X17, ctx->r16) = 0;
    // sb          $v0, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r2;
    // sb          $v0, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r2;
    // sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
    // sb          $v0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r2;
    // sb          $zero, 0x19($s0)
    MEM_B(0X19, ctx->r16) = 0;
    // sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // sb          $zero, 0x19($s1)
    MEM_B(0X19, ctx->r17) = 0;
    // sb          $zero, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = 0;
    // sb          $zero, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = 0;
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
