#include "recomp.h"
#include "disable_warnings.h"

void sub_8003F12C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // addiu       $a3, $v0, 0x1CB4
    ctx->r7 = ADD32(ctx->r2, 0X1CB4);
    // lwl         $v1, 0x3($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r7);
    // lwr         $v1, 0x0($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r7);
    // lwl         $a1, 0x7($a3)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X7, ctx->r7);
    // lwr         $a1, 0x4($a3)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X4, ctx->r7);
    // lwl         $a2, 0xB($a3)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0XB, ctx->r7);
    // lwr         $a2, 0x8($a3)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X8, ctx->r7);
    // swl         $v1, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r3);
    // swr         $v1, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r3);
    // swl         $a1, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r5);
    // swr         $a1, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r5);
    // swl         $a2, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r6);
    // swr         $a2, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r6);
    // lwl         $v1, 0xF($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0XF, ctx->r7);
    // lwr         $v1, 0xC($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0XC, ctx->r7);
    // nop

    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a3, $v0, 0x1CC4
    ctx->r7 = ADD32(ctx->r2, 0X1CC4);
    // lwl         $v1, 0x3($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r7);
    // lwr         $v1, 0x0($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r7);
    // lwl         $a1, 0x7($a3)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X7, ctx->r7);
    // lwr         $a1, 0x4($a3)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X4, ctx->r7);
    // lwl         $a2, 0xB($a3)
    ctx->r6 = do_lwl(rdram, ctx->r6, 0XB, ctx->r7);
    // lwr         $a2, 0x8($a3)
    ctx->r6 = do_lwr(rdram, ctx->r6, 0X8, ctx->r7);
    // swl         $v1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r3);
    // swr         $v1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r3);
    // swl         $a1, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r5);
    // swr         $a1, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r5);
    // swl         $a2, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r6);
    // swr         $a2, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r6);
    // lwl         $v1, 0xF($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0XF, ctx->r7);
    // lwr         $v1, 0xC($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0XC, ctx->r7);
    // nop

    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // addu        $s7, $s2, $zero
    ctx->r23 = ADD32(ctx->r18, 0);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $a0, $v0, L_8003F23C
    if (ctx->r4 == ctx->r2) {
        // lui         $fp, 0x1F80
        ctx->r30 = S32(0X1F80 << 16);
        goto L_8003F23C;
    }
    // lui         $fp, 0x1F80
    ctx->r30 = S32(0X1F80 << 16);
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
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x7810
    ctx->r3 = ADD32(ctx->r3, 0X7810);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $s5, 0x4($v0)
    ctx->r21 = MEM_BU(0X4, ctx->r2);
    // j           L_8003F244
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    goto L_8003F244;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8003F23C:
    // addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8003F244:
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // andi        $a0, $s5, 0xFF
    ctx->r4 = ctx->r21 & 0XFF;
    // sb          $v0, 0x187($v1)
    MEM_B(0X187, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sh          $zero, 0x17E($v1)
    MEM_H(0X17E, ctx->r3) = 0;
    // beq         $a0, $v0, L_8003F2C8
    if (ctx->r4 == ctx->r2) {
        // sh          $zero, 0x180($v1)
        MEM_H(0X180, ctx->r3) = 0;
        goto L_8003F2C8;
    }
    // sh          $zero, 0x180($v1)
    MEM_H(0X180, ctx->r3) = 0;
    // andi        $s1, $s6, 0xFF
    ctx->r17 = ctx->r22 & 0XFF;
    // addu        $v0, $s1, $v1
    ctx->r2 = ADD32(ctx->r17, ctx->r3);
    // lbu         $a1, 0x148($v0)
    ctx->r5 = MEM_BU(0X148, ctx->r2);
    // nop

    // bne         $a1, $a0, L_8003F2CC
    if (ctx->r5 != ctx->r4) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003F2CC;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // beq         $v0, $zero, L_8003F2C8
    if (ctx->r2 == 0) {
        // sll         $a1, $a1, 2
        ctx->r5 = S32(ctx->r5) << 2;
        goto L_8003F2C8;
    }
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addiu       $a1, $a1, 0x1E5
    ctx->r5 = ADD32(ctx->r5, 0X1E5);
    // lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // addiu       $s0, $s0, -0x7378
    ctx->r16 = ADD32(ctx->r16, -0X7378);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_0;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17) << 2;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // jal         0x8003EC5C
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_8003EC5C(rdram, ctx);
    goto after_1;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
