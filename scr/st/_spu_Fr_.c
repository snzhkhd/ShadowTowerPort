#include "recomp.h"
#include "disable_warnings.h"

void _spu_Fr_(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sh          $a1, 0x1A6($v0)
    MEM_H(0X1A6, ctx->r2) = ctx->r5;
    // jal         0x8006C77C
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    _spu_Fw1ts(rdram, ctx);
    goto after_0;
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    after_0:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x30
    ctx->r2 = ctx->r2 | 0X30;
    // sh          $v0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r2;
    // jal         0x8006C77C
    // sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) << 16;
    _spu_Fw1ts(rdram, ctx);
    goto after_1;
    // sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) << 16;
    after_1:
    // jal         0x8006C754
    // nop

    sub_8006C754(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD44($v0)
    ctx->r2 = MEM_W(0XD44, ctx->r2);
    // nop

    // sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD48($v0)
    ctx->r2 = MEM_W(0XD48, ctx->r2);
    // ori         $s0, $s0, 0x10
    ctx->r16 = ctx->r16 | 0X10;
    // sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD4C($v1)
    ctx->r3 = MEM_W(0XD4C, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0xD90($at)
    MEM_W(0XD90, ctx->r1) = ctx->r2;
    // sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
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
