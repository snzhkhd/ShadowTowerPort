#include "recomp.h"
#include "disable_warnings.h"

void sub_80045044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // lbu         $fp, 0x64($sp)
    ctx->r30 = MEM_BU(0X64, ctx->r29);
    // lbu         $t6, 0x68($sp)
    ctx->r14 = MEM_BU(0X68, ctx->r29);
    // lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(0X60, ctx->r29);
    // sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // sb          $t6, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r14;
    // lbu         $t6, 0x6C($sp)
    ctx->r14 = MEM_BU(0X6C, ctx->r29);
    // addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // sb          $t6, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r14;
    // lbu         $t6, 0x70($sp)
    ctx->r14 = MEM_BU(0X70, ctx->r29);
    // andi        $t0, $s6, 0xFF
    ctx->r8 = ctx->r22 & 0XFF;
    // sb          $t6, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r14;
    // lbu         $t6, 0x74($sp)
    ctx->r14 = MEM_BU(0X74, ctx->r29);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // sb          $t6, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r14;
    // lbu         $t6, 0x78($sp)
    ctx->r14 = MEM_BU(0X78, ctx->r29);
    // addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // bne         $t0, $v0, L_80045174
    if (ctx->r8 != ctx->r2) {
        // sb          $t6, 0x22($sp)
        MEM_B(0X22, ctx->r29) = ctx->r14;
        goto L_80045174;
    }
    // sb          $t6, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r14;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v1, $v0, 0x5920
    ctx->r3 = ADD32(ctx->r2, 0X5920);
    // andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // lbu         $s5, 0x4($v1)
    ctx->r21 = MEM_BU(0X4, ctx->r3);
    // lbu         $t5, 0x10($v1)
    ctx->r13 = MEM_BU(0X10, ctx->r3);
    // bne         $v0, $t0, L_800450EC
    if (ctx->r2 != ctx->r8) {
        // addu        $t4, $a1, $zero
        ctx->r12 = ADD32(ctx->r5, 0);
        goto L_800450EC;
    }
    // addu        $t4, $a1, $zero
    ctx->r12 = ADD32(ctx->r5, 0);
    // lbu         $a1, 0x5($v1)
    ctx->r5 = MEM_BU(0X5, ctx->r3);
    // lbu         $t4, 0x11($v1)
    ctx->r12 = MEM_BU(0X11, ctx->r3);
    // j           L_800450F0
    // andi        $v1, $s4, 0xFF
    ctx->r3 = ctx->r20 & 0XFF;
    goto L_800450F0;
    // andi        $v1, $s4, 0xFF
    ctx->r3 = ctx->r20 & 0XFF;
L_800450EC:
    // andi        $v1, $s4, 0xFF
    ctx->r3 = ctx->r20 & 0XFF;
L_800450F0:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // bne         $v1, $v0, L_80045114
    if (ctx->r3 != ctx->r2) {
        // addu        $a2, $s4, $zero
        ctx->r6 = ADD32(ctx->r20, 0);
        goto L_80045114;
    }
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v0, $v0, 0x5920
    ctx->r2 = ADD32(ctx->r2, 0X5920);
    // lbu         $t3, 0x6($v0)
    ctx->r11 = MEM_BU(0X6, ctx->r2);
    // lbu         $a2, 0x12($v0)
    ctx->r6 = MEM_BU(0X12, ctx->r2);
    // j           L_8004511C
    // andi        $v1, $s2, 0xFF
    ctx->r3 = ctx->r18 & 0XFF;
    goto L_8004511C;
    // andi        $v1, $s2, 0xFF
    ctx->r3 = ctx->r18 & 0XFF;
L_80045114:
    // addu        $t3, $s4, $zero
    ctx->r11 = ADD32(ctx->r20, 0);
    // andi        $v1, $s2, 0xFF
    ctx->r3 = ctx->r18 & 0XFF;
L_8004511C:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // bne         $v1, $v0, L_80045140
    if (ctx->r3 != ctx->r2) {
        // addu        $a3, $s2, $zero
        ctx->r7 = ADD32(ctx->r18, 0);
        goto L_80045140;
    }
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v0, $v0, 0x5920
    ctx->r2 = ADD32(ctx->r2, 0X5920);
    // lbu         $t1, 0x7($v0)
    ctx->r9 = MEM_BU(0X7, ctx->r2);
    // lbu         $a3, 0x13($v0)
    ctx->r7 = MEM_BU(0X13, ctx->r2);
    // j           L_80045148
    // andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
    goto L_80045148;
    // andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
