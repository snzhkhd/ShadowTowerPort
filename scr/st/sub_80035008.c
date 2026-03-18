#include "recomp.h"
#include "disable_warnings.h"

void sub_80035008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // beq         $s0, $zero, L_80035088
    if (ctx->r16 == 0) {
        // sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
        goto L_80035088;
    }
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // beq         $v0, $zero, L_80035088
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_80035088;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(0X38, ctx->r16);
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(0X28, ctx->r16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // beq         $a0, $zero, L_80035084
    if (ctx->r4 == 0) {
        // sw          $zero, 0x24($s0)
        MEM_W(0X24, ctx->r16) = 0;
        goto L_80035084;
    }
    // sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
L_80035084:
    // sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
L_80035088:
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
