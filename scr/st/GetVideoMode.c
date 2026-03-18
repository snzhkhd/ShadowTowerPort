#include "recomp.h"
#include "disable_warnings.h"

void GetVideoMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7C10($v0)
    ctx->r2 = MEM_W(0X7C10, ctx->r2);
    // jr          $ra
    // nop

    return;
    // nop

;}
