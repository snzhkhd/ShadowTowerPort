#include "recomp.h"
#include "disable_warnings.h"

void sub_8005D25C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // sw          $ra, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r31;
    // sw          $fp, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r30;
    // sw          $s7, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r23;
    // sw          $s6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r22;
    // sw          $s5, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r20;
    // sw          $s3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r19;
    // sw          $s2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r18;
    // sw          $s1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r16;
    // addiu       $v0, $zero, 0x280
    ctx->r2 = ADD32(0, 0X280);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // sh          $zero, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = 0;
    // addiu       $a2, $v0, 0x2974
    ctx->r6 = ADD32(ctx->r2, 0X2974);
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
    // swl         $v1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r3);
    // swr         $v1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r3);
    // swl         $a0, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r4);
    // swr         $a0, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r4);
    // swl         $a1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r5);
    // swr         $a1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r5);
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
    // swl         $v1, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r3);
    // swr         $v1, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r3);
    // swl         $a0, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r4);
    // swr         $a0, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r4);
    // swl         $a1, 0x37($sp)
    do_swl(rdram, 0X37, ctx->r29, ctx->r5);
    // swr         $a1, 0x34($sp)
    do_swr(rdram, 0X34, ctx->r29, ctx->r5);
    // lb          $v1, 0x18($a2)
    ctx->r3 = MEM_BS(0X18, ctx->r6);
    // lb          $a0, 0x19($a2)
    ctx->r4 = MEM_BS(0X19, ctx->r6);
    // sb          $v1, 0x38($sp)
    MEM_B(0X38, ctx->r29) = ctx->r3;
    // sb          $a0, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r4;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x2990
    ctx->r6 = ADD32(ctx->r2, 0X2990);
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
    // swl         $v1, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r3);
    // swr         $v1, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r3);
    // swl         $a0, 0x47($sp)
    do_swl(rdram, 0X47, ctx->r29, ctx->r4);
    // swr         $a0, 0x44($sp)
    do_swr(rdram, 0X44, ctx->r29, ctx->r4);
    // swl         $a1, 0x4B($sp)
    do_swl(rdram, 0X4B, ctx->r29, ctx->r5);
    // swr         $a1, 0x48($sp)
    do_swr(rdram, 0X48, ctx->r29, ctx->r5);
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
    // swl         $v1, 0x4F($sp)
    do_swl(rdram, 0X4F, ctx->r29, ctx->r3);
    // swr         $v1, 0x4C($sp)
    do_swr(rdram, 0X4C, ctx->r29, ctx->r3);
    // swl         $a0, 0x53($sp)
    do_swl(rdram, 0X53, ctx->r29, ctx->r4);
    // swr         $a0, 0x50($sp)
    do_swr(rdram, 0X50, ctx->r29, ctx->r4);
    // swl         $a1, 0x57($sp)
    do_swl(rdram, 0X57, ctx->r29, ctx->r5);
    // swr         $a1, 0x54($sp)
    do_swr(rdram, 0X54, ctx->r29, ctx->r5);
    // lb          $v1, 0x18($a2)
    ctx->r3 = MEM_BS(0X18, ctx->r6);
    // lb          $a0, 0x19($a2)
    ctx->r4 = MEM_BS(0X19, ctx->r6);
    // sb          $v1, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r3;
    // sb          $a0, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r4;
    // addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
    // sh          $v0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // sh          $v0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1F6
    ctx->r2 = ADD32(0, 0X1F6);
    // jal         0x80058CC8
    // sh          $v0, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r2;
    sub_80058CC8(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r2;
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
    // addiu       $s3, $s0, -0x7378
    ctx->r19 = ADD32(ctx->r16, -0X7378);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sw          $v0, 0x14($at)
    MEM_W(0X14, ctx->r1) = ctx->r2;
    // jal         0x80016030
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_80016030(rdram, ctx);
    goto after_2;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_2:
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // addiu       $s1, $s3, 0x4
    ctx->r17 = ADD32(ctx->r19, 0X4);
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
    // addu        $s3, $v0, $s3
    ctx->r19 = ADD32(ctx->r2, ctx->r19);
    // jal         0x8003EC5C
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    sub_8003EC5C(rdram, ctx);
    goto after_4;
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    after_4:
    // addiu       $s3, $s0, -0x7378
    ctx->r19 = ADD32(ctx->r16, -0X7378);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // jal         0x80016030
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_80016030(rdram, ctx);
    goto after_5;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_5:
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(0X14, ctx->r18);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    sub_80014CFC(rdram, ctx);
    goto after_6;
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    after_6:
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // ori         $a1, $a1, 0x2EE
    ctx->r5 = ctx->r5 | 0X2EE;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // ori         $a2, $a2, 0x2F2
    ctx->r6 = ctx->r6 | 0X2F2;
    // lw          $v0, -0x7378($s0)
    ctx->r2 = MEM_W(-0X7378, ctx->r16);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s3, $v0, $s3
    ctx->r19 = ADD32(ctx->r2, ctx->r19);
    // jal         0x8003EC5C
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    sub_8003EC5C(rdram, ctx);
    goto after_7;
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
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
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
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
    ST_DrawSync(rdram, ctx);
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
    // addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
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
    ST_DrawSync(rdram, ctx);
    goto after_13;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_13:
    // addiu       $a0, $zero, 0x274
    ctx->r4 = ADD32(0, 0X274);
    // sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
    // jal         0x800152D0
    // sh          $zero, 0xE($s2)
    MEM_H(0XE, ctx->r18) = 0;
    sub_800152D0(rdram, ctx);
    goto after_14;
    // sh          $zero, 0xE($s2)
    MEM_H(0XE, ctx->r18) = 0;
    after_14:
    // addiu       $a0, $zero, 0x274
    ctx->r4 = ADD32(0, 0X274);
    // jal         0x800152D0
    // sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    sub_800152D0(rdram, ctx);
    goto after_15;
    // sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    after_15:
    // lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(0X4, ctx->r18);
    // nop

    // beq         $a0, $zero, L_8005D4F4
    if (ctx->r4 == 0) {
        // sw          $v0, 0x8($s2)
        MEM_W(0X8, ctx->r18) = ctx->r2;
        goto L_8005D4F4;
    }
    // sw          $v0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r2;
    // bne         $v0, $zero, L_8005D4FC
    if (ctx->r2 != 0) {
        // addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
        goto L_8005D4FC;
    }
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_8005D4F4:
    // jal         0x80078A24
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    exit(rdram, ctx);
    goto after_16;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
L_8005D4FC:
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
    // addiu       $a2, $zero, 0x9D
    ctx->r6 = ADD32(0, 0X9D);
    // lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(0X8, ctx->r18);
    // jal         0x80014D5C
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    sub_80014D5C(rdram, ctx);
    goto after_18;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    after_18:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a2, $v0, 0x7590
    ctx->r6 = ADD32(ctx->r2, 0X7590);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a1, $v0, 0x76F8
    ctx->r5 = ADD32(ctx->r2, 0X76F8);
    // sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
    // sh          $zero, 0xE($s2)
    MEM_H(0XE, ctx->r18) = 0;
L_8005D538:
    // lbu         $v1, 0x11D($a1)
    ctx->r3 = MEM_BU(0X11D, ctx->r5);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8005D6E4
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $s1, 0x13A
        ctx->r2 = SIGNED(ctx->r17) < 0X13A ? 1 : 0;
        goto L_8005D6E4;
    }
    // slti        $v0, $s1, 0x13A
    ctx->r2 = SIGNED(ctx->r17) < 0X13A ? 1 : 0;
    // beq         $v0, $zero, L_8005D6E4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x10A
        ctx->r2 = ADD32(0, 0X10A);
        goto L_8005D6E4;
    }
    // addiu       $v0, $zero, 0x10A
    ctx->r2 = ADD32(0, 0X10A);
    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // addu        $v0, $s1, $a2
        ctx->r2 = ADD32(ctx->r17, ctx->r6);
        goto L_8005D6E4;
    }
    // addu        $v0, $s1, $a2
    ctx->r2 = ADD32(ctx->r17, ctx->r6);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 & 0X7F;
    // beq         $v0, $zero, L_8005D6E4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x38($a0)
    ctx->r2 = MEM_HU(0X38, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x3A($a0)
    ctx->r2 = MEM_HU(0X3A, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(0X3C, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x3E($a0)
    ctx->r2 = MEM_HU(0X3E, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x40($a0)
    ctx->r2 = MEM_HU(0X40, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x42($a0)
    ctx->r2 = MEM_HU(0X42, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x46($a0)
    ctx->r2 = MEM_HU(0X46, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x48($a0)
    ctx->r2 = MEM_HU(0X48, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x4A($a0)
    ctx->r2 = MEM_HU(0X4A, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x4C($a0)
    ctx->r2 = MEM_HU(0X4C, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x4E($a0)
    ctx->r2 = MEM_HU(0X4E, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x52($a0)
    ctx->r2 = MEM_HU(0X52, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x54($a0)
    ctx->r2 = MEM_HU(0X54, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x56($a0)
    ctx->r2 = MEM_HU(0X56, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x58($a0)
    ctx->r2 = MEM_HU(0X58, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x5A($a0)
    ctx->r2 = MEM_HU(0X5A, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x5C($a0)
    ctx->r2 = MEM_HU(0X5C, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x5E($a0)
    ctx->r2 = MEM_HU(0X5E, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8005D6E4;
    }
    // nop

    // lhu         $v0, 0x60($a0)
    ctx->r2 = MEM_HU(0X60, ctx->r4);
    // nop

    // beq         $s1, $v0, L_8005D6E4
    if (ctx->r17 == ctx->r2) {
        // srl         $v0, $v1, 7
        ctx->r2 = S32(U32(ctx->r3) >> 7);
        goto L_8005D6E4;
    }
    // srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
    // bne         $v0, $zero, L_8005D6C0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005D6C0;
    }
    // nop

    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // nop

    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sh          $v1, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r3;
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // j           L_8005D6D8
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    goto L_8005D6D8;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
L_8005D6C0:
    // lhu         $v0, 0xE($s2)
    ctx->r2 = MEM_HU(0XE, ctx->r18);
    // nop

    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sh          $v1, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r3;
    // lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(0X8, ctx->r18);
L_8005D6D8:
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $s1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r17;
L_8005D6E4:
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // slti        $v0, $s1, 0x13A
    ctx->r2 = SIGNED(ctx->r17) < 0X13A ? 1 : 0;
    // bne         $v0, $zero, L_8005D538
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x2C
        ctx->r5 = ADD32(ctx->r5, 0X2C);
        goto L_8005D538;
    }
    // addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    // jal         0x800152D0
    // addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    sub_800152D0(rdram, ctx);
    goto after_19;
    // addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_19:
    // bne         $v0, $zero, L_8005D70C
    if (ctx->r2 != 0) {
        // sw          $v0, 0x10($s2)
        MEM_W(0X10, ctx->r18) = ctx->r2;
        goto L_8005D70C;
    }
    // sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // jal         0x80078A24
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    exit(rdram, ctx);
    goto after_20;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_20:
L_8005D70C:
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // addu        $v1, $s1, $zero
    ctx->r3 = ADD32(ctx->r17, 0);
L_8005D714:
    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // sll         $a1, $s1, 2
    ctx->r5 = S32(ctx->r17) << 2;
    // bgez        $s1, L_8005D728
    if (SIGNED(ctx->r17) >= 0) {
        // addu        $a0, $a1, $v0
        ctx->r4 = ADD32(ctx->r5, ctx->r2);
        goto L_8005D728;
    }
    // addu        $a0, $a1, $v0
    ctx->r4 = ADD32(ctx->r5, ctx->r2);
    // addiu       $v1, $s1, 0x3
    ctx->r3 = ADD32(ctx->r17, 0X3);
L_8005D728:
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addiu       $v0, $v0, 0x280
    ctx->r2 = ADD32(ctx->r2, 0X280);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $s1, $v1
    ctx->r3 = SUB32(ctx->r17, ctx->r3);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(0X10, ctx->r18);
    // addiu       $v0, $v0, 0x7C
    ctx->r2 = ADD32(ctx->r2, 0X7C);
    // addu        $a0, $a1, $a0
    ctx->r4 = ADD32(ctx->r5, ctx->r4);
    // sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // slti        $v0, $s1, 0x14
    ctx->r2 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
    // bne         $v0, $zero, L_8005D714
    if (ctx->r2 != 0) {
        // addu        $v1, $s1, $zero
        ctx->r3 = ADD32(ctx->r17, 0);
        goto L_8005D714;
    }
    // addu        $v1, $s1, $zero
    ctx->r3 = ADD32(ctx->r17, 0);
    // addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
    // addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8005D780:
    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17) << 2;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $a0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r4;
    // slti        $v0, $s1, 0x1D
    ctx->r2 = SIGNED(ctx->r17) < 0X1D ? 1 : 0;
    // bne         $v0, $zero, L_8005D780
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x1C
        ctx->r4 = ADD32(ctx->r4, 0X1C);
        goto L_8005D780;
    }
    // addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // addiu       $s1, $zero, 0x1D
    ctx->r17 = ADD32(0, 0X1D);
    // lui         $t0, 0x38E3
    ctx->r8 = S32(0X38E3 << 16);
    // ori         $t0, $t0, 0x8E39
    ctx->r8 = ctx->r8 | 0X8E39;
    // addiu       $a2, $s1, -0x1D
    ctx->r6 = ADD32(ctx->r17, -0X1D);
L_8005D7BC:
    // mult        $a2, $t0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $a3, $s1, 2
    ctx->r7 = S32(ctx->r17) << 2;
    // sra         $v0, $a2, 31
    ctx->r2 = S32(ctx->r6) >> 31;
    // lw          $a1, 0x10($s2)
    ctx->r5 = MEM_W(0X10, ctx->r18);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // addu        $a1, $a3, $a1
    ctx->r5 = ADD32(ctx->r7, ctx->r5);
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $a0, $t2, 1
    ctx->r4 = S32(ctx->r10) >> 1;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4) << 3;
    // subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addiu       $v0, $v0, 0x280
    ctx->r2 = ADD32(ctx->r2, 0X280);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // subu        $a2, $a2, $v1
    ctx->r6 = SUB32(ctx->r6, ctx->r3);
    // addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6) << 3;
    // subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // sh          $v0, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r2;
    // slti        $v0, $s1, 0x28
    ctx->r2 = SIGNED(ctx->r17) < 0X28 ? 1 : 0;
    // bne         $v0, $zero, L_8005D7BC
    if (ctx->r2 != 0) {
        // addiu       $a2, $s1, -0x1D
        ctx->r6 = ADD32(ctx->r17, -0X1D);
        goto L_8005D7BC;
    }
    // addiu       $a2, $s1, -0x1D
    ctx->r6 = ADD32(ctx->r17, -0X1D);
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // addu        $s6, $s1, $zero
    ctx->r22 = ADD32(ctx->r17, 0);
    // addiu       $s3, $zero, 0x27
    ctx->r19 = ADD32(0, 0X27);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $v0, $v0, -0x7E00
    ctx->r2 = ADD32(ctx->r2, -0X7E00);
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $fp, $v0, 0x76F8
    ctx->r30 = ADD32(ctx->r2, 0X76F8);
    // addu        $s5, $s1, $zero
    ctx->r21 = ADD32(ctx->r17, 0);
    // addu        $s7, $s1, $zero
    ctx->r23 = ADD32(ctx->r17, 0);
    // addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // addiu       $v0, $s4, 0xA88
    ctx->r2 = ADD32(ctx->r20, 0XA88);
    // sw          $v0, 0xA84($s4)
    MEM_W(0XA84, ctx->r20) = ctx->r2;
L_8005D864:
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x2000
    ctx->r3 = ctx->r3 | 0X2000;
    // addiu       $v0, $s6, 0x1000
    ctx->r2 = ADD32(ctx->r22, 0X1000);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8005D894
    if (ctx->r3 == 0) {
        // slti        $v1, $s1, 0x14
        ctx->r3 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
        goto L_8005D894;
    }
    // slti        $v1, $s1, 0x14
    ctx->r3 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ST_DrawSync(rdram, ctx);
    goto after_21;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_21:
    // addiu       $v0, $s4, 0xA88
    ctx->r2 = ADD32(ctx->r20, 0XA88);
    // sw          $v0, 0xA84($s4)
    MEM_W(0XA84, ctx->r20) = ctx->r2;
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // slti        $v1, $s1, 0x14
    ctx->r3 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
L_8005D894:
    // beq         $v1, $zero, L_8005D8D8
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8005D8D8;
    }
    // nop

    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8005D8D0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005D8D0;
    }
    // nop

    // lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(0X4, ctx->r18);
    // nop

    // addu        $v0, $s7, $v0
    ctx->r2 = ADD32(ctx->r23, ctx->r2);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // j           L_8005D904
    // nop

    goto L_8005D904;
    // nop

L_8005D8D0:
    // bne         $v1, $zero, L_8005D95C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8005D95C;
    }
    // nop

L_8005D8D8:
    // lhu         $v0, 0xE($s2)
    ctx->r2 = MEM_HU(0XE, ctx->r18);
    // addiu       $v1, $s1, -0x14
    ctx->r3 = ADD32(ctx->r17, -0X14);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8005D95C
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8005D95C;
    }
    // nop

    // lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(0X8, ctx->r18);
    // nop

    // addu        $v0, $s7, $v0
    ctx->r2 = ADD32(ctx->r23, ctx->r2);
    // lh          $v1, -0x28($v0)
    ctx->r3 = MEM_HS(-0X28, ctx->r2);
L_8005D904:
    // lw          $a2, 0xA84($s4)
    ctx->r6 = MEM_W(0XA84, ctx->r20);
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
    // addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // lbu         $a1, 0x11D($v0)
    ctx->r5 = MEM_BU(0X11D, ctx->r2);
    // jal         0x80016030
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    sub_80016030(rdram, ctx);
    goto after_22;
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_22:
    // sll         $s0, $v0, 11
    ctx->r16 = S32(ctx->r2) << 11;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // lw          $a1, 0x10($s2)
    ctx->r5 = MEM_W(0X10, ctx->r18);
    // lw          $a0, 0xA84($s4)
    ctx->r4 = MEM_W(0XA84, ctx->r20);
    // jal         0x8003EC5C
    // addu        $a1, $a1, $s5
    ctx->r5 = ADD32(ctx->r5, ctx->r21);
    sub_8003EC5C(rdram, ctx);
    goto after_23;
    // addu        $a1, $a1, $s5
    ctx->r5 = ADD32(ctx->r5, ctx->r21);
    after_23:
    // lw          $v0, 0xA84($s4)
    ctx->r2 = MEM_W(0XA84, ctx->r20);
    // addu        $s6, $s6, $s0
    ctx->r22 = ADD32(ctx->r22, ctx->r16);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // j           L_8005D990
    // sw          $v0, 0xA84($s4)
    MEM_W(0XA84, ctx->r20) = ctx->r2;
    goto L_8005D990;
    // sw          $v0, 0xA84($s4)
    MEM_W(0XA84, ctx->r20) = ctx->r2;
L_8005D95C:
    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // addu        $v0, $s5, $v0
    ctx->r2 = ADD32(ctx->r21, ctx->r2);
    // lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(0X2, ctx->r2);
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // jal         0x80079BE4
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    ClearImage(rdram, ctx);
    goto after_24;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    after_24:
L_8005D990:
    // addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // addiu       $s7, $s7, 0x2
    ctx->r23 = ADD32(ctx->r23, 0X2);
    // addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8005D864
    if (ctx->r2 != ctx->r3) {
        // addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8005D864;
    }
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // addu        $t2, $v1, $zero
    ctx->r10 = ADD32(ctx->r3, 0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $t2, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r10;
    // sh          $zero, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = 0;
    // sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    // sh          $zero, 0x2($s2)
    MEM_H(0X2, ctx->r18) = 0;
    // jal         0x80031CFC
    // sh          $v0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r2;
    sub_80031CFC(rdram, ctx);
    goto after_25;
    // sh          $v0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r2;
    after_25:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ST_DrawSync(rdram, ctx);
    goto after_26;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_26:
    // jal         0x800172BC
    // addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    sub_800172BC(rdram, ctx);
    goto after_27;
    // addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    after_27:
    // jal         0x80057A3C
    // lui         $s7, 0x6666
    ctx->r23 = S32(0X6666 << 16);
    sub_80057A3C(rdram, ctx);
    goto after_28;
    // lui         $s7, 0x6666
    ctx->r23 = S32(0X6666 << 16);
    after_28:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s5, $v0, -0x2E80
    ctx->r21 = ADD32(ctx->r2, -0X2E80);
    // ori         $s7, $s7, 0x6667
    ctx->r23 = ctx->r23 | 0X6667;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $s6, $v0, -0x7E00
    ctx->r22 = ADD32(ctx->r2, -0X7E00);
L_8005DA00:
    // lhu         $v0, 0x4($s5)
    ctx->r2 = MEM_HU(0X4, ctx->r21);
    // lhu         $s3, 0x0($s2)
    ctx->r19 = MEM_HU(0X0, ctx->r18);
    // lhu         $t2, 0x2($s2)
    ctx->r10 = MEM_HU(0X2, ctx->r18);
    // andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // beq         $v0, $zero, L_8005DA58
    if (ctx->r2 == 0) {
        // sh          $t2, 0x78($sp)
        MEM_H(0X78, ctx->r29) = ctx->r10;
        goto L_8005DA58;
    }
    // sh          $t2, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r10;
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_29;
    // nop

    after_29:
    // sh          $zero, 0x4($s5)
    MEM_H(0X4, ctx->r21) = 0;
    // lhu         $v1, 0x2DC($s2)
    ctx->r3 = MEM_HU(0X2DC, ctx->r18);
    // nop

    // andi        $v0, $v1, 0x8000
    ctx->r2 = ctx->r3 & 0X8000;
    // beq         $v0, $zero, L_8005DA48
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x7FFF
        ctx->r2 = ctx->r3 & 0X7FFF;
        goto L_8005DA48;
    }
    // andi        $v0, $v1, 0x7FFF
    ctx->r2 = ctx->r3 & 0X7FFF;
    // j           L_8005DA58
    // sh          $v0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r2;
    goto L_8005DA58;
    // sh          $v0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r2;
L_8005DA40:
    // j           L_8005DB18
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    goto L_8005DB18;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_8005DA48:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_8005E800
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8005E800;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $v0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r2;
L_8005DA58:
    // lhu         $v0, 0x4($s5)
    ctx->r2 = MEM_HU(0X4, ctx->r21);
    // nop

    // andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // beq         $v0, $zero, L_8005DEA4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005DEA4;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_30;
    // nop

    after_30:
    // sh          $zero, 0x4($s5)
    MEM_H(0X4, ctx->r21) = 0;
    // lhu         $v0, 0x2DC($s2)
    ctx->r2 = MEM_HU(0X2DC, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // beq         $v0, $zero, L_8005DDF4
    if (ctx->r2 == 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_8005DDF4;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lhu         $v0, 0x2E0($s2)
    ctx->r2 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bgez        $v1, L_8005DAA8
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005DAA8;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x7
    ctx->r2 = ADD32(ctx->r3, 0X7);
L_8005DAA8:
    // sra         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2) >> 3;
    // sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6) << 3;
    // subu        $a3, $v1, $v0
    ctx->r7 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8005DC5C
    if (ctx->r2 == 0) {
        // sll         $v0, $a2, 2
        ctx->r2 = S32(ctx->r6) << 2;
        goto L_8005DC5C;
    }
    // sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6) << 2;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // lh          $v1, 0x0($s2)
    ctx->r3 = MEM_HS(0X0, ctx->r18);
    // lhu         $a1, 0xE($s2)
    ctx->r5 = MEM_HU(0XE, ctx->r18);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // blez        $v1, L_8005DB18
    if (SIGNED(ctx->r3) <= 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_8005DB18;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(0X8, ctx->r18);
    // addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8005DAF8:
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_HS(0X0, ctx->r3);
    // nop

    // beq         $v0, $fp, L_8005DA40
    if (ctx->r2 == ctx->r30) {
        // nop
    
        goto L_8005DA40;
    }
    // nop

    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slt         $v0, $a0, $a2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // bne         $v0, $zero, L_8005DAF8
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
        goto L_8005DAF8;
    }
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8005DB18:
    // sll         $t1, $a1, 16
    ctx->r9 = S32(ctx->r5) << 16;
    // sra         $t0, $t1, 16
    ctx->r8 = S32(ctx->r9) >> 16;
    // sll         $a2, $t0, 1
    ctx->r6 = S32(ctx->r8) << 1;
    // sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) << 16;
    // sra         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7) >> 16;
    // mult        $a0, $s7
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $a1, $a0, 1
    ctx->r5 = S32(ctx->r4) << 1;
    // lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(0X4, ctx->r18);
    // lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(0X8, ctx->r18);
    // addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(0X4, ctx->r18);
    // sra         $a3, $a3, 31
    ctx->r7 = S32(ctx->r7) >> 31;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sh          $fp, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r30;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v1, $t2, 3
    ctx->r3 = S32(ctx->r10) >> 3;
    // subu        $v1, $v1, $a3
    ctx->r3 = SUB32(ctx->r3, ctx->r7);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // sra         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4) >> 14;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // nop

    // sh          $v0, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // nop

    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(0X2, ctx->r4);
    // addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    // sh          $v0, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // sh          $v0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r2;
    // sh          $v1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r3;
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 14
    ctx->r3 = S32(ctx->r2) >> 14;
    // slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8005DC28
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x70
        ctx->r4 = ADD32(ctx->r29, 0X70);
        goto L_8005DC28;
    }
    // addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // addiu       $v0, $v1, 0x14
    ctx->r2 = ADD32(ctx->r3, 0X14);
    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8005DC28
    if (ctx->r2 == 0) {
        // mult        $t0, $s7
        result = S64(S32(ctx->r8)) * S64(S32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_8005DC28;
    }
    // mult        $t0, $s7
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $t1, 31
    ctx->r2 = S32(ctx->r9) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v1, $t2, 3
    ctx->r3 = S32(ctx->r10) >> 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(0X10, ctx->r18);
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $a1, 0x50($v0)
    ctx->r5 = MEM_HS(0X50, ctx->r2);
    // lh          $a2, 0x52($v0)
    ctx->r6 = MEM_HS(0X52, ctx->r2);
    // jal         0x80079DCC
    // addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    MoveImage(rdram, ctx);
    goto after_31;
    // addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    after_31:
    // addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
L_8005DC28:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x80079BE4
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    ClearImage(rdram, ctx);
    goto after_32;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_32:
    // lhu         $v0, 0xE($s2)
    ctx->r2 = MEM_HU(0XE, ctx->r18);
    // lhu         $v1, 0xC($s2)
    ctx->r3 = MEM_HU(0XC, ctx->r18);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
    // j           L_8005DDE8
    // sh          $v1, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r3;
    goto L_8005DDE8;
    // sh          $v1, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r3;
L_8005DC54:
    // j           L_8005DCB4
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    goto L_8005DCB4;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_8005DC5C:
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // lhu         $v1, 0x2($s2)
    ctx->r3 = MEM_HU(0X2, ctx->r18);
    // lhu         $a1, 0xC($s2)
    ctx->r5 = MEM_HU(0XC, ctx->r18);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 14
    ctx->r3 = S32(ctx->r3) >> 14;
    // addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // blez        $v1, L_8005DCB4
    if (SIGNED(ctx->r3) <= 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_8005DCB4;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(0X4, ctx->r18);
    // addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8005DC94:
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_HS(0X0, ctx->r3);
    // nop

    // beq         $v0, $fp, L_8005DC54
    if (ctx->r2 == ctx->r30) {
        // nop
    
        goto L_8005DC54;
    }
    // nop

    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slt         $v0, $a0, $a2
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // bne         $v0, $zero, L_8005DC94
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
        goto L_8005DC94;
    }
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8005DCB4:
    // sll         $t1, $a1, 16
    ctx->r9 = S32(ctx->r5) << 16;
    // sra         $t0, $t1, 16
    ctx->r8 = S32(ctx->r9) >> 16;
    // sll         $a2, $t0, 1
    ctx->r6 = S32(ctx->r8) << 1;
    // sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) << 16;
    // sra         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7) >> 16;
    // mult        $a0, $s7
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $a1, $a0, 1
    ctx->r5 = S32(ctx->r4) << 1;
    // lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(0X8, ctx->r18);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(0X8, ctx->r18);
    // sra         $a3, $a3, 31
    ctx->r7 = S32(ctx->r7) >> 31;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sh          $fp, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r30;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v1, $t2, 3
    ctx->r3 = S32(ctx->r10) >> 3;
    // subu        $v1, $v1, $a3
    ctx->r3 = SUB32(ctx->r3, ctx->r7);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // sra         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4) >> 14;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lhu         $v0, 0x50($v0)
    ctx->r2 = MEM_HU(0X50, ctx->r2);
    // nop

    // sh          $v0, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // nop

    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lhu         $v1, 0x52($a0)
    ctx->r3 = MEM_HU(0X52, ctx->r4);
    // addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    // sh          $v0, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // sh          $v0, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r2;
    // sh          $v1, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r3;
    // lh          $v0, 0x0($s2)
    ctx->r2 = MEM_HS(0X0, ctx->r18);
    // nop

    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // slt         $v0, $t0, $v1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8005DDC0
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x70
        ctx->r4 = ADD32(ctx->r29, 0X70);
        goto L_8005DDC0;
    }
    // addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // addiu       $v0, $v1, 0x14
    ctx->r2 = ADD32(ctx->r3, 0X14);
    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8005DDC0
    if (ctx->r2 == 0) {
        // mult        $t0, $s7
        result = S64(S32(ctx->r8)) * S64(S32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_8005DDC0;
    }
    // mult        $t0, $s7
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $t1, 31
    ctx->r2 = S32(ctx->r9) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v1, $t2, 3
    ctx->r3 = S32(ctx->r10) >> 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(0X10, ctx->r18);
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $a1, 0x0($v0)
    ctx->r5 = MEM_HS(0X0, ctx->r2);
    // lh          $a2, 0x2($v0)
    ctx->r6 = MEM_HS(0X2, ctx->r2);
    // jal         0x80079DCC
    // addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    MoveImage(rdram, ctx);
    goto after_33;
    // addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    after_33:
    // addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
L_8005DDC0:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x80079BE4
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    ClearImage(rdram, ctx);
    goto after_34;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_34:
    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // lhu         $v1, 0xE($s2)
    ctx->r3 = MEM_HU(0XE, ctx->r18);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // sh          $v1, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r3;
L_8005DDE8:
    // lhu         $v0, 0x2DC($s2)
    ctx->r2 = MEM_HU(0X2DC, ctx->r18);
    // j           L_8005DEA0
    // andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    goto L_8005DEA0;
    // andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
L_8005DDF4:
    // lhu         $v0, 0x2E0($s2)
    ctx->r2 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bgez        $v1, L_8005DE10
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005DE10;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x7
    ctx->r2 = ADD32(ctx->r3, 0X7);
L_8005DE10:
    // sra         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2) >> 3;
    // sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4) << 3;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8005DE4C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005DE4C;
    }
    // nop

    // lh          $v0, 0x0($s2)
    ctx->r2 = MEM_HS(0X0, ctx->r18);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // j           L_8005DE70
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    goto L_8005DE70;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
L_8005DE4C:
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(0X8, ctx->r18);
L_8005DE70:
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
    // nop

    // bne         $v0, $fp, L_8005DE8C
    if (ctx->r2 != ctx->r30) {
        // nop
    
        goto L_8005DE8C;
    }
    // nop

    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8005DE8C:
    // bne         $a2, $zero, L_8005DEA4
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8005DEA4;
    }
    // nop

    // lhu         $v0, 0x2DC($s2)
    ctx->r2 = MEM_HU(0X2DC, ctx->r18);
    // nop

    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
L_8005DEA0:
    // sh          $v0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r2;
L_8005DEA4:
    // lhu         $v0, 0x2DC($s2)
    ctx->r2 = MEM_HU(0X2DC, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // bne         $v0, $zero, L_8005E7C8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005E7C8;
    }
    // nop

    // lhu         $v0, 0x4($s5)
    ctx->r2 = MEM_HU(0X4, ctx->r21);
    // nop

    // andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // beq         $v0, $zero, L_8005DF04
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005DF04;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_35;
    // nop

    after_35:
    // sh          $zero, 0x4($s5)
    MEM_H(0X4, ctx->r21) = 0;
    // lhu         $v0, 0x2DC($s2)
    ctx->r2 = MEM_HU(0X2DC, ctx->r18);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // bne         $v1, $a0, L_8005DEF8
    if (ctx->r3 != ctx->r4) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8005DEF8;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // j           L_8005DF04
    // sh          $v0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r2;
    goto L_8005DF04;
    // sh          $v0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r2;
L_8005DEF8:
    // bne         $v1, $v0, L_8005DF04
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005DF04;
    }
    // nop

    // sh          $a0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r4;
L_8005DF04:
    // lhu         $v0, 0xC($s5)
    ctx->r2 = MEM_HU(0XC, ctx->r21);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_8005DF64
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005DF64;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_36;
    // nop

    after_36:
    // sh          $zero, 0xC($s5)
    MEM_H(0XC, ctx->r21) = 0;
    // lhu         $a0, 0x2E0($s2)
    ctx->r4 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bgez        $v1, L_8005DF40
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005DF40;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x7
    ctx->r2 = ADD32(ctx->r3, 0X7);
L_8005DF40:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // beq         $v0, $v1, L_8005DF64
    if (ctx->r2 == ctx->r3) {
        // addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
        goto L_8005DF64;
    }
    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
L_8005DF64:
    // lhu         $v0, 0xC($s5)
    ctx->r2 = MEM_HU(0XC, ctx->r21);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8005DF9C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005DF9C;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_37;
    // nop

    after_37:
    // sh          $zero, 0xC($s5)
    MEM_H(0XC, ctx->r21) = 0;
    // lhu         $v1, 0x2E0($s2)
    ctx->r3 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // andi        $v0, $v1, 0x7
    ctx->r2 = ctx->r3 & 0X7;
    // beq         $v0, $zero, L_8005DF9C
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8005DF9C;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
L_8005DF9C:
    // lhu         $v0, 0xC($s5)
    ctx->r2 = MEM_HU(0XC, ctx->r21);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8005E0D4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005E0D4;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_38;
    // nop

    after_38:
    // lhu         $v0, 0x2($s5)
    ctx->r2 = MEM_HU(0X2, ctx->r21);
    // nop

    // andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // beq         $v0, $zero, L_8005E050
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005E050;
    }
    // nop

    // lhu         $v0, 0x2E0($s2)
    ctx->r2 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bgez        $v1, L_8005DFE8
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005DFE8;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x7
    ctx->r2 = ADD32(ctx->r3, 0X7);
L_8005DFE8:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8005E02C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005E02C;
    }
    // nop

    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // nop

    // addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_8005E0D0
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8005E0D0;
    }
    // nop

    // j           L_8005E0D0
    // sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    goto L_8005E0D0;
    // sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
L_8005E02C:
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // nop

    // addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_8005E0D0
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8005E0D0;
    }
    // nop

    // j           L_8005E0D0
    // sh          $zero, 0x2($s2)
    MEM_H(0X2, ctx->r18) = 0;
    goto L_8005E0D0;
    // sh          $zero, 0x2($s2)
    MEM_H(0X2, ctx->r18) = 0;
L_8005E050:
    // lhu         $a0, 0x2E0($s2)
    ctx->r4 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_8005E074
    if (ctx->r2 != 0) {
        // addiu       $v0, $a0, -0x8
        ctx->r2 = ADD32(ctx->r4, -0X8);
        goto L_8005E074;
    }
    // addiu       $v0, $a0, -0x8
    ctx->r2 = ADD32(ctx->r4, -0X8);
    // j           L_8005E0D0
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
    goto L_8005E0D0;
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
L_8005E074:
    // bgez        $v1, L_8005E080
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005E080;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x7
    ctx->r2 = ADD32(ctx->r3, 0X7);
L_8005E080:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8005E0B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005E0B8;
    }
    // nop

    // lh          $v0, 0x0($s2)
    ctx->r2 = MEM_HS(0X0, ctx->r18);
    // lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(0X0, ctx->r18);
    // blez        $v0, L_8005E0D0
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8005E0D0;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // j           L_8005E0D0
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    goto L_8005E0D0;
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
L_8005E0B8:
    // lhu         $v1, 0x2($s2)
    ctx->r3 = MEM_HU(0X2, ctx->r18);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // blez        $v0, L_8005E0D0
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8005E0D0;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
L_8005E0D0:
    // sh          $zero, 0xC($s5)
    MEM_H(0XC, ctx->r21) = 0;
L_8005E0D4:
    // lhu         $v0, 0xC($s5)
    ctx->r2 = MEM_HU(0XC, ctx->r21);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_8005E228
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005E228;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_39;
    // nop

    after_39:
    // lhu         $v0, 0x2($s5)
    ctx->r2 = MEM_HU(0X2, ctx->r21);
    // nop

    // andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // beq         $v0, $zero, L_8005E198
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005E198;
    }
    // nop

    // lhu         $v0, 0x2E0($s2)
    ctx->r2 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bgez        $v1, L_8005E120
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005E120;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x7
    ctx->r2 = ADD32(ctx->r3, 0X7);
L_8005E120:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8005E16C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005E16C;
    }
    // nop

    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x4A
    ctx->r2 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
    // bne         $v0, $zero, L_8005E224
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x49
        ctx->r2 = ADD32(0, 0X49);
        goto L_8005E224;
    }
    // addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
    // j           L_8005E224
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    goto L_8005E224;
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
L_8005E16C:
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x4A
    ctx->r2 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
    // bne         $v0, $zero, L_8005E224
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x49
        ctx->r2 = ADD32(0, 0X49);
        goto L_8005E224;
    }
    // addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
    // j           L_8005E224
    // sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
    goto L_8005E224;
    // sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