L_80045140:
    // addu        $t1, $s2, $zero
    ctx->r9 = ADD32(ctx->r18, 0);
    // andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
L_80045148:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // bne         $v1, $v0, L_8004516C
    if (ctx->r3 != ctx->r2) {
        // addu        $t2, $s3, $zero
        ctx->r10 = ADD32(ctx->r19, 0);
        goto L_8004516C;
    }
    // addu        $t2, $s3, $zero
    ctx->r10 = ADD32(ctx->r19, 0);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v0, $v0, 0x5920
    ctx->r2 = ADD32(ctx->r2, 0X5920);
    // lbu         $t0, 0x8($v0)
    ctx->r8 = MEM_BU(0X8, ctx->r2);
    // lbu         $t2, 0x14($v0)
    ctx->r10 = MEM_BU(0X14, ctx->r2);
    // j           L_800451A0
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    goto L_800451A0;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_8004516C:
    // j           L_8004519C
    // addu        $t0, $s3, $zero
    ctx->r8 = ADD32(ctx->r19, 0);
    goto L_8004519C;
    // addu        $t0, $s3, $zero
    ctx->r8 = ADD32(ctx->r19, 0);
L_80045174:
    // addu        $t4, $a1, $zero
    ctx->r12 = ADD32(ctx->r5, 0);
    // addu        $t2, $v1, $zero
    ctx->r10 = ADD32(ctx->r3, 0);
    // addu        $t5, $a0, $zero
    ctx->r13 = ADD32(ctx->r4, 0);
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v0, $v0, 0x5920
    ctx->r2 = ADD32(ctx->r2, 0X5920);
    // lbu         $a1, 0x5($v0)
    ctx->r5 = MEM_BU(0X5, ctx->r2);
    // lbu         $t3, 0x6($v0)
    ctx->r11 = MEM_BU(0X6, ctx->r2);
    // lbu         $t1, 0x7($v0)
    ctx->r9 = MEM_BU(0X7, ctx->r2);
    // lbu         $t0, 0x8($v0)
    ctx->r8 = MEM_BU(0X8, ctx->r2);
L_8004519C:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_800451A0:
    // lh          $v1, 0x5920($v0)
    ctx->r3 = MEM_HS(0X5920, ctx->r2);
    // nop

    // bne         $v1, $zero, L_800452E0
    if (ctx->r3 != 0) {
        // addiu       $a0, $v0, 0x5920
        ctx->r4 = ADD32(ctx->r2, 0X5920);
        goto L_800452E0;
    }
    // addiu       $a0, $v0, 0x5920
    ctx->r4 = ADD32(ctx->r2, 0X5920);
    // lbu         $v1, 0x4($a0)
    ctx->r3 = MEM_BU(0X4, ctx->r4);
    // andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // bne         $v1, $v0, L_80045204
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80045204;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v1, 0x5($a0)
    ctx->r3 = MEM_BU(0X5, ctx->r4);
    // andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // bne         $v1, $v0, L_80045204
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80045204;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v1, 0x6($a0)
    ctx->r3 = MEM_BU(0X6, ctx->r4);
    // andi        $v0, $t3, 0xFF
    ctx->r2 = ctx->r11 & 0XFF;
    // bne         $v1, $v0, L_80045204
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80045204;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v1, 0x7($a0)
    ctx->r3 = MEM_BU(0X7, ctx->r4);
    // andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    // bne         $v1, $v0, L_80045204
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80045204;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v1, 0x8($a0)
    ctx->r3 = MEM_BU(0X8, ctx->r4);
    // andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // beq         $v1, $v0, L_80045534
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80045534;
    }
    // nop

