#include "recomp.h"
#include "disable_warnings.h"

void sub_800251C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // lui         $v1, 0x1F80
    ctx->r3 = S32(0X1F80 << 16);
    // ori         $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 | 0XF8;
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
    // ori         $v0, $v0, 0x244
    ctx->r2 = ctx->r2 | 0X244;
    // lui         $a0, 0x1F80
    ctx->r4 = S32(0X1F80 << 16);
    // ori         $a0, $a0, 0xF8
    ctx->r4 = ctx->r4 | 0XF8;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // sw          $ra, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r31;
    // sw          $fp, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r30;
    // sw          $s7, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r22;
    // sw          $s5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r21;
    // sw          $s4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r20;
    // sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // sw          $v1, 0xF0($s2)
    MEM_W(0XF0, ctx->r18) = ctx->r3;
    // jal         0x80014D5C
    // sw          $v0, 0xF4($s2)
    MEM_W(0XF4, ctx->r18) = ctx->r2;
    sub_80014D5C(rdram, ctx);
    goto after_0;
    // sw          $v0, 0xF4($s2)
    MEM_W(0XF4, ctx->r18) = ctx->r2;
    after_0:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v1, $v0, 0x76F8
    ctx->r3 = ADD32(ctx->r2, 0X76F8);
    // lbu         $fp, 0x6($v1)
    ctx->r30 = MEM_BU(0X6, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // beq         $fp, $v0, L_8002558C
    if (ctx->r30 == ctx->r2) {
        // sh          $zero, 0x98($s2)
        MEM_H(0X98, ctx->r18) = 0;
        goto L_8002558C;
    }
    // sh          $zero, 0x98($s2)
    MEM_H(0X98, ctx->r18) = 0;
    // addiu       $t0, $sp, 0x48
    ctx->r8 = ADD32(ctx->r29, 0X48);
    // sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
L_8002524C:
    // addiu       $t0, $t0, 0x76F8
    ctx->r8 = ADD32(ctx->r8, 0X76F8);
    // addu        $v0, $fp, $t0
    ctx->r2 = ADD32(ctx->r30, ctx->r8);
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // lbu         $v1, 0x7($v0)
    ctx->r3 = MEM_BU(0X7, ctx->r2);
    // addiu       $t0, $t0, 0x76F8
    ctx->r8 = ADD32(ctx->r8, 0X76F8);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addiu       $v1, $t0, 0x3710
    ctx->r3 = ADD32(ctx->r8, 0X3710);
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // addiu       $t0, $t0, 0x5090
    ctx->r8 = ADD32(ctx->r8, 0X5090);
    // lw          $a0, 0x6E00($t0)
    ctx->r4 = MEM_W(0X6E00, ctx->r8);
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // addiu       $t0, $t0, 0x7810
    ctx->r8 = ADD32(ctx->r8, 0X7810);
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
    // lw          $v1, 0x28($s1)
    ctx->r3 = MEM_W(0X28, ctx->r17);
    // nop

    // slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v1, $zero, L_800252C4
    if (ctx->r3 != 0) {
        // addu        $s3, $v0, $t0
        ctx->r19 = ADD32(ctx->r2, ctx->r8);
        goto L_800252C4;
    }
    // addu        $s3, $v0, $t0
    ctx->r19 = ADD32(ctx->r2, ctx->r8);
    // lbu         $v0, 0x24($s1)
    ctx->r2 = MEM_BU(0X24, ctx->r17);
    // nop

    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sb          $v0, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r2;
L_800252C4:
    // lbu         $v1, 0x22($s1)
    ctx->r3 = MEM_BU(0X22, ctx->r17);
    // nop

    // sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_800252F4
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_800252F4;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x1478
    ctx->r2 = ADD32(ctx->r2, 0X1478);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_800252EC;
    jr_addend_800252EC = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_800252EC >> 2) {
        case 0: goto L_8002557C; break;
        case 1: goto L_800252F4; break;
        case 2: goto L_800252F4; break;
        case 3: goto L_800252F4; break;
        case 4: goto L_8002557C; break;
        case 5: goto L_800252F4; break;
        default: switch_error(__func__, 0x800252EC, 0x80011478);
    }
    // nop

