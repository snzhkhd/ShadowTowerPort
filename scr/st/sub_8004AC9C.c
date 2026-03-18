#include "recomp.h"
#include "disable_warnings.h"

void sub_8004AC9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lhu         $v1, 0x68($s0)
    ctx->r3 = MEM_HU(0X68, ctx->r16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sh          $zero, 0x90($s0)
    MEM_H(0X90, ctx->r16) = 0;
    // bne         $v1, $v0, L_8004ACD4
    if (ctx->r3 != ctx->r2) {
        // sh          $zero, 0x8C($s0)
        MEM_H(0X8C, ctx->r16) = 0;
        goto L_8004ACD4;
    }
    // sh          $zero, 0x8C($s0)
    MEM_H(0X8C, ctx->r16) = 0;
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // j           L_8004ACD8
    // sh          $v0, 0x8E($s0)
    MEM_H(0X8E, ctx->r16) = ctx->r2;
    goto L_8004ACD8;
    // sh          $v0, 0x8E($s0)
    MEM_H(0X8E, ctx->r16) = ctx->r2;
L_8004ACD4:
    // sh          $v1, 0x8E($s0)
    MEM_H(0X8E, ctx->r16) = ctx->r3;
L_8004ACD8:
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
