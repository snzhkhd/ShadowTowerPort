#include "recomp.h"
#include "disable_warnings.h"

void CheckCallback(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lhu         $v0, 0x6B0A($v0)
    ctx->r2 = MEM_HU(0X6B0A, ctx->r2);
    // jr          $ra
    // nop

    return;
    // nop

;}
