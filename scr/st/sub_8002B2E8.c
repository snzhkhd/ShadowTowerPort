#include "recomp.h"
#include "disable_warnings.h"

void sub_8002B2E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // sw          $ra, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r31;
    // sw          $s6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r22;
    // sw          $s5, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r20;
    // sw          $s3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r19;
    // sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
    // sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
    // jal         0x80078AB4
    // sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    memset_recomp(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    after_0:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F58
    ctx->r6 = ADD32(ctx->r2, 0X7F58);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r3);
    // swr         $v1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F5C
    ctx->r6 = ADD32(ctx->r2, 0X7F5C);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r3);
    // swr         $v1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F2C
    ctx->r6 = ADD32(ctx->r2, 0X7F2C);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r3);
    // swr         $v1, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r3);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
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
    // nop

    // swl         $v1, 0x57($sp)
    do_swl(rdram, 0X57, ctx->r29, ctx->r3);
    // swr         $v1, 0x54($sp)
    do_swr(rdram, 0X54, ctx->r29, ctx->r3);
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
    // swl         $v1, 0x5B($sp)
    do_swl(rdram, 0X5B, ctx->r29, ctx->r3);
    // swr         $v1, 0x58($sp)
    do_swr(rdram, 0X58, ctx->r29, ctx->r3);
    // swl         $a0, 0x5F($sp)
    do_swl(rdram, 0X5F, ctx->r29, ctx->r4);
    // swr         $a0, 0x5C($sp)
    do_swr(rdram, 0X5C, ctx->r29, ctx->r4);
    // swl         $a1, 0x63($sp)
    do_swl(rdram, 0X63, ctx->r29, ctx->r5);
    // swr         $a1, 0x60($sp)
    do_swr(rdram, 0X60, ctx->r29, ctx->r5);
    // lwl         $v1, 0xF($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0XF, ctx->r6);
    // lwr         $v1, 0xC($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0XC, ctx->r6);
    // nop

    // swl         $v1, 0x67($sp)
    do_swl(rdram, 0X67, ctx->r29, ctx->r3);
    // swr         $v1, 0x64($sp)
    do_swr(rdram, 0X64, ctx->r29, ctx->r3);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x11A4
    ctx->r6 = ADD32(ctx->r2, 0X11A4);
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
    // swl         $v1, 0x6B($sp)
    do_swl(rdram, 0X6B, ctx->r29, ctx->r3);
    // swr         $v1, 0x68($sp)
    do_swr(rdram, 0X68, ctx->r29, ctx->r3);
    // swl         $a0, 0x6F($sp)
    do_swl(rdram, 0X6F, ctx->r29, ctx->r4);
    // swr         $a0, 0x6C($sp)
    do_swr(rdram, 0X6C, ctx->r29, ctx->r4);
    // swl         $a1, 0x73($sp)
    do_swl(rdram, 0X73, ctx->r29, ctx->r5);
    // swr         $a1, 0x70($sp)
    do_swr(rdram, 0X70, ctx->r29, ctx->r5);
    // jal         0x800174C4
    // addiu       $s1, $zero, 0x50
    ctx->r17 = ADD32(0, 0X50);
    ST_BeginDraw2D(rdram, ctx);
    goto after_1;
    // addiu       $s1, $zero, 0x50
    ctx->r17 = ADD32(0, 0X50);
    after_1:
    // lui         $t0, 0x8208
    ctx->r8 = S32(0X8208 << 16);
    // ori         $t0, $t0, 0x2083
    ctx->r8 = ctx->r8 | 0X2083;
    // lui         $a0, 0x1F80
    ctx->r4 = S32(0X1F80 << 16);
    // ori         $a0, $a0, 0x33C
    ctx->r4 = ctx->r4 | 0X33C;
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // lui         $a2, 0x1F80
    ctx->r6 = S32(0X1F80 << 16);
    // ori         $a2, $a2, 0x35C
    ctx->r6 = ctx->r6 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x48
    ctx->r2 = ADD32(0, 0X48);
    // sb          $v0, 0x300($s2)
    MEM_B(0X300, ctx->r18) = ctx->r2;
    // sb          $v0, 0x301($s2)
    MEM_B(0X301, ctx->r18) = ctx->r2;
    // sb          $v0, 0x302($s2)
    MEM_B(0X302, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x62
    ctx->r2 = ADD32(0, 0X62);
    // sb          $v0, 0x308($s2)
    MEM_B(0X308, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
    // sb          $v0, 0x309($s2)
    MEM_B(0X309, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sb          $v0, 0x30A($s2)
    MEM_B(0X30A, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // sb          $v0, 0x30C($s2)
    MEM_B(0X30C, ctx->r18) = ctx->r2;
    // sb          $v0, 0x30D($s2)
    MEM_B(0X30D, ctx->r18) = ctx->r2;
    // sb          $v0, 0x30E($s2)
    MEM_B(0X30E, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    // sb          $v0, 0x30F($s2)
    MEM_B(0X30F, ctx->r18) = ctx->r2;
    // sb          $v0, 0x30B($s2)
    MEM_B(0X30B, ctx->r18) = ctx->r2;
    // sb          $v0, 0x303($s2)
    MEM_B(0X303, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
    // sh          $v0, 0x358($s2)
    MEM_H(0X358, ctx->r18) = ctx->r2;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v0, -0x2EDF($v0)
    ctx->r2 = MEM_BU(-0X2EDF, ctx->r2);
    // addiu       $s0, $zero, 0x1A0
    ctx->r16 = ADD32(0, 0X1A0);
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // mult        $v1, $t0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $s0, 0x35A($s2)
    MEM_H(0X35A, ctx->r18) = ctx->r16;
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x35C($s2)
    MEM_H(0X35C, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1FF
    ctx->r2 = ADD32(0, 0X1FF);
    // sh          $v0, 0x35E($s2)
    MEM_H(0X35E, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x53
    ctx->r2 = ADD32(0, 0X53);
    // sh          $v0, 0x33E($s2)
    MEM_H(0X33E, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sh          $v0, 0x340($s2)
    MEM_H(0X340, ctx->r18) = ctx->r2;
    // sh          $v0, 0x342($s2)
    MEM_H(0X342, ctx->r18) = ctx->r2;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // mfhi        $t1
    ctx->r9 = hi;
    // addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addiu       $v0, $v0, 0xB4
    ctx->r2 = ADD32(ctx->r2, 0XB4);
    // jal         0x80028364
    // sh          $v0, 0x33C($s2)
    MEM_H(0X33C, ctx->r18) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_2;
    // sh          $v0, 0x33C($s2)
    MEM_H(0X33C, ctx->r18) = ctx->r2;
    after_2:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // ori         $a0, $a0, 0x33C
    ctx->r4 = ctx->r4 | 0X33C;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // ori         $a2, $a2, 0x35C
    ctx->r6 = ctx->r6 | 0X35C;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // addiu       $v0, $zero, 0x240
    ctx->r2 = ADD32(0, 0X240);
    // sh          $v0, 0x358($s2)
    MEM_H(0X358, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0xB0
    ctx->r2 = ADD32(0, 0XB0);
    // sh          $v0, 0x33C($s2)
    MEM_H(0X33C, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x4E
    ctx->r2 = ADD32(0, 0X4E);
    // sh          $v0, 0x33E($s2)
    MEM_H(0X33E, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sh          $v0, 0x340($s2)
    MEM_H(0X340, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // sh          $v0, 0x342($s2)
    MEM_H(0X342, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $s0, 0x35A($s2)
    MEM_H(0X35A, ctx->r18) = ctx->r16;
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xD50
    ctx->r2 = ADD32(ctx->r2, 0XD50);
    // addiu       $s4, $v0, 0xC00
    ctx->r20 = ADD32(ctx->r2, 0XC00);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
L_8002B5EC:
    // addiu       $a3, $s2, 0x308
    ctx->r7 = ADD32(ctx->r18, 0X308);
    // addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // lhu         $a0, 0x192($s0)
    ctx->r4 = MEM_HU(0X192, ctx->r16);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) << 1;
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // lhu         $a1, 0x68($v0)
    ctx->r5 = MEM_HU(0X68, ctx->r2);
    // addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // jal         0x8002732C
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_8002732C(rdram, ctx);
    goto after_4;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_4:
    // slti        $v0, $s3, 0x6
    ctx->r2 = SIGNED(ctx->r19) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_8002B5EC
    if (ctx->r2 != 0) {
        // andi        $a2, $s1, 0xFFFF
        ctx->r6 = ctx->r17 & 0XFFFF;
        goto L_8002B5EC;
    }
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s6, $v0, -0x2EDE
    ctx->r22 = ADD32(ctx->r2, -0X2EDE);
    // addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $s4, $v0, 0xD50
    ctx->r20 = ADD32(ctx->r2, 0XD50);
    // addiu       $s5, $s4, 0xC00
    ctx->r21 = ADD32(ctx->r20, 0XC00);
    // addiu       $s1, $zero, 0x64
    ctx->r17 = ADD32(0, 0X64);
L_8002B644:
    // lbu         $v1, 0x0($s6)
    ctx->r3 = MEM_BU(0X0, ctx->r22);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8002B680
    if (ctx->r3 != ctx->r2) {
        // addiu       $a1, $zero, 0xC1
        ctx->r5 = ADD32(0, 0XC1);
        goto L_8002B680;
    }
    // addiu       $a1, $zero, 0xC1
    ctx->r5 = ADD32(0, 0XC1);
    // andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lhu         $a0, 0x19E($s4)
    ctx->r4 = MEM_HU(0X19E, ctx->r20);
    // addiu       $a3, $s2, 0x308
    ctx->r7 = ADD32(ctx->r18, 0X308);
    // jal         0x8002732C
    // addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    sub_8002732C(rdram, ctx);
    goto after_5;
    // addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    after_5:
    // addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lhu         $a0, 0x1A0($s4)
    ctx->r4 = MEM_HU(0X1A0, ctx->r20);
    // j           L_8002B6A8
    // addiu       $a3, $s2, 0x30C
    ctx->r7 = ADD32(ctx->r18, 0X30C);
    goto L_8002B6A8;
    // addiu       $a3, $s2, 0x30C
    ctx->r7 = ADD32(ctx->r18, 0X30C);
L_8002B680:
    // andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lhu         $a0, 0x19E($s4)
    ctx->r4 = MEM_HU(0X19E, ctx->r20);
    // addiu       $a3, $s2, 0x30C
    ctx->r7 = ADD32(ctx->r18, 0X30C);
    // jal         0x8002732C
    // addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    sub_8002732C(rdram, ctx);
    goto after_6;
    // addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    after_6:
    // addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lhu         $a0, 0x1A0($s4)
    ctx->r4 = MEM_HU(0X1A0, ctx->r20);
    // addiu       $a3, $s2, 0x308
    ctx->r7 = ADD32(ctx->r18, 0X308);
L_8002B6A8:
    // jal         0x8002732C
    // addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    sub_8002732C(rdram, ctx);
    goto after_7;
    // addu        $a0, $a0, $s5
    ctx->r4 = ADD32(ctx->r4, ctx->r21);
    after_7:
    // addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // slti        $v0, $s3, 0x5
    ctx->r2 = SIGNED(ctx->r19) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_8002B644
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
        goto L_8002B644;
    }
    // addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    // addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // addiu       $s0, $s2, 0x300
    ctx->r16 = ADD32(ctx->r18, 0X300);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v0, -0x2EDF($v0)
    ctx->r2 = MEM_BU(-0X2EDF, ctx->r2);
    // lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // jal         0x800276BC
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    sub_800276BC(rdram, ctx);
    goto after_8;
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    after_8:
    // addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // lhu         $v0, 0x2E0($s2)
    ctx->r2 = MEM_HU(0X2E0, ctx->r18);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v0, 0x1C0($v0)
    ctx->r2 = MEM_HU(0X1C0, ctx->r2);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_9;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_9:
    // ori         $a0, $s2, 0x33C
    ctx->r4 = ctx->r18 | 0X33C;
    // ori         $a1, $s2, 0x358
    ctx->r5 = ctx->r18 | 0X358;
    // ori         $a2, $s2, 0x35C
    ctx->r6 = ctx->r18 | 0X35C;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // addiu       $v0, $zero, 0x254
    ctx->r2 = ADD32(0, 0X254);
    // sh          $v0, 0x358($s2)
    MEM_H(0X358, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // sh          $v0, 0x35A($s2)
    MEM_H(0X35A, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x35C($s2)
    MEM_H(0X35C, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1FF
    ctx->r2 = ADD32(0, 0X1FF);
    // sh          $v0, 0x35E($s2)
    MEM_H(0X35E, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sh          $v0, 0x33C($s2)
    MEM_H(0X33C, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // sh          $v0, 0x33E($s2)
    MEM_H(0X33E, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // sh          $v0, 0x340($s2)
    MEM_H(0X340, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x342($s2)
    MEM_H(0X342, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_10;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_10:
L_8002B77C:
    // lhu         $v0, 0x2E0($s2)
    ctx->r2 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $s3, $v0, L_8002B79C
    if (ctx->r19 != ctx->r2) {
        // addiu       $a0, $sp, 0x38
        ctx->r4 = ADD32(ctx->r29, 0X38);
        goto L_8002B79C;
    }
    // addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // j           L_8002B7A0
    // addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    goto L_8002B7A0;
    // addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
L_8002B79C:
    // addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
L_8002B7A0:
    // jal         0x80028C2C
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sub_80028C2C(rdram, ctx);
    goto after_11;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // lhu         $v0, 0x3A($sp)
    ctx->r2 = MEM_HU(0X3A, ctx->r29);
    // lhu         $v1, 0x3E($sp)
    ctx->r3 = MEM_HU(0X3E, ctx->r29);
    // addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x42($sp)
    ctx->r2 = MEM_HU(0X42, ctx->r29);
    // addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // sh          $v1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r3;
    // lhu         $v1, 0x46($sp)
    ctx->r3 = MEM_HU(0X46, ctx->r29);
    // addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    // slti        $v0, $s3, 0x6
    ctx->r2 = SIGNED(ctx->r19) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_8002B77C
    if (ctx->r2 != 0) {
        // sh          $v1, 0x46($sp)
        MEM_H(0X46, ctx->r29) = ctx->r3;
        goto L_8002B77C;
    }
    // sh          $v1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r3;
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
    // lw          $ra, 0x94($sp)
    ctx->r31 = MEM_W(0X94, ctx->r29);
    // lw          $s6, 0x90($sp)
    ctx->r22 = MEM_W(0X90, ctx->r29);
    // lw          $s5, 0x8C($sp)
    ctx->r21 = MEM_W(0X8C, ctx->r29);
    // lw          $s4, 0x88($sp)
    ctx->r20 = MEM_W(0X88, ctx->r29);
    // lw          $s3, 0x84($sp)
    ctx->r19 = MEM_W(0X84, ctx->r29);
    // lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(0X80, ctx->r29);
    // lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(0X7C, ctx->r29);
    // lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(0X78, ctx->r29);
    // addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // jr          $ra
    // nop

    return;
    // nop

;}
