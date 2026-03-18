#include "recomp.h"
#include "disable_warnings.h"

void sub_80038438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lh          $a1, 0x0($v0)
    ctx->r5 = MEM_HS(0X0, ctx->r2);
    // lh          $a2, 0x2($v0)
    ctx->r6 = MEM_HS(0X2, ctx->r2);
    // jal         0x80079DCC
    // nop

    MoveImage(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
