#include "recomp.h"
#include "disable_warnings.h"

void sub_80052F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addiu       $s2, $v0, -0x51F8
    ctx->r18 = ADD32(ctx->r2, -0X51F8);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // addiu       $s5, $s2, -0x35F8
    ctx->r21 = ADD32(ctx->r18, -0X35F8);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addiu       $s6, $s2, -0x3710
    ctx->r22 = ADD32(ctx->r18, -0X3710);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addiu       $s1, $s4, 0x2
    ctx->r17 = ADD32(ctx->r20, 0X2);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $s2, 0x22
    ctx->r16 = ADD32(ctx->r18, 0X22);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sb          $zero, -0x3710($s2)
    MEM_B(-0X3710, ctx->r18) = 0;
L_80052F78:
    // lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(0X0, ctx->r20);
    // nop

    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(0X14, ctx->r17);
    // nop

    // sh          $v0, -0x20($s0)
    MEM_H(-0X20, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(0X2, ctx->r17);
    // lh          $v1, 0x6($s1)
    ctx->r3 = MEM_HS(0X6, ctx->r17);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, -0x1A($s0)
    MEM_W(-0X1A, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(0X3, ctx->r17);
    // lh          $v1, 0x8($s1)
    ctx->r3 = MEM_HS(0X8, ctx->r17);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, -0x16($s0)
    MEM_W(-0X16, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x4($s1)
    ctx->r2 = MEM_BU(0X4, ctx->r17);
    // lh          $v1, 0xA($s1)
    ctx->r3 = MEM_HS(0XA, ctx->r17);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, -0x12($s0)
    MEM_W(-0X12, ctx->r16) = ctx->r2;
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sh          $v0, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = ctx->r2;
    // lhu         $v0, 0xE($s1)
    ctx->r2 = MEM_HU(0XE, ctx->r17);
    // nop

    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sh          $v0, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x10($s1)
    ctx->r2 = MEM_HU(0X10, ctx->r17);
    // nop

    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sh          $v0, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // sh          $v0, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r2;
    // lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(0X0, ctx->r18);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_800530E4
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_800530E4;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v1, 0x5929($v0)
    ctx->r3 = MEM_BU(0X5929, ctx->r2);
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // nop

    // sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2) << 1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // addu        $a1, $a1, $s5
    ctx->r5 = ADD32(ctx->r5, ctx->r21);
    // sb          $v1, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r3;
    // lbu         $v0, 0x6($a1)
    ctx->r2 = MEM_BU(0X6, ctx->r5);
    // nop

    // sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // lhu         $a2, 0x0($s2)
    ctx->r6 = MEM_HU(0X0, ctx->r18);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // srl         $a0, $a2, 5
    ctx->r4 = S32(U32(ctx->r6) >> 5);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    // andi        $a2, $a2, 0x1F
    ctx->r6 = ctx->r6 & 0X1F;
    // lw          $v1, 0x48($a0)
    ctx->r3 = MEM_W(0X48, ctx->r4);
    // sllv        $v0, $v0, $a2
    ctx->r2 = S32(ctx->r2) << (ctx->r6 & 31);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r3;
    // lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(0X1, ctx->r22);
    // lbu         $v1, -0x118($s5)
    ctx->r3 = MEM_BU(-0X118, ctx->r21);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sb          $v0, 0x1($s6)
    MEM_B(0X1, ctx->r22) = ctx->r2;
    // sb          $v1, -0x118($s5)
    MEM_B(-0X118, ctx->r21) = ctx->r3;
    // lbu         $v0, 0x4($a1)
    ctx->r2 = MEM_BU(0X4, ctx->r5);
    // nop

    // addu        $a0, $v0, $s6
    ctx->r4 = ADD32(ctx->r2, ctx->r22);
    // lbu         $v1, 0x94($a0)
    ctx->r3 = MEM_BU(0X94, ctx->r4);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // bne         $v1, $v0, L_800530C0
    if (ctx->r3 != ctx->r2) {
        // slti        $v0, $s3, 0x1C
        ctx->r2 = SIGNED(ctx->r19) < 0X1C ? 1 : 0;
        goto L_800530C0;
    }
    // slti        $v0, $s3, 0x1C
    ctx->r2 = SIGNED(ctx->r19) < 0X1C ? 1 : 0;
    // lw          $v0, -0x4($s5)
    ctx->r2 = MEM_W(-0X4, ctx->r21);
    // nop

    // sb          $v0, 0x94($a0)
    MEM_B(0X94, ctx->r4) = ctx->r2;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, -0x4($s5)
    MEM_W(-0X4, ctx->r21) = ctx->r2;
    // slti        $v0, $s3, 0x1C
    ctx->r2 = SIGNED(ctx->r19) < 0X1C ? 1 : 0;
L_800530C0:
    // beq         $v0, $zero, L_800530DC
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_800530DC;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(0X0, ctx->r18);
    // jal         0x80052D40
    // nop

    sub_80052D40(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // beq         $v0, $zero, L_800530E4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_800530E4;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800530DC:
    // j           L_800530E8
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    goto L_800530E8;
    // sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_800530E4:
    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_800530E8:
    // addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
    // addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // slti        $v0, $s3, 0x20
    ctx->r2 = SIGNED(ctx->r19) < 0X20 ? 1 : 0;
    // bne         $v0, $zero, L_80052F78
    if (ctx->r2 != 0) {
        // addiu       $s4, $s4, 0x18
        ctx->r20 = ADD32(ctx->r20, 0X18);
        goto L_80052F78;
    }
    // addiu       $s4, $s4, 0x18
    ctx->r20 = ADD32(ctx->r20, 0X18);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s2, $v0, -0x4BF8
    ctx->r18 = ADD32(ctx->r2, -0X4BF8);
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_80053110:
    // lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(0X0, ctx->r18);
    // jal         0x80052D40
    // nop

    sub_80052D40(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // bne         $v0, $zero, L_80053134
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80053134;
    }
    // nop

    // jal         0x80052E50
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_80052E50(rdram, ctx);
    goto after_2;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_2:
    // j           L_8005313C
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    goto L_8005313C;
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80053134:
    // addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8005313C:
    // slti        $v0, $s3, 0x10
    ctx->r2 = SIGNED(ctx->r19) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80053110
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80053110;
    }
    // nop

    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
    // lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
