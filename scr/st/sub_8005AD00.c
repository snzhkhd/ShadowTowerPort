#include "recomp.h"
#include "disable_warnings.h"

void sub_8005AD00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // sw          $ra, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r31;
    // sw          $fp, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r30;
    // sw          $s7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r23;
    // sw          $s6, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r22;
    // sw          $s5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r21;
    // sw          $s4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r20;
    // sw          $s3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r19;
    // sw          $s2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r18;
    // sw          $s1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r17;
    // sw          $s0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r16;
    // addiu       $s2, $zero, 0x280
    ctx->r18 = ADD32(0, 0X280);
    // sh          $s2, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r18;
    // sh          $zero, 0x12($sp)
    MEM_H(0X12, ctx->r29) = 0;
    // addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // addu        $s7, $s6, $zero
    ctx->r23 = ADD32(ctx->r22, 0);
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // addiu       $s0, $v1, -0x7400
    ctx->r16 = ADD32(ctx->r3, -0X7400);
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // lw          $v1, -0x7400($v1)
    ctx->r3 = MEM_W(-0X7400, ctx->r3);
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1F6
    ctx->r2 = ADD32(0, 0X1F6);
    // sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    // lhu         $a1, 0x2($v1)
    ctx->r5 = MEM_HU(0X2, ctx->r3);
    // jal         0x80015A94
    // addiu       $s4, $s0, 0x88
    ctx->r20 = ADD32(ctx->r16, 0X88);
    sub_80015A94(rdram, ctx);
    goto after_0;
    // addiu       $s4, $s0, 0x88
    ctx->r20 = ADD32(ctx->r16, 0X88);
    after_0:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x80068CE0
    // addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    CdControl(rdram, ctx);
    goto after_1;
    // addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_1:
    // jal         0x800796E4
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    ResetGraph(rdram, ctx);
    goto after_2;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // jal         0x8005AA80
    // addiu       $s1, $s0, 0x8C
    ctx->r17 = ADD32(ctx->r16, 0X8C);
    sub_8005AA80(rdram, ctx);
    goto after_3;
    // addiu       $s1, $s0, 0x8C
    ctx->r17 = ADD32(ctx->r16, 0X8C);
    after_3:
    // jal         0x800152D0
    // addiu       $a0, $zero, 0x5400
    ctx->r4 = ADD32(0, 0X5400);
    sub_800152D0(rdram, ctx);
    goto after_4;
    // addiu       $a0, $zero, 0x5400
    ctx->r4 = ADD32(0, 0X5400);
    after_4:
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sw          $v0, 0x2CC($at)
    MEM_W(0X2CC, ctx->r1) = ctx->r2;
    // jal         0x800152D0
    // addiu       $a0, $zero, 0x90
    ctx->r4 = ADD32(0, 0X90);
    sub_800152D0(rdram, ctx);
    goto after_5;
    // addiu       $a0, $zero, 0x90
    ctx->r4 = ADD32(0, 0X90);
    after_5:
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sw          $v0, 0x2D0($at)
    MEM_W(0X2D0, ctx->r1) = ctx->r2;
    // jal         0x80016030
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    sub_80016030(rdram, ctx);
    goto after_6;
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_6:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    sub_80014CFC(rdram, ctx);
    goto after_7;
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    after_7:
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // ori         $a1, $a1, 0x2E6
    ctx->r5 = ctx->r5 | 0X2E6;
    // lui         $a2, 0x1F80
    ctx->r6 = S32(0X1F80 << 16);
    // ori         $a2, $a2, 0x2EA
    ctx->r6 = ctx->r6 | 0X2EA;
    // lw          $v0, 0x88($s0)
    ctx->r2 = MEM_W(0X88, ctx->r16);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s4, $v0, $s4
    ctx->r20 = ADD32(ctx->r2, ctx->r20);
    // jal         0x8003EC5C
    // addiu       $a0, $s4, 0x4
    ctx->r4 = ADD32(ctx->r20, 0X4);
    sub_8003EC5C(rdram, ctx);
    goto after_8;
    // addiu       $a0, $s4, 0x4
    ctx->r4 = ADD32(ctx->r20, 0X4);
    after_8:
    // addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // lui         $s3, 0x1F80
    ctx->r19 = S32(0X1F80 << 16);
    // lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(0X0, ctx->r20);
    // lw          $a0, 0x2D0($s3)
    ctx->r4 = MEM_W(0X2D0, ctx->r19);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s4, $s4, $v0
    ctx->r20 = ADD32(ctx->r20, ctx->r2);
    // jal         0x80014CFC
    // addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    sub_80014CFC(rdram, ctx);
    goto after_9;
    // addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    after_9:
    // addiu       $s4, $s0, 0x88
    ctx->r20 = ADD32(ctx->r16, 0X88);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // jal         0x80016030
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    sub_80016030(rdram, ctx);
    goto after_10;
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_10:
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // lw          $a0, 0x2CC($s3)
    ctx->r4 = MEM_W(0X2CC, ctx->r19);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    sub_80014CFC(rdram, ctx);
    goto after_11;
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    after_11:
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // ori         $a1, $a1, 0x2EE
    ctx->r5 = ctx->r5 | 0X2EE;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // ori         $a2, $a2, 0x2F2
    ctx->r6 = ctx->r6 | 0X2F2;
    // lw          $v0, 0x88($s0)
    ctx->r2 = MEM_W(0X88, ctx->r16);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s4, $v0, $s4
    ctx->r20 = ADD32(ctx->r2, ctx->r20);
    // jal         0x8003EC5C
    // addiu       $a0, $s4, 0x4
    ctx->r4 = ADD32(ctx->r20, 0X4);
    sub_8003EC5C(rdram, ctx);
    goto after_12;
    // addiu       $a0, $s4, 0x4
    ctx->r4 = ADD32(ctx->r20, 0X4);
    after_12:
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // addiu       $s0, $s0, 0x88
    ctx->r16 = ADD32(ctx->r16, 0X88);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_13;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_13:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // ori         $a1, $a1, 0x2F6
    ctx->r5 = ctx->r5 | 0X2F6;
    // addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_14;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // jal         0x80079A60
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    DrawSync(rdram, ctx);
    goto after_15;
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_15:
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_16;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_16:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_17;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_17:
    // jal         0x80079A60
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    DrawSync(rdram, ctx);
    goto after_18;
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_18:
    // addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $v0, 0x2($s3)
    MEM_H(0X2, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x230
    ctx->r2 = ADD32(0, 0X230);
    // sh          $v0, 0x4($s3)
    MEM_H(0X4, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x1F2
    ctx->r2 = ADD32(0, 0X1F2);
    // sh          $s2, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r18;
    // jal         0x800152D0
    // sh          $v0, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_19;
    // sh          $v0, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r2;
    after_19:
    // addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // jal         0x800152D0
    // sw          $v0, 0x174($s3)
    MEM_W(0X174, ctx->r19) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_20;
    // sw          $v0, 0x174($s3)
    MEM_W(0X174, ctx->r19) = ctx->r2;
    after_20:
    // addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // jal         0x800152D0
    // sw          $v0, 0x178($s3)
    MEM_W(0X178, ctx->r19) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_21;
    // sw          $v0, 0x178($s3)
    MEM_W(0X178, ctx->r19) = ctx->r2;
    after_21:
    // addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // jal         0x800152D0
    // sw          $v0, 0x17C($s3)
    MEM_W(0X17C, ctx->r19) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_22;
    // sw          $v0, 0x17C($s3)
    MEM_W(0X17C, ctx->r19) = ctx->r2;
    after_22:
    // addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // jal         0x800152D0
    // sw          $v0, 0x180($s3)
    MEM_W(0X180, ctx->r19) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_23;
    // sw          $v0, 0x180($s3)
    MEM_W(0X180, ctx->r19) = ctx->r2;
    after_23:
    // addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // jal         0x800152D0
    // sw          $v0, 0x184($s3)
    MEM_W(0X184, ctx->r19) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_24;
    // sw          $v0, 0x184($s3)
    MEM_W(0X184, ctx->r19) = ctx->r2;
    after_24:
    // addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    // jal         0x800152D0
    // sw          $v0, 0x188($s3)
    MEM_W(0X188, ctx->r19) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_25;
    // sw          $v0, 0x188($s3)
    MEM_W(0X188, ctx->r19) = ctx->r2;
    after_25:
    // addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // jal         0x800152D0
    // sw          $v0, 0x18C($s3)
    MEM_W(0X18C, ctx->r19) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_26;
    // sw          $v0, 0x18C($s3)
    MEM_W(0X18C, ctx->r19) = ctx->r2;
    after_26:
    // addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // jal         0x800152D0
    // sw          $v0, 0x190($s3)
    MEM_W(0X190, ctx->r19) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_27;
    // sw          $v0, 0x190($s3)
    MEM_W(0X190, ctx->r19) = ctx->r2;
    after_27:
    // addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // jal         0x800152D0
    // sw          $v0, 0x194($s3)
    MEM_W(0X194, ctx->r19) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_28;
    // sw          $v0, 0x194($s3)
    MEM_W(0X194, ctx->r19) = ctx->r2;
    after_28:
    // addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    // jal         0x800152D0
    // sw          $v0, 0x198($s3)
    MEM_W(0X198, ctx->r19) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_29;
    // sw          $v0, 0x198($s3)
    MEM_W(0X198, ctx->r19) = ctx->r2;
    after_29:
    // addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $t0, $v1, 0x7590
    ctx->r8 = ADD32(ctx->r3, 0X7590);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $a3, $v1, 0x76F8
    ctx->r7 = ADD32(ctx->r3, 0X76F8);
    // sw          $v0, 0x1B0($s3)
    MEM_W(0X1B0, ctx->r19) = ctx->r2;
    // sh          $zero, 0x1AE($s3)
    MEM_H(0X1AE, ctx->r19) = 0;
    // sh          $zero, 0x1AC($s3)
    MEM_H(0X1AC, ctx->r19) = 0;
    // sh          $zero, 0x1AA($s3)
    MEM_H(0X1AA, ctx->r19) = 0;
    // sh          $zero, 0x1A8($s3)
    MEM_H(0X1A8, ctx->r19) = 0;
    // sh          $zero, 0x1A6($s3)
    MEM_H(0X1A6, ctx->r19) = 0;
    // sh          $zero, 0x1A4($s3)
    MEM_H(0X1A4, ctx->r19) = 0;
    // sh          $zero, 0x1A2($s3)
    MEM_H(0X1A2, ctx->r19) = 0;
    // sh          $zero, 0x1A0($s3)
    MEM_H(0X1A0, ctx->r19) = 0;
    // sh          $zero, 0x19E($s3)
    MEM_H(0X19E, ctx->r19) = 0;
    // sh          $zero, 0x19C($s3)
    MEM_H(0X19C, ctx->r19) = 0;
L_8005AFB8:
    // addu        $v0, $a2, $t0
    ctx->r2 = ADD32(ctx->r6, ctx->r8);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 & 0X7F;
    // beq         $v0, $zero, L_8005B0E4
    if (ctx->r2 == 0) {
        // srl         $v0, $v1, 7
        ctx->r2 = S32(U32(ctx->r3) >> 7);
        goto L_8005B0E4;
    }
    // srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
    // bne         $v0, $zero, L_8005B0E4
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8005B0E4;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // lbu         $v1, 0x13E($a3)
    ctx->r3 = MEM_BU(0X13E, ctx->r7);
    // nop

    // beq         $v1, $v0, L_8005B0E4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
        goto L_8005B0E4;
    }
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // bne         $v1, $v0, L_8005B014
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005B014;
    }
    // nop

    // lhu         $v0, 0x1A8($s3)
    ctx->r2 = MEM_HU(0X1A8, ctx->r19);
    // nop

    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sh          $v1, 0x1A8($s3)
    MEM_H(0X1A8, ctx->r19) = ctx->r3;
    // lw          $v1, 0x18C($s3)
    ctx->r3 = MEM_W(0X18C, ctx->r19);
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // j           L_8005B0E0
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    goto L_8005B0E0;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8005B014:
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // bne         $v1, $v0, L_8005B044
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005B044;
    }
    // nop

    // lhu         $v0, 0x19E($s3)
    ctx->r2 = MEM_HU(0X19E, ctx->r19);
    // nop

    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sh          $v1, 0x19E($s3)
    MEM_H(0X19E, ctx->r19) = ctx->r3;
    // lw          $v1, 0x178($s3)
    ctx->r3 = MEM_W(0X178, ctx->r19);
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // j           L_8005B0E0
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    goto L_8005B0E0;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8005B044:
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // beq         $v1, $v0, L_8005B058
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x1E
        ctx->r2 = ADD32(0, 0X1E);
        goto L_8005B058;
    }
    // addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // bne         $v1, $v0, L_8005B0A8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005B0A8;
    }
    // nop

