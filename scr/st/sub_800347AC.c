#include "recomp.h"
#include "disable_warnings.h"

void sub_800347AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(0X4, ctx->r4);
    // lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(0X0, ctx->r4);
    // blez        $v1, L_800347E0
    if (SIGNED(ctx->r3) <= 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_800347E0;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_800347BC:
    // lw          $v0, 0xC($a3)
    ctx->r2 = MEM_W(0XC, ctx->r7);
    // nop

    // beq         $a1, $v0, L_800347DC
    if (ctx->r5 == ctx->r2) {
        // nop
    
        goto L_800347DC;
    }
    // nop

    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_800347BC
    if (ctx->r2 != 0) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_800347BC;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_800347DC:
    // lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(0X4, ctx->r4);
L_800347E0:
    // nop

    // beq         $a2, $v1, L_800347F0
    if (ctx->r6 == ctx->r3) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_800347F0;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
L_800347F0:
    // jr          $ra
    // nop

    return;
    // nop

;}
