#include "recomp.h"
#include "disable_warnings.h"

void sub_80057B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v1, $v0, -0x2E80
    ctx->r3 = ADD32(ctx->r2, -0X2E80);
    // lbu         $v0, 0x19($v1)
    ctx->r2 = MEM_BU(0X19, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80057B30
    if (ctx->r2 == 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80057B30;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // j           L_80057B40
    // sb          $v0, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r2;
    goto L_80057B40;
    // sb          $v0, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r2;
L_80057B30:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x2ED0
    ctx->r2 = ADD32(ctx->r2, -0X2ED0);
    // sb          $zero, 0x45($v0)
    MEM_B(0X45, ctx->r2) = 0;
    // sb          $zero, 0x47($v0)
    MEM_B(0X47, ctx->r2) = 0;
L_80057B40:
    // jr          $ra
    // nop

    return;
    // nop

;}
