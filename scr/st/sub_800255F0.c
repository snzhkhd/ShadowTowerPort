#include "recomp.h"
#include "disable_warnings.h"

void sub_800255F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // lui         $s1, 0x1F80
    ctx->r17 = S32(0X1F80 << 16);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // addiu       $s5, $v0, -0x1CE8
    ctx->r21 = ADD32(ctx->r2, -0X1CE8);
    // sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // addiu       $s7, $zero, 0x7F
    ctx->r23 = ADD32(0, 0X7F);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // addiu       $fp, $v0, 0x5090
    ctx->r30 = ADD32(ctx->r2, 0X5090);
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // addiu       $s0, $s5, 0x7
    ctx->r16 = ADD32(ctx->r21, 0X7);
    // sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // addiu       $s4, $s5, 0x48
    ctx->r20 = ADD32(ctx->r21, 0X48);
    // sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // addiu       $s3, $s5, 0x38
    ctx->r19 = ADD32(ctx->r21, 0X38);
    // sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // addiu       $s6, $s5, 0x30
    ctx->r22 = ADD32(ctx->r21, 0X30);
    // sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
L_80025644:
    // lbu         $v1, 0x0($s5)
    ctx->r3 = MEM_BU(0X0, ctx->r21);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_80025870
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80025870;
    }
    // nop

    // lbu         $v0, -0x1($s0)
    ctx->r2 = MEM_BU(-0X1, ctx->r16);
    // nop

    // andi        $a2, $v0, 0x3
    ctx->r6 = ctx->r2 & 0X3;
    // beq         $a2, $zero, L_80025870
    if (ctx->r6 == 0) {
        // nop
    
        goto L_80025870;
    }
    // nop

    // lw          $v0, 0x19($s0)
    ctx->r2 = MEM_W(0X19, ctx->r16);
    // lw          $v1, 0x1D($s0)
    ctx->r3 = MEM_W(0X1D, ctx->r16);
    // lw          $a0, 0x21($s0)
    ctx->r4 = MEM_W(0X21, ctx->r16);
    // lw          $a1, 0x25($s0)
    ctx->r5 = MEM_W(0X25, ctx->r16);
    // sw          $v0, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->r2;
    // sw          $v1, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->r3;
    // sw          $a0, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->r4;
    // sw          $a1, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->r5;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $a2, $v0, L_800256A4
    if (ctx->r6 == ctx->r2) {
        // addiu       $s2, $s5, 0x20
        ctx->r18 = ADD32(ctx->r21, 0X20);
        goto L_800256A4;
    }
    // addiu       $s2, $s5, 0x20
    ctx->r18 = ADD32(ctx->r21, 0X20);
    // jal         0x80016554
    // nop

    sub_80016554(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // beq         $v0, $zero, L_80025870
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80025870;
    }
    // nop

