#include "recomp.h"
#include "disable_warnings.h"

void MulMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(0X0, ctx->r4);
    // lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(0X4, ctx->r4);
    // lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(0X8, ctx->r4);
    // lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(0XC, ctx->r4);
    // lw          $t4, 0x10($a0)
    ctx->r12 = MEM_W(0X10, ctx->r4);
    // ctc2        $t0, $0
    gte_ctc2(ctx, 8, 0);
    // ctc2        $t1, $1
    gte_ctc2(ctx, 9, 1);
    // ctc2        $t2, $2
    gte_ctc2(ctx, 10, 2);
    // ctc2        $t3, $3
    gte_ctc2(ctx, 11, 3);
    // ctc2        $t4, $4
    gte_ctc2(ctx, 12, 4);
    // lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(0X0, ctx->r5);
    // lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(0X4, ctx->r5);
    // lw          $t2, 0xC($a1)
    ctx->r10 = MEM_W(0XC, ctx->r5);
    // lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // and         $t1, $t1, $at
    ctx->r9 = ctx->r9 & ctx->r1;
    // or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // mtc2        $t0, $0
    gte_mtc2(ctx, 8, 0);
    // mtc2        $t2, $1
    gte_mtc2(ctx, 10, 1);
    // nop

    // .word       0x4A486012                   # INVALID     $s2, $t0, 0x6012 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A486012);
    // lhu         $t0, 0x2($a1)
    ctx->r8 = MEM_HU(0X2, ctx->r5);
    // lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(0X8, ctx->r5);
    // lh          $t2, 0xE($a1)
    ctx->r10 = MEM_HS(0XE, ctx->r5);
    // sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) << 16;
    // or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // mfc2        $t3, $9
    ctx->r11 = gte_mfc2(ctx, 9);
    // mfc2        $t4, $10
    ctx->r12 = gte_mfc2(ctx, 10);
    // mfc2        $t5, $11
    ctx->r13 = gte_mfc2(ctx, 11);
    // mtc2        $t0, $0
    gte_mtc2(ctx, 8, 0);
    // mtc2        $t2, $1
    gte_mtc2(ctx, 10, 1);
    // nop

    // .word       0x4A486012                   # INVALID     $s2, $t0, 0x6012 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A486012);
    // lhu         $t0, 0x4($a1)
    ctx->r8 = MEM_HU(0X4, ctx->r5);
    // lw          $t1, 0x8($a1)
    ctx->r9 = MEM_W(0X8, ctx->r5);
    // lw          $t2, 0x10($a1)
    ctx->r10 = MEM_W(0X10, ctx->r5);
    // lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // and         $t1, $t1, $at
    ctx->r9 = ctx->r9 & ctx->r1;
    // or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // mfc2        $t6, $9
    ctx->r14 = gte_mfc2(ctx, 9);
    // mfc2        $t7, $10
    ctx->r15 = gte_mfc2(ctx, 10);
    // mfc2        $t8, $11
    ctx->r24 = gte_mfc2(ctx, 11);
    // mtc2        $t0, $0
    gte_mtc2(ctx, 8, 0);
    // mtc2        $t2, $1
    gte_mtc2(ctx, 10, 1);
    // nop

    // .word       0x4A486012                   # INVALID     $s2, $t0, 0x6012 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A486012);
    // andi        $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 & 0XFFFF;
    // sll         $t6, $t6, 16
    ctx->r14 = S32(ctx->r14) << 16;
    // or          $t6, $t6, $t3
    ctx->r14 = ctx->r14 | ctx->r11;
    // sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // andi        $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 & 0XFFFF;
    // sll         $t8, $t8, 16
    ctx->r24 = S32(ctx->r24) << 16;
    // or          $t8, $t8, $t5
    ctx->r24 = ctx->r24 | ctx->r13;
    // sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    // mfc2        $t0, $9
    ctx->r8 = gte_mfc2(ctx, 9);
    // mfc2        $t1, $10
    ctx->r9 = gte_mfc2(ctx, 10);
    // andi        $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 & 0XFFFF;
    // sll         $t4, $t4, 16
    ctx->r12 = S32(ctx->r12) << 16;
    // or          $t0, $t0, $t4
    ctx->r8 = ctx->r8 | ctx->r12;
    // sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // andi        $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 & 0XFFFF;
    // sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) << 16;
    // or          $t1, $t1, $t7
    ctx->r9 = ctx->r9 | ctx->r15;
    // sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // swc2        $11, 0x10($a0)
    gte_swc2(rdram, ctx, 11, 4, 16);
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // jr          $ra
    // nop

    return;
    // nop

;}
