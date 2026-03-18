#include "recomp.h"
#include "disable_warnings.h"

void RCpolyFT4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addi        $a3, $a1, 0x78
    ctx->r7 = ADD32(ctx->r5, 0X78);
    // addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
;}
