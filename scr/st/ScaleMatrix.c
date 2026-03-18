#include "recomp.h"
#include "disable_warnings.h"

void ScaleMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(0X0, ctx->r5);
    // lw          $t4, 0x4($a1)
    ctx->r12 = MEM_W(0X4, ctx->r5);
    // lw          $t5, 0x8($a1)
    ctx->r13 = MEM_W(0X8, ctx->r5);
    // lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(0X0, ctx->r4);
    // nop

    // andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) << 16;
    // sra         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) >> 16;
    // multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // sra         $t1, $t1, 12
    ctx->r9 = S32(ctx->r9) >> 12;
    // andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
    // sra         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8) >> 16;
    // multu       $t2, $t4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // sra         $t2, $t2, 12
    ctx->r10 = S32(ctx->r10) >> 12;
    // sll         $t2, $t2, 16
    ctx->r10 = S32(ctx->r10) << 16;
    // or          $t1, $t1, $t2
    ctx->r9 = ctx->r9 | ctx->r10;
    // sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(0X4, ctx->r4);
    // nop

    // andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) << 16;
    // sra         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) >> 16;
    // multu       $t1, $t5
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // sra         $t1, $t1, 12
    ctx->r9 = S32(ctx->r9) >> 12;
    // andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
    // sra         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8) >> 16;
    // multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // sra         $t2, $t2, 12
    ctx->r10 = S32(ctx->r10) >> 12;
    // sll         $t2, $t2, 16
    ctx->r10 = S32(ctx->r10) << 16;
    // or          $t1, $t1, $t2
    ctx->r9 = ctx->r9 | ctx->r10;
    // sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(0X8, ctx->r4);
    // nop

    // andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) << 16;
    // sra         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) >> 16;
    // multu       $t1, $t4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // sra         $t1, $t1, 12
    ctx->r9 = S32(ctx->r9) >> 12;
    // andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
    // sra         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8) >> 16;
    // multu       $t2, $t5
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // sra         $t2, $t2, 12
    ctx->r10 = S32(ctx->r10) >> 12;
    // sll         $t2, $t2, 16
    ctx->r10 = S32(ctx->r10) << 16;
    // or          $t1, $t1, $t2
    ctx->r9 = ctx->r9 | ctx->r10;
    // sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(0XC, ctx->r4);
    // nop

    // andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) << 16;
    // sra         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) >> 16;
    // multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // sra         $t1, $t1, 12
    ctx->r9 = S32(ctx->r9) >> 12;
    // andi        $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 & 0XFFFF;
    // sra         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8) >> 16;
    // multu       $t2, $t4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // sra         $t2, $t2, 12
    ctx->r10 = S32(ctx->r10) >> 12;
    // sll         $t2, $t2, 16
    ctx->r10 = S32(ctx->r10) << 16;
    // or          $t1, $t1, $t2
    ctx->r9 = ctx->r9 | ctx->r10;
    // sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    // lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(0X10, ctx->r4);
    // nop

    // andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) << 16;
    // sra         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9) >> 16;
    // multu       $t1, $t5
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // sra         $t1, $t1, 12
    ctx->r9 = S32(ctx->r9) >> 12;
    // sw          $t1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r9;
    // jr          $ra
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    return;
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
;}
