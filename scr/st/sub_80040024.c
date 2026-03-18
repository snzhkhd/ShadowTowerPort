#include "recomp.h"
#include "disable_warnings.h"

void sub_80040024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lh          $v1, 0x13C($v0)
    ctx->r3 = MEM_HS(0X13C, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_80040110
    if (ctx->r3 == ctx->r2) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80040110;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $a1, $zero, L_800400A8
    if (ctx->r5 == 0) {
        // nop
    
        goto L_800400A8;
    }
    // nop

    // lhu         $v1, 0x52($a0)
    ctx->r3 = MEM_HU(0X52, ctx->r4);
    // nop

    // beq         $v1, $v0, L_800400F0
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_800400F0;
    }
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x7810
    ctx->r3 = ADD32(ctx->r3, 0X7810);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0x28($v0)
    ctx->r2 = MEM_BU(0X28, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800400F0
    if (ctx->r2 == 0) {
        // addu        $v0, $a1, $a0
        ctx->r2 = ADD32(ctx->r5, ctx->r4);
        goto L_800400F0;
    }
    // addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // lbu         $a0, 0x14C($v0)
    ctx->r4 = MEM_BU(0X14C, ctx->r2);
    // j           L_800400E8
    // nop

    goto L_800400E8;
    // nop

L_800400A8:
    // lhu         $v1, 0x38($a0)
    ctx->r3 = MEM_HU(0X38, ctx->r4);
    // nop

    // beq         $v1, $v0, L_800400F0
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_800400F0;
    }
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x7810
    ctx->r3 = ADD32(ctx->r3, 0X7810);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0x28($v0)
    ctx->r2 = MEM_BU(0X28, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800400F0
    if (ctx->r2 == 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_800400F0;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lbu         $a0, 0x14C($a0)
    ctx->r4 = MEM_BU(0X14C, ctx->r4);
L_800400E8:
    // jal         0x80040F04
    // nop

    sub_80040F04(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_800400F0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // j           L_80040298
    // sh          $v0, 0x13C($v1)
    MEM_H(0X13C, ctx->r3) = ctx->r2;
    goto L_80040298;
    // sh          $v0, 0x13C($v1)
    MEM_H(0X13C, ctx->r3) = ctx->r2;
L_80040110:
    // lhu         $v1, 0x38($a0)
    ctx->r3 = MEM_HU(0X38, ctx->r4);
    // nop

    // beq         $v1, $v0, L_80040160
    if (ctx->r3 == ctx->r2) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_80040160;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x7810
    ctx->r3 = ADD32(ctx->r3, 0X7810);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0x28($v0)
    ctx->r2 = MEM_BU(0X28, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80040164
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80040164;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, 0x44($a0)
    ctx->r2 = MEM_HU(0X44, ctx->r4);
    // nop

    // xori        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 ^ 0XFFFF;
    // sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
L_80040160:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80040164:
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v0, 0x52($a0)
    ctx->r2 = MEM_HU(0X52, ctx->r4);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // beq         $v0, $a2, L_800401BC
    if (ctx->r2 == ctx->r6) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_800401BC;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x7810
    ctx->r3 = ADD32(ctx->r3, 0X7810);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0x28($v0)
    ctx->r2 = MEM_BU(0X28, ctx->r2);
    // nop

    // beq         $v0, $zero, L_800401C0
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_800401C0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, 0x50($a0)
    ctx->r2 = MEM_HU(0X50, ctx->r4);
    // nop

    // beq         $v0, $a2, L_800401C0
    if (ctx->r2 == ctx->r6) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_800401C0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800401BC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_800401C0:
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v0, 0x1CB($a0)
    ctx->r2 = MEM_BU(0X1CB, ctx->r4);
    // nop

    // beq         $v0, $zero, L_800401E4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800401E4;
    }
    // nop

    // lh          $v0, 0x1C0($a0)
    ctx->r2 = MEM_HS(0X1C0, ctx->r4);
    // nop

    // beq         $v0, $zero, L_80040278
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80040278;
    }
    // nop

L_800401E4:
    // beq         $a1, $zero, L_80040298
    if (ctx->r5 == 0) {
        // nop
    
        goto L_80040298;
    }
    // nop

    // lbu         $v0, 0x188($a0)
    ctx->r2 = MEM_BU(0X188, ctx->r4);
    // nop

    // bne         $v0, $zero, L_80040270
    if (ctx->r2 != 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80040270;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lh          $v0, 0x72($a0)
    ctx->r2 = MEM_HS(0X72, ctx->r4);
    // nop

    // addiu       $v1, $v0, 0x3E8
    ctx->r3 = ADD32(ctx->r2, 0X3E8);
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_80040218
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80040218;
    }
    // nop

    // break       7
    do_break(2147746324);
L_80040218:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_80040230
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80040230;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80040230
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80040230;
    }
    // nop

    // break       6
    do_break(2147746348);
L_80040230:
    // mflo        $v0
    ctx->r2 = lo;
    // addiu       $v1, $zero, 0x24
    ctx->r3 = ADD32(0, 0X24);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x182($a0)
    ctx->r2 = MEM_HU(0X182, ctx->r4);
    // mflo        $a3
    ctx->r7 = lo;
    // addiu       $v1, $a3, 0x24
    ctx->r3 = ADD32(ctx->r7, 0X24);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x182($a0)
    MEM_H(0X182, ctx->r4) = ctx->r2;
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x1401
    ctx->r2 = ctx->r2 < 0X1401 ? 1 : 0;
    // bne         $v0, $zero, L_80040298
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1400
        ctx->r2 = ADD32(0, 0X1400);
        goto L_80040298;
    }
    // addiu       $v0, $zero, 0x1400
    ctx->r2 = ADD32(0, 0X1400);
    // j           L_80040298
    // sh          $v0, 0x182($a0)
    MEM_H(0X182, ctx->r4) = ctx->r2;
    goto L_80040298;
    // sh          $v0, 0x182($a0)
    MEM_H(0X182, ctx->r4) = ctx->r2;
L_80040270:
    // j           L_80040298
    // sb          $v0, 0x188($a0)
    MEM_B(0X188, ctx->r4) = ctx->r2;
    goto L_80040298;
    // sb          $v0, 0x188($a0)
    MEM_B(0X188, ctx->r4) = ctx->r2;
L_80040278:
    // lhu         $v0, 0x182($a0)
    ctx->r2 = MEM_HU(0X182, ctx->r4);
    // nop

    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // blez        $v0, L_80040294
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80040294;
    }
    // nop

    // j           L_80040298
    // sh          $v0, 0x182($a0)
    MEM_H(0X182, ctx->r4) = ctx->r2;
    goto L_80040298;
    // sh          $v0, 0x182($a0)
    MEM_H(0X182, ctx->r4) = ctx->r2;
L_80040294:
    // sh          $zero, 0x182($a0)
    MEM_H(0X182, ctx->r4) = 0;
L_80040298:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
