#include "recomp.h"
#include "disable_warnings.h"

void sub_800340F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v1, $v0, 0x768C
    ctx->r3 = ADD32(ctx->r2, 0X768C);
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // addiu       $a2, $zero, -0x5
    ctx->r6 = ADD32(0, -0X5);
    // addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_8003410C:
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // beq         $v0, $zero, L_80034124
    if (ctx->r2 == 0) {
        // addiu       $v0, $a0, -0x1
        ctx->r2 = ADD32(ctx->r4, -0X1);
        goto L_80034124;
    }
    // addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
L_80034124:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $zero, L_8003410C
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
        goto L_8003410C;
    }
    // addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
