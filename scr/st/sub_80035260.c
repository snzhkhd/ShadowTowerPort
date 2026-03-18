#include "recomp.h"
#include "disable_warnings.h"

void sub_80035260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(0X48, ctx->r16);
    // nop

    // bne         $a0, $zero, L_8003542C
    if (ctx->r4 != 0) {
        // lui         $s1, 0x1F80
        ctx->r17 = S32(0X1F80 << 16);
        goto L_8003542C;
    }
    // lui         $s1, 0x1F80
    ctx->r17 = S32(0X1F80 << 16);
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // ori         $a1, $a1, 0xA8
    ctx->r5 = ctx->r5 | 0XA8;
    // lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(0X0, ctx->r5);
    // lw          $t5, 0x4($a1)
    ctx->r13 = MEM_W(0X4, ctx->r5);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($a1)
    ctx->r12 = MEM_W(0X8, ctx->r5);
    // lw          $t5, 0xC($a1)
    ctx->r13 = MEM_W(0XC, ctx->r5);
    // lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(0X10, ctx->r5);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lw          $t4, 0x14($a1)
    ctx->r12 = MEM_W(0X14, ctx->r5);
    // lw          $t5, 0x18($a1)
    ctx->r13 = MEM_W(0X18, ctx->r5);
    // ctc2        $t4, $5
    gte_ctc2(ctx, 12, 5);
    // lw          $t6, 0x1C($a1)
    ctx->r14 = MEM_W(0X1C, ctx->r5);
    // ctc2        $t5, $6
    gte_ctc2(ctx, 13, 6);
    // ctc2        $t6, $7
    gte_ctc2(ctx, 14, 7);
    // lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(0X18, ctx->r16);
    // nop

    // sh          $v0, 0x9C($s1)
    MEM_H(0X9C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1C($s0)
    ctx->r2 = MEM_HU(0X1C, ctx->r16);
    // nop

    // sh          $v0, 0x9E($s1)
    MEM_H(0X9E, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(0X20, ctx->r16);
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // ori         $a1, $a1, 0x9C
    ctx->r5 = ctx->r5 | 0X9C;
    // sh          $v0, 0xA0($s1)
    MEM_H(0XA0, ctx->r17) = ctx->r2;
    // lwc2        $0, 0x0($a1)
    gte_lwc2(rdram, ctx, 0, 5, 0);
    // lwc2        $1, 0x4($a1)
    gte_lwc2(rdram, ctx, 1, 5, 4);
    // nop

    // nop

    // .word       0x4A480012                   # INVALID     $s2, $t0, 0x12 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A480012);
    // addiu       $v0, $s0, 0x38
    ctx->r2 = ADD32(ctx->r16, 0X38);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // addiu       $v1, $s0, 0x24
    ctx->r3 = ADD32(ctx->r16, 0X24);
    // lw          $t4, 0x14($v1)
    ctx->r12 = MEM_W(0X14, ctx->r3);
    // lw          $t5, 0x18($v1)
    ctx->r13 = MEM_W(0X18, ctx->r3);
    // ctc2        $t4, $5
    gte_ctc2(ctx, 12, 5);
    // lw          $t6, 0x1C($v1)
    ctx->r14 = MEM_W(0X1C, ctx->r3);
    // ctc2        $t5, $6
    gte_ctc2(ctx, 13, 6);
    // ctc2        $t6, $7
    gte_ctc2(ctx, 14, 7);
    // addiu       $v0, $s0, 0x4
    ctx->r2 = ADD32(ctx->r16, 0X4);
    // lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(0X0, ctx->r2);
    // lhu         $t5, 0x6($v0)
    ctx->r13 = MEM_HU(0X6, ctx->r2);
    // lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(0XC, ctx->r2);
    // mtc2        $t4, $9
    gte_mtc2(ctx, 12, 9);
    // mtc2        $t5, $10
    gte_mtc2(ctx, 13, 10);
    // mtc2        $t6, $11
    gte_mtc2(ctx, 14, 11);
    // nop

    // nop

    // .word       0x4A49E012                   # INVALID     $s2, $t1, -0x1FEE # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A49E012);
    // mfc2        $t4, $9
    ctx->r12 = gte_mfc2(ctx, 9);
    // mfc2        $t5, $10
    ctx->r13 = gte_mfc2(ctx, 10);
    // mfc2        $t6, $11
    ctx->r14 = gte_mfc2(ctx, 11);
    // sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // sh          $t5, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r13;
    // sh          $t6, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r14;
    // addiu       $v0, $s0, 0x6
    ctx->r2 = ADD32(ctx->r16, 0X6);
    // lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(0X0, ctx->r2);
    // lhu         $t5, 0x6($v0)
    ctx->r13 = MEM_HU(0X6, ctx->r2);
    // lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(0XC, ctx->r2);
    // mtc2        $t4, $9
    gte_mtc2(ctx, 12, 9);
    // mtc2        $t5, $10
    gte_mtc2(ctx, 13, 10);
    // mtc2        $t6, $11
    gte_mtc2(ctx, 14, 11);
    // nop

    // nop

    // .word       0x4A49E012                   # INVALID     $s2, $t1, -0x1FEE # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A49E012);
    // addiu       $v0, $s0, 0x26
    ctx->r2 = ADD32(ctx->r16, 0X26);
    // mfc2        $t4, $9
    ctx->r12 = gte_mfc2(ctx, 9);
    // mfc2        $t5, $10
    ctx->r13 = gte_mfc2(ctx, 10);
    // mfc2        $t6, $11
    ctx->r14 = gte_mfc2(ctx, 11);
    // sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // sh          $t6, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r14;
    // addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(0X0, ctx->r2);
    // lhu         $t5, 0x6($v0)
    ctx->r13 = MEM_HU(0X6, ctx->r2);
    // lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(0XC, ctx->r2);
    // mtc2        $t4, $9
    gte_mtc2(ctx, 12, 9);
    // mtc2        $t5, $10
    gte_mtc2(ctx, 13, 10);
    // mtc2        $t6, $11
    gte_mtc2(ctx, 14, 11);
    // nop

    // nop

    // .word       0x4A49E012                   # INVALID     $s2, $t1, -0x1FEE # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A49E012);
    // addiu       $v0, $s0, 0x28
    ctx->r2 = ADD32(ctx->r16, 0X28);
    // mfc2        $t4, $9
    ctx->r12 = gte_mfc2(ctx, 9);
    // mfc2        $t5, $10
    ctx->r13 = gte_mfc2(ctx, 10);
    // mfc2        $t6, $11
    ctx->r14 = gte_mfc2(ctx, 11);
    // sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // sh          $t6, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r14;
    // lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(0X0, ctx->r3);
    // lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(0X4, ctx->r3);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(0X8, ctx->r3);
    // lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(0XC, ctx->r3);
    // lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(0X10, ctx->r3);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // j           L_800355E8
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_800355E8;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003542C:
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80035484
    if (ctx->r2 == 0) {
        // addiu       $v0, $s0, 0x24
        ctx->r2 = ADD32(ctx->r16, 0X24);
        goto L_80035484;
    }
    // addiu       $v0, $s0, 0x24
    ctx->r2 = ADD32(ctx->r16, 0X24);
    // lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(0X14, ctx->r2);
    // lw          $t5, 0x18($v0)
    ctx->r13 = MEM_W(0X18, ctx->r2);
    // ctc2        $t4, $5
    gte_ctc2(ctx, 12, 5);
    // lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(0X1C, ctx->r2);
    // ctc2        $t5, $6
    gte_ctc2(ctx, 13, 6);
    // ctc2        $t6, $7
    gte_ctc2(ctx, 14, 7);
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
    // j           L_800355EC
    // nop

    goto L_800355EC;
    // nop

L_80035484:
    // jal         0x80035260
    // nop

    sub_80035260(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(0X18, ctx->r16);
    // nop

    // sh          $v0, 0x9C($s1)
    MEM_H(0X9C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1C($s0)
    ctx->r2 = MEM_HU(0X1C, ctx->r16);
    // nop

    // sh          $v0, 0x9E($s1)
    MEM_H(0X9E, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(0X20, ctx->r16);
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // ori         $a1, $a1, 0x9C
    ctx->r5 = ctx->r5 | 0X9C;
    // sh          $v0, 0xA0($s1)
    MEM_H(0XA0, ctx->r17) = ctx->r2;
    // lwc2        $0, 0x0($a1)
    gte_lwc2(rdram, ctx, 0, 5, 0);
    // lwc2        $1, 0x4($a1)
    gte_lwc2(rdram, ctx, 1, 5, 4);
    // nop

    // nop

    // .word       0x4A480012                   # INVALID     $s2, $t0, 0x12 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A480012);
    // addiu       $v0, $s0, 0x38
    ctx->r2 = ADD32(ctx->r16, 0X38);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // addiu       $v1, $s0, 0x24
    ctx->r3 = ADD32(ctx->r16, 0X24);
    // lw          $t4, 0x14($v1)
    ctx->r12 = MEM_W(0X14, ctx->r3);
    // lw          $t5, 0x18($v1)
    ctx->r13 = MEM_W(0X18, ctx->r3);
    // ctc2        $t4, $5
    gte_ctc2(ctx, 12, 5);
    // lw          $t6, 0x1C($v1)
    ctx->r14 = MEM_W(0X1C, ctx->r3);
    // ctc2        $t5, $6
    gte_ctc2(ctx, 13, 6);
    // ctc2        $t6, $7
    gte_ctc2(ctx, 14, 7);
    // addiu       $v0, $s0, 0x4
    ctx->r2 = ADD32(ctx->r16, 0X4);
    // lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(0X0, ctx->r2);
    // lhu         $t5, 0x6($v0)
    ctx->r13 = MEM_HU(0X6, ctx->r2);
    // lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(0XC, ctx->r2);
    // mtc2        $t4, $9
    gte_mtc2(ctx, 12, 9);
    // mtc2        $t5, $10
    gte_mtc2(ctx, 13, 10);
    // mtc2        $t6, $11
    gte_mtc2(ctx, 14, 11);
    // nop

    // nop

    // .word       0x4A49E012                   # INVALID     $s2, $t1, -0x1FEE # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A49E012);
    // mfc2        $t4, $9
    ctx->r12 = gte_mfc2(ctx, 9);
    // mfc2        $t5, $10
    ctx->r13 = gte_mfc2(ctx, 10);
    // mfc2        $t6, $11
    ctx->r14 = gte_mfc2(ctx, 11);
    // sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // sh          $t5, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r13;
    // sh          $t6, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r14;
    // addiu       $v0, $s0, 0x6
    ctx->r2 = ADD32(ctx->r16, 0X6);
    // lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(0X0, ctx->r2);
    // lhu         $t5, 0x6($v0)
    ctx->r13 = MEM_HU(0X6, ctx->r2);
    // lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(0XC, ctx->r2);
    // mtc2        $t4, $9
    gte_mtc2(ctx, 12, 9);
    // mtc2        $t5, $10
    gte_mtc2(ctx, 13, 10);
    // mtc2        $t6, $11
    gte_mtc2(ctx, 14, 11);
    // nop

    // nop

    // .word       0x4A49E012                   # INVALID     $s2, $t1, -0x1FEE # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A49E012);
    // addiu       $v0, $s0, 0x26
    ctx->r2 = ADD32(ctx->r16, 0X26);
    // mfc2        $t4, $9
    ctx->r12 = gte_mfc2(ctx, 9);
    // mfc2        $t5, $10
    ctx->r13 = gte_mfc2(ctx, 10);
    // mfc2        $t6, $11
    ctx->r14 = gte_mfc2(ctx, 11);
    // sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // sh          $t6, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r14;
    // addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // lhu         $t4, 0x0($v0)
    ctx->r12 = MEM_HU(0X0, ctx->r2);
    // lhu         $t5, 0x6($v0)
    ctx->r13 = MEM_HU(0X6, ctx->r2);
    // lhu         $t6, 0xC($v0)
    ctx->r14 = MEM_HU(0XC, ctx->r2);
    // mtc2        $t4, $9
    gte_mtc2(ctx, 12, 9);
    // mtc2        $t5, $10
    gte_mtc2(ctx, 13, 10);
    // mtc2        $t6, $11
    gte_mtc2(ctx, 14, 11);
    // nop

    // nop

    // .word       0x4A49E012                   # INVALID     $s2, $t1, -0x1FEE # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A49E012);
    // addiu       $v0, $s0, 0x28
    ctx->r2 = ADD32(ctx->r16, 0X28);
    // mfc2        $t4, $9
    ctx->r12 = gte_mfc2(ctx, 9);
    // mfc2        $t5, $10
    ctx->r13 = gte_mfc2(ctx, 10);
    // mfc2        $t6, $11
    ctx->r14 = gte_mfc2(ctx, 11);
    // sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // sh          $t5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r13;
    // sh          $t6, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r14;
    // lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(0X0, ctx->r3);
    // lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(0X4, ctx->r3);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(0X8, ctx->r3);
    // lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(0XC, ctx->r3);
    // lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(0X10, ctx->r3);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800355E8:
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800355EC:
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
