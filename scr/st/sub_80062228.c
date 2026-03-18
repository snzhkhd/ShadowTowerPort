#include "recomp.h"
#include "disable_warnings.h"

void sub_80062228(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xF18
    ctx->r29 = ADD32(ctx->r29, -0XF18);
    // sw          $s5, 0xF0C($sp)
    MEM_W(0XF0C, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $s2, 0xF00($sp)
    MEM_W(0XF00, ctx->r29) = ctx->r18;
    // addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // addiu       $a3, $sp, 0x238
    ctx->r7 = ADD32(ctx->r29, 0X238);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x2A7C
    ctx->r6 = ADD32(ctx->r2, 0X2A7C);
    // sw          $s4, 0xF08($sp)
    MEM_W(0XF08, ctx->r29) = ctx->r20;
    // lui         $s4, 0x1F80
    ctx->r20 = S32(0X1F80 << 16);
    // andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // sw          $ra, 0xF10($sp)
    MEM_W(0XF10, ctx->r29) = ctx->r31;
    // sw          $s3, 0xF04($sp)
    MEM_W(0XF04, ctx->r29) = ctx->r19;
    // sw          $s1, 0xEFC($sp)
    MEM_W(0XEFC, ctx->r29) = ctx->r17;
    // beq         $v0, $zero, L_800622C0
    if (ctx->r2 == 0) {
        // sw          $s0, 0xEF8($sp)
        MEM_W(0XEF8, ctx->r29) = ctx->r16;
        goto L_800622C0;
    }
    // sw          $s0, 0xEF8($sp)
    MEM_W(0XEF8, ctx->r29) = ctx->r16;
    // addiu       $t0, $a2, 0xE0
    ctx->r8 = ADD32(ctx->r6, 0XE0);
L_8006226C:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lwl         $a0, 0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r6);
    // lwr         $a0, 0x8($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r6);
    // lwl         $a1, 0xF($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r6);
    // lwr         $a1, 0xC($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r6);
    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // swl         $v1, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r3);
    // swr         $v1, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r3);
    // swl         $a0, 0xB($a3)
    do_swl(rdram, 0XB, ctx->r7, ctx->r4);
    // swr         $a0, 0x8($a3)
    do_swr(rdram, 0X8, ctx->r7, ctx->r4);
    // swl         $a1, 0xF($a3)
    do_swl(rdram, 0XF, ctx->r7, ctx->r5);
    // swr         $a1, 0xC($a3)
    do_swr(rdram, 0XC, ctx->r7, ctx->r5);
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_8006226C
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8006226C;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // j           L_800622F4
    // addiu       $a3, $sp, 0x318
    ctx->r7 = ADD32(ctx->r29, 0X318);
    goto L_800622F4;
    // addiu       $a3, $sp, 0x318
    ctx->r7 = ADD32(ctx->r29, 0X318);
L_800622C0:
    // addiu       $t0, $a2, 0xE0
    ctx->r8 = ADD32(ctx->r6, 0XE0);
L_800622C4:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_800622C4
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_800622C4;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // addiu       $a3, $sp, 0x318
    ctx->r7 = ADD32(ctx->r29, 0X318);
L_800622F4:
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x2B5C
    ctx->r6 = ADD32(ctx->r2, 0X2B5C);
    // andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // beq         $v0, $zero, L_8006235C
    if (ctx->r2 == 0) {
        // addiu       $t0, $a2, 0x700
        ctx->r8 = ADD32(ctx->r6, 0X700);
        goto L_8006235C;
    }
    // addiu       $t0, $a2, 0x700
    ctx->r8 = ADD32(ctx->r6, 0X700);
L_80062308:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lwl         $a0, 0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r6);
    // lwr         $a0, 0x8($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r6);
    // lwl         $a1, 0xF($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r6);
    // lwr         $a1, 0xC($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r6);
    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // swl         $v1, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r3);
    // swr         $v1, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r3);
    // swl         $a0, 0xB($a3)
    do_swl(rdram, 0XB, ctx->r7, ctx->r4);
    // swr         $a0, 0x8($a3)
    do_swr(rdram, 0X8, ctx->r7, ctx->r4);
    // swl         $a1, 0xF($a3)
    do_swl(rdram, 0XF, ctx->r7, ctx->r5);
    // swr         $a1, 0xC($a3)
    do_swr(rdram, 0XC, ctx->r7, ctx->r5);
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_80062308
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_80062308;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // j           L_8006238C
    // addiu       $a3, $sp, 0xA18
    ctx->r7 = ADD32(ctx->r29, 0XA18);
    goto L_8006238C;
    // addiu       $a3, $sp, 0xA18
    ctx->r7 = ADD32(ctx->r29, 0XA18);
