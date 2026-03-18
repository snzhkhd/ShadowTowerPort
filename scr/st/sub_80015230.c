#include "recomp.h"
#include "disable_warnings.h"

void sub_80015230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x80014E20
    // addiu       $a0, $a0, -0xC
    ctx->r4 = ADD32(ctx->r4, -0XC);
    sub_80014E20(rdram, ctx);
    goto after_0;
    // addiu       $a0, $a0, -0xC
    ctx->r4 = ADD32(ctx->r4, -0XC);
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
