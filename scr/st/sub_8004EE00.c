#include "recomp.h"
#include "disable_warnings.h"

void sub_8004EE00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r2;
    // sh          $v0, 0x3E($a0)
    MEM_H(0X3E, ctx->r4) = ctx->r2;
    // sh          $v0, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // sh          $zero, 0x38($a0)
    MEM_H(0X38, ctx->r4) = 0;
    // sh          $zero, 0x34($a0)
    MEM_H(0X34, ctx->r4) = 0;
    // sh          $zero, 0x36($a0)
    MEM_H(0X36, ctx->r4) = 0;
    // sb          $v0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r2;
    // sh          $zero, 0x14($a0)
    MEM_H(0X14, ctx->r4) = 0;
    // sb          $v0, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r2;
    // jr          $ra
    // sh          $zero, 0x16($a0)
    MEM_H(0X16, ctx->r4) = 0;
    return;
    // sh          $zero, 0x16($a0)
    MEM_H(0X16, ctx->r4) = 0;
;}
