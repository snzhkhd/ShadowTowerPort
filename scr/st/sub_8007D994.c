#include "recomp.h"
#include "disable_warnings.h"

void sub_8007D994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lbu         $v1, 0x46($s0)
    ctx->r3 = MEM_BU(0X46, ctx->r16);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $v0, L_8007DA20
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x4
        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
        goto L_8007DA20;
    }
    // slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8007D9CC
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8007D9CC;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $v1, $v0, L_8007D9E0
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007D9E0;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // j           L_8007DAD0
    // nop

    goto L_8007DAD0;
    // nop

L_8007D9CC:
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_8007DA44
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007DA44;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // j           L_8007DAD0
    // nop

    goto L_8007DAD0;
    // nop

L_8007D9E0:
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
    // lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(0X3C, ctx->r16);
    // lbu         $v0, 0x3($v0)
    ctx->r2 = MEM_BU(0X3, ctx->r2);
    // nop

    // sb          $v0, 0xE3($s0)
    MEM_B(0XE3, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(0X4, ctx->r3);
    // lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(0X3C, ctx->r16);
    // sh          $zero, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = 0;
    // sb          $v0, 0xE4($s0)
    MEM_B(0XE4, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(0X5, ctx->r3);
    // lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(0X3C, ctx->r16);
    // sb          $v0, 0xE9($s0)
    MEM_B(0XE9, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x6($v1)
    ctx->r2 = MEM_BU(0X6, ctx->r3);
    // sw          $zero, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = 0;
    // j           L_8007DACC
    // sb          $v0, 0xEA($s0)
    MEM_B(0XEA, ctx->r16) = ctx->r2;
    goto L_8007DACC;
    // sb          $v0, 0xEA($s0)
    MEM_B(0XEA, ctx->r16) = ctx->r2;
L_8007DA20:
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
    // nop

    // lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(0X4, ctx->r2);
    // lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(0X5, ctx->r2);
    // sb          $zero, 0x47($s0)
    MEM_B(0X47, ctx->r16) = 0;
    // sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) << 8;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_8007DACC
    // sh          $v0, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r2;
    goto L_8007DACC;
    // sh          $v0, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r2;
L_8007DA44:
    // lw          $a0, 0xEC($s0)
    ctx->r4 = MEM_W(0XEC, ctx->r16);
    // lbu         $v0, 0x47($s0)
    ctx->r2 = MEM_BU(0X47, ctx->r16);
    // lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(0X3C, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // lbu         $v1, 0x4($v1)
    ctx->r3 = MEM_BU(0X4, ctx->r3);
    // addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // sb          $v0, 0x47($s0)
    MEM_B(0X47, ctx->r16) = ctx->r2;
    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // andi        $v1, $v1, 0x1FC
    ctx->r3 = ctx->r3 & 0X1FC;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // lbu         $v1, 0xEA($s0)
    ctx->r3 = MEM_BU(0XEA, ctx->r16);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_8007DA88
    if (ctx->r2 == 0) {
        // sw          $a0, 0xEC($s0)
        MEM_W(0XEC, ctx->r16) = ctx->r4;
        goto L_8007DA88;
    }
    // sw          $a0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->r4;
L_8007DA80:
    // j           L_8007DAD0
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8007DAD0;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007DA88:
    // jal         0x8007DAE0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8007DAE0(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // slti        $v0, $v0, 0x81
    ctx->r2 = SIGNED(ctx->r2) < 0X81 ? 1 : 0;
    // bne         $v0, $zero, L_8007DAB0
    if (ctx->r2 != 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8007DAB0;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // sb          $v0, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // j           L_8007DA80
    // sb          $v0, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r2;
    goto L_8007DA80;
    // sb          $v0, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r2;
L_8007DAB0:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // addiu       $a1, $s0, 0x63
    ctx->r5 = ADD32(ctx->r16, 0X63);
    // jal         0x8007DB18
    // sb          $v0, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r2;
    sub_8007DB18(rdram, ctx);
    goto after_1;
    // sb          $v0, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r2;
    after_1:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // j           L_8007DA80
    // sb          $v0, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r2;
    goto L_8007DA80;
    // sb          $v0, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r2;
L_8007DACC:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007DAD0:
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
