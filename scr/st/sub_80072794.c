#include "recomp.h"
#include "disable_warnings.h"

void sub_80072794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4) << 3;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $zero, -0x70E3($at)
    MEM_B(-0X70E3, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $zero, -0x7100($at)
    MEM_H(-0X7100, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // jr          $ra
    // sh          $zero, -0x70FC($at)
    MEM_H(-0X70FC, ctx->r1) = 0;
    return;
    // sh          $zero, -0x70FC($at)
    MEM_H(-0X70FC, ctx->r1) = 0;
;}