L_8005B058:
    // addiu       $v0, $zero, 0x10A
    ctx->r2 = ADD32(0, 0X10A);
    // beq         $a2, $v0, L_8005B0E4
    if (ctx->r6 == ctx->r2) {
        // addiu       $v0, $zero, 0x136
        ctx->r2 = ADD32(0, 0X136);
        goto L_8005B0E4;
    }
    // addiu       $v0, $zero, 0x136
    ctx->r2 = ADD32(0, 0X136);
    // beq         $a2, $v0, L_8005B0E4
    if (ctx->r6 == ctx->r2) {
        // addiu       $v0, $zero, 0x137
        ctx->r2 = ADD32(0, 0X137);
        goto L_8005B0E4;
    }
    // addiu       $v0, $zero, 0x137
    ctx->r2 = ADD32(0, 0X137);
    // beq         $a2, $v0, L_8005B0E4
    if (ctx->r6 == ctx->r2) {
        // addiu       $v0, $zero, 0x138
        ctx->r2 = ADD32(0, 0X138);
        goto L_8005B0E4;
    }
    // addiu       $v0, $zero, 0x138
    ctx->r2 = ADD32(0, 0X138);
    // beq         $a2, $v0, L_8005B0E4
    if (ctx->r6 == ctx->r2) {
        // addiu       $v0, $zero, 0x139
        ctx->r2 = ADD32(0, 0X139);
        goto L_8005B0E4;
    }
    // addiu       $v0, $zero, 0x139
    ctx->r2 = ADD32(0, 0X139);
    // beq         $a2, $v0, L_8005B0E4
    if (ctx->r6 == ctx->r2) {
        // nop
    
        goto L_8005B0E4;
    }
    // nop

    // lhu         $v0, 0x1AE($s3)
    ctx->r2 = MEM_HU(0X1AE, ctx->r19);
    // nop

    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sh          $v1, 0x1AE($s3)
    MEM_H(0X1AE, ctx->r19) = ctx->r3;
    // lw          $v1, 0x198($s3)
    ctx->r3 = MEM_W(0X198, ctx->r19);
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // j           L_8005B0E0
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    goto L_8005B0E0;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8005B0A8:
    // lbu         $v1, 0x13E($a3)
    ctx->r3 = MEM_BU(0X13E, ctx->r7);
    // nop

    // sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3) << 2;
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addiu       $v1, $v1, 0x19C
    ctx->r3 = ADD32(ctx->r3, 0X19C);
    // addu        $v1, $s3, $v1
    ctx->r3 = ADD32(ctx->r19, ctx->r3);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(0X174, ctx->r4);
    // addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
L_8005B0E0:
    // sh          $a2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r6;
L_8005B0E4:
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slti        $v0, $a2, 0x13A
    ctx->r2 = SIGNED(ctx->r6) < 0X13A ? 1 : 0;
    // bne         $v0, $zero, L_8005AFB8
    if (ctx->r2 != 0) {
        // addiu       $a3, $a3, 0x2C
        ctx->r7 = ADD32(ctx->r7, 0X2C);
        goto L_8005AFB8;
    }
    // addiu       $a3, $a3, 0x2C
    ctx->r7 = ADD32(ctx->r7, 0X2C);
    // jal         0x80031CFC
    // nop

    sub_80031CFC(rdram, ctx);
    goto after_30;
    // nop

    after_30:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_31;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_31:
    // jal         0x800172BC
    // nop

    sub_800172BC(rdram, ctx);
    goto after_32;
    // nop

    after_32:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $v0, 0x2C4($s3)
    MEM_H(0X2C4, ctx->r19) = ctx->r2;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
L_8005B120:
    // lhu         $v0, 0x2C4($s3)
    ctx->r2 = MEM_HU(0X2C4, ctx->r19);
    // lh          $v1, 0x62($a0)
    ctx->r3 = MEM_HS(0X62, ctx->r4);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // lhu         $v1, 0x62($a0)
    ctx->r3 = MEM_HU(0X62, ctx->r4);
    // beq         $v0, $zero, L_8005B144
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005B144;
    }
    // nop

    // sh          $v1, 0x2C4($s3)
    MEM_H(0X2C4, ctx->r19) = ctx->r3;
L_8005B144:
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slti        $v0, $a2, 0xE
    ctx->r2 = SIGNED(ctx->r6) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_8005B120
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
        goto L_8005B120;
    }
    // addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $zero, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = 0;
    // sh          $v0, 0x2DC($s3)
    MEM_H(0X2DC, ctx->r19) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // sb          $zero, 0x2C6($s3)
    MEM_B(0X2C6, ctx->r19) = 0;
    // sh          $zero, 0x2E0($s3)
    MEM_H(0X2E0, ctx->r19) = 0;
    // lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(0X2, ctx->r2);
    // addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // sh          $v1, 0x2D8($s3)
    MEM_H(0X2D8, ctx->r19) = ctx->r3;
    // lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(0X6, ctx->r2);
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // jal         0x8005A3A8
    // sh          $v0, 0x2DA($s3)
    MEM_H(0X2DA, ctx->r19) = ctx->r2;
    sub_8005A3A8(rdram, ctx);
    goto after_33;
    // sh          $v0, 0x2DA($s3)
    MEM_H(0X2DA, ctx->r19) = ctx->r2;
    after_33:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_34;
    // nop

    after_34:
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7F4C
    ctx->r6 = ADD32(ctx->r2, -0X7F4C);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x5B($sp)
    do_swl(rdram, 0X5B, ctx->r29, ctx->r3);
    // swr         $v1, 0x58($sp)
    do_swr(rdram, 0X58, ctx->r29, ctx->r3);
    // swl         $a0, 0x5F($sp)
    do_swl(rdram, 0X5F, ctx->r29, ctx->r4);
    // swr         $a0, 0x5C($sp)
    do_swr(rdram, 0X5C, ctx->r29, ctx->r4);
    // addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x2924
    ctx->r6 = ADD32(ctx->r2, 0X2924);
    // addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $zero, -0x7E56($at)
    MEM_H(-0X7E56, ctx->r1) = 0;
L_8005B1D4:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_8005B1D4
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8005B1D4;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x80079BE4
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    ClearImage(rdram, ctx);
    goto after_35;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_35:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_36;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_36:
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $zero, -0x7E6E($at)
    MEM_H(-0X7E6E, ctx->r1) = 0;
    // jal         0x8002FC4C
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    sub_8002FC4C(rdram, ctx);
    goto after_37;
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    after_37:
    // jal         0x8002FC4C
    // ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    sub_8002FC4C(rdram, ctx);
    goto after_38;
    // ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    after_38:
    // lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(0X60, ctx->r29);
    // jal         0x80059204
    // addiu       $s0, $sp, 0x14
    ctx->r16 = ADD32(ctx->r29, 0X14);
    sub_80059204(rdram, ctx);
    goto after_39;
    // addiu       $s0, $sp, 0x14
    ctx->r16 = ADD32(ctx->r29, 0X14);
    after_39:
    // jal         0x8002FC4C
    // nop

    sub_8002FC4C(rdram, ctx);
    goto after_40;
    // nop

    after_40:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s1, $v0, -0x70D8
    ctx->r17 = ADD32(ctx->r2, -0X70D8);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s4, $v0, 0x76F8
    ctx->r20 = ADD32(ctx->r2, 0X76F8);
L_8005B258:
    // lhu         $v0, 0x3E($s1)
    ctx->r2 = MEM_HU(0X3E, ctx->r17);
    // nop

    // beq         $v0, $s5, L_8005B2A0
    if (ctx->r2 == ctx->r21) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8005B2A0;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // lbu         $v1, 0x13E($v0)
    ctx->r3 = MEM_BU(0X13E, ctx->r2);
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // bne         $v1, $v0, L_8005B2A0
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
        goto L_8005B2A0;
    }
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(0X50, ctx->r16);
    // nop

    // beq         $v1, $v0, L_8005B358
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005B358;
    }
    // nop

L_8005B2A0:
    // lhu         $v0, 0x40($s1)
    ctx->r2 = MEM_HU(0X40, ctx->r17);
    // nop

    // beq         $v0, $s5, L_8005B2E8
    if (ctx->r2 == ctx->r21) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8005B2E8;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // lbu         $v1, 0x13E($v0)
    ctx->r3 = MEM_BU(0X13E, ctx->r2);
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // bne         $v1, $v0, L_8005B2E8
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x11
        ctx->r2 = ADD32(0, 0X11);
        goto L_8005B2E8;
    }
    // addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(0X50, ctx->r16);
    // nop

    // beq         $v1, $v0, L_8005B358
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005B358;
    }
    // nop

L_8005B2E8:
    // lhu         $v0, 0x4A($s1)
    ctx->r2 = MEM_HU(0X4A, ctx->r17);
    // nop

    // beq         $v0, $s5, L_8005B33C
    if (ctx->r2 == ctx->r21) {
        // sll         $v1, $v0, 1
        ctx->r3 = S32(ctx->r2) << 1;
        goto L_8005B33C;
    }
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // lbu         $a0, 0x13E($v1)
    ctx->r4 = MEM_BU(0X13E, ctx->r3);
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // bne         $a0, $v0, L_8005B33C
    if (ctx->r4 != ctx->r2) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8005B33C;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(0X50, ctx->r16);
    // nop

    // beq         $v1, $v0, L_8005B358
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005B358;
    }
    // nop

    // beq         $v1, $a0, L_8005B358
    if (ctx->r3 == ctx->r4) {
        // addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
        goto L_8005B358;
    }
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // beq         $v1, $v0, L_8005B358
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005B358;
    }
    // nop

L_8005B33C:
    // lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(0X50, ctx->r16);
    // jal         0x80059204
    // nop

    sub_80059204(rdram, ctx);
    goto after_41;
    // nop

    after_41:
    // jal         0x8002FC4C
    // nop

    sub_8002FC4C(rdram, ctx);
    goto after_42;
    // nop

    after_42:
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_43;
    // nop

    after_43:
L_8005B358:
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // slti        $v0, $s2, 0x14
    ctx->r2 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
    // bne         $v0, $zero, L_8005B258
    if (ctx->r2 != 0) {
        // addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
        goto L_8005B258;
    }
    // addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // jal         0x8002FC4C
    // addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    sub_8002FC4C(rdram, ctx);
    goto after_44;
    // addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    after_44:
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_45;
    // nop

    after_45:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_46;
    // nop

    after_46:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s4, $v0, -0x2E80
    ctx->r20 = ADD32(ctx->r2, -0X2E80);
    // lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // addiu       $s2, $t2, -0x70D8
    ctx->r18 = ADD32(ctx->r10, -0X70D8);
L_8005B390:
    // beq         $fp, $zero, L_8005B3A0
    if (ctx->r30 == 0) {
        // nop
    
        goto L_8005B3A0;
    }
    // nop

    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
L_8005B3A0:
    // lhu         $v0, 0x2DC($s3)
    ctx->r2 = MEM_HU(0X2DC, ctx->r19);
    // nop

    // bne         $v0, $s5, L_8005C118
    if (ctx->r2 != ctx->r21) {
        // addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
        goto L_8005C118;
    }
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // lhu         $v1, 0x4($s4)
    ctx->r3 = MEM_HU(0X4, ctx->r20);
    // nop

    // andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // beq         $v0, $zero, L_8005B3D4
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x400
        ctx->r2 = ctx->r3 & 0X400;
        goto L_8005B3D4;
    }
    // andi        $v0, $v1, 0x400
    ctx->r2 = ctx->r3 & 0X400;
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $s5, -0x7E56($at)
    MEM_H(-0X7E56, ctx->r1) = ctx->r21;
    // j           L_8005B3E4
    // nop

    goto L_8005B3E4;
    // nop

L_8005B3D4:
    // beq         $v0, $zero, L_8005B3E4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005B3E4;
    }
    // nop

    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $zero, -0x7E56($at)
    MEM_H(-0X7E56, ctx->r1) = 0;
L_8005B3E4:
    // lhu         $v0, 0x2($s4)
    ctx->r2 = MEM_HU(0X2, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // beq         $v0, $zero, L_8005B418
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005B418;
    }
    // nop

    // lbu         $v0, 0x2C6($s3)
    ctx->r2 = MEM_BU(0X2C6, ctx->r19);
    // nop

    // bne         $v0, $zero, L_8005B410
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005B410;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_47;
    // nop

    after_47:
L_8005B410:
    // j           L_8005B41C
    // sb          $s5, 0x2C6($s3)
    MEM_B(0X2C6, ctx->r19) = ctx->r21;
    goto L_8005B41C;
    // sb          $s5, 0x2C6($s3)
    MEM_B(0X2C6, ctx->r19) = ctx->r21;
L_8005B418:
    // sb          $zero, 0x2C6($s3)
    MEM_B(0X2C6, ctx->r19) = 0;
L_8005B41C:
    // lhu         $v1, 0x4($s4)
    ctx->r3 = MEM_HU(0X4, ctx->r20);
    // nop

    // andi        $v0, $v1, 0x2000
    ctx->r2 = ctx->r3 & 0X2000;
    // beq         $v0, $zero, L_8005B440
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x4000
        ctx->r2 = ctx->r3 & 0X4000;
        goto L_8005B440;
    }
    // andi        $v0, $v1, 0x4000
    ctx->r2 = ctx->r3 & 0X4000;
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_48;
    // nop

    after_48:
    // j           L_8005C71C
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    goto L_8005C71C;
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
L_8005B440:
    // beq         $v0, $zero, L_8005BE48
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
        goto L_8005BE48;
    }
    // addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // bne         $a0, $v0, L_8005B478
    if (ctx->r4 != ctx->r2) {
        // sh          $v1, 0x2DC($s3)
        MEM_H(0X2DC, ctx->r19) = ctx->r3;
        goto L_8005B478;
    }
    // sh          $v1, 0x2DC($s3)
    MEM_H(0X2DC, ctx->r19) = ctx->r3;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $s0, -0x709C($v0)
    ctx->r16 = MEM_HU(-0X709C, ctx->r2);
    // j           L_8005B4A0
    // nop

    goto L_8005B4A0;
    // nop

L_8005B478:
    // slti        $v0, $a0, 0xA
    ctx->r2 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_8005B48C
    if (ctx->r2 == 0) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_8005B48C;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // j           L_8005B494
    // addiu       $v1, $v1, -0x70A0
    ctx->r3 = ADD32(ctx->r3, -0X70A0);
    goto L_8005B494;
    // addiu       $v1, $v1, -0x70A0
    ctx->r3 = ADD32(ctx->r3, -0X70A0);
L_8005B48C:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70A2
    ctx->r3 = ADD32(ctx->r3, -0X70A2);
L_8005B494:
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $s0, 0x0($v0)
    ctx->r16 = MEM_HU(0X0, ctx->r2);
L_8005B4A0:
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // sltiu       $v0, $v1, 0x16
    ctx->r2 = ctx->r3 < 0X16 ? 1 : 0;
    // beq         $v0, $zero, L_8005BC70
    if (ctx->r2 == 0) {
        // sh          $zero, 0x2C2($s3)
        MEM_H(0X2C2, ctx->r19) = 0;
        goto L_8005BC70;
    }
    // sh          $zero, 0x2C2($s3)
    MEM_H(0X2C2, ctx->r19) = 0;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x3790
    ctx->r2 = ADD32(ctx->r2, 0X3790);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_8005B4D4;
    jr_addend_8005B4D4 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8005B4D4 >> 2) {
        case 0: goto L_8005B81C; break;
        case 1: goto L_8005B8EC; break;
        case 2: goto L_8005B74C; break;
        case 3: goto L_8005B4DC; break;
        case 4: goto L_8005B4DC; break;
        case 5: goto L_8005BA24; break;
        case 6: goto L_8005BBCC; break;
        case 7: goto L_8005B9BC; break;
        case 8: goto L_8005B684; break;
        case 9: goto L_8005B6E8; break;
        case 10: goto L_8005B6E8; break;
        case 11: goto L_8005B7B4; break;
        case 12: goto L_8005BA24; break;
        case 13: goto L_8005BBCC; break;
        case 14: goto L_8005B81C; break;
        case 15: goto L_8005B8EC; break;
        case 16: goto L_8005B74C; break;
        case 17: goto L_8005B5B0; break;
        case 18: goto L_8005B5B0; break;
        case 19: goto L_8005BA24; break;
        case 20: goto L_8005BA24; break;
        case 21: goto L_8005BA24; break;
        default: switch_error(__func__, 0x8005B4D4, 0x80013790);
    }
    // nop

