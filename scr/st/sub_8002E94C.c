#include "recomp.h"
#include "disable_warnings.h"

void sub_8002E94C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, 0x7F64
    ctx->r6 = ADD32(ctx->r2, 0X7F64);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r3);
    // swr         $v1, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r3);
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    memset_recomp(rdram, ctx);
    goto after_0;
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    memset_recomp(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    after_1:
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // addiu       $v1, $zero, 0x78
    ctx->r3 = ADD32(0, 0X78);
    // addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // sb          $v1, 0x30C($s2)
    MEM_B(0X30C, ctx->r18) = ctx->r3;
    // sb          $v1, 0x309($s2)
    MEM_B(0X309, ctx->r18) = ctx->r3;
    // sb          $v1, 0x31C($s2)
    MEM_B(0X31C, ctx->r18) = ctx->r3;
    // sb          $v1, 0x319($s2)
    MEM_B(0X319, ctx->r18) = ctx->r3;
    // lhu         $v1, 0x2DC($s2)
    ctx->r3 = MEM_HU(0X2DC, ctx->r18);
    // addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
    // sb          $v0, 0x30F($s2)
    MEM_B(0X30F, ctx->r18) = ctx->r2;
    // sb          $v0, 0x30B($s2)
    MEM_B(0X30B, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
    // sb          $v0, 0x31F($s2)
    MEM_B(0X31F, ctx->r18) = ctx->r2;
    // sb          $v0, 0x31B($s2)
    MEM_B(0X31B, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $a0, 0x308($s2)
    MEM_B(0X308, ctx->r18) = ctx->r4;
    // sb          $a1, 0x30D($s2)
    MEM_B(0X30D, ctx->r18) = ctx->r5;
    // sb          $a0, 0x30A($s2)
    MEM_B(0X30A, ctx->r18) = ctx->r4;
    // sb          $a0, 0x30E($s2)
    MEM_B(0X30E, ctx->r18) = ctx->r4;
    // sb          $a0, 0x318($s2)
    MEM_B(0X318, ctx->r18) = ctx->r4;
    // sb          $a1, 0x31D($s2)
    MEM_B(0X31D, ctx->r18) = ctx->r5;
    // sb          $a0, 0x31A($s2)
    MEM_B(0X31A, ctx->r18) = ctx->r4;
    // bne         $v1, $v0, L_8002EA28
    if (ctx->r3 != ctx->r2) {
        // sb          $a0, 0x31E($s2)
        MEM_B(0X31E, ctx->r18) = ctx->r4;
        goto L_8002EA28;
    }
    // sb          $a0, 0x31E($s2)
    MEM_B(0X31E, ctx->r18) = ctx->r4;
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // ori         $v0, $v0, 0x300
    ctx->r2 = ctx->r2 | 0X300;
    // sw          $v0, 0x328($s2)
    MEM_W(0X328, ctx->r18) = ctx->r2;
    // sw          $v0, 0x324($s2)
    MEM_W(0X324, ctx->r18) = ctx->r2;
    // j           L_8002EA4C
    // sw          $v0, 0x320($s2)
    MEM_W(0X320, ctx->r18) = ctx->r2;
    goto L_8002EA4C;
    // sw          $v0, 0x320($s2)
    MEM_W(0X320, ctx->r18) = ctx->r2;
L_8002EA28:
    // lui         $a0, 0x1F80
    ctx->r4 = S32(0X1F80 << 16);
    // ori         $a0, $a0, 0x300
    ctx->r4 = ctx->r4 | 0X300;
    // lui         $v1, 0x1F80
    ctx->r3 = S32(0X1F80 << 16);
    // ori         $v1, $v1, 0x308
    ctx->r3 = ctx->r3 | 0X308;
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
    // ori         $v0, $v0, 0x30C
    ctx->r2 = ctx->r2 | 0X30C;
    // sw          $a0, 0x320($s2)
    MEM_W(0X320, ctx->r18) = ctx->r4;
    // sw          $v1, 0x324($s2)
    MEM_W(0X324, ctx->r18) = ctx->r3;
    // sw          $v0, 0x328($s2)
    MEM_W(0X328, ctx->r18) = ctx->r2;
L_8002EA4C:
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xD50
    ctx->r2 = ADD32(ctx->r2, 0XD50);
    // addiu       $s4, $v0, 0xC00
    ctx->r20 = ADD32(ctx->r2, 0XC00);
    // addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
L_8002EA68:
    // addiu       $s1, $s1, 0xF
    ctx->r17 = ADD32(ctx->r17, 0XF);
    // lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(0X1C, ctx->r16);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19) << 1;
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // addu        $v0, $sp, $v0
    ctx->r2 = ADD32(ctx->r29, ctx->r2);
    // lw          $a3, 0x320($s2)
    ctx->r7 = MEM_W(0X320, ctx->r18);
    // lhu         $a1, 0x30($v0)
    ctx->r5 = MEM_HU(0X30, ctx->r2);
    // addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // addiu       $a1, $a1, 0x13C
    ctx->r5 = ADD32(ctx->r5, 0X13C);
    // jal         0x8002732C
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_8002732C(rdram, ctx);
    goto after_2;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_2:
    // slti        $v0, $s3, 0xE
    ctx->r2 = SIGNED(ctx->r19) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_8002EA68
    if (ctx->r2 != 0) {
        // andi        $a2, $s1, 0xFFFF
        ctx->r6 = ctx->r17 & 0XFFFF;
        goto L_8002EA68;
    }
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
    // lhu         $v1, 0x2DC($s2)
    ctx->r3 = MEM_HU(0X2DC, ctx->r18);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8002EAC4
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $s2, 0x310
        ctx->r2 = ADD32(ctx->r18, 0X310);
        goto L_8002EAC4;
    }
    // addiu       $v0, $s2, 0x310
    ctx->r2 = ADD32(ctx->r18, 0X310);
    // sw          $v0, 0x328($s2)
    MEM_W(0X328, ctx->r18) = ctx->r2;
    // sw          $v0, 0x324($s2)
    MEM_W(0X324, ctx->r18) = ctx->r2;
    // j           L_8002EAD8
    // sw          $v0, 0x320($s2)
    MEM_W(0X320, ctx->r18) = ctx->r2;
    goto L_8002EAD8;
    // sw          $v0, 0x320($s2)
    MEM_W(0X320, ctx->r18) = ctx->r2;
L_8002EAC4:
    // sw          $v0, 0x320($s2)
    MEM_W(0X320, ctx->r18) = ctx->r2;
    // addiu       $v0, $s2, 0x318
    ctx->r2 = ADD32(ctx->r18, 0X318);
    // sw          $v0, 0x324($s2)
    MEM_W(0X324, ctx->r18) = ctx->r2;
    // addiu       $v0, $s2, 0x31C
    ctx->r2 = ADD32(ctx->r18, 0X31C);
    // sw          $v0, 0x328($s2)
    MEM_W(0X328, ctx->r18) = ctx->r2;
L_8002EAD8:
    // lhu         $v1, 0x2DC($s2)
    ctx->r3 = MEM_HU(0X2DC, ctx->r18);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_8002EB80
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8002EB80;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, 0x2C6($s2)
    ctx->r2 = MEM_BU(0X2C6, ctx->r18);
    // nop

    // beq         $v0, $zero, L_8002EB7C
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
        goto L_8002EB7C;
    }
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // lhu         $v0, 0x2BE($s2)
    ctx->r2 = MEM_HU(0X2BE, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // beq         $v0, $v1, L_8002ED6C
    if (ctx->r2 == ctx->r3) {
        // addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
        goto L_8002ED6C;
    }
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // lui         $s4, 0x1300
    ctx->r20 = S32(0X1300 << 16);
    // lhu         $v0, 0x2C0($s2)
    ctx->r2 = MEM_HU(0X2C0, ctx->r18);
    // addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x7820
    ctx->r2 = ADD32(ctx->r2, 0X7820);
    // addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // addiu       $a1, $zero, 0x24E
    ctx->r5 = ADD32(0, 0X24E);
L_8002EB48:
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
    // lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // addiu       $s1, $s1, 0xF
    ctx->r17 = ADD32(ctx->r17, 0XF);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // lw          $a3, 0x320($s2)
    ctx->r7 = MEM_W(0X320, ctx->r18);
    // jal         0x80027440
    // or          $a0, $a0, $s4
    ctx->r4 = ctx->r4 | ctx->r20;
    sub_80027440(rdram, ctx);
    goto after_3;
    // or          $a0, $a0, $s4
    ctx->r4 = ctx->r4 | ctx->r20;
    after_3:
    // slti        $v0, $s3, 0xE
    ctx->r2 = SIGNED(ctx->r19) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_8002EB48
    if (ctx->r2 != 0) {
        // addiu       $a1, $zero, 0x24E
        ctx->r5 = ADD32(0, 0X24E);
        goto L_8002EB48;
    }
    // addiu       $a1, $zero, 0x24E
    ctx->r5 = ADD32(0, 0X24E);
    // j           L_8002ED6C
    // nop

    goto L_8002ED6C;
    // nop

L_8002EB7C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8002EB80:
    // addiu       $s5, $v0, -0x7076
    ctx->r21 = ADD32(ctx->r2, -0X7076);
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // lui         $s6, 0x300
    ctx->r22 = S32(0X300 << 16);
    // addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
    // addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
L_8002EB94:
    // lhu         $v1, 0x2DC($s2)
    ctx->r3 = MEM_HU(0X2DC, ctx->r18);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_8002EC4C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8002EC4C;
    }
    // nop

    // lh          $v0, 0x25C($s1)
    ctx->r2 = MEM_HS(0X25C, ctx->r17);
    // nop

    // blez        $v0, L_8002EBF4
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $a1, $zero, 0x24E
        ctx->r5 = ADD32(0, 0X24E);
        goto L_8002EBF4;
    }
    // addiu       $a1, $zero, 0x24E
    ctx->r5 = ADD32(0, 0X24E);
    // andi        $s0, $s4, 0xFFFF
    ctx->r16 = ctx->r20 & 0XFFFF;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lh          $a0, 0x1B4($s1)
    ctx->r4 = MEM_HS(0X1B4, ctx->r17);
    // lw          $a3, 0x320($s2)
    ctx->r7 = MEM_W(0X320, ctx->r18);
    // jal         0x80027440
    // or          $a0, $a0, $s6
    ctx->r4 = ctx->r4 | ctx->r22;
    sub_80027440(rdram, ctx);
    goto after_4;
    // or          $a0, $a0, $s6
    ctx->r4 = ctx->r4 | ctx->r22;
    after_4:
    // addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // addiu       $a1, $zero, 0x220
    ctx->r5 = ADD32(0, 0X220);
    // lw          $a3, 0x324($s2)
    ctx->r7 = MEM_W(0X324, ctx->r18);
    // jal         0x80026ECC
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80026ECC(rdram, ctx);
    goto after_5;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_5:
    // addiu       $a1, $zero, 0x1FC
    ctx->r5 = ADD32(0, 0X1FC);
    // lh          $a0, 0x25C($s1)
    ctx->r4 = MEM_HS(0X25C, ctx->r17);
    // lw          $a3, 0x324($s2)
    ctx->r7 = MEM_W(0X324, ctx->r18);
    // j           L_8002EC78
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    goto L_8002EC78;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
L_8002EBF4:
    // bgez        $v0, L_8002EC40
    if (SIGNED(ctx->r2) >= 0) {
        // andi        $s0, $s4, 0xFFFF
        ctx->r16 = ctx->r20 & 0XFFFF;
        goto L_8002EC40;
    }
    // andi        $s0, $s4, 0xFFFF
    ctx->r16 = ctx->r20 & 0XFFFF;
    // addiu       $a1, $zero, 0x24E
    ctx->r5 = ADD32(0, 0X24E);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lh          $a0, 0x1B4($s1)
    ctx->r4 = MEM_HS(0X1B4, ctx->r17);
    // lw          $a3, 0x320($s2)
    ctx->r7 = MEM_W(0X320, ctx->r18);
    // jal         0x80027440
    // or          $a0, $a0, $s6
    ctx->r4 = ctx->r4 | ctx->r22;
    sub_80027440(rdram, ctx);
    goto after_6;
    // or          $a0, $a0, $s6
    ctx->r4 = ctx->r4 | ctx->r22;
    after_6:
    // addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // addiu       $a1, $zero, 0x220
    ctx->r5 = ADD32(0, 0X220);
    // lw          $a3, 0x328($s2)
    ctx->r7 = MEM_W(0X328, ctx->r18);
    // jal         0x80026ECC
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80026ECC(rdram, ctx);
    goto after_7;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_7:
    // addiu       $a1, $zero, 0x1FC
    ctx->r5 = ADD32(0, 0X1FC);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lh          $a0, 0x25C($s1)
    ctx->r4 = MEM_HS(0X25C, ctx->r17);
    // lw          $a3, 0x328($s2)
    ctx->r7 = MEM_W(0X328, ctx->r18);
    // j           L_8002EC78
    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    goto L_8002EC78;
    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_8002EC40:
    // lh          $a0, 0x1B4($s1)
    ctx->r4 = MEM_HS(0X1B4, ctx->r17);
    // j           L_8002EC74
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
    goto L_8002EC74;
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
L_8002EC4C:
    // lh          $v0, 0x0($s5)
    ctx->r2 = MEM_HS(0X0, ctx->r21);
    // nop

    // bgez        $v0, L_8002EC6C
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $a1, $zero, 0x24E
        ctx->r5 = ADD32(0, 0X24E);
        goto L_8002EC6C;
    }
    // addiu       $a1, $zero, 0x24E
    ctx->r5 = ADD32(0, 0X24E);
    // lui         $a0, 0x300
    ctx->r4 = S32(0X300 << 16);
    // lw          $a3, 0x320($s2)
    ctx->r7 = MEM_W(0X320, ctx->r18);
    // j           L_8002EC7C
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
    goto L_8002EC7C;
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
L_8002EC6C:
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
    // lhu         $a0, 0x0($s5)
    ctx->r4 = MEM_HU(0X0, ctx->r21);
