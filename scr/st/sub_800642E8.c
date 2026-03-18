#include "recomp.h"
#include "disable_warnings.h"

void sub_800642E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s1, $v0, -0x2E80
    ctx->r17 = ADD32(ctx->r2, -0X2E80);
    // lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(0X4, ctx->r17);
    // nop

    // andi        $v0, $a0, 0x2000
    ctx->r2 = ctx->r4 & 0X2000;
    // beq         $v0, $zero, L_80064344
    if (ctx->r2 == 0) {
        // lui         $s0, 0x1F80
        ctx->r16 = S32(0X1F80 << 16);
        goto L_80064344;
    }
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // j           L_80064B88
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_80064B88;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80064344:
    // lhu         $v1, 0xC($s1)
    ctx->r3 = MEM_HU(0XC, ctx->r17);
    // nop

    // andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // beq         $v0, $zero, L_80064398
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x40
        ctx->r2 = ctx->r3 & 0X40;
        goto L_80064398;
    }
    // andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8006438C
    if (ctx->r2 != 0) {
        // sh          $zero, 0xC($s1)
        MEM_H(0XC, ctx->r17) = 0;
        goto L_8006438C;
    }
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // lhu         $v1, 0x2E2($s0)
    ctx->r3 = MEM_HU(0X2E2, ctx->r16);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // blez        $v0, L_80064B84
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_80064B84;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // j           L_80064B84
    // sh          $v0, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = ctx->r2;
    goto L_80064B84;
    // sh          $v0, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = ctx->r2;
L_8006438C:
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // j           L_80064B84
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
    goto L_80064B84;
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_80064398:
    // beq         $v0, $zero, L_800643F0
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x800
        ctx->r2 = ctx->r3 & 0X800;
        goto L_800643F0;
    }
    // andi        $v0, $v1, 0x800
    ctx->r2 = ctx->r3 & 0X800;
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lhu         $a0, 0x2E0($s0)
    ctx->r4 = MEM_HU(0X2E0, ctx->r16);
    // addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_800643E4
    if (ctx->r2 != ctx->r3) {
        // sh          $zero, 0xC($s1)
        MEM_H(0XC, ctx->r17) = 0;
        goto L_800643E4;
    }
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // lhu         $v1, 0x2E2($s0)
    ctx->r3 = MEM_HU(0X2E2, ctx->r16);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_80064B84
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_80064B84;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // j           L_80064B84
    // sh          $v0, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = ctx->r2;
    goto L_80064B84;
    // sh          $v0, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = ctx->r2;
L_800643E4:
    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // j           L_80064B84
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
    goto L_80064B84;
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_800643F0:
    // beq         $v0, $zero, L_8006443C
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x200
        ctx->r2 = ctx->r3 & 0X200;
        goto L_8006443C;
    }
    // andi        $v0, $v1, 0x200
    ctx->r2 = ctx->r3 & 0X200;
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lhu         $v1, 0x2E2($s0)
    ctx->r3 = MEM_HU(0X2E2, ctx->r16);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $zero, L_80064420
    if (ctx->r2 != 0) {
        // sh          $zero, 0xC($s1)
        MEM_H(0XC, ctx->r17) = 0;
        goto L_80064420;
    }
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // j           L_80064B84
    // sh          $zero, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = 0;
    goto L_80064B84;
    // sh          $zero, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = 0;
L_80064420:
    // slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80064434
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, -0x5
        ctx->r2 = ADD32(ctx->r3, -0X5);
        goto L_80064434;
    }
    // addiu       $v0, $v1, -0x5
    ctx->r2 = ADD32(ctx->r3, -0X5);
    // j           L_80064B84
    // sh          $v0, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = ctx->r2;
    goto L_80064B84;
    // sh          $v0, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = ctx->r2;
L_80064434:
    // j           L_80064B84
    // sh          $zero, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = 0;
    goto L_80064B84;
    // sh          $zero, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = 0;
