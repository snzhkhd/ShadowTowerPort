#include "recomp.h"
#include "disable_warnings.h"

void sub_8004F718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x2230
    ctx->r3 = ADD32(ctx->r3, 0X2230);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // slti        $a0, $a0, 0xF0
    ctx->r4 = SIGNED(ctx->r4) < 0XF0 ? 1 : 0;
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // beq         $a0, $zero, L_8004F944
    if (ctx->r4 == 0) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_8004F944;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s6, $v1, -0x1F20
    ctx->r22 = ADD32(ctx->r3, -0X1F20);
    // addiu       $s2, $v0, 0x20
    ctx->r18 = ADD32(ctx->r2, 0X20);
L_8004F77C:
    // lhu         $v1, -0x16($s2)
    ctx->r3 = MEM_HU(-0X16, ctx->r18);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_8004F928
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8004F928;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $s3, $v1, $s6
    ctx->r19 = ADD32(ctx->r3, ctx->r22);
    // lhu         $v0, 0x6($s3)
    ctx->r2 = MEM_HU(0X6, ctx->r19);
    // nop

    // beq         $v0, $zero, L_8004F92C
    if (ctx->r2 == 0) {
        // addiu       $v0, $s4, 0x1
        ctx->r2 = ADD32(ctx->r20, 0X1);
        goto L_8004F92C;
    }
    // addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(0X4, ctx->r21);
    // nop

    // subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
    // addiu       $v0, $s1, 0x2800
    ctx->r2 = ADD32(ctx->r17, 0X2800);
    // sltiu       $v0, $v0, 0x5001
    ctx->r2 = ctx->r2 < 0X5001 ? 1 : 0;
    // beq         $v0, $zero, L_8004F92C
    if (ctx->r2 == 0) {
        // addiu       $v0, $s4, 0x1
        ctx->r2 = ADD32(ctx->r20, 0X1);
        goto L_8004F92C;
    }
    // addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // lw          $v1, 0xC($s2)
    ctx->r3 = MEM_W(0XC, ctx->r18);
    // lw          $v0, 0xC($s5)
    ctx->r2 = MEM_W(0XC, ctx->r21);
    // nop

    // subu        $s0, $v1, $v0
    ctx->r16 = SUB32(ctx->r3, ctx->r2);
    // addiu       $v0, $s0, 0x2800
    ctx->r2 = ADD32(ctx->r16, 0X2800);
    // sltiu       $v0, $v0, 0x5001
    ctx->r2 = ctx->r2 < 0X5001 ? 1 : 0;
    // beq         $v0, $zero, L_8004F928
    if (ctx->r2 == 0) {
        // mult        $s1, $s1
        result = S64(S32(ctx->r17)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_8004F928;
    }
    // mult        $s1, $s1
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // mult        $s0, $s0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // jal         0x800746C4
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    SquareRoot0(rdram, ctx);
    goto after_0;
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // jal         0x80076EA4
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    ratan2(rdram, ctx);
    goto after_1;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // lhu         $v0, 0x6($s3)
    ctx->r2 = MEM_HU(0X6, ctx->r19);
    // nop

    // slt         $s0, $s0, $v0
    ctx->r16 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $s0, $zero, L_8004F92C
    if (ctx->r16 == 0) {
        // addiu       $v0, $s4, 0x1
        ctx->r2 = ADD32(ctx->r20, 0X1);
        goto L_8004F92C;
    }
    // addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(0X8, ctx->r18);
    // lw          $a1, 0x8($s5)
    ctx->r5 = MEM_W(0X8, ctx->r21);
    // nop

    // slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // beq         $v0, $zero, L_8004F858
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004F858;
    }
    // nop

    // lhu         $v0, 0x1E($s5)
    ctx->r2 = MEM_HU(0X1E, ctx->r21);
    // nop

    // subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // j           L_8004F868
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    goto L_8004F868;
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
L_8004F858:
    // lhu         $v1, -0xE($s2)
    ctx->r3 = MEM_HU(-0XE, ctx->r18);
    // addiu       $v0, $a0, -0x300
    ctx->r2 = ADD32(ctx->r4, -0X300);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_8004F868:
    // bne         $v0, $zero, L_8004F92C
    if (ctx->r2 != 0) {
        // addiu       $v0, $s4, 0x1
        ctx->r2 = ADD32(ctx->r20, 0X1);
        goto L_8004F92C;
    }
    // addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x6E6E($v0)
    ctx->r2 = MEM_HU(-0X6E6E, ctx->r2);
    // lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(0X0, ctx->r18);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
    // slti        $v0, $v1, 0x801
    ctx->r2 = SIGNED(ctx->r3) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_8004F898
    if (ctx->r2 != 0) {
        // addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
        goto L_8004F898;
    }
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // ori         $a0, $v1, 0xF000
    ctx->r4 = ctx->r3 | 0XF000;
