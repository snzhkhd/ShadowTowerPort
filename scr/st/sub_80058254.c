#include "recomp.h"
#include "disable_warnings.h"

void sub_80058254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) << 16;
    // lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(0X30, ctx->r29);
    // lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(0X34, ctx->r29);
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // jal         0x80057FC4
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    sub_80057FC4(rdram, ctx);
    goto after_0;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
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