L_8005E198:
    // lhu         $a0, 0x2E0($s2)
    ctx->r4 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // beq         $v0, $zero, L_8005E1BC
    if (ctx->r2 == 0) {
        // addiu       $v0, $a0, 0x8
        ctx->r2 = ADD32(ctx->r4, 0X8);
        goto L_8005E1BC;
    }
    // addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // j           L_8005E224
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
    goto L_8005E224;
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
L_8005E1BC:
    // bgez        $v1, L_8005E1C8
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005E1C8;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x7
    ctx->r2 = ADD32(ctx->r3, 0X7);
L_8005E1C8:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8005E204
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005E204;
    }
    // nop

    // lh          $v0, 0x0($s2)
    ctx->r2 = MEM_HS(0X0, ctx->r18);
    // lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(0X0, ctx->r18);
    // slti        $v0, $v0, 0x49
    ctx->r2 = SIGNED(ctx->r2) < 0X49 ? 1 : 0;
    // beq         $v0, $zero, L_8005E224
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_8005E224;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // j           L_8005E224
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    goto L_8005E224;
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
L_8005E204:
    // lhu         $v1, 0x2($s2)
    ctx->r3 = MEM_HU(0X2, ctx->r18);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x49
    ctx->r2 = SIGNED(ctx->r2) < 0X49 ? 1 : 0;
    // beq         $v0, $zero, L_8005E224
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_8005E224;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
L_8005E224:
    // sh          $zero, 0xC($s5)
    MEM_H(0XC, ctx->r21) = 0;
