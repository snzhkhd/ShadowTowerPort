#include "recomp.h"
#include "disable_warnings.h"

void sub_8007D604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // bne         $v0, $v1, L_8007D658
    if (ctx->r2 != ctx->r3) {
        // addiu       $s1, $zero, 0x88
        ctx->r17 = ADD32(0, 0X88);
        goto L_8007D658;
    }
    // addiu       $s1, $zero, 0x88
    ctx->r17 = ADD32(0, 0X88);
    // lbu         $v0, 0x44($s0)
    ctx->r2 = MEM_BU(0X44, ctx->r16);
    // nop

    // sltiu       $v0, $v0, 0x9
    ctx->r2 = ctx->r2 < 0X9 ? 1 : 0;
    // bne         $v0, $zero, L_8007D658
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007D658;
    }
    // nop

    // addiu       $s1, $zero, 0x22
    ctx->r17 = ADD32(0, 0X22);
L_8007D658:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E7C($v1)
    ctx->r3 = MEM_W(0X7E7C, ctx->r3);
    // nop

L_8007D664:
    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // beq         $v0, $zero, L_8007D664
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007D664;
    }
    // nop

    // jal         0x8007F324
    // addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    setRC2wait(rdram, ctx);
    goto after_0;
    // addiu       $a0, $zero, 0x190
    ctx->r4 = ADD32(0, 0X190);
    after_0:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7E7C($a0)
    ctx->r4 = MEM_W(0X7E7C, ctx->r4);
    // nop

    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // lbu         $v1, 0x44($s0)
    ctx->r3 = MEM_BU(0X44, ctx->r16);
    // nop

    // bne         $v1, $zero, L_8007D6B0
    if (ctx->r3 != 0) {
        // andi        $s2, $v0, 0xFF
        ctx->r18 = ctx->r2 & 0XFF;
        goto L_8007D6B0;
    }
    // andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // sra         $v1, $s2, 4
    ctx->r3 = S32(ctx->r18) >> 4;
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // beq         $v1, $v0, L_8007D6BC
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x22
        ctx->r2 = ADD32(0, 0X22);
        goto L_8007D6BC;
    }
    // addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
L_8007D6B0:
    // sh          $s1, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r17;
    // j           L_8007D6C0
    // nop

    goto L_8007D6C0;
    // nop

L_8007D6BC:
    // sh          $v0, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r2;
L_8007D6C0:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E78($v1)
    ctx->r3 = MEM_W(0X7E78, ctx->r3);
    // nop

    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // bne         $v0, $zero, L_8007D790
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007D790;
    }
    // nop

    // lui         $t1, 0x1F80
    ctx->r9 = S32(0X1F80 << 16);
    // ori         $t1, $t1, 0x1120
    ctx->r9 = ctx->r9 | 0X1120;
    // lui         $a2, 0x1F80
    ctx->r6 = S32(0X1F80 << 16);
    // ori         $a2, $a2, 0x1128
    ctx->r6 = ctx->r6 | 0X1128;
    // lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // lui         $t0, 0x1F80
    ctx->r8 = S32(0X1F80 << 16);
    // ori         $t0, $t0, 0x1124
    ctx->r8 = ctx->r8 | 0X1124;
    // addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // lw          $a0, -0x4AA8($a0)
    ctx->r4 = MEM_W(-0X4AA8, ctx->r4);
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // lw          $a1, -0x4AA4($a1)
    ctx->r5 = MEM_W(-0X4AA4, ctx->r5);
L_8007D710:
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // nop

    // andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // sltu        $v0, $v1, $a0
    ctx->r2 = ctx->r3 < ctx->r4 ? 1 : 0;
    // beq         $v0, $zero, L_8007D748
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007D748;
    }
    // nop

    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // nop

    // beq         $v0, $zero, L_8007D744
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007D744;
    }
    // nop

    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // j           L_8007D748
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    goto L_8007D748;
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
L_8007D744:
    // addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
L_8007D748:
    // lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(0X0, ctx->r8);
    // nop

    // andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // beq         $v0, $zero, L_8007D768
    if (ctx->r2 == 0) {
        // subu        $v0, $v1, $a0
        ctx->r2 = SUB32(ctx->r3, ctx->r4);
        goto L_8007D768;
    }
    // subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // beq         $v0, $zero, L_8007D81C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
        goto L_8007D81C;
    }
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
L_8007D768:
    // subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // beq         $v0, $zero, L_8007D81C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
        goto L_8007D81C;
    }
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8007D710
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007D710;
    }
    // nop

L_8007D790:
    // lbu         $v1, 0xE8($s0)
    ctx->r3 = MEM_BU(0XE8, ctx->r16);
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // beq         $v1, $v0, L_8007D7CC
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8007D7CC;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E5C($v1)
    ctx->r3 = MEM_W(0X7E5C, ctx->r3);
    // nop

    // bne         $v1, $v0, L_8007D7CC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8007D7CC;
    }
    // nop

    // jal         0x8007F324
    // addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    setRC2wait(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_1:
L_8007D7BC:
    // jal         0x8007F344
    // nop

    chkRC2wait(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // beq         $v0, $zero, L_8007D7BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007D7BC;
    }
    // nop

L_8007D7CC:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E7C($v0)
    ctx->r2 = MEM_W(0X7E7C, ctx->r2);
    // nop

    // sb          $s3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r19;
    // lbu         $v0, 0x45($s0)
    ctx->r2 = MEM_BU(0X45, ctx->r16);
    // lbu         $v1, 0x44($s0)
    ctx->r3 = MEM_BU(0X44, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x45($s0)
    MEM_B(0X45, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8007D80C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8007D80C;
    }
    // nop

    // lbu         $v1, 0x44($s0)
    ctx->r3 = MEM_BU(0X44, ctx->r16);
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $s2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r18;
L_8007D80C:
    // lbu         $v1, 0x44($s0)
    ctx->r3 = MEM_BU(0X44, ctx->r16);
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sb          $v1, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r3;
L_8007D81C:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
