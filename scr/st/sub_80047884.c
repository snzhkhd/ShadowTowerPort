#include "recomp.h"
#include "disable_warnings.h"

void sub_80047884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v1, $v0, 0x5948
    ctx->r3 = ADD32(ctx->r2, 0X5948);
    // lui         $t8, 0x1F80
    ctx->r24 = S32(0X1F80 << 16);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addu        $s2, $sp, $zero
    ctx->r18 = ADD32(ctx->r29, 0);
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
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lhu         $t3, 0x44CA($v1)
    ctx->r11 = MEM_HU(0X44CA, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // beq         $t3, $v0, L_80048AA0
    if (ctx->r11 == ctx->r2) {
        // sw          $t3, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r11;
        goto L_80048AA0;
    }
    // sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // addu        $s6, $v1, $zero
    ctx->r22 = ADD32(ctx->r3, 0);
    // sll         $v0, $t3, 1
    ctx->r2 = S32(ctx->r11) << 1;
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
L_800478E0:
    // lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(0X14, ctx->r29);
    // nop

    // lhu         $v0, 0x44CE($t3)
    ctx->r2 = MEM_HU(0X44CE, ctx->r11);
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
    // lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(0X0, ctx->r24);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r3;
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(0X0, ctx->r24);
    // lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(0X4, ctx->r24);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // sw          $v0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r2;
    // lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(0X8, ctx->r4);
    // lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(0X0, ctx->r24);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r2;
    // lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(0X10, ctx->r5);
    // lhu         $fp, 0x24($a1)
    ctx->r30 = MEM_HU(0X24, ctx->r5);
    // lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(0X0, ctx->r24);
    // lhu         $a0, 0x18($a1)
    ctx->r4 = MEM_HU(0X18, ctx->r5);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // lhu         $v1, 0x1C($a1)
    ctx->r3 = MEM_HU(0X1C, ctx->r5);
    // lhu         $a0, 0x20($a1)
    ctx->r4 = MEM_HU(0X20, ctx->r5);
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lhu         $v1, 0x1A($a1)
    ctx->r3 = MEM_HU(0X1A, ctx->r5);
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // lhu         $v1, 0x1E($a1)
    ctx->r3 = MEM_HU(0X1E, ctx->r5);
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // addu        $s1, $s1, $v1
    ctx->r17 = ADD32(ctx->r17, ctx->r3);
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lbu         $v1, 0x3($a2)
    ctx->r3 = MEM_BU(0X3, ctx->r6);
    // addiu       $v0, $v0, 0x42C
    ctx->r2 = ADD32(ctx->r2, 0X42C);
    // andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) << 5;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // beq         $a0, $zero, L_80048A20
    if (ctx->r4 == 0) {
        // sw          $v1, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r3;
        goto L_80048A20;
    }
    // sw          $v1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r3;
    // lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(0X14, ctx->r29);
    // addiu       $t9, $s1, 0x2
    ctx->r25 = ADD32(ctx->r17, 0X2);
    // sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
L_80047A00:
    // lhu         $v1, 0x2($t9)
    ctx->r3 = MEM_HU(0X2, ctx->r25);
    // lw          $v0, 0x8($t8)
    ctx->r2 = MEM_W(0X8, ctx->r24);
    // lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(0XC, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(0X0, ctx->r11);
    // lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(0X4, ctx->r11);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(0X8, ctx->r11);
    // lw          $t5, 0xC($t3)
    ctx->r13 = MEM_W(0XC, ctx->r11);
    // lw          $t6, 0x10($t3)
    ctx->r14 = MEM_W(0X10, ctx->r11);
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
    // sh          $t4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r12;
    // sh          $t5, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r13;
    // sh          $t6, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r14;
    // lhu         $v0, 0x148($t8)
    ctx->r2 = MEM_HU(0X148, ctx->r24);
    // lh          $v1, 0x0($s2)
    ctx->r3 = MEM_HS(0X0, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v1, 0x2($s2)
    ctx->r3 = MEM_HU(0X2, ctx->r18);
    // lhu         $v0, 0x14A($t8)
    ctx->r2 = MEM_HU(0X14A, ctx->r24);
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
    // lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(0X4, ctx->r18);
    // lhu         $v0, 0x14C($t8)
    ctx->r2 = MEM_HU(0X14C, ctx->r24);
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
    // blez        $v0, L_80047AE0
    if (SIGNED(ctx->r2) <= 0) {
        // lui         $v1, 0x5
        ctx->r3 = S32(0X5 << 16);
        goto L_80047AE0;
    }
    // lui         $v1, 0x5
    ctx->r3 = S32(0X5 << 16);
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_80048A0C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048A0C;
    }
    // nop

L_80047AE0:
    // lhu         $v0, 0x4($t9)
    ctx->r2 = MEM_HU(0X4, ctx->r25);
    // lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(0X10, ctx->r24);
    // lh          $t1, 0x0($s2)
    ctx->r9 = MEM_HS(0X0, ctx->r18);
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
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // mflo        $t2
    ctx->r10 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2) >> 16;
    // mult        $t0, $v1
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(0X4, ctx->r18);
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
    // lw          $v0, 0xE4($t8)
    ctx->r2 = MEM_W(0XE4, ctx->r24);
    // nop

    // mult        $t1, $v0
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // lw          $v0, 0xE8($t8)
    ctx->r2 = MEM_W(0XE8, ctx->r24);
    // nop

    // mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0xEC($t8)
    ctx->r2 = MEM_W(0XEC, ctx->r24);
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
    // mflo        $t7
    ctx->r15 = lo;
    // addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // bgez        $v1, L_80047B8C
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80047B8C;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80047B8C:
    // lw          $v0, 0xF4($t8)
    ctx->r2 = MEM_W(0XF4, ctx->r24);
    // nop

    // mult        $t1, $v0
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // lw          $v0, 0xF8($t8)
    ctx->r2 = MEM_W(0XF8, ctx->r24);
    // nop

    // mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0xFC($t8)
    ctx->r2 = MEM_W(0XFC, ctx->r24);
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
    // bgez        $a0, L_80047BD4
    if (SIGNED(ctx->r4) >= 0) {
        // sra         $s3, $v1, 12
        ctx->r19 = S32(ctx->r3) >> 12;
        goto L_80047BD4;
    }
    // sra         $s3, $v1, 12
    ctx->r19 = S32(ctx->r3) >> 12;
    // addiu       $a0, $a0, 0xFFF
    ctx->r4 = ADD32(ctx->r4, 0XFFF);
