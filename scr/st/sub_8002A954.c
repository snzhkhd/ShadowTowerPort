#include "recomp.h"
#include "disable_warnings.h"

void sub_8002A954(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x1110
    ctx->r6 = ADD32(ctx->r2, 0X1110);
    // sw          $s4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r20;
    // lui         $s4, 0x1F80
    ctx->r20 = S32(0X1F80 << 16);
    // andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // sw          $ra, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r31;
    // sw          $fp, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r30;
    // sw          $s7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r23;
    // sw          $s6, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r22;
    // sw          $s5, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r21;
    // sw          $s3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r19;
    // sw          $s2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r18;
    // sw          $s1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r17;
    // beq         $v0, $zero, L_8002A9F0
    if (ctx->r2 == 0) {
        // sw          $s0, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r16;
        goto L_8002A9F0;
    }
    // sw          $s0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r16;
    // addiu       $t0, $a2, 0x30
    ctx->r8 = ADD32(ctx->r6, 0X30);
L_8002A99C:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lwl         $a0, 0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r6);
    // lwr         $a0, 0x8($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r6);
    // lwl         $a1, 0xF($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r6);
    // lwr         $a1, 0xC($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r6);
    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // swl         $v1, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r3);
    // swr         $v1, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r3);
    // swl         $a0, 0xB($a3)
    do_swl(rdram, 0XB, ctx->r7, ctx->r4);
    // swr         $a0, 0x8($a3)
    do_swr(rdram, 0X8, ctx->r7, ctx->r4);
    // swl         $a1, 0xF($a3)
    do_swl(rdram, 0XF, ctx->r7, ctx->r5);
    // swr         $a1, 0xC($a3)
    do_swr(rdram, 0XC, ctx->r7, ctx->r5);
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_8002A99C
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8002A99C;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // j           L_8002AA24
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    goto L_8002AA24;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
L_8002A9F0:
    // addiu       $t0, $a2, 0x30
    ctx->r8 = ADD32(ctx->r6, 0X30);
L_8002A9F4:
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
    // bne         $a2, $t0, L_8002A9F4
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8002A9F4;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
L_8002AA24:
    // addiu       $a2, $v0, 0x7F38
    ctx->r6 = ADD32(ctx->r2, 0X7F38);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x53($sp)
    do_swl(rdram, 0X53, ctx->r29, ctx->r3);
    // swr         $v1, 0x50($sp)
    do_swr(rdram, 0X50, ctx->r29, ctx->r3);
    // swl         $a0, 0x57($sp)
    do_swl(rdram, 0X57, ctx->r29, ctx->r4);
    // swr         $a0, 0x54($sp)
    do_swr(rdram, 0X54, ctx->r29, ctx->r4);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F40
    ctx->r6 = ADD32(ctx->r2, 0X7F40);
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
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F48
    ctx->r6 = ADD32(ctx->r2, 0X7F48);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x63($sp)
    do_swl(rdram, 0X63, ctx->r29, ctx->r3);
    // swr         $v1, 0x60($sp)
    do_swr(rdram, 0X60, ctx->r29, ctx->r3);
    // swl         $a0, 0x67($sp)
    do_swl(rdram, 0X67, ctx->r29, ctx->r4);
    // swr         $a0, 0x64($sp)
    do_swr(rdram, 0X64, ctx->r29, ctx->r4);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F50
    ctx->r6 = ADD32(ctx->r2, 0X7F50);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x6B($sp)
    do_swl(rdram, 0X6B, ctx->r29, ctx->r3);
    // swr         $v1, 0x68($sp)
    do_swr(rdram, 0X68, ctx->r29, ctx->r3);
    // swl         $a0, 0x6F($sp)
    do_swl(rdram, 0X6F, ctx->r29, ctx->r4);
    // swr         $a0, 0x6C($sp)
    do_swr(rdram, 0X6C, ctx->r29, ctx->r4);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x1140
    ctx->r6 = ADD32(ctx->r2, 0X1140);
    // andi        $v0, $a2, 0x3
    ctx->r2 = ctx->r6 & 0X3;
    // beq         $v0, $zero, L_8002AB2C
    if (ctx->r2 == 0) {
        // addiu       $a3, $sp, 0x70
        ctx->r7 = ADD32(ctx->r29, 0X70);
        goto L_8002AB2C;
    }
    // addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    // addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8002AAD8:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lwl         $a0, 0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r6);
    // lwr         $a0, 0x8($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r6);
    // lwl         $a1, 0xF($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r6);
    // lwr         $a1, 0xC($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r6);
    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // swl         $v1, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r3);
    // swr         $v1, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r3);
    // swl         $a0, 0xB($a3)
    do_swl(rdram, 0XB, ctx->r7, ctx->r4);
    // swr         $a0, 0x8($a3)
    do_swr(rdram, 0X8, ctx->r7, ctx->r4);
    // swl         $a1, 0xF($a3)
    do_swl(rdram, 0XF, ctx->r7, ctx->r5);
    // swr         $a1, 0xC($a3)
    do_swr(rdram, 0XC, ctx->r7, ctx->r5);
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_8002AAD8
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8002AAD8;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // j           L_8002AB5C
    // nop

    goto L_8002AB5C;
    // nop

