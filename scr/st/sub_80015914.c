#include "recomp.h"
#include "disable_warnings.h"

void sub_80015914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $a2
    ctx->r6 = hi;
    // srl         $a1, $a2, 3
    ctx->r5 = S32(U32(ctx->r6) >> 3);
    // andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5) << 2;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // jr          $ra
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    return;
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
;}
