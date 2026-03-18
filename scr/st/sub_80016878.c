#include "recomp.h"
#include "disable_warnings.h"

void sub_80016878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x4430
    ctx->r2 = ADD32(ctx->r2, -0X4430);
    // addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
    // addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_8001688C:
    // sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bne         $v1, $a0, L_8001688C
    if (ctx->r3 != ctx->r4) {
        // addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
        goto L_8001688C;
    }
    // addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
