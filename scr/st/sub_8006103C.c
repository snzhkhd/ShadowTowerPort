#include "recomp.h"
#include "disable_warnings.h"

void sub_8006103C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x2C0
    ctx->r29 = ADD32(ctx->r29, -0X2C0);
    // sw          $s2, 0x2B0($sp)
    MEM_W(0X2B0, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x2B4($sp)
    MEM_W(0X2B4, ctx->r29) = ctx->r19;
    // lui         $s3, 0x1F80
    ctx->r19 = S32(0X1F80 << 16);
    // sll         $v0, $s2, 3
    ctx->r2 = S32(ctx->r18) << 3;
    // subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
    // sw          $ra, 0x2BC($sp)
    MEM_W(0X2BC, ctx->r29) = ctx->r31;
    // sw          $s4, 0x2B8($sp)
    MEM_W(0X2B8, ctx->r29) = ctx->r20;
    // sw          $s1, 0x2AC($sp)
    MEM_W(0X2AC, ctx->r29) = ctx->r17;
    // sw          $s0, 0x2A8($sp)
    MEM_W(0X2A8, ctx->r29) = ctx->r16;
    // lhu         $v1, 0x2DC($s3)
    ctx->r3 = MEM_HU(0X2DC, ctx->r19);
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // andi        $v1, $v1, 0xFF00
    ctx->r3 = ctx->r3 & 0XFF00;
    // beq         $v1, $zero, L_800611AC
    if (ctx->r3 == 0) {
        // sw          $v0, 0x1F4($s3)
        MEM_W(0X1F4, ctx->r19) = ctx->r2;
        goto L_800611AC;
    }
    // sw          $v0, 0x1F4($s3)
    MEM_W(0X1F4, ctx->r19) = ctx->r2;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7F34
    ctx->r6 = ADD32(ctx->r2, -0X7F34);
    // lh          $v1, 0x0($a2)
    ctx->r3 = MEM_HS(0X0, ctx->r6);
    // lb          $a0, 0x2($a2)
    ctx->r4 = MEM_BS(0X2, ctx->r6);
    // sh          $v1, 0x268($sp)
    MEM_H(0X268, ctx->r29) = ctx->r3;
    // sb          $a0, 0x26A($sp)
    MEM_B(0X26A, ctx->r29) = ctx->r4;
    // jal         0x80078AE4
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    itoa(rdram, ctx);
    goto after_0;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // addiu       $s0, $sp, 0x268
    ctx->r16 = ADD32(ctx->r29, 0X268);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80078A64
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    strcat_recomp(rdram, ctx);
    goto after_1;
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_1:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // jal         0x80078A64
    // addiu       $a1, $a1, -0x7F30
    ctx->r5 = ADD32(ctx->r5, -0X7F30);
    strcat_recomp(rdram, ctx);
    goto after_2;
    // addiu       $a1, $a1, -0x7F30
    ctx->r5 = ADD32(ctx->r5, -0X7F30);
    after_2:
    // lw          $v0, 0x1F4($s3)
    ctx->r2 = MEM_W(0X1F4, ctx->r19);
    // nop

    // sh          $zero, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = 0;
    // lw          $v0, 0x1F4($s3)
    ctx->r2 = MEM_W(0X1F4, ctx->r19);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lh          $v0, 0xE2($v0)
    ctx->r2 = MEM_HS(0XE2, ctx->r2);
    // addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5) << 3;
    // jal         0x800780B4
    // addu        $a1, $s0, $a1
    ctx->r5 = ADD32(ctx->r16, ctx->r5);
    firstfile(rdram, ctx);
    goto after_3;
    // addu        $a1, $s0, $a1
    ctx->r5 = ADD32(ctx->r16, ctx->r5);
    after_3:
    // beq         $v0, $zero, L_80061148
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80061148;
    }
    // nop

