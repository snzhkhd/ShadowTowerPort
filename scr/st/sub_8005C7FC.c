#include "recomp.h"
#include "disable_warnings.h"

void sub_8005C7FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // sw          $ra, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r31;
    // sw          $fp, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r30;
    // sw          $s7, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r22;
    // sw          $s5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r21;
    // sw          $s4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r20;
    // sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // addiu       $v0, $zero, 0x380
    ctx->r2 = ADD32(0, 0X380);
    // addiu       $s0, $zero, 0x1C0
    ctx->r16 = ADD32(0, 0X1C0);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // sh          $s0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r16;
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1F6
    ctx->r2 = ADD32(0, 0X1F6);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1BE
    ctx->r2 = ADD32(0, 0X1BE);
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x230
    ctx->r2 = ADD32(0, 0X230);
    // sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1F2
    ctx->r2 = ADD32(0, 0X1F2);
    // jal         0x80058CC8
    // sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    sub_80058CC8(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    after_0:
    // jal         0x800152D0
    // addiu       $a0, $zero, 0x5400
    ctx->r4 = ADD32(0, 0X5400);
    sub_800152D0(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, 0x5400
    ctx->r4 = ADD32(0, 0X5400);
    after_1:
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sw          $v0, 0x4($at)
    MEM_W(0X4, ctx->r1) = ctx->r2;
    // jal         0x800152D0
    // addiu       $a0, $zero, 0x19F4
    ctx->r4 = ADD32(0, 0X19F4);
    sub_800152D0(rdram, ctx);
    goto after_2;
    // addiu       $a0, $zero, 0x19F4
    ctx->r4 = ADD32(0, 0X19F4);
    after_2:
    // addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // addiu       $a1, $zero, 0x280
    ctx->r5 = ADD32(0, 0X280);
    // addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    // sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x2E0
    ctx->r2 = ADD32(0, 0X2E0);
    // sh          $v0, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x20($s2)
    MEM_H(0X20, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x340
    ctx->r2 = ADD32(0, 0X340);
    // addiu       $v1, $zero, 0x3A0
    ctx->r3 = ADD32(0, 0X3A0);
    // sh          $v0, 0x24($s2)
    MEM_H(0X24, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sh          $v0, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $v0, 0x3E($s2)
    MEM_H(0X3E, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x130
    ctx->r2 = ADD32(0, 0X130);
    // sh          $v0, 0x42($s2)
    MEM_H(0X42, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x160
    ctx->r2 = ADD32(0, 0X160);
    // sh          $v0, 0x46($s2)
    MEM_H(0X46, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
    // sh          $a1, 0x14($s2)
    MEM_H(0X14, ctx->r18) = ctx->r5;
    // sh          $a2, 0x16($s2)
    MEM_H(0X16, ctx->r18) = ctx->r6;
    // sh          $a1, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r5;
    // sh          $a3, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r7;
    // sh          $a2, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r6;
    // sh          $a3, 0x22($s2)
    MEM_H(0X22, ctx->r18) = ctx->r7;
    // sh          $a2, 0x26($s2)
    MEM_H(0X26, ctx->r18) = ctx->r6;
    // sh          $v1, 0x28($s2)
    MEM_H(0X28, ctx->r18) = ctx->r3;
    // sh          $zero, 0x2A($s2)
    MEM_H(0X2A, ctx->r18) = 0;
    // sh          $v1, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r3;
    // sh          $v1, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r3;
    // sh          $v1, 0x34($s2)
    MEM_H(0X34, ctx->r18) = ctx->r3;
    // sh          $a2, 0x36($s2)
    MEM_H(0X36, ctx->r18) = ctx->r6;
    // sh          $v1, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r3;
    // sh          $a3, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r7;
    // sh          $a1, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r5;
    // sh          $a1, 0x40($s2)
    MEM_H(0X40, ctx->r18) = ctx->r5;
    // sh          $a1, 0x44($s2)
    MEM_H(0X44, ctx->r18) = ctx->r5;
    // sh          $a1, 0x48($s2)
    MEM_H(0X48, ctx->r18) = ctx->r5;
    // sh          $v0, 0x4A($s2)
    MEM_H(0X4A, ctx->r18) = ctx->r2;
    // sh          $a1, 0x4C($s2)
    MEM_H(0X4C, ctx->r18) = ctx->r5;
    // sh          $s0, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r16;
    // sh          $a1, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r5;
    // jal         0x800152D0
    // sh          $zero, 0x52($s2)
    MEM_H(0X52, ctx->r18) = 0;
    sub_800152D0(rdram, ctx);
    goto after_3;
    // sh          $zero, 0x52($s2)
    MEM_H(0X52, ctx->r18) = 0;
    after_3:
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $a1, $v1, -0x3150
    ctx->r5 = ADD32(ctx->r3, -0X3150);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
    // addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // sw          $v0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r2;
    // sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
L_8005C964:
    // bne         $s1, $a2, L_8005C978
    if (ctx->r17 != ctx->r6) {
        // nop
    
        goto L_8005C978;
    }
    // nop

    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8005C978:
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // beq         $v0, $zero, L_8005C9B0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005C9B0;
    }
    // nop

    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // nop

    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sh          $v1, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r3;
    // lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(0X8, ctx->r18);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $s3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r19;
L_8005C9B0:
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // slti        $v0, $s3, 0x97
    ctx->r2 = SIGNED(ctx->r19) < 0X97 ? 1 : 0;
    // bne         $v0, $zero, L_8005C964
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8005C964;
    }
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // lui         $a2, 0x6666
    ctx->r6 = S32(0X6666 << 16);
    // lhu         $v1, 0xC($s2)
    ctx->r3 = MEM_HU(0XC, ctx->r18);
    // ori         $a2, $a2, 0x6667
    ctx->r6 = ctx->r6 | 0X6667;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) >> 16;
    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $a0, 0xC($s2)
    ctx->r4 = MEM_HU(0XC, ctx->r18);
    // mfhi        $t1
    ctx->r9 = hi;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4) >> 16;
    // mult        $a1, $a2
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // sra         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9) >> 1;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
    // mfhi        $a2
    ctx->r6 = hi;
    // sra         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6) >> 1;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v1, 0xE($s2)
    ctx->r3 = MEM_HU(0XE, ctx->r18);
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // sh          $a1, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r5;
    // addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // sh          $v1, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r3;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // bgez        $v1, L_8005CA3C
    if (SIGNED(ctx->r3) >= 0) {
        // lui         $s0, 0x8009
        ctx->r16 = S32(0X8009 << 16);
        goto L_8005CA3C;
    }
    // lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // sh          $zero, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = 0;
L_8005CA3C:
    // addiu       $s3, $s0, -0x7378
    ctx->r19 = ADD32(ctx->r16, -0X7378);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // jal         0x80016030
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_80016030(rdram, ctx);
    goto after_4;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_4:
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
    goto after_5;
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    after_5:
    // ori         $a1, $s2, 0x2E6
    ctx->r5 = ctx->r18 | 0X2E6;
    // ori         $a2, $s2, 0x2EA
    ctx->r6 = ctx->r18 | 0X2EA;
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
    goto after_6;
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    after_6:
    // addiu       $s3, $s0, -0x7378
    ctx->r19 = ADD32(ctx->r16, -0X7378);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // jal         0x80016030
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_80016030(rdram, ctx);
    goto after_7;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_7:
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(0X4, ctx->r18);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    sub_80014CFC(rdram, ctx);
    goto after_8;
    // addiu       $a2, $zero, 0x1500
    ctx->r6 = ADD32(0, 0X1500);
    after_8:
    // ori         $a1, $s2, 0x2EE
    ctx->r5 = ctx->r18 | 0X2EE;
    // ori         $a2, $s2, 0x2F2
    ctx->r6 = ctx->r18 | 0X2F2;
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
    goto after_9;
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    after_9:
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
    goto after_10;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_10:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // ori         $a1, $s2, 0x2F6
    ctx->r5 = ctx->r18 | 0X2F6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_11;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_12;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_12:
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_13;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_13:
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
    goto after_14;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_15;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_15:
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // jal         0x80016030
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80016030(rdram, ctx);
    goto after_16;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_16:
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(0X0, ctx->r18);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0x67D
    ctx->r6 = ADD32(0, 0X67D);
    sub_80014CFC(rdram, ctx);
    goto after_17;
    // addiu       $a2, $zero, 0x67D
    ctx->r6 = ADD32(0, 0X67D);
    after_17:
    // addiu       $a0, $s0, -0xA88
    ctx->r4 = ADD32(ctx->r16, -0XA88);
    // sw          $s0, 0xA84($a0)
    MEM_W(0XA84, ctx->r4) = ctx->r16;
    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0x10
    ctx->r2 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_8005CB70
    if (ctx->r2 == 0) {
        // addiu       $s1, $zero, 0xF
        ctx->r17 = ADD32(0, 0XF);
        goto L_8005CB70;
    }
    // addiu       $s1, $zero, 0xF
    ctx->r17 = ADD32(0, 0XF);
    // addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_8005CB70:
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // blez        $s1, L_8005CC60
    if (SIGNED(ctx->r17) <= 0) {
        // addu        $s3, $s4, $zero
        ctx->r19 = ADD32(ctx->r20, 0);
        goto L_8005CC60;
    }
    // addu        $s3, $s4, $zero
    ctx->r19 = ADD32(ctx->r20, 0);
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
L_8005CB80:
    // lhu         $v0, 0x2E2($s2)
    ctx->r2 = MEM_HU(0X2E2, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // addu        $s0, $v1, $s3
    ctx->r16 = ADD32(ctx->r3, ctx->r19);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8005CC50
    if (ctx->r2 == 0) {
        // lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
        goto L_8005CC50;
    }
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x2000
    ctx->r3 = ctx->r3 | 0X2000;
    // addiu       $v0, $s4, 0x2800
    ctx->r2 = ADD32(ctx->r20, 0X2800);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8005CBDC
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8005CBDC;
    }
    // nop

    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_18;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_18:
    // addiu       $v0, $s5, 0xA88
    ctx->r2 = ADD32(ctx->r21, 0XA88);
    // sw          $v0, 0xA84($s5)
    MEM_W(0XA84, ctx->r21) = ctx->r2;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_8005CBDC:
    // lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(0X8, ctx->r18);
    // lw          $a2, 0xA84($s5)
    ctx->r6 = MEM_W(0XA84, ctx->r21);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(0X0, ctx->r2);
    // jal         0x80016030
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    sub_80016030(rdram, ctx);
    goto after_19;
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_19:
    // lui         $v1, 0x8888
    ctx->r3 = S32(0X8888 << 16);
    // ori         $v1, $v1, 0x8889
    ctx->r3 = ctx->r3 | 0X8889;
    // mult        $s0, $v1
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // sra         $a1, $s0, 31
    ctx->r5 = S32(ctx->r16) >> 31;
    // lw          $a0, 0xA84($s5)
    ctx->r4 = MEM_W(0XA84, ctx->r21);
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v1, $t0, $s0
    ctx->r3 = ADD32(ctx->r8, ctx->r16);
    // sra         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) >> 3;
    // subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // sll         $a1, $v1, 4
    ctx->r5 = S32(ctx->r3) << 4;
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // subu        $a1, $s0, $a1
    ctx->r5 = SUB32(ctx->r16, ctx->r5);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // addu        $a1, $s2, $a1
    ctx->r5 = ADD32(ctx->r18, ctx->r5);
    // jal         0x8003EC5C
    // sll         $s0, $v0, 11
    ctx->r16 = S32(ctx->r2) << 11;
    sub_8003EC5C(rdram, ctx);
    goto after_20;
    // sll         $s0, $v0, 11
    ctx->r16 = S32(ctx->r2) << 11;
    after_20:
    // lw          $v0, 0xA84($s5)
    ctx->r2 = MEM_W(0XA84, ctx->r21);
    // addu        $s4, $s4, $s0
    ctx->r20 = ADD32(ctx->r20, ctx->r16);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sw          $v0, 0xA84($s5)
    MEM_W(0XA84, ctx->r21) = ctx->r2;
L_8005CC50:
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // slt         $v0, $s3, $s1
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r17) ? 1 : 0;
    // bne         $v0, $zero, L_8005CB80
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005CB80;
    }
    // nop