L_8006443C:
    // beq         $v0, $zero, L_8006448C
    if (ctx->r2 == 0) {
        // andi        $v0, $a0, 0x4000
        ctx->r2 = ctx->r4 & 0X4000;
        goto L_8006448C;
    }
    // andi        $v0, $a0, 0x4000
    ctx->r2 = ctx->r4 & 0X4000;
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lhu         $v1, 0x2E2($s0)
    ctx->r3 = MEM_HU(0X2E2, ctx->r16);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $a0, L_80064470
    if (ctx->r2 != ctx->r4) {
        // sh          $zero, 0xC($s1)
        MEM_H(0XC, ctx->r17) = 0;
        goto L_80064470;
    }
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // j           L_80064B84
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
    goto L_80064B84;
    // sh          $v0, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = ctx->r2;
L_80064470:
    // slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_80064484
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x5
        ctx->r2 = ADD32(ctx->r3, 0X5);
        goto L_80064484;
    }
    // addiu       $v0, $v1, 0x5
    ctx->r2 = ADD32(ctx->r3, 0X5);
    // j           L_80064B84
    // sh          $v0, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = ctx->r2;
    goto L_80064B84;
    // sh          $v0, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = ctx->r2;
L_80064484:
    // j           L_80064B84
    // sh          $a0, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = ctx->r4;
    goto L_80064B84;
    // sh          $a0, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = ctx->r4;
L_8006448C:
    // beq         $v0, $zero, L_80064B88
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80064B88;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lhu         $v0, 0x2E2($s0)
    ctx->r2 = MEM_HU(0X2E2, ctx->r16);
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // lhu         $v1, 0x2E0($s0)
    ctx->r3 = MEM_HU(0X2E0, ctx->r16);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // sltiu       $v0, $v1, 0xF
    ctx->r2 = ctx->r3 < 0XF ? 1 : 0;
    // beq         $v0, $zero, L_800646BC
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_800646BC;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x38D8
    ctx->r2 = ADD32(ctx->r2, 0X38D8);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_800644D4;
    jr_addend_800644D4 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_800644D4 >> 2) {
        case 0: goto L_800644DC; break;
        case 1: goto L_800644FC; break;
        case 2: goto L_8006451C; break;
        case 3: goto L_8006453C; break;
        case 4: goto L_8006455C; break;
        case 5: goto L_8006457C; break;
        case 6: goto L_8006459C; break;
        case 7: goto L_800645BC; break;
        case 8: goto L_800645DC; break;
        case 9: goto L_800645FC; break;
        case 10: goto L_8006461C; break;
        case 11: goto L_8006463C; break;
        case 12: goto L_8006465C; break;
        case 13: goto L_8006467C; break;
        case 14: goto L_8006469C; break;
        default: switch_error(__func__, 0x800644D4, 0x800138D8);
    }
    // nop

