#include "recomp.h"
#include "disable_warnings.h"

void _SpuIsInAllocateArea(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE28($v0)
    ctx->r2 = MEM_W(0XE28, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8006FB10
    if (ctx->r2 != 0) {
        // lui         $t0, 0x8000
        ctx->r8 = S32(0X8000 << 16);
        goto L_8006FB10;
    }
    // lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // j           L_8006FB6C
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8006FB6C;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006FB10:
    // lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // lui         $a2, 0xFFF
    ctx->r6 = S32(0XFFF << 16);
    // ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
L_8006FB20:
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // nop

    // and         $v0, $v1, $t0
    ctx->r2 = ctx->r3 & ctx->r8;
    // bne         $v0, $zero, L_8006FB60
    if (ctx->r2 != 0) {
        // and         $v0, $v1, $a3
        ctx->r2 = ctx->r3 & ctx->r7;
        goto L_8006FB60;
    }
    // and         $v0, $v1, $a3
    ctx->r2 = ctx->r3 & ctx->r7;
    // bne         $v0, $zero, L_8006FB68
    if (ctx->r2 != 0) {
        // and         $v1, $v1, $a2
        ctx->r3 = ctx->r3 & ctx->r6;
        goto L_8006FB68;
    }
    // and         $v1, $v1, $a2
    ctx->r3 = ctx->r3 & ctx->r6;
    // sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // beq         $v0, $zero, L_8006FB6C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8006FB6C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(0X4, ctx->r5);
    // nop

    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // bne         $v0, $zero, L_8006FB6C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8006FB6C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006FB60:
    // j           L_8006FB20
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    goto L_8006FB20;
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_8006FB68:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006FB6C:
    // jr          $ra
    // nop

    return;
    // nop

;}