L_8005CC60:
    // jal         0x80031CFC
    // lui         $fp, 0x8009
    ctx->r30 = S32(0X8009 << 16);
    sub_80031CFC(rdram, ctx);
    goto after_21;
    // lui         $fp, 0x8009
    ctx->r30 = S32(0X8009 << 16);
    after_21:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_22;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_22:
    // jal         0x800172BC
    // nop

    sub_800172BC(rdram, ctx);
    goto after_23;
    // nop

    after_23:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $v0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r2;
    // jal         0x80057A3C
    // sh          $zero, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = 0;
    sub_80057A3C(rdram, ctx);
    goto after_24;
    // sh          $zero, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = 0;
    after_24:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s6, $v0, -0x2E80
    ctx->r22 = ADD32(ctx->r2, -0X2E80);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $s7, $v0, -0x7E00
    ctx->r23 = ADD32(ctx->r2, -0X7E00);
L_8005CC98:
    // addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // lhu         $v0, 0x2E2($s2)
    ctx->r2 = MEM_HU(0X2E2, ctx->r18);
    // lhu         $v1, 0x2DC($s2)
    ctx->r3 = MEM_HU(0X2DC, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bne         $v1, $t0, L_8005D18C
    if (ctx->r3 != ctx->r8) {
        // sra         $s3, $v0, 16
        ctx->r19 = S32(ctx->r2) >> 16;
        goto L_8005D18C;
    }
    // sra         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2) >> 16;
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // lhu         $v0, 0x2E0($s2)
    ctx->r2 = MEM_HU(0X2E0, ctx->r18);
    // ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t0
    ctx->r8 = hi;
    // sra         $v1, $t0, 1
    ctx->r3 = S32(ctx->r8) >> 1;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4) >> 16;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // lhu         $v0, 0x4($s6)
    ctx->r2 = MEM_HU(0X4, ctx->r22);
    // nop

    // andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // beq         $v0, $zero, L_8005CD14
    if (ctx->r2 == 0) {
        // sra         $s1, $v1, 16
        ctx->r17 = S32(ctx->r3) >> 16;
        goto L_8005CD14;
    }
    // sra         $s1, $v1, 16
    ctx->r17 = S32(ctx->r3) >> 16;
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_25;
    // nop

    after_25:
    // j           L_8005D1EC
    // sh          $zero, 0x4($s6)
    MEM_H(0X4, ctx->r22) = 0;
    goto L_8005D1EC;
    // sh          $zero, 0x4($s6)
    MEM_H(0X4, ctx->r22) = 0;