L_80061104:
    // lw          $v1, 0x1F4($s3)
    ctx->r3 = MEM_W(0X1F4, ctx->r19);
    // nop

    // lhu         $v0, 0xE2($v1)
    ctx->r2 = MEM_HU(0XE2, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0xE2($v1)
    MEM_H(0XE2, ctx->r3) = ctx->r2;
    // lw          $v0, 0x1F4($s3)
    ctx->r2 = MEM_W(0X1F4, ctx->r19);
    // nop

    // lh          $v0, 0xE2($v0)
    ctx->r2 = MEM_HS(0XE2, ctx->r2);
    // nop

    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // jal         0x80077F14
    // addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    nextfile(rdram, ctx);
    goto after_4;
    // addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    after_4:
    // bne         $v0, $zero, L_80061104
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80061104;
    }
    // nop

L_80061148:
    // lw          $v0, 0x1F4($s3)
    ctx->r2 = MEM_W(0X1F4, ctx->r19);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lh          $v0, 0xE2($v0)
    ctx->r2 = MEM_HS(0XE2, ctx->r2);
    // nop

    // blez        $v0, L_80061180
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $s1, $a0, $zero
        ctx->r17 = ADD32(ctx->r4, 0);
        goto L_80061180;
    }
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
L_80061168:
    // lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(0X18, ctx->r3);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // slt         $v0, $s1, $a1
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_80061168
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x28
        ctx->r3 = ADD32(ctx->r3, 0X28);
        goto L_80061168;
    }
    // addiu       $v1, $v1, 0x28
    ctx->r3 = ADD32(ctx->r3, 0X28);
L_80061180:
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0xA000
    ctx->r2 = ctx->r2 | 0XA000;
    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_800611A0
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_800611A0;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lw          $v0, 0x1F4($s3)
    ctx->r2 = MEM_W(0X1F4, ctx->r19);
    // j           L_800611AC
    // sh          $zero, 0xE4($v0)
    MEM_H(0XE4, ctx->r2) = 0;
    goto L_800611AC;
    // sh          $zero, 0xE4($v0)
    MEM_H(0XE4, ctx->r2) = 0;
L_800611A0:
    // lw          $v1, 0x1F4($s3)
    ctx->r3 = MEM_W(0X1F4, ctx->r19);
    // nop

    // sh          $v0, 0xE4($v1)
    MEM_H(0XE4, ctx->r3) = ctx->r2;
L_800611AC:
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7F34
    ctx->r6 = ADD32(ctx->r2, -0X7F34);
    // lh          $v1, 0x0($a2)
    ctx->r3 = MEM_HS(0X0, ctx->r6);
    // lb          $a0, 0x2($a2)
    ctx->r4 = MEM_BS(0X2, ctx->r6);
    // sh          $v1, 0x268($sp)
    MEM_H(0X268, ctx->r29) = ctx->r3;
    // sb          $a0, 0x26A($sp)
    MEM_B(0X26A, ctx->r29) = ctx->r4;
    // jal         0x80078AE4
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    itoa(rdram, ctx);
    goto after_5;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_5:
    // addiu       $s0, $sp, 0x268
    ctx->r16 = ADD32(ctx->r29, 0X268);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80078A64
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    strcat_recomp(rdram, ctx);
    goto after_6;
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_6:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // jal         0x80078A64
    // addiu       $a1, $a1, -0x7F2C
    ctx->r5 = ADD32(ctx->r5, -0X7F2C);
    strcat_recomp(rdram, ctx);
    goto after_7;
    // addiu       $a1, $a1, -0x7F2C
    ctx->r5 = ADD32(ctx->r5, -0X7F2C);
    after_7:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // jal         0x80078A64
    // addiu       $a1, $a1, 0x2A68
    ctx->r5 = ADD32(ctx->r5, 0X2A68);
    strcat_recomp(rdram, ctx);
    goto after_8;
    // addiu       $a1, $a1, 0x2A68
    ctx->r5 = ADD32(ctx->r5, 0X2A68);
    after_8:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // jal         0x80078A64
    // addiu       $a1, $a1, -0x7F28
    ctx->r5 = ADD32(ctx->r5, -0X7F28);
    strcat_recomp(rdram, ctx);
    goto after_9;
    // addiu       $a1, $a1, -0x7F28
    ctx->r5 = ADD32(ctx->r5, -0X7F28);
    after_9:
    // lw          $v0, 0x1F4($s3)
    ctx->r2 = MEM_W(0X1F4, ctx->r19);
    // nop

    // sh          $zero, 0xE2($v0)
    MEM_H(0XE2, ctx->r2) = 0;
    // lw          $v0, 0x1F4($s3)
    ctx->r2 = MEM_W(0X1F4, ctx->r19);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lh          $v0, 0xE2($v0)
    ctx->r2 = MEM_HS(0XE2, ctx->r2);
    // addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5) << 3;
    // jal         0x800780B4
    // addu        $a1, $s0, $a1
    ctx->r5 = ADD32(ctx->r16, ctx->r5);
    firstfile(rdram, ctx);
    goto after_10;
    // addu        $a1, $s0, $a1
    ctx->r5 = ADD32(ctx->r16, ctx->r5);
    after_10:
    // beq         $v0, $zero, L_80061288
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80061288;
    }
    // nop

