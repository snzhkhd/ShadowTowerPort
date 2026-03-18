#include "recomp.h"
#include "disable_warnings.h"

void sub_80068868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $t0, 0xA001
    ctx->r8 = S32(0XA001 << 16);
    // addiu       $t0, $t0, -0x2080
    ctx->r8 = ADD32(ctx->r8, -0X2080);
    // jalr        $t0
    // nop

    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // nop

;}
