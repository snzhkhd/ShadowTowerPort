#include "recomp.h"
#include "disable_warnings.h"

void sub_80016508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $v1, 0x6CD8($v0)
    MEM_B(0X6CD8, ctx->r2) = ctx->r3;
    // sb          $v1, 0x6CD9($v0)
    MEM_B(0X6CD9, ctx->r2) = ctx->r3;
    // addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // sh          $zero, 0x6CE2($v0)
    MEM_H(0X6CE2, ctx->r2) = 0;
    // sh          $zero, 0x6CDE($v0)
    MEM_H(0X6CDE, ctx->r2) = 0;
    // sh          $zero, 0x6CDA($v0)
    MEM_H(0X6CDA, ctx->r2) = 0;
    // sb          $zero, 0x6CD6($v0)
    MEM_B(0X6CD6, ctx->r2) = 0;
    // sh          $zero, 0x6CE4($v0)
    MEM_H(0X6CE4, ctx->r2) = 0;
    // sh          $zero, 0x6CE0($v0)
    MEM_H(0X6CE0, ctx->r2) = 0;
    // sh          $zero, 0x6CDC($v0)
    MEM_H(0X6CDC, ctx->r2) = 0;
    // sb          $zero, 0x6CD7($v0)
    MEM_B(0X6CD7, ctx->r2) = 0;
    // jr          $ra
    // sb          $v1, 0x6CD2($v0)
    MEM_B(0X6CD2, ctx->r2) = ctx->r3;
    return;
    // sb          $v1, 0x6CD2($v0)
    MEM_B(0X6CD2, ctx->r2) = ctx->r3;
;}
