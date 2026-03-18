#include "recomp.h"
#include "disable_warnings.h"

void sub_8003EBFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // addu        $t2, $a2, $zero
    ctx->r10 = ADD32(ctx->r6, 0);
    // addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // addiu       $a0, $a0, -0x6E90
    ctx->r4 = ADD32(ctx->r4, -0X6E90);
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(0X38, ctx->r29);
    // addu        $a2, $t1, $zero
    ctx->r6 = ADD32(ctx->r9, 0);
    // sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // addu        $a3, $t2, $zero
    ctx->r7 = ADD32(ctx->r10, 0);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x8004A580
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    sub_8004A580(rdram, ctx);
    goto after_0;
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
