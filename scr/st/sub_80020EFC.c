#include "recomp.h"
#include "disable_warnings.h"

void sub_80020EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80020F14
    if (ctx->r2 != 0) {
        // addu        $s0, $a0, $zero
        ctx->r16 = ADD32(ctx->r4, 0);
        goto L_80020F14;
    }
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // lw          $v0, 0xE0($t2)
    ctx->r2 = MEM_W(0XE0, ctx->r10);
    // j           L_80020F30
    // addiu       $a0, $v0, 0xA0
    ctx->r4 = ADD32(ctx->r2, 0XA0);
    goto L_80020F30;
    // addiu       $a0, $v0, 0xA0
    ctx->r4 = ADD32(ctx->r2, 0XA0);
L_80020F14:
    // lbu         $v0, 0x6CC2($v1)
    ctx->r2 = MEM_BU(0X6CC2, ctx->r3);
    // nop

    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0xE0($t2)
    ctx->r2 = MEM_W(0XE0, ctx->r10);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
L_80020F30:
    // addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // addu        $v0, $t1, $t9
    ctx->r2 = ADD32(ctx->r9, ctx->r25);
    // sb          $v0, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r2;
    // sb          $v0, 0x25($a0)
    MEM_B(0X25, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // sb          $v0, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $t3, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r11;
    // sb          $t4, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r12;
    // sb          $t5, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r13;
    // sh          $t6, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r14;
    // sh          $t7, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r15;
    // sb          $t0, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r8;
    // sb          $t1, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r9;
    // sb          $v1, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r3;
    // sb          $t1, 0x15($a0)
    MEM_B(0X15, ctx->r4) = ctx->r9;
    // sb          $t0, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r8;
    // sb          $v1, 0x24($a0)
    MEM_B(0X24, ctx->r4) = ctx->r3;
    // sh          $s0, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r16;
    // sh          $s0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r16;
    // sh          $a2, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r6;
    // sh          $a2, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r6;
    // sh          $s1, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r17;
    // sh          $s1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r17;
    // sh          $a3, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r7;
    // beq         $a1, $v0, L_80020FAC
    if (ctx->r5 == ctx->r2) {
        // sh          $a3, 0x1A($a0)
        MEM_H(0X1A, ctx->r4) = ctx->r7;
        goto L_80020FAC;
    }
    // sh          $a3, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r7;
    // addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    // sb          $v0, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r2;
L_80020FAC:
    // jal         0x80079FF8
    // nop

    DrawPrim(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
