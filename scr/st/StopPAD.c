#include "recomp.h"
#include "disable_warnings.h"

void StopPAD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x800786D8
    // nop

    DisablePAD(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // jal         0x80078684
    // nop

    StopPAD2(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x80078580
    // nop

    sub_80078580(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x7C40($at)
    MEM_W(0X7C40, ctx->r1) = 0;
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
