#include "recomp.h"
#include "disable_warnings.h"

void sub_800637C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, -0x7F1C
    ctx->r6 = ADD32(ctx->r2, -0X7F1C);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r3);
    // swr         $v1, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r3);
    // swl         $a0, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r4);
    // swr         $a0, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r4);
    // jal         0x80063638
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    sub_80063638(rdram, ctx);
    goto after_0;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    after_0:
    // addiu       $a0, $zero, 0x5400
    ctx->r4 = ADD32(0, 0X5400);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // addiu       $v1, $zero, 0x230
    ctx->r3 = ADD32(0, 0X230);
    // sh          $v0, 0x2E6($s0)
    MEM_H(0X2E6, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x1EF
    ctx->r2 = ADD32(0, 0X1EF);
    // sh          $v0, 0x2EC($s0)
    MEM_H(0X2EC, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
    // sh          $v0, 0x2EE($s0)
    MEM_H(0X2EE, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x1F1
    ctx->r2 = ADD32(0, 0X1F1);
    // sh          $a1, 0x2E8($s0)
    MEM_H(0X2E8, ctx->r16) = ctx->r5;
    // sh          $v1, 0x2EA($s0)
    MEM_H(0X2EA, ctx->r16) = ctx->r3;
    // sh          $a1, 0x2F0($s0)
    MEM_H(0X2F0, ctx->r16) = ctx->r5;
    // sh          $v1, 0x2F2($s0)
    MEM_H(0X2F2, ctx->r16) = ctx->r3;
    // jal         0x800152D0
    // sh          $v0, 0x2F4($s0)
    MEM_H(0X2F4, ctx->r16) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x2F4($s0)
    MEM_H(0X2F4, ctx->r16) = ctx->r2;
    after_1:
    // addiu       $a0, $zero, 0x90
    ctx->r4 = ADD32(0, 0X90);
    // jal         0x800152D0
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    after_2:
    // lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // addiu       $s3, $s2, -0x7378
    ctx->r19 = ADD32(ctx->r18, -0X7378);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // jal         0x80016030
    // sw          $v0, 0xD08($s1)
    MEM_W(0XD08, ctx->r17) = ctx->r2;
    sub_80016030(rdram, ctx);
    goto after_3;
    // sw          $v0, 0xD08($s1)
    MEM_W(0XD08, ctx->r17) = ctx->r2;
    after_3:
    // lw          $v0, -0x7378($s2)
    ctx->r2 = MEM_W(-0X7378, ctx->r18);
    // addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s3, $v0, $s3
    ctx->r19 = ADD32(ctx->r2, ctx->r19);
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // lw          $a0, 0xD08($s1)
    ctx->r4 = MEM_W(0XD08, ctx->r17);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // jal         0x80014CFC
    // addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    sub_80014CFC(rdram, ctx);
    goto after_4;
    // addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    after_4:
    // addiu       $s3, $s2, -0x7378
    ctx->r19 = ADD32(ctx->r18, -0X7378);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // jal         0x80016030
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_80016030(rdram, ctx);
    goto after_5;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_5:
    // addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    sub_80014CFC(rdram, ctx);
    goto after_6;
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    after_6:
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // ori         $a1, $a1, 0x2EE
    ctx->r5 = ctx->r5 | 0X2EE;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // ori         $a2, $a2, 0x2F2
    ctx->r6 = ctx->r6 | 0X2F2;
    // lw          $v0, -0x7378($s2)
    ctx->r2 = MEM_W(-0X7378, ctx->r18);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s3, $v0, $s3
    ctx->r19 = ADD32(ctx->r2, ctx->r19);
    // jal         0x8003EC5C
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    sub_8003EC5C(rdram, ctx);
    goto after_7;
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    after_7:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lhu         $a0, 0x3E($v0)
    ctx->r4 = MEM_HU(0X3E, ctx->r2);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // sh          $a0, 0xD28($v1)
    MEM_H(0XD28, ctx->r3) = ctx->r4;
    // lhu         $a0, 0x40($v0)
    ctx->r4 = MEM_HU(0X40, ctx->r2);
    // lhu         $a1, 0x58($v0)
    ctx->r5 = MEM_HU(0X58, ctx->r2);
    // lhu         $a2, 0x5A($v0)
    ctx->r6 = MEM_HU(0X5A, ctx->r2);
    // lhu         $a3, 0x44($v0)
    ctx->r7 = MEM_HU(0X44, ctx->r2);
    // lhu         $v0, 0x50($v0)
    ctx->r2 = MEM_HU(0X50, ctx->r2);
    // addiu       $v1, $v1, 0xD28
    ctx->r3 = ADD32(ctx->r3, 0XD28);
    // sh          $a0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r4;
    // sh          $a1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r5;
    // sh          $a2, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r6;
    // sh          $a3, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r7;
    // jal         0x80057A3C
    // sh          $v0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r2;
    sub_80057A3C(rdram, ctx);
    goto after_8;
    // sh          $v0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r2;
    after_8:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