L_80047BD4:
    // lw          $v0, 0x104($t8)
    ctx->r2 = MEM_W(0X104, ctx->r24);
    // nop

    // mult        $t1, $v0
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // lw          $v0, 0x108($t8)
    ctx->r2 = MEM_W(0X108, ctx->r24);
    // nop

    // mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x10C($t8)
    ctx->r2 = MEM_W(0X10C, ctx->r24);
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
    // bgez        $v0, L_80047C1C
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $s4, $a0, 12
        ctx->r20 = S32(ctx->r4) >> 12;
        goto L_80047C1C;
    }
    // sra         $s4, $a0, 12
    ctx->r20 = S32(ctx->r4) >> 12;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80047C1C:
    // sra         $s7, $v0, 12
    ctx->r23 = S32(ctx->r2) >> 12;
    // slti        $v0, $s3, -0x100
    ctx->r2 = SIGNED(ctx->r19) < -0X100 ? 1 : 0;
    // bne         $v0, $zero, L_80048A0C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80048A0C;
    }
    // nop

    // lw          $v1, 0x14($t8)
    ctx->r3 = MEM_W(0X14, ctx->r24);
    // lhu         $a2, 0x6($t9)
    ctx->r6 = MEM_HU(0X6, ctx->r25);
    // lhu         $a3, 0x8($t9)
    ctx->r7 = MEM_HU(0X8, ctx->r25);
    // lhu         $v0, 0xA($t9)
    ctx->r2 = MEM_HU(0XA, ctx->r25);
    // lw          $a0, 0x18($t8)
    ctx->r4 = MEM_W(0X18, ctx->r24);
    // lw          $a1, 0x1C($t8)
    ctx->r5 = MEM_W(0X1C, ctx->r24);
    // addu        $s5, $v1, $t4
    ctx->r21 = ADD32(ctx->r3, ctx->r12);
    // sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6) << 1;
    // addu        $t0, $v1, $a2
    ctx->r8 = ADD32(ctx->r3, ctx->r6);
    // sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7) << 1;
    // addu        $t1, $v1, $a3
    ctx->r9 = ADD32(ctx->r3, ctx->r7);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addu        $t7, $a0, $t4
    ctx->r15 = ADD32(ctx->r4, ctx->r12);
    // addu        $t2, $a0, $a2
    ctx->r10 = ADD32(ctx->r4, ctx->r6);
    // addu        $t3, $a0, $a3
    ctx->r11 = ADD32(ctx->r4, ctx->r7);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $s0, $a1, $t4
    ctx->r16 = ADD32(ctx->r5, ctx->r12);
    // addu        $a2, $a1, $a2
    ctx->r6 = ADD32(ctx->r5, ctx->r6);
    // addu        $a3, $a1, $a3
    ctx->r7 = ADD32(ctx->r5, ctx->r7);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(0X0, ctx->r21);
    // lw          $t5, 0x4($s5)
    ctx->r13 = MEM_W(0X4, ctx->r21);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // lw          $t6, 0x8($s5)
    ctx->r14 = MEM_W(0X8, ctx->r21);
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
    // addiu       $v0, $t8, 0x24
    ctx->r2 = ADD32(ctx->r24, 0X24);
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
    // addiu       $v0, $t8, 0x34
    ctx->r2 = ADD32(ctx->r24, 0X34);
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
    // addiu       $v0, $t8, 0x44
    ctx->r2 = ADD32(ctx->r24, 0X44);
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
    // lwc2        $11, 0x8($s5)
    gte_lwc2(rdram, ctx, 11, 21, 8);
    // lwc2        $9, 0x0($s5)
    gte_lwc2(rdram, ctx, 9, 21, 0);
    // lwc2        $10, 0x4($s5)
    gte_lwc2(rdram, ctx, 10, 21, 4);
    // nop

    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // addiu       $v0, $t8, 0x54
    ctx->r2 = ADD32(ctx->r24, 0X54);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(0X0, ctx->r15);
    // lw          $t5, 0x4($t7)
    ctx->r13 = MEM_W(0X4, ctx->r15);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // lw          $t6, 0x8($t7)
    ctx->r14 = MEM_W(0X8, ctx->r15);
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
    // addiu       $v0, $t8, 0x64
    ctx->r2 = ADD32(ctx->r24, 0X64);
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
    // addiu       $v0, $t8, 0x74
    ctx->r2 = ADD32(ctx->r24, 0X74);
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
    // lwc2        $11, 0x8($t3)
    gte_lwc2(rdram, ctx, 11, 11, 8);
    // lwc2        $9, 0x0($t3)
    gte_lwc2(rdram, ctx, 9, 11, 0);
    // lwc2        $10, 0x4($t3)
    gte_lwc2(rdram, ctx, 10, 11, 4);
    // nop

    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // addiu       $v0, $t8, 0x84
    ctx->r2 = ADD32(ctx->r24, 0X84);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(0X0, ctx->r11);
    // lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(0X4, ctx->r11);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // lw          $t6, 0x8($t3)
    ctx->r14 = MEM_W(0X8, ctx->r11);
    // ctc2        $t5, $2
    gte_ctc2(ctx, 13, 2);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lwc2        $11, 0x8($t7)
    gte_lwc2(rdram, ctx, 11, 15, 8);
    // lwc2        $9, 0x0($t7)
    gte_lwc2(rdram, ctx, 9, 15, 0);
    // lwc2        $10, 0x4($t7)
    gte_lwc2(rdram, ctx, 10, 15, 4);
    // nop

    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // addiu       $v0, $t8, 0x94
    ctx->r2 = ADD32(ctx->r24, 0X94);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(0X0, ctx->r16);
    // lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(0X4, ctx->r16);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(0X8, ctx->r16);
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
    // addiu       $v0, $t8, 0xA4
    ctx->r2 = ADD32(ctx->r24, 0XA4);
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
    // addiu       $v0, $t8, 0xB4
    ctx->r2 = ADD32(ctx->r24, 0XB4);
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
    // addiu       $v0, $t8, 0xC4
    ctx->r2 = ADD32(ctx->r24, 0XC4);
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
    // lwc2        $11, 0x8($s0)
    gte_lwc2(rdram, ctx, 11, 16, 8);
    // lwc2        $9, 0x0($s0)
    gte_lwc2(rdram, ctx, 9, 16, 0);
    // lwc2        $10, 0x4($s0)
    gte_lwc2(rdram, ctx, 10, 16, 4);
    // nop

    // nop

    // .word       0x4B78000C                   # INVALID     $k1, $t8, 0xC # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B78000C);
    // addiu       $v0, $t8, 0xD4
    ctx->r2 = ADD32(ctx->r24, 0XD4);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(0X0, ctx->r25);
    // nop

    // andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // beq         $v0, $zero, L_800480A0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800480A0;
    }
    // nop

    // lw          $v0, 0x28($t8)
    ctx->r2 = MEM_W(0X28, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // bltz        $v0, L_80048020
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_80048020;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $v0, 0x38($t8)
    ctx->r2 = MEM_W(0X38, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // bltz        $v0, L_80048020
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_80048020;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $v0, 0x48($t8)
    ctx->r2 = MEM_W(0X48, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // bltz        $v0, L_80048020
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_80048020;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $v0, 0x58($t8)
    ctx->r2 = MEM_W(0X58, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // bltz        $v0, L_80048020
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_80048020;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $v0, 0x120($t8)
    ctx->r2 = MEM_W(0X120, ctx->r24);
    // nop

    // slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80048020
    if (ctx->r2 == 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_80048020;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // sw          $s3, 0x120($t8)
    MEM_W(0X120, ctx->r24) = ctx->r19;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sw          $v0, 0x150($t8)
    MEM_W(0X150, ctx->r24) = ctx->r2;
    // sw          $v1, 0x154($t8)
    MEM_W(0X154, ctx->r24) = ctx->r3;
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
L_80048020:
    // bne         $v0, $zero, L_80048A0C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80048A0C;
    }
    // nop

    // lw          $v0, 0x68($t8)
    ctx->r2 = MEM_W(0X68, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // bltz        $v0, L_800480A0
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_800480A0;
    }
    // nop

    // lw          $v0, 0x78($t8)
    ctx->r2 = MEM_W(0X78, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // bltz        $v0, L_800480A0
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_800480A0;
    }
    // nop

    // lw          $v0, 0x88($t8)
    ctx->r2 = MEM_W(0X88, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // bltz        $v0, L_800480A0
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_800480A0;
    }
    // nop

    // lw          $v0, 0x98($t8)
    ctx->r2 = MEM_W(0X98, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // bltz        $v0, L_800480A0
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_800480A0;
    }
    // nop

    // lw          $v0, 0x124($t8)
    ctx->r2 = MEM_W(0X124, ctx->r24);
    // nop

    // slt         $v0, $s4, $v0
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800480A0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800480A0;
    }
    // nop

    // sw          $s4, 0x124($t8)
    MEM_W(0X124, ctx->r24) = ctx->r20;
L_800480A0:
    // lhu         $v1, 0x0($t9)
    ctx->r3 = MEM_HU(0X0, ctx->r25);
    // nop

    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // beq         $v0, $zero, L_80048438
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048438;
    }
    // nop

    // lw          $v0, 0x28($t8)
    ctx->r2 = MEM_W(0X28, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_800483A4
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_800483A4;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $v0, 0x38($t8)
    ctx->r2 = MEM_W(0X38, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_800483A4
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_800483A4;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $v0, 0x48($t8)
    ctx->r2 = MEM_W(0X48, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_800483A4
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_800483A4;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $v0, 0x58($t8)
    ctx->r2 = MEM_W(0X58, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_800483A4
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_800483A4;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $v0, 0x114($t8)
    ctx->r2 = MEM_W(0X114, ctx->r24);
    // nop

    // slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800483A0
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x800
        ctx->r2 = ctx->r3 & 0X800;
        goto L_800483A0;
    }
    // andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // beq         $v0, $zero, L_80048158
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048158;
    }
    // nop

    // lw          $v0, 0x47E0($s6)
    ctx->r2 = MEM_W(0X47E0, ctx->r22);
    // nop

    // srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_80048158
    if (ctx->r2 != 0) {
        // addiu       $v1, $zero, -0x11
        ctx->r3 = ADD32(0, -0X11);
        goto L_80048158;
    }
    // addiu       $v1, $zero, -0x11
    ctx->r3 = ADD32(0, -0X11);
    // lw          $v0, 0x198($t8)
    ctx->r2 = MEM_W(0X198, ctx->r24);
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
    // sw          $v0, 0x198($t8)
    MEM_W(0X198, ctx->r24) = ctx->r2;
L_80048158:
    // lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(0X0, ctx->r25);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_80048184
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048184;
    }
    // nop

    // lw          $v0, 0x47E0($s6)
    ctx->r2 = MEM_W(0X47E0, ctx->r22);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_80048184
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80048184;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, 0x198($t8)
    MEM_W(0X198, ctx->r24) = ctx->r2;
L_80048184:
    // lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(0X0, ctx->r25);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_800481B4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800481B4;
    }
    // nop

    // lw          $v0, 0x47E0($s6)
    ctx->r2 = MEM_W(0X47E0, ctx->r22);
    // nop

    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_800481B4
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_800481B4;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sw          $v0, 0x198($t8)
    MEM_W(0X198, ctx->r24) = ctx->r2;
L_800481B4:
    // lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(0X0, ctx->r25);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_80048200
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048200;
    }
    // nop

    // lw          $v0, 0x47E0($s6)
    ctx->r2 = MEM_W(0X47E0, ctx->r22);
    // nop

    // srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_80048200
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80048200;
    }
    // nop

    // lw          $v0, 0x198($t8)
    ctx->r2 = MEM_W(0X198, ctx->r24);
    // lw          $v1, 0xE8($t8)
    ctx->r3 = MEM_W(0XE8, ctx->r24);
    // ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // sw          $v0, 0x198($t8)
    MEM_W(0X198, ctx->r24) = ctx->r2;
    // lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(0X4, ctx->r21);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x138($t8)
    MEM_W(0X138, ctx->r24) = ctx->r2;
