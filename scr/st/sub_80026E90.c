#include "recomp.h"
#include "disable_warnings.h"

void sub_80026E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r2;
    // sb          $v0, 0x74($v1)
    MEM_B(0X74, ctx->r3) = ctx->r2;
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x2EC($v1)
    ctx->r2 = MEM_W(0X2EC, ctx->r3);
    // lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, 0x2F0($v1)
    MEM_W(0X2F0, ctx->r3) = ctx->r2;
    // sw          $v0, 0x2F8($v1)
    MEM_W(0X2F8, ctx->r3) = ctx->r2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // jr          $ra
    // sw          $v0, 0x2FC($v1)
    MEM_W(0X2FC, ctx->r3) = ctx->r2;
    return;
    // sw          $v0, 0x2FC($v1)
    MEM_W(0X2FC, ctx->r3) = ctx->r2;
;}
