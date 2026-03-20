#include "recomp.h"
#include "disable_warnings.h"

void DrawOTag(uint8_t* rdram, recomp_context* ctx) 
{
   // printf("[DrawOTag] addr=%08X\n", ctx->r4);
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lbu         $v0, 0x7CC2($v0)
    ctx->r2 = MEM_BU(0X7CC2, ctx->r2);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8007A090
    if (ctx->r2 != 0) {
        // sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
        goto L_8007A090;
    }
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x425C
    ctx->r4 = ADD32(ctx->r4, 0X425C);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7CBC($v0)
    ctx->r2 = MEM_W(0X7CBC, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
L_8007A090:
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7CB8($v0)
    ctx->r2 = MEM_W(0X7CB8, ctx->r2);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(0X18, ctx->r2);
    // lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(0X8, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
