#include "recomp.h"
#include "disable_warnings.h"

void sub_8004B090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // jr          $ra
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
