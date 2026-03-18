#include "recomp.h"
#include "disable_warnings.h"

void sub_80042620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, -0x7FC0
    ctx->r6 = ADD32(ctx->r2, -0X7FC0);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r3);
    // swr         $v1, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r3);
    // swl         $a0, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r4);
    // swr         $a0, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r4);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7FB8
    ctx->r6 = ADD32(ctx->r2, -0X7FB8);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r3);
    // swr         $v1, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r3);
    // swl         $a0, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r4);
    // swr         $a0, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r4);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v0, 0x3E($a1)
    ctx->r2 = MEM_HU(0X3E, ctx->r5);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // beq         $v0, $a2, L_800426F0
    if (ctx->r2 == ctx->r6) {
        // addiu       $s7, $zero, 0x1
        ctx->r23 = ADD32(0, 0X1);
        goto L_800426F0;
    }
    // addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $a0, $a0, 0x76F8
    ctx->r4 = ADD32(ctx->r4, 0X76F8);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x13E($v0)
    ctx->r3 = MEM_BU(0X13E, ctx->r2);
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // beq         $v1, $v0, L_80042730
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80042730;
    }
    // nop

L_800426F0:
    // lhu         $v0, 0x40($a1)
    ctx->r2 = MEM_HU(0X40, ctx->r5);
    // nop

    // beq         $v0, $a2, L_80042734
    if (ctx->r2 == ctx->r6) {
        // lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
        goto L_80042734;
    }
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $a0, $a0, 0x76F8
    ctx->r4 = ADD32(ctx->r4, 0X76F8);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x13E($v0)
    ctx->r3 = MEM_BU(0X13E, ctx->r2);
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // bne         $v1, $v0, L_80042738
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80042738;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80042730:
    // addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
L_80042734:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80042738:
    // addiu       $s4, $v0, -0x70D8
    ctx->r20 = ADD32(ctx->r2, -0X70D8);
    // ori         $fp, $zero, 0xFFFF
    ctx->r30 = 0 | 0XFFFF;
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
L_80042744:
    // bne         $v0, $zero, L_80042760
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80042760;
    }
    // nop

    // lhu         $v0, 0x40($s4)
    ctx->r2 = MEM_HU(0X40, ctx->r20);
    // lhu         $v1, 0x3E($s4)
    ctx->r3 = MEM_HU(0X3E, ctx->r20);
    // sh          $v0, 0x3E($s4)
    MEM_H(0X3E, ctx->r20) = ctx->r2;
    // j           L_80042770
    // sh          $v1, 0x40($s4)
    MEM_H(0X40, ctx->r20) = ctx->r3;
    goto L_80042770;
    // sh          $v1, 0x40($s4)
    MEM_H(0X40, ctx->r20) = ctx->r3;
L_80042760:
    // lhu         $v0, 0x5A($s4)
    ctx->r2 = MEM_HU(0X5A, ctx->r20);
    // lhu         $v1, 0x58($s4)
    ctx->r3 = MEM_HU(0X58, ctx->r20);
    // sh          $v0, 0x58($s4)
    MEM_H(0X58, ctx->r20) = ctx->r2;
    // sh          $v1, 0x5A($s4)
    MEM_H(0X5A, ctx->r20) = ctx->r3;
L_80042770:
    // andi        $s5, $a3, 0xFF
    ctx->r21 = ctx->r7 & 0XFF;
    // sll         $v0, $s5, 2
    ctx->r2 = S32(ctx->r21) << 2;
    // addu        $s0, $v0, $s4
    ctx->r16 = ADD32(ctx->r2, ctx->r20);
    // andi        $a0, $s6, 0xFF
    ctx->r4 = ctx->r22 & 0XFF;
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $s1, $v0, $s4
    ctx->r17 = ADD32(ctx->r2, ctx->r20);
    // lw          $v0, 0xE8($s1)
    ctx->r2 = MEM_W(0XE8, ctx->r17);
    // lw          $v1, 0xE8($s0)
    ctx->r3 = MEM_W(0XE8, ctx->r16);
    // sw          $v0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->r2;
    // lw          $v0, 0xF8($s1)
    ctx->r2 = MEM_W(0XF8, ctx->r17);
    // addu        $s2, $s5, $s4
    ctx->r18 = ADD32(ctx->r21, ctx->r20);
    // sw          $v1, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->r3;
    // lw          $v1, 0xF8($s0)
    ctx->r3 = MEM_W(0XF8, ctx->r16);
    // addu        $s3, $a0, $s4
    ctx->r19 = ADD32(ctx->r4, ctx->r20);
    // sw          $v0, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->r2;
    // sw          $v1, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->r3;
    // lbu         $v0, 0x148($s3)
    ctx->r2 = MEM_BU(0X148, ctx->r19);
    // lbu         $v1, 0x148($s2)
    ctx->r3 = MEM_BU(0X148, ctx->r18);
    // sb          $v0, 0x148($s2)
    MEM_B(0X148, ctx->r18) = ctx->r2;
    // sb          $v1, 0x148($s3)
    MEM_B(0X148, ctx->r19) = ctx->r3;
    // lbu         $v0, 0x148($s2)
    ctx->r2 = MEM_BU(0X148, ctx->r18);
    // addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // beq         $v0, $t0, L_800427E0
    if (ctx->r2 == ctx->r8) {
        // nop
    
        goto L_800427E0;
    }
    // nop

    // lw          $a1, 0xF8($s0)
    ctx->r5 = MEM_W(0XF8, ctx->r16);
    // andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // jal         0x80033A48
    // addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    sub_80033A48(rdram, ctx);
    goto after_0;
    // addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_0:
