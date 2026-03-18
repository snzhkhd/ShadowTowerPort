#include "recomp.h"
#include "disable_warnings.h"

void sub_8007EE38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addiu       $v1, $v1, -0x4C88
    ctx->r3 = ADD32(ctx->r3, -0X4C88);
L_8007EE48:
    // beq         $a0, $v1, L_8007EE68
    if (ctx->r4 == ctx->r3) {
        // addu        $v0, $a2, $zero
        ctx->r2 = ADD32(ctx->r6, 0);
        goto L_8007EE68;
    }
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x2
    ctx->r2 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8007EE48
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0xF0
        ctx->r3 = ADD32(ctx->r3, 0XF0);
        goto L_8007EE48;
    }
    // addiu       $v1, $v1, 0xF0
    ctx->r3 = ADD32(ctx->r3, 0XF0);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8007EE68:
    // jr          $ra
    // nop

    return;
    // nop

;}
