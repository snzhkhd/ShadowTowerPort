#include "recomp.h"
#include "disable_warnings.h"

void RotMatrixZYX_gte(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lh          $t0, 0x4($a0)
    ctx->r8 = MEM_HS(0X4, ctx->r4);
    // or          $v0, $zero, $a1
    ctx->r2 = 0 | ctx->r5;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0x2280
    ctx->r3 = ADD32(ctx->r3, 0X2280);
    // lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(0X0, ctx->r4);
    // sra         $t3, $t0, 31
    ctx->r11 = S32(ctx->r8) >> 31;
    // add         $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
    // xor         $t0, $t0, $t3
    ctx->r8 = ctx->r8 ^ ctx->r11;
    // sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8) << 2;
    // andi        $t0, $t0, 0x3FFC
    ctx->r8 = ctx->r8 & 0X3FFC;
    // add         $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(0X0, ctx->r8);
    // sra         $t0, $t4, 16
    ctx->r8 = S32(ctx->r12) >> 16;
    // sra         $t2, $t0, 31
    ctx->r10 = S32(ctx->r8) >> 31;
    // add         $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // xor         $t0, $t0, $t2
    ctx->r8 = ctx->r8 ^ ctx->r10;
    // sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8) << 2;
    // andi        $t0, $t0, 0x3FFC
    ctx->r8 = ctx->r8 & 0X3FFC;
    // add         $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(0X0, ctx->r8);
    // sll         $t0, $t4, 16
    ctx->r8 = S32(ctx->r12) << 16;
    // sra         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8) >> 16;
    // sra         $t1, $t0, 31
    ctx->r9 = S32(ctx->r8) >> 31;
    // add         $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // xor         $t0, $t0, $t1
    ctx->r8 = ctx->r8 ^ ctx->r9;
    // sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8) << 2;
    // andi        $t0, $t0, 0x3FFC
    ctx->r8 = ctx->r8 & 0X3FFC;
    // add         $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(0X0, ctx->r8);
    // sll         $at, $a2, 16
    ctx->r1 = S32(ctx->r6) << 16;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) << 16;
    // add         $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // xor         $at, $at, $t3
    ctx->r1 = ctx->r1 ^ ctx->r11;
    // srl         $at, $at, 16
    ctx->r1 = S32(U32(ctx->r1) >> 16);
    // or          $a2, $a2, $at
    ctx->r6 = ctx->r6 | ctx->r1;
    // sll         $at, $a1, 16
    ctx->r1 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // add         $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // xor         $at, $at, $t2
    ctx->r1 = ctx->r1 ^ ctx->r10;
    // srl         $at, $at, 16
    ctx->r1 = S32(U32(ctx->r1) >> 16);
    // or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
    // sll         $at, $a0, 16
    ctx->r1 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // add         $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // xor         $at, $at, $t1
    ctx->r1 = ctx->r1 ^ ctx->r9;
    // srl         $at, $at, 16
    ctx->r1 = S32(U32(ctx->r1) >> 16);
    // or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    // sra         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4) >> 16;
    // mtc2        $t0, $8
    gte_mtc2(ctx, 8, 8);
    // sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5) << 16;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    // mtc2        $a3, $9
    gte_mtc2(ctx, 7, 9);
    // sll         $v1, $a2, 16
    ctx->r3 = S32(ctx->r6) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // mtc2        $v1, $10
    gte_mtc2(ctx, 3, 10);
    // sra         $at, $a2, 16
    ctx->r1 = S32(ctx->r6) >> 16;
    // mtc2        $at, $11
    gte_mtc2(ctx, 1, 11);
    // nop

    // nop

    // .word       0x4B98003D                   # INVALID     $gp, $t8, 0x3D # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B98003D);
    // sra         $at, $a1, 16
    ctx->r1 = S32(ctx->r5) >> 16;
    // mult        $at, $t0
    result = S64(S32(ctx->r1)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfc2        $t0, $9
    ctx->r8 = gte_mfc2(ctx, 9);
    // mfc2        $t1, $10
    ctx->r9 = gte_mfc2(ctx, 10);
    // sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4) << 16;
    // mfc2        $t2, $11
    ctx->r10 = gte_mfc2(ctx, 11);
    // sra         $t6, $t6, 16
    ctx->r14 = S32(ctx->r14) >> 16;
    // mtc2        $t6, $8
    gte_mtc2(ctx, 14, 8);
    // mtc2        $a3, $9
    gte_mtc2(ctx, 7, 9);
    // mtc2        $v1, $10
    gte_mtc2(ctx, 3, 10);
    // sra         $at, $a2, 16
    ctx->r1 = S32(ctx->r6) >> 16;
    // mtc2        $at, $11
    gte_mtc2(ctx, 1, 11);
    // nop

    // nop

    // .word       0x4B98003D                   # INVALID     $gp, $t8, 0x3D # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B98003D);
    // mflo        $at
    ctx->r1 = lo;
    // sra         $at, $at, 12
    ctx->r1 = S32(ctx->r1) >> 12;
    // sh          $at, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r1;
    // mfc2        $t3, $9
    ctx->r11 = gte_mfc2(ctx, 9);
    // mfc2        $t4, $10
    ctx->r12 = gte_mfc2(ctx, 10);
    // mfc2        $t5, $11
    ctx->r13 = gte_mfc2(ctx, 11);
    // sra         $at, $a2, 16
    ctx->r1 = S32(ctx->r6) >> 16;
    // mtc2        $at, $8
    gte_mtc2(ctx, 1, 8);
    // sra         $at, $a1, 16
    ctx->r1 = S32(ctx->r5) >> 16;
    // mtc2        $at, $9
    gte_mtc2(ctx, 1, 9);
    // mult        $at, $t6
    result = S64(S32(ctx->r1)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mtc2        $t3, $10
    gte_mtc2(ctx, 11, 10);
    // mtc2        $t0, $11
    gte_mtc2(ctx, 8, 11);
    // sub         $a3, $zero, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    // andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // .word       0x4B98003D                   # INVALID     $gp, $t8, 0x3D # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B98003D);
    // mfc2        $a0, $9
    ctx->r4 = gte_mfc2(ctx, 9);
    // mfc2        $a1, $10
    ctx->r5 = gte_mfc2(ctx, 10);
    // mfc2        $a2, $11
    ctx->r6 = gte_mfc2(ctx, 11);
    // mtc2        $at, $9
    gte_mtc2(ctx, 1, 9);
    // mflo        $at
    ctx->r1 = lo;
    // mtc2        $v1, $8
    gte_mtc2(ctx, 3, 8);
    // sra         $at, $at, 12
    ctx->r1 = S32(ctx->r1) >> 12;
    // mtc2        $t3, $10
    gte_mtc2(ctx, 11, 10);
    // sll         $at, $at, 16
    ctx->r1 = S32(ctx->r1) << 16;
    // mtc2        $t0, $11
    gte_mtc2(ctx, 8, 11);
    // or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
    // sw          $a3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r7;
    // .word       0x4B98003D                   # INVALID     $gp, $t8, 0x3D # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B98003D);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sub         $a1, $a1, $t1
    ctx->r5 = SUB32(ctx->r5, ctx->r9);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // or          $a1, $a1, $a0
    ctx->r5 = ctx->r5 | ctx->r4;
    // sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // mfc2        $at, $9
    ctx->r1 = gte_mfc2(ctx, 9);
    // add         $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // mfc2        $t6, $10
    ctx->r14 = gte_mfc2(ctx, 10);
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // mfc2        $t7, $11
    ctx->r15 = gte_mfc2(ctx, 11);
    // sll         $at, $at, 16
    ctx->r1 = S32(ctx->r1) << 16;
    // or          $at, $at, $a2
    ctx->r1 = ctx->r1 | ctx->r6;
    // sw          $at, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r1;
    // add         $t6, $t6, $t2
    ctx->r14 = ADD32(ctx->r14, ctx->r10);
    // andi        $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 & 0XFFFF;
    // sub         $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // sll         $t7, $t7, 16
    ctx->r15 = S32(ctx->r15) << 16;
    // or          $t6, $t6, $t7
    ctx->r14 = ctx->r14 | ctx->r15;
    // jr          $ra
    // sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    return;
    // sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
;}
