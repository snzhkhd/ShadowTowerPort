#include "recomp.h"
#include "disable_warnings.h"

void sub_8003E840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
L_8003E850:
    // sw          $zero, 0x1EC($a0)
    MEM_W(0X1EC, ctx->r4) = 0;
    // sh          $zero, 0x20C($v1)
    MEM_H(0X20C, ctx->r3) = 0;
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x5
    ctx->r2 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_8003E850
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_8003E850;
    }
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // jr          $ra
    // nop

    return;
    // nop

;}