L_800644DC:
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $s2, 0x48($v0)
    ctx->r18 = MEM_HU(0X48, ctx->r2);
    // addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // j           L_800646CC
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
    goto L_800646CC;
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
L_800644FC:
    // addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $s2, 0x4A($v0)
    ctx->r18 = MEM_HU(0X4A, ctx->r2);
    // addiu       $v0, $v0, 0x4A
    ctx->r2 = ADD32(ctx->r2, 0X4A);
    // j           L_800646CC
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
    goto L_800646CC;
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
L_8006451C:
    // addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $s2, 0x3C($v0)
    ctx->r18 = MEM_HU(0X3C, ctx->r2);
    // addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // j           L_800646CC
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
    goto L_800646CC;
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
L_8006453C:
    // addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $s2, 0x4C($v0)
    ctx->r18 = MEM_HU(0X4C, ctx->r2);
    // addiu       $v0, $v0, 0x4C
    ctx->r2 = ADD32(ctx->r2, 0X4C);
    // j           L_800646CC
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
    goto L_800646CC;
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
L_8006455C:
    // addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $s2, 0x3E($v0)
    ctx->r18 = MEM_HU(0X3E, ctx->r2);
    // addiu       $v0, $v0, 0x3E
    ctx->r2 = ADD32(ctx->r2, 0X3E);
    // j           L_800646CC
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
    goto L_800646CC;
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
L_8006457C:
    // addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $s2, 0x40($v0)
    ctx->r18 = MEM_HU(0X40, ctx->r2);
    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // j           L_800646CC
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
    goto L_800646CC;
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
L_8006459C:
    // addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $s2, 0x58($v0)
    ctx->r18 = MEM_HU(0X58, ctx->r2);
    // addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // j           L_800646CC
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
    goto L_800646CC;
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
L_800645BC:
    // addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $s2, 0x5A($v0)
    ctx->r18 = MEM_HU(0X5A, ctx->r2);
    // addiu       $v0, $v0, 0x5A
    ctx->r2 = ADD32(ctx->r2, 0X5A);
    // j           L_800646CC
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
    goto L_800646CC;
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
L_800645DC:
    // addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $s2, 0x3A($v0)
    ctx->r18 = MEM_HU(0X3A, ctx->r2);
    // addiu       $v0, $v0, 0x3A
    ctx->r2 = ADD32(ctx->r2, 0X3A);
    // j           L_800646CC
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
    goto L_800646CC;
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
L_800645FC:
    // addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $s2, 0x54($v0)
    ctx->r18 = MEM_HU(0X54, ctx->r2);
    // addiu       $v0, $v0, 0x54
    ctx->r2 = ADD32(ctx->r2, 0X54);
    // j           L_800646CC
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
    goto L_800646CC;
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
L_8006461C:
    // addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $s2, 0x46($v0)
    ctx->r18 = MEM_HU(0X46, ctx->r2);
    // addiu       $v0, $v0, 0x46
    ctx->r2 = ADD32(ctx->r2, 0X46);
    // j           L_800646CC
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
    goto L_800646CC;
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
L_8006463C:
    // addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $s2, 0x38($v0)
    ctx->r18 = MEM_HU(0X38, ctx->r2);
    // addiu       $v0, $v0, 0x38
    ctx->r2 = ADD32(ctx->r2, 0X38);
    // j           L_800646CC
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
    goto L_800646CC;
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
L_8006465C:
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $s2, 0x44($v0)
    ctx->r18 = MEM_HU(0X44, ctx->r2);
    // addiu       $v0, $v0, 0x44
    ctx->r2 = ADD32(ctx->r2, 0X44);
    // j           L_800646CC
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
    goto L_800646CC;
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
L_8006467C:
    // addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $s2, 0x52($v0)
    ctx->r18 = MEM_HU(0X52, ctx->r2);
    // addiu       $v0, $v0, 0x52
    ctx->r2 = ADD32(ctx->r2, 0X52);
    // j           L_800646CC
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
    goto L_800646CC;
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
L_8006469C:
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $s2, 0x50($v0)
    ctx->r18 = MEM_HU(0X50, ctx->r2);
    // addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, 0X50);
    // j           L_800646CC
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
    goto L_800646CC;
    // sw          $v0, 0xCF8($v1)
    MEM_W(0XCF8, ctx->r3) = ctx->r2;
L_800646BC:
    // ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // sw          $zero, 0xCF8($v0)
    MEM_W(0XCF8, ctx->r2) = 0;
