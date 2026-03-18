#include "recomp.h"
#include "disable_warnings.h"

void _SsVmSeqKeyOff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lh          $v0, 0x5A($v1)
    ctx->r2 = MEM_HS(0X5A, ctx->r3);
    // jr          $ra
    // nop

    return;
    // nop

;}