L_8005E228:
    // lhu         $v0, 0xC($s5)
    ctx->r2 = MEM_HU(0XC, ctx->r21);
    // nop

    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // beq         $v0, $zero, L_8005E268
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005E268;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_40;
    // nop

    after_40:
    // sh          $zero, 0xC($s5)
    MEM_H(0XC, ctx->r21) = 0;
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // nop

    // addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_8005E268
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8005E268;
    }
    // nop

    // sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
L_8005E268:
    // lhu         $v0, 0xC($s5)
    ctx->r2 = MEM_HU(0XC, ctx->r21);
    // nop

    // andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // beq         $v0, $zero, L_8005E2B0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005E2B0;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_41;
    // nop

    after_41:
    // sh          $zero, 0xC($s5)
    MEM_H(0XC, ctx->r21) = 0;
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x4A
    ctx->r2 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
    // bne         $v0, $zero, L_8005E2B0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x49
        ctx->r2 = ADD32(0, 0X49);
        goto L_8005E2B0;
    }
    // addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
    // sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
L_8005E2B0:
    // lhu         $v0, 0xC($s5)
    ctx->r2 = MEM_HU(0XC, ctx->r21);
    // nop

    // andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // beq         $v0, $zero, L_8005E2F0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005E2F0;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_42;
    // nop

    after_42:
    // sh          $zero, 0xC($s5)
    MEM_H(0XC, ctx->r21) = 0;
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // nop

    // addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_8005E2F0
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8005E2F0;
    }
    // nop

    // sh          $zero, 0x2($s2)
    MEM_H(0X2, ctx->r18) = 0;
