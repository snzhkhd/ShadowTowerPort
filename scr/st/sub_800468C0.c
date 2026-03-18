#include "recomp.h"
#include "disable_warnings.h"

void sub_800468C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v1, $v0, 0x5948
    ctx->r3 = ADD32(ctx->r2, 0X5948);
    // lui         $t3, 0x1F80
    ctx->r11 = S32(0X1F80 << 16);
    // addu        $t9, $sp, $zero
    ctx->r25 = ADD32(ctx->r29, 0);
    // sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lhu         $s7, 0x44CA($v1)
    ctx->r23 = MEM_HU(0X44CA, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // beq         $s7, $v0, L_80047854
    if (ctx->r23 == ctx->r2) {
        // sw          $s7, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r23;
        goto L_80047854;
    }
    // sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // sll         $v0, $s7, 1
    ctx->r2 = S32(ctx->r23) << 1;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // sw          $v0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r2;
L_8004691C:
    // lw          $s7, 0x8($sp)
    ctx->r23 = MEM_W(0X8, ctx->r29);
    // nop

    // lhu         $v0, 0x44CE($s7)
    ctx->r2 = MEM_HU(0X44CE, ctx->r23);
    // nop

    // sll         $a2, $v0, 1
    ctx->r6 = S32(ctx->r2) << 1;
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6) << 2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v0, $v0, -0x4130
    ctx->r2 = ADD32(ctx->r2, -0X4130);
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(0X0, ctx->r6);
    // nop

    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(0X0, ctx->r11);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r3;
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(0X0, ctx->r11);
    // lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(0X4, ctx->r11);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // sw          $v0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r2;
    // lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(0X8, ctx->r4);
    // lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(0X0, ctx->r11);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    // lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(0X10, ctx->r5);
    // lhu         $s5, 0x20($a1)
    ctx->r21 = MEM_HU(0X20, ctx->r5);
    // lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(0X0, ctx->r11);
    // lhu         $a0, 0x18($a1)
    ctx->r4 = MEM_HU(0X18, ctx->r5);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // lhu         $v1, 0x1C($a1)
    ctx->r3 = MEM_HU(0X1C, ctx->r5);
    // addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lhu         $v1, 0x1A($a1)
    ctx->r3 = MEM_HU(0X1A, ctx->r5);
    // addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // lhu         $v1, 0x1E($a1)
    ctx->r3 = MEM_HU(0X1E, ctx->r5);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // lbu         $v1, 0x3($a2)
    ctx->r3 = MEM_BU(0X3, ctx->r6);
    // addiu       $v0, $v0, 0x42C
    ctx->r2 = ADD32(ctx->r2, 0X42C);
    // andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // beq         $a0, $zero, L_800477D4
    if (ctx->r4 == 0) {
        // addu        $fp, $v1, $v0
        ctx->r30 = ADD32(ctx->r3, ctx->r2);
        goto L_800477D4;
    }
    // addu        $fp, $v1, $v0
    ctx->r30 = ADD32(ctx->r3, ctx->r2);
    // lw          $s6, 0x8($sp)
    ctx->r22 = MEM_W(0X8, ctx->r29);
    // addiu       $t7, $t8, 0x2
    ctx->r15 = ADD32(ctx->r24, 0X2);
L_80046A20:
    // lhu         $v1, 0x2($t7)
    ctx->r3 = MEM_HU(0X2, ctx->r15);
    // lw          $v0, 0x8($t3)
    ctx->r2 = MEM_W(0X8, ctx->r11);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(0X0, ctx->r30);
    // lw          $t5, 0x4($fp)
    ctx->r13 = MEM_W(0X4, ctx->r30);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($fp)
    ctx->r12 = MEM_W(0X8, ctx->r30);
    // lw          $t5, 0xC($fp)
    ctx->r13 = MEM_W(0XC, ctx->r30);
    // lw          $t6, 0x10($fp)
    ctx->r14 = MEM_W(0X10, ctx->r30);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // nop

    // nop

    // .word       0x4A486012                   # INVALID     $s2, $t0, 0x6012 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A486012);
    // mfc2        $t4, $9
    ctx->r12 = gte_mfc2(ctx, 9);
    // mfc2        $t5, $10
    ctx->r13 = gte_mfc2(ctx, 10);
    // mfc2        $t6, $11
    ctx->r14 = gte_mfc2(ctx, 11);
    // sh          $t4, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r12;
    // sh          $t5, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r13;
    // sh          $t6, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r14;
    // lhu         $v0, 0x148($t3)
    ctx->r2 = MEM_HU(0X148, ctx->r11);
    // lh          $v1, 0x0($t9)
    ctx->r3 = MEM_HS(0X0, ctx->r25);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v1, 0x2($t9)
    ctx->r3 = MEM_HU(0X2, ctx->r25);
    // lhu         $v0, 0x14A($t3)
    ctx->r2 = MEM_HU(0X14A, ctx->r11);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // mflo        $a1
    ctx->r5 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v1, 0x4($t9)
    ctx->r3 = MEM_HU(0X4, ctx->r25);
    // lhu         $v0, 0x14C($t3)
    ctx->r2 = MEM_HU(0X14C, ctx->r11);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // mflo        $a0
    ctx->r4 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // blez        $v0, L_80046B00
    if (SIGNED(ctx->r2) <= 0) {
        // lui         $v1, 0x5
        ctx->r3 = S32(0X5 << 16);
        goto L_80046B00;
    }
    // lui         $v1, 0x5
    ctx->r3 = S32(0X5 << 16);
    // lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(0X0, ctx->r24);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_800477C0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800477C0;
    }
    // nop

