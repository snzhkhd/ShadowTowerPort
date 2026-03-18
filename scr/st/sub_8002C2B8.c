#include "recomp.h"
#include "disable_warnings.h"

void sub_8002C2B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // sw          $s0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r16;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x11CC
    ctx->r6 = ADD32(ctx->r2, 0X11CC);
    // addiu       $t0, $a2, 0xC0
    ctx->r8 = ADD32(ctx->r6, 0XC0);
    // sw          $ra, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r31;
    // sw          $s7, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r23;
    // sw          $s6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r22;
    // sw          $s5, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r21;
    // sw          $s4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r20;
    // sw          $s3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r19;
    // sw          $s2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r18;
    // sw          $s1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r17;
L_8002C2F4:
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
    // bne         $a2, $t0, L_8002C2F4
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8002C2F4;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
    // sb          $v1, 0x33A($s0)
    MEM_B(0X33A, ctx->r16) = ctx->r3;
    // sb          $v1, 0x339($s0)
    MEM_B(0X339, ctx->r16) = ctx->r3;
    // sb          $v1, 0x338($s0)
    MEM_B(0X338, ctx->r16) = ctx->r3;
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_8002C494
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8002C494;
    }
    // nop

    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // beq         $v0, $zero, L_8002C360
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0x144
        ctx->r3 = ADD32(0, 0X144);
        goto L_8002C360;
    }
    // addiu       $v1, $zero, 0x144
    ctx->r3 = ADD32(0, 0X144);
    // addiu       $v1, $zero, 0x143
    ctx->r3 = ADD32(0, 0X143);
