#include "recomp.h"
#include "disable_warnings.h"

void sub_800214A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // sb          $a0, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r4;
    // sb          $a0, 0x74($v1)
    MEM_B(0X74, ctx->r3) = ctx->r4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // jr          $ra
    // sb          $zero, 0x6CC4($v1)
    MEM_B(0X6CC4, ctx->r3) = 0;
    return;
    // sb          $zero, 0x6CC4($v1)
    MEM_B(0X6CC4, ctx->r3) = 0;
;}
