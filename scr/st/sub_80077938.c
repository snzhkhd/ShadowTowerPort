#include "recomp.h"
#include "disable_warnings.h"

void sub_80077938(uint8_t* rdram, recomp_context* ctx) {
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

    // bne         $v0, $zero, L_8007799C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007799C;
    }
    // nop

    // jal         0x80077E84
    // addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    HookEntryInt(rdram, ctx);
    goto after_0;
    // addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    after_0:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7B98($a0)
    ctx->r4 = MEM_W(0X7B98, ctx->r4);
    // lhu         $v1, 0x32($s0)
    ctx->r3 = MEM_HU(0X32, ctx->r16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7B9C($v1)
    ctx->r3 = MEM_W(0X7B9C, ctx->r3);
    // lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(0X34, ctx->r16);
    // nop

    // jal         0x80077EA4
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    ExitCriticalSection(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    after_1:
    // j           L_800779A0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_800779A0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8007799C:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800779A0:
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
