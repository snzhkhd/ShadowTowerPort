#include "recomp.h"
#include "disable_warnings.h"

void sub_800168A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v1, $v0, -0x4430
    ctx->r3 = ADD32(ctx->r2, -0X4430);
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_800168B4:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $a1, L_800168D4
    if (ctx->r2 == ctx->r5) {
        // addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
        goto L_800168D4;
    }
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // bne         $a0, $zero, L_800168B4
    if (ctx->r4 != 0) {
        // addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
        goto L_800168B4;
    }
    // addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // j           L_800168D8
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_800168D8;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800168D4:
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_800168D8:
    // jr          $ra
    // nop

    return;
    // nop

;}
