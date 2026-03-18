#include "recomp.h"
#include "disable_warnings.h"

void sub_80052CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v1, $v0, -0x51F8
    ctx->r3 = ADD32(ctx->r2, -0X51F8);
    // addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // addiu       $v0, $v1, -0x3710
    ctx->r2 = ADD32(ctx->r3, -0X3710);
    // sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
L_80052CCC:
    // sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // sb          $zero, 0x22($v1)
    MEM_B(0X22, ctx->r3) = 0;
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // bne         $a0, $a1, L_80052CCC
    if (ctx->r4 != ctx->r5) {
        // addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
        goto L_80052CCC;
    }
    // addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x76F8
    ctx->r2 = ADD32(ctx->r2, 0X76F8);
    // addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
L_80052CF4:
    // sw          $zero, 0x48($v0)
    MEM_W(0X48, ctx->r2) = 0;
    // sw          $zero, 0x70($v0)
    MEM_W(0X70, ctx->r2) = 0;
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // bne         $a0, $v1, L_80052CF4
    if (ctx->r4 != ctx->r3) {
        // addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
        goto L_80052CF4;
    }
    // addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // jr          $ra
    // nop

    return;
    // nop

;}
