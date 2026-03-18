#include "recomp.h"
#include "disable_warnings.h"

void memmove_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // sltu        $v0, $a3, $a1
    ctx->r2 = ctx->r7 < ctx->r5 ? 1 : 0;
    // bne         $v0, $zero, L_80079410
    if (ctx->r2 != 0) {
        // addu        $v0, $a2, $zero
        ctx->r2 = ADD32(ctx->r6, 0);
        goto L_80079410;
    }
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // blez        $v0, L_80079434
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
        goto L_80079434;
    }
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_800793EC:
    // addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // addu        $v0, $a1, $a2
    ctx->r2 = ADD32(ctx->r5, ctx->r6);
    // addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // bgtz        $v1, L_800793EC
    if (SIGNED(ctx->r3) > 0) {
        // sb          $v0, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r2;
        goto L_800793EC;
    }
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // j           L_80079438
    // addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    goto L_80079438;
    // addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
L_80079410:
    // blez        $v0, L_80079434
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
        goto L_80079434;
    }
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80079418:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // bgtz        $v1, L_80079418
    if (SIGNED(ctx->r3) > 0) {
        // addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
        goto L_80079418;
    }
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_80079434:
    // addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
L_80079438:
    // jr          $ra
    // nop

    return;
    // nop

;}