L_8006235C:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_8006235C
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8006235C;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // addiu       $a3, $sp, 0xA18
    ctx->r7 = ADD32(ctx->r29, 0XA18);
L_8006238C:
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x325C
    ctx->r6 = ADD32(ctx->r2, 0X325C);
    // andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // beq         $v0, $zero, L_800623F4
    if (ctx->r2 == 0) {
        // addiu       $t0, $a2, 0x40
        ctx->r8 = ADD32(ctx->r6, 0X40);
        goto L_800623F4;
    }
    // addiu       $t0, $a2, 0x40
    ctx->r8 = ADD32(ctx->r6, 0X40);
L_800623A0:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lwl         $a0, 0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r6);
    // lwr         $a0, 0x8($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r6);
    // lwl         $a1, 0xF($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r6);
    // lwr         $a1, 0xC($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r6);
    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // swl         $v1, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r3);
    // swr         $v1, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r3);
    // swl         $a0, 0xB($a3)
    do_swl(rdram, 0XB, ctx->r7, ctx->r4);
    // swr         $a0, 0x8($a3)
    do_swr(rdram, 0X8, ctx->r7, ctx->r4);
    // swl         $a1, 0xF($a3)
    do_swl(rdram, 0XF, ctx->r7, ctx->r5);
    // swr         $a1, 0xC($a3)
    do_swr(rdram, 0XC, ctx->r7, ctx->r5);
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_800623A0
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_800623A0;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // j           L_80062424
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    goto L_80062424;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
L_800623F4:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_800623F4
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_800623F4;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
L_80062424:
    // addiu       $a2, $v0, -0x7F24
    ctx->r6 = ADD32(ctx->r2, -0X7F24);
    // lb          $v1, 0x0($a2)
    ctx->r3 = MEM_BS(0X0, ctx->r6);
    // lb          $a0, 0x1($a2)
    ctx->r4 = MEM_BS(0X1, ctx->r6);
    // sb          $v1, 0xA58($sp)
    MEM_B(0XA58, ctx->r29) = ctx->r3;
    // sb          $a0, 0xA59($sp)
    MEM_B(0XA59, ctx->r29) = ctx->r4;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x32A0
    ctx->r6 = ADD32(ctx->r2, 0X32A0);
    // andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // beq         $v0, $zero, L_800624A4
    if (ctx->r2 == 0) {
        // addiu       $a3, $sp, 0xA60
        ctx->r7 = ADD32(ctx->r29, 0XA60);
        goto L_800624A4;
    }
    // addiu       $a3, $sp, 0xA60
    ctx->r7 = ADD32(ctx->r29, 0XA60);
    // addiu       $t0, $a2, 0x490
    ctx->r8 = ADD32(ctx->r6, 0X490);
L_80062450:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lwl         $a0, 0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r6);
    // lwr         $a0, 0x8($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r6);
    // lwl         $a1, 0xF($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r6);
    // lwr         $a1, 0xC($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r6);
    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // swl         $v1, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r3);
    // swr         $v1, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r3);
    // swl         $a0, 0xB($a3)
    do_swl(rdram, 0XB, ctx->r7, ctx->r4);
    // swr         $a0, 0x8($a3)
    do_swr(rdram, 0X8, ctx->r7, ctx->r4);
    // swl         $a1, 0xF($a3)
    do_swl(rdram, 0XF, ctx->r7, ctx->r5);
    // swr         $a1, 0xC($a3)
    do_swr(rdram, 0XC, ctx->r7, ctx->r5);
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_80062450
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_80062450;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // j           L_800624D4
    // nop

    goto L_800624D4;
    // nop

L_800624A4:
    // addiu       $t0, $a2, 0x490
    ctx->r8 = ADD32(ctx->r6, 0X490);
