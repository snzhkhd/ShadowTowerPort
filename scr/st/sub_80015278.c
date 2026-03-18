#include "recomp.h"
#include "disable_warnings.h"

void sub_80015278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // jr          $ra
    // sh          $a1, -0xA($a0)
    MEM_H(-0XA, ctx->r4) = ctx->r5;
    return;
    // sh          $a1, -0xA($a0)
    MEM_H(-0XA, ctx->r4) = ctx->r5;
;}
