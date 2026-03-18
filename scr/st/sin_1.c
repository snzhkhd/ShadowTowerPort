#include "recomp.h"
#include "disable_warnings.h"

void sin_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // slti        $v0, $a0, 0x801
    ctx->r2 = SIGNED(ctx->r4) < 0X801 ? 1 : 0;
    // beq         $v0, $zero, L_80074478
    if (ctx->r2 == 0) {
        // slti        $v0, $a0, 0x401
        ctx->r2 = SIGNED(ctx->r4) < 0X401 ? 1 : 0;
        goto L_80074478;
    }
    // slti        $v0, $a0, 0x401
    ctx->r2 = SIGNED(ctx->r4) < 0X401 ? 1 : 0;
    // beq         $v0, $zero, L_80074458
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4) << 1;
        goto L_80074458;
    }
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lh          $v0, 0x1710($at)
    ctx->r2 = MEM_HS(0X1710, ctx->r1);
    // j           L_800744B8
    // nop

    goto L_800744B8;
    // nop

L_80074458:
    // addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
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
    // j           L_800744B8
    // nop

    goto L_800744B8;
    // nop

L_80074478:
    // slti        $v0, $a0, 0xC01
    ctx->r2 = SIGNED(ctx->r4) < 0XC01 ? 1 : 0;
    // bne         $v0, $zero, L_800744A4
    if (ctx->r2 != 0) {
        // sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4) << 1;
        goto L_800744A4;
    }
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
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
    // j           L_800744B8
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    goto L_800744B8;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_800744A4:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lh          $v0, 0x710($at)
    ctx->r2 = MEM_HS(0X710, ctx->r1);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_800744B8:
    // jr          $ra
    // nop

    return;
    // nop

;}
