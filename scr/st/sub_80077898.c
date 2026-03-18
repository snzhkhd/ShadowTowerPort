#include "recomp.h"
#include "disable_warnings.h"

void sub_80077898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // addiu       $s0, $s0, 0x6B08
    ctx->r16 = ADD32(ctx->r16, 0X6B08);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80077928
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80077928;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // jal         0x80077E94
    // nop

    EnterCriticalSection(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7B98($v0)
    ctx->r2 = MEM_W(0X7B98, ctx->r2);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7B9C($a0)
    ctx->r4 = MEM_W(0X7B9C, ctx->r4);
    // lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(0X0, ctx->r2);
    // nop

    // sh          $v1, 0x32($s0)
    MEM_H(0X32, ctx->r16) = ctx->r3;
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7B94($a0)
    ctx->r4 = MEM_W(0X7B94, ctx->r4);
    // sw          $v1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r3;
    // sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // nop

    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7B9C($a0)
    ctx->r4 = MEM_W(0X7B9C, ctx->r4);
    // lui         $v1, 0x7777
    ctx->r3 = S32(0X7777 << 16);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // ori         $v1, $v1, 0x7777
    ctx->r3 = ctx->r3 | 0X7777;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // jal         0x80077E74
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    ResetEntryInt(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    after_1:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
L_80077928:
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
