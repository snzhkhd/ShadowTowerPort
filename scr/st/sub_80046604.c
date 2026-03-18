#include "recomp.h"
#include "disable_warnings.h"

void sub_80046604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v1, $v0, 0x5948
    ctx->r3 = ADD32(ctx->r2, 0X5948);
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // lhu         $t7, 0x44CA($v1)
    ctx->r15 = MEM_HU(0X44CA, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $t7, $t7, -0x1
    ctx->r15 = ADD32(ctx->r15, -0X1);
    // beq         $t7, $v0, L_800468A0
    if (ctx->r15 == ctx->r2) {
        // lui         $a1, 0x1F80
        ctx->r5 = S32(0X1F80 << 16);
        goto L_800468A0;
    }
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $s3, $v0, -0x4130
    ctx->r19 = ADD32(ctx->r2, -0X4130);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $s2, $v0, 0x42C
    ctx->r18 = ADD32(ctx->r2, 0X42C);
    // addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // addiu       $s1, $s0, 0x11B0
    ctx->r17 = ADD32(ctx->r16, 0X11B0);
    // addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80046658:
    // sll         $v0, $t7, 1
    ctx->r2 = S32(ctx->r15) << 1;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lhu         $v0, 0x44CE($v0)
    ctx->r2 = MEM_HU(0X44CE, ctx->r2);
    // nop

    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(0X3, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sh          $v0, 0x20($a1)
    MEM_H(0X20, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x20($a1)
    ctx->r2 = MEM_HU(0X20, ctx->r5);
    // nop

    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(0X0, ctx->r2);
    // lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(0X4, ctx->r2);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(0X8, ctx->r2);
    // lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(0XC, ctx->r2);
    // lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(0X10, ctx->r2);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // sll         $v0, $t7, 4
    ctx->r2 = S32(ctx->r15) << 4;
    // addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(0X0, ctx->r2);
    // lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(0X4, ctx->r2);
    // lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(0X8, ctx->r2);
    // ctc2        $t4, $5
    gte_ctc2(ctx, 12, 5);
    // ctc2        $t5, $6
    gte_ctc2(ctx, 13, 6);
    // ctc2        $t6, $7
    gte_ctc2(ctx, 14, 7);
    // lw          $a3, 0x10($a1)
    ctx->r7 = MEM_W(0X10, ctx->r5);
    // lw          $t6, 0x14($a1)
    ctx->r14 = MEM_W(0X14, ctx->r5);
    // lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(0X0, ctx->r3);
    // lw          $t5, 0x18($a1)
    ctx->r13 = MEM_W(0X18, ctx->r5);
    // lw          $t3, 0x1C($a1)
    ctx->r11 = MEM_W(0X1C, ctx->r5);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(0X4, ctx->r5);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(0X4, ctx->r4);
    // addu        $t4, $v0, $zero
    ctx->r12 = ADD32(ctx->r2, 0);
    // sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6) << 4;
    // addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // bne         $v0, $zero, L_800468A0
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
        goto L_800468A0;
    }
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // beq         $a2, $t9, L_80046840
    if (ctx->r6 == ctx->r25) {
        // addiu       $a0, $a3, 0x8
        ctx->r4 = ADD32(ctx->r7, 0X8);
        goto L_80046840;
    }
    // addiu       $a0, $a3, 0x8
    ctx->r4 = ADD32(ctx->r7, 0X8);
    // addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // addiu       $t1, $t5, 0x8
    ctx->r9 = ADD32(ctx->r13, 0X8);
    // addiu       $t0, $t6, 0x8
    ctx->r8 = ADD32(ctx->r14, 0X8);
L_80046760:
    // lwc2        $0, 0x0($t4)
    gte_lwc2(rdram, ctx, 0, 12, 0);
    // lwc2        $1, 0x4($t4)
    gte_lwc2(rdram, ctx, 1, 12, 4);
    // nop

    // nop

    // .word       0x4A480012                   # INVALID     $s2, $t0, 0x12 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A480012);
    // swc2        $25, 0x0($a3)
    gte_swc2(rdram, ctx, 25, 7, 0);
    // swc2        $26, 0x4($a3)
    gte_swc2(rdram, ctx, 26, 7, 4);
    // swc2        $27, 0x8($a3)
    gte_swc2(rdram, ctx, 27, 7, 8);
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // lw          $v1, 0xE4($a1)
    ctx->r3 = MEM_W(0XE4, ctx->r5);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(-0X4, ctx->r4);
    // lw          $v1, 0xE8($a1)
    ctx->r3 = MEM_W(0XE8, ctx->r5);
    // addiu       $t4, $t4, 0x8
    ctx->r12 = ADD32(ctx->r12, 0X8);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r2;
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // lw          $v1, 0xEC($a1)
    ctx->r3 = MEM_W(0XEC, ctx->r5);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // lw          $v1, 0xF4($a1)
    ctx->r3 = MEM_W(0XF4, ctx->r5);
    // addiu       $t6, $t6, 0x10
    ctx->r14 = ADD32(ctx->r14, 0X10);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(-0X4, ctx->r4);
    // lw          $v1, 0xF8($a1)
    ctx->r3 = MEM_W(0XF8, ctx->r5);
    // addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r2;
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // lw          $v1, 0xFC($a1)
    ctx->r3 = MEM_W(0XFC, ctx->r5);
    // addiu       $t5, $t5, 0x10
    ctx->r13 = ADD32(ctx->r13, 0X10);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // lw          $v1, 0x104($a1)
    ctx->r3 = MEM_W(0X104, ctx->r5);
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(-0X4, ctx->r4);
    // lw          $v1, 0x108($a1)
    ctx->r3 = MEM_W(0X108, ctx->r5);
    // addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r2;
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // lw          $v1, 0x10C($a1)
    ctx->r3 = MEM_W(0X10C, ctx->r5);
    // addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // bne         $a2, $t8, L_80046760
    if (ctx->r6 != ctx->r24) {
        // addiu       $t2, $t2, 0x10
        ctx->r10 = ADD32(ctx->r10, 0X10);
        goto L_80046760;
    }
    // addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
L_80046840:
    // addiu       $t7, $t7, -0x1
    ctx->r15 = ADD32(ctx->r15, -0X1);
    // lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(0X4, ctx->r5);
    // lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(0X4, ctx->r5);
    // lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(0X4, ctx->r2);
    // lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(0X10, ctx->r5);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(0X4, ctx->r4);
    // lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(0X14, ctx->r5);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    // lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(0X4, ctx->r4);
    // lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(0X18, ctx->r5);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r2;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // lw          $v1, 0x1C($a1)
    ctx->r3 = MEM_W(0X1C, ctx->r5);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // bne         $t7, $t9, L_80046658
    if (ctx->r15 != ctx->r25) {
        // sw          $v1, 0x1C($a1)
        MEM_W(0X1C, ctx->r5) = ctx->r3;
        goto L_80046658;
    }
    // sw          $v1, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r3;
L_800468A0:
    // lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(0X18, ctx->r29);
    // lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(0X14, ctx->r29);
    // lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(0X10, ctx->r29);
    // lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(0XC, ctx->r29);
    // lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(0X8, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
