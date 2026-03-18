#include "recomp.h"
#include "disable_warnings.h"

void sub_80038300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $s0, 0xF1C($v0)
    ctx->r16 = MEM_W(0XF1C, ctx->r2);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jal         0x80035D04
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80035D04(rdram, ctx);
    goto after_0;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // lh          $a1, 0x40($s0)
    ctx->r5 = MEM_HS(0X40, ctx->r16);
    // lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(0X20, ctx->r16);
    // lh          $a2, 0x42($s0)
    ctx->r6 = MEM_HS(0X42, ctx->r16);
    // lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(0X24, ctx->r16);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // lh          $a1, 0x44($s0)
    ctx->r5 = MEM_HS(0X44, ctx->r16);
    // sw          $v1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r3;
    // lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(0X28, ctx->r16);
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // sw          $a0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r4;
    // lhu         $a0, 0x34($s0)
    ctx->r4 = MEM_HU(0X34, ctx->r16);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // subu        $a0, $a0, $s1
    ctx->r4 = SUB32(ctx->r4, ctx->r17);
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // sw          $v1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r3;
    // sh          $a0, 0x34($s0)
    MEM_H(0X34, ctx->r16) = ctx->r4;
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
