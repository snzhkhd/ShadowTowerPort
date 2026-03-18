#include "recomp.h"
#include "disable_warnings.h"

void sub_80068854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0xA001
    ctx->r2 = S32(0XA001 << 16);
    // addiu       $v0, $v0, -0x2054
    ctx->r2 = ADD32(ctx->r2, -0X2054);
    // jr          $v0
    // nop

    LOOKUP_FUNC(18446744072098996140)(rdram, ctx);
    return;
    // nop

;}
