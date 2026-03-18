#include "recomp.h"
#include "disable_warnings.h"

void sub_80030BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, 0x7F5C
    ctx->r6 = ADD32(ctx->r2, 0X7F5C);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r3);
    // swr         $v1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7FC8
    ctx->r6 = ADD32(ctx->r2, 0X7FC8);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r3);
    // swr         $v1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r3);
    // swl         $a0, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r4);
    // swr         $a0, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r4);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7FD0
    ctx->r6 = ADD32(ctx->r2, 0X7FD0);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r3);
    // swr         $v1, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r3);
    // swl         $a0, 0x37($sp)
    do_swl(rdram, 0X37, ctx->r29, ctx->r4);
    // swr         $a0, 0x34($sp)
    do_swr(rdram, 0X34, ctx->r29, ctx->r4);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7FD8
    ctx->r6 = ADD32(ctx->r2, 0X7FD8);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x3B($sp)
    do_swl(rdram, 0X3B, ctx->r29, ctx->r3);
    // swr         $v1, 0x38($sp)
    do_swr(rdram, 0X38, ctx->r29, ctx->r3);
    // swl         $a0, 0x3F($sp)
    do_swl(rdram, 0X3F, ctx->r29, ctx->r4);
    // swr         $a0, 0x3C($sp)
    do_swr(rdram, 0X3C, ctx->r29, ctx->r4);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // lhu         $v0, 0x2E0($s2)
    ctx->r2 = MEM_HU(0X2E0, ctx->r18);
    // addiu       $a3, $v1, 0x7FE0
    ctx->r7 = ADD32(ctx->r3, 0X7FE0);
    // lwl         $a0, 0x3($a3)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X3, ctx->r7);
    // lwr         $a0, 0x0($a3)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X0, ctx->r7);
    // nop

    // swl         $a0, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r4);
    // swr         $a0, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r4);
    // addiu       $s5, $zero, 0x40
    ctx->r21 = ADD32(0, 0X40);
    // addiu       $s6, $zero, 0x20
    ctx->r22 = ADD32(0, 0X20);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // bgez        $a0, L_80030CDC
    if (SIGNED(ctx->r4) >= 0) {
        // addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
        goto L_80030CDC;
    }
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // addiu       $v0, $a0, 0x7
    ctx->r2 = ADD32(ctx->r4, 0X7);
