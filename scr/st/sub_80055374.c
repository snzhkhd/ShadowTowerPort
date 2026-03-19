#include "recomp.h"
#include "disable_warnings.h"

void sub_80055374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // addiu       $v0, $v0, 0x640
    ctx->r2 = ADD32(ctx->r2, 0X640);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(0X8, ctx->r3);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // sw          $zero, -0x2F20($v0)
    MEM_W(-0X2F20, ctx->r2) = 0;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(0X18, ctx->r29);
    // lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(0X1C, ctx->r29);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // addiu       $v0, $zero, 0x420
    ctx->r2 = ADD32(0, 0X420);
    // sh          $v0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x640
    ctx->r2 = ADD32(0, 0X640);
    // sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
    // sh          $zero, 0x36($sp)
    MEM_H(0X36, ctx->r29) = 0;
    // sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
    // sh          $zero, 0x42($sp)
    MEM_H(0X42, ctx->r29) = 0;
    // sh          $v0, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r2;
    // jal         0x80053174
    // sh          $zero, 0x40($sp)
    MEM_H(0X40, ctx->r29) = 0;
    sub_80053174(rdram, ctx);
    goto after_0;
    // sh          $zero, 0x40($sp)
    MEM_H(0X40, ctx->r29) = 0;
    after_0:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s2, $v0, L_80055460
    if (ctx->r18 == ctx->r2) {
        // addu        $s0, $s2, $zero
        ctx->r16 = ADD32(ctx->r18, 0);
        goto L_80055460;
    }
    // addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // sll         $v1, $s2, 1
    ctx->r3 = S32(ctx->r18) << 1;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x51F8
    ctx->r2 = ADD32(ctx->r2, -0X51F8);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $a0, 0x22($v1)
    ctx->r4 = MEM_BU(0X22, ctx->r3);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sb          $v0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r2;
    // j           L_8005595C
    // sb          $a0, 0x23($v1)
    MEM_B(0X23, ctx->r3) = ctx->r4;
    goto L_8005595C;
    // sb          $a0, 0x23($v1)
    MEM_B(0X23, ctx->r3) = ctx->r4;
L_80055460:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x8004BB88
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sub_8004BB88(rdram, ctx);
    goto after_1;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // beq         $s2, $s0, L_80055588
    if (ctx->r18 == ctx->r16) {
        // sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18) << 1;
        goto L_80055588;
    }
    // sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18) << 1;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x5EC8
    ctx->r3 = ADD32(ctx->r3, -0X5EC8);
    // addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x70D8
    ctx->r16 = ADD32(ctx->r16, -0X70D8);
    // lw          $a1, 0x40($s2)
    ctx->r5 = MEM_W(0X40, ctx->r18);
    // lhu         $v1, 0x30($s2)
    ctx->r3 = MEM_HU(0X30, ctx->r18);
    // lw          $a0, 0x78($s2)
    ctx->r4 = MEM_W(0X78, ctx->r18);
    // lw          $v0, 0x24C($s0)
    ctx->r2 = MEM_W(0X24C, ctx->r16);
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // jal         0x80076EA4
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    ratan2(rdram, ctx);
    goto after_2;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    after_2:
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // lhu         $v0, 0x30($s2)
    ctx->r2 = MEM_HU(0X30, ctx->r18);
    // lw          $a1, 0x40($s2)
    ctx->r5 = MEM_W(0X40, ctx->r18);
    // lw          $a0, 0x78($s2)
    ctx->r4 = MEM_W(0X78, ctx->r18);
    // lw          $v1, 0x24C($s0)
    ctx->r3 = MEM_W(0X24C, ctx->r16);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // jal         0x80076EA4
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    ratan2(rdram, ctx);
    goto after_3;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    after_3:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // slti        $v0, $s1, 0x801
    ctx->r2 = SIGNED(ctx->r17) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_800554F8
    if (ctx->r2 != 0) {
        // slti        $v0, $a0, 0x801
        ctx->r2 = SIGNED(ctx->r4) < 0X801 ? 1 : 0;
        goto L_800554F8;
    }
    // slti        $v0, $a0, 0x801
    ctx->r2 = SIGNED(ctx->r4) < 0X801 ? 1 : 0;
    // addiu       $s1, $s1, -0x800
    ctx->r17 = ADD32(ctx->r17, -0X800);