L_80046B00:
    // lhu         $v0, 0x4($t7)
    ctx->r2 = MEM_HU(0X4, ctx->r15);
    // lw          $a0, 0x10($t3)
    ctx->r4 = MEM_W(0X10, ctx->r11);
    // lh          $t1, 0x0($t9)
    ctx->r9 = MEM_HS(0X0, ctx->r25);
    // sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // nop

    // mult        $t1, $v0
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(0X4, ctx->r4);
    // lhu         $v0, 0x2($t9)
    ctx->r2 = MEM_HU(0X2, ctx->r25);
    // mflo        $t2
    ctx->r10 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2) >> 16;
    // mult        $t0, $v1
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x4($t9)
    ctx->r2 = MEM_HU(0X4, ctx->r25);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // mflo        $a2
    ctx->r6 = lo;
    // lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(0X8, ctx->r4);
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // mult        $a3, $v1
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0xE4($t3)
    ctx->r2 = MEM_W(0XE4, ctx->r11);
    // nop

    // mult        $t1, $v0
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // lw          $v0, 0xE8($t3)
    ctx->r2 = MEM_W(0XE8, ctx->r11);
    // nop

    // mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0xEC($t3)
    ctx->r2 = MEM_W(0XEC, ctx->r11);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $t2, $a2
    ctx->r2 = ADD32(ctx->r10, ctx->r6);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // negu        $a2, $v0
    ctx->r6 = SUB32(0, ctx->r2);
    // addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // mflo        $s0
    ctx->r16 = lo;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // bgez        $v1, L_80046BAC
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80046BAC;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80046BAC:
    // lw          $v0, 0xF4($t3)
    ctx->r2 = MEM_W(0XF4, ctx->r11);
    // nop

    // mult        $t1, $v0
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // lw          $v0, 0xF8($t3)
    ctx->r2 = MEM_W(0XF8, ctx->r11);
    // nop

    // mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0xFC($t3)
    ctx->r2 = MEM_W(0XFC, ctx->r11);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // mflo        $t2
    ctx->r10 = lo;
    // addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // addu        $a0, $v0, $a2
    ctx->r4 = ADD32(ctx->r2, ctx->r6);
    // bgez        $a0, L_80046BF4
    if (SIGNED(ctx->r4) >= 0) {
        // sra         $s0, $v1, 12
        ctx->r16 = S32(ctx->r3) >> 12;
        goto L_80046BF4;
    }
    // sra         $s0, $v1, 12
    ctx->r16 = S32(ctx->r3) >> 12;
    // addiu       $a0, $a0, 0xFFF
    ctx->r4 = ADD32(ctx->r4, 0XFFF);
