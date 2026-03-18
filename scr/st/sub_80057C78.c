#include "recomp.h"
#include "disable_warnings.h"

void sub_80057C78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x80058318
    // addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    sub_80058318(rdram, ctx);
    goto after_0;
    // addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
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