L_80048200:
    // lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(0X0, ctx->r25);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_80048230
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048230;
    }
    // nop

    // lw          $v0, 0x47E0($s6)
    ctx->r2 = MEM_W(0X47E0, ctx->r22);
    // nop

    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_80048230
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_80048230;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // sw          $v0, 0x198($t8)
    MEM_W(0X198, ctx->r24) = ctx->r2;
L_80048230:
    // lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(0X0, ctx->r25);
    // nop

    // andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // beq         $v0, $zero, L_80048260
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048260;
    }
    // nop

    // lw          $v0, 0x47E0($s6)
    ctx->r2 = MEM_W(0X47E0, ctx->r22);
    // nop

    // srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_80048260
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
        goto L_80048260;
    }
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x198($t8)
    MEM_W(0X198, ctx->r24) = ctx->r2;
L_80048260:
    // lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(0X0, ctx->r25);
    // nop

    // andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // beq         $v0, $zero, L_800482AC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800482AC;
    }
    // nop

    // lw          $v0, 0x47E0($s6)
    ctx->r2 = MEM_W(0X47E0, ctx->r22);
    // nop

    // srl         $v0, $v0, 5
    ctx->r2 = S32(U32(ctx->r2) >> 5);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_800482AC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800482AC;
    }
    // nop

    // lw          $v0, 0x198($t8)
    ctx->r2 = MEM_W(0X198, ctx->r24);
    // lw          $v1, 0xE8($t8)
    ctx->r3 = MEM_W(0XE8, ctx->r24);
    // ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // sw          $v0, 0x198($t8)
    MEM_W(0X198, ctx->r24) = ctx->r2;
    // lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(0X4, ctx->r21);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x144($t8)
    MEM_W(0X144, ctx->r24) = ctx->r2;
