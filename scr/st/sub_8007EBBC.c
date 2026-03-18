#include "recomp.h"
#include "disable_warnings.h"

void sub_8007EBBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // addiu       $a0, $s0, 0x57
    ctx->r4 = ADD32(ctx->r16, 0X57);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // jal         0x8007EE94
    // addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    bzero_recomp(rdram, ctx);
    goto after_0;
    // addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // lhu         $v0, 0xE6($s0)
    ctx->r2 = MEM_HU(0XE6, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8007ED34
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007ED34;
    }
    // nop

    // lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(0X28, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8007ED34
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007ED34;
    }
    // nop

    // lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(0X34, ctx->r16);
    // nop

    // sltiu       $v0, $v0, 0x7
    ctx->r2 = ctx->r2 < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_8007EC10
    if (ctx->r2 == 0) {
        // addiu       $t1, $zero, 0x6
        ctx->r9 = ADD32(0, 0X6);
        goto L_8007EC10;
    }
    // addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // lbu         $t1, 0x34($s0)
    ctx->r9 = MEM_BU(0X34, ctx->r16);
L_8007EC10:
    // lbu         $v0, 0xE9($s0)
    ctx->r2 = MEM_BU(0XE9, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8007EE28
    if (ctx->r2 == 0) {
        // addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
        goto L_8007EE28;
    }
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
L_8007EC28:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $v0, $t2, $v0
    ctx->r2 = ADD32(ctx->r10, ctx->r2);
    // lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(0X2, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8007EC48
    if (ctx->r2 == 0) {
        // addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
        goto L_8007EC48;
    }
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_8007EC48:
    // addiu       $a1, $s0, 0x5D
    ctx->r5 = ADD32(ctx->r16, 0X5D);
    // lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(0X28, ctx->r16);
    // beq         $t1, $zero, L_8007EC90
    if (ctx->r9 == 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_8007EC90;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8007EC58:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // nop

    // bne         $v0, $t0, L_8007EC7C
    if (ctx->r2 != ctx->r8) {
        // nop
    
        goto L_8007EC7C;
    }
    // nop

    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // bne         $v0, $zero, L_8007ECD0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007ECD0;
    }
    // nop

L_8007EC7C:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // slt         $v0, $v1, $t1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // bne         $v0, $zero, L_8007EC58
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_8007EC58;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8007EC90:
    // beq         $a2, $zero, L_8007ED18
    if (ctx->r6 == 0) {
        // nop
    
        goto L_8007ED18;
    }
    // nop

    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // addu        $v0, $t2, $v0
    ctx->r2 = ADD32(ctx->r10, ctx->r2);
    // lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(0X3, ctx->r2);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E60($v0)
    ctx->r2 = MEM_W(0X7E60, ctx->r2);
    // nop

    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // slti        $v0, $v1, 0x3D
    ctx->r2 = SIGNED(ctx->r3) < 0X3D ? 1 : 0;
    // beq         $v0, $zero, L_8007ECD8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007ECD8;
    }
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // j           L_8007ECDC
    // sw          $v1, 0x7E60($at)
    MEM_W(0X7E60, ctx->r1) = ctx->r3;
    goto L_8007ECDC;
    // sw          $v1, 0x7E60($at)
    MEM_W(0X7E60, ctx->r1) = ctx->r3;