L_800624A8:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_800624A8
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_800624A8;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_800624D4:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // swl         $v1, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r3);
    // swr         $v1, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r3);
    // addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // lw          $v0, 0x1F4($s4)
    ctx->r2 = MEM_W(0X1F4, ctx->r20);
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lh          $a3, 0xE2($v0)
    ctx->r7 = MEM_HS(0XE2, ctx->r2);
    // addiu       $t2, $v1, -0x7F20
    ctx->r10 = ADD32(ctx->r3, -0X7F20);
    // lh          $v0, 0x0($t2)
    ctx->r2 = MEM_HS(0X0, ctx->r10);
    // lb          $t0, 0x2($t2)
    ctx->r8 = MEM_BS(0X2, ctx->r10);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // sb          $t0, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r8;
    // lhu         $v0, 0x1FE($s4)
    ctx->r2 = MEM_HU(0X1FE, ctx->r20);
    // addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
    // sb          $v1, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r3;
    // addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // sb          $v1, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r3;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // xor         $v0, $v0, $a3
    ctx->r2 = ctx->r2 ^ ctx->r7;
    // jal         0x80078AB4
    // sltiu       $s3, $v0, 0x1
    ctx->r19 = ctx->r2 < 0X1 ? 1 : 0;
    memset_recomp(rdram, ctx);
    goto after_0;
    // sltiu       $s3, $v0, 0x1
    ctx->r19 = ctx->r2 < 0X1 ? 1 : 0;
    after_0:
    // beq         $s3, $zero, L_80062564
    if (ctx->r19 == 0) {
        // nop
    
        goto L_80062564;
    }
    // nop

    // lhu         $v0, 0x204($s4)
    ctx->r2 = MEM_HU(0X204, ctx->r20);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // j           L_8006257C
    // sra         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2) >> 16;
    goto L_8006257C;
    // sra         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2) >> 16;
L_80062564:
    // lhu         $v0, 0x1FE($s4)
    ctx->r2 = MEM_HU(0X1FE, ctx->r20);
    // lw          $v1, 0x1F4($s4)
    ctx->r3 = MEM_W(0X1F4, ctx->r20);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $t2, 0x14($v1)
    ctx->r10 = MEM_W(0X14, ctx->r3);
L_8006257C:
    // lui         $v0, 0x9249
    ctx->r2 = S32(0X9249 << 16);
    // ori         $v0, $v0, 0x2493
    ctx->r2 = ctx->r2 | 0X2493;
    // mult        $t2, $v0
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $t1, $sp, 0xB8
    ctx->r9 = ADD32(ctx->r29, 0XB8);
    // sra         $v0, $t2, 31
    ctx->r2 = S32(ctx->r10) >> 31;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // mfhi        $t3
    ctx->r11 = hi;
    // addu        $v1, $t3, $t2
    ctx->r3 = ADD32(ctx->r11, ctx->r10);
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // subu        $v0, $t2, $v0
    ctx->r2 = SUB32(ctx->r10, ctx->r2);
    // sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2) << 5;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lwl         $a1, 0x22B($v1)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X22B, ctx->r3);
    // lwr         $a1, 0x228($v1)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X228, ctx->r3);
    // lwl         $a2, 0x22F($v1)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X22F, ctx->r3);
    // lwr         $a2, 0x22C($v1)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X22C, ctx->r3);
    // lwl         $a3, 0x233($v1)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0X233, ctx->r3);
    // lwr         $a3, 0x230($v1)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X230, ctx->r3);
    // lwl         $t0, 0x237($v1)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X237, ctx->r3);
    // lwr         $t0, 0x234($v1)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X234, ctx->r3);
    // swl         $a1, 0x9B($sp)
    do_swl(rdram, 0X9B, ctx->r29, ctx->r5);
    // swr         $a1, 0x98($sp)
    do_swr(rdram, 0X98, ctx->r29, ctx->r5);
    // swl         $a2, 0x9F($sp)
    do_swl(rdram, 0X9F, ctx->r29, ctx->r6);
    // swr         $a2, 0x9C($sp)
    do_swr(rdram, 0X9C, ctx->r29, ctx->r6);
    // swl         $a3, 0xA3($sp)
    do_swl(rdram, 0XA3, ctx->r29, ctx->r7);
    // swr         $a3, 0xA0($sp)
    do_swr(rdram, 0XA0, ctx->r29, ctx->r7);
    // swl         $t0, 0xA7($sp)
    do_swl(rdram, 0XA7, ctx->r29, ctx->r8);
    // swr         $t0, 0xA4($sp)
    do_swr(rdram, 0XA4, ctx->r29, ctx->r8);
    // lwl         $a1, 0x23B($v1)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X23B, ctx->r3);
    // lwr         $a1, 0x238($v1)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X238, ctx->r3);
    // lwl         $a2, 0x23F($v1)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0X23F, ctx->r3);
    // lwr         $a2, 0x23C($v1)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X23C, ctx->r3);
    // lwl         $a3, 0x243($v1)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0X243, ctx->r3);
    // lwr         $a3, 0x240($v1)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X240, ctx->r3);
    // lwl         $t0, 0x247($v1)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X247, ctx->r3);
    // lwr         $t0, 0x244($v1)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X244, ctx->r3);
    // swl         $a1, 0xAB($sp)
    do_swl(rdram, 0XAB, ctx->r29, ctx->r5);
    // swr         $a1, 0xA8($sp)
    do_swr(rdram, 0XA8, ctx->r29, ctx->r5);
    // swl         $a2, 0xAF($sp)
    do_swl(rdram, 0XAF, ctx->r29, ctx->r6);
    // swr         $a2, 0xAC($sp)
    do_swr(rdram, 0XAC, ctx->r29, ctx->r6);
    // swl         $a3, 0xB3($sp)
    do_swl(rdram, 0XB3, ctx->r29, ctx->r7);
    // swr         $a3, 0xB0($sp)
    do_swr(rdram, 0XB0, ctx->r29, ctx->r7);
    // swl         $t0, 0xB7($sp)
    do_swl(rdram, 0XB7, ctx->r29, ctx->r8);
    // swr         $t0, 0xB4($sp)
    do_swr(rdram, 0XB4, ctx->r29, ctx->r8);
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // j           L_8006269C
    // addiu       $a2, $v0, 0x308
    ctx->r6 = ADD32(ctx->r2, 0X308);
    goto L_8006269C;
    // addiu       $a2, $v0, 0x308
    ctx->r6 = ADD32(ctx->r2, 0X308);
