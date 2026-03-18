#include "recomp.h"
#include "disable_warnings.h"

void SetGraphDebug(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0x7CC2
    ctx->r3 = ADD32(ctx->r3, 0X7CC2);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lbu         $s0, 0x0($v1)
    ctx->r16 = MEM_BU(0X0, ctx->r3);
    // sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // beq         $a0, $zero, L_800798A4
    if (ctx->r4 == 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_800798A4;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7CBC($v0)
    ctx->r2 = MEM_W(0X7CBC, ctx->r2);
    // lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(0X0, ctx->r3);
    // lbu         $a2, -0x2($v1)
    ctx->r6 = MEM_BU(-0X2, ctx->r3);
    // lbu         $a3, 0x1($v1)
    ctx->r7 = MEM_BU(0X1, ctx->r3);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jalr        $v0
    // addiu       $a0, $a0, 0x4148
    ctx->r4 = ADD32(ctx->r4, 0X4148);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // addiu       $a0, $a0, 0x4148
    ctx->r4 = ADD32(ctx->r4, 0X4148);
    after_0:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_800798A4:
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
