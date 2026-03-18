#include "recomp.h"
#include "disable_warnings.h"

void sub_8004B658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // addiu       $s6, $zero, 0x7530
    ctx->r22 = ADD32(0, 0X7530);
    // sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // addiu       $s3, $v0, -0x5EC8
    ctx->r19 = ADD32(ctx->r2, -0X5EC8);
    // sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // addiu       $s5, $zero, 0x3F
    ctx->r21 = ADD32(0, 0X3F);
    // sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    // sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // sh          $a1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r5;
    // sh          $a2, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r6;
L_8004B6B0:
    // lbu         $v1, 0x5($s1)
    ctx->r3 = MEM_BU(0X5, ctx->r17);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8004B88C
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_8004B88C;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, 0x270($v0)
    ctx->r2 = MEM_W(0X270, ctx->r2);
    // nop

    // beq         $s3, $v0, L_8004B88C
    if (ctx->r19 == ctx->r2) {
        // nop
    
        goto L_8004B88C;
    }
    // nop

    // lui         $t0, 0x2
    ctx->r8 = S32(0X2 << 16);
    // lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(0X70, ctx->r17);
    // lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(0X7C, ctx->r29);
    // and         $v0, $v0, $t0
    ctx->r2 = ctx->r2 & ctx->r8;
    // beq         $v0, $zero, L_8004B6EC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004B6EC;
    }
    // nop

    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
L_8004B6EC:
    // lw          $v0, 0x74($s1)
    ctx->r2 = MEM_W(0X74, ctx->r17);
    // nop

    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lhu         $v1, 0x30($s1)
    ctx->r3 = MEM_HU(0X30, ctx->r17);
    // lw          $v0, 0x78($s1)
    ctx->r2 = MEM_W(0X78, ctx->r17);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lw          $v0, 0x7C($s1)
    ctx->r2 = MEM_W(0X7C, ctx->r17);
    // addiu       $a0, $s3, 0x74
    ctx->r4 = ADD32(ctx->r19, 0X74);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(0X0, ctx->r20);
    // lw          $a3, 0x8($s4)
    ctx->r7 = MEM_W(0X8, ctx->r20);
    // jal         0x8004A484
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    sub_8004A484(rdram, ctx);
    goto after_0;
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    after_0:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s2, $v0, L_8004B88C
    if (ctx->r18 == ctx->r2) {
        // addiu       $a3, $sp, 0x30
        ctx->r7 = ADD32(ctx->r29, 0X30);
        goto L_8004B88C;
    }
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // lw          $v0, 0x74($s1)
    ctx->r2 = MEM_W(0X74, ctx->r17);
    // lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(0X0, ctx->r20);
    // lw          $v1, 0x78($s1)
    ctx->r3 = MEM_W(0X78, ctx->r17);
    // lw          $a1, 0x4($s4)
    ctx->r5 = MEM_W(0X4, ctx->r20);
    // lw          $a2, 0x8($s4)
    ctx->r6 = MEM_W(0X8, ctx->r20);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // lw          $v0, 0x7C($s1)
    ctx->r2 = MEM_W(0X7C, ctx->r17);
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // jal         0x8004A390
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    sub_8004A390(rdram, ctx);
    goto after_1;
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    after_1:
    // lhu         $v0, 0x32($sp)
    ctx->r2 = MEM_HU(0X32, ctx->r29);
    // lhu         $t0, 0x38($sp)
    ctx->r8 = MEM_HU(0X38, ctx->r29);
    // nop

    // subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
    // slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_8004B798
    if (ctx->r2 != 0) {
        // sh          $v1, 0x32($sp)
        MEM_H(0X32, ctx->r29) = ctx->r3;
        goto L_8004B798;
    }
    // sh          $v1, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r3;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r2;
L_8004B798:
    // lhu         $v0, 0x30($sp)
    ctx->r2 = MEM_HU(0X30, ctx->r29);
    // lhu         $t0, 0x40($sp)
    ctx->r8 = MEM_HU(0X40, ctx->r29);
    // nop

    // subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
    // slti        $v0, $v1, 0x800
    ctx->r2 = SIGNED(ctx->r3) < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_8004B7C4
    if (ctx->r2 != 0) {
        // sh          $v1, 0x30($sp)
        MEM_H(0X30, ctx->r29) = ctx->r3;
        goto L_8004B7C4;
    }
    // sh          $v1, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r3;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r2;
