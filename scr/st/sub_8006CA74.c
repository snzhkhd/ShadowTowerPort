#include "recomp.h"
#include "disable_warnings.h"

void sub_8006CA74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $a2, 0x1F80
    ctx->r6 = S32(0X1F80 << 16);
    // ori         $a2, $a2, 0x1C00
    ctx->r6 = ctx->r6 | 0X1C00;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // addiu       $a3, $a3, 0xE6C
    ctx->r7 = ADD32(ctx->r7, 0XE6C);
L_8006CA90:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
L_8006CA98:
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // slti        $v0, $a1, 0x8
    ctx->r2 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_8006CA98
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_8006CA98;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v0, $a0, 0x18
    ctx->r2 = SIGNED(ctx->r4) < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_8006CA90
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006CA90;
    }
    // nop

    // lui         $a2, 0x1F80
    ctx->r6 = S32(0X1F80 << 16);
    // ori         $a2, $a2, 0x1D80
    ctx->r6 = ctx->r6 | 0X1D80;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0xE7C
    ctx->r3 = ADD32(ctx->r3, 0XE7C);
L_8006CAD8:
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // slti        $v0, $a0, 0x10
    ctx->r2 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_8006CAD8
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_8006CAD8;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // jal         0x80071B14
    // addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    _SsVmInit(rdram, ctx);
    goto after_0;
    // addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_0:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addiu       $v1, $v1, -0x7920
    ctx->r3 = ADD32(ctx->r3, -0X7920);
L_8006CB08:
    // addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // addiu       $v0, $v1, 0x3C
    ctx->r2 = ADD32(ctx->r3, 0X3C);
L_8006CB10:
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // bgez        $a0, L_8006CB10
    if (SIGNED(ctx->r4) >= 0) {
        // addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
        goto L_8006CB10;
    }
    // addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x20
    ctx->r2 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // bne         $v0, $zero, L_8006CB08
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x40
        ctx->r3 = ADD32(ctx->r3, 0X40);
        goto L_8006CB08;
    }
    // addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v0, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = ctx->r2;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $zero, -0x79A8($at)
    MEM_W(-0X79A8, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $zero, -0x79AC($at)
    MEM_W(-0X79AC, ctx->r1) = 0;
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
