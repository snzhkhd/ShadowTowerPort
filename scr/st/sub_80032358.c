#include "recomp.h"
#include "disable_warnings.h"

void sub_80032358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) << 16;
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lh          $a1, 0x2E($a0)
    ctx->r5 = MEM_HS(0X2E, ctx->r4);
    // lh          $a0, 0x6A($s0)
    ctx->r4 = MEM_HS(0X6A, ctx->r16);
    // jal         0x8004A830
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    sub_8004A830(rdram, ctx);
    goto after_0;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    after_0:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // lh          $v0, 0x68($s0)
    ctx->r2 = MEM_HS(0X68, ctx->r16);
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addiu       $v0, $v0, 0x1000
    ctx->r2 = ADD32(ctx->r2, 0X1000);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_800323A4
    if (ctx->r3 == 0) {
        // sh          $a0, 0x6A($s0)
        MEM_H(0X6A, ctx->r16) = ctx->r4;
        goto L_800323A4;
    }
    // sh          $a0, 0x6A($s0)
    MEM_H(0X6A, ctx->r16) = ctx->r4;
    // addiu       $v0, $a0, -0x1000
    ctx->r2 = ADD32(ctx->r4, -0X1000);
    // sh          $v0, 0x68($s0)
    MEM_H(0X68, ctx->r16) = ctx->r2;
L_800323A4:
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
