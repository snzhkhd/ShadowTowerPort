#include "recomp.h"
#include "disable_warnings.h"

void sub_80066240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1F6
    ctx->r2 = ADD32(0, 0X1F6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x38A0
    ctx->r6 = ADD32(ctx->r2, 0X38A0);
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
    // lwl         $a0, 0x13($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X13, ctx->r6);
    // lwr         $a0, 0x10($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X10, ctx->r6);
    // lwl         $a1, 0x17($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X17, ctx->r6);
    // lwr         $a1, 0x14($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X14, ctx->r6);
    // swl         $v1, 0x37($sp)
    do_swl(rdram, 0X37, ctx->r29, ctx->r3);
    // swr         $v1, 0x34($sp)
    do_swr(rdram, 0X34, ctx->r29, ctx->r3);
    // swl         $a0, 0x3B($sp)
    do_swl(rdram, 0X3B, ctx->r29, ctx->r4);
    // swr         $a0, 0x38($sp)
    do_swr(rdram, 0X38, ctx->r29, ctx->r4);
    // swl         $a1, 0x3F($sp)
    do_swl(rdram, 0X3F, ctx->r29, ctx->r5);
    // swr         $a1, 0x3C($sp)
    do_swr(rdram, 0X3C, ctx->r29, ctx->r5);
    // lb          $v1, 0x18($a2)
    ctx->r3 = MEM_BS(0X18, ctx->r6);
    // lb          $a0, 0x19($a2)
    ctx->r4 = MEM_BS(0X19, ctx->r6);
    // sb          $v1, 0x40($sp)
    MEM_B(0X40, ctx->r29) = ctx->r3;
    // sb          $a0, 0x41($sp)
    MEM_B(0X41, ctx->r29) = ctx->r4;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v1, $zero, 0x68
    ctx->r3 = ADD32(0, 0X68);
    // sb          $v1, 0xD38($v0)
    MEM_B(0XD38, ctx->r2) = ctx->r3;
    // addiu       $v0, $v0, 0xD38
    ctx->r2 = ADD32(ctx->r2, 0XD38);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // jal         0x80058CC8
    // sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    sub_80058CC8(rdram, ctx);
    goto after_0;
    // sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    after_0:
    // jal         0x800152D0
    // addiu       $a0, $zero, 0x5400
    ctx->r4 = ADD32(0, 0X5400);
    sub_800152D0(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, 0x5400
    ctx->r4 = ADD32(0, 0X5400);
    after_1:
    // lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // addiu       $s2, $s0, -0x7378
    ctx->r18 = ADD32(ctx->r16, -0X7378);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sw          $v0, 0x14($at)
    MEM_W(0X14, ctx->r1) = ctx->r2;
    // jal         0x80016030
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    sub_80016030(rdram, ctx);
    goto after_2;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_2:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // addiu       $s1, $s2, 0x4
    ctx->r17 = ADD32(ctx->r18, 0X4);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    sub_80014CFC(rdram, ctx);
    goto after_3;
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    after_3:
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // ori         $a1, $a1, 0x2E6
    ctx->r5 = ctx->r5 | 0X2E6;
    // lui         $a2, 0x1F80
    ctx->r6 = S32(0X1F80 << 16);
    // ori         $a2, $a2, 0x2EA
    ctx->r6 = ctx->r6 | 0X2EA;
    // lw          $v0, -0x7378($s0)
    ctx->r2 = MEM_W(-0X7378, ctx->r16);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s2, $v0, $s2
    ctx->r18 = ADD32(ctx->r2, ctx->r18);
    // jal         0x8003EC5C
    // addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    sub_8003EC5C(rdram, ctx);
    goto after_4;
    // addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_4:
    // addiu       $s2, $s0, -0x7378
    ctx->r18 = ADD32(ctx->r16, -0X7378);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // jal         0x80016030
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    sub_80016030(rdram, ctx);
    goto after_5;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_5:
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // lui         $s1, 0x1F80
    ctx->r17 = S32(0X1F80 << 16);
    // lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(0X14, ctx->r17);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    sub_80014CFC(rdram, ctx);
    goto after_6;
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    after_6:
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // ori         $a1, $a1, 0x2EE
    ctx->r5 = ctx->r5 | 0X2EE;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // ori         $a2, $a2, 0x2F2
    ctx->r6 = ctx->r6 | 0X2F2;
    // lw          $v0, -0x7378($s0)
    ctx->r2 = MEM_W(-0X7378, ctx->r16);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s2, $v0, $s2
    ctx->r18 = ADD32(ctx->r2, ctx->r18);
    // jal         0x8003EC5C
    // addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    sub_8003EC5C(rdram, ctx);
    goto after_7;
    // addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_7:
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // addiu       $s0, $s0, -0x7378
    ctx->r16 = ADD32(ctx->r16, -0X7378);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_8;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_8:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // ori         $a1, $a1, 0x2F6
    ctx->r5 = ctx->r5 | 0X2F6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_9;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_10;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_10:
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_11;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_11:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_12;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_13;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_13:
    // addiu       $a0, $zero, 0x274
    ctx->r4 = ADD32(0, 0X274);
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // jal         0x800152D0
    // sh          $zero, 0xE($s1)
    MEM_H(0XE, ctx->r17) = 0;
    sub_800152D0(rdram, ctx);
    goto after_14;
    // sh          $zero, 0xE($s1)
    MEM_H(0XE, ctx->r17) = 0;
    after_14:
    // addiu       $a0, $zero, 0x274
    ctx->r4 = ADD32(0, 0X274);
    // jal         0x800152D0
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_15;
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    after_15:
    // lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(0X4, ctx->r17);
    // nop

    // beq         $a0, $zero, L_80066460
    if (ctx->r4 == 0) {
        // sw          $v0, 0x8($s1)
        MEM_W(0X8, ctx->r17) = ctx->r2;
        goto L_80066460;
    }
    // sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // bne         $v0, $zero, L_80066468
    if (ctx->r2 != 0) {
        // addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
        goto L_80066468;
    }
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80066460:
    // jal         0x80078A24
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    exit(rdram, ctx);
    goto after_16;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
L_80066468:
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x9D
    ctx->r6 = ADD32(0, 0X9D);
    sub_80014D5C(rdram, ctx);
    goto after_17;
    // addiu       $a2, $zero, 0x9D
    ctx->r6 = ADD32(0, 0X9D);
    after_17:
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(0X8, ctx->r17);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x9D
    ctx->r6 = ADD32(0, 0X9D);
    sub_80014D5C(rdram, ctx);
    goto after_18;
    // addiu       $a2, $zero, 0x9D
    ctx->r6 = ADD32(0, 0X9D);
    after_18:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a3, $v0, 0x7590
    ctx->r7 = ADD32(ctx->r2, 0X7590);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a2, $v0, 0x76F8
    ctx->r6 = ADD32(ctx->r2, 0X76F8);
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // sh          $zero, 0xE($s1)
    MEM_H(0XE, ctx->r17) = 0;
L_800664A4:
    // lbu         $v1, 0x11D($a2)
    ctx->r3 = MEM_BU(0X11D, ctx->r6);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_80066650
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $a0, 0x13A
        ctx->r2 = SIGNED(ctx->r4) < 0X13A ? 1 : 0;
        goto L_80066650;
    }
    // slti        $v0, $a0, 0x13A
    ctx->r2 = SIGNED(ctx->r4) < 0X13A ? 1 : 0;
    // beq         $v0, $zero, L_80066650
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x10A
        ctx->r2 = ADD32(0, 0X10A);
        goto L_80066650;
    }
    // addiu       $v0, $zero, 0x10A
    ctx->r2 = ADD32(0, 0X10A);
    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // addu        $v0, $a0, $a3
        ctx->r2 = ADD32(ctx->r4, ctx->r7);
        goto L_80066650;
    }
    // addu        $v0, $a0, $a3
    ctx->r2 = ADD32(ctx->r4, ctx->r7);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 & 0X7F;
    // beq         $v0, $zero, L_80066650
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x38($a1)
    ctx->r2 = MEM_HU(0X38, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x3A($a1)
    ctx->r2 = MEM_HU(0X3A, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x3C($a1)
    ctx->r2 = MEM_HU(0X3C, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x3E($a1)
    ctx->r2 = MEM_HU(0X3E, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x40($a1)
    ctx->r2 = MEM_HU(0X40, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x42($a1)
    ctx->r2 = MEM_HU(0X42, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x46($a1)
    ctx->r2 = MEM_HU(0X46, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x48($a1)
    ctx->r2 = MEM_HU(0X48, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x4A($a1)
    ctx->r2 = MEM_HU(0X4A, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x4C($a1)
    ctx->r2 = MEM_HU(0X4C, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x4E($a1)
    ctx->r2 = MEM_HU(0X4E, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x52($a1)
    ctx->r2 = MEM_HU(0X52, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x54($a1)
    ctx->r2 = MEM_HU(0X54, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x56($a1)
    ctx->r2 = MEM_HU(0X56, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x58($a1)
    ctx->r2 = MEM_HU(0X58, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x5A($a1)
    ctx->r2 = MEM_HU(0X5A, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x5C($a1)
    ctx->r2 = MEM_HU(0X5C, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x5E($a1)
    ctx->r2 = MEM_HU(0X5E, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // nop
    
        goto L_80066650;
    }
    // nop

    // lhu         $v0, 0x60($a1)
    ctx->r2 = MEM_HU(0X60, ctx->r5);
    // nop

    // beq         $a0, $v0, L_80066650
    if (ctx->r4 == ctx->r2) {
        // srl         $v0, $v1, 7
        ctx->r2 = S32(U32(ctx->r3) >> 7);
        goto L_80066650;
    }
    // srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
    // bne         $v0, $zero, L_8006662C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006662C;
    }
    // nop

    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sh          $v1, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r3;
    // lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(0X4, ctx->r17);
    // j           L_80066644
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    goto L_80066644;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
L_8006662C:
    // lhu         $v0, 0xE($s1)
    ctx->r2 = MEM_HU(0XE, ctx->r17);
    // nop

    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sh          $v1, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r3;
    // lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(0X8, ctx->r17);
L_80066644:
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
L_80066650:
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slti        $v0, $a0, 0x13A
    ctx->r2 = SIGNED(ctx->r4) < 0X13A ? 1 : 0;
    // bne         $v0, $zero, L_800664A4
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2C
        ctx->r6 = ADD32(ctx->r6, 0X2C);
        goto L_800664A4;
    }
    // addiu       $a2, $a2, 0x2C
    ctx->r6 = ADD32(ctx->r6, 0X2C);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // sh          $v0, 0x2DC($s1)
    MEM_H(0X2DC, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $zero, 0x2E0($s1)
    MEM_H(0X2E0, ctx->r17) = 0;
    // sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // jal         0x80031CFC
    // sh          $v0, 0xD3A($v1)
    MEM_H(0XD3A, ctx->r3) = ctx->r2;
    sub_80031CFC(rdram, ctx);
    goto after_19;
    // sh          $v0, 0xD3A($v1)
    MEM_H(0XD3A, ctx->r3) = ctx->r2;
    after_19:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_20;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_20:
    // jal         0x800172BC
    // nop

    sub_800172BC(rdram, ctx);
    goto after_21;
    // nop

    after_21:
    // lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(0X54, ctx->r29);
    // lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(0X50, ctx->r29);
    // lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(0X4C, ctx->r29);
    // lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(0X48, ctx->r29);
    // addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // jr          $ra
    // nop

    return;
    // nop

;}
