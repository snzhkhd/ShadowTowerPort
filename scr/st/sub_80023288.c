#include "recomp.h"
#include "disable_warnings.h"

void sub_80023288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // addiu       $a2, $v0, 0x1030
    ctx->r6 = ADD32(ctx->r2, 0X1030);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // lwl         $a1, 0xB($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XB, ctx->r6);
    // lwr         $a1, 0x8($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X8, ctx->r6);
    // swl         $v1, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r3);
    // swr         $v1, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r3);
    // swl         $a0, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r4);
    // swr         $a0, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r4);
    // swl         $a1, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r5);
    // swr         $a1, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r5);
    // lwl         $v1, 0xF($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0XF, ctx->r6);
    // lwr         $v1, 0xC($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0XC, ctx->r6);
    // nop

    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x1040
    ctx->r6 = ADD32(ctx->r2, 0X1040);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // lwl         $a1, 0xB($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XB, ctx->r6);
    // lwr         $a1, 0x8($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X8, ctx->r6);
    // swl         $v1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r3);
    // swr         $v1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r3);
    // swl         $a0, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r4);
    // swr         $a0, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r4);
    // swl         $a1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r5);
    // swr         $a1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r5);
    // lwl         $v1, 0xF($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0XF, ctx->r6);
    // lwr         $v1, 0xC($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0XC, ctx->r6);
    // nop

    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8001526C
    // addiu       $s1, $sp, 0x10
    ctx->r17 = ADD32(ctx->r29, 0X10);
    sub_8001526C(rdram, ctx);
    goto after_0;
    // addiu       $s1, $sp, 0x10
    ctx->r17 = ADD32(ctx->r29, 0X10);
    after_0:
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a1, $s1, $v0
    ctx->r5 = ADD32(ctx->r17, ctx->r2);
    // addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(0X8, ctx->r16);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // jal         0x800177A0
    // addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    sub_800177A0(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    after_1:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80015250
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    sub_80015250(rdram, ctx);
    goto after_2;
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
