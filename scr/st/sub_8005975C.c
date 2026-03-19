#include "recomp.h"
#include "disable_warnings.h"

void sub_8005975C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // bne         $s1, $zero, L_80059840
    if (ctx->r17 != 0) {
        // sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
        goto L_80059840;
    }
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // ori         $a3, $a3, 0x292
    ctx->r7 = ctx->r7 | 0X292;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a2, $v0, -0x70A0
    ctx->r6 = ADD32(ctx->r2, -0X70A0);
    // or          $v0, $a2, $a3
    ctx->r2 = ctx->r6 | ctx->r7;
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // beq         $v0, $zero, L_800597EC
    if (ctx->r2 == 0) {
        // addiu       $t0, $a2, 0x20
        ctx->r8 = ADD32(ctx->r6, 0X20);
        goto L_800597EC;
    }
    // addiu       $t0, $a2, 0x20
    ctx->r8 = ADD32(ctx->r6, 0X20);
L_80059798:
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
    // bne         $a2, $t0, L_80059798
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_80059798;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // j           L_80059818
    // nop

    goto L_80059818;
    // nop

L_800597EC:
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
    // bne         $a2, $t0, L_800597EC
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_800597EC;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_80059818:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lh          $a0, 0x8($a2)
    ctx->r4 = MEM_HS(0X8, ctx->r6);
    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // swl         $v1, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r3);
    // swr         $v1, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r3);
    // sh          $a0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r4;
L_80059840:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, 0x4A($a1)
    ctx->r3 = MEM_HU(0X4A, ctx->r5);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_800598FC
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_800598FC;
    }
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // addiu       $a0, $a0, 0x76F8
    ctx->r4 = ADD32(ctx->r4, 0X76F8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $a0, 0x13E($v0)
    ctx->r4 = MEM_BU(0X13E, ctx->r2);
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // bne         $a0, $v0, L_80059900
    if (ctx->r4 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80059900;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $v1, $v0, L_800598C0
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
        goto L_800598C0;
    }
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // beq         $v1, $v0, L_800598C0
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
        goto L_800598C0;
    }
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // beq         $v1, $v0, L_800598C4
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_800598C4;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // beq         $v1, $a0, L_800598C0
    if (ctx->r3 == ctx->r4) {
        // addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
        goto L_800598C0;
    }
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // bne         $v1, $v0, L_80059900
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80059900;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_800598C0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_800598C4:
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // sh          $v1, 0x3C($v0)
    MEM_H(0X3C, ctx->r2) = ctx->r3;
    // sh          $v1, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r3;
    // sh          $v1, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r3;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $s1, $v0, L_80059900
    if (ctx->r17 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80059900;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // jal         0x80059204
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    sub_80059204(rdram, ctx);
    goto after_0;
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // jal         0x80059204
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    sub_80059204(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_1:
    // jal         0x80059204
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    sub_80059204(rdram, ctx);
    goto after_2;
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_2:
L_800598FC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80059900:
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v0, 0x3E($a1)
    ctx->r2 = MEM_HU(0X3E, ctx->r5);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // beq         $v0, $a2, L_80059988
    if (ctx->r2 == ctx->r6) {
        // lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
        goto L_80059988;
    }
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $a0, $a0, 0x76F8
    ctx->r4 = ADD32(ctx->r4, 0X76F8);
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
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x13E($v0)
    ctx->r3 = MEM_BU(0X13E, ctx->r2);
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // bne         $v1, $v0, L_8005998C
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8005998C;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $v0, L_80059968
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x11
        ctx->r2 = ADD32(0, 0X11);
        goto L_80059968;
    }
    // addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // bne         $v1, $v0, L_8005998C
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8005998C;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80059968:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $a2, 0x3E($a1)
    MEM_H(0X3E, ctx->r5) = ctx->r6;
    // bne         $s1, $v0, L_80059988
    if (ctx->r17 != ctx->r2) {
        // sh          $a2, 0x58($a1)
        MEM_H(0X58, ctx->r5) = ctx->r6;
        goto L_80059988;
    }
    // sh          $a2, 0x58($a1)
    MEM_H(0X58, ctx->r5) = ctx->r6;
    // jal         0x80059204
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    sub_80059204(rdram, ctx);
    goto after_3;
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // jal         0x80059204
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    sub_80059204(rdram, ctx);
    goto after_4;
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_4:
L_80059988:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8005998C:
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v0, 0x40($a1)
    ctx->r2 = MEM_HU(0X40, ctx->r5);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // beq         $v0, $a2, L_80059A14
    if (ctx->r2 == ctx->r6) {
        // lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
        goto L_80059A14;
    }
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $a0, $a0, 0x76F8
    ctx->r4 = ADD32(ctx->r4, 0X76F8);
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
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x13E($v0)
    ctx->r3 = MEM_BU(0X13E, ctx->r2);
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // bne         $v1, $v0, L_80059A14
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80059A14;
    }
    // nop

    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_800599F4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
        goto L_800599F4;
    }
    // addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // bne         $v1, $v0, L_80059A14
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80059A14;
    }
    // nop

