#include "recomp.h"
#include "disable_warnings.h"

void sub_8003E874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x8003CAE4
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_8003CAE4(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x70D8
    ctx->r16 = ADD32(ctx->r16, -0X70D8);
    // addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // sw          $v0, 0x244($s0)
    MEM_W(0X244, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // sh          $zero, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = 0;
    // sh          $zero, 0x2DA($s0)
    MEM_H(0X2DA, ctx->r16) = 0;
    // sh          $zero, 0x2D8($s0)
    MEM_H(0X2D8, ctx->r16) = 0;
    // sh          $zero, 0x2D6($s0)
    MEM_H(0X2D6, ctx->r16) = 0;
    // sb          $v0, 0x186($s0)
    MEM_B(0X186, ctx->r16) = ctx->r2;
    // sb          $zero, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = 0;
    // sb          $zero, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = 0;
    // sb          $zero, 0x21E($s0)
    MEM_B(0X21E, ctx->r16) = 0;
    // sb          $zero, 0x21B($s0)
    MEM_B(0X21B, ctx->r16) = 0;
    // sb          $zero, 0x21A($s0)
    MEM_B(0X21A, ctx->r16) = 0;
    // sb          $zero, 0x219($s0)
    MEM_B(0X219, ctx->r16) = 0;
    // sw          $zero, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = 0;
    // jal         0x8003EE38
    // sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
    sub_8003EE38(rdram, ctx);
    goto after_1;
    // sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
    after_1:
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // jal         0x8003EE38
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sub_8003EE38(rdram, ctx);
    goto after_2;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // sw          $zero, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = 0;
    // sw          $zero, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = 0;
    // sw          $zero, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = 0;
    // jal         0x8003F12C
    // sw          $zero, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = 0;
    sub_8003F12C(rdram, ctx);
    goto after_3;
    // sw          $zero, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = 0;
    after_3:
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // jal         0x8003F12C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_8003F12C(rdram, ctx);
    goto after_4;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_4:
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // jal         0x8003F12C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_8003F12C(rdram, ctx);
    goto after_5;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_5:
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // jal         0x8003F12C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_8003F12C(rdram, ctx);
    goto after_6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // sb          $v0, 0x1D4($s0)
    MEM_B(0X1D4, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // sb          $v0, 0x1D5($s0)
    MEM_B(0X1D5, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
    // sb          $v0, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    // sb          $v0, 0x1D7($s0)
    MEM_B(0X1D7, ctx->r16) = ctx->r2;
    // jal         0x8003F12C
    // sh          $zero, 0x3E($s0)
    MEM_H(0X3E, ctx->r16) = 0;
    sub_8003F12C(rdram, ctx);
    goto after_7;
    // sh          $zero, 0x3E($s0)
    MEM_H(0X3E, ctx->r16) = 0;
    after_7:
    // jal         0x80055990
    // addiu       $s1, $zero, 0xC00
    ctx->r17 = ADD32(0, 0XC00);
    sub_80055990(rdram, ctx);
    goto after_8;
    // addiu       $s1, $zero, 0xC00
    ctx->r17 = ADD32(0, 0XC00);
    after_8:
    // sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    // sb          $zero, 0x33($s0)
    MEM_B(0X33, ctx->r16) = 0;
    // sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // jal         0x8003CEDC
    // sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
    sub_8003CEDC(rdram, ctx);
    goto after_9;
    // sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
    after_9:
    // lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    // ori         $a0, $a0, 0xD000
    ctx->r4 = ctx->r4 | 0XD000;
    // lui         $v1, 0x4
    ctx->r3 = S32(0X4 << 16);
    // ori         $v1, $v1, 0x5C0
    ctx->r3 = ctx->r3 | 0X5C0;
    // lui         $v0, 0x3
    ctx->r2 = S32(0X3 << 16);
    // ori         $v0, $v0, 0xF000
    ctx->r2 = ctx->r2 | 0XF000;
    // sh          $zero, 0x278($s0)
    MEM_H(0X278, ctx->r16) = 0;
    // sh          $s1, 0x27A($s0)
    MEM_H(0X27A, ctx->r16) = ctx->r17;
    // sh          $zero, 0x27C($s0)
    MEM_H(0X27C, ctx->r16) = 0;
    // sw          $a0, 0x248($s0)
    MEM_W(0X248, ctx->r16) = ctx->r4;
    // sw          $v1, 0x24C($s0)
    MEM_W(0X24C, ctx->r16) = ctx->r3;
    // sw          $v0, 0x250($s0)
    MEM_W(0X250, ctx->r16) = ctx->r2;
    // sh          $zero, 0x1D0($s0)
    MEM_H(0X1D0, ctx->r16) = 0;
    // sh          $zero, 0x1CE($s0)
    MEM_H(0X1CE, ctx->r16) = 0;
    // jal         0x8003E794
    // sh          $zero, 0x1CC($s0)
    MEM_H(0X1CC, ctx->r16) = 0;
    sub_8003E794(rdram, ctx);
    goto after_10;
    // sh          $zero, 0x1CC($s0)
    MEM_H(0X1CC, ctx->r16) = 0;
    after_10:
    // jal         0x800595D4
    // nop

    sub_800595D4(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // addiu       $v0, $zero, 0x3D
    ctx->r2 = ADD32(0, 0X3D);
    // sb          $v0, 0x22D($s0)
    MEM_B(0X22D, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sb          $v0, 0x22E($s0)
    MEM_B(0X22E, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x3F
    ctx->r2 = ADD32(0, 0X3F);
    // sb          $v0, 0x22F($s0)
    MEM_B(0X22F, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x5C0
    ctx->r2 = ADD32(0, 0X5C0);
    // sb          $zero, 0x22C($s0)
    MEM_B(0X22C, ctx->r16) = 0;
    // sh          $zero, 0x230($s0)
    MEM_H(0X230, ctx->r16) = 0;
    // sh          $v0, 0x232($s0)
    MEM_H(0X232, ctx->r16) = ctx->r2;
    // sh          $zero, 0x234($s0)
    MEM_H(0X234, ctx->r16) = 0;
    // jal         0x8003E840
    // sh          $s1, 0x236($s0)
    MEM_H(0X236, ctx->r16) = ctx->r17;
    sub_8003E840(rdram, ctx);
    goto after_12;
    // sh          $s1, 0x236($s0)
    MEM_H(0X236, ctx->r16) = ctx->r17;
    after_12:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