L_80062648:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lwl         $a0, 0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r6);
    // lwr         $a0, 0x8($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r6);
    // lwl         $a1, 0xF($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r6);
    // lwr         $a1, 0xC($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r6);
    // swl         $v0, 0x3($t1)
    do_swl(rdram, 0X3, ctx->r9, ctx->r2);
    // swr         $v0, 0x0($t1)
    do_swr(rdram, 0X0, ctx->r9, ctx->r2);
    // swl         $v1, 0x7($t1)
    do_swl(rdram, 0X7, ctx->r9, ctx->r3);
    // swr         $v1, 0x4($t1)
    do_swr(rdram, 0X4, ctx->r9, ctx->r3);
    // swl         $a0, 0xB($t1)
    do_swl(rdram, 0XB, ctx->r9, ctx->r4);
    // swr         $a0, 0x8($t1)
    do_swr(rdram, 0X8, ctx->r9, ctx->r4);
    // swl         $a1, 0xF($t1)
    do_swl(rdram, 0XF, ctx->r9, ctx->r5);
    // swr         $a1, 0xC($t1)
    do_swr(rdram, 0XC, ctx->r9, ctx->r5);
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $a3, L_80062648
    if (ctx->r6 != ctx->r7) {
        // addiu       $t1, $t1, 0x10
        ctx->r9 = ADD32(ctx->r9, 0X10);
        goto L_80062648;
    }
    // addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // j           L_800626D0
    // lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    goto L_800626D0;
    // lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
L_8006269C:
    // addiu       $a3, $v0, 0x408
    ctx->r7 = ADD32(ctx->r2, 0X408);
L_800626A0:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // sw          $v1, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r3;
    // sw          $a0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r4;
    // sw          $a1, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $a3, L_800626A0
    if (ctx->r6 != ctx->r7) {
        // addiu       $t1, $t1, 0x10
        ctx->r9 = ADD32(ctx->r9, 0X10);
        goto L_800626A0;
    }
    // addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