L_8005E2F0:
    // lhu         $v0, 0xC($s5)
    ctx->r2 = MEM_HU(0XC, ctx->r21);
    // nop

    // andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // beq         $v0, $zero, L_8005E338
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005E338;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_43;
    // nop

    after_43:
    // sh          $zero, 0xC($s5)
    MEM_H(0XC, ctx->r21) = 0;
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x4A
    ctx->r2 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
    // bne         $v0, $zero, L_8005E338
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x49
        ctx->r2 = ADD32(0, 0X49);
        goto L_8005E338;
    }
    // addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
    // sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
L_8005E338:
    // lhu         $v1, 0x2DC($s2)
    ctx->r3 = MEM_HU(0X2DC, ctx->r18);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_8005E450
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005E450;
    }
    // nop

    // lhu         $v0, 0x2E0($s2)
    ctx->r2 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // bgez        $a0, L_8005E364
    if (SIGNED(ctx->r4) >= 0) {
        // addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
        goto L_8005E364;
    }
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // addiu       $v0, $a0, 0x7
    ctx->r2 = ADD32(ctx->r4, 0X7);
L_8005E364:
    // sra         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) >> 3;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8005E3B4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005E3B4;
    }
    // nop

    // lh          $v0, 0x0($s2)
    ctx->r2 = MEM_HS(0X0, ctx->r18);
    // nop

    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $s1, 0x0($v0)
    ctx->r17 = MEM_HU(0X0, ctx->r2);
    // j           L_8005E3E4
    // nop

    goto L_8005E3E4;
    // nop

