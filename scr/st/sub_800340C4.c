#include "recomp.h"
#include "disable_warnings.h"

void sub_800340C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v1, $v0, 0x768C
    ctx->r3 = ADD32(ctx->r2, 0X768C);
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_800340D4:
    // sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
    // sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $zero, L_800340D4
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
        goto L_800340D4;
    }
    // addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
