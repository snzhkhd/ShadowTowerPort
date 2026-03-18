#include "recomp.h"
#include "disable_warnings.h"

void sub_80021518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addu        $t9, $a0, $zero
    ctx->r25 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v1, 0x304($s1)
    ctx->r3 = MEM_W(0X304, ctx->r17);
    // lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(0X30, ctx->r29);
    // lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(0X34, ctx->r29);
    // lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(0X38, ctx->r29);
    // lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(0X3C, ctx->r29);
    // lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(0X44, ctx->r29);
    // lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(0X48, ctx->r29);
    // lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(0X4C, ctx->r29);
    // lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(0X50, ctx->r29);
    // lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(0X54, ctx->r29);
    // lbu         $s2, 0x40($sp)
    ctx->r18 = MEM_BU(0X40, ctx->r29);
    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_80021638
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80021638;
    }
    // nop

    // sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lw          $v0, 0x328($s1)
    ctx->r2 = MEM_W(0X328, ctx->r17);
    // addu        $v1, $t0, $t7
    ctx->r3 = ADD32(ctx->r8, ctx->r15);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($s1)
    MEM_W(0X328, ctx->r17) = ctx->r2;
    // addu        $v0, $t1, $t8
    ctx->r2 = ADD32(ctx->r9, ctx->r24);
    // sb          $t2, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r10;
    // sb          $t3, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r11;
    // sb          $t4, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r12;
    // sh          $t5, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r13;
    // sh          $t6, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r14;
    // sb          $t0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r8;
    // sb          $t1, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r9;
    // sb          $v1, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r3;
    // sb          $t1, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r9;
    // sb          $t0, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r8;
    // sb          $v0, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r2;
    // sb          $v1, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r3;
    // sb          $v0, 0x25($s0)
    MEM_B(0X25, ctx->r16) = ctx->r2;
    // sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
    // sh          $t9, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r25;
    // sh          $a2, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r6;
    // sh          $a2, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r6;
    // sh          $a1, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r5;
    // sh          $a1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r5;
    // sh          $a3, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r7;
    // jal         0x8007C814
    // sh          $a3, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r7;
    SetPolyFT4(rdram, ctx);
    goto after_0;
    // sh          $a3, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r7;
    after_0:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $s2, $v0, L_80021614
    if (ctx->r18 == ctx->r2) {
        // addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
        goto L_80021614;
    }
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8007C7E4
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    SetSemiTrans(rdram, ctx);
    goto after_1;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_80021614:
    // lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(0X58, ctx->r29);
    // lw          $v0, 0xE4($s1)
    ctx->r2 = MEM_W(0XE4, ctx->r17);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // jal         0x8007C764
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    AddPrim(rdram, ctx);
    goto after_2;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_2:
    // lw          $v0, 0x324($s1)
    ctx->r2 = MEM_W(0X324, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x324($s1)
    MEM_W(0X324, ctx->r17) = ctx->r2;
L_80021638:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
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
