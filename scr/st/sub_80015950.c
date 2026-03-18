#include "recomp.h"
#include "disable_warnings.h"

void sub_80015950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(0X0, ctx->r16);
    // jal         0x800158F4
    // nop

    sub_800158F4(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(0X1, ctx->r16);
    // jal         0x800158F4
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    sub_800158F4(rdram, ctx);
    goto after_1;
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_1:
    // lbu         $a0, 0x2($s0)
    ctx->r4 = MEM_BU(0X2, ctx->r16);
    // jal         0x800158F4
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    sub_800158F4(rdram, ctx);
    goto after_2;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_2:
    // sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17) << 2;
    // addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // sll         $a0, $v1, 4
    ctx->r4 = S32(ctx->r3) << 4;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // sll         $a1, $a0, 4
    ctx->r5 = S32(ctx->r4) << 4;
    // subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16) << 2;
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4) << 4;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
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
