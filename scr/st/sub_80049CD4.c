#include "recomp.h"
#include "disable_warnings.h"

void sub_80049CD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4) << 16;
    // sra         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) >> 16;
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jal         0x800743F4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rsin(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x800744C4
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    rcos(rdram, ctx);
    goto after_1;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
    // sh          $v1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r3;
    // negu        $v1, $s0
    ctx->r3 = SUB32(0, ctx->r16);
    // sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // sh          $zero, 0x6($s1)
    MEM_H(0X6, ctx->r17) = 0;
    // sh          $v0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r2;
    // sh          $v1, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r3;
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // sh          $s0, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r16;
    // sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
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
