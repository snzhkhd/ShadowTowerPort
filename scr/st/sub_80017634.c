#include "recomp.h"
#include "disable_warnings.h"

void sub_80017634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // addiu       $s0, $s0, -0x2F70
    ctx->r16 = ADD32(ctx->r16, -0X2F70);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lw          $a2, 0x2E8($s0)
    ctx->r6 = MEM_W(0X2E8, ctx->r16);
    // lw          $a0, 0xE4($s0)
    ctx->r4 = MEM_W(0XE4, ctx->r16);
    // jal         0x8007C7A4
    // addiu       $a1, $a2, 0xFC
    ctx->r5 = ADD32(ctx->r6, 0XFC);
    AddPrims(rdram, ctx);
    goto after_0;
    // addiu       $a1, $a2, 0xFC
    ctx->r5 = ADD32(ctx->r6, 0XFC);
    after_0:
    // lw          $a0, 0xE4($s0)
    ctx->r4 = MEM_W(0XE4, ctx->r16);
    // jal         0x8007A054
    // addiu       $a0, $a0, 0x3FFC
    ctx->r4 = ADD32(ctx->r4, 0X3FFC);
    DrawOTag(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, 0x3FFC
    ctx->r4 = ADD32(ctx->r4, 0X3FFC);
    after_1:
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
