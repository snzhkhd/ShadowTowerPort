#include "recomp.h"
#include "disable_warnings.h"

void sub_80059204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x28D0
    ctx->r6 = ADD32(ctx->r2, 0X28D0);
    // andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // sw          $ra, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r31;
    // sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // beq         $v0, $zero, L_8005928C
    if (ctx->r2 == 0) {
        // sw          $s0, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r16;
        goto L_8005928C;
    }
    // sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_80059238:
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
    // bne         $a2, $t0, L_80059238
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_80059238;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // j           L_800592BC
    // nop

    goto L_800592BC;
    // nop

L_8005928C:
    // addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_80059290:
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
    // bne         $a2, $t0, L_80059290
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_80059290;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_800592BC:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // nop

    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $v0, $v0, -0x7E00
    ctx->r2 = ADD32(ctx->r2, -0X7E00);
    // addiu       $v1, $v0, 0xA88
    ctx->r3 = ADD32(ctx->r2, 0XA88);
    // sw          $v1, 0xA84($v0)
    MEM_W(0XA84, ctx->r2) = ctx->r3;
    // sll         $v1, $s3, 1
    ctx->r3 = S32(ctx->r19) << 1;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70A0
    ctx->r2 = ADD32(ctx->r2, -0X70A0);
    // addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    // sltiu       $v0, $s3, 0x15
    ctx->r2 = ctx->r19 < 0X15 ? 1 : 0;
    // beq         $v0, $zero, L_800595B4
    if (ctx->r2 == 0) {
        // addiu       $s1, $zero, -0x1
        ctx->r17 = ADD32(0, -0X1);
        goto L_800595B4;
    }
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x3738
    ctx->r2 = ADD32(ctx->r2, 0X3738);
    // sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_80059314;
    jr_addend_80059314 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80059314 >> 2) {
        case 0: goto L_8005931C; break;
        case 1: goto L_80059328; break;
        case 2: goto L_80059334; break;
        case 3: goto L_80059340; break;
        case 4: goto L_80059350; break;
        case 5: goto L_800593F0; break;
        case 6: goto L_800593FC; break;
        case 7: goto L_80059380; break;
        case 8: goto L_8005938C; break;
        case 9: goto L_80059398; break;
        case 10: goto L_800593E4; break;
        case 11: goto L_800593F0; break;
        case 12: goto L_800593FC; break;
        case 13: goto L_8005931C; break;
        case 14: goto L_80059328; break;
        case 15: goto L_80059334; break;
        case 16: goto L_80059360; break;
        case 17: goto L_80059370; break;
        case 18: goto L_800593F0; break;
        case 19: goto L_800593F0; break;
        case 20: goto L_800593F0; break;
        default: switch_error(__func__, 0x80059314, 0x80013738);
    }
    // nop

L_8005931C:
    // addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // j           L_80059404
    // addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
    goto L_80059404;
    // addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
L_80059328:
    // addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // j           L_80059404
    // addiu       $a1, $zero, 0xEE
    ctx->r5 = ADD32(0, 0XEE);
    goto L_80059404;
    // addiu       $a1, $zero, 0xEE
    ctx->r5 = ADD32(0, 0XEE);
L_80059334:
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // j           L_80059404
    // addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
    goto L_80059404;
    // addiu       $a1, $zero, 0x7C
    ctx->r5 = ADD32(0, 0X7C);
L_80059340:
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // j           L_80059404
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    goto L_80059404;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80059350:
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // j           L_80059404
    // addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    goto L_80059404;
    // addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80059360:
    // addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // addiu       $a1, $zero, 0xA6
    ctx->r5 = ADD32(0, 0XA6);
    // j           L_80059404
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    goto L_80059404;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80059370:
    // addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // addiu       $a1, $zero, 0xA6
    ctx->r5 = ADD32(0, 0XA6);
    // j           L_80059404
    // addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    goto L_80059404;
    // addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80059380:
    // addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // j           L_80059404
    // addiu       $a1, $zero, 0x103
    ctx->r5 = ADD32(0, 0X103);
    goto L_80059404;
    // addiu       $a1, $zero, 0x103
    ctx->r5 = ADD32(0, 0X103);
L_8005938C:
    // addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // j           L_80059404
    // addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    goto L_80059404;
    // addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
L_80059398:
    // addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(0X0, ctx->r18);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_80059404
    if (ctx->r3 == ctx->r2) {
        // addiu       $a1, $zero, 0x5D
        ctx->r5 = ADD32(0, 0X5D);
        goto L_80059404;
    }
    // addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
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
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // bne         $v1, $v0, L_80059408
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
        goto L_80059408;
    }
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // j           L_80059408
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    goto L_80059408;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_800593E4:
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // j           L_80059404
    // addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    goto L_80059404;
    // addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
L_800593F0:
    // addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // j           L_80059404
    // addiu       $a1, $zero, 0x113
    ctx->r5 = ADD32(0, 0X113);
    goto L_80059404;
    // addiu       $a1, $zero, 0x113
    ctx->r5 = ADD32(0, 0X113);
L_800593FC:
    // addiu       $a2, $zero, 0x3D1
    ctx->r6 = ADD32(0, 0X3D1);
    // addiu       $a1, $zero, 0x3D0
    ctx->r5 = ADD32(0, 0X3D0);
