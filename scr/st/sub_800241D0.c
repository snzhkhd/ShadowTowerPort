#include "recomp.h"
#include "disable_warnings.h"

void sub_800241D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // lui         $v1, 0x1F80
    ctx->r3 = S32(0X1F80 << 16);
    // ori         $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 | 0XF8;
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
    // ori         $v0, $v0, 0x244
    ctx->r2 = ctx->r2 | 0X244;
    // lui         $a0, 0x1F80
    ctx->r4 = S32(0X1F80 << 16);
    // ori         $a0, $a0, 0xF8
    ctx->r4 = ctx->r4 | 0XF8;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // lui         $s3, 0x1F80
    ctx->r19 = S32(0X1F80 << 16);
    // sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r30;
    // sw          $s7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r23;
    // sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // sw          $v1, 0xF0($s3)
    MEM_W(0XF0, ctx->r19) = ctx->r3;
    // jal         0x80014D5C
    // sw          $v0, 0xF4($s3)
    MEM_W(0XF4, ctx->r19) = ctx->r2;
    sub_80014D5C(rdram, ctx);
    goto after_0;
    // sw          $v0, 0xF4($s3)
    MEM_W(0XF4, ctx->r19) = ctx->r2;
    after_0:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // ori         $a0, $a0, 0x244
    ctx->r4 = ctx->r4 | 0X244;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    sub_80014D5C(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v1, $v0, -0x5EC8
    ctx->r3 = ADD32(ctx->r2, -0X5EC8);
    // lbu         $s4, 0x6100($v1)
    ctx->r20 = MEM_BU(0X6100, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // beq         $s4, $v0, L_8002468C
    if (ctx->r20 == ctx->r2) {
        // sh          $zero, 0x98($s3)
        MEM_H(0X98, ctx->r19) = 0;
        goto L_8002468C;
    }
    // sh          $zero, 0x98($s3)
    MEM_H(0X98, ctx->r19) = 0;
    // addu        $s6, $v1, $zero
    ctx->r22 = ADD32(ctx->r3, 0);
    // addiu       $fp, $s6, 0x3500
    ctx->r30 = ADD32(ctx->r22, 0X3500);
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // addiu       $s7, $v0, 0x5090
    ctx->r23 = ADD32(ctx->r2, 0X5090);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $s5, $v0, 0x5090
    ctx->r21 = ADD32(ctx->r2, 0X5090);
    // sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20) << 1;
L_80024278:
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // lhu         $v1, 0x6104($v0)
    ctx->r3 = MEM_HU(0X6104, ctx->r2);
    // addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s1, $v0, $s6
    ctx->r17 = ADD32(ctx->r2, ctx->r22);
    // lbu         $a0, 0xB($s1)
    ctx->r4 = MEM_BU(0XB, ctx->r17);
    // lbu         $v1, 0x2($s1)
    ctx->r3 = MEM_BU(0X2, ctx->r17);
    // addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // jal         0x80033DB8
    // addu        $s0, $v0, $fp
    ctx->r16 = ADD32(ctx->r2, ctx->r30);
    sub_80033DB8(rdram, ctx);
    goto after_2;
    // addu        $s0, $v0, $fp
    ctx->r16 = ADD32(ctx->r2, ctx->r30);
    after_2:
    // lbu         $v0, 0x1E($s1)
    ctx->r2 = MEM_BU(0X1E, ctx->r17);
    // sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    // andi        $a0, $v0, 0x3F
    ctx->r4 = ctx->r2 & 0X3F;
    // sb          $a0, 0x1E($s1)
    MEM_B(0X1E, ctx->r17) = ctx->r4;
    // lw          $v0, 0x6E04($s7)
    ctx->r2 = MEM_W(0X6E04, ctx->r23);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x3C($s1)
    ctx->r3 = MEM_W(0X3C, ctx->r17);
    // mflo        $t1
    ctx->r9 = lo;
    // sltu        $v0, $t1, $v1
    ctx->r2 = ctx->r9 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_80024310
    if (ctx->r2 == 0) {
        // ori         $v0, $a0, 0x40
        ctx->r2 = ctx->r4 | 0X40;
        goto L_80024310;
    }
    // ori         $v0, $a0, 0x40
    ctx->r2 = ctx->r4 | 0X40;
    // lw          $v0, 0x6E00($s7)
    ctx->r2 = MEM_W(0X6E00, ctx->r23);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // sltu        $v0, $v1, $t1
    ctx->r2 = ctx->r3 < ctx->r9 ? 1 : 0;
    // bne         $v0, $zero, L_80024314
    if (ctx->r2 != 0) {
        // ori         $v0, $a0, 0x80
        ctx->r2 = ctx->r4 | 0X80;
        goto L_80024314;
    }
    // ori         $v0, $a0, 0x80
    ctx->r2 = ctx->r4 | 0X80;
L_80024310:
    // sb          $v0, 0x1E($s1)
    MEM_B(0X1E, ctx->r17) = ctx->r2;
L_80024314:
    // lw          $v0, 0x1C($s1)
    ctx->r2 = MEM_W(0X1C, ctx->r17);
    // lui         $v1, 0x30
    ctx->r3 = S32(0X30 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_80024334
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80024334;
    }
    // nop

    // lh          $a3, 0x34($s1)
    ctx->r7 = MEM_HS(0X34, ctx->r17);
    // j           L_80024338
    // nop

    goto L_80024338;
    // nop

L_80024334:
    // lh          $a3, 0x36($s1)
    ctx->r7 = MEM_HS(0X36, ctx->r17);
L_80024338:
    // lhu         $v1, 0x10($s0)
    ctx->r3 = MEM_HU(0X10, ctx->r16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_80024374
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80024374;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v0, -0x45F8
    ctx->r2 = ADD32(ctx->r2, -0X45F8);
    // srl         $a0, $a1, 5
    ctx->r4 = S32(U32(ctx->r5) >> 5);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // andi        $a1, $a1, 0x1F
    ctx->r5 = ctx->r5 & 0X1F;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lw          $v1, 0x14A8($a0)
    ctx->r3 = MEM_W(0X14A8, ctx->r4);
    // sllv        $v0, $v0, $a1
    ctx->r2 = S32(ctx->r2) << (ctx->r5 & 31);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x14A8($a0)
    MEM_W(0X14A8, ctx->r4) = ctx->r3;
L_80024374:
    // lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(0X48, ctx->r29);
    // nop

    // beq         $v0, $zero, L_8002461C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8002461C;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(0X70, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_80024448
    if (ctx->r2 == 0) {
        // addiu       $t0, $s1, 0x74
        ctx->r8 = ADD32(ctx->r17, 0X74);
        goto L_80024448;
    }
    // addiu       $t0, $s1, 0x74
    ctx->r8 = ADD32(ctx->r17, 0X74);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // sh          $zero, 0xDC($s3)
    MEM_H(0XDC, ctx->r19) = 0;
    // sh          $zero, 0xDA($s3)
    MEM_H(0XDA, ctx->r19) = 0;
    // sh          $zero, 0xD8($s3)
    MEM_H(0XD8, ctx->r19) = 0;
    // lb          $v0, 0x21($s1)
    ctx->r2 = MEM_BS(0X21, ctx->r17);
    // lw          $v1, 0xE4($s5)
    ctx->r3 = MEM_W(0XE4, ctx->r21);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r3;
    // lb          $v1, 0x21($s1)
    ctx->r3 = MEM_BS(0X21, ctx->r17);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x80($s3)
    MEM_W(0X80, ctx->r19) = ctx->r2;
    // lb          $v0, 0x21($s1)
    ctx->r2 = MEM_BS(0X21, ctx->r17);
    // addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // lbu         $a1, 0xB($s1)
    ctx->r5 = MEM_BU(0XB, ctx->r17);
    // addiu       $v0, $s1, 0x94
    ctx->r2 = ADD32(ctx->r17, 0X94);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $s1, 0xA4
    ctx->r2 = ADD32(ctx->r17, 0XA4);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, 0x40C
    ctx->r2 = ADD32(ctx->r2, 0X40C);
    // subu        $v1, $v1, $a3
    ctx->r3 = SUB32(ctx->r3, ctx->r7);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x8($s1)
    ctx->r2 = MEM_BU(0X8, ctx->r17);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x2A($s1)
    ctx->r2 = MEM_HU(0X2A, ctx->r17);
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lh          $v0, 0x24($s1)
    ctx->r2 = MEM_HS(0X24, ctx->r17);
    // addiu       $a3, $s3, 0xD8
    ctx->r7 = ADD32(ctx->r19, 0XD8);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x1E($s1)
    ctx->r2 = MEM_BU(0X1E, ctx->r17);
    // addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // jal         0x80022678
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    sub_80022678(rdram, ctx);
    goto after_3;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // j           L_80024620
    // nop

    goto L_80024620;
    // nop

L_80024448:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F04
    ctx->r6 = ADD32(ctx->r2, 0X7F04);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x63($sp)
    do_swl(rdram, 0X63, ctx->r29, ctx->r3);
    // swr         $v1, 0x60($sp)
    do_swr(rdram, 0X60, ctx->r29, ctx->r3);
    // swl         $a0, 0x67($sp)
    do_swl(rdram, 0X67, ctx->r29, ctx->r4);
    // swr         $a0, 0x64($sp)
    do_swr(rdram, 0X64, ctx->r29, ctx->r4);
    // lhu         $v1, 0x8C($s1)
    ctx->r3 = MEM_HU(0X8C, ctx->r17);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // sh          $v1, 0xD8($s3)
    MEM_H(0XD8, ctx->r19) = ctx->r3;
    // lhu         $v0, 0x8E($s1)
    ctx->r2 = MEM_HU(0X8E, ctx->r17);
    // nop

    // sh          $v0, 0xDA($s3)
    MEM_H(0XDA, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x90($s1)
    ctx->r2 = MEM_HU(0X90, ctx->r17);
    // nop

    // sh          $v0, 0xDC($s3)
    MEM_H(0XDC, ctx->r19) = ctx->r2;
    // lbu         $v1, 0x3($s1)
    ctx->r3 = MEM_BU(0X3, ctx->r17);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $v0, L_80024544
    if (ctx->r3 == ctx->r2) {
        // addiu       $s0, $sp, 0x60
        ctx->r16 = ADD32(ctx->r29, 0X60);
        goto L_80024544;
    }
    // addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // lb          $v0, 0x21($s1)
    ctx->r2 = MEM_BS(0X21, ctx->r17);
    // lw          $v1, 0xE4($s5)
    ctx->r3 = MEM_W(0XE4, ctx->r21);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r3;
    // lb          $v1, 0x21($s1)
    ctx->r3 = MEM_BS(0X21, ctx->r17);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x80($s3)
    MEM_W(0X80, ctx->r19) = ctx->r2;
    // lb          $v0, 0x21($s1)
    ctx->r2 = MEM_BS(0X21, ctx->r17);
    // addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // lbu         $a1, 0xB($s1)
    ctx->r5 = MEM_BU(0XB, ctx->r17);
    // addiu       $v0, $s1, 0x94
    ctx->r2 = ADD32(ctx->r17, 0X94);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $s1, 0xA4
    ctx->r2 = ADD32(ctx->r17, 0XA4);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x4288
    ctx->r2 = ADD32(ctx->r2, -0X4288);
    // subu        $v1, $v1, $a3
    ctx->r3 = SUB32(ctx->r3, ctx->r7);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x8($s1)
    ctx->r2 = MEM_BU(0X8, ctx->r17);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x2A($s1)
    ctx->r2 = MEM_HU(0X2A, ctx->r17);
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lh          $v0, 0x24($s1)
    ctx->r2 = MEM_HS(0X24, ctx->r17);
    // addiu       $a3, $s3, 0xD8
    ctx->r7 = ADD32(ctx->r19, 0XD8);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x1E($s1)
    ctx->r2 = MEM_BU(0X1E, ctx->r17);
    // addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // jal         0x80022678
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    sub_80022678(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_4:
L_80024544:
    // lhu         $v0, 0x32($s1)
    ctx->r2 = MEM_HU(0X32, ctx->r17);
    // nop

    // beq         $v0, $zero, L_80024620
    if (ctx->r2 == 0) {
        // addiu       $a2, $sp, 0x50
        ctx->r6 = ADD32(ctx->r29, 0X50);
        goto L_80024620;
    }
    // addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // lw          $v0, 0x74($s1)
    ctx->r2 = MEM_W(0X74, ctx->r17);
    // lw          $v1, 0x78($s1)
    ctx->r3 = MEM_W(0X78, ctx->r17);
    // lw          $a0, 0x7C($s1)
    ctx->r4 = MEM_W(0X7C, ctx->r17);
    // lw          $a1, 0x80($s1)
    ctx->r5 = MEM_W(0X80, ctx->r17);
    // sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // lhu         $v0, 0x32($s1)
    ctx->r2 = MEM_HU(0X32, ctx->r17);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // sh          $v0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x32($s1)
    ctx->r2 = MEM_HU(0X32, ctx->r17);
    // addiu       $a3, $s3, 0xD8
    ctx->r7 = ADD32(ctx->r19, 0XD8);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // sh          $v0, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r2;
    // lb          $v1, 0x21($s1)
    ctx->r3 = MEM_BS(0X21, ctx->r17);
    // lw          $v0, 0xE4($s5)
    ctx->r2 = MEM_W(0XE4, ctx->r21);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // lb          $v1, 0x21($s1)
    ctx->r3 = MEM_BS(0X21, ctx->r17);
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x80($s3)
    MEM_W(0X80, ctx->r19) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lb          $v1, 0x21($s1)
    ctx->r3 = MEM_BS(0X21, ctx->r17);
    // addiu       $v0, $v0, -0x4288
    ctx->r2 = ADD32(ctx->r2, -0X4288);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1004
    ctx->r2 = ADD32(0, 0X1004);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x80022678
    // sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    sub_80022678(rdram, ctx);
    goto after_5;
    // sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    after_5:
    // j           L_80024620
    // nop

    goto L_80024620;
    // nop

L_8002461C:
    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
L_80024620:
    // lb          $v0, 0x22($s1)
    ctx->r2 = MEM_BS(0X22, ctx->r17);
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // beq         $v0, $s2, L_8002465C
    if (ctx->r2 == ctx->r18) {
        // lui         $s0, 0x801E
        ctx->r16 = S32(0X801E << 16);
        goto L_8002465C;
    }
    // lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // addiu       $s0, $s0, -0x2408
    ctx->r16 = ADD32(ctx->r16, -0X2408);
    // jal         0x8006BC18
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    SpuGetAllKeysStatus(rdram, ctx);
    goto after_6;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // lb          $v0, 0x22($s1)
    ctx->r2 = MEM_BS(0X22, ctx->r17);
    // addiu       $s0, $s0, -0xA38
    ctx->r16 = ADD32(ctx->r16, -0XA38);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lbu         $v0, 0xA38($v0)
    ctx->r2 = MEM_BU(0XA38, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002465C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002465C;
    }
    // nop

    // sb          $s2, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r18;
L_8002465C:
    // addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // lbu         $v1, 0xB($s1)
    ctx->r3 = MEM_BU(0XB, ctx->r17);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // addu        $v1, $s3, $v1
    ctx->r3 = ADD32(ctx->r19, ctx->r3);
    // sb          $v0, 0xF8($v1)
    MEM_B(0XF8, ctx->r3) = ctx->r2;
    // lbu         $v0, 0xB($s1)
    ctx->r2 = MEM_BU(0XB, ctx->r17);
    // lbu         $v1, 0xC($s1)
    ctx->r3 = MEM_BU(0XC, ctx->r17);
    // addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // sb          $v1, 0xC8($v0)
    MEM_B(0XC8, ctx->r2) = ctx->r3;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s4, $v0, L_80024278
    if (ctx->r20 != ctx->r2) {
        // sll         $v0, $s4, 1
        ctx->r2 = S32(ctx->r20) << 1;
        goto L_80024278;
    }
    // sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20) << 1;
L_8002468C:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v0, 0x593F($v0)
    ctx->r2 = MEM_BU(0X593F, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800246B0
    if (ctx->r2 != 0) {
        // addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
        goto L_800246B0;
    }
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // jal         0x80023C6C
    // addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    sub_80023C6C(rdram, ctx);
    goto after_7;
    // addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_7:
L_800246B0:
    // lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(0X8C, ctx->r29);
    // lw          $fp, 0x88($sp)
    ctx->r30 = MEM_W(0X88, ctx->r29);
    // lw          $s7, 0x84($sp)
    ctx->r23 = MEM_W(0X84, ctx->r29);
    // lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(0X80, ctx->r29);
    // lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(0X7C, ctx->r29);
    // lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(0X78, ctx->r29);
    // lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(0X74, ctx->r29);
    // lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(0X70, ctx->r29);
    // lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(0X6C, ctx->r29);
    // lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(0X68, ctx->r29);
    // addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // jr          $ra
    // nop

    return;
    // nop

;}
