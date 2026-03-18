#include "recomp.h"
#include "disable_warnings.h"

void StartRCnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0x7C20($a1)
    ctx->r5 = MEM_W(0X7C20, ctx->r5);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // lw          $a0, 0x7C28($at)
    ctx->r4 = MEM_W(0X7C28, ctx->r1);
    // lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(0X4, ctx->r5);
    // slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // jr          $ra
    // sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    return;
    // sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
;}