L_80059404:
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80059408:
    // beq         $s3, $v0, L_80059418
    if (ctx->r19 == ctx->r2) {
        // addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
        goto L_80059418;
    }
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // bne         $s3, $v0, L_80059438
    if (ctx->r19 != ctx->r2) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80059438;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80059418:
    // lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(0X0, ctx->r18);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_80059430
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80059430;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // j           L_80059460
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    goto L_80059460;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
L_80059430:
    // j           L_80059460
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    goto L_80059460;
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_80059438:
    // lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(0X0, ctx->r18);
    // nop

    // beq         $v1, $v0, L_80059454
    if (ctx->r3 == ctx->r2) {
        // addu        $v1, $v1, $a2
        ctx->r3 = ADD32(ctx->r3, ctx->r6);
        goto L_80059454;
    }
    // addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // j           L_8005945C
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    goto L_8005945C;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_80059454:
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
L_8005945C:
    // addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_80059460:
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // addiu       $s0, $s0, -0x7E00
    ctx->r16 = ADD32(ctx->r16, -0X7E00);
    // lw          $a2, 0xA84($s0)
    ctx->r6 = MEM_W(0XA84, ctx->r16);
    // jal         0x80016030
    // andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    sub_80016030(rdram, ctx);
    goto after_0;
    // andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_0:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lw          $s0, 0xA84($s0)
    ctx->r16 = MEM_W(0XA84, ctx->r16);
    // beq         $s1, $v0, L_800594A8
    if (ctx->r17 == ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_800594A8;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $s1, $v0, L_800594AC
    if (ctx->r17 != ctx->r2) {
        // addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
        goto L_800594AC;
    }
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // j           L_800594AC
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    goto L_800594AC;
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_800594A8:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800594AC:
    // sll         $a1, $s3, 2
    ctx->r5 = S32(ctx->r19) << 2;
    // addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_1;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // beq         $v0, $a1, L_800595B4
    if (ctx->r2 == ctx->r5) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_800595B4;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(0X0, ctx->r18);
    // addiu       $v0, $v0, 0x76F8
    ctx->r2 = ADD32(ctx->r2, 0X76F8);
    // sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4) << 1;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v1, 0x13E($v1)
    ctx->r3 = MEM_BU(0X13E, ctx->r3);
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // bne         $v1, $v0, L_80059588
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_80059588;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // bne         $s3, $v0, L_80059544
    if (ctx->r19 != ctx->r2) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_80059544;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lhu         $v1, 0x1C($sp)
    ctx->r3 = MEM_HU(0X1C, ctx->r29);
    // lhu         $a1, 0x1E($sp)
    ctx->r5 = MEM_HU(0X1E, ctx->r29);
    // addiu       $v0, $zero, 0x5C
    ctx->r2 = ADD32(0, 0X5C);
    // sh          $v0, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
    // sh          $v0, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r2;
    // sh          $v1, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r3;
    // jal         0x80079A60
    // sh          $a1, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r5;
    DrawSync(rdram, ctx);
    goto after_2;
    // sh          $a1, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r5;
    after_2:
    // lh          $a1, 0x50($sp)
    ctx->r5 = MEM_HS(0X50, ctx->r29);
    // lh          $a2, 0x52($sp)
    ctx->r6 = MEM_HS(0X52, ctx->r29);
    // j           L_80059578
    // nop

    goto L_80059578;
    // nop

L_80059544:
    // bne         $s3, $v0, L_800595B4
    if (ctx->r19 != ctx->r2) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_800595B4;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lhu         $v1, 0x20($sp)
    ctx->r3 = MEM_HU(0X20, ctx->r29);
    // lhu         $a1, 0x22($sp)
    ctx->r5 = MEM_HU(0X22, ctx->r29);
    // addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    // sh          $v0, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // sh          $v0, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r2;
    // sh          $v1, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r3;
    // jal         0x80079A60
    // sh          $a1, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r5;
    DrawSync(rdram, ctx);
    goto after_3;
    // sh          $a1, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r5;
    after_3:
    // lh          $a1, 0x54($sp)
    ctx->r5 = MEM_HS(0X54, ctx->r29);
    // lh          $a2, 0x56($sp)
    ctx->r6 = MEM_HS(0X56, ctx->r29);
L_80059578:
    // jal         0x80079DCC
    // addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    MoveImage(rdram, ctx);
    goto after_4;
    // addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_4:
    // j           L_800595B4
    // nop

    goto L_800595B4;
    // nop

L_80059588:
    // beq         $a0, $a1, L_800595B4
    if (ctx->r4 == ctx->r5) {
        // addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
        goto L_800595B4;
    }
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // bne         $v1, $v0, L_800595B4
    if (ctx->r3 != ctx->r2) {
        // addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
        goto L_800595B4;
    }
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // jal         0x8003EC5C
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    sub_8003EC5C(rdram, ctx);
    goto after_5;
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_5:
L_800595B4:
    // lw          $ra, 0x80($sp)
    ctx->r31 = MEM_W(0X80, ctx->r29);
    // lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(0X7C, ctx->r29);
    // lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(0X78, ctx->r29);
    // lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(0X74, ctx->r29);
    // lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(0X70, ctx->r29);
    // addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // jr          $ra
    // nop

    return;
    // nop

;}
