#include "recomp.h"
#include "disable_warnings.h"

void sub_8003498C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(0X4, ctx->r4);
    // nop

    // blez        $v1, L_800349BC
    if (SIGNED(ctx->r3) <= 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_800349BC;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8003499C:
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // beq         $a2, $v0, L_800349BC
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_800349BC;
    }
    // nop

    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bgtz        $v1, L_8003499C
    if (SIGNED(ctx->r3) > 0) {
        // addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
        goto L_8003499C;
    }
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_800349BC:
    // beq         $v1, $zero, L_800349C8
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_800349C8;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_800349C8:
    // jr          $ra
    // nop

    return;
    // nop

;}
