#include "recomp.h"
#include "disable_warnings.h"

void _SsSndReplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addiu       $v0, $v0, -0x79A0
    ctx->r2 = ADD32(ctx->r2, -0X79A0);
    // sra         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4) >> 14;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $a1, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r5;
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x98($v0)
    ctx->r3 = MEM_W(0X98, ctx->r2);
    // addiu       $a0, $zero, -0x9
    ctx->r4 = ADD32(0, -0X9);
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // jr          $ra
    // sw          $v1, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r3;
    return;
    // sw          $v1, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r3;
;}
