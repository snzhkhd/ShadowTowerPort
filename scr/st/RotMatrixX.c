#include "recomp.h"
#include "disable_warnings.h"

void RotMatrixX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t7, $a0, $zero
    ctx->r15 = ADD32(ctx->r4, 0);
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // bgez        $t7, L_80075428
    if (SIGNED(ctx->r15) >= 0) {
        // andi        $t9, $t7, 0xFFF
        ctx->r25 = ctx->r15 & 0XFFF;
        goto L_80075428;
    }
    // andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // negu        $t7, $t7
    ctx->r15 = SUB32(0, ctx->r15);
    // bgez        $t7, L_80075400
    if (SIGNED(ctx->r15) >= 0) {
        // andi        $t7, $t7, 0xFFF
        ctx->r15 = ctx->r15 & 0XFFF;
        goto L_80075400;
    }
    // andi        $t7, $t7, 0xFFF
    ctx->r15 = ctx->r15 & 0XFFF;
L_80075400:
    // sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15) << 2;
    // lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // lw          $t9, 0x2280($t9)
    ctx->r25 = MEM_W(0X2280, ctx->r25);
    // nop

    // sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25) << 16;
    // sra         $t6, $t6, 16
    ctx->r14 = S32(ctx->r14) >> 16;
    // negu        $t1, $t6
    ctx->r9 = SUB32(0, ctx->r14);
    // j           L_80075448
    // sra         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25) >> 16;
    goto L_80075448;
    // sra         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25) >> 16;
L_80075428:
    // sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25) << 2;
    // lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // lw          $t9, 0x2280($t9)
    ctx->r25 = MEM_W(0X2280, ctx->r25);
    // nop

    // sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25) << 16;
    // sra         $t1, $t8, 16
    ctx->r9 = S32(ctx->r24) >> 16;
    // sra         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25) >> 16;
L_80075448:
    // lh          $t2, 0x6($a1)
    ctx->r10 = MEM_HS(0X6, ctx->r5);
    // lh          $t5, 0xC($a1)
    ctx->r13 = MEM_HS(0XC, ctx->r5);
    // multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lh          $t3, 0x8($a1)
    ctx->r11 = MEM_HS(0X8, ctx->r5);
    // lh          $t6, 0xE($a1)
    ctx->r14 = MEM_HS(0XE, ctx->r5);
    // mflo        $t8
    ctx->r24 = lo;
    // lh          $t4, 0xA($a1)
    ctx->r12 = MEM_HS(0XA, ctx->r5);
    // lh          $t7, 0x10($a1)
    ctx->r15 = MEM_HS(0X10, ctx->r5);
    // multu       $t1, $t5
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // nop

    // nop

    // mflo        $t9
    ctx->r25 = lo;
    // subu        $t9, $t8, $t9
    ctx->r25 = SUB32(ctx->r24, ctx->r25);
    // sra         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25) >> 12;
    // multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $t8, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r24;
    // nop

    // mflo        $t8
    ctx->r24 = lo;
    // nop

    // nop

    // multu       $t1, $t6
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // nop

    // nop

    // mflo        $t9
    ctx->r25 = lo;
    // subu        $t9, $t8, $t9
    ctx->r25 = SUB32(ctx->r24, ctx->r25);
    // sra         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25) >> 12;
    // multu       $t0, $t4
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $t8, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r24;
    // nop

    // mflo        $t8
    ctx->r24 = lo;
    // nop

    // nop

    // multu       $t1, $t7
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // nop

    // nop

    // mflo        $t9
    ctx->r25 = lo;
    // subu        $t9, $t8, $t9
    ctx->r25 = SUB32(ctx->r24, ctx->r25);
    // sra         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25) >> 12;
    // multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $t8, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r24;
    // nop

    // mflo        $t8
    ctx->r24 = lo;
    // nop

    // nop

    // multu       $t0, $t5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // nop

    // nop

    // mflo        $t9
    ctx->r25 = lo;
    // addu        $t9, $t8, $t9
    ctx->r25 = ADD32(ctx->r24, ctx->r25);
    // sra         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25) >> 12;
    // multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $t8, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r24;
    // nop

    // mflo        $t8
    ctx->r24 = lo;
    // nop

    // nop

    // multu       $t0, $t6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // nop

    // nop

    // mflo        $t9
    ctx->r25 = lo;
    // addu        $t9, $t8, $t9
    ctx->r25 = ADD32(ctx->r24, ctx->r25);
    // sra         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25) >> 12;
    // multu       $t1, $t4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $t8, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r24;
    // nop

    // mflo        $t8
    ctx->r24 = lo;
    // nop

    // nop

    // multu       $t0, $t7
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // nop

    // nop

    // mflo        $t9
    ctx->r25 = lo;
    // addu        $t9, $t8, $t9
    ctx->r25 = ADD32(ctx->r24, ctx->r25);
    // sra         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25) >> 12;
    // sh          $t8, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r24;
    // jr          $ra
    // nop

    return;
    // nop

;}