L_80045200:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_80045204:
    // addiu       $a0, $v0, 0x5920
    ctx->r4 = ADD32(ctx->r2, 0X5920);
    // lbu         $v1, 0x4($a0)
    ctx->r3 = MEM_BU(0X4, ctx->r4);
    // addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // beq         $v1, $v0, L_80045228
    if (ctx->r3 == ctx->r2) {
        // andi        $v0, $s5, 0xFF
        ctx->r2 = ctx->r21 & 0XFF;
        goto L_80045228;
    }
    // andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // beq         $v1, $v0, L_80045228
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80045228;
    }
    // nop

    // jal         0x80055CF4
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    sub_80055CF4(rdram, ctx);
    goto after_0;
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_0:
L_80045228:
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $v0, 0x5920($v1)
    MEM_H(0X5920, ctx->r3) = ctx->r2;
    // addiu       $v1, $v1, 0x5920
    ctx->r3 = ADD32(ctx->r3, 0X5920);
    // sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // sb          $s6, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r22;
    // sb          $s7, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r23;
    // sb          $s4, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r20;
    // sb          $s2, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r18;
    // sb          $s3, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r19;
    // sb          $fp, 0x20($v1)
    MEM_B(0X20, ctx->r3) = ctx->r30;
    // lbu         $t6, 0x10($sp)
    ctx->r14 = MEM_BU(0X10, ctx->r29);
    // nop

    // sb          $t6, 0x21($v1)
    MEM_B(0X21, ctx->r3) = ctx->r14;
    // lbu         $t6, 0x18($sp)
    ctx->r14 = MEM_BU(0X18, ctx->r29);
    // nop

    // sb          $t6, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r14;
    // lbu         $t6, 0x20($sp)
    ctx->r14 = MEM_BU(0X20, ctx->r29);
    // nop

    // sb          $t6, 0x23($v1)
    MEM_B(0X23, ctx->r3) = ctx->r14;
    // lbu         $t6, 0x21($sp)
    ctx->r14 = MEM_BU(0X21, ctx->r29);
    // andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // sb          $t6, 0x24($v1)
    MEM_B(0X24, ctx->r3) = ctx->r14;
    // lbu         $t6, 0x22($sp)
    ctx->r14 = MEM_BU(0X22, ctx->r29);
    // sltiu       $v0, $v0, 0x2C
    ctx->r2 = ctx->r2 < 0X2C ? 1 : 0;
    // sb          $t6, 0x25($v1)
    MEM_B(0X25, ctx->r3) = ctx->r14;
    // beq         $v0, $zero, L_800452A8
    if (ctx->r2 == 0) {
        // sb          $zero, 0x1C($v1)
        MEM_B(0X1C, ctx->r3) = 0;
        goto L_800452A8;
    }
    // sb          $zero, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = 0;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lw          $v0, -0x7DFC($v0)
    ctx->r2 = MEM_W(-0X7DFC, ctx->r2);
    // j           L_800452B0
    // sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    goto L_800452B0;
    // sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
L_800452A8:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
L_800452B0:
    // andi        $v1, $s7, 0xFF
    ctx->r3 = ctx->r23 & 0XFF;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // bne         $v1, $v0, L_800452CC
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_800452CC;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // j           L_80045534
    // sb          $zero, 0x593D($v0)
    MEM_B(0X593D, ctx->r2) = 0;
    goto L_80045534;
    // sb          $zero, 0x593D($v0)
    MEM_B(0X593D, ctx->r2) = 0;
L_800452CC:
    // addiu       $v0, $v0, 0x5920
    ctx->r2 = ADD32(ctx->r2, 0X5920);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $v1, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r3;
    // j           L_80045534
    // sb          $v1, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = ctx->r3;
    goto L_80045534;
    // sb          $v1, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = ctx->r3;
