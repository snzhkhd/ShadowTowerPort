#include "recomp.h"
#include "disable_warnings.h"

void sub_8004A148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // subu        $a0, $a0, $a1
    ctx->r4 = SUB32(ctx->r4, ctx->r5);
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) << 16;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_8004A178
    if (ctx->r2 == 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_8004A178;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8004A17C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004A17C;
    }
    // nop

L_8004A178:
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8004A17C:
    // jr          $ra
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    return;
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
;}