L_800554F8:
    // bne         $v0, $zero, L_80055508
    if (ctx->r2 != 0) {
        // slti        $v0, $s1, 0x61
        ctx->r2 = SIGNED(ctx->r17) < 0X61 ? 1 : 0;
        goto L_80055508;
    }
    // slti        $v0, $s1, 0x61
    ctx->r2 = SIGNED(ctx->r17) < 0X61 ? 1 : 0;
    // addiu       $s1, $s1, -0x800
    ctx->r17 = ADD32(ctx->r17, -0X800);
    // slti        $v0, $s1, 0x61
    ctx->r2 = SIGNED(ctx->r17) < 0X61 ? 1 : 0;
L_80055508:
    // bne         $v0, $zero, L_80055514
    if (ctx->r2 != 0) {
        // slti        $v0, $a0, 0xA0
        ctx->r2 = SIGNED(ctx->r4) < 0XA0 ? 1 : 0;
        goto L_80055514;
    }
    // slti        $v0, $a0, 0xA0
    ctx->r2 = SIGNED(ctx->r4) < 0XA0 ? 1 : 0;
    // addiu       $s1, $zero, 0x60
    ctx->r17 = ADD32(0, 0X60);
L_80055514:
    // beq         $v0, $zero, L_80055520
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80055520;
    }
    // nop

    // addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
L_80055520:
    // lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(0X74, ctx->r29);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // lh          $a1, 0x0($a3)
    ctx->r5 = MEM_HS(0X0, ctx->r7);
    // jal         0x8004A184
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_8004A184(rdram, ctx);
    goto after_4;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_4:
    // beq         $v0, $zero, L_80055588
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80055588;
    }
    // nop

    // lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(0X74, ctx->r29);
    // sll         $a1, $s1, 16
    ctx->r5 = S32(ctx->r17) << 16;
    // lh          $a0, 0x0($a3)
    ctx->r4 = MEM_HS(0X0, ctx->r7);
    // jal         0x8004A184
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8004A184(rdram, ctx);
    goto after_5;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_5:
    // beq         $v0, $zero, L_80055588
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80055588;
    }
    // nop

    // lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(0X74, ctx->r29);
    // lh          $a1, 0x8E($s2)
    ctx->r5 = MEM_HS(0X8E, ctx->r18);
    // lh          $a0, 0x2($a3)
    ctx->r4 = MEM_HS(0X2, ctx->r7);
    // jal         0x8004A148
    // addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    sub_8004A148(rdram, ctx);
    goto after_6;
    // addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_6:
    // beq         $v0, $zero, L_8005595C
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8005595C;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80054368
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_80054368(rdram, ctx);
    goto after_7;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_7:
    // j           L_8005595C
    // nop

    goto L_8005595C;
    // nop

L_80055588:
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // addiu       $v1, $a1, 0x5948
    ctx->r3 = ADD32(ctx->r5, 0X5948);
    // sh          $a0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r4;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // lw          $a2, 0x14($sp)
    ctx->r6 = MEM_W(0X14, ctx->r29);
    // lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(0X18, ctx->r29);
    // lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(0X1C, ctx->r29);
    // sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // sw          $a2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r6;
    // sw          $a3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r7;
    // sw          $t0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r8;
    // addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s7, $v0, 0x2230
    ctx->r23 = ADD32(ctx->r2, 0X2230);
    // addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // addiu       $s6, $zero, 0xFF
    ctx->r22 = ADD32(0, 0XFF);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $fp, $v0, -0x4930
    ctx->r30 = ADD32(ctx->r2, -0X4930);
    // addiu       $v0, $zero, 0x640
    ctx->r2 = ADD32(0, 0X640);
    // sh          $a0, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r4;
    // sh          $v0, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = ctx->r2;
    // sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
    // sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // sh          $zero, 0x22($v1)
    MEM_H(0X22, ctx->r3) = 0;
    // sh          $zero, 0x20($v1)
    MEM_H(0X20, ctx->r3) = 0;
    // sw          $zero, 0x5948($a1)
    MEM_W(0X5948, ctx->r5) = 0;