L_80046BF4:
    // lw          $v0, 0x104($t3)
    ctx->r2 = MEM_W(0X104, ctx->r11);
    // nop

    // mult        $t1, $v0
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // lw          $v0, 0x108($t3)
    ctx->r2 = MEM_W(0X108, ctx->r11);
    // nop

    // mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x10C($t3)
    ctx->r2 = MEM_W(0X10C, ctx->r11);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // mflo        $a3
    ctx->r7 = lo;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // bgez        $v0, L_80046C3C
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $s1, $a0, 12
        ctx->r17 = S32(ctx->r4) >> 12;
        goto L_80046C3C;
    }
    // sra         $s1, $a0, 12
    ctx->r17 = S32(ctx->r4) >> 12;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80046C3C:
    // sra         $s4, $v0, 12
    ctx->r20 = S32(ctx->r2) >> 12;
    // slti        $v0, $s0, -0x100
    ctx->r2 = SIGNED(ctx->r16) < -0X100 ? 1 : 0;
    // bne         $v0, $zero, L_800477C0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800477C0;
    }
    // nop

    // lw          $v1, 0x14($t3)
    ctx->r3 = MEM_W(0X14, ctx->r11);
    // lhu         $a1, 0x6($t7)
    ctx->r5 = MEM_HU(0X6, ctx->r15);
    // lhu         $v0, 0x8($t7)
    ctx->r2 = MEM_HU(0X8, ctx->r15);
    // lw          $a0, 0x18($t3)
    ctx->r4 = MEM_W(0X18, ctx->r11);
    // lw          $a2, 0x1C($t3)
    ctx->r6 = MEM_W(0X1C, ctx->r11);
    // addu        $s2, $v1, $t4
    ctx->r18 = ADD32(ctx->r3, ctx->r12);
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    // addu        $a3, $v1, $a1
    ctx->r7 = ADD32(ctx->r3, ctx->r5);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addu        $t1, $a0, $t4
    ctx->r9 = ADD32(ctx->r4, ctx->r12);
    // addu        $t0, $a0, $a1
    ctx->r8 = ADD32(ctx->r4, ctx->r5);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $t2, $a2, $t4
    ctx->r10 = ADD32(ctx->r6, ctx->r12);
    // addu        $a1, $a2, $a1
    ctx->r5 = ADD32(ctx->r6, ctx->r5);
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(0X0, ctx->r18);
    // lw          $t5, 0x4($s2)
    ctx->r13 = MEM_W(0X4, ctx->r18);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // lw          $t6, 0x8($s2)
    ctx->r14 = MEM_W(0X8, ctx->r18);
    // ctc2        $t5, $2
    gte_ctc2(ctx, 13, 2);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lwc2        $11, 0x8($a3)
    gte_lwc2(rdram, ctx, 11, 7, 8);
    // lwc2        $9, 0x0($a3)
    gte_lwc2(rdram, ctx, 9, 7, 0);
    // lwc2        $10, 0x4($a3)
    gte_lwc2(rdram, ctx, 10, 7, 4);
    // nop

    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // addiu       $v0, $t3, 0x24
    ctx->r2 = ADD32(ctx->r11, 0X24);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(0X0, ctx->r7);
    // lw          $t5, 0x4($a3)
    ctx->r13 = MEM_W(0X4, ctx->r7);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(0X8, ctx->r7);
    // ctc2        $t5, $2
    gte_ctc2(ctx, 13, 2);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lwc2        $11, 0x8($v1)
    gte_lwc2(rdram, ctx, 11, 3, 8);
    // lwc2        $9, 0x0($v1)
    gte_lwc2(rdram, ctx, 9, 3, 0);
    // lwc2        $10, 0x4($v1)
    gte_lwc2(rdram, ctx, 10, 3, 4);
    // nop

    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // addiu       $v0, $t3, 0x34
    ctx->r2 = ADD32(ctx->r11, 0X34);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(0X0, ctx->r3);
    // lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(0X4, ctx->r3);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(0X8, ctx->r3);
    // ctc2        $t5, $2
    gte_ctc2(ctx, 13, 2);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lwc2        $11, 0x8($s2)
    gte_lwc2(rdram, ctx, 11, 18, 8);
    // lwc2        $9, 0x0($s2)
    gte_lwc2(rdram, ctx, 9, 18, 0);
    // lwc2        $10, 0x4($s2)
    gte_lwc2(rdram, ctx, 10, 18, 4);
    // nop

    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // addiu       $v0, $t3, 0x44
    ctx->r2 = ADD32(ctx->r11, 0X44);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(0X0, ctx->r9);
    // lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(0X4, ctx->r9);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // lw          $t6, 0x8($t1)
    ctx->r14 = MEM_W(0X8, ctx->r9);
    // ctc2        $t5, $2
    gte_ctc2(ctx, 13, 2);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lwc2        $11, 0x8($t0)
    gte_lwc2(rdram, ctx, 11, 8, 8);
    // lwc2        $9, 0x0($t0)
    gte_lwc2(rdram, ctx, 9, 8, 0);
    // lwc2        $10, 0x4($t0)
    gte_lwc2(rdram, ctx, 10, 8, 4);
    // nop

    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // addiu       $v0, $t3, 0x64
    ctx->r2 = ADD32(ctx->r11, 0X64);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(0X0, ctx->r8);
    // lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(0X4, ctx->r8);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(0X8, ctx->r8);
    // ctc2        $t5, $2
    gte_ctc2(ctx, 13, 2);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lwc2        $11, 0x8($a0)
    gte_lwc2(rdram, ctx, 11, 4, 8);
    // lwc2        $9, 0x0($a0)
    gte_lwc2(rdram, ctx, 9, 4, 0);
    // lwc2        $10, 0x4($a0)
    gte_lwc2(rdram, ctx, 10, 4, 4);
    // nop

    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // addiu       $v0, $t3, 0x74
    ctx->r2 = ADD32(ctx->r11, 0X74);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(0X0, ctx->r4);
    // lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(0X4, ctx->r4);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(0X8, ctx->r4);
    // ctc2        $t5, $2
    gte_ctc2(ctx, 13, 2);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lwc2        $11, 0x8($t1)
    gte_lwc2(rdram, ctx, 11, 9, 8);
    // lwc2        $9, 0x0($t1)
    gte_lwc2(rdram, ctx, 9, 9, 0);
    // lwc2        $10, 0x4($t1)
    gte_lwc2(rdram, ctx, 10, 9, 4);
    // nop

    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // addiu       $v0, $t3, 0x84
    ctx->r2 = ADD32(ctx->r11, 0X84);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(0X0, ctx->r10);
    // lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(0X4, ctx->r10);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // lw          $t6, 0x8($t2)
    ctx->r14 = MEM_W(0X8, ctx->r10);
    // ctc2        $t5, $2
    gte_ctc2(ctx, 13, 2);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lwc2        $11, 0x8($a1)
    gte_lwc2(rdram, ctx, 11, 5, 8);
    // lwc2        $9, 0x0($a1)
    gte_lwc2(rdram, ctx, 9, 5, 0);
    // lwc2        $10, 0x4($a1)
    gte_lwc2(rdram, ctx, 10, 5, 4);
    // nop

    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // addiu       $v0, $t3, 0xA4
    ctx->r2 = ADD32(ctx->r11, 0XA4);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(0X0, ctx->r5);
    // lw          $t5, 0x4($a1)
    ctx->r13 = MEM_W(0X4, ctx->r5);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(0X8, ctx->r5);
    // ctc2        $t5, $2
    gte_ctc2(ctx, 13, 2);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lwc2        $11, 0x8($a2)
    gte_lwc2(rdram, ctx, 11, 6, 8);
    // lwc2        $9, 0x0($a2)
    gte_lwc2(rdram, ctx, 9, 6, 0);
    // lwc2        $10, 0x4($a2)
    gte_lwc2(rdram, ctx, 10, 6, 4);
    // nop

    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // addiu       $v0, $t3, 0xB4
    ctx->r2 = ADD32(ctx->r11, 0XB4);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(0X0, ctx->r6);
    // lw          $t5, 0x4($a2)
    ctx->r13 = MEM_W(0X4, ctx->r6);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(0X8, ctx->r6);
    // ctc2        $t5, $2
    gte_ctc2(ctx, 13, 2);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lwc2        $11, 0x8($t2)
    gte_lwc2(rdram, ctx, 11, 10, 8);
    // lwc2        $9, 0x0($t2)
    gte_lwc2(rdram, ctx, 9, 10, 0);
    // lwc2        $10, 0x4($t2)
    gte_lwc2(rdram, ctx, 10, 10, 4);
    // nop

    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // addiu       $v0, $t3, 0xC4
    ctx->r2 = ADD32(ctx->r11, 0XC4);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(0X0, ctx->r15);
    // nop

    // andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // beq         $v0, $zero, L_80046FBC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80046FBC;
    }
    // nop

    // lw          $v0, 0x28($t3)
    ctx->r2 = MEM_W(0X28, ctx->r11);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // bltz        $v0, L_80046F54
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s1, -0x100
        ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
        goto L_80046F54;
    }
    // slti        $v0, $s1, -0x100
    ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
    // lw          $v0, 0x38($t3)
    ctx->r2 = MEM_W(0X38, ctx->r11);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // bltz        $v0, L_80046F54
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s1, -0x100
        ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
        goto L_80046F54;
    }
    // slti        $v0, $s1, -0x100
    ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
    // lw          $v0, 0x48($t3)
    ctx->r2 = MEM_W(0X48, ctx->r11);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // bltz        $v0, L_80046F54
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s1, -0x100
        ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
        goto L_80046F54;
    }
    // slti        $v0, $s1, -0x100
    ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
    // lw          $v0, 0x120($t3)
    ctx->r2 = MEM_W(0X120, ctx->r11);
    // nop

    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80046F54
    if (ctx->r2 == 0) {
        // slti        $v0, $s1, -0x100
        ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
        goto L_80046F54;
    }
    // slti        $v0, $s1, -0x100
    ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
    // sw          $s0, 0x120($t3)
    MEM_W(0X120, ctx->r11) = ctx->r16;
    // lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(0X0, ctx->r25);
    // lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(0X4, ctx->r25);
    // sw          $v0, 0x150($t3)
    MEM_W(0X150, ctx->r11) = ctx->r2;
    // sw          $v1, 0x154($t3)
    MEM_W(0X154, ctx->r11) = ctx->r3;
    // slti        $v0, $s1, -0x100
    ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
