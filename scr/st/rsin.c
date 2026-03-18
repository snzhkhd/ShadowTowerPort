#include "recomp.h"
#include "disable_warnings.h"

void rsin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // bltz        $a0, L_80074410
    if (SIGNED(ctx->r4) < 0) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_80074410;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x80074430
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    sin_1(rdram, ctx);
    goto after_0;
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    after_0:
    // j           L_80074420
    // nop

    goto L_80074420;
    // nop

L_80074410:
    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // jal         0x80074430
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    sin_1(rdram, ctx);
    goto after_1;
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    after_1:
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80074420:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
