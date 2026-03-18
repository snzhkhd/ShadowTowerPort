#include "recomp.h"
#include "disable_warnings.h"

void sub_80032058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $t1, $v0, -0x874
    ctx->r9 = ADD32(ctx->r2, -0X874);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $t0, $v0, -0x48C4
    ctx->r8 = ADD32(ctx->r2, -0X48C4);
    // addiu       $t2, $zero, 0x3F
    ctx->r10 = ADD32(0, 0X3F);
    // addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // addiu       $a3, $t0, 0x6A
    ctx->r7 = ADD32(ctx->r8, 0X6A);
    // addiu       $a2, $t1, 0x2E
    ctx->r6 = ADD32(ctx->r9, 0X2E);
L_80032078:
    // lwl         $v0, -0x17($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, -0X17, ctx->r6);
    // lwr         $v0, -0x1A($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, -0X1A, ctx->r6);
    // lwl         $v1, -0x13($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, -0X13, ctx->r6);
    // lwr         $v1, -0x16($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, -0X16, ctx->r6);
    // lwl         $a0, -0xF($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, -0XF, ctx->r6);
    // lwr         $a0, -0x12($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, -0X12, ctx->r6);
    // lwl         $a1, -0xB($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, -0XB, ctx->r6);
    // lwr         $a1, -0xE($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, -0XE, ctx->r6);
    // swl         $v0, -0x17($a3)
    do_swl(rdram, -0X17, ctx->r7, ctx->r2);
    // swr         $v0, -0x1A($a3)
    do_swr(rdram, -0X1A, ctx->r7, ctx->r2);
    // swl         $v1, -0x13($a3)
    do_swl(rdram, -0X13, ctx->r7, ctx->r3);
    // swr         $v1, -0x16($a3)
    do_swr(rdram, -0X16, ctx->r7, ctx->r3);
    // swl         $a0, -0xF($a3)
    do_swl(rdram, -0XF, ctx->r7, ctx->r4);
    // swr         $a0, -0x12($a3)
    do_swr(rdram, -0X12, ctx->r7, ctx->r4);
    // swl         $a1, -0xB($a3)
    do_swl(rdram, -0XB, ctx->r7, ctx->r5);
    // swr         $a1, -0xE($a3)
    do_swr(rdram, -0XE, ctx->r7, ctx->r5);
    // lwl         $v0, -0x7($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, -0X7, ctx->r6);
    // lwr         $v0, -0xA($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, -0XA, ctx->r6);
    // nop

    // swl         $v0, -0x7($a3)
    do_swl(rdram, -0X7, ctx->r7, ctx->r2);
    // swr         $v0, -0xA($a3)
    do_swr(rdram, -0XA, ctx->r7, ctx->r2);
    // lwl         $v0, 0x3($t1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r9);
    // lwr         $v0, 0x0($t1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r9);
    // lwl         $v1, 0x7($t1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r9);
    // lwr         $v1, 0x4($t1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r9);
    // lwl         $a0, 0xB($t1)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r9);
    // lwr         $a0, 0x8($t1)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r9);
    // lwl         $a1, 0xF($t1)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r9);
    // lwr         $a1, 0xC($t1)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r9);
    // swl         $v0, 0x3($t0)
    do_swl(rdram, 0X3, ctx->r8, ctx->r2);
    // swr         $v0, 0x0($t0)
    do_swr(rdram, 0X0, ctx->r8, ctx->r2);
    // swl         $v1, 0x7($t0)
    do_swl(rdram, 0X7, ctx->r8, ctx->r3);
    // swr         $v1, 0x4($t0)
    do_swr(rdram, 0X4, ctx->r8, ctx->r3);
    // swl         $a0, 0xB($t0)
    do_swl(rdram, 0XB, ctx->r8, ctx->r4);
    // swr         $a0, 0x8($t0)
    do_swr(rdram, 0X8, ctx->r8, ctx->r4);
    // swl         $a1, 0xF($t0)
    do_swl(rdram, 0XF, ctx->r8, ctx->r5);
    // swr         $a1, 0xC($t0)
    do_swr(rdram, 0XC, ctx->r8, ctx->r5);
    // lwl         $v0, 0x13($t1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r9);
    // lwr         $v0, 0x10($t1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r9);
    // nop

    // swl         $v0, 0x13($t0)
    do_swl(rdram, 0X13, ctx->r8, ctx->r2);
    // swr         $v0, 0x10($t0)
    do_swr(rdram, 0X10, ctx->r8, ctx->r2);
    // lwl         $v0, -0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, -0X3, ctx->r6);
    // lwr         $v0, -0x6($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, -0X6, ctx->r6);
    // nop

    // swl         $v0, -0x3($a3)
    do_swl(rdram, -0X3, ctx->r7, ctx->r2);
    // swr         $v0, -0x6($a3)
    do_swr(rdram, -0X6, ctx->r7, ctx->r2);
    // addiu       $t1, $t1, 0x30
    ctx->r9 = ADD32(ctx->r9, 0X30);
    // addiu       $t0, $t0, 0x6C
    ctx->r8 = ADD32(ctx->r8, 0X6C);
    // lhu         $v0, -0x2($a2)
    ctx->r2 = MEM_HU(-0X2, ctx->r6);
    // addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // sh          $v0, -0x2($a3)
    MEM_H(-0X2, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // bne         $t2, $t3, L_80032078
    if (ctx->r10 != ctx->r11) {
        // addiu       $a3, $a3, 0x6C
        ctx->r7 = ADD32(ctx->r7, 0X6C);
        goto L_80032078;
    }
    // addiu       $a3, $a3, 0x6C
    ctx->r7 = ADD32(ctx->r7, 0X6C);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jr          $ra
    // sb          $v0, -0x492E($v1)
    MEM_B(-0X492E, ctx->r3) = ctx->r2;
    return;
    // sb          $v0, -0x492E($v1)
    MEM_B(-0X492E, ctx->r3) = ctx->r2;
;}
