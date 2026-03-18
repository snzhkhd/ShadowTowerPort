#include "recomp.h"
#include "disable_warnings.h"

void sub_80067624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lbu         $v1, 0xD38($v0)
    ctx->r3 = MEM_BU(0XD38, ctx->r2);
    // addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // bne         $v1, $v0, L_80067678
    if (ctx->r3 != ctx->r2) {
        // sw          $s0, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r16;
        goto L_80067678;
    }
    // sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // addiu       $t1, $zero, 0x14E
    ctx->r9 = ADD32(0, 0X14E);
    // sh          $t1, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r9;
    // addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // sh          $t1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r9;
    // j           L_8006768C
    // addiu       $t1, $zero, 0x156
    ctx->r9 = ADD32(0, 0X156);
    goto L_8006768C;
    // addiu       $t1, $zero, 0x156
    ctx->r9 = ADD32(0, 0X156);
L_80067678:
    // addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // sh          $t1, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r9;
    // addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // sh          $t1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r9;
    // addiu       $t1, $zero, 0x12
    ctx->r9 = ADD32(0, 0X12);
L_8006768C:
    // sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // addiu       $t1, $zero, 0x87
    ctx->r9 = ADD32(0, 0X87);
    // sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // lhu         $t1, 0x30($sp)
    ctx->r9 = MEM_HU(0X30, ctx->r29);
    // addiu       $v0, $zero, 0xC0
    ctx->r2 = ADD32(0, 0XC0);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sh          $v0, 0x354($at)
    MEM_H(0X354, ctx->r1) = ctx->r2;
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sh          $t1, 0x350($at)
    MEM_H(0X350, ctx->r1) = ctx->r9;
    // lhu         $t1, 0x38($sp)
    ctx->r9 = MEM_HU(0X38, ctx->r29);
    // addiu       $v0, $zero, 0x7C
    ctx->r2 = ADD32(0, 0X7C);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sh          $v0, 0x356($at)
    MEM_H(0X356, ctx->r1) = ctx->r2;
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sh          $t1, 0x352($at)
    MEM_H(0X352, ctx->r1) = ctx->r9;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lbu         $v1, 0xD38($v0)
    ctx->r3 = MEM_BU(0XD38, ctx->r2);
    // addiu       $v0, $zero, 0x68
    ctx->r2 = ADD32(0, 0X68);
    // bne         $v1, $v0, L_80067724
    if (ctx->r3 != ctx->r2) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80067724;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // lui         $v1, 0x1F80
    ctx->r3 = S32(0X1F80 << 16);
    // lhu         $v1, 0x2E0($v1)
    ctx->r3 = MEM_HU(0X2E0, ctx->r3);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lui         $v1, 0x1F80
    ctx->r3 = S32(0X1F80 << 16);
    // lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(0X4, ctx->r3);
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // j           L_80067770
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    goto L_80067770;
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
L_80067724:
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
    // lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(0X2, ctx->r2);
    // lui         $v1, 0x1F80
    ctx->r3 = S32(0X1F80 << 16);
    // lhu         $v1, 0x2E0($v1)
    ctx->r3 = MEM_HU(0X2E0, ctx->r3);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lui         $v1, 0x1F80
    ctx->r3 = S32(0X1F80 << 16);
    // lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(0X8, ctx->r3);
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(0X0, ctx->r2);
    // nop

    // sh          $t1, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r9;
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_80067774
    if (ctx->r3 != ctx->r2) {
        // addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
        goto L_80067774;
    }
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80067770:
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_80067774:
    // bne         $v0, $zero, L_80067B9C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80067B9C;
    }
    // nop

    // jal         0x8006616C
    // nop

    sub_8006616C(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bne         $v0, $zero, L_80067814
    if (ctx->r2 != 0) {
        // addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
        goto L_80067814;
    }
    // addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // lui         $t1, 0x1F80
    ctx->r9 = S32(0X1F80 << 16);
    // addiu       $s1, $t1, 0x350
    ctx->r17 = ADD32(ctx->r9, 0X350);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $s0, $t1, 0x358
    ctx->r16 = ADD32(ctx->r9, 0X358);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sh          $v0, 0x358($at)
    MEM_H(0X358, ctx->r1) = ctx->r2;
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sh          $zero, 0x35A($at)
    MEM_H(0X35A, ctx->r1) = 0;
    // jal         0x80028364
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    sub_80028364(rdram, ctx);
    goto after_1;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_1:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $v1, 0x1F80
    ctx->r3 = S32(0X1F80 << 16);
    // lhu         $v1, 0x350($v1)
    ctx->r3 = MEM_HU(0X350, ctx->r3);
    // addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sh          $v0, 0x354($at)
    MEM_H(0X354, ctx->r1) = ctx->r2;
    // addiu       $v0, $zero, 0x340
    ctx->r2 = ADD32(0, 0X340);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sh          $v0, 0x358($at)
    MEM_H(0X358, ctx->r1) = ctx->r2;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // addiu       $v1, $v1, 0xC0
    ctx->r3 = ADD32(ctx->r3, 0XC0);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sh          $v1, 0x350($at)
    MEM_H(0X350, ctx->r1) = ctx->r3;
    // jal         0x80028364
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    sub_80028364(rdram, ctx);
    goto after_2;
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    after_2:
    // addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
L_80067814:
    // lhu         $t1, 0x20($sp)
    ctx->r9 = MEM_HU(0X20, ctx->r29);
    // addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // sll         $v1, $t1, 16
    ctx->r3 = S32(ctx->r9) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
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
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x7820
    ctx->r3 = ADD32(ctx->r3, 0X7820);
    // addu        $s4, $v0, $v1
    ctx->r20 = ADD32(ctx->r2, ctx->r3);
    // lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(0X18, ctx->r29);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E52($at)
    MEM_H(-0X7E52, ctx->r1) = ctx->r2;
    // addiu       $fp, $t1, -0x4
    ctx->r30 = ADD32(ctx->r9, -0X4);
    // sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
L_80067860:
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(0X4C, ctx->r29);
    // lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(0X1C, ctx->r29);
    // sll         $v0, $s6, 1
    ctx->r2 = S32(ctx->r22) << 1;
    // sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // addiu       $t1, $t1, 0x28
    ctx->r9 = ADD32(ctx->r9, 0X28);
    // sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // addiu       $t1, $t1, 0xD50
    ctx->r9 = ADD32(ctx->r9, 0XD50);
    // addu        $s1, $v0, $t1
    ctx->r17 = ADD32(ctx->r2, ctx->r9);
L_80067888:
    // addiu       $s7, $zero, 0xE
    ctx->r23 = ADD32(0, 0XE);
    // beq         $s5, $s7, L_8006793C
    if (ctx->r21 == ctx->r23) {
        // lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
        goto L_8006793C;
    }
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(0X0, ctx->r20);
    // nop

    // beq         $v0, $zero, L_800678EC
    if (ctx->r2 == 0) {
        // addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
        goto L_800678EC;
    }
    // addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // andi        $s0, $s2, 0xFFFF
    ctx->r16 = ctx->r18 & 0XFFFF;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lui         $t1, 0x1F80
    ctx->r9 = S32(0X1F80 << 16);
    // addiu       $a3, $t1, 0x300
    ctx->r7 = ADD32(ctx->r9, 0X300);
    // lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // addiu       $t1, $t1, 0x1950
    ctx->r9 = ADD32(ctx->r9, 0X1950);
    // lhu         $a0, 0x190($s1)
    ctx->r4 = MEM_HU(0X190, ctx->r17);
    // lhu         $a1, 0x40($sp)
    ctx->r5 = MEM_HU(0X40, ctx->r29);
    // jal         0x8002732C
    // addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    sub_8002732C(rdram, ctx);
    goto after_3;
    // addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    after_3:
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lui         $t1, 0x1F80
    ctx->r9 = S32(0X1F80 << 16);
    // addiu       $a3, $t1, 0x310
    ctx->r7 = ADD32(ctx->r9, 0X310);
    // lui         $a0, 0x1300
    ctx->r4 = S32(0X1300 << 16);
    // lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(0X0, ctx->r20);
    // lhu         $a1, 0x44($sp)
    ctx->r5 = MEM_HU(0X44, ctx->r29);
    // jal         0x80027440
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    sub_80027440(rdram, ctx);
    goto after_4;
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    after_4:
L_800678EC:
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // slti        $v0, $s3, 0x4
    ctx->r2 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_80067888
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0xF
        ctx->r18 = ADD32(ctx->r18, 0XF);
        goto L_80067888;
    }
    // addiu       $s2, $s2, 0xF
    ctx->r18 = ADD32(ctx->r18, 0XF);
    // beq         $s5, $s7, L_80067938
    if (ctx->r21 == ctx->r23) {
        // nop
    
        goto L_80067938;
    }
    // nop

    // lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(0X4C, ctx->r29);
    // nop

    // addiu       $t1, $t1, 0x48
    ctx->r9 = ADD32(ctx->r9, 0X48);
    // sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(0X28, ctx->r29);
    // addiu       $fp, $fp, 0x48
    ctx->r30 = ADD32(ctx->r30, 0X48);
    // addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // slti        $v0, $t1, 0x4
    ctx->r2 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_80067860
    if (ctx->r2 != 0) {
        // sw          $t1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r9;
        goto L_80067860;
    }
    // sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_80067938:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