L_80046F54:
    // bne         $v0, $zero, L_800477C0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800477C0;
    }
    // nop

    // lw          $v0, 0x68($t3)
    ctx->r2 = MEM_W(0X68, ctx->r11);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // bltz        $v0, L_80046FBC
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_80046FBC;
    }
    // nop

    // lw          $v0, 0x78($t3)
    ctx->r2 = MEM_W(0X78, ctx->r11);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // bltz        $v0, L_80046FBC
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_80046FBC;
    }
    // nop

    // lw          $v0, 0x88($t3)
    ctx->r2 = MEM_W(0X88, ctx->r11);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // bltz        $v0, L_80046FBC
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_80046FBC;
    }
    // nop

    // lw          $v0, 0x124($t3)
    ctx->r2 = MEM_W(0X124, ctx->r11);
    // nop

    // slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80046FBC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80046FBC;
    }
    // nop

    // sw          $s1, 0x124($t3)
    MEM_W(0X124, ctx->r11) = ctx->r17;
L_80046FBC:
    // lhu         $v1, 0x0($t7)
    ctx->r3 = MEM_HU(0X0, ctx->r15);
    // nop

    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // beq         $v0, $zero, L_80047310
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80047310;
    }
    // nop

    // lw          $v0, 0x28($t3)
    ctx->r2 = MEM_W(0X28, ctx->r11);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_80047298
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s1, -0x100
        ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
        goto L_80047298;
    }
    // slti        $v0, $s1, -0x100
    ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
    // lw          $v0, 0x38($t3)
    ctx->r2 = MEM_W(0X38, ctx->r11);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_80047298
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s1, -0x100
        ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
        goto L_80047298;
    }
    // slti        $v0, $s1, -0x100
    ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
    // lw          $v0, 0x48($t3)
    ctx->r2 = MEM_W(0X48, ctx->r11);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_80047298
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s1, -0x100
        ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
        goto L_80047298;
    }
    // slti        $v0, $s1, -0x100
    ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
    // lw          $v0, 0x114($t3)
    ctx->r2 = MEM_W(0X114, ctx->r11);
    // nop

    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80047294
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x800
        ctx->r2 = ctx->r3 & 0X800;
        goto L_80047294;
    }
    // andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // beq         $v0, $zero, L_8004705C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004705C;
    }
    // nop

    // lw          $v0, 0x47E0($s3)
    ctx->r2 = MEM_W(0X47E0, ctx->r19);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_8004705C
    if (ctx->r2 != 0) {
        // addiu       $v1, $zero, -0x11
        ctx->r3 = ADD32(0, -0X11);
        goto L_8004705C;
    }
    // addiu       $v1, $zero, -0x11
    ctx->r3 = ADD32(0, -0X11);
    // lw          $v0, 0x198($t3)
    ctx->r2 = MEM_W(0X198, ctx->r11);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addiu       $v1, $zero, -0x9
    ctx->r3 = ADD32(0, -0X9);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addiu       $v1, $zero, -0x21
    ctx->r3 = ADD32(0, -0X21);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x198($t3)
    MEM_W(0X198, ctx->r11) = ctx->r2;
