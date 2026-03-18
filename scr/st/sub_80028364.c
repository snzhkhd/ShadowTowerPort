#include "recomp.h"
#include "disable_warnings.h"

void sub_80028364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // addu        $fp, $a2, $zero
    ctx->r30 = ADD32(ctx->r6, 0);
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(0X50, ctx->r29);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
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
    // andi        $t2, $a0, 0x1
    ctx->r10 = ctx->r4 & 0X1;
    // sra         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) >> 1;
    // andi        $t1, $v0, 0x3
    ctx->r9 = ctx->r2 & 0X3;
    // sra         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4) >> 3;
    // andi        $t0, $v0, 0x3
    ctx->r8 = ctx->r2 & 0X3;
    // sra         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4) >> 5;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // lw          $v1, 0x304($a2)
    ctx->r3 = MEM_W(0X304, ctx->r6);
    // andi        $s7, $a0, 0x3
    ctx->r23 = ctx->r4 & 0X3;
    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_80028674
    if (ctx->r2 != 0) {
        // addu        $s6, $a3, $zero
        ctx->r22 = ADD32(ctx->r7, 0);
        goto L_80028674;
    }
    // addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // lw          $v0, 0x328($a2)
    ctx->r2 = MEM_W(0X328, ctx->r6);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($a2)
    MEM_W(0X328, ctx->r6) = ctx->r2;
    // lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(0X0, ctx->r5);
    // lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(0X0, ctx->r5);
    // lbu         $s3, 0x2($a1)
    ctx->r19 = MEM_BU(0X2, ctx->r5);
    // andi        $a2, $v0, 0xFFC0
    ctx->r6 = ctx->r2 & 0XFFC0;
    // lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(0X2, ctx->r5);
    // andi        $s1, $v1, 0x3F
    ctx->r17 = ctx->r3 & 0X3F;
    // bne         $t0, $zero, L_80028434
    if (ctx->r8 != 0) {
        // andi        $a3, $v0, 0xFF00
        ctx->r7 = ctx->r2 & 0XFF00;
        goto L_80028434;
    }
    // andi        $a3, $v0, 0xFF00
    ctx->r7 = ctx->r2 & 0XFF00;
    // andi        $v1, $s1, 0xFF
    ctx->r3 = ctx->r17 & 0XFF;
    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_8002844C
    if (ctx->r2 == 0) {
        // sll         $s1, $v1, 2
        ctx->r17 = S32(ctx->r3) << 2;
        goto L_8002844C;
    }
    // sll         $s1, $v1, 2
    ctx->r17 = S32(ctx->r3) << 2;
    // j           L_80028450
    // nop

    goto L_80028450;
    // nop

L_80028434:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $t0, $v0, L_80028450
    if (ctx->r8 != ctx->r2) {
        // andi        $v1, $s1, 0xFF
        ctx->r3 = ctx->r17 & 0XFF;
        goto L_80028450;
    }
    // andi        $v1, $s1, 0xFF
    ctx->r3 = ctx->r17 & 0XFF;
    // sltiu       $v0, $v1, 0x80
    ctx->r2 = ctx->r3 < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_80028450
    if (ctx->r2 != 0) {
        // sll         $s1, $v1, 1
        ctx->r17 = S32(ctx->r3) << 1;
        goto L_80028450;
    }
    // sll         $s1, $v1, 1
    ctx->r17 = S32(ctx->r3) << 1;
L_8002844C:
    // addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
L_80028450:
    // lh          $v1, 0x4($s2)
    ctx->r3 = MEM_HS(0X4, ctx->r18);
    // andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, 0x100
    ctx->r2 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // beq         $v0, $zero, L_80028474
    if (ctx->r2 == 0) {
        // addiu       $s5, $zero, 0xFF
        ctx->r21 = ADD32(0, 0XFF);
        goto L_80028474;
    }
    // addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // lbu         $v0, 0x4($s2)
    ctx->r2 = MEM_BU(0X4, ctx->r18);
    // nop

    // addu        $s5, $s1, $v0
    ctx->r21 = ADD32(ctx->r17, ctx->r2);
L_80028474:
    // lh          $v0, 0x6($s2)
    ctx->r2 = MEM_HS(0X6, ctx->r18);
    // nop

    // addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // slti        $v0, $v0, 0x100
    ctx->r2 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // beq         $v0, $zero, L_80028498
    if (ctx->r2 == 0) {
        // addiu       $s4, $zero, 0xFF
        ctx->r20 = ADD32(0, 0XFF);
        goto L_80028498;
    }
    // addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
    // lbu         $v0, 0x6($s2)
    ctx->r2 = MEM_BU(0X6, ctx->r18);
    // nop

    // addu        $s4, $s3, $v0
    ctx->r20 = ADD32(ctx->r19, ctx->r2);
