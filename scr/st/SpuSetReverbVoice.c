#include "recomp.h"
#include "disable_warnings.h"

void SpuSetReverbVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // addiu       $a2, $zero, 0xCC
    ctx->r6 = ADD32(0, 0XCC);
    // jal         0x80070D54
    // addiu       $a3, $zero, 0xCD
    ctx->r7 = ADD32(0, 0XCD);
    _SpuSetAnyVoice(rdram, ctx);
    goto after_0;
    // addiu       $a3, $zero, 0xCD
    ctx->r7 = ADD32(0, 0XCD);
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
