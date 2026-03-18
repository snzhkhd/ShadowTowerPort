#include "recomp.h"
#include "disable_warnings.h"

void sub_80016A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // addiu       $fp, $v0, -0x4430
    ctx->r30 = ADD32(ctx->r2, -0X4430);
    // addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // addiu       $s7, $sp, 0x10
    ctx->r23 = ADD32(ctx->r29, 0X10);
    // lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // addiu       $s6, $v0, -0x5376
    ctx->r22 = ADD32(ctx->r2, -0X5376);
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // addiu       $s3, $fp, 0x2
    ctx->r19 = ADD32(ctx->r30, 0X2);
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_80016A60:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lh          $v1, 0x2($s3)
    ctx->r3 = MEM_HS(0X2, ctx->r19);
    // lbu         $v0, 0x5929($v0)
    ctx->r2 = MEM_BU(0X5929, ctx->r2);
    // nop

    // beq         $v1, $v0, L_80016A80
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_80016A80;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // bne         $v1, $v0, L_80016F68
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80016F68;
    }
    // nop

L_80016A80:
    // lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(0X0, ctx->r19);
    // nop

    // bne         $v0, $zero, L_80016F64
    if (ctx->r2 != 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80016F64;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lwl         $v0, 0x11($s3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X11, ctx->r19);
    // lwr         $v0, 0xE($s3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0XE, ctx->r19);
    // lwl         $v1, 0x15($s3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X15, ctx->r19);
    // lwr         $v1, 0x12($s3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X12, ctx->r19);
    // swl         $v0, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r2);
    // swr         $v0, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r2);
    // swl         $v1, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r3);
    // swr         $v1, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r3);
    // lbu         $v0, -0x1($s3)
    ctx->r2 = MEM_BU(-0X1, ctx->r19);
    // nop

    // sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
    // lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(0X0, ctx->r30);
    // nop

    // slti        $v0, $v1, 0x15
    ctx->r2 = SIGNED(ctx->r3) < 0X15 ? 1 : 0;
    // beq         $v0, $zero, L_80016AF8
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x11
        ctx->r2 = SIGNED(ctx->r3) < 0X11 ? 1 : 0;
        goto L_80016AF8;
    }
    // slti        $v0, $v1, 0x11
    ctx->r2 = SIGNED(ctx->r3) < 0X11 ? 1 : 0;
    // beq         $v0, $zero, L_80016E6C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80016E6C;
    }
    // nop

    // beq         $v1, $zero, L_80016F68
    if (ctx->r3 == 0) {
        // slti        $v0, $v1, 0x6
        ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
        goto L_80016F68;
    }
    // slti        $v0, $v1, 0x6
    ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_80016B24
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, 0xA
        ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
        goto L_80016B24;
    }
    // slti        $v0, $v1, 0xA
    ctx->r2 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_80016F68
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80016F68;
    }
    // nop

    // j           L_80016BC4
    // nop

    goto L_80016BC4;
    // nop

L_80016AF8:
    // addiu       $v0, $zero, 0x31
    ctx->r2 = ADD32(0, 0X31);
    // beq         $v1, $v0, L_80016EDC
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x32
        ctx->r2 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
        goto L_80016EDC;
    }
    // slti        $v0, $v1, 0x32
    ctx->r2 = SIGNED(ctx->r3) < 0X32 ? 1 : 0;
    // beq         $v0, $zero, L_80016F68
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x26
        ctx->r2 = SIGNED(ctx->r3) < 0X26 ? 1 : 0;
        goto L_80016F68;
    }
    // slti        $v0, $v1, 0x26
    ctx->r2 = SIGNED(ctx->r3) < 0X26 ? 1 : 0;
    // beq         $v0, $zero, L_80016F68
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x21
        ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
        goto L_80016F68;
    }
    // slti        $v0, $v1, 0x21
    ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    // beq         $v0, $zero, L_80016CD8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80016CD8;
    }
    // nop

    // j           L_80016F6C
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    goto L_80016F6C;
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
L_80016B24:
    // lbu         $v1, 0x1($s3)
    ctx->r3 = MEM_BU(0X1, ctx->r19);
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // lh          $v1, 0x14($s3)
    ctx->r3 = MEM_HS(0X14, ctx->r19);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sh          $a0, 0x4($s3)
    MEM_H(0X4, ctx->r19) = ctx->r4;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // lhu         $v1, 0x14($s3)
    ctx->r3 = MEM_HU(0X14, ctx->r19);
    // bne         $v0, $zero, L_80016B58
    if (ctx->r2 != 0) {
        // subu        $v0, $a0, $v1
        ctx->r2 = SUB32(ctx->r4, ctx->r3);
        goto L_80016B58;
    }
    // subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // sh          $v0, 0x4($s3)
    MEM_H(0X4, ctx->r19) = ctx->r2;