L_8003F2C8:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8003F2CC:
    // addiu       $a2, $v0, -0x70D8
    ctx->r6 = ADD32(ctx->r2, -0X70D8);
    // andi        $v1, $s6, 0xFF
    ctx->r3 = ctx->r22 & 0XFF;
    // addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // sb          $s5, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r21;
    // addiu       $v0, $s5, -0x1F
    ctx->r2 = ADD32(ctx->r21, -0X1F);
    // sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8003F2F4
    if (ctx->r2 == 0) {
        // andi        $a1, $s5, 0xFF
        ctx->r5 = ctx->r21 & 0XFF;
        goto L_8003F2F4;
    }
    // andi        $a1, $s5, 0xFF
    ctx->r5 = ctx->r21 & 0XFF;
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // addiu       $s7, $s5, 0x1D
    ctx->r23 = ADD32(ctx->r21, 0X1D);
L_8003F2F4:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $a1, $v0, L_8003F464
    if (ctx->r5 == ctx->r2) {
        // sll         $s4, $v1, 2
        ctx->r20 = S32(ctx->r3) << 2;
        goto L_8003F464;
    }
    // sll         $s4, $v1, 2
    ctx->r20 = S32(ctx->r3) << 2;
    // addu        $s3, $s4, $a2
    ctx->r19 = ADD32(ctx->r20, ctx->r6);
    // sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5) << 3;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // addiu       $v1, $v1, 0x5220
    ctx->r3 = ADD32(ctx->r3, 0X5220);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0xE8($s3)
    MEM_W(0XE8, ctx->r19) = ctx->r2;
    // andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // beq         $v0, $zero, L_8003F3BC
    if (ctx->r2 == 0) {
        // xori        $s2, $s6, 0x1
        ctx->r18 = ctx->r22 ^ 0X1;
        goto L_8003F3BC;
    }
    // xori        $s2, $s6, 0x1
    ctx->r18 = ctx->r22 ^ 0X1;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // andi        $s1, $s2, 0xFF
    ctx->r17 = ctx->r18 & 0XFF;
    // sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17) << 2;
    // addu        $s1, $s1, $a2
    ctx->r17 = ADD32(ctx->r17, ctx->r6);
    // andi        $s0, $s7, 0xFF
    ctx->r16 = ctx->r23 & 0XFF;
    // sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16) << 3;
    // subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // sw          $v0, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->r2;
    // lw          $a2, 0xF8($s3)
    ctx->r6 = MEM_W(0XF8, ctx->r19);
    // jal         0x80016030
    // addiu       $a1, $a1, 0x1E4
    ctx->r5 = ADD32(ctx->r5, 0X1E4);
    sub_80016030(rdram, ctx);
    goto after_3;
    // addiu       $a1, $a1, 0x1E4
    ctx->r5 = ADD32(ctx->r5, 0X1E4);
    after_3:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // lw          $a2, 0xF8($s1)
    ctx->r6 = MEM_W(0XF8, ctx->r17);
    // jal         0x80016030
    // addiu       $a1, $s0, 0x1E4
    ctx->r5 = ADD32(ctx->r16, 0X1E4);
    sub_80016030(rdram, ctx);
    goto after_4;
    // addiu       $a1, $s0, 0x1E4
    ctx->r5 = ADD32(ctx->r16, 0X1E4);
    after_4:
    // andi        $a0, $s6, 0xFF
    ctx->r4 = ctx->r22 & 0XFF;
    // lw          $a1, 0xF8($s3)
    ctx->r5 = MEM_W(0XF8, ctx->r19);
    // jal         0x80033A48
    // addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    sub_80033A48(rdram, ctx);
    goto after_5;
    // addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_5:
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // addu        $a2, $a2, $s4
    ctx->r6 = ADD32(ctx->r6, ctx->r20);
    // lw          $a0, 0xC($fp)
    ctx->r4 = MEM_W(0XC, ctx->r30);
    // jal         0x800177A0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_800177A0(rdram, ctx);
    goto after_6;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
    // andi        $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 & 0XFF;
    // lw          $a1, 0xF8($s1)
    ctx->r5 = MEM_W(0XF8, ctx->r17);
    // jal         0x80033A48
    // addiu       $a0, $s2, 0x20
    ctx->r4 = ADD32(ctx->r18, 0X20);
    sub_80033A48(rdram, ctx);
    goto after_7;
    // addiu       $a0, $s2, 0x20
    ctx->r4 = ADD32(ctx->r18, 0X20);
    after_7:
    // j           L_8003F400
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    goto L_8003F400;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8003F3BC:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // lw          $a2, 0xF8($s3)
    ctx->r6 = MEM_W(0XF8, ctx->r19);
    // jal         0x80016030
    // addiu       $a1, $a1, 0x1E4
    ctx->r5 = ADD32(ctx->r5, 0X1E4);
    sub_80016030(rdram, ctx);
    goto after_8;
    // addiu       $a1, $a1, 0x1E4
    ctx->r5 = ADD32(ctx->r5, 0X1E4);
    after_8:
    // andi        $a0, $s6, 0xFF
    ctx->r4 = ctx->r22 & 0XFF;
    // lw          $a1, 0xF8($s3)
    ctx->r5 = MEM_W(0XF8, ctx->r19);
    // jal         0x80033A48
    // addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    sub_80033A48(rdram, ctx);
    goto after_9;
    // addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_9:
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // addu        $a2, $a2, $s4
    ctx->r6 = ADD32(ctx->r6, ctx->r20);
    // lw          $a0, 0xC($fp)
    ctx->r4 = MEM_W(0XC, ctx->r30);
    // jal         0x800177A0
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_800177A0(rdram, ctx);
    goto after_10;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8003F400:
    // sll         $s1, $s5, 2
    ctx->r17 = S32(ctx->r21) << 2;
    // addiu       $a1, $s1, 0x1E5
    ctx->r5 = ADD32(ctx->r17, 0X1E5);
    // lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // addiu       $s0, $s0, -0x7378
    ctx->r16 = ADD32(ctx->r16, -0X7378);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_11;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_11:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // andi        $s0, $s6, 0xFF
    ctx->r16 = ctx->r22 & 0XFF;
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // jal         0x8003EC5C
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_8003EC5C(rdram, ctx);
    goto after_12;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_12:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_13;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_13:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lbu         $a2, 0x1D4($s0)
    ctx->r6 = MEM_BU(0X1D4, ctx->r16);
    // addiu       $a1, $s1, 0x1E6
    ctx->r5 = ADD32(ctx->r17, 0X1E6);
    // jal         0x80058A0C
    // addiu       $a2, $a2, -0x16
    ctx->r6 = ADD32(ctx->r6, -0X16);
    sub_80058A0C(rdram, ctx);
    goto after_14;
    // addiu       $a2, $a2, -0x16
    ctx->r6 = ADD32(ctx->r6, -0X16);
    after_14:
