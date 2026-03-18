#include "recomp.h"
#include "disable_warnings.h"

void start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $v0, $v0, -0x7E78
    ctx->r2 = ADD32(ctx->r2, -0X7E78);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addiu       $v1, $v1, -0x4AA0
    ctx->r3 = ADD32(ctx->r3, -0X4AA0);
L_80014330:
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $at, $zero, L_80014330
    if (ctx->r1 != 0) {
        // nop
    
        goto L_80014330;
    }
    // nop

    // lui         $gp, 0x8008
    ctx->r28 = S32(0X8008 << 16);
    // addiu       $gp, $gp, 0x7EC0
    ctx->r28 = ADD32(ctx->r28, 0X7EC0);
    // j           L_8001435C
    // nop

    sub_8001435C(rdram, ctx);
    return;
    // nop

;}
