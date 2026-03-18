#include "recomp.h"
#include "disable_warnings.h"

void sub_8002FE4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, 0x7F98
    ctx->r6 = ADD32(ctx->r2, 0X7F98);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r3);
    // swr         $v1, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r3);
    // swl         $a0, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r4);
    // swr         $a0, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r4);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7FA0
    ctx->r6 = ADD32(ctx->r2, 0X7FA0);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r3);
    // swr         $v1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r3);
    // swl         $a0, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r4);
    // swr         $a0, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r4);
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // lui         $s3, 0x1F80
    ctx->r19 = S32(0X1F80 << 16);
    // ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2) >> 16;
    // mult        $t0, $v1
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // ori         $a0, $a0, 0x330
    ctx->r4 = ctx->r4 | 0X330;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // ori         $a1, $a1, 0x32C
    ctx->r5 = ctx->r5 | 0X32C;
    // addiu       $a2, $zero, 0x201
    ctx->r6 = ADD32(0, 0X201);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $s6, $zero, 0x60
    ctx->r22 = ADD32(0, 0X60);
    // addiu       $s2, $zero, 0x30
    ctx->r18 = ADD32(0, 0X30);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $zero, -0x7E56($at)
    MEM_H(-0X7E56, ctx->r1) = 0;
    // sh          $s6, 0x334($s3)
    MEM_H(0X334, ctx->r19) = ctx->r22;
    // sh          $s2, 0x336($s3)
    MEM_H(0X336, ctx->r19) = ctx->r18;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v1, $t1, 1
    ctx->r3 = S32(ctx->r9) >> 1;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8) << 16;
    // sra         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8) >> 16;
    // sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8) << 3;
    // subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sh          $v0, 0x330($s3)
    MEM_H(0X330, ctx->r19) = ctx->r2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // jal         0x80027D18
    // sh          $v0, 0x332($s3)
    MEM_H(0X332, ctx->r19) = ctx->r2;
    sub_80027D18(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x332($s3)
    MEM_H(0X332, ctx->r19) = ctx->r2;
    after_0:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_1;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_1:
    // addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // lhu         $v0, 0x2E2($s3)
    ctx->r2 = MEM_HU(0X2E2, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_8002FFA0
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $s1, $sp, 0x20
        ctx->r17 = ADD32(ctx->r29, 0X20);
        goto L_8002FFA0;
    }
    // addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // ori         $a1, $a1, 0x32C
    ctx->r5 = ctx->r5 | 0X32C;
    // jal         0x8002916C
    // addiu       $a2, $zero, 0xC00
    ctx->r6 = ADD32(0, 0XC00);
    sub_8002916C(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0xC00
    ctx->r6 = ADD32(0, 0XC00);
    after_2:
L_8002FFA0:
    // lhu         $v1, 0x2E2($s3)
    ctx->r3 = MEM_HU(0X2E2, ctx->r19);
    // lhu         $v0, 0xE($s3)
    ctx->r2 = MEM_HU(0XE, ctx->r19);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8002FFD8
    if (ctx->r2 != 0) {
        // lui         $a1, 0x1F80
        ctx->r5 = S32(0X1F80 << 16);
        goto L_8002FFD8;
    }
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a1, $a1, 0x32C
    ctx->r5 = ctx->r5 | 0X32C;
    // jal         0x8002916C
    // addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    sub_8002916C(rdram, ctx);
    goto after_3;
    // addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    after_3:
L_8002FFD8:
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
    // addiu       $a1, $zero, 0x1E6
    ctx->r5 = ADD32(0, 0X1E6);
    // addiu       $a2, $zero, 0xD6
    ctx->r6 = ADD32(0, 0XD6);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // ori         $a3, $a3, 0x310
    ctx->r7 = ctx->r7 | 0X310;
    // lhu         $v1, 0x2E2($s3)
    ctx->r3 = MEM_HU(0X2E2, ctx->r19);
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3) << 2;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $s0, $a0, $v0
    ctx->r16 = ADD32(ctx->r4, ctx->r2);
    // addiu       $a0, $s0, 0x1
    ctx->r4 = ADD32(ctx->r16, 0X1);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // lui         $v1, 0x300
    ctx->r3 = S32(0X300 << 16);
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lbu         $s1, 0x0($v0)
    ctx->r17 = MEM_BU(0X0, ctx->r2);
    // jal         0x80027440
    // or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    sub_80027440(rdram, ctx);
    goto after_5;
    // or          $a0, $a0, $v1
    ctx->r4 = ctx->r4 | ctx->r3;
    after_5:
    // addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // addiu       $a1, $zero, 0x213
    ctx->r5 = ADD32(0, 0X213);
    // addiu       $a2, $zero, 0xD6
    ctx->r6 = ADD32(0, 0XD6);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // jal         0x80026ECC
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    sub_80026ECC(rdram, ctx);
    goto after_6;
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    after_6:
    // lui         $a0, 0x300
    ctx->r4 = S32(0X300 << 16);
    // ori         $a0, $a0, 0x96
    ctx->r4 = ctx->r4 | 0X96;
    // addiu       $a1, $zero, 0x227
    ctx->r5 = ADD32(0, 0X227);
    // addiu       $a2, $zero, 0xD6
    ctx->r6 = ADD32(0, 0XD6);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // jal         0x80027440
    // ori         $a3, $a3, 0x310
    ctx->r7 = ctx->r7 | 0X310;
    sub_80027440(rdram, ctx);
    goto after_7;
    // ori         $a3, $a3, 0x310
    ctx->r7 = ctx->r7 | 0X310;
    after_7:
    // lhu         $v0, 0xC($s3)
    ctx->r2 = MEM_HU(0XC, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800300D4
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x28
        ctx->r5 = ADD32(0, 0X28);
        goto L_800300D4;
    }
    // addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // addiu       $a2, $zero, 0xD6
    ctx->r6 = ADD32(0, 0XD6);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // lbu         $v0, 0x303($s3)
    ctx->r2 = MEM_BU(0X303, ctx->r19);
    // lw          $v1, 0x4($s3)
    ctx->r3 = MEM_W(0X4, ctx->r19);
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sb          $v0, 0x303($s3)
    MEM_B(0X303, ctx->r19) = ctx->r2;
    // sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(0X0, ctx->r2);
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_8;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_8:
    // lbu         $v0, 0x303($s3)
    ctx->r2 = MEM_BU(0X303, ctx->r19);
    // nop

    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // sb          $v0, 0x303($s3)
    MEM_B(0X303, ctx->r19) = ctx->r2;
L_800300D4:
    // addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    // addiu       $a2, $zero, 0x240
    ctx->r6 = ADD32(0, 0X240);
    // jal         0x80029548
    // addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    sub_80029548(rdram, ctx);
    goto after_9;
    // addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    after_9:
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // lui         $s5, 0x1F80
    ctx->r21 = S32(0X1F80 << 16);
    // ori         $s5, $s5, 0x350
    ctx->r21 = ctx->r21 | 0X350;
    // lhu         $v0, 0x2E2($s3)
    ctx->r2 = MEM_HU(0X2E2, ctx->r19);
    // addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // sh          $s6, 0x354($s3)
    MEM_H(0X354, ctx->r19) = ctx->r22;
    // sh          $s2, 0x356($s3)
    MEM_H(0X356, ctx->r19) = ctx->r18;
    // sh          $v1, 0x352($s3)
    MEM_H(0X352, ctx->r19) = ctx->r3;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
L_80030118:
    // lhu         $v0, 0x2E2($s3)
    ctx->r2 = MEM_HU(0X2E2, ctx->r19);
    // lhu         $v1, 0xE($s3)
    ctx->r3 = MEM_HU(0XE, ctx->r19);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // bne         $v0, $v1, L_8003014C
    if (ctx->r2 != ctx->r3) {
        // addiu       $s2, $zero, 0x5
        ctx->r18 = ADD32(0, 0X5);
        goto L_8003014C;
    }
    // addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // lhu         $v0, 0x10($s3)
    ctx->r2 = MEM_HU(0X10, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2) >> 16;
L_8003014C:
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sh          $v0, 0x350($s3)
    MEM_H(0X350, ctx->r19) = ctx->r2;
    // blez        $s2, L_800301F4
    if (SIGNED(ctx->r18) <= 0) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_800301F4;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8003015C:
    // lhu         $v0, 0xC($s3)
    ctx->r2 = MEM_HU(0XC, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800301D8
    if (ctx->r2 == 0) {
        // addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
        goto L_800301D8;
    }
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // addiu       $a1, $s3, 0x300
    ctx->r5 = ADD32(ctx->r19, 0X300);
    // addiu       $a2, $zero, 0x201
    ctx->r6 = ADD32(0, 0X201);
    // jal         0x80027D18
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_80027D18(rdram, ctx);
    goto after_10;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // lui         $v0, 0x8888
    ctx->r2 = S32(0X8888 << 16);
    // ori         $v0, $v0, 0x8889
    ctx->r2 = ctx->r2 | 0X8889;
    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // sra         $v1, $s0, 31
    ctx->r3 = S32(ctx->r16) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // addu        $v0, $t1, $s0
    ctx->r2 = ADD32(ctx->r9, ctx->r16);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $a1, $v0, 4
    ctx->r5 = S32(ctx->r2) << 4;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // subu        $a1, $s0, $a1
    ctx->r5 = SUB32(ctx->r16, ctx->r5);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // jal         0x80028364
    // addu        $a1, $s3, $a1
    ctx->r5 = ADD32(ctx->r19, ctx->r5);
    sub_80028364(rdram, ctx);
    goto after_11;
    // addu        $a1, $s3, $a1
    ctx->r5 = ADD32(ctx->r19, ctx->r5);
    after_11:
L_800301D8:
    // lhu         $v0, 0x350($s3)
    ctx->r2 = MEM_HU(0X350, ctx->r19);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    // sh          $v0, 0x350($s3)
    MEM_H(0X350, ctx->r19) = ctx->r2;
    // slt         $v0, $s1, $s2
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // bne         $v0, $zero, L_8003015C
    if (ctx->r2 != 0) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_8003015C;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800301F4:
    // lhu         $v0, 0x352($s3)
    ctx->r2 = MEM_HU(0X352, ctx->r19);
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // addiu       $v0, $v0, 0x38
    ctx->r2 = ADD32(ctx->r2, 0X38);
    // sh          $v0, 0x352($s3)
    MEM_H(0X352, ctx->r19) = ctx->r2;
    // slti        $v0, $s4, 0x3
    ctx->r2 = SIGNED(ctx->r20) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_80030118
    if (ctx->r2 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80030118;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // jal         0x800286A8
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    sub_800286A8(rdram, ctx);
    goto after_12;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_12:
    // addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // addiu       $a2, $zero, 0x240
    ctx->r6 = ADD32(0, 0X240);
    // jal         0x80029548
    // addiu       $a3, $zero, 0xB0
    ctx->r7 = ADD32(0, 0XB0);
    sub_80029548(rdram, ctx);
    goto after_13;
    // addiu       $a3, $zero, 0xB0
    ctx->r7 = ADD32(0, 0XB0);
    after_13:
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
    // lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(0X40, ctx->r29);
    // lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(0X3C, ctx->r29);
    // lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
