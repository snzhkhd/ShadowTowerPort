#include "recomp.h"
#include "disable_warnings.h"

void sub_800347F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // lw          $a2, 0x4($a3)
    ctx->r6 = MEM_W(0X4, ctx->r7);
    // lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(0X0, ctx->r7);
    // blez        $a2, L_80034844
    if (SIGNED(ctx->r6) <= 0) {
        // addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
        goto L_80034844;
    }
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_80034810:
    // lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(0XC, ctx->r4);
    // nop

    // beq         $v0, $t0, L_80034830
    if (ctx->r2 == ctx->r8) {
        // nop
    
        goto L_80034830;
    }
    // nop

    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // bne         $v0, $zero, L_80034810
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
        goto L_80034810;
    }
    // addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_80034830:
    // lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(0X4, ctx->r7);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_80034870
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80034870;
    }
    // nop

L_80034844:
    // lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(0X8, ctx->r7);
    // nop

    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80034920
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80034920;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lw          $v0, 0x4($a3)
    ctx->r2 = MEM_W(0X4, ctx->r7);
    // lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(0X0, ctx->r7);
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
L_80034870:
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
    // sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // sw          $zero, 0x48($v0)
    MEM_W(0X48, ctx->r2) = 0;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
    // sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // sh          $v1, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r3;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // sh          $zero, 0x10($v0)
    MEM_H(0X10, ctx->r2) = 0;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // sh          $zero, 0x12($v0)
    MEM_H(0X12, ctx->r2) = 0;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // sh          $v1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r3;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(0X4, ctx->r4);
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // sh          $v1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r3;
    // sb          $zero, 0xA($v0)
    MEM_B(0XA, ctx->r2) = 0;
    // sb          $zero, 0xB($v0)
    MEM_B(0XB, ctx->r2) = 0;
L_80034920:
    // jr          $ra
    // nop

    return;
    // nop

;}
