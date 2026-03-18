#include "recomp.h"
#include "disable_warnings.h"

void InitPAD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // jal         0x80078764
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    _remove_ChgclrPAD(rdram, ctx);
    goto after_0;
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    after_0:
    // jal         0x80077E94
    // nop

    EnterCriticalSection(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x800786EC
    // nop

    _patch_pad(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x80077EA4
    // nop

    ExitCriticalSection(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x80077F24
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ChangeClearPAD(rdram, ctx);
    goto after_4;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // jal         0x80078508
    // nop

    sub_80078508(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // jal         0x80078664
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    InitPAD2(rdram, ctx);
    goto after_6;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_6:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7C40($at)
    MEM_W(0X7C40, ctx->r1) = ctx->r2;
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
