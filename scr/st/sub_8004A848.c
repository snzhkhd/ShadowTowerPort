#include "recomp.h"
#include "disable_warnings.h"

void sub_8004A848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // andi        $a1, $a1, 0xFFF
    ctx->r5 = ctx->r5 & 0XFFF;
    // slti        $v0, $a1, 0x801
    ctx->r2 = SIGNED(ctx->r5) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_8004A874
    if (ctx->r2 != 0) {
        // mult        $a1, $a2
        result = S64(S32(ctx->r5)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_8004A874;
    }
    // mult        $a1, $a2
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $a1, -0x1000
    ctx->r5 = ADD32(ctx->r5, -0X1000);
    // mult        $a1, $a2
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8004A874:
    // mflo        $v1
    ctx->r3 = lo;
    // sra         $v0, $v1, 12
    ctx->r2 = S32(ctx->r3) >> 12;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // jr          $ra
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    return;
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
;}