L_8005E3B4:
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(0X8, ctx->r18);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $s1, -0x8($v0)
    ctx->r17 = MEM_HU(-0X8, ctx->r2);
L_8005E3E4:
    // lhu         $t2, 0x80($sp)
    ctx->r10 = MEM_HU(0X80, ctx->r29);
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // sll         $v1, $t2, 16
    ctx->r3 = S32(ctx->r10) << 16;
    // beq         $v1, $v0, L_8005E450
    if (ctx->r3 == ctx->r2) {
        // sra         $a1, $v0, 16
        ctx->r5 = S32(ctx->r2) >> 16;
        goto L_8005E450;
    }
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // beq         $a1, $fp, L_8005E450
    if (ctx->r5 == ctx->r30) {
        // addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
        goto L_8005E450;
    }
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // addiu       $s0, $s0, -0x7378
    ctx->r16 = ADD32(ctx->r16, -0X7378);
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // addiu       $t2, $t2, 0x76F8
    ctx->r10 = ADD32(ctx->r10, 0X76F8);
    // addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // lbu         $a1, 0x11D($v0)
    ctx->r5 = MEM_BU(0X11D, ctx->r2);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // sh          $s1, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r17;
    // jal         0x80016030
    // addiu       $a1, $a1, 0xC8
    ctx->r5 = ADD32(ctx->r5, 0XC8);
    sub_80016030(rdram, ctx);
    goto after_44;
    // addiu       $a1, $a1, 0xC8
    ctx->r5 = ADD32(ctx->r5, 0XC8);
    after_44:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_45;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_45:
L_8005E450:
    // lh          $v1, 0x0($s2)
    ctx->r3 = MEM_HS(0X0, ctx->r18);
    // sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // beq         $v1, $a0, L_8005E604
    if (ctx->r3 == ctx->r4) {
        // slt         $v0, $a0, $v1
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_8005E604;
    }
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8005E488
    if (ctx->r2 == 0) {
        // subu        $v0, $v1, $a0
        ctx->r2 = SUB32(ctx->r3, ctx->r4);
        goto L_8005E488;
    }
    // subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // sll         $s3, $v0, 2
    ctx->r19 = S32(ctx->r2) << 2;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // sll         $v0, $v0, 18
    ctx->r2 = S32(ctx->r2) << 18;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x14
    ctx->r2 = ADD32(ctx->r2, -0X14);
    // j           L_8005E494
    // subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
    goto L_8005E494;
    // subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
L_8005E488:
    // subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // sll         $s3, $v0, 2
    ctx->r19 = S32(ctx->r2) << 2;
    // sll         $s1, $v1, 2
    ctx->r17 = S32(ctx->r3) << 2;
L_8005E494:
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // addiu       $v0, $s6, 0xA88
    ctx->r2 = ADD32(ctx->r22, 0XA88);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // beq         $v1, $fp, L_8005E604
    if (ctx->r3 == ctx->r30) {
        // sw          $v0, 0xA84($s6)
        MEM_W(0XA84, ctx->r22) = ctx->r2;
        goto L_8005E604;
    }
    // sw          $v0, 0xA84($s6)
    MEM_W(0XA84, ctx->r22) = ctx->r2;
