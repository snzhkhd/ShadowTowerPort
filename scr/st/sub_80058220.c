#include "recomp.h"
#include "disable_warnings.h"

void sub_80058220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addiu       $v0, $zero, 0x4800
    ctx->r2 = ADD32(0, 0X4800);
    // sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) << 16;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // sw          $a3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r7;
    // addiu       $a3, $zero, 0x5000
    ctx->r7 = ADD32(0, 0X5000);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jal         0x80057FC4
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80057FC4(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
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
