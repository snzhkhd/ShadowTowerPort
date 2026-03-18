#include "recomp.h"
#include "disable_warnings.h"

void sub_80054000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_80054014:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80068CE0
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    CdControl(rdram, ctx);
    goto after_0;
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_0:
    // beq         $v0, $zero, L_80054014
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
        goto L_80054014;
    }
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v1, 0x10($sp)
    ctx->r3 = MEM_BU(0X10, ctx->r29);
    // lbu         $a0, 0x11($sp)
    ctx->r4 = MEM_BU(0X11, ctx->r29);
    // lbu         $a1, 0x12($sp)
    ctx->r5 = MEM_BU(0X12, ctx->r29);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // sb          $v1, 0x1DC($v0)
    MEM_B(0X1DC, ctx->r2) = ctx->r3;
    // sb          $a0, 0x1DD($v0)
    MEM_B(0X1DD, ctx->r2) = ctx->r4;
    // andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // sb          $a1, 0x1DE($v0)
    MEM_B(0X1DE, ctx->r2) = ctx->r5;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $a0, $v0, L_80054078
    if (ctx->r4 == ctx->r2) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_80054078;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bne         $a0, $v0, L_80054078
    if (ctx->r4 != ctx->r2) {
        // lui         $s0, 0x801A
        ctx->r16 = S32(0X801A << 16);
        goto L_80054078;
    }
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
L_80054064:
    // addiu       $a1, $s0, -0x6F00
    ctx->r5 = ADD32(ctx->r16, -0X6F00);
    // jal         0x80068F50
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControlB(rdram, ctx);
    goto after_1;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // beq         $v0, $zero, L_80054064
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x1B
        ctx->r4 = ADD32(0, 0X1B);
        goto L_80054064;
    }
    // addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
L_80054078:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