L_800482AC:
    // lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(0X0, ctx->r25);
    // nop

    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // bne         $v0, $zero, L_80048A0C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80048A0C;
    }
    // nop

    // lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(0X10, ctx->r29);
    // nop

    // lhu         $v0, 0x44CE($t3)
    ctx->r2 = MEM_HU(0X44CE, ctx->r11);
    // sw          $s3, 0x114($t8)
    MEM_W(0X114, ctx->r24) = ctx->r19;
    // sh          $v0, 0x22($t8)
    MEM_H(0X22, ctx->r24) = ctx->r2;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sw          $v0, 0x158($t8)
    MEM_W(0X158, ctx->r24) = ctx->r2;
    // sw          $v1, 0x15C($t8)
    MEM_W(0X15C, ctx->r24) = ctx->r3;
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // sh          $zero, 0x192($t8)
    MEM_H(0X192, ctx->r24) = 0;
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // sh          $v0, 0x190($t8)
    MEM_H(0X190, ctx->r24) = ctx->r2;
    // lbu         $v0, -0x1($t9)
    ctx->r2 = MEM_BU(-0X1, ctx->r25);
    // nop

    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // sh          $v0, 0x194($t8)
    MEM_H(0X194, ctx->r24) = ctx->r2;
    // lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(0XC, ctx->r29);
    // nop

    // lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(0X0, ctx->r11);
    // lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(0X4, ctx->r11);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(0X8, ctx->r11);
    // lw          $t5, 0xC($t3)
    ctx->r13 = MEM_W(0XC, ctx->r11);
    // lw          $t6, 0x10($t3)
    ctx->r14 = MEM_W(0X10, ctx->r11);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // addiu       $v0, $t8, 0x190
    ctx->r2 = ADD32(ctx->r24, 0X190);
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
    // lhu         $v0, 0x47CE($s6)
    ctx->r2 = MEM_HU(0X47CE, ctx->r22);
    // lhu         $v1, 0x190($t8)
    ctx->r3 = MEM_HU(0X190, ctx->r24);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x47CE($s6)
    MEM_H(0X47CE, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x47D0($s6)
    ctx->r2 = MEM_HU(0X47D0, ctx->r22);
    // lhu         $a0, 0x192($t8)
    ctx->r4 = MEM_HU(0X192, ctx->r24);
    // lhu         $v1, 0x47D2($s6)
    ctx->r3 = MEM_HU(0X47D2, ctx->r22);
    // lhu         $a1, 0x194($t8)
    ctx->r5 = MEM_HU(0X194, ctx->r24);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sh          $v0, 0x47D0($s6)
    MEM_H(0X47D0, ctx->r22) = ctx->r2;
    // sh          $v1, 0x47D2($s6)
    MEM_H(0X47D2, ctx->r22) = ctx->r3;
L_800483A0:
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
L_800483A4:
    // bne         $v0, $zero, L_80048A0C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80048A0C;
    }
    // nop

    // lw          $v0, 0x68($t8)
    ctx->r2 = MEM_W(0X68, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_80048438
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_80048438;
    }
    // nop

    // lw          $v0, 0x78($t8)
    ctx->r2 = MEM_W(0X78, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_80048438
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_80048438;
    }
    // nop

    // lw          $v0, 0x88($t8)
    ctx->r2 = MEM_W(0X88, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_80048438
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_80048438;
    }
    // nop

    // lw          $v0, 0x98($t8)
    ctx->r2 = MEM_W(0X98, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_80048438
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_80048438;
    }
    // nop

    // lw          $v0, 0x118($t8)
    ctx->r2 = MEM_W(0X118, ctx->r24);
    // nop

    // slt         $v0, $s4, $v0
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80048438
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048438;
    }
    // nop

    // sw          $s4, 0x118($t8)
    MEM_W(0X118, ctx->r24) = ctx->r20;
    // lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(0X10, ctx->r29);
    // nop

    // lhu         $v0, 0x44CE($t3)
    ctx->r2 = MEM_HU(0X44CE, ctx->r11);
    // nop

    // sw          $v0, 0x47D8($s6)
    MEM_W(0X47D8, ctx->r22) = ctx->r2;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sw          $v0, 0x160($t8)
    MEM_W(0X160, ctx->r24) = ctx->r2;
    // sw          $v1, 0x164($t8)
    MEM_W(0X164, ctx->r24) = ctx->r3;
