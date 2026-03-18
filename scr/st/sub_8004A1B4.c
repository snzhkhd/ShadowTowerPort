#include "recomp.h"
#include "disable_warnings.h"

void sub_8004A1B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // bgez        $a2, L_8004A1C8
    if (SIGNED(ctx->r6) >= 0) {
        // addu        $v1, $a2, $zero
        ctx->r3 = ADD32(ctx->r6, 0);
        goto L_8004A1C8;
    }
    // addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_8004A1C8:
    // bgez        $a1, L_8004A1D4
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_8004A1D4;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8004A1D4:
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8004A278
    if (ctx->r2 != 0) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_8004A278;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // blez        $a1, L_8004A228
    if (SIGNED(ctx->r5) <= 0) {
        // sll         $a0, $a2, 12
        ctx->r4 = S32(ctx->r6) << 12;
        goto L_8004A228;
    }
    // sll         $a0, $a2, 12
    ctx->r4 = S32(ctx->r6) << 12;
    // div         $zero, $a0, $a1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r5)));
    // bne         $a1, $zero, L_8004A1F8
    if (ctx->r5 != 0) {
        // nop
    
        goto L_8004A1F8;
    }
    // nop

    // break       7
    do_break(2147787252);
L_8004A1F8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a1, $at, L_8004A210
    if (ctx->r5 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8004A210;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_8004A210
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_8004A210;
    }
    // nop

    // break       6
    do_break(2147787276);
L_8004A210:
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x80074564
    // nop

    catan(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // j           L_8004A2F4
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    goto L_8004A2F4;
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
L_8004A228:
    // bgez        $a1, L_8004A270
    if (SIGNED(ctx->r5) >= 0) {
        // nop
    
        goto L_8004A270;
    }
    // nop

    // div         $zero, $a0, $a1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r5)));
    // bne         $a1, $zero, L_8004A240
    if (ctx->r5 != 0) {
        // nop
    
        goto L_8004A240;
    }
    // nop

    // break       7
    do_break(2147787324);
L_8004A240:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a1, $at, L_8004A258
    if (ctx->r5 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8004A258;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_8004A258
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_8004A258;
    }
    // nop

    // break       6
    do_break(2147787348);
L_8004A258:
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x80074564
    // nop

    catan(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // addiu       $v1, $zero, 0x800
    ctx->r3 = ADD32(0, 0X800);
    // j           L_8004A2F4
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    goto L_8004A2F4;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
L_8004A270:
    // j           L_8004A2F4
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8004A2F4;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004A278:
    // bgez        $a2, L_8004A2BC
    if (SIGNED(ctx->r6) >= 0) {
        // sll         $a0, $a1, 12
        ctx->r4 = S32(ctx->r5) << 12;
        goto L_8004A2BC;
    }
    // sll         $a0, $a1, 12
    ctx->r4 = S32(ctx->r5) << 12;
    // div         $zero, $a0, $a2
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r6)));
    // bne         $a2, $zero, L_8004A290
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8004A290;
    }
    // nop

    // break       7
    do_break(2147787404);
L_8004A290:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a2, $at, L_8004A2A8
    if (ctx->r6 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8004A2A8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_8004A2A8
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_8004A2A8;
    }
    // nop

    // break       6
    do_break(2147787428);
L_8004A2A8:
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x80074564
    // nop

    catan(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_8004A2F4
    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    goto L_8004A2F4;
    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
L_8004A2BC:
    // div         $zero, $a0, $a2
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r6)));
    // bne         $a2, $zero, L_8004A2CC
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8004A2CC;
    }
    // nop

    // break       7
    do_break(2147787464);
L_8004A2CC:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a2, $at, L_8004A2E4
    if (ctx->r6 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8004A2E4;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_8004A2E4
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_8004A2E4;
    }
    // nop

    // break       6
    do_break(2147787488);
L_8004A2E4:
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x80074564
    // nop

    catan(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // addiu       $v0, $v0, 0xC00
    ctx->r2 = ADD32(ctx->r2, 0XC00);
L_8004A2F4:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
