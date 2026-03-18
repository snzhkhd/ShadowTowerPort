#include "recomp.h"
#include "disable_warnings.h"

void _spu_t(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $sp, 0x1C
    ctx->r16 = ADD32(ctx->r29, 0X1C);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // beq         $a0, $a2, L_8006C2D4
    if (ctx->r4 == ctx->r6) {
        // sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
        goto L_8006C2D4;
    }
    // sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8006C290
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8006C290;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $a0, $zero, L_8006C340
    if (ctx->r4 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8006C340;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_8006C4B8
    // nop

    goto L_8006C4B8;
    // nop

L_8006C290:
    // beq         $a0, $v0, L_8006C2A8
    if (ctx->r4 == ctx->r2) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8006C2A8;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $a0, $v0, L_8006C3A8
    if (ctx->r4 == ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8006C3A8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_8006C4B8
    // nop

    goto L_8006C4B8;
    // nop

L_8006C2A8:
    // lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(0X1C, ctx->r29);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD68($v0)
    ctx->r2 = MEM_W(0XD68, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // srlv        $v0, $a0, $v0
    ctx->r2 = S32(U32(ctx->r4) >> (ctx->r2 & 31));
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sh          $v0, 0xD58($at)
    MEM_H(0XD58, ctx->r1) = ctx->r2;
    // sh          $v0, 0x1A6($v1)
    MEM_H(0X1A6, ctx->r3) = ctx->r2;
    // j           L_8006C4B8
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8006C4B8;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006C2D4:
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0xD40($a1)
    ctx->r5 = MEM_W(0XD40, ctx->r5);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lhu         $a0, 0xD58($a0)
    ctx->r4 = MEM_HU(0XD58, ctx->r4);
    // lhu         $v0, 0x1A6($a1)
    ctx->r2 = MEM_HU(0X1A6, ctx->r5);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xD90($at)
    MEM_W(0XD90, ctx->r1) = 0;
    // beq         $v0, $a0, L_8006C318
    if (ctx->r2 == ctx->r4) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_8006C318;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006C2FC:
    // sltiu       $v0, $v1, 0xF01
    ctx->r2 = ctx->r3 < 0XF01 ? 1 : 0;
    // beq         $v0, $zero, L_8006C4B8
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
        goto L_8006C4B8;
    }
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // lhu         $v0, 0x1A6($a1)
    ctx->r2 = MEM_HU(0X1A6, ctx->r5);
    // nop

    // bne         $v0, $a0, L_8006C2FC
    if (ctx->r2 != ctx->r4) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8006C2FC;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006C318:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // nop

    // andi        $v0, $v0, 0xFFCF
    ctx->r2 = ctx->r2 & 0XFFCF;
    // ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // sh          $v0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r2;
    // j           L_8006C4B8
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8006C4B8;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006C340:
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0xD40($a1)
    ctx->r5 = MEM_W(0XD40, ctx->r5);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lhu         $a0, 0xD58($a0)
    ctx->r4 = MEM_HU(0XD58, ctx->r4);
    // lhu         $v0, 0x1A6($a1)
    ctx->r2 = MEM_HU(0X1A6, ctx->r5);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $a2, 0xD90($at)
    MEM_W(0XD90, ctx->r1) = ctx->r6;
    // beq         $v0, $a0, L_8006C384
    if (ctx->r2 == ctx->r4) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_8006C384;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006C368:
    // sltiu       $v0, $v1, 0xF01
    ctx->r2 = ctx->r3 < 0XF01 ? 1 : 0;
    // beq         $v0, $zero, L_8006C4B8
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
        goto L_8006C4B8;
    }
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // lhu         $v0, 0x1A6($a1)
    ctx->r2 = MEM_HU(0X1A6, ctx->r5);
    // nop

    // bne         $v0, $a0, L_8006C368
    if (ctx->r2 != ctx->r4) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8006C368;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006C384:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD40($v1)
    ctx->r3 = MEM_W(0XD40, ctx->r3);
    // nop

    // lhu         $v0, 0x1AA($v1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x30
    ctx->r2 = ctx->r2 | 0X30;
    // sh          $v0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r2;
    // j           L_8006C4B8
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8006C4B8;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006C3A8:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD90($v0)
    ctx->r2 = MEM_W(0XD90, ctx->r2);
    // nop

    // bne         $v0, $a2, L_8006C3C0
    if (ctx->r2 != ctx->r6) {
        // addiu       $a0, $zero, 0x20
        ctx->r4 = ADD32(0, 0X20);
        goto L_8006C3C0;
    }
    // addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
L_8006C3C0:
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0xD40($a1)
    ctx->r5 = MEM_W(0XD40, ctx->r5);
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // lhu         $v0, 0x1AA($a1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r5);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // beq         $v0, $a0, L_8006C400
    if (ctx->r2 == ctx->r4) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8006C400;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006C3E0:
    // sltiu       $v0, $v1, 0xF01
    ctx->r2 = ctx->r3 < 0XF01 ? 1 : 0;
    // beq         $v0, $zero, L_8006C4B8
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
        goto L_8006C4B8;
    }
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // lhu         $v0, 0x1AA($a1)
    ctx->r2 = MEM_HU(0X1AA, ctx->r5);
    // nop

    // andi        $v0, $v0, 0x30
    ctx->r2 = ctx->r2 & 0X30;
    // bne         $v0, $a0, L_8006C3E0
    if (ctx->r2 != ctx->r4) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8006C3E0;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8006C400:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD90($v1)
    ctx->r3 = MEM_W(0XD90, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8006C424
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8006C424;
    }
    // nop

    // jal         0x8006C754
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    sub_8006C754(rdram, ctx);
    goto after_0;
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_0:
    // j           L_8006C430
    // lui         $a2, 0x100
    ctx->r6 = S32(0X100 << 16);
    goto L_8006C430;
    // lui         $a2, 0x100
    ctx->r6 = S32(0X100 << 16);
L_8006C424:
    // jal         0x8006C72C
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    sub_8006C72C(rdram, ctx);
    goto after_1;
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_1:
    // lui         $a2, 0x100
    ctx->r6 = S32(0X100 << 16);
L_8006C430:
    // lw          $a0, -0x4($s0)
    ctx->r4 = MEM_W(-0X4, ctx->r16);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $a0, 0xD94($at)
    MEM_W(0XD94, ctx->r1) = ctx->r4;
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0xD44($a1)
    ctx->r5 = MEM_W(0XD44, ctx->r5);
    // srl         $v1, $a0, 6
    ctx->r3 = S32(U32(ctx->r4) >> 6);
    // andi        $v0, $a0, 0x3F
    ctx->r2 = ctx->r4 & 0X3F;
    // sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xD94($a0)
    ctx->r4 = MEM_W(0XD94, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v1, 0xD98($at)
    MEM_W(0XD98, ctx->r1) = ctx->r3;
    // sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD98($v0)
    ctx->r2 = MEM_W(0XD98, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD48($v1)
    ctx->r3 = MEM_W(0XD48, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xD90($v1)
    ctx->r3 = MEM_W(0XD90, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8006C4A4
    if (ctx->r3 != ctx->r2) {
        // ori         $a2, $a2, 0x201
        ctx->r6 = ctx->r6 | 0X201;
        goto L_8006C4A4;
    }
    // ori         $a2, $a2, 0x201
    ctx->r6 = ctx->r6 | 0X201;
    // lui         $a2, 0x100
    ctx->r6 = S32(0X100 << 16);
    // ori         $a2, $a2, 0x200
    ctx->r6 = ctx->r6 | 0X200;
L_8006C4A4:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD4C($v0)
    ctx->r2 = MEM_W(0XD4C, ctx->r2);
    // nop

    // sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006C4B8:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
