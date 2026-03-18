#include "recomp.h"
#include "disable_warnings.h"

void sub_80015B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a3, 0x1234
    ctx->r7 = S32(0X1234 << 16);
    // ori         $a3, $a3, 0x5678
    ctx->r7 = ctx->r7 | 0X5678;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // sll         $a1, $a1, 9
    ctx->r5 = S32(ctx->r5) << 9;
    // addiu       $v1, $a1, -0x2
    ctx->r3 = ADD32(ctx->r5, -0X2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_80015BB0
    if (ctx->r3 == ctx->r2) {
        // addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
        goto L_80015BB0;
    }
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
L_80015B9C:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bne         $v1, $t0, L_80015B9C
    if (ctx->r3 != ctx->r8) {
        // addu        $a3, $a3, $v0
        ctx->r7 = ADD32(ctx->r7, ctx->r2);
        goto L_80015B9C;
    }
    // addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
L_80015BB0:
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // xor         $v0, $a3, $v0
    ctx->r2 = ctx->r7 ^ ctx->r2;
    // jr          $ra
    // sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
;}
