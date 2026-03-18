#include "recomp.h"
#include "disable_warnings.h"

void sub_8004B1E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    // addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8004B1F8:
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // beq         $v1, $zero, L_8004B224
    if (ctx->r3 == 0) {
        // addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_8004B224;
    }
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // beq         $v0, $a1, L_8004B228
    if (ctx->r2 == ctx->r5) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8004B228;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // bne         $a2, $a3, L_8004B1F8
    if (ctx->r6 != ctx->r7) {
        // nop
    
        goto L_8004B1F8;
    }
    // nop

L_8004B224:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004B228:
    // jr          $ra
    // nop

    return;
    // nop

;}
