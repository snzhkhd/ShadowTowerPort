#include "recomp.h"
#include "disable_warnings.h"

void ClearImage2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x41FC
    ctx->r4 = ADD32(ctx->r4, 0X41FC);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // jal         0x80079AC8
    // addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    sub_80079AC8(rdram, ctx);
    goto after_0;
    // addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    after_0:
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17) << 16;
    // andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // sll         $s0, $s0, 8
    ctx->r16 = S32(ctx->r16) << 8;
    // lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // or          $s0, $s0, $v0
    ctx->r16 = ctx->r16 | ctx->r2;
    // or          $s1, $s1, $s0
    ctx->r17 = ctx->r17 | ctx->r16;
    // andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7CB8($v1)
    ctx->r3 = MEM_W(0X7CB8, ctx->r3);
    // addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // lw          $a0, 0xC($v1)
    ctx->r4 = MEM_W(0XC, ctx->r3);
    // lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(0X8, ctx->r3);
    // nop

    // jalr        $v0
    // or          $a3, $s1, $s2
    ctx->r7 = ctx->r17 | ctx->r18;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // or          $a3, $s1, $s2
    ctx->r7 = ctx->r17 | ctx->r18;
    after_1:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