L_80061244:
    // lw          $v1, 0x1F4($s3)
    ctx->r3 = MEM_W(0X1F4, ctx->r19);
    // nop

    // lhu         $v0, 0xE2($v1)
    ctx->r2 = MEM_HU(0XE2, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0xE2($v1)
    MEM_H(0XE2, ctx->r3) = ctx->r2;
    // lw          $v0, 0x1F4($s3)
    ctx->r2 = MEM_W(0X1F4, ctx->r19);
    // nop

    // lh          $v0, 0xE2($v0)
    ctx->r2 = MEM_HS(0XE2, ctx->r2);
    // nop

    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // jal         0x80077F14
    // addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    nextfile(rdram, ctx);
    goto after_11;
    // addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    after_11:
    // bne         $v0, $zero, L_80061244
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80061244;
    }
    // nop

L_80061288:
    // lw          $v0, 0x1F4($s3)
    ctx->r2 = MEM_W(0X1F4, ctx->r19);
    // nop

    // lh          $v0, 0xE2($v0)
    ctx->r2 = MEM_HS(0XE2, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800612EC
    if (ctx->r2 != 0) {
        // addiu       $s1, $zero, 0x7
        ctx->r17 = ADD32(0, 0X7);
        goto L_800612EC;
    }
    // addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    // lhu         $v0, 0x2DC($s3)
    ctx->r2 = MEM_HU(0X2DC, ctx->r19);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // andi        $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 & 0XFF00;
    // beq         $v0, $zero, L_800612DC
    if (ctx->r2 == 0) {
        // sh          $v1, 0x204($s3)
        MEM_H(0X204, ctx->r19) = ctx->r3;
        goto L_800612DC;
    }
    // sh          $v1, 0x204($s3)
    MEM_H(0X204, ctx->r19) = ctx->r3;
    // lw          $v1, 0x1F4($s3)
    ctx->r3 = MEM_W(0X1F4, ctx->r19);
    // nop

    // lh          $v0, 0xE4($v1)
    ctx->r2 = MEM_HS(0XE4, ctx->r3);
    // nop

    // bne         $v0, $zero, L_800612D4
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_800612D4;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // j           L_800613C4
    // sh          $v0, 0xE0($v1)
    MEM_H(0XE0, ctx->r3) = ctx->r2;
    goto L_800613C4;
    // sh          $v0, 0xE0($v1)
    MEM_H(0XE0, ctx->r3) = ctx->r2;
L_800612D4:
    // j           L_800613C4
    // sh          $zero, 0xE0($v1)
    MEM_H(0XE0, ctx->r3) = 0;
    goto L_800613C4;
    // sh          $zero, 0xE0($v1)
    MEM_H(0XE0, ctx->r3) = 0;
L_800612DC:
    // lw          $v1, 0x1F4($s3)
    ctx->r3 = MEM_W(0X1F4, ctx->r19);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // j           L_800613C4
    // sh          $v0, 0xE0($v1)
    MEM_H(0XE0, ctx->r3) = ctx->r2;
    goto L_800613C4;
    // sh          $v0, 0xE0($v1)
    MEM_H(0XE0, ctx->r3) = ctx->r2;
L_800612EC:
    // addiu       $v0, $sp, 0x2C
    ctx->r2 = ADD32(ctx->r29, 0X2C);
L_800612F0:
    // sw          $zero, 0x278($v0)
    MEM_W(0X278, ctx->r2) = 0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bgez        $s1, L_800612F0
    if (SIGNED(ctx->r17) >= 0) {
        // addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
        goto L_800612F0;
    }
    // addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // lw          $a0, 0x1F4($s3)
    ctx->r4 = MEM_W(0X1F4, ctx->r19);
    // nop

    // lh          $v0, 0xE2($a0)
    ctx->r2 = MEM_HS(0XE2, ctx->r4);
    // nop

    // blez        $v0, L_8006138C
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
        goto L_8006138C;
    }
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // addiu       $s2, $sp, 0x10
    ctx->r18 = ADD32(ctx->r29, 0X10);
    // addu        $s4, $s2, $zero
    ctx->r20 = ADD32(ctx->r18, 0);
