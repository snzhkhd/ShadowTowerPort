#include "recomp.h"
#include "disable_warnings.h"

void sub_8004FED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sw          $v0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r2;
    // lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(0X28, ctx->r17);
    // lw          $v1, 0x28($s2)
    ctx->r3 = MEM_W(0X28, ctx->r18);
    // addiu       $a0, $a0, 0x2230
    ctx->r4 = ADD32(ctx->r4, 0X2230);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r2;
    // lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(0X2C, ctx->r17);
    // lw          $v1, 0x2C($s2)
    ctx->r3 = MEM_W(0X2C, ctx->r18);
    // subu        $a0, $s2, $a0
    ctx->r4 = SUB32(ctx->r18, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r2;
    // sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4) << 5;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v1, $v0, 15
    ctx->r3 = S32(ctx->r2) << 15;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // lhu         $v0, 0x36($s2)
    ctx->r2 = MEM_HU(0X36, ctx->r18);
    // sra         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) >> 3;
    // sh          $v1, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r3;
    // sh          $v0, 0x36($s1)
    MEM_H(0X36, ctx->r17) = ctx->r2;
    // beq         $s4, $zero, L_8004FF70
    if (ctx->r20 == 0) {
        // addiu       $s0, $s2, 0x34
        ctx->r16 = ADD32(ctx->r18, 0X34);
        /*goto L_8004FF70;*/
        recomp_vram_call(rdram, ctx, 0x8004FF70);
        return;
    }
    // addiu       $s0, $s2, 0x34
    ctx->r16 = ADD32(ctx->r18, 0X34);
    // lhu         $v0, 0x10($s1)
    ctx->r2 = MEM_HU(0X10, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0xCC
    ctx->r2 = ADD32(ctx->r2, 0XCC);
    // sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_8004FF74
    if (ctx->r2 != 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        /*goto L_8004FF74;*/
        recomp_vram_call(rdram, ctx, 0x8004FF74);
        return;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
;}