L_8005CD14:
    // lhu         $v0, 0xC($s6)
    ctx->r2 = MEM_HU(0XC, ctx->r22);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_8005CD4C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005CD4C;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_26;
    // nop

    after_26:
    // slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8005CD4C
    if (ctx->r2 == 0) {
        // sh          $zero, 0xC($s6)
        MEM_H(0XC, ctx->r22) = 0;
        goto L_8005CD4C;
    }
    // sh          $zero, 0xC($s6)
    MEM_H(0XC, ctx->r22) = 0;
    // lhu         $v0, 0x2E0($s2)
    ctx->r2 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
L_8005CD4C:
    // lhu         $v0, 0xC($s6)
    ctx->r2 = MEM_HU(0XC, ctx->r22);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8005CD80
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005CD80;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_27;
    // nop

    after_27:
    // beq         $s0, $zero, L_8005CD80
    if (ctx->r16 == 0) {
        // sh          $zero, 0xC($s6)
        MEM_H(0XC, ctx->r22) = 0;
        goto L_8005CD80;
    }
    // sh          $zero, 0xC($s6)
    MEM_H(0XC, ctx->r22) = 0;
    // lhu         $v0, 0x2E0($s2)
    ctx->r2 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
L_8005CD80:
    // lhu         $v0, 0xC($s6)
    ctx->r2 = MEM_HU(0XC, ctx->r22);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8005CE0C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005CE0C;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_28;
    // nop

    after_28:
    // lhu         $v0, 0x2($s6)
    ctx->r2 = MEM_HU(0X2, ctx->r22);
    // nop

    // andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // beq         $v0, $zero, L_8005CDD4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005CDD4;
    }
    // nop

    // lhu         $v0, 0x2E2($s2)
    ctx->r2 = MEM_HU(0X2E2, ctx->r18);
    // nop

    // addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // sh          $v0, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_8005CE08
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8005CE08;
    }
    // nop

    // j           L_8005CE08
    // sh          $zero, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = 0;
    goto L_8005CE08;
    // sh          $zero, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = 0;