L_8005E4C4:
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x2000
    ctx->r3 = ctx->r3 | 0X2000;
    // addiu       $v0, $s4, 0x1000
    ctx->r2 = ADD32(ctx->r20, 0X1000);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8005E4F0
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8005E4F0;
    }
    // nop

    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ST_DrawSync(rdram, ctx);
    goto after_46;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_46:
    // addiu       $v0, $s6, 0xA88
    ctx->r2 = ADD32(ctx->r22, 0XA88);
    // sw          $v0, 0xA84($s6)
    MEM_W(0XA84, ctx->r22) = ctx->r2;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_8005E4F0:
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // nop

    // beq         $v1, $fp, L_8005E590
    if (ctx->r3 == ctx->r30) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_8005E590;
    }
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
    // lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // addiu       $t2, $t2, 0x76F8
    ctx->r10 = ADD32(ctx->r10, 0X76F8);
    // addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // lbu         $a1, 0x11D($v0)
    ctx->r5 = MEM_BU(0X11D, ctx->r2);
    // lw          $a2, 0xA84($s6)
    ctx->r6 = MEM_W(0XA84, ctx->r22);
    // jal         0x80016030
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    sub_80016030(rdram, ctx);
    goto after_47;
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_47:
    // mult        $s1, $s7
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // sra         $v1, $s1, 31
    ctx->r3 = S32(ctx->r17) >> 31;
    // sll         $s0, $v0, 11
    ctx->r16 = S32(ctx->r2) << 11;
    // lw          $a0, 0xA84($s6)
    ctx->r4 = MEM_W(0XA84, ctx->r22);
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $t0, $t2, 3
    ctx->r8 = S32(ctx->r10) >> 3;
    // subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // sll         $a1, $t0, 2
    ctx->r5 = S32(ctx->r8) << 2;
    // addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // subu        $a1, $s1, $a1
    ctx->r5 = SUB32(ctx->r17, ctx->r5);
    // lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(0X10, ctx->r18);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // jal         0x8003EC5C
    // addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    sub_8003EC5C(rdram, ctx);
    goto after_48;
    // addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    after_48:
    // lw          $v0, 0xA84($s6)
    ctx->r2 = MEM_W(0XA84, ctx->r22);
    // addu        $s4, $s4, $s0
    ctx->r20 = ADD32(ctx->r20, ctx->r16);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // j           L_8005E5EC
    // sw          $v0, 0xA84($s6)
    MEM_W(0XA84, ctx->r22) = ctx->r2;
    goto L_8005E5EC;
    // sw          $v0, 0xA84($s6)
    MEM_W(0XA84, ctx->r22) = ctx->r2;
L_8005E590:
    // mult        $s1, $s7
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // sra         $v0, $s1, 31
    ctx->r2 = S32(ctx->r17) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v1, $t2, 3
    ctx->r3 = S32(ctx->r10) >> 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $s1, $v0
    ctx->r2 = SUB32(ctx->r17, ctx->r2);
    // lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(0X10, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v1, 0x0($v1)
    ctx->r3 = MEM_HU(0X0, ctx->r3);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sh          $v1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r3;
    // lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(0X10, ctx->r18);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(0X2, ctx->r2);
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // jal         0x80079BE4
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    ClearImage(rdram, ctx);
    goto after_49;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    after_49:
L_8005E5EC:
    // addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $fp, L_8005E4C4
    if (ctx->r2 != ctx->r30) {
        // addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8005E4C4;
    }
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8005E604:
    // lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(0X2, ctx->r18);
    // lhu         $t2, 0x78($sp)
    ctx->r10 = MEM_HU(0X78, ctx->r29);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // beq         $v1, $a0, L_8005E7C8
    if (ctx->r3 == ctx->r4) {
        // slt         $v0, $a0, $v1
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_8005E7C8;
    }
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8005E648
    if (ctx->r2 == 0) {
        // subu        $v0, $v1, $a0
        ctx->r2 = SUB32(ctx->r3, ctx->r4);
        goto L_8005E648;
    }
    // subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // sll         $s3, $v0, 2
    ctx->r19 = S32(ctx->r2) << 2;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // sll         $v0, $v0, 18
    ctx->r2 = S32(ctx->r2) << 18;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x14
    ctx->r2 = ADD32(ctx->r2, -0X14);
    // j           L_8005E654
    // subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
    goto L_8005E654;
    // subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
L_8005E648:
    // subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // sll         $s3, $v0, 2
    ctx->r19 = S32(ctx->r2) << 2;
    // sll         $s1, $v1, 2
    ctx->r17 = S32(ctx->r3) << 2;
L_8005E654:
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // addiu       $v0, $s6, 0xA88
    ctx->r2 = ADD32(ctx->r22, 0XA88);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // beq         $v1, $fp, L_8005E7C8
    if (ctx->r3 == ctx->r30) {
        // sw          $v0, 0xA84($s6)
        MEM_W(0XA84, ctx->r22) = ctx->r2;
        goto L_8005E7C8;
    }
    // sw          $v0, 0xA84($s6)
    MEM_W(0XA84, ctx->r22) = ctx->r2;