L_8005B4DC:
    // lhu         $v0, 0x1A8($s3)
    ctx->r2 = MEM_HU(0X1A8, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // blez        $a3, L_8005B598
    if (SIGNED(ctx->r7) <= 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8005B598;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_8005B500:
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // bne         $a0, $t1, L_8005B538
    if (ctx->r4 != ctx->r9) {
        // nop
    
        goto L_8005B538;
    }
    // nop

    // lw          $v0, 0x18C($s3)
    ctx->r2 = MEM_W(0X18C, ctx->r19);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $v0, 0x40($s2)
    ctx->r2 = MEM_HU(0X40, ctx->r18);
    // nop

    // bne         $v1, $v0, L_8005B560
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005B560;
    }
    // nop

L_8005B538:
    // bne         $a0, $t0, L_8005B588
    if (ctx->r4 != ctx->r8) {
        // nop
    
        goto L_8005B588;
    }
    // nop

    // lw          $v0, 0x18C($s3)
    ctx->r2 = MEM_W(0X18C, ctx->r19);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $v0, 0x3E($s2)
    ctx->r2 = MEM_HU(0X3E, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8005B588
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005B588;
    }
    // nop

L_8005B560:
    // lhu         $v1, 0x2C2($s3)
    ctx->r3 = MEM_HU(0X2C2, ctx->r19);
    // lw          $a0, 0x1B0($s3)
    ctx->r4 = MEM_W(0X1B0, ctx->r19);
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sh          $v0, 0x2C2($s3)
    MEM_H(0X2C2, ctx->r19) = ctx->r2;
    // lw          $v0, 0x18C($s3)
    ctx->r2 = MEM_W(0X18C, ctx->r19);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8005B588:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8005B500
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_8005B500;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_8005B598:
    // jal         0x80057CC8
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    sub_80057CC8(rdram, ctx);
    goto after_49;
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    after_49:
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // sb          $v0, 0x2C7($s3)
    MEM_B(0X2C7, ctx->r19) = ctx->r2;
    // j           L_8005BC78
    // addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    goto L_8005BC78;
    // addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_8005B5B0:
    // lhu         $v0, 0x1AA($s3)
    ctx->r2 = MEM_HU(0X1AA, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // blez        $a3, L_8005B66C
    if (SIGNED(ctx->r7) <= 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8005B66C;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $t1, $zero, 0x11
    ctx->r9 = ADD32(0, 0X11);
    // addiu       $t0, $zero, 0x12
    ctx->r8 = ADD32(0, 0X12);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_8005B5D4:
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // bne         $a0, $t1, L_8005B60C
    if (ctx->r4 != ctx->r9) {
        // nop
    
        goto L_8005B60C;
    }
    // nop

    // lw          $v0, 0x190($s3)
    ctx->r2 = MEM_W(0X190, ctx->r19);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $v0, 0x5A($s2)
    ctx->r2 = MEM_HU(0X5A, ctx->r18);
    // nop

    // bne         $v1, $v0, L_8005B634
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005B634;
    }
    // nop

L_8005B60C:
    // bne         $a0, $t0, L_8005B65C
    if (ctx->r4 != ctx->r8) {
        // nop
    
        goto L_8005B65C;
    }
    // nop

    // lw          $v0, 0x190($s3)
    ctx->r2 = MEM_W(0X190, ctx->r19);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $v0, 0x58($s2)
    ctx->r2 = MEM_HU(0X58, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8005B65C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005B65C;
    }
    // nop

L_8005B634:
    // lhu         $v1, 0x2C2($s3)
    ctx->r3 = MEM_HU(0X2C2, ctx->r19);
    // lw          $a0, 0x1B0($s3)
    ctx->r4 = MEM_W(0X1B0, ctx->r19);
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sh          $v0, 0x2C2($s3)
    MEM_H(0X2C2, ctx->r19) = ctx->r2;
    // lw          $v0, 0x190($s3)
    ctx->r2 = MEM_W(0X190, ctx->r19);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8005B65C:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8005B5D4
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_8005B5D4;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_8005B66C:
    // jal         0x80057CC8
    // addiu       $s6, $zero, 0xA6
    ctx->r22 = ADD32(0, 0XA6);
    sub_80057CC8(rdram, ctx);
    goto after_50;
    // addiu       $s6, $zero, 0xA6
    ctx->r22 = ADD32(0, 0XA6);
    after_50:
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // sb          $v0, 0x2C7($s3)
    MEM_B(0X2C7, ctx->r19) = ctx->r2;
    // j           L_8005BC78
    // addiu       $s7, $zero, 0x6
    ctx->r23 = ADD32(0, 0X6);
    goto L_8005BC78;
    // addiu       $s7, $zero, 0x6
    ctx->r23 = ADD32(0, 0X6);
L_8005B684:
    // lhu         $v0, 0x19C($s3)
    ctx->r2 = MEM_HU(0X19C, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // blez        $a3, L_8005B6D4
    if (SIGNED(ctx->r7) <= 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8005B6D4;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8005B69C:
    // sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5) << 1;
    // lhu         $v1, 0x2C2($s3)
    ctx->r3 = MEM_HU(0X2C2, ctx->r19);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sh          $v0, 0x2C2($s3)
    MEM_H(0X2C2, ctx->r19) = ctx->r2;
    // lw          $v0, 0x174($s3)
    ctx->r2 = MEM_W(0X174, ctx->r19);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lw          $v0, 0x1B0($s3)
    ctx->r2 = MEM_W(0X1B0, ctx->r19);
    // lhu         $a0, 0x0($a0)
    ctx->r4 = MEM_HU(0X0, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8005B69C
    if (ctx->r2 != 0) {
        // sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
        goto L_8005B69C;
    }
    // sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
L_8005B6D4:
    // jal         0x80057CC8
    // addiu       $s6, $zero, 0x48
    ctx->r22 = ADD32(0, 0X48);
    sub_80057CC8(rdram, ctx);
    goto after_51;
    // addiu       $s6, $zero, 0x48
    ctx->r22 = ADD32(0, 0X48);
    after_51:
    // sb          $zero, 0x2C7($s3)
    MEM_B(0X2C7, ctx->r19) = 0;
    // j           L_8005BC78
    // addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    goto L_8005BC78;
    // addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
L_8005B6E8:
    // lhu         $v0, 0x19E($s3)
    ctx->r2 = MEM_HU(0X19E, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // blez        $a3, L_8005B738
    if (SIGNED(ctx->r7) <= 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8005B738;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8005B700:
    // sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5) << 1;
    // lhu         $v1, 0x2C2($s3)
    ctx->r3 = MEM_HU(0X2C2, ctx->r19);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sh          $v0, 0x2C2($s3)
    MEM_H(0X2C2, ctx->r19) = ctx->r2;
    // lw          $v0, 0x178($s3)
    ctx->r2 = MEM_W(0X178, ctx->r19);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lw          $v0, 0x1B0($s3)
    ctx->r2 = MEM_W(0X1B0, ctx->r19);
    // lhu         $a0, 0x0($a0)
    ctx->r4 = MEM_HU(0X0, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8005B700
    if (ctx->r2 != 0) {
        // sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
        goto L_8005B700;
    }
    // sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
L_8005B738:
    // jal         0x80057CC8
    // addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    sub_80057CC8(rdram, ctx);
    goto after_52;
    // addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    after_52:
    // sb          $s5, 0x2C7($s3)
    MEM_B(0X2C7, ctx->r19) = ctx->r21;
    // j           L_8005BC78
    // addiu       $s6, $zero, 0x5D
    ctx->r22 = ADD32(0, 0X5D);
    goto L_8005BC78;
    // addiu       $s6, $zero, 0x5D
    ctx->r22 = ADD32(0, 0X5D);
L_8005B74C:
    // lhu         $v0, 0x1A0($s3)
    ctx->r2 = MEM_HU(0X1A0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // blez        $a3, L_8005B79C
    if (SIGNED(ctx->r7) <= 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8005B79C;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8005B764:
    // sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5) << 1;
    // lhu         $v1, 0x2C2($s3)
    ctx->r3 = MEM_HU(0X2C2, ctx->r19);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sh          $v0, 0x2C2($s3)
    MEM_H(0X2C2, ctx->r19) = ctx->r2;
    // lw          $v0, 0x17C($s3)
    ctx->r2 = MEM_W(0X17C, ctx->r19);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lw          $v0, 0x1B0($s3)
    ctx->r2 = MEM_W(0X1B0, ctx->r19);
    // lhu         $a0, 0x0($a0)
    ctx->r4 = MEM_HU(0X0, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8005B764
    if (ctx->r2 != 0) {
        // sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
        goto L_8005B764;
    }
    // sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
L_8005B79C:
    // jal         0x80057CC8
    // addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    sub_80057CC8(rdram, ctx);
    goto after_53;
    // addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    after_53:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0x2C7($s3)
    MEM_B(0X2C7, ctx->r19) = ctx->r2;
    // j           L_8005BC78
    // addiu       $s6, $zero, 0x7C
    ctx->r22 = ADD32(0, 0X7C);
    goto L_8005BC78;
    // addiu       $s6, $zero, 0x7C
    ctx->r22 = ADD32(0, 0X7C);
L_8005B7B4:
    // lhu         $v0, 0x1A2($s3)
    ctx->r2 = MEM_HU(0X1A2, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // blez        $a3, L_8005B804
    if (SIGNED(ctx->r7) <= 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8005B804;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8005B7CC:
    // sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5) << 1;
    // lhu         $v1, 0x2C2($s3)
    ctx->r3 = MEM_HU(0X2C2, ctx->r19);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sh          $v0, 0x2C2($s3)
    MEM_H(0X2C2, ctx->r19) = ctx->r2;
    // lw          $v0, 0x180($s3)
    ctx->r2 = MEM_W(0X180, ctx->r19);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lw          $v0, 0x1B0($s3)
    ctx->r2 = MEM_W(0X1B0, ctx->r19);
    // lhu         $a0, 0x0($a0)
    ctx->r4 = MEM_HU(0X0, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8005B7CC
    if (ctx->r2 != 0) {
        // sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
        goto L_8005B7CC;
    }
    // sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
L_8005B804:
    // jal         0x80057CC8
    // addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
    sub_80057CC8(rdram, ctx);
    goto after_54;
    // addiu       $s7, $zero, 0x5
    ctx->r23 = ADD32(0, 0X5);
    after_54:
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sb          $v0, 0x2C7($s3)
    MEM_B(0X2C7, ctx->r19) = ctx->r2;
    // j           L_8005BC78
    // addiu       $s6, $zero, 0x91
    ctx->r22 = ADD32(0, 0X91);
    goto L_8005BC78;
    // addiu       $s6, $zero, 0x91
    ctx->r22 = ADD32(0, 0X91);
L_8005B81C:
    // lhu         $v0, 0x1A4($s3)
    ctx->r2 = MEM_HU(0X1A4, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // blez        $a3, L_8005B8D4
    if (SIGNED(ctx->r7) <= 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8005B8D4;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $t0, $zero, 0xE
    ctx->r8 = ADD32(0, 0XE);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_8005B83C:
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // bne         $a0, $zero, L_8005B874
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8005B874;
    }
    // nop

    // lw          $v0, 0x184($s3)
    ctx->r2 = MEM_W(0X184, ctx->r19);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $v0, 0x52($s2)
    ctx->r2 = MEM_HU(0X52, ctx->r18);
    // nop

    // bne         $v1, $v0, L_8005B89C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005B89C;
    }
    // nop

L_8005B874:
    // bne         $a0, $t0, L_8005B8C4
    if (ctx->r4 != ctx->r8) {
        // nop
    
        goto L_8005B8C4;
    }
    // nop

    // lw          $v0, 0x184($s3)
    ctx->r2 = MEM_W(0X184, ctx->r19);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $v0, 0x38($s2)
    ctx->r2 = MEM_HU(0X38, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8005B8C4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005B8C4;
    }
    // nop

L_8005B89C:
    // lhu         $v1, 0x2C2($s3)
    ctx->r3 = MEM_HU(0X2C2, ctx->r19);
    // lw          $a0, 0x1B0($s3)
    ctx->r4 = MEM_W(0X1B0, ctx->r19);
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sh          $v0, 0x2C2($s3)
    MEM_H(0X2C2, ctx->r19) = ctx->r2;
    // lw          $v0, 0x184($s3)
    ctx->r2 = MEM_W(0X184, ctx->r19);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8005B8C4:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8005B83C
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_8005B83C;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_8005B8D4:
    // jal         0x80057CC8
    // addiu       $s7, $zero, 0x7
    ctx->r23 = ADD32(0, 0X7);
    sub_80057CC8(rdram, ctx);
    goto after_55;
    // addiu       $s7, $zero, 0x7
    ctx->r23 = ADD32(0, 0X7);
    after_55:
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // sb          $v0, 0x2C7($s3)
    MEM_B(0X2C7, ctx->r19) = ctx->r2;
    // j           L_8005BC78
    // addiu       $s6, $zero, 0xCA
    ctx->r22 = ADD32(0, 0XCA);
    goto L_8005BC78;
    // addiu       $s6, $zero, 0xCA
    ctx->r22 = ADD32(0, 0XCA);
L_8005B8EC:
    // lhu         $v0, 0x1AC($s3)
    ctx->r2 = MEM_HU(0X1AC, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // blez        $a3, L_8005B9A4
    if (SIGNED(ctx->r7) <= 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8005B9A4;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_8005B90C:
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // bne         $a0, $s5, L_8005B944
    if (ctx->r4 != ctx->r21) {
        // nop
    
        goto L_8005B944;
    }
    // nop

    // lw          $v0, 0x194($s3)
    ctx->r2 = MEM_W(0X194, ctx->r19);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $v0, 0x54($s2)
    ctx->r2 = MEM_HU(0X54, ctx->r18);
    // nop

    // bne         $v1, $v0, L_8005B96C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005B96C;
    }
    // nop

L_8005B944:
    // bne         $a0, $t0, L_8005B994
    if (ctx->r4 != ctx->r8) {
        // nop
    
        goto L_8005B994;
    }
    // nop

    // lw          $v0, 0x194($s3)
    ctx->r2 = MEM_W(0X194, ctx->r19);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $v0, 0x3A($s2)
    ctx->r2 = MEM_HU(0X3A, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8005B994
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005B994;
    }
    // nop

L_8005B96C:
    // lhu         $v1, 0x2C2($s3)
    ctx->r3 = MEM_HU(0X2C2, ctx->r19);
    // lw          $a0, 0x1B0($s3)
    ctx->r4 = MEM_W(0X1B0, ctx->r19);
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sh          $v0, 0x2C2($s3)
    MEM_H(0X2C2, ctx->r19) = ctx->r2;
    // lw          $v0, 0x194($s3)
    ctx->r2 = MEM_W(0X194, ctx->r19);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8005B994:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8005B90C
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_8005B90C;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_8005B9A4:
    // jal         0x80057CC8
    // addiu       $s7, $zero, 0x8
    ctx->r23 = ADD32(0, 0X8);
    sub_80057CC8(rdram, ctx);
    goto after_56;
    // addiu       $s7, $zero, 0x8
    ctx->r23 = ADD32(0, 0X8);
    after_56:
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // sb          $v0, 0x2C7($s3)
    MEM_B(0X2C7, ctx->r19) = ctx->r2;
    // j           L_8005BC78
    // addiu       $s6, $zero, 0xEE
    ctx->r22 = ADD32(0, 0XEE);
    goto L_8005BC78;
    // addiu       $s6, $zero, 0xEE
    ctx->r22 = ADD32(0, 0XEE);
L_8005B9BC:
    // lhu         $v0, 0x1A6($s3)
    ctx->r2 = MEM_HU(0X1A6, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // blez        $a3, L_8005BA0C
    if (SIGNED(ctx->r7) <= 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8005BA0C;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_8005B9D4:
    // sll         $a0, $a1, 1
    ctx->r4 = S32(ctx->r5) << 1;
    // lhu         $v1, 0x2C2($s3)
    ctx->r3 = MEM_HU(0X2C2, ctx->r19);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sh          $v0, 0x2C2($s3)
    MEM_H(0X2C2, ctx->r19) = ctx->r2;
    // lw          $v0, 0x188($s3)
    ctx->r2 = MEM_W(0X188, ctx->r19);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lw          $v0, 0x1B0($s3)
    ctx->r2 = MEM_W(0X1B0, ctx->r19);
    // lhu         $a0, 0x0($a0)
    ctx->r4 = MEM_HU(0X0, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8005B9D4
    if (ctx->r2 != 0) {
        // sh          $a0, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r4;
        goto L_8005B9D4;
    }
    // sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
L_8005BA0C:
    // jal         0x80057CC8
    // addiu       $s7, $zero, 0x9
    ctx->r23 = ADD32(0, 0X9);
    sub_80057CC8(rdram, ctx);
    goto after_57;
    // addiu       $s7, $zero, 0x9
    ctx->r23 = ADD32(0, 0X9);
    after_57:
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sb          $v0, 0x2C7($s3)
    MEM_B(0X2C7, ctx->r19) = ctx->r2;
    // j           L_8005BC78
    // addiu       $s6, $zero, 0x103
    ctx->r22 = ADD32(0, 0X103);
    goto L_8005BC78;
    // addiu       $s6, $zero, 0x103
    ctx->r22 = ADD32(0, 0X103);
L_8005BA24:
    // lhu         $v0, 0x1AE($s3)
    ctx->r2 = MEM_HU(0X1AE, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // blez        $a3, L_8005BBB4
    if (SIGNED(ctx->r7) <= 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8005BBB4;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_8005BA40:
    // lw          $v0, 0x198($s3)
    ctx->r2 = MEM_W(0X198, ctx->r19);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $v0, 0x42($s2)
    ctx->r2 = MEM_HU(0X42, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8005BAA0
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005BAA0;
    }
    // nop

    // lhu         $v0, 0x5E($s2)
    ctx->r2 = MEM_HU(0X5E, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8005BAA0
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005BAA0;
    }
    // nop

    // lhu         $v0, 0x4E($s2)
    ctx->r2 = MEM_HU(0X4E, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8005BAA0
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005BAA0;
    }
    // nop

    // lhu         $v0, 0x60($s2)
    ctx->r2 = MEM_HU(0X60, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8005BAA0
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005BAA0;
    }
    // nop

    // lhu         $v0, 0x5C($s2)
    ctx->r2 = MEM_HU(0X5C, ctx->r18);
    // nop

    // bne         $v1, $v0, L_8005BB7C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005BB7C;
    }
    // nop

L_8005BAA0:
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bne         $a0, $v0, L_8005BADC
    if (ctx->r4 != ctx->r2) {
        // addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
        goto L_8005BADC;
    }
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // lw          $v0, 0x198($s3)
    ctx->r2 = MEM_W(0X198, ctx->r19);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $v0, 0x42($s2)
    ctx->r2 = MEM_HU(0X42, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8005BB7C
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
        goto L_8005BB7C;
    }
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_8005BADC:
    // bne         $a0, $v0, L_8005BB04
    if (ctx->r4 != ctx->r2) {
        // addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
        goto L_8005BB04;
    }
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // lw          $v0, 0x198($s3)
    ctx->r2 = MEM_W(0X198, ctx->r19);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $v0, 0x5E($s2)
    ctx->r2 = MEM_HU(0X5E, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8005BB7C
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
        goto L_8005BB7C;
    }
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_8005BB04:
    // bne         $a0, $v0, L_8005BB2C
    if (ctx->r4 != ctx->r2) {
        // addiu       $v0, $zero, 0x15
        ctx->r2 = ADD32(0, 0X15);
        goto L_8005BB2C;
    }
    // addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    // lw          $v0, 0x198($s3)
    ctx->r2 = MEM_W(0X198, ctx->r19);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $v0, 0x4E($s2)
    ctx->r2 = MEM_HU(0X4E, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8005BB7C
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x15
        ctx->r2 = ADD32(0, 0X15);
        goto L_8005BB7C;
    }
    // addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_8005BB2C:
    // bne         $a0, $v0, L_8005BB54
    if (ctx->r4 != ctx->r2) {
        // addiu       $v0, $zero, 0x13
        ctx->r2 = ADD32(0, 0X13);
        goto L_8005BB54;
    }
    // addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // lw          $v0, 0x198($s3)
    ctx->r2 = MEM_W(0X198, ctx->r19);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $v0, 0x60($s2)
    ctx->r2 = MEM_HU(0X60, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8005BB7C
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x13
        ctx->r2 = ADD32(0, 0X13);
        goto L_8005BB7C;
    }
    // addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_8005BB54:
    // bne         $a0, $v0, L_8005BBA4
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_8005BBA4;
    }
    // nop

    // lw          $v0, 0x198($s3)
    ctx->r2 = MEM_W(0X198, ctx->r19);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $v0, 0x5C($s2)
    ctx->r2 = MEM_HU(0X5C, ctx->r18);
    // nop

    // bne         $v1, $v0, L_8005BBA4
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005BBA4;
    }
    // nop

L_8005BB7C:
    // lhu         $v1, 0x2C2($s3)
    ctx->r3 = MEM_HU(0X2C2, ctx->r19);
    // lw          $a0, 0x1B0($s3)
    ctx->r4 = MEM_W(0X1B0, ctx->r19);
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sh          $v0, 0x2C2($s3)
    MEM_H(0X2C2, ctx->r19) = ctx->r2;
    // lw          $v0, 0x198($s3)
    ctx->r2 = MEM_W(0X198, ctx->r19);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
L_8005BBA4:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8005BA40
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_8005BA40;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_8005BBB4:
    // jal         0x80057CC8
    // addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    sub_80057CC8(rdram, ctx);
    goto after_58;
    // addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    after_58:
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // sb          $v0, 0x2C7($s3)
    MEM_B(0X2C7, ctx->r19) = ctx->r2;
    // j           L_8005BC78
    // addiu       $s6, $zero, 0x113
    ctx->r22 = ADD32(0, 0X113);
    goto L_8005BC78;
    // addiu       $s6, $zero, 0x113
    ctx->r22 = ADD32(0, 0X113);
L_8005BBCC:
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // bne         $a0, $v0, L_8005BBFC
    if (ctx->r4 != ctx->r2) {
        // addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
        goto L_8005BBFC;
    }
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // lhu         $v1, 0x38($s2)
    ctx->r3 = MEM_HU(0X38, ctx->r18);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $v1, $v0, L_8005BC14
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005BC14;
    }
    // nop

    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_8005BBFC:
    // bne         $a0, $v0, L_8005BC24
    if (ctx->r4 != ctx->r2) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_8005BC24;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lhu         $v1, 0x52($s2)
    ctx->r3 = MEM_HU(0X52, ctx->r18);
    // nop

    // beq         $v1, $v0, L_8005BC24
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005BC24;
    }
    // nop

L_8005BC14:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_59;
    // nop

    after_59:
    // j           L_8005BC34
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    goto L_8005BC34;
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_8005BC24:
    // jal         0x80057D34
    // nop

    sub_80057D34(rdram, ctx);
    goto after_60;
    // nop

    after_60:
    // j           L_8005C6DC
    // sh          $s5, 0x2DC($s3)
    MEM_H(0X2DC, ctx->r19) = ctx->r21;
    goto L_8005C6DC;
    // sh          $s5, 0x2DC($s3)
    MEM_H(0X2DC, ctx->r19) = ctx->r21;
L_8005BC34:
    // sb          $v0, 0x2C7($s3)
    MEM_B(0X2C7, ctx->r19) = ctx->r2;
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $s0, $v0, L_8005BC4C
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_8005BC4C;
    }
    // nop

    // j           L_8005BC50
    // sh          $zero, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = 0;
    goto L_8005BC50;
    // sh          $zero, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = 0;
L_8005BC4C:
    // sh          $s0, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r16;
L_8005BC50:
    // addiu       $s7, $zero, 0x3D1
    ctx->r23 = ADD32(0, 0X3D1);
    // addiu       $s6, $zero, 0x3D0
    ctx->r22 = ADD32(0, 0X3D0);
    // lhu         $v0, 0x2BE($s3)
    ctx->r2 = MEM_HU(0X2BE, ctx->r19);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // jal         0x8005A3A8
    // sh          $v0, 0x2C0($s3)
    MEM_H(0X2C0, ctx->r19) = ctx->r2;
    sub_8005A3A8(rdram, ctx);
    goto after_61;
    // sh          $v0, 0x2C0($s3)
    MEM_H(0X2C0, ctx->r19) = ctx->r2;
    after_61:
    // j           L_8005BC78
    // nop

    goto L_8005BC78;
    // nop

L_8005BC70:
    // addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // addu        $s6, $s7, $zero
    ctx->r22 = ADD32(ctx->r23, 0);
L_8005BC78:
    // lbu         $v1, 0x2C7($s3)
    ctx->r3 = MEM_BU(0X2C7, ctx->r19);
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // bne         $v1, $v0, L_8005BD2C
    if (ctx->r3 != ctx->r2) {
        // andi        $a0, $s0, 0xFFFF
        ctx->r4 = ctx->r16 & 0XFFFF;
        goto L_8005BD2C;
    }
    // andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // addiu       $v1, $zero, 0x280
    ctx->r3 = ADD32(0, 0X280);
    // sh          $v1, 0x358($s3)
    MEM_H(0X358, ctx->r19) = ctx->r3;
    // addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_8005BCB4
    if (ctx->r2 != ctx->r3) {
        // sh          $zero, 0x35A($s3)
        MEM_H(0X35A, ctx->r19) = 0;
        goto L_8005BCB4;
    }
    // sh          $zero, 0x35A($s3)
    MEM_H(0X35A, ctx->r19) = 0;
    // lhu         $v0, 0x38($s2)
    ctx->r2 = MEM_HU(0X38, ctx->r18);
    // j           L_8005BCB8
    // nop

    goto L_8005BCB8;
    // nop

L_8005BCB4:
    // lhu         $v0, 0x52($s2)
    ctx->r2 = MEM_HU(0X52, ctx->r18);
L_8005BCB8:
    // lw          $v1, 0x2D0($s3)
    ctx->r3 = MEM_W(0X2D0, ctx->r19);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v0, $v0, -0x310
    ctx->r2 = ADD32(ctx->r2, -0X310);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x2D4($s3)
    MEM_W(0X2D4, ctx->r19) = ctx->r3;
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // addiu       $a1, $zero, 0x3CF
    ctx->r5 = ADD32(0, 0X3CF);
    // lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // addiu       $s0, $s0, -0x7378
    ctx->r16 = ADD32(ctx->r16, -0X7378);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_62;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_62:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s3, 0x358
    ctx->r5 = ADD32(ctx->r19, 0X358);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_63;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_63:
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // lhu         $a1, 0x2BE($s3)
    ctx->r5 = MEM_HU(0X2BE, ctx->r19);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addiu       $a1, $a1, 0x3E3
    ctx->r5 = ADD32(ctx->r5, 0X3E3);
    // jal         0x80016030
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_80016030(rdram, ctx);
    goto after_64;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_64:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // addiu       $a2, $s3, 0x4
    ctx->r6 = ADD32(ctx->r19, 0X4);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_65;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_65:
    // j           L_8005C0E0
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    goto L_8005C0E0;
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
L_8005BD2C:
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $a0, $v0, L_8005BD48
    if (ctx->r4 != ctx->r2) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8005BD48;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // j           L_8005BD88
    // sh          $v0, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r2;
    goto L_8005BD88;
    // sh          $v0, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r2;
L_8005BD40:
    // j           L_8005BD88
    // sh          $a2, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r6;
    goto L_8005BD88;
    // sh          $a2, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r6;
L_8005BD48:
    // lhu         $v1, 0x2C2($s3)
    ctx->r3 = MEM_HU(0X2C2, ctx->r19);
    // nop

    // beq         $v1, $zero, L_8005BD88
    if (ctx->r3 == 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_8005BD88;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // lw          $v0, 0x1B0($s3)
    ctx->r2 = MEM_W(0X1B0, ctx->r19);
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8005BD68:
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_HS(0X0, ctx->r3);
    // nop

    // beq         $v0, $a1, L_8005BD40
    if (ctx->r2 == ctx->r5) {
        // nop
    
        goto L_8005BD40;
    }
    // nop

    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slt         $v0, $a2, $a0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_8005BD68
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
        goto L_8005BD68;
    }
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8005BD88:
    // lhu         $v0, 0x2BE($s3)
    ctx->r2 = MEM_HU(0X2BE, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $a0, $v0, L_8005BDB0
    if (ctx->r4 != ctx->r2) {
        // sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4) << 1;
        goto L_8005BDB0;
    }
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // sh          $a0, 0x2C0($s3)
    MEM_H(0X2C0, ctx->r19) = ctx->r4;
    // j           L_8005BDD4
    // addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
    goto L_8005BDD4;
    // addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
L_8005BDB0:
    // lw          $v1, 0x1B0($s3)
    ctx->r3 = MEM_W(0X1B0, ctx->r19);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(0X0, ctx->r2);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // sh          $v1, 0x2C0($s3)
    MEM_H(0X2C0, ctx->r19) = ctx->r3;
L_8005BDD4:
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // sll         $s0, $v0, 1
    ctx->r16 = S32(ctx->r2) << 1;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // addiu       $s1, $s1, -0x7378
    ctx->r17 = ADD32(ctx->r17, -0X7378);
    // jal         0x80016030
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sub_80016030(rdram, ctx);
    goto after_66;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_66:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // addiu       $a2, $s3, 0x4
    ctx->r6 = ADD32(ctx->r19, 0X4);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_67;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_67:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_68;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_68:
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // jal         0x80016030
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sub_80016030(rdram, ctx);
    goto after_69;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_69:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_70;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_70:
    // jal         0x8005A3A8
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8005A3A8(rdram, ctx);
    goto after_71;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_71:
    // j           L_8005C0E0
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    goto L_8005C0E0;
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
L_8005BE48:
    // lhu         $v1, 0xC($s4)
    ctx->r3 = MEM_HU(0XC, ctx->r20);
    // nop

    // andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // beq         $v0, $zero, L_8005BEFC
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x80
        ctx->r2 = ctx->r3 & 0X80;
        goto L_8005BEFC;
    }
    // andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // sltiu       $v0, $v1, 0x16
    ctx->r2 = ctx->r3 < 0X16 ? 1 : 0;
    // beq         $v0, $zero, L_8005BED8
    if (ctx->r2 == 0) {
        // addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
        goto L_8005BED8;
    }
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x37E8
    ctx->r2 = ADD32(ctx->r2, 0X37E8);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_8005BE90;
    jr_addend_8005BE90 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8005BE90 >> 2) {
        case 0: goto L_8005BE98; break;
        case 1: goto L_8005BED8; break;
        case 2: goto L_8005BED8; break;
        case 3: goto L_8005BED8; break;
        case 4: goto L_8005BED8; break;
        case 5: goto L_8005BEB8; break;
        case 6: goto L_8005BEA0; break;
        case 7: goto L_8005BEA8; break;
        case 8: goto L_8005BED8; break;
        case 9: goto L_8005BED8; break;
        case 10: goto L_8005BED8; break;
        case 11: goto L_8005BED8; break;
        case 12: goto L_8005BEC8; break;
        case 13: goto L_8005BEB0; break;
        case 14: goto L_8005BED8; break;
        case 15: goto L_8005BED8; break;
        case 16: goto L_8005BED8; break;
        case 17: goto L_8005BED8; break;
        case 18: goto L_8005BED8; break;
        case 19: goto L_8005BED8; break;
        case 20: goto L_8005BEC0; break;
        case 21: goto L_8005BED0; break;
        default: switch_error(__func__, 0x8005BE90, 0x800137E8);
    }
    // nop

L_8005BE98:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8005BEA0:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_8005BEA8:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_8005BEB0:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_8005BEB8:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_8005BEC0:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_8005BEC8:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_8005BED0:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_8005BED8:
    // lhu         $v1, 0x2E0($s3)
    ctx->r3 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0xE
    ctx->r2 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
    // beq         $v0, $zero, L_8005C0D4
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x7
        ctx->r2 = ADD32(ctx->r3, 0X7);
        goto L_8005C0D4;
    }
    // addiu       $v0, $v1, 0x7
    ctx->r2 = ADD32(ctx->r3, 0X7);
    // j           L_8005C0D4
    // sh          $v0, 0x2E0($s3)
    MEM_H(0X2E0, ctx->r19) = ctx->r2;
    goto L_8005C0D4;
    // sh          $v0, 0x2E0($s3)
    MEM_H(0X2E0, ctx->r19) = ctx->r2;
L_8005BEFC:
    // beq         $v0, $zero, L_8005BFA8
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x40
        ctx->r2 = ctx->r3 & 0X40;
        goto L_8005BFA8;
    }
    // andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // addiu       $v0, $v0, -0x6
    ctx->r2 = ADD32(ctx->r2, -0X6);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // sltiu       $v0, $v1, 0x10
    ctx->r2 = ctx->r3 < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_8005BF84
    if (ctx->r2 == 0) {
        // addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
        goto L_8005BF84;
    }
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x3840
    ctx->r2 = ADD32(ctx->r2, 0X3840);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_8005BF3C;
    jr_addend_8005BF3C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8005BF3C >> 2) {
        case 0: goto L_8005BF5C; break;
        case 1: goto L_8005BF54; break;
        case 2: goto L_8005BF84; break;
        case 3: goto L_8005BF84; break;
        case 4: goto L_8005BF84; break;
        case 5: goto L_8005BF84; break;
        case 6: goto L_8005BF74; break;
        case 7: goto L_8005BF4C; break;
        case 8: goto L_8005BF44; break;
        case 9: goto L_8005BF84; break;
        case 10: goto L_8005BF84; break;
        case 11: goto L_8005BF84; break;
        case 12: goto L_8005BF84; break;
        case 13: goto L_8005BF64; break;
        case 14: goto L_8005BF7C; break;
        case 15: goto L_8005BF6C; break;
        default: switch_error(__func__, 0x8005BF3C, 0x80013840);
    }
    // nop

L_8005BF44:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_8005BF4C:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_8005BF54:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_8005BF5C:
    // j           L_8005C0D4
    // sh          $zero, 0x2E0($s3)
    MEM_H(0X2E0, ctx->r19) = 0;
    goto L_8005C0D4;
    // sh          $zero, 0x2E0($s3)
    MEM_H(0X2E0, ctx->r19) = 0;
L_8005BF64:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_8005BF6C:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_8005BF74:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_8005BF7C:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8005BF84:
    // lhu         $v1, 0x2E0($s3)
    ctx->r3 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_8005C0D4
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, -0x7
        ctx->r2 = ADD32(ctx->r3, -0X7);
        goto L_8005C0D4;
    }
    // addiu       $v0, $v1, -0x7
    ctx->r2 = ADD32(ctx->r3, -0X7);
    // j           L_8005C0D4
    // sh          $v0, 0x2E0($s3)
    MEM_H(0X2E0, ctx->r19) = ctx->r2;
    goto L_8005C0D4;
    // sh          $v0, 0x2E0($s3)
    MEM_H(0X2E0, ctx->r19) = ctx->r2;
L_8005BFA8:
    // beq         $v0, $zero, L_8005C050
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x10
        ctx->r2 = ctx->r3 & 0X10;
        goto L_8005C050;
    }
    // andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // beq         $v1, $v0, L_8005BFFC
    if (ctx->r3 == ctx->r2) {
        // addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
        goto L_8005BFFC;
    }
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_8005BFE8
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
        goto L_8005BFE8;
    }
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // beq         $v1, $v0, L_8005C004
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005C004;
    }
    // nop

    // j           L_8005C00C
    // nop

    goto L_8005C00C;
    // nop

L_8005BFE8:
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // beq         $v1, $v0, L_8005C0D0
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
        goto L_8005C0D0;
    }
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // j           L_8005C00C
    // nop

    goto L_8005C00C;
    // nop

L_8005BFFC:
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_8005C004:
    // j           L_8005C0D4
    // sh          $fp, 0x2E0($s3)
    MEM_H(0X2E0, ctx->r19) = ctx->r30;
    goto L_8005C0D4;
    // sh          $fp, 0x2E0($s3)
    MEM_H(0X2E0, ctx->r19) = ctx->r30;
L_8005C00C:
    // lhu         $a0, 0x2E0($s3)
    ctx->r4 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // beq         $v1, $v0, L_8005C0D4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x14
        ctx->r2 = ADD32(0, 0X14);
        goto L_8005C0D4;
    }
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // beq         $v1, $v0, L_8005C0D4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
        goto L_8005C0D4;
    }
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // beq         $v1, $v0, L_8005C0D4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x15
        ctx->r2 = ADD32(0, 0X15);
        goto L_8005C0D4;
    }
    // addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
    // beq         $v1, $v0, L_8005C0D4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x13
        ctx->r2 = ADD32(0, 0X13);
        goto L_8005C0D4;
    }
    // addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
    // beq         $v1, $v0, L_8005C0D4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
        goto L_8005C0D4;
    }
    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // j           L_8005C0D4
    // sh          $v0, 0x2E0($s3)
    MEM_H(0X2E0, ctx->r19) = ctx->r2;
    goto L_8005C0D4;
    // sh          $v0, 0x2E0($s3)
    MEM_H(0X2E0, ctx->r19) = ctx->r2;
