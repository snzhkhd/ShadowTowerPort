#include "recomp.h"
#include "disable_warnings.h"

void sub_800152D0(uint8_t* rdram, recomp_context* ctx) 
{
   
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // addiu       $v0, $a0, 0x7
    ctx->r2 = ADD32(ctx->r4, 0X7);
    // addiu       $a0, $zero, -0x8
    ctx->r4 = ADD32(0, -0X8);
    // jal         0x8001528C
    // and         $a0, $v0, $a0
    ctx->r4 = ctx->r2 & ctx->r4;
    sub_8001528C(rdram, ctx);
    goto after_0;
    // and         $a0, $v0, $a0
    ctx->r4 = ctx->r2 & ctx->r4;
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
