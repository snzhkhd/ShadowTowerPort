#include "recomp.h"
#include "disable_warnings.h"

void sub_8006620C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // addiu       $a2, $a2, -0x7378
    ctx->r6 = ADD32(ctx->r6, -0X7378);
    // jal         0x80015D54
    // addiu       $a3, $a3, 0x61C8
    ctx->r7 = ADD32(ctx->r7, 0X61C8);
    sub_80015D54(rdram, ctx);
    goto after_0;
    // addiu       $a3, $a3, 0x61C8
    ctx->r7 = ADD32(ctx->r7, 0X61C8);
    after_0:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
