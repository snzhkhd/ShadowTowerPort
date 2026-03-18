#include "recomp.h"
#include "disable_warnings.h"

void _copy_memcard_patch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // ori         $v0, $zero, 0xDF80
    ctx->r2 = 0 | 0XDF80;
    // lui         $t2, 0x8007
    ctx->r10 = S32(0X8007 << 16);
    // addiu       $t2, $t2, -0x781C
    ctx->r10 = ADD32(ctx->r10, -0X781C);
    // lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // addiu       $t1, $t1, -0x77AC
    ctx->r9 = ADD32(ctx->r9, -0X77AC);
L_80068994:
    // lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(0X0, ctx->r10);
    // nop

    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // bne         $t2, $t1, L_80068994
    if (ctx->r10 != ctx->r9) {
        // addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
        goto L_80068994;
    }
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // jr          $ra
    // nop

    return;
    // nop

;}
