#include "recomp.h"
#include "disable_warnings.h"

void RCpolyFT3A(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $t0, 0x48($a3)
    ctx->r8 = MEM_W(0X48, ctx->r7);
    // lw          $t1, 0x4C($a3)
    ctx->r9 = MEM_W(0X4C, ctx->r7);
    // lw          $t2, 0x50($a3)
    ctx->r10 = MEM_W(0X50, ctx->r7);
    // cfc2        $t9, $26
    ctx->r25 = gte_cfc2(ctx, 26);
    // lw          $t4, 0x14($t0)
    ctx->r12 = MEM_W(0X14, ctx->r8);
    // lw          $t5, 0x14($t1)
    ctx->r13 = MEM_W(0X14, ctx->r9);
    // lw          $t6, 0x14($t2)
    ctx->r14 = MEM_W(0X14, ctx->r10);
    // sra         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25) >> 1;
    // sltu        $at, $t4, $t8
    ctx->r1 = ctx->r12 < ctx->r24 ? 1 : 0;
    // beq         $at, $zero, L_80075B14
    if (ctx->r1 == 0) {
        // sltu        $at, $t5, $t8
        ctx->r1 = ctx->r13 < ctx->r24 ? 1 : 0;
        goto L_80075B14;
    }
    // sltu        $at, $t5, $t8
    ctx->r1 = ctx->r13 < ctx->r24 ? 1 : 0;
    // beq         $at, $zero, L_80075B14
    if (ctx->r1 == 0) {
        // sltu        $at, $t6, $t8
        ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
        goto L_80075B14;
    }
    // sltu        $at, $t6, $t8
    ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
    // beq         $at, $zero, L_80075B14
    if (ctx->r1 == 0) {
        // nop
    
        goto L_80075B14;
    }
    // nop

    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // jr          $ra
    // nop

    return;
    // nop

L_80075B14:
    // cfc2        $t9, $24
    ctx->r25 = gte_cfc2(ctx, 24);
    // lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(0X4, ctx->r5);
    // lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(0X8, ctx->r5);
    // sra         $t9, $t9, 16
    ctx->r25 = S32(ctx->r25) >> 16;
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // lh          $t4, 0x10($t0)
    ctx->r12 = MEM_HS(0X10, ctx->r8);
    // lh          $t5, 0x10($t1)
    ctx->r13 = MEM_HS(0X10, ctx->r9);
    // lh          $t6, 0x10($t2)
    ctx->r14 = MEM_HS(0X10, ctx->r10);
    // slt         $at, $t8, $t4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r12) ? 1 : 0;
    // beq         $at, $zero, L_80075B64
    if (ctx->r1 == 0) {
        // slt         $at, $t8, $t5
        ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
        goto L_80075B64;
    }
    // slt         $at, $t8, $t5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
    // beq         $at, $zero, L_80075B64
    if (ctx->r1 == 0) {
        // slt         $at, $t8, $t6
        ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
        goto L_80075B64;
    }
    // slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // beq         $at, $zero, L_80075B64
    if (ctx->r1 == 0) {
        // nop
    
        goto L_80075B64;
    }
    // nop

    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // jr          $ra
    // nop

    return;
    // nop

L_80075B64:
    // subu        $t8, $t9, $v0
    ctx->r24 = SUB32(ctx->r25, ctx->r2);
    // slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // beq         $at, $zero, L_80075B90
    if (ctx->r1 == 0) {
        // slt         $at, $t5, $t8
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
        goto L_80075B90;
    }
    // slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // beq         $at, $zero, L_80075B90
    if (ctx->r1 == 0) {
        // slt         $at, $t6, $t8
        ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
        goto L_80075B90;
    }
    // slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // beq         $at, $zero, L_80075B90
    if (ctx->r1 == 0) {
        // nop
    
        goto L_80075B90;
    }
    // nop

    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // jr          $ra
    // nop

    return;
    // nop

L_80075B90:
    // cfc2        $t9, $25
    ctx->r25 = gte_cfc2(ctx, 25);
    // lh          $t4, 0x12($t0)
    ctx->r12 = MEM_HS(0X12, ctx->r8);
    // lh          $t5, 0x12($t1)
    ctx->r13 = MEM_HS(0X12, ctx->r9);
    // lh          $t6, 0x12($t2)
    ctx->r14 = MEM_HS(0X12, ctx->r10);
    // sra         $t9, $t9, 16
    ctx->r25 = S32(ctx->r25) >> 16;
    // addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // slt         $at, $t8, $t4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r12) ? 1 : 0;
    // beq         $at, $zero, L_80075BD0
    if (ctx->r1 == 0) {
        // slt         $at, $t8, $t5
        ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
        goto L_80075BD0;
    }
    // slt         $at, $t8, $t5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
    // beq         $at, $zero, L_80075BD0
    if (ctx->r1 == 0) {
        // slt         $at, $t8, $t6
        ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
        goto L_80075BD0;
    }
    // slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // beq         $at, $zero, L_80075BD0
    if (ctx->r1 == 0) {
        // nop
    
        goto L_80075BD0;
    }
    // nop

    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // jr          $ra
    // nop

    return;
    // nop

L_80075BD0:
    // subu        $t8, $t9, $v1
    ctx->r24 = SUB32(ctx->r25, ctx->r3);
    // slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // beq         $at, $zero, L_80075BFC
    if (ctx->r1 == 0) {
        // slt         $at, $t5, $t8
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
        goto L_80075BFC;
    }
    // slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // beq         $at, $zero, L_80075BFC
    if (ctx->r1 == 0) {
        // slt         $at, $t6, $t8
        ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
        goto L_80075BFC;
    }
    // slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // beq         $at, $zero, L_80075BFC
    if (ctx->r1 == 0) {
        // nop
    
        goto L_80075BFC;
    }
    // nop

    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // jr          $ra
    // nop

    return;
    // nop

L_80075BFC:
    // lh          $t4, 0x0($t0)
    ctx->r12 = MEM_HS(0X0, ctx->r8);
    // lh          $t5, 0x0($t1)
    ctx->r13 = MEM_HS(0X0, ctx->r9);
    // lh          $t6, 0x0($t2)
    ctx->r14 = MEM_HS(0X0, ctx->r10);
    // add         $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // add         $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // add         $t9, $t6, $t4
    ctx->r25 = ADD32(ctx->r14, ctx->r12);
    // sra         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15) >> 1;
    // sra         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24) >> 1;
    // sra         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25) >> 1;
    // sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
    // sh          $t8, 0x18($a3)
    MEM_H(0X18, ctx->r7) = ctx->r24;
    // sh          $t9, 0x30($a3)
    MEM_H(0X30, ctx->r7) = ctx->r25;
    // lh          $t4, 0x2($t0)
    ctx->r12 = MEM_HS(0X2, ctx->r8);
    // lh          $t5, 0x2($t1)
    ctx->r13 = MEM_HS(0X2, ctx->r9);
    // lh          $t6, 0x2($t2)
    ctx->r14 = MEM_HS(0X2, ctx->r10);
    // add         $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // add         $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // add         $t9, $t6, $t4
    ctx->r25 = ADD32(ctx->r14, ctx->r12);
    // sra         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15) >> 1;
    // sra         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24) >> 1;
    // sra         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25) >> 1;
    // sh          $t7, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r15;
    // sh          $t8, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r24;
    // sh          $t9, 0x32($a3)
    MEM_H(0X32, ctx->r7) = ctx->r25;
    // lh          $t4, 0x4($t0)
    ctx->r12 = MEM_HS(0X4, ctx->r8);
    // lh          $t5, 0x4($t1)
    ctx->r13 = MEM_HS(0X4, ctx->r9);
    // lh          $t6, 0x4($t2)
    ctx->r14 = MEM_HS(0X4, ctx->r10);
    // add         $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // add         $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // add         $t9, $t6, $t4
    ctx->r25 = ADD32(ctx->r14, ctx->r12);
    // sra         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15) >> 1;
    // sra         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24) >> 1;
    // sra         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25) >> 1;
    // sh          $t7, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r15;
    // sh          $t8, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = ctx->r24;
    // sh          $t9, 0x34($a3)
    MEM_H(0X34, ctx->r7) = ctx->r25;
    // lwc2        $0, 0x0($a3)
    gte_lwc2(rdram, ctx, 0, 7, 0);
    // lwc2        $1, 0x4($a3)
    gte_lwc2(rdram, ctx, 1, 7, 4);
    // lwc2        $2, 0x18($a3)
    gte_lwc2(rdram, ctx, 2, 7, 24);
    // lwc2        $3, 0x1C($a3)
    gte_lwc2(rdram, ctx, 3, 7, 28);
    // lwc2        $4, 0x30($a3)
    gte_lwc2(rdram, ctx, 4, 7, 48);
    // lwc2        $5, 0x34($a3)
    gte_lwc2(rdram, ctx, 5, 7, 52);
    // lbu         $t4, 0x8($t0)
    ctx->r12 = MEM_BU(0X8, ctx->r8);
    // .word       0x4A280030                   # INVALID     $s1, $t0, 0x30 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A280030);
    // lbu         $t5, 0x8($t1)
    ctx->r13 = MEM_BU(0X8, ctx->r9);
    // lbu         $t6, 0x8($t2)
    ctx->r14 = MEM_BU(0X8, ctx->r10);
    // addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // addu        $t9, $t6, $t4
    ctx->r25 = ADD32(ctx->r14, ctx->r12);
    // srl         $t7, $t7, 1
    ctx->r15 = S32(U32(ctx->r15) >> 1);
    // srl         $t8, $t8, 1
    ctx->r24 = S32(U32(ctx->r24) >> 1);
    // srl         $t9, $t9, 1
    ctx->r25 = S32(U32(ctx->r25) >> 1);
    // sb          $t7, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r15;
    // sb          $t8, 0x20($a3)
    MEM_B(0X20, ctx->r7) = ctx->r24;
    // sb          $t9, 0x38($a3)
    MEM_B(0X38, ctx->r7) = ctx->r25;
    // lbu         $t4, 0x9($t0)
    ctx->r12 = MEM_BU(0X9, ctx->r8);
    // lbu         $t5, 0x9($t1)
    ctx->r13 = MEM_BU(0X9, ctx->r9);
    // lbu         $t6, 0x9($t2)
    ctx->r14 = MEM_BU(0X9, ctx->r10);
    // addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // addu        $t9, $t6, $t4
    ctx->r25 = ADD32(ctx->r14, ctx->r12);
    // srl         $t7, $t7, 1
    ctx->r15 = S32(U32(ctx->r15) >> 1);
    // srl         $t8, $t8, 1
    ctx->r24 = S32(U32(ctx->r24) >> 1);
    // srl         $t9, $t9, 1
    ctx->r25 = S32(U32(ctx->r25) >> 1);
    // sb          $t7, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r15;
    // sb          $t8, 0x21($a3)
    MEM_B(0X21, ctx->r7) = ctx->r24;
    // sb          $t9, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r25;
    // lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(0X0, ctx->r5);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // bne         $t4, $a2, L_80075D88
    if (ctx->r12 != ctx->r6) {
        // nop
    
        goto L_80075D88;
    }
    // nop

    // swc2        $12, 0x10($a3)
    gte_swc2(rdram, ctx, 12, 7, 16);
    // swc2        $13, 0x28($a3)
    gte_swc2(rdram, ctx, 13, 7, 40);
    // swc2        $14, 0x40($a3)
    gte_swc2(rdram, ctx, 14, 7, 64);
    // addu        $v1, $ra, $zero
    ctx->r3 = ADD32(ctx->r31, 0);
    // lw          $t0, 0x4C($a3)
    ctx->r8 = MEM_W(0X4C, ctx->r7);
    // addiu       $t1, $a3, 0x18
    ctx->r9 = ADD32(ctx->r7, 0X18);
    // addiu       $t2, $a3, 0x0
    ctx->r10 = ADD32(ctx->r7, 0X0);
    // jal         0x80075E40
    // nop

    sub_80075E40(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addiu       $t0, $a3, 0x0
    ctx->r8 = ADD32(ctx->r7, 0X0);
    // addiu       $t1, $a3, 0x18
    ctx->r9 = ADD32(ctx->r7, 0X18);
    // addiu       $t2, $a3, 0x30
    ctx->r10 = ADD32(ctx->r7, 0X30);
    // jal         0x80075E40
    // nop

    sub_80075E40(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $t0, 0x48($a3)
    ctx->r8 = MEM_W(0X48, ctx->r7);
    // addiu       $t1, $a3, 0x0
    ctx->r9 = ADD32(ctx->r7, 0X0);
    // addiu       $t2, $a3, 0x30
    ctx->r10 = ADD32(ctx->r7, 0X30);
    // jal         0x80075E40
    // nop

    sub_80075E40(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $t0, 0x50($a3)
    ctx->r8 = MEM_W(0X50, ctx->r7);
    // addiu       $t1, $a3, 0x30
    ctx->r9 = ADD32(ctx->r7, 0X30);
    // addiu       $t2, $a3, 0x18
    ctx->r10 = ADD32(ctx->r7, 0X18);
    // jal         0x80075E40
    // nop

    sub_80075E40(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // addu        $ra, $v1, $zero
    ctx->r31 = ADD32(ctx->r3, 0);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // b           L_80075E34
    // nop

    goto L_80075E34;
    // nop

L_80075D88:
    // swc2        $17, 0x14($a3)
    gte_swc2(rdram, ctx, 17, 7, 20);
    // swc2        $18, 0x2C($a3)
    gte_swc2(rdram, ctx, 18, 7, 44);
    // swc2        $19, 0x44($a3)
    gte_swc2(rdram, ctx, 19, 7, 68);
    // swc2        $12, 0x10($a3)
    gte_swc2(rdram, ctx, 12, 7, 16);
    // swc2        $13, 0x28($a3)
    gte_swc2(rdram, ctx, 13, 7, 40);
    // swc2        $14, 0x40($a3)
    gte_swc2(rdram, ctx, 14, 7, 64);
    // addiu       $a3, $a3, 0x58
    ctx->r7 = ADD32(ctx->r7, 0X58);
    // sw          $ra, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r31;
    // lw          $t4, -0x10($a3)
    ctx->r12 = MEM_W(-0X10, ctx->r7);
    // addiu       $t5, $a3, -0x58
    ctx->r13 = ADD32(ctx->r7, -0X58);
    // addiu       $t6, $a3, -0x28
    ctx->r14 = ADD32(ctx->r7, -0X28);
    // sw          $t4, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r12;
    // sw          $t5, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r13;
    // sw          $t6, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r14;
    // jal         0x80075ACC
    // nop

    RCpolyFT3A(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lw          $t4, -0xC($a3)
    ctx->r12 = MEM_W(-0XC, ctx->r7);
    // addiu       $t5, $a3, -0x40
    ctx->r13 = ADD32(ctx->r7, -0X40);
    // addiu       $t6, $a3, -0x58
    ctx->r14 = ADD32(ctx->r7, -0X58);
    // sw          $t4, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r12;
    // sw          $t5, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r13;
    // sw          $t6, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r14;
    // jal         0x80075ACC
    // nop

    RCpolyFT3A(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lw          $t4, -0x8($a3)
    ctx->r12 = MEM_W(-0X8, ctx->r7);
    // addiu       $t5, $a3, -0x28
    ctx->r13 = ADD32(ctx->r7, -0X28);
    // addiu       $t6, $a3, -0x40
    ctx->r14 = ADD32(ctx->r7, -0X40);
    // sw          $t4, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r12;
    // sw          $t5, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r13;
    // sw          $t6, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r14;
    // jal         0x80075ACC
    // nop

    RCpolyFT3A(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // addiu       $t4, $a3, -0x58
    ctx->r12 = ADD32(ctx->r7, -0X58);
    // addiu       $t5, $a3, -0x40
    ctx->r13 = ADD32(ctx->r7, -0X40);
    // addiu       $t6, $a3, -0x28
    ctx->r14 = ADD32(ctx->r7, -0X28);
    // sw          $t4, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r12;
    // sw          $t5, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r13;
    // sw          $t6, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r14;
    // jal         0x80075ACC
    // nop

    RCpolyFT3A(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lw          $ra, 0x54($a3)
    ctx->r31 = MEM_W(0X54, ctx->r7);
    // addiu       $a3, $a3, -0x58
    ctx->r7 = ADD32(ctx->r7, -0X58);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80075E34:
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // jr          $ra
    // nop

    return;
    // nop

;}