L_800555FC:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80055600:
    // lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // jal         0x8004F718
    // addiu       $a1, $a1, 0x5948
    ctx->r5 = ADD32(ctx->r5, 0X5948);
    sub_8004F718(rdram, ctx);
    goto after_8;
    // addiu       $a1, $a1, 0x5948
    ctx->r5 = ADD32(ctx->r5, 0X5948);
    after_8:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // beq         $s2, $s5, L_80055940
    if (ctx->r18 == ctx->r21) {
        // sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18) << 1;
        goto L_80055940;
    }
    // sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18) << 1;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $s0, $v0, $s7
    ctx->r16 = ADD32(ctx->r2, ctx->r23);
    // lhu         $v1, 0xA($s0)
    ctx->r3 = MEM_HU(0XA, ctx->r16);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // sw          $s4, -0x2F20($v0)
    MEM_W(-0X2F20, ctx->r2) = ctx->r20;
    // sh          $s4, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r20;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $s7, $v0
    ctx->r2 = ADD32(ctx->r23, ctx->r2);
    // lbu         $v1, -0x1F20($v0)
    ctx->r3 = MEM_BU(-0X1F20, ctx->r2);
    // nop

    // slti        $v0, $v1, 0x34
    ctx->r2 = SIGNED(ctx->r3) < 0X34 ? 1 : 0;
    // beq         $v0, $zero, L_80055688
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x32
        ctx->r2 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
        goto L_80055688;
    }
    // slti        $v0, $v1, 0x32
    ctx->r2 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
    // beq         $v0, $zero, L_800556D8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800556D8;
    }
    // nop

    // bltz        $v1, L_80055934
    if (SIGNED(ctx->r3) < 0) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_80055934;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_800556D8
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0xE
        ctx->r2 = ADD32(0, 0XE);
        goto L_800556D8;
    }
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // beq         $v1, $v0, L_80055874
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80055874;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // j           L_800555FC
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_800555FC;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80055688:
    // addiu       $v0, $zero, 0xE2
    ctx->r2 = ADD32(0, 0XE2);
    // beq         $v1, $v0, L_80055850
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0xE3
        ctx->r2 = SIGNED(ctx->r3) < 0XE3 ? 1 : 0;
        goto L_80055850;
    }
    // slti        $v0, $v1, 0xE3
    ctx->r2 = SIGNED(ctx->r3) < 0XE3 ? 1 : 0;
    // beq         $v0, $zero, L_800556B4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x34
        ctx->r2 = ADD32(0, 0X34);
        goto L_800556B4;
    }
    // addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
    // beq         $v1, $v0, L_800557C4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xE1
        ctx->r2 = ADD32(0, 0XE1);
        goto L_800557C4;
    }
    // addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // beq         $v1, $v0, L_80055818
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80055818;
    }
    // nop

    // j           L_800555FC
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_800555FC;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800556B4:
    // addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // bne         $v1, $v0, L_80055934
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80055934;
    }
    // nop

    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80055934
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80055934;
    }
    // nop

    // j           L_80055934
    // sh          $s4, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r20;
    goto L_80055934;
    // sh          $s4, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r20;
L_800556D8:
    // lbu         $v1, 0x4F($s0)
    ctx->r3 = MEM_BU(0X4F, ctx->r16);
    // addiu       $v0, $zero, 0xFB
    ctx->r2 = ADD32(0, 0XFB);
    // bne         $v1, $v0, L_80055724
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0xFC
        ctx->r2 = ADD32(0, 0XFC);
        goto L_80055724;
    }
    // addiu       $v0, $zero, 0xFC
    ctx->r2 = ADD32(0, 0XFC);
    // lh          $v0, 0x22($s0)
    ctx->r2 = MEM_HS(0X22, ctx->r16);
    // lhu         $v1, 0x22($s0)
    ctx->r3 = MEM_HU(0X22, ctx->r16);
    // slti        $v0, $v0, 0x801
    ctx->r2 = SIGNED(ctx->r2) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_80055700
    if (ctx->r2 != 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80055700;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, -0x1000
    ctx->r2 = ADD32(ctx->r3, -0X1000);
L_80055700:
    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 < 0X7FF ? 1 : 0;
    // beq         $v0, $zero, L_80055768
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80055768;
    }
    // nop

    // jal         0x80057D58
    // nop

    sub_80057D58(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // j           L_80055768
    // sb          $s6, 0x4F($s0)
    MEM_B(0X4F, ctx->r16) = ctx->r22;
    goto L_80055768;
    // sb          $s6, 0x4F($s0)
    MEM_B(0X4F, ctx->r16) = ctx->r22;
L_80055724:
    // bne         $v1, $v0, L_80055768
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80055768;
    }
    // nop

    // lh          $v0, 0x22($s0)
    ctx->r2 = MEM_HS(0X22, ctx->r16);
    // lhu         $v1, 0x22($s0)
    ctx->r3 = MEM_HU(0X22, ctx->r16);
    // slti        $v0, $v0, 0x801
    ctx->r2 = SIGNED(ctx->r2) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_80055744
    if (ctx->r2 != 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80055744;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, -0x1000
    ctx->r2 = ADD32(ctx->r3, -0X1000);
L_80055744:
    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x801
    ctx->r2 = ctx->r2 < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_80055768
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80055768;
    }
    // nop

    // jal         0x80057D58
    // nop

    sub_80057D58(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x4F($s0)
    MEM_B(0X4F, ctx->r16) = ctx->r2;
L_80055768:
    // lbu         $v0, 0x4F($s0)
    ctx->r2 = MEM_BU(0X4F, ctx->r16);
    // nop

    // bne         $v0, $s6, L_800557A4
    if (ctx->r2 != ctx->r22) {
        // addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
        goto L_800557A4;
    }
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8005578C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005578C;
    }
    // nop

    // sh          $s4, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r20;
