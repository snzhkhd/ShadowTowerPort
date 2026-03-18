#include "recomp.h"
#include "disable_warnings.h"

void CD_set_test_parmnum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // jr          $ra
    // sw          $a0, 0xC84($at)
    MEM_W(0XC84, ctx->r1) = ctx->r4;
    return;
    // sw          $a0, 0xC84($at)
    MEM_W(0XC84, ctx->r1) = ctx->r4;
;}
