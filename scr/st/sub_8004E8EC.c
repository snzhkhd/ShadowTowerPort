#include "recomp.h"
#include "disable_warnings.h"

void sub_8004E8EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a1, $v0, -0x29C8
    ctx->r5 = ADD32(ctx->r2, -0X29C8);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // addiu       $a3, $a1, 0xC00
    ctx->r7 = ADD32(ctx->r5, 0XC00);
L_8004E904:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // nop

    // beq         $v0, $t1, L_8004E958
    if (ctx->r2 == ctx->r9) {
        // nop
    
        goto L_8004E958;
    }
    // nop

    // addiu       $v1, $a1, 0x60
    ctx->r3 = ADD32(ctx->r5, 0X60);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8004E91C:
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // bne         $v0, $t0, L_8004E934
    if (ctx->r2 != ctx->r8) {
        // addu        $v0, $v0, $a3
        ctx->r2 = ADD32(ctx->r2, ctx->r7);
        goto L_8004E934;
    }
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // j           L_8004E938
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    goto L_8004E938;
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8004E934:
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8004E938:
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v0, $a0, 0x18
    ctx->r2 = SIGNED(ctx->r4) < 0X18 ? 1 : 0;
    // bne         $v0, $zero, L_8004E91C
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
        goto L_8004E91C;
    }
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slti        $v0, $a2, 0x10
    ctx->r2 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_8004E904
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0xC0
        ctx->r5 = ADD32(ctx->r5, 0XC0);
        goto L_8004E904;
    }
    // addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
L_8004E958:
    // jr          $ra
    // nop

    return;
    // nop

;}
