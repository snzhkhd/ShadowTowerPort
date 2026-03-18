#include "recomp.h"
#include "disable_warnings.h"

void sub_8007DAE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v0, 0xE3($a0)
    ctx->r2 = MEM_BU(0XE3, ctx->r4);
    // lbu         $a1, 0xE9($a0)
    ctx->r5 = MEM_BU(0XE9, ctx->r4);
    // lw          $a0, 0xEC($a0)
    ctx->r4 = MEM_W(0XEC, ctx->r4);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5) << 2;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // andi        $v1, $v1, 0xFFC
    ctx->r3 = ctx->r3 & 0XFFC;
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jr          $ra
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    return;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
;}