L_8005C050:
    // beq         $v0, $zero, L_8005C0DC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005C0DC;
    }
    // nop

    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // bne         $v1, $v0, L_8005C07C
    if (ctx->r3 != ctx->r2) {
        // addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
        goto L_8005C07C;
    }
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // j           L_8005C0D0
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    goto L_8005C0D0;
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_8005C07C:
    // slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // bne         $v0, $zero, L_8005C098
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, 0x16
        ctx->r2 = SIGNED(ctx->r3) < 0X16 ? 1 : 0;
        goto L_8005C098;
    }
    // slti        $v0, $v1, 0x16
    ctx->r2 = SIGNED(ctx->r3) < 0X16 ? 1 : 0;
    // beq         $v0, $zero, L_8005C098
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x14
        ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
        goto L_8005C098;
    }
    // slti        $v0, $v1, 0x14
    ctx->r2 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // beq         $v0, $zero, L_8005C0D0
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
        goto L_8005C0D0;
    }
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_8005C098:
    // lhu         $a0, 0x2E0($s3)
    ctx->r4 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // beq         $v1, $zero, L_8005C0D4
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
        goto L_8005C0D4;
    }
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // beq         $v1, $v0, L_8005C0D4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
        goto L_8005C0D4;
    }
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // beq         $v1, $v0, L_8005C0D4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
        goto L_8005C0D4;
    }
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // beq         $v1, $v0, L_8005C0D4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xE
        ctx->r2 = ADD32(0, 0XE);
        goto L_8005C0D4;
    }
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // beq         $v1, $v0, L_8005C0D4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $a0, -0x1
        ctx->r2 = ADD32(ctx->r4, -0X1);
        goto L_8005C0D4;
    }
    // addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
