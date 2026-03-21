#include "recomp.h"
#include "disable_warnings.h"

void sub_80042CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // addiu       $s0, $s0, -0x2EE0
    ctx->r16 = ADD32(ctx->r16, -0X2EE0);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lbu         $s2, 0x3($s0)
    ctx->r18 = MEM_BU(0X3, ctx->r16);
    // lbu         $s1, 0x5($s0)
    ctx->r17 = MEM_BU(0X5, ctx->r16);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // jal         0x80026AFC
    // sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    DrawScene_80026AFC(rdram, ctx);
    goto after_0;
    // sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    after_0:
    // jal         0x800341A0
    // nop

    sub_800341A0(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x8003509C
    // nop

    sub_8003509C(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x80034224
    // nop

    sub_80034224(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x80035120
    // nop

    sub_80035120(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // sb          $s2, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r18;
    // sb          $s1, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r17;
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
