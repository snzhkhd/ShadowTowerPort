#include "recomp.h"
#include "disable_warnings.h"

void sub_8003EA20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x70D8
    ctx->r16 = ADD32(ctx->r16, -0X70D8);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, 0xF28
    ctx->r2 = ADD32(ctx->r2, 0XF28);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $v0, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->r2;
    // addiu       $v0, $v0, 0x4000
    ctx->r2 = ADD32(ctx->r2, 0X4000);
    // sw          $v0, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x6DE0
    ctx->r2 = ADD32(ctx->r2, -0X6DE0);
    // sw          $v0, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->r2;
    // addiu       $v0, $v0, 0x7000
    ctx->r2 = ADD32(ctx->r2, 0X7000);
    // sw          $v0, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, 0x7220
    ctx->r2 = ADD32(ctx->r2, 0X7220);
    // sw          $v0, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->r2;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v0, $v0, -0x1DE0
    ctx->r2 = ADD32(ctx->r2, -0X1DE0);
    // jal         0x8003E874
    // sw          $v0, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r2;
    sub_8003E874(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r2;
    after_0:
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // addiu       $v1, $a0, -0x2EE0
    ctx->r3 = ADD32(ctx->r4, -0X2EE0);
    // addiu       $v0, $zero, 0x3F
    ctx->r2 = ADD32(0, 0X3F);
    // sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // sb          $v0, -0x2EE0($a0)
    MEM_B(-0X2EE0, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    // sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sb          $v0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // sb          $v0, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
    // sb          $zero, 0x21C($s0)
    MEM_B(0X21C, ctx->r16) = 0;
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
