#include "recomp.h"
#include "disable_warnings.h"

void sub_800381A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lw          $s2, 0xF1C($v0)
    ctx->r18 = MEM_W(0XF1C, ctx->r2);
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lbu         $v0, 0x8($s2)
    ctx->r2 = MEM_BU(0X8, ctx->r18);
    // nop

    // bne         $v0, $zero, L_800382D4
    if (ctx->r2 != 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_800382D4;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // addiu       $s0, $s1, 0x5948
    ctx->r16 = ADD32(ctx->r17, 0X5948);
    // lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(0X20, ctx->r18);
    // lw          $v1, 0x24($s2)
    ctx->r3 = MEM_W(0X24, ctx->r18);
    // lw          $a0, 0x28($s2)
    ctx->r4 = MEM_W(0X28, ctx->r18);
    // lw          $a1, 0x2C($s2)
    ctx->r5 = MEM_W(0X2C, ctx->r18);
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    // sw          $a0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r4;
    // sw          $a1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r5;
    // sh          $a3, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r7;
    // sh          $t0, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r8;
    // lwl         $v0, 0x43($s2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X43, ctx->r18);
    // lwr         $v0, 0x40($s2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X40, ctx->r18);
    // lwl         $v1, 0x47($s2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X47, ctx->r18);
    // lwr         $v1, 0x44($s2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X44, ctx->r18);
    // swl         $v0, 0x17($s0)
    do_swl(rdram, 0X17, ctx->r16, ctx->r2);
    // swr         $v0, 0x14($s0)
    do_swr(rdram, 0X14, ctx->r16, ctx->r2);
    // swl         $v1, 0x1B($s0)
    do_swl(rdram, 0X1B, ctx->r16, ctx->r3);
    // swr         $v1, 0x18($s0)
    do_swr(rdram, 0X18, ctx->r16, ctx->r3);
    // lh          $v0, 0x40($s2)
    ctx->r2 = MEM_HS(0X40, ctx->r18);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lh          $v0, 0x44($s2)
    ctx->r2 = MEM_HS(0X44, ctx->r18);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a3
    ctx->r7 = lo;
    // jal         0x800746C4
    // addu        $a0, $v1, $a3
    ctx->r4 = ADD32(ctx->r3, ctx->r7);
    SquareRoot0(rdram, ctx);
    goto after_0;
    // addu        $a0, $v1, $a3
    ctx->r4 = ADD32(ctx->r3, ctx->r7);
    after_0:
    // sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
    // lh          $a0, 0x44($s2)
    ctx->r4 = MEM_HS(0X44, ctx->r18);
    // lh          $a1, 0x40($s2)
    ctx->r5 = MEM_HS(0X40, ctx->r18);
    // jal         0x80076EA4
    // nop

    ratan2(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // sh          $v0, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // jal         0x8003BEB4
    // sw          $v0, 0x5948($s1)
    MEM_W(0X5948, ctx->r17) = ctx->r2;
    sub_8003BEB4(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x5948($s1)
    MEM_W(0X5948, ctx->r17) = ctx->r2;
    after_2:
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // sll         $a2, $v0, 7
    ctx->r6 = S32(ctx->r2) << 7;
    // lh          $a0, 0x40($s2)
    ctx->r4 = MEM_HS(0X40, ctx->r18);
    // lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(0X20, ctx->r18);
    // lh          $a1, 0x42($s2)
    ctx->r5 = MEM_HS(0X42, ctx->r18);
    // lw          $v1, 0x24($s2)
    ctx->r3 = MEM_W(0X24, ctx->r18);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lh          $a0, 0x44($s2)
    ctx->r4 = MEM_HS(0X44, ctx->r18);
    // sw          $v0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r2;
    // lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(0X28, ctx->r18);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v1, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r3;
    // lhu         $v1, 0x34($s2)
    ctx->r3 = MEM_HU(0X34, ctx->r18);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // subu        $v1, $v1, $s3
    ctx->r3 = SUB32(ctx->r3, ctx->r19);
    // andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
    // j           L_800382DC
    // sh          $v1, 0x34($s2)
    MEM_H(0X34, ctx->r18) = ctx->r3;
    goto L_800382DC;
    // sh          $v1, 0x34($s2)
    MEM_H(0X34, ctx->r18) = ctx->r3;
L_800382D4:
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sb          $v0, 0x8($s2)
    MEM_B(0X8, ctx->r18) = ctx->r2;
L_800382DC:
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
