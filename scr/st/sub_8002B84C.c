#include "recomp.h"
#include "disable_warnings.h"

void sub_8002B84C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r30;
    // sw          $s7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r23;
    // sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, 0x1194
    ctx->r6 = ADD32(ctx->r2, 0X1194);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // lwl         $a1, 0xB($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XB, ctx->r6);
    // lwr         $a1, 0x8($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X8, ctx->r6);
    // swl         $v1, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r3);
    // swr         $v1, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r3);
    // swl         $a0, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r4);
    // swr         $a0, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r4);
    // swl         $a1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r5);
    // swr         $a1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r5);
    // lwl         $v1, 0xF($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0XF, ctx->r6);
    // lwr         $v1, 0xC($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0XC, ctx->r6);
    // nop

    // swl         $v1, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r3);
    // swr         $v1, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r3);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x10F0
    ctx->r6 = ADD32(ctx->r2, 0X10F0);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // lwl         $a1, 0xB($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XB, ctx->r6);
    // lwr         $a1, 0x8($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X8, ctx->r6);
    // swl         $v1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r3);
    // swr         $v1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r3);
    // swl         $a0, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r4);
    // swr         $a0, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r4);
    // swl         $a1, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r5);
    // swr         $a1, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r5);
    // lwl         $v1, 0xF($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0XF, ctx->r6);
    // lwr         $v1, 0xC($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0XC, ctx->r6);
    // nop

    // swl         $v1, 0x37($sp)
    do_swl(rdram, 0X37, ctx->r29, ctx->r3);
    // swr         $v1, 0x34($sp)
    do_swr(rdram, 0X34, ctx->r29, ctx->r3);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x1100
    ctx->r6 = ADD32(ctx->r2, 0X1100);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // lwl         $a1, 0xB($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XB, ctx->r6);
    // lwr         $a1, 0x8($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X8, ctx->r6);
    // swl         $v1, 0x3B($sp)
    do_swl(rdram, 0X3B, ctx->r29, ctx->r3);
    // swr         $v1, 0x38($sp)
    do_swr(rdram, 0X38, ctx->r29, ctx->r3);
    // swl         $a0, 0x3F($sp)
    do_swl(rdram, 0X3F, ctx->r29, ctx->r4);
    // swr         $a0, 0x3C($sp)
    do_swr(rdram, 0X3C, ctx->r29, ctx->r4);
    // swl         $a1, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r5);
    // swr         $a1, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r5);
    // lwl         $v1, 0xF($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0XF, ctx->r6);
    // lwr         $v1, 0xC($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0XC, ctx->r6);
    // nop

    // swl         $v1, 0x47($sp)
    do_swl(rdram, 0X47, ctx->r29, ctx->r3);
    // swr         $v1, 0x44($sp)
    do_swr(rdram, 0X44, ctx->r29, ctx->r3);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x11B0
    ctx->r6 = ADD32(ctx->r2, 0X11B0);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // lwl         $a1, 0xB($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XB, ctx->r6);
    // lwr         $a1, 0x8($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X8, ctx->r6);
    // swl         $v1, 0x4B($sp)
    do_swl(rdram, 0X4B, ctx->r29, ctx->r3);
    // swr         $v1, 0x48($sp)
    do_swr(rdram, 0X48, ctx->r29, ctx->r3);
    // swl         $a0, 0x4F($sp)
    do_swl(rdram, 0X4F, ctx->r29, ctx->r4);
    // swr         $a0, 0x4C($sp)
    do_swr(rdram, 0X4C, ctx->r29, ctx->r4);
    // swl         $a1, 0x53($sp)
    do_swl(rdram, 0X53, ctx->r29, ctx->r5);
    // swr         $a1, 0x50($sp)
    do_swr(rdram, 0X50, ctx->r29, ctx->r5);
    // lwl         $v1, 0xF($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0XF, ctx->r6);
    // lwr         $v1, 0xC($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0XC, ctx->r6);
    // lwl         $a0, 0x13($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X13, ctx->r6);
    // lwr         $a0, 0x10($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X10, ctx->r6);
    // lwl         $a1, 0x17($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X17, ctx->r6);
    // lwr         $a1, 0x14($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X14, ctx->r6);
    // swl         $v1, 0x57($sp)
    do_swl(rdram, 0X57, ctx->r29, ctx->r3);
    // swr         $v1, 0x54($sp)
    do_swr(rdram, 0X54, ctx->r29, ctx->r3);
    // swl         $a0, 0x5B($sp)
    do_swl(rdram, 0X5B, ctx->r29, ctx->r4);
    // swr         $a0, 0x58($sp)
    do_swr(rdram, 0X58, ctx->r29, ctx->r4);
    // swl         $a1, 0x5F($sp)
    do_swl(rdram, 0X5F, ctx->r29, ctx->r5);
    // swr         $a1, 0x5C($sp)
    do_swr(rdram, 0X5C, ctx->r29, ctx->r5);
    // lwl         $v1, 0x1B($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X1B, ctx->r6);
    // lwr         $v1, 0x18($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X18, ctx->r6);
    // nop

    // swl         $v1, 0x63($sp)
    do_swl(rdram, 0X63, ctx->r29, ctx->r3);
    // swr         $v1, 0x60($sp)
    do_swr(rdram, 0X60, ctx->r29, ctx->r3);
    // jal         0x800174C4
    // lui         $fp, 0x1F80
    ctx->r30 = S32(0X1F80 << 16);
    ST_BeginDraw2D(rdram, ctx);
    goto after_0;
    // lui         $fp, 0x1F80
    ctx->r30 = S32(0X1F80 << 16);
    after_0:
    // lbu         $v1, 0x2E4($fp)
    ctx->r3 = MEM_BU(0X2E4, ctx->r30);
    // addiu       $v0, $zero, 0x48
    ctx->r2 = ADD32(0, 0X48);
    // sb          $v0, 0x300($fp)
    MEM_B(0X300, ctx->r30) = ctx->r2;
    // sb          $v0, 0x301($fp)
    MEM_B(0X301, ctx->r30) = ctx->r2;
    // sb          $v0, 0x302($fp)
    MEM_B(0X302, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x62
    ctx->r2 = ADD32(0, 0X62);
    // sb          $v0, 0x308($fp)
    MEM_B(0X308, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
    // sb          $v0, 0x309($fp)
    MEM_B(0X309, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sb          $v0, 0x30A($fp)
    MEM_B(0X30A, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sb          $v0, 0x30C($fp)
    MEM_B(0X30C, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sb          $v0, 0x30D($fp)
    MEM_B(0X30D, ctx->r30) = ctx->r2;
    // sb          $v0, 0x30E($fp)
    MEM_B(0X30E, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    // sb          $v0, 0x30F($fp)
    MEM_B(0X30F, ctx->r30) = ctx->r2;
    // sb          $v0, 0x30B($fp)
    MEM_B(0X30B, ctx->r30) = ctx->r2;
    // sltiu       $v1, $v1, 0x10
    ctx->r3 = ctx->r3 < 0X10 ? 1 : 0;
    // beq         $v1, $zero, L_8002BA48
    if (ctx->r3 == 0) {
        // sb          $v0, 0x303($fp)
        MEM_B(0X303, ctx->r30) = ctx->r2;
        goto L_8002BA48;
    }
    // sb          $v0, 0x303($fp)
    MEM_B(0X303, ctx->r30) = ctx->r2;
    // lbu         $v1, 0x2E4($fp)
    ctx->r3 = MEM_BU(0X2E4, ctx->r30);
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // j           L_8002BA54
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_8002BA54;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8002BA48:
    // lbu         $v0, 0x2E4($fp)
    ctx->r2 = MEM_BU(0X2E4, ctx->r30);
    // nop

    // addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
L_8002BA54:
    // sh          $v0, 0x360($fp)
    MEM_H(0X360, ctx->r30) = ctx->r2;
    // lhu         $v0, 0x2E2($fp)
    ctx->r2 = MEM_HU(0X2E2, ctx->r30);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_8002BAE8
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8002BAE8;
    }
    // nop

    // lbu         $v1, 0x360($fp)
    ctx->r3 = MEM_BU(0X360, ctx->r30);
    // sb          $zero, 0x32E($fp)
    MEM_B(0X32E, ctx->r30) = 0;
    // lbu         $v0, 0x30($sp)
    ctx->r2 = MEM_BU(0X30, ctx->r29);
    // lbu         $a0, 0x360($fp)
    ctx->r4 = MEM_BU(0X360, ctx->r30);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // sb          $v0, 0x30($sp)
    MEM_B(0X30, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x31($sp)
    ctx->r2 = MEM_BU(0X31, ctx->r29);
    // lbu         $v1, 0x360($fp)
    ctx->r3 = MEM_BU(0X360, ctx->r30);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // sb          $v0, 0x31($sp)
    MEM_B(0X31, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x34($sp)
    ctx->r2 = MEM_BU(0X34, ctx->r29);
    // lbu         $a0, 0x360($fp)
    ctx->r4 = MEM_BU(0X360, ctx->r30);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // sb          $v0, 0x34($sp)
    MEM_B(0X34, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x35($sp)
    ctx->r2 = MEM_BU(0X35, ctx->r29);
    // lbu         $v1, 0x360($fp)
    ctx->r3 = MEM_BU(0X360, ctx->r30);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // sb          $v0, 0x35($sp)
    MEM_B(0X35, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x360($fp)
    ctx->r2 = MEM_BU(0X360, ctx->r30);
    // addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // sb          $v1, 0x32C($fp)
    MEM_B(0X32C, ctx->r30) = ctx->r3;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // j           L_8002BAFC
    // sb          $v0, 0x32D($fp)
    MEM_B(0X32D, ctx->r30) = ctx->r2;
    goto L_8002BAFC;
    // sb          $v0, 0x32D($fp)
    MEM_B(0X32D, ctx->r30) = ctx->r2;
L_8002BAE8:
    // lwl         $v0, 0x30B($fp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X30B, ctx->r30);
    // lwr         $v0, 0x308($fp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X308, ctx->r30);
    // nop

    // swl         $v0, 0x32F($fp)
    do_swl(rdram, 0X32F, ctx->r30, ctx->r2);
    // swr         $v0, 0x32C($fp)
    do_swr(rdram, 0X32C, ctx->r30, ctx->r2);
L_8002BAFC:
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xD50
    ctx->r2 = ADD32(ctx->r2, 0XD50);
    // addiu       $s5, $v0, 0xC00
    ctx->r21 = ADD32(ctx->r2, 0XC00);
    // addiu       $s2, $zero, 0x50
    ctx->r18 = ADD32(0, 0X50);
    // addiu       $s1, $sp, 0x18
    ctx->r17 = ADD32(ctx->r29, 0X18);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s4, $v0, -0x2E5E
    ctx->r20 = ADD32(ctx->r2, -0X2E5E);
L_8002BB20:
    // lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(0X0, ctx->r20);
    // lh          $v1, 0x0($fp)
    ctx->r3 = MEM_HS(0X0, ctx->r30);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8002BB40
    if (ctx->r2 == 0) {
        // andi        $a2, $s2, 0xFFFF
        ctx->r6 = ctx->r18 & 0XFFFF;
        goto L_8002BB40;
    }
    // andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    // j           L_8002BB44
    // addiu       $a3, $fp, 0x30C
    ctx->r7 = ADD32(ctx->r30, 0X30C);
    goto L_8002BB44;
    // addiu       $a3, $fp, 0x30C
    ctx->r7 = ADD32(ctx->r30, 0X30C);
L_8002BB40:
    // addiu       $a3, $fp, 0x308
    ctx->r7 = ADD32(ctx->r30, 0X308);
L_8002BB44:
    // lhu         $a0, 0x1A2($s0)
    ctx->r4 = MEM_HU(0X1A2, ctx->r16);
    // lhu         $a1, 0x30($s1)
    ctx->r5 = MEM_HU(0X30, ctx->r17);
    // addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    // addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // jal         0x8002732C
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_8002732C(rdram, ctx);
    goto after_1;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_1:
    // addiu       $s2, $s2, 0x12
    ctx->r18 = ADD32(ctx->r18, 0X12);
    // addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // slti        $v0, $s3, 0x6
    ctx->r2 = SIGNED(ctx->r19) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_8002BB20
    if (ctx->r2 != 0) {
        // addiu       $s4, $s4, 0x2
        ctx->r20 = ADD32(ctx->r20, 0X2);
        goto L_8002BB20;
    }
    // addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xD50
    ctx->r2 = ADD32(ctx->r2, 0XD50);
    // addiu       $s5, $v0, 0xC00
    ctx->r21 = ADD32(ctx->r2, 0XC00);
    // addiu       $s2, $zero, 0x50
    ctx->r18 = ADD32(0, 0X50);
    // addiu       $s1, $sp, 0x54
    ctx->r17 = ADD32(ctx->r29, 0X54);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s4, $v0, -0x2E52
    ctx->r20 = ADD32(ctx->r2, -0X2E52);
L_8002BB9C:
    // lhu         $v0, 0x0($s4)
    ctx->r2 = MEM_HU(0X0, ctx->r20);
    // lh          $v1, 0x0($fp)
    ctx->r3 = MEM_HS(0X0, ctx->r30);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8002BBBC
    if (ctx->r2 == 0) {
        // andi        $a2, $s2, 0xFFFF
        ctx->r6 = ctx->r18 & 0XFFFF;
        goto L_8002BBBC;
    }
    // andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    // j           L_8002BBC0
    // addiu       $a3, $fp, 0x30C
    ctx->r7 = ADD32(ctx->r30, 0X30C);
    goto L_8002BBC0;
    // addiu       $a3, $fp, 0x30C
    ctx->r7 = ADD32(ctx->r30, 0X30C);
L_8002BBBC:
    // addiu       $a3, $fp, 0x308
    ctx->r7 = ADD32(ctx->r30, 0X308);
L_8002BBC0:
    // lhu         $a0, 0x1AE($s0)
    ctx->r4 = MEM_HU(0X1AE, ctx->r16);
    // lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(0X0, ctx->r17);
    // addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    // addiu       $a1, $a1, 0xA8
    ctx->r5 = ADD32(ctx->r5, 0XA8);
    // jal         0x8002732C
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_8002732C(rdram, ctx);
    goto after_2;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_2:
    // addiu       $s2, $s2, 0x12
    ctx->r18 = ADD32(ctx->r18, 0X12);
    // addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // slti        $v0, $s3, 0x6
    ctx->r2 = SIGNED(ctx->r19) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_8002BB9C
    if (ctx->r2 != 0) {
        // addiu       $s4, $s4, 0x2
        ctx->r20 = ADD32(ctx->r20, 0X2);
        goto L_8002BB9C;
    }
    // addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // addiu       $s0, $zero, 0x1FA
    ctx->r16 = ADD32(0, 0X1FA);
    // addiu       $v0, $zero, 0x180
    ctx->r2 = ADD32(0, 0X180);
    // sh          $v0, 0x35A($fp)
    MEM_H(0X35A, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x35C($fp)
    MEM_H(0X35C, ctx->r30) = ctx->r2;
    // slti        $v0, $s3, 0x6
    ctx->r2 = SIGNED(ctx->r19) < 0X6 ? 1 : 0;
L_8002BC10:
    // bne         $v0, $zero, L_8002BC1C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x8A
        ctx->r2 = ADD32(0, 0X8A);
        goto L_8002BC1C;
    }
    // addiu       $v0, $zero, 0x8A
    ctx->r2 = ADD32(0, 0X8A);
    // addiu       $v0, $zero, 0x112
    ctx->r2 = ADD32(0, 0X112);
L_8002BC1C:
    // sh          $v0, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r2;
    // lui         $v0, 0x2AAA
    ctx->r2 = S32(0X2AAA << 16);
    // ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // mult        $s3, $v0
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $s3, 31
    ctx->r2 = S32(ctx->r19) >> 31;
    // addu        $a0, $fp, $s3
    ctx->r4 = ADD32(ctx->r30, ctx->r19);
    // mfhi        $t0
    ctx->r8 = hi;
    // subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // subu        $v1, $s3, $v1
    ctx->r3 = SUB32(ctx->r19, ctx->r3);
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $v0, $v0, 0x4F
    ctx->r2 = ADD32(ctx->r2, 0X4F);
    // sh          $v0, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r2;
    // lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(0X2, ctx->r4);
    // nop

    // sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_8002BCA0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
        goto L_8002BCA0;
    }
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(0X2, ctx->r4);
    // addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // sh          $v1, 0x340($fp)
    MEM_H(0X340, ctx->r30) = ctx->r3;
    // lhu         $v1, 0x33C($fp)
    ctx->r3 = MEM_HU(0X33C, ctx->r30);
    // sh          $s0, 0x35E($fp)
    MEM_H(0X35E, ctx->r30) = ctx->r16;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addiu       $v0, $v0, 0x220
    ctx->r2 = ADD32(ctx->r2, 0X220);
    // addiu       $v1, $v1, -0x8
    ctx->r3 = ADD32(ctx->r3, -0X8);
    // sh          $v0, 0x358($fp)
    MEM_H(0X358, ctx->r30) = ctx->r2;
    // j           L_8002BCE0
    // sh          $v1, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r3;
    goto L_8002BCE0;
    // sh          $v1, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r3;
L_8002BCA0:
    // lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(0X2, ctx->r4);
    // sh          $v0, 0x340($fp)
    MEM_H(0X340, ctx->r30) = ctx->r2;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addiu       $v1, $v1, 0x240
    ctx->r3 = ADD32(ctx->r3, 0X240);
    // sh          $v1, 0x358($fp)
    MEM_H(0X358, ctx->r30) = ctx->r3;
    // lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(0X2, ctx->r4);
    // nop

    // sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8002BCDC
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1FE
        ctx->r2 = ADD32(0, 0X1FE);
        goto L_8002BCDC;
    }
    // addiu       $v0, $zero, 0x1FE
    ctx->r2 = ADD32(0, 0X1FE);
    // lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(0X2, ctx->r4);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // j           L_8002BCE0
    // sh          $v0, 0x35E($fp)
    MEM_H(0X35E, ctx->r30) = ctx->r2;
    goto L_8002BCE0;
    // sh          $v0, 0x35E($fp)
    MEM_H(0X35E, ctx->r30) = ctx->r2;
L_8002BCDC:
    // sh          $s0, 0x35E($fp)
    MEM_H(0X35E, ctx->r30) = ctx->r16;
L_8002BCE0:
    // lbu         $v0, 0x360($fp)
    ctx->r2 = MEM_BU(0X360, ctx->r30);
    // lhu         $v1, 0x2E0($fp)
    ctx->r3 = MEM_HU(0X2E0, ctx->r30);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sb          $v0, 0x33A($fp)
    MEM_B(0X33A, ctx->r30) = ctx->r2;
    // sb          $v0, 0x339($fp)
    MEM_B(0X339, ctx->r30) = ctx->r2;
    // bne         $s3, $v1, L_8002BD34
    if (ctx->r19 != ctx->r3) {
        // sb          $v0, 0x338($fp)
        MEM_B(0X338, ctx->r30) = ctx->r2;
        goto L_8002BD34;
    }
    // sb          $v0, 0x338($fp)
    MEM_B(0X338, ctx->r30) = ctx->r2;
    // lhu         $v0, 0x2E2($fp)
    ctx->r2 = MEM_HU(0X2E2, ctx->r30);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_8002BD34
    if (ctx->r2 != ctx->r3) {
        // addiu       $a0, $fp, 0x33C
        ctx->r4 = ADD32(ctx->r30, 0X33C);
        goto L_8002BD34;
    }
    // addiu       $a0, $fp, 0x33C
    ctx->r4 = ADD32(ctx->r30, 0X33C);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // addiu       $a1, $fp, 0x358
    ctx->r5 = ADD32(ctx->r30, 0X358);
    // addiu       $a2, $fp, 0x35C
    ctx->r6 = ADD32(ctx->r30, 0X35C);
    // j           L_8002BD48
    // addiu       $a3, $fp, 0x338
    ctx->r7 = ADD32(ctx->r30, 0X338);
    goto L_8002BD48;
    // addiu       $a3, $fp, 0x338
    ctx->r7 = ADD32(ctx->r30, 0X338);
L_8002BD34:
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // addiu       $a0, $fp, 0x33C
    ctx->r4 = ADD32(ctx->r30, 0X33C);
    // addiu       $a1, $fp, 0x358
    ctx->r5 = ADD32(ctx->r30, 0X358);
    // addiu       $a2, $fp, 0x35C
    ctx->r6 = ADD32(ctx->r30, 0X35C);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8002BD48:
    // jal         0x80028364
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    sub_80028364(rdram, ctx);
    goto after_3;
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    after_3:
    // slti        $v0, $s3, 0xC
    ctx->r2 = SIGNED(ctx->r19) < 0XC ? 1 : 0;
    // bne         $v0, $zero, L_8002BC10
    if (ctx->r2 != 0) {
        // slti        $v0, $s3, 0x6
        ctx->r2 = SIGNED(ctx->r19) < 0X6 ? 1 : 0;
        goto L_8002BC10;
    }
    // slti        $v0, $s3, 0x6
    ctx->r2 = SIGNED(ctx->r19) < 0X6 ? 1 : 0;
    // addiu       $s7, $fp, 0x33C
    ctx->r23 = ADD32(ctx->r30, 0X33C);
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // addiu       $s6, $fp, 0x358
    ctx->r22 = ADD32(ctx->r30, 0X358);
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // addiu       $s5, $fp, 0x35C
    ctx->r21 = ADD32(ctx->r30, 0X35C);
    // addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x240
    ctx->r2 = ADD32(0, 0X240);
    // sh          $v0, 0x358($fp)
    MEM_H(0X358, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x1B0
    ctx->r2 = ADD32(0, 0X1B0);
    // addiu       $s4, $zero, 0x220
    ctx->r20 = ADD32(0, 0X220);
    // addiu       $s3, $zero, 0x1FF
    ctx->r19 = ADD32(0, 0X1FF);
    // sh          $v0, 0x35A($fp)
    MEM_H(0X35A, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // addiu       $s2, $zero, 0x2C
    ctx->r18 = ADD32(0, 0X2C);
    // sh          $v0, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
    // addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // sh          $s4, 0x35C($fp)
    MEM_H(0X35C, ctx->r30) = ctx->r20;
    // sh          $s3, 0x35E($fp)
    MEM_H(0X35E, ctx->r30) = ctx->r19;
    // sh          $s2, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r18;
    // sh          $v0, 0x340($fp)
    MEM_H(0X340, ctx->r30) = ctx->r2;
    // sh          $s1, 0x342($fp)
    MEM_H(0X342, ctx->r30) = ctx->r17;
    // jal         0x80028364
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80028364(rdram, ctx);
    goto after_4;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_4:
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x24E
    ctx->r2 = ADD32(0, 0X24E);
    // sh          $v0, 0x358($fp)
    MEM_H(0X358, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x1E0
    ctx->r2 = ADD32(0, 0X1E0);
    // sh          $v0, 0x35A($fp)
    MEM_H(0X35A, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sh          $v0, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // sh          $s4, 0x35C($fp)
    MEM_H(0X35C, ctx->r30) = ctx->r20;
    // sh          $s3, 0x35E($fp)
    MEM_H(0X35E, ctx->r30) = ctx->r19;
    // sh          $s2, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r18;
    // sh          $v0, 0x340($fp)
    MEM_H(0X340, ctx->r30) = ctx->r2;
    // sh          $s1, 0x342($fp)
    MEM_H(0X342, ctx->r30) = ctx->r17;
    // jal         0x80028364
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80028364(rdram, ctx);
    goto after_5;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_5:
    // addiu       $a2, $zero, 0xCC
    ctx->r6 = ADD32(0, 0XCC);
    // addiu       $s2, $fp, 0x308
    ctx->r18 = ADD32(ctx->r30, 0X308);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // addiu       $s5, $zero, 0x54
    ctx->r21 = ADD32(0, 0X54);
    // addiu       $s4, $zero, 0x5E
    ctx->r20 = ADD32(0, 0X5E);
    // lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // addiu       $s0, $s0, 0xD50
    ctx->r16 = ADD32(ctx->r16, 0XD50);
    // addiu       $s1, $s0, 0xC00
    ctx->r17 = ADD32(ctx->r16, 0XC00);
    // lhu         $a0, 0x1BA($s0)
    ctx->r4 = MEM_HU(0X1BA, ctx->r16);
    // lhu         $a1, 0x60($sp)
    ctx->r5 = MEM_HU(0X60, ctx->r29);
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    // jal         0x8002732C
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_8002732C(rdram, ctx);
    goto after_6;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_6:
    // addiu       $a2, $zero, 0xCC
    ctx->r6 = ADD32(0, 0XCC);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // lhu         $a0, 0x1BC($s0)
    ctx->r4 = MEM_HU(0X1BC, ctx->r16);
    // lhu         $a1, 0x62($sp)
    ctx->r5 = MEM_HU(0X62, ctx->r29);
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // addiu       $a1, $a1, 0x98
    ctx->r5 = ADD32(ctx->r5, 0X98);
    // jal         0x8002732C
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_8002732C(rdram, ctx);
    goto after_7;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_7:
L_8002BE68:
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // bne         $s3, $v0, L_8002BEA0
    if (ctx->r19 != ctx->r2) {
        // addiu       $v0, $zero, 0xB8
        ctx->r2 = ADD32(0, 0XB8);
        goto L_8002BEA0;
    }
    // addiu       $v0, $zero, 0xB8
    ctx->r2 = ADD32(0, 0XB8);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xFA
    ctx->r2 = ADD32(0, 0XFA);
    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xA8
    ctx->r2 = ADD32(0, 0XA8);
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x10A
    ctx->r2 = ADD32(0, 0X10A);
    // sh          $s5, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r21;
    // sh          $s5, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r21;
    // sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // sh          $s4, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r20;
    // sh          $s4, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r20;
L_8002BEA0:
    // lhu         $v0, 0x2E0($fp)
    ctx->r2 = MEM_HU(0X2E0, ctx->r30);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $s3, $v0, L_8002BEC0
    if (ctx->r19 != ctx->r2) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8002BEC0;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // j           L_8002BEC4
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    goto L_8002BEC4;
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
L_8002BEC0:
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
L_8002BEC4:
    // jal         0x80028C2C
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sub_80028C2C(rdram, ctx);
    goto after_8;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(0X1A, ctx->r29);
    // lhu         $v1, 0x1E($sp)
    ctx->r3 = MEM_HU(0X1E, ctx->r29);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x22($sp)
    ctx->r2 = MEM_HU(0X22, ctx->r29);
    // addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
    // lhu         $v1, 0x26($sp)
    ctx->r3 = MEM_HU(0X26, ctx->r29);
    // addiu       $v0, $v0, 0x12
    ctx->r2 = ADD32(ctx->r2, 0X12);
    // addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // slti        $v0, $s3, 0xC
    ctx->r2 = SIGNED(ctx->r19) < 0XC ? 1 : 0;
    // bne         $v0, $zero, L_8002BE68
    if (ctx->r2 != 0) {
        // sh          $v1, 0x26($sp)
        MEM_H(0X26, ctx->r29) = ctx->r3;
        goto L_8002BE68;
    }
    // sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x82
    ctx->r2 = ADD32(0, 0X82);
    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xD0
    ctx->r2 = ADD32(0, 0XD0);
    // sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x92
    ctx->r2 = ADD32(0, 0X92);
    // sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // lhu         $v1, 0x2E0($fp)
    ctx->r3 = MEM_HU(0X2E0, ctx->r30);
    // addiu       $v0, $zero, 0xDA
    ctx->r2 = ADD32(0, 0XDA);
    // sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // bne         $v1, $v0, L_8002BF60
    if (ctx->r3 != ctx->r2) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8002BF60;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // j           L_8002BF64
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    goto L_8002BF64;
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
L_8002BF60:
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
L_8002BF64:
    // jal         0x80028C2C
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sub_80028C2C(rdram, ctx);
    goto after_9;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // jal         0x800286A8
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    sub_800286A8(rdram, ctx);
    goto after_10;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_10:
    // addiu       $v0, $zero, 0xA8
    ctx->r2 = ADD32(0, 0XA8);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xEA
    ctx->r2 = ADD32(0, 0XEA);
    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xD0
    ctx->r2 = ADD32(0, 0XD0);
    // sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x98
    ctx->r2 = ADD32(0, 0X98);
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xFA
    ctx->r2 = ADD32(0, 0XFA);
    // sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // lhu         $v1, 0x2E0($fp)
    ctx->r3 = MEM_HU(0X2E0, ctx->r30);
    // addiu       $v0, $zero, 0xDA
    ctx->r2 = ADD32(0, 0XDA);
    // sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // bne         $v1, $v0, L_8002BFD4
    if (ctx->r3 != ctx->r2) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_8002BFD4;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // j           L_8002BFD8
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    goto L_8002BFD8;
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
L_8002BFD4:
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
L_8002BFD8:
    // jal         0x80028C2C
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sub_80028C2C(rdram, ctx);
    goto after_11;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // jal         0x800286A8
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    sub_800286A8(rdram, ctx);
    goto after_12;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_12:
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
    goto after_13;
    // addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    after_13:
    // jal         0x800175A4
    // nop

    sub_800175A4(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // jal         0x8002948C
    // nop

    sub_8002948C(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // jal         0x80017634
    // nop

    sub_80017634(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(0X8C, ctx->r29);
    // lw          $fp, 0x88($sp)
    ctx->r30 = MEM_W(0X88, ctx->r29);
    // lw          $s7, 0x84($sp)
    ctx->r23 = MEM_W(0X84, ctx->r29);
    // lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(0X80, ctx->r29);
    // lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(0X7C, ctx->r29);
    // lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(0X78, ctx->r29);
    // lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(0X74, ctx->r29);
    // lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(0X70, ctx->r29);
    // lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(0X6C, ctx->r29);
    // lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(0X68, ctx->r29);
    // addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // jr          $ra
    // nop

    return;
    // nop

;}
