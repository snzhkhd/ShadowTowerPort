#include "recomp.h"
#include "disable_warnings.h"

void sub_8002ED98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xD50
    ctx->r2 = ADD32(ctx->r2, 0XD50);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addiu       $s3, $v0, 0xC00
    ctx->r19 = ADD32(ctx->r2, 0XC00);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // lui         $s5, 0x1F80
    ctx->r21 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // addiu       $v1, $zero, 0x30
    ctx->r3 = ADD32(0, 0X30);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sb          $v0, 0x318($s5)
    MEM_B(0X318, ctx->r21) = ctx->r2;
    // sb          $v0, 0x31C($s5)
    MEM_B(0X31C, ctx->r21) = ctx->r2;
    // sb          $v0, 0x31D($s5)
    MEM_B(0X31D, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sb          $v0, 0x31E($s5)
    MEM_B(0X31E, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
    // sb          $v1, 0x319($s5)
    MEM_B(0X319, ctx->r21) = ctx->r3;
    // sb          $v1, 0x31A($s5)
    MEM_B(0X31A, ctx->r21) = ctx->r3;
    // sb          $v0, 0x31F($s5)
    MEM_B(0X31F, ctx->r21) = ctx->r2;
    // sb          $v0, 0x31B($s5)
    MEM_B(0X31B, ctx->r21) = ctx->r2;
    // addiu       $a1, $zero, 0x13C
    ctx->r5 = ADD32(0, 0X13C);
L_8002EE0C:
    // andi        $a2, $s1, 0xFFFF
    ctx->r6 = ctx->r17 & 0XFFFF;
    // addiu       $a3, $s5, 0x300
    ctx->r7 = ADD32(ctx->r21, 0X300);
    // addiu       $s1, $s1, 0xF
    ctx->r17 = ADD32(ctx->r17, 0XF);
    // lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(0X0, ctx->r16);
    // addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // jal         0x8002732C
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    sub_8002732C(rdram, ctx);
    goto after_0;
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    after_0:
    // slti        $v0, $s2, 0xE
    ctx->r2 = SIGNED(ctx->r18) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_8002EE0C
    if (ctx->r2 != 0) {
        // addiu       $a1, $zero, 0x13C
        ctx->r5 = ADD32(0, 0X13C);
        goto L_8002EE0C;
    }
    // addiu       $a1, $zero, 0x13C
    ctx->r5 = ADD32(0, 0X13C);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s3, $v0, -0x70D8
    ctx->r19 = ADD32(ctx->r2, -0X70D8);
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // lui         $s4, 0x500
    ctx->r20 = S32(0X500 << 16);
    // addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
L_8002EE4C:
    // lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(0X0, ctx->r19);
    // lh          $a1, 0x2($s3)
    ctx->r5 = MEM_HS(0X2, ctx->r19);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // sra         $a0, $v0, 31
    ctx->r4 = S32(ctx->r2) >> 31;
    // subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8002EEA4
    if (ctx->r2 != 0) {
        // addiu       $v0, $s5, 0x31C
        ctx->r2 = ADD32(ctx->r21, 0X31C);
        goto L_8002EEA4;
    }
    // addiu       $v0, $s5, 0x31C
    ctx->r2 = ADD32(ctx->r21, 0X31C);
    // lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9) >> 1;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8002EEA4
    if (ctx->r2 != 0) {
        // addiu       $v0, $s5, 0x318
        ctx->r2 = ADD32(ctx->r21, 0X318);
        goto L_8002EEA4;
    }
    // addiu       $v0, $s5, 0x318
    ctx->r2 = ADD32(ctx->r21, 0X318);
    // addiu       $v0, $s5, 0x310
    ctx->r2 = ADD32(ctx->r21, 0X310);
L_8002EEA4:
    // sw          $v0, 0x320($s5)
    MEM_W(0X320, ctx->r21) = ctx->r2;
    // lhu         $a0, 0x0($s3)
    ctx->r4 = MEM_HU(0X0, ctx->r19);
    // addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // addiu       $a1, $zero, 0x236
    ctx->r5 = ADD32(0, 0X236);
    // andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addiu       $s1, $s1, 0xF
    ctx->r17 = ADD32(ctx->r17, 0XF);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // lw          $a3, 0x320($s5)
    ctx->r7 = MEM_W(0X320, ctx->r21);
    // jal         0x80027440
    // or          $a0, $a0, $s4
    ctx->r4 = ctx->r4 | ctx->r20;
    sub_80027440(rdram, ctx);
    goto after_1;
    // or          $a0, $a0, $s4
    ctx->r4 = ctx->r4 | ctx->r20;
    after_1:
    // addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // addiu       $a1, $zero, 0x22A
    ctx->r5 = ADD32(0, 0X22A);
    // lw          $a3, 0x320($s5)
    ctx->r7 = MEM_W(0X320, ctx->r21);
    // jal         0x80026ECC
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80026ECC(rdram, ctx);
    goto after_2;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // lhu         $a0, 0x0($s3)
    ctx->r4 = MEM_HU(0X0, ctx->r19);
    // addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // addiu       $a1, $zero, 0x1EE
    ctx->r5 = ADD32(0, 0X1EE);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lw          $a3, 0x320($s5)
    ctx->r7 = MEM_W(0X320, ctx->r21);
    // jal         0x80027440
    // or          $a0, $a0, $s4
    ctx->r4 = ctx->r4 | ctx->r20;
    sub_80027440(rdram, ctx);
    goto after_3;
    // or          $a0, $a0, $s4
    ctx->r4 = ctx->r4 | ctx->r20;
    after_3:
    // slti        $v0, $s2, 0x2
    ctx->r2 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8002EE4C
    if (ctx->r2 != 0) {
        // addiu       $a1, $zero, 0x21E
        ctx->r5 = ADD32(0, 0X21E);
        goto L_8002EE4C;
    }
    // addiu       $a1, $zero, 0x21E
    ctx->r5 = ADD32(0, 0X21E);
    // addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // lhu         $a0, 0x0($s3)
    ctx->r4 = MEM_HU(0X0, ctx->r19);
    // addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    // addiu       $s0, $s5, 0x310
    ctx->r16 = ADD32(ctx->r21, 0X310);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // lui         $s6, 0x300
    ctx->r22 = S32(0X300 << 16);
    // addiu       $s4, $zero, 0x3D
    ctx->r20 = ADD32(0, 0X3D);
    // addu        $s1, $s6, $zero
    ctx->r17 = ADD32(ctx->r22, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_80027440(rdram, ctx);
    goto after_4;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_4:
    // addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // addiu       $a1, $zero, 0x242
    ctx->r5 = ADD32(0, 0X242);
    // addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    // jal         0x80026ECC
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sub_80026ECC(rdram, ctx);
    goto after_5;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_5:
    // lhu         $a0, 0x0($s3)
    ctx->r4 = MEM_HU(0X0, ctx->r19);
    // addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // addiu       $a1, $zero, 0x24E
    ctx->r5 = ADD32(0, 0X24E);
    // addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_80027440(rdram, ctx);
    goto after_6;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_6:
L_8002EF6C:
    // lhu         $a0, 0x0($s3)
    ctx->r4 = MEM_HU(0X0, ctx->r19);
    // addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // addiu       $a1, $zero, 0x24E
    ctx->r5 = ADD32(0, 0X24E);
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
    // addiu       $a3, $s5, 0x310
    ctx->r7 = ADD32(ctx->r21, 0X310);
    // addiu       $s4, $s4, 0xF
    ctx->r20 = ADD32(ctx->r20, 0XF);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // jal         0x80027440
    // or          $a0, $a0, $s6
    ctx->r4 = ctx->r4 | ctx->r22;
    sub_80027440(rdram, ctx);
    goto after_7;
    // or          $a0, $a0, $s6
    ctx->r4 = ctx->r4 | ctx->r22;
    after_7:
    // slti        $v0, $s2, 0xD
    ctx->r2 = SIGNED(ctx->r18) < 0XD ? 1 : 0;
    // bne         $v0, $zero, L_8002EF6C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8002EF6C;
    }
    // nop

    // lui         $a0, 0x6666
    ctx->r4 = S32(0X6666 << 16);
    // lhu         $a1, 0x0($s3)
    ctx->r5 = MEM_HU(0X0, ctx->r19);
    // ori         $a0, $a0, 0x6667
    ctx->r4 = ctx->r4 | 0X6667;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) >> 16;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v1, 0x2($s3)
    ctx->r3 = MEM_HU(0X2, ctx->r19);
    // mfhi        $a2
    ctx->r6 = hi;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) >> 16;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $a1, $a1, 31
    ctx->r5 = S32(ctx->r5) >> 31;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // sra         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6) >> 2;
    // subu        $a0, $a0, $a1
    ctx->r4 = SUB32(ctx->r4, ctx->r5);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // mfhi        $v0
    ctx->r2 = hi;
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_8002EFFC
    if (ctx->r2 != 0) {
        // addiu       $v0, $s5, 0x318
        ctx->r2 = ADD32(ctx->r21, 0X318);
        goto L_8002EFFC;
    }
    // addiu       $v0, $s5, 0x318
    ctx->r2 = ADD32(ctx->r21, 0X318);
    // addiu       $v0, $s5, 0x310
    ctx->r2 = ADD32(ctx->r21, 0X310);
