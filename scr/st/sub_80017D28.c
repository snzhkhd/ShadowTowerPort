#include "recomp.h"
#include "disable_warnings.h"

void sub_80017D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // lw          $a2, 0x6E08($v1)
    ctx->r6 = MEM_W(0X6E08, ctx->r3);
    // andi        $v0, $a1, 0x20
    ctx->r2 = ctx->r5 & 0X20;
    // beq         $v0, $zero, L_80017FDC
    if (ctx->r2 == 0) {
        // sw          $a2, 0x394($a3)
        MEM_W(0X394, ctx->r7) = ctx->r6;
        goto L_80017FDC;
    }
    // sw          $a2, 0x394($a3)
    MEM_W(0X394, ctx->r7) = ctx->r6;
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v1, $v1, -0x34F0
    ctx->r3 = ADD32(ctx->r3, -0X34F0);
    // addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    // lh          $v0, 0x50($v1)
    ctx->r2 = MEM_HS(0X50, ctx->r3);
    // subu        $a0, $a0, $t0
    ctx->r4 = SUB32(ctx->r4, ctx->r8);
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lh          $v0, 0x68($a2)
    ctx->r2 = MEM_HS(0X68, ctx->r6);
    // nop

    // sw          $v0, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r2;
    // lh          $v0, 0x6A($a2)
    ctx->r2 = MEM_HS(0X6A, ctx->r6);
    // sw          $v1, 0x394($a3)
    MEM_W(0X394, ctx->r7) = ctx->r3;
    // sw          $v0, 0x68($a3)
    MEM_W(0X68, ctx->r7) = ctx->r2;
    // mflo        $t1
    ctx->r9 = lo;
    // lh          $v0, 0x50($a2)
    ctx->r2 = MEM_HS(0X50, ctx->r6);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a3
    ctx->r7 = lo;
    // lh          $v0, 0x52($v1)
    ctx->r2 = MEM_HS(0X52, ctx->r3);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $t1, $a3
    ctx->r2 = ADD32(ctx->r9, ctx->r7);
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // sh          $v0, 0x0($sp)
    MEM_H(0X0, ctx->r29) = ctx->r2;
    // mflo        $a1
    ctx->r5 = lo;
    // lh          $v0, 0x52($a2)
    ctx->r2 = MEM_HS(0X52, ctx->r6);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // lh          $v0, 0x54($v1)
    ctx->r2 = MEM_HS(0X54, ctx->r3);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a1, $t1
    ctx->r2 = ADD32(ctx->r5, ctx->r9);
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // sh          $v0, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r2;
    // mflo        $a3
    ctx->r7 = lo;
    // lh          $v0, 0x54($a2)
    ctx->r2 = MEM_HS(0X54, ctx->r6);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // lh          $v0, 0x56($v1)
    ctx->r2 = MEM_HS(0X56, ctx->r3);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a3, $t1
    ctx->r2 = ADD32(ctx->r7, ctx->r9);
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // sh          $v0, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r2;
    // mflo        $a1
    ctx->r5 = lo;
    // lh          $v0, 0x56($a2)
    ctx->r2 = MEM_HS(0X56, ctx->r6);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // lh          $v0, 0x58($v1)
    ctx->r2 = MEM_HS(0X58, ctx->r3);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a1, $t1
    ctx->r2 = ADD32(ctx->r5, ctx->r9);
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // sh          $v0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r2;
    // mflo        $a3
    ctx->r7 = lo;
    // lh          $v0, 0x58($a2)
    ctx->r2 = MEM_HS(0X58, ctx->r6);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // lh          $v0, 0x5A($v1)
    ctx->r2 = MEM_HS(0X5A, ctx->r3);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a3, $t1
    ctx->r2 = ADD32(ctx->r7, ctx->r9);
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // sh          $v0, 0x8($sp)
    MEM_H(0X8, ctx->r29) = ctx->r2;
    // mflo        $a1
    ctx->r5 = lo;
    // lh          $v0, 0x5A($a2)
    ctx->r2 = MEM_HS(0X5A, ctx->r6);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // lh          $v0, 0x5C($v1)
    ctx->r2 = MEM_HS(0X5C, ctx->r3);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a1, $t1
    ctx->r2 = ADD32(ctx->r5, ctx->r9);
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // sh          $v0, 0xA($sp)
    MEM_H(0XA, ctx->r29) = ctx->r2;
    // mflo        $a3
    ctx->r7 = lo;
    // lh          $v0, 0x5C($a2)
    ctx->r2 = MEM_HS(0X5C, ctx->r6);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // lh          $v0, 0x5E($v1)
    ctx->r2 = MEM_HS(0X5E, ctx->r3);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a3, $t1
    ctx->r2 = ADD32(ctx->r7, ctx->r9);
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // sh          $v0, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r2;
    // mflo        $a1
    ctx->r5 = lo;
    // lh          $v0, 0x5E($a2)
    ctx->r2 = MEM_HS(0X5E, ctx->r6);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // lh          $v0, 0x60($v1)
    ctx->r2 = MEM_HS(0X60, ctx->r3);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a1, $t1
    ctx->r2 = ADD32(ctx->r5, ctx->r9);
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // sh          $v0, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r2;
    // mflo        $a3
    ctx->r7 = lo;
    // lh          $v0, 0x60($a2)
    ctx->r2 = MEM_HS(0X60, ctx->r6);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // lbu         $v0, 0x64($v1)
    ctx->r2 = MEM_BU(0X64, ctx->r3);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a3, $t1
    ctx->r2 = ADD32(ctx->r7, ctx->r9);
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // mflo        $a1
    ctx->r5 = lo;
    // lbu         $v0, 0x64($a2)
    ctx->r2 = MEM_BU(0X64, ctx->r6);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x65($v1)
    ctx->r2 = MEM_BU(0X65, ctx->r3);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // lbu         $v0, 0x65($a2)
    ctx->r2 = MEM_BU(0X65, ctx->r6);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a3
    ctx->r7 = lo;
    // lbu         $v0, 0x66($v1)
    ctx->r2 = MEM_BU(0X66, ctx->r3);
    // nop

    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a1, $a3
    ctx->r2 = ADD32(ctx->r5, ctx->r7);
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // sb          $v0, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r2;
    // mflo        $v1
    ctx->r3 = lo;
    // lbu         $v0, 0x66($a2)
    ctx->r2 = MEM_BU(0X66, ctx->r6);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // srl         $v0, $v0, 12
    ctx->r2 = S32(U32(ctx->r2) >> 12);
    // sb          $v0, 0x1A($sp)
    MEM_B(0X1A, ctx->r29) = ctx->r2;
    // lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(0X0, ctx->r29);
    // lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(0X4, ctx->r29);
    // ctc2        $t4, $16
    gte_ctc2(ctx, 12, 16);
    // ctc2        $t5, $17
    gte_ctc2(ctx, 13, 17);
    // lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(0X8, ctx->r29);
    // lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(0XC, ctx->r29);
    // lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(0X10, ctx->r29);
    // ctc2        $t4, $18
    gte_ctc2(ctx, 12, 18);
    // ctc2        $t5, $19
    gte_ctc2(ctx, 13, 19);
    // ctc2        $t6, $20
    gte_ctc2(ctx, 14, 20);
    // lbu         $t2, 0x18($sp)
    ctx->r10 = MEM_BU(0X18, ctx->r29);
    // lbu         $t3, 0x19($sp)
    ctx->r11 = MEM_BU(0X19, ctx->r29);
    // sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10) << 4;
    // sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11) << 4;
    // sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2) << 4;
    // ctc2        $t4, $13
    gte_ctc2(ctx, 12, 13);
    // ctc2        $t5, $14
    gte_ctc2(ctx, 13, 14);
    // ctc2        $t6, $15
    gte_ctc2(ctx, 14, 15);
    // j           L_80018434
    // nop

    goto L_80018434;
    // nop

