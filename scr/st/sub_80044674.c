#include "recomp.h"
#include "disable_warnings.h"

void sub_80044674(uint8_t* rdram, recomp_context* ctx) 
{
 //   printf("sub_80044674\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // addiu       $s2, $s3, -0x3778
    ctx->r18 = ADD32(ctx->r19, -0X3778);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // addiu       $v0, $a2, 0x5920
    ctx->r2 = ADD32(ctx->r6, 0X5920);
    // addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
    // sb          $v1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r3;
    // sb          $v1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r3;
    // sh          $zero, 0x5920($a2)
    MEM_H(0X5920, ctx->r6) = 0;
    // sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    // sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    // sb          $zero, 0x9($v0)
    MEM_B(0X9, ctx->r2) = 0;
    // lui         $v1, 0x8001
    ctx->r3 = S32(0X8001 << 16);
    // lw          $v1, 0x3980($v1)
    ctx->r3 = MEM_W(0X3980, ctx->r3);
    // addiu       $a1, $a1, 0x1F18
    ctx->r5 = ADD32(ctx->r5, 0X1F18);
    // sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // sb          $zero, 0x2A1($v0)
    MEM_B(0X2A1, ctx->r2) = 0;
    // addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // sw          $v0, 0x318($gp)
    MEM_W(0X318, ctx->r28) = ctx->r2;
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sw          $v1, -0x7E24($at)
    MEM_W(-0X7E24, ctx->r1) = ctx->r3;
    // jal         0x80016294
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    sub_80016294(rdram, ctx);
    goto after_0;
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x80016294
    // addiu       $a1, $a1, 0x1F24
    ctx->r5 = ADD32(ctx->r5, 0X1F24);
    sub_80016294(rdram, ctx);
    goto after_1;
    // addiu       $a1, $a1, 0x1F24
    ctx->r5 = ADD32(ctx->r5, 0X1F24);
    after_1:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x80016294
    // addiu       $a1, $a1, 0x1F30
    ctx->r5 = ADD32(ctx->r5, 0X1F30);
    sub_80016294(rdram, ctx);
    goto after_2;
    // addiu       $a1, $a1, 0x1F30
    ctx->r5 = ADD32(ctx->r5, 0X1F30);
    after_2:
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x80016294
    // addiu       $a1, $a1, 0x1F3C
    ctx->r5 = ADD32(ctx->r5, 0X1F3C);
    sub_80016294(rdram, ctx);
    goto after_3;
    // addiu       $a1, $a1, 0x1F3C
    ctx->r5 = ADD32(ctx->r5, 0X1F3C);
    after_3:
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x80016294
    // addiu       $a1, $a1, 0x1F48
    ctx->r5 = ADD32(ctx->r5, 0X1F48);
    sub_80016294(rdram, ctx);
    goto after_4;
    // addiu       $a1, $a1, 0x1F48
    ctx->r5 = ADD32(ctx->r5, 0X1F48);
    after_4:
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x80016294
    // addiu       $a1, $a1, 0x1F54
    ctx->r5 = ADD32(ctx->r5, 0X1F54);
    sub_80016294(rdram, ctx);
    goto after_5;
    // addiu       $a1, $a1, 0x1F54
    ctx->r5 = ADD32(ctx->r5, 0X1F54);
    after_5:
    // addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x80016294
    // addiu       $a1, $a1, 0x1F60
    ctx->r5 = ADD32(ctx->r5, 0X1F60);
    sub_80016294(rdram, ctx);
    goto after_6;
    // addiu       $a1, $a1, 0x1F60
    ctx->r5 = ADD32(ctx->r5, 0X1F60);
    after_6:
    // addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x80016294
    // addiu       $a1, $a1, 0x1F6C
    ctx->r5 = ADD32(ctx->r5, 0X1F6C);
    sub_80016294(rdram, ctx);
    goto after_7;
    // addiu       $a1, $a1, 0x1F6C
    ctx->r5 = ADD32(ctx->r5, 0X1F6C);
    after_7:
    // addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x80016294
    // addiu       $a1, $a1, 0x1F78
    ctx->r5 = ADD32(ctx->r5, 0X1F78);
    sub_80016294(rdram, ctx);
    goto after_8;
    // addiu       $a1, $a1, 0x1F78
    ctx->r5 = ADD32(ctx->r5, 0X1F78);
    after_8:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x1F88
    ctx->r5 = ADD32(ctx->r5, 0X1F88);
    CdSearchFile(rdram, ctx);
    goto after_9;
    // addiu       $a1, $a1, 0x1F88
    ctx->r5 = ADD32(ctx->r5, 0X1F88);
    after_9:
    // lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // addiu       $s0, $s0, -0x45F8
    ctx->r16 = ADD32(ctx->r16, -0X45F8);
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x161B($s0)
    do_swl(rdram, 0X161B, ctx->r16, ctx->r2);
    // swr         $v0, 0x1618($s0)
    do_swr(rdram, 0X1618, ctx->r16, ctx->r2);
    // addiu       $s1, $sp, 0x10
    ctx->r17 = ADD32(ctx->r29, 0X10);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x1F9C
    ctx->r5 = ADD32(ctx->r5, 0X1F9C);
    CdSearchFile(rdram, ctx);
    goto after_10;
    // addiu       $a1, $a1, 0x1F9C
    ctx->r5 = ADD32(ctx->r5, 0X1F9C);
    after_10:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x161F($s0)
    do_swl(rdram, 0X161F, ctx->r16, ctx->r2);
    // swr         $v0, 0x161C($s0)
    do_swr(rdram, 0X161C, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x1FB0
    ctx->r5 = ADD32(ctx->r5, 0X1FB0);
    CdSearchFile(rdram, ctx);
    goto after_11;
    // addiu       $a1, $a1, 0x1FB0
    ctx->r5 = ADD32(ctx->r5, 0X1FB0);
    after_11:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1623($s0)
    do_swl(rdram, 0X1623, ctx->r16, ctx->r2);
    // swr         $v0, 0x1620($s0)
    do_swr(rdram, 0X1620, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x1FC4
    ctx->r5 = ADD32(ctx->r5, 0X1FC4);
    CdSearchFile(rdram, ctx);
    goto after_12;
    // addiu       $a1, $a1, 0x1FC4
    ctx->r5 = ADD32(ctx->r5, 0X1FC4);
    after_12:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1627($s0)
    do_swl(rdram, 0X1627, ctx->r16, ctx->r2);
    // swr         $v0, 0x1624($s0)
    do_swr(rdram, 0X1624, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x1FD8
    ctx->r5 = ADD32(ctx->r5, 0X1FD8);
    CdSearchFile(rdram, ctx);
    goto after_13;
    // addiu       $a1, $a1, 0x1FD8
    ctx->r5 = ADD32(ctx->r5, 0X1FD8);
    after_13:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x162B($s0)
    do_swl(rdram, 0X162B, ctx->r16, ctx->r2);
    // swr         $v0, 0x1628($s0)
    do_swr(rdram, 0X1628, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x1FEC
    ctx->r5 = ADD32(ctx->r5, 0X1FEC);
    CdSearchFile(rdram, ctx);
    goto after_14;
    // addiu       $a1, $a1, 0x1FEC
    ctx->r5 = ADD32(ctx->r5, 0X1FEC);
    after_14:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x162F($s0)
    do_swl(rdram, 0X162F, ctx->r16, ctx->r2);
    // swr         $v0, 0x162C($s0)
    do_swr(rdram, 0X162C, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2000
    ctx->r5 = ADD32(ctx->r5, 0X2000);
    CdSearchFile(rdram, ctx);
    goto after_15;
    // addiu       $a1, $a1, 0x2000
    ctx->r5 = ADD32(ctx->r5, 0X2000);
    after_15:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1633($s0)
    do_swl(rdram, 0X1633, ctx->r16, ctx->r2);
    // swr         $v0, 0x1630($s0)
    do_swr(rdram, 0X1630, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2014
    ctx->r5 = ADD32(ctx->r5, 0X2014);
    CdSearchFile(rdram, ctx);
    goto after_16;
    // addiu       $a1, $a1, 0x2014
    ctx->r5 = ADD32(ctx->r5, 0X2014);
    after_16:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1637($s0)
    do_swl(rdram, 0X1637, ctx->r16, ctx->r2);
    // swr         $v0, 0x1634($s0)
    do_swr(rdram, 0X1634, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2028
    ctx->r5 = ADD32(ctx->r5, 0X2028);
    CdSearchFile(rdram, ctx);
    goto after_17;
    // addiu       $a1, $a1, 0x2028
    ctx->r5 = ADD32(ctx->r5, 0X2028);
    after_17:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x163B($s0)
    do_swl(rdram, 0X163B, ctx->r16, ctx->r2);
    // swr         $v0, 0x1638($s0)
    do_swr(rdram, 0X1638, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x203C
    ctx->r5 = ADD32(ctx->r5, 0X203C);
    CdSearchFile(rdram, ctx);
    goto after_18;
    // addiu       $a1, $a1, 0x203C
    ctx->r5 = ADD32(ctx->r5, 0X203C);
    after_18:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x163F($s0)
    do_swl(rdram, 0X163F, ctx->r16, ctx->r2);
    // swr         $v0, 0x163C($s0)
    do_swr(rdram, 0X163C, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2050
    ctx->r5 = ADD32(ctx->r5, 0X2050);
    CdSearchFile(rdram, ctx);
    goto after_19;
    // addiu       $a1, $a1, 0x2050
    ctx->r5 = ADD32(ctx->r5, 0X2050);
    after_19:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1643($s0)
    do_swl(rdram, 0X1643, ctx->r16, ctx->r2);
    // swr         $v0, 0x1640($s0)
    do_swr(rdram, 0X1640, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2064
    ctx->r5 = ADD32(ctx->r5, 0X2064);
    CdSearchFile(rdram, ctx);
    goto after_20;
    // addiu       $a1, $a1, 0x2064
    ctx->r5 = ADD32(ctx->r5, 0X2064);
    after_20:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1647($s0)
    do_swl(rdram, 0X1647, ctx->r16, ctx->r2);
    // swr         $v0, 0x1644($s0)
    do_swr(rdram, 0X1644, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2078
    ctx->r5 = ADD32(ctx->r5, 0X2078);
    CdSearchFile(rdram, ctx);
    goto after_21;
    // addiu       $a1, $a1, 0x2078
    ctx->r5 = ADD32(ctx->r5, 0X2078);
    after_21:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x164B($s0)
    do_swl(rdram, 0X164B, ctx->r16, ctx->r2);
    // swr         $v0, 0x1648($s0)
    do_swr(rdram, 0X1648, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x208C
    ctx->r5 = ADD32(ctx->r5, 0X208C);
    CdSearchFile(rdram, ctx);
    goto after_22;
    // addiu       $a1, $a1, 0x208C
    ctx->r5 = ADD32(ctx->r5, 0X208C);
    after_22:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x164F($s0)
    do_swl(rdram, 0X164F, ctx->r16, ctx->r2);
    // swr         $v0, 0x164C($s0)
    do_swr(rdram, 0X164C, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x20A0
    ctx->r5 = ADD32(ctx->r5, 0X20A0);
    CdSearchFile(rdram, ctx);
    goto after_23;
    // addiu       $a1, $a1, 0x20A0
    ctx->r5 = ADD32(ctx->r5, 0X20A0);
    after_23:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1653($s0)
    do_swl(rdram, 0X1653, ctx->r16, ctx->r2);
    // swr         $v0, 0x1650($s0)
    do_swr(rdram, 0X1650, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x20B4
    ctx->r5 = ADD32(ctx->r5, 0X20B4);
    CdSearchFile(rdram, ctx);
    goto after_24;
    // addiu       $a1, $a1, 0x20B4
    ctx->r5 = ADD32(ctx->r5, 0X20B4);
    after_24:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1657($s0)
    do_swl(rdram, 0X1657, ctx->r16, ctx->r2);
    // swr         $v0, 0x1654($s0)
    do_swr(rdram, 0X1654, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x20C8
    ctx->r5 = ADD32(ctx->r5, 0X20C8);
    CdSearchFile(rdram, ctx);
    goto after_25;
    // addiu       $a1, $a1, 0x20C8
    ctx->r5 = ADD32(ctx->r5, 0X20C8);
    after_25:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x165B($s0)
    do_swl(rdram, 0X165B, ctx->r16, ctx->r2);
    // swr         $v0, 0x1658($s0)
    do_swr(rdram, 0X1658, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x20DC
    ctx->r5 = ADD32(ctx->r5, 0X20DC);
    CdSearchFile(rdram, ctx);
    goto after_26;
    // addiu       $a1, $a1, 0x20DC
    ctx->r5 = ADD32(ctx->r5, 0X20DC);
    after_26:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x165F($s0)
    do_swl(rdram, 0X165F, ctx->r16, ctx->r2);
    // swr         $v0, 0x165C($s0)
    do_swr(rdram, 0X165C, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x20F0
    ctx->r5 = ADD32(ctx->r5, 0X20F0);
    CdSearchFile(rdram, ctx);
    goto after_27;
    // addiu       $a1, $a1, 0x20F0
    ctx->r5 = ADD32(ctx->r5, 0X20F0);
    after_27:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1663($s0)
    do_swl(rdram, 0X1663, ctx->r16, ctx->r2);
    // swr         $v0, 0x1660($s0)
    do_swr(rdram, 0X1660, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2104
    ctx->r5 = ADD32(ctx->r5, 0X2104);
    CdSearchFile(rdram, ctx);
    goto after_28;
    // addiu       $a1, $a1, 0x2104
    ctx->r5 = ADD32(ctx->r5, 0X2104);
    after_28:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1667($s0)
    do_swl(rdram, 0X1667, ctx->r16, ctx->r2);
    // swr         $v0, 0x1664($s0)
    do_swr(rdram, 0X1664, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2118
    ctx->r5 = ADD32(ctx->r5, 0X2118);
    CdSearchFile(rdram, ctx);
    goto after_29;
    // addiu       $a1, $a1, 0x2118
    ctx->r5 = ADD32(ctx->r5, 0X2118);
    after_29:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x166B($s0)
    do_swl(rdram, 0X166B, ctx->r16, ctx->r2);
    // swr         $v0, 0x1668($s0)
    do_swr(rdram, 0X1668, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x212C
    ctx->r5 = ADD32(ctx->r5, 0X212C);
    CdSearchFile(rdram, ctx);
    goto after_30;
    // addiu       $a1, $a1, 0x212C
    ctx->r5 = ADD32(ctx->r5, 0X212C);
    after_30:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x166F($s0)
    do_swl(rdram, 0X166F, ctx->r16, ctx->r2);
    // swr         $v0, 0x166C($s0)
    do_swr(rdram, 0X166C, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2140
    ctx->r5 = ADD32(ctx->r5, 0X2140);
    CdSearchFile(rdram, ctx);
    goto after_31;
    // addiu       $a1, $a1, 0x2140
    ctx->r5 = ADD32(ctx->r5, 0X2140);
    after_31:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1673($s0)
    do_swl(rdram, 0X1673, ctx->r16, ctx->r2);
    // swr         $v0, 0x1670($s0)
    do_swr(rdram, 0X1670, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2154
    ctx->r5 = ADD32(ctx->r5, 0X2154);
    CdSearchFile(rdram, ctx);
    goto after_32;
    // addiu       $a1, $a1, 0x2154
    ctx->r5 = ADD32(ctx->r5, 0X2154);
    after_32:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1677($s0)
    do_swl(rdram, 0X1677, ctx->r16, ctx->r2);
    // swr         $v0, 0x1674($s0)
    do_swr(rdram, 0X1674, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2168
    ctx->r5 = ADD32(ctx->r5, 0X2168);
    CdSearchFile(rdram, ctx);
    goto after_33;
    // addiu       $a1, $a1, 0x2168
    ctx->r5 = ADD32(ctx->r5, 0X2168);
    after_33:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x167B($s0)
    do_swl(rdram, 0X167B, ctx->r16, ctx->r2);
    // swr         $v0, 0x1678($s0)
    do_swr(rdram, 0X1678, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x217C
    ctx->r5 = ADD32(ctx->r5, 0X217C);
    CdSearchFile(rdram, ctx);
    goto after_34;
    // addiu       $a1, $a1, 0x217C
    ctx->r5 = ADD32(ctx->r5, 0X217C);
    after_34:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x167F($s0)
    do_swl(rdram, 0X167F, ctx->r16, ctx->r2);
    // swr         $v0, 0x167C($s0)
    do_swr(rdram, 0X167C, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2190
    ctx->r5 = ADD32(ctx->r5, 0X2190);
    CdSearchFile(rdram, ctx);
    goto after_35;
    // addiu       $a1, $a1, 0x2190
    ctx->r5 = ADD32(ctx->r5, 0X2190);
    after_35:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1683($s0)
    do_swl(rdram, 0X1683, ctx->r16, ctx->r2);
    // swr         $v0, 0x1680($s0)
    do_swr(rdram, 0X1680, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x21A4
    ctx->r5 = ADD32(ctx->r5, 0X21A4);
    CdSearchFile(rdram, ctx);
    goto after_36;
    // addiu       $a1, $a1, 0x21A4
    ctx->r5 = ADD32(ctx->r5, 0X21A4);
    after_36:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1687($s0)
    do_swl(rdram, 0X1687, ctx->r16, ctx->r2);
    // swr         $v0, 0x1684($s0)
    do_swr(rdram, 0X1684, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x21B8
    ctx->r5 = ADD32(ctx->r5, 0X21B8);
    CdSearchFile(rdram, ctx);
    goto after_37;
    // addiu       $a1, $a1, 0x21B8
    ctx->r5 = ADD32(ctx->r5, 0X21B8);
    after_37:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x168B($s0)
    do_swl(rdram, 0X168B, ctx->r16, ctx->r2);
    // swr         $v0, 0x1688($s0)
    do_swr(rdram, 0X1688, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x21CC
    ctx->r5 = ADD32(ctx->r5, 0X21CC);
    CdSearchFile(rdram, ctx);
    goto after_38;
    // addiu       $a1, $a1, 0x21CC
    ctx->r5 = ADD32(ctx->r5, 0X21CC);
    after_38:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x168F($s0)
    do_swl(rdram, 0X168F, ctx->r16, ctx->r2);
    // swr         $v0, 0x168C($s0)
    do_swr(rdram, 0X168C, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x21E0
    ctx->r5 = ADD32(ctx->r5, 0X21E0);
    CdSearchFile(rdram, ctx);
    goto after_39;
    // addiu       $a1, $a1, 0x21E0
    ctx->r5 = ADD32(ctx->r5, 0X21E0);
    after_39:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1693($s0)
    do_swl(rdram, 0X1693, ctx->r16, ctx->r2);
    // swr         $v0, 0x1690($s0)
    do_swr(rdram, 0X1690, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x21F4
    ctx->r5 = ADD32(ctx->r5, 0X21F4);
    CdSearchFile(rdram, ctx);
    goto after_40;
    // addiu       $a1, $a1, 0x21F4
    ctx->r5 = ADD32(ctx->r5, 0X21F4);
    after_40:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x1697($s0)
    do_swl(rdram, 0X1697, ctx->r16, ctx->r2);
    // swr         $v0, 0x1694($s0)
    do_swr(rdram, 0X1694, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2208
    ctx->r5 = ADD32(ctx->r5, 0X2208);
    CdSearchFile(rdram, ctx);
    goto after_41;
    // addiu       $a1, $a1, 0x2208
    ctx->r5 = ADD32(ctx->r5, 0X2208);
    after_41:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x169B($s0)
    do_swl(rdram, 0X169B, ctx->r16, ctx->r2);
    // swr         $v0, 0x1698($s0)
    do_swr(rdram, 0X1698, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x221C
    ctx->r5 = ADD32(ctx->r5, 0X221C);
    CdSearchFile(rdram, ctx);
    goto after_42;
    // addiu       $a1, $a1, 0x221C
    ctx->r5 = ADD32(ctx->r5, 0X221C);
    after_42:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x169F($s0)
    do_swl(rdram, 0X169F, ctx->r16, ctx->r2);
    // swr         $v0, 0x169C($s0)
    do_swr(rdram, 0X169C, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2230
    ctx->r5 = ADD32(ctx->r5, 0X2230);
    CdSearchFile(rdram, ctx);
    goto after_43;
    // addiu       $a1, $a1, 0x2230
    ctx->r5 = ADD32(ctx->r5, 0X2230);
    after_43:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x16A3($s0)
    do_swl(rdram, 0X16A3, ctx->r16, ctx->r2);
    // swr         $v0, 0x16A0($s0)
    do_swr(rdram, 0X16A0, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2244
    ctx->r5 = ADD32(ctx->r5, 0X2244);
    CdSearchFile(rdram, ctx);
    goto after_44;
    // addiu       $a1, $a1, 0x2244
    ctx->r5 = ADD32(ctx->r5, 0X2244);
    after_44:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x16A7($s0)
    do_swl(rdram, 0X16A7, ctx->r16, ctx->r2);
    // swr         $v0, 0x16A4($s0)
    do_swr(rdram, 0X16A4, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2258
    ctx->r5 = ADD32(ctx->r5, 0X2258);
    CdSearchFile(rdram, ctx);
    goto after_45;
    // addiu       $a1, $a1, 0x2258
    ctx->r5 = ADD32(ctx->r5, 0X2258);
    after_45:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x16AB($s0)
    do_swl(rdram, 0X16AB, ctx->r16, ctx->r2);
    // swr         $v0, 0x16A8($s0)
    do_swr(rdram, 0X16A8, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x226C
    ctx->r5 = ADD32(ctx->r5, 0X226C);
    CdSearchFile(rdram, ctx);
    goto after_46;
    // addiu       $a1, $a1, 0x226C
    ctx->r5 = ADD32(ctx->r5, 0X226C);
    after_46:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x16AF($s0)
    do_swl(rdram, 0X16AF, ctx->r16, ctx->r2);
    // swr         $v0, 0x16AC($s0)
    do_swr(rdram, 0X16AC, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2280
    ctx->r5 = ADD32(ctx->r5, 0X2280);
    CdSearchFile(rdram, ctx);
    goto after_47;
    // addiu       $a1, $a1, 0x2280
    ctx->r5 = ADD32(ctx->r5, 0X2280);
    after_47:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x16B3($s0)
    do_swl(rdram, 0X16B3, ctx->r16, ctx->r2);
    // swr         $v0, 0x16B0($s0)
    do_swr(rdram, 0X16B0, ctx->r16, ctx->r2);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x8006AA24
    // addiu       $a1, $a1, 0x2294
    ctx->r5 = ADD32(ctx->r5, 0X2294);
    CdSearchFile(rdram, ctx);
    goto after_48;
    // addiu       $a1, $a1, 0x2294
    ctx->r5 = ADD32(ctx->r5, 0X2294);
    after_48:
    // lwl         $v0, 0x13($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X13, ctx->r29);
    // lwr         $v0, 0x10($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X10, ctx->r29);
    // nop

    // swl         $v0, 0x16B7($s0)
    do_swl(rdram, 0X16B7, ctx->r16, ctx->r2);
    // swr         $v0, 0x16B4($s0)
    do_swr(rdram, 0X16B4, ctx->r16, ctx->r2);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    // jal         0x80016030
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    sub_80016030(rdram, ctx);
    goto after_49;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_49:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addiu       $a1, $zero, 0x1E1
    ctx->r5 = ADD32(0, 0X1E1);
    // lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // jal         0x80045F90
    // addiu       $a2, $a2, 0x43F4
    ctx->r6 = ADD32(ctx->r6, 0X43F4);
    sub_80045F90(rdram, ctx);
    goto after_50;
    // addiu       $a2, $a2, 0x43F4
    ctx->r6 = ADD32(ctx->r6, 0X43F4);
    after_50:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addiu       $a1, $zero, 0x1E2
    ctx->r5 = ADD32(0, 0X1E2);
    // jal         0x80058A0C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80058A0C(rdram, ctx);
    goto after_51;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_51:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // addiu       $a0, $a0, 0x310
    ctx->r4 = ADD32(ctx->r4, 0X310);
    // lw          $a2, -0x3778($s3)
    ctx->r6 = MEM_W(-0X3778, ctx->r19);
    // addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // jal         0x80014CFC
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    sub_80014CFC(rdram, ctx);
    goto after_52;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_52:
    // lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // lw          $v0, -0x3778($s3)
    ctx->r2 = MEM_W(-0X3778, ctx->r19);
    // addiu       $a0, $a0, 0x5220
    ctx->r4 = ADD32(ctx->r4, 0X5220);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s2, $v0, $s2
    ctx->r18 = ADD32(ctx->r2, ctx->r18);
    // lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(0X0, ctx->r18);
    // addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // jal         0x80014CFC
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    sub_80014CFC(rdram, ctx);
    goto after_53;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_53:
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // addiu       $a0, $a0, -0x7378
    ctx->r4 = ADD32(ctx->r4, -0X7378);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(0X0, ctx->r18);
    // addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // jal         0x80014CFC
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    sub_80014CFC(rdram, ctx);
    goto after_54;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_54:
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // addiu       $a0, $a0, -0x2D68
    ctx->r4 = ADD32(ctx->r4, -0X2D68);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(0X0, ctx->r18);
    // addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // jal         0x80014CFC
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    sub_80014CFC(rdram, ctx);
    goto after_55;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_55:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // addiu       $a0, $a0, -0x874
    ctx->r4 = ADD32(ctx->r4, -0X874);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(0X0, ctx->r18);
    // addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // jal         0x80014CFC
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    sub_80014CFC(rdram, ctx);
    goto after_56;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_56:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // addiu       $a0, $a0, -0x23BC
    ctx->r4 = ADD32(ctx->r4, -0X23BC);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(0X0, ctx->r18);
    // addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // jal         0x80014CFC
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    sub_80014CFC(rdram, ctx);
    goto after_57;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_57:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(0X0, ctx->r18);
    // addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // jal         0x80014CFC
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    sub_80014CFC(rdram, ctx);
    goto after_58;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_58:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // addiu       $a0, $a0, 0x7810
    ctx->r4 = ADD32(ctx->r4, 0X7810);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(0X0, ctx->r18);
    // addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // jal         0x80014CFC
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    sub_80014CFC(rdram, ctx);
    goto after_59;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_59:
    // lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // addiu       $s0, $s0, -0x4F78
    ctx->r16 = ADD32(ctx->r16, -0X4F78);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
    // lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(0X0, ctx->r18);
    // addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // jal         0x80014CFC
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    sub_80014CFC(rdram, ctx);
    goto after_60;
    // srl         $a2, $a2, 2
    ctx->r6 = S32(U32(ctx->r6) >> 2);
    after_60:
    // addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // jal         0x800339C4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_800339C4(rdram, ctx);
    goto after_61;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_61:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_62;
    // nop

    after_62:
    // jal         0x8003EA20
    // nop

    sub_8003EA20(rdram, ctx);
    goto after_63;
    // nop

    after_63:
    // jal         0x80052D10
    // nop

    sub_80052D10(rdram, ctx);
    goto after_64;
    // nop

    after_64:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop
//    printf("\nsub_80044674  end\n");
    return;
    // nop

;}
