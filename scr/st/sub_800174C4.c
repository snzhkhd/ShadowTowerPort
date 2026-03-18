#include "recomp.h"
#include "disable_warnings.h"

void sub_800174C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x1
    ctx->r17 = S32(0X1 << 16);
    // ori         $s1, $s1, 0x8000
    ctx->r17 = ctx->r17 | 0X8000;
    // lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // addiu       $a2, $a2, -0x2F70
    ctx->r6 = ADD32(ctx->r6, -0X2F70);
    // addu        $s1, $a2, $s1
    ctx->r17 = ADD32(ctx->r6, ctx->r17);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lbu         $v0, 0x6CC2($s1)
    ctx->r2 = MEM_BU(0X6CC2, ctx->r17);
    // ori         $s0, $zero, 0x8000
    ctx->r16 = 0 | 0X8000;
    // sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // sb          $v0, 0x6CC2($s1)
    MEM_B(0X6CC2, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x6CC2($s1)
    ctx->r2 = MEM_BU(0X6CC2, ctx->r17);
    // addu        $s0, $a2, $s0
    ctx->r16 = ADD32(ctx->r6, ctx->r16);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, 0x537C
    ctx->r2 = ADD32(ctx->r2, 0X537C);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x304($s0)
    MEM_W(0X304, ctx->r16) = ctx->r3;
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lbu         $a0, 0x6CC2($s1)
    ctx->r4 = MEM_BU(0X6CC2, ctx->r17);
    // addiu       $a2, $a2, 0xE4
    ctx->r6 = ADD32(ctx->r6, 0XE4);
    // sll         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4) << 14;
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // jal         0x80079F4C
    // sw          $a0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->r4;
    ClearOTagR(rdram, ctx);
    goto after_0;
    // sw          $a0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->r4;
    after_0:
    // addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // lbu         $a0, 0x6CC2($s1)
    ctx->r4 = MEM_BU(0X6CC2, ctx->r17);
    // addiu       $v0, $v0, 0x5178
    ctx->r2 = ADD32(ctx->r2, 0X5178);
    // sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) << 8;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // jal         0x80079F4C
    // sw          $a0, 0x2E8($s0)
    MEM_W(0X2E8, ctx->r16) = ctx->r4;
    ClearOTagR(rdram, ctx);
    goto after_1;
    // sw          $a0, 0x2E8($s0)
    MEM_W(0X2E8, ctx->r16) = ctx->r4;
    after_1:
    // sw          $zero, 0x328($s0)
    MEM_W(0X328, ctx->r16) = 0;
    // sw          $zero, 0x324($s0)
    MEM_W(0X324, ctx->r16) = 0;
    // sw          $zero, 0x320($s0)
    MEM_W(0X320, ctx->r16) = 0;
    // sw          $zero, 0x31C($s0)
    MEM_W(0X31C, ctx->r16) = 0;
    // sw          $zero, 0x32C($s0)
    MEM_W(0X32C, ctx->r16) = 0;
    // sw          $zero, 0x330($s0)
    MEM_W(0X330, ctx->r16) = 0;
    // sw          $zero, 0x338($s0)
    MEM_W(0X338, ctx->r16) = 0;
    // sw          $zero, 0x33C($s0)
    MEM_W(0X33C, ctx->r16) = 0;
    // sw          $zero, 0x340($s0)
    MEM_W(0X340, ctx->r16) = 0;
    // sw          $zero, 0x344($s0)
    MEM_W(0X344, ctx->r16) = 0;
    // sw          $zero, 0x348($s0)
    MEM_W(0X348, ctx->r16) = 0;
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
