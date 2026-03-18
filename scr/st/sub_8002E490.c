#include "recomp.h"
#include "disable_warnings.h"

void sub_8002E490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    // jal         0x80029548
    // addiu       $a3, $zero, 0xE0
    ctx->r7 = ADD32(0, 0XE0);
    sub_80029548(rdram, ctx);
    goto after_0;
    // addiu       $a3, $zero, 0xE0
    ctx->r7 = ADD32(0, 0XE0);
    after_0:
    // addiu       $a0, $zero, 0x134
    ctx->r4 = ADD32(0, 0X134);
    // addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // addiu       $a2, $zero, 0x144
    ctx->r6 = ADD32(0, 0X144);
    // jal         0x80029548
    // addiu       $a3, $zero, 0xE0
    ctx->r7 = ADD32(0, 0XE0);
    sub_80029548(rdram, ctx);
    goto after_1;
    // addiu       $a3, $zero, 0xE0
    ctx->r7 = ADD32(0, 0XE0);
    after_1:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
