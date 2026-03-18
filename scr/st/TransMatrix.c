#include "recomp.h"
#include "disable_warnings.h"

void TransMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(0X0, ctx->r5);
    // lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(0X4, ctx->r5);
    // lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(0X8, ctx->r5);
    // sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    // sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // sw          $t2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r10;
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // jr          $ra
    // nop

    return;
    // nop

;}
