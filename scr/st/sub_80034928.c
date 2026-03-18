#include "recomp.h"
#include "disable_warnings.h"

void sub_80034928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $a3, 0x4($a0)
    ctx->r7 = MEM_W(0X4, ctx->r4);
    // lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(0X0, ctx->r4);
    // blez        $a3, L_8003496C
    if (SIGNED(ctx->r7) <= 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_8003496C;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_80034938:
    // lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(0XC, ctx->r6);
    // nop

    // beq         $v0, $a1, L_80034958
    if (ctx->r2 == ctx->r5) {
        // nop
    
        goto L_80034958;
    }
    // nop

    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // slt         $v0, $v1, $a3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_80034938
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
        goto L_80034938;
    }
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
L_80034958:
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_80034974
    if (ctx->r2 != 0) {
        // addu        $v0, $a2, $zero
        ctx->r2 = ADD32(ctx->r6, 0);
        goto L_80034974;
    }
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
L_8003496C:
    // j           L_80034984
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80034984;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80034974:
    // ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // sh          $v1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r3;
    // sb          $zero, 0xA($v0)
    MEM_B(0XA, ctx->r2) = 0;
    // sb          $zero, 0xB($v0)
    MEM_B(0XB, ctx->r2) = 0;
L_80034984:
    // jr          $ra
    // nop

    return;
    // nop

;}