L_80017FDC:
    // andi        $v0, $a1, 0x10
    ctx->r2 = ctx->r5 & 0X10;
    // beq         $v0, $zero, L_800181D4
    if (ctx->r2 == 0) {
        // lui         $a0, 0x8019
        ctx->r4 = S32(0X8019 << 16);
        goto L_800181D4;
    }
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lh          $v0, 0x68($a2)
    ctx->r2 = MEM_HS(0X68, ctx->r6);
    // addiu       $a0, $a0, -0x355C
    ctx->r4 = ADD32(ctx->r4, -0X355C);
    // sw          $v0, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r2;
    // lh          $v0, 0x6A($a2)
    ctx->r2 = MEM_HS(0X6A, ctx->r6);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // sw          $a0, 0x394($a3)
    MEM_W(0X394, ctx->r7) = ctx->r4;
    // sw          $v0, 0x68($a3)
    MEM_W(0X68, ctx->r7) = ctx->r2;
    // lh          $v1, 0x50($a0)
    ctx->r3 = MEM_HS(0X50, ctx->r4);
    // lh          $v0, 0x50($a2)
    ctx->r2 = MEM_HS(0X50, ctx->r6);
    // subu        $a1, $a1, $t0
    ctx->r5 = SUB32(ctx->r5, ctx->r8);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t7
    ctx->r15 = lo;
    // srl         $v0, $t7, 13
    ctx->r2 = S32(U32(ctx->r15) >> 13);
    // sh          $v0, 0x0($sp)
    MEM_H(0X0, ctx->r29) = ctx->r2;
    // lh          $v0, 0x52($a0)
    ctx->r2 = MEM_HS(0X52, ctx->r4);
    // lh          $v1, 0x52($a2)
    ctx->r3 = MEM_HS(0X52, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // srl         $v0, $t2, 13
    ctx->r2 = S32(U32(ctx->r10) >> 13);
    // sh          $v0, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r2;
    // lh          $v0, 0x54($a0)
    ctx->r2 = MEM_HS(0X54, ctx->r4);
    // lh          $v1, 0x54($a2)
    ctx->r3 = MEM_HS(0X54, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t3
    ctx->r11 = lo;
    // srl         $v0, $t3, 13
    ctx->r2 = S32(U32(ctx->r11) >> 13);
    // sh          $v0, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r2;
    // lh          $v0, 0x56($a0)
    ctx->r2 = MEM_HS(0X56, ctx->r4);
    // lh          $v1, 0x56($a2)
    ctx->r3 = MEM_HS(0X56, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t7
    ctx->r15 = lo;
    // srl         $v0, $t7, 13
    ctx->r2 = S32(U32(ctx->r15) >> 13);
    // sh          $v0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r2;
    // lh          $v0, 0x58($a0)
    ctx->r2 = MEM_HS(0X58, ctx->r4);
    // lh          $v1, 0x58($a2)
    ctx->r3 = MEM_HS(0X58, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // srl         $v0, $t2, 13
    ctx->r2 = S32(U32(ctx->r10) >> 13);
    // sh          $v0, 0x8($sp)
    MEM_H(0X8, ctx->r29) = ctx->r2;
    // lh          $v0, 0x5A($a0)
    ctx->r2 = MEM_HS(0X5A, ctx->r4);
    // lh          $v1, 0x5A($a2)
    ctx->r3 = MEM_HS(0X5A, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t3
    ctx->r11 = lo;
    // srl         $v0, $t3, 13
    ctx->r2 = S32(U32(ctx->r11) >> 13);
    // sh          $v0, 0xA($sp)
    MEM_H(0XA, ctx->r29) = ctx->r2;
    // lh          $v0, 0x5C($a0)
    ctx->r2 = MEM_HS(0X5C, ctx->r4);
    // lh          $v1, 0x5C($a2)
    ctx->r3 = MEM_HS(0X5C, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t7
    ctx->r15 = lo;
    // srl         $v0, $t7, 13
    ctx->r2 = S32(U32(ctx->r15) >> 13);
    // sh          $v0, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r2;
    // lh          $v0, 0x5E($a0)
    ctx->r2 = MEM_HS(0X5E, ctx->r4);
    // lh          $v1, 0x5E($a2)
    ctx->r3 = MEM_HS(0X5E, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // srl         $v0, $t2, 13
    ctx->r2 = S32(U32(ctx->r10) >> 13);
    // sh          $v0, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r2;
    // lh          $v0, 0x60($a0)
    ctx->r2 = MEM_HS(0X60, ctx->r4);
    // lh          $v1, 0x60($a2)
    ctx->r3 = MEM_HS(0X60, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t3
    ctx->r11 = lo;
    // srl         $v0, $t3, 13
    ctx->r2 = S32(U32(ctx->r11) >> 13);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x64($a0)
    ctx->r2 = MEM_BU(0X64, ctx->r4);
    // lbu         $v1, 0x64($a2)
    ctx->r3 = MEM_BU(0X64, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t7
    ctx->r15 = lo;
    // srl         $v0, $t7, 13
    ctx->r2 = S32(U32(ctx->r15) >> 13);
    // sb          $v0, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x65($a0)
    ctx->r2 = MEM_BU(0X65, ctx->r4);
    // lbu         $v1, 0x65($a2)
    ctx->r3 = MEM_BU(0X65, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // srl         $v0, $t2, 13
    ctx->r2 = S32(U32(ctx->r10) >> 13);
    // sb          $v0, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x66($a0)
    ctx->r2 = MEM_BU(0X66, ctx->r4);
    // lbu         $v1, 0x66($a2)
    ctx->r3 = MEM_BU(0X66, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t3
    ctx->r11 = lo;
    // srl         $v0, $t3, 13
    ctx->r2 = S32(U32(ctx->r11) >> 13);
    // sb          $v0, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r2;
    // lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(0X0, ctx->r29);
    // lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(0X4, ctx->r29);
    // ctc2        $t4, $16
    gte_ctc2(ctx, 12, 16);
    // ctc2        $t5, $17
    gte_ctc2(ctx, 13, 17);
    // lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(0X8, ctx->r29);
    // lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(0XC, ctx->r29);
    // lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(0X10, ctx->r29);
    // ctc2        $t4, $18
    gte_ctc2(ctx, 12, 18);
    // ctc2        $t5, $19
    gte_ctc2(ctx, 13, 19);
    // ctc2        $t6, $20
    gte_ctc2(ctx, 14, 20);
    // lbu         $t7, 0x20($sp)
    ctx->r15 = MEM_BU(0X20, ctx->r29);
    // lbu         $t2, 0x21($sp)
    ctx->r10 = MEM_BU(0X21, ctx->r29);
    // sll         $t4, $t7, 4
    ctx->r12 = S32(ctx->r15) << 4;
    // sll         $t5, $t2, 4
    ctx->r13 = S32(ctx->r10) << 4;
    // sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2) << 4;
    // ctc2        $t4, $13
    gte_ctc2(ctx, 12, 13);
    // ctc2        $t5, $14
    gte_ctc2(ctx, 13, 14);
    // ctc2        $t6, $15
    gte_ctc2(ctx, 14, 15);
    // j           L_80018434
    // nop

    goto L_80018434;
    // nop

L_800181D4:
    // andi        $v0, $a1, 0x8
    ctx->r2 = ctx->r5 & 0X8;
    // beq         $v0, $zero, L_800183CC
    if (ctx->r2 == 0) {
        // lui         $a0, 0x8019
        ctx->r4 = S32(0X8019 << 16);
        goto L_800183CC;
    }
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lh          $v0, 0x68($a2)
    ctx->r2 = MEM_HS(0X68, ctx->r6);
    // nop

    // sw          $v0, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r2;
    // lh          $v0, 0x6A($a2)
    ctx->r2 = MEM_HS(0X6A, ctx->r6);
    // addiu       $a0, $a0, -0x35C8
    ctx->r4 = ADD32(ctx->r4, -0X35C8);
    // sw          $a0, 0x394($a3)
    MEM_W(0X394, ctx->r7) = ctx->r4;
    // sw          $v0, 0x68($a3)
    MEM_W(0X68, ctx->r7) = ctx->r2;
    // lh          $v0, 0x50($a0)
    ctx->r2 = MEM_HS(0X50, ctx->r4);
    // lh          $v1, 0x50($a2)
    ctx->r3 = MEM_HS(0X50, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t3
    ctx->r11 = lo;
    // srl         $v0, $t3, 13
    ctx->r2 = S32(U32(ctx->r11) >> 13);
    // sh          $v0, 0x0($sp)
    MEM_H(0X0, ctx->r29) = ctx->r2;
    // lh          $v0, 0x52($a0)
    ctx->r2 = MEM_HS(0X52, ctx->r4);
    // lh          $v1, 0x52($a2)
    ctx->r3 = MEM_HS(0X52, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t7
    ctx->r15 = lo;
    // srl         $v0, $t7, 13
    ctx->r2 = S32(U32(ctx->r15) >> 13);
    // sh          $v0, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r2;
    // lh          $v0, 0x54($a0)
    ctx->r2 = MEM_HS(0X54, ctx->r4);
    // lh          $v1, 0x54($a2)
    ctx->r3 = MEM_HS(0X54, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // srl         $v0, $t2, 13
    ctx->r2 = S32(U32(ctx->r10) >> 13);
    // sh          $v0, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r2;
    // lh          $v0, 0x56($a0)
    ctx->r2 = MEM_HS(0X56, ctx->r4);
    // lh          $v1, 0x56($a2)
    ctx->r3 = MEM_HS(0X56, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t3
    ctx->r11 = lo;
    // srl         $v0, $t3, 13
    ctx->r2 = S32(U32(ctx->r11) >> 13);
    // sh          $v0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r2;
    // lh          $v0, 0x58($a0)
    ctx->r2 = MEM_HS(0X58, ctx->r4);
    // lh          $v1, 0x58($a2)
    ctx->r3 = MEM_HS(0X58, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t7
    ctx->r15 = lo;
    // srl         $v0, $t7, 13
    ctx->r2 = S32(U32(ctx->r15) >> 13);
    // sh          $v0, 0x8($sp)
    MEM_H(0X8, ctx->r29) = ctx->r2;
    // lh          $v0, 0x5A($a0)
    ctx->r2 = MEM_HS(0X5A, ctx->r4);
    // lh          $v1, 0x5A($a2)
    ctx->r3 = MEM_HS(0X5A, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // srl         $v0, $t2, 13
    ctx->r2 = S32(U32(ctx->r10) >> 13);
    // sh          $v0, 0xA($sp)
    MEM_H(0XA, ctx->r29) = ctx->r2;
    // lh          $v0, 0x5C($a0)
    ctx->r2 = MEM_HS(0X5C, ctx->r4);
    // lh          $v1, 0x5C($a2)
    ctx->r3 = MEM_HS(0X5C, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t3
    ctx->r11 = lo;
    // srl         $v0, $t3, 13
    ctx->r2 = S32(U32(ctx->r11) >> 13);
    // sh          $v0, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r2;
    // lh          $v0, 0x5E($a0)
    ctx->r2 = MEM_HS(0X5E, ctx->r4);
    // lh          $v1, 0x5E($a2)
    ctx->r3 = MEM_HS(0X5E, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t7
    ctx->r15 = lo;
    // srl         $v0, $t7, 13
    ctx->r2 = S32(U32(ctx->r15) >> 13);
    // sh          $v0, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r2;
    // lh          $v0, 0x60($a0)
    ctx->r2 = MEM_HS(0X60, ctx->r4);
    // lh          $v1, 0x60($a2)
    ctx->r3 = MEM_HS(0X60, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // srl         $v0, $t2, 13
    ctx->r2 = S32(U32(ctx->r10) >> 13);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x64($a0)
    ctx->r2 = MEM_BU(0X64, ctx->r4);
    // lbu         $v1, 0x64($a2)
    ctx->r3 = MEM_BU(0X64, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t3
    ctx->r11 = lo;
    // srl         $v0, $t3, 13
    ctx->r2 = S32(U32(ctx->r11) >> 13);
    // sb          $v0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x65($a0)
    ctx->r2 = MEM_BU(0X65, ctx->r4);
    // lbu         $v1, 0x65($a2)
    ctx->r3 = MEM_BU(0X65, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t7
    ctx->r15 = lo;
    // srl         $v0, $t7, 13
    ctx->r2 = S32(U32(ctx->r15) >> 13);
    // sb          $v0, 0x29($sp)
    MEM_B(0X29, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x66($a0)
    ctx->r2 = MEM_BU(0X66, ctx->r4);
    // lbu         $v1, 0x66($a2)
    ctx->r3 = MEM_BU(0X66, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // srl         $v0, $t2, 13
    ctx->r2 = S32(U32(ctx->r10) >> 13);
    // sb          $v0, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r2;
    // lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(0X0, ctx->r29);
    // lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(0X4, ctx->r29);
    // ctc2        $t4, $16
    gte_ctc2(ctx, 12, 16);
    // ctc2        $t5, $17
    gte_ctc2(ctx, 13, 17);
    // lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(0X8, ctx->r29);
    // lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(0XC, ctx->r29);
    // lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(0X10, ctx->r29);
    // ctc2        $t4, $18
    gte_ctc2(ctx, 12, 18);
    // ctc2        $t5, $19
    gte_ctc2(ctx, 13, 19);
    // ctc2        $t6, $20
    gte_ctc2(ctx, 14, 20);
    // lbu         $t3, 0x28($sp)
    ctx->r11 = MEM_BU(0X28, ctx->r29);
    // lbu         $t7, 0x29($sp)
    ctx->r15 = MEM_BU(0X29, ctx->r29);
    // sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11) << 4;
    // sll         $t5, $t7, 4
    ctx->r13 = S32(ctx->r15) << 4;
    // sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2) << 4;
    // ctc2        $t4, $13
    gte_ctc2(ctx, 12, 13);
    // ctc2        $t5, $14
    gte_ctc2(ctx, 13, 14);
    // ctc2        $t6, $15
    gte_ctc2(ctx, 14, 15);
    // j           L_80018434
    // nop

    goto L_80018434;
    // nop

L_800183CC:
    // lbu         $t2, 0x64($a2)
    ctx->r10 = MEM_BU(0X64, ctx->r6);
    // lbu         $t3, 0x65($a2)
    ctx->r11 = MEM_BU(0X65, ctx->r6);
    // lbu         $t7, 0x66($a2)
    ctx->r15 = MEM_BU(0X66, ctx->r6);
    // sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10) << 4;
    // sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11) << 4;
    // sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15) << 4;
    // ctc2        $t4, $13
    gte_ctc2(ctx, 12, 13);
    // ctc2        $t5, $14
    gte_ctc2(ctx, 13, 14);
    // ctc2        $t6, $15
    gte_ctc2(ctx, 14, 15);
    // addiu       $v0, $a2, 0x50
    ctx->r2 = ADD32(ctx->r6, 0X50);
    // lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(0X0, ctx->r2);
    // lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(0X4, ctx->r2);
    // ctc2        $t4, $16
    gte_ctc2(ctx, 12, 16);
    // ctc2        $t5, $17
    gte_ctc2(ctx, 13, 17);
    // lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(0X8, ctx->r2);
    // lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(0XC, ctx->r2);
    // lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(0X10, ctx->r2);
    // ctc2        $t4, $18
    gte_ctc2(ctx, 12, 18);
    // ctc2        $t5, $19
    gte_ctc2(ctx, 13, 19);
    // ctc2        $t6, $20
    gte_ctc2(ctx, 14, 20);
    // lh          $v0, 0x68($a2)
    ctx->r2 = MEM_HS(0X68, ctx->r6);
    // nop

    // sw          $v0, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r2;
    // lh          $v0, 0x6A($a2)
    ctx->r2 = MEM_HS(0X6A, ctx->r6);
    // nop

    // sw          $v0, 0x68($a3)
    MEM_W(0X68, ctx->r7) = ctx->r2;
L_80018434:
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
