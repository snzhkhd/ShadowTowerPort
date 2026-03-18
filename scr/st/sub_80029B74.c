#include "recomp.h"
#include "disable_warnings.h"

void sub_80029B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // sw          $ra, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r31;
    // sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, 0x10D0
    ctx->r6 = ADD32(ctx->r2, 0X10D0);
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
    // addiu       $a2, $v0, 0x10E0
    ctx->r6 = ADD32(ctx->r2, 0X10E0);
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
    // jal         0x800174C4
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    sub_800174C4(rdram, ctx);
    goto after_0;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    after_0:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xD50
    ctx->r2 = ADD32(ctx->r2, 0XD50);
    // addiu       $s2, $v0, 0xC00
    ctx->r18 = ADD32(ctx->r2, 0XC00);
    // addiu       $s1, $zero, 0x30
    ctx->r17 = ADD32(0, 0X30);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // lui         $s5, 0x1F80
    ctx->r21 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x48
    ctx->r2 = ADD32(0, 0X48);
    // sb          $v0, 0x300($s5)
    MEM_B(0X300, ctx->r21) = ctx->r2;
    // sb          $v0, 0x301($s5)
    MEM_B(0X301, ctx->r21) = ctx->r2;
    // sb          $v0, 0x302($s5)
    MEM_B(0X302, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x62
    ctx->r2 = ADD32(0, 0X62);
    // sb          $v0, 0x308($s5)
    MEM_B(0X308, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
    // sb          $v0, 0x309($s5)
    MEM_B(0X309, ctx->r21) = ctx->r2;
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // sb          $v0, 0x30A($s5)
    MEM_B(0X30A, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    // sb          $v0, 0x30B($s5)
    MEM_B(0X30B, ctx->r21) = ctx->r2;
    // sb          $v0, 0x303($s5)
    MEM_B(0X303, ctx->r21) = ctx->r2;
    // addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
L_80029D1C:
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
    // addiu       $a3, $s5, 0x300
    ctx->r7 = ADD32(ctx->r21, 0X300);
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // jal         0x8002732C
    // addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    sub_8002732C(rdram, ctx);
    goto after_1;
    // addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    after_1:
    // slti        $v0, $s4, 0xB
    ctx->r2 = SIGNED(ctx->r20) < 0XB ? 1 : 0;
    // bne         $v0, $zero, L_80029D1C
    if (ctx->r2 != 0) {
        // addiu       $a1, $zero, 0x18
        ctx->r5 = ADD32(0, 0X18);
        goto L_80029D1C;
    }
    // addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v1, -0x70AC($v0)
    ctx->r3 = MEM_W(-0X70AC, ctx->r2);
    // nop

    // andi        $v0, $v1, 0x7
    ctx->r2 = ctx->r3 & 0X7;
    // beq         $v0, $zero, L_80029D78
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x6A
        ctx->r5 = ADD32(0, 0X6A);
        goto L_80029D78;
    }
    // addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x28($a0)
    ctx->r2 = MEM_HU(0X28, ctx->r4);
    // j           L_80029E18
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
    goto L_80029E18;
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
L_80029D78:
    // andi        $v0, $v1, 0x18
    ctx->r2 = ctx->r3 & 0X18;
    // beq         $v0, $zero, L_80029D9C
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x5D
        ctx->r5 = ADD32(0, 0X5D);
        goto L_80029D9C;
    }
    // addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x2A($a0)
    ctx->r2 = MEM_HU(0X2A, ctx->r4);
    // j           L_80029E18
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
    goto L_80029E18;
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
L_80029D9C:
    // andi        $v0, $v1, 0x60
    ctx->r2 = ctx->r3 & 0X60;
    // beq         $v0, $zero, L_80029DC0
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x77
        ctx->r5 = ADD32(0, 0X77);
        goto L_80029DC0;
    }
    // addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    // addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x2C($a0)
    ctx->r2 = MEM_HU(0X2C, ctx->r4);
    // j           L_80029E18
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
    goto L_80029E18;
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
L_80029DC0:
    // andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // beq         $v0, $zero, L_80029DE0
    if (ctx->r2 == 0) {
        // addiu       $a2, $zero, 0x70
        ctx->r6 = ADD32(0, 0X70);
        goto L_80029DE0;
    }
    // addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x2E($a0)
    ctx->r2 = MEM_HU(0X2E, ctx->r4);
    // j           L_80029E18
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
    goto L_80029E18;
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
L_80029DE0:
    // andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // beq         $v0, $zero, L_80029E04
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x6A
        ctx->r5 = ADD32(0, 0X6A);
        goto L_80029E04;
    }
    // addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x30($a0)
    ctx->r2 = MEM_HU(0X30, ctx->r4);
    // j           L_80029E18
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
    goto L_80029E18;
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
L_80029E04:
    // addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x26($a0)
    ctx->r2 = MEM_HU(0X26, ctx->r4);