L_800252F4:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F0C
    ctx->r6 = ADD32(ctx->r2, 0X7F0C);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x4B($sp)
    do_swl(rdram, 0X4B, ctx->r29, ctx->r3);
    // swr         $v1, 0x48($sp)
    do_swr(rdram, 0X48, ctx->r29, ctx->r3);
    // swl         $a0, 0x4F($sp)
    do_swl(rdram, 0X4F, ctx->r29, ctx->r4);
    // swr         $a0, 0x4C($sp)
    do_swr(rdram, 0X4C, ctx->r29, ctx->r4);
    // lbu         $v0, 0x4($s3)
    ctx->r2 = MEM_BU(0X4, ctx->r19);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // sb          $v1, 0xF8($v0)
    MEM_B(0XF8, ctx->r2) = ctx->r3;
    // lbu         $a0, 0x4($s3)
    ctx->r4 = MEM_BU(0X4, ctx->r19);
    // addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // jal         0x80033DB8
    // addiu       $a0, $a0, 0x24C
    ctx->r4 = ADD32(ctx->r4, 0X24C);
    sub_80033DB8(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, 0x24C
    ctx->r4 = ADD32(ctx->r4, 0X24C);
    after_1:
    // lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(0X50, ctx->r29);
    // nop

    // beq         $v0, $zero, L_8002557C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002557C;
    }
    // nop

    // lhu         $v0, 0x18($s1)
    ctx->r2 = MEM_HU(0X18, ctx->r17);
    // nop

    // sh          $v0, 0xD8($s2)
    MEM_H(0XD8, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x1A($s1)
    ctx->r2 = MEM_HU(0X1A, ctx->r17);
    // nop

    // sh          $v0, 0xDA($s2)
    MEM_H(0XDA, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x1C($s1)
    ctx->r2 = MEM_HU(0X1C, ctx->r17);
    // nop

    // sh          $v0, 0xDC($s2)
    MEM_H(0XDC, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x1E($s3)
    ctx->r2 = MEM_HU(0X1E, ctx->r19);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_800254F0
    if (ctx->r2 == 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_800254F0;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // addiu       $t0, $t0, 0x5090
    ctx->r8 = ADD32(ctx->r8, 0X5090);
    // addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // addiu       $s6, $zero, 0x1000
    ctx->r22 = ADD32(0, 0X1000);
    // addiu       $s7, $s1, 0x8
    ctx->r23 = ADD32(ctx->r17, 0X8);
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    // addiu       $s5, $s1, 0x4
    ctx->r21 = ADD32(ctx->r17, 0X4);
    // lb          $v0, 0x2D($s1)
    ctx->r2 = MEM_BS(0X2D, ctx->r17);
    // lw          $v1, 0xE4($t0)
    ctx->r3 = MEM_W(0XE4, ctx->r8);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
    // lb          $v0, 0x2D($s1)
    ctx->r2 = MEM_BS(0X2D, ctx->r17);
    // addiu       $s4, $s2, 0xD8
    ctx->r20 = ADD32(ctx->r18, 0XD8);
    // subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // sw          $v0, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r2;
    // lb          $v0, 0x2D($s1)
    ctx->r2 = MEM_BS(0X2D, ctx->r17);
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // subu        $v0, $s6, $v0
    ctx->r2 = SUB32(ctx->r22, ctx->r2);
    // sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lbu         $a1, 0x4($s3)
    ctx->r5 = MEM_BU(0X4, ctx->r19);
    // lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(0X78, ctx->r29);
    // addiu       $v0, $v0, -0x4288
    ctx->r2 = ADD32(ctx->r2, -0X4288);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // lbu         $v0, 0x24($s1)
    ctx->r2 = MEM_BU(0X24, ctx->r17);
    // addiu       $a1, $a1, 0x24C
    ctx->r5 = ADD32(ctx->r5, 0X24C);
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // jal         0x80022678
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    sub_80022678(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_2:
    // lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // addiu       $t0, $t0, 0x5090
    ctx->r8 = ADD32(ctx->r8, 0X5090);
    // sh          $zero, 0xDC($s2)
    MEM_H(0XDC, ctx->r18) = 0;
    // sh          $zero, 0xDA($s2)
    MEM_H(0XDA, ctx->r18) = 0;
    // sh          $zero, 0xD8($s2)
    MEM_H(0XD8, ctx->r18) = 0;
    // lb          $v0, 0x2D($s1)
    ctx->r2 = MEM_BS(0X2D, ctx->r17);
    // lw          $v1, 0xE4($t0)
    ctx->r3 = MEM_W(0XE4, ctx->r8);
    // lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
    // lb          $v0, 0x2D($s1)
    ctx->r2 = MEM_BS(0X2D, ctx->r17);
    // addiu       $t0, $t0, 0x5090
    ctx->r8 = ADD32(ctx->r8, 0X5090);
    // subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // sw          $s0, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r16;
    // lb          $v0, 0x2D($s1)
    ctx->r2 = MEM_BS(0X2D, ctx->r17);
    // lw          $v1, 0x6DA8($t0)
    ctx->r3 = MEM_W(0X6DA8, ctx->r8);
    // lw          $a0, 0x6DAC($t0)
    ctx->r4 = MEM_W(0X6DAC, ctx->r8);
    // lw          $a1, 0x6DB0($t0)
    ctx->r5 = MEM_W(0X6DB0, ctx->r8);
    // lw          $a2, 0x6DB4($t0)
    ctx->r6 = MEM_W(0X6DB4, ctx->r8);
    // sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // sw          $a0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r4;
    // sw          $a1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r5;
    // sw          $a2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r6;
    // lw          $v1, 0x6DB8($t0)
    ctx->r3 = MEM_W(0X6DB8, ctx->r8);
    // lw          $a0, 0x6DBC($t0)
    ctx->r4 = MEM_W(0X6DBC, ctx->r8);
    // lw          $a1, 0x6DC0($t0)
    ctx->r5 = MEM_W(0X6DC0, ctx->r8);
    // lw          $a2, 0x6DC4($t0)
    ctx->r6 = MEM_W(0X6DC4, ctx->r8);
    // sw          $v1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r3;
    // sw          $a0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r4;
    // sw          $a1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r5;
    // sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    // subu        $v0, $s6, $v0
    ctx->r2 = SUB32(ctx->r22, ctx->r2);
    // sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // lbu         $v1, 0x22($s1)
    ctx->r3 = MEM_BU(0X22, ctx->r17);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $v1, $v0, L_800254BC
    if (ctx->r3 == ctx->r2) {
        // addiu       $s0, $sp, 0x58
        ctx->r16 = ADD32(ctx->r29, 0X58);
        goto L_800254BC;
    }
    // addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // lh          $a0, 0x18($s1)
    ctx->r4 = MEM_HS(0X18, ctx->r17);
    // jal         0x800753E4
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    RotMatrixX(rdram, ctx);
    goto after_3;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
L_800254BC:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    // addiu       $v0, $zero, 0x81
    ctx->r2 = ADD32(0, 0X81);
    // lbu         $a1, 0x4($s3)
    ctx->r5 = MEM_BU(0X4, ctx->r19);
    // lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(0X78, ctx->r29);
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // j           L_80025564
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    goto L_80025564;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
L_800254F0:
    // lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // addiu       $t0, $t0, 0x5090
    ctx->r8 = ADD32(ctx->r8, 0X5090);
    // addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
    // addiu       $a3, $s2, 0xD8
    ctx->r7 = ADD32(ctx->r18, 0XD8);
    // lb          $v0, 0x2D($s1)
    ctx->r2 = MEM_BS(0X2D, ctx->r17);
    // lw          $v1, 0xE4($t0)
    ctx->r3 = MEM_W(0XE4, ctx->r8);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
    // lb          $v1, 0x2D($s1)
    ctx->r3 = MEM_BS(0X2D, ctx->r17);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r2;
    // lb          $v0, 0x2D($s1)
    ctx->r2 = MEM_BS(0X2D, ctx->r17);
    // addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // lbu         $a1, 0x4($s3)
    ctx->r5 = MEM_BU(0X4, ctx->r19);
    // addiu       $v0, $s1, 0x4
    ctx->r2 = ADD32(ctx->r17, 0X4);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(0X78, ctx->r29);
    // addiu       $v0, $v0, -0x4288
    ctx->r2 = ADD32(ctx->r2, -0X4288);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
L_80025564:
    // sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // lbu         $v0, 0x24($s1)
    ctx->r2 = MEM_BU(0X24, ctx->r17);
    // addiu       $a1, $a1, 0x24C
    ctx->r5 = ADD32(ctx->r5, 0X24C);
    // sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // jal         0x80022678
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    sub_80022678(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_4:
L_8002557C:
    // addiu       $fp, $fp, -0x1
    ctx->r30 = ADD32(ctx->r30, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $fp, $v0, L_8002524C
    if (ctx->r30 != ctx->r2) {
        // lui         $t0, 0x801C
        ctx->r8 = S32(0X801C << 16);
        goto L_8002524C;
    }
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
L_8002558C:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v0, 0x593F($v0)
    ctx->r2 = MEM_BU(0X593F, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800255B8
    if (ctx->r2 != 0) {
        // addiu       $v0, $s2, 0x178
        ctx->r2 = ADD32(ctx->r18, 0X178);
        goto L_800255B8;
    }
    // addiu       $v0, $s2, 0x178
    ctx->r2 = ADD32(ctx->r18, 0X178);
    // addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x24C
    ctx->r6 = ADD32(0, 0X24C);
    // jal         0x80023ED8
    // addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    sub_80023ED8(rdram, ctx);
    goto after_5;
    // addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_5:
    // addiu       $v0, $s2, 0x178
    ctx->r2 = ADD32(ctx->r18, 0X178);
L_800255B8:
    // sw          $v0, 0xF0($s2)
    MEM_W(0XF0, ctx->r18) = ctx->r2;
    // lw          $ra, 0xA4($sp)
    ctx->r31 = MEM_W(0XA4, ctx->r29);
    // lw          $fp, 0xA0($sp)
    ctx->r30 = MEM_W(0XA0, ctx->r29);
    // lw          $s7, 0x9C($sp)
    ctx->r23 = MEM_W(0X9C, ctx->r29);
    // lw          $s6, 0x98($sp)
    ctx->r22 = MEM_W(0X98, ctx->r29);
    // lw          $s5, 0x94($sp)
    ctx->r21 = MEM_W(0X94, ctx->r29);
    // lw          $s4, 0x90($sp)
    ctx->r20 = MEM_W(0X90, ctx->r29);
    // lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(0X8C, ctx->r29);
    // lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(0X88, ctx->r29);
    // lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(0X84, ctx->r29);
    // lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(0X80, ctx->r29);
    // addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // jr          $ra
    // nop

    return;
    // nop

;}