L_80016B58:
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // lh          $s4, 0x6($s3)
    ctx->r20 = MEM_HS(0X6, ctx->r19);
    // lh          $a3, 0x8($s3)
    ctx->r7 = MEM_HS(0X8, ctx->r19);
    // lhu         $v1, 0x4($s3)
    ctx->r3 = MEM_HU(0X4, ctx->r19);
    // lh          $a2, 0x4($s3)
    ctx->r6 = MEM_HS(0X4, ctx->r19);
    // lhu         $v0, 0x14($s3)
    ctx->r2 = MEM_HU(0X14, ctx->r19);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // addu        $a2, $a3, $a2
    ctx->r6 = ADD32(ctx->r7, ctx->r6);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x80079DCC
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    MoveImage(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    after_0:
    // lh          $v0, 0x4($s3)
    ctx->r2 = MEM_HS(0X4, ctx->r19);
    // nop

    // beq         $v0, $zero, L_80016F68
    if (ctx->r2 == 0) {
        // addu        $a0, $s7, $zero
        ctx->r4 = ADD32(ctx->r23, 0);
        goto L_80016F68;
    }
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // lhu         $v0, 0x10($s3)
    ctx->r2 = MEM_HU(0X10, ctx->r19);
    // lhu         $v1, 0x16($sp)
    ctx->r3 = MEM_HU(0X16, ctx->r29);
    // lh          $s1, 0x8($s3)
    ctx->r17 = MEM_HS(0X8, ctx->r19);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // jal         0x80079DCC
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    MoveImage(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    after_1:
    // j           L_80016F6C
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    goto L_80016F6C;
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
L_80016BC4:
    // lbu         $v1, 0x1($s3)
    ctx->r3 = MEM_BU(0X1, ctx->r19);
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // lh          $v1, 0x12($s3)
    ctx->r3 = MEM_HS(0X12, ctx->r19);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sh          $a0, 0x4($s3)
    MEM_H(0X4, ctx->r19) = ctx->r4;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // lhu         $v1, 0x12($s3)
    ctx->r3 = MEM_HU(0X12, ctx->r19);
    // bne         $v0, $zero, L_80016C00
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80016C00;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // sh          $v0, 0x4($s3)
    MEM_H(0X4, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80016C00:
    // lhu         $s5, 0x14($s3)
    ctx->r21 = MEM_HU(0X14, ctx->r19);
    // addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // lhu         $s2, 0x4($s3)
    ctx->r18 = MEM_HU(0X4, ctx->r19);
    // lh          $s1, 0x8($s3)
    ctx->r17 = MEM_HS(0X8, ctx->r19);
    // addiu       $v0, $s5, -0x1
    ctx->r2 = ADD32(ctx->r21, -0X1);
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // beq         $v0, $t9, L_80016F68
    if (ctx->r2 == ctx->r25) {
        // nop
    
        goto L_80016F68;
    }
    // nop

L_80016C2C:
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // lh          $v1, 0x12($s3)
    ctx->r3 = MEM_HS(0X12, ctx->r19);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // lhu         $v1, 0x12($s3)
    ctx->r3 = MEM_HU(0X12, ctx->r19);
    // bne         $v0, $zero, L_80016C4C
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80016C4C;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // subu        $s2, $s2, $v1
    ctx->r18 = SUB32(ctx->r18, ctx->r3);
L_80016C4C:
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // sll         $s0, $s2, 16
    ctx->r16 = S32(ctx->r18) << 16;
    // lh          $a1, 0x6($s3)
    ctx->r5 = MEM_HS(0X6, ctx->r19);
    // lhu         $v0, 0xE($s3)
    ctx->r2 = MEM_HU(0XE, ctx->r19);
    // sra         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16) >> 16;
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x12($s3)
    ctx->r2 = MEM_HU(0X12, ctx->r19);
    // addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // jal         0x80079DCC
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    MoveImage(rdram, ctx);
    goto after_2;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    after_2:
    // beq         $s0, $zero, L_80016CA4
    if (ctx->r16 == 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80016CA4;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lh          $s4, 0x6($s3)
    ctx->r20 = MEM_HS(0X6, ctx->r19);
    // lhu         $v0, 0xE($s3)
    ctx->r2 = MEM_HU(0XE, ctx->r19);
    // lhu         $v1, 0x14($sp)
    ctx->r3 = MEM_HU(0X14, ctx->r29);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // sh          $s2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r18;
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80079DCC
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    MoveImage(rdram, ctx);
    goto after_3;
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    after_3:
L_80016CA4:
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // addiu       $v0, $s5, -0x1
    ctx->r2 = ADD32(ctx->r21, -0X1);
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // lhu         $v1, 0x12($sp)
    ctx->r3 = MEM_HU(0X12, ctx->r29);
    // addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // bne         $v0, $t8, L_80016C2C
    if (ctx->r2 != ctx->r24) {
        // sh          $v1, 0x12($sp)
        MEM_H(0X12, ctx->r29) = ctx->r3;
        goto L_80016C2C;
    }
    // sh          $v1, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r3;
    // j           L_80016F6C
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    goto L_80016F6C;
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
L_80016CD8:
    // lbu         $v1, 0x1($s3)
    ctx->r3 = MEM_BU(0X1, ctx->r19);
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // lh          $v1, 0x14($s3)
    ctx->r3 = MEM_HS(0X14, ctx->r19);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sh          $a0, 0x4($s3)
    MEM_H(0X4, ctx->r19) = ctx->r4;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // lhu         $v1, 0x14($s3)
    ctx->r3 = MEM_HU(0X14, ctx->r19);
    // bne         $v0, $zero, L_80016D14
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80016D14;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // sh          $v0, 0x4($s3)
    MEM_H(0X4, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80016D14:
    // lhu         $s2, 0x12($s3)
    ctx->r18 = MEM_HU(0X12, ctx->r19);
    // addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // lhu         $s5, 0x4($s3)
    ctx->r21 = MEM_HU(0X4, ctx->r19);
    // lh          $s4, 0x6($s3)
    ctx->r20 = MEM_HS(0X6, ctx->r19);
    // addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // beq         $v0, $t9, L_80016F68
    if (ctx->r2 == ctx->r25) {
        // nop
    
        goto L_80016F68;
    }
    // nop

L_80016D40:
    // lh          $v0, 0x12($s3)
    ctx->r2 = MEM_HS(0X12, ctx->r19);
    // addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80016D58
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80016D58;
    }
    // nop

    // break       7
    do_break(2147577172);
L_80016D58:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80016D70
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80016D70;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_80016D70
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_80016D70;
    }
    // nop

    // break       6
    do_break(2147577196);
L_80016D70:
    // mflo        $v1
    ctx->r3 = lo;
    // sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // jal         0x800743F4
    // nop

    rsin(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lhu         $v1, 0x14($s3)
    ctx->r3 = MEM_HU(0X14, ctx->r19);
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3) >> 16;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // bgez        $a0, L_80016DB4
    if (SIGNED(ctx->r4) >= 0) {
        // sra         $v1, $v1, 1
        ctx->r3 = S32(ctx->r3) >> 1;
        goto L_80016DB4;
    }
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // addiu       $a1, $a0, 0x3
    ctx->r5 = ADD32(ctx->r4, 0X3);
L_80016DB4:
    // sra         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) >> 2;
    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80016DCC
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80016DCC;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80016DCC:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // slt         $v0, $s0, $a0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_80016DE4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80016DE4;
    }
    // nop

    // subu        $s0, $s0, $a0
    ctx->r16 = SUB32(ctx->r16, ctx->r4);
L_80016DE4:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lh          $a2, 0x8($s3)
    ctx->r6 = MEM_HS(0X8, ctx->r19);
    // lhu         $v0, 0x10($s3)
    ctx->r2 = MEM_HU(0X10, ctx->r19);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x14($s3)
    ctx->r2 = MEM_HU(0X14, ctx->r19);
    // addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // jal         0x80079DCC
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    MoveImage(rdram, ctx);
    goto after_5;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    after_5:
    // beq         $s0, $zero, L_80016E38
    if (ctx->r16 == 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80016E38;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lh          $s1, 0x8($s3)
    ctx->r17 = MEM_HS(0X8, ctx->r19);
    // lhu         $v0, 0x10($s3)
    ctx->r2 = MEM_HU(0X10, ctx->r19);
    // lhu         $v1, 0x16($sp)
    ctx->r3 = MEM_HU(0X16, ctx->r29);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // sh          $s0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r16;
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80079DCC
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    MoveImage(rdram, ctx);
    goto after_6;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    after_6:
L_80016E38:
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // lhu         $v1, 0x10($sp)
    ctx->r3 = MEM_HU(0X10, ctx->r29);
    // addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // bne         $v0, $t8, L_80016D40
    if (ctx->r2 != ctx->r24) {
        // sh          $v1, 0x10($sp)
        MEM_H(0X10, ctx->r29) = ctx->r3;
        goto L_80016D40;
    }
    // sh          $v1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r3;
    // j           L_80016F6C
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    goto L_80016F6C;
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
L_80016E6C:
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // lbu         $v1, 0x1($s3)
    ctx->r3 = MEM_BU(0X1, ctx->r19);
    // addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80016EA8
    if (ctx->r2 != 0) {
        // sh          $a0, 0x4($s3)
        MEM_H(0X4, ctx->r19) = ctx->r4;
        goto L_80016EA8;
    }
    // sh          $a0, 0x4($s3)
    MEM_H(0X4, ctx->r19) = ctx->r4;
    // sh          $zero, 0x4($s3)
    MEM_H(0X4, ctx->r19) = 0;
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // jal         0x80079D0C
    // addiu       $a1, $a1, -0x5378
    ctx->r5 = ADD32(ctx->r5, -0X5378);
    LoadImage(rdram, ctx);
    goto after_7;
    // addiu       $a1, $a1, -0x5378
    ctx->r5 = ADD32(ctx->r5, -0X5378);
    after_7:
    // j           L_80016F6C
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    goto L_80016F6C;
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
L_80016EA8:
    // lhu         $v0, 0x14($s3)
    ctx->r2 = MEM_HU(0X14, ctx->r19);
    // nop

    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x12($sp)
    ctx->r2 = MEM_HU(0X12, ctx->r29);
    // mflo        $t9
    ctx->r25 = lo;
    // addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // lh          $a1, 0x6($s3)
    ctx->r5 = MEM_HS(0X6, ctx->r19);
    // lh          $a2, 0x8($s3)
    ctx->r6 = MEM_HS(0X8, ctx->r19);
    // jal         0x80079DCC
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    MoveImage(rdram, ctx);
    goto after_8;
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    after_8:
    // j           L_80016F6C
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    goto L_80016F6C;
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
L_80016EDC:
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // lhu         $s2, -0x5376($v0)
    ctx->r18 = MEM_HU(-0X5376, ctx->r2);
    // lhu         $v1, 0x2($s6)
    ctx->r3 = MEM_HU(0X2, ctx->r22);
    // lhu         $a2, 0x4($s6)
    ctx->r6 = MEM_HU(0X4, ctx->r22);
    // lhu         $a3, 0x6($s6)
    ctx->r7 = MEM_HU(0X6, ctx->r22);
    // lhu         $t0, 0x8($s6)
    ctx->r8 = MEM_HU(0X8, ctx->r22);
    // lhu         $t1, 0xA($s6)
    ctx->r9 = MEM_HU(0XA, ctx->r22);
    // lhu         $t2, 0xC($s6)
    ctx->r10 = MEM_HU(0XC, ctx->r22);
    // lhu         $t3, 0xE($s6)
    ctx->r11 = MEM_HU(0XE, ctx->r22);
    // lhu         $t4, 0x10($s6)
    ctx->r12 = MEM_HU(0X10, ctx->r22);
    // lhu         $t5, 0x12($s6)
    ctx->r13 = MEM_HU(0X12, ctx->r22);
    // lhu         $t6, 0x14($s6)
    ctx->r14 = MEM_HU(0X14, ctx->r22);
    // lhu         $t7, 0x16($s6)
    ctx->r15 = MEM_HU(0X16, ctx->r22);
    // lhu         $s0, 0x18($s6)
    ctx->r16 = MEM_HU(0X18, ctx->r22);
    // lhu         $s1, 0x1A($s6)
    ctx->r17 = MEM_HU(0X1A, ctx->r22);
    // addiu       $a1, $s6, -0x2
    ctx->r5 = ADD32(ctx->r22, -0X2);
    // sh          $v1, -0x5376($v0)
    MEM_H(-0X5376, ctx->r2) = ctx->r3;
    // sh          $a2, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r6;
    // sh          $a3, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r7;
    // sh          $t0, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r8;
    // sh          $t1, 0x8($s6)
    MEM_H(0X8, ctx->r22) = ctx->r9;
    // sh          $t2, 0xA($s6)
    MEM_H(0XA, ctx->r22) = ctx->r10;
    // sh          $t3, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r11;
    // sh          $t4, 0xE($s6)
    MEM_H(0XE, ctx->r22) = ctx->r12;
    // sh          $t5, 0x10($s6)
    MEM_H(0X10, ctx->r22) = ctx->r13;
    // sh          $t6, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r14;
    // sh          $t7, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r15;
    // sh          $s0, 0x16($s6)
    MEM_H(0X16, ctx->r22) = ctx->r16;
    // sh          $s1, 0x18($s6)
    MEM_H(0X18, ctx->r22) = ctx->r17;
    // jal         0x80079D0C
    // sh          $s2, 0x1A($s6)
    MEM_H(0X1A, ctx->r22) = ctx->r18;
    LoadImage(rdram, ctx);
    goto after_9;
    // sh          $s2, 0x1A($s6)
    MEM_H(0X1A, ctx->r22) = ctx->r18;
    after_9:
    // j           L_80016F6C
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    goto L_80016F6C;
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
L_80016F64:
    // sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
L_80016F68:
    // addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
L_80016F6C:
    // addiu       $fp, $fp, 0x18
    ctx->r30 = ADD32(ctx->r30, 0X18);
    // lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(0X18, ctx->r29);
    // addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // addiu       $t8, $t8, -0x1
    ctx->r24 = ADD32(ctx->r24, -0X1);
    // bne         $t8, $t9, L_80016A60
    if (ctx->r24 != ctx->r25) {
        // sw          $t8, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_80016A60;
    }
    // sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
    // lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(0X40, ctx->r29);
    // lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(0X3C, ctx->r29);
    // lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(0X38, ctx->r29);
    // lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
