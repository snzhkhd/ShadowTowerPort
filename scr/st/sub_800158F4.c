#include "recomp.h"
#include "disable_warnings.h"

void sub_800158F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // srl         $v1, $v1, 4
    ctx->r3 = S32(U32(ctx->r3) >> 4);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // andi        $a0, $a0, 0xF
    ctx->r4 = ctx->r4 & 0XF;
    // jr          $ra
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    return;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
;}
