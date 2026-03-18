#include "recomp.h"
#include "disable_warnings.h"

void sub_8007D040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // jal         0x80077E94
    // sw          $zero, 0x7E50($at)
    MEM_W(0X7E50, ctx->r1) = 0;
    EnterCriticalSection(rdram, ctx);
    goto after_0;
    // sw          $zero, 0x7E50($at)
    MEM_W(0X7E50, ctx->r1) = 0;
    after_0:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // lui         $s0, 0x801F
    ctx->r16 = S32(0X801F << 16);
    // addiu       $s0, $s0, -0x4D48
    ctx->r16 = ADD32(ctx->r16, -0X4D48);
    // jal         0x800786B4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    SysDeqIntRP(rdram, ctx);
    goto after_1;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // jal         0x800786A4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    SysEnqIntRP(rdram, ctx);
    goto after_2;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E78($v1)
    ctx->r3 = MEM_W(0X7E78, ctx->r3);
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // jal         0x80077F34
    // sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    ChangeClearRCnt(rdram, ctx);
    goto after_3;
    // sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    after_3:
    // jal         0x80077EA4
    // nop

    ExitCriticalSection(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7E4C($a0)
    ctx->r4 = MEM_W(0X7E4C, ctx->r4);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E1C($v0)
    ctx->r2 = MEM_W(0X7E1C, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7E4C($a0)
    ctx->r4 = MEM_W(0X7E4C, ctx->r4);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E1C($v0)
    ctx->r2 = MEM_W(0X7E1C, ctx->r2);
    // nop

    // jalr        $v0
    // addiu       $a0, $a0, 0xF0
    ctx->r4 = ADD32(ctx->r4, 0XF0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_6;
    // addiu       $a0, $a0, 0xF0
    ctx->r4 = ADD32(ctx->r4, 0XF0);
    after_6:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addiu       $v0, $v0, -0x4D38
    ctx->r2 = ADD32(ctx->r2, -0X4D38);
    // sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7E50($at)
    MEM_W(0X7E50, ctx->r1) = ctx->r2;
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
