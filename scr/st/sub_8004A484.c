#include "recomp.h"
#include "disable_warnings.h"

void sub_8004A484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // subu        $v1, $v0, $a1
    ctx->r3 = SUB32(ctx->r2, ctx->r5);
    // negu        $a1, $s0
    ctx->r5 = SUB32(0, ctx->r16);
    // slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_8004A56C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004A56C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // slt         $v0, $s0, $v1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8004A56C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004A56C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(0X8, ctx->r4);
    // nop

    // subu        $a3, $v0, $a3
    ctx->r7 = SUB32(ctx->r2, ctx->r7);
    // slt         $v0, $a3, $a1
    ctx->r2 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_8004A56C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004A56C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // slt         $v0, $s0, $a3
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8004A56C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004A56C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $a2, $v0, L_8004A534
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_8004A534;
    }
    // nop

    // lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(0X4, ctx->r4);
    // nop

    // slt         $v0, $a0, $a2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // beq         $v0, $zero, L_8004A51C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004A51C;
    }
    // nop

    // lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(0X30, ctx->r29);
    // nop

    // subu        $v0, $a2, $v0
    ctx->r2 = SUB32(ctx->r6, ctx->r2);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8004A534
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004A534;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // j           L_8004A56C
    // nop

    goto L_8004A56C;
    // nop

L_8004A51C:
    // lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(0X2C, ctx->r29);
    // nop

    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8004A56C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004A56C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004A534:
    // sra         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) >> 3;
    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $a3, $a3, 3
    ctx->r7 = S32(ctx->r7) >> 3;
    // nop

    // mult        $a3, $a3
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // jal         0x800746C4
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    SquareRoot0(rdram, ctx);
    goto after_0;
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    after_0:
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // slt         $v1, $s0, $v0
    ctx->r3 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8004A56C
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8004A56C;
    }
    // nop

    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004A56C:
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