L_80029E18:
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_2;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_2:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, 0x58($a1)
    ctx->r3 = MEM_HU(0X58, ctx->r5);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_80029EB0
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_80029EB0;
    }
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // addiu       $a0, $a0, 0x76F8
    ctx->r4 = ADD32(ctx->r4, 0X76F8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v0, 0x13A($v1)
    ctx->r2 = MEM_BU(0X13A, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0x9
    ctx->r2 = ctx->r2 < 0X9 ? 1 : 0;
    // bne         $v0, $zero, L_80029EB0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_80029EB0;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // lbu         $t0, 0x13A($v1)
    ctx->r8 = MEM_BU(0X13A, ctx->r3);
    // nop

    // addiu       $v1, $t0, -0x9
    ctx->r3 = ADD32(ctx->r8, -0X9);
    // bne         $v1, $v0, L_80029E84
    if (ctx->r3 != ctx->r2) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80029E84;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
L_80029E84:
    // addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    // subu        $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(0X22, ctx->r2);
    // j           L_80029EC8
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
    goto L_80029EC8;
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
L_80029EB0:
    // addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    // addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x32($a0)
    ctx->r2 = MEM_HU(0X32, ctx->r4);
L_80029EC8:
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_3;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_3:
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xD50
    ctx->r2 = ADD32(ctx->r2, 0XD50);
    // addiu       $s2, $v0, 0xC00
    ctx->r18 = ADD32(ctx->r2, 0XC00);
    // addiu       $s1, $zero, 0x5A
    ctx->r17 = ADD32(0, 0X5A);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
L_80029EF0:
    // addiu       $a3, $s5, 0x308
    ctx->r7 = ADD32(ctx->r21, 0X308);
    // addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(0X16, ctx->r16);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20) << 1;
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // lhu         $a1, 0x18($v0)
    ctx->r5 = MEM_HU(0X18, ctx->r2);
    // addu        $a0, $a0, $s2
    ctx->r4 = ADD32(ctx->r4, ctx->r18);
    // addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    // jal         0x8002732C
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_8002732C(rdram, ctx);
    goto after_4;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_4:
    // slti        $v0, $s4, 0x8
    ctx->r2 = SIGNED(ctx->r20) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_80029EF0
    if (ctx->r2 != 0) {
        // andi        $a2, $s1, 0xFFFF
        ctx->r6 = ctx->r17 & 0XFFFF;
        goto L_80029EF0;
    }
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
    // addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // addiu       $s0, $s5, 0x300
    ctx->r16 = ADD32(ctx->r21, 0X300);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // lui         $s3, 0x801A
    ctx->r19 = S32(0X801A << 16);
    // addiu       $s2, $s3, -0x70D8
    ctx->r18 = ADD32(ctx->r19, -0X70D8);
    // lhu         $a0, 0x2($s2)
    ctx->r4 = MEM_HU(0X2, ctx->r18);
    // lui         $s1, 0x400
    ctx->r17 = S32(0X400 << 16);
    // jal         0x800276BC
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_800276BC(rdram, ctx);
    goto after_5;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_5:
    // addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // jal         0x80026ECC
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sub_80026ECC(rdram, ctx);
    goto after_6;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_6:
    // addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // lhu         $a0, -0x70D8($s3)
    ctx->r4 = MEM_HU(-0X70D8, ctx->r19);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // jal         0x800276BC
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_800276BC(rdram, ctx);
    goto after_7;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_7:
    // addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // lhu         $a0, 0x6($s2)
    ctx->r4 = MEM_HU(0X6, ctx->r18);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // jal         0x800276BC
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_800276BC(rdram, ctx);
    goto after_8;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_8:
    // addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // jal         0x80026ECC
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sub_80026ECC(rdram, ctx);
    goto after_9;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_9:
    // addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // lhu         $a0, 0x4($s2)
    ctx->r4 = MEM_HU(0X4, ctx->r18);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // jal         0x800276BC
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_800276BC(rdram, ctx);
    goto after_10;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_10:
    // addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // lhu         $a0, 0x8($s2)
    ctx->r4 = MEM_HU(0X8, ctx->r18);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // jal         0x800276BC
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_800276BC(rdram, ctx);
    goto after_11;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_11:
    // addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // jal         0x80026ECC
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sub_80026ECC(rdram, ctx);
    goto after_12;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_12:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // ori         $a0, $a0, 0x1339
    ctx->r4 = ctx->r4 | 0X1339;
    // addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // jal         0x800276BC
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sub_800276BC(rdram, ctx);
    goto after_13;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_13:
    // addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // lbu         $a0, 0x769A($v0)
    ctx->r4 = MEM_BU(0X769A, ctx->r2);
    // lui         $s1, 0x300
    ctx->r17 = S32(0X300 << 16);
    // andi        $a0, $a0, 0x7F
    ctx->r4 = ctx->r4 & 0X7F;
    // jal         0x800276BC
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_800276BC(rdram, ctx);
    goto after_14;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_14:
    // addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // lhu         $a0, 0x10($s2)
    ctx->r4 = MEM_HU(0X10, ctx->r18);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // jal         0x800276BC
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_800276BC(rdram, ctx);
    goto after_15;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_15:
    // addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // lhu         $a0, 0xE($s2)
    ctx->r4 = MEM_HU(0XE, ctx->r18);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // jal         0x800276BC
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_800276BC(rdram, ctx);
    goto after_16;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_16:
    // addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // lhu         $a0, 0xBA($s2)
    ctx->r4 = MEM_HU(0XBA, ctx->r18);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // jal         0x800276BC
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_800276BC(rdram, ctx);
    goto after_17;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_17:
    // addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // lhu         $a0, 0xBC($s2)
    ctx->r4 = MEM_HU(0XBC, ctx->r18);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // jal         0x800276BC
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_800276BC(rdram, ctx);
    goto after_18;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_18:
    // addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // lhu         $a0, 0xBE($s2)
    ctx->r4 = MEM_HU(0XBE, ctx->r18);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // jal         0x800276BC
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_800276BC(rdram, ctx);
    goto after_19;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_19:
    // ori         $a0, $s5, 0x33C
    ctx->r4 = ctx->r21 | 0X33C;
    // ori         $a1, $s5, 0x358
    ctx->r5 = ctx->r21 | 0X358;
    // ori         $a2, $s5, 0x35C
    ctx->r6 = ctx->r21 | 0X35C;
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // addiu       $v0, $zero, 0x26E
    ctx->r2 = ADD32(0, 0X26E);
    // sh          $v0, 0x358($s5)
    MEM_H(0X358, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x1A0
    ctx->r2 = ADD32(0, 0X1A0);
    // sh          $v0, 0x35A($s5)
    MEM_H(0X35A, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x35C($s5)
    MEM_H(0X35C, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x1FF
    ctx->r2 = ADD32(0, 0X1FF);
    // sh          $v0, 0x35E($s5)
    MEM_H(0X35E, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0xC4
    ctx->r2 = ADD32(0, 0XC4);
    // sh          $v0, 0x33C($s5)
    MEM_H(0X33C, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x36
    ctx->r2 = ADD32(0, 0X36);
    // sh          $v0, 0x33E($s5)
    MEM_H(0X33E, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x48
    ctx->r2 = ADD32(0, 0X48);
    // sh          $v0, 0x340($s5)
    MEM_H(0X340, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // sh          $v0, 0x342($s5)
    MEM_H(0X342, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_20;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_20:
L_8002A104:
    // lhu         $v0, 0x2DE($s5)
    ctx->r2 = MEM_HU(0X2DE, ctx->r21);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $s4, $v0, L_8002A124
    if (ctx->r20 != ctx->r2) {
        // addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
        goto L_8002A124;
    }
    // addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // j           L_8002A128
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    goto L_8002A128;
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
L_8002A124:
    // addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
L_8002A128:
    // jal         0x80028C2C
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sub_80028C2C(rdram, ctx);
    goto after_21;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_21:
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // lhu         $v0, 0x2A($sp)
    ctx->r2 = MEM_HU(0X2A, ctx->r29);
    // lhu         $v1, 0x2E($sp)
    ctx->r3 = MEM_HU(0X2E, ctx->r29);
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x32($sp)
    ctx->r2 = MEM_HU(0X32, ctx->r29);
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    // lhu         $v1, 0x36($sp)
    ctx->r3 = MEM_HU(0X36, ctx->r29);
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
    // slti        $v0, $s4, 0x8
    ctx->r2 = SIGNED(ctx->r20) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_8002A104
    if (ctx->r2 != 0) {
        // sh          $v1, 0x36($sp)
        MEM_H(0X36, ctx->r29) = ctx->r3;
        goto L_8002A104;
    }
    // sh          $v1, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r3;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // jal         0x800286A8
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    sub_800286A8(rdram, ctx);
    goto after_22;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_22:
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
    goto after_23;
    // addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    after_23:
    // jal         0x800175A4
    // nop

    sub_800175A4(rdram, ctx);
    goto after_24;
    // nop

    after_24:
    // jal         0x8002948C
    // nop

    sub_8002948C(rdram, ctx);
    goto after_25;
    // nop

    after_25:
    // jal         0x80017634
    // nop

    sub_80017634(rdram, ctx);
    goto after_26;
    // nop

    after_26:
    // lw          $ra, 0x70($sp)
    ctx->r31 = MEM_W(0X70, ctx->r29);
    // lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(0X6C, ctx->r29);
    // lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(0X68, ctx->r29);
    // lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(0X64, ctx->r29);
    // lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(0X60, ctx->r29);
    // lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(0X5C, ctx->r29);
    // lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(0X58, ctx->r29);
    // addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // jr          $ra
    // nop

    return;
    // nop

;}
