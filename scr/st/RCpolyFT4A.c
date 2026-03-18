#include "recomp.h"
#include "disable_warnings.h"

void RCpolyFT4A(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $t0, 0x78($a3)
    ctx->r8 = MEM_W(0X78, ctx->r7);
    // lw          $t1, 0x7C($a3)
    ctx->r9 = MEM_W(0X7C, ctx->r7);
    // lw          $t2, 0x80($a3)
    ctx->r10 = MEM_W(0X80, ctx->r7);
    // lw          $t3, 0x84($a3)
    ctx->r11 = MEM_W(0X84, ctx->r7);
    // cfc2        $t9, $26
    ctx->r25 = gte_cfc2(ctx, 26);
    // lw          $t4, 0x14($t0)
    ctx->r12 = MEM_W(0X14, ctx->r8);
    // lw          $t5, 0x14($t1)
    ctx->r13 = MEM_W(0X14, ctx->r9);
    // lw          $t6, 0x14($t2)
    ctx->r14 = MEM_W(0X14, ctx->r10);
    // lw          $t7, 0x14($t3)
    ctx->r15 = MEM_W(0X14, ctx->r11);
    // sra         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25) >> 1;
    // sltu        $at, $t4, $t8
    ctx->r1 = ctx->r12 < ctx->r24 ? 1 : 0;
    // beq         $at, $zero, L_800763C4
    if (ctx->r1 == 0) {
        // sltu        $at, $t5, $t8
        ctx->r1 = ctx->r13 < ctx->r24 ? 1 : 0;
        goto L_800763C4;
    }
    // sltu        $at, $t5, $t8
    ctx->r1 = ctx->r13 < ctx->r24 ? 1 : 0;
    // beq         $at, $zero, L_800763C4
    if (ctx->r1 == 0) {
        // sltu        $at, $t6, $t8
        ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
        goto L_800763C4;
    }
    // sltu        $at, $t6, $t8
    ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
    // beq         $at, $zero, L_800763C4
    if (ctx->r1 == 0) {
        // sltu        $at, $t7, $t8
        ctx->r1 = ctx->r15 < ctx->r24 ? 1 : 0;
        goto L_800763C4;
    }
    // sltu        $at, $t7, $t8
    ctx->r1 = ctx->r15 < ctx->r24 ? 1 : 0;
    // beq         $at, $zero, L_800763C4
    if (ctx->r1 == 0) {
        // nop
    
        goto L_800763C4;
    }
    // nop

    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // jr          $ra
    // nop

    return;
    // nop

L_800763C4:
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
    // lh          $t7, 0x10($t3)
    ctx->r15 = MEM_HS(0X10, ctx->r11);
    // slt         $at, $t8, $t4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r12) ? 1 : 0;
    // beq         $at, $zero, L_80076420
    if (ctx->r1 == 0) {
        // slt         $at, $t8, $t5
        ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
        goto L_80076420;
    }
    // slt         $at, $t8, $t5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
    // beq         $at, $zero, L_80076420
    if (ctx->r1 == 0) {
        // slt         $at, $t8, $t6
        ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
        goto L_80076420;
    }
    // slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // beq         $at, $zero, L_80076420
    if (ctx->r1 == 0) {
        // slt         $at, $t8, $t7
        ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
        goto L_80076420;
    }
    // slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // beq         $at, $zero, L_80076420
    if (ctx->r1 == 0) {
        // nop
    
        goto L_80076420;
    }
    // nop

    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // jr          $ra
    // nop

    return;
    // nop

L_80076420:
    // subu        $t8, $t9, $v0
    ctx->r24 = SUB32(ctx->r25, ctx->r2);
    // slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // beq         $at, $zero, L_80076454
    if (ctx->r1 == 0) {
        // slt         $at, $t5, $t8
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
        goto L_80076454;
    }
    // slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // beq         $at, $zero, L_80076454
    if (ctx->r1 == 0) {
        // slt         $at, $t6, $t8
        ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
        goto L_80076454;
    }
    // slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // beq         $at, $zero, L_80076454
    if (ctx->r1 == 0) {
        // slt         $at, $t7, $t8
        ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
        goto L_80076454;
    }
    // slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // beq         $at, $zero, L_80076454
    if (ctx->r1 == 0) {
        // nop
    
        goto L_80076454;
    }
    // nop

    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // jr          $ra
    // nop

    return;
    // nop

L_80076454:
    // cfc2        $t9, $25
    ctx->r25 = gte_cfc2(ctx, 25);
    // lh          $t4, 0x12($t0)
    ctx->r12 = MEM_HS(0X12, ctx->r8);
    // lh          $t5, 0x12($t1)
    ctx->r13 = MEM_HS(0X12, ctx->r9);
    // lh          $t6, 0x12($t2)
    ctx->r14 = MEM_HS(0X12, ctx->r10);
    // lh          $t7, 0x12($t3)
    ctx->r15 = MEM_HS(0X12, ctx->r11);
    // sra         $t9, $t9, 16
    ctx->r25 = S32(ctx->r25) >> 16;
    // addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // slt         $at, $t8, $t4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r12) ? 1 : 0;
    // beq         $at, $zero, L_800764A0
    if (ctx->r1 == 0) {
        // slt         $at, $t8, $t5
        ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
        goto L_800764A0;
    }
    // slt         $at, $t8, $t5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
    // beq         $at, $zero, L_800764A0
    if (ctx->r1 == 0) {
        // slt         $at, $t8, $t6
        ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
        goto L_800764A0;
    }
    // slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // beq         $at, $zero, L_800764A0
    if (ctx->r1 == 0) {
        // slt         $at, $t8, $t7
        ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
        goto L_800764A0;
    }
    // slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // beq         $at, $zero, L_800764A0
    if (ctx->r1 == 0) {
        // nop
    
        goto L_800764A0;
    }
    // nop

    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // jr          $ra
    // nop

    return;
    // nop

L_800764A0:
    // subu        $t8, $t9, $v1
    ctx->r24 = SUB32(ctx->r25, ctx->r3);
    // slt         $at, $t4, $t8
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r24) ? 1 : 0;
    // beq         $at, $zero, L_800764D4
    if (ctx->r1 == 0) {
        // slt         $at, $t5, $t8
        ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
        goto L_800764D4;
    }
    // slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // beq         $at, $zero, L_800764D4
    if (ctx->r1 == 0) {
        // slt         $at, $t6, $t8
        ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
        goto L_800764D4;
    }
    // slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // beq         $at, $zero, L_800764D4
    if (ctx->r1 == 0) {
        // slt         $at, $t7, $t8
        ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
        goto L_800764D4;
    }
    // slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // beq         $at, $zero, L_800764D4
    if (ctx->r1 == 0) {
        // nop
    
        goto L_800764D4;
    }
    // nop

    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // jr          $ra
    // nop

    return;
    // nop