L_8002EC74:
    // lw          $a3, 0x320($s2)
    ctx->r7 = MEM_W(0X320, ctx->r18);
L_8002EC78:
    // or          $a0, $a0, $s6
    ctx->r4 = ctx->r4 | ctx->r22;
L_8002EC7C:
    // jal         0x80027440
    // addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    sub_80027440(rdram, ctx);
    goto after_8;
    // addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    after_8:
    // addiu       $s4, $s4, 0xF
    ctx->r20 = ADD32(ctx->r20, 0XF);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // slti        $v0, $s3, 0xE
    ctx->r2 = SIGNED(ctx->r19) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_8002EB94
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
        goto L_8002EB94;
    }
    // addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // addiu       $s1, $zero, 0x1B
    ctx->r17 = ADD32(0, 0X1B);
    // addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
L_8002ECAC:
    // lh          $v1, 0x1B4($s0)
    ctx->r3 = MEM_HS(0X1B4, ctx->r16);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v1, 0x2C4($s2)
    ctx->r3 = MEM_HU(0X2C4, ctx->r18);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_8002ECE4
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002ECE4;
    }
    // nop

    // break       7
    do_break(2147675360);
L_8002ECE4:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8002ECFC
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8002ECFC;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8002ECFC
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8002ECFC;
    }
    // nop

    // break       6
    do_break(2147675384);