L_80030CDC:
    // sra         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2) >> 3;
    // sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8) << 3;
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_80030D3C
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 6
        ctx->r2 = S32(ctx->r3) << 6;
        goto L_80030D3C;
    }
    // sll         $v0, $v1, 6
    ctx->r2 = S32(ctx->r3) << 6;
    // addiu       $v0, $v0, 0x32
    ctx->r2 = ADD32(ctx->r2, 0X32);
    // sh          $v0, 0x330($s2)
    MEM_H(0X330, ctx->r18) = ctx->r2;
    // lui         $a0, 0x1F80
    ctx->r4 = S32(0X1F80 << 16);
    // ori         $a0, $a0, 0x330
    ctx->r4 = ctx->r4 | 0X330;
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // ori         $a1, $a1, 0x32C
    ctx->r5 = ctx->r5 | 0X32C;
    // addiu       $a2, $zero, 0x201
    ctx->r6 = ADD32(0, 0X201);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // sll         $v0, $t0, 5
    ctx->r2 = S32(ctx->r8) << 5;
    // addiu       $v0, $v0, 0x23
    ctx->r2 = ADD32(ctx->r2, 0X23);
    // sh          $v0, 0x332($s2)
    MEM_H(0X332, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    // sh          $v0, 0x334($s2)
    MEM_H(0X334, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // jal         0x80027D18
    // sh          $v0, 0x336($s2)
    MEM_H(0X336, ctx->r18) = ctx->r2;
    sub_80027D18(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x336($s2)
    MEM_H(0X336, ctx->r18) = ctx->r2;
    after_0:
L_80030D3C:
    // lh          $v0, 0x0($s2)
    ctx->r2 = MEM_HS(0X0, ctx->r18);
    // nop

    // blez        $v0, L_80030D5C
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
        goto L_80030D5C;
    }
    // addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // ori         $a1, $s2, 0x32C
    ctx->r5 = ctx->r18 | 0X32C;
    // jal         0x8002916C
    // addiu       $a2, $zero, 0xC00
    ctx->r6 = ADD32(0, 0XC00);
    sub_8002916C(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0xC00
    ctx->r6 = ADD32(0, 0XC00);
    after_1:
    // lh          $v0, 0x0($s2)
    ctx->r2 = MEM_HS(0X0, ctx->r18);
L_80030D5C:
    // nop

    // slti        $v0, $v0, 0x49
    ctx->r2 = SIGNED(ctx->r2) < 0X49 ? 1 : 0;
    // beq         $v0, $zero, L_80030D78
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
        goto L_80030D78;
    }
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // ori         $a1, $s2, 0x32C
    ctx->r5 = ctx->r18 | 0X32C;
    // jal         0x8002916C
    // addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    sub_8002916C(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    after_2:
L_80030D78:
    // lui         $a0, 0xDD67
    ctx->r4 = S32(0XDD67 << 16);
    // lh          $v0, 0x0($s2)
    ctx->r2 = MEM_HS(0X0, ctx->r18);
    // ori         $a0, $a0, 0xC8A7
    ctx->r4 = ctx->r4 | 0XC8A7;
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // mfhi        $t1
    ctx->r9 = hi;
    // addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0x2F
    ctx->r2 = ADD32(ctx->r2, 0X2F);
    // jal         0x80028220
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    sub_80028220(rdram, ctx);
    goto after_3;
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    after_3:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_4;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_4:
    // addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lhu         $v0, 0x38($sp)
    ctx->r2 = MEM_HU(0X38, ctx->r29);
    // lhu         $v1, 0x3C($sp)
    ctx->r3 = MEM_HU(0X3C, ctx->r29);
    // lhu         $a3, 0x3E($sp)
    ctx->r7 = MEM_HU(0X3E, ctx->r29);
    // addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // sh          $v0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x3A($sp)
    ctx->r2 = MEM_HU(0X3A, ctx->r29);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // sh          $v1, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r3;
    // sh          $a3, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r7;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // jal         0x80028220
    // sh          $v0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r2;
    sub_80028220(rdram, ctx);
    goto after_5;
    // sh          $v0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r2;
    after_5:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_6;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_6:
    // ori         $a0, $s2, 0x33C
    ctx->r4 = ctx->r18 | 0X33C;
    // ori         $a1, $s2, 0x358
    ctx->r5 = ctx->r18 | 0X358;
    // ori         $a2, $s2, 0x35C
    ctx->r6 = ctx->r18 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // sh          $v0, 0x33C($s2)
    MEM_H(0X33C, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // sh          $v0, 0x33E($s2)
    MEM_H(0X33E, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0xC4
    ctx->r2 = ADD32(0, 0XC4);
    // sh          $v0, 0x340($s2)
    MEM_H(0X340, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x342($s2)
    MEM_H(0X342, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
    // sh          $v0, 0x358($s2)
    MEM_H(0X358, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // sh          $v0, 0x35A($s2)
    MEM_H(0X35A, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x35C($s2)
    MEM_H(0X35C, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1F6
    ctx->r2 = ADD32(0, 0X1F6);
    // sh          $v0, 0x35E($s2)
    MEM_H(0X35E, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_7;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_7:
    // lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // lh          $a0, 0x0($s2)
    ctx->r4 = MEM_HS(0X0, ctx->r18);
    // ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
    // addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
    // sh          $v0, 0x352($s2)
    MEM_H(0X352, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    // sh          $v0, 0x354($s2)
    MEM_H(0X354, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // sh          $v0, 0x356($s2)
    MEM_H(0X356, ctx->r18) = ctx->r2;
    // sra         $v0, $a0, 31
    ctx->r2 = S32(ctx->r4) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v1, $t1, 3
    ctx->r3 = S32(ctx->r9) >> 3;
    // subu        $s0, $v1, $v0
    ctx->r16 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $s0, $a0, $v0
    ctx->r16 = SUB32(ctx->r4, ctx->r2);
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_80030ED0:
    // sh          $v0, 0x350($s2)
    MEM_H(0X350, ctx->r18) = ctx->r2;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // addiu       $a0, $s2, 0x350
    ctx->r4 = ADD32(ctx->r18, 0X350);
L_80030EDC:
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // sll         $a1, $s0, 2
    ctx->r5 = S32(ctx->r16) << 2;
    // jal         0x80028364
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    sub_80028364(rdram, ctx);
    goto after_8;
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    after_8:
    // lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x350($s2)
    ctx->r2 = MEM_HU(0X350, ctx->r18);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // sh          $v0, 0x350($s2)
    MEM_H(0X350, ctx->r18) = ctx->r2;
    // sra         $v0, $a0, 31
    ctx->r2 = S32(ctx->r4) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v1, $t1, 3
    ctx->r3 = S32(ctx->r9) >> 3;
    // subu        $s0, $v1, $v0
    ctx->r16 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $s0, $a0, $v0
    ctx->r16 = SUB32(ctx->r4, ctx->r2);
    // slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_80030EDC
    if (ctx->r2 != 0) {
        // addiu       $a0, $s2, 0x350
        ctx->r4 = ADD32(ctx->r18, 0X350);
        goto L_80030EDC;
    }
    // addiu       $a0, $s2, 0x350
    ctx->r4 = ADD32(ctx->r18, 0X350);
    // lhu         $v0, 0x352($s2)
    ctx->r2 = MEM_HU(0X352, ctx->r18);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // sh          $v0, 0x352($s2)
    MEM_H(0X352, ctx->r18) = ctx->r2;
    // slti        $v0, $s3, 0x5
    ctx->r2 = SIGNED(ctx->r19) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80030ED0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x32
        ctx->r2 = ADD32(0, 0X32);
        goto L_80030ED0;
    }
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // addiu       $a2, $zero, 0x128
    ctx->r6 = ADD32(0, 0X128);
    // jal         0x80029548
    // addiu       $a3, $zero, 0xBC
    ctx->r7 = ADD32(0, 0XBC);
    sub_80029548(rdram, ctx);
    goto after_9;
    // addiu       $a3, $zero, 0xBC
    ctx->r7 = ADD32(0, 0XBC);
    after_9:
    // lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(0X74, ctx->r29);
    // lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(0X70, ctx->r29);
    // lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(0X6C, ctx->r29);
    // lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(0X68, ctx->r29);
    // lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(0X64, ctx->r29);
    // lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(0X60, ctx->r29);
    // lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(0X5C, ctx->r29);
    // lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(0X58, ctx->r29);
    // addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // jr          $ra
    // nop

    return;
    // nop

;}
