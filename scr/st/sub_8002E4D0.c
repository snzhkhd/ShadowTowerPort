#include "recomp.h"
#include "disable_warnings.h"

void sub_8002E4D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x158
    ctx->r29 = ADD32(ctx->r29, -0X158);
    // addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x128C
    ctx->r6 = ADD32(ctx->r2, 0X128C);
    // andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // sw          $ra, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r31;
    // sw          $fp, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r30;
    // sw          $s7, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r22;
    // sw          $s5, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r21;
    // sw          $s4, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r20;
    // sw          $s3, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r18;
    // sw          $s1, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r17;
    // beq         $v0, $zero, L_8002E568
    if (ctx->r2 == 0) {
        // sw          $s0, 0x130($sp)
        MEM_W(0X130, ctx->r29) = ctx->r16;
        goto L_8002E568;
    }
    // sw          $s0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r16;
    // addiu       $t0, $a2, 0xA0
    ctx->r8 = ADD32(ctx->r6, 0XA0);
L_8002E514:
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
    // bne         $a2, $t0, L_8002E514
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8002E514;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // j           L_8002E598
    // nop

    goto L_8002E598;
    // nop

L_8002E568:
    // addiu       $t0, $a2, 0xA0
    ctx->r8 = ADD32(ctx->r6, 0XA0);
L_8002E56C:
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
    // bne         $a2, $t0, L_8002E56C
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8002E56C;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_8002E598:
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
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x1334
    ctx->r6 = ADD32(ctx->r2, 0X1334);
    // andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // beq         $v0, $zero, L_8002E624
    if (ctx->r2 == 0) {
        // addiu       $a3, $sp, 0xC0
        ctx->r7 = ADD32(ctx->r29, 0XC0);
        goto L_8002E624;
    }
    // addiu       $a3, $sp, 0xC0
    ctx->r7 = ADD32(ctx->r29, 0XC0);
    // addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8002E5D0:
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
    // bne         $a2, $t0, L_8002E5D0
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8002E5D0;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // j           L_8002E654
    // nop

    goto L_8002E654;
    // nop

