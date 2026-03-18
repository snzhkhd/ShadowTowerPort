#include "recomp.h"
#include "disable_warnings.h"

void sub_8004FC94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $t2, $v0, -0x70D8
    ctx->r10 = ADD32(ctx->r2, -0X70D8);
    // lw          $v0, 0x248($t2)
    ctx->r2 = MEM_W(0X248, ctx->r10);
    // lw          $v1, 0x250($t2)
    ctx->r3 = MEM_W(0X250, ctx->r10);
    // lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(0X10, ctx->r29);
    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // sra         $t0, $v0, 12
    ctx->r8 = S32(ctx->r2) >> 12;
    // addiu       $v1, $v1, 0x800
    ctx->r3 = ADD32(ctx->r3, 0X800);
    // slt         $v0, $t0, $a0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_8004FD1C
    if (ctx->r2 != 0) {
        // sra         $v1, $v1, 12
        ctx->r3 = S32(ctx->r3) >> 12;
        goto L_8004FD1C;
    }
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8004FD1C
    if (ctx->r2 == 0) {
        // slt         $v0, $v1, $a1
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
        goto L_8004FD1C;
    }
    // slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_8004FD20
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004FD20;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8004FD1C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x8000
        ctx->r2 = 0 | 0X8000;
        goto L_8004FD1C;
    }
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // beq         $t1, $v0, L_8004FD20
    if (ctx->r9 == ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8004FD20;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lw          $v1, 0x24C($t2)
    ctx->r3 = MEM_W(0X24C, ctx->r10);
    // nop

    // slt         $v0, $t1, $v1
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8004FD20
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004FD20;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addiu       $v0, $t1, -0x1000
    ctx->r2 = ADD32(ctx->r9, -0X1000);
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8004FD20
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004FD20;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_8004FD20
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_8004FD20;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004FD1C:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004FD20:
    // jr          $ra
    // nop

    return;
    // nop

;}