L_8003F464:
    // andi        $a0, $s6, 0xFF
    ctx->r4 = ctx->r22 & 0XFF;
    // sltiu       $v0, $a0, 0x2
    ctx->r2 = ctx->r4 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8003F488
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003F488;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $v0, 0x130($v1)
    MEM_H(0X130, ctx->r3) = ctx->r2;
L_8003F488:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $zero, 0x108($v0)
    MEM_W(0X108, ctx->r2) = 0;
    // sb          $zero, 0x14E($v1)
    MEM_B(0X14E, ctx->r3) = 0;
    // sb          $zero, 0x14F($v1)
    MEM_B(0X14F, ctx->r3) = 0;
    // sh          $zero, 0x2DE($v1)
    MEM_H(0X2DE, ctx->r3) = 0;
    // sh          $zero, 0x2E0($v1)
    MEM_H(0X2E0, ctx->r3) = 0;
    // sh          $zero, 0x2E2($v1)
    MEM_H(0X2E2, ctx->r3) = 0;
    // jal         0x80015AD4
    // sb          $zero, 0x189($v1)
    MEM_B(0X189, ctx->r3) = 0;
    sub_80015AD4(rdram, ctx);
    goto after_15;
    // sb          $zero, 0x189($v1)
    MEM_B(0X189, ctx->r3) = 0;
    after_15:
    // lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(0X54, ctx->r29);
    // lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(0X50, ctx->r29);
    // lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(0X4C, ctx->r29);
    // lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(0X48, ctx->r29);
    // lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(0X44, ctx->r29);
    // lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(0X40, ctx->r29);
    // lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(0X3C, ctx->r29);
    // lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // jr          $ra
    // nop

    return;
    // nop

;}
