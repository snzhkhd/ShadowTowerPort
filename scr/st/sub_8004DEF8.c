#include "recomp.h"
#include "disable_warnings.h"

void sub_8004DEF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // addu        $fp, $a1, $zero
    ctx->r30 = ADD32(ctx->r5, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // lbu         $s3, 0x48($sp)
    ctx->r19 = MEM_BU(0X48, ctx->r29);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sb          $v0, 0x64($s2)
    MEM_B(0X64, ctx->r18) = ctx->r2;
    // lbu         $v0, 0x1F($s2)
    ctx->r2 = MEM_BU(0X1F, ctx->r18);
    // addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // bne         $v0, $s5, L_8004DF58
    if (ctx->r2 != ctx->r21) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8004DF58;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // j           L_8004E2A4
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8004E2A4;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004DF58:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x8004DE24
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_8004DE24(rdram, ctx);
    goto after_0;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // beq         $s3, $zero, L_8004DF74
    if (ctx->r19 == 0) {
        // addu        $s1, $v0, $zero
        ctx->r17 = ADD32(ctx->r2, 0);
        goto L_8004DF74;
    }
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17) << 1;
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
L_8004DF74:
    // sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $s1, $v0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t0
    ctx->r8 = hi;
    // sra         $v1, $t0, 11
    ctx->r3 = S32(ctx->r8) >> 11;
    // subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
    // beq         $s1, $zero, L_8004E2A4
    if (ctx->r17 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004E2A4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lbu         $v1, 0x2($s2)
    ctx->r3 = MEM_BU(0X2, ctx->r18);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $s7, $v1, -0x29C8
    ctx->r23 = ADD32(ctx->r3, -0X29C8);
    // addu        $s4, $v0, $s7
    ctx->r20 = ADD32(ctx->r2, ctx->r23);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s6, $v0, -0x70D8
    ctx->r22 = ADD32(ctx->r2, -0X70D8);
    // lw          $v0, 0x2C($s6)
    ctx->r2 = MEM_W(0X2C, ctx->r22);
    // lui         $v1, 0x20
    ctx->r3 = S32(0X20 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8004DFF4
    if (ctx->r2 == 0) {
        // sll         $v0, $s1, 1
        ctx->r2 = S32(ctx->r17) << 1;
        goto L_8004DFF4;
    }
    // sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17) << 1;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $s1, $v0, 1
    ctx->r17 = S32(ctx->r2) >> 1;
L_8004DFF4:
    // lbu         $s3, 0x1C6($s6)
    ctx->r19 = MEM_BU(0X1C6, ctx->r22);
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // bgez        $v0, L_8004E020
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8004E020;
    }
    // nop

    // addiu       $v0, $v0, 0x7FFF
    ctx->r2 = ADD32(ctx->r2, 0X7FFF);
L_8004E020:
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // beq         $v0, $zero, L_8004E03C
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
        goto L_8004E03C;
    }
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // jal         0x800582F0
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    sub_800582F0(rdram, ctx);
    goto after_2;
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_2:
    // sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17) << 1;
L_8004E03C:
    // bne         $fp, $s5, L_8004E048
    if (ctx->r30 != ctx->r21) {
        // addiu       $a1, $zero, 0x18
        ctx->r5 = ADD32(0, 0X18);
        goto L_8004E048;
    }
    // addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17) << 1;
