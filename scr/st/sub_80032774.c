#include "recomp.h"
#include "disable_warnings.h"

void sub_80032774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // andi        $v0, $a0, 0x10
    ctx->r2 = ctx->r4 & 0X10;
    // bne         $v0, $zero, L_800327B8
    if (ctx->r2 != 0) {
        // addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
        goto L_800327B8;
    }
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // andi        $v0, $a0, 0x20
    ctx->r2 = ctx->r4 & 0X20;
    // beq         $v0, $zero, L_8003279C
    if (ctx->r2 == 0) {
        // andi        $v0, $a0, 0x40
        ctx->r2 = ctx->r4 & 0X40;
        goto L_8003279C;
    }
    // andi        $v0, $a0, 0x40
    ctx->r2 = ctx->r4 & 0X40;
    // j           L_800327B8
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    goto L_800327B8;
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8003279C:
    // beq         $v0, $zero, L_800327AC
    if (ctx->r2 == 0) {
        // andi        $v0, $a0, 0x80
        ctx->r2 = ctx->r4 & 0X80;
        goto L_800327AC;
    }
    // andi        $v0, $a0, 0x80
    ctx->r2 = ctx->r4 & 0X80;
    // j           L_800327B8
    // addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    goto L_800327B8;
    // addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800327AC:
    // beq         $v0, $zero, L_800327BC
    if (ctx->r2 == 0) {
        // andi        $v0, $a2, 0x1
        ctx->r2 = ctx->r6 & 0X1;
        goto L_800327BC;
    }
    // andi        $v0, $a2, 0x1
    ctx->r2 = ctx->r6 & 0X1;
    // addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_800327B8:
    // andi        $v0, $a2, 0x1
    ctx->r2 = ctx->r6 & 0X1;
L_800327BC:
    // beq         $v0, $zero, L_800327CC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800327CC;
    }
    // nop

    // j           L_800327F0
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    goto L_800327F0;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800327CC:
    // andi        $v0, $a2, 0x2
    ctx->r2 = ctx->r6 & 0X2;
    // beq         $v0, $zero, L_800327E0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800327E0;
    }
    // nop

    // j           L_800327F0
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    goto L_800327F0;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800327E0:
    // andi        $v0, $a2, 0x4
    ctx->r2 = ctx->r6 & 0X4;
    // beq         $v0, $zero, L_800327F0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800327F0;
    }
    // nop

    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_800327F0:
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jr          $ra
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    return;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
;}
