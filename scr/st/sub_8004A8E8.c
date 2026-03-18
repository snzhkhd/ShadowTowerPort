#include "recomp.h"
#include "disable_warnings.h"

void sub_8004A8E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // lh          $v0, 0x2($a1)
    ctx->r2 = MEM_HS(0X2, ctx->r5);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // lh          $v0, 0x4($a1)
    ctx->r2 = MEM_HS(0X4, ctx->r5);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(0X8, ctx->r4);
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jr          $ra
    // sw          $v0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r2;
    return;
    // sw          $v0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r2;
;}