L_8002EFFC:
    // sw          $v0, 0x320($s5)
    MEM_W(0X320, ctx->r21) = ctx->r2;
    // lui         $s0, 0x2416
    ctx->r16 = S32(0X2416 << 16);
    // lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(0X0, ctx->r19);
    // ori         $s0, $s0, 0x8E19
    ctx->r16 = ctx->r16 | 0X8E19;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // mult        $a0, $s0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2) << 5;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // mult        $v1, $s0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $zero, 0x1EE
    ctx->r5 = ADD32(0, 0X1EE);
    // addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    // lui         $s2, 0x300
    ctx->r18 = S32(0X300 << 16);
    // lw          $a3, 0x320($s5)
    ctx->r7 = MEM_W(0X320, ctx->r21);
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // sra         $v0, $t0, 6
    ctx->r2 = S32(ctx->r8) >> 6;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E62($at)
    MEM_H(-0X7E62, ctx->r1) = ctx->r2;
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // lhu         $a0, -0x7E62($a0)
    ctx->r4 = MEM_HU(-0X7E62, ctx->r4);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v0, $t2, 6
    ctx->r2 = S32(ctx->r10) >> 6;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E78($at)
    MEM_H(-0X7E78, ctx->r1) = ctx->r2;
    // jal         0x80027440
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    sub_80027440(rdram, ctx);
    goto after_8;
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    after_8:
    // addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // addiu       $a1, $zero, 0x216
    ctx->r5 = ADD32(0, 0X216);
    // lw          $a3, 0x320($s5)
    ctx->r7 = MEM_W(0X320, ctx->r21);
    // jal         0x80026ECC
    // addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    sub_80026ECC(rdram, ctx);
    goto after_9;
    // addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    after_9:
    // addiu       $a1, $zero, 0x21E
    ctx->r5 = ADD32(0, 0X21E);
    // addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    // lui         $s1, 0x100
    ctx->r17 = S32(0X100 << 16);
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E62($v1)
    ctx->r3 = MEM_HU(-0X7E62, ctx->r3);
    // lw          $a3, 0x320($s5)
    ctx->r7 = MEM_W(0X320, ctx->r21);
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // lhu         $a0, -0x7E78($a0)
    ctx->r4 = MEM_HU(-0X7E78, ctx->r4);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // jal         0x80027440
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_80027440(rdram, ctx);
    goto after_10;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_10:
    // addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // addiu       $a1, $zero, 0x22A
    ctx->r5 = ADD32(0, 0X22A);
    // lw          $a3, 0x320($s5)
    ctx->r7 = MEM_W(0X320, ctx->r21);
    // jal         0x80026ECC
    // addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    sub_80026ECC(rdram, ctx);
    goto after_11;
    // addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    after_11:
    // lh          $v0, 0x0($s3)
    ctx->r2 = MEM_HS(0X0, ctx->r19);
    // nop

    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // mult        $a0, $s0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2) << 5;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // mult        $v1, $s0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $zero, 0x236
    ctx->r5 = ADD32(0, 0X236);
    // addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    // lw          $a3, 0x320($s5)
    ctx->r7 = MEM_W(0X320, ctx->r21);
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // sra         $v0, $t0, 6
    ctx->r2 = S32(ctx->r8) >> 6;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E62($at)
    MEM_H(-0X7E62, ctx->r1) = ctx->r2;
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // lhu         $a0, -0x7E62($a0)
    ctx->r4 = MEM_HU(-0X7E62, ctx->r4);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v0, $t2, 6
    ctx->r2 = S32(ctx->r10) >> 6;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E78($at)
    MEM_H(-0X7E78, ctx->r1) = ctx->r2;
    // jal         0x80027440
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    sub_80027440(rdram, ctx);
    goto after_12;
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    after_12:
    // addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // addiu       $a1, $zero, 0x25E
    ctx->r5 = ADD32(0, 0X25E);
    // lw          $a3, 0x320($s5)
    ctx->r7 = MEM_W(0X320, ctx->r21);
    // jal         0x80026ECC
    // addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    sub_80026ECC(rdram, ctx);
    goto after_13;
    // addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    after_13:
    // addiu       $a1, $zero, 0x266
    ctx->r5 = ADD32(0, 0X266);
    // addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E62($v1)
    ctx->r3 = MEM_HU(-0X7E62, ctx->r3);
    // lw          $a3, 0x320($s5)
    ctx->r7 = MEM_W(0X320, ctx->r21);
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // lhu         $a0, -0x7E78($a0)
    ctx->r4 = MEM_HU(-0X7E78, ctx->r4);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // jal         0x80027440
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    sub_80027440(rdram, ctx);
    goto after_14;
    // or          $a0, $a0, $s1
    ctx->r4 = ctx->r4 | ctx->r17;
    after_14:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
    // lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
