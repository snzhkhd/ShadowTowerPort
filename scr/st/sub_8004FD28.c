#include "recomp.h"
#include "disable_warnings.h"

void sub_8004FD28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $t2, $v0, -0x70D8
    ctx->r10 = ADD32(ctx->r2, -0X70D8);
    // srl         $v0, $a2, 31
    ctx->r2 = S32(U32(ctx->r6) >> 31);
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // lw          $v1, 0x248($t2)
    ctx->r3 = MEM_W(0X248, ctx->r10);
    // lw          $t1, 0x10($sp)
    ctx->r9 = MEM_W(0X10, ctx->r29);
    // addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
    // srl         $v0, $a3, 31
    ctx->r2 = S32(U32(ctx->r7) >> 31);
    // addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // lw          $v1, 0x250($t2)
    ctx->r3 = MEM_W(0X250, ctx->r10);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slt         $v0, $t0, $a0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_8004FDC8
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004FDC8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8004FDC4
    if (ctx->r2 == 0) {
        // slt         $v0, $v1, $a1
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
        goto L_8004FDC4;
    }
    // slt         $v0, $v1, $a1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_8004FDC8
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004FDC8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8004FDC4
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0x8000
        ctx->r2 = 0 | 0X8000;
        goto L_8004FDC4;
    }
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // beq         $t1, $v0, L_8004FDC8
    if (ctx->r9 == ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8004FDC8;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lw          $v1, 0x24C($t2)
    ctx->r3 = MEM_W(0X24C, ctx->r10);
    // nop

    // slt         $v0, $t1, $v1
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8004FDC8
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004FDC8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addiu       $v0, $t1, -0x1000
    ctx->r2 = ADD32(ctx->r9, -0X1000);
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8004FDC8
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004FDC8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_8004FDC8
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_8004FDC8;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004FDC4:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004FDC8:
    // jr          $ra
    // nop

    return;
    // nop

;}
