#include "recomp.h"
#include "disable_warnings.h"

void sub_80014CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // beq         $v0, $zero, L_80014D24
    if (ctx->r2 == 0) {
        // addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
        goto L_80014D24;
    }
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80014D08:
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // bne         $v1, $zero, L_80014D08
    if (ctx->r3 != 0) {
        // addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_80014D08;
    }
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80014D24:
    // jr          $ra
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    return;
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
;}