L_80061320:
    // sll         $s0, $s1, 5
    ctx->r16 = S32(ctx->r17) << 5;
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // jal         0x80078A94
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    strcpy_recomp(rdram, ctx);
    goto after_12;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_12:
    // lbu         $v0, 0x11($s2)
    ctx->r2 = MEM_BU(0X11, ctx->r18);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // lbu         $v0, 0x12($s2)
    ctx->r2 = MEM_BU(0X12, ctx->r18);
    // addiu       $a0, $a0, -0x30
    ctx->r4 = ADD32(ctx->r4, -0X30);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // sw          $v1, 0x278($v0)
    MEM_W(0X278, ctx->r2) = ctx->r3;
    // lw          $v0, 0x1F4($s3)
    ctx->r2 = MEM_W(0X1F4, ctx->r19);
    // nop

    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
    // lw          $a0, 0x1F4($s3)
    ctx->r4 = MEM_W(0X1F4, ctx->r19);
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // lh          $v0, 0xE2($a0)
    ctx->r2 = MEM_HS(0XE2, ctx->r4);
    // nop

    // slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_80061320
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x28
        ctx->r18 = ADD32(ctx->r18, 0X28);
        goto L_80061320;
    }
    // addiu       $s2, $s2, 0x28
    ctx->r18 = ADD32(ctx->r18, 0X28);
L_8006138C:
    // addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // addiu       $v1, $sp, 0x14
    ctx->r3 = ADD32(ctx->r29, 0X14);
L_80061398:
    // lw          $v0, 0x278($v1)
    ctx->r2 = MEM_W(0X278, ctx->r3);
    // nop

    // bne         $v0, $a0, L_800613B8
    if (ctx->r2 != ctx->r4) {
        // nop
    
        goto L_800613B8;
    }
    // nop

    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_80061398
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
        goto L_80061398;
    }
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800613B8:
    // lw          $v0, 0x1F4($s3)
    ctx->r2 = MEM_W(0X1F4, ctx->r19);
    // sh          $s1, 0x204($s3)
    MEM_H(0X204, ctx->r19) = ctx->r17;
    // sh          $zero, 0xE0($v0)
    MEM_H(0XE0, ctx->r2) = 0;
L_800613C4:
    // lw          $ra, 0x2BC($sp)
    ctx->r31 = MEM_W(0X2BC, ctx->r29);
    // lw          $s4, 0x2B8($sp)
    ctx->r20 = MEM_W(0X2B8, ctx->r29);
    // lw          $s3, 0x2B4($sp)
    ctx->r19 = MEM_W(0X2B4, ctx->r29);
    // lw          $s2, 0x2B0($sp)
    ctx->r18 = MEM_W(0X2B0, ctx->r29);
    // lw          $s1, 0x2AC($sp)
    ctx->r17 = MEM_W(0X2AC, ctx->r29);
    // lw          $s0, 0x2A8($sp)
    ctx->r16 = MEM_W(0X2A8, ctx->r29);
    // addiu       $sp, $sp, 0x2C0
    ctx->r29 = ADD32(ctx->r29, 0X2C0);
    // jr          $ra
    // nop

    return;
    // nop

;}
