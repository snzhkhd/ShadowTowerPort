#include "recomp.h"
#include "disable_warnings.h"

void sub_80036370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v1, $v0, -0x1CE8
    ctx->r3 = ADD32(ctx->r2, -0X1CE8);
    // addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_80036380:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $a1, L_800363A8
    if (ctx->r2 == ctx->r5) {
        // addiu       $v0, $a0, -0x1
        ctx->r2 = ADD32(ctx->r4, -0X1);
        goto L_800363A8;
    }
    // addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $zero, L_80036380
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x58
        ctx->r3 = ADD32(ctx->r3, 0X58);
        goto L_80036380;
    }
    // addiu       $v1, $v1, 0x58
    ctx->r3 = ADD32(ctx->r3, 0X58);
    // j           L_800363AC
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_800363AC;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800363A8:
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800363AC:
    // jr          $ra
    // nop

    return;
    // nop

;}