L_800646CC:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s1, $v0, L_80064860
    if (ctx->r17 != ctx->r2) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80064860;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $a1, 0xCF8($v0)
    ctx->r5 = MEM_W(0XCF8, ctx->r2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x7094
    ctx->r4 = ADD32(ctx->r2, -0X7094);
    // bne         $a1, $a0, L_80064700
    if (ctx->r5 != ctx->r4) {
        // addiu       $v0, $a0, 0xC
        ctx->r2 = ADD32(ctx->r4, 0XC);
        goto L_80064700;
    }
    // addiu       $v0, $a0, 0xC
    ctx->r2 = ADD32(ctx->r4, 0XC);
    // lhu         $v1, -0xC($a0)
    ctx->r3 = MEM_HU(-0XC, ctx->r4);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $v1, $v0, L_80064718
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_80064718;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $a0, 0xC
    ctx->r2 = ADD32(ctx->r4, 0XC);
L_80064700:
    // bne         $a1, $v0, L_80064850
    if (ctx->r5 != ctx->r2) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80064850;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lhu         $v1, 0xE($a0)
    ctx->r3 = MEM_HU(0XE, ctx->r4);
    // nop

    // beq         $v1, $v0, L_80064850
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_80064850;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
L_80064718:
    // addiu       $a2, $v0, 0x3880
    ctx->r6 = ADD32(ctx->r2, 0X3880);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // lwl         $a1, 0xB($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XB, ctx->r6);
    // lwr         $a1, 0x8($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X8, ctx->r6);
    // swl         $v1, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r3);
    // swr         $v1, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r3);
    // swl         $a0, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r4);
    // swr         $a0, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r4);
    // swl         $a1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r5);
    // swr         $a1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r5);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v1, 0xCF8($v0)
    ctx->r3 = MEM_W(0XCF8, ctx->r2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x7094
    ctx->r2 = ADD32(ctx->r2, -0X7094);
    // bne         $v1, $v0, L_80064770
    if (ctx->r3 != ctx->r2) {
        // lui         $v1, 0x801E
        ctx->r3 = S32(0X801E << 16);
        goto L_80064770;
    }
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // lhu         $v0, -0xC($v0)
    ctx->r2 = MEM_HU(-0XC, ctx->r2);
    // j           L_80064774
    // nop

    goto L_80064774;
    // nop

L_80064770:
    // lhu         $v0, 0xE($v0)
    ctx->r2 = MEM_HU(0XE, ctx->r2);
L_80064774:
    // lw          $v1, 0xD08($v1)
    ctx->r3 = MEM_W(0XD08, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v0, $v0, -0x310
    ctx->r2 = ADD32(ctx->r2, -0X310);
    // addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xD08
    ctx->r2 = ADD32(ctx->r2, 0XD08);
    // sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // addiu       $v0, $v0, 0xB
    ctx->r2 = ADD32(ctx->r2, 0XB);
L_8006479C:
    // sb          $v1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r3;
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // bgez        $a1, L_8006479C
    if (SIGNED(ctx->r5) >= 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_8006479C;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $t0, $sp, 0x18
    ctx->r8 = ADD32(ctx->r29, 0X18);
    // addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $a2, $v0, 0xD08
    ctx->r6 = ADD32(ctx->r2, 0XD08);
    // addu        $v0, $t0, $a1
    ctx->r2 = ADD32(ctx->r8, ctx->r5);
L_800647C4:
    // lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(0X0, ctx->r2);
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // sllv        $v1, $t1, $a0
    ctx->r3 = S32(ctx->r9) << (ctx->r4 & 31);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_800647F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800647F4;
    }
    // nop

    // lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(0X4, ctx->r6);
    // nop

    // addu        $v1, $v0, $a2
    ctx->r3 = ADD32(ctx->r2, ctx->r6);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $a0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r4;
    // sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
L_800647F4:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0xC
    ctx->r2 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // bne         $v0, $zero, L_800647C4
    if (ctx->r2 != 0) {
        // addu        $v0, $t0, $a1
        ctx->r2 = ADD32(ctx->r8, ctx->r5);
        goto L_800647C4;
    }
    // addu        $v0, $t0, $a1
    ctx->r2 = ADD32(ctx->r8, ctx->r5);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v0, 0xD0C($v0)
    ctx->r2 = MEM_W(0XD0C, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80064850
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80064850;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // lhu         $v1, 0x2E2($s0)
    ctx->r3 = MEM_HU(0X2E2, ctx->r16);
    // lhu         $a0, 0x2E0($s0)
    ctx->r4 = MEM_HU(0X2E0, ctx->r16);
    // sh          $zero, 0x2E2($s0)
    MEM_H(0X2E2, ctx->r16) = 0;
    // sh          $zero, 0x2E0($s0)
    MEM_H(0X2E0, ctx->r16) = 0;
    // ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
    // sh          $v1, 0x328($gp)
    MEM_H(0X328, ctx->r28) = ctx->r3;
    // sh          $a0, 0x32A($gp)
    MEM_H(0X32A, ctx->r28) = ctx->r4;
    // j           L_80064B88
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80064B88;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80064850:
    // jal         0x80057D34
    // nop

    sub_80057D34(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // j           L_80064B88
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80064B88;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80064860:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // jal         0x800152D0
    // addiu       $a0, $zero, 0x214
    ctx->r4 = ADD32(0, 0X214);
    sub_800152D0(rdram, ctx);
    goto after_8;
    // addiu       $a0, $zero, 0x214
    ctx->r4 = ADD32(0, 0X214);
    after_8:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $t6, $v1, 0x7590
    ctx->r14 = ADD32(ctx->r3, 0X7590);
    // addiu       $t2, $s1, -0x1
    ctx->r10 = ADD32(ctx->r17, -0X1);
    // lui         $v1, 0x8001
    ctx->r3 = S32(0X8001 << 16);
    // addiu       $v1, $v1, 0x3918
    ctx->r3 = ADD32(ctx->r3, 0X3918);
    // sll         $a0, $t2, 2
    ctx->r4 = S32(ctx->r10) << 2;
    // addu        $a0, $a0, $v1
    gpr jr_addend_800648FC;
    jr_addend_800648FC = ctx->r4;
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $t1, $v1, 0xCE8
    ctx->r9 = ADD32(ctx->r3, 0XCE8);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $t3, $v1, -0x709E
    ctx->r11 = ADD32(ctx->r3, -0X709E);
    // addiu       $t0, $t3, -0x3A
    ctx->r8 = ADD32(ctx->r11, -0X3A);
    // addiu       $t5, $t3, -0x2
    ctx->r13 = ADD32(ctx->r11, -0X2);
    // addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $a3, $v1, 0x76F8
    ctx->r7 = ADD32(ctx->r3, 0X76F8);
    // sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
L_800648BC:
    // addu        $v0, $a1, $t6
    ctx->r2 = ADD32(ctx->r5, ctx->r14);
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 & 0X7F;
    // beq         $v0, $zero, L_80064A3C
    if (ctx->r2 == 0) {
        // srl         $v0, $v1, 7
        ctx->r2 = S32(U32(ctx->r3) >> 7);
        goto L_80064A3C;
    }
    // srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
    // bne         $v0, $zero, L_80064A3C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_80064A3C;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // lbu         $v1, 0x13E($a3)
    ctx->r3 = MEM_BU(0X13E, ctx->r7);
    // nop

    // beq         $v1, $v0, L_80064A3C
    if (ctx->r3 == ctx->r2) {
        // sltiu       $v0, $t2, 0x8
        ctx->r2 = ctx->r10 < 0X8 ? 1 : 0;
        goto L_80064A3C;
    }
    // sltiu       $v0, $t2, 0x8
    ctx->r2 = ctx->r10 < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_80064A08
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80064A08;
    }
    // nop

    // lw          $v0, 0x0($a0)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_800648FC >> 2) {
        case 0: goto L_800649AC; break;
        case 1: goto L_80064A08; break;
        case 2: goto L_80064A08; break;
        case 3: goto L_8006492C; break;
        case 4: goto L_80064A08; break;
        case 5: goto L_80064954; break;
        case 6: goto L_800649CC; break;
        case 7: goto L_80064904; break;
        default: switch_error(__func__, 0x800648FC, 0x80013918);
    }
    // nop

L_80064904:
    // lw          $v0, 0x10($t1)
    ctx->r2 = MEM_W(0X10, ctx->r9);
    // nop

    // bne         $v0, $t3, L_80064920
    if (ctx->r2 != ctx->r11) {
        // nop
    
        goto L_80064920;
    }
    // nop

    // lhu         $v0, 0x54($t0)
    ctx->r2 = MEM_HU(0X54, ctx->r8);
    // j           L_800649FC
    // nop

    goto L_800649FC;
    // nop

L_80064920:
    // lhu         $v0, 0x3A($t0)
    ctx->r2 = MEM_HU(0X3A, ctx->r8);
    // j           L_800649FC
    // nop

    goto L_800649FC;
    // nop

L_8006492C:
    // lw          $v0, 0x10($t1)
    ctx->r2 = MEM_W(0X10, ctx->r9);
    // nop

    // bne         $v0, $t5, L_80064948
    if (ctx->r2 != ctx->r13) {
        // nop
    
        goto L_80064948;
    }
    // nop

    // lhu         $v0, 0x52($t0)
    ctx->r2 = MEM_HU(0X52, ctx->r8);
    // j           L_800649FC
    // nop

    goto L_800649FC;
    // nop

L_80064948:
    // lhu         $v0, 0x38($t0)
    ctx->r2 = MEM_HU(0X38, ctx->r8);
    // j           L_800649FC
    // nop

    goto L_800649FC;
    // nop

L_80064954:
    // lw          $v1, 0x10($t1)
    ctx->r3 = MEM_W(0X10, ctx->r9);
    // nop

    // bne         $v1, $t4, L_80064974
    if (ctx->r3 != ctx->r12) {
        // addiu       $v0, $t4, 0x2
        ctx->r2 = ADD32(ctx->r12, 0X2);
        goto L_80064974;
    }
    // addiu       $v0, $t4, 0x2
    ctx->r2 = ADD32(ctx->r12, 0X2);
    // lhu         $v0, 0x40($t0)
    ctx->r2 = MEM_HU(0X40, ctx->r8);
    // nop

    // beq         $a1, $v0, L_80064A3C
    if (ctx->r5 == ctx->r2) {
        // addiu       $v0, $t4, 0x2
        ctx->r2 = ADD32(ctx->r12, 0X2);
        goto L_80064A3C;
    }
    // addiu       $v0, $t4, 0x2
    ctx->r2 = ADD32(ctx->r12, 0X2);
L_80064974:
    // bne         $v1, $v0, L_8006498C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8006498C;
    }
    // nop

    // lhu         $v0, 0x3E($t0)
    ctx->r2 = MEM_HU(0X3E, ctx->r8);
    // nop

    // beq         $a1, $v0, L_80064A3C
    if (ctx->r5 == ctx->r2) {
        // nop
    
        goto L_80064A3C;
    }
    // nop

L_8006498C:
    // lbu         $v1, 0x13E($a3)
    ctx->r3 = MEM_BU(0X13E, ctx->r7);
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // beq         $v1, $v0, L_80064A18
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
        goto L_80064A18;
    }
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // beq         $v1, $v0, L_80064A18
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80064A18;
    }
    // nop

    // j           L_80064A40
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    goto L_80064A40;
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800649AC:
    // lbu         $v1, 0x13E($a3)
    ctx->r3 = MEM_BU(0X13E, ctx->r7);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_80064A18
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
        goto L_80064A18;
    }
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // beq         $v1, $v0, L_80064A18
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80064A18;
    }
    // nop

    // j           L_80064A40
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    goto L_80064A40;
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800649CC:
    // lw          $v1, 0x10($t1)
    ctx->r3 = MEM_W(0X10, ctx->r9);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a2, $v0, -0x7080
    ctx->r6 = ADD32(ctx->r2, -0X7080);
    // bne         $v1, $a2, L_800649F0
    if (ctx->r3 != ctx->r6) {
        // addiu       $v0, $a2, 0x2
        ctx->r2 = ADD32(ctx->r6, 0X2);
        goto L_800649F0;
    }
    // addiu       $v0, $a2, 0x2
    ctx->r2 = ADD32(ctx->r6, 0X2);
    // lhu         $v0, 0x5A($t0)
    ctx->r2 = MEM_HU(0X5A, ctx->r8);
    // nop

    // beq         $a1, $v0, L_80064A3C
    if (ctx->r5 == ctx->r2) {
        // addiu       $v0, $a2, 0x2
        ctx->r2 = ADD32(ctx->r6, 0X2);
        goto L_80064A3C;
    }
    // addiu       $v0, $a2, 0x2
    ctx->r2 = ADD32(ctx->r6, 0X2);
