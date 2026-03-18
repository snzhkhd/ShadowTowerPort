#include "recomp.h"
#include "disable_warnings.h"

void sub_8007E054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E34($v0)
    ctx->r2 = MEM_W(0X7E34, ctx->r2);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // jalr        $v0
    // addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
    after_0:
    // bne         $v0, $zero, L_8007E0D0
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007E0D0;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lbu         $a0, 0xE4($s0)
    ctx->r4 = MEM_BU(0XE4, ctx->r16);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $v1, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r3;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, -0x1F14
    ctx->r3 = ADD32(ctx->r3, -0X1F14);
    // sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, -0x1EC0
    ctx->r3 = ADD32(ctx->r3, -0X1EC0);
    // sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
    // sb          $s1, 0x51($s0)
    MEM_B(0X51, ctx->r16) = ctx->r17;
    // sb          $s2, 0x52($s0)
    MEM_B(0X52, ctx->r16) = ctx->r18;
    // xor         $v1, $v1, $a0
    ctx->r3 = ctx->r3 ^ ctx->r4;
    // sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // sb          $v1, 0x53($s0)
    MEM_B(0X53, ctx->r16) = ctx->r3;
L_8007E0D0:
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