L_8004F898:
    // lbu         $v0, 0x3($s3)
    ctx->r2 = MEM_BU(0X3, ctx->r19);
    // nop

    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // beq         $v0, $zero, L_8004F8BC
    if (ctx->r2 == 0) {
        // addiu       $v0, $a0, 0x190
        ctx->r2 = ADD32(ctx->r4, 0X190);
        goto L_8004F8BC;
    }
    // addiu       $v0, $a0, 0x190
    ctx->r2 = ADD32(ctx->r4, 0X190);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x321
    ctx->r2 = ctx->r2 < 0X321 ? 1 : 0;
    // beq         $v0, $zero, L_8004F92C
    if (ctx->r2 == 0) {
        // addiu       $v0, $s4, 0x1
        ctx->r2 = ADD32(ctx->r20, 0X1);
        goto L_8004F92C;
    }
    // addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
L_8004F8BC:
    // lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(0X0, ctx->r19);
    // nop

    // addiu       $v0, $v1, -0x32
    ctx->r2 = ADD32(ctx->r3, -0X32);
    // sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_8004F920
    if (ctx->r2 != 0) {
        // sll         $v0, $s4, 16
        ctx->r2 = S32(ctx->r20) << 16;
        goto L_8004F920;
    }
    // sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20) << 16;
    // andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_8004F920
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $s4, 16
        ctx->r2 = S32(ctx->r20) << 16;
        goto L_8004F920;
    }
    // sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20) << 16;
    // beq         $v1, $zero, L_8004F920
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8004F920;
    }
    // nop

    // addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // beq         $v1, $v0, L_8004F920
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $s4, 16
        ctx->r2 = S32(ctx->r20) << 16;
        goto L_8004F920;
    }
    // sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20) << 16;
    // addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // beq         $v1, $v0, L_8004F920
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $s4, 16
        ctx->r2 = S32(ctx->r20) << 16;
        goto L_8004F920;
    }
    // sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20) << 16;
    // addiu       $v0, $zero, 0xE2
    ctx->r2 = ADD32(0, 0XE2);
    // beq         $v1, $v0, L_8004F920
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $s4, 16
        ctx->r2 = S32(ctx->r20) << 16;
        goto L_8004F920;
    }
    // sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20) << 16;
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // bne         $v1, $v0, L_8004F92C
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $s4, 0x1
        ctx->r2 = ADD32(ctx->r20, 0X1);
        goto L_8004F92C;
    }
    // addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
    // sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20) << 16;
L_8004F920:
    // j           L_8004F948
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    goto L_8004F948;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
L_8004F928:
    // addiu       $v0, $s4, 0x1
    ctx->r2 = ADD32(ctx->r20, 0X1);
L_8004F92C:
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0xF0
    ctx->r2 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_8004F77C
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x58
        ctx->r18 = ADD32(ctx->r18, 0X58);
        goto L_8004F77C;
    }
    // addiu       $s2, $s2, 0x58
    ctx->r18 = ADD32(ctx->r18, 0X58);
L_8004F944:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004F948:
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
