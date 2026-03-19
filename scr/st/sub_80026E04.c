#include "recomp.h"
#include "disable_warnings.h"

void sub_80026E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // jal         0x80079A60
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    ST_DrawSync(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // addiu       $s0, $s0, -0x2F70
    ctx->r16 = ADD32(ctx->r16, -0X2F70);
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lbu         $v0, 0x6CC2($v0)
    ctx->r2 = MEM_BU(0X6CC2, ctx->r2);
    // ori         $v1, $zero, 0xD400
    ctx->r3 = 0 | 0XD400;
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lw          $a1, 0x2EC($v0)
    ctx->r5 = MEM_W(0X2EC, ctx->r2);
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // sw          $a1, 0x2F0($v0)
    MEM_W(0X2F0, ctx->r2) = ctx->r5;
    // sw          $a1, 0x2F8($v0)
    MEM_W(0X2F8, ctx->r2) = ctx->r5;
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // jal         0x80079D6C
    // sw          $a1, 0x2FC($v0)
    MEM_W(0X2FC, ctx->r2) = ctx->r5;
    StoreImage(rdram, ctx);
    goto after_1;
    // sw          $a1, 0x2FC($v0)
    MEM_W(0X2FC, ctx->r2) = ctx->r5;
    after_1:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
    // sb          $v0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r2;
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
