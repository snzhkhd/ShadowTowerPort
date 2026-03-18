#include "recomp.h"
#include "disable_warnings.h"

void ratan2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // bgez        $a1, L_80076EB8
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
        goto L_80076EB8;
    }
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_80076EB8:
    // bgez        $a0, L_80076EC8
    if (SIGNED(ctx->r4) >= 0) {
        // nop
    
        goto L_80076EC8;
    }
    // nop

    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_80076EC8:
    // bne         $a1, $zero, L_80076EDC
    if (ctx->r5 != 0) {
        // slt         $v0, $a0, $a1
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
        goto L_80076EDC;
    }
    // slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // beq         $a0, $zero, L_80077010
    if (ctx->r4 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80077010;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80076EDC:
    // beq         $v0, $zero, L_80076F6C
    if (ctx->r2 == 0) {
        // lui         $v0, 0x7FE0
        ctx->r2 = S32(0X7FE0 << 16);
        goto L_80076F6C;
    }
    // lui         $v0, 0x7FE0
    ctx->r2 = S32(0X7FE0 << 16);
    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_80076F24
    if (ctx->r2 == 0) {
        // sra         $v0, $a1, 10
        ctx->r2 = S32(ctx->r5) >> 10;
        goto L_80076F24;
    }
    // sra         $v0, $a1, 10
    ctx->r2 = S32(ctx->r5) >> 10;
    // div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80076F00
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80076F00;
    }
    // nop

    // break       7
    do_break(2147970812);
L_80076F00:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80076F18
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80076F18;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_80076F18
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_80076F18;
    }
    // nop

    // break       6
    do_break(2147970836);
L_80076F18:
    // mflo        $a0
    ctx->r4 = lo;
    // j           L_80076F58
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    goto L_80076F58;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
L_80076F24:
    // sll         $v0, $a0, 10
    ctx->r2 = S32(ctx->r4) << 10;
    // div         $zero, $v0, $a1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r5)));
    // bne         $a1, $zero, L_80076F38
    if (ctx->r5 != 0) {
        // nop
    
        goto L_80076F38;
    }
    // nop

    // break       7
    do_break(2147970868);
L_80076F38:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a1, $at, L_80076F50
    if (ctx->r5 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80076F50;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80076F50
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80076F50;
    }
    // nop

    // break       6
    do_break(2147970892);
L_80076F50:
    // mflo        $a0
    ctx->r4 = lo;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
L_80076F58:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lh          $v1, 0x6280($v1)
    ctx->r3 = MEM_HS(0X6280, ctx->r3);
    // j           L_80076FF4
    // nop

    goto L_80076FF4;
    // nop

L_80076F6C:
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // beq         $v0, $zero, L_80076FAC
    if (ctx->r2 == 0) {
        // sra         $v0, $a0, 10
        ctx->r2 = S32(ctx->r4) >> 10;
        goto L_80076FAC;
    }
    // sra         $v0, $a0, 10
    ctx->r2 = S32(ctx->r4) >> 10;
    // div         $zero, $a1, $v0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80076F88
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80076F88;
    }
    // nop

    // break       7
    do_break(2147970948);
L_80076F88:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80076FA0
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80076FA0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a1, $at, L_80076FA0
    if (ctx->r5 != ctx->r1) {
        // nop
    
        goto L_80076FA0;
    }
    // nop

    // break       6
    do_break(2147970972);
L_80076FA0:
    // mflo        $a0
    ctx->r4 = lo;
    // j           L_80076FE0
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    goto L_80076FE0;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
L_80076FAC:
    // sll         $v0, $a1, 10
    ctx->r2 = S32(ctx->r5) << 10;
    // div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // bne         $a0, $zero, L_80076FC0
    if (ctx->r4 != 0) {
        // nop
    
        goto L_80076FC0;
    }
    // nop

    // break       7
    do_break(2147971004);
L_80076FC0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_80076FD8
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80076FD8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80076FD8
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80076FD8;
    }
    // nop

    // break       6
    do_break(2147971028);
L_80076FD8:
    // mflo        $a0
    ctx->r4 = lo;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
L_80076FE0:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lh          $v1, 0x6280($v1)
    ctx->r3 = MEM_HS(0X6280, ctx->r3);
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
L_80076FF4:
    // beq         $a2, $zero, L_80077000
    if (ctx->r6 == 0) {
        // addiu       $v0, $zero, 0x800
        ctx->r2 = ADD32(0, 0X800);
        goto L_80077000;
    }
    // addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
L_80077000:
    // beq         $a3, $zero, L_80077010
    if (ctx->r7 == 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80077010;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_80077010:
    // jr          $ra
    // nop

    return;
    // nop

;}
