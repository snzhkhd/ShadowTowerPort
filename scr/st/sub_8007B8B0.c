#include "recomp.h"
#include "disable_warnings.h"

void sub_8007B8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // jal         0x8007B8D4
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    GPU_SafeExecute(rdram, ctx);
    goto after_0;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
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