L_80028498:
    // addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
    // sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) << 16;
    // sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) << 16;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // jal         0x8007C704
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    GetTPage(rdram, ctx);
    goto after_0;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    after_0:
    // sh          $v0, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r2;
    // lh          $a0, 0x0($fp)
    ctx->r4 = MEM_HS(0X0, ctx->r30);
    // lh          $a1, 0x2($fp)
    ctx->r5 = MEM_HS(0X2, ctx->r30);
    // jal         0x8007C744
    // nop

    GetClut(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // bne         $s6, $zero, L_800284E0
    if (ctx->r22 != 0) {
        // sh          $v0, 0xE($s0)
        MEM_H(0XE, ctx->r16) = ctx->r2;
        goto L_800284E0;
    }
    // sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // j           L_800284FC
    // sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
    goto L_800284FC;
    // sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
L_800284E0:
    // lbu         $v0, 0x0($s6)
    ctx->r2 = MEM_BU(0X0, ctx->r22);
    // nop

    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(0X1, ctx->r22);
    // nop

    // sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x2($s6)
    ctx->r2 = MEM_BU(0X2, ctx->r22);
L_800284FC:
    // nop

    // sb          $v0, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r2;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0xE4($v0)
    ctx->r2 = MEM_W(0XE4, ctx->r2);
    // lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $v1, 0x900
    ctx->r3 = S32(0X900 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // nop

    // sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // nop

    // sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(0X4, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // nop

    // sh          $v0, 0x12($s0)
    MEM_H(0X12, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // nop

    // sh          $v0, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // lhu         $v1, 0x6($s2)
    ctx->r3 = MEM_HU(0X6, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(0X4, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // lhu         $v1, 0x6($s2)
    ctx->r3 = MEM_HU(0X6, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $s7, $v0, L_800285E8
    if (ctx->r23 != ctx->r2) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_800285E8;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // addiu       $v1, $s5, -0x1
    ctx->r3 = ADD32(ctx->r21, -0X1);
    // addiu       $v0, $s1, -0x1
    ctx->r2 = ADD32(ctx->r17, -0X1);
    // sb          $v1, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r3;
    // sb          $s3, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r19;
    // sb          $v0, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r2;
    // sb          $s3, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r19;
    // sb          $v1, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r3;
    // sb          $s4, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r20;
    // j           L_80028634
    // sb          $v0, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r2;
    goto L_80028634;
    // sb          $v0, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r2;
L_800285E8:
    // bne         $s7, $v0, L_80028618
    if (ctx->r23 != ctx->r2) {
        // addiu       $v0, $s4, -0x1
        ctx->r2 = ADD32(ctx->r20, -0X1);
        goto L_80028618;
    }
    // addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
    // sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // sb          $v0, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r2;
    // addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // sb          $s1, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r17;
    // sb          $s5, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r21;
    // sb          $s1, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r17;
    // sb          $v0, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r2;
    // sb          $s5, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r21;
    // j           L_80028638
    // sb          $v0, 0x25($s0)
    MEM_B(0X25, ctx->r16) = ctx->r2;
    goto L_80028638;
    // sb          $v0, 0x25($s0)
    MEM_B(0X25, ctx->r16) = ctx->r2;
L_80028618:
    // sb          $s1, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r17;
    // sb          $s3, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r19;
    // sb          $s5, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r21;
    // sb          $s3, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r19;
    // sb          $s1, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r17;
    // sb          $s4, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r20;
    // sb          $s5, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r21;
L_80028634:
    // sb          $s4, 0x25($s0)
    MEM_B(0X25, ctx->r16) = ctx->r20;
L_80028638:
    // lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(0X10, ctx->r29);
    // nop

    // bne         $t2, $zero, L_8002864C
    if (ctx->r10 != 0) {
        // addiu       $v0, $zero, 0x2E
        ctx->r2 = ADD32(0, 0X2E);
        goto L_8002864C;
    }
    // addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    // addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
L_8002864C:
    // sb          $v0, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r2;
    // lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0xE4($v0)
    ctx->r2 = MEM_W(0XE4, ctx->r2);
    // and         $a0, $s0, $a0
    ctx->r4 = ctx->r16 & ctx->r4;
    // sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_80028674:
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