L_8005C0D0:
    // sh          $v0, 0x2E0($s3)
    MEM_H(0X2E0, ctx->r19) = ctx->r2;
L_8005C0D4:
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
    // sb          $zero, 0x2E4($s3)
    MEM_B(0X2E4, ctx->r19) = 0;
L_8005C0DC:
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
L_8005C0E0:
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(0XB0, ctx->r29);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // beq         $v0, $t2, L_8005C6DC
    if (ctx->r2 == ctx->r10) {
        // nop
    
        goto L_8005C6DC;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_72;
    // nop

    after_72:
    // lhu         $v0, 0x2E0($s3)
    ctx->r2 = MEM_HU(0X2E0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // j           L_8005C6DC
    // sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    goto L_8005C6DC;
    // sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
L_8005C118:
    // lbu         $v1, 0x2C7($s3)
    ctx->r3 = MEM_BU(0X2C7, ctx->r19);
    // nop

    // beq         $v1, $v0, L_8005C3A8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005C3A8;
    }
    // nop

    // lhu         $v0, 0x4($s4)
    ctx->r2 = MEM_HU(0X4, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // beq         $v0, $zero, L_8005C21C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005C21C;
    }
    // nop

    // lhu         $v0, 0x2C0($s3)
    ctx->r2 = MEM_HU(0X2C0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a0, $v0, L_8005C1B4
    if (ctx->r4 == ctx->r2) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_8005C1B4;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x76F8
    ctx->r2 = ADD32(ctx->r2, 0X76F8);
    // sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4) << 1;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x13F($v1)
    ctx->r2 = MEM_BU(0X13F, ctx->r3);
    // nop

    // beq         $v0, $zero, L_8005C1B4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005C1B4;
    }
    // nop

    // lbu         $v0, 0x140($v1)
    ctx->r2 = MEM_BU(0X140, ctx->r3);
    // nop

    // bne         $v0, $zero, L_8005C1B4
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_8005C1B4;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // lbu         $v1, 0x13E($v1)
    ctx->r3 = MEM_BU(0X13E, ctx->r3);
    // nop

    // beq         $v1, $v0, L_8005C1B4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005C1B4;
    }
    // nop

    // jal         0x80057D34
    // nop

    sub_80057D34(rdram, ctx);
    goto after_73;
    // nop

    after_73:
    // j           L_8005C2F4
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    goto L_8005C2F4;
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
L_8005C1B4:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_74;
    // nop

    after_74:
    // jal         0x8005975C
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sub_8005975C(rdram, ctx);
    goto after_75;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_75:
    // jal         0x8005A3A8
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8005A3A8(rdram, ctx);
    goto after_76;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_76:
    // lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // lhu         $v0, 0x2D8($s3)
    ctx->r2 = MEM_HU(0X2D8, ctx->r19);
    // lhu         $v1, -0x70D8($t2)
    ctx->r3 = MEM_HU(-0X70D8, ctx->r10);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8005C1F0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005C1F0;
    }
    // nop

    // sh          $v1, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r3;