L_8005CDD4:
    // blez        $s1, L_8005CDF0
    if (SIGNED(ctx->r17) <= 0) {
        // nop
    
        goto L_8005CDF0;
    }
    // nop

    // lhu         $v0, 0x2E0($s2)
    ctx->r2 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // addiu       $v0, $v0, -0x5
    ctx->r2 = ADD32(ctx->r2, -0X5);
    // j           L_8005CE08
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
    goto L_8005CE08;
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
L_8005CDF0:
    // lhu         $v1, 0x2E2($s2)
    ctx->r3 = MEM_HU(0X2E2, ctx->r18);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // blez        $v0, L_8005CE08
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_8005CE08;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sh          $v0, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r2;
L_8005CE08:
    // sh          $zero, 0xC($s6)
    MEM_H(0XC, ctx->r22) = 0;
L_8005CE0C:
    // lhu         $v0, 0xC($s6)
    ctx->r2 = MEM_HU(0XC, ctx->r22);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_8005CEEC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005CEEC;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_29;
    // nop

    after_29:
    // lhu         $v0, 0x2($s6)
    ctx->r2 = MEM_HU(0X2, ctx->r22);
    // nop

    // andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // beq         $v0, $zero, L_8005CE90
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005CE90;
    }
    // nop

    // lhu         $v0, 0xE($s2)
    ctx->r2 = MEM_HU(0XE, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_8005CEE8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005CEE8;
    }
    // nop

    // lhu         $v1, 0x2E2($s2)
    ctx->r3 = MEM_HU(0X2E2, ctx->r18);
    // lhu         $a0, 0xE($s2)
    ctx->r4 = MEM_HU(0XE, ctx->r18);
    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // sh          $v1, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r3;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8005CEE8
    if (ctx->r2 == 0) {
        // addiu       $v0, $a0, -0x2
        ctx->r2 = ADD32(ctx->r4, -0X2);
        goto L_8005CEE8;
    }
    // addiu       $v0, $a0, -0x2
    ctx->r2 = ADD32(ctx->r4, -0X2);
    // j           L_8005CEE8
    // sh          $v0, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r2;
    goto L_8005CEE8;
    // sh          $v0, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r2;
