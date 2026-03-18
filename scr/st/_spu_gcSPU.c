#include "recomp.h"
#include "disable_warnings.h"

void _spu_gcSPU(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE24($v0)
    ctx->r2 = MEM_W(0XE24, ctx->r2);
    // nop

    // bltz        $v0, L_80073740
    if (SIGNED(ctx->r2) < 0) {
        // addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
        goto L_80073740;
    }
    // addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // lui         $t2, 0x2FFF
    ctx->r10 = S32(0X2FFF << 16);
    // ori         $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 | 0XFFFF;
    // lui         $t3, 0xFFF
    ctx->r11 = S32(0XFFF << 16);
    // ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // lw          $t0, 0xE28($t0)
    ctx->r8 = MEM_W(0XE28, ctx->r8);
    // addu        $t5, $v0, $zero
    ctx->r13 = ADD32(ctx->r2, 0);
    // addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
L_8007369C:
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // nop

    // and         $v0, $v0, $t4
    ctx->r2 = ctx->r2 & ctx->r12;
    // beq         $v0, $zero, L_80073720
    if (ctx->r2 == 0) {
        // addiu       $a2, $t1, 0x1
        ctx->r6 = ADD32(ctx->r9, 0X1);
        goto L_80073720;
    }
    // addiu       $a2, $t1, 0x1
    ctx->r6 = ADD32(ctx->r9, 0X1);
    // sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6) << 3;
    // addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
L_800736B8:
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // bne         $v0, $t2, L_800736D0
    if (ctx->r2 != ctx->r10) {
        // addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_800736D0;
    }
    // addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // j           L_800736B8
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    goto L_800736B8;
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800736D0:
    // sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6) << 3;
    // addu        $a1, $v0, $t0
    ctx->r5 = ADD32(ctx->r2, ctx->r8);
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // nop

    // and         $v0, $v1, $t4
    ctx->r2 = ctx->r3 & ctx->r12;
    // beq         $v0, $zero, L_80073720
    if (ctx->r2 == 0) {
        // and         $v0, $v1, $t3
        ctx->r2 = ctx->r3 & ctx->r11;
        goto L_80073720;
    }
    // and         $v0, $v1, $t3
    ctx->r2 = ctx->r3 & ctx->r11;
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(0X4, ctx->r7);
    // and         $v1, $v1, $t3
    ctx->r3 = ctx->r3 & ctx->r11;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // bne         $v0, $v1, L_80073720
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80073720;
    }
    // nop

    // sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(0X4, ctx->r7);
    // lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(0X4, ctx->r5);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_80073728
    // sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    goto L_80073728;
    // sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
L_80073720:
    // addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_80073728:
    // slt         $v0, $t5, $t1
    ctx->r2 = SIGNED(ctx->r13) < SIGNED(ctx->r9) ? 1 : 0;
    // beq         $v0, $zero, L_8007369C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007369C;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE24($v0)
    ctx->r2 = MEM_W(0XE24, ctx->r2);
    // nop

L_80073740:
    // bltz        $v0, L_80073784
    if (SIGNED(ctx->r2) < 0) {
        // addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
        goto L_80073784;
    }
    // addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // lui         $a1, 0x2FFF
    ctx->r5 = S32(0X2FFF << 16);
    // ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xE28($v1)
    ctx->r3 = MEM_W(0XE28, ctx->r3);
    // nop

L_80073760:
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // nop

    // bne         $v0, $zero, L_80073774
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80073774;
    }
    // nop

    // sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
L_80073774:
    // addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // slt         $v0, $a0, $t1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // beq         $v0, $zero, L_80073760
    if (ctx->r2 == 0) {
        // addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_80073760;
    }
    // addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80073784:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xE24($v1)
    ctx->r3 = MEM_W(0XE24, ctx->r3);
    // nop

    // bltz        $v1, L_80073850
    if (SIGNED(ctx->r3) < 0) {
        // addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
        goto L_80073850;
    }
    // addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // lui         $t6, 0x4000
    ctx->r14 = S32(0X4000 << 16);
    // lui         $t4, 0xFFF
    ctx->r12 = S32(0XFFF << 16);
    // lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // lw          $t5, 0xE28($t5)
    ctx->r13 = MEM_W(0XE28, ctx->r13);
    // ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // addu        $t2, $t5, $zero
    ctx->r10 = ADD32(ctx->r13, 0);
L_800737B0:
    // lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(0X0, ctx->r10);
    // nop

    // and         $v0, $v0, $t6
    ctx->r2 = ctx->r2 & ctx->r14;
    // bne         $v0, $zero, L_80073850
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80073850;
    }
    // nop

    // addiu       $a2, $t1, 0x1
    ctx->r6 = ADD32(ctx->r9, 0X1);
    // slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // bne         $v0, $zero, L_80073838
    if (ctx->r2 != 0) {
        // sll         $v0, $a2, 3
        ctx->r2 = S32(ctx->r6) << 3;
        goto L_80073838;
    }
    // sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6) << 3;
    // addu        $t0, $t2, $zero
    ctx->r8 = ADD32(ctx->r10, 0);
    // lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // lw          $t3, 0xE24($t3)
    ctx->r11 = MEM_W(0XE24, ctx->r11);
    // addu        $a0, $v0, $t5
    ctx->r4 = ADD32(ctx->r2, ctx->r13);