L_8005C1F0:
    // lhu         $v0, 0x2DA($s3)
    ctx->r2 = MEM_HU(0X2DA, ctx->r19);
    // lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(0X4, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8005C210
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005C210;
    }
    // nop

    // sh          $v1, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r3;
L_8005C210:
    // sh          $s5, 0x2DC($s3)
    MEM_H(0X2DC, ctx->r19) = ctx->r21;
    // j           L_8005C2F4
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    goto L_8005C2F4;
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
L_8005C21C:
    // lhu         $v1, 0xC($s4)
    ctx->r3 = MEM_HU(0XC, ctx->r20);
    // nop

    // andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // beq         $v0, $zero, L_8005C284
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x80
        ctx->r2 = ctx->r3 & 0X80;
        goto L_8005C284;
    }
    // andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_77;
    // nop

    after_77:
    // lhu         $a0, 0x2BE($s3)
    ctx->r4 = MEM_HU(0X2BE, ctx->r19);
    // lhu         $v0, 0x2C2($s3)
    ctx->r2 = MEM_HU(0X2C2, ctx->r19);
    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8005C278
    if (ctx->r3 == 0) {
        // addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
        goto L_8005C278;
    }
    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // sh          $v0, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lw          $v1, 0x1B0($s3)
    ctx->r3 = MEM_W(0X1B0, ctx->r19);
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // j           L_8005C2F4
    // sh          $v0, 0x2C0($s3)
    MEM_H(0X2C0, ctx->r19) = ctx->r2;
    goto L_8005C2F4;
    // sh          $v0, 0x2C0($s3)
    MEM_H(0X2C0, ctx->r19) = ctx->r2;
L_8005C278:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // j           L_8005C2EC
    // sh          $v0, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r2;
    goto L_8005C2EC;
    // sh          $v0, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r2;
L_8005C284:
    // beq         $v0, $zero, L_8005C2F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005C2F4;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_78;
    // nop

    after_78:
    // lhu         $v1, 0x2BE($s3)
    ctx->r3 = MEM_HU(0X2BE, ctx->r19);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // bgez        $v0, L_8005C2B4
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8005C2B4;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // lhu         $v0, 0x2C2($s3)
    ctx->r2 = MEM_HU(0X2C2, ctx->r19);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8005C2B4:
    // sh          $v0, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x2BE($s3)
    ctx->r2 = MEM_HU(0X2BE, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_8005C2DC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005C2DC;
    }
    // nop

    // j           L_8005C2F4
    // sh          $v1, 0x2C0($s3)
    MEM_H(0X2C0, ctx->r19) = ctx->r3;
    goto L_8005C2F4;
    // sh          $v1, 0x2C0($s3)
    MEM_H(0X2C0, ctx->r19) = ctx->r3;
L_8005C2DC:
    // lw          $v0, 0x1B0($s3)
    ctx->r2 = MEM_W(0X1B0, ctx->r19);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
L_8005C2EC:
    // nop

    // sh          $v0, 0x2C0($s3)
    MEM_H(0X2C0, ctx->r19) = ctx->r2;
L_8005C2F4:
    // lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(0XC, ctx->r20);
    // nop

    // andi        $v0, $v0, 0xA0
    ctx->r2 = ctx->r2 & 0XA0;
    // beq         $v0, $zero, L_8005C664
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8005C664;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lhu         $v1, 0x2BE($s3)
    ctx->r3 = MEM_HU(0X2BE, ctx->r19);
    // nop

    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // bne         $v1, $v0, L_8005C328
    if (ctx->r3 != ctx->r2) {
        // addiu       $fp, $zero, 0x3
        ctx->r30 = ADD32(0, 0X3);
        goto L_8005C328;
    }
    // addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // j           L_8005C33C
    // addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
    goto L_8005C33C;
    // addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
L_8005C328:
    // lhu         $v0, 0x2C0($s3)
    ctx->r2 = MEM_HU(0X2C0, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
L_8005C33C:
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // sll         $s0, $v0, 1
    ctx->r16 = S32(ctx->r2) << 1;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // lui         $s1, 0x8009
    ctx->r17 = S32(0X8009 << 16);
    // addiu       $s1, $s1, -0x7378
    ctx->r17 = ADD32(ctx->r17, -0X7378);
    // jal         0x80016030
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sub_80016030(rdram, ctx);
    goto after_79;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_79:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // addiu       $a2, $s3, 0x4
    ctx->r6 = ADD32(ctx->r19, 0X4);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_80;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_80:
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // jal         0x80016030
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    sub_80016030(rdram, ctx);
    goto after_81;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_81:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_82;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_82:
    // jal         0x8005A3A8
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sub_8005A3A8(rdram, ctx);
    goto after_83;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_83:
    // j           L_8005C664
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
    goto L_8005C664;
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
L_8005C3A8:
    // lhu         $v0, 0x2BE($s3)
    ctx->r2 = MEM_HU(0X2BE, ctx->r19);
    // lhu         $v1, 0xC($s4)
    ctx->r3 = MEM_HU(0XC, ctx->r20);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2) >> 16;
    // andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // beq         $v0, $zero, L_8005C3F4
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x80
        ctx->r2 = ctx->r3 & 0X80;
        goto L_8005C3F4;
    }
    // andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // jal         0x80057D10
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    sub_80057D10(rdram, ctx);
    goto after_84;
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    after_84:
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
    // lhu         $v1, 0x2BE($s3)
    ctx->r3 = MEM_HU(0X2BE, ctx->r19);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0xF
    ctx->r2 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // beq         $v0, $zero, L_8005C610
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x3
        ctx->r2 = ADD32(ctx->r3, 0X3);
        goto L_8005C610;
    }
    // addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // j           L_8005C610
    // sh          $v0, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r2;
    goto L_8005C610;
    // sh          $v0, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r2;
L_8005C3F4:
    // beq         $v0, $zero, L_8005C42C
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x10
        ctx->r2 = ctx->r3 & 0X10;
        goto L_8005C42C;
    }
    // andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // jal         0x80057D10
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    sub_80057D10(rdram, ctx);
    goto after_85;
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    after_85:
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
    // lhu         $v1, 0x2BE($s3)
    ctx->r3 = MEM_HU(0X2BE, ctx->r19);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8005C610
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, -0x3
        ctx->r2 = ADD32(ctx->r3, -0X3);
        goto L_8005C610;
    }
    // addiu       $v0, $v1, -0x3
    ctx->r2 = ADD32(ctx->r3, -0X3);
    // j           L_8005C610
    // sh          $v0, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r2;
    goto L_8005C610;
    // sh          $v0, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r2;
L_8005C42C:
    // beq         $v0, $zero, L_8005C484
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x40
        ctx->r2 = ctx->r3 & 0X40;
        goto L_8005C484;
    }
    // andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // jal         0x80057D10
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    sub_80057D10(rdram, ctx);
    goto after_86;
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    after_86:
    // lui         $v0, 0x5555
    ctx->r2 = S32(0X5555 << 16);
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
    // lhu         $a1, 0x2BE($s3)
    ctx->r5 = MEM_HU(0X2BE, ctx->r19);
    // ori         $v0, $v0, 0x5556
    ctx->r2 = ctx->r2 | 0X5556;
    // sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5) << 16;
    // sra         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3) >> 16;
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // subu        $v1, $t2, $v1
    ctx->r3 = SUB32(ctx->r10, ctx->r3);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // beq         $a0, $zero, L_8005C614
    if (ctx->r4 == 0) {
        // addiu       $v0, $a1, -0x1
        ctx->r2 = ADD32(ctx->r5, -0X1);
        goto L_8005C614;
    }
    // addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // j           L_8005C610
    // sh          $v0, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r2;
    goto L_8005C610;
    // sh          $v0, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r2;
L_8005C484:
    // beq         $v0, $zero, L_8005C4E0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005C4E0;
    }
    // nop

    // jal         0x80057D10
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    sub_80057D10(rdram, ctx);
    goto after_87;
    // addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    after_87:
    // lui         $v0, 0x5555
    ctx->r2 = S32(0X5555 << 16);
    // sh          $zero, 0xC($s4)
    MEM_H(0XC, ctx->r20) = 0;
    // lhu         $a1, 0x2BE($s3)
    ctx->r5 = MEM_HU(0X2BE, ctx->r19);
    // ori         $v0, $v0, 0x5556
    ctx->r2 = ctx->r2 | 0X5556;
    // sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5) << 16;
    // sra         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3) >> 16;
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // subu        $v1, $t2, $v1
    ctx->r3 = SUB32(ctx->r10, ctx->r3);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // beq         $a0, $fp, L_8005C614
    if (ctx->r4 == ctx->r30) {
        // addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
        goto L_8005C614;
    }
    // addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // j           L_8005C610
    // sh          $v0, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r2;
    goto L_8005C610;
    // sh          $v0, 0x2BE($s3)
    MEM_H(0X2BE, ctx->r19) = ctx->r2;
