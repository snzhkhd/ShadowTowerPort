#include "recomp.h"
#include "disable_warnings.h"

void sub_80057B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // slti        $v0, $s0, 0x100
    ctx->r2 = SIGNED(ctx->r16) < 0X100 ? 1 : 0;
    // bne         $v0, $zero, L_80057B98
    if (ctx->r2 != 0) {
        // sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
        goto L_80057B98;
    }
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // addiu       $s0, $s0, -0x100
    ctx->r16 = ADD32(ctx->r16, -0X100);
    // slti        $v0, $s0, 0x201
    ctx->r2 = SIGNED(ctx->r16) < 0X201 ? 1 : 0;
    // bne         $v0, $zero, L_80057B74
    if (ctx->r2 != 0) {
        // addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
        goto L_80057B74;
    }
    // addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // addiu       $s0, $zero, 0x200
    ctx->r16 = ADD32(0, 0X200);
L_80057B74:
    // sra         $a1, $s0, 3
    ctx->r5 = S32(ctx->r16) >> 3;
    // jal         0x800582F0
    // addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    sub_800582F0(rdram, ctx);
    goto after_0;
    // addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // bgez        $a0, L_80057B90
    if (SIGNED(ctx->r4) >= 0) {
        // nop
    
        goto L_80057B90;
    }
    // nop

    // addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
L_80057B90:
    // jal         0x80057A68
    // sra         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) >> 2;
    sub_80057A68(rdram, ctx);
    goto after_1;
    // sra         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) >> 2;
    after_1:
L_80057B98:
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
