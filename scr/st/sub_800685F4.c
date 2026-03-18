#include "recomp.h"
#include "disable_warnings.h"

void sub_800685F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // bne         $v0, $zero, L_80068618
    if (ctx->r2 != 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80068618;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
L_80068604:
    // lhu         $v0, -0x2ECE($v1)
    ctx->r2 = MEM_HU(-0X2ECE, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // beq         $v0, $zero, L_80068604
    if (ctx->r2 == 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80068604;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80068618:
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    sub_80014CFC(rdram, ctx);
    goto after_0;
    // addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $v1, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r3;
    // sb          $v1, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r3;
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
