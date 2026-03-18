#include "recomp.h"
#include "disable_warnings.h"

void sub_8001C88C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $a1, $v0, 0x5948
    ctx->r5 = ADD32(ctx->r2, 0X5948);
    // lhu         $v1, 0x44CC($a1)
    ctx->r3 = MEM_HU(0X44CC, ctx->r5);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // beq         $v1, $v0, L_8001C8D4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8001C8D4;
    }
    // nop

    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
L_8001C8B8:
    // lhu         $v0, 0x45CE($a1)
    ctx->r2 = MEM_HU(0X45CE, ctx->r5);
    // nop

    // beq         $a0, $v0, L_8001C8D8
    if (ctx->r4 == ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8001C8D8;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bne         $v1, $a2, L_8001C8B8
    if (ctx->r3 != ctx->r6) {
        // addiu       $a1, $a1, -0x2
        ctx->r5 = ADD32(ctx->r5, -0X2);
        goto L_8001C8B8;
    }
    // addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
L_8001C8D4:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8001C8D8:
    // jr          $ra
    // nop

    return;
    // nop

;}