L_8005CE90:
    // lhu         $a2, 0x2E2($s2)
    ctx->r6 = MEM_HU(0X2E2, ctx->r18);
    // nop

    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // lhu         $v0, 0xE($s2)
    ctx->r2 = MEM_HU(0XE, ctx->r18);
    // addu        $v1, $a1, $s1
    ctx->r3 = ADD32(ctx->r5, ctx->r17);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v1, $zero, L_8005CEE8
    if (ctx->r3 == 0) {
        // slti        $v0, $s1, 0x2
        ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
        goto L_8005CEE8;
    }
    // slti        $v0, $s1, 0x2
    ctx->r2 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8005CED8
    if (ctx->r2 == 0) {
        // addiu       $v0, $a0, -0x3
        ctx->r2 = ADD32(ctx->r4, -0X3);
        goto L_8005CED8;
    }
    // addiu       $v0, $a0, -0x3
    ctx->r2 = ADD32(ctx->r4, -0X3);
    // lhu         $v0, 0x2E0($s2)
    ctx->r2 = MEM_HU(0X2E0, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // j           L_8005CEE8
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
    goto L_8005CEE8;
    // sh          $v0, 0x2E0($s2)
    MEM_H(0X2E0, ctx->r18) = ctx->r2;
L_8005CED8:
    // slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_8005CEE8
    if (ctx->r2 != 0) {
        // addiu       $v0, $a2, 0x1
        ctx->r2 = ADD32(ctx->r6, 0X1);
        goto L_8005CEE8;
    }
    // addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // sh          $v0, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r2;
L_8005CEE8:
    // sh          $zero, 0xC($s6)
    MEM_H(0XC, ctx->r22) = 0;
L_8005CEEC:
    // lhu         $v0, 0xC($s6)
    ctx->r2 = MEM_HU(0XC, ctx->r22);
    // nop

    // andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // beq         $v0, $zero, L_8005CF2C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005CF2C;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_30;
    // nop

    after_30:
    // sh          $zero, 0xC($s6)
    MEM_H(0XC, ctx->r22) = 0;
    // lhu         $v0, 0x2E2($s2)
    ctx->r2 = MEM_HU(0X2E2, ctx->r18);
    // nop

    // addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // sh          $v0, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_8005CF2C
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8005CF2C;
    }
    // nop

    // sh          $zero, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = 0;
