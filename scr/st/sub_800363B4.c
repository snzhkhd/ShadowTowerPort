#include "recomp.h"
#include "disable_warnings.h"

void sub_800363B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
    // sb          $v0, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $a1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r5;
    // sb          $a3, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r7;
    // sh          $v0, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r2;
    // sh          $a2, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r6;
    // sh          $a2, 0x3A($a0)
    MEM_H(0X3A, ctx->r4) = ctx->r6;
    // jr          $ra
    // sh          $a2, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r6;
    return;
    // sh          $a2, 0x38($a0)
    MEM_H(0X38, ctx->r4) = ctx->r6;
;}
