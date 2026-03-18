#include "recomp.h"
#include "disable_warnings.h"

void sub_80045FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lh          $v1, 0xE($a0)
    ctx->r3 = MEM_HS(0XE, ctx->r4);
    // nop

    // slti        $v0, $v1, 0x11
    ctx->r2 = SIGNED(ctx->r3) < 0X11 ? 1 : 0;
    // bne         $v0, $zero, L_80045FE8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80045FE8;
    }
    // nop

    // lhu         $v0, 0xE($a0)
    ctx->r2 = MEM_HU(0XE, ctx->r4);
    // addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // sw          $v1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r3;
    // sw          $v1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r3;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // j           L_80045FF4
    // sh          $v0, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r2;
    goto L_80045FF4;
    // sh          $v0, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r2;
L_80045FE8:
    // sw          $v1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r3;
    // sw          $v1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r3;
    // sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
L_80045FF4:
    // jr          $ra
    // nop

    return;
    // nop

;}
