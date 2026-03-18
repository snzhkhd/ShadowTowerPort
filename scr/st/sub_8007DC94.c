#include "recomp.h"
#include "disable_warnings.h"

void sub_8007DC94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // lbu         $v1, 0x46($a1)
    ctx->r3 = MEM_BU(0X46, ctx->r5);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $v0, L_8007DD24
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x4
        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
        goto L_8007DD24;
    }
    // slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8007DCC0
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8007DCC0;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $v1, $v0, L_8007DCD4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007DCD4;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // j           L_8007DF00
    // nop

    goto L_8007DF00;
    // nop

L_8007DCC0:
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_8007DDC8
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007DDC8;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // j           L_8007DF00
    // nop

    goto L_8007DF00;
    // nop

L_8007DCD4:
    // lbu         $a0, 0x47($a1)
    ctx->r4 = MEM_BU(0X47, ctx->r5);
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // lw          $v1, 0x3C($a1)
    ctx->r3 = MEM_W(0X3C, ctx->r5);
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(0X4, ctx->r3);
    // lbu         $v1, 0x5($v1)
    ctx->r3 = MEM_BU(0X5, ctx->r3);
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // lbu         $v0, 0x47($a1)
    ctx->r2 = MEM_BU(0X47, ctx->r5);
    // lbu         $v1, 0xE3($a1)
    ctx->r3 = MEM_BU(0XE3, ctx->r5);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x47($a1)
    MEM_B(0X47, ctx->r5) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8007DF00
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007DF00;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_8007DEFC
    // sb          $zero, 0x47($a1)
    MEM_B(0X47, ctx->r5) = 0;
    goto L_8007DEFC;
    // sb          $zero, 0x47($a1)
    MEM_B(0X47, ctx->r5) = 0;
