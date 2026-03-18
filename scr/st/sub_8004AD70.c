#include "recomp.h"
#include "disable_warnings.h"

void sub_8004AD70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(0X2, ctx->r16);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // sb          $a0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r4;
    // sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    // sh          $zero, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = 0;
    // sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x29C8
    ctx->r3 = ADD32(ctx->r3, -0X29C8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x5($v0)
    ctx->r3 = MEM_BU(0X5, ctx->r2);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sb          $v0, 0x22($s0)
    MEM_B(0X22, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xFFF
    ctx->r2 = ADD32(0, 0XFFF);
    // sh          $v0, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = ctx->r2;
    // sb          $v1, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r3;
    // lhu         $v1, 0x68($s0)
    ctx->r3 = MEM_HU(0X68, ctx->r16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sw          $zero, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = 0;
    // bne         $v1, $v0, L_8004AE04
    if (ctx->r3 != ctx->r2) {
        // sb          $a0, 0x23($s0)
        MEM_B(0X23, ctx->r16) = ctx->r4;
        goto L_8004AE04;
    }
    // sb          $a0, 0x23($s0)
    MEM_B(0X23, ctx->r16) = ctx->r4;
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sh          $v0, 0x8E($s0)
    MEM_H(0X8E, ctx->r16) = ctx->r2;
L_8004AE04:
    // addiu       $v0, $zero, 0x37
    ctx->r2 = ADD32(0, 0X37);
    // sb          $v0, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // sh          $zero, 0xA0($s0)
    MEM_H(0XA0, ctx->r16) = 0;
    // sh          $zero, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = 0;
    // sh          $zero, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = 0;
    // sh          $zero, 0xB2($s0)
    MEM_H(0XB2, ctx->r16) = 0;
    // sh          $v0, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r2;
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
