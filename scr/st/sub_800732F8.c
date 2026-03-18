#include "recomp.h"
#include "disable_warnings.h"

void sub_800732F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v1, -0x79A0($v1)
    ctx->r3 = MEM_W(-0X79A0, ctx->r3);
    // lui         $a3, 0x801F
    ctx->r7 = S32(0X801F << 16);
    // addiu       $a3, $a3, -0x68F2
    ctx->r7 = ADD32(ctx->r7, -0X68F2);
    // sh          $a0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r4;
    // andi        $a0, $a0, 0xFF00
    ctx->r4 = ctx->r4 & 0XFF00;
    // sra         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) >> 8;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x58($v1)
    ctx->r2 = MEM_HU(0X58, ctx->r3);
    // nop

    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x5A($v1)
    ctx->r2 = MEM_HU(0X5A, ctx->r3);
    // nop

    // sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // lh          $v0, 0x0($a3)
    ctx->r2 = MEM_HS(0X0, ctx->r7);
    // jr          $ra
    // nop

    return;
    // nop

;}
