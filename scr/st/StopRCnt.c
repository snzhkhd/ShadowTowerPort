#include "recomp.h"
#include "disable_warnings.h"

void StopRCnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0x7C20($a1)
    ctx->r5 = MEM_W(0X7C20, ctx->r5);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lw          $v0, 0x7C28($v0)
    ctx->r2 = MEM_W(0X7C28, ctx->r2);
    // lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(0X4, ctx->r5);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jr          $ra
    // sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    return;
    // sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
;}