L_80048438:
    // lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(0X0, ctx->r25);
    // nop

    // andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // beq         $v0, $zero, L_80048A0C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048A0C;
    }
    // nop

    // lh          $a3, 0x0($s2)
    ctx->r7 = MEM_HS(0X0, ctx->r18);
    // lw          $v0, 0x24($t8)
    ctx->r2 = MEM_W(0X24, ctx->r24);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x28($t8)
    ctx->r3 = MEM_W(0X28, ctx->r24);
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // mflo        $t0
    ctx->r8 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
    // mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(0X4, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(0X2C, ctx->r24);
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
    // bgtz        $v0, L_80048564
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_80048564;
    }
    // nop

    // lw          $v0, 0x34($t8)
    ctx->r2 = MEM_W(0X34, ctx->r24);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0x38($t8)
    ctx->r2 = MEM_W(0X38, ctx->r24);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x3C($t8)
    ctx->r2 = MEM_W(0X3C, ctx->r24);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bgtz        $v0, L_80048564
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_80048564;
    }
    // nop

    // lw          $v0, 0x44($t8)
    ctx->r2 = MEM_W(0X44, ctx->r24);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0x48($t8)
    ctx->r2 = MEM_W(0X48, ctx->r24);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x4C($t8)
    ctx->r2 = MEM_W(0X4C, ctx->r24);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bgtz        $v0, L_80048564
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_80048564;
    }
    // nop

    // lw          $v0, 0x54($t8)
    ctx->r2 = MEM_W(0X54, ctx->r24);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0x58($t8)
    ctx->r2 = MEM_W(0X58, ctx->r24);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x5C($t8)
    ctx->r2 = MEM_W(0X5C, ctx->r24);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $a1
    ctx->r5 = lo;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // blez        $v0, L_800486AC
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_800486AC;
    }
    // nop