L_800626D0:
    // ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // addiu       $a0, $sp, 0xA24
    ctx->r4 = ADD32(ctx->r29, 0XA24);
    // addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // mult        $t2, $v0
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $s1, $v0, 0x5920
    ctx->r17 = ADD32(ctx->r2, 0X5920);
    // addiu       $v1, $sp, 0xA60
    ctx->r3 = ADD32(ctx->r29, 0XA60);
    // lbu         $v0, 0x9($s1)
    ctx->r2 = MEM_BU(0X9, ctx->r17);
    // lbu         $a3, 0xA59($sp)
    ctx->r7 = MEM_BU(0XA59, ctx->r29);
    // sll         $a1, $v0, 3
    ctx->r5 = S32(ctx->r2) << 3;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // lbu         $v0, 0xA58($sp)
    ctx->r2 = MEM_BU(0XA58, ctx->r29);
    // addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    // sb          $v0, 0xA1E($sp)
    MEM_B(0XA1E, ctx->r29) = ctx->r2;
    // sb          $v0, 0xA20($sp)
    MEM_B(0XA20, ctx->r29) = ctx->r2;
    // sra         $v0, $t2, 31
    ctx->r2 = S32(ctx->r10) >> 31;
    // mfhi        $t3
    ctx->r11 = hi;
    // sra         $v1, $t3, 2
    ctx->r3 = S32(ctx->r11) >> 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // addu        $v0, $a3, $v1
    ctx->r2 = ADD32(ctx->r7, ctx->r3);
    // sb          $v0, 0xA1F($sp)
    MEM_B(0XA1F, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $v0, $t2, $v0
    ctx->r2 = SUB32(ctx->r10, ctx->r2);
    // addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // jal         0x80014D2C
    // sb          $a3, 0xA21($sp)
    MEM_B(0XA21, ctx->r29) = ctx->r7;
    sub_80014D2C(rdram, ctx);
    goto after_1;
    // sb          $a3, 0xA21($sp)
    MEM_B(0XA21, ctx->r29) = ctx->r7;
    after_1:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $t0, $v0, -0x70D8
    ctx->r8 = ADD32(ctx->r2, -0X70D8);
    // lhu         $t1, 0x8($t0)
    ctx->r9 = MEM_HU(0X8, ctx->r8);
    // nop

    // andi        $a1, $t1, 0xFFFF
    ctx->r5 = ctx->r9 & 0XFFFF;
    // sltiu       $v0, $a1, 0x3E8
    ctx->r2 = ctx->r5 < 0X3E8 ? 1 : 0;
    // bne         $v0, $zero, L_80062794
    if (ctx->r2 != 0) {
        // addiu       $s0, $sp, 0xA18
        ctx->r16 = ADD32(ctx->r29, 0XA18);
        goto L_80062794;
    }
    // addiu       $s0, $sp, 0xA18
    ctx->r16 = ADD32(ctx->r29, 0XA18);
    // lui         $v1, 0x1062
    ctx->r3 = S32(0X1062 << 16);
    // lhu         $v0, 0x8($t0)
    ctx->r2 = MEM_HU(0X8, ctx->r8);
    // ori         $v1, $v1, 0x4DD3
    ctx->r3 = ctx->r3 | 0X4DD3;
    // multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lbu         $v0, 0xA58($sp)
    ctx->r2 = MEM_BU(0XA58, ctx->r29);
    // nop

    // sb          $v0, 0xA46($sp)
    MEM_B(0XA46, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xA59($sp)
    ctx->r2 = MEM_BU(0XA59, ctx->r29);
    // mfhi        $t3
    ctx->r11 = hi;
    // srl         $v1, $t3, 6
    ctx->r3 = S32(U32(ctx->r11) >> 6);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0xA47($sp)
    MEM_B(0XA47, ctx->r29) = ctx->r2;
L_80062794:
    // sltiu       $v0, $a1, 0x64
    ctx->r2 = ctx->r5 < 0X64 ? 1 : 0;
    // bne         $v0, $zero, L_800627FC
    if (ctx->r2 != 0) {
        // sltiu       $v0, $a1, 0xA
        ctx->r2 = ctx->r5 < 0XA ? 1 : 0;
        goto L_800627FC;
    }
    // sltiu       $v0, $a1, 0xA
    ctx->r2 = ctx->r5 < 0XA ? 1 : 0;
    // lui         $v1, 0x51EB
    ctx->r3 = S32(0X51EB << 16);
    // lhu         $v0, 0x8($t0)
    ctx->r2 = MEM_HU(0X8, ctx->r8);
    // ori         $v1, $v1, 0x851F
    ctx->r3 = ctx->r3 | 0X851F;
    // multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // mfhi        $t3
    ctx->r11 = hi;
    // srl         $a0, $t3, 5
    ctx->r4 = S32(U32(ctx->r11) >> 5);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lbu         $v0, 0xA58($sp)
    ctx->r2 = MEM_BU(0XA58, ctx->r29);
    // nop

    // sb          $v0, 0xA48($sp)
    MEM_B(0XA48, ctx->r29) = ctx->r2;
    // mfhi        $t3
    ctx->r11 = hi;
    // srl         $v1, $t3, 3
    ctx->r3 = S32(U32(ctx->r11) >> 3);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lbu         $v1, 0xA59($sp)
    ctx->r3 = MEM_BU(0XA59, ctx->r29);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sb          $v1, 0xA49($sp)
    MEM_B(0XA49, ctx->r29) = ctx->r3;
    // sltiu       $v0, $a1, 0xA
    ctx->r2 = ctx->r5 < 0XA ? 1 : 0;
L_800627FC:
    // bne         $v0, $zero, L_80062854
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80062854;
    }
    // nop

    // lhu         $v0, 0x8($t0)
    ctx->r2 = MEM_HU(0X8, ctx->r8);
    // lui         $v1, 0xCCCC
    ctx->r3 = S32(0XCCCC << 16);
    // ori         $v1, $v1, 0xCCCD
    ctx->r3 = ctx->r3 | 0XCCCD;
    // multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t3
    ctx->r11 = hi;
    // srl         $a0, $t3, 3
    ctx->r4 = S32(U32(ctx->r11) >> 3);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lbu         $v0, 0xA58($sp)
    ctx->r2 = MEM_BU(0XA58, ctx->r29);
    // nop

    // sb          $v0, 0xA4A($sp)
    MEM_B(0XA4A, ctx->r29) = ctx->r2;
    // mfhi        $t3
    ctx->r11 = hi;
    // srl         $v1, $t3, 3
    ctx->r3 = S32(U32(ctx->r11) >> 3);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lbu         $v1, 0xA59($sp)
    ctx->r3 = MEM_BU(0XA59, ctx->r29);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sb          $v1, 0xA4B($sp)
    MEM_B(0XA4B, ctx->r29) = ctx->r3;
L_80062854:
    // lhu         $a0, 0x8($t0)
    ctx->r4 = MEM_HU(0X8, ctx->r8);
    // lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lbu         $v1, 0x9($s1)
    ctx->r3 = MEM_BU(0X9, ctx->r17);
    // lhu         $a1, 0x28($t0)
    ctx->r5 = MEM_HU(0X28, ctx->r8);
    // lbu         $v0, 0xA58($sp)
    ctx->r2 = MEM_BU(0XA58, ctx->r29);
    // addiu       $t0, $sp, 0xA58
    ctx->r8 = ADD32(ctx->r29, 0XA58);
    // sh          $t1, 0xA52($sp)
    MEM_H(0XA52, ctx->r29) = ctx->r9;
    // sb          $v1, 0xA51($sp)
    MEM_B(0XA51, ctx->r29) = ctx->r3;
    // sh          $a1, 0xA54($sp)
    MEM_H(0XA54, ctx->r29) = ctx->r5;
    // sb          $v0, 0xA4C($sp)
    MEM_B(0XA4C, ctx->r29) = ctx->r2;
    // mfhi        $t3
    ctx->r11 = hi;
    // srl         $v1, $t3, 3
    ctx->r3 = S32(U32(ctx->r11) >> 3);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lbu         $v1, 0xA59($sp)
    ctx->r3 = MEM_BU(0XA59, ctx->r29);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sb          $v1, 0xA4D($sp)
    MEM_B(0XA4D, ctx->r29) = ctx->r3;
L_800628B0:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_800628B0
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_800628B0;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_800628DC:
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
L_800628E0:
    // lhu         $a0, 0x1F8($s4)
    ctx->r4 = MEM_HU(0X1F8, ctx->r20);
    // addiu       $a3, $v0, -0x7F34
    ctx->r7 = ADD32(ctx->r2, -0X7F34);
    // lh          $v1, 0x0($a3)
    ctx->r3 = MEM_HS(0X0, ctx->r7);
    // lb          $a1, 0x2($a3)
    ctx->r5 = MEM_BS(0X2, ctx->r7);
    // sh          $v1, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r3;
    // sb          $a1, 0x1A($sp)
    MEM_B(0X1A, ctx->r29) = ctx->r5;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x80078AE4
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    itoa(rdram, ctx);
    goto after_2;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_2:
    // addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80078A64
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    strcat_recomp(rdram, ctx);
    goto after_3;
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_3:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // jal         0x80078A64
    // addiu       $a1, $a1, -0x7F2C
    ctx->r5 = ADD32(ctx->r5, -0X7F2C);
    strcat_recomp(rdram, ctx);
    goto after_4;
    // addiu       $a1, $a1, -0x7F2C
    ctx->r5 = ADD32(ctx->r5, -0X7F2C);
    after_4:
    // beq         $s3, $zero, L_800629F0
    if (ctx->r19 == 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_800629F0;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x80078A64
    // addiu       $a1, $a1, 0x2A68
    ctx->r5 = ADD32(ctx->r5, 0X2A68);
    strcat_recomp(rdram, ctx);
    goto after_5;
    // addiu       $a1, $a1, 0x2A68
    ctx->r5 = ADD32(ctx->r5, 0X2A68);
    after_5:
    // lui         $a0, 0x6666
    ctx->r4 = S32(0X6666 << 16);
    // lhu         $v1, 0x204($s4)
    ctx->r3 = MEM_HU(0X204, ctx->r20);
    // ori         $a0, $a0, 0x6667
    ctx->r4 = ctx->r4 | 0X6667;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) >> 16;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $a2, 0x204($s4)
    ctx->r6 = MEM_HU(0X204, ctx->r20);
    // mfhi        $t1
    ctx->r9 = hi;
    // sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) << 16;
    // sra         $a3, $a2, 16
    ctx->r7 = S32(ctx->r6) >> 16;
    // mult        $a3, $a0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // sb          $zero, 0x12($sp)
    MEM_B(0X12, ctx->r29) = 0;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // sra         $a2, $a2, 31
    ctx->r6 = S32(ctx->r6) >> 31;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // sra         $v0, $t1, 2
    ctx->r2 = S32(ctx->r9) >> 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    // mfhi        $t0
    ctx->r8 = hi;
    // sra         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8) >> 2;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
    // addiu       $a3, $a3, 0x30
    ctx->r7 = ADD32(ctx->r7, 0X30);
    // jal         0x80078A64
    // sb          $a3, 0x11($sp)
    MEM_B(0X11, ctx->r29) = ctx->r7;
    strcat_recomp(rdram, ctx);
    goto after_6;
    // sb          $a3, 0x11($sp)
    MEM_B(0X11, ctx->r29) = ctx->r7;
    after_6:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    // jal         0x80077EB4
    // ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    open(rdram, ctx);
    goto after_7;
    // ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    after_7:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_800629E0
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_800629E0;
    }
    // nop

    // beq         $s2, $zero, L_80062A2C
    if (ctx->r18 == 0) {
        // addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_80062A2C;
    }
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // j           L_800628E0
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    goto L_800628E0;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
L_800629E0:
    // jal         0x80077EF4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    close(rdram, ctx);
    goto after_8;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // j           L_80062A0C
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    goto L_80062A0C;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_800629F0:
    // lhu         $a1, 0x1FE($s4)
    ctx->r5 = MEM_HU(0X1FE, ctx->r20);
    // lw          $v0, 0x1F4($s4)
    ctx->r2 = MEM_W(0X1F4, ctx->r20);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 11
    ctx->r5 = S32(ctx->r5) >> 11;
    // jal         0x80078A64
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    strcat_recomp(rdram, ctx);
    goto after_9;
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    after_9:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_80062A0C:
    // jal         0x80077EB4
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    open(rdram, ctx);
    goto after_10;
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_80062A3C
    if (ctx->r16 != ctx->r2) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80062A3C;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // bne         $s2, $zero, L_800628DC
    if (ctx->r18 != 0) {
        // addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_800628DC;
    }
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80062A2C:
    // addiu       $v0, $zero, 0x163
    ctx->r2 = ADD32(0, 0X163);
    // sh          $v0, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r2;
    // j           L_80062B98
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80062B98;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80062A3C:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80077EC4
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    lseek(rdram, ctx);
    goto after_11;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_11:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $s3, $sp, 0x38
    ctx->r19 = ADD32(ctx->r29, 0X38);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // jal         0x80077EE4
    // addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    write(rdram, ctx);
    goto after_12;
    // addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_12:
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // bne         $v0, $s1, L_80062A78
    if (ctx->r2 != ctx->r17) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80062A78;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // beq         $s2, $zero, L_80062AD8
    if (ctx->r18 == 0) {
        // addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_80062AD8;
    }
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // j           L_80062AF8
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    goto L_80062AF8;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80062A78:
    // addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // jal         0x80061D34
    // addiu       $a3, $zero, 0x1D88
    ctx->r7 = ADD32(0, 0X1D88);
    sub_80061D34(rdram, ctx);
    goto after_13;
    // addiu       $a3, $zero, 0x1D88
    ctx->r7 = ADD32(0, 0X1D88);
    after_13:
    // bne         $v0, $s1, L_80062AA8
    if (ctx->r2 != ctx->r17) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80062AA8;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // bne         $s2, $zero, L_80062AF4
    if (ctx->r18 != 0) {
        // addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_80062AF4;
    }
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // j           L_80062AE0
    // nop

    goto L_80062AE0;
    // nop

