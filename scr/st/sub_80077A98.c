#include "recomp.h"
#include "disable_warnings.h"

void sub_80077A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, 0x7BB0
    ctx->r2 = ADD32(ctx->r2, 0X7BB0);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // nop

    // beq         $a1, $v0, L_80077ABC
    if (ctx->r5 == ctx->r2) {
        // nop
    
        goto L_80077ABC;
    }
    // nop

    // sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_80077ABC:
    // jr          $ra
    // nop

    return;
    // nop

;}
