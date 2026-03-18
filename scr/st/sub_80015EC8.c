#include "recomp.h"
#include "disable_warnings.h"

void sub_80015EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4) << 1;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $v0, $v0, -0x7424
    ctx->r2 = ADD32(ctx->r2, -0X7424);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(0X0, ctx->r5);
    // lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(0X2, ctx->r5);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jr          $ra
    // sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) << 11;
    return;
    // sll         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) << 11;
;}
