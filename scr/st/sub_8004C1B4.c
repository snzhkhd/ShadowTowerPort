#include "recomp.h"
#include "disable_warnings.h"

void sub_8004C1B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // lh          $v0, 0x9C($s2)
    ctx->r2 = MEM_HS(0X9C, ctx->r18);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lh          $v0, 0xA0($s2)
    ctx->r2 = MEM_HS(0XA0, ctx->r18);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // addu        $s4, $fp, $zero
    ctx->r20 = ADD32(ctx->r30, 0);
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // lbu         $v0, 0x2($s2)
    ctx->r2 = MEM_BU(0X2, ctx->r18);
    // mflo        $a3
    ctx->r7 = lo;
    // addu        $a0, $v1, $a3
    ctx->r4 = ADD32(ctx->r3, ctx->r7);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3) << 6;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x29C8
    ctx->r2 = ADD32(ctx->r2, -0X29C8);
    // jal         0x800746C4
    // addu        $s7, $v1, $v0
    ctx->r23 = ADD32(ctx->r3, ctx->r2);
    SquareRoot0(rdram, ctx);
    goto after_0;
    // addu        $s7, $v1, $v0
    ctx->r23 = ADD32(ctx->r3, ctx->r2);
    after_0:
    // lh          $a0, 0xA0($s2)
    ctx->r4 = MEM_HS(0XA0, ctx->r18);
    // lh          $a1, 0x9C($s2)
    ctx->r5 = MEM_HS(0X9C, ctx->r18);
    // jal         0x80076EA4
    // addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    ratan2(rdram, ctx);
    goto after_1;
    // addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    after_1:
    // lwl         $v1, 0x9F($s2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X9F, ctx->r18);
    // lwr         $v1, 0x9C($s2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X9C, ctx->r18);
    // lwl         $a0, 0xA3($s2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XA3, ctx->r18);
    // lwr         $a0, 0xA0($s2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0XA0, ctx->r18);
    // swl         $v1, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r3);
    // swr         $v1, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r3);
    // swl         $a0, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r4);
    // swr         $a0, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r4);
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // lbu         $v1, 0xE($s2)
    ctx->r3 = MEM_BU(0XE, ctx->r18);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $v1, $v0, L_8004C288
    if (ctx->r3 == ctx->r2) {
        // lui         $a1, 0x801B
        ctx->r5 = S32(0X801B << 16);
        goto L_8004C288;
    }
    // lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // lhu         $v0, 0x16($s2)
    ctx->r2 = MEM_HU(0X16, ctx->r18);
    // nop

    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
L_8004C288:
    // addiu       $v1, $a1, 0x5948
    ctx->r3 = ADD32(ctx->r5, 0X5948);
    // lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(0X74, ctx->r18);
    // lw          $a0, 0x78($s2)
    ctx->r4 = MEM_W(0X78, ctx->r18);
    // lw          $a2, 0x7C($s2)
    ctx->r6 = MEM_W(0X7C, ctx->r18);
    // lw          $a3, 0x80($s2)
    ctx->r7 = MEM_W(0X80, ctx->r18);
    // sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // sw          $a2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r6;
    // sw          $a3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r7;
    // lhu         $a0, 0x30($s2)
    ctx->r4 = MEM_HU(0X30, ctx->r18);
    // lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(0X8, ctx->r3);
    // nop

    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x2E($s2)
    ctx->r2 = MEM_HU(0X2E, ctx->r18);
    // nop

    // sh          $v0, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x30($s2)
    ctx->r2 = MEM_HU(0X30, ctx->r18);
    // nop

    // sh          $v0, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = ctx->r2;
    // lw          $v0, 0x50($s2)
    ctx->r2 = MEM_W(0X50, ctx->r18);
    // nop

    // ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // sw          $v0, 0x5948($a1)
    MEM_W(0X5948, ctx->r5) = ctx->r2;
