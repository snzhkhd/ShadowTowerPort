#include "recomp.h"
#include "disable_warnings.h"

void sub_800562D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // beq         $s2, $zero, L_8005630C
    if (ctx->r18 == 0) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_8005630C;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sb          $zero, 0x8($s1)
    MEM_B(0X8, ctx->r17) = 0;
    // sb          $zero, 0x7($s1)
    MEM_B(0X7, ctx->r17) = 0;
    // sb          $zero, 0x6($s1)
    MEM_B(0X6, ctx->r17) = 0;
    // sb          $zero, 0x5($s1)
    MEM_B(0X5, ctx->r17) = 0;
    // j           L_8005632C
    // sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
    goto L_8005632C;
    // sb          $zero, 0x4($s1)
    MEM_B(0X4, ctx->r17) = 0;
L_8005630C:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v0, $v0, 0x5920
    ctx->r2 = ADD32(ctx->r2, 0X5920);
    // lwl         $v1, 0x7($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r2);
    // lwr         $v1, 0x4($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r2);
    // lb          $a0, 0x8($v0)
    ctx->r4 = MEM_BS(0X8, ctx->r2);
    // swl         $v1, 0x7($s1)
    do_swl(rdram, 0X7, ctx->r17, ctx->r3);
    // swr         $v1, 0x4($s1)
    do_swr(rdram, 0X4, ctx->r17, ctx->r3);
    // sb          $a0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r4;