L_8005CF2C:
    // lhu         $v0, 0xC($s6)
    ctx->r2 = MEM_HU(0XC, ctx->r22);
    // nop

    // andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // beq         $v0, $zero, L_8005CF9C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005CF9C;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_31;
    // nop

    after_31:
    // sh          $zero, 0xC($s6)
    MEM_H(0XC, ctx->r22) = 0;
    // lhu         $v0, 0xE($s2)
    ctx->r2 = MEM_HU(0XE, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_8005CF9C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005CF9C;
    }
    // nop

    // lhu         $v1, 0x2E2($s2)
    ctx->r3 = MEM_HU(0X2E2, ctx->r18);
    // lhu         $a0, 0xE($s2)
    ctx->r4 = MEM_HU(0XE, ctx->r18);
    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // sh          $v1, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r3;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8005CF9C
    if (ctx->r2 == 0) {
        // addiu       $v0, $a0, -0x2
        ctx->r2 = ADD32(ctx->r4, -0X2);
        goto L_8005CF9C;
    }
    // addiu       $v0, $a0, -0x2
    ctx->r2 = ADD32(ctx->r4, -0X2);
    // sh          $v0, 0x2E2($s2)
    MEM_H(0X2E2, ctx->r18) = ctx->r2;
L_8005CF9C:
    // lhu         $v0, 0x4($s6)
    ctx->r2 = MEM_HU(0X4, ctx->r22);
    // nop

    // andi        $v0, $v0, 0x5000
    ctx->r2 = ctx->r2 & 0X5000;
    // beq         $v0, $zero, L_8005D05C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005D05C;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_32;
    // nop

    after_32:
    // sh          $zero, 0x4($s6)
    MEM_H(0X4, ctx->r22) = 0;
    // lhu         $v0, 0x2E2($s2)
    ctx->r2 = MEM_HU(0X2E2, ctx->r18);
    // lhu         $v1, 0x2E0($s2)
    ctx->r3 = MEM_HU(0X2E0, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8005D05C
    if (ctx->r2 == 0) {
        // addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
        goto L_8005D05C;
    }
    // addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // beq         $v1, $t0, L_8005D058
    if (ctx->r3 == ctx->r8) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8005D058;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // addiu       $s0, $fp, -0x7378
    ctx->r16 = ADD32(ctx->r30, -0X7378);
    // lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(0X8, ctx->r18);
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(0X0, ctx->r2);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x80016030
    // addiu       $a1, $a1, 0xC8
    ctx->r5 = ADD32(ctx->r5, 0XC8);
    sub_80016030(rdram, ctx);
    goto after_33;
    // addiu       $a1, $a1, 0xC8
    ctx->r5 = ADD32(ctx->r5, 0XC8);
    after_33:
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // addiu       $a1, $s2, 0x50
    ctx->r5 = ADD32(ctx->r18, 0X50);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_34;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_34:
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // lw          $v0, -0x7378($fp)
    ctx->r2 = MEM_W(-0X7378, ctx->r30);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s0, $v0, $s0
    ctx->r16 = ADD32(ctx->r2, ctx->r16);
    // jal         0x8003EC5C
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    sub_8003EC5C(rdram, ctx);
    goto after_35;
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_35:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8005D058:
    // sh          $v0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r2;
L_8005D05C:
    // lhu         $v0, 0x2E2($s2)
    ctx->r2 = MEM_HU(0X2E2, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // beq         $a1, $s3, L_8005D1B4
    if (ctx->r5 == ctx->r19) {
        // slt         $v0, $s3, $a1
        ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r5) ? 1 : 0;
        goto L_8005D1B4;
    }
    // slt         $v0, $s3, $a1
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r5) ? 1 : 0;
    // beq         $v0, $zero, L_8005D094
    if (ctx->r2 == 0) {
        // subu        $v1, $a1, $s3
        ctx->r3 = SUB32(ctx->r5, ctx->r19);
        goto L_8005D094;
    }
    // subu        $v1, $a1, $s3
    ctx->r3 = SUB32(ctx->r5, ctx->r19);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $s5, $v0, $v1
    ctx->r21 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v1, $s3, 0x3
    ctx->r3 = ADD32(ctx->r19, 0X3);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // j           L_8005D0A8
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    goto L_8005D0A8;
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
L_8005D094:
    // subu        $v0, $s3, $a1
    ctx->r2 = SUB32(ctx->r19, ctx->r5);
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $s5, $v1, $v0
    ctx->r21 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // addu        $s1, $v0, $a1
    ctx->r17 = ADD32(ctx->r2, ctx->r5);
