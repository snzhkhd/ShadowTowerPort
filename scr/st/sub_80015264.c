#include "recomp.h"
#include "disable_warnings.h"

void sub_80015264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // jr          $ra
    // sb          $a1, -0xB($a0)
    MEM_B(-0XB, ctx->r4) = ctx->r5;
    return;
    // sb          $a1, -0xB($a0)
    MEM_B(-0XB, ctx->r4) = ctx->r5;
;}
