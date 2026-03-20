#include "recomp.h"
#include "disable_warnings.h"

void memset_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // beq         $a2, $zero, L_8007C6E4
    if (ctx->r6 == 0) {
        // addiu       $v0, $a2, -0x1
        ctx->r2 = ADD32(ctx->r6, -0X1);
        goto L_8007C6E4;
    }
    // addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8007C6D4:
    // sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $v0, $v1, L_8007C6D4
    if (ctx->r2 != ctx->r3) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_8007C6D4;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8007C6E4:
    // jr          $ra
    // nop

    return;
    // nop

;}