L_8004E048:
    // addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // lbu         $v0, 0x1E($s2)
    ctx->r2 = MEM_BU(0X1E, ctx->r18);
    // lhu         $a0, 0x2C($s2)
    ctx->r4 = MEM_HU(0X2C, ctx->r18);
    // andi        $v0, $v0, 0xCA
    ctx->r2 = ctx->r2 & 0XCA;
    // sb          $v0, 0x1E($s2)
    MEM_B(0X1E, ctx->r18) = ctx->r2;
    // slt         $v0, $s1, $a0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_8004E150
    if (ctx->r2 != 0) {
        // addu        $s3, $s5, $zero
        ctx->r19 = ADD32(ctx->r21, 0);
        goto L_8004E150;
    }
    // addu        $s3, $s5, $zero
    ctx->r19 = ADD32(ctx->r21, 0);
    // lbu         $v1, 0x1F($s2)
    ctx->r3 = MEM_BU(0X1F, ctx->r18);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $v0, L_8004E164
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8004E164;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // jal         0x8004DA2C
    // sb          $v0, 0x5($s2)
    MEM_B(0X5, ctx->r18) = ctx->r2;
    sub_8004DA2C(rdram, ctx);
    goto after_3;
    // sb          $v0, 0x5($s2)
    MEM_B(0X5, ctx->r18) = ctx->r2;
    after_3:
    // jal         0x8004DB0C
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    sub_8004DB0C(rdram, ctx);
    goto after_4;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_4:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a2, $v0, -0x45F8
    ctx->r6 = ADD32(ctx->r2, -0X45F8);
    // lhu         $a1, 0x10($s4)
    ctx->r5 = MEM_HU(0X10, ctx->r20);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // srl         $a0, $a1, 5
    ctx->r4 = S32(U32(ctx->r5) >> 5);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // andi        $a1, $a1, 0x1F
    ctx->r5 = ctx->r5 & 0X1F;
    // lw          $v1, 0x14BC($a0)
    ctx->r3 = MEM_W(0X14BC, ctx->r4);
    // sllv        $v0, $v0, $a1
    ctx->r2 = S32(ctx->r2) << (ctx->r5 & 31);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // addiu       $v0, $s7, -0xD40
    ctx->r2 = ADD32(ctx->r23, -0XD40);
    // sltu        $v0, $s2, $v0
    ctx->r2 = ctx->r18 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_8004E0F8
    if (ctx->r2 == 0) {
        // sw          $v1, 0x14BC($a0)
        MEM_W(0X14BC, ctx->r4) = ctx->r3;
        goto L_8004E0F8;
    }
    // sw          $v1, 0x14BC($a0)
    MEM_W(0X14BC, ctx->r4) = ctx->r3;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v1, 0x5929($v0)
    ctx->r3 = MEM_BU(0X5929, ctx->r2);
    // nop

    // addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // lbu         $v0, 0x16E4($v1)
    ctx->r2 = MEM_BU(0X16E4, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x16E4($v1)
    MEM_B(0X16E4, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x30($s6)
    ctx->r2 = MEM_HU(0X30, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0x30($s6)
    MEM_H(0X30, ctx->r22) = ctx->r2;
L_8004E0F8:
    // addiu       $v1, $s4, 0x60
    ctx->r3 = ADD32(ctx->r20, 0X60);
    // addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // lbu         $v0, 0x1E($s2)
    ctx->r2 = MEM_BU(0X1E, ctx->r18);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // sh          $zero, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = 0;
    // ori         $v0, $v0, 0x15
    ctx->r2 = ctx->r2 | 0X15;
    // sb          $v0, 0x1E($s2)
    MEM_B(0X1E, ctx->r18) = ctx->r2;
L_8004E118:
    // lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(0X0, ctx->r3);
    // nop

    // beq         $s0, $zero, L_8004E1E0
    if (ctx->r16 == 0) {
        // addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
        goto L_8004E1E0;
    }
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // beq         $v0, $a2, L_8004E148
    if (ctx->r2 == ctx->r6) {
        // addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
        goto L_8004E148;
    }
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // bne         $a1, $a0, L_8004E118
    if (ctx->r5 != ctx->r4) {
        // addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_8004E118;
    }
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // j           L_8004E1E0
    // nop

    goto L_8004E1E0;
    // nop

L_8004E148:
    // j           L_8004E1E0
    // addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    goto L_8004E1E0;
    // addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_8004E150:
    // lbu         $v1, 0x1F($s2)
    ctx->r3 = MEM_BU(0X1F, ctx->r18);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $v0, L_8004E164
    if (ctx->r3 == ctx->r2) {
        // subu        $v0, $a0, $s1
        ctx->r2 = SUB32(ctx->r4, ctx->r17);
        goto L_8004E164;
    }
    // subu        $v0, $a0, $s1
    ctx->r2 = SUB32(ctx->r4, ctx->r17);
    // sh          $v0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r2;
L_8004E164:
    // lui         $a0, 0x51EB
    ctx->r4 = S32(0X51EB << 16);
    // lhu         $v0, 0x2C($s2)
    ctx->r2 = MEM_HU(0X2C, ctx->r18);
    // ori         $a0, $a0, 0x851F
    ctx->r4 = ctx->r4 | 0X851F;
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lbu         $v0, 0x1E($s2)
    ctx->r2 = MEM_BU(0X1E, ctx->r18);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // sb          $v0, 0x1E($s2)
    MEM_B(0X1E, ctx->r18) = ctx->r2;
    // mfhi        $t0
    ctx->r8 = hi;
    // sra         $v0, $t0, 5
    ctx->r2 = S32(ctx->r8) >> 5;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8004E1E0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004E1E0;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // beq         $a1, $v0, L_8004E1E0
    if (ctx->r5 == ctx->r2) {
        // addiu       $v1, $s4, 0x60
        ctx->r3 = ADD32(ctx->r20, 0X60);
        goto L_8004E1E0;
    }
    // addiu       $v1, $s4, 0x60
    ctx->r3 = ADD32(ctx->r20, 0X60);
    // addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8004E1B8:
    // lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(0X0, ctx->r3);
    // nop

    // beq         $s0, $zero, L_8004E1E0
    if (ctx->r16 == 0) {
        // addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
        goto L_8004E1E0;
    }
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // beq         $v0, $a2, L_8004E148
    if (ctx->r2 == ctx->r6) {
        // addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
        goto L_8004E148;
    }
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // bne         $a1, $a0, L_8004E1B8
    if (ctx->r5 != ctx->r4) {
        // addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_8004E1B8;
    }
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8004E1E0:
    // beq         $s5, $zero, L_8004E210
    if (ctx->r21 == 0) {
        // addiu       $v0, $zero, 0xFFF
        ctx->r2 = ADD32(0, 0XFFF);
        goto L_8004E210;
    }
    // addiu       $v0, $zero, 0xFFF
    ctx->r2 = ADD32(0, 0XFFF);
    // sb          $s3, 0x18($s2)
    MEM_B(0X18, ctx->r18) = ctx->r19;
    // sw          $s0, 0xA8($s2)
    MEM_W(0XA8, ctx->r18) = ctx->r16;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // sb          $zero, 0x1A($s2)
    MEM_B(0X1A, ctx->r18) = 0;
    // sh          $zero, 0x2A($s2)
    MEM_H(0X2A, ctx->r18) = 0;
    // sb          $v0, 0xF($s2)
    MEM_B(0XF, ctx->r18) = ctx->r2;
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // sh          $v0, 0xB0($s2)
    MEM_H(0XB0, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0xFFF
    ctx->r2 = ADD32(0, 0XFFF);
L_8004E210:
    // sh          $v0, 0x34($s2)
    MEM_H(0X34, ctx->r18) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v1, 0x218($s0)
    ctx->r3 = MEM_BU(0X218, ctx->r16);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_8004E2A0
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $s1, 16
        ctx->r2 = S32(ctx->r17) << 16;
        goto L_8004E2A0;
    }
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // lbu         $v0, 0x1C9($s0)
    ctx->r2 = MEM_BU(0X1C9, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8004E264
    if (ctx->r2 == 0) {
        // mult        $s1, $v0
        result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_8004E264;
    }
    // mult        $s1, $v0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // mflo        $a0
    ctx->r4 = lo;
    // lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // mfhi        $t0
    ctx->r8 = hi;
    // sra         $v0, $t0, 5
    ctx->r2 = S32(ctx->r8) >> 5;
    // jal         0x8003CF28
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    sub_8003CF28(rdram, ctx);
    goto after_5;
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    after_5:
L_8004E264:
    // lbu         $v0, 0x1CA($s0)
    ctx->r2 = MEM_BU(0X1CA, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8004E29C
    if (ctx->r2 == 0) {
        // mult        $s1, $v0
        result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_8004E29C;
    }
    // mult        $s1, $v0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // mflo        $a0
    ctx->r4 = lo;
    // lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // mfhi        $t0
    ctx->r8 = hi;
    // sra         $v0, $t0, 5
    ctx->r2 = S32(ctx->r8) >> 5;
    // jal         0x8003CF94
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    sub_8003CF94(rdram, ctx);
    goto after_6;
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    after_6:
L_8004E29C:
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
L_8004E2A0:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
L_8004E2A4:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(0X30, ctx->r29);
    // lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(0X2C, ctx->r29);
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
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