L_8004C2E8:
    // lhu         $v0, 0x10($sp)
    ctx->r2 = MEM_HU(0X10, ctx->r29);
    // nop

    // sh          $v0, 0x9C($s2)
    MEM_H(0X9C, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x12($sp)
    ctx->r2 = MEM_HU(0X12, ctx->r29);
    // nop

    // sh          $v0, 0x9E($s2)
    MEM_H(0X9E, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x14($sp)
    ctx->r2 = MEM_HU(0X14, ctx->r29);
    // nop

    // sh          $v0, 0xA0($s2)
    MEM_H(0XA0, ctx->r18) = ctx->r2;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $s0, $v0, 0x5948
    ctx->r16 = ADD32(ctx->r2, 0X5948);
    // lwl         $v0, 0x9F($s2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X9F, ctx->r18);
    // lwr         $v0, 0x9C($s2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X9C, ctx->r18);
    // lwl         $v1, 0xA3($s2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0XA3, ctx->r18);
    // lwr         $v1, 0xA0($s2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0XA0, ctx->r18);
    // swl         $v0, 0x17($s0)
    do_swl(rdram, 0X17, ctx->r16, ctx->r2);
    // swr         $v0, 0x14($s0)
    do_swr(rdram, 0X14, ctx->r16, ctx->r2);
    // swl         $v1, 0x1B($s0)
    do_swl(rdram, 0X1B, ctx->r16, ctx->r3);
    // swr         $v1, 0x18($s0)
    do_swr(rdram, 0X18, ctx->r16, ctx->r3);
    // lh          $a0, 0xA0($s2)
    ctx->r4 = MEM_HS(0XA0, ctx->r18);
    // lh          $a1, 0x9C($s2)
    ctx->r5 = MEM_HS(0X9C, ctx->r18);
    // jal         0x80076EA4
    // nop

    ratan2(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lh          $v1, 0x10($sp)
    ctx->r3 = MEM_HS(0X10, ctx->r29);
    // nop

    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v1, 0x14($sp)
    ctx->r3 = MEM_HS(0X14, ctx->r29);
    // nop

    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $v0, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r2;
    // mflo        $v1
    ctx->r3 = lo;
    // jal         0x800746C4
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    SquareRoot0(rdram, ctx);
    goto after_3;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    after_3:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80049544
    // sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
    sub_80049544(rdram, ctx);
    goto after_4;
    // sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
    after_4:
    // bne         $s4, $zero, L_8004C408
    if (ctx->r20 != 0) {
        // addu        $s1, $v0, $zero
        ctx->r17 = ADD32(ctx->r2, 0);
        goto L_8004C408;
    }
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // lhu         $v0, 0x44CA($s0)
    ctx->r2 = MEM_HU(0X44CA, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8004C3B4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8004C3B4;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lbu         $v1, 0x3($s2)
    ctx->r3 = MEM_BU(0X3, ctx->r18);
    // nop

    // bne         $v1, $v0, L_8004C3A8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004C3A8;
    }
    // nop

    // sb          $zero, 0x3($s2)
    MEM_B(0X3, ctx->r18) = 0;
L_8004C3A8:
    // lhu         $v0, 0x47D8($s0)
    ctx->r2 = MEM_HU(0X47D8, ctx->r16);
    // j           L_8004C3CC
    // sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
    goto L_8004C3CC;
    // sh          $v0, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r2;
L_8004C3B4:
    // lbu         $v0, 0x3($s2)
    ctx->r2 = MEM_BU(0X3, ctx->r18);
    // nop

    // bne         $v0, $zero, L_8004C3D0
    if (ctx->r2 != 0) {
        // lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
        goto L_8004C3D0;
    }
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
L_8004C3CC:
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
L_8004C3D0:
    // lhu         $a0, 0x26($s2)
    ctx->r4 = MEM_HU(0X26, ctx->r18);
    // addiu       $v1, $v1, -0x4130
    ctx->r3 = ADD32(ctx->r3, -0X4130);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(0X1, ctx->r2);
    // lbu         $v0, 0x6($s2)
    ctx->r2 = MEM_BU(0X6, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8004C408
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004C408;
    }
    // nop

    // sh          $zero, 0x14($sp)
    MEM_H(0X14, ctx->r29) = 0;
    // j           L_8004C654
    // sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
    goto L_8004C654;
    // sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
L_8004C408:
    // beq         $s1, $zero, L_8004C654
    if (ctx->r17 == 0) {
        // addu        $v0, $s4, $zero
        ctx->r2 = ADD32(ctx->r20, 0);
        goto L_8004C654;
    }
    // addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // beq         $v0, $zero, L_8004C654
    if (ctx->r2 == 0) {
        // addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_8004C654;
    }
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // andi        $v0, $s1, 0x2
    ctx->r2 = ctx->r17 & 0X2;
    // beq         $v0, $zero, L_8004C4B8
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8004C4B8;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $s3, $v0, 0x5948
    ctx->r19 = ADD32(ctx->r2, 0X5948);
    // lhu         $v1, 0x2E($s2)
    ctx->r3 = MEM_HU(0X2E, ctx->r18);
    // lw          $v0, 0x3C($s3)
    ctx->r2 = MEM_W(0X3C, ctx->r19);
    // lh          $a1, 0x8C($s3)
    ctx->r5 = MEM_HS(0X8C, ctx->r19);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_8004C458
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8004C458;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_8004C458:
    // lh          $a0, 0x90($s3)
    ctx->r4 = MEM_HS(0X90, ctx->r19);
    // nop

    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8004C478
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0x10($sp)
        MEM_H(0X10, ctx->r29) = ctx->r2;
        goto L_8004C478;
    }
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8004C478:
    // lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(0X30, ctx->r29);
    // sra         $v0, $v1, 12
    ctx->r2 = S32(ctx->r3) >> 12;
    // bne         $a2, $zero, L_8004C654
    if (ctx->r6 != 0) {
        // sh          $v0, 0x14($sp)
        MEM_H(0X14, ctx->r29) = ctx->r2;
        goto L_8004C654;
    }
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // jal         0x80076EA4
    // nop

    ratan2(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // addiu       $s1, $v0, 0x400
    ctx->r17 = ADD32(ctx->r2, 0X400);
    // andi        $v1, $s1, 0xFFF
    ctx->r3 = ctx->r17 & 0XFFF;
    // subu        $a0, $s5, $v1
    ctx->r4 = SUB32(ctx->r21, ctx->r3);
    // sw          $v0, 0x78($s3)
    MEM_W(0X78, ctx->r19) = ctx->r2;
    // jal         0x800744C4
    // sh          $v1, 0x5E($s2)
    MEM_H(0X5E, ctx->r18) = ctx->r3;
    rcos(rdram, ctx);
    goto after_6;
    // sh          $v1, 0x5E($s2)
    MEM_H(0X5E, ctx->r18) = ctx->r3;
    after_6:
    // mult        $s6, $v0
    result = S64(S32(ctx->r22)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // j           L_8004C5E0
    // sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    goto L_8004C5E0;
    // sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
L_8004C4B8:
    // andi        $v0, $s1, 0x8
    ctx->r2 = ctx->r17 & 0X8;
    // beq         $v0, $zero, L_8004C554
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8004C554;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $s3, $v0, 0x5948
    ctx->r19 = ADD32(ctx->r2, 0X5948);
    // lhu         $v1, 0x2E($s2)
    ctx->r3 = MEM_HU(0X2E, ctx->r18);
    // lw          $v0, 0x44($s3)
    ctx->r2 = MEM_W(0X44, ctx->r19);
    // lh          $a1, 0x9C($s3)
    ctx->r5 = MEM_HS(0X9C, ctx->r19);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_8004C4F4
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8004C4F4;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_8004C4F4:
    // lh          $a0, 0xA0($s3)
    ctx->r4 = MEM_HS(0XA0, ctx->r19);
    // nop

    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8004C514
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0x10($sp)
        MEM_H(0X10, ctx->r29) = ctx->r2;
        goto L_8004C514;
    }
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8004C514:
    // lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(0X34, ctx->r29);
    // sra         $v0, $v1, 12
    ctx->r2 = S32(ctx->r3) >> 12;
    // bne         $a2, $zero, L_8004C654
    if (ctx->r6 != 0) {
        // sh          $v0, 0x14($sp)
        MEM_H(0X14, ctx->r29) = ctx->r2;
        goto L_8004C654;
    }
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // jal         0x80076EA4
    // nop

    ratan2(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // addiu       $s1, $v0, 0x400
    ctx->r17 = ADD32(ctx->r2, 0X400);
    // andi        $v1, $s1, 0xFFF
    ctx->r3 = ctx->r17 & 0XFFF;
    // subu        $a0, $s5, $v1
    ctx->r4 = SUB32(ctx->r21, ctx->r3);
    // sw          $v0, 0x78($s3)
    MEM_W(0X78, ctx->r19) = ctx->r2;
    // jal         0x800744C4
    // sh          $v1, 0x5E($s2)
    MEM_H(0X5E, ctx->r18) = ctx->r3;
    rcos(rdram, ctx);
    goto after_8;
    // sh          $v1, 0x5E($s2)
    MEM_H(0X5E, ctx->r18) = ctx->r3;
    after_8:
    // mult        $s6, $v0
    result = S64(S32(ctx->r22)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // j           L_8004C5E0
    // sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    goto L_8004C5E0;
    // sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
L_8004C554:
    // andi        $v0, $s1, 0xD0
    ctx->r2 = ctx->r17 & 0XD0;
    // beq         $v0, $zero, L_8004C654
    if (ctx->r2 == 0) {
        // andi        $v0, $s1, 0x80
        ctx->r2 = ctx->r17 & 0X80;
        goto L_8004C654;
    }
    // andi        $v0, $s1, 0x80
    ctx->r2 = ctx->r17 & 0X80;
    // beq         $v0, $zero, L_8004C56C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8004C56C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x39($s2)
    MEM_B(0X39, ctx->r18) = ctx->r2;
L_8004C56C:
    // jal         0x800492F4
    // addiu       $a0, $s2, 0x74
    ctx->r4 = ADD32(ctx->r18, 0X74);
    sub_800492F4(rdram, ctx);
    goto after_9;
    // addiu       $a0, $s2, 0x74
    ctx->r4 = ADD32(ctx->r18, 0X74);
    after_9:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $s3, $v0, 0x5948
    ctx->r19 = ADD32(ctx->r2, 0X5948);
    // lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(0X74, ctx->r18);
    // lw          $v1, 0xAC($s3)
    ctx->r3 = MEM_W(0XAC, ctx->r19);
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lw          $v0, 0x7C($s2)
    ctx->r2 = MEM_W(0X7C, ctx->r18);
    // lw          $v1, 0xB4($s3)
    ctx->r3 = MEM_W(0XB4, ctx->r19);
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x800747E0
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    VectorNormalS(rdram, ctx);
    goto after_10;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_10:
    // sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
    // bne         $fp, $zero, L_8004C654
    if (ctx->r30 != 0) {
        // sh          $zero, 0x14($sp)
        MEM_H(0X14, ctx->r29) = 0;
        goto L_8004C654;
    }
    // sh          $zero, 0x14($sp)
    MEM_H(0X14, ctx->r29) = 0;
    // lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(0X20, ctx->r29);
    // lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(0X18, ctx->r29);
    // jal         0x80076EA4
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    ratan2(rdram, ctx);
    goto after_11;
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    after_11:
    // addiu       $s1, $v0, 0x400
    ctx->r17 = ADD32(ctx->r2, 0X400);
    // andi        $a0, $s1, 0xFFF
    ctx->r4 = ctx->r17 & 0XFFF;
    // subu        $a0, $s5, $a0
    ctx->r4 = SUB32(ctx->r21, ctx->r4);
    // jal         0x800744C4
    // sw          $v0, 0x78($s3)
    MEM_W(0X78, ctx->r19) = ctx->r2;
    rcos(rdram, ctx);
    goto after_12;
    // sw          $v0, 0x78($s3)
    MEM_W(0X78, ctx->r19) = ctx->r2;
    after_12:
    // mult        $s6, $v0
    result = S64(S32(ctx->r22)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8004C5E0:
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_8004C5F4
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $s0, $v0, 12
        ctx->r16 = S32(ctx->r2) >> 12;
        goto L_8004C5F4;
    }
    // sra         $s0, $v0, 12
    ctx->r16 = S32(ctx->r2) >> 12;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
    // sra         $s0, $v0, 12
    ctx->r16 = S32(ctx->r2) >> 12;
L_8004C5F4:
    // beq         $s0, $zero, L_8004C2E8
    if (ctx->r16 == 0) {
        // sh          $s0, 0x44C6($s3)
        MEM_H(0X44C6, ctx->r19) = ctx->r16;
        goto L_8004C2E8;
    }
    // sh          $s0, 0x44C6($s3)
    MEM_H(0X44C6, ctx->r19) = ctx->r16;
    // jal         0x800744C4
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    rcos(rdram, ctx);
    goto after_13;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_13:
    // mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8004C618
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8004C618;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8004C618:
    // lhu         $v0, 0x10($sp)
    ctx->r2 = MEM_HU(0X10, ctx->r29);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x800743F4
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    rsin(rdram, ctx);
    goto after_14;
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    after_14:
    // mult        $v0, $s0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8004C640
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8004C640;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8004C640:
    // lhu         $v0, 0x14($sp)
    ctx->r2 = MEM_HU(0X14, ctx->r29);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_8004C2E8
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    goto L_8004C2E8;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
L_8004C654:
    // andi        $v0, $s1, 0x4
    ctx->r2 = ctx->r17 & 0X4;
    // beq         $v0, $zero, L_8004C678
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8004C678;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $a0, 0x5974($v0)
    ctx->r4 = MEM_W(0X5974, ctx->r2);
    // lhu         $v0, 0x30($s2)
    ctx->r2 = MEM_HU(0X30, ctx->r18);
    // lhu         $v1, 0x12($sp)
    ctx->r3 = MEM_HU(0X12, ctx->r29);
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r3;
L_8004C678:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lhu         $v1, 0x30($s2)
    ctx->r3 = MEM_HU(0X30, ctx->r18);
    // lw          $v0, 0x5974($v0)
    ctx->r2 = MEM_W(0X5974, ctx->r2);
    // lbu         $a1, 0xE($s2)
    ctx->r5 = MEM_BU(0XE, ctx->r18);
    // subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8004C6A4
    if (ctx->r2 == 0) {
        // sw          $a0, 0x4C($s2)
        MEM_W(0X4C, ctx->r18) = ctx->r4;
        goto L_8004C6A4;
    }
    // sw          $a0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->r4;
    // j           L_8004C7B0
    // sh          $zero, 0x12($sp)
    MEM_H(0X12, ctx->r29) = 0;
    goto L_8004C7B0;
    // sh          $zero, 0x12($sp)
    MEM_H(0X12, ctx->r29) = 0;
L_8004C6A4:
    // blez        $a0, L_8004C768
    if (SIGNED(ctx->r4) <= 0) {
        // andi        $v1, $a1, 0xFF
        ctx->r3 = ctx->r5 & 0XFF;
        goto L_8004C768;
    }
    // andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_8004C768
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004C768;
    }
    // nop

    // lhu         $v0, 0x30($s2)
    ctx->r2 = MEM_HU(0X30, ctx->r18);
    // nop

    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_8004C6D4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_8004C6D4;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // bne         $v1, $v0, L_8004C79C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004C79C;
    }
    // nop

L_8004C6D4:
    // lh          $v0, 0x16($s2)
    ctx->r2 = MEM_HS(0X16, ctx->r18);
    // lhu         $a1, 0x16($s2)
    ctx->r5 = MEM_HU(0X16, ctx->r18);
    // blez        $v0, L_8004C700
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8004C700;
    }
    // nop

    // lh          $v0, 0x12($sp)
    ctx->r2 = MEM_HS(0X12, ctx->r29);
    // nop

    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8004C724
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004C724;
    }
    // nop

    // j           L_8004C7AC
    // sh          $a0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r4;
    goto L_8004C7AC;
    // sh          $a0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r4;
L_8004C700:
    // bgez        $v0, L_8004C738
    if (SIGNED(ctx->r2) >= 0) {
        // slt         $v0, $a0, $v0
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
        goto L_8004C738;
    }
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8004C724
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004C724;
    }
    // nop

    // lhu         $v0, 0x12($sp)
    ctx->r2 = MEM_HU(0X12, ctx->r29);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // j           L_8004C7AC
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    goto L_8004C7AC;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
L_8004C724:
    // lhu         $v0, 0xE($s7)
    ctx->r2 = MEM_HU(0XE, ctx->r23);
    // nop

    // addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // j           L_8004C7B0
    // sh          $v0, 0x16($s2)
    MEM_H(0X16, ctx->r18) = ctx->r2;
    goto L_8004C7B0;
    // sh          $v0, 0x16($s2)
    MEM_H(0X16, ctx->r18) = ctx->r2;