L_8006793C:
    // lhu         $t1, 0x20($sp)
    ctx->r9 = MEM_HU(0X20, ctx->r29);
    // addiu       $a0, $a0, 0x76F8
    ctx->r4 = ADD32(ctx->r4, 0X76F8);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $zero, -0x7E52($at)
    MEM_H(-0X7E52, ctx->r1) = 0;
    // sll         $v1, $t1, 16
    ctx->r3 = S32(ctx->r9) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
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
    // addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(0X1C, ctx->r29);
    // lbu         $v0, 0x13F($v1)
    ctx->r2 = MEM_BU(0X13F, ctx->r3);
    // addiu       $t1, $t1, 0x3C
    ctx->r9 = ADD32(ctx->r9, 0X3C);
    // beq         $v0, $zero, L_80067A50
    if (ctx->r2 == 0) {
        // sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
        goto L_80067A50;
    }
    // sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // lbu         $v0, 0x140($v1)
    ctx->r2 = MEM_BU(0X140, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_800679A0
    if (ctx->r2 == 0) {
        // lui         $t1, 0x1F80
        ctx->r9 = S32(0X1F80 << 16);
        goto L_800679A0;
    }
    // lui         $t1, 0x1F80
    ctx->r9 = S32(0X1F80 << 16);
    // addiu       $s3, $t1, 0x308
    ctx->r19 = ADD32(ctx->r9, 0X308);
    // j           L_800679A8
    // addiu       $s4, $t1, 0x318
    ctx->r20 = ADD32(ctx->r9, 0X318);
    goto L_800679A8;
    // addiu       $s4, $t1, 0x318
    ctx->r20 = ADD32(ctx->r9, 0X318);
L_800679A0:
    // addiu       $s3, $t1, 0x300
    ctx->r19 = ADD32(ctx->r9, 0X300);
    // addiu       $s4, $t1, 0x310
    ctx->r20 = ADD32(ctx->r9, 0X310);
L_800679A8:
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x3A($a0)
    ctx->r2 = MEM_HU(0X3A, ctx->r4);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // lhu         $s1, 0x1C($sp)
    ctx->r17 = MEM_HU(0X1C, ctx->r29);
    // lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(0X18, ctx->r29);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // jal         0x8002732C
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_5;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_5:
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(0X18, ctx->r29);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $a1, $t1, 0x46
    ctx->r5 = ADD32(ctx->r9, 0X46);
    // lhu         $t1, 0x20($sp)
    ctx->r9 = MEM_HU(0X20, ctx->r29);
    // addiu       $v1, $v1, 0x76F8
    ctx->r3 = ADD32(ctx->r3, 0X76F8);
    // sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $s0, $v0, 1
    ctx->r16 = S32(ctx->r2) << 1;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // lbu         $a0, 0x140($s0)
    ctx->r4 = MEM_BU(0X140, ctx->r16);
    // lui         $s2, 0x300
    ctx->r18 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    sub_80027440(rdram, ctx);
    goto after_6;
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    after_6:
    // addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(0X18, ctx->r29);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // jal         0x80026ECC
    // addiu       $a1, $t1, 0x6A
    ctx->r5 = ADD32(ctx->r9, 0X6A);
    sub_80026ECC(rdram, ctx);
    goto after_7;
    // addiu       $a1, $t1, 0x6A
    ctx->r5 = ADD32(ctx->r9, 0X6A);
    after_7:
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(0X18, ctx->r29);
    // lbu         $a0, 0x13F($s0)
    ctx->r4 = MEM_BU(0X13F, ctx->r16);
    // addiu       $a1, $t1, 0x7A
    ctx->r5 = ADD32(ctx->r9, 0X7A);
    // jal         0x80027440
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    sub_80027440(rdram, ctx);
    goto after_8;
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    after_8:
L_80067A50:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lhu         $t1, 0x20($sp)
    ctx->r9 = MEM_HU(0X20, ctx->r29);
    // addiu       $a0, $a0, 0x76F8
    ctx->r4 = ADD32(ctx->r4, 0X76F8);
    // sll         $v1, $t1, 16
    ctx->r3 = S32(ctx->r9) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
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
    // addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(0X1C, ctx->r29);
    // lhu         $v0, 0x13C($v1)
    ctx->r2 = MEM_HU(0X13C, ctx->r3);
    // addiu       $t1, $t1, 0xF
    ctx->r9 = ADD32(ctx->r9, 0XF);
    // beq         $v0, $zero, L_80067B9C
    if (ctx->r2 == 0) {
        // sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
        goto L_80067B9C;
    }
    // sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // lui         $a0, 0x2416
    ctx->r4 = S32(0X2416 << 16);
    // lhu         $v1, 0x13C($v1)
    ctx->r3 = MEM_HU(0X13C, ctx->r3);
    // ori         $a0, $a0, 0x8E19
    ctx->r4 = ctx->r4 | 0X8E19;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $t1, 0x1F80
    ctx->r9 = S32(0X1F80 << 16);
    // addiu       $s3, $t1, 0x300
    ctx->r19 = ADD32(ctx->r9, 0X300);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) << 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $s2, 0x1C($sp)
    ctx->r18 = MEM_HU(0X1C, ctx->r29);
    // lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(0X18, ctx->r29);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v1, 0x38($a0)
    ctx->r3 = MEM_HU(0X38, ctx->r4);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // srl         $s0, $t0, 6
    ctx->r16 = S32(U32(ctx->r8) >> 6);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $s1, $t2, 6
    ctx->r17 = S32(ctx->r10) >> 6;
    // subu        $s1, $s1, $v0
    ctx->r17 = SUB32(ctx->r17, ctx->r2);
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // jal         0x8002732C
    // subu        $s1, $s1, $v0
    ctx->r17 = SUB32(ctx->r17, ctx->r2);
    sub_8002732C(rdram, ctx);
    goto after_9;
    // subu        $s1, $s1, $v0
    ctx->r17 = SUB32(ctx->r17, ctx->r2);
    after_9:
    // lui         $a0, 0x300
    ctx->r4 = S32(0X300 << 16);
    // or          $a0, $s0, $a0
    ctx->r4 = ctx->r16 | ctx->r4;
    // lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(0X18, ctx->r29);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // addiu       $a1, $t1, 0x46
    ctx->r5 = ADD32(ctx->r9, 0X46);
    // lui         $t1, 0x1F80
    ctx->r9 = S32(0X1F80 << 16);
    // addiu       $s0, $t1, 0x310
    ctx->r16 = ADD32(ctx->r9, 0X310);
    // jal         0x80027440
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sub_80027440(rdram, ctx);
    goto after_10;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_10:
    // addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(0X18, ctx->r29);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // jal         0x80026ECC
    // addiu       $a1, $t1, 0x6D
    ctx->r5 = ADD32(ctx->r9, 0X6D);
    sub_80026ECC(rdram, ctx);
    goto after_11;
    // addiu       $a1, $t1, 0x6D
    ctx->r5 = ADD32(ctx->r9, 0X6D);
    after_11:
    // andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // or          $a0, $s1, $a0
    ctx->r4 = ctx->r17 | ctx->r4;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(0X18, ctx->r29);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // jal         0x80027440
    // addiu       $a1, $t1, 0x74
    ctx->r5 = ADD32(ctx->r9, 0X74);
    sub_80027440(rdram, ctx);
    goto after_12;
    // addiu       $a1, $t1, 0x74
    ctx->r5 = ADD32(ctx->r9, 0X74);
    after_12:
    // addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(0X18, ctx->r29);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // jal         0x80026ECC
    // addiu       $a1, $t1, 0x84
    ctx->r5 = ADD32(ctx->r9, 0X84);
    sub_80026ECC(rdram, ctx);
    goto after_13;
    // addiu       $a1, $t1, 0x84
    ctx->r5 = ADD32(ctx->r9, 0X84);
    after_13:
L_80067B9C:
    // lhu         $t1, 0x30($sp)
    ctx->r9 = MEM_HU(0X30, ctx->r29);
    // addiu       $a2, $zero, 0x128
    ctx->r6 = ADD32(0, 0X128);
    // addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
    // lhu         $t1, 0x38($sp)
    ctx->r9 = MEM_HU(0X38, ctx->r29);
    // addiu       $a3, $zero, 0xDE
    ctx->r7 = ADD32(0, 0XDE);
    // jal         0x80029548
    // addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
    sub_80029548(rdram, ctx);
    goto after_14;
    // addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
    after_14:
    // lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(0X74, ctx->r29);
    // lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(0X70, ctx->r29);
    // lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(0X6C, ctx->r29);
    // lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(0X68, ctx->r29);
    // lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(0X64, ctx->r29);
    // lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(0X60, ctx->r29);
    // lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(0X5C, ctx->r29);
    // lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(0X58, ctx->r29);
    // lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(0X54, ctx->r29);
    // lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(0X50, ctx->r29);
    // addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // jr          $ra
    // nop

    return;
    // nop

;}
