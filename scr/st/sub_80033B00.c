#include "recomp.h"
#include "disable_warnings.h"

void sub_80033B00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // addu        $t2, $a1, $zero
    ctx->r10 = ADD32(ctx->r5, 0);
    // addu        $t3, $a2, $zero
    ctx->r11 = ADD32(ctx->r6, 0);
    // beq         $a3, $zero, L_80033B74
    if (ctx->r7 == 0) {
        // addiu       $t0, $a3, -0x1
        ctx->r8 = ADD32(ctx->r7, -0X1);
        goto L_80033B74;
    }
    // addiu       $t0, $a3, -0x1
    ctx->r8 = ADD32(ctx->r7, -0X1);
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80033B24:
    // lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(0X0, ctx->r10);
    // addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // lhu         $v1, 0x0($t3)
    ctx->r3 = MEM_HU(0X0, ctx->r11);
    // addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    // lhu         $v0, -0x2($a1)
    ctx->r2 = MEM_HU(-0X2, ctx->r5);
    // lhu         $v1, -0x2($a2)
    ctx->r3 = MEM_HU(-0X2, ctx->r6);
    // addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(0X0, ctx->r6);
    // addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // bne         $t0, $a3, L_80033B24
    if (ctx->r8 != ctx->r7) {
        // addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_80033B24;
    }
    // addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80033B74:
    // jr          $ra
    // nop

    return;
    // nop

;}
