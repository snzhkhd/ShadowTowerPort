#include "recomp.h"
#include "disable_warnings.h"

void sub_8002A5A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // jal         0x800174C4
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    ST_BeginDraw2D(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    after_0:
    // addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xD50
    ctx->r2 = ADD32(ctx->r2, 0XD50);
    // lui         $t0, 0x1F80
    ctx->r8 = S32(0X1F80 << 16);
    // ori         $t0, $t0, 0x33C
    ctx->r8 = ctx->r8 | 0X33C;
    // sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // lui         $t0, 0x1F80
    ctx->r8 = S32(0X1F80 << 16);
    // ori         $t0, $t0, 0x358
    ctx->r8 = ctx->r8 | 0X358;
    // sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // lui         $t0, 0x1F80
    ctx->r8 = S32(0X1F80 << 16);
    // ori         $t0, $t0, 0x35C
    ctx->r8 = ctx->r8 | 0X35C;
    // lui         $s6, 0x1F80
    ctx->r22 = S32(0X1F80 << 16);
    // sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // addiu       $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
    // addu        $fp, $v0, $zero
    ctx->r30 = ADD32(ctx->r2, 0);
    // addu        $s3, $s6, $zero
    ctx->r19 = ADD32(ctx->r22, 0);
    // addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // sb          $v0, 0x310($s3)
    MEM_B(0X310, ctx->r19) = ctx->r2;
    // sb          $v0, 0x300($s3)
    MEM_B(0X300, ctx->r19) = ctx->r2;
    // sb          $v0, 0x311($s3)
    MEM_B(0X311, ctx->r19) = ctx->r2;
    // sb          $v0, 0x301($s3)
    MEM_B(0X301, ctx->r19) = ctx->r2;
    // sb          $v0, 0x312($s3)
    MEM_B(0X312, ctx->r19) = ctx->r2;
    // sb          $v0, 0x302($s3)
    MEM_B(0X302, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x62
    ctx->r2 = ADD32(0, 0X62);
    // sb          $v0, 0x318($s3)
    MEM_B(0X318, ctx->r19) = ctx->r2;
    // sb          $v0, 0x308($s3)
    MEM_B(0X308, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
    // sb          $v0, 0x319($s3)
    MEM_B(0X319, ctx->r19) = ctx->r2;
    // sb          $v0, 0x309($s3)
    MEM_B(0X309, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sb          $v0, 0x31A($s3)
    MEM_B(0X31A, ctx->r19) = ctx->r2;
    // sb          $v0, 0x30A($s3)
    MEM_B(0X30A, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    // sb          $v0, 0x30B($s3)
    MEM_B(0X30B, ctx->r19) = ctx->r2;
    // sb          $v0, 0x303($s3)
    MEM_B(0X303, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x29
    ctx->r2 = ADD32(0, 0X29);
    // sb          $v0, 0x31B($s3)
    MEM_B(0X31B, ctx->r19) = ctx->r2;
    // sb          $v0, 0x313($s3)
    MEM_B(0X313, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // sh          $v0, 0x33E($s3)
    MEM_H(0X33E, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // sh          $v0, 0x340($s3)
    MEM_H(0X340, ctx->r19) = ctx->r2;
    // sh          $v0, 0x342($s3)
    MEM_H(0X342, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x255
    ctx->r2 = ADD32(0, 0X255);
    // sh          $v0, 0x358($s3)
    MEM_H(0X358, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x1B1
    ctx->r2 = ADD32(0, 0X1B1);
    // sh          $v0, 0x35A($s3)
    MEM_H(0X35A, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x35C($s3)
    MEM_H(0X35C, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x1F6
    ctx->r2 = ADD32(0, 0X1F6);
    // sh          $v0, 0x35E($s3)
    MEM_H(0X35E, ctx->r19) = ctx->r2;
L_8002A6A4:
    // lhu         $v0, 0x22($s3)
    ctx->r2 = MEM_HU(0X22, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $s7, L_8002A6C8
    if (ctx->r2 != ctx->r23) {
        // addiu       $s2, $s3, 0x300
        ctx->r18 = ADD32(ctx->r19, 0X300);
        goto L_8002A6C8;
    }
    // addiu       $s2, $s3, 0x300
    ctx->r18 = ADD32(ctx->r19, 0X300);
    // addiu       $s2, $s3, 0x308
    ctx->r18 = ADD32(ctx->r19, 0X308);
    // j           L_8002A6CC
    // addiu       $s5, $s3, 0x318
    ctx->r21 = ADD32(ctx->r19, 0X318);
    goto L_8002A6CC;
    // addiu       $s5, $s3, 0x318
    ctx->r21 = ADD32(ctx->r19, 0X318);
L_8002A6C8:
    // addiu       $s5, $s3, 0x310
    ctx->r21 = ADD32(ctx->r19, 0X310);
L_8002A6CC:
    // lhu         $v0, 0x22($s3)
    ctx->r2 = MEM_HU(0X22, ctx->r19);
    // addiu       $v1, $s7, 0x7
    ctx->r3 = ADD32(ctx->r23, 0X7);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_8002A6F0
    if (ctx->r2 != ctx->r3) {
        // addiu       $s1, $s3, 0x300
        ctx->r17 = ADD32(ctx->r19, 0X300);
        goto L_8002A6F0;
    }
    // addiu       $s1, $s3, 0x300
    ctx->r17 = ADD32(ctx->r19, 0X300);
    // addiu       $s1, $s3, 0x308
    ctx->r17 = ADD32(ctx->r19, 0X308);
    // j           L_8002A6F4
    // addiu       $s4, $s3, 0x318
    ctx->r20 = ADD32(ctx->r19, 0X318);
    goto L_8002A6F4;
    // addiu       $s4, $s3, 0x318
    ctx->r20 = ADD32(ctx->r19, 0X318);
L_8002A6F0:
    // addiu       $s4, $s3, 0x310
    ctx->r20 = ADD32(ctx->r19, 0X310);
L_8002A6F4:
    // addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // lhu         $s0, 0x24($sp)
    ctx->r16 = MEM_HU(0X24, ctx->r29);
    // lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(0X24, ctx->r29);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
    // sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // lhu         $a0, 0x424($fp)
    ctx->r4 = MEM_HU(0X424, ctx->r30);
    // addiu       $t0, $t0, 0x1950
    ctx->r8 = ADD32(ctx->r8, 0X1950);
    // jal         0x8002732C
    // addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    sub_8002732C(rdram, ctx);
    goto after_1;
    // addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    after_1:
    // addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // lhu         $a0, 0x432($fp)
    ctx->r4 = MEM_HU(0X432, ctx->r30);
    // addiu       $fp, $fp, 0x2
    ctx->r30 = ADD32(ctx->r30, 0X2);
    // lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // addiu       $t0, $t0, 0x1950
    ctx->r8 = ADD32(ctx->r8, 0X1950);
    // jal         0x8002732C
    // addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    sub_8002732C(rdram, ctx);
    goto after_2;
    // addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    after_2:
    // addiu       $a1, $zero, 0x6C
    ctx->r5 = ADD32(0, 0X6C);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // lh          $a0, 0x24($s6)
    ctx->r4 = MEM_HS(0X24, ctx->r22);
    // lh          $v0, 0x40($s6)
    ctx->r2 = MEM_HS(0X40, ctx->r22);
    // lui         $t0, 0x300
    ctx->r8 = S32(0X300 << 16);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // jal         0x80027440
    // or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    sub_80027440(rdram, ctx);
    goto after_3;
    // or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    after_3:
    // addiu       $a1, $zero, 0xE8
    ctx->r5 = ADD32(0, 0XE8);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // lh          $a0, 0x32($s6)
    ctx->r4 = MEM_HS(0X32, ctx->r22);
    // lh          $v0, 0x4E($s6)
    ctx->r2 = MEM_HS(0X4E, ctx->r22);
    // lui         $t0, 0x300
    ctx->r8 = S32(0X300 << 16);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // jal         0x80027440
    // or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    sub_80027440(rdram, ctx);
    goto after_4;
    // or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    after_4:
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // addiu       $v0, $zero, 0x8D
    ctx->r2 = ADD32(0, 0X8D);
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(0X1C, ctx->r29);
    // lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(0X20, ctx->r29);
    // addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // sh          $v0, 0x33C($s3)
    MEM_H(0X33C, ctx->r19) = ctx->r2;
    // jal         0x80028364
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    sub_80028364(rdram, ctx);
    goto after_5;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_5:
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(0X1C, ctx->r29);
    // lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(0X20, ctx->r29);
    // addiu       $v0, $zero, 0x109
    ctx->r2 = ADD32(0, 0X109);
    // sh          $v0, 0x33C($s3)
    MEM_H(0X33C, ctx->r19) = ctx->r2;
    // jal         0x80028364
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    sub_80028364(rdram, ctx);
    goto after_6;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_6:
    // lhu         $v0, 0x33E($s3)
    ctx->r2 = MEM_HU(0X33E, ctx->r19);
    // nop

    // addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // sh          $v0, 0x33E($s3)
    MEM_H(0X33E, ctx->r19) = ctx->r2;
    // slti        $v0, $s7, 0x7
    ctx->r2 = SIGNED(ctx->r23) < 0X7 ? 1 : 0;
    // bne         $v0, $zero, L_8002A6A4
    if (ctx->r2 != 0) {
        // addiu       $s6, $s6, 0x2
        ctx->r22 = ADD32(ctx->r22, 0X2);
        goto L_8002A6A4;
    }
    // addiu       $s6, $s6, 0x2
    ctx->r22 = ADD32(ctx->r22, 0X2);
    // addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // ori         $a3, $s3, 0x300
    ctx->r7 = ctx->r19 | 0X300;
    // addiu       $v0, $zero, 0x48
    ctx->r2 = ADD32(0, 0X48);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // sb          $v0, 0x310($s3)
    MEM_B(0X310, ctx->r19) = ctx->r2;
    // sb          $v0, 0x300($s3)
    MEM_B(0X300, ctx->r19) = ctx->r2;
    // sb          $v0, 0x311($s3)
    MEM_B(0X311, ctx->r19) = ctx->r2;
    // sb          $v0, 0x301($s3)
    MEM_B(0X301, ctx->r19) = ctx->r2;
    // sb          $v0, 0x312($s3)
    MEM_B(0X312, ctx->r19) = ctx->r2;
    // sb          $v0, 0x302($s3)
    MEM_B(0X302, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x440($a0)
    ctx->r2 = MEM_HU(0X440, ctx->r4);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_7;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_7:
    // addiu       $a1, $zero, 0xF2
    ctx->r5 = ADD32(0, 0XF2);
    // addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // ori         $a3, $s3, 0x310
    ctx->r7 = ctx->r19 | 0X310;
    // lhu         $a0, 0x20($s3)
    ctx->r4 = MEM_HU(0X20, ctx->r19);
    // lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // jal         0x80027440
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    sub_80027440(rdram, ctx);
    goto after_8;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    after_8:
    // addiu       $s2, $s3, 0x33C
    ctx->r18 = ADD32(ctx->r19, 0X33C);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addiu       $s1, $s3, 0x358
    ctx->r17 = ADD32(ctx->r19, 0X358);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addiu       $s0, $s3, 0x35C
    ctx->r16 = ADD32(ctx->r19, 0X35C);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x35C($s3)
    MEM_H(0X35C, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x1FF
    ctx->r2 = ADD32(0, 0X1FF);
    // sh          $v0, 0x35E($s3)
    MEM_H(0X35E, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // sh          $v0, 0x33C($s3)
    MEM_H(0X33C, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // sh          $v0, 0x33E($s3)
    MEM_H(0X33E, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x4C
    ctx->r2 = ADD32(0, 0X4C);
    // sh          $v0, 0x340($s3)
    MEM_H(0X340, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x342($s3)
    MEM_H(0X342, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x26D
    ctx->r2 = ADD32(0, 0X26D);
    // sh          $v0, 0x358($s3)
    MEM_H(0X358, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x1E0
    ctx->r2 = ADD32(0, 0X1E0);
    // sh          $v0, 0x35A($s3)
    MEM_H(0X35A, ctx->r19) = ctx->r2;
    // jal         0x80028364
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    sub_80028364(rdram, ctx);
    goto after_9;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_9:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x279
    ctx->r2 = ADD32(0, 0X279);
    // sh          $v0, 0x358($s3)
    MEM_H(0X358, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // sh          $v0, 0x35A($s3)
    MEM_H(0X35A, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sh          $v0, 0x33C($s3)
    MEM_H(0X33C, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // sh          $v0, 0x340($s3)
    MEM_H(0X340, ctx->r19) = ctx->r2;
    // jal         0x80028364
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    sub_80028364(rdram, ctx);
    goto after_10;
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_10:
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
    goto after_11;
    // addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    after_11:
    // jal         0x800175A4
    // nop

    sub_800175A4(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // jal         0x8002948C
    // nop

    sub_8002948C(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // jal         0x80017634
    // nop

    sub_80017634(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(0X4C, ctx->r29);
    // lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(0X48, ctx->r29);
    // lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(0X44, ctx->r29);
    // lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(0X40, ctx->r29);
    // lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(0X3C, ctx->r29);
    // lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
