#include "recomp.h"
#include "disable_warnings.h"

void sub_80057A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v0, -0x2EDB($v0)
    ctx->r2 = MEM_BU(-0X2EDB, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80057B08
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80057B08;
    }
    // nop

    // blez        $a0, L_80057AE0
    if (SIGNED(ctx->r4) <= 0) {
        // addiu       $a0, $a0, 0x40
        ctx->r4 = ADD32(ctx->r4, 0X40);
        goto L_80057AE0;
    }
    // addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // slti        $v0, $a0, 0x100
    ctx->r2 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // bne         $v0, $zero, L_80057A98
    if (ctx->r2 != 0) {
        // addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
        goto L_80057A98;
    }
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80057A98:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // bgez        $a0, L_80057AA8
    if (SIGNED(ctx->r4) >= 0) {
        // addiu       $a1, $v0, -0x2E80
        ctx->r5 = ADD32(ctx->r2, -0X2E80);
        goto L_80057AA8;
    }
    // addiu       $a1, $v0, -0x2E80
    ctx->r5 = ADD32(ctx->r2, -0X2E80);
    // addiu       $v1, $a0, 0xF
    ctx->r3 = ADD32(ctx->r4, 0XF);
L_80057AA8:
    // sra         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) >> 4;
    // lbu         $v1, 0x18($a1)
    ctx->r3 = MEM_BU(0X18, ctx->r5);
    // addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // sb          $v0, 0x19($a1)
    MEM_B(0X19, ctx->r5) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80057AD0
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80057AD0;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x2ED0
    ctx->r2 = ADD32(ctx->r2, -0X2ED0);
    // sb          $v1, 0x45($v0)
    MEM_B(0X45, ctx->r2) = ctx->r3;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_80057AD0:
    // addiu       $v0, $v0, -0x2ED0
    ctx->r2 = ADD32(ctx->r2, -0X2ED0);
    // sb          $a0, 0x47($v0)
    MEM_B(0X47, ctx->r2) = ctx->r4;
    // j           L_80057B08
    // nop

    goto L_80057B08;
    // nop

L_80057AE0:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v1, -0x2E68($v0)
    ctx->r3 = MEM_BU(-0X2E68, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80057B00
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80057B00;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x2ED0
    ctx->r2 = ADD32(ctx->r2, -0X2ED0);
    // sb          $zero, 0x45($v0)
    MEM_B(0X45, ctx->r2) = 0;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_80057B00:
    // addiu       $v0, $v0, -0x2ED0
    ctx->r2 = ADD32(ctx->r2, -0X2ED0);
    // sb          $zero, 0x47($v0)
    MEM_B(0X47, ctx->r2) = 0;
L_80057B08:
    // jr          $ra
    // nop

    return;
    // nop

;}
