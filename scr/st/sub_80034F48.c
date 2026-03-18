#include "recomp.h"
#include "disable_warnings.h"

void sub_80034F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $a0, $v0, 0x780C
    ctx->r4 = ADD32(ctx->r2, 0X780C);
    // addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // addiu       $v1, $a0, 0x38
    ctx->r3 = ADD32(ctx->r4, 0X38);
L_80034F64:
    // sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // sh          $a2, -0x36($v1)
    MEM_H(-0X36, ctx->r3) = ctx->r6;
    // sh          $a3, -0x34($v1)
    MEM_H(-0X34, ctx->r3) = ctx->r7;
    // sw          $zero, -0x30($v1)
    MEM_W(-0X30, ctx->r3) = 0;
    // sw          $zero, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = 0;
    // sw          $zero, -0x28($v1)
    MEM_W(-0X28, ctx->r3) = 0;
    // sw          $zero, -0x24($v1)
    MEM_W(-0X24, ctx->r3) = 0;
    // sw          $zero, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = 0;
    // sw          $zero, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = 0;
    // sw          $a2, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r6;
    // sw          $zero, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = 0;
    // sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    // addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $zero, L_80034F64
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x3C
        ctx->r4 = ADD32(ctx->r4, 0X3C);
        goto L_80034F64;
    }
    // addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // jr          $ra
    // nop

    return;
    // nop

;}
