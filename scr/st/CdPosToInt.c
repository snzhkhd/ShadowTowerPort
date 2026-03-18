#include "recomp.h"
#include "disable_warnings.h"

void CdPosToInt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // lbu         $a2, 0x1($a0)
    ctx->r6 = MEM_BU(0X1, ctx->r4);
    // srl         $a1, $v1, 4
    ctx->r5 = S32(U32(ctx->r3) >> 4);
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // andi        $v1, $v1, 0xF
    ctx->r3 = ctx->r3 & 0XF;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $a1, $v0, 4
    ctx->r5 = S32(ctx->r2) << 4;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // srl         $v1, $a2, 4
    ctx->r3 = S32(U32(ctx->r6) >> 4);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // andi        $a2, $a2, 0xF
    ctx->r6 = ctx->r6 & 0XF;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5) << 2;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // lbu         $a1, 0x2($a0)
    ctx->r5 = MEM_BU(0X2, ctx->r4);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // srl         $a0, $a1, 4
    ctx->r4 = S32(U32(ctx->r5) >> 4);
    // sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) << 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // andi        $a1, $a1, 0xF
    ctx->r5 = ctx->r5 & 0XF;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jr          $ra
    // addiu       $v0, $v0, -0x96
    ctx->r2 = ADD32(ctx->r2, -0X96);
    return;
    // addiu       $v0, $v0, -0x96
    ctx->r2 = ADD32(ctx->r2, -0X96);
;}
