#include "recomp.h"
#include "disable_warnings.h"

void sub_8003306C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, -0x36A0
    ctx->r2 = ADD32(ctx->r2, -0X36A0);
    // addiu       $a0, $v0, 0x6C
    ctx->r4 = ADD32(ctx->r2, 0X6C);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // sw          $v0, 0x6E08($v1)
    MEM_W(0X6E08, ctx->r3) = ctx->r2;
    // sw          $a0, 0x6E0C($v1)
    MEM_W(0X6E0C, ctx->r3) = ctx->r4;
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // lbu         $v1, 0x5929($v1)
    ctx->r3 = MEM_BU(0X5929, ctx->r3);
    // addiu       $v0, $v0, -0x1290
    ctx->r2 = ADD32(ctx->r2, -0X1290);
    // sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $a1, 0xC($v1)
    ctx->r5 = MEM_BU(0XC, ctx->r3);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // andi        $a0, $a1, 0xF0
    ctx->r4 = ctx->r5 & 0XF0;
    // jal         0x80032800
    // andi        $a1, $a1, 0xF
    ctx->r5 = ctx->r5 & 0XF;
    sub_80032800(rdram, ctx);
    goto after_0;
    // andi        $a1, $a1, 0xF
    ctx->r5 = ctx->r5 & 0XF;
    after_0:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