L_8007DD24:
    // lbu         $v1, 0x47($a1)
    ctx->r3 = MEM_BU(0X47, ctx->r5);
    // lw          $a0, 0x3C($a1)
    ctx->r4 = MEM_W(0X3C, ctx->r5);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(0X4, ctx->r5);
    // lbu         $a0, 0x4($a0)
    ctx->r4 = MEM_BU(0X4, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // lw          $v0, 0x3C($a1)
    ctx->r2 = MEM_W(0X3C, ctx->r5);
    // nop

    // lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(0X5, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // lw          $v0, 0x3C($a1)
    ctx->r2 = MEM_W(0X3C, ctx->r5);
    // nop

    // lbu         $v0, 0x6($v0)
    ctx->r2 = MEM_BU(0X6, ctx->r2);
    // nop

    // sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // lw          $v0, 0x3C($a1)
    ctx->r2 = MEM_W(0X3C, ctx->r5);
    // nop

    // lbu         $v0, 0x7($v0)
    ctx->r2 = MEM_BU(0X7, ctx->r2);
    // nop

    // sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // lw          $v0, 0x3C($a1)
    ctx->r2 = MEM_W(0X3C, ctx->r5);
    // nop

    // lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(0X5, ctx->r2);
    // nop

    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x47($a1)
    ctx->r2 = MEM_BU(0X47, ctx->r5);
    // lbu         $v1, 0xE9($a1)
    ctx->r3 = MEM_BU(0XE9, ctx->r5);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x47($a1)
    MEM_B(0X47, ctx->r5) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8007DF00
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007DF00;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // sb          $zero, 0x47($a1)
    MEM_B(0X47, ctx->r5) = 0;
    // j           L_8007DEFC
    // sb          $zero, 0x48($a1)
    MEM_B(0X48, ctx->r5) = 0;
    goto L_8007DEFC;
    // sb          $zero, 0x48($a1)
    MEM_B(0X48, ctx->r5) = 0;
L_8007DDC8:
    // lbu         $v0, 0x47($a1)
    ctx->r2 = MEM_BU(0X47, ctx->r5);
    // lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(0X8, ctx->r5);
    // lbu         $a0, 0x48($a1)
    ctx->r4 = MEM_BU(0X48, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // bne         $a0, $zero, L_8007DE44
    if (ctx->r4 != 0) {
        // addu        $a3, $v1, $v0
        ctx->r7 = ADD32(ctx->r3, ctx->r2);
        goto L_8007DE44;
    }
    // addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x3C($a1)
    ctx->r2 = MEM_W(0X3C, ctx->r5);
    // nop

    // lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(0X4, ctx->r2);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // sb          $v0, 0x48($a1)
    MEM_B(0X48, ctx->r5) = ctx->r2;
    // sb          $v0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r2;
    // lw          $v0, 0x3C($a1)
    ctx->r2 = MEM_W(0X3C, ctx->r5);
    // lbu         $v1, 0x47($a1)
    ctx->r3 = MEM_BU(0X47, ctx->r5);
    // nop

    // bne         $v1, $zero, L_8007DE1C
    if (ctx->r3 != 0) {
        // addiu       $a2, $v0, 0x5
        ctx->r6 = ADD32(ctx->r2, 0X5);
        goto L_8007DE1C;
    }
    // addiu       $a2, $v0, 0x5
    ctx->r6 = ADD32(ctx->r2, 0X5);
    // lbu         $v0, 0xEA($a1)
    ctx->r2 = MEM_BU(0XEA, ctx->r5);
    // lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(0X8, ctx->r5);
    // j           L_8007DE2C
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    goto L_8007DE2C;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
L_8007DE1C:
    // lbu         $v0, -0x8($a3)
    ctx->r2 = MEM_BU(-0X8, ctx->r7);
    // lw          $v1, -0x4($a3)
    ctx->r3 = MEM_W(-0X4, ctx->r7);
    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // andi        $v0, $v0, 0x1FC
    ctx->r2 = ctx->r2 & 0X1FC;
L_8007DE2C:
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v1, -0x4D28($at)
    MEM_W(-0X4D28, ctx->r1) = ctx->r3;
    // j           L_8007DE54
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    goto L_8007DE54;
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_8007DE44:
    // lw          $v0, 0x3C($a1)
    ctx->r2 = MEM_W(0X3C, ctx->r5);
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // addiu       $a2, $v0, 0x2
    ctx->r6 = ADD32(ctx->r2, 0X2);
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_8007DE54:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a0, $v0, L_8007DEA8
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_8007DEA8;
    }
    // nop

    // lui         $a3, 0x801F
    ctx->r7 = S32(0X801F << 16);
    // addiu       $a3, $a3, -0x4D28
    ctx->r7 = ADD32(ctx->r7, -0X4D28);
    // addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8007DE6C:
    // lbu         $v0, 0x48($a1)
    ctx->r2 = MEM_BU(0X48, ctx->r5);
    // nop

    // beq         $v0, $zero, L_8007DEC0
    if (ctx->r2 == 0) {
        // addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
        goto L_8007DEC0;
    }
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(0X0, ctx->r6);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // lbu         $v0, 0x48($a1)
    ctx->r2 = MEM_BU(0X48, ctx->r5);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $a0, $t0, L_8007DE6C
    if (ctx->r4 != ctx->r8) {
        // sb          $v0, 0x48($a1)
        MEM_B(0X48, ctx->r5) = ctx->r2;
        goto L_8007DE6C;
    }
    // sb          $v0, 0x48($a1)
    MEM_B(0X48, ctx->r5) = ctx->r2;
L_8007DEA8:
    // lbu         $v0, 0x48($a1)
    ctx->r2 = MEM_BU(0X48, ctx->r5);
    // nop

    // beq         $v0, $zero, L_8007DEC0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007DEC0;
    }
    // nop

L_8007DEB8:
    // j           L_8007DF00
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8007DF00;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007DEC0:
    // lbu         $v0, 0x47($a1)
    ctx->r2 = MEM_BU(0X47, ctx->r5);
    // lbu         $v1, 0xEA($a1)
    ctx->r3 = MEM_BU(0XEA, ctx->r5);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x47($a1)
    MEM_B(0X47, ctx->r5) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8007DEF4
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007DEF4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // sb          $v1, 0x49($a1)
    MEM_B(0X49, ctx->r5) = ctx->r3;
    // addiu       $v1, $zero, 0xFE
    ctx->r3 = ADD32(0, 0XFE);
    // j           L_8007DF00
    // sb          $v1, 0x46($a1)
    MEM_B(0X46, ctx->r5) = ctx->r3;
    goto L_8007DF00;
    // sb          $v1, 0x46($a1)
    MEM_B(0X46, ctx->r5) = ctx->r3;
L_8007DEF4:
    // j           L_8007DEB8
    // sb          $zero, 0x48($a1)
    MEM_B(0X48, ctx->r5) = 0;
    goto L_8007DEB8;
    // sb          $zero, 0x48($a1)
    MEM_B(0X48, ctx->r5) = 0;
L_8007DEFC:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007DF00:
    // jr          $ra
    // nop

    return;
    // nop

;}