L_8005E684:
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x2000
    ctx->r3 = ctx->r3 | 0X2000;
    // addiu       $v0, $s4, 0x1000
    ctx->r2 = ADD32(ctx->r20, 0X1000);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8005E6B0
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8005E6B0;
    }
    // nop

    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ST_DrawSync(rdram, ctx);
    goto after_50;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_50:
    // addiu       $v0, $s6, 0xA88
    ctx->r2 = ADD32(ctx->r22, 0XA88);
    // sw          $v0, 0xA84($s6)
    MEM_W(0XA84, ctx->r22) = ctx->r2;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_8005E6B0:
    // lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(0X8, ctx->r18);
    // sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // nop

    // beq         $v1, $fp, L_8005E754
    if (ctx->r3 == ctx->r30) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_8005E754;
    }
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
    // lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // addiu       $t2, $t2, 0x76F8
    ctx->r10 = ADD32(ctx->r10, 0X76F8);
    // addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // lbu         $a1, 0x11D($v0)
    ctx->r5 = MEM_BU(0X11D, ctx->r2);
    // lw          $a2, 0xA84($s6)
    ctx->r6 = MEM_W(0XA84, ctx->r22);
    // jal         0x80016030
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    sub_80016030(rdram, ctx);
    goto after_51;
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_51:
    // mult        $s1, $s7
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // sra         $v1, $s1, 31
    ctx->r3 = S32(ctx->r17) >> 31;
    // sll         $s0, $v0, 11
    ctx->r16 = S32(ctx->r2) << 11;
    // lw          $a0, 0xA84($s6)
    ctx->r4 = MEM_W(0XA84, ctx->r22);
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $t0, $t2, 3
    ctx->r8 = S32(ctx->r10) >> 3;
    // subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // sll         $a1, $t0, 2
    ctx->r5 = S32(ctx->r8) << 2;
    // addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // subu        $a1, $s1, $a1
    ctx->r5 = SUB32(ctx->r17, ctx->r5);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(0X10, ctx->r18);
    // addiu       $a1, $a1, 0x50
    ctx->r5 = ADD32(ctx->r5, 0X50);
    // jal         0x8003EC5C
    // addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    sub_8003EC5C(rdram, ctx);
    goto after_52;
    // addu        $a1, $v1, $a1
    ctx->r5 = ADD32(ctx->r3, ctx->r5);
    after_52:
    // lw          $v0, 0xA84($s6)
    ctx->r2 = MEM_W(0XA84, ctx->r22);
    // addu        $s4, $s4, $s0
    ctx->r20 = ADD32(ctx->r20, ctx->r16);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // j           L_8005E7B0
    // sw          $v0, 0xA84($s6)
    MEM_W(0XA84, ctx->r22) = ctx->r2;
    goto L_8005E7B0;
    // sw          $v0, 0xA84($s6)
    MEM_W(0XA84, ctx->r22) = ctx->r2;
L_8005E754:
    // mult        $s1, $s7
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // sra         $v0, $s1, 31
    ctx->r2 = S32(ctx->r17) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v1, $t2, 3
    ctx->r3 = S32(ctx->r10) >> 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $s1, $v0
    ctx->r2 = SUB32(ctx->r17, ctx->r2);
    // lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(0X10, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v1, 0x50($v1)
    ctx->r3 = MEM_HU(0X50, ctx->r3);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sh          $v1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r3;
    // lw          $v1, 0x10($s2)
    ctx->r3 = MEM_W(0X10, ctx->r18);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v0, 0x52($v0)
    ctx->r2 = MEM_HU(0X52, ctx->r2);
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // jal         0x80079BE4
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    ClearImage(rdram, ctx);
    goto after_53;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    after_53:
L_8005E7B0:
    // addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $fp, L_8005E684
    if (ctx->r2 != ctx->r30) {
        // addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8005E684;
    }
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8005E7C8:
    // jal         0x800164B4
    // nop

    sub_800164B4(rdram, ctx);
    goto after_54;
    // nop

    after_54:
    // jal         0x80031AEC
    // nop

    sub_80031AEC(rdram, ctx);
    goto after_55;
    // nop

    after_55:
    // lbu         $a0, 0x2E4($s2)
    ctx->r4 = MEM_BU(0X2E4, ctx->r18);
    // nop

    // addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // bgez        $v1, L_8005E7F0
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005E7F0;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_8005E7F0:
    // andi        $v0, $v0, 0x1E0
    ctx->r2 = ctx->r2 & 0X1E0;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // j           L_8005DA00
    // sb          $v0, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = ctx->r2;
    goto L_8005DA00;
    // sb          $v0, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = ctx->r2;
L_8005E800:
    // lhu         $s3, 0xC($s2)
    ctx->r19 = MEM_HU(0XC, ctx->r18);
    // nop

    // beq         $s3, $zero, L_8005E854
    if (ctx->r19 == 0) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_8005E854;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a0, $v0, 0x7590
    ctx->r4 = ADD32(ctx->r2, 0X7590);
L_8005E81C:
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // nop

    // beq         $v1, $a1, L_8005E848
    if (ctx->r3 == ctx->r5) {
        // addu        $v1, $v1, $a0
        ctx->r3 = ADD32(ctx->r3, ctx->r4);
        goto L_8005E848;
    }
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8005E848:
    // sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19) << 16;
    // bne         $v0, $zero, L_8005E81C
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8005E81C;
    }
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8005E854:
    // lhu         $s3, 0xE($s2)
    ctx->r19 = MEM_HU(0XE, ctx->r18);
    // nop

    // beq         $s3, $zero, L_8005E8A8
    if (ctx->r19 == 0) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_8005E8A8;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a0, $v0, 0x7590
    ctx->r4 = ADD32(ctx->r2, 0X7590);
L_8005E870:
    // lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(0X8, ctx->r18);
    // sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x0($v0)
    ctx->r3 = MEM_HS(0X0, ctx->r2);
    // nop

    // beq         $v1, $a1, L_8005E89C
    if (ctx->r3 == ctx->r5) {
        // addu        $v1, $v1, $a0
        ctx->r3 = ADD32(ctx->r3, ctx->r4);
        goto L_8005E89C;
    }
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_8005E89C:
    // sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19) << 16;
    // bne         $v0, $zero, L_8005E870
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8005E870;
    }
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8005E8A8:
    // jal         0x80058C4C
    // nop

    sub_80058C4C(rdram, ctx);
    goto after_56;
    // nop

    after_56:
    // lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(0X4, ctx->r18);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_57;
    // nop

    after_57:
    // lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(0X8, ctx->r18);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_58;
    // nop

    after_58:
    // lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(0X10, ctx->r18);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_59;
    // nop

    after_59:
    // lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(0X14, ctx->r18);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_60;
    // nop

    after_60:
    // jal         0x80058D30
    // nop

    sub_80058D30(rdram, ctx);
    goto after_61;
    // nop

    after_61:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_62;
    // nop

    after_62:
    // lw          $ra, 0xAC($sp)
    ctx->r31 = MEM_W(0XAC, ctx->r29);
    // lw          $fp, 0xA8($sp)
    ctx->r30 = MEM_W(0XA8, ctx->r29);
    // lw          $s7, 0xA4($sp)
    ctx->r23 = MEM_W(0XA4, ctx->r29);
    // lw          $s6, 0xA0($sp)
    ctx->r22 = MEM_W(0XA0, ctx->r29);
    // lw          $s5, 0x9C($sp)
    ctx->r21 = MEM_W(0X9C, ctx->r29);
    // lw          $s4, 0x98($sp)
    ctx->r20 = MEM_W(0X98, ctx->r29);
    // lw          $s3, 0x94($sp)
    ctx->r19 = MEM_W(0X94, ctx->r29);
    // lw          $s2, 0x90($sp)
    ctx->r18 = MEM_W(0X90, ctx->r29);
    // lw          $s1, 0x8C($sp)
    ctx->r17 = MEM_W(0X8C, ctx->r29);
    // lw          $s0, 0x88($sp)
    ctx->r16 = MEM_W(0X88, ctx->r29);
    // addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // jr          $ra
    // nop

    return;
    // nop

;}
