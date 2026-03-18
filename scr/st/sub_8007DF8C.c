#include "recomp.h"
#include "disable_warnings.h"

void sub_8007DF8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v0, 0xE9($a0)
    ctx->r2 = MEM_BU(0XE9, ctx->r4);
    // nop

    // beq         $v0, $zero, L_8007E044
    if (ctx->r2 == 0) {
        // addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
        goto L_8007E044;
    }
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
L_8007DFA4:
    // lw          $a1, 0x20($a0)
    ctx->r5 = MEM_W(0X20, ctx->r4);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_8007DFB0:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // nop

    // bne         $v0, $t0, L_8007DFC4
    if (ctx->r2 != ctx->r8) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_8007DFC4;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_8007DFC4:
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bgez        $v1, L_8007DFB0
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8007DFB0;
    }
    // nop

    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // addu        $v0, $t2, $v0
    ctx->r2 = ADD32(ctx->r10, ctx->r2);
    // lbu         $t1, 0x2($v0)
    ctx->r9 = MEM_BU(0X2, ctx->r2);
    // lw          $a1, 0x20($a0)
    ctx->r5 = MEM_W(0X20, ctx->r4);
    // bne         $t1, $zero, L_8007DFF0
    if (ctx->r9 != 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_8007DFF0;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8007DFF0:
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
L_8007DFF4:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // nop

    // bne         $v0, $t0, L_8007E020
    if (ctx->r2 != ctx->r8) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_8007E020;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a3, $t1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // beq         $v0, $zero, L_8007E01C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007E01C;
    }
    // nop

    // sb          $t3, 0x5D($a2)
    MEM_B(0X5D, ctx->r6) = ctx->r11;
    // j           L_8007E020
    // addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    goto L_8007E020;
    // addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
L_8007E01C:
    // sb          $t0, 0x5D($a2)
    MEM_B(0X5D, ctx->r6) = ctx->r8;
L_8007E020:
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // slti        $v0, $v1, 0x6
    ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_8007DFF4
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8007DFF4;
    }
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // lbu         $v0, 0xE9($a0)
    ctx->r2 = MEM_BU(0XE9, ctx->r4);
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8007DFA4
    if (ctx->r2 != 0) {
        // addiu       $t2, $t2, 0x5
        ctx->r10 = ADD32(ctx->r10, 0X5);
        goto L_8007DFA4;
    }
    // addiu       $t2, $t2, 0x5
    ctx->r10 = ADD32(ctx->r10, 0X5);
L_8007E044:
    // addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // sb          $v0, 0x46($a0)
    MEM_B(0X46, ctx->r4) = ctx->r2;
    // jr          $ra
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
