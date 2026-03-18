#include "recomp.h"
#include "disable_warnings.h"

void sub_800346DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(0X34, ctx->r4);
    // lw          $a3, 0x28($a0)
    ctx->r7 = MEM_W(0X28, ctx->r4);
    // lw          $a2, 0x2C($a0)
    ctx->r6 = MEM_W(0X2C, ctx->r4);
    // lw          $t0, 0x30($a0)
    ctx->r8 = MEM_W(0X30, ctx->r4);
    // sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(0X34, ctx->r4);
    // nop

    // sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
    // lw          $v1, 0x34($a0)
    ctx->r3 = MEM_W(0X34, ctx->r4);
    // lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(0X28, ctx->r4);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // blez        $a1, L_80034758
    if (SIGNED(ctx->r5) <= 0) {
        // sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80034758;
    }
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // addiu       $v1, $a3, 0xB
    ctx->r3 = ADD32(ctx->r7, 0XB);
L_80034720:
    // sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // sw          $t2, 0x1($v1)
    MEM_W(0X1, ctx->r3) = ctx->r10;
    // sw          $a2, -0x7($v1)
    MEM_W(-0X7, ctx->r3) = ctx->r6;
    // sw          $t0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r8;
    // sh          $t1, -0x3($v1)
    MEM_H(-0X3, ctx->r3) = ctx->r9;
    // sb          $zero, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = 0;
    // sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // addiu       $a2, $a2, 0x50
    ctx->r6 = ADD32(ctx->r6, 0X50);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_80034720
    if (ctx->r2 != 0) {
        // addiu       $t0, $t0, 0x28
        ctx->r8 = ADD32(ctx->r8, 0X28);
        goto L_80034720;
    }
    // addiu       $t0, $t0, 0x28
    ctx->r8 = ADD32(ctx->r8, 0X28);
L_80034758:
    // jr          $ra
    // nop

    return;
    // nop

;}