L_800599F4:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $a2, 0x40($a1)
    MEM_H(0X40, ctx->r5) = ctx->r6;
    // bne         $s1, $v0, L_80059A14
    if (ctx->r17 != ctx->r2) {
        // sh          $a2, 0x5A($a1)
        MEM_H(0X5A, ctx->r5) = ctx->r6;
        goto L_80059A14;
    }
    // sh          $a2, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r6;
    // jal         0x80059204
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    sub_80059204(rdram, ctx);
    goto after_5;
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_5:
    // jal         0x80059204
    // addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    sub_80059204(rdram, ctx);
    goto after_6;
    // addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_6:
L_80059A14:
    // lhu         $v0, 0x2C0($s0)
    ctx->r2 = MEM_HU(0X2C0, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a0, $v0, L_80059B28
    if (ctx->r4 == ctx->r2) {
        // lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
        goto L_80059B28;
    }
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x76F8
    ctx->r3 = ADD32(ctx->r3, 0X76F8);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x13E($v0)
    ctx->r3 = MEM_BU(0X13E, ctx->r2);
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // bne         $v1, $v0, L_80059A90
    if (ctx->r3 != ctx->r2) {
        // lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
        goto L_80059A90;
    }
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // sh          $v1, 0x3C($v0)
    MEM_H(0X3C, ctx->r2) = ctx->r3;
    // sh          $v1, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r3;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $s1, $v0, L_80059A90
    if (ctx->r17 != ctx->r2) {
        // nop
    
        goto L_80059A90;
    }
    // nop

    // jal         0x80059204
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    sub_80059204(rdram, ctx);
    goto after_7;
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // jal         0x80059204
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    sub_80059204(rdram, ctx);
    goto after_8;
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_8:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
L_80059A90:
    // lhu         $v1, 0x2C0($s0)
    ctx->r3 = MEM_HU(0X2C0, ctx->r16);
    // addiu       $a0, $a0, 0x76F8
    ctx->r4 = ADD32(ctx->r4, 0X76F8);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
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
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x13E($v0)
    ctx->r3 = MEM_BU(0X13E, ctx->r2);
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // bne         $v1, $v0, L_80059B28
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80059B28;
    }
    // nop

    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // bne         $v1, $v0, L_80059B04
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_80059B04;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // sh          $v1, -0x7080($v0)
    MEM_H(-0X7080, ctx->r2) = ctx->r3;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $s1, $v0, L_80059B28
    if (ctx->r17 != ctx->r2) {
        // addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
        goto L_80059B28;
    }
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // j           L_80059B20
    // nop

    goto L_80059B20;
    // nop

L_80059B04:
    // bne         $v1, $v0, L_80059B28
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80059B28;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // sh          $v1, -0x707E($v0)
    MEM_H(-0X707E, ctx->r2) = ctx->r3;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $s1, $v0, L_80059B28
    if (ctx->r17 != ctx->r2) {
        // addiu       $a0, $zero, 0x11
        ctx->r4 = ADD32(0, 0X11);
        goto L_80059B28;
    }
    // addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
L_80059B20:
    // jal         0x80059204
    // nop

    sub_80059204(rdram, ctx);
    goto after_9;
    // nop

    after_9:
L_80059B28:
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $a0, $v0, L_80059B4C
    if (ctx->r4 == ctx->r2) {
        // addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
        goto L_80059B4C;
    }
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // bne         $a0, $v0, L_80059B90
    if (ctx->r4 != ctx->r2) {
        // slti        $v0, $a0, 0xA
        ctx->r2 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
        goto L_80059B90;
    }
    // slti        $v0, $a0, 0xA
    ctx->r2 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
