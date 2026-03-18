#include "recomp.h"
#include "disable_warnings.h"

void sub_80057BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v1, -0x5EDC($v0)
    ctx->r3 = MEM_W(-0X5EDC, ctx->r2);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // andi        $v0, $v1, 0x34
    ctx->r2 = ctx->r3 & 0X34;
    // beq         $v0, $zero, L_80057BD0
    if (ctx->r2 == 0) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_80057BD0;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // j           L_80057BF0
    // addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    goto L_80057BF0;
    // addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
L_80057BD0:
    // andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_80057BF0
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $zero, 0x11
        ctx->r4 = ADD32(0, 0X11);
        goto L_80057BF0;
    }
    // addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_80057BF0
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80057BF0;
    }
    // nop

    // addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
L_80057BF0:
    // sra         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) >> 2;
    // jal         0x800582F0
    // addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    sub_800582F0(rdram, ctx);
    goto after_0;
    // addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    after_0:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
