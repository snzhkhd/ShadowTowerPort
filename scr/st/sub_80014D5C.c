#include "recomp.h"
#include "disable_warnings.h"

void sub_80014D5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // j           L_80014D70
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    goto L_80014D70;
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
L_80014D64:
    // sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
L_80014D70:
    // bne         $v0, $zero, L_80014D64
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
        goto L_80014D64;
    }
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // jr          $ra
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
