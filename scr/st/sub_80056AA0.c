#include "recomp.h"
#include "disable_warnings.h"

void sub_80056AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v0, $v0, 0x5920
    ctx->r2 = ADD32(ctx->r2, 0X5920);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lwl         $v1, 0x7($s3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r19);
    // lwr         $v1, 0x4($s3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r19);
    // lb          $a0, 0x8($s3)
    ctx->r4 = MEM_BS(0X8, ctx->r19);
    // swl         $v1, 0x7($v0)
    do_swl(rdram, 0X7, ctx->r2, ctx->r3);
    // swr         $v1, 0x4($v0)
    do_swr(rdram, 0X4, ctx->r2, ctx->r3);
    // sb          $a0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r4;
    // lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // addiu       $s0, $s0, -0x45F8
    ctx->r16 = ADD32(ctx->r16, -0X45F8);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s3, 0xC
    ctx->r5 = ADD32(ctx->r19, 0XC);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    sub_80014CFC(rdram, ctx);
    goto after_0;
    // addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_0:
    // addiu       $a0, $s0, 0x180
    ctx->r4 = ADD32(ctx->r16, 0X180);
    // addiu       $a1, $s3, 0x18C
    ctx->r5 = ADD32(ctx->r19, 0X18C);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    sub_80014CFC(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_1:
    // addiu       $a0, $s0, 0x240
    ctx->r4 = ADD32(ctx->r16, 0X240);
    // addiu       $a1, $s3, 0x24C
    ctx->r5 = ADD32(ctx->r19, 0X24C);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    sub_80014CFC(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    after_2:
    // addiu       $a0, $s0, 0x840
    ctx->r4 = ADD32(ctx->r16, 0X840);
    // addiu       $a1, $s3, 0x84C
    ctx->r5 = ADD32(ctx->r19, 0X84C);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    sub_80014CFC(rdram, ctx);
    goto after_3;
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    after_3:
    // addiu       $a0, $s0, 0xE40
    ctx->r4 = ADD32(ctx->r16, 0XE40);
    // addiu       $a1, $s3, 0xE4C
    ctx->r5 = ADD32(ctx->r19, 0XE4C);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    sub_80014CFC(rdram, ctx);
    goto after_4;
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    after_4:
    // addiu       $a0, $s0, 0x1440
    ctx->r4 = ADD32(ctx->r16, 0X1440);
    // addiu       $a1, $s3, 0x144C
    ctx->r5 = ADD32(ctx->r19, 0X144C);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    sub_80014CFC(rdram, ctx);
    goto after_5;
    // addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
    // addiu       $a0, $s0, 0x1448
    ctx->r4 = ADD32(ctx->r16, 0X1448);
    // addiu       $a1, $s3, 0x1454
    ctx->r5 = ADD32(ctx->r19, 0X1454);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    sub_80014CFC(rdram, ctx);
    goto after_6;
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_6:
    // addiu       $a0, $s0, 0x1478
    ctx->r4 = ADD32(ctx->r16, 0X1478);
    // addiu       $a1, $s3, 0x1484
    ctx->r5 = ADD32(ctx->r19, 0X1484);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    sub_80014CFC(rdram, ctx);
    goto after_7;
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_7:
    // addiu       $a0, $s0, 0x14A8
    ctx->r4 = ADD32(ctx->r16, 0X14A8);
    // addiu       $a1, $s3, 0x14B4
    ctx->r5 = ADD32(ctx->r19, 0X14B4);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    sub_80014CFC(rdram, ctx);
    goto after_8;
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_8:
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_80056B80:
    // sb          $zero, 0x16E4($a1)
    MEM_B(0X16E4, ctx->r5) = 0;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_80056B90:
    // bgez        $a2, L_80056B9C
    if (SIGNED(ctx->r6) >= 0) {
        // addu        $v0, $a2, $zero
        ctx->r2 = ADD32(ctx->r6, 0);
        goto L_80056B9C;
    }
    // addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // addiu       $v0, $a2, 0x1F
    ctx->r2 = ADD32(ctx->r6, 0X1F);
L_80056B9C:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v0, $a2, $v0
    ctx->r2 = SUB32(ctx->r6, ctx->r2);
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // sllv        $v0, $t1, $v0
    ctx->r2 = S32(ctx->r9) << (ctx->r2 & 31);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // beq         $v1, $zero, L_80056BDC
    if (ctx->r3 == 0) {
        // slti        $v0, $a2, 0x30
        ctx->r2 = SIGNED(ctx->r6) < 0X30 ? 1 : 0;
        goto L_80056BDC;
    }
    // slti        $v0, $a2, 0x30
    ctx->r2 = SIGNED(ctx->r6) < 0X30 ? 1 : 0;
    // beq         $v0, $zero, L_80056BDC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80056BDC;
    }
    // nop

    // lbu         $v0, 0x16E4($a0)
    ctx->r2 = MEM_BU(0X16E4, ctx->r4);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x16E4($a0)
    MEM_B(0X16E4, ctx->r4) = ctx->r2;
L_80056BDC:
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slti        $v0, $a2, 0x40
    ctx->r2 = SIGNED(ctx->r6) < 0X40 ? 1 : 0;
    // bne         $v0, $zero, L_80056B90
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80056B90;
    }
    // nop

    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // slti        $v0, $t0, 0x30
    ctx->r2 = SIGNED(ctx->r8) < 0X30 ? 1 : 0;
    // bne         $v0, $zero, L_80056B80
    if (ctx->r2 != 0) {
        // addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_80056B80;
    }
    // addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // lbu         $v0, 0x14C8($s3)
    ctx->r2 = MEM_BU(0X14C8, ctx->r19);
    // addiu       $s0, $s0, 0x76F8
    ctx->r16 = ADD32(ctx->r16, 0X76F8);
    // sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x14C9($s3)
    ctx->r2 = MEM_BU(0X14C9, ctx->r19);
    // addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // sb          $v0, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x14CA($s3)
    ctx->r2 = MEM_BU(0X14CA, ctx->r19);
    // addiu       $a1, $s3, 0x14CC
    ctx->r5 = ADD32(ctx->r19, 0X14CC);
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x14CB($s3)
    ctx->r2 = MEM_BU(0X14CB, ctx->r19);
    // addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // jal         0x80014CFC
    // sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
    sub_80014CFC(rdram, ctx);
    goto after_9;
    // sb          $v0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r2;
    after_9:
    // addiu       $a3, $s0, 0x3D10
    ctx->r7 = ADD32(ctx->r16, 0X3D10);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $t0, $s0, 0x118
    ctx->r8 = ADD32(ctx->r16, 0X118);
    // addiu       $a0, $s0, 0x3D32
    ctx->r4 = ADD32(ctx->r16, 0X3D32);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