L_800427E0:
    // lbu         $v0, 0x148($s3)
    ctx->r2 = MEM_BU(0X148, ctx->r19);
    // addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // beq         $v0, $t0, L_80042800
    if (ctx->r2 == ctx->r8) {
        // nop
    
        goto L_80042800;
    }
    // nop

    // lw          $a1, 0xF8($s1)
    ctx->r5 = MEM_W(0XF8, ctx->r17);
    // andi        $a0, $s6, 0xFF
    ctx->r4 = ctx->r22 & 0XFF;
    // jal         0x80033A48
    // addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    sub_80033A48(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_1:
L_80042800:
    // lw          $v0, 0x108($s0)
    ctx->r2 = MEM_W(0X108, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80042814
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80042814;
    }
    // nop

    // sh          $fp, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r30;
L_80042814:
    // lw          $v0, 0x108($s1)
    ctx->r2 = MEM_W(0X108, ctx->r17);
    // nop

    // beq         $v0, $zero, L_80042828
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80042828;
    }
    // nop

    // sh          $fp, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r30;
L_80042828:
    // lbu         $v0, 0x1D4($s3)
    ctx->r2 = MEM_BU(0X1D4, ctx->r19);
    // lbu         $v1, 0x1D4($s2)
    ctx->r3 = MEM_BU(0X1D4, ctx->r18);
    // sb          $v0, 0x1D4($s2)
    MEM_B(0X1D4, ctx->r18) = ctx->r2;
    // bne         $s5, $zero, L_8004284C
    if (ctx->r21 != 0) {
        // sb          $v1, 0x1D4($s3)
        MEM_B(0X1D4, ctx->r19) = ctx->r3;
        goto L_8004284C;
    }
    // sb          $v1, 0x1D4($s3)
    MEM_B(0X1D4, ctx->r19) = ctx->r3;
    // sh          $zero, 0x17E($s4)
    MEM_H(0X17E, ctx->r20) = 0;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // j           L_80042854
    // addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    goto L_80042854;
    // addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
L_8004284C:
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
L_80042854:
    // addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // bne         $s7, $zero, L_80042744
    if (ctx->r23 != 0) {
        // andi        $v0, $a3, 0xFF
        ctx->r2 = ctx->r7 & 0XFF;
        goto L_80042744;
    }
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v0, 0x148($s0)
    ctx->r2 = MEM_BU(0X148, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1F
    ctx->r2 = ADD32(ctx->r2, -0X1F);
    // sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8004288C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004288C;
    }
    // nop

    // lw          $a1, 0xFC($s0)
    ctx->r5 = MEM_W(0XFC, ctx->r16);
    // jal         0x80033A48
    // addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    sub_80033A48(rdram, ctx);
    goto after_2;
    // addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_2:
L_8004288C:
    // lbu         $v0, 0x14A($s0)
    ctx->r2 = MEM_BU(0X14A, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1F
    ctx->r2 = ADD32(ctx->r2, -0X1F);
    // sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_800428B0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800428B0;
    }
    // nop

    // lw          $a1, 0x104($s0)
    ctx->r5 = MEM_W(0X104, ctx->r16);
    // jal         0x80033A48
    // addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    sub_80033A48(rdram, ctx);
    goto after_3;
    // addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_3:
L_800428B0:
    // sw          $zero, 0x108($s0)
    MEM_W(0X108, ctx->r16) = 0;
    // sw          $zero, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = 0;
    // sw          $zero, 0x110($s0)
    MEM_W(0X110, ctx->r16) = 0;
    // jal         0x8003CEDC
    // sw          $zero, 0x114($s0)
    MEM_W(0X114, ctx->r16) = 0;
    sub_8003CEDC(rdram, ctx);
    goto after_4;
    // sw          $zero, 0x114($s0)
    MEM_W(0X114, ctx->r16) = 0;
    after_4:
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sh          $v0, 0x18A($s0)
    MEM_H(0X18A, ctx->r16) = ctx->r2;
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