L_80048564:
    // lhu         $v0, 0x148($t8)
    ctx->r2 = MEM_HU(0X148, ctx->r24);
    // lw          $v1, 0x24($t8)
    ctx->r3 = MEM_W(0X24, ctx->r24);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // mult        $a3, $v1
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x14A($t8)
    ctx->r2 = MEM_HU(0X14A, ctx->r24);
    // lw          $v1, 0x28($t8)
    ctx->r3 = MEM_W(0X28, ctx->r24);
    // mflo        $t0
    ctx->r8 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
    // mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x14C($t8)
    ctx->r2 = MEM_HU(0X14C, ctx->r24);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v1, 0x2C($t8)
    ctx->r3 = MEM_W(0X2C, ctx->r24);
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
    // bltz        $v0, L_800486E8
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_800486E8;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $v0, 0x34($t8)
    ctx->r2 = MEM_W(0X34, ctx->r24);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0x38($t8)
    ctx->r2 = MEM_W(0X38, ctx->r24);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x3C($t8)
    ctx->r2 = MEM_W(0X3C, ctx->r24);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bltz        $v0, L_800486E8
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_800486E8;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $v0, 0x44($t8)
    ctx->r2 = MEM_W(0X44, ctx->r24);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0x48($t8)
    ctx->r2 = MEM_W(0X48, ctx->r24);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x4C($t8)
    ctx->r2 = MEM_W(0X4C, ctx->r24);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bltz        $v0, L_800486E8
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_800486E8;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $v0, 0x54($t8)
    ctx->r2 = MEM_W(0X54, ctx->r24);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0x58($t8)
    ctx->r2 = MEM_W(0X58, ctx->r24);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x5C($t8)
    ctx->r2 = MEM_W(0X5C, ctx->r24);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $a1
    ctx->r5 = lo;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // bltz        $v0, L_800486E8
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_800486E8;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $v0, 0x12C($t8)
    ctx->r2 = MEM_W(0X12C, ctx->r24);
    // nop

    // slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800486E8
    if (ctx->r2 == 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_800486E8;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // sw          $s3, 0x12C($t8)
    MEM_W(0X12C, ctx->r24) = ctx->r19;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sw          $v0, 0x178($t8)
    MEM_W(0X178, ctx->r24) = ctx->r2;
    // j           L_800486E4
    // sw          $v1, 0x17C($t8)
    MEM_W(0X17C, ctx->r24) = ctx->r3;
    goto L_800486E4;
    // sw          $v1, 0x17C($t8)
    MEM_W(0X17C, ctx->r24) = ctx->r3;
L_800486AC:
    // lw          $v0, 0x128($t8)
    ctx->r2 = MEM_W(0X128, ctx->r24);
    // nop

    // slt         $v0, $s3, $v0
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_800486E8
    if (ctx->r2 == 0) {
        // slti        $v0, $s4, -0x100
        ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
        goto L_800486E8;
    }
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
    // lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(0X10, ctx->r29);
    // nop

    // lhu         $v0, 0x44CE($t3)
    ctx->r2 = MEM_HU(0X44CE, ctx->r11);
    // sw          $s3, 0x128($t8)
    MEM_W(0X128, ctx->r24) = ctx->r19;
    // sh          $v0, 0x22($t8)
    MEM_H(0X22, ctx->r24) = ctx->r2;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sw          $v0, 0x170($t8)
    MEM_W(0X170, ctx->r24) = ctx->r2;
    // sw          $v1, 0x174($t8)
    MEM_W(0X174, ctx->r24) = ctx->r3;
L_800486E4:
    // slti        $v0, $s4, -0x100
    ctx->r2 = SIGNED(ctx->r20) < -0X100 ? 1 : 0;
L_800486E8:
    // bne         $v0, $zero, L_80048A0C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80048A0C;
    }
    // nop

    // lw          $v0, 0x68($t8)
    ctx->r2 = MEM_W(0X68, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_8004877C
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s7, -0x100
        ctx->r2 = SIGNED(ctx->r23) < -0X100 ? 1 : 0;
        goto L_8004877C;
    }
    // slti        $v0, $s7, -0x100
    ctx->r2 = SIGNED(ctx->r23) < -0X100 ? 1 : 0;
    // lw          $v0, 0x78($t8)
    ctx->r2 = MEM_W(0X78, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_8004877C
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s7, -0x100
        ctx->r2 = SIGNED(ctx->r23) < -0X100 ? 1 : 0;
        goto L_8004877C;
    }
    // slti        $v0, $s7, -0x100
    ctx->r2 = SIGNED(ctx->r23) < -0X100 ? 1 : 0;
    // lw          $v0, 0x88($t8)
    ctx->r2 = MEM_W(0X88, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_8004877C
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s7, -0x100
        ctx->r2 = SIGNED(ctx->r23) < -0X100 ? 1 : 0;
        goto L_8004877C;
    }
    // slti        $v0, $s7, -0x100
    ctx->r2 = SIGNED(ctx->r23) < -0X100 ? 1 : 0;
    // lw          $v0, 0x98($t8)
    ctx->r2 = MEM_W(0X98, ctx->r24);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // bltz        $v0, L_8004877C
    if (SIGNED(ctx->r2) < 0) {
        // slti        $v0, $s7, -0x100
        ctx->r2 = SIGNED(ctx->r23) < -0X100 ? 1 : 0;
        goto L_8004877C;
    }
    // slti        $v0, $s7, -0x100
    ctx->r2 = SIGNED(ctx->r23) < -0X100 ? 1 : 0;
    // lw          $v0, 0x11C($t8)
    ctx->r2 = MEM_W(0X11C, ctx->r24);
    // nop

    // slt         $v0, $s4, $v0
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8004877C
    if (ctx->r2 == 0) {
        // slti        $v0, $s7, -0x100
        ctx->r2 = SIGNED(ctx->r23) < -0X100 ? 1 : 0;
        goto L_8004877C;
    }
    // slti        $v0, $s7, -0x100
    ctx->r2 = SIGNED(ctx->r23) < -0X100 ? 1 : 0;
    // lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(0X10, ctx->r29);
    // nop

    // lhu         $v0, 0x44CE($t3)
    ctx->r2 = MEM_HU(0X44CE, ctx->r11);
    // sw          $s4, 0x11C($t8)
    MEM_W(0X11C, ctx->r24) = ctx->r20;
    // sh          $v0, 0x22($t8)
    MEM_H(0X22, ctx->r24) = ctx->r2;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sw          $v0, 0x168($t8)
    MEM_W(0X168, ctx->r24) = ctx->r2;
    // sw          $v1, 0x16C($t8)
    MEM_W(0X16C, ctx->r24) = ctx->r3;
    // slti        $v0, $s7, -0x100
    ctx->r2 = SIGNED(ctx->r23) < -0X100 ? 1 : 0;
