#include "recomp.h"
#include "disable_warnings.h"

void sub_8004FB88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v1, 0x5($a0)
    ctx->r3 = MEM_BU(0X5, ctx->r4);
    // nop

    // bltz        $v1, L_8004FC00
    if (SIGNED(ctx->r3) < 0) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_8004FC00;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8004FBB0
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, 0x35
        ctx->r2 = SIGNED(ctx->r3) < 0X35 ? 1 : 0;
        goto L_8004FBB0;
    }
    // slti        $v0, $v1, 0x35
    ctx->r2 = SIGNED(ctx->r3) < 0X35 ? 1 : 0;
    // beq         $v0, $zero, L_8004FC00
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x32
        ctx->r2 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
        goto L_8004FC00;
    }
    // slti        $v0, $v1, 0x32
    ctx->r2 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
    // bne         $v0, $zero, L_8004FC04
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004FC04;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004FBB0:
    // lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(0XC, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8004FC04
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004FC04;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lbu         $v0, 0x4F($a0)
    ctx->r2 = MEM_BU(0X4F, ctx->r4);
    // nop

    // sltiu       $v0, $v0, 0xFE
    ctx->r2 = ctx->r2 < 0XFE ? 1 : 0;
    // bne         $v0, $zero, L_8004FBDC
    if (ctx->r2 != 0) {
        // addiu       $v0, $a1, -0x110
        ctx->r2 = ADD32(ctx->r5, -0X110);
        goto L_8004FBDC;
    }
    // addiu       $v0, $a1, -0x110
    ctx->r2 = ADD32(ctx->r5, -0X110);
    // j           L_8004FC04
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    goto L_8004FC04;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8004FBDC:
    // lbu         $v1, 0x4F($a0)
    ctx->r3 = MEM_BU(0X4F, ctx->r4);
    // nop

    // bne         $v1, $v0, L_8004FBF8
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8004FBF8;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x4F($a0)
    MEM_B(0X4F, ctx->r4) = ctx->r2;
    // j           L_8004FC04
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_8004FC04;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004FBF8:
    // j           L_8004FC04
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    goto L_8004FC04;
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8004FC00:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004FC04:
    // jr          $ra
    // nop

    return;
    // nop

;}