L_8004B7C4:
    // lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(0X70, ctx->r17);
    // lui         $t0, 0x2
    ctx->r8 = S32(0X2 << 16);
    // and         $v0, $v0, $t0
    ctx->r2 = ctx->r2 & ctx->r8;
    // beq         $v0, $zero, L_8004B808
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004B808;
    }
    // nop

    // lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(0X8C, ctx->r29);
    // nop

    // bltz        $t0, L_8004B808
    if (SIGNED(ctx->r8) < 0) {
        // nop
    
        goto L_8004B808;
    }
    // nop

    // sra         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18) >> 2;
    // lhu         $v0, 0x30($sp)
    ctx->r2 = MEM_HU(0X30, ctx->r29);
    // lhu         $v1, 0x32($sp)
    ctx->r3 = MEM_HU(0X32, ctx->r29);
    // addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // addiu       $v1, $v1, -0x200
    ctx->r3 = ADD32(ctx->r3, -0X200);
    // sh          $v0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r2;
    // j           L_8004B838
    // sh          $v1, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r3;
    goto L_8004B838;
    // sh          $v1, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r3;
L_8004B808:
    // lh          $v0, 0x32($sp)
    ctx->r2 = MEM_HS(0X32, ctx->r29);
    // lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(0X80, ctx->r29);
    // nop

    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8004B88C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004B88C;
    }
    // nop

    // lh          $v0, 0x30($sp)
    ctx->r2 = MEM_HS(0X30, ctx->r29);
    // lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(0X84, ctx->r29);
    // nop

    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8004B88C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004B88C;
    }
    // nop

L_8004B838:
    // lh          $v0, 0x32($sp)
    ctx->r2 = MEM_HS(0X32, ctx->r29);
    // lh          $v1, 0x30($sp)
    ctx->r3 = MEM_HS(0X30, ctx->r29);
    // lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(0X8C, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v1, $s2, 7
    ctx->r3 = S32(ctx->r18) >> 7;
    // blez        $t0, L_8004B874
    if (SIGNED(ctx->r8) <= 0) {
        // addu        $s0, $v0, $v1
        ctx->r16 = ADD32(ctx->r2, ctx->r3);
        goto L_8004B874;
    }
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(0X8C, ctx->r29);
    // nop

    // mult        $v0, $t0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t0
    ctx->r8 = lo;
    // sra         $v0, $t0, 15
    ctx->r2 = S32(ctx->r8) >> 15;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_8004B874:
    // slt         $v0, $s0, $s6
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r22) ? 1 : 0;
    // beq         $v0, $zero, L_8004B88C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004B88C;
    }
    // nop

    // addu        $s6, $s0, $zero
    ctx->r22 = ADD32(ctx->r16, 0);
    // addu        $fp, $s1, $zero
    ctx->r30 = ADD32(ctx->r17, 0);
    // addu        $s7, $s2, $zero
    ctx->r23 = ADD32(ctx->r18, 0);
L_8004B88C:
    // addiu       $s1, $s1, 0xD4
    ctx->r17 = ADD32(ctx->r17, 0XD4);
    // addiu       $v1, $s5, -0x1
    ctx->r3 = ADD32(ctx->r21, -0X1);
    // addu        $s5, $v1, $zero
    ctx->r21 = ADD32(ctx->r3, 0);
    // andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $v1, $v0, L_8004B6B0
    if (ctx->r3 != ctx->r2) {
        // addiu       $s3, $s3, 0xD4
        ctx->r19 = ADD32(ctx->r19, 0XD4);
        goto L_8004B6B0;
    }
    // addiu       $s3, $s3, 0xD4
    ctx->r19 = ADD32(ctx->r19, 0XD4);
    // lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(0X88, ctx->r29);
    // nop

    // sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // addu        $v0, $fp, $zero
    ctx->r2 = ADD32(ctx->r30, 0);
    // lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(0X6C, ctx->r29);
    // lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(0X68, ctx->r29);
    // lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(0X64, ctx->r29);
    // lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(0X60, ctx->r29);
    // lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(0X5C, ctx->r29);
    // lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(0X58, ctx->r29);
    // lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(0X54, ctx->r29);
    // lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(0X50, ctx->r29);
    // lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(0X4C, ctx->r29);
    // lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(0X48, ctx->r29);
    // addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // jr          $ra
    // nop

    return;
    // nop

;}
