#include "recomp.h"
#include "disable_warnings.h"

void sub_80018F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // addu        $fp, $a3, $zero
    ctx->r30 = ADD32(ctx->r7, 0);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // lui         $s1, 0x1F80
    ctx->r17 = S32(0X1F80 << 16);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // lw          $v1, 0x8C($s1)
    ctx->r3 = MEM_W(0X8C, ctx->r17);
    // lbu         $a0, 0x6DFC($v0)
    ctx->r4 = MEM_BU(0X6DFC, ctx->r2);
    // lw          $t5, 0x10($s1)
    ctx->r13 = MEM_W(0X10, ctx->r17);
    // addu        $v1, $v1, $s5
    ctx->r3 = ADD32(ctx->r3, ctx->r21);
    // andi        $v0, $a0, 0x2
    ctx->r2 = ctx->r4 & 0X2;
    // sw          $v1, 0x8C($s1)
    MEM_W(0X8C, ctx->r17) = ctx->r3;
    // beq         $v0, $zero, L_80018FCC
    if (ctx->r2 == 0) {
        // sw          $t5, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r13;
        goto L_80018FCC;
    }
    // sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // j           L_80018FDC
    // addiu       $s4, $v0, -0x713C
    ctx->r20 = ADD32(ctx->r2, -0X713C);
    goto L_80018FDC;
    // addiu       $s4, $v0, -0x713C
    ctx->r20 = ADD32(ctx->r2, -0X713C);
L_80018FCC:
    // andi        $v0, $a0, 0x4
    ctx->r2 = ctx->r4 & 0X4;
    // beq         $v0, $zero, L_80018FDC
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8002
        ctx->r2 = S32(0X8002 << 16);
        goto L_80018FDC;
    }
    // lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // addiu       $s4, $v0, -0x70FC
    ctx->r20 = ADD32(ctx->r2, -0X70FC);
L_80018FDC:
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // beq         $v0, $zero, L_80019264
    if (ctx->r2 == 0) {
        // addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
        goto L_80019264;
    }
    // addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // andi        $v0, $fp, 0x2
    ctx->r2 = ctx->r30 & 0X2;
    // ori         $v0, $v0, 0x3C
    ctx->r2 = ctx->r2 | 0X3C;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $s6, $s1, 0x60
    ctx->r22 = ADD32(ctx->r17, 0X60);
