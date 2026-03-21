#include "recomp.h"
#include "disable_warnings.h"

void RCpolyGT3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addi        $a3, $a1, 0x60
    ctx->r7 = ADD32(ctx->r5, 0X60);
    // addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // tail call → RCpolyGT3A(a0, a1, 0, a1+96)
    RCpolyGT3A(rdram, ctx);
;}