L_8002C360:
    // addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // addiu       $s1, $s0, 0x300
    ctx->r17 = ADD32(ctx->r16, 0X300);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $s2, $v0, 0xD50
    ctx->r18 = ADD32(ctx->r2, 0XD50);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(0X0, ctx->r2);
    // addiu       $s3, $s2, 0xC00
    ctx->r19 = ADD32(ctx->r18, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    sub_8002732C(rdram, ctx);
    goto after_0;
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    after_0:
    // lhu         $v1, 0x202($s0)
    ctx->r3 = MEM_HU(0X202, ctx->r16);
    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // sb          $v0, 0x300($s0)
    MEM_B(0X300, ctx->r16) = ctx->r2;
    // sb          $v0, 0x301($s0)
    MEM_B(0X301, ctx->r16) = ctx->r2;
    // beq         $v1, $zero, L_8002C3D4
    if (ctx->r3 == 0) {
        // sb          $v0, 0x302($s0)
        MEM_B(0X302, ctx->r16) = ctx->r2;
        goto L_8002C3D4;
    }
    // sb          $v0, 0x302($s0)
    MEM_B(0X302, ctx->r16) = ctx->r2;
    // addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // lhu         $a0, 0x28A($s2)
    ctx->r4 = MEM_HU(0X28A, ctx->r18);
    // ori         $a3, $s0, 0x308
    ctx->r7 = ctx->r16 | 0X308;
    // jal         0x8002732C
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    sub_8002732C(rdram, ctx);
    goto after_1;
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    after_1:
    // addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    // addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // lhu         $a0, 0x28C($s2)
    ctx->r4 = MEM_HU(0X28C, ctx->r18);
    // j           L_8002C3FC
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    goto L_8002C3FC;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
L_8002C3D4:
    // addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // lhu         $a0, 0x28A($s2)
    ctx->r4 = MEM_HU(0X28A, ctx->r18);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // jal         0x8002732C
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    sub_8002732C(rdram, ctx);
    goto after_2;
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    after_2:
    // addiu       $a1, $zero, 0xBE
    ctx->r5 = ADD32(0, 0XBE);
    // addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // lhu         $a0, 0x28C($s2)
    ctx->r4 = MEM_HU(0X28C, ctx->r18);
    // ori         $a3, $s0, 0x308
    ctx->r7 = ctx->r16 | 0X308;
L_8002C3FC:
    // jal         0x8002732C
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    sub_8002732C(rdram, ctx);
    goto after_3;
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    after_3:
    // ori         $a0, $s0, 0x348
    ctx->r4 = ctx->r16 | 0X348;
    // ori         $a1, $s0, 0x344
    ctx->r5 = ctx->r16 | 0X344;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // addiu       $v0, $zero, 0x48
    ctx->r2 = ADD32(0, 0X48);
    // sb          $v0, 0x300($s0)
    MEM_B(0X300, ctx->r16) = ctx->r2;
    // sb          $v0, 0x301($s0)
    MEM_B(0X301, ctx->r16) = ctx->r2;
    // sb          $v0, 0x302($s0)
    MEM_B(0X302, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // sh          $v0, 0x33C($s0)
    MEM_H(0X33C, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // sh          $v0, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    // sh          $v0, 0x340($s0)
    MEM_H(0X340, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // sh          $v0, 0x342($s0)
    MEM_H(0X342, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x3D
    ctx->r2 = ADD32(0, 0X3D);
    // sh          $v0, 0x348($s0)
    MEM_H(0X348, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x79
    ctx->r2 = ADD32(0, 0X79);
    // sh          $v0, 0x34A($s0)
    MEM_H(0X34A, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xC6
    ctx->r2 = ADD32(0, 0XC6);
    // sh          $v0, 0x34C($s0)
    MEM_H(0X34C, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sh          $v0, 0x34E($s0)
    MEM_H(0X34E, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sb          $v0, 0x346($s0)
    MEM_B(0X346, ctx->r16) = ctx->r2;
    // sb          $v0, 0x345($s0)
    MEM_B(0X345, ctx->r16) = ctx->r2;
    // jal         0x80028220
    // sb          $v0, 0x344($s0)
    MEM_B(0X344, ctx->r16) = ctx->r2;
    sub_80028220(rdram, ctx);
    goto after_4;
    // sb          $v0, 0x344($s0)
    MEM_B(0X344, ctx->r16) = ctx->r2;
    after_4:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_5;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_5:
    // ori         $a0, $s0, 0x33C
    ctx->r4 = ctx->r16 | 0X33C;
    // ori         $a1, $s0, 0x338
    ctx->r5 = ctx->r16 | 0X338;
    // jal         0x80028220
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80028220(rdram, ctx);
    goto after_6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
L_8002C494:
    // lhu         $v0, 0x1FA($s0)
    ctx->r2 = MEM_HU(0X1FA, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_8002C568
    if (ctx->r2 != 0) {
        // ori         $a0, $s0, 0x330
        ctx->r4 = ctx->r16 | 0X330;
        goto L_8002C568;
    }
    // ori         $a0, $s0, 0x330
    ctx->r4 = ctx->r16 | 0X330;
    // lhu         $v0, 0x200($s0)
    ctx->r2 = MEM_HU(0X200, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_8002C500
    if (SIGNED(ctx->r2) <= 0) {
        // ori         $a0, $s0, 0x33C
        ctx->r4 = ctx->r16 | 0X33C;
        goto L_8002C500;
    }
    // ori         $a0, $s0, 0x33C
    ctx->r4 = ctx->r16 | 0X33C;
    // ori         $a1, $s0, 0x32C
    ctx->r5 = ctx->r16 | 0X32C;
    // addiu       $a2, $zero, 0xC00
    ctx->r6 = ADD32(0, 0XC00);
    // addiu       $v0, $zero, 0x9C
    ctx->r2 = ADD32(0, 0X9C);
    // sh          $v0, 0x33C($s0)
    MEM_H(0X33C, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x44
    ctx->r2 = ADD32(0, 0X44);
    // sh          $v0, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x340($s0)
    MEM_H(0X340, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // jal         0x8002916C
    // sh          $v0, 0x342($s0)
    MEM_H(0X342, ctx->r16) = ctx->r2;
    sub_8002916C(rdram, ctx);
    goto after_7;
    // sh          $v0, 0x342($s0)
    MEM_H(0X342, ctx->r16) = ctx->r2;
    after_7:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_8;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_8:
L_8002C500:
    // lhu         $v1, 0x200($s0)
    ctx->r3 = MEM_HU(0X200, ctx->r16);
    // lhu         $v0, 0x1FA($s0)
    ctx->r2 = MEM_HU(0X1FA, ctx->r16);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8002C564
    if (ctx->r3 == 0) {
        // ori         $a0, $s0, 0x33C
        ctx->r4 = ctx->r16 | 0X33C;
        goto L_8002C564;
    }
    // ori         $a0, $s0, 0x33C
    ctx->r4 = ctx->r16 | 0X33C;
    // ori         $a1, $s0, 0x32C
    ctx->r5 = ctx->r16 | 0X32C;
    // addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // addiu       $v0, $zero, 0x9C
    ctx->r2 = ADD32(0, 0X9C);
    // sh          $v0, 0x33C($s0)
    MEM_H(0X33C, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xD7
    ctx->r2 = ADD32(0, 0XD7);
    // sh          $v0, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x340($s0)
    MEM_H(0X340, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // jal         0x8002916C
    // sh          $v0, 0x342($s0)
    MEM_H(0X342, ctx->r16) = ctx->r2;
    sub_8002916C(rdram, ctx);
    goto after_9;
    // sh          $v0, 0x342($s0)
    MEM_H(0X342, ctx->r16) = ctx->r2;
    after_9:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_10;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_10:
L_8002C564:
    // ori         $a0, $s0, 0x330
    ctx->r4 = ctx->r16 | 0X330;
L_8002C568:
    // ori         $a1, $s0, 0x32C
    ctx->r5 = ctx->r16 | 0X32C;
    // addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // lhu         $v1, 0x1FE($s0)
    ctx->r3 = MEM_HU(0X1FE, ctx->r16);
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sh          $v0, 0x330($s0)
    MEM_H(0X330, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $v0, 0x334($s0)
    MEM_H(0X334, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // sh          $v0, 0x336($s0)
    MEM_H(0X336, ctx->r16) = ctx->r2;
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
    // addiu       $v0, $v0, 0x4A
    ctx->r2 = ADD32(ctx->r2, 0X4A);
    // jal         0x80027D18
    // sh          $v0, 0x332($s0)
    MEM_H(0X332, ctx->r16) = ctx->r2;
    sub_80027D18(rdram, ctx);
    goto after_11;
    // sh          $v0, 0x332($s0)
    MEM_H(0X332, ctx->r16) = ctx->r2;
    after_11:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_12;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_12:
    // lhu         $v0, 0x1FA($s0)
    ctx->r2 = MEM_HU(0X1FA, ctx->r16);
    // addiu       $v1, $zero, 0x4A
    ctx->r3 = ADD32(0, 0X4A);
    // sh          $v1, 0x332($s0)
    MEM_H(0X332, ctx->r16) = ctx->r3;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // beq         $v0, $zero, L_8002C5E8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002C5E8;
    }
    // nop

    // addu        $s6, $v1, $zero
    ctx->r22 = ADD32(ctx->r3, 0);
L_8002C5E8:
    // blez        $s6, L_8002C87C
    if (SIGNED(ctx->r22) <= 0) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_8002C87C;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $s3, $v0, 0xD50
    ctx->r19 = ADD32(ctx->r2, 0XD50);
    // addiu       $s4, $s3, 0xC00
    ctx->r20 = ADD32(ctx->r19, 0XC00);
    // addiu       $s2, $s0, 0x300
    ctx->r18 = ADD32(ctx->r16, 0X300);
    // addiu       $s5, $sp, 0x10
    ctx->r21 = ADD32(ctx->r29, 0X10);
    // addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
L_8002C608:
    // lhu         $v0, 0x1FC($s0)
    ctx->r2 = MEM_HU(0X1FC, ctx->r16);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_8002C670
    if (ctx->r2 != ctx->r3) {
        // addiu       $a1, $zero, 0x26
        ctx->r5 = ADD32(0, 0X26);
        goto L_8002C670;
    }
    // addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // lhu         $v1, 0x200($s0)
    ctx->r3 = MEM_HU(0X200, ctx->r16);
    // lhu         $v0, 0x1FA($s0)
    ctx->r2 = MEM_HU(0X1FA, ctx->r16);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $v1, $v0, L_8002C674
    if (ctx->r3 != ctx->r2) {
        // addu        $a3, $s2, $zero
        ctx->r7 = ADD32(ctx->r18, 0);
        goto L_8002C674;
    }
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // addiu       $a3, $s0, 0x300
    ctx->r7 = ADD32(ctx->r16, 0X300);
    // lhu         $a0, 0x284($s3)
    ctx->r4 = MEM_HU(0X284, ctx->r19);
    // lhu         $a2, 0x332($s0)
    ctx->r6 = MEM_HU(0X332, ctx->r16);
    // addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // jal         0x8002732C
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    sub_8002732C(rdram, ctx);
    goto after_13;
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_13:
    // j           L_8002C828
    // addiu       $a0, $s0, 0x330
    ctx->r4 = ADD32(ctx->r16, 0X330);
    goto L_8002C828;
    // addiu       $a0, $s0, 0x330
    ctx->r4 = ADD32(ctx->r16, 0X330);
L_8002C670:
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
L_8002C674:
    // lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // lhu         $a0, 0x200($s0)
    ctx->r4 = MEM_HU(0X200, ctx->r16);
    // lhu         $a2, 0x332($s0)
    ctx->r6 = MEM_HU(0X332, ctx->r16);
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // jal         0x800276BC
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    sub_800276BC(rdram, ctx);
    goto after_14;
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_14:
    // addiu       $a1, $zero, 0xDA
    ctx->r5 = ADD32(0, 0XDA);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // lhu         $a0, 0x290($s3)
    ctx->r4 = MEM_HU(0X290, ctx->r19);
    // lhu         $a2, 0x332($s0)
    ctx->r6 = MEM_HU(0X332, ctx->r16);
    // addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // jal         0x8002732C
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    sub_8002732C(rdram, ctx);
    goto after_15;
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_15:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E54($at)
    MEM_H(-0X7E54, ctx->r1) = ctx->r2;
    // lhu         $v0, 0x200($s0)
    ctx->r2 = MEM_HU(0X200, ctx->r16);
    // addiu       $v1, $zero, 0x118
    ctx->r3 = ADD32(0, 0X118);
    // sh          $v1, 0x2FC($gp)
    MEM_H(0X2FC, ctx->r28) = ctx->r3;
    // lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(0X1F4, ctx->r16);
    // sw          $zero, 0x304($gp)
    MEM_W(0X304, ctx->r28) = 0;
    // sh          $zero, 0x2FA($gp)
    MEM_H(0X2FA, ctx->r28) = 0;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x19($v1)
    ctx->r2 = MEM_BU(0X19, ctx->r3);
    // nop

    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // beq         $v0, $s7, L_8002C798
    if (ctx->r2 == ctx->r23) {
        // addiu       $a1, $zero, 0x40
        ctx->r5 = ADD32(0, 0X40);
        goto L_8002C798;
    }
    // addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // lhu         $a0, 0x4C4($v0)
    ctx->r4 = MEM_HU(0X4C4, ctx->r2);
    // lhu         $a2, 0x332($s0)
    ctx->r6 = MEM_HU(0X332, ctx->r16);
    // addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // jal         0x8002732C
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    sub_8002732C(rdram, ctx);
    goto after_16;
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    after_16:
    // lhu         $v0, 0x200($s0)
    ctx->r2 = MEM_HU(0X200, ctx->r16);
    // lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(0X1F4, ctx->r16);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v1, 0x19($v1)
    ctx->r3 = MEM_BU(0X19, ctx->r3);
    // nop

    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // beq         $v0, $s7, L_8002C798
    if (ctx->r2 == ctx->r23) {
        // addiu       $a1, $zero, 0x40
        ctx->r5 = ADD32(0, 0X40);
        goto L_8002C798;
    }
    // addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // lhu         $a0, 0x578($v0)
    ctx->r4 = MEM_HU(0X578, ctx->r2);
    // lhu         $a2, 0x332($s0)
    ctx->r6 = MEM_HU(0X332, ctx->r16);
    // addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // addiu       $a2, $a2, 0x16
    ctx->r6 = ADD32(ctx->r6, 0X16);
    // j           L_8002C7DC
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    goto L_8002C7DC;
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
L_8002C798:
    // addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // addiu       $a3, $s0, 0x300
    ctx->r7 = ADD32(ctx->r16, 0X300);
    // lhu         $v0, 0x200($s0)
    ctx->r2 = MEM_HU(0X200, ctx->r16);
    // lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(0X1F4, ctx->r16);
    // lhu         $a2, 0x332($s0)
    ctx->r6 = MEM_HU(0X332, ctx->r16);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x19($v1)
    ctx->r2 = MEM_BU(0X19, ctx->r3);
    // addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // lhu         $a0, 0x578($v0)
    ctx->r4 = MEM_HU(0X578, ctx->r2);
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
L_8002C7DC:
    // jal         0x8002732C
    // nop

    sub_8002732C(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // addiu       $a1, $zero, 0xF8
    ctx->r5 = ADD32(0, 0XF8);
    // addiu       $a3, $s0, 0x300
    ctx->r7 = ADD32(ctx->r16, 0X300);
    // lui         $a0, 0x400
    ctx->r4 = S32(0X400 << 16);
    // lhu         $a2, 0x332($s0)
    ctx->r6 = MEM_HU(0X332, ctx->r16);
    // lhu         $v0, 0x200($s0)
    ctx->r2 = MEM_HU(0X200, ctx->r16);
    // lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(0X1F4, ctx->r16);
    // addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x1A($v1)
    ctx->r2 = MEM_HU(0X1A, ctx->r3);
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // jal         0x800276BC
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    sub_800276BC(rdram, ctx);
    goto after_18;
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    after_18:
    // addiu       $a0, $s0, 0x330
    ctx->r4 = ADD32(ctx->r16, 0X330);
L_8002C828:
    // addiu       $a1, $s0, 0x338
    ctx->r5 = ADD32(ctx->r16, 0X338);
    // addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $v1, $v1, -0x4150
    ctx->r3 = ADD32(ctx->r3, -0X4150);
    // lhu         $v0, 0x200($s0)
    ctx->r2 = MEM_HU(0X200, ctx->r16);
    // lw          $t0, 0x308($gp)
    ctx->r8 = MEM_W(0X308, ctx->r28);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80027D18
    // sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    sub_80027D18(rdram, ctx);
    goto after_19;
    // sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    after_19:
    // lhu         $v0, 0x332($s0)
    ctx->r2 = MEM_HU(0X332, ctx->r16);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // sh          $v0, 0x332($s0)
    MEM_H(0X332, ctx->r16) = ctx->r2;
    // slt         $v0, $s1, $s6
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r22) ? 1 : 0;
    // bne         $v0, $zero, L_8002C608
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002C608;
    }
    // nop

L_8002C87C:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_20;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_20:
    // lw          $ra, 0xF8($sp)
    ctx->r31 = MEM_W(0XF8, ctx->r29);
    // lw          $s7, 0xF4($sp)
    ctx->r23 = MEM_W(0XF4, ctx->r29);
    // lw          $s6, 0xF0($sp)
    ctx->r22 = MEM_W(0XF0, ctx->r29);
    // lw          $s5, 0xEC($sp)
    ctx->r21 = MEM_W(0XEC, ctx->r29);
    // lw          $s4, 0xE8($sp)
    ctx->r20 = MEM_W(0XE8, ctx->r29);
    // lw          $s3, 0xE4($sp)
    ctx->r19 = MEM_W(0XE4, ctx->r29);
    // lw          $s2, 0xE0($sp)
    ctx->r18 = MEM_W(0XE0, ctx->r29);
    // lw          $s1, 0xDC($sp)
    ctx->r17 = MEM_W(0XDC, ctx->r29);
    // lw          $s0, 0xD8($sp)
    ctx->r16 = MEM_W(0XD8, ctx->r29);
    // addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    // jr          $ra
    // nop

    return;
    // nop

;}