L_8002E624:
    // addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8002E628:
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
    // bne         $a2, $t0, L_8002E628
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8002E628;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_8002E654:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // nop

    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // addiu       $a0, $sp, 0x120
    ctx->r4 = ADD32(ctx->r29, 0X120);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // addiu       $v0, $zero, 0x1FF
    ctx->r2 = ADD32(0, 0X1FF);
    // sh          $zero, 0x118($sp)
    MEM_H(0X118, ctx->r29) = 0;
    // jal         0x80078AB4
    // sh          $v0, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = ctx->r2;
    memset_recomp(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = ctx->r2;
    after_0:
    // lui         $s4, 0x1F80
    ctx->r20 = S32(0X1F80 << 16);
    // lhu         $v0, 0x2E0($s4)
    ctx->r2 = MEM_HU(0X2E0, ctx->r20);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // bne         $v0, $zero, L_8002E6A8
    if (ctx->r2 != 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8002E6A8;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
L_8002E6A8:
    // ori         $a0, $s4, 0x330
    ctx->r4 = ctx->r20 | 0X330;
    // ori         $a1, $s4, 0x32C
    ctx->r5 = ctx->r20 | 0X32C;
    // addiu       $a2, $zero, 0x201
    ctx->r6 = ADD32(0, 0X201);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addiu       $v1, $sp, 0x18
    ctx->r3 = ADD32(ctx->r29, 0X18);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // sh          $v0, 0x330($s4)
    MEM_H(0X330, ctx->r20) = ctx->r2;
    // lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(0X2, ctx->r3);
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x332($s4)
    MEM_H(0X332, ctx->r20) = ctx->r2;
    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // addiu       $s7, $s4, 0x31C
    ctx->r23 = ADD32(ctx->r20, 0X31C);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // sh          $v0, 0x334($s4)
    MEM_H(0X334, ctx->r20) = ctx->r2;
    // lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(0X6, ctx->r3);
    // addu        $s5, $s1, $zero
    ctx->r21 = ADD32(ctx->r17, 0);
    // addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // jal         0x80027D18
    // sh          $v0, 0x336($s4)
    MEM_H(0X336, ctx->r20) = ctx->r2;
    sub_80027D18(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x336($s4)
    MEM_H(0X336, ctx->r20) = ctx->r2;
    after_1:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_2;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_2:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s2, $v0, -0x70A0
    ctx->r18 = ADD32(ctx->r2, -0X70A0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s6, $v0, 0x76F8
    ctx->r22 = ADD32(ctx->r2, 0X76F8);
    // addiu       $fp, $s2, -0x38
    ctx->r30 = ADD32(ctx->r18, -0X38);
    // addiu       $v0, $zero, 0xC0
    ctx->r2 = ADD32(0, 0XC0);
    // sb          $v0, 0x31C($s4)
    MEM_B(0X31C, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x9E
    ctx->r2 = ADD32(0, 0X9E);
    // sb          $v0, 0x31D($s4)
    MEM_B(0X31D, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sb          $v0, 0x31E($s4)
    MEM_B(0X31E, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sb          $v0, 0x31F($s4)
    MEM_B(0X31F, ctx->r20) = ctx->r2;
L_8002E748:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $s1, $v0, L_8002E7C4
    if (ctx->r17 == ctx->r2) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8002E7C4;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // bne         $s1, $v0, L_8002E78C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_8002E78C;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // lhu         $v1, 0x58($fp)
    ctx->r3 = MEM_HU(0X58, ctx->r30);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // lbu         $v1, 0x13E($v0)
    ctx->r3 = MEM_BU(0X13E, ctx->r2);
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // beq         $v1, $v0, L_8002E7C4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_8002E7C4;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8002E78C:
    // bne         $s1, $v0, L_8002E7C8
    if (ctx->r17 != ctx->r2) {
        // addiu       $s3, $zero, 0x10
        ctx->r19 = ADD32(0, 0X10);
        goto L_8002E7C8;
    }
    // addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // lhu         $v1, 0x5A($fp)
    ctx->r3 = MEM_HU(0X5A, ctx->r30);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // lbu         $v1, 0x13E($v0)
    ctx->r3 = MEM_BU(0X13E, ctx->r2);
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // bne         $v1, $v0, L_8002E7CC
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
        goto L_8002E7CC;
    }
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8002E7C4:
    // addiu       $s3, $zero, 0x30
    ctx->r19 = ADD32(0, 0X30);
L_8002E7C8:
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8002E7CC:
    // beq         $s1, $v0, L_8002E8E0
    if (ctx->r17 == ctx->r2) {
        // addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
        goto L_8002E8E0;
    }
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // beq         $s1, $v0, L_8002E8E0
    if (ctx->r17 == ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8002E8E0;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lbu         $v1, 0x2C6($s4)
    ctx->r3 = MEM_BU(0X2C6, ctx->r20);
    // nop

    // bne         $v1, $v0, L_8002E8E0
    if (ctx->r3 != ctx->r2) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_8002E8E0;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(0X0, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8002E8E0
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8002E8E0;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $s6
    ctx->r3 = ADD32(ctx->r3, ctx->r22);
    // lbu         $v0, 0x13F($v1)
    ctx->r2 = MEM_BU(0X13F, ctx->r3);
    // nop

    // beq         $v0, $zero, L_8002E8E0
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xC8
        ctx->r2 = ADD32(0, 0XC8);
        goto L_8002E8E0;
    }
    // addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    // sb          $v0, 0x31C($s4)
    MEM_B(0X31C, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0xA4
    ctx->r2 = ADD32(0, 0XA4);
    // sb          $v0, 0x31D($s4)
    MEM_B(0X31D, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // addu        $s0, $s0, $s5
    ctx->r16 = ADD32(ctx->r16, ctx->r21);
    // addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    // lui         $t1, 0x200
    ctx->r9 = S32(0X200 << 16);
    // sb          $v0, 0x31E($s4)
    MEM_B(0X31E, ctx->r20) = ctx->r2;
    // lhu         $a1, 0x0($s0)
    ctx->r5 = MEM_HU(0X0, ctx->r16);
    // lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(0X0, ctx->r18);
    // lhu         $a2, 0x2($s0)
    ctx->r6 = MEM_HU(0X2, ctx->r16);
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // lbu         $a0, 0x140($v0)
    ctx->r4 = MEM_BU(0X140, ctx->r2);
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // jal         0x80027440
    // or          $a0, $a0, $t1
    ctx->r4 = ctx->r4 | ctx->r9;
    sub_80027440(rdram, ctx);
    goto after_3;
    // or          $a0, $a0, $t1
    ctx->r4 = ctx->r4 | ctx->r9;
    after_3:
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    // lui         $t1, 0x200
    ctx->r9 = S32(0X200 << 16);
    // sb          $v0, 0x31C($s4)
    MEM_B(0X31C, ctx->r20) = ctx->r2;
    // sb          $v0, 0x31D($s4)
    MEM_B(0X31D, ctx->r20) = ctx->r2;
    // sb          $zero, 0x31E($s4)
    MEM_B(0X31E, ctx->r20) = 0;
    // lhu         $a1, 0x0($s0)
    ctx->r5 = MEM_HU(0X0, ctx->r16);
    // lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(0X0, ctx->r18);
    // lhu         $a2, 0x2($s0)
    ctx->r6 = MEM_HU(0X2, ctx->r16);
    // addiu       $a1, $a1, 0x9
    ctx->r5 = ADD32(ctx->r5, 0X9);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // addiu       $a2, $a2, 0x5
    ctx->r6 = ADD32(ctx->r6, 0X5);
    // lbu         $a0, 0x140($v0)
    ctx->r4 = MEM_BU(0X140, ctx->r2);
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // jal         0x80027440
    // or          $a0, $a0, $t1
    ctx->r4 = ctx->r4 | ctx->r9;
    sub_80027440(rdram, ctx);
    goto after_4;
    // or          $a0, $a0, $t1
    ctx->r4 = ctx->r4 | ctx->r9;
    after_4:
L_8002E8E0:
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    // addiu       $v0, $sp, 0xC0
    ctx->r2 = ADD32(ctx->r29, 0XC0);
    // sll         $a1, $s1, 2
    ctx->r5 = S32(ctx->r17) << 2;
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    // addiu       $a2, $sp, 0x118
    ctx->r6 = ADD32(ctx->r29, 0X118);
    // jal         0x80028364
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_80028364(rdram, ctx);
    goto after_5;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
    // addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // slti        $v0, $s1, 0x15
    ctx->r2 = SIGNED(ctx->r17) < 0X15 ? 1 : 0;
    // bne         $v0, $zero, L_8002E748
    if (ctx->r2 != 0) {
        // addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
        goto L_8002E748;
    }
    // addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // lw          $ra, 0x154($sp)
    ctx->r31 = MEM_W(0X154, ctx->r29);
    // lw          $fp, 0x150($sp)
    ctx->r30 = MEM_W(0X150, ctx->r29);
    // lw          $s7, 0x14C($sp)
    ctx->r23 = MEM_W(0X14C, ctx->r29);
    // lw          $s6, 0x148($sp)
    ctx->r22 = MEM_W(0X148, ctx->r29);
    // lw          $s5, 0x144($sp)
    ctx->r21 = MEM_W(0X144, ctx->r29);
    // lw          $s4, 0x140($sp)
    ctx->r20 = MEM_W(0X140, ctx->r29);
    // lw          $s3, 0x13C($sp)
    ctx->r19 = MEM_W(0X13C, ctx->r29);
    // lw          $s2, 0x138($sp)
    ctx->r18 = MEM_W(0X138, ctx->r29);
    // lw          $s1, 0x134($sp)
    ctx->r17 = MEM_W(0X134, ctx->r29);
    // lw          $s0, 0x130($sp)
    ctx->r16 = MEM_W(0X130, ctx->r29);
    // addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
    // jr          $ra
    // nop

    return;
    // nop

;}