L_8004C738:
    // lh          $v0, 0xE($s7)
    ctx->r2 = MEM_HS(0XE, ctx->r23);
    // lhu         $v1, 0xE($s7)
    ctx->r3 = MEM_HU(0XE, ctx->r23);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8004C760
    if (ctx->r2 == 0) {
        // addu        $v0, $a1, $v1
        ctx->r2 = ADD32(ctx->r5, ctx->r3);
        goto L_8004C760;
    }
    // addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // lhu         $v0, 0x12($sp)
    ctx->r2 = MEM_HU(0X12, ctx->r29);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // j           L_8004C7AC
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    goto L_8004C7AC;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
L_8004C760:
    // j           L_8004C7B0
    // sh          $v0, 0x16($s2)
    MEM_H(0X16, ctx->r18) = ctx->r2;
    goto L_8004C7B0;
    // sh          $v0, 0x16($s2)
    MEM_H(0X16, ctx->r18) = ctx->r2;
L_8004C768:
    // bgez        $a0, L_8004C7A8
    if (SIGNED(ctx->r4) >= 0) {
        // negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
        goto L_8004C7A8;
    }
    // negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // lhu         $v0, 0x30($s2)
    ctx->r2 = MEM_HU(0X30, ctx->r18);
    // nop

    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8004C79C
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8004C79C;
    }
    // nop

    // lhu         $v0, 0x12($sp)
    ctx->r2 = MEM_HU(0X12, ctx->r29);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // j           L_8004C7AC
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    goto L_8004C7AC;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
L_8004C79C:
    // sh          $zero, 0x14($sp)
    MEM_H(0X14, ctx->r29) = 0;
    // j           L_8004C7B0
    // sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
    goto L_8004C7B0;
    // sh          $zero, 0x10($sp)
    MEM_H(0X10, ctx->r29) = 0;
L_8004C7A8:
    // sh          $zero, 0x12($sp)
    MEM_H(0X12, ctx->r29) = 0;
L_8004C7AC:
    // sh          $zero, 0x16($s2)
    MEM_H(0X16, ctx->r18) = 0;
L_8004C7B0:
    // lhu         $v0, 0x10($sp)
    ctx->r2 = MEM_HU(0X10, ctx->r29);
    // nop

    // sh          $v0, 0x9C($s2)
    MEM_H(0X9C, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x12($sp)
    ctx->r2 = MEM_HU(0X12, ctx->r29);
    // nop

    // sh          $v0, 0x9E($s2)
    MEM_H(0X9E, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x14($sp)
    ctx->r2 = MEM_HU(0X14, ctx->r29);
    // nop

    // sh          $v0, 0xA0($s2)
    MEM_H(0XA0, ctx->r18) = ctx->r2;
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
