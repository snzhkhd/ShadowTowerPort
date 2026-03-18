#include "recomp.h"
#include "disable_warnings.h"

void sub_8007D8F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sw          $a1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r5;
    // jr          $ra
    // sb          $a2, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r6;
    return;
    // sb          $a2, 0x34($a0)
    MEM_B(0X34, ctx->r4) = ctx->r6;
;}
