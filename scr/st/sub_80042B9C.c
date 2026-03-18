#include "recomp.h"
#include "disable_warnings.h"

void sub_80042B9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lbu         $a3, 0x218($a1)
    ctx->r7 = MEM_BU(0X218, ctx->r5);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $a3, $v0, L_80042C00
    if (ctx->r7 == ctx->r2) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80042C00;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v1, $v0, -0x2E80
    ctx->r3 = ADD32(ctx->r2, -0X2E80);
    // lhu         $a2, 0x4($v1)
    ctx->r6 = MEM_HU(0X4, ctx->r3);
    // lhu         $a0, 0x36($v1)
    ctx->r4 = MEM_HU(0X36, ctx->r3);
    // nop

    // and         $v0, $a2, $a0
    ctx->r2 = ctx->r6 & ctx->r4;
    // beq         $v0, $zero, L_80042C00
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80042C00;
    }
    // nop

    // lbu         $v0, 0x12($v1)
    ctx->r2 = MEM_BU(0X12, ctx->r3);
    // nop

    // bne         $v0, $zero, L_80042C00
    if (ctx->r2 != 0) {
        // nor         $v0, $zero, $a0
        ctx->r2 = ~(0 | ctx->r4);
        goto L_80042C00;
    }
    // nor         $v0, $zero, $a0
    ctx->r2 = ~(0 | ctx->r4);
    // and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // bne         $a3, $zero, L_80042C00
    if (ctx->r7 != 0) {
        // sh          $v0, 0x4($v1)
        MEM_H(0X4, ctx->r3) = ctx->r2;
        goto L_80042C00;
    }
    // sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // addiu       $a0, $a1, 0x248
    ctx->r4 = ADD32(ctx->r5, 0X248);
    // jal         0x80055374
    // addiu       $a1, $a1, 0x278
    ctx->r5 = ADD32(ctx->r5, 0X278);
    sub_80055374(rdram, ctx);
    goto after_0;
    // addiu       $a1, $a1, 0x278
    ctx->r5 = ADD32(ctx->r5, 0X278);
    after_0:
L_80042C00:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
