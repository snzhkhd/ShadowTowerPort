#include "recomp.h"
#include "disable_warnings.h"

void sub_80052C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x6EAC
    ctx->r16 = ADD32(ctx->r16, -0X6EAC);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // jal         0x80052894
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_80052894(rdram, ctx);
    goto after_0;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // sb          $zero, -0x201($s0)
    MEM_B(-0X201, ctx->r16) = 0;
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