L_8005D0A8:
    // addiu       $v0, $s7, 0xA88
    ctx->r2 = ADD32(ctx->r23, 0XA88);
    // sw          $v0, 0xA84($s7)
    MEM_W(0XA84, ctx->r23) = ctx->r2;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // blez        $s5, L_8005D1B4
    if (SIGNED(ctx->r21) <= 0) {
        // addu        $s3, $s4, $zero
        ctx->r19 = ADD32(ctx->r20, 0);
        goto L_8005D1B4;
    }
    // addu        $s3, $s4, $zero
    ctx->r19 = ADD32(ctx->r20, 0);
L_8005D0BC:
    // lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(0XC, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8005D174
    if (ctx->r2 == 0) {
        // lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
        goto L_8005D174;
    }
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x2000
    ctx->r3 = ctx->r3 | 0X2000;
    // addiu       $v0, $s4, 0x2800
    ctx->r2 = ADD32(ctx->r20, 0X2800);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8005D100
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8005D100;
    }
    // nop

    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    DrawSync(rdram, ctx);
    goto after_36;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_36:
    // addiu       $v0, $s7, 0xA88
    ctx->r2 = ADD32(ctx->r23, 0XA88);
    // sw          $v0, 0xA84($s7)
    MEM_W(0XA84, ctx->r23) = ctx->r2;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_8005D100:
    // lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(0X8, ctx->r18);
    // lw          $a2, 0xA84($s7)
    ctx->r6 = MEM_W(0XA84, ctx->r23);
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(0X0, ctx->r2);
    // jal         0x80016030
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    sub_80016030(rdram, ctx);
    goto after_37;
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_37:
    // lui         $v1, 0x8888
    ctx->r3 = S32(0X8888 << 16);
    // ori         $v1, $v1, 0x8889
    ctx->r3 = ctx->r3 | 0X8889;
    // mult        $s1, $v1
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // sra         $a1, $s1, 31
    ctx->r5 = S32(ctx->r17) >> 31;
    // sll         $s0, $v0, 11
    ctx->r16 = S32(ctx->r2) << 11;
    // lw          $a0, 0xA84($s7)
    ctx->r4 = MEM_W(0XA84, ctx->r23);
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v1, $t0, $s1
    ctx->r3 = ADD32(ctx->r8, ctx->r17);
    // sra         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) >> 3;
    // subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // sll         $a1, $v1, 4
    ctx->r5 = S32(ctx->r3) << 4;
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // subu        $a1, $s1, $a1
    ctx->r5 = SUB32(ctx->r17, ctx->r5);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // jal         0x8003EC5C
    // addu        $a1, $s2, $a1
    ctx->r5 = ADD32(ctx->r18, ctx->r5);
    sub_8003EC5C(rdram, ctx);
    goto after_38;
    // addu        $a1, $s2, $a1
    ctx->r5 = ADD32(ctx->r18, ctx->r5);
    after_38:
    // lw          $v0, 0xA84($s7)
    ctx->r2 = MEM_W(0XA84, ctx->r23);
    // addu        $s4, $s4, $s0
    ctx->r20 = ADD32(ctx->r20, ctx->r16);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sw          $v0, 0xA84($s7)
    MEM_W(0XA84, ctx->r23) = ctx->r2;
