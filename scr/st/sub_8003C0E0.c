#include "recomp.h"
#include "disable_warnings.h"

void sub_8003C0E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x70D8
    ctx->r16 = ADD32(ctx->r16, -0X70D8);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lhu         $a0, 0x3E($s0)
    ctx->r4 = MEM_HU(0X3E, ctx->r16);
    // jal         0x8003F12C
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_8003F12C(rdram, ctx);
    goto after_0;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_0:
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // lhu         $a0, 0x58($s0)
    ctx->r4 = MEM_HU(0X58, ctx->r16);
    // jal         0x8003F12C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_8003F12C(rdram, ctx);
    goto after_1;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // lhu         $a0, 0x40($s0)
    ctx->r4 = MEM_HU(0X40, ctx->r16);
    // jal         0x8003F12C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_8003F12C(rdram, ctx);
    goto after_2;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // lhu         $a0, 0x5A($s0)
    ctx->r4 = MEM_HU(0X5A, ctx->r16);
    // jal         0x8003F12C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_8003F12C(rdram, ctx);
    goto after_3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // lhu         $a0, 0x44($s0)
    ctx->r4 = MEM_HU(0X44, ctx->r16);
    // jal         0x8003EE38
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_8003EE38(rdram, ctx);
    goto after_4;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
    // lhu         $a0, 0x50($s0)
    ctx->r4 = MEM_HU(0X50, ctx->r16);
    // jal         0x8003EE38
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sub_8003EE38(rdram, ctx);
    goto after_5;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // jal         0x8003C054
    // nop

    sub_8003C054(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // jal         0x8003CEDC
    // nop

    sub_8003CEDC(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, -0x4929($v1)
    MEM_B(-0X4929, ctx->r3) = ctx->r2;
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
