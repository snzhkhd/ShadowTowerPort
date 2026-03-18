#include "recomp.h"
#include "disable_warnings.h"

void SsUtGetReverbType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lh          $v0, -0x69FC($v0)
    ctx->r2 = MEM_HS(-0X69FC, ctx->r2);
    // jr          $ra
    // nop

    return;
    // nop

;}