L_8004705C:
    // lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(0X0, ctx->r15);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_80047088
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80047088;
    }
    // nop

    // lw          $v0, 0x47E0($s3)
    ctx->r2 = MEM_W(0X47E0, ctx->r19);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_80047088
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80047088;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, 0x198($t3)
    MEM_W(0X198, ctx->r11) = ctx->r2;
L_80047088:
    // lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(0X0, ctx->r15);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_800470B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800470B8;
    }
    // nop

    // lw          $v0, 0x47E0($s3)
    ctx->r2 = MEM_W(0X47E0, ctx->r19);
    // nop

    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_800470B8
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_800470B8;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sw          $v0, 0x198($t3)
    MEM_W(0X198, ctx->r11) = ctx->r2;
L_800470B8:
    // lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(0X0, ctx->r15);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_80047104
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80047104;
    }
    // nop

    // lw          $v0, 0x47E0($s3)
    ctx->r2 = MEM_W(0X47E0, ctx->r19);
    // nop

    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_80047104
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80047104;
    }
    // nop

    // lw          $v0, 0x198($t3)
    ctx->r2 = MEM_W(0X198, ctx->r11);
    // lw          $v1, 0xE8($t3)
    ctx->r3 = MEM_W(0XE8, ctx->r11);
    // ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // sw          $v0, 0x198($t3)
    MEM_W(0X198, ctx->r11) = ctx->r2;
    // lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(0X4, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x138($t3)
    MEM_W(0X138, ctx->r11) = ctx->r2;
L_80047104:
    // lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(0X0, ctx->r15);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_80047134
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80047134;
    }
    // nop

    // lw          $v0, 0x47E0($s3)
    ctx->r2 = MEM_W(0X47E0, ctx->r19);
    // nop

    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_80047134
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_80047134;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // sw          $v0, 0x198($t3)
    MEM_W(0X198, ctx->r11) = ctx->r2;
L_80047134:
    // lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(0X0, ctx->r15);
    // nop

    // andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // beq         $v0, $zero, L_80047164
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80047164;
    }
    // nop

    // lw          $v0, 0x47E0($s3)
    ctx->r2 = MEM_W(0X47E0, ctx->r19);
    // nop

    // srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_80047164
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
        goto L_80047164;
    }
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x198($t3)
    MEM_W(0X198, ctx->r11) = ctx->r2;
L_80047164:
    // lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(0X0, ctx->r15);
    // nop

    // andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // beq         $v0, $zero, L_800471B0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800471B0;
    }
    // nop

    // lw          $v0, 0x47E0($s3)
    ctx->r2 = MEM_W(0X47E0, ctx->r19);
    // nop

    // srl         $v0, $v0, 5
    ctx->r2 = S32(U32(ctx->r2) >> 5);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_800471B0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800471B0;
    }
    // nop

    // lw          $v0, 0x198($t3)
    ctx->r2 = MEM_W(0X198, ctx->r11);
    // lw          $v1, 0xE8($t3)
    ctx->r3 = MEM_W(0XE8, ctx->r11);
    // ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // sw          $v0, 0x198($t3)
    MEM_W(0X198, ctx->r11) = ctx->r2;
    // lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(0X4, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x144($t3)
    MEM_W(0X144, ctx->r11) = ctx->r2;