L_8005C4E0:
    // lhu         $v0, 0x4($s4)
    ctx->r2 = MEM_HU(0X4, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // beq         $v0, $zero, L_8005C610
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005C610;
    }
    // nop

    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    // lw          $v0, 0x2D4($s3)
    ctx->r2 = MEM_W(0X2D4, ctx->r19);
    // lhu         $v1, 0x2BE($s3)
    ctx->r3 = MEM_HU(0X2BE, ctx->r19);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // sllv        $v1, $s5, $v1
    ctx->r3 = S32(ctx->r21) << (ctx->r3 & 31);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8005C608
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005C608;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_88;
    // nop

    after_88:
    // lui         $a2, 0x5555
    ctx->r6 = S32(0X5555 << 16);
    // lhu         $v1, 0x2BE($s3)
    ctx->r3 = MEM_HU(0X2BE, ctx->r19);
    // ori         $a2, $a2, 0x5556
    ctx->r6 = ctx->r6 | 0X5556;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) >> 16;
    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $a0, 0x2BE($s3)
    ctx->r4 = MEM_HU(0X2BE, ctx->r19);
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4) >> 16;
    // sh          $v0, 0x340($s3)
    MEM_H(0X340, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $t0
    ctx->r8 = hi;
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // sh          $v0, 0x342($s3)
    MEM_H(0X342, ctx->r19) = ctx->r2;
    // mult        $a1, $a2
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // subu        $v1, $t0, $v1
    ctx->r3 = SUB32(ctx->r8, ctx->r3);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // lhu         $v1, 0x2E0($s3)
    ctx->r3 = MEM_HU(0X2E0, ctx->r19);
    // addiu       $v0, $v0, 0x280
    ctx->r2 = ADD32(ctx->r2, 0X280);
    // sh          $v0, 0x33C($s3)
    MEM_H(0X33C, ctx->r19) = ctx->r2;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // mfhi        $a2
    ctx->r6 = hi;
    // subu        $a0, $a2, $a0
    ctx->r4 = SUB32(ctx->r6, ctx->r4);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sh          $v0, 0x33E($s3)
    MEM_H(0X33E, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // bne         $v1, $v0, L_8005C5DC
    if (ctx->r3 != ctx->r2) {
        // addiu       $a1, $zero, 0x314
        ctx->r5 = ADD32(0, 0X314);
        goto L_8005C5DC;
    }
    // addiu       $a1, $zero, 0x314
    ctx->r5 = ADD32(0, 0X314);
    // addiu       $a0, $s3, 0x33C
    ctx->r4 = ADD32(ctx->r19, 0X33C);
    // addiu       $a1, $zero, 0x2E4
    ctx->r5 = ADD32(0, 0X2E4);
    // lhu         $v0, 0x2BE($s3)
    ctx->r2 = MEM_HU(0X2BE, ctx->r19);
    // addiu       $a2, $zero, 0x7C
    ctx->r6 = ADD32(0, 0X7C);
    // j           L_8005C5EC
    // sh          $v0, 0x44($s2)
    MEM_H(0X44, ctx->r18) = ctx->r2;
    goto L_8005C5EC;
    // sh          $v0, 0x44($s2)
    MEM_H(0X44, ctx->r18) = ctx->r2;
L_8005C5DC:
    // addiu       $a0, $s3, 0x33C
    ctx->r4 = ADD32(ctx->r19, 0X33C);
    // lhu         $v0, 0x2BE($s3)
    ctx->r2 = MEM_HU(0X2BE, ctx->r19);
    // addiu       $a2, $zero, 0x7C
    ctx->r6 = ADD32(0, 0X7C);
    // sh          $v0, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r2;
L_8005C5EC:
    // jal         0x80079DCC
    // nop

    MoveImage(rdram, ctx);
    goto after_89;
    // nop

    after_89:
    // sh          $s5, 0x2DC($s3)
    MEM_H(0X2DC, ctx->r19) = ctx->r21;
    // jal         0x8005A3A8
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8005A3A8(rdram, ctx);
    goto after_90;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_90:
    // j           L_8005C610
    // nop

    goto L_8005C610;
    // nop

L_8005C608:
    // jal         0x80057D34
    // nop

    sub_80057D34(rdram, ctx);
    goto after_91;
    // nop

    after_91:
L_8005C610:
    // lhu         $a1, 0x2BE($s3)
    ctx->r5 = MEM_HU(0X2BE, ctx->r19);
L_8005C614:
    // nop

    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // beq         $s0, $v0, L_8005C664
    if (ctx->r16 == ctx->r2) {
        // addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
        goto L_8005C664;
    }
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // addiu       $a1, $a1, 0x3E3
    ctx->r5 = ADD32(ctx->r5, 0X3E3);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // addiu       $s0, $s0, -0x7378
    ctx->r16 = ADD32(ctx->r16, -0X7378);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_92;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_92:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // addiu       $a2, $s3, 0x4
    ctx->r6 = ADD32(ctx->r19, 0X4);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_93;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_93:
    // lhu         $v0, 0x2BE($s3)
    ctx->r2 = MEM_HU(0X2BE, ctx->r19);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // jal         0x8005A3A8
    // sh          $v0, 0x2C0($s3)
    MEM_H(0X2C0, ctx->r19) = ctx->r2;
    sub_8005A3A8(rdram, ctx);
    goto after_94;
    // sh          $v0, 0x2C0($s3)
    MEM_H(0X2C0, ctx->r19) = ctx->r2;
    after_94:
L_8005C664:
    // lhu         $v0, 0x4($s4)
    ctx->r2 = MEM_HU(0X4, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // beq         $v0, $zero, L_8005C694
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
        goto L_8005C694;
    }
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_95;
    // nop

    after_95:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x8005A3A8
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    sub_8005A3A8(rdram, ctx);
    goto after_96;
    // sh          $zero, 0x4($s4)
    MEM_H(0X4, ctx->r20) = 0;
    after_96:
    // j           L_8005C6DC
    // sh          $s5, 0x2DC($s3)
    MEM_H(0X2DC, ctx->r19) = ctx->r21;
    goto L_8005C6DC;
    // sh          $s5, 0x2DC($s3)
    MEM_H(0X2DC, ctx->r19) = ctx->r21;
L_8005C694:
    // lbu         $v1, 0x2C7($s3)
    ctx->r3 = MEM_BU(0X2C7, ctx->r19);
    // nop

    // beq         $v1, $v0, L_8005C6DC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8005C6DC;
    }
    // nop

    // lhu         $v0, 0x2($s4)
    ctx->r2 = MEM_HU(0X2, ctx->r20);
    // nop

    // andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // beq         $v0, $zero, L_8005C6D8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005C6D8;
    }
    // nop

    // lbu         $v0, 0x2C6($s3)
    ctx->r2 = MEM_BU(0X2C6, ctx->r19);
    // nop

    // bne         $v0, $zero, L_8005C6D0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005C6D0;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_97;
    // nop

    after_97:
L_8005C6D0:
    // j           L_8005C6DC
    // sb          $s5, 0x2C6($s3)
    MEM_B(0X2C6, ctx->r19) = ctx->r21;
    goto L_8005C6DC;
    // sb          $s5, 0x2C6($s3)
    MEM_B(0X2C6, ctx->r19) = ctx->r21;
L_8005C6D8:
    // sb          $zero, 0x2C6($s3)
    MEM_B(0X2C6, ctx->r19) = 0;
L_8005C6DC:
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $s5, -0x7E6E($at)
    MEM_H(-0X7E6E, ctx->r1) = ctx->r21;
    // jal         0x800164B4
    // nop

    sub_800164B4(rdram, ctx);
    goto after_98;
    // nop

    after_98:
    // jal         0x8002FC4C
    // nop

    sub_8002FC4C(rdram, ctx);
    goto after_99;
    // nop

    after_99:
    // lbu         $a0, 0x2E4($s3)
    ctx->r4 = MEM_BU(0X2E4, ctx->r19);
    // nop

    // addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // bgez        $v1, L_8005C70C
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005C70C;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_8005C70C:
    // andi        $v0, $v0, 0x1E0
    ctx->r2 = ctx->r2 & 0X1E0;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // j           L_8005B390
    // sb          $v0, 0x2E4($s3)
    MEM_B(0X2E4, ctx->r19) = ctx->r2;
    goto L_8005B390;
    // sb          $v0, 0x2E4($s3)
    MEM_B(0X2E4, ctx->r19) = ctx->r2;
L_8005C71C:
    // lw          $a0, 0x174($s3)
    ctx->r4 = MEM_W(0X174, ctx->r19);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_100;
    // nop

    after_100:
    // lw          $a0, 0x178($s3)
    ctx->r4 = MEM_W(0X178, ctx->r19);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_101;
    // nop

    after_101:
    // lw          $a0, 0x17C($s3)
    ctx->r4 = MEM_W(0X17C, ctx->r19);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_102;
    // nop

    after_102:
    // lw          $a0, 0x180($s3)
    ctx->r4 = MEM_W(0X180, ctx->r19);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_103;
    // nop

    after_103:
    // lw          $a0, 0x184($s3)
    ctx->r4 = MEM_W(0X184, ctx->r19);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_104;
    // nop

    after_104:
    // lw          $a0, 0x188($s3)
    ctx->r4 = MEM_W(0X188, ctx->r19);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_105;
    // nop

    after_105:
    // lw          $a0, 0x18C($s3)
    ctx->r4 = MEM_W(0X18C, ctx->r19);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_106;
    // nop

    after_106:
    // lw          $a0, 0x190($s3)
    ctx->r4 = MEM_W(0X190, ctx->r19);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_107;
    // nop

    after_107:
    // lw          $a0, 0x194($s3)
    ctx->r4 = MEM_W(0X194, ctx->r19);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_108;
    // nop

    after_108:
    // lw          $a0, 0x198($s3)
    ctx->r4 = MEM_W(0X198, ctx->r19);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_109;
    // nop

    after_109:
    // lw          $a0, 0x2CC($s3)
    ctx->r4 = MEM_W(0X2CC, ctx->r19);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_110;
    // nop

    after_110:
    // lw          $a0, 0x2D0($s3)
    ctx->r4 = MEM_W(0X2D0, ctx->r19);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_111;
    // nop

    after_111:
    // lw          $a0, 0x1B0($s3)
    ctx->r4 = MEM_W(0X1B0, ctx->r19);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_112;
    // nop

    after_112:
    // jal         0x80058D30
    // nop

    sub_80058D30(rdram, ctx);
    goto after_113;
    // nop

    after_113:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_114;
    // nop

    after_114:
    // lw          $ra, 0xDC($sp)
    ctx->r31 = MEM_W(0XDC, ctx->r29);
    // lw          $fp, 0xD8($sp)
    ctx->r30 = MEM_W(0XD8, ctx->r29);
    // lw          $s7, 0xD4($sp)
    ctx->r23 = MEM_W(0XD4, ctx->r29);
    // lw          $s6, 0xD0($sp)
    ctx->r22 = MEM_W(0XD0, ctx->r29);
    // lw          $s5, 0xCC($sp)
    ctx->r21 = MEM_W(0XCC, ctx->r29);
    // lw          $s4, 0xC8($sp)
    ctx->r20 = MEM_W(0XC8, ctx->r29);
    // lw          $s3, 0xC4($sp)
    ctx->r19 = MEM_W(0XC4, ctx->r29);
    // lw          $s2, 0xC0($sp)
    ctx->r18 = MEM_W(0XC0, ctx->r29);
    // lw          $s1, 0xBC($sp)
    ctx->r17 = MEM_W(0XBC, ctx->r29);
    // lw          $s0, 0xB8($sp)
    ctx->r16 = MEM_W(0XB8, ctx->r29);
    // addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // jr          $ra
    // nop

    return;
    // nop

;}