L_80018FF8:
    // lhu         $v1, 0x12($t0)
    ctx->r3 = MEM_HU(0X12, ctx->r8);
    // lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(0X40, ctx->r17);
    // lhu         $a0, 0x1A($t0)
    ctx->r4 = MEM_HU(0X1A, ctx->r8);
    // addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // addu        $t2, $v0, $a0
    ctx->r10 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v1, 0x16($t0)
    ctx->r3 = MEM_HU(0X16, ctx->r8);
    // lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(0X0, ctx->r12);
    // lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(0X0, ctx->r10);
    // addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    // lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(0X0, ctx->r9);
    // mtc2        $t6, $12
    gte_mtc2(ctx, 14, 12);
    // mtc2        $t5, $14
    gte_mtc2(ctx, 13, 14);
    // mtc2        $t7, $13
    gte_mtc2(ctx, 15, 13);
    // addiu       $s7, $t0, 0x20
    ctx->r23 = ADD32(ctx->r8, 0X20);
    // nop

    // nop

    // .word       0x4B400006                   # INVALID     $k0, $zero, 0x6 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B400006);
    // lbu         $v0, 0xB($t0)
    ctx->r2 = MEM_BU(0XB, ctx->r8);
    // lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(0X14, ctx->r29);
    // nop

    // or          $v0, $v0, $t6
    ctx->r2 = ctx->r2 | ctx->r14;
    // sb          $v0, 0x63($s1)
    MEM_B(0X63, ctx->r17) = ctx->r2;
    // addiu       $v0, $s1, 0x70
    ctx->r2 = ADD32(ctx->r17, 0X70);
    // swc2        $24, 0x0($v0)
    gte_swc2(rdram, ctx, 24, 2, 0);
    // lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(0X70, ctx->r17);
    // nop

    // blez        $v0, L_80019254
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80019254;
    }
    // nop

    // lbu         $v1, 0xA($t0)
    ctx->r3 = MEM_BU(0XA, ctx->r8);
    // lhu         $a2, 0x1E($t0)
    ctx->r6 = MEM_HU(0X1E, ctx->r8);
    // lw          $a1, 0x40($s1)
    ctx->r5 = MEM_W(0X40, ctx->r17);
    // lh          $v0, 0x4($t4)
    ctx->r2 = MEM_HS(0X4, ctx->r12);
    // lh          $a0, 0x4($t1)
    ctx->r4 = MEM_HS(0X4, ctx->r9);
    // sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3) << 24;
    // sra         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3) >> 24;
    // addu        $a3, $a1, $a2
    ctx->r7 = ADD32(ctx->r5, ctx->r6);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lh          $a0, 0x4($t2)
    ctx->r4 = MEM_HS(0X4, ctx->r10);
    // lh          $a1, 0x4($a3)
    ctx->r5 = MEM_HS(0X4, ctx->r7);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // sra         $t3, $v1, 16
    ctx->r11 = S32(ctx->r3) >> 16;
    // slt         $v0, $t3, $v0
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80019254
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80019254;
    }
    // nop

    // lw          $v0, 0x80($s1)
    ctx->r2 = MEM_W(0X80, ctx->r17);
    // nop

    // slt         $v0, $v0, $t3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // beq         $v0, $zero, L_80019254
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80019254;
    }
    // nop

    // lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(0X10, ctx->r17);
    // nop

    // addiu       $v0, $a2, 0x34
    ctx->r2 = ADD32(ctx->r6, 0X34);
    // sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // swc2        $12, 0x8($a2)
    gte_swc2(rdram, ctx, 12, 6, 8);
    // swc2        $13, 0x14($a2)
    gte_swc2(rdram, ctx, 13, 6, 20);
    // swc2        $14, 0x20($a2)
    gte_swc2(rdram, ctx, 14, 6, 32);
    // lhu         $a1, 0x10($t0)
    ctx->r5 = MEM_HU(0X10, ctx->r8);
    // lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(0X24, ctx->r17);
    // lhu         $v1, 0x14($t0)
    ctx->r3 = MEM_HU(0X14, ctx->r8);
    // lhu         $a0, 0x18($t0)
    ctx->r4 = MEM_HU(0X18, ctx->r8);
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lwc2        $0, 0x0($a1)
    gte_lwc2(rdram, ctx, 0, 5, 0);
    // lwc2        $1, 0x4($a1)
    gte_lwc2(rdram, ctx, 1, 5, 4);
    // lwc2        $2, 0x0($v1)
    gte_lwc2(rdram, ctx, 2, 3, 0);
    // lwc2        $3, 0x4($v1)
    gte_lwc2(rdram, ctx, 3, 3, 4);
    // lwc2        $4, 0x0($v0)
    gte_lwc2(rdram, ctx, 4, 2, 0);
    // lwc2        $5, 0x4($v0)
    gte_lwc2(rdram, ctx, 5, 2, 4);
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // nop

    // sw          $v0, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r2;
    // lwc2        $6, 0x0($s6)
    gte_lwc2(rdram, ctx, 6, 22, 0);
    // lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(0X0, ctx->r8);
    // nop

    // sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // lh          $v0, 0x6($t4)
    ctx->r2 = MEM_HS(0X6, ctx->r12);
    // lh          $v1, 0x6($t1)
    ctx->r3 = MEM_HS(0X6, ctx->r9);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x6($t2)
    ctx->r3 = MEM_HS(0X6, ctx->r10);
    // lh          $a0, 0x6($a3)
    ctx->r4 = MEM_HS(0X6, ctx->r7);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // mtc2        $v0, $8
    gte_mtc2(ctx, 2, 8);
    // lui         $v0, 0x60
    ctx->r2 = S32(0X60 << 16);
    // lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(0X4, ctx->r8);
    // and         $v0, $fp, $v0
    ctx->r2 = ctx->r30 & ctx->r2;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r3;
    // .word       0x4AF80416                   # INVALID     $s7, $t8, 0x416 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AF80416);
    // addiu       $a3, $a2, 0x4
    ctx->r7 = ADD32(ctx->r6, 0X4);
    // addiu       $s2, $a2, 0x10
    ctx->r18 = ADD32(ctx->r6, 0X10);
    // lhu         $v0, 0x8($t0)
    ctx->r2 = MEM_HU(0X8, ctx->r8);
    // addiu       $s3, $a2, 0x1C
    ctx->r19 = ADD32(ctx->r6, 0X1C);
    // sh          $v0, 0x24($a2)
    MEM_H(0X24, ctx->r6) = ctx->r2;
    // swc2        $20, 0x0($a3)
    gte_swc2(rdram, ctx, 20, 7, 0);
    // swc2        $21, 0x0($s2)
    gte_swc2(rdram, ctx, 21, 18, 0);
    // swc2        $22, 0x0($s3)
    gte_swc2(rdram, ctx, 22, 19, 0);
    // lhu         $v1, 0x1C($t0)
    ctx->r3 = MEM_HU(0X1C, ctx->r8);
    // lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(0X24, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // lwc2        $6, 0x0($s6)
    gte_lwc2(rdram, ctx, 6, 22, 0);
    // lhu         $t4, 0x6($t4)
    ctx->r12 = MEM_HU(0X6, ctx->r12);
    // nop

    // mtc2        $t4, $8
    gte_mtc2(ctx, 12, 8);
    // lhu         $v0, 0xC($t0)
    ctx->r2 = MEM_HU(0XC, ctx->r8);
    // nop

    // sh          $v0, 0x30($a2)
    MEM_H(0X30, ctx->r6) = ctx->r2;
    // .word       0x4AE80413                   # INVALID     $s7, $t0, 0x413 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AE80413);
    // lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // sll         $a0, $t3, 2
    ctx->r4 = S32(ctx->r11) << 2;
    // ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(0X48, ctx->r29);
    // lui         $v0, 0xC00
    ctx->r2 = S32(0XC00 << 16);
    // addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // addiu       $s0, $a2, 0x28
    ctx->r16 = ADD32(ctx->r6, 0X28);
    // and         $v1, $v1, $a1
    ctx->r3 = ctx->r3 & ctx->r5;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // and         $a1, $a2, $a1
    ctx->r5 = ctx->r6 & ctx->r5;
    // sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // swc2        $22, 0x0($s0)
    gte_swc2(rdram, ctx, 22, 16, 0);
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0x6DFC($v0)
    ctx->r2 = MEM_BU(0X6DFC, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // beq         $v0, $zero, L_80019258
    if (ctx->r2 == 0) {
        // addu        $t0, $s7, $zero
        ctx->r8 = ADD32(ctx->r23, 0);
        goto L_80019258;
    }
    // addu        $t0, $s7, $zero
    ctx->r8 = ADD32(ctx->r23, 0);
    // jalr        $s4
    // addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
    goto after_0;
    // addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    after_0:
    // jalr        $s4
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
    goto after_1;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_1:
    // jalr        $s4
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
    goto after_2;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_2:
    // jalr        $s4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
    goto after_3;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
L_80019254:
    // addu        $t0, $s7, $zero
    ctx->r8 = ADD32(ctx->r23, 0);
L_80019258:
    // addu        $v0, $s5, $zero
    ctx->r2 = ADD32(ctx->r21, 0);
    // bne         $v0, $zero, L_80018FF8
    if (ctx->r2 != 0) {
        // addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
        goto L_80018FF8;
    }
    // addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_80019264:
    // lui         $v1, 0x2AAA
    ctx->r3 = S32(0X2AAA << 16);
    // lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(0X10, ctx->r17);
    // lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(0X10, ctx->r29);
    // ori         $v1, $v1, 0xAAAB
    ctx->r3 = ctx->r3 | 0XAAAB;
    // subu        $a0, $a0, $t5
    ctx->r4 = SUB32(ctx->r4, ctx->r13);
    // sra         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) >> 2;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x90($s1)
    ctx->r2 = MEM_W(0X90, ctx->r17);
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // sw          $t0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r8;
    // mfhi        $t6
    ctx->r14 = hi;
    // sra         $v1, $t6, 1
    ctx->r3 = S32(ctx->r14) >> 1;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r2;
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
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
