#include "recomp.h"
#include "disable_warnings.h"

void sub_80014DA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_80014E18
    if (ctx->r3 == ctx->r2) {
        // addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
        goto L_80014E18;
    }
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
L_80014DB8:
    // bne         $v1, $zero, L_80014DF8
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80014DF8;
    }
    // nop

    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // bne         $v0, $zero, L_80014E18
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80014E18;
    }
    // nop

    // lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(0X4, ctx->r5);
    // lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(0X4, ctx->r4);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_80014E08
    // sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    goto L_80014E08;
    // sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_80014DF8:
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_80014E08:
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // nop

    // bne         $v1, $a2, L_80014DB8
    if (ctx->r3 != ctx->r6) {
        // nop
    
        goto L_80014DB8;
    }
    // nop

L_80014E18:
    // jr          $ra
    // nop

    return;
    // nop

;}
