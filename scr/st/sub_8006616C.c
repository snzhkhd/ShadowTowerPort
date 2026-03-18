#include "recomp.h"
#include "disable_warnings.h"

void sub_8006616C(uint8_t* rdram, recomp_context* ctx) {
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
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $v0, $v0, -0x7E00
    ctx->r2 = ADD32(ctx->r2, -0X7E00);
    // lw          $v1, 0x9D8($v0)
    ctx->r3 = MEM_W(0X9D8, ctx->r2);
    // lw          $v0, 0x9D4($v0)
    ctx->r2 = MEM_W(0X9D4, ctx->r2);
    // nop

    // bne         $v1, $v0, L_800661A8
    if (ctx->r3 != ctx->r2) {
        // addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
        goto L_800661A8;
    }
    // addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_800661A8:
    // jal         0x80077EA4
    // nop

    ExitCriticalSection(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
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
