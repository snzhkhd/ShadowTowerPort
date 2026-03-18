#include "recomp.h"
#include "disable_warnings.h"

void sub_8005AA80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // sw          $ra, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r31;
    // sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, -0x7F54
    ctx->r6 = ADD32(ctx->r2, -0X7F54);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r3);
    // swr         $v1, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r3);
    // swl         $a0, 0x47($sp)
    do_swl(rdram, 0X47, ctx->r29, ctx->r4);
    // swr         $a0, 0x44($sp)
    do_swr(rdram, 0X44, ctx->r29, ctx->r4);
    // addiu       $s4, $zero, 0xF
    ctx->r20 = ADD32(0, 0XF);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $s0, $v0, -0x2F70
    ctx->r16 = ADD32(ctx->r2, -0X2F70);
    // lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // addiu       $s3, $v0, 0x5090
    ctx->r19 = ADD32(ctx->r2, 0X5090);
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // addiu       $s5, $sp, 0x48
    ctx->r21 = ADD32(ctx->r29, 0X48);
    // lui         $s1, 0xFF
    ctx->r17 = S32(0XFF << 16);
    // ori         $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 | 0XFFFF;
    // addiu       $s6, $sp, 0x30
    ctx->r22 = ADD32(ctx->r29, 0X30);
    // and         $s7, $s6, $s1
    ctx->r23 = ctx->r22 & ctx->r17;
L_8005AAFC:
    // lbu         $v0, 0x6CC2($s3)
    ctx->r2 = MEM_BU(0X6CC2, ctx->r19);
    // sb          $zero, 0x18($s0)
    MEM_B(0X18, ctx->r16) = 0;
    // sb          $zero, 0x74($s0)
    MEM_B(0X74, ctx->r16) = 0;
    // sb          $s2, 0x73($s0)
    MEM_B(0X73, ctx->r16) = ctx->r18;
    // sb          $s2, 0x17($s0)
    MEM_B(0X17, ctx->r16) = ctx->r18;
    // sb          $zero, 0x74($s0)
    MEM_B(0X74, ctx->r16) = 0;
    // sb          $zero, 0x18($s0)
    MEM_B(0X18, ctx->r16) = 0;
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // jal         0x8007A0C4
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    PutDrawEnv(rdram, ctx);
    goto after_0;
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    after_0:
    // lbu         $v0, 0x6CC2($s3)
    ctx->r2 = MEM_BU(0X6CC2, ctx->r19);
    // addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // subu        $v0, $s2, $v0
    ctx->r2 = SUB32(ctx->r18, ctx->r2);
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // jal         0x8007A0C4
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    PutDrawEnv(rdram, ctx);
    goto after_1;
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    after_1:
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // jal         0x80079F4C
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ClearOTagR(rdram, ctx);
    goto after_2;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // lui         $v0, 0x500
    ctx->r2 = S32(0X500 << 16);
    // lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(0X48, ctx->r29);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // sh          $zero, 0x22($sp)
    MEM_H(0X22, ctx->r29) = 0;
    // lbu         $v1, 0x6CC2($s3)
    ctx->r3 = MEM_BU(0X6CC2, ctx->r19);
    // and         $a2, $a2, $s1
    ctx->r6 = ctx->r6 & ctx->r17;
    // or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // subu        $v1, $s2, $v1
    ctx->r3 = SUB32(ctx->r18, ctx->r3);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(0X4, ctx->r2);
    // lbu         $v1, 0x6CC2($s3)
    ctx->r3 = MEM_BU(0X6CC2, ctx->r19);
    // addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    // sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
    // sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    // subu        $v1, $s2, $v1
    ctx->r3 = SUB32(ctx->r18, ctx->r3);
    // sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lbu         $v1, 0x6CC2($s3)
    ctx->r3 = MEM_BU(0X6CC2, ctx->r19);
    // lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(0X6, ctx->r2);
    // subu        $v1, $s2, $v1
    ctx->r3 = SUB32(ctx->r18, ctx->r3);
    // sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // addiu       $v1, $sp, 0x18
    ctx->r3 = ADD32(ctx->r29, 0X18);
    // lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(0X4, ctx->r2);
    // lbu         $t0, 0x6CC2($s3)
    ctx->r8 = MEM_BU(0X6CC2, ctx->r19);
    // and         $v1, $v1, $s1
    ctx->r3 = ctx->r3 & ctx->r17;
    // sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // subu        $t0, $s2, $t0
    ctx->r8 = SUB32(ctx->r18, ctx->r8);
    // sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8) << 1;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lhu         $v1, 0x6($v0)
    ctx->r3 = MEM_HU(0X6, ctx->r2);
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sb          $v0, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r2;
    // sb          $v0, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = ctx->r2;
    // sb          $v0, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r2;
    // jal         0x8007C704
    // sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    GetTPage(rdram, ctx);
    goto after_3;
    // sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    after_3:
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    // jal         0x8007A934
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sub_8007A934(rdram, ctx);
    goto after_4;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $a2, 0xFF00
    ctx->r6 = S32(0XFF00 << 16);
    // lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(0X30, ctx->r29);
    // lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(0X48, ctx->r29);
    // and         $a1, $a1, $a2
    ctx->r5 = ctx->r5 & ctx->r6;
    // and         $v0, $v1, $s1
    ctx->r2 = ctx->r3 & ctx->r17;
    // or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // and         $v1, $v1, $a2
    ctx->r3 = ctx->r3 & ctx->r6;
    // or          $v1, $v1, $s7
    ctx->r3 = ctx->r3 | ctx->r23;
    // sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // jal         0x80077104
    // sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    VSync(rdram, ctx);
    goto after_5;
    // sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_5:
    // jal         0x8007A054
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    DrawOTag(rdram, ctx);
    goto after_6;
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_6:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s4, $v0, L_8005AAFC
    if (ctx->r20 != ctx->r2) {
        // lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
        goto L_8005AAFC;
    }
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $v1, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r3;
    // sb          $v1, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r3;
    // lw          $ra, 0x70($sp)
    ctx->r31 = MEM_W(0X70, ctx->r29);
    // lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(0X6C, ctx->r29);
    // lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(0X68, ctx->r29);
    // lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(0X64, ctx->r29);
    // lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(0X60, ctx->r29);
    // lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(0X5C, ctx->r29);
    // lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(0X58, ctx->r29);
    // lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(0X54, ctx->r29);
    // lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(0X50, ctx->r29);
    // addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // jr          $ra
    // nop

    return;
    // nop

;}
