#include "recomp.h"
#include "disable_warnings.h"

void sub_8003E734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lw          $v0, 0x248($v1)
    ctx->r2 = MEM_W(0X248, ctx->r3);
    // nop

    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // lw          $v0, 0x250($v1)
    ctx->r2 = MEM_W(0X250, ctx->r3);
    // nop

    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // lh          $a3, 0x2CE($v1)
    ctx->r7 = MEM_HS(0X2CE, ctx->r3);
    // lw          $v0, 0x24C($v1)
    ctx->r2 = MEM_W(0X24C, ctx->r3);
    // lh          $a2, 0x2D2($v1)
    ctx->r6 = MEM_HS(0X2D2, ctx->r3);
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // addiu       $v0, $v0, -0x640
    ctx->r2 = ADD32(ctx->r2, -0X640);
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x268($v1)
    ctx->r2 = MEM_HU(0X268, ctx->r3);
    // nop

    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x26A($v1)
    ctx->r2 = MEM_HU(0X26A, ctx->r3);
    // nop

    // sh          $v0, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x26C($v1)
    ctx->r2 = MEM_HU(0X26C, ctx->r3);
    // jr          $ra
    // sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    return;
    // sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
;}