L_8005632C:
    // addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    // lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // addiu       $s0, $s0, -0x45F8
    ctx->r16 = ADD32(ctx->r16, -0X45F8);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    sub_80014CFC(rdram, ctx);
    goto after_0;
    // addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_0:
    // addiu       $a0, $s1, 0x18C
    ctx->r4 = ADD32(ctx->r17, 0X18C);
    // addiu       $a1, $s0, 0x180
    ctx->r5 = ADD32(ctx->r16, 0X180);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    sub_80014CFC(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_1:
    // addiu       $a0, $s1, 0x24C
    ctx->r4 = ADD32(ctx->r17, 0X24C);
    // addiu       $a1, $s0, 0x240
    ctx->r5 = ADD32(ctx->r16, 0X240);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    sub_80014CFC(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    after_2:
    // addiu       $a0, $s1, 0x84C
    ctx->r4 = ADD32(ctx->r17, 0X84C);
    // addiu       $a1, $s0, 0x840
    ctx->r5 = ADD32(ctx->r16, 0X840);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    sub_80014CFC(rdram, ctx);
    goto after_3;
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    after_3:
    // addiu       $a0, $s1, 0xE4C
    ctx->r4 = ADD32(ctx->r17, 0XE4C);
    // addiu       $a1, $s0, 0xE40
    ctx->r5 = ADD32(ctx->r16, 0XE40);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    sub_80014CFC(rdram, ctx);
    goto after_4;
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    after_4:
    // addiu       $a0, $s1, 0x144C
    ctx->r4 = ADD32(ctx->r17, 0X144C);
    // addiu       $a1, $s0, 0x1440
    ctx->r5 = ADD32(ctx->r16, 0X1440);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    sub_80014CFC(rdram, ctx);
    goto after_5;
    // addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
    // addiu       $a0, $s1, 0x1454
    ctx->r4 = ADD32(ctx->r17, 0X1454);
    // addiu       $a1, $s0, 0x1448
    ctx->r5 = ADD32(ctx->r16, 0X1448);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    sub_80014CFC(rdram, ctx);
    goto after_6;
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_6:
    // addiu       $a0, $s1, 0x1484
    ctx->r4 = ADD32(ctx->r17, 0X1484);
    // addiu       $a1, $s0, 0x1478
    ctx->r5 = ADD32(ctx->r16, 0X1478);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    sub_80014CFC(rdram, ctx);
    goto after_7;
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_7:
    // addiu       $a0, $s1, 0x14B4
    ctx->r4 = ADD32(ctx->r17, 0X14B4);
    // addiu       $a1, $s0, 0x14A8
    ctx->r5 = ADD32(ctx->r16, 0X14A8);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    sub_80014CFC(rdram, ctx);
    goto after_8;
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_8:
    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // addiu       $s0, $s0, 0x76F8
    ctx->r16 = ADD32(ctx->r16, 0X76F8);
    // lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(0X2, ctx->r16);
    // nop

    // sb          $v0, 0x14C8($s1)
    MEM_B(0X14C8, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x3($s0)
    ctx->r2 = MEM_BU(0X3, ctx->r16);
    // addiu       $a0, $s1, 0x14CC
    ctx->r4 = ADD32(ctx->r17, 0X14CC);
    // sb          $v0, 0x14C9($s1)
    MEM_B(0X14C9, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // addiu       $a1, $s0, 0x70
    ctx->r5 = ADD32(ctx->r16, 0X70);
    // sb          $v0, 0x14CA($s1)
    MEM_B(0X14CA, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // jal         0x80014CFC
    // sb          $v0, 0x14CB($s1)
    MEM_B(0X14CB, ctx->r17) = ctx->r2;
    sub_80014CFC(rdram, ctx);
    goto after_9;
    // sb          $v0, 0x14CB($s1)
    MEM_B(0X14CB, ctx->r17) = ctx->r2;
    after_9:
    // addiu       $a2, $s0, 0x3D10
    ctx->r6 = ADD32(ctx->r16, 0X3D10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a0, $s0, 0x3D3C
    ctx->r4 = ADD32(ctx->r16, 0X3D3C);
    // addu        $v1, $s1, $zero
    ctx->r3 = ADD32(ctx->r17, 0);
L_80056410:
    // lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(0X2, ctx->r16);
    // nop

    // slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8005649C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005649C;
    }
    // nop

    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // nop

    // sh          $v0, 0x14F0($v1)
    MEM_H(0X14F0, ctx->r3) = ctx->r2;
    // lhu         $v0, -0x2A($a0)
    ctx->r2 = MEM_HU(-0X2A, ctx->r4);
    // nop

    // sh          $v0, 0x14F2($v1)
    MEM_H(0X14F2, ctx->r3) = ctx->r2;
    // lw          $v0, -0x24($a0)
    ctx->r2 = MEM_W(-0X24, ctx->r4);
    // nop

    // sw          $v0, 0x14F4($v1)
    MEM_W(0X14F4, ctx->r3) = ctx->r2;
    // lw          $v0, -0x20($a0)
    ctx->r2 = MEM_W(-0X20, ctx->r4);
    // nop

    // sw          $v0, 0x14F8($v1)
    MEM_W(0X14F8, ctx->r3) = ctx->r2;
    // lw          $v0, -0x1C($a0)
    ctx->r2 = MEM_W(-0X1C, ctx->r4);
    // nop

    // sw          $v0, 0x14FC($v1)
    MEM_W(0X14FC, ctx->r3) = ctx->r2;
    // lhu         $v0, -0x14($a0)
    ctx->r2 = MEM_HU(-0X14, ctx->r4);
    // nop

    // sh          $v0, 0x1500($v1)
    MEM_H(0X1500, ctx->r3) = ctx->r2;
    // lhu         $v0, -0x12($a0)
    ctx->r2 = MEM_HU(-0X12, ctx->r4);
    // nop

    // sh          $v0, 0x1502($v1)
    MEM_H(0X1502, ctx->r3) = ctx->r2;
    // lhu         $v0, -0x10($a0)
    ctx->r2 = MEM_HU(-0X10, ctx->r4);
    // nop

    // sh          $v0, 0x1504($v1)
    MEM_H(0X1504, ctx->r3) = ctx->r2;
    // lbu         $v0, -0xA($a0)
    ctx->r2 = MEM_BU(-0XA, ctx->r4);
    // nop

    // sb          $v0, 0x1506($v1)
    MEM_B(0X1506, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // sb          $v0, 0x1507($v1)
    MEM_B(0X1507, ctx->r3) = ctx->r2;
L_8005649C:
    // addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80056410
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x30
        ctx->r6 = ADD32(ctx->r6, 0X30);
        goto L_80056410;
    }
    // addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a2, $v0, -0x48F8
    ctx->r6 = ADD32(ctx->r2, -0X48F8);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $t0, $a2, -0x4010
    ctx->r8 = ADD32(ctx->r6, -0X4010);
    // addiu       $a0, $a2, 0x2C
    ctx->r4 = ADD32(ctx->r6, 0X2C);
    // addiu       $a3, $zero, 0x180
    ctx->r7 = ADD32(0, 0X180);
L_800564CC:
    // lbu         $v0, 0x3($t0)
    ctx->r2 = MEM_BU(0X3, ctx->r8);
    // nop

    // slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80056558
    if (ctx->r2 == 0) {
        // addu        $v1, $s1, $a3
        ctx->r3 = ADD32(ctx->r17, ctx->r7);
        goto L_80056558;
    }
    // addu        $v1, $s1, $a3
    ctx->r3 = ADD32(ctx->r17, ctx->r7);
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // nop

    // sh          $v0, 0x14F0($v1)
    MEM_H(0X14F0, ctx->r3) = ctx->r2;
    // lhu         $v0, -0x2A($a0)
    ctx->r2 = MEM_HU(-0X2A, ctx->r4);
    // nop

    // sh          $v0, 0x14F2($v1)
    MEM_H(0X14F2, ctx->r3) = ctx->r2;
    // lw          $v0, -0x24($a0)
    ctx->r2 = MEM_W(-0X24, ctx->r4);
    // nop

    // sw          $v0, 0x14F4($v1)
    MEM_W(0X14F4, ctx->r3) = ctx->r2;
    // lw          $v0, -0x20($a0)
    ctx->r2 = MEM_W(-0X20, ctx->r4);
    // nop

    // sw          $v0, 0x14F8($v1)
    MEM_W(0X14F8, ctx->r3) = ctx->r2;
    // lw          $v0, -0x1C($a0)
    ctx->r2 = MEM_W(-0X1C, ctx->r4);
    // nop

    // sw          $v0, 0x14FC($v1)
    MEM_W(0X14FC, ctx->r3) = ctx->r2;
    // lhu         $v0, -0x14($a0)
    ctx->r2 = MEM_HU(-0X14, ctx->r4);
    // nop

    // sh          $v0, 0x1500($v1)
    MEM_H(0X1500, ctx->r3) = ctx->r2;
    // lhu         $v0, -0x12($a0)
    ctx->r2 = MEM_HU(-0X12, ctx->r4);
    // nop

    // sh          $v0, 0x1502($v1)
    MEM_H(0X1502, ctx->r3) = ctx->r2;
    // lhu         $v0, -0x10($a0)
    ctx->r2 = MEM_HU(-0X10, ctx->r4);
    // nop

    // sh          $v0, 0x1504($v1)
    MEM_H(0X1504, ctx->r3) = ctx->r2;
    // lbu         $v0, -0xA($a0)
    ctx->r2 = MEM_BU(-0XA, ctx->r4);
    // nop

    // sb          $v0, 0x1506($v1)
    MEM_B(0X1506, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // nop

    // sb          $v0, 0x1507($v1)
    MEM_B(0X1507, ctx->r3) = ctx->r2;
L_80056558:
    // addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_800564CC
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x30
        ctx->r6 = ADD32(ctx->r6, 0X30);
        goto L_800564CC;
    }
    // addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(0X2C, ctx->r16);
    // nop

    // sw          $v0, 0x17F0($s1)
    MEM_W(0X17F0, ctx->r17) = ctx->r2;
    // lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(0X34, ctx->r16);
    // nop

    // sw          $v0, 0x17F4($s1)
    MEM_W(0X17F4, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // sh          $v0, 0x17F8($s1)
    MEM_H(0X17F8, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(0X6, ctx->r16);
    // nop

    // sh          $v0, 0x17FA($s1)
    MEM_H(0X17FA, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // sh          $v0, 0x17FC($s1)
    MEM_H(0X17FC, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x30($s0)
    ctx->r2 = MEM_HU(0X30, ctx->r16);
    // nop

    // sh          $v0, 0x17FE($s1)
    MEM_H(0X17FE, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x26($s0)
    ctx->r2 = MEM_BU(0X26, ctx->r16);
    // nop

    // sb          $v0, 0x1800($s1)
    MEM_B(0X1800, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x27($s0)
    ctx->r2 = MEM_BU(0X27, ctx->r16);
    // addiu       $a0, $s1, 0x1804
    ctx->r4 = ADD32(ctx->r17, 0X1804);
    // sb          $v0, 0x1801($s1)
    MEM_B(0X1801, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(0X28, ctx->r16);
    // addiu       $a1, $s0, 0x62
    ctx->r5 = ADD32(ctx->r16, 0X62);
    // sb          $v0, 0x1802($s1)
    MEM_B(0X1802, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x32($s0)
    ctx->r2 = MEM_BU(0X32, ctx->r16);
    // addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // jal         0x80014D2C
    // sb          $v0, 0x1803($s1)
    MEM_B(0X1803, ctx->r17) = ctx->r2;
    sub_80014D2C(rdram, ctx);
    goto after_10;
    // sb          $v0, 0x1803($s1)
    MEM_B(0X1803, ctx->r17) = ctx->r2;
    after_10:
    // addiu       $a0, $s1, 0x1820
    ctx->r4 = ADD32(ctx->r17, 0X1820);
    // addiu       $a1, $s0, 0x7E
    ctx->r5 = ADD32(ctx->r16, 0X7E);
    // jal         0x80014D2C
    // addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    sub_80014D2C(rdram, ctx);
    goto after_11;
    // addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_11:
    // addiu       $a0, $s1, 0x183C
    ctx->r4 = ADD32(ctx->r17, 0X183C);
    // addiu       $a1, $s0, 0x9A
    ctx->r5 = ADD32(ctx->r16, 0X9A);
    // jal         0x80014D2C
    // addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    sub_80014D2C(rdram, ctx);
    goto after_12;
    // addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_12:
    // addiu       $a0, $s1, 0x1870
    ctx->r4 = ADD32(ctx->r17, 0X1870);
    // addiu       $a1, $s0, 0x22C
    ctx->r5 = ADD32(ctx->r16, 0X22C);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    sub_80014CFC(rdram, ctx);
    goto after_13;
    // addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_13:
    // lhu         $v0, 0x190($s0)
    ctx->r2 = MEM_HU(0X190, ctx->r16);
    // nop

    // sh          $v0, 0x187C($s1)
    MEM_H(0X187C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x192($s0)
    ctx->r2 = MEM_HU(0X192, ctx->r16);
    // nop

    // sh          $v0, 0x187E($s1)
    MEM_H(0X187E, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x194($s0)
    ctx->r2 = MEM_HU(0X194, ctx->r16);
    // nop

    // sh          $v0, 0x1880($s1)
    MEM_H(0X1880, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x196($s0)
    ctx->r2 = MEM_HU(0X196, ctx->r16);
    // nop

    // sh          $v0, 0x1882($s1)
    MEM_H(0X1882, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x198($s0)
    ctx->r2 = MEM_HU(0X198, ctx->r16);
    // nop

    // sh          $v0, 0x1884($s1)
    MEM_H(0X1884, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x19A($s0)
    ctx->r2 = MEM_HU(0X19A, ctx->r16);
    // nop

    // sh          $v0, 0x1886($s1)
    MEM_H(0X1886, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x19C($s0)
    ctx->r2 = MEM_HU(0X19C, ctx->r16);
    // nop

    // sh          $v0, 0x1888($s1)
    MEM_H(0X1888, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x19E($s0)
    ctx->r2 = MEM_HU(0X19E, ctx->r16);
    // nop

    // sh          $v0, 0x188A($s1)
    MEM_H(0X188A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1A0($s0)
    ctx->r2 = MEM_HU(0X1A0, ctx->r16);
    // nop

    // sh          $v0, 0x188C($s1)
    MEM_H(0X188C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1A2($s0)
    ctx->r2 = MEM_HU(0X1A2, ctx->r16);
    // nop

    // sh          $v0, 0x188E($s1)
    MEM_H(0X188E, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1A4($s0)
    ctx->r2 = MEM_HU(0X1A4, ctx->r16);
    // nop

    // sh          $v0, 0x1890($s1)
    MEM_H(0X1890, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1A6($s0)
    ctx->r2 = MEM_HU(0X1A6, ctx->r16);
    // nop

    // sh          $v0, 0x1892($s1)
    MEM_H(0X1892, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1A8($s0)
    ctx->r2 = MEM_HU(0X1A8, ctx->r16);
    // nop

    // sh          $v0, 0x1894($s1)
    MEM_H(0X1894, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1AA($s0)
    ctx->r2 = MEM_HU(0X1AA, ctx->r16);
    // nop

    // sh          $v0, 0x1896($s1)
    MEM_H(0X1896, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1AC($s0)
    ctx->r2 = MEM_HU(0X1AC, ctx->r16);
    // nop

    // sh          $v0, 0x1898($s1)
    MEM_H(0X1898, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1AE($s0)
    ctx->r2 = MEM_HU(0X1AE, ctx->r16);
    // nop

    // sh          $v0, 0x189A($s1)
    MEM_H(0X189A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1B0($s0)
    ctx->r2 = MEM_HU(0X1B0, ctx->r16);
    // nop

    // sh          $v0, 0x189C($s1)
    MEM_H(0X189C, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1B2($s0)
    ctx->r2 = MEM_HU(0X1B2, ctx->r16);
    // nop

    // sh          $v0, 0x189E($s1)
    MEM_H(0X189E, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1B4($s0)
    ctx->r2 = MEM_HU(0X1B4, ctx->r16);
    // nop

    // sh          $v0, 0x18A0($s1)
    MEM_H(0X18A0, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1B6($s0)
    ctx->r2 = MEM_HU(0X1B6, ctx->r16);
    // nop

    // sh          $v0, 0x18A2($s1)
    MEM_H(0X18A2, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1B8($s0)
    ctx->r2 = MEM_HU(0X1B8, ctx->r16);
    // nop

    // sh          $v0, 0x18A4($s1)
    MEM_H(0X18A4, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1BA($s0)
    ctx->r2 = MEM_HU(0X1BA, ctx->r16);
    // nop

    // sh          $v0, 0x18A6($s1)
    MEM_H(0X18A6, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1BC($s0)
    ctx->r2 = MEM_HU(0X1BC, ctx->r16);
    // nop

    // sh          $v0, 0x18A8($s1)
    MEM_H(0X18A8, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1BE($s0)
    ctx->r2 = MEM_HU(0X1BE, ctx->r16);
    // nop

    // sh          $v0, 0x18AA($s1)
    MEM_H(0X18AA, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1C0($s0)
    ctx->r2 = MEM_HU(0X1C0, ctx->r16);
    // nop

    // sh          $v0, 0x18AC($s1)
    MEM_H(0X18AC, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x1C2($s0)
    ctx->r2 = MEM_HU(0X1C2, ctx->r16);
    // nop

    // sh          $v0, 0x18AE($s1)
    MEM_H(0X18AE, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x219($s0)
    ctx->r2 = MEM_BU(0X219, ctx->r16);
    // nop

    // sb          $v0, 0x18B0($s1)
    MEM_B(0X18B0, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x21A($s0)
    ctx->r2 = MEM_BU(0X21A, ctx->r16);
    // nop

    // sb          $v0, 0x18B1($s1)
    MEM_B(0X18B1, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x21B($s0)
    ctx->r2 = MEM_BU(0X21B, ctx->r16);
    // beq         $s2, $zero, L_800567B8
    if (ctx->r18 == 0) {
        // sb          $v0, 0x18B2($s1)
        MEM_B(0X18B2, ctx->r17) = ctx->r2;
        goto L_800567B8;
    }
    // sb          $v0, 0x18B2($s1)
    MEM_B(0X18B2, ctx->r17) = ctx->r2;
    // lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    // ori         $a0, $a0, 0xD000
    ctx->r4 = ctx->r4 | 0XD000;
    // lui         $v1, 0x4
    ctx->r3 = S32(0X4 << 16);
    // ori         $v1, $v1, 0x5C0
    ctx->r3 = ctx->r3 | 0X5C0;
    // lui         $v0, 0x3
    ctx->r2 = S32(0X3 << 16);
    // ori         $v0, $v0, 0xF000
    ctx->r2 = ctx->r2 | 0XF000;
    // sw          $v0, 0x1860($s1)
    MEM_W(0X1860, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0xC00
    ctx->r2 = ADD32(0, 0XC00);
    // sw          $a0, 0x1858($s1)
    MEM_W(0X1858, ctx->r17) = ctx->r4;
    // sw          $v1, 0x185C($s1)
    MEM_W(0X185C, ctx->r17) = ctx->r3;
    // sh          $zero, 0x1868($s1)
    MEM_H(0X1868, ctx->r17) = 0;
    // sh          $v0, 0x186A($s1)
    MEM_H(0X186A, ctx->r17) = ctx->r2;
    // j           L_800567F8
    // sh          $zero, 0x186C($s1)
    MEM_H(0X186C, ctx->r17) = 0;
    goto L_800567F8;
    // sh          $zero, 0x186C($s1)
    MEM_H(0X186C, ctx->r17) = 0;
L_800567B8:
    // lw          $v0, 0x248($s0)
    ctx->r2 = MEM_W(0X248, ctx->r16);
    // lw          $v1, 0x24C($s0)
    ctx->r3 = MEM_W(0X24C, ctx->r16);
    // lw          $a0, 0x250($s0)
    ctx->r4 = MEM_W(0X250, ctx->r16);
    // lw          $a1, 0x254($s0)
    ctx->r5 = MEM_W(0X254, ctx->r16);
    // sw          $v0, 0x1858($s1)
    MEM_W(0X1858, ctx->r17) = ctx->r2;
    // sw          $v1, 0x185C($s1)
    MEM_W(0X185C, ctx->r17) = ctx->r3;
    // sw          $a0, 0x1860($s1)
    MEM_W(0X1860, ctx->r17) = ctx->r4;
    // sw          $a1, 0x1864($s1)
    MEM_W(0X1864, ctx->r17) = ctx->r5;
    // lwl         $v0, 0x27B($s0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X27B, ctx->r16);
    // lwr         $v0, 0x278($s0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X278, ctx->r16);
    // lwl         $v1, 0x27F($s0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X27F, ctx->r16);
    // lwr         $v1, 0x27C($s0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X27C, ctx->r16);
    // swl         $v0, 0x186B($s1)
    do_swl(rdram, 0X186B, ctx->r17, ctx->r2);
    // swr         $v0, 0x1868($s1)
    do_swr(rdram, 0X1868, ctx->r17, ctx->r2);
    // swl         $v1, 0x186F($s1)
    do_swl(rdram, 0X186F, ctx->r17, ctx->r3);
    // swr         $v1, 0x186C($s1)
    do_swr(rdram, 0X186C, ctx->r17, ctx->r3);
L_800567F8:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v1, -0x2EE0($v0)
    ctx->r3 = MEM_BU(-0X2EE0, ctx->r2);
    // addiu       $v0, $v0, -0x2EE0
    ctx->r2 = ADD32(ctx->r2, -0X2EE0);
    // sb          $v1, 0x18B4($s1)
    MEM_B(0X18B4, ctx->r17) = ctx->r3;
    // lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(0X1, ctx->r2);
    // nop

    // sb          $v1, 0x18B5($s1)
    MEM_B(0X18B5, ctx->r17) = ctx->r3;
    // lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(0X2, ctx->r2);
    // nop

    // sb          $v1, 0x18B6($s1)
    MEM_B(0X18B6, ctx->r17) = ctx->r3;
    // lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(0X3, ctx->r2);
    // nop

    // sb          $v1, 0x18B7($s1)
    MEM_B(0X18B7, ctx->r17) = ctx->r3;
    // lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(0X4, ctx->r2);
    // nop

    // sb          $v1, 0x18B8($s1)
    MEM_B(0X18B8, ctx->r17) = ctx->r3;
    // lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(0X5, ctx->r2);
    // nop

    // sb          $v0, 0x18B9($s1)
    MEM_B(0X18B9, ctx->r17) = ctx->r2;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s2, $v0, -0x45F8
    ctx->r18 = ADD32(ctx->r2, -0X45F8);
    // lw          $v1, 0x16E0($s2)
    ctx->r3 = MEM_W(0X16E0, ctx->r18);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_80056874
    if (ctx->r3 != ctx->r2) {
        // addiu       $a0, $s1, 0x18BC
        ctx->r4 = ADD32(ctx->r17, 0X18BC);
        goto L_80056874;
    }
    // addiu       $a0, $s1, 0x18BC
    ctx->r4 = ADD32(ctx->r17, 0X18BC);
    // jal         0x80077104
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    VSync(rdram, ctx);
    goto after_14;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_14:
    // jal         0x80078AC4
    // sh          $v0, 0x16E0($s2)
    MEM_H(0X16E0, ctx->r18) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_15;
    // sh          $v0, 0x16E0($s2)
    MEM_H(0X16E0, ctx->r18) = ctx->r2;
    after_15:
    // sh          $v0, 0x16E2($s2)
    MEM_H(0X16E2, ctx->r18) = ctx->r2;
    // addiu       $a0, $s1, 0x18BC
    ctx->r4 = ADD32(ctx->r17, 0X18BC);
L_80056874:
    // addiu       $a1, $s2, 0x14BC
    ctx->r5 = ADD32(ctx->r18, 0X14BC);
    // lw          $v0, 0x16E0($s2)
    ctx->r2 = MEM_W(0X16E0, ctx->r18);
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // jal         0x80014CFC
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    sub_80014CFC(rdram, ctx);
    goto after_16;
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    after_16:
    // addiu       $a0, $s1, 0x18D0
    ctx->r4 = ADD32(ctx->r17, 0X18D0);
    // addiu       $a1, $s2, 0x14D0
    ctx->r5 = ADD32(ctx->r18, 0X14D0);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x4F
    ctx->r6 = ADD32(0, 0X4F);
    sub_80014CFC(rdram, ctx);
    goto after_17;
    // addiu       $a2, $zero, 0x4F
    ctx->r6 = ADD32(0, 0X4F);
    after_17:
    // addiu       $a0, $s1, 0x1A0C
    ctx->r4 = ADD32(ctx->r17, 0X1A0C);
    // lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // addiu       $a1, $a1, 0x7590
    ctx->r5 = ADD32(ctx->r5, 0X7590);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x4F
    ctx->r6 = ADD32(0, 0X4F);
    sub_80014CFC(rdram, ctx);
    goto after_18;
    // addiu       $a2, $zero, 0x4F
    ctx->r6 = ADD32(0, 0X4F);
    after_18:
    // addiu       $a0, $s1, 0x1B48
    ctx->r4 = ADD32(ctx->r17, 0X1B48);
    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // addiu       $s0, $s0, 0x7740
    ctx->r16 = ADD32(ctx->r16, 0X7740);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    sub_80014CFC(rdram, ctx);
    goto after_19;
    // addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_19:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, 0x38($v0)
    ctx->r3 = MEM_HU(0X38, ctx->r2);
    // nop

    // sh          $v1, 0x1B70($s1)
    MEM_H(0X1B70, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x3A($v0)
    ctx->r3 = MEM_HU(0X3A, ctx->r2);
    // nop

    // sh          $v1, 0x1B72($s1)
    MEM_H(0X1B72, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x3C($v0)
    ctx->r3 = MEM_HU(0X3C, ctx->r2);
    // nop

    // sh          $v1, 0x1B74($s1)
    MEM_H(0X1B74, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x3E($v0)
    ctx->r3 = MEM_HU(0X3E, ctx->r2);
    // nop

    // sh          $v1, 0x1B76($s1)
    MEM_H(0X1B76, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x40($v0)
    ctx->r3 = MEM_HU(0X40, ctx->r2);
    // nop

    // sh          $v1, 0x1B78($s1)
    MEM_H(0X1B78, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x42($v0)
    ctx->r3 = MEM_HU(0X42, ctx->r2);
    // nop

    // sh          $v1, 0x1B7A($s1)
    MEM_H(0X1B7A, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x44($v0)
    ctx->r3 = MEM_HU(0X44, ctx->r2);
    // nop

    // sh          $v1, 0x1B7C($s1)
    MEM_H(0X1B7C, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x46($v0)
    ctx->r3 = MEM_HU(0X46, ctx->r2);
    // nop

    // sh          $v1, 0x1B7E($s1)
    MEM_H(0X1B7E, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x48($v0)
    ctx->r3 = MEM_HU(0X48, ctx->r2);
    // nop

    // sh          $v1, 0x1B80($s1)
    MEM_H(0X1B80, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x4A($v0)
    ctx->r3 = MEM_HU(0X4A, ctx->r2);
    // nop

    // sh          $v1, 0x1B82($s1)
    MEM_H(0X1B82, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x4C($v0)
    ctx->r3 = MEM_HU(0X4C, ctx->r2);
    // nop

    // sh          $v1, 0x1B84($s1)
    MEM_H(0X1B84, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x4E($v0)
    ctx->r3 = MEM_HU(0X4E, ctx->r2);
    // nop

    // sh          $v1, 0x1B86($s1)
    MEM_H(0X1B86, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x50($v0)
    ctx->r3 = MEM_HU(0X50, ctx->r2);
    // nop

    // sh          $v1, 0x1B88($s1)
    MEM_H(0X1B88, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x52($v0)
    ctx->r3 = MEM_HU(0X52, ctx->r2);
    // nop

    // sh          $v1, 0x1B8A($s1)
    MEM_H(0X1B8A, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x54($v0)
    ctx->r3 = MEM_HU(0X54, ctx->r2);
    // nop

    // sh          $v1, 0x1B8C($s1)
    MEM_H(0X1B8C, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x56($v0)
    ctx->r3 = MEM_HU(0X56, ctx->r2);
    // nop

    // sh          $v1, 0x1B8E($s1)
    MEM_H(0X1B8E, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x58($v0)
    ctx->r3 = MEM_HU(0X58, ctx->r2);
    // nop

    // sh          $v1, 0x1B90($s1)
    MEM_H(0X1B90, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x5A($v0)
    ctx->r3 = MEM_HU(0X5A, ctx->r2);
    // nop

    // sh          $v1, 0x1B92($s1)
    MEM_H(0X1B92, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x5C($v0)
    ctx->r3 = MEM_HU(0X5C, ctx->r2);
    // nop

    // sh          $v1, 0x1B94($s1)
    MEM_H(0X1B94, ctx->r17) = ctx->r3;
    // lhu         $v1, 0x5E($v0)
    ctx->r3 = MEM_HU(0X5E, ctx->r2);
    // nop

    // sh          $v1, 0x1B96($s1)
    MEM_H(0X1B96, ctx->r17) = ctx->r3;
    // lhu         $v0, 0x60($v0)
    ctx->r2 = MEM_HU(0X60, ctx->r2);
    // nop

    // sh          $v0, 0x1B98($s1)
    MEM_H(0X1B98, ctx->r17) = ctx->r2;
    // lw          $v0, 0x160C($s2)
    ctx->r2 = MEM_W(0X160C, ctx->r18);
    // nop

    // sw          $v0, 0x1B9C($s1)
    MEM_W(0X1B9C, ctx->r17) = ctx->r2;
    // lw          $v0, 0x1610($s2)
    ctx->r2 = MEM_W(0X1610, ctx->r18);
    // addiu       $s0, $s0, 0xD0
    ctx->r16 = ADD32(ctx->r16, 0XD0);
    // sw          $v0, 0x1BA0($s1)
    MEM_W(0X1BA0, ctx->r17) = ctx->r2;
    // lw          $v0, 0x1614($s2)
    ctx->r2 = MEM_W(0X1614, ctx->r18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sw          $v0, 0x1BA4($s1)
    MEM_W(0X1BA4, ctx->r17) = ctx->r2;
L_800569EC:
    // addu        $v1, $s1, $a1
    ctx->r3 = ADD32(ctx->r17, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(0X28, ctx->r16);
    // nop

    // sb          $v0, 0x1BA8($v1)
    MEM_B(0X1BA8, ctx->r3) = ctx->r2;
    // slti        $v0, $a1, 0x13A
    ctx->r2 = SIGNED(ctx->r5) < 0X13A ? 1 : 0;
    // bne         $v0, $zero, L_800569EC
    if (ctx->r2 != 0) {
        // addiu       $s0, $s0, 0x2C
        ctx->r16 = ADD32(ctx->r16, 0X2C);
        goto L_800569EC;
    }
    // addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    // addiu       $a0, $s1, 0x1CE4
    ctx->r4 = ADD32(ctx->r17, 0X1CE4);
    // lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // addiu       $a1, $a1, -0x4924
    ctx->r5 = ADD32(ctx->r5, -0X4924);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    sub_80014CFC(rdram, ctx);
    goto after_20;
    // addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_20:
    // addiu       $a0, $s1, 0x1D44
    ctx->r4 = ADD32(ctx->r17, 0X1D44);
    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // addiu       $s0, $s0, 0x76CA
    ctx->r16 = ADD32(ctx->r16, 0X76CA);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x80014D2C
    // addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    sub_80014D2C(rdram, ctx);
    goto after_21;
    // addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_21:
    // lwl         $v0, 0x1F($s0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X1F, ctx->r16);
    // lwr         $v0, 0x1C($s0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X1C, ctx->r16);
    // lwl         $v1, 0x23($s0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X23, ctx->r16);
    // lwr         $v1, 0x20($s0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X20, ctx->r16);
    // lwl         $a0, 0x27($s0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X27, ctx->r16);
    // lwr         $a0, 0x24($s0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X24, ctx->r16);
    // lh          $a1, 0x28($s0)
    ctx->r5 = MEM_HS(0X28, ctx->r16);
    // swl         $v0, 0x1D63($s1)
    do_swl(rdram, 0X1D63, ctx->r17, ctx->r2);
    // swr         $v0, 0x1D60($s1)
    do_swr(rdram, 0X1D60, ctx->r17, ctx->r2);
    // swl         $v1, 0x1D67($s1)
    do_swl(rdram, 0X1D67, ctx->r17, ctx->r3);
    // swr         $v1, 0x1D64($s1)
    do_swr(rdram, 0X1D64, ctx->r17, ctx->r3);
    // swl         $a0, 0x1D6B($s1)
    do_swl(rdram, 0X1D6B, ctx->r17, ctx->r4);
    // swr         $a0, 0x1D68($s1)
    do_swr(rdram, 0X1D68, ctx->r17, ctx->r4);
    // sh          $a1, 0x1D6C($s1)
    MEM_H(0X1D6C, ctx->r17) = ctx->r5;
    // addiu       $a0, $s1, 0x1D6E
    ctx->r4 = ADD32(ctx->r17, 0X1D6E);
    // lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // addiu       $a1, $a1, -0x2E5E
    ctx->r5 = ADD32(ctx->r5, -0X2E5E);
    // jal         0x80014D2C
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    sub_80014D2C(rdram, ctx);
    goto after_22;
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_22:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
