#include "recomp.h"
#include "disable_warnings.h"

void SpuWritePartly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // lui         $v0, 0x7
    ctx->r2 = S32(0X7 << 16);
    // ori         $v0, $v0, 0xEFF0
    ctx->r2 = ctx->r2 | 0XEFF0;
    // sltu        $v0, $v0, $s1
    ctx->r2 = ctx->r2 < ctx->r17 ? 1 : 0;
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // beq         $v0, $zero, L_800742B0
    if (ctx->r2 == 0) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_800742B0;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s1, 0x7
    ctx->r17 = S32(0X7 << 16);
    // ori         $s1, $s1, 0xEFF0
    ctx->r17 = ctx->r17 | 0XEFF0;
L_800742B0:
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // lhu         $s0, 0xD58($s0)
    ctx->r16 = MEM_HU(0XD58, ctx->r16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD68($v0)
    ctx->r2 = MEM_W(0XD68, ctx->r2);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x8006C4C8
    // sllv        $s0, $s0, $v0
    ctx->r16 = S32(ctx->r16) << (ctx->r2 & 31);
    _spu_Fw(rdram, ctx);
    goto after_0;
    // sllv        $s0, $s0, $v0
    ctx->r16 = S32(ctx->r16) << (ctx->r2 & 31);
    after_0:
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // jal         0x8006C5F4
    // addu        $a1, $s0, $s1
    ctx->r5 = ADD32(ctx->r16, ctx->r17);
    _spu_FsetRXXa(rdram, ctx);
    goto after_1;
    // addu        $a1, $s0, $s1
    ctx->r5 = ADD32(ctx->r16, ctx->r17);
    after_1:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD78($v1)
    ctx->r3 = MEM_W(0XD78, ctx->r3);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v0, 0xD58($at)
    MEM_H(0XD58, ctx->r1) = ctx->r2;
    // bne         $v1, $zero, L_800742F8
    if (ctx->r3 != 0) {
        // addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
        goto L_800742F8;
    }
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xD74($at)
    MEM_W(0XD74, ctx->r1) = 0;
L_800742F8:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