L_8004877C:
    // bne         $v0, $zero, L_80048A0C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80048A0C;
    }
    // nop

    // lh          $a3, 0x0($s2)
    ctx->r7 = MEM_HS(0X0, ctx->r18);
    // lw          $v0, 0xA4($t8)
    ctx->r2 = MEM_W(0XA4, ctx->r24);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0xA8($t8)
    ctx->r3 = MEM_W(0XA8, ctx->r24);
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // mflo        $t0
    ctx->r8 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
    // mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(0X4, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v1, 0xAC($t8)
    ctx->r3 = MEM_W(0XAC, ctx->r24);
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
    // bgtz        $v0, L_8004889C
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8004889C;
    }
    // nop

    // lw          $v0, 0xB4($t8)
    ctx->r2 = MEM_W(0XB4, ctx->r24);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0xB8($t8)
    ctx->r2 = MEM_W(0XB8, ctx->r24);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0xBC($t8)
    ctx->r2 = MEM_W(0XBC, ctx->r24);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bgtz        $v0, L_8004889C
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8004889C;
    }
    // nop

    // lw          $v0, 0xC4($t8)
    ctx->r2 = MEM_W(0XC4, ctx->r24);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0xC8($t8)
    ctx->r2 = MEM_W(0XC8, ctx->r24);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0xCC($t8)
    ctx->r2 = MEM_W(0XCC, ctx->r24);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bgtz        $v0, L_8004889C
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8004889C;
    }
    // nop

    // lw          $v0, 0xD4($t8)
    ctx->r2 = MEM_W(0XD4, ctx->r24);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0xD8($t8)
    ctx->r2 = MEM_W(0XD8, ctx->r24);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0xDC($t8)
    ctx->r2 = MEM_W(0XDC, ctx->r24);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $a1
    ctx->r5 = lo;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // blez        $v0, L_800489E4
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_800489E4;
    }
    // nop

