#include "recomp.h"
#include "disable_warnings.h"

void rcos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // bgez        $a0, L_800744D0
    if (SIGNED(ctx->r4) >= 0) {
        // nop
    
        goto L_800744D0;
    }
    // nop

    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_800744D0:
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // slti        $v0, $a0, 0x801
    ctx->r2 = SIGNED(ctx->r4) < 0X801 ? 1 : 0;
    // beq         $v0, $zero, L_8007451C
    if (ctx->r2 == 0) {
        // slti        $v0, $a0, 0x401
        ctx->r2 = SIGNED(ctx->r4) < 0X401 ? 1 : 0;
        goto L_8007451C;
    }
    // slti        $v0, $a0, 0x401
    ctx->r2 = SIGNED(ctx->r4) < 0X401 ? 1 : 0;
    // beq         $v0, $zero, L_80074504
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x400
        ctx->r2 = ADD32(0, 0X400);
        goto L_80074504;
    }
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lh          $v0, 0x1710($at)
    ctx->r2 = MEM_HS(0X1710, ctx->r1);
    // j           L_8007455C
    // nop

    goto L_8007455C;
    // nop

L_80074504:
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lh          $v0, 0xF10($at)
    ctx->r2 = MEM_HS(0XF10, ctx->r1);
    // j           L_8007455C
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    goto L_8007455C;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8007451C:
    // slti        $v0, $a0, 0xC01
    ctx->r2 = SIGNED(ctx->r4) < 0XC01 ? 1 : 0;
    // bne         $v0, $zero, L_80074540
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0xC00
        ctx->r2 = ADD32(0, 0XC00);
        goto L_80074540;
    }
    // addiu       $v0, $zero, 0xC00
    ctx->r2 = ADD32(0, 0XC00);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lh          $v0, -0xF0($at)
    ctx->r2 = MEM_HS(-0XF0, ctx->r1);
    // j           L_8007455C
    // nop

    goto L_8007455C;
    // nop

L_80074540:
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lh          $v0, 0x1710($at)
    ctx->r2 = MEM_HS(0X1710, ctx->r1);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8007455C:
    // jr          $ra
    // nop

    return;
    // nop

;}
