#include "recomp.h"
#include "disable_warnings.h"

void sub_8004A0F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a3
    ctx->r7 = lo;
    // lh          $v0, 0x2($a1)
    ctx->r2 = MEM_HS(0X2, ctx->r5);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lh          $v0, 0x4($a1)
    ctx->r2 = MEM_HS(0X4, ctx->r5);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $a3, 12
    ctx->r2 = S32(ctx->r7) >> 12;
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // sra         $v0, $v1, 12
    ctx->r2 = S32(ctx->r3) >> 12;
    // sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // mflo        $a0
    ctx->r4 = lo;
    // sra         $v0, $a0, 12
    ctx->r2 = S32(ctx->r4) >> 12;
    // jr          $ra
    // sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    return;
    // sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
;}
