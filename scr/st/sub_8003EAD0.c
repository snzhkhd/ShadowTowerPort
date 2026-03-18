#include "recomp.h"
#include "disable_warnings.h"

void sub_8003EAD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sw          $zero, 0x2E4($v0)
    MEM_W(0X2E4, ctx->r2) = 0;
    // sw          $zero, 0x2E8($v0)
    MEM_W(0X2E8, ctx->r2) = 0;
    // sh          $zero, 0x2CA($v0)
    MEM_H(0X2CA, ctx->r2) = 0;
    // sh          $zero, 0x2CC($v0)
    MEM_H(0X2CC, ctx->r2) = 0;
    // sh          $zero, 0x2C8($v0)
    MEM_H(0X2C8, ctx->r2) = 0;
    // jr          $ra
    // sb          $v1, 0x21E($v0)
    MEM_B(0X21E, ctx->r2) = ctx->r3;
    return;
    // sb          $v1, 0x21E($v0)
    MEM_B(0X21E, ctx->r2) = ctx->r3;
;}