L_800764D4:
    // lh          $t4, 0x0($t0)
    ctx->r12 = MEM_HS(0X0, ctx->r8);
    // lh          $t5, 0x0($t1)
    ctx->r13 = MEM_HS(0X0, ctx->r9);
    // lh          $t6, 0x0($t2)
    ctx->r14 = MEM_HS(0X0, ctx->r10);
    // lh          $t7, 0x0($t3)
    ctx->r15 = MEM_HS(0X0, ctx->r11);
    // add         $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // add         $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // sra         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24) >> 1;
    // sra         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25) >> 1;
    // sh          $t8, 0x30($a3)
    MEM_H(0X30, ctx->r7) = ctx->r24;
    // sh          $t9, 0x18($a3)
    MEM_H(0X18, ctx->r7) = ctx->r25;
    // add         $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // add         $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // add         $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // sra         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24) >> 1;
    // sra         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25) >> 1;
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
    // sh          $t9, 0x48($a3)
    MEM_H(0X48, ctx->r7) = ctx->r25;
    // sh          $v1, 0x60($a3)
    MEM_H(0X60, ctx->r7) = ctx->r3;
    // lh          $t4, 0x2($t0)
    ctx->r12 = MEM_HS(0X2, ctx->r8);
    // lh          $t5, 0x2($t1)
    ctx->r13 = MEM_HS(0X2, ctx->r9);
    // lh          $t6, 0x2($t2)
    ctx->r14 = MEM_HS(0X2, ctx->r10);
    // lh          $t7, 0x2($t3)
    ctx->r15 = MEM_HS(0X2, ctx->r11);
    // add         $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // add         $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // sra         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24) >> 1;
    // sra         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25) >> 1;
    // sh          $t8, 0x32($a3)
    MEM_H(0X32, ctx->r7) = ctx->r24;
    // sh          $t9, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r25;
    // add         $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // add         $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // add         $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // sra         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24) >> 1;
    // sra         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25) >> 1;
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // sh          $t8, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r24;
    // sh          $t9, 0x4A($a3)
    MEM_H(0X4A, ctx->r7) = ctx->r25;
    // sh          $v1, 0x62($a3)
    MEM_H(0X62, ctx->r7) = ctx->r3;
    // lh          $t4, 0x4($t0)
    ctx->r12 = MEM_HS(0X4, ctx->r8);
    // lh          $t5, 0x4($t1)
    ctx->r13 = MEM_HS(0X4, ctx->r9);
    // lh          $t6, 0x4($t2)
    ctx->r14 = MEM_HS(0X4, ctx->r10);
    // lh          $t7, 0x4($t3)
    ctx->r15 = MEM_HS(0X4, ctx->r11);
    // add         $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // add         $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // sra         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24) >> 1;
    // sra         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25) >> 1;
    // sh          $t8, 0x34($a3)
    MEM_H(0X34, ctx->r7) = ctx->r24;
    // sh          $t9, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = ctx->r25;
    // add         $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // add         $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // add         $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // sra         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24) >> 1;
    // sra         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25) >> 1;
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // sh          $t8, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r24;
    // sh          $t9, 0x4C($a3)
    MEM_H(0X4C, ctx->r7) = ctx->r25;
    // sh          $v1, 0x64($a3)
    MEM_H(0X64, ctx->r7) = ctx->r3;
    // lwc2        $0, 0x0($a3)
    gte_lwc2(rdram, ctx, 0, 7, 0);
    // lwc2        $1, 0x4($a3)
    gte_lwc2(rdram, ctx, 1, 7, 4);
    // lwc2        $2, 0x18($a3)
    gte_lwc2(rdram, ctx, 2, 7, 24);
    // lwc2        $3, 0x1C($a3)
    gte_lwc2(rdram, ctx, 3, 7, 28);
    // lwc2        $4, 0x60($a3)
    gte_lwc2(rdram, ctx, 4, 7, 96);
    // lwc2        $5, 0x64($a3)
    gte_lwc2(rdram, ctx, 5, 7, 100);
    // lbu         $t4, 0x8($t0)
    ctx->r12 = MEM_BU(0X8, ctx->r8);
    // .word       0x4A280030                   # INVALID     $s1, $t0, 0x30 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A280030);
    // lbu         $t5, 0x8($t1)
    ctx->r13 = MEM_BU(0X8, ctx->r9);
    // lbu         $t6, 0x8($t2)
    ctx->r14 = MEM_BU(0X8, ctx->r10);
    // lbu         $t7, 0x8($t3)
    ctx->r15 = MEM_BU(0X8, ctx->r11);
    // add         $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // add         $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // sra         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24) >> 1;
    // sra         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25) >> 1;
    // sb          $t8, 0x38($a3)
    MEM_B(0X38, ctx->r7) = ctx->r24;
    // sb          $t9, 0x20($a3)
    MEM_B(0X20, ctx->r7) = ctx->r25;
    // add         $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // add         $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // add         $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // sra         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24) >> 1;
    // sra         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25) >> 1;
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // sb          $t8, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r24;
    // sb          $t9, 0x50($a3)
    MEM_B(0X50, ctx->r7) = ctx->r25;
    // sb          $v1, 0x68($a3)
    MEM_B(0X68, ctx->r7) = ctx->r3;
    // swc2        $12, 0x10($a3)
    gte_swc2(rdram, ctx, 12, 7, 16);
    // swc2        $13, 0x28($a3)
    gte_swc2(rdram, ctx, 13, 7, 40);
    // swc2        $14, 0x70($a3)
    gte_swc2(rdram, ctx, 14, 7, 112);
    // swc2        $17, 0x14($a3)
    gte_swc2(rdram, ctx, 17, 7, 20);
    // swc2        $18, 0x2C($a3)
    gte_swc2(rdram, ctx, 18, 7, 44);
    // swc2        $19, 0x74($a3)
    gte_swc2(rdram, ctx, 19, 7, 116);
    // lwc2        $0, 0x30($a3)
    gte_lwc2(rdram, ctx, 0, 7, 48);
    // lwc2        $1, 0x34($a3)
    gte_lwc2(rdram, ctx, 1, 7, 52);
    // lwc2        $2, 0x48($a3)
    gte_lwc2(rdram, ctx, 2, 7, 72);
    // lwc2        $3, 0x4C($a3)
    gte_lwc2(rdram, ctx, 3, 7, 76);
    // lbu         $t4, 0x9($t0)
    ctx->r12 = MEM_BU(0X9, ctx->r8);
    // .word       0x4A280030                   # INVALID     $s1, $t0, 0x30 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A280030);
    // lbu         $t5, 0x9($t1)
    ctx->r13 = MEM_BU(0X9, ctx->r9);
    // lbu         $t6, 0x9($t2)
    ctx->r14 = MEM_BU(0X9, ctx->r10);
    // lbu         $t7, 0x9($t3)
    ctx->r15 = MEM_BU(0X9, ctx->r11);
    // add         $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // add         $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // sra         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24) >> 1;
    // sra         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25) >> 1;
    // sb          $t8, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r24;
    // sb          $t9, 0x21($a3)
    MEM_B(0X21, ctx->r7) = ctx->r25;
    // add         $t8, $t4, $t5
    ctx->r24 = ADD32(ctx->r12, ctx->r13);
    // add         $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // add         $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // sra         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24) >> 1;
    // sra         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25) >> 1;
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // sb          $t8, 0x9($a3)
    MEM_B(0X9, ctx->r7) = ctx->r24;
    // sb          $t9, 0x51($a3)
    MEM_B(0X51, ctx->r7) = ctx->r25;
    // sb          $v1, 0x69($a3)
    MEM_B(0X69, ctx->r7) = ctx->r3;
    // lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(0X0, ctx->r5);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // bne         $t4, $a2, L_80076724
    if (ctx->r12 != ctx->r6) {
        // nop
    
        goto L_80076724;
    }
    // nop

    // addu        $v1, $ra, $zero
    ctx->r3 = ADD32(ctx->r31, 0);
    // lw          $t0, 0x78($a3)
    ctx->r8 = MEM_W(0X78, ctx->r7);
    // addiu       $t1, $a3, 0x0
    ctx->r9 = ADD32(ctx->r7, 0X0);
    // addiu       $t2, $a3, 0x18
    ctx->r10 = ADD32(ctx->r7, 0X18);
    // addiu       $t3, $a3, 0x60
    ctx->r11 = ADD32(ctx->r7, 0X60);
    // swc2        $12, 0x40($a3)
    gte_swc2(rdram, ctx, 12, 7, 64);
    // swc2        $13, 0x58($a3)
    gte_swc2(rdram, ctx, 13, 7, 88);
    // jal         0x800767F4
    // nop

    sub_800767F4(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $t0, 0x7C($a3)
    ctx->r8 = MEM_W(0X7C, ctx->r7);
    // addiu       $t1, $a3, 0x30
    ctx->r9 = ADD32(ctx->r7, 0X30);
    // addiu       $t2, $a3, 0x0
    ctx->r10 = ADD32(ctx->r7, 0X0);
    // addiu       $t3, $a3, 0x60
    ctx->r11 = ADD32(ctx->r7, 0X60);
    // jal         0x800767F4
    // nop

    sub_800767F4(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $t0, 0x80($a3)
    ctx->r8 = MEM_W(0X80, ctx->r7);
    // addiu       $t1, $a3, 0x18
    ctx->r9 = ADD32(ctx->r7, 0X18);
    // addiu       $t2, $a3, 0x48
    ctx->r10 = ADD32(ctx->r7, 0X48);
    // addiu       $t3, $a3, 0x60
    ctx->r11 = ADD32(ctx->r7, 0X60);
    // jal         0x800767F4
    // nop

    sub_800767F4(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $t0, 0x84($a3)
    ctx->r8 = MEM_W(0X84, ctx->r7);
    // addiu       $t1, $a3, 0x48
    ctx->r9 = ADD32(ctx->r7, 0X48);
    // addiu       $t2, $a3, 0x30
    ctx->r10 = ADD32(ctx->r7, 0X30);
    // addiu       $t3, $a3, 0x60
    ctx->r11 = ADD32(ctx->r7, 0X60);
    // jal         0x800767F4
    // nop

    sub_800767F4(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // addu        $ra, $v1, $zero
    ctx->r31 = ADD32(ctx->r3, 0);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // b           L_800767E8
    // nop

    goto L_800767E8;
    // nop

L_80076724:
    // addiu       $a3, $a3, 0x8C
    ctx->r7 = ADD32(ctx->r7, 0X8C);
    // sw          $ra, 0x88($a3)
    MEM_W(0X88, ctx->r7) = ctx->r31;
    // lw          $t4, -0x14($a3)
    ctx->r12 = MEM_W(-0X14, ctx->r7);
    // addiu       $t5, $a3, -0x8C
    ctx->r13 = ADD32(ctx->r7, -0X8C);
    // addiu       $t6, $a3, -0x74
    ctx->r14 = ADD32(ctx->r7, -0X74);
    // addiu       $t7, $a3, -0x2C
    ctx->r15 = ADD32(ctx->r7, -0X2C);
    // sw          $t4, 0x78($a3)
    MEM_W(0X78, ctx->r7) = ctx->r12;
    // sw          $t5, 0x7C($a3)
    MEM_W(0X7C, ctx->r7) = ctx->r13;
    // sw          $t6, 0x80($a3)
    MEM_W(0X80, ctx->r7) = ctx->r14;
    // sw          $t7, 0x84($a3)
    MEM_W(0X84, ctx->r7) = ctx->r15;
    // swc2        $12, -0x4C($a3)
    gte_swc2(rdram, ctx, 12, 7, 65460);
    // swc2        $13, -0x34($a3)
    gte_swc2(rdram, ctx, 13, 7, 65484);
    // swc2        $17, -0x48($a3)
    gte_swc2(rdram, ctx, 17, 7, 65464);
    // swc2        $18, -0x30($a3)
    gte_swc2(rdram, ctx, 18, 7, 65488);
    // jal         0x8007636C
    // nop

    RCpolyFT4A(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lw          $t4, -0x10($a3)
    ctx->r12 = MEM_W(-0X10, ctx->r7);
    // addiu       $t5, $a3, -0x5C
    ctx->r13 = ADD32(ctx->r7, -0X5C);
    // addiu       $t6, $a3, -0x8C
    ctx->r14 = ADD32(ctx->r7, -0X8C);
    // addiu       $t7, $a3, -0x2C
    ctx->r15 = ADD32(ctx->r7, -0X2C);
    // sw          $t4, 0x78($a3)
    MEM_W(0X78, ctx->r7) = ctx->r12;
    // sw          $t5, 0x7C($a3)
    MEM_W(0X7C, ctx->r7) = ctx->r13;
    // sw          $t6, 0x80($a3)
    MEM_W(0X80, ctx->r7) = ctx->r14;
    // sw          $t7, 0x84($a3)
    MEM_W(0X84, ctx->r7) = ctx->r15;
    // jal         0x8007636C
    // nop

    RCpolyFT4A(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lw          $t4, -0xC($a3)
    ctx->r12 = MEM_W(-0XC, ctx->r7);
    // addiu       $t5, $a3, -0x74
    ctx->r13 = ADD32(ctx->r7, -0X74);
    // addiu       $t6, $a3, -0x44
    ctx->r14 = ADD32(ctx->r7, -0X44);
    // addiu       $t7, $a3, -0x2C
    ctx->r15 = ADD32(ctx->r7, -0X2C);
    // sw          $t4, 0x78($a3)
    MEM_W(0X78, ctx->r7) = ctx->r12;
    // sw          $t5, 0x7C($a3)
    MEM_W(0X7C, ctx->r7) = ctx->r13;
    // sw          $t6, 0x80($a3)
    MEM_W(0X80, ctx->r7) = ctx->r14;
    // sw          $t7, 0x84($a3)
    MEM_W(0X84, ctx->r7) = ctx->r15;
    // jal         0x8007636C
    // nop

    RCpolyFT4A(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lw          $t4, -0x8($a3)
    ctx->r12 = MEM_W(-0X8, ctx->r7);
    // addiu       $t5, $a3, -0x44
    ctx->r13 = ADD32(ctx->r7, -0X44);
    // addiu       $t6, $a3, -0x5C
    ctx->r14 = ADD32(ctx->r7, -0X5C);
    // addiu       $t7, $a3, -0x2C
    ctx->r15 = ADD32(ctx->r7, -0X2C);
    // sw          $t4, 0x78($a3)
    MEM_W(0X78, ctx->r7) = ctx->r12;
    // sw          $t5, 0x7C($a3)
    MEM_W(0X7C, ctx->r7) = ctx->r13;
    // sw          $t6, 0x80($a3)
    MEM_W(0X80, ctx->r7) = ctx->r14;
    // sw          $t7, 0x84($a3)
    MEM_W(0X84, ctx->r7) = ctx->r15;
    // jal         0x8007636C
    // nop

    RCpolyFT4A(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lw          $ra, 0x88($a3)
    ctx->r31 = MEM_W(0X88, ctx->r7);
    // addiu       $a3, $a3, -0x8C
    ctx->r7 = ADD32(ctx->r7, -0X8C);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_800767E8:
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // jr          $ra
    // nop

    return;
    // nop

;}
