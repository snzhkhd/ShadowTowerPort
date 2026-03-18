#include "recomp.h"
#include "disable_warnings.h"

void ApplyMatrixSV(uint8_t* rdram, recomp_context* ctx) {
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
    // lwc2        $0, 0x0($a1)
    gte_lwc2(rdram, ctx, 0, 5, 0);
    // lwc2        $1, 0x4($a1)
    gte_lwc2(rdram, ctx, 1, 5, 4);
    // nop

    // .word       0x4A486012                   # INVALID     $s2, $t0, 0x6012 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A486012);
    // mfc2        $t0, $9
    ctx->r8 = gte_mfc2(ctx, 9);
    // mfc2        $t1, $10
    ctx->r9 = gte_mfc2(ctx, 10);
    // mfc2        $t2, $11
    ctx->r10 = gte_mfc2(ctx, 11);
    // sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    // sh          $t1, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r9;
    // sh          $t2, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r10;
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // jr          $ra
    // nop

    return;
    // nop

;}