L_800471B0:
    // lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(0X0, ctx->r15);
    // nop

    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // bne         $v0, $zero, L_800477C0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800477C0;
    }
    // nop

    // lhu         $v0, 0x44CE($s6)
    ctx->r2 = MEM_HU(0X44CE, ctx->r22);
    // sw          $s0, 0x114($t3)
    MEM_W(0X114, ctx->r11) = ctx->r16;
    // sh          $v0, 0x22($t3)
    MEM_H(0X22, ctx->r11) = ctx->r2;
    // lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(0X0, ctx->r25);
    // lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(0X4, ctx->r25);
    // sw          $v0, 0x158($t3)
    MEM_W(0X158, ctx->r11) = ctx->r2;
    // sw          $v1, 0x15C($t3)
    MEM_W(0X15C, ctx->r11) = ctx->r3;
    // lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(0X0, ctx->r24);
    // sh          $zero, 0x192($t3)
    MEM_H(0X192, ctx->r11) = 0;
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // sh          $v0, 0x190($t3)
    MEM_H(0X190, ctx->r11) = ctx->r2;
    // lbu         $v0, -0x1($t7)
    ctx->r2 = MEM_BU(-0X1, ctx->r15);
    // nop

    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // sh          $v0, 0x194($t3)
    MEM_H(0X194, ctx->r11) = ctx->r2;
    // lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(0X0, ctx->r30);
    // lw          $t5, 0x4($fp)
    ctx->r13 = MEM_W(0X4, ctx->r30);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($fp)
    ctx->r12 = MEM_W(0X8, ctx->r30);
    // lw          $t5, 0xC($fp)
    ctx->r13 = MEM_W(0XC, ctx->r30);
    // lw          $t6, 0x10($fp)
    ctx->r14 = MEM_W(0X10, ctx->r30);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // addiu       $v0, $t3, 0x190
    ctx->r2 = ADD32(ctx->r11, 0X190);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // nop

    // nop

    // .word       0x4A486012                   # INVALID     $s2, $t0, 0x6012 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A486012);
    // mfc2        $t4, $9
    ctx->r12 = gte_mfc2(ctx, 9);
    // mfc2        $t5, $10
    ctx->r13 = gte_mfc2(ctx, 10);
    // mfc2        $t6, $11
    ctx->r14 = gte_mfc2(ctx, 11);
    // sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // lhu         $v0, 0x47CE($s3)
    ctx->r2 = MEM_HU(0X47CE, ctx->r19);
    // lhu         $v1, 0x190($t3)
    ctx->r3 = MEM_HU(0X190, ctx->r11);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x47CE($s3)
    MEM_H(0X47CE, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x47D0($s3)
    ctx->r2 = MEM_HU(0X47D0, ctx->r19);
    // lhu         $a0, 0x192($t3)
    ctx->r4 = MEM_HU(0X192, ctx->r11);
    // lhu         $v1, 0x47D2($s3)
    ctx->r3 = MEM_HU(0X47D2, ctx->r19);
    // lhu         $a1, 0x194($t3)
    ctx->r5 = MEM_HU(0X194, ctx->r11);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sh          $v0, 0x47D0($s3)
    MEM_H(0X47D0, ctx->r19) = ctx->r2;
    // sh          $v1, 0x47D2($s3)
    MEM_H(0X47D2, ctx->r19) = ctx->r3;
L_80047294:
    // slti        $v0, $s1, -0x100
    ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
L_80047298:
    // bne         $v0, $zero, L_800477C0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800477C0;
    }
    // nop

    // lw          $v0, 0x68($t3)
    ctx->r2 = MEM_W(0X68, ctx->r11);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_80047310
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_80047310;
    }
    // nop

    // lw          $v0, 0x78($t3)
    ctx->r2 = MEM_W(0X78, ctx->r11);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_80047310
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_80047310;
    }
    // nop

    // lw          $v0, 0x88($t3)
    ctx->r2 = MEM_W(0X88, ctx->r11);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_80047310
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_80047310;
    }
    // nop

    // lw          $v0, 0x118($t3)
    ctx->r2 = MEM_W(0X118, ctx->r11);
    // nop

    // slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80047310
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80047310;
    }
    // nop

    // sw          $s1, 0x118($t3)
    MEM_W(0X118, ctx->r11) = ctx->r17;
    // lhu         $v0, 0x44CE($s6)
    ctx->r2 = MEM_HU(0X44CE, ctx->r22);
    // nop

    // sw          $v0, 0x47D8($s3)
    MEM_W(0X47D8, ctx->r19) = ctx->r2;
    // lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(0X0, ctx->r25);
    // lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(0X4, ctx->r25);
    // sw          $v0, 0x160($t3)
    MEM_W(0X160, ctx->r11) = ctx->r2;
    // sw          $v1, 0x164($t3)
    MEM_W(0X164, ctx->r11) = ctx->r3;
L_80047310:
    // lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(0X0, ctx->r15);
    // nop

    // andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // beq         $v0, $zero, L_800477C0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800477C0;
    }
    // nop

    // lh          $a3, 0x0($t9)
    ctx->r7 = MEM_HS(0X0, ctx->r25);
    // lw          $v0, 0x24($t3)
    ctx->r2 = MEM_W(0X24, ctx->r11);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x28($t3)
    ctx->r3 = MEM_W(0X28, ctx->r11);
    // lhu         $v0, 0x2($t9)
    ctx->r2 = MEM_HU(0X2, ctx->r25);
    // mflo        $t0
    ctx->r8 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
    // mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x4($t9)
    ctx->r2 = MEM_HU(0X4, ctx->r25);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(0X2C, ctx->r11);
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // mult        $a1, $v1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $t0, $a0
    ctx->r2 = ADD32(ctx->r8, ctx->r4);
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // bgtz        $v0, L_800473FC
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_800473FC;
    }
    // nop

    // lw          $v0, 0x34($t3)
    ctx->r2 = MEM_W(0X34, ctx->r11);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0x38($t3)
    ctx->r2 = MEM_W(0X38, ctx->r11);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x3C($t3)
    ctx->r2 = MEM_W(0X3C, ctx->r11);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bgtz        $v0, L_800473FC
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_800473FC;
    }
    // nop

    // lw          $v0, 0x44($t3)
    ctx->r2 = MEM_W(0X44, ctx->r11);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0x48($t3)
    ctx->r2 = MEM_W(0X48, ctx->r11);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x4C($t3)
    ctx->r2 = MEM_W(0X4C, ctx->r11);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $a1
    ctx->r5 = lo;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // blez        $v0, L_80047504
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80047504;
    }
    // nop