L_8004889C:
    // lhu         $v0, 0x148($t8)
    ctx->r2 = MEM_HU(0X148, ctx->r24);
    // lw          $v1, 0xA4($t8)
    ctx->r3 = MEM_W(0XA4, ctx->r24);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // mult        $a3, $v1
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x14A($t8)
    ctx->r2 = MEM_HU(0X14A, ctx->r24);
    // lw          $v1, 0xA8($t8)
    ctx->r3 = MEM_W(0XA8, ctx->r24);
    // mflo        $t0
    ctx->r8 = lo;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) >> 16;
    // mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x14C($t8)
    ctx->r2 = MEM_HU(0X14C, ctx->r24);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v1, 0xAC($t8)
    ctx->r3 = MEM_W(0XAC, ctx->r24);
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
    // bltz        $v0, L_80048A0C
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_80048A0C;
    }
    // nop

    // lw          $v0, 0xB4($t8)
    ctx->r2 = MEM_W(0XB4, ctx->r24);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0xB8($t8)
    ctx->r2 = MEM_W(0XB8, ctx->r24);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0xBC($t8)
    ctx->r2 = MEM_W(0XBC, ctx->r24);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bltz        $v0, L_80048A0C
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_80048A0C;
    }
    // nop

    // lw          $v0, 0xC4($t8)
    ctx->r2 = MEM_W(0XC4, ctx->r24);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0xC8($t8)
    ctx->r2 = MEM_W(0XC8, ctx->r24);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0xCC($t8)
    ctx->r2 = MEM_W(0XCC, ctx->r24);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // bltz        $v0, L_80048A0C
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_80048A0C;
    }
    // nop

    // lw          $v0, 0xD4($t8)
    ctx->r2 = MEM_W(0XD4, ctx->r24);
    // nop

    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lw          $v0, 0xD8($t8)
    ctx->r2 = MEM_W(0XD8, ctx->r24);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0xDC($t8)
    ctx->r2 = MEM_W(0XDC, ctx->r24);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // mflo        $a1
    ctx->r5 = lo;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // bltz        $v0, L_80048A0C
    if (SIGNED(ctx->r2) < 0) {
        // nop
    
        goto L_80048A0C;
    }
    // nop

    // lw          $v0, 0x134($t8)
    ctx->r2 = MEM_W(0X134, ctx->r24);
    // nop

    // slt         $v0, $s7, $v0
    ctx->r2 = SIGNED(ctx->r23) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80048A0C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048A0C;
    }
    // nop

    // sw          $s7, 0x134($t8)
    MEM_W(0X134, ctx->r24) = ctx->r23;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sw          $v0, 0x188($t8)
    MEM_W(0X188, ctx->r24) = ctx->r2;
    // j           L_80048A0C
    // sw          $v1, 0x18C($t8)
    MEM_W(0X18C, ctx->r24) = ctx->r3;
    goto L_80048A0C;
    // sw          $v1, 0x18C($t8)
    MEM_W(0X18C, ctx->r24) = ctx->r3;
L_800489E4:
    // lw          $v0, 0x130($t8)
    ctx->r2 = MEM_W(0X130, ctx->r24);
    // nop

    // slt         $v0, $s7, $v0
    ctx->r2 = SIGNED(ctx->r23) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80048A0C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80048A0C;
    }
    // nop

    // sw          $s7, 0x130($t8)
    MEM_W(0X130, ctx->r24) = ctx->r23;
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sw          $v0, 0x180($t8)
    MEM_W(0X180, ctx->r24) = ctx->r2;
    // sw          $v1, 0x184($t8)
    MEM_W(0X184, ctx->r24) = ctx->r3;
L_80048A0C:
    // addiu       $t9, $t9, 0x10
    ctx->r25 = ADD32(ctx->r25, 0X10);
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // addu        $v0, $fp, $zero
    ctx->r2 = ADD32(ctx->r30, 0);
    // bne         $v0, $zero, L_80047A00
    if (ctx->r2 != 0) {
        // addiu       $fp, $fp, -0x1
        ctx->r30 = ADD32(ctx->r30, -0X1);
        goto L_80047A00;
    }
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
L_80048A20:
    // lw          $v0, 0x4($t8)
    ctx->r2 = MEM_W(0X4, ctx->r24);
    // lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(0X4, ctx->r24);
    // lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(0X4, ctx->r2);
    // lw          $v0, 0x10($t8)
    ctx->r2 = MEM_W(0X10, ctx->r24);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r2;
    // lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(0X14, ctx->r29);
    // lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(0X4, ctx->r4);
    // addiu       $t3, $t3, -0x2
    ctx->r11 = ADD32(ctx->r11, -0X2);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // lw          $v0, 0x14($t8)
    ctx->r2 = MEM_W(0X14, ctx->r24);
    // lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(0X4, ctx->r24);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r2;
    // lw          $t3, 0x8($sp)
    ctx->r11 = MEM_W(0X8, ctx->r29);
    // lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(0X4, ctx->r4);
    // addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // sw          $t3, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r11;
    // lw          $v0, 0x18($t8)
    ctx->r2 = MEM_W(0X18, ctx->r24);
    // lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(0X4, ctx->r24);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r2;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // lw          $v1, 0x1C($t8)
    ctx->r3 = MEM_W(0X1C, ctx->r24);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $t3, $v0, L_800478E0
    if (ctx->r11 != ctx->r2) {
        // sw          $v1, 0x1C($t8)
        MEM_W(0X1C, ctx->r24) = ctx->r3;
        goto L_800478E0;
    }
    // sw          $v1, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r3;
L_80048AA0:
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
