#include "recomp.h"
#include "disable_warnings.h"

void sub_8004EE48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $a0, $v0, L_8004EEB4
    if (ctx->r4 == ctx->r2) {
        // sll         $v1, $a0, 1
        ctx->r3 = S32(ctx->r4) << 1;
        goto L_8004EEB4;
    }
    // sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4) << 1;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x51F8
    ctx->r2 = ADD32(ctx->r2, -0X51F8);
    // andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // beq         $a1, $zero, L_8004EE88
    if (ctx->r5 == 0) {
        // addu        $a0, $v1, $v0
        ctx->r4 = ADD32(ctx->r3, ctx->r2);
        goto L_8004EE88;
    }
    // addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $a1, $v0, L_8004EEA0
    if (ctx->r5 == ctx->r2) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_8004EEA0;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // j           L_8004EEB4
    // nop

    goto L_8004EEB4;
    // nop

L_8004EE88:
    // lbu         $v0, 0x22($a0)
    ctx->r2 = MEM_BU(0X22, ctx->r4);
    // nop

    // beq         $v0, $zero, L_8004EEB4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_8004EEB4;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // j           L_8004EEB4
    // sb          $v0, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r2;
    goto L_8004EEB4;
    // sb          $v0, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r2;
L_8004EEA0:
    // lbu         $v1, 0x22($a0)
    ctx->r3 = MEM_BU(0X22, ctx->r4);
    // nop

    // bne         $v1, $v0, L_8004EEB4
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8004EEB4;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r2;
L_8004EEB4:
    // jr          $ra
    // nop

    return;
    // nop

;}