L_80059B4C:
    // lhu         $a0, 0x2C0($s0)
    ctx->r4 = MEM_HU(0X2C0, ctx->r16);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_80059B78
    if (ctx->r2 != ctx->r3) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80059B78;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // sh          $v1, -0x709C($v0)
    MEM_H(-0X709C, ctx->r2) = ctx->r3;
    // addiu       $v0, $v0, -0x709C
    ctx->r2 = ADD32(ctx->r2, -0X709C);
    // j           L_80059B7C
    // sh          $v1, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r3;
    goto L_80059B7C;
    // sh          $v1, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r3;
L_80059B78:
    // sh          $a0, -0x709C($v0)
    MEM_H(-0X709C, ctx->r2) = ctx->r4;
L_80059B7C:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $s1, $v0, L_80059C68
    if (ctx->r17 != ctx->r2) {
        // addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
        goto L_80059C68;
    }
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // j           L_80059C60
    // nop

    goto L_80059C60;
    // nop

L_80059B90:
    // beq         $v0, $zero, L_80059BFC
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
        goto L_80059BFC;
    }
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // lhu         $a1, 0x2C0($s0)
    ctx->r5 = MEM_HU(0X2C0, ctx->r16);
    // nop

    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_80059BCC
    if (ctx->r2 != ctx->r3) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_80059BCC;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70A0
    ctx->r2 = ADD32(ctx->r2, -0X70A0);
    // sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // j           L_80059BDC
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    goto L_80059BDC;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_80059BCC:
    // addiu       $v1, $v1, -0x70A0
    ctx->r3 = ADD32(ctx->r3, -0X70A0);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
L_80059BDC:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $s1, $v0, L_80059C68
    if (ctx->r17 != ctx->r2) {
        // nop
    
        goto L_80059C68;
    }
    // nop

    // lhu         $a0, 0x2E0($s0)
    ctx->r4 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // j           L_80059C60
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    goto L_80059C60;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
L_80059BFC:
    // lhu         $a1, 0x2C0($s0)
    ctx->r5 = MEM_HU(0X2C0, ctx->r16);
    // nop

    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_80059C30
    if (ctx->r2 != ctx->r3) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_80059C30;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70A2
    ctx->r2 = ADD32(ctx->r2, -0X70A2);
    // sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // j           L_80059C40
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    goto L_80059C40;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_80059C30:
    // addiu       $v1, $v1, -0x70A2
    ctx->r3 = ADD32(ctx->r3, -0X70A2);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
L_80059C40:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $s1, $v0, L_80059C68
    if (ctx->r17 != ctx->r2) {
        // nop
    
        goto L_80059C68;
    }
    // nop

    // lhu         $a0, 0x2E0($s0)
    ctx->r4 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_80059C60:
    // jal         0x80059204
    // nop

    sub_80059204(rdram, ctx);
    goto after_10;
    // nop

    after_10:
L_80059C68:
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // beq         $v1, $zero, L_80059C90
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0xE
        ctx->r2 = ADD32(0, 0XE);
        goto L_80059C90;
    }
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // bne         $v1, $v0, L_80059CD4
    if (ctx->r3 != ctx->r2) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_80059CD4;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // j           L_80059CA0
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    goto L_80059CA0;
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80059C90:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // j           L_80059CA4
    // sh          $v0, -0x7094($v1)
    MEM_H(-0X7094, ctx->r3) = ctx->r2;
    goto L_80059CA4;
    // sh          $v0, -0x7094($v1)
    MEM_H(-0X7094, ctx->r3) = ctx->r2;
L_80059CA0:
    // sh          $v0, -0x7088($v1)
    MEM_H(-0X7088, ctx->r3) = ctx->r2;
L_80059CA4:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $s1, $v0, L_80059CD4
    if (ctx->r17 != ctx->r2) {
        // nop
    
        goto L_80059CD4;
    }
    // nop

    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ST_DrawSync(rdram, ctx);
    goto after_11;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_11:
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80059CCC
    if (ctx->r2 != 0) {
        // addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
        goto L_80059CCC;
    }
    // addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_80059CCC:
    // jal         0x80059204
    // nop

    sub_80059204(rdram, ctx);
    goto after_12;
    // nop

    after_12:
L_80059CD4:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