L_8002ECFC:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x65
    ctx->r2 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
    // bne         $v0, $zero, L_8002ED24
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
        goto L_8002ED24;
    }
    // addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
L_8002ED24:
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // sh          $s1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r17;
    // addiu       $s1, $s1, 0xF
    ctx->r17 = ADD32(ctx->r17, 0XF);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // lhu         $v0, 0x2C($sp)
    ctx->r2 = MEM_HU(0X2C, ctx->r29);
    // addiu       $v1, $zero, 0x272
    ctx->r3 = ADD32(0, 0X272);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // jal         0x80028DB8
    // sh          $v1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r3;
    sub_80028DB8(rdram, ctx);
    goto after_9;
    // sh          $v1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r3;
    after_9:
    // slti        $v0, $s3, 0xE
    ctx->r2 = SIGNED(ctx->r19) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_8002ECAC
    if (ctx->r2 != 0) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_8002ECAC;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addiu       $a1, $zero, 0x340
    ctx->r5 = ADD32(0, 0X340);
    // jal         0x800286A8
    // addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    sub_800286A8(rdram, ctx);
    goto after_10;
    // addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_10:
L_8002ED6C:
    // lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(0X6C, ctx->r29);
    // lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(0X68, ctx->r29);
    // lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(0X64, ctx->r29);
    // lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(0X60, ctx->r29);
    // lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(0X5C, ctx->r29);
    // lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(0X58, ctx->r29);
    // lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(0X54, ctx->r29);
    // lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(0X50, ctx->r29);
    // addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // jr          $ra
    // nop

    return;
    // nop

;}
