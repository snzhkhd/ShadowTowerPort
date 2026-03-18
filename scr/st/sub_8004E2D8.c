#include "recomp.h"
#include "disable_warnings.h"

void sub_8004E2D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // addiu       $a3, $zero, 0xFD
    ctx->r7 = ADD32(0, 0XFD);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x5EC8
    ctx->r2 = ADD32(ctx->r2, -0X5EC8);
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // addiu       $v1, $a1, 0x7
    ctx->r3 = ADD32(ctx->r5, 0X7);
L_8004E2F4:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // bne         $v0, $a3, L_8004E310
    if (ctx->r2 != ctx->r7) {
        // nop
    
        goto L_8004E310;
    }
    // nop

    // lbu         $v0, 0x6103($a1)
    ctx->r2 = MEM_BU(0X6103, ctx->r5);
    // nop

    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8004E310:
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // bne         $a0, $a2, L_8004E2F4
    if (ctx->r4 != ctx->r6) {
        // addiu       $v1, $v1, 0xD4
        ctx->r3 = ADD32(ctx->r3, 0XD4);
        goto L_8004E2F4;
    }
    // addiu       $v1, $v1, 0xD4
    ctx->r3 = ADD32(ctx->r3, 0XD4);
    // jr          $ra
    // nop

    return;
    // nop

;}
