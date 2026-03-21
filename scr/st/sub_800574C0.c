#include "recomp.h"
#include "disable_warnings.h"

void sub_800574C0(uint8_t* rdram, recomp_context* ctx) 
{
    // stub — memory card reconnect detection not needed
    return;



    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // jal         0x8007CAC8
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_8007CAC8(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $s0, $v1, -0x2E80
    ctx->r16 = ADD32(ctx->r3, -0X2E80);
    // jal         0x80057428
    // sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
    sub_80057428(rdram, ctx);
    goto after_1;
    // sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
    after_1:
    // lbu         $v1, 0x18($s0)
    ctx->r3 = MEM_BU(0X18, ctx->r16);
    // nop

    // beq         $v1, $zero, L_80057548
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_80057548;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // bne         $v1, $v0, L_80057510
    if (ctx->r3 != ctx->r2) {
        // sb          $zero, 0x1B($s0)
        MEM_B(0X1B, ctx->r16) = 0;
        goto L_80057510;
    }
    // sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // j           L_80057514
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_80057514;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80057510:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80057514:
    // sb          $v0, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r2;
    // sb          $v0, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r2;
    // lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x2E80
    ctx->r2 = ADD32(ctx->r2, -0X2E80);
    // addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // sb          $v1, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = ctx->r3;
    // sb          $v1, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r3;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80057538:
    // jal         0x8007CC44
    // addiu       $a1, $s0, -0x2E66
    ctx->r5 = ADD32(ctx->r16, -0X2E66);
    sub_8007CC44(rdram, ctx);
    goto after_2;
    // addiu       $a1, $s0, -0x2E66
    ctx->r5 = ADD32(ctx->r16, -0X2E66);
    after_2:
    // beq         $v0, $zero, L_80057538
    if (ctx->r2 == 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80057538;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80057548:
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
