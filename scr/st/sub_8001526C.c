#include "recomp.h"
#include "disable_warnings.h"

void sub_8001526C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v0, -0xB($a0)
    ctx->r2 = MEM_BU(-0XB, ctx->r4);
    // jr          $ra
    // nop

    return;
    // nop

;}