L_8007ECD0:
    // j           L_8007EC90
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    goto L_8007EC90;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8007ECD8:
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8007ECDC:
    // beq         $a2, $zero, L_8007ED18
    if (ctx->r6 == 0) {
        // nop
    
        goto L_8007ED18;
    }
    // nop

    // addiu       $a1, $s0, 0x5D
    ctx->r5 = ADD32(ctx->r16, 0X5D);
    // addiu       $a0, $s0, 0x57
    ctx->r4 = ADD32(ctx->r16, 0X57);
    // beq         $t1, $zero, L_8007ED18
    if (ctx->r9 == 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_8007ED18;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8007ECF4:
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // nop

    // bne         $v0, $t0, L_8007ED08
    if (ctx->r2 != ctx->r8) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_8007ED08;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
L_8007ED08:
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // slt         $v0, $v1, $t1
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // bne         $v0, $zero, L_8007ECF4
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_8007ECF4;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8007ED18:
    // lbu         $v0, 0xE9($s0)
    ctx->r2 = MEM_BU(0XE9, ctx->r16);
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8007EC28
    if (ctx->r2 != 0) {
        // addiu       $t2, $t2, 0x5
        ctx->r10 = ADD32(ctx->r10, 0X5);
        goto L_8007EC28;
    }
    // addiu       $t2, $t2, 0x5
    ctx->r10 = ADD32(ctx->r10, 0X5);
    // j           L_8007EE28
    // nop

    goto L_8007EE28;
    // nop

L_8007ED34:
    // lbu         $v1, 0xE8($s0)
    ctx->r3 = MEM_BU(0XE8, ctx->r16);
    // nop

    // addiu       $v0, $v1, -0x4
    ctx->r2 = ADD32(ctx->r3, -0X4);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8007ED54
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
        goto L_8007ED54;
    }
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // bne         $v1, $v0, L_8007EDE8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8007EDE8;
    }
    // nop

L_8007ED54:
    // lhu         $v0, 0xE6($s0)
    ctx->r2 = MEM_HU(0XE6, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8007EDE8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007EDE8;
    }
    // nop

    // lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(0X34, ctx->r16);
    // nop

    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8007EDE8
    if (ctx->r2 != 0) {
        // addiu       $v1, $zero, 0x40
        ctx->r3 = ADD32(0, 0X40);
        goto L_8007EDE8;
    }
    // addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
    // lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(0X28, ctx->r16);
    // nop

    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // andi        $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 & 0XC0;
    // bne         $v0, $v1, L_8007EE28
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8007EE28;
    }
    // nop

    // lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(0X1, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8007EE28
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007EE28;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E60($v0)
    ctx->r2 = MEM_W(0X7E60, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // slti        $v0, $v0, 0x3D
    ctx->r2 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // beq         $v0, $zero, L_8007EE28
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007EE28;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x58($s0)
    MEM_B(0X58, ctx->r16) = ctx->r2;
    // sb          $v0, 0x57($s0)
    MEM_B(0X57, ctx->r16) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E60($v0)
    ctx->r2 = MEM_W(0X7E60, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // j           L_8007EE28
    // sw          $v0, 0x7E60($at)
    MEM_W(0X7E60, ctx->r1) = ctx->r2;
    goto L_8007EE28;
    // sw          $v0, 0x7E60($at)
    MEM_W(0X7E60, ctx->r1) = ctx->r2;
L_8007EDE8:
    // lbu         $v1, 0xE8($s0)
    ctx->r3 = MEM_BU(0XE8, ctx->r16);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // bne         $v1, $v0, L_8007EE00
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007EE00;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // j           L_8007EE28
    // sb          $v0, 0x57($s0)
    MEM_B(0X57, ctx->r16) = ctx->r2;
    goto L_8007EE28;
    // sb          $v0, 0x57($s0)
    MEM_B(0X57, ctx->r16) = ctx->r2;
L_8007EE00:
    // lhu         $v0, 0xE6($s0)
    ctx->r2 = MEM_HU(0XE6, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8007EE28
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007EE28;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // addiu       $a0, $s0, 0x5
    ctx->r4 = ADD32(ctx->r16, 0X5);
L_8007EE18:
    // sb          $v0, 0x57($a0)
    MEM_B(0X57, ctx->r4) = ctx->r2;
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bgez        $v1, L_8007EE18
    if (SIGNED(ctx->r3) >= 0) {
        // addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
        goto L_8007EE18;
    }
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_8007EE28:
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
