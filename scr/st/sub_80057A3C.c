#include "recomp.h"
#include "disable_warnings.h"

void sub_80057A3C(uint8_t* rdram, recomp_context* ctx) 
{
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x2E80
    ctx->r2 = ADD32(ctx->r2, -0X2E80);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // sb          $zero, 0x13($v0)
    MEM_B(0X13, ctx->r2) = 0;
    // sb          $zero, 0x12($v0)
    MEM_B(0X12, ctx->r2) = 0;
    // sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    // sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // jr          $ra
    // sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    return;
    // sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
;}
