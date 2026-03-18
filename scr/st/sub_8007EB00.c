#include "recomp.h"
#include "disable_warnings.h"

void sub_8007EB00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v0, 0x45($a0)
    ctx->r2 = MEM_BU(0X45, ctx->r4);
    // lbu         $a1, 0x36($a0)
    ctx->r5 = MEM_BU(0X36, ctx->r4);
    // nop

    // beq         $a1, $zero, L_8007EB28
    if (ctx->r5 == 0) {
        // addiu       $v1, $v0, -0x3
        ctx->r3 = ADD32(ctx->r2, -0X3);
        goto L_8007EB28;
    }
    // addiu       $v1, $v0, -0x3
    ctx->r3 = ADD32(ctx->r2, -0X3);
    // addiu       $v0, $zero, 0x4D
    ctx->r2 = ADD32(0, 0X4D);
    // beq         $a1, $v0, L_8007EB70
    if (ctx->r5 == ctx->r2) {
        // nop
    
        goto L_8007EB70;
    }
    // nop

    // j           L_8007EB90
    // nop

    goto L_8007EB90;
    // nop

L_8007EB28:
    // slti        $v0, $v1, 0x6
    ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_8007EB44
    if (ctx->r2 == 0) {
        // addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
        goto L_8007EB44;
    }
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // lbu         $v0, 0x57($v0)
    ctx->r2 = MEM_BU(0X57, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8007EBB4
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007EBB4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007EB44:
    // lbu         $v0, 0x34($a0)
    ctx->r2 = MEM_BU(0X34, ctx->r4);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8007EBB4
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007EBB4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(0X28, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8007EB64:
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // j           L_8007EBB4
    // nop

    goto L_8007EBB4;
    // nop

L_8007EB70:
    // lbu         $v0, 0x35($a0)
    ctx->r2 = MEM_BU(0X35, ctx->r4);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8007EBB4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8007EBB4;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(0X2C, ctx->r4);
    // j           L_8007EB64
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    goto L_8007EB64;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8007EB90:
    // lbu         $v0, 0x35($a0)
    ctx->r2 = MEM_BU(0X35, ctx->r4);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8007EBB4
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007EBB4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(0X2C, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
L_8007EBB4:
    // jr          $ra
    // nop

    return;
    // nop

;}
