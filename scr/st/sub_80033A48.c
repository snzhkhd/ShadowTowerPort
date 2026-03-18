#include "recomp.h"
#include "disable_warnings.h"

void sub_80033A48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // ori         $v0, $zero, 0x834C
    ctx->r2 = 0 | 0X834C;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(0X8, ctx->r5);
    // nop

    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sw          $a1, 0xC($at)
    MEM_W(0XC, ctx->r1) = ctx->r5;
    // jr          $ra
    // nop

    return;
    // nop

;}
