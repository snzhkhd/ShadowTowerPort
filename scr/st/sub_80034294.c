#include "recomp.h"
#include "disable_warnings.h"

void sub_80034294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, 0x768C
    ctx->r2 = ADD32(ctx->r2, 0X768C);
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    // addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_800342BC:
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // nop

    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // beq         $v0, $zero, L_8003432C
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x18
        ctx->r2 = ADD32(ctx->r3, 0X18);
        goto L_8003432C;
    }
    // addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $zero, L_800342BC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800342BC;
    }
    // nop

    // jal         0x800341A0
    // nop

    sub_800341A0(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, 0x768C
    ctx->r2 = ADD32(ctx->r2, 0X768C);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // addiu       $a1, $zero, -0x5
    ctx->r5 = ADD32(0, -0X5);
    // addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_80034310:
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // nop

    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // bne         $v0, $zero, L_80034334
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, 0x18
        ctx->r2 = ADD32(ctx->r3, 0X18);
        goto L_80034334;
    }
    // addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
L_8003432C:
    // j           L_80034350
    // sh          $a2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r6;
    goto L_80034350;
    // sh          $a2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r6;
L_80034334:
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $zero, L_80034310
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80034310;
    }
    // nop

    // sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_80034350:
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