L_800473FC:
    // lhu         $v0, 0x148($t3)
    ctx->r2 = MEM_HU(0X148, ctx->r11);
    // lw          $v1, 0x24($t3)
    ctx->r3 = MEM_W(0X24, ctx->r11);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // mult        $a3, $v1
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x14A($t3)
    ctx->r2 = MEM_HU(0X14A, ctx->r11);
    // lw          $v1, 0x28($t3)
    ctx->r3 = MEM_W(0X28, ctx->r11);
    // mflo        $t0
    ctx->r8 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
    // mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x14C($t3)
    ctx->r2 = MEM_HU(0X14C, ctx->r11);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v1, 0x2C($t3)
    ctx->r3 = MEM_W(0X2C, ctx->r11);
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // mult        $a1, $v1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $t0, $a0
    ctx->r2 = ADD32(ctx->r8, ctx->r4);
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // bltz        $v0, L_80047538
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s1, -0x100
        ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
        goto L_80047538;
    }
    // slti        $v0, $s1, -0x100
    ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
    // lw          $v0, 0x34($t3)
    ctx->r2 = MEM_W(0X34, ctx->r11);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0x38($t3)
    ctx->r2 = MEM_W(0X38, ctx->r11);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x3C($t3)
    ctx->r2 = MEM_W(0X3C, ctx->r11);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bltz        $v0, L_80047538
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s1, -0x100
        ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
        goto L_80047538;
    }
    // slti        $v0, $s1, -0x100
    ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
    // lw          $v0, 0x44($t3)
    ctx->r2 = MEM_W(0X44, ctx->r11);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0x48($t3)
    ctx->r2 = MEM_W(0X48, ctx->r11);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x4C($t3)
    ctx->r2 = MEM_W(0X4C, ctx->r11);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $a1
    ctx->r5 = lo;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // bltz        $v0, L_80047538
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s1, -0x100
        ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
        goto L_80047538;
    }
    // slti        $v0, $s1, -0x100
    ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
    // lw          $v0, 0x12C($t3)
    ctx->r2 = MEM_W(0X12C, ctx->r11);
    // nop

    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80047538
    if (ctx->r2 == 0) {
        // slti        $v0, $s1, -0x100
        ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
        goto L_80047538;
    }
    // slti        $v0, $s1, -0x100
    ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
    // sw          $s0, 0x12C($t3)
    MEM_W(0X12C, ctx->r11) = ctx->r16;
    // lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(0X0, ctx->r25);
    // lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(0X4, ctx->r25);
    // sw          $v0, 0x178($t3)
    MEM_W(0X178, ctx->r11) = ctx->r2;
    // j           L_80047534
    // sw          $v1, 0x17C($t3)
    MEM_W(0X17C, ctx->r11) = ctx->r3;
    goto L_80047534;
    // sw          $v1, 0x17C($t3)
    MEM_W(0X17C, ctx->r11) = ctx->r3;
L_80047504:
    // lw          $v0, 0x128($t3)
    ctx->r2 = MEM_W(0X128, ctx->r11);
    // nop

    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80047538
    if (ctx->r2 == 0) {
        // slti        $v0, $s1, -0x100
        ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
        goto L_80047538;
    }
    // slti        $v0, $s1, -0x100
    ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
    // lhu         $v0, 0x44CE($s6)
    ctx->r2 = MEM_HU(0X44CE, ctx->r22);
    // sw          $s0, 0x128($t3)
    MEM_W(0X128, ctx->r11) = ctx->r16;
    // sh          $v0, 0x22($t3)
    MEM_H(0X22, ctx->r11) = ctx->r2;
    // lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(0X0, ctx->r25);
    // lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(0X4, ctx->r25);
    // sw          $v0, 0x170($t3)
    MEM_W(0X170, ctx->r11) = ctx->r2;
    // sw          $v1, 0x174($t3)
    MEM_W(0X174, ctx->r11) = ctx->r3;
L_80047534:
    // slti        $v0, $s1, -0x100
    ctx->r2 = SIGNED(ctx->r17) < -0X100 ? 1 : 0;
L_80047538:
    // bne         $v0, $zero, L_800477C0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800477C0;
    }
    // nop

    // lw          $v0, 0x68($t3)
    ctx->r2 = MEM_W(0X68, ctx->r11);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_800475B0
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_800475B0;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $v0, 0x78($t3)
    ctx->r2 = MEM_W(0X78, ctx->r11);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_800475B0
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_800475B0;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $v0, 0x88($t3)
    ctx->r2 = MEM_W(0X88, ctx->r11);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_800475B0
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_800475B0;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $v0, 0x11C($t3)
    ctx->r2 = MEM_W(0X11C, ctx->r11);
    // nop

    // slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800475B0
    if (ctx->r2 == 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_800475B0;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lhu         $v0, 0x44CE($s6)
    ctx->r2 = MEM_HU(0X44CE, ctx->r22);
    // sw          $s1, 0x11C($t3)
    MEM_W(0X11C, ctx->r11) = ctx->r17;
    // sh          $v0, 0x22($t3)
    MEM_H(0X22, ctx->r11) = ctx->r2;
    // lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(0X0, ctx->r25);
    // lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(0X4, ctx->r25);
    // sw          $v0, 0x168($t3)
    MEM_W(0X168, ctx->r11) = ctx->r2;
    // sw          $v1, 0x16C($t3)
    MEM_W(0X16C, ctx->r11) = ctx->r3;
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
L_800475B0:
    // bne         $v0, $zero, L_800477C0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800477C0;
    }
    // nop

    // lh          $a3, 0x0($t9)
    ctx->r7 = MEM_HS(0X0, ctx->r25);
    // lw          $v0, 0xA4($t3)
    ctx->r2 = MEM_W(0XA4, ctx->r11);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0xA8($t3)
    ctx->r3 = MEM_W(0XA8, ctx->r11);
    // lhu         $v0, 0x2($t9)
    ctx->r2 = MEM_HU(0X2, ctx->r25);
    // mflo        $t0
    ctx->r8 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
    // mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x4($t9)
    ctx->r2 = MEM_HU(0X4, ctx->r25);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v1, 0xAC($t3)
    ctx->r3 = MEM_W(0XAC, ctx->r11);
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // mult        $a1, $v1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $t0, $a0
    ctx->r2 = ADD32(ctx->r8, ctx->r4);
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // bgtz        $v0, L_80047690
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_80047690;
    }
    // nop

    // lw          $v0, 0xB4($t3)
    ctx->r2 = MEM_W(0XB4, ctx->r11);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0xB8($t3)
    ctx->r2 = MEM_W(0XB8, ctx->r11);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0xBC($t3)
    ctx->r2 = MEM_W(0XBC, ctx->r11);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bgtz        $v0, L_80047690
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_80047690;
    }
    // nop

    // lw          $v0, 0xC4($t3)
    ctx->r2 = MEM_W(0XC4, ctx->r11);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0xC8($t3)
    ctx->r2 = MEM_W(0XC8, ctx->r11);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0xCC($t3)
    ctx->r2 = MEM_W(0XCC, ctx->r11);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $a1
    ctx->r5 = lo;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // blez        $v0, L_80047798
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80047798;
    }
    // nop