L_80062AA8:
    // sb          $v0, 0x7A($sp)
    MEM_B(0X7A, ctx->r29) = ctx->r2;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80077EC4
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    lseek(rdram, ctx);
    goto after_15;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_15:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // jal         0x80077EE4
    // addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    write(rdram, ctx);
    goto after_16;
    // addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_16:
    // bne         $v0, $s1, L_80062B08
    if (ctx->r2 != ctx->r17) {
        // lui         $v1, 0x801B
        ctx->r3 = S32(0X801B << 16);
        goto L_80062B08;
    }
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // bne         $s2, $zero, L_80062AF0
    if (ctx->r18 != 0) {
        // addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_80062AF0;
    }
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80062AD8:
    // addiu       $v0, $zero, 0x163
    ctx->r2 = ADD32(0, 0X163);
    // sh          $v0, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r2;
L_80062AE0:
    // jal         0x80077EF4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    close(rdram, ctx);
    goto after_17;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_17:
    // j           L_80062B98
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80062B98;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80062AF0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80062AF4:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80062AF8:
    // jal         0x80077EC4
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    lseek(rdram, ctx);
    goto after_18;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_18:
    // j           L_80062A3C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    goto L_80062A3C;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80062B08:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v1, 0x5924($v1)
    ctx->r3 = MEM_BU(0X5924, ctx->r3);
    // lw          $a1, 0x24C($v0)
    ctx->r5 = MEM_W(0X24C, ctx->r2);
    // sb          $v1, 0x22C($v0)
    MEM_B(0X22C, ctx->r2) = ctx->r3;
    // lw          $v1, 0x248($v0)
    ctx->r3 = MEM_W(0X248, ctx->r2);
    // sra         $a1, $a1, 12
    ctx->r5 = S32(ctx->r5) >> 12;
    // sb          $a1, 0x22E($v0)
    MEM_B(0X22E, ctx->r2) = ctx->r5;
    // lhu         $a1, 0x27A($v0)
    ctx->r5 = MEM_HU(0X27A, ctx->r2);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // sb          $v1, 0x22D($v0)
    MEM_B(0X22D, ctx->r2) = ctx->r3;
    // lw          $v1, 0x250($v0)
    ctx->r3 = MEM_W(0X250, ctx->r2);
    // addiu       $a1, $a1, 0x800
    ctx->r5 = ADD32(ctx->r5, 0X800);
    // sh          $a1, 0x236($v0)
    MEM_H(0X236, ctx->r2) = ctx->r5;
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // sb          $v1, 0x22F($v0)
    MEM_B(0X22F, ctx->r2) = ctx->r3;
    // lbu         $v1, 0x22D($v0)
    ctx->r3 = MEM_BU(0X22D, ctx->r2);
    // lhu         $a1, 0x248($v0)
    ctx->r5 = MEM_HU(0X248, ctx->r2);
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // lbu         $v1, 0x22E($v0)
    ctx->r3 = MEM_BU(0X22E, ctx->r2);
    // sh          $a1, 0x230($v0)
    MEM_H(0X230, ctx->r2) = ctx->r5;
    // lhu         $a1, 0x24C($v0)
    ctx->r5 = MEM_HU(0X24C, ctx->r2);
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // lbu         $v1, 0x22F($v0)
    ctx->r3 = MEM_BU(0X22F, ctx->r2);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // sh          $a1, 0x232($v0)
    MEM_H(0X232, ctx->r2) = ctx->r5;
    // lhu         $a1, 0x250($v0)
    ctx->r5 = MEM_HU(0X250, ctx->r2);
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // jal         0x80077EF4
    // sh          $a1, 0x234($v0)
    MEM_H(0X234, ctx->r2) = ctx->r5;
    close(rdram, ctx);
    goto after_19;
    // sh          $a1, 0x234($v0)
    MEM_H(0X234, ctx->r2) = ctx->r5;
    after_19:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_20;
    // nop

    after_20:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80062B98:
    // lw          $ra, 0xF10($sp)
    ctx->r31 = MEM_W(0XF10, ctx->r29);
    // lw          $s5, 0xF0C($sp)
    ctx->r21 = MEM_W(0XF0C, ctx->r29);
    // lw          $s4, 0xF08($sp)
    ctx->r20 = MEM_W(0XF08, ctx->r29);
    // lw          $s3, 0xF04($sp)
    ctx->r19 = MEM_W(0XF04, ctx->r29);
    // lw          $s2, 0xF00($sp)
    ctx->r18 = MEM_W(0XF00, ctx->r29);
    // lw          $s1, 0xEFC($sp)
    ctx->r17 = MEM_W(0XEFC, ctx->r29);
    // lw          $s0, 0xEF8($sp)
    ctx->r16 = MEM_W(0XEF8, ctx->r29);
    // addiu       $sp, $sp, 0xF18
    ctx->r29 = ADD32(ctx->r29, 0XF18);
    // jr          $ra
    // nop

    return;
    // nop

;}