L_8005578C:
    // lhu         $v1, 0xC($s0)
    ctx->r3 = MEM_HU(0XC, ctx->r16);
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // bne         $v1, $v0, L_80055934
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_80055934;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // j           L_80055934
    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    goto L_80055934;
    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
L_800557A4:
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_80055934
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80055934;
    }
    // nop

    // jal         0x80057D7C
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    sub_80057D7C(rdram, ctx);
    goto after_11;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    after_11:
    // j           L_80055600
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    goto L_80055600;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_800557C4:
    // lbu         $v1, 0x4F($s0)
    ctx->r3 = MEM_BU(0X4F, ctx->r16);
    // nop

    // bne         $v1, $s6, L_80055934
    if (ctx->r3 != ctx->r22) {
        // nop
    
        goto L_80055934;
    }
    // nop

    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // bne         $v0, $zero, L_800557F0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800557F0;
    }
    // nop

    // sh          $s4, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r20;
    // sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
L_800557F0:
    // nop

    // bne         $v0, $v1, L_80055934
    if (ctx->r2 != ctx->r3) {
        // addiu       $v0, $zero, 0xFC
        ctx->r2 = ADD32(0, 0XFC);
        goto L_80055934;
    }
    // addiu       $v0, $zero, 0xFC
    ctx->r2 = ADD32(0, 0XFC);
    // lbu         $v1, 0x49($s0)
    ctx->r3 = MEM_BU(0X49, ctx->r16);
    // nop

    // beq         $v1, $v0, L_80055934
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_80055934;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // j           L_80055934
    // sb          $s4, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r20;
    goto L_80055934;
    // sb          $s4, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r20;