L_80047690:
    // lhu         $v0, 0x148($t3)
    ctx->r2 = MEM_HU(0X148, ctx->r11);
    // lw          $v1, 0xA4($t3)
    ctx->r3 = MEM_W(0XA4, ctx->r11);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // mult        $a3, $v1
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x14A($t3)
    ctx->r2 = MEM_HU(0X14A, ctx->r11);
    // lw          $v1, 0xA8($t3)
    ctx->r3 = MEM_W(0XA8, ctx->r11);
    // mflo        $t0
    ctx->r8 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
    // mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x14C($t3)
    ctx->r2 = MEM_HU(0X14C, ctx->r11);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v1, 0xAC($t3)
    ctx->r3 = MEM_W(0XAC, ctx->r11);
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // mult        $a1, $v1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $t0, $a0
    ctx->r2 = ADD32(ctx->r8, ctx->r4);
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // bltz        $v0, L_800477C0
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_800477C0;
    }
    // nop

    // lw          $v0, 0xB4($t3)
    ctx->r2 = MEM_W(0XB4, ctx->r11);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0xB8($t3)
    ctx->r2 = MEM_W(0XB8, ctx->r11);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0xBC($t3)
    ctx->r2 = MEM_W(0XBC, ctx->r11);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bltz        $v0, L_800477C0
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_800477C0;
    }
    // nop

    // lw          $v0, 0xC4($t3)
    ctx->r2 = MEM_W(0XC4, ctx->r11);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0xC8($t3)
    ctx->r2 = MEM_W(0XC8, ctx->r11);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0xCC($t3)
    ctx->r2 = MEM_W(0XCC, ctx->r11);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $a1
    ctx->r5 = lo;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // bltz        $v0, L_800477C0
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_800477C0;
    }
    // nop

    // lw          $v0, 0x134($t3)
    ctx->r2 = MEM_W(0X134, ctx->r11);
    // nop

    // slt         $v0, $s4, $v0
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800477C0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800477C0;
    }
    // nop

    // sw          $s4, 0x134($t3)
    MEM_W(0X134, ctx->r11) = ctx->r20;
    // lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(0X0, ctx->r25);
    // lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(0X4, ctx->r25);
    // sw          $v0, 0x188($t3)
    MEM_W(0X188, ctx->r11) = ctx->r2;
    // j           L_800477C0
    // sw          $v1, 0x18C($t3)
    MEM_W(0X18C, ctx->r11) = ctx->r3;
    goto L_800477C0;
    // sw          $v1, 0x18C($t3)
    MEM_W(0X18C, ctx->r11) = ctx->r3;
L_80047798:
    // lw          $v0, 0x130($t3)
    ctx->r2 = MEM_W(0X130, ctx->r11);
    // nop

    // slt         $v0, $s4, $v0
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800477C0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800477C0;
    }
    // nop

    // sw          $s4, 0x130($t3)
    MEM_W(0X130, ctx->r11) = ctx->r20;
    // lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(0X0, ctx->r25);
    // lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(0X4, ctx->r25);
    // sw          $v0, 0x180($t3)
    MEM_W(0X180, ctx->r11) = ctx->r2;
    // sw          $v1, 0x184($t3)
    MEM_W(0X184, ctx->r11) = ctx->r3;
L_800477C0:
    // addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // bne         $v0, $zero, L_80046A20
    if (ctx->r2 != 0) {
        // addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
        goto L_80046A20;
    }
    // addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_800477D4:
    // lw          $v0, 0x4($t3)
    ctx->r2 = MEM_W(0X4, ctx->r11);
    // lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(0X4, ctx->r11);
    // lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(0X4, ctx->r2);
    // lw          $v0, 0x10($t3)
    ctx->r2 = MEM_W(0X10, ctx->r11);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r2;
    // lw          $s7, 0x8($sp)
    ctx->r23 = MEM_W(0X8, ctx->r29);
    // lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(0X4, ctx->r4);
    // addiu       $s7, $s7, -0x2
    ctx->r23 = ADD32(ctx->r23, -0X2);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // sw          $s7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r23;
    // lw          $v0, 0x14($t3)
    ctx->r2 = MEM_W(0X14, ctx->r11);
    // lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(0X4, ctx->r11);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r2;
    // lw          $s7, 0x10($sp)
    ctx->r23 = MEM_W(0X10, ctx->r29);
    // lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(0X4, ctx->r4);
    // addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // lw          $v0, 0x18($t3)
    ctx->r2 = MEM_W(0X18, ctx->r11);
    // lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(0X4, ctx->r11);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r2;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // lw          $v1, 0x1C($t3)
    ctx->r3 = MEM_W(0X1C, ctx->r11);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s7, $v0, L_8004691C
    if (ctx->r23 != ctx->r2) {
        // sw          $v1, 0x1C($t3)
        MEM_W(0X1C, ctx->r11) = ctx->r3;
        goto L_8004691C;
    }
    // sw          $v1, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r3;
L_80047854:
    // lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(0X38, ctx->r29);
    // lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