L_800737E4:
    // lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(0X0, ctx->r4);
    // nop

    // and         $v0, $a1, $t6
    ctx->r2 = ctx->r5 & ctx->r14;
    // bne         $v0, $zero, L_80073838
    if (ctx->r2 != 0) {
        // and         $v0, $a1, $t4
        ctx->r2 = ctx->r5 & ctx->r12;
        goto L_80073838;
    }
    // and         $v0, $a1, $t4
    ctx->r2 = ctx->r5 & ctx->r12;
    // lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(0X0, ctx->r8);
    // nop

    // and         $v1, $a3, $t4
    ctx->r3 = ctx->r7 & ctx->r12;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_80073828
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80073828;
    }
    // nop

    // sw          $a1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r5;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(0X4, ctx->r8);
    // sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
L_80073828:
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slt         $v0, $t3, $a2
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    // beq         $v0, $zero, L_800737E4
    if (ctx->r2 == 0) {
        // addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_800737E4;
    }
    // addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80073838:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xE24($v1)
    ctx->r3 = MEM_W(0XE24, ctx->r3);
    // addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // slt         $v0, $v1, $t1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // beq         $v0, $zero, L_800737B0
    if (ctx->r2 == 0) {
        // addiu       $t2, $t2, 0x8
        ctx->r10 = ADD32(ctx->r10, 0X8);
        goto L_800737B0;
    }
    // addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
L_80073850:
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0xE24($a1)
    ctx->r5 = MEM_W(0XE24, ctx->r5);
    // nop

    // bltz        $a1, L_800738D4
    if (SIGNED(ctx->r5) < 0) {
        // addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
        goto L_800738D4;
    }
    // addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // lui         $t0, 0x4000
    ctx->r8 = S32(0X4000 << 16);
    // lui         $a3, 0x2FFF
    ctx->r7 = S32(0X2FFF << 16);
    // lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // lw          $a2, 0xE28($a2)
    ctx->r6 = MEM_W(0XE28, ctx->r6);
    // ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
L_8007387C:
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // and         $v0, $v1, $t0
    ctx->r2 = ctx->r3 & ctx->r8;
    // bne         $v0, $zero, L_800738D4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800738D4;
    }
    // nop

    // bne         $v1, $a3, L_800738BC
    if (ctx->r3 != ctx->r7) {
        // sll         $v0, $a1, 3
        ctx->r2 = S32(ctx->r5) << 3;
        goto L_800738BC;
    }
    // sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5) << 3;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // nop

    // sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $t1, 0xE24($at)
    MEM_W(0XE24, ctx->r1) = ctx->r9;
    // j           L_800738D4
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    goto L_800738D4;
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_800738BC:
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0xE24($a1)
    ctx->r5 = MEM_W(0XE24, ctx->r5);
    // addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // slt         $v0, $a1, $t1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // beq         $v0, $zero, L_8007387C
    if (ctx->r2 == 0) {
        // addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_8007387C;
    }
    // addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800738D4:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE24($v0)
    ctx->r2 = MEM_W(0XE24, ctx->r2);
    // nop

    // addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // bltz        $t1, L_8007395C
    if (SIGNED(ctx->r9) < 0) {
        // sll         $v0, $t1, 3
        ctx->r2 = S32(ctx->r9) << 3;
        goto L_8007395C;
    }
    // sll         $v0, $t1, 3
    ctx->r2 = S32(ctx->r9) << 3;
    // lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // lui         $a2, 0xFFF
    ctx->r6 = S32(0XFFF << 16);
    // ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0xE28($a1)
    ctx->r5 = MEM_W(0XE28, ctx->r5);
    // nop

    // addu        $a0, $v0, $a1
    ctx->r4 = ADD32(ctx->r2, ctx->r5);
L_8007390C:
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // and         $v0, $v1, $t0
    ctx->r2 = ctx->r3 & ctx->r8;
    // beq         $v0, $zero, L_8007395C
    if (ctx->r2 == 0) {
        // and         $v0, $v1, $a2
        ctx->r2 = ctx->r3 & ctx->r6;
        goto L_8007395C;
    }
    // and         $v0, $v1, $a2
    ctx->r2 = ctx->r3 & ctx->r6;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xE24($v1)
    ctx->r3 = MEM_W(0XE24, ctx->r3);
    // or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $t1, 0xE24($at)
    MEM_W(0XE24, ctx->r1) = ctx->r9;
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(0X4, ctx->r3);
    // addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // bgez        $t1, L_8007390C
    if (SIGNED(ctx->r9) >= 0) {
        // addiu       $a0, $a0, -0x8
        ctx->r4 = ADD32(ctx->r4, -0X8);
        goto L_8007390C;
    }
    // addiu       $a0, $a0, -0x8
    ctx->r4 = ADD32(ctx->r4, -0X8);
L_8007395C:
    // jr          $ra
    // nop

    return;
    // nop

;}
