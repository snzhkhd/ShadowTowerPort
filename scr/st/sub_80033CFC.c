#include "recomp.h"
#include "disable_warnings.h"

void sub_80033CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t4, $zero, $zero
    ctx->r12 = ADD32(0, 0);
    // addu        $t2, $t4, $zero
    ctx->r10 = ADD32(ctx->r12, 0);
    // addu        $t0, $t2, $zero
    ctx->r8 = ADD32(ctx->r10, 0);
    // lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(0X10, ctx->r4);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // addiu       $t1, $v0, 0x4
    ctx->r9 = ADD32(ctx->r2, 0X4);
    // lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // beq         $a1, $v0, L_80033D98
    if (ctx->r5 == ctx->r2) {
        // addu        $t3, $t0, $zero
        ctx->r11 = ADD32(ctx->r8, 0);
        goto L_80033D98;
    }
    // addu        $t3, $t0, $zero
    ctx->r11 = ADD32(ctx->r8, 0);
    // addu        $t5, $v0, $zero
    ctx->r13 = ADD32(ctx->r2, 0);
L_80033D40:
    // lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(0X0, ctx->r9);
    // nop

    // addu        $t4, $a0, $v0
    ctx->r12 = ADD32(ctx->r4, ctx->r2);
    // lhu         $v1, 0x0($t4)
    ctx->r3 = MEM_HU(0X0, ctx->r12);
    // nop

    // addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // slt         $v0, $a2, $t0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // beq         $v0, $zero, L_80033D88
    if (ctx->r2 == 0) {
        // addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
        goto L_80033D88;
    }
    // addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // subu        $v0, $a2, $t3
    ctx->r2 = SUB32(ctx->r6, ctx->r11);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_80033D7C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80033D7C;
    }
    // nop

    // break       7
    do_break(2147695992);
L_80033D7C:
    // mflo        $v1
    ctx->r3 = lo;
    // j           L_80033DA4
    // sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    goto L_80033DA4;
    // sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
L_80033D88:
    // addu        $t3, $t0, $zero
    ctx->r11 = ADD32(ctx->r8, 0);
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // bne         $a1, $t5, L_80033D40
    if (ctx->r5 != ctx->r13) {
        // addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
        goto L_80033D40;
    }
    // addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80033D98:
    // addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
    // sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
L_80033DA4:
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // nop

    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // jr          $ra
    // addu        $v0, $t4, $zero
    ctx->r2 = ADD32(ctx->r12, 0);
    return;
    // addu        $v0, $t4, $zero
    ctx->r2 = ADD32(ctx->r12, 0);
;}
