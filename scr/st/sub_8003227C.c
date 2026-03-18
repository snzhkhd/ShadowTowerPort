#include "recomp.h"
#include "disable_warnings.h"

void sub_8003227C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sll         $s0, $a2, 16
    ctx->r16 = S32(ctx->r6) << 16;
    // sra         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) >> 16;
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // lbu         $a0, 0x64($s1)
    ctx->r4 = MEM_BU(0X64, ctx->r17);
    // lbu         $a1, 0x28($s2)
    ctx->r5 = MEM_BU(0X28, ctx->r18);
    // jal         0x8004A830
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_8004A830(rdram, ctx);
    goto after_0;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // lbu         $a0, 0x65($s1)
    ctx->r4 = MEM_BU(0X65, ctx->r17);
    // sb          $v0, 0x64($s1)
    MEM_B(0X64, ctx->r17) = ctx->r2;
    // lbu         $a1, 0x29($s2)
    ctx->r5 = MEM_BU(0X29, ctx->r18);
    // jal         0x8004A830
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_8004A830(rdram, ctx);
    goto after_1;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // lbu         $a0, 0x66($s1)
    ctx->r4 = MEM_BU(0X66, ctx->r17);
    // sb          $v0, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r2;
    // lbu         $a1, 0x2A($s2)
    ctx->r5 = MEM_BU(0X2A, ctx->r18);
    // jal         0x8004A830
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_8004A830(rdram, ctx);
    goto after_2;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // sb          $v0, 0x66($s1)
    MEM_B(0X66, ctx->r17) = ctx->r2;
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
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