L_800649F0:
    // bne         $v1, $v0, L_80064A08
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80064A08;
    }
    // nop

    // lhu         $v0, 0x58($t0)
    ctx->r2 = MEM_HU(0X58, ctx->r8);
L_800649FC:
    // nop

    // beq         $a1, $v0, L_80064A3C
    if (ctx->r5 == ctx->r2) {
        // nop
    
        goto L_80064A3C;
    }
    // nop

L_80064A08:
    // lbu         $v0, 0x13E($a3)
    ctx->r2 = MEM_BU(0X13E, ctx->r7);
    // nop

    // bne         $v0, $s1, L_80064A3C
    if (ctx->r2 != ctx->r17) {
        // nop
    
        goto L_80064A3C;
    }
    // nop

L_80064A18:
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sh          $v1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r3;
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
L_80064A3C:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80064A40:
    // slti        $v0, $a1, 0x10A
    ctx->r2 = SIGNED(ctx->r5) < 0X10A ? 1 : 0;
    // bne         $v0, $zero, L_800648BC
    if (ctx->r2 != 0) {
        // addiu       $a3, $a3, 0x2C
        ctx->r7 = ADD32(ctx->r7, 0X2C);
        goto L_800648BC;
    }
    // addiu       $a3, $a3, 0x2C
    ctx->r7 = ADD32(ctx->r7, 0X2C);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $s2, $v0, L_80064A64
    if (ctx->r18 != ctx->r2) {
        // lui         $v1, 0x801E
        ctx->r3 = S32(0X801E << 16);
        goto L_80064A64;
    }
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // j           L_80064AC8
    // sw          $v0, 0xCF0($v1)
    MEM_W(0XCF0, ctx->r3) = ctx->r2;
    goto L_80064AC8;
    // sw          $v0, 0xCF0($v1)
    MEM_W(0XCF0, ctx->r3) = ctx->r2;
