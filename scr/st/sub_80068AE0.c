#include "recomp.h"
#include "disable_warnings.h"

void sub_80068AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // jal         0x80077DF4
    // addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    DeliverEvent(rdram, ctx);
    goto after_0;
    // addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
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
