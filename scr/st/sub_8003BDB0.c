#include "recomp.h"
#include "disable_warnings.h"

void sub_8003BDB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lh          $v0, 0x2D4($s0)
    ctx->r2 = MEM_HS(0X2D4, ctx->r16);
    // nop

    // slti        $v0, $v0, 0x480
    ctx->r2 = SIGNED(ctx->r2) < 0X480 ? 1 : 0;
    // bne         $v0, $zero, L_8003BDFC
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8003BDFC;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v0, 0x5978($v0)
    ctx->r2 = MEM_W(0X5978, ctx->r2);
    // nop

    // slti        $v0, $v0, 0x640
    ctx->r2 = SIGNED(ctx->r2) < 0X640 ? 1 : 0;
    // bne         $v0, $zero, L_8003BDFC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003BDFC;
    }
    // nop

    // jal         0x8003BD14
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8003BD14(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x238($s0)
    MEM_B(0X238, ctx->r16) = ctx->r2;
L_8003BDFC:
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
