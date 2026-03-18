#include "recomp.h"
#include "disable_warnings.h"

void sub_80049FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // lwl         $v0, 0x3($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r4);
    // lwr         $v0, 0x0($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r4);
    // lwl         $v1, 0x7($a0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r4);
    // lwr         $v1, 0x4($a0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r4);
    // swl         $v0, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r2);
    // swr         $v0, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r2);
    // swl         $v1, 0x37($sp)
    do_swl(rdram, 0X37, ctx->r29, ctx->r3);
    // swr         $v1, 0x34($sp)
    do_swr(rdram, 0X34, ctx->r29, ctx->r3);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7F64
    ctx->r6 = ADD32(ctx->r2, -0X7F64);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x3B($sp)
    do_swl(rdram, 0X3B, ctx->r29, ctx->r3);
    // swr         $v1, 0x38($sp)
    do_swr(rdram, 0X38, ctx->r29, ctx->r3);
    // swl         $a0, 0x3F($sp)
    do_swl(rdram, 0X3F, ctx->r29, ctx->r4);
    // swr         $a0, 0x3C($sp)
    do_swr(rdram, 0X3C, ctx->r29, ctx->r4);
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // lhu         $v0, 0x32($sp)
    ctx->r2 = MEM_HU(0X32, ctx->r29);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // jal         0x800758C4
    // sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
    RotMatrixZYX_gte(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
    after_0:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // jal         0x80074CF4
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    ApplyMatrixSV(rdram, ctx);
    goto after_1;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
    // lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
