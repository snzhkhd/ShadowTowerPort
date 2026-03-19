#include "recomp.h"
#include "disable_warnings.h"

void sub_8005F38C(uint8_t* rdram, recomp_context* ctx) {
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
    // addiu       $a2, $v0, -0x7F44
    ctx->r6 = ADD32(ctx->r2, -0X7F44);
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
    // addiu       $a0, $zero, 0x5400
    ctx->r4 = ADD32(0, 0X5400);
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
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
    goto after_0;
    // sh          $v0, 0x2F4($s0)
    MEM_H(0X2F4, ctx->r16) = ctx->r2;
    after_0:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $zero, 0x380
    ctx->r5 = ADD32(0, 0X380);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80079DCC
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    MoveImage(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    after_1:
    // jal         0x80015AD4
    // lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_2;
    // lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    after_2:
    // addiu       $s3, $s1, -0x7378
    ctx->r19 = ADD32(ctx->r17, -0X7378);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80016030
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_80016030(rdram, ctx);
    goto after_3;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_3:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // addiu       $s2, $s3, 0x4
    ctx->r18 = ADD32(ctx->r19, 0X4);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    sub_80014CFC(rdram, ctx);
    goto after_4;
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    after_4:
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // ori         $a1, $a1, 0x2E6
    ctx->r5 = ctx->r5 | 0X2E6;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // ori         $a2, $a2, 0x2EA
    ctx->r6 = ctx->r6 | 0X2EA;
    // lw          $v0, -0x7378($s1)
    ctx->r2 = MEM_W(-0X7378, ctx->r17);
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
    goto after_5;
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    after_5:
    // addiu       $s3, $s1, -0x7378
    ctx->r19 = ADD32(ctx->r17, -0X7378);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // jal         0x80016030
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_80016030(rdram, ctx);
    goto after_6;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_6:
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    sub_80014CFC(rdram, ctx);
    goto after_7;
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    after_7:
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // ori         $a1, $a1, 0x2EE
    ctx->r5 = ctx->r5 | 0X2EE;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // ori         $a2, $a2, 0x2F2
    ctx->r6 = ctx->r6 | 0X2F2;
    // lw          $v0, -0x7378($s1)
    ctx->r2 = MEM_W(-0X7378, ctx->r17);
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
    goto after_8;
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    after_8:
    // jal         0x80058C04
    // nop

    PadChkVsync(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_10;
    // nop

    after_10:
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
