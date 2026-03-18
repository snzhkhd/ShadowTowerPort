#include "recomp.h"
#include "disable_warnings.h"

void SetIntrMask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7B98($v1)
    ctx->r3 = MEM_W(0X7B98, ctx->r3);
    // nop

    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // jr          $ra
    // sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    return;
    // sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
;}
