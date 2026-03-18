#include "recomp.h"
#include "disable_warnings.h"

void sub_80065270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // lui         $s7, 0x1F80
    ctx->r23 = S32(0X1F80 << 16);
    // sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // lhu         $v0, 0x8($s7)
    ctx->r2 = MEM_HU(0X8, ctx->r23);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_80065338
    if (SIGNED(ctx->r2) <= 0) {
        // lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
        goto L_80065338;
    }
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7EE4
    ctx->r6 = ADD32(ctx->r2, -0X7EE4);
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
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7EDC
    ctx->r6 = ADD32(ctx->r2, -0X7EDC);
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
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // ori         $a1, $a1, 0x32C
    ctx->r5 = ctx->r5 | 0X32C;
    // jal         0x8002916C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_8002916C(rdram, ctx);
    goto after_0;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // ori         $a1, $a1, 0x32C
    ctx->r5 = ctx->r5 | 0X32C;
    // jal         0x8002916C
    // addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    sub_8002916C(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    after_1:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_2;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_2:
L_80065338:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lh          $s1, 0xCE8($v0)
    ctx->r17 = MEM_HS(0XCE8, ctx->r2);
    // lhu         $v0, 0xCE8($v0)
    ctx->r2 = MEM_HU(0XCE8, ctx->r2);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $s1, $v1, L_80065488
    if (ctx->r17 == ctx->r3) {
        // sh          $v0, 0x28($sp)
        MEM_H(0X28, ctx->r29) = ctx->r2;
        goto L_80065488;
    }
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17) << 1;
    // lbu         $v0, 0x303($s7)
    ctx->r2 = MEM_BU(0X303, ctx->r23);
    // lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(0X0, ctx->r23);
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sb          $v0, 0x303($s7)
    MEM_B(0X303, ctx->r23) = ctx->r2;
    // addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
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
    goto after_3;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_3:
    // addu        $s0, $s0, $s1
    ctx->r16 = ADD32(ctx->r16, ctx->r17);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // subu        $s0, $s0, $s1
    ctx->r16 = SUB32(ctx->r16, ctx->r17);
    // lbu         $v0, 0x303($s7)
    ctx->r2 = MEM_BU(0X303, ctx->r23);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // sb          $v0, 0x303($s7)
    MEM_B(0X303, ctx->r23) = ctx->r2;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x76F8
    ctx->r2 = ADD32(ctx->r2, 0X76F8);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lbu         $v0, 0x13F($s0)
    ctx->r2 = MEM_BU(0X13F, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8006548C
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0xA5
        ctx->r5 = ADD32(0, 0XA5);
        goto L_8006548C;
    }
    // addiu       $a1, $zero, 0xA5
    ctx->r5 = ADD32(0, 0XA5);
    // lbu         $v0, 0x140($s0)
    ctx->r2 = MEM_BU(0X140, ctx->r16);
    // nop

    // sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_800653E4
    if (ctx->r2 == 0) {
        // lui         $s2, 0x1F80
        ctx->r18 = S32(0X1F80 << 16);
        goto L_800653E4;
    }
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // ori         $s2, $s2, 0x308
    ctx->r18 = ctx->r18 | 0X308;
    // lui         $s3, 0x1F80
    ctx->r19 = S32(0X1F80 << 16);
    // j           L_800653F0
    // ori         $s3, $s3, 0x318
    ctx->r19 = ctx->r19 | 0X318;
    goto L_800653F0;
    // ori         $s3, $s3, 0x318
    ctx->r19 = ctx->r19 | 0X318;
L_800653E4:
    // ori         $s2, $s2, 0x300
    ctx->r18 = ctx->r18 | 0X300;
    // lui         $s3, 0x1F80
    ctx->r19 = S32(0X1F80 << 16);
    // ori         $s3, $s3, 0x310
    ctx->r19 = ctx->r19 | 0X310;
L_800653F0:
    // addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0xDA($a0)
    ctx->r2 = MEM_HU(0XDA, ctx->r4);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_4;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_4:
    // addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    // addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // lhu         $t1, 0x28($sp)
    ctx->r9 = MEM_HU(0X28, ctx->r29);
    // addiu       $v1, $v1, 0x76F8
    ctx->r3 = ADD32(ctx->r3, 0X76F8);
    // sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $s0, $v0, 1
    ctx->r16 = S32(ctx->r2) << 1;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // lbu         $a0, 0x140($s0)
    ctx->r4 = MEM_BU(0X140, ctx->r16);
    // lui         $s1, 0x300
    ctx->r17 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_80027440(rdram, ctx);
    goto after_5;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_5:
    // addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    // jal         0x80026ECC
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_80026ECC(rdram, ctx);
    goto after_6;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_6:
    // addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    // addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    // lbu         $a0, 0x13F($s0)
    ctx->r4 = MEM_BU(0X13F, ctx->r16);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_80027440(rdram, ctx);
    goto after_7;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_7:
L_80065488:
    // addiu       $a1, $zero, 0xA5
    ctx->r5 = ADD32(0, 0XA5);
L_8006548C:
    // addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    // addiu       $s2, $s7, 0x300
    ctx->r18 = ADD32(ctx->r23, 0X300);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // addiu       $s3, $s7, 0x310
    ctx->r19 = ADD32(ctx->r23, 0X310);
    // lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // addiu       $s0, $s0, 0xD50
    ctx->r16 = ADD32(ctx->r16, 0XD50);
    // lhu         $a0, 0xCE($s0)
    ctx->r4 = MEM_HU(0XCE, ctx->r16);
    // addiu       $s1, $s0, 0xC00
    ctx->r17 = ADD32(ctx->r16, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    sub_8002732C(rdram, ctx);
    goto after_8;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_8:
    // addiu       $a1, $zero, 0xA5
    ctx->r5 = ADD32(0, 0XA5);
    // addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // lhu         $a0, 0xCE($s0)
    ctx->r4 = MEM_HU(0XCE, ctx->r16);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // jal         0x8002732C
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    sub_8002732C(rdram, ctx);
    goto after_9;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_9:
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // lhu         $t1, 0x28($sp)
    ctx->r9 = MEM_HU(0X28, ctx->r29);
    // addiu       $v1, $v1, 0x76F8
    ctx->r3 = ADD32(ctx->r3, 0X76F8);
    // sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9) << 16;
    // sra         $s6, $v0, 16
    ctx->r22 = S32(ctx->r2) >> 16;
    // sll         $v0, $s6, 1
    ctx->r2 = S32(ctx->r22) << 1;
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s6
    ctx->r2 = SUB32(ctx->r2, ctx->r22);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $fp, $v0, $v1
    ctx->r30 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80065504:
    // bne         $s6, $v0, L_80065534
    if (ctx->r22 != ctx->r2) {
        // addiu       $a1, $zero, 0xCF
        ctx->r5 = ADD32(0, 0XCF);
        goto L_80065534;
    }
    // addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    // lui         $a0, 0x1300
    ctx->r4 = S32(0X1300 << 16);
    // andi        $s0, $s5, 0xFFFF
    ctx->r16 = ctx->r21 & 0XFFFF;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x800276BC
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    sub_800276BC(rdram, ctx);
    goto after_10;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_10:
    // lui         $a0, 0x1300
    ctx->r4 = S32(0X1300 << 16);
    // addiu       $a1, $zero, 0x111
    ctx->r5 = ADD32(0, 0X111);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // j           L_80065568
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    goto L_80065568;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
L_80065534:
    // andi        $s2, $s5, 0xFFFF
    ctx->r18 = ctx->r21 & 0XFFFF;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // addu        $s0, $fp, $s4
    ctx->r16 = ADD32(ctx->r30, ctx->r20);
    // lbu         $a0, 0x128($s0)
    ctx->r4 = MEM_BU(0X128, ctx->r16);
    // lui         $s1, 0x1300
    ctx->r17 = S32(0X1300 << 16);
    // jal         0x800276BC
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_800276BC(rdram, ctx);
    goto after_11;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_11:
    // addiu       $a1, $zero, 0x111
    ctx->r5 = ADD32(0, 0X111);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // lbu         $a0, 0x12F($s0)
    ctx->r4 = MEM_BU(0X12F, ctx->r16);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
L_80065568:
    // jal         0x800276BC
    // addiu       $s5, $s5, 0xE
    ctx->r21 = ADD32(ctx->r21, 0XE);
    sub_800276BC(rdram, ctx);
    goto after_12;
    // addiu       $s5, $s5, 0xE
    ctx->r21 = ADD32(ctx->r21, 0XE);
    after_12:
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // slti        $v0, $s4, 0x7
    ctx->r2 = SIGNED(ctx->r20) < 0X7 ? 1 : 0;
    // bne         $v0, $zero, L_80065504
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80065504;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lhu         $t1, 0x28($sp)
    ctx->r9 = MEM_HU(0X28, ctx->r29);
    // nop

    // sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a0, $v0, L_800656F4
    if (ctx->r4 == ctx->r2) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_800656F4;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
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
    // addu        $a1, $v1, $v0
    ctx->r5 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x13C($a1)
    ctx->r2 = MEM_HU(0X13C, ctx->r5);
    // nop

    // beq         $v0, $zero, L_800656DC
    if (ctx->r2 == 0) {
        // lui         $a0, 0x2416
        ctx->r4 = S32(0X2416 << 16);
        goto L_800656DC;
    }
    // lui         $a0, 0x2416
    ctx->r4 = S32(0X2416 << 16);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // ori         $a0, $a0, 0x8E19
    ctx->r4 = ctx->r4 | 0X8E19;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2) << 5;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // mfhi        $t0
    ctx->r8 = hi;
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addiu       $a1, $zero, 0xDD
    ctx->r5 = ADD32(0, 0XDD);
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    // addiu       $s1, $s7, 0x300
    ctx->r17 = ADD32(ctx->r23, 0X300);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0xD0($a0)
    ctx->r2 = MEM_HU(0XD0, ctx->r4);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // sra         $v0, $t0, 6
    ctx->r2 = S32(ctx->r8) >> 6;
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E62($at)
    MEM_H(-0X7E62, ctx->r1) = ctx->r2;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v0, $t2, 6
    ctx->r2 = S32(ctx->r10) >> 6;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E78($at)
    MEM_H(-0X7E78, ctx->r1) = ctx->r2;
    // jal         0x8002732C
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    sub_8002732C(rdram, ctx);
    goto after_13;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_13:
    // addiu       $a1, $zero, 0xF9
    ctx->r5 = ADD32(0, 0XF9);
    // addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    // addiu       $s0, $s7, 0x310
    ctx->r16 = ADD32(ctx->r23, 0X310);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lhu         $v0, -0x7E62($v0)
    ctx->r2 = MEM_HU(-0X7E62, ctx->r2);
    // lui         $a0, 0x300
    ctx->r4 = S32(0X300 << 16);
    // jal         0x800276BC
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    sub_800276BC(rdram, ctx);
    goto after_14;
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    after_14:
    // addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // addiu       $a1, $zero, 0x10D
    ctx->r5 = ADD32(0, 0X10D);
    // addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    // jal         0x80026ECC
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    sub_80026ECC(rdram, ctx);
    goto after_15;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_15:
    // addiu       $a1, $zero, 0x113
    ctx->r5 = ADD32(0, 0X113);
    // addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E62($v1)
    ctx->r3 = MEM_HU(-0X7E62, ctx->r3);
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // lhu         $a0, -0x7E78($a0)
    ctx->r4 = MEM_HU(-0X7E78, ctx->r4);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // jal         0x800276BC
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    sub_800276BC(rdram, ctx);
    goto after_16;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    after_16:
    // addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    // addiu       $a1, $zero, 0x119
    ctx->r5 = ADD32(0, 0X119);
    // addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    // jal         0x80026ECC
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    sub_80026ECC(rdram, ctx);
    goto after_17;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_17:
L_800656DC:
    // ori         $a0, $s7, 0x350
    ctx->r4 = ctx->r23 | 0X350;
    // ori         $a1, $s7, 0x358
    ctx->r5 = ctx->r23 | 0X358;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // j           L_80065708
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    goto L_80065708;
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_800656F4:
    // ori         $a0, $s7, 0x350
    ctx->r4 = ctx->r23 | 0X350;
    // ori         $a1, $s7, 0x358
    ctx->r5 = ctx->r23 | 0X358;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
L_80065708:
    // sh          $v0, 0x350($s7)
    MEM_H(0X350, ctx->r23) = ctx->r2;
    // addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // sh          $v0, 0x352($s7)
    MEM_H(0X352, ctx->r23) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sh          $v0, 0x354($s7)
    MEM_H(0X354, ctx->r23) = ctx->r2;
    // sh          $v0, 0x356($s7)
    MEM_H(0X356, ctx->r23) = ctx->r2;
    // addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // sh          $v0, 0x358($s7)
    MEM_H(0X358, ctx->r23) = ctx->r2;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $v0, 0x35A($s7)
    MEM_H(0X35A, ctx->r23) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_18;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_18:
    // lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(0X5C, ctx->r29);
    // lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(0X58, ctx->r29);
    // lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(0X54, ctx->r29);
    // lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(0X50, ctx->r29);
    // lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(0X4C, ctx->r29);
    // lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(0X48, ctx->r29);
    // lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(0X44, ctx->r29);
    // lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(0X40, ctx->r29);
    // lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(0X3C, ctx->r29);
    // lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // jr          $ra
    // nop

    return;
    // nop

;}
