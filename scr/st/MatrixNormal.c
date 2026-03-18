#include "recomp.h"
#include "disable_warnings.h"

void MatrixNormal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lh          $t0, 0x0($a0)
    ctx->r8 = MEM_HS(0X0, ctx->r4);
    // lh          $t1, 0x2($a0)
    ctx->r9 = MEM_HS(0X2, ctx->r4);
    // lh          $t2, 0x4($a0)
    ctx->r10 = MEM_HS(0X4, ctx->r4);
    // lh          $t3, 0x6($a0)
    ctx->r11 = MEM_HS(0X6, ctx->r4);
    // lh          $t4, 0x8($a0)
    ctx->r12 = MEM_HS(0X8, ctx->r4);
    // lh          $t5, 0xA($a0)
    ctx->r13 = MEM_HS(0XA, ctx->r4);
    // cfc2        $v0, $0
    ctx->r2 = gte_cfc2(ctx, 0);
    // cfc2        $v1, $2
    ctx->r3 = gte_cfc2(ctx, 2);
    // cfc2        $a2, $4
    ctx->r6 = gte_cfc2(ctx, 4);
    // ctc2        $t0, $0
    gte_ctc2(ctx, 8, 0);
    // ctc2        $t1, $2
    gte_ctc2(ctx, 9, 2);
    // ctc2        $t2, $4
    gte_ctc2(ctx, 10, 4);
    // mtc2        $t5, $11
    gte_mtc2(ctx, 13, 11);
    // mtc2        $t3, $9
    gte_mtc2(ctx, 11, 9);
    // mtc2        $t4, $10
    gte_mtc2(ctx, 12, 10);
    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // mfc2        $t7, $25
    ctx->r15 = gte_mfc2(ctx, 25);
    // mfc2        $t8, $26
    ctx->r24 = gte_mfc2(ctx, 26);
    // mfc2        $t9, $27
    ctx->r25 = gte_mfc2(ctx, 27);
    // ctc2        $t3, $0
    gte_ctc2(ctx, 11, 0);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $4
    gte_ctc2(ctx, 13, 4);
    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // mtc2        $t3, $0
    gte_mtc2(ctx, 11, 0);
    // mtc2        $t4, $1
    gte_mtc2(ctx, 12, 1);
    // mtc2        $t5, $2
    gte_mtc2(ctx, 13, 2);
    // mfc2        $t0, $25
    ctx->r8 = gte_mfc2(ctx, 25);
    // mfc2        $t1, $26
    ctx->r9 = gte_mfc2(ctx, 26);
    // mfc2        $t2, $27
    ctx->r10 = gte_mfc2(ctx, 27);
    // ctc2        $v0, $0
    gte_ctc2(ctx, 2, 0);
    // ctc2        $v1, $2
    gte_ctc2(ctx, 3, 2);
    // ctc2        $a2, $4
    gte_ctc2(ctx, 6, 4);
    // addu        $a3, $ra, $zero
    ctx->r7 = ADD32(ctx->r31, 0);
    // jal         0x80074854
    // nop

    sub_80074854(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
    // sh          $t2, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r10;
    // mfc2        $t0, $0
    ctx->r8 = gte_mfc2(ctx, 0);
    // mfc2        $t1, $1
    ctx->r9 = gte_mfc2(ctx, 1);
    // mfc2        $t2, $2
    ctx->r10 = gte_mfc2(ctx, 2);
    // jal         0x80074854
    // nop

    sub_80074854(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // sh          $t0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r8;
    // sh          $t1, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r9;
    // sh          $t2, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r10;
    // addu        $t0, $t7, $zero
    ctx->r8 = ADD32(ctx->r15, 0);
    // addu        $t1, $t8, $zero
    ctx->r9 = ADD32(ctx->r24, 0);
    // jal         0x80074854
    // addu        $t2, $t9, $zero
    ctx->r10 = ADD32(ctx->r25, 0);
    sub_80074854(rdram, ctx);
    goto after_2;
    // addu        $t2, $t9, $zero
    ctx->r10 = ADD32(ctx->r25, 0);
    after_2:
    // sh          $t0, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r8;
    // sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // sh          $t2, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r10;
    // addu        $ra, $a3, $zero
    ctx->r31 = ADD32(ctx->r7, 0);
    // jr          $ra
    // nop

    return;
    // nop

;}
