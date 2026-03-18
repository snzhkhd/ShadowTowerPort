#include "recomp.h"
#include "disable_warnings.h"

void sub_8002D8E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // lui         $s3, 0x1F80
    ctx->r19 = S32(0X1F80 << 16);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lhu         $v0, 0x8($s3)
    ctx->r2 = MEM_HU(0X8, ctx->r19);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0x6
    ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_8002D938
    if (ctx->r2 == 0) {
        // addiu       $fp, $zero, 0x5
        ctx->r30 = ADD32(0, 0X5);
        goto L_8002D938;
    }
    // addiu       $fp, $zero, 0x5
    ctx->r30 = ADD32(0, 0X5);
    // addu        $fp, $v1, $zero
    ctx->r30 = ADD32(ctx->r3, 0);
L_8002D938:
    // blez        $fp, L_8002DA6C
    if (SIGNED(ctx->r30) <= 0) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_8002DA6C;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // lui         $s6, 0x1F80
    ctx->r22 = S32(0X1F80 << 16);
    // ori         $s6, $s6, 0x300
    ctx->r22 = ctx->r22 | 0X300;
    // lui         $s7, 0x1F80
    ctx->r23 = S32(0X1F80 << 16);
    // ori         $s7, $s7, 0x310
    ctx->r23 = ctx->r23 | 0X310;
    // addiu       $s5, $zero, 0x3E
    ctx->r21 = ADD32(0, 0X3E);
    // addiu       $s4, $zero, 0x30
    ctx->r20 = ADD32(0, 0X30);
L_8002D958:
    // addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
    // lhu         $v0, 0x2E2($s3)
    ctx->r2 = MEM_HU(0X2E2, ctx->r19);
    // lw          $v1, 0x4($s3)
    ctx->r3 = MEM_W(0X4, ctx->r19);
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
    // lbu         $v1, 0x303($s3)
    ctx->r3 = MEM_BU(0X303, ctx->r19);
    // lh          $s1, 0x0($v0)
    ctx->r17 = MEM_HS(0X0, ctx->r2);
    // ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    // sb          $v1, 0x303($s3)
    MEM_B(0X303, ctx->r19) = ctx->r3;
    // lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(0X0, ctx->r19);
    // sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17) << 1;
    // addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(0X0, ctx->r2);
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_0;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_0:
    // addu        $s0, $s0, $s1
    ctx->r16 = ADD32(ctx->r16, ctx->r17);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // subu        $s0, $s0, $s1
    ctx->r16 = SUB32(ctx->r16, ctx->r17);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // addiu       $t0, $t0, 0x76F8
    ctx->r8 = ADD32(ctx->r8, 0X76F8);
    // lbu         $v0, 0x303($s3)
    ctx->r2 = MEM_BU(0X303, ctx->r19);
    // addu        $s1, $s0, $t0
    ctx->r17 = ADD32(ctx->r16, ctx->r8);
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // sb          $v0, 0x303($s3)
    MEM_B(0X303, ctx->r19) = ctx->r2;
    // lbu         $v0, 0x13F($s1)
    ctx->r2 = MEM_BU(0X13F, ctx->r17);
    // nop

    // beq         $v0, $zero, L_8002DA58
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x83
        ctx->r5 = ADD32(0, 0X83);
        goto L_8002DA58;
    }
    // addiu       $a1, $zero, 0x83
    ctx->r5 = ADD32(0, 0X83);
    // andi        $s0, $s5, 0xFFFF
    ctx->r16 = ctx->r21 & 0XFFFF;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // addiu       $t0, $t0, 0xD50
    ctx->r8 = ADD32(ctx->r8, 0XD50);
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // lhu         $a0, 0xDA($t0)
    ctx->r4 = MEM_HU(0XDA, ctx->r8);
    // lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
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
    // addiu       $a1, $zero, 0xBB
    ctx->r5 = ADD32(0, 0XBB);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    // lbu         $a0, 0x140($s1)
    ctx->r4 = MEM_BU(0X140, ctx->r17);
    // lui         $t0, 0x300
    ctx->r8 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    sub_80027440(rdram, ctx);
    goto after_2;
    // or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    after_2:
    // addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // addiu       $a1, $zero, 0xDB
    ctx->r5 = ADD32(0, 0XDB);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x80026ECC
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    sub_80026ECC(rdram, ctx);
    goto after_3;
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    after_3:
    // addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    // lbu         $a0, 0x13F($s1)
    ctx->r4 = MEM_BU(0X13F, ctx->r17);
    // lui         $t0, 0x300
    ctx->r8 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    sub_80027440(rdram, ctx);
    goto after_4;
    // or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    after_4:
L_8002DA58:
    // addiu       $s5, $s5, 0x24
    ctx->r21 = ADD32(ctx->r21, 0X24);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // slt         $v0, $s2, $fp
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r30) ? 1 : 0;
    // bne         $v0, $zero, L_8002D958
    if (ctx->r2 != 0) {
        // addiu       $s4, $s4, 0x24
        ctx->r20 = ADD32(ctx->r20, 0X24);
        goto L_8002D958;
    }
    // addiu       $s4, $s4, 0x24
    ctx->r20 = ADD32(ctx->r20, 0X24);
L_8002DA6C:
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
