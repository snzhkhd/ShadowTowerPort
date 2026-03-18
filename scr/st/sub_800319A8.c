#include "recomp.h"
#include "disable_warnings.h"

void sub_800319A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, 0x7F5C
    ctx->r6 = ADD32(ctx->r2, 0X7F5C);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r3);
    // swr         $v1, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7FFC
    ctx->r6 = ADD32(ctx->r2, 0X7FFC);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r3);
    // swr         $v1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r3);
    // lui         $a0, 0x1F80
    ctx->r4 = S32(0X1F80 << 16);
    // ori         $a0, $a0, 0x350
    ctx->r4 = ctx->r4 | 0X350;
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // lui         $a2, 0x1F80
    ctx->r6 = S32(0X1F80 << 16);
    // ori         $a2, $a2, 0x35C
    ctx->r6 = ctx->r6 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
    // sh          $v0, 0x358($s0)
    MEM_H(0X358, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x1E0
    ctx->r2 = ADD32(0, 0X1E0);
    // sh          $v0, 0x35A($s0)
    MEM_H(0X35A, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x35C($s0)
    MEM_H(0X35C, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x1F7
    ctx->r2 = ADD32(0, 0X1F7);
    // sh          $v0, 0x35E($s0)
    MEM_H(0X35E, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sh          $v0, 0x354($s0)
    MEM_H(0X354, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x356($s0)
    MEM_H(0X356, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x161
    ctx->r2 = ADD32(0, 0X161);
    // addiu       $s1, $zero, 0xA8
    ctx->r17 = ADD32(0, 0XA8);
    // sh          $v0, 0x350($s0)
    MEM_H(0X350, ctx->r16) = ctx->r2;
    // sh          $s1, 0x352($s0)
    MEM_H(0X352, ctx->r16) = ctx->r17;
    // jal         0x80028364
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sub_80028364(rdram, ctx);
    goto after_0;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a0, $a0, 0x350
    ctx->r4 = ctx->r4 | 0X350;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // ori         $a2, $a2, 0x35C
    ctx->r6 = ctx->r6 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x388
    ctx->r2 = ADD32(0, 0X388);
    // sh          $v0, 0x358($s0)
    MEM_H(0X358, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x1F8
    ctx->r2 = ADD32(0, 0X1F8);
    // sh          $v0, 0x35E($s0)
    MEM_H(0X35E, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xE8
    ctx->r2 = ADD32(0, 0XE8);
    // sh          $v0, 0x350($s0)
    MEM_H(0X350, ctx->r16) = ctx->r2;
    // sh          $s1, 0x352($s0)
    MEM_H(0X352, ctx->r16) = ctx->r17;
    // jal         0x80028364
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sub_80028364(rdram, ctx);
    goto after_1;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // addiu       $a1, $zero, 0xBC
    ctx->r5 = ADD32(0, 0XBC);
    // addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x1B0($a0)
    ctx->r2 = MEM_HU(0X1B0, ctx->r4);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_2;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_2:
    // addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    // addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    // addiu       $a2, $zero, 0x13F
    ctx->r6 = ADD32(0, 0X13F);
    // jal         0x80029548
    // addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    sub_80029548(rdram, ctx);
    goto after_3;
    // addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    after_3:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