L_80055818:
    // lhu         $v0, 0x36($s0)
    ctx->r2 = MEM_HU(0X36, ctx->r16);
    // lhu         $v1, 0x20($s0)
    ctx->r3 = MEM_HU(0X20, ctx->r16);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // sltiu       $v0, $v0, 0xC01
    ctx->r2 = ctx->r2 < 0XC01 ? 1 : 0;
    // bne         $v0, $zero, L_80055934
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80055934;
    }
    // nop

    // lbu         $a0, 0x48($s0)
    ctx->r4 = MEM_BU(0X48, ctx->r16);
    // jal         0x80054858
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    sub_80054858(rdram, ctx);
    goto after_12;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    after_12:
    // j           L_80055600
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    goto L_80055600;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80055850:
    // addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v1, -0x70D8($v0)
    ctx->r3 = MEM_HU(-0X70D8, ctx->r2);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // jal         0x800582F0
    // sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    sub_800582F0(rdram, ctx);
    goto after_13;
    // sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    after_13:
    // j           L_800555FC
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    goto L_800555FC;
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80055874:
    // lh          $v1, 0x5920($v0)
    ctx->r3 = MEM_HS(0X5920, ctx->r2);
    // nop

    // beq         $v1, $s4, L_80055934
    if (ctx->r3 == ctx->r20) {
        // addiu       $s0, $v0, 0x5920
        ctx->r16 = ADD32(ctx->r2, 0X5920);
        goto L_80055934;
    }
    // addiu       $s0, $v0, 0x5920
    ctx->r16 = ADD32(ctx->r2, 0X5920);
    // lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(0X18, ctx->r16);
    // nop

    // bne         $v0, $s5, L_80055934
    if (ctx->r2 != ctx->r21) {
        // nop
    
        goto L_80055934;
    }
    // nop

    // jal         0x80015AD4
    // sb          $s4, 0xA($fp)
    MEM_B(0XA, ctx->r30) = ctx->r20;
    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_14;
    // sb          $s4, 0xA($fp)
    MEM_B(0XA, ctx->r30) = ctx->r20;
    after_14:
    // addiu       $s1, $zero, 0xEF
    ctx->r17 = ADD32(0, 0XEF);
    // addiu       $s3, $zero, 0xEC
    ctx->r19 = ADD32(0, 0XEC);
    // lbu         $a0, 0x4($s0)
    ctx->r4 = MEM_BU(0X4, ctx->r16);
    // jal         0x80055CF4
    // addiu       $s0, $s7, 0x54
    ctx->r16 = ADD32(ctx->r23, 0X54);
    sub_80055CF4(rdram, ctx);
    goto after_15;
    // addiu       $s0, $s7, 0x54
    ctx->r16 = ADD32(ctx->r23, 0X54);
    after_15:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // jal         0x80042CFC
    // nop

    sub_80042CFC(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_18;
    // nop

    after_18:
    // jal         0x80057A68
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80057A68(rdram, ctx);
    goto after_19;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_19:
L_800558D0:
    // lbu         $v0, -0x4F($s0)
    ctx->r2 = MEM_BU(-0X4F, ctx->r16);
    // nop

    // bne         $v0, $s3, L_80055900
    if (ctx->r2 != ctx->r19) {
        // nop
    
        goto L_80055900;
    }
    // nop

    // lh          $a0, 0x0($s0)
    ctx->r4 = MEM_HS(0X0, ctx->r16);
    // nop

    // beq         $a0, $s5, L_80055900
    if (ctx->r4 == ctx->r21) {
        // nop
    
        goto L_80055900;
    }
    // nop

    // lbu         $a1, -0xA($s0)
    ctx->r5 = MEM_BU(-0XA, ctx->r16);
    // jal         0x8005850C
    // addiu       $a1, $a1, 0x454
    ctx->r5 = ADD32(ctx->r5, 0X454);
    sub_8005850C(rdram, ctx);
    goto after_20;
    // addiu       $a1, $a1, 0x454
    ctx->r5 = ADD32(ctx->r5, 0X454);
    after_20:
    // sh          $s5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r21;
L_80055900:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s5, L_800558D0
    if (ctx->r17 != ctx->r21) {
        // addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
        goto L_800558D0;
    }
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // jal         0x80058DC4
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    sub_80058DC4(rdram, ctx);
    goto after_21;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_21:
    // jal         0x80062C28
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sub_80062C28(rdram, ctx);
    goto after_22;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_22:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // jal         0x80057A3C
    // sb          $v0, 0xA($fp)
    MEM_B(0XA, ctx->r30) = ctx->r2;
    sub_80057A3C(rdram, ctx);
    goto after_23;
    // sb          $v0, 0xA($fp)
    MEM_B(0XA, ctx->r30) = ctx->r2;
    after_23:
    // jal         0x80058ED4
    // nop

    sub_80058ED4(rdram, ctx);
    goto after_24;
    // nop

    after_24:
L_80055934:
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // j           L_80055600
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    goto L_80055600;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80055940:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v0, 0x592C($v0)
    ctx->r2 = MEM_W(0X592C, ctx->r2);
    // lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(0X74, ctx->r29);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // jalr        $v0
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_25;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_25:
L_8005595C:
    // lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(0X6C, ctx->r29);
    // lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(0X68, ctx->r29);
    // lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(0X64, ctx->r29);
    // lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(0X60, ctx->r29);
    // lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(0X5C, ctx->r29);
    // lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(0X58, ctx->r29);
    // lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(0X54, ctx->r29);
    // lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(0X50, ctx->r29);
    // lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(0X4C, ctx->r29);
    // lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(0X48, ctx->r29);
    // addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // jr          $ra
    // nop

    return;
    // nop

;}