L_8002AB2C:
    // addiu       $t0, $a2, 0x50
    ctx->r8 = ADD32(ctx->r6, 0X50);
L_8002AB30:
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
    // bne         $a2, $t0, L_8002AB30
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8002AB30;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_8002AB5C:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // nop

    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // jal         0x800174C4
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    ST_BeginDraw2D(rdram, ctx);
    goto after_0;
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    after_0:
    // lw          $v0, 0x74($gp)
    ctx->r2 = MEM_W(0X74, ctx->r28);
    // nop

    // slti        $v0, $v0, 0x10
    ctx->r2 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_8002AB94
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_8002AB94;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // lhu         $v1, 0x74($gp)
    ctx->r3 = MEM_HU(0X74, ctx->r28);
    // j           L_8002ABA0
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_8002ABA0;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8002AB94:
    // lhu         $v0, 0x74($gp)
    ctx->r2 = MEM_HU(0X74, ctx->r28);
    // nop

    // addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
L_8002ABA0:
    // sh          $v0, 0x360($s4)
    MEM_H(0X360, ctx->r20) = ctx->r2;
    // lbu         $v1, 0x360($s4)
    ctx->r3 = MEM_BU(0X360, ctx->r20);
    // addiu       $v0, $zero, 0x48
    ctx->r2 = ADD32(0, 0X48);
    // sb          $v0, 0x310($s4)
    MEM_B(0X310, ctx->r20) = ctx->r2;
    // sb          $v0, 0x300($s4)
    MEM_B(0X300, ctx->r20) = ctx->r2;
    // sb          $v0, 0x311($s4)
    MEM_B(0X311, ctx->r20) = ctx->r2;
    // sb          $v0, 0x301($s4)
    MEM_B(0X301, ctx->r20) = ctx->r2;
    // sb          $v0, 0x312($s4)
    MEM_B(0X312, ctx->r20) = ctx->r2;
    // sb          $v0, 0x302($s4)
    MEM_B(0X302, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x62
    ctx->r2 = ADD32(0, 0X62);
    // sb          $v0, 0x318($s4)
    MEM_B(0X318, ctx->r20) = ctx->r2;
    // sb          $v0, 0x308($s4)
    MEM_B(0X308, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
    // sb          $v0, 0x319($s4)
    MEM_B(0X319, ctx->r20) = ctx->r2;
    // sb          $v0, 0x309($s4)
    MEM_B(0X309, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sb          $v0, 0x31A($s4)
    MEM_B(0X31A, ctx->r20) = ctx->r2;
    // sb          $v0, 0x30A($s4)
    MEM_B(0X30A, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    // sb          $v0, 0x30B($s4)
    MEM_B(0X30B, ctx->r20) = ctx->r2;
    // sb          $v0, 0x303($s4)
    MEM_B(0X303, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x29
    ctx->r2 = ADD32(0, 0X29);
    // sb          $v0, 0x31B($s4)
    MEM_B(0X31B, ctx->r20) = ctx->r2;
    // sb          $v0, 0x313($s4)
    MEM_B(0X313, ctx->r20) = ctx->r2;
    // lbu         $v0, 0x360($s4)
    ctx->r2 = MEM_BU(0X360, ctx->r20);
    // sb          $zero, 0x32E($s4)
    MEM_B(0X32E, ctx->r20) = 0;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sb          $v1, 0x32C($s4)
    MEM_B(0X32C, ctx->r20) = ctx->r3;
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E58($v1)
    ctx->r3 = MEM_HU(-0X7E58, ctx->r3);
    // addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // beq         $v1, $zero, L_8002AE5C
    if (ctx->r3 == 0) {
        // sb          $v0, 0x32D($s4)
        MEM_B(0X32D, ctx->r20) = ctx->r2;
        goto L_8002AE5C;
    }
    // sb          $v0, 0x32D($s4)
    MEM_B(0X32D, ctx->r20) = ctx->r2;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $s5, $v0, 0xD50
    ctx->r21 = ADD32(ctx->r2, 0XD50);
    // addiu       $s6, $s5, 0xC00
    ctx->r22 = ADD32(ctx->r21, 0XC00);
    // addiu       $fp, $s4, 0x308
    ctx->r30 = ADD32(ctx->r20, 0X308);
    // addiu       $s7, $s4, 0x300
    ctx->r23 = ADD32(ctx->r20, 0X300);
    // addiu       $s1, $zero, 0x36
    ctx->r17 = ADD32(0, 0X36);
    // addu        $s3, $s4, $zero
    ctx->r19 = ADD32(ctx->r20, 0);
L_8002AC4C:
    // lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(0X8, ctx->r19);
    // nop

    // slti        $v0, $v1, 0x5A
    ctx->r2 = SIGNED(ctx->r3) < 0X5A ? 1 : 0;
    // bne         $v0, $zero, L_8002ACB0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x59
        ctx->r2 = ADD32(0, 0X59);
        goto L_8002ACB0;
    }
    // addiu       $v0, $zero, 0x59
    ctx->r2 = ADD32(0, 0X59);
    // addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // bne         $v1, $v0, L_8002AC78
    if (ctx->r3 != ctx->r2) {
        // addiu       $a1, $zero, 0x35
        ctx->r5 = ADD32(0, 0X35);
        goto L_8002AC78;
    }
    // addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    // lhu         $a0, 0x4D2($s5)
    ctx->r4 = MEM_HU(0X4D2, ctx->r21);
    // j           L_8002ACC4
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
    goto L_8002ACC4;
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
L_8002AC78:
    // lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(0X4, ctx->r20);
    // nop

    // bne         $v1, $v0, L_8002ACA0
    if (ctx->r3 != ctx->r2) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_8002ACA0;
    }
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // lhu         $a0, 0x410($v0)
    ctx->r4 = MEM_HU(0X410, ctx->r2);
    // j           L_8002ACC8
    // addiu       $a3, $s4, 0x308
    ctx->r7 = ADD32(ctx->r20, 0X308);
    goto L_8002ACC8;
    // addiu       $a3, $s4, 0x308
    ctx->r7 = ADD32(ctx->r20, 0X308);
L_8002ACA0:
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // lhu         $a0, 0x410($v0)
    ctx->r4 = MEM_HU(0X410, ctx->r2);
    // j           L_8002ACC4
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
    goto L_8002ACC4;
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
L_8002ACB0:
    // bne         $v1, $v0, L_8002ACD8
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8002ACD8;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
    // lhu         $a0, 0x4D4($s5)
    ctx->r4 = MEM_HU(0X4D4, ctx->r21);
L_8002ACC4:
    // addiu       $a3, $s4, 0x300
    ctx->r7 = ADD32(ctx->r20, 0X300);
L_8002ACC8:
    // jal         0x8002732C
    // addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    sub_8002732C(rdram, ctx);
    goto after_1;
    // addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    after_1:
    // j           L_8002AE44
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    goto L_8002AE44;
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_8002ACD8:
    // lbu         $v0, 0x5929($v0)
    ctx->r2 = MEM_BU(0X5929, ctx->r2);
    // nop

    // bne         $v1, $v0, L_8002AD94
    if (ctx->r3 != ctx->r2) {
        // addiu       $a1, $zero, 0x43
        ctx->r5 = ADD32(0, 0X43);
        goto L_8002AD94;
    }
    // addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // lhu         $a0, 0x578($v0)
    ctx->r4 = MEM_HU(0X578, ctx->r2);
    // addu        $a3, $fp, $zero
    ctx->r7 = ADD32(ctx->r30, 0);
    // jal         0x8002732C
    // addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    sub_8002732C(rdram, ctx);
    goto after_2;
    // addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    after_2:
    // lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(0X8, ctx->r19);
    // addiu       $t1, $t1, -0x45F8
    ctx->r9 = ADD32(ctx->r9, -0X45F8);
    // addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // lbu         $v0, 0x16E4($v0)
    ctx->r2 = MEM_BU(0X16E4, ctx->r2);
    // nop

    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $v0, $sp, $v1
    ctx->r2 = ADD32(ctx->r29, ctx->r3);
    // lbu         $v0, 0x10($v0)
    ctx->r2 = MEM_BU(0X10, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_8002AD4C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002AD4C;
    }
    // nop

    // break       7
    do_break(2147659080);
L_8002AD4C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8002AD64
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8002AD64;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_8002AD64
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_8002AD64;
    }
    // nop

    // break       6
    do_break(2147659104);
L_8002AD64:
    // mflo        $a0
    ctx->r4 = lo;
    // addiu       $a1, $zero, 0xDF
    ctx->r5 = ADD32(0, 0XDF);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addiu       $a3, $s4, 0x318
    ctx->r7 = ADD32(ctx->r20, 0X318);
    // lui         $v0, 0x300
    ctx->r2 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    sub_80027440(rdram, ctx);
    goto after_3;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    after_3:
    // addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // j           L_8002AE3C
    // addu        $a3, $fp, $zero
    ctx->r7 = ADD32(ctx->r30, 0);
    goto L_8002AE3C;
    // addu        $a3, $fp, $zero
    ctx->r7 = ADD32(ctx->r30, 0);
L_8002AD94:
    // andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // lhu         $a0, 0x578($v0)
    ctx->r4 = MEM_HU(0X578, ctx->r2);
    // addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    // jal         0x8002732C
    // addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    sub_8002732C(rdram, ctx);
    goto after_4;
    // addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    after_4:
    // lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // lw          $v1, 0x8($s3)
    ctx->r3 = MEM_W(0X8, ctx->r19);
    // addiu       $t1, $t1, -0x45F8
    ctx->r9 = ADD32(ctx->r9, -0X45F8);
    // addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // lbu         $v0, 0x16E4($v0)
    ctx->r2 = MEM_BU(0X16E4, ctx->r2);
    // nop

    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addu        $v0, $sp, $v1
    ctx->r2 = ADD32(ctx->r29, ctx->r3);
    // lbu         $v0, 0x10($v0)
    ctx->r2 = MEM_BU(0X10, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_8002ADF8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002ADF8;
    }
    // nop

    // break       7
    do_break(2147659252);
L_8002ADF8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8002AE10
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8002AE10;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_8002AE10
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_8002AE10;
    }
    // nop

    // break       6
    do_break(2147659276);
L_8002AE10:
    // mflo        $a0
    ctx->r4 = lo;
    // addiu       $a1, $zero, 0xDF
    ctx->r5 = ADD32(0, 0XDF);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addiu       $a3, $s4, 0x310
    ctx->r7 = ADD32(ctx->r20, 0X310);
    // lui         $v0, 0x300
    ctx->r2 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    sub_80027440(rdram, ctx);
    goto after_5;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    after_5:
    // addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
L_8002AE3C:
    // jal         0x80026ECC
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    sub_80026ECC(rdram, ctx);
    goto after_6;
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    after_6:
L_8002AE44:
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // slti        $v0, $s2, 0xA
    ctx->r2 = SIGNED(ctx->r18) < 0XA ? 1 : 0;
    // bne         $v0, $zero, L_8002AC4C
    if (ctx->r2 != 0) {
        // addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
        goto L_8002AC4C;
    }
    // addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // j           L_8002B110
    // nop

    goto L_8002B110;
    // nop

L_8002AE5C:
    // addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    // ori         $a3, $s4, 0x308
    ctx->r7 = ctx->r20 | 0X308;
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xD50
    ctx->r2 = ADD32(ctx->r2, 0XD50);
    // addiu       $v1, $v0, 0xC00
    ctx->r3 = ADD32(ctx->r2, 0XC00);
    // addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // addiu       $s1, $zero, 0x5D
    ctx->r17 = ADD32(0, 0X5D);
    // lhu         $a0, 0x4B0($v0)
    ctx->r4 = MEM_HU(0X4B0, ctx->r2);
    // addiu       $s0, $v0, 0x2
    ctx->r16 = ADD32(ctx->r2, 0X2);
    // jal         0x8002732C
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    sub_8002732C(rdram, ctx);
    goto after_7;
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    after_7:
    // addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
L_8002AE94:
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
    // addiu       $a3, $s4, 0x308
    ctx->r7 = ADD32(ctx->r20, 0X308);
    // addiu       $s1, $s1, 0x1E
    ctx->r17 = ADD32(ctx->r17, 0X1E);
    // lhu         $a0, 0x4B0($s0)
    ctx->r4 = MEM_HU(0X4B0, ctx->r16);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // jal         0x8002732C
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    sub_8002732C(rdram, ctx);
    goto after_8;
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    after_8:
    // slti        $v0, $s2, 0x5
    ctx->r2 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_8002AE94
    if (ctx->r2 != 0) {
        // addiu       $a1, $zero, 0x48
        ctx->r5 = ADD32(0, 0X48);
        goto L_8002AE94;
    }
    // addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // lw          $v1, 0x4($s4)
    ctx->r3 = MEM_W(0X4, ctx->r20);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_8002AF30
    if (ctx->r3 == ctx->r2) {
        // addiu       $a1, $zero, 0x56
        ctx->r5 = ADD32(0, 0X56);
        goto L_8002AF30;
    }
    // addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    // addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    // addiu       $s2, $s4, 0x300
    ctx->r18 = ADD32(ctx->r20, 0X300);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // addiu       $s0, $s0, 0xD50
    ctx->r16 = ADD32(ctx->r16, 0XD50);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lhu         $a0, 0x410($v0)
    ctx->r4 = MEM_HU(0X410, ctx->r2);
    // addiu       $s1, $s0, 0xC00
    ctx->r17 = ADD32(ctx->r16, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    sub_8002732C(rdram, ctx);
    goto after_9;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_9:
    // addiu       $a2, $zero, 0x4F
    ctx->r6 = ADD32(0, 0X4F);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v0, 0x5929($v0)
    ctx->r2 = MEM_BU(0X5929, ctx->r2);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $s0, $v0, $s0
    ctx->r16 = ADD32(ctx->r2, ctx->r16);
    // addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // lhu         $a0, 0x578($s0)
    ctx->r4 = MEM_HU(0X578, ctx->r16);
    // lhu         $a1, 0x70($v0)
    ctx->r5 = MEM_HU(0X70, ctx->r2);
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // addiu       $a1, $a1, 0x64
    ctx->r5 = ADD32(ctx->r5, 0X64);
    // j           L_8002AF60
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    goto L_8002AF60;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
L_8002AF30:
    // addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // addiu       $a2, $zero, 0x49
    ctx->r6 = ADD32(0, 0X49);
    // ori         $a3, $s4, 0x300
    ctx->r7 = ctx->r20 | 0X300;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v0, 0x5929($v0)
    ctx->r2 = MEM_BU(0X5929, ctx->r2);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v0, 0x578($v0)
    ctx->r2 = MEM_HU(0X578, ctx->r2);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
L_8002AF60:
    // jal         0x8002732C
    // addiu       $s2, $s4, 0x310
    ctx->r18 = ADD32(ctx->r20, 0X310);
    sub_8002732C(rdram, ctx);
    goto after_10;
    // addiu       $s2, $s4, 0x310
    ctx->r18 = ADD32(ctx->r20, 0X310);
    after_10:
    // addiu       $a1, $zero, 0xB3
    ctx->r5 = ADD32(0, 0XB3);
    // addiu       $a2, $zero, 0x6B
    ctx->r6 = ADD32(0, 0X6B);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x70D8
    ctx->r16 = ADD32(ctx->r16, -0X70D8);
    // lbu         $a0, 0x27($s0)
    ctx->r4 = MEM_BU(0X27, ctx->r16);
    // lui         $s1, 0x300
    ctx->r17 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_80027440(rdram, ctx);
    goto after_11;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_11:
    // addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // addiu       $a1, $zero, 0xD5
    ctx->r5 = ADD32(0, 0XD5);
    // addiu       $a2, $zero, 0x6B
    ctx->r6 = ADD32(0, 0X6B);
    // addiu       $s3, $s4, 0x300
    ctx->r19 = ADD32(ctx->r20, 0X300);
    // jal         0x80026ECC
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    sub_80026ECC(rdram, ctx);
    goto after_12;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_12:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a0, $a0, 0x63
    ctx->r4 = ctx->r4 | 0X63;
    // addiu       $a1, $zero, 0xDD
    ctx->r5 = ADD32(0, 0XDD);
    // addiu       $a2, $zero, 0x6B
    ctx->r6 = ADD32(0, 0X6B);
    // jal         0x80027440
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_80027440(rdram, ctx);
    goto after_13;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_13:
    // addiu       $a1, $zero, 0xB3
    ctx->r5 = ADD32(0, 0XB3);
    // addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    // lhu         $a0, 0x28($s0)
    ctx->r4 = MEM_HU(0X28, ctx->r16);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_80027440(rdram, ctx);
    goto after_14;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_14:
    // addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // addiu       $a1, $zero, 0xD5
    ctx->r5 = ADD32(0, 0XD5);
    // addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    // jal         0x80026ECC
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    sub_80026ECC(rdram, ctx);
    goto after_15;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_15:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a0, $a0, 0x109
    ctx->r4 = ctx->r4 | 0X109;
    // addiu       $a1, $zero, 0xDD
    ctx->r5 = ADD32(0, 0XDD);
    // addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    // jal         0x80027440
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_80027440(rdram, ctx);
    goto after_16;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_16:
    // addiu       $a1, $zero, 0xB3
    ctx->r5 = ADD32(0, 0XB3);
    // addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    // lhu         $a0, 0x30($s0)
    ctx->r4 = MEM_HU(0X30, ctx->r16);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_80027440(rdram, ctx);
    goto after_17;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_17:
    // addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // addiu       $a1, $zero, 0xD5
    ctx->r5 = ADD32(0, 0XD5);
    // addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    // jal         0x80026ECC
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    sub_80026ECC(rdram, ctx);
    goto after_18;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_18:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a0, $a0, 0x276
    ctx->r4 = ctx->r4 | 0X276;
    // addiu       $a1, $zero, 0xDD
    ctx->r5 = ADD32(0, 0XDD);
    // addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    // jal         0x80027440
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_80027440(rdram, ctx);
    goto after_19;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_19:
    // lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(0X34, ctx->r16);
    // lui         $v1, 0x8888
    ctx->r3 = S32(0X8888 << 16);
    // ori         $v1, $v1, 0x8889
    ctx->r3 = ctx->r3 | 0X8889;
    // multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t1
    ctx->r9 = hi;
    // srl         $a0, $t1, 5
    ctx->r4 = S32(U32(ctx->r9) >> 5);
    // nop

    // multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $zero, 0xC7
    ctx->r5 = ADD32(0, 0XC7);
    // addiu       $a2, $zero, 0xC6
    ctx->r6 = ADD32(0, 0XC6);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // mfhi        $t1
    ctx->r9 = hi;
    // srl         $s5, $t1, 5
    ctx->r21 = S32(U32(ctx->r9) >> 5);
    // addu        $v1, $s5, $zero
    ctx->r3 = ADD32(ctx->r21, 0);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $s5, $a0, $v0
    ctx->r21 = SUB32(ctx->r4, ctx->r2);
    // andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // jal         0x80027440
    // or          $a0, $v1, $a0
    ctx->r4 = ctx->r3 | ctx->r4;
    sub_80027440(rdram, ctx);
    goto after_20;
    // or          $a0, $v1, $a0
    ctx->r4 = ctx->r3 | ctx->r4;
    after_20:
    // addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // addiu       $a2, $zero, 0xC6
    ctx->r6 = ADD32(0, 0XC6);
    // jal         0x80026ECC
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    sub_80026ECC(rdram, ctx);
    goto after_21;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_21:
    // lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // mult        $s5, $v0
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // addiu       $a2, $zero, 0xC6
    ctx->r6 = ADD32(0, 0XC6);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sra         $v0, $s5, 31
    ctx->r2 = S32(ctx->r21) >> 31;
    // lui         $s1, 0x100
    ctx->r17 = S32(0X100 << 16);
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $s0, $t1, 2
    ctx->r16 = S32(ctx->r9) >> 2;
    // subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // jal         0x80027440
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_80027440(rdram, ctx);
    goto after_22;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_22:
    // sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16) << 2;
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // subu        $a0, $s5, $a0
    ctx->r4 = SUB32(ctx->r21, ctx->r4);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    // addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    // addiu       $a2, $zero, 0xC6
    ctx->r6 = ADD32(0, 0XC6);
    // jal         0x80027440
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_80027440(rdram, ctx);
    goto after_23;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_23:
L_8002B110:
    // lw          $a0, 0x74($gp)
    ctx->r4 = MEM_W(0X74, ctx->r28);
    // nop

    // addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // bgez        $v1, L_8002B128
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8002B128;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_8002B128:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sw          $v0, 0x74($gp)
    MEM_W(0X74, ctx->r28) = ctx->r2;
    // slti        $v0, $v0, 0x10
    ctx->r2 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_8002B150
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_8002B150;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // lhu         $v1, 0x74($gp)
    ctx->r3 = MEM_HU(0X74, ctx->r28);
    // j           L_8002B15C
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_8002B15C;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8002B150:
    // lhu         $v0, 0x74($gp)
    ctx->r2 = MEM_HU(0X74, ctx->r28);
    // nop

    // addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
L_8002B15C:
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E58($v1)
    ctx->r3 = MEM_HU(-0X7E58, ctx->r3);
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sb          $v0, 0x40($sp)
    MEM_B(0X40, ctx->r29) = ctx->r2;
    // sb          $v0, 0x41($sp)
    MEM_B(0X41, ctx->r29) = ctx->r2;
    // beq         $v1, $zero, L_8002B1FC
    if (ctx->r3 == 0) {
        // sb          $v0, 0x42($sp)
        MEM_B(0X42, ctx->r29) = ctx->r2;
        goto L_8002B1FC;
    }
    // sb          $v0, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lw          $v0, -0x7E74($v0)
    ctx->r2 = MEM_W(-0X7E74, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8002B1BC
    if (ctx->r2 == 0) {
        // ori         $a0, $s4, 0x33C
        ctx->r4 = ctx->r20 | 0X33C;
        goto L_8002B1BC;
    }
    // ori         $a0, $s4, 0x33C
    ctx->r4 = ctx->r20 | 0X33C;
    // ori         $a1, $s4, 0x32C
    ctx->r5 = ctx->r20 | 0X32C;
    // addiu       $a2, $zero, 0xC00
    ctx->r6 = ADD32(0, 0XC00);
    // addiu       $v0, $zero, 0xA0
    ctx->r2 = ADD32(0, 0XA0);
    // sh          $v0, 0x33C($s4)
    MEM_H(0X33C, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x2B
    ctx->r2 = ADD32(0, 0X2B);
    // sh          $v0, 0x33E($s4)
    MEM_H(0X33E, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x340($s4)
    MEM_H(0X340, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // jal         0x8002916C
    // sh          $v0, 0x342($s4)
    MEM_H(0X342, ctx->r20) = ctx->r2;
    sub_8002916C(rdram, ctx);
    goto after_24;
    // sh          $v0, 0x342($s4)
    MEM_H(0X342, ctx->r20) = ctx->r2;
    after_24:
L_8002B1BC:
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lw          $v1, -0x7E74($v1)
    ctx->r3 = MEM_W(-0X7E74, ctx->r3);
    // addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // beq         $v1, $v0, L_8002B1FC
    if (ctx->r3 == ctx->r2) {
        // ori         $a0, $s4, 0x33C
        ctx->r4 = ctx->r20 | 0X33C;
        goto L_8002B1FC;
    }
    // ori         $a0, $s4, 0x33C
    ctx->r4 = ctx->r20 | 0X33C;
    // ori         $a1, $s4, 0x32C
    ctx->r5 = ctx->r20 | 0X32C;
    // addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // addiu       $v0, $zero, 0xA0
    ctx->r2 = ADD32(0, 0XA0);
    // sh          $v0, 0x33C($s4)
    MEM_H(0X33C, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0xDC
    ctx->r2 = ADD32(0, 0XDC);
    // sh          $v0, 0x33E($s4)
    MEM_H(0X33E, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x340($s4)
    MEM_H(0X340, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // jal         0x8002916C
    // sh          $v0, 0x342($s4)
    MEM_H(0X342, ctx->r20) = ctx->r2;
    sub_8002916C(rdram, ctx);
    goto after_25;
    // sh          $v0, 0x342($s4)
    MEM_H(0X342, ctx->r20) = ctx->r2;
    after_25:
L_8002B1FC:
    // addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // sh          $v0, 0x33C($s4)
    MEM_H(0X33C, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sh          $v0, 0x33E($s4)
    MEM_H(0X33E, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x108
    ctx->r2 = ADD32(0, 0X108);
    // sh          $v0, 0x340($s4)
    MEM_H(0X340, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0xA8
    ctx->r2 = ADD32(0, 0XA8);
    // sh          $v0, 0x342($s4)
    MEM_H(0X342, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // sb          $v0, 0x338($s4)
    MEM_B(0X338, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x58
    ctx->r2 = ADD32(0, 0X58);
    // sb          $v0, 0x339($s4)
    MEM_B(0X339, ctx->r20) = ctx->r2;
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E58($v1)
    ctx->r3 = MEM_HU(-0X7E58, ctx->r3);
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // beq         $v1, $zero, L_8002B250
    if (ctx->r3 == 0) {
        // sb          $v0, 0x33A($s4)
        MEM_B(0X33A, ctx->r20) = ctx->r2;
        goto L_8002B250;
    }
    // sb          $v0, 0x33A($s4)
    MEM_B(0X33A, ctx->r20) = ctx->r2;
    // addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // ori         $a1, $s4, 0x32C
    ctx->r5 = ctx->r20 | 0X32C;
    // j           L_8002B25C
    // addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    goto L_8002B25C;
    // addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
L_8002B250:
    // addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // ori         $a1, $s4, 0x32C
    ctx->r5 = ctx->r20 | 0X32C;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8002B25C:
    // jal         0x8002916C
    // nop

    sub_8002916C(rdram, ctx);
    goto after_26;
    // nop

    after_26:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_27;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_27:
    // ori         $a0, $s4, 0x33C
    ctx->r4 = ctx->r20 | 0X33C;
    // ori         $a1, $s4, 0x338
    ctx->r5 = ctx->r20 | 0X338;
    // addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // jal         0x80027D18
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_80027D18(rdram, ctx);
    goto after_28;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_28:
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // addiu       $a2, $zero, 0x120
    ctx->r6 = ADD32(0, 0X120);
    // jal         0x80029618
    // addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    sub_80029618(rdram, ctx);
    goto after_29;
    // addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    after_29:
    // jal         0x800175A4
    // nop

    sub_800175A4(rdram, ctx);
    goto after_30;
    // nop

    after_30:
    // jal         0x8002948C
    // nop

    sub_8002948C(rdram, ctx);
    goto after_31;
    // nop

    after_31:
    // jal         0x80017634
    // nop

    sub_80017634(rdram, ctx);
    goto after_32;
    // nop

    after_32:
    // lw          $ra, 0xEC($sp)
    ctx->r31 = MEM_W(0XEC, ctx->r29);
    // lw          $fp, 0xE8($sp)
    ctx->r30 = MEM_W(0XE8, ctx->r29);
    // lw          $s7, 0xE4($sp)
    ctx->r23 = MEM_W(0XE4, ctx->r29);
    // lw          $s6, 0xE0($sp)
    ctx->r22 = MEM_W(0XE0, ctx->r29);
    // lw          $s5, 0xDC($sp)
    ctx->r21 = MEM_W(0XDC, ctx->r29);
    // lw          $s4, 0xD8($sp)
    ctx->r20 = MEM_W(0XD8, ctx->r29);
    // lw          $s3, 0xD4($sp)
    ctx->r19 = MEM_W(0XD4, ctx->r29);
    // lw          $s2, 0xD0($sp)
    ctx->r18 = MEM_W(0XD0, ctx->r29);
    // lw          $s1, 0xCC($sp)
    ctx->r17 = MEM_W(0XCC, ctx->r29);
    // lw          $s0, 0xC8($sp)
    ctx->r16 = MEM_W(0XC8, ctx->r29);
    // addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    // jr          $ra
    // nop

    return;
    // nop

;}
