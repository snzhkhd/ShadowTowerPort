#include "recomp.h"
#include "disable_warnings.h"

void GetGraphDebug(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lbu         $v0, 0x7CC2($v0)
    ctx->r2 = MEM_BU(0X7CC2, ctx->r2);
    // jr          $ra
    // nop

    return;
    // nop

;}
