#include "recomp.h"
#include "disable_warnings.h"

void sub_800573BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $v1, $v1, -0x2E80
    ctx->r3 = ADD32(ctx->r3, -0X2E80);
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sh          $v0, 0x26($v1)
    MEM_H(0X26, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sh          $v0, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // sh          $v0, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // sh          $v0, 0x2C($v1)
    MEM_H(0X2C, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $v0, 0x2E($v1)
    MEM_H(0X2E, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // sh          $v0, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x32($v1)
    MEM_H(0X32, ctx->r3) = ctx->r2;
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // sh          $v0, 0x34($v1)
    MEM_H(0X34, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // sh          $v0, 0x36($v1)
    MEM_H(0X36, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x2000
    ctx->r2 = ADD32(0, 0X2000);
    // jr          $ra
    // sh          $v0, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r2;
    return;
    // sh          $v0, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r2;
;}
