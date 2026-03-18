#include "recomp.h"
#include "disable_warnings.h"

void CdLastPos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // jr          $ra
    // addiu       $v0, $v0, 0x9F4
    ctx->r2 = ADD32(ctx->r2, 0X9F4);
    return;
    // addiu       $v0, $v0, 0x9F4
    ctx->r2 = ADD32(ctx->r2, 0X9F4);
;}
