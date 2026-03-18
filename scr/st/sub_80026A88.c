#include "recomp.h"
#include "disable_warnings.h"

void sub_80026A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a0, $v0, L_80026AF4
    if (ctx->r4 == ctx->r2) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80026AF4;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v0, -0x2EDD($v0)
    ctx->r2 = MEM_BU(-0X2EDD, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80026AF4
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80026AF4;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
L_80026AC8:
    // lw          $v0, 0x1EC($v1)
    ctx->r2 = MEM_W(0X1EC, ctx->r3);
    // nop

    // bne         $v0, $zero, L_80026AE4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80026AE4;
    }
    // nop

    // sw          $t0, 0x1EC($v1)
    MEM_W(0X1EC, ctx->r3) = ctx->r8;
    // j           L_80026AF4
    // sh          $a3, 0x20C($a0)
    MEM_H(0X20C, ctx->r4) = ctx->r7;
    goto L_80026AF4;
    // sh          $a3, 0x20C($a0)
    MEM_H(0X20C, ctx->r4) = ctx->r7;
L_80026AE4:
    // addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // bne         $a1, $a2, L_80026AC8
    if (ctx->r5 != ctx->r6) {
        // addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
        goto L_80026AC8;
    }
    // addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
L_80026AF4:
    // jr          $ra
    // nop

    return;
    // nop

;}
