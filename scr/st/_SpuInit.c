#include "recomp.h"
#include "disable_warnings.h"

void _SpuInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // jal         0x80077314
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    ResetCallback(rdram, ctx);
    goto after_0;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // jal         0x8006BCA4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    _spu_init(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // bne         $s0, $zero, L_8006C824
    if (ctx->r16 != 0) {
        // ori         $a0, $zero, 0xC000
        ctx->r4 = 0 | 0XC000;
        goto L_8006C824;
    }
    // ori         $a0, $zero, 0xC000
    ctx->r4 = 0 | 0XC000;
    // addiu       $v1, $zero, 0x17
    ctx->r3 = ADD32(0, 0X17);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, 0xE0A
    ctx->r2 = ADD32(ctx->r2, 0XE0A);
L_8006C814:
    // sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bgez        $v1, L_8006C814
    if (SIGNED(ctx->r3) >= 0) {
        // addiu       $v0, $v0, -0x2
        ctx->r2 = ADD32(ctx->r2, -0X2);
        goto L_8006C814;
    }
    // addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_8006C824:
    // jal         0x8006C8CC
    // nop

    SpuStart(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // addiu       $a0, $zero, 0xD1
    ctx->r4 = ADD32(0, 0XD1);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, 0xDC4
    ctx->r2 = ADD32(ctx->r2, 0XDC4);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0xE30($a1)
    ctx->r5 = MEM_W(0XE30, ctx->r5);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xDB4($at)
    MEM_W(0XDB4, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xDB8($at)
    MEM_W(0XDB8, ctx->r1) = 0;
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $a1, 0xDBC($at)
    MEM_W(0XDBC, ctx->r1) = ctx->r5;
    // jal         0x8006C5B0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    _spu_FsetRXX(rdram, ctx);
    goto after_3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xE20($at)
    MEM_W(0XE20, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xE24($at)
    MEM_W(0XE24, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xE28($at)
    MEM_W(0XE28, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xDB0($at)
    MEM_W(0XDB0, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xD5C($at)
    MEM_W(0XD5C, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xDAC($at)
    MEM_W(0XDAC, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xDD8($at)
    MEM_W(0XDD8, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xDD4($at)
    MEM_W(0XDD4, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xE0C($at)
    MEM_W(0XE0C, ctx->r1) = 0;
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