L_80056C4C:
    // lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(0X2, ctx->r16);
    // nop

    // slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80056D1C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80056D1C;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lhu         $v0, 0x14F0($a1)
    ctx->r2 = MEM_HU(0X14F0, ctx->r5);
    // nop

    // sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x14F2($a1)
    ctx->r2 = MEM_HU(0X14F2, ctx->r5);
    // nop

    // sh          $v0, -0x20($a0)
    MEM_H(-0X20, ctx->r4) = ctx->r2;
    // lw          $v0, 0x14F4($a1)
    ctx->r2 = MEM_W(0X14F4, ctx->r5);
    // nop

    // sw          $v0, -0x1A($a0)
    MEM_W(-0X1A, ctx->r4) = ctx->r2;
    // lw          $v0, 0x14F8($a1)
    ctx->r2 = MEM_W(0X14F8, ctx->r5);
    // nop

    // sw          $v0, -0x16($a0)
    MEM_W(-0X16, ctx->r4) = ctx->r2;
    // lw          $v0, 0x14FC($a1)
    ctx->r2 = MEM_W(0X14FC, ctx->r5);
    // nop

    // sw          $v0, -0x12($a0)
    MEM_W(-0X12, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x1500($a1)
    ctx->r2 = MEM_HU(0X1500, ctx->r5);
    // nop

    // sh          $v0, -0xA($a0)
    MEM_H(-0XA, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x1502($a1)
    ctx->r2 = MEM_HU(0X1502, ctx->r5);
    // nop

    // sh          $v0, -0x8($a0)
    MEM_H(-0X8, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x1504($a1)
    ctx->r2 = MEM_HU(0X1504, ctx->r5);
    // nop

    // sh          $v0, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1506($a1)
    ctx->r2 = MEM_BU(0X1506, ctx->r5);
    // nop

    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1507($a1)
    ctx->r2 = MEM_BU(0X1507, ctx->r5);
    // nop

    // sb          $v0, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r2;
    // lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(0X0, ctx->r7);
    // sw          $zero, -0x1E($a0)
    MEM_W(-0X1E, ctx->r4) = 0;
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
    // addu        $s2, $v0, $t0
    ctx->r18 = ADD32(ctx->r2, ctx->r8);
    // lhu         $v0, 0x1E($s2)
    ctx->r2 = MEM_HU(0X1E, ctx->r18);
    // sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // sh          $v0, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x6($s2)
    ctx->r2 = MEM_BU(0X6, ctx->r18);
    // j           L_80056D24
    // sb          $v0, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r2;
    goto L_80056D24;
    // sb          $v0, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r2;
L_80056D1C:
    // sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_80056D24:
    // addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // slti        $v0, $a2, 0x10
    ctx->r2 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80056C4C
    if (ctx->r2 != 0) {
        // addiu       $a3, $a3, 0x30
        ctx->r7 = ADD32(ctx->r7, 0X30);
        goto L_80056C4C;
    }
    // addiu       $a3, $a3, 0x30
    ctx->r7 = ADD32(ctx->r7, 0X30);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a3, $v0, -0x48F8
    ctx->r7 = ADD32(ctx->r2, -0X48F8);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $t0, $a3, -0x4010
    ctx->r8 = ADD32(ctx->r7, -0X4010);
    // addiu       $t1, $t0, 0x118
    ctx->r9 = ADD32(ctx->r8, 0X118);
    // addiu       $a0, $a3, 0x22
    ctx->r4 = ADD32(ctx->r7, 0X22);
    // addiu       $a1, $zero, 0x180
    ctx->r5 = ADD32(0, 0X180);
L_80056D58:
    // lbu         $v0, 0x3($t0)
    ctx->r2 = MEM_BU(0X3, ctx->r8);
    // nop

    // slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80056E28
    if (ctx->r2 == 0) {
        // addu        $v1, $s3, $a1
        ctx->r3 = ADD32(ctx->r19, ctx->r5);
        goto L_80056E28;
    }
    // addu        $v1, $s3, $a1
    ctx->r3 = ADD32(ctx->r19, ctx->r5);
    // lhu         $v0, 0x14F0($v1)
    ctx->r2 = MEM_HU(0X14F0, ctx->r3);
    // nop

    // sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // lhu         $v0, 0x14F2($v1)
    ctx->r2 = MEM_HU(0X14F2, ctx->r3);
    // nop

    // sh          $v0, -0x20($a0)
    MEM_H(-0X20, ctx->r4) = ctx->r2;
    // lw          $v0, 0x14F4($v1)
    ctx->r2 = MEM_W(0X14F4, ctx->r3);
    // nop

    // sw          $v0, -0x1A($a0)
    MEM_W(-0X1A, ctx->r4) = ctx->r2;
    // lw          $v0, 0x14F8($v1)
    ctx->r2 = MEM_W(0X14F8, ctx->r3);
    // nop

    // sw          $v0, -0x16($a0)
    MEM_W(-0X16, ctx->r4) = ctx->r2;
    // lw          $v0, 0x14FC($v1)
    ctx->r2 = MEM_W(0X14FC, ctx->r3);
    // nop

    // sw          $v0, -0x12($a0)
    MEM_W(-0X12, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x1500($v1)
    ctx->r2 = MEM_HU(0X1500, ctx->r3);
    // nop

    // sh          $v0, -0xA($a0)
    MEM_H(-0XA, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x1502($v1)
    ctx->r2 = MEM_HU(0X1502, ctx->r3);
    // nop

    // sh          $v0, -0x8($a0)
    MEM_H(-0X8, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x1504($v1)
    ctx->r2 = MEM_HU(0X1504, ctx->r3);
    // nop

    // sh          $v0, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1506($v1)
    ctx->r2 = MEM_BU(0X1506, ctx->r3);
    // nop

    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x1507($v1)
    ctx->r2 = MEM_BU(0X1507, ctx->r3);
    // nop

    // sb          $v0, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r2;
    // lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(0X0, ctx->r7);
    // sw          $zero, -0x1E($a0)
    MEM_W(-0X1E, ctx->r4) = 0;
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
    // addu        $s2, $v0, $t1
    ctx->r18 = ADD32(ctx->r2, ctx->r9);
    // lhu         $v0, 0x1E($s2)
    ctx->r2 = MEM_HU(0X1E, ctx->r18);
    // sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // sh          $v0, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x6($s2)
    ctx->r2 = MEM_BU(0X6, ctx->r18);
    // j           L_80056E34
    // sb          $v0, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r2;
    goto L_80056E34;
    // sb          $v0, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r2;
L_80056E28:
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sh          $v0, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r2;
    // sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_80056E34:
    // addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // slti        $v0, $a2, 0x10
    ctx->r2 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80056D58
    if (ctx->r2 != 0) {
        // addiu       $a3, $a3, 0x30
        ctx->r7 = ADD32(ctx->r7, 0X30);
        goto L_80056D58;
    }
    // addiu       $a3, $a3, 0x30
    ctx->r7 = ADD32(ctx->r7, 0X30);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lw          $v0, 0x17F0($s3)
    ctx->r2 = MEM_W(0X17F0, ctx->r19);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
    // lw          $v0, 0x17F4($s3)
    ctx->r2 = MEM_W(0X17F4, ctx->r19);
    // nop

    // sw          $v0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x17F8($s3)
    ctx->r2 = MEM_HU(0X17F8, ctx->r19);
    // nop

    // sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x17FA($s3)
    ctx->r2 = MEM_HU(0X17FA, ctx->r19);
    // nop

    // sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x17FC($s3)
    ctx->r2 = MEM_HU(0X17FC, ctx->r19);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sh          $v0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r2;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lhu         $a0, 0x17FE($s3)
    ctx->r4 = MEM_HU(0X17FE, ctx->r19);
    // addiu       $a3, $v0, 0x76F8
    ctx->r7 = ADD32(ctx->r2, 0X76F8);
    // sh          $a0, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r4;
    // lbu         $v0, 0x1800($s3)
    ctx->r2 = MEM_BU(0X1800, ctx->r19);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // sb          $v0, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x1801($s3)
    ctx->r2 = MEM_BU(0X1801, ctx->r19);
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // sb          $v0, 0x27($a0)
    MEM_B(0X27, ctx->r4) = ctx->r2;
L_80056EB8:
    // bgez        $a1, L_80056EC4
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_80056EC4;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // addiu       $v0, $a1, 0x1F
    ctx->r2 = ADD32(ctx->r5, 0X1F);
L_80056EC4:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // lw          $v1, 0x70($v1)
    ctx->r3 = MEM_W(0X70, ctx->r3);
    // sllv        $v0, $a2, $v0
    ctx->r2 = S32(ctx->r6) << (ctx->r2 & 31);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // beq         $v1, $zero, L_80056EFC
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80056EFC;
    }
    // nop

    // lhu         $v0, 0x28($a0)
    ctx->r2 = MEM_HU(0X28, ctx->r4);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r2;
L_80056EFC:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x10A
    ctx->r2 = SIGNED(ctx->r5) < 0X10A ? 1 : 0;
    // bne         $v0, $zero, L_80056EB8
    if (ctx->r2 != 0) {
        // lui         $s0, 0x801A
        ctx->r16 = S32(0X801A << 16);
        goto L_80056EB8;
    }
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x70D8
    ctx->r16 = ADD32(ctx->r16, -0X70D8);
    // addiu       $a0, $s0, 0x62
    ctx->r4 = ADD32(ctx->r16, 0X62);
    // addiu       $a1, $s3, 0x1804
    ctx->r5 = ADD32(ctx->r19, 0X1804);
    // lbu         $v0, 0x1803($s3)
    ctx->r2 = MEM_BU(0X1803, ctx->r19);
    // addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // jal         0x80014D2C
    // sb          $v0, 0x32($s0)
    MEM_B(0X32, ctx->r16) = ctx->r2;
    sub_80014D2C(rdram, ctx);
    goto after_10;
    // sb          $v0, 0x32($s0)
    MEM_B(0X32, ctx->r16) = ctx->r2;
    after_10:
    // addiu       $a0, $s0, 0x7E
    ctx->r4 = ADD32(ctx->r16, 0X7E);
    // addiu       $a1, $s3, 0x1820
    ctx->r5 = ADD32(ctx->r19, 0X1820);
    // jal         0x80014D2C
    // addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    sub_80014D2C(rdram, ctx);
    goto after_11;
    // addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_11:
    // addiu       $a0, $s0, 0x9A
    ctx->r4 = ADD32(ctx->r16, 0X9A);
    // addiu       $a1, $s3, 0x183C
    ctx->r5 = ADD32(ctx->r19, 0X183C);
    // jal         0x80014D2C
    // addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    sub_80014D2C(rdram, ctx);
    goto after_12;
    // addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_12:
    // addiu       $a0, $s0, 0x22C
    ctx->r4 = ADD32(ctx->r16, 0X22C);
    // addiu       $a1, $s3, 0x1870
    ctx->r5 = ADD32(ctx->r19, 0X1870);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    sub_80014CFC(rdram, ctx);
    goto after_13;
    // addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_13:
    // lhu         $v0, 0x187C($s3)
    ctx->r2 = MEM_HU(0X187C, ctx->r19);
    // nop

    // sh          $v0, 0x190($s0)
    MEM_H(0X190, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x187E($s3)
    ctx->r2 = MEM_HU(0X187E, ctx->r19);
    // nop

    // sh          $v0, 0x192($s0)
    MEM_H(0X192, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1880($s3)
    ctx->r2 = MEM_HU(0X1880, ctx->r19);
    // nop

    // sh          $v0, 0x194($s0)
    MEM_H(0X194, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1882($s3)
    ctx->r2 = MEM_HU(0X1882, ctx->r19);
    // nop

    // sh          $v0, 0x196($s0)
    MEM_H(0X196, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1884($s3)
    ctx->r2 = MEM_HU(0X1884, ctx->r19);
    // nop

    // sh          $v0, 0x198($s0)
    MEM_H(0X198, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1886($s3)
    ctx->r2 = MEM_HU(0X1886, ctx->r19);
    // nop

    // sh          $v0, 0x19A($s0)
    MEM_H(0X19A, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1888($s3)
    ctx->r2 = MEM_HU(0X1888, ctx->r19);
    // nop

    // sh          $v0, 0x19C($s0)
    MEM_H(0X19C, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x188A($s3)
    ctx->r2 = MEM_HU(0X188A, ctx->r19);
    // nop

    // sh          $v0, 0x19E($s0)
    MEM_H(0X19E, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x188C($s3)
    ctx->r2 = MEM_HU(0X188C, ctx->r19);
    // nop

    // sh          $v0, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x188E($s3)
    ctx->r2 = MEM_HU(0X188E, ctx->r19);
    // nop

    // sh          $v0, 0x1A2($s0)
    MEM_H(0X1A2, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1890($s3)
    ctx->r2 = MEM_HU(0X1890, ctx->r19);
    // nop

    // sh          $v0, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1892($s3)
    ctx->r2 = MEM_HU(0X1892, ctx->r19);
    // nop

    // sh          $v0, 0x1A6($s0)
    MEM_H(0X1A6, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1894($s3)
    ctx->r2 = MEM_HU(0X1894, ctx->r19);
    // nop

    // sh          $v0, 0x1A8($s0)
    MEM_H(0X1A8, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1896($s3)
    ctx->r2 = MEM_HU(0X1896, ctx->r19);
    // nop

    // sh          $v0, 0x1AA($s0)
    MEM_H(0X1AA, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1898($s3)
    ctx->r2 = MEM_HU(0X1898, ctx->r19);
    // nop

    // sh          $v0, 0x1AC($s0)
    MEM_H(0X1AC, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x189A($s3)
    ctx->r2 = MEM_HU(0X189A, ctx->r19);
    // nop

    // sh          $v0, 0x1AE($s0)
    MEM_H(0X1AE, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x189C($s3)
    ctx->r2 = MEM_HU(0X189C, ctx->r19);
    // nop

    // sh          $v0, 0x1B0($s0)
    MEM_H(0X1B0, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x189E($s3)
    ctx->r2 = MEM_HU(0X189E, ctx->r19);
    // nop

    // sh          $v0, 0x1B2($s0)
    MEM_H(0X1B2, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x18A0($s3)
    ctx->r2 = MEM_HU(0X18A0, ctx->r19);
    // nop

    // sh          $v0, 0x1B4($s0)
    MEM_H(0X1B4, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x18A2($s3)
    ctx->r2 = MEM_HU(0X18A2, ctx->r19);
    // nop

    // sh          $v0, 0x1B6($s0)
    MEM_H(0X1B6, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x18A4($s3)
    ctx->r2 = MEM_HU(0X18A4, ctx->r19);
    // nop

    // sh          $v0, 0x1B8($s0)
    MEM_H(0X1B8, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x18A6($s3)
    ctx->r2 = MEM_HU(0X18A6, ctx->r19);
    // nop

    // sh          $v0, 0x1BA($s0)
    MEM_H(0X1BA, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x18A8($s3)
    ctx->r2 = MEM_HU(0X18A8, ctx->r19);
    // nop

    // sh          $v0, 0x1BC($s0)
    MEM_H(0X1BC, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x18AA($s3)
    ctx->r2 = MEM_HU(0X18AA, ctx->r19);
    // nop

    // sh          $v0, 0x1BE($s0)
    MEM_H(0X1BE, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x18AC($s3)
    ctx->r2 = MEM_HU(0X18AC, ctx->r19);
    // nop

    // sh          $v0, 0x1C0($s0)
    MEM_H(0X1C0, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x18AE($s3)
    ctx->r2 = MEM_HU(0X18AE, ctx->r19);
    // nop

    // sh          $v0, 0x1C2($s0)
    MEM_H(0X1C2, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x18B0($s3)
    ctx->r2 = MEM_BU(0X18B0, ctx->r19);
    // nop

    // sb          $v0, 0x219($s0)
    MEM_B(0X219, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x18B1($s3)
    ctx->r2 = MEM_BU(0X18B1, ctx->r19);
    // nop

    // sb          $v0, 0x21A($s0)
    MEM_B(0X21A, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x18B2($s3)
    ctx->r2 = MEM_BU(0X18B2, ctx->r19);
    // nop

    // sb          $v0, 0x21B($s0)
    MEM_B(0X21B, ctx->r16) = ctx->r2;
    // lw          $v0, 0x1858($s3)
    ctx->r2 = MEM_W(0X1858, ctx->r19);
    // lw          $v1, 0x185C($s3)
    ctx->r3 = MEM_W(0X185C, ctx->r19);
    // lw          $a0, 0x1860($s3)
    ctx->r4 = MEM_W(0X1860, ctx->r19);
    // lw          $a1, 0x1864($s3)
    ctx->r5 = MEM_W(0X1864, ctx->r19);
    // sw          $v0, 0x248($s0)
    MEM_W(0X248, ctx->r16) = ctx->r2;
    // sw          $v1, 0x24C($s0)
    MEM_W(0X24C, ctx->r16) = ctx->r3;
    // sw          $a0, 0x250($s0)
    MEM_W(0X250, ctx->r16) = ctx->r4;
    // sw          $a1, 0x254($s0)
    MEM_W(0X254, ctx->r16) = ctx->r5;
    // lwl         $v0, 0x186B($s3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X186B, ctx->r19);
    // lwr         $v0, 0x1868($s3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X1868, ctx->r19);
    // lwl         $v1, 0x186F($s3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X186F, ctx->r19);
    // lwr         $v1, 0x186C($s3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X186C, ctx->r19);
    // swl         $v0, 0x27B($s0)
    do_swl(rdram, 0X27B, ctx->r16, ctx->r2);
    // swr         $v0, 0x278($s0)
    do_swr(rdram, 0X278, ctx->r16, ctx->r2);
    // swl         $v1, 0x27F($s0)
    do_swl(rdram, 0X27F, ctx->r16, ctx->r3);
    // swr         $v1, 0x27C($s0)
    do_swr(rdram, 0X27C, ctx->r16, ctx->r3);
    // lbu         $v0, 0x18B4($s3)
    ctx->r2 = MEM_BU(0X18B4, ctx->r19);
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // sb          $v0, -0x2EE0($v1)
    MEM_B(-0X2EE0, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x18B5($s3)
    ctx->r2 = MEM_BU(0X18B5, ctx->r19);
    // addiu       $v1, $v1, -0x2EE0
    ctx->r3 = ADD32(ctx->r3, -0X2EE0);
    // sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x18B6($s3)
    ctx->r2 = MEM_BU(0X18B6, ctx->r19);
    // lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x18B7($s3)
    ctx->r2 = MEM_BU(0X18B7, ctx->r19);
    // addiu       $s1, $s1, -0x45F8
    ctx->r17 = ADD32(ctx->r17, -0X45F8);
    // sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x18B8($s3)
    ctx->r2 = MEM_BU(0X18B8, ctx->r19);
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x18B9($s3)
    ctx->r2 = MEM_BU(0X18B9, ctx->r19);
    // addiu       $a0, $s1, 0x14BC
    ctx->r4 = ADD32(ctx->r17, 0X14BC);
    // sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // addiu       $a1, $s3, 0x18BC
    ctx->r5 = ADD32(ctx->r19, 0X18BC);
    // jal         0x80014CFC
    // sw          $v0, 0x16E0($s1)
    MEM_W(0X16E0, ctx->r17) = ctx->r2;
    sub_80014CFC(rdram, ctx);
    goto after_14;
    // sw          $v0, 0x16E0($s1)
    MEM_W(0X16E0, ctx->r17) = ctx->r2;
    after_14:
    // addiu       $a0, $s1, 0x14D0
    ctx->r4 = ADD32(ctx->r17, 0X14D0);
    // addiu       $a1, $s3, 0x18D0
    ctx->r5 = ADD32(ctx->r19, 0X18D0);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x4F
    ctx->r6 = ADD32(0, 0X4F);
    sub_80014CFC(rdram, ctx);
    goto after_15;
    // addiu       $a2, $zero, 0x4F
    ctx->r6 = ADD32(0, 0X4F);
    after_15:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // addiu       $a0, $a0, 0x7590
    ctx->r4 = ADD32(ctx->r4, 0X7590);
    // addiu       $a1, $s3, 0x1A0C
    ctx->r5 = ADD32(ctx->r19, 0X1A0C);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x4F
    ctx->r6 = ADD32(0, 0X4F);
    sub_80014CFC(rdram, ctx);
    goto after_16;
    // addiu       $a2, $zero, 0x4F
    ctx->r6 = ADD32(0, 0X4F);
    after_16:
    // lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // addiu       $s2, $s2, 0x7740
    ctx->r18 = ADD32(ctx->r18, 0X7740);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addiu       $a1, $s3, 0x1B48
    ctx->r5 = ADD32(ctx->r19, 0X1B48);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    sub_80014CFC(rdram, ctx);
    goto after_17;
    // addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_17:
    // lhu         $v0, 0x1B70($s3)
    ctx->r2 = MEM_HU(0X1B70, ctx->r19);
    // nop

    // sh          $v0, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B72($s3)
    ctx->r2 = MEM_HU(0X1B72, ctx->r19);
    // nop

    // sh          $v0, 0x3A($s0)
    MEM_H(0X3A, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B74($s3)
    ctx->r2 = MEM_HU(0X1B74, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B76($s3)
    ctx->r2 = MEM_HU(0X1B76, ctx->r19);
    // nop

    // sh          $v0, 0x3E($s0)
    MEM_H(0X3E, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B78($s3)
    ctx->r2 = MEM_HU(0X1B78, ctx->r19);
    // nop

    // sh          $v0, 0x40($s0)
    MEM_H(0X40, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B7A($s3)
    ctx->r2 = MEM_HU(0X1B7A, ctx->r19);
    // nop

    // sh          $v0, 0x42($s0)
    MEM_H(0X42, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B7C($s3)
    ctx->r2 = MEM_HU(0X1B7C, ctx->r19);
    // nop

    // sh          $v0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B7E($s3)
    ctx->r2 = MEM_HU(0X1B7E, ctx->r19);
    // nop

    // sh          $v0, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B80($s3)
    ctx->r2 = MEM_HU(0X1B80, ctx->r19);
    // nop

    // sh          $v0, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B82($s3)
    ctx->r2 = MEM_HU(0X1B82, ctx->r19);
    // nop

    // sh          $v0, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B84($s3)
    ctx->r2 = MEM_HU(0X1B84, ctx->r19);
    // nop

    // sh          $v0, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B86($s3)
    ctx->r2 = MEM_HU(0X1B86, ctx->r19);
    // nop

    // sh          $v0, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B88($s3)
    ctx->r2 = MEM_HU(0X1B88, ctx->r19);
    // nop

    // sh          $v0, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B8A($s3)
    ctx->r2 = MEM_HU(0X1B8A, ctx->r19);
    // nop

    // sh          $v0, 0x52($s0)
    MEM_H(0X52, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B8C($s3)
    ctx->r2 = MEM_HU(0X1B8C, ctx->r19);
    // nop

    // sh          $v0, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B8E($s3)
    ctx->r2 = MEM_HU(0X1B8E, ctx->r19);
    // nop

    // sh          $v0, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B90($s3)
    ctx->r2 = MEM_HU(0X1B90, ctx->r19);
    // nop

    // sh          $v0, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B92($s3)
    ctx->r2 = MEM_HU(0X1B92, ctx->r19);
    // nop

    // sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B94($s3)
    ctx->r2 = MEM_HU(0X1B94, ctx->r19);
    // nop

    // sh          $v0, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B96($s3)
    ctx->r2 = MEM_HU(0X1B96, ctx->r19);
    // nop

    // sh          $v0, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x1B98($s3)
    ctx->r2 = MEM_HU(0X1B98, ctx->r19);
    // nop

    // sh          $v0, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r2;
    // lw          $v0, 0x1B9C($s3)
    ctx->r2 = MEM_W(0X1B9C, ctx->r19);
    // nop

    // sw          $v0, 0x160C($s1)
    MEM_W(0X160C, ctx->r17) = ctx->r2;
    // lw          $v0, 0x1BA0($s3)
    ctx->r2 = MEM_W(0X1BA0, ctx->r19);
    // addiu       $s2, $s2, 0xD0
    ctx->r18 = ADD32(ctx->r18, 0XD0);
    // sw          $v0, 0x1610($s1)
    MEM_W(0X1610, ctx->r17) = ctx->r2;
    // lw          $v0, 0x1BA4($s3)
    ctx->r2 = MEM_W(0X1BA4, ctx->r19);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // sw          $v0, 0x1614($s1)
    MEM_W(0X1614, ctx->r17) = ctx->r2;
L_800572A8:
    // addu        $v0, $s3, $a2
    ctx->r2 = ADD32(ctx->r19, ctx->r6);
    // lbu         $v0, 0x1BA8($v0)
    ctx->r2 = MEM_BU(0X1BA8, ctx->r2);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // sb          $v0, 0x28($s2)
    MEM_B(0X28, ctx->r18) = ctx->r2;
    // slti        $v0, $a2, 0x13A
    ctx->r2 = SIGNED(ctx->r6) < 0X13A ? 1 : 0;
    // bne         $v0, $zero, L_800572A8
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x2C
        ctx->r18 = ADD32(ctx->r18, 0X2C);
        goto L_800572A8;
    }
    // addiu       $s2, $s2, 0x2C
    ctx->r18 = ADD32(ctx->r18, 0X2C);
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // addiu       $a0, $a0, -0x4924
    ctx->r4 = ADD32(ctx->r4, -0X4924);
    // addiu       $a1, $s3, 0x1CE4
    ctx->r5 = ADD32(ctx->r19, 0X1CE4);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    sub_80014CFC(rdram, ctx);
    goto after_18;
    // addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_18:
    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // addiu       $s0, $s0, 0x76CA
    ctx->r16 = ADD32(ctx->r16, 0X76CA);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s3, 0x1D44
    ctx->r5 = ADD32(ctx->r19, 0X1D44);
    // jal         0x80014D2C
    // addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    sub_80014D2C(rdram, ctx);
    goto after_19;
    // addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_19:
    // lwl         $v0, 0x1D63($s3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X1D63, ctx->r19);
    // lwr         $v0, 0x1D60($s3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X1D60, ctx->r19);
    // lwl         $v1, 0x1D67($s3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X1D67, ctx->r19);
    // lwr         $v1, 0x1D64($s3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X1D64, ctx->r19);
    // lwl         $a0, 0x1D6B($s3)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X1D6B, ctx->r19);
    // lwr         $a0, 0x1D68($s3)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X1D68, ctx->r19);
    // lh          $a1, 0x1D6C($s3)
    ctx->r5 = MEM_HS(0X1D6C, ctx->r19);
    // swl         $v0, 0x1F($s0)
    do_swl(rdram, 0X1F, ctx->r16, ctx->r2);
    // swr         $v0, 0x1C($s0)
    do_swr(rdram, 0X1C, ctx->r16, ctx->r2);
    // swl         $v1, 0x23($s0)
    do_swl(rdram, 0X23, ctx->r16, ctx->r3);
    // swr         $v1, 0x20($s0)
    do_swr(rdram, 0X20, ctx->r16, ctx->r3);
    // swl         $a0, 0x27($s0)
    do_swl(rdram, 0X27, ctx->r16, ctx->r4);
    // swr         $a0, 0x24($s0)
    do_swr(rdram, 0X24, ctx->r16, ctx->r4);
    // sh          $a1, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r5;
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // addiu       $a0, $a0, -0x2E5E
    ctx->r4 = ADD32(ctx->r4, -0X2E5E);
    // addiu       $a1, $s3, 0x1D6E
    ctx->r5 = ADD32(ctx->r19, 0X1D6E);
    // jal         0x80014D2C
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    sub_80014D2C(rdram, ctx);
    goto after_20;
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_20:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
