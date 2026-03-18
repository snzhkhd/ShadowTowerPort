#include "recomp.h"
#include "disable_warnings.h"

void sub_80078508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // jal         0x80077E94
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    EnterCriticalSection(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addiu       $v1, $v1, -0x66F4
    ctx->r3 = ADD32(ctx->r3, -0X66F4);
    // addiu       $s0, $v1, -0x4
    ctx->r16 = ADD32(ctx->r3, -0X4);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0x7A48
    ctx->r2 = ADD32(ctx->r2, -0X7A48);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0x79E0
    ctx->r2 = ADD32(ctx->r2, -0X79E0);
    // sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $zero, -0x66F8($at)
    MEM_W(-0X66F8, ctx->r1) = 0;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $zero, -0x66EC($at)
    MEM_W(-0X66EC, ctx->r1) = 0;
    // jal         0x800786B4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    SysDeqIntRP(rdram, ctx);
    goto after_1;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // jal         0x800786A4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    SysEnqIntRP(rdram, ctx);
    goto after_2;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // jal         0x80077EA4
    // nop

    ExitCriticalSection(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