L_800452E0:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_800452FC
    if (ctx->r3 != ctx->r2) {
        // andi        $v0, $t5, 0xFF
        ctx->r2 = ctx->r13 & 0XFF;
        goto L_800452FC;
    }
    // andi        $v0, $t5, 0xFF
    ctx->r2 = ctx->r13 & 0XFF;
    // lbu         $v1, 0x10($a0)
    ctx->r3 = MEM_BU(0X10, ctx->r4);
    // nop

    // bne         $v1, $v0, L_80045340
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80045340;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_800452FC:
    // lbu         $v1, 0x11($a0)
    ctx->r3 = MEM_BU(0X11, ctx->r4);
    // andi        $v0, $t4, 0xFF
    ctx->r2 = ctx->r12 & 0XFF;
    // bne         $v1, $v0, L_80045340
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80045340;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v1, 0x12($a0)
    ctx->r3 = MEM_BU(0X12, ctx->r4);
    // andi        $v0, $a2, 0xFF
    ctx->r2 = ctx->r6 & 0XFF;
    // bne         $v1, $v0, L_80045340
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80045340;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v1, 0x13($a0)
    ctx->r3 = MEM_BU(0X13, ctx->r4);
    // andi        $v0, $a3, 0xFF
    ctx->r2 = ctx->r7 & 0XFF;
    // bne         $v1, $v0, L_80045340
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80045340;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v1, 0x14($a0)
    ctx->r3 = MEM_BU(0X14, ctx->r4);
    // andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
    // beq         $v1, $v0, L_80045534
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80045534;
    }
    // nop

    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_80045340:
    // addiu       $a1, $v0, 0x5920
    ctx->r5 = ADD32(ctx->r2, 0X5920);
    // lbu         $t2, 0x10($a1)
    ctx->r10 = MEM_BU(0X10, ctx->r5);
    // addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // bne         $t2, $a0, L_80045364
    if (ctx->r10 != ctx->r4) {
        // andi        $v0, $s5, 0xFF
        ctx->r2 = ctx->r21 & 0XFF;
        goto L_80045364;
    }
    // andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // lbu         $v1, 0x4($a1)
    ctx->r3 = MEM_BU(0X4, ctx->r5);
    // nop

    // beq         $v1, $v0, L_80045534
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80045534;
    }
    // nop

L_80045364:
    // lbu         $t1, 0x11($a1)
    ctx->r9 = MEM_BU(0X11, ctx->r5);
    // nop

    // bne         $t1, $a0, L_80045384
    if (ctx->r9 != ctx->r4) {
        // andi        $v0, $s7, 0xFF
        ctx->r2 = ctx->r23 & 0XFF;
        goto L_80045384;
    }
    // andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // lbu         $v1, 0x5($a1)
    ctx->r3 = MEM_BU(0X5, ctx->r5);
    // nop

    // beq         $v1, $v0, L_80045534
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80045534;
    }
    // nop

L_80045384:
    // lbu         $t0, 0x12($a1)
    ctx->r8 = MEM_BU(0X12, ctx->r5);
    // nop

    // bne         $t0, $a0, L_800453A4
    if (ctx->r8 != ctx->r4) {
        // andi        $v0, $s4, 0xFF
        ctx->r2 = ctx->r20 & 0XFF;
        goto L_800453A4;
    }
    // andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // lbu         $v1, 0x6($a1)
    ctx->r3 = MEM_BU(0X6, ctx->r5);
    // nop

    // beq         $v1, $v0, L_80045534
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80045534;
    }
    // nop

L_800453A4:
    // lbu         $a3, 0x13($a1)
    ctx->r7 = MEM_BU(0X13, ctx->r5);
    // nop

    // bne         $a3, $a0, L_800453C4
    if (ctx->r7 != ctx->r4) {
        // andi        $v0, $s2, 0xFF
        ctx->r2 = ctx->r18 & 0XFF;
        goto L_800453C4;
    }
    // andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // lbu         $v1, 0x7($a1)
    ctx->r3 = MEM_BU(0X7, ctx->r5);
    // nop

    // beq         $v1, $v0, L_80045534
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80045534;
    }
    // nop

L_800453C4:
    // lbu         $a2, 0x14($a1)
    ctx->r6 = MEM_BU(0X14, ctx->r5);
    // nop

    // bne         $a2, $a0, L_800453E4
    if (ctx->r6 != ctx->r4) {
        // andi        $v0, $s3, 0xFF
        ctx->r2 = ctx->r19 & 0XFF;
        goto L_800453E4;
    }
    // andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // lbu         $v1, 0x8($a1)
    ctx->r3 = MEM_BU(0X8, ctx->r5);
    // nop

    // beq         $v1, $v0, L_80045534
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80045534;
    }
    // nop

L_800453E4:
    // beq         $t2, $a0, L_800453F4
    if (ctx->r10 == ctx->r4) {
        // andi        $v0, $s6, 0xFF
        ctx->r2 = ctx->r22 & 0XFF;
        goto L_800453F4;
    }
    // andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // beq         $v0, $a0, L_80045434
    if (ctx->r2 == ctx->r4) {
        // nop
    
        goto L_80045434;
    }
    // nop

L_800453F4:
    // beq         $t1, $a0, L_80045404
    if (ctx->r9 == ctx->r4) {
        // andi        $v0, $s7, 0xFF
        ctx->r2 = ctx->r23 & 0XFF;
        goto L_80045404;
    }
    // andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // beq         $v0, $a0, L_80045434
    if (ctx->r2 == ctx->r4) {
        // nop
    
        goto L_80045434;
    }
    // nop

