#include "recomp.h"
#include "disable_warnings.h"

void SetDrawOffset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // jal         0x8007AEA8
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8007AEA8(rdram, ctx);
    goto after_0;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_0:
    // sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
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
