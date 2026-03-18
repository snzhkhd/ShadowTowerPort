#include "recomp.h"
#include "disable_warnings.h"

void sub_8007AE10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
    // bltz        $a2, L_8007AE48
    if (SIGNED(ctx->r6) < 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007AE48;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lh          $v0, 0x7CC4($v0)
    ctx->r2 = MEM_HS(0X7CC4, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // slt         $v0, $v0, $a2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // lhu         $a2, 0x7CC4($a2)
    ctx->r6 = MEM_HU(0X7CC4, ctx->r6);
    // bne         $v0, $zero, L_8007AE48
    if (ctx->r2 != 0) {
        // addiu       $v0, $a2, -0x1
        ctx->r2 = ADD32(ctx->r6, -0X1);
        goto L_8007AE48;
    }
    // addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_8007AE48:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
    // bltz        $a2, L_8007AE88
    if (SIGNED(ctx->r6) < 0) {
        // nop
    
        goto L_8007AE88;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lh          $v0, 0x7CC6($v0)
    ctx->r2 = MEM_HS(0X7CC6, ctx->r2);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // slt         $v0, $v0, $a2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // lhu         $a2, 0x7CC6($a2)
    ctx->r6 = MEM_HU(0X7CC6, ctx->r6);
    // beq         $v0, $zero, L_8007AE90
    if (ctx->r2 == 0) {
        // andi        $v1, $a1, 0x3FF
        ctx->r3 = ctx->r5 & 0X3FF;
        goto L_8007AE90;
    }
    // andi        $v1, $a1, 0x3FF
    ctx->r3 = ctx->r5 & 0X3FF;
    // j           L_8007AE8C
    // addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    goto L_8007AE8C;
    // addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
L_8007AE88:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8007AE8C:
    // andi        $v1, $a1, 0x3FF
    ctx->r3 = ctx->r5 & 0X3FF;
L_8007AE90:
    // sll         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3) << 10;
    // andi        $v0, $a0, 0x3FF
    ctx->r2 = ctx->r4 & 0X3FF;
    // lui         $a0, 0xE300
    ctx->r4 = S32(0XE300 << 16);
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // jr          $ra
    // or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    return;
    // or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
;}