L_80064A64:
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // blez        $v1, L_80064AA8
    if (SIGNED(ctx->r3) <= 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_80064AA8;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80064A88:
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_HS(0X0, ctx->r3);
    // nop

    // beq         $v0, $s2, L_80064AA8
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_80064AA8;
    }
    // nop

    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a1, $a0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_80064A88
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
        goto L_80064A88;
    }
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_80064AA8:
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $a1, $v0, L_80064AC4
    if (ctx->r5 != ctx->r2) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80064AC4;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80064AC4:
    // sw          $a1, 0xCF0($v0)
    MEM_W(0XCF0, ctx->r2) = ctx->r5;
L_80064AC8:
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $s2, $v0, L_80064AFC
    if (ctx->r18 == ctx->r2) {
        // lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
        goto L_80064AFC;
    }
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x76F8
    ctx->r3 = ADD32(ctx->r3, 0X76F8);
    // sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18) << 1;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $a1, 0x11D($v0)
    ctx->r5 = MEM_BU(0X11D, ctx->r2);
    // j           L_80064B00
    // nop

    goto L_80064B00;
    // nop

L_80064AFC:
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80064B00:
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // nop

    // ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $s2, $v0, L_80064B44
    if (ctx->r18 != ctx->r2) {
        // addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
        goto L_80064B44;
    }
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // addiu       $a1, $zero, 0x321
    ctx->r5 = ADD32(0, 0X321);
    // lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // jal         0x80016030
    // addiu       $a2, $a2, -0x7378
    ctx->r6 = ADD32(ctx->r6, -0X7378);
    sub_80016030(rdram, ctx);
    goto after_9;
    // addiu       $a2, $a2, -0x7378
    ctx->r6 = ADD32(ctx->r6, -0X7378);
    after_9:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // sw          $v1, 0xCE8($v0)
    MEM_W(0XCE8, ctx->r2) = ctx->r3;
    // addiu       $v0, $v0, 0xCE8
    ctx->r2 = ADD32(ctx->r2, 0XCE8);
    // j           L_80064B68
    // sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    goto L_80064B68;
    // sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_80064B44:
    // addiu       $a1, $a1, 0x258
    ctx->r5 = ADD32(ctx->r5, 0X258);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // jal         0x80016030
    // addiu       $a2, $a2, -0x7378
    ctx->r6 = ADD32(ctx->r6, -0X7378);
    sub_80016030(rdram, ctx);
    goto after_10;
    // addiu       $a2, $a2, -0x7378
    ctx->r6 = ADD32(ctx->r6, -0X7378);
    after_10:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // sw          $s2, 0xCE8($v0)
    MEM_W(0XCE8, ctx->r2) = ctx->r18;
    // addiu       $v0, $v0, 0xCE8
    ctx->r2 = ADD32(ctx->r2, 0XCE8);
    // sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
L_80064B68:
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // addiu       $a0, $a0, -0x7378
    ctx->r4 = ADD32(ctx->r4, -0X7378);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003EC5C
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_8003EC5C(rdram, ctx);
    goto after_11;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // sw          $s2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r18;
L_80064B84:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80064B88:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
