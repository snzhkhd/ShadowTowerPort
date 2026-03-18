#include "recomp.h"
#include "disable_warnings.h"

void PadSetMainMode_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jalr        $v0
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    after_0:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // jal         0x8007E054
    // andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    sub_8007E054(rdram, ctx);
    goto after_1;
    // andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    after_1:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