L_8005D174:
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // slt         $v0, $s3, $s5
    ctx->r2 = SIGNED(ctx->r19) < SIGNED(ctx->r21) ? 1 : 0;
    // bne         $v0, $zero, L_8005D0BC
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8005D0BC;
    }
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // j           L_8005D1B4
    // nop

    goto L_8005D1B4;
    // nop

L_8005D18C:
    // lhu         $v0, 0x4($s6)
    ctx->r2 = MEM_HU(0X4, ctx->r22);
    // nop

    // andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // beq         $v0, $zero, L_8005D1B4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005D1B4;
    }
    // nop

    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_39;
    // nop

    after_39:
    // sh          $zero, 0x4($s6)
    MEM_H(0X4, ctx->r22) = 0;
    // addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // sh          $t0, 0x2DC($s2)
    MEM_H(0X2DC, ctx->r18) = ctx->r8;
L_8005D1B4:
    // jal         0x800164B4
    // nop

    sub_800164B4(rdram, ctx);
    goto after_40;
    // nop

    after_40:
    // jal         0x80030AB8
    // nop

    sub_80030AB8(rdram, ctx);
    goto after_41;
    // nop

    after_41:
    // lbu         $a0, 0x2E4($s2)
    ctx->r4 = MEM_BU(0X2E4, ctx->r18);
    // nop

    // addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // bgez        $v1, L_8005D1DC
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8005D1DC;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_8005D1DC:
    // andi        $v0, $v0, 0x1E0
    ctx->r2 = ctx->r2 & 0X1E0;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // j           L_8005CC98
    // sb          $v0, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = ctx->r2;
    goto L_8005CC98;
    // sb          $v0, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = ctx->r2;
L_8005D1EC:
    // lw          $a0, 0x4($s2)
    ctx->r4 = MEM_W(0X4, ctx->r18);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_42;
    // nop

    after_42:
    // lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(0X8, ctx->r18);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_43;
    // nop

    after_43:
    // lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(0X0, ctx->r18);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_44;
    // nop

    after_44:
    // jal         0x80058C4C
    // nop

    sub_80058C4C(rdram, ctx);
    goto after_45;
    // nop

    after_45:
    // jal         0x80058D30
    // nop

    sub_80058D30(rdram, ctx);
    goto after_46;
    // nop

    after_46:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_47;
    // nop

    after_47:
    // lw          $ra, 0x94($sp)
    ctx->r31 = MEM_W(0X94, ctx->r29);
    // lw          $fp, 0x90($sp)
    ctx->r30 = MEM_W(0X90, ctx->r29);
    // lw          $s7, 0x8C($sp)
    ctx->r23 = MEM_W(0X8C, ctx->r29);
    // lw          $s6, 0x88($sp)
    ctx->r22 = MEM_W(0X88, ctx->r29);
    // lw          $s5, 0x84($sp)
    ctx->r21 = MEM_W(0X84, ctx->r29);
    // lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(0X80, ctx->r29);
    // lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(0X7C, ctx->r29);
    // lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(0X78, ctx->r29);
    // lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(0X74, ctx->r29);
    // lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(0X70, ctx->r29);
    // addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // jr          $ra
    // nop

    return;
    // nop

;}
