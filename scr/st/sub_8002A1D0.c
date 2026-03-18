#include "recomp.h"
#include "disable_warnings.h"

void sub_8002A1D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // lui         $s5, 0x1F80
    ctx->r21 = S32(0X1F80 << 16);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lhu         $v0, 0x2E2($s5)
    ctx->r2 = MEM_HU(0X2E2, ctx->r21);
    // lhu         $v1, 0x2E0($s5)
    ctx->r3 = MEM_HU(0X2E0, ctx->r21);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x1C($s5)
    ctx->r3 = MEM_W(0X1C, ctx->r21);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $s0, 0x0($v0)
    ctx->r16 = MEM_HS(0X0, ctx->r2);
    // jal         0x800174C4
    // nop

    sub_800174C4(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addiu       $v0, $zero, 0x48
    ctx->r2 = ADD32(0, 0X48);
    // sb          $v0, 0x310($s5)
    MEM_B(0X310, ctx->r21) = ctx->r2;
    // sb          $v0, 0x300($s5)
    MEM_B(0X300, ctx->r21) = ctx->r2;
    // sb          $v0, 0x311($s5)
    MEM_B(0X311, ctx->r21) = ctx->r2;
    // sb          $v0, 0x301($s5)
    MEM_B(0X301, ctx->r21) = ctx->r2;
    // sb          $v0, 0x312($s5)
    MEM_B(0X312, ctx->r21) = ctx->r2;
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
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sb          $v0, 0x30A($s5)
    MEM_B(0X30A, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    // sb          $v0, 0x30B($s5)
    MEM_B(0X30B, ctx->r21) = ctx->r2;
    // sb          $v0, 0x303($s5)
    MEM_B(0X303, ctx->r21) = ctx->r2;
    // lbu         $v0, 0x2E4($s5)
    ctx->r2 = MEM_BU(0X2E4, ctx->r21);
    // addiu       $v1, $zero, 0x29
    ctx->r3 = ADD32(0, 0X29);
    // sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_8002A290
    if (ctx->r2 == 0) {
        // sb          $v1, 0x313($s5)
        MEM_B(0X313, ctx->r21) = ctx->r3;
        goto L_8002A290;
    }
    // sb          $v1, 0x313($s5)
    MEM_B(0X313, ctx->r21) = ctx->r3;
    // lbu         $v1, 0x2E4($s5)
    ctx->r3 = MEM_BU(0X2E4, ctx->r21);
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // j           L_8002A29C
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_8002A29C;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8002A290:
    // lbu         $v0, 0x2E4($s5)
    ctx->r2 = MEM_BU(0X2E4, ctx->r21);
    // nop

    // addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
L_8002A29C:
    // sh          $v0, 0x360($s5)
    MEM_H(0X360, ctx->r21) = ctx->r2;
    // ori         $a0, $s5, 0x330
    ctx->r4 = ctx->r21 | 0X330;
    // ori         $a1, $s5, 0x32C
    ctx->r5 = ctx->r21 | 0X32C;
    // addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
    // sh          $v0, 0x330($s5)
    MEM_H(0X330, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x114
    ctx->r2 = ADD32(0, 0X114);
    // sh          $v0, 0x334($s5)
    MEM_H(0X334, ctx->r21) = ctx->r2;
    // lbu         $v0, 0x360($s5)
    ctx->r2 = MEM_BU(0X360, ctx->r21);
    // lbu         $t0, 0x360($s5)
    ctx->r8 = MEM_BU(0X360, ctx->r21);
    // addiu       $v1, $zero, 0x1A
    ctx->r3 = ADD32(0, 0X1A);
    // sh          $v1, 0x336($s5)
    MEM_H(0X336, ctx->r21) = ctx->r3;
    // lhu         $v1, 0x2E0($s5)
    ctx->r3 = MEM_HU(0X2E0, ctx->r21);
    // addiu       $s4, $zero, 0x5
    ctx->r20 = ADD32(0, 0X5);
    // sb          $zero, 0x32E($s5)
    MEM_B(0X32E, ctx->r21) = 0;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8) << 1;
    // addiu       $t0, $t0, 0x30
    ctx->r8 = ADD32(ctx->r8, 0X30);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sb          $v0, 0x32C($s5)
    MEM_B(0X32C, ctx->r21) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $v0, $v0, 0x45
    ctx->r2 = ADD32(ctx->r2, 0X45);
    // sb          $t0, 0x32D($s5)
    MEM_B(0X32D, ctx->r21) = ctx->r8;
    // jal         0x80027D18
    // sh          $v0, 0x332($s5)
    MEM_H(0X332, ctx->r21) = ctx->r2;
    sub_80027D18(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x332($s5)
    MEM_H(0X332, ctx->r21) = ctx->r2;
    after_1:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_2;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_2:
    // addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // lhu         $a0, 0x18($s5)
    ctx->r4 = MEM_HU(0X18, ctx->r21);
    // addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // sh          $v1, 0x350($s5)
    MEM_H(0X350, ctx->r21) = ctx->r3;
    // sh          $v0, 0x352($s5)
    MEM_H(0X352, ctx->r21) = ctx->r2;
    // sh          $v1, 0x354($s5)
    MEM_H(0X354, ctx->r21) = ctx->r3;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // slti        $v0, $a0, 0x6
    ctx->r2 = SIGNED(ctx->r4) < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_8002A35C
    if (ctx->r2 == 0) {
        // sh          $v1, 0x356($s5)
        MEM_H(0X356, ctx->r21) = ctx->r3;
        goto L_8002A35C;
    }
    // sh          $v1, 0x356($s5)
    MEM_H(0X356, ctx->r21) = ctx->r3;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
L_8002A35C:
    // lbu         $v1, 0x303($s5)
    ctx->r3 = MEM_BU(0X303, ctx->r21);
    // lhu         $v0, 0x2E0($s5)
    ctx->r2 = MEM_HU(0X2E0, ctx->r21);
    // ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v0, $s4
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // beq         $v0, $zero, L_8002A3A4
    if (ctx->r2 == 0) {
        // sb          $v1, 0x303($s5)
        MEM_B(0X303, ctx->r21) = ctx->r3;
        goto L_8002A3A4;
    }
    // sb          $v1, 0x303($s5)
    MEM_B(0X303, ctx->r21) = ctx->r3;
    // addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(0X0, ctx->r21);
    // sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v0, 0x2EC($v0)
    ctx->r2 = MEM_HU(0X2EC, ctx->r2);
    // ori         $a3, $s5, 0x300
    ctx->r7 = ctx->r21 | 0X300;
    // addiu       $v0, $v0, 0xC00
    ctx->r2 = ADD32(ctx->r2, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    sub_8002732C(rdram, ctx);
    goto after_3;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_3:
L_8002A3A4:
    // blez        $s4, L_8002A4A4
    if (SIGNED(ctx->r20) <= 0) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_8002A4A4;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s6, $v0, 0x7590
    ctx->r22 = ADD32(ctx->r2, 0X7590);
    // addiu       $s3, $zero, 0x4C
    ctx->r19 = ADD32(0, 0X4C);
    // addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
L_8002A3BC:
    // andi        $s1, $s3, 0xFFFF
    ctx->r17 = ctx->r19 & 0XFFFF;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // lhu         $v0, 0x2E2($s5)
    ctx->r2 = MEM_HU(0X2E2, ctx->r21);
    // lw          $v1, 0x1C($s5)
    ctx->r3 = MEM_W(0X1C, ctx->r21);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $s0, 0x0($v0)
    ctx->r16 = MEM_HS(0X0, ctx->r2);
    // lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(0X0, ctx->r21);
    // sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(0X0, ctx->r2);
    // addiu       $a3, $s5, 0x300
    ctx->r7 = ADD32(ctx->r21, 0X300);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_4;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_4:
    // addiu       $a1, $zero, 0x112
    ctx->r5 = ADD32(0, 0X112);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // addu        $s0, $s0, $s6
    ctx->r16 = ADD32(ctx->r16, ctx->r22);
    // addiu       $a3, $s5, 0x310
    ctx->r7 = ADD32(ctx->r21, 0X310);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // lui         $a0, 0x200
    ctx->r4 = S32(0X200 << 16);
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // jal         0x80027440
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    sub_80027440(rdram, ctx);
    goto after_5;
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    after_5:
    // lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // lhu         $a1, 0x2E2($s5)
    ctx->r5 = MEM_HU(0X2E2, ctx->r21);
    // ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // addu        $a1, $a1, $s2
    ctx->r5 = ADD32(ctx->r5, ctx->r18);
    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $s3, $s3, 0x1A
    ctx->r19 = ADD32(ctx->r19, 0X1A);
    // addiu       $a0, $s5, 0x350
    ctx->r4 = ADD32(ctx->r21, 0X350);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sra         $v0, $a1, 31
    ctx->r2 = S32(ctx->r5) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v1, $t1, 1
    ctx->r3 = S32(ctx->r9) >> 1;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // jal         0x80028364
    // addu        $a1, $s5, $a1
    ctx->r5 = ADD32(ctx->r21, ctx->r5);
    sub_80028364(rdram, ctx);
    goto after_6;
    // addu        $a1, $s5, $a1
    ctx->r5 = ADD32(ctx->r21, ctx->r5);
    after_6:
    // lhu         $v0, 0x352($s5)
    ctx->r2 = MEM_HU(0X352, ctx->r21);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // addiu       $v0, $v0, 0x1A
    ctx->r2 = ADD32(ctx->r2, 0X1A);
    // sh          $v0, 0x352($s5)
    MEM_H(0X352, ctx->r21) = ctx->r2;
    // slt         $v0, $s2, $s4
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r20) ? 1 : 0;
    // bne         $v0, $zero, L_8002A3BC
    if (ctx->r2 != 0) {
        // addiu       $a1, $zero, 0x36
        ctx->r5 = ADD32(0, 0X36);
        goto L_8002A3BC;
    }
    // addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
L_8002A4A4:
    // addiu       $s4, $s5, 0x33C
    ctx->r20 = ADD32(ctx->r21, 0X33C);
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // addiu       $s3, $s5, 0x358
    ctx->r19 = ADD32(ctx->r21, 0X358);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // addiu       $s2, $s5, 0x35C
    ctx->r18 = ADD32(ctx->r21, 0X35C);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x35C($s5)
    MEM_H(0X35C, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x1FF
    ctx->r2 = ADD32(0, 0X1FF);
    // sh          $v0, 0x35E($s5)
    MEM_H(0X35E, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // sh          $v0, 0x33C($s5)
    MEM_H(0X33C, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // sh          $v0, 0x33E($s5)
    MEM_H(0X33E, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
    // sh          $v0, 0x340($s5)
    MEM_H(0X340, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x342($s5)
    MEM_H(0X342, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x270
    ctx->r2 = ADD32(0, 0X270);
    // addiu       $s0, $zero, 0x1C0
    ctx->r16 = ADD32(0, 0X1C0);
    // sh          $v0, 0x358($s5)
    MEM_H(0X358, ctx->r21) = ctx->r2;
    // lbu         $v0, 0x303($s5)
    ctx->r2 = MEM_BU(0X303, ctx->r21);
    // addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // sh          $s0, 0x35A($s5)
    MEM_H(0X35A, ctx->r21) = ctx->r16;
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // jal         0x80028364
    // sb          $v0, 0x303($s5)
    MEM_B(0X303, ctx->r21) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_7;
    // sb          $v0, 0x303($s5)
    MEM_B(0X303, ctx->r21) = ctx->r2;
    after_7:
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x279
    ctx->r2 = ADD32(0, 0X279);
    // sh          $v0, 0x358($s5)
    MEM_H(0X358, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sh          $v0, 0x33C($s5)
    MEM_H(0X33C, ctx->r21) = ctx->r2;
    // addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // sh          $s0, 0x35A($s5)
    MEM_H(0X35A, ctx->r21) = ctx->r16;
    // sh          $v0, 0x340($s5)
    MEM_H(0X340, ctx->r21) = ctx->r2;
    // jal         0x80028364
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    sub_80028364(rdram, ctx);
    goto after_8;
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_8:
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
    goto after_9;
    // addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    after_9:
    // jal         0x800175A4
    // nop

    sub_800175A4(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // jal         0x8002948C
    // nop

    sub_8002948C(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // jal         0x80017634
    // nop

    sub_80017634(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