L_80045404:
    // beq         $t0, $a0, L_80045414
    if (ctx->r8 == ctx->r4) {
        // andi        $v0, $s4, 0xFF
        ctx->r2 = ctx->r20 & 0XFF;
        goto L_80045414;
    }
    // andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // beq         $v0, $a0, L_80045434
    if (ctx->r2 == ctx->r4) {
        // nop
    
        goto L_80045434;
    }
    // nop

L_80045414:
    // beq         $a3, $a0, L_80045424
    if (ctx->r7 == ctx->r4) {
        // andi        $v0, $s2, 0xFF
        ctx->r2 = ctx->r18 & 0XFF;
        goto L_80045424;
    }
    // andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // beq         $v0, $a0, L_80045434
    if (ctx->r2 == ctx->r4) {
        // nop
    
        goto L_80045434;
    }
    // nop

L_80045424:
    // beq         $a2, $a0, L_8004547C
    if (ctx->r6 == ctx->r4) {
        // andi        $v0, $s3, 0xFF
        ctx->r2 = ctx->r19 & 0XFF;
        goto L_8004547C;
    }
    // andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // bne         $v0, $a0, L_80045480
    if (ctx->r2 != ctx->r4) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80045480;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_80045434:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // lh          $v0, 0x5920($v1)
    ctx->r2 = MEM_HS(0X5920, ctx->r3);
    // nop

    // beq         $v0, $zero, L_800454C4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800454C4;
    }
    // nop

    // addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_80045454:
    // jal         0x8001531C
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x800456F8
    // nop

    sub_800456F8(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lh          $v0, 0x5920($s0)
    ctx->r2 = MEM_HS(0X5920, ctx->r16);
    // nop

    // beq         $v0, $zero, L_800454C4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800454C4;
    }
    // nop

    // j           L_80045454
    // nop

    goto L_80045454;
    // nop

L_8004547C:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_80045480:
    // addiu       $a0, $v0, 0x5920
    ctx->r4 = ADD32(ctx->r2, 0X5920);
    // lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(0X2, ctx->r4);
    // addiu       $v1, $zero, 0xF0
    ctx->r3 = ADD32(0, 0XF0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_800454C4
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_800454C4;
    }
    // nop

    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_800454A4:
    // jal         0x8001531C
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // beq         $v0, $s0, L_800454A4
    if (ctx->r2 == ctx->r16) {
        // nop
    
        goto L_800454A4;
    }
    // nop

L_800454C4:
    // jal         0x80077EA4
    // nop

    ExitCriticalSection(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $a0, $v0, 0x5920
    ctx->r4 = ADD32(ctx->r2, 0X5920);
    // lbu         $v0, 0x1C($a0)
    ctx->r2 = MEM_BU(0X1C, ctx->r4);
    // nop

    // beq         $v0, $zero, L_80045200
    if (ctx->r2 == 0) {
        // andi        $a1, $s6, 0xFF
        ctx->r5 = ctx->r22 & 0XFF;
        goto L_80045200;
    }
    // andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $a1, $v0, L_80045200
    if (ctx->r5 == ctx->r2) {
        // sll         $v0, $fp, 24
        ctx->r2 = S32(ctx->r30) << 24;
        goto L_80045200;
    }
    // sll         $v0, $fp, 24
    ctx->r2 = S32(ctx->r30) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // bne         $v0, $v1, L_80045204
    if (ctx->r2 != ctx->r3) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80045204;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v0, 0x10($a0)
    ctx->r2 = MEM_BU(0X10, ctx->r4);
    // nop

    // beq         $v0, $a1, L_80045204
    if (ctx->r2 == ctx->r5) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80045204;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v0, 0x20($a0)
    ctx->r2 = MEM_BU(0X20, ctx->r4);
    // lbu         $v1, 0x21($a0)
    ctx->r3 = MEM_BU(0X21, ctx->r4);
    // negu        $fp, $v0
    ctx->r30 = SUB32(0, ctx->r2);
    // lbu         $v0, 0x22($a0)
    ctx->r2 = MEM_BU(0X22, ctx->r4);
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // sb          $v1, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r3;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // j           L_80045200
    // sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
    goto L_80045200;
    // sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
L_80045534:
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
