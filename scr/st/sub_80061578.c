#include "recomp.h"
#include "disable_warnings.h"

void sub_80061578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // jal         0x800613E8
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_800613E8(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(0X1F4, ctx->r16);
    // nop

    // lhu         $v1, 0xE0($v0)
    ctx->r3 = MEM_HU(0XE0, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_800615B0
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_800615B0;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // j           L_800615BC
    // addiu       $v0, $zero, 0x15F
    ctx->r2 = ADD32(0, 0X15F);
    goto L_800615BC;
    // addiu       $v0, $zero, 0x15F
    ctx->r2 = ADD32(0, 0X15F);
L_800615B0:
    // bne         $v1, $v0, L_800615C4
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_800615C4;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // addiu       $v0, $zero, 0x15E
    ctx->r2 = ADD32(0, 0X15E);
L_800615BC:
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800615C4:
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