L_800256A4:
    // lhu         $v0, 0x7($s0)
    ctx->r2 = MEM_HU(0X7, ctx->r16);
    // nop

    // sh          $v0, 0x98($s1)
    MEM_H(0X98, ctx->r17) = ctx->r2;
    // lhu         $a0, 0x3($s0)
    ctx->r4 = MEM_HU(0X3, ctx->r16);
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // addiu       $a0, $a0, 0x60
    ctx->r4 = ADD32(ctx->r4, 0X60);
    // jal         0x80033DB8
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    sub_80033DB8(rdram, ctx);
    goto after_1;
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_1:
    // lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(0X38, ctx->r29);
    // nop

    // beq         $v0, $zero, L_80025870
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80025870;
    }
    // nop

    // lbu         $v0, -0x1($s0)
    ctx->r2 = MEM_BU(-0X1, ctx->r16);
    // nop

    // andi        $v1, $v0, 0xC
    ctx->r3 = ctx->r2 & 0XC;
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_80025794
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x5
        ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
        goto L_80025794;
    }
    // slti        $v0, $v1, 0x5
    ctx->r2 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_80025704
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_80025704;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // beq         $v1, $zero, L_8002571C
    if (ctx->r3 == 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_8002571C;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // j           L_80025874
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    goto L_80025874;
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
L_80025704:
    // beq         $v1, $v0, L_800257CC
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
        goto L_800257CC;
    }
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // beq         $v1, $v0, L_80025804
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, -0x10
        ctx->r2 = ADD32(0, -0X10);
        goto L_80025804;
    }
    // addiu       $v0, $zero, -0x10
    ctx->r2 = ADD32(0, -0X10);
    // j           L_80025874
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    goto L_80025874;
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
L_8002571C:
    // lhu         $v0, 0x29($s0)
    ctx->r2 = MEM_HU(0X29, ctx->r16);
    // nop

    // sh          $v0, 0xD8($s1)
    MEM_H(0XD8, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x2B($s0)
    ctx->r2 = MEM_HU(0X2B, ctx->r16);
    // nop

    // sh          $v0, 0xDA($s1)
    MEM_H(0XDA, ctx->r17) = ctx->r2;
    // lw          $v0, 0xE4($fp)
    ctx->r2 = MEM_W(0XE4, ctx->r30);
    // lhu         $v1, 0x2D($s0)
    ctx->r3 = MEM_HU(0X2D, ctx->r16);
    // addiu       $v0, $v0, -0x1C
    ctx->r2 = ADD32(ctx->r2, -0X1C);
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // sw          $v0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x1007
    ctx->r2 = ADD32(0, 0X1007);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // sh          $v1, 0xDC($s1)
    MEM_H(0XDC, ctx->r17) = ctx->r3;
    // lhu         $a1, 0x3($s0)
    ctx->r5 = MEM_HU(0X3, ctx->r16);
    // addiu       $v0, $v0, -0x4288
    ctx->r2 = ADD32(ctx->r2, -0X4288);
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, -0x5($s0)
    ctx->r2 = MEM_BU(-0X5, ctx->r16);
    // nop

    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0xD($s0)
    ctx->r2 = MEM_HU(0XD, ctx->r16);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lh          $v0, 0xB($s0)
    ctx->r2 = MEM_HS(0XB, ctx->r16);
    // j           L_8002584C
    // addiu       $a3, $s1, 0xD8
    ctx->r7 = ADD32(ctx->r17, 0XD8);
    goto L_8002584C;
    // addiu       $a3, $s1, 0xD8
    ctx->r7 = ADD32(ctx->r17, 0XD8);
L_80025794:
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // sw          $v0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->r2;
    // lw          $v1, 0xE4($fp)
    ctx->r3 = MEM_W(0XE4, ctx->r30);
    // addiu       $v0, $zero, 0x1007
    ctx->r2 = ADD32(0, 0X1007);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v1, $v1, -0x1C
    ctx->r3 = ADD32(ctx->r3, -0X1C);
    // sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // lhu         $a1, 0x3($s0)
    ctx->r5 = MEM_HU(0X3, ctx->r16);
    // addiu       $v0, $v0, 0x40C
    ctx->r2 = ADD32(ctx->r2, 0X40C);
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // j           L_8002582C
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    goto L_8002582C;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_800257CC:
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // sw          $v0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->r2;
    // lw          $v1, 0xE4($fp)
    ctx->r3 = MEM_W(0XE4, ctx->r30);
    // addiu       $v0, $zero, 0x1007
    ctx->r2 = ADD32(0, 0X1007);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x1C
    ctx->r3 = ADD32(ctx->r3, -0X1C);
    // sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // lhu         $a1, 0x3($s0)
    ctx->r5 = MEM_HU(0X3, ctx->r16);
    // addiu       $v0, $v0, -0x41C8
    ctx->r2 = ADD32(ctx->r2, -0X41C8);
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // j           L_8002582C
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    goto L_8002582C;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_80025804:
    // sw          $v0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->r2;
    // lw          $v1, 0xE4($fp)
    ctx->r3 = MEM_W(0XE4, ctx->r30);
    // addiu       $v0, $zero, 0xFEC
    ctx->r2 = ADD32(0, 0XFEC);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // addiu       $v1, $v1, 0x50
    ctx->r3 = ADD32(ctx->r3, 0X50);
    // sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // lhu         $a1, 0x3($s0)
    ctx->r5 = MEM_HU(0X3, ctx->r16);
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_8002582C:
    // lbu         $v0, -0x5($s0)
    ctx->r2 = MEM_BU(-0X5, ctx->r16);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0xD($s0)
    ctx->r2 = MEM_HU(0XD, ctx->r16);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lh          $v0, 0xB($s0)
    ctx->r2 = MEM_HS(0XB, ctx->r16);
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
L_8002584C:
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lh          $v0, 0xB($s0)
    ctx->r2 = MEM_HS(0XB, ctx->r16);
    // addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // jal         0x80022678
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    sub_80022678(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_2:
L_80025870:
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
L_80025874:
    // addiu       $s4, $s4, 0x58
    ctx->r20 = ADD32(ctx->r20, 0X58);
    // addiu       $s3, $s3, 0x58
    ctx->r19 = ADD32(ctx->r19, 0X58);
    // addiu       $s6, $s6, 0x58
    ctx->r22 = ADD32(ctx->r22, 0X58);
    // addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s7, $v0, L_80025644
    if (ctx->r23 != ctx->r2) {
        // addiu       $s5, $s5, 0x58
        ctx->r21 = ADD32(ctx->r21, 0X58);
        goto L_80025644;
    }
    // addiu       $s5, $s5, 0x58
    ctx->r21 = ADD32(ctx->r21, 0X58);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $s3, $v0, -0x3B74
    ctx->r19 = ADD32(ctx->r2, -0X3B74);
    // addiu       $s7, $zero, 0x7F
    ctx->r23 = ADD32(0, 0X7F);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $s5, $v0, 0x5090
    ctx->r21 = ADD32(ctx->r2, 0X5090);
    // addiu       $s4, $zero, 0x1000
    ctx->r20 = ADD32(0, 0X1000);
    // addiu       $fp, $s1, 0xD8
    ctx->r30 = ADD32(ctx->r17, 0XD8);
    // addiu       $s6, $zero, 0x7
    ctx->r22 = ADD32(0, 0X7);
    // addiu       $s0, $s3, 0x5
    ctx->r16 = ADD32(ctx->r19, 0X5);
    // sh          $zero, 0xDC($s1)
    MEM_H(0XDC, ctx->r17) = 0;
    // sh          $zero, 0xDA($s1)
    MEM_H(0XDA, ctx->r17) = 0;
    // sh          $zero, 0xD8($s1)
    MEM_H(0XD8, ctx->r17) = 0;
    // sh          $zero, 0x98($s1)
    MEM_H(0X98, ctx->r17) = 0;
L_800258C4:
    // lhu         $v1, 0x0($s3)
    ctx->r3 = MEM_HU(0X0, ctx->r19);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_80025BC8
    if (ctx->r3 == ctx->r2) {
        // andi        $v0, $v1, 0x8000
        ctx->r2 = ctx->r3 & 0X8000;
        goto L_80025BC8;
    }
    // andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // beq         $v0, $zero, L_800258F0
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_800258F0;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // lw          $v1, 0xE4($s5)
    ctx->r3 = MEM_W(0XE4, ctx->r21);
    // sw          $v0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->r2;
    // sw          $s4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r20;
    // j           L_80025B50
    // sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    goto L_80025B50;
    // sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
L_800258F0:
    // lw          $v0, 0x3($s0)
    ctx->r2 = MEM_W(0X3, ctx->r16);
    // lw          $v1, 0x7($s0)
    ctx->r3 = MEM_W(0X7, ctx->r16);
    // lw          $a0, 0xB($s0)
    ctx->r4 = MEM_W(0XB, ctx->r16);
    // lw          $a1, 0xF($s0)
    ctx->r5 = MEM_W(0XF, ctx->r16);
    // sw          $v0, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->r2;
    // sw          $v1, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->r3;
    // sw          $a0, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->r4;
    // sw          $a1, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->r5;
    // jal         0x80016554
    // addiu       $s2, $s3, 0x8
    ctx->r18 = ADD32(ctx->r19, 0X8);
    sub_80016554(rdram, ctx);
    goto after_3;
    // addiu       $s2, $s3, 0x8
    ctx->r18 = ADD32(ctx->r19, 0X8);
    after_3:
    // beq         $v0, $zero, L_80025B50
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80025B50;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lbu         $a1, -0x3($s0)
    ctx->r5 = MEM_BU(-0X3, ctx->r16);
    // nop

    // andi        $v1, $a1, 0x3F
    ctx->r3 = ctx->r5 & 0X3F;
    // bne         $v1, $v0, L_80025A00
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_80025A00;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // andi        $v0, $a1, 0xC0
    ctx->r2 = ctx->r5 & 0XC0;
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // sh          $v0, 0xDA($s1)
    MEM_H(0XDA, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // sw          $v0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x1014
    ctx->r2 = ADD32(0, 0X1014);
    // lw          $v1, 0xE4($s5)
    ctx->r3 = MEM_W(0XE4, ctx->r21);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x50
    ctx->r3 = ADD32(ctx->r3, -0X50);
    // sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // lhu         $a1, 0x0($s3)
    ctx->r5 = MEM_HU(0X0, ctx->r19);
    // addiu       $v0, $v0, -0x4288
    ctx->r2 = ADD32(ctx->r2, -0X4288);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addu        $a3, $fp, $zero
    ctx->r7 = ADD32(ctx->r30, 0);
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // jal         0x80022678
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80022678(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_4:
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // sh          $zero, 0xDA($s1)
    MEM_H(0XDA, ctx->r17) = 0;
    // lhu         $a1, 0x0($s3)
    ctx->r5 = MEM_HU(0X0, ctx->r19);
    // lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // addiu       $t0, $t0, -0x41C8
    ctx->r8 = ADD32(ctx->r8, -0X41C8);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addu        $a3, $fp, $zero
    ctx->r7 = ADD32(ctx->r30, 0);
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // j           L_80025B48
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    goto L_80025B48;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80025A00:
    // bne         $v1, $v0, L_80025A74
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_80025A74;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // sw          $v0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x1014
    ctx->r2 = ADD32(0, 0X1014);
    // lw          $v1, 0xE4($s5)
    ctx->r3 = MEM_W(0XE4, ctx->r21);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // addiu       $v1, $v1, -0x50
    ctx->r3 = ADD32(ctx->r3, -0X50);
    // sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // lhu         $a1, 0x0($s3)
    ctx->r5 = MEM_HU(0X0, ctx->r19);
    // lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // addiu       $t0, $t0, -0x41C8
    ctx->r8 = ADD32(ctx->r8, -0X41C8);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $a3, $s1, 0xD8
    ctx->r7 = ADD32(ctx->r17, 0XD8);
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // j           L_80025B48
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    goto L_80025B48;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80025A74:
    // bne         $v1, $v0, L_80025AE8
    if (ctx->r3 != ctx->r2) {
        // addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
        goto L_80025AE8;
    }
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // sw          $v0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x1014
    ctx->r2 = ADD32(0, 0X1014);
    // lw          $v1, 0xE4($s5)
    ctx->r3 = MEM_W(0XE4, ctx->r21);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x50
    ctx->r3 = ADD32(ctx->r3, -0X50);
    // sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // lhu         $a1, 0x0($s3)
    ctx->r5 = MEM_HU(0X0, ctx->r19);
    // addiu       $v0, $v0, -0x4288
    ctx->r2 = ADD32(ctx->r2, -0X4288);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $a3, $s1, 0xD8
    ctx->r7 = ADD32(ctx->r17, 0XD8);
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // j           L_80025B48
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    goto L_80025B48;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80025AE8:
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // lw          $v1, 0xE4($s5)
    ctx->r3 = MEM_W(0XE4, ctx->r21);
    // addiu       $a3, $s1, 0xD8
    ctx->r7 = ADD32(ctx->r17, 0XD8);
    // sw          $v0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->r2;
    // sw          $s4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r20;
    // sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // lhu         $a1, 0x0($s3)
    ctx->r5 = MEM_HU(0X0, ctx->r19);
    // lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // addiu       $t0, $t0, -0x41C8
    ctx->r8 = ADD32(ctx->r8, -0X41C8);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_80025B48:
    // jal         0x80022678
    // nop

    sub_80022678(rdram, ctx);
    goto after_5;
    // nop

    after_5:
L_80025B50:
    // lbu         $v0, -0x1($s0)
    ctx->r2 = MEM_BU(-0X1, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80025BC8
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
        goto L_80025BC8;
    }
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // lbu         $v1, -0x1($s0)
    ctx->r3 = MEM_BU(-0X1, ctx->r16);
    // lw          $v0, -0x3B78($v0)
    ctx->r2 = MEM_W(-0X3B78, ctx->r2);
    // nop

    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_80025B7C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80025B7C;
    }
    // nop

    // break       7
    do_break(2147638136);
L_80025B7C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_80025B94
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80025B94;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80025B94
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80025B94;
    }
    // nop

    // break       6
    do_break(2147638160);
L_80025B94:
    // mfhi        $v1
    ctx->r3 = hi;
    // nop

    // bne         $v1, $zero, L_80025BC8
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80025BC8;
    }
    // nop

    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // lbu         $v1, -0x2($s0)
    ctx->r3 = MEM_BU(-0X2, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80025BC8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80025BC8;
    }
    // nop

    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80025BC8:
    // addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s7, $v0, L_800258C4
    if (ctx->r23 != ctx->r2) {
        // addiu       $s3, $s3, 0x18
        ctx->r19 = ADD32(ctx->r19, 0X18);
        goto L_800258C4;
    }
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // lw          $v0, -0x3B78($v1)
    ctx->r2 = MEM_W(-0X3B78, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, -0x3B78($v1)
    MEM_W(-0X3B78, ctx->r3) = ctx->r2;
    // lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(0X64, ctx->r29);
    // lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(0X60, ctx->r29);
    // lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(0X5C, ctx->r29);
    // lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(0X58, ctx->r29);
    // lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(0X54, ctx->r29);
    // lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(0X50, ctx->r29);
    // lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(0X4C, ctx->r29);
    // lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(0X48, ctx->r29);
    // lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(0X44, ctx->r29);
    // lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // jr          $ra
    // nop

    return;
    // nop

;}
