#include "recomp.h"
#include "disable_warnings.h"

void sub_800785B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7C44($v0)
    ctx->r2 = MEM_W(0X7C44, ctx->r2);
    // addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(0X0, ctx->r29);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // lw          $v1, 0x0($sp)
    ctx->r3 = MEM_W(0X0, ctx->r29);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_80078614
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80078614;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800785F4:
    // lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(0X0, ctx->r29);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(0X0, ctx->r29);
    // nop

    // bne         $v0, $v1, L_800785F4
    if (ctx->r2 != ctx->r3) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_800785F4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80078614:
    // addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // jr          $ra
    // nop

    return;
    // nop

;}
