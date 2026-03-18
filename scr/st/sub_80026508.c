#include "recomp.h"
#include "disable_warnings.h"

void sub_80026508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lhu         $a1, 0x2($a0)
    ctx->r5 = MEM_HU(0X2, ctx->r4);
    // lhu         $v0, 0x18A($a0)
    ctx->r2 = MEM_HU(0X18A, ctx->r4);
    // nop

    // bne         $a1, $v0, L_80026544
    if (ctx->r5 != ctx->r2) {
        // nop
    
        goto L_80026544;
    }
    // nop

    // lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(0X6, ctx->r4);
    // lhu         $v0, 0x18C($a0)
    ctx->r2 = MEM_HU(0X18C, ctx->r4);
    // nop

    // beq         $v1, $v0, L_8002655C
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8002655C;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80026544:
    // lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(0X6, ctx->r4);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0x186($a0)
    MEM_B(0X186, ctx->r4) = ctx->r2;
    // sh          $a1, 0x18A($a0)
    MEM_H(0X18A, ctx->r4) = ctx->r5;
    // sh          $v1, 0x18C($a0)
    MEM_H(0X18C, ctx->r4) = ctx->r3;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8002655C:
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v1, 0x186($s0)
    ctx->r3 = MEM_BU(0X186, ctx->r16);
    // nop

    // beq         $v1, $zero, L_800265E8
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_800265E8;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_800265EC
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_800265EC;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // addiu       $a3, $t0, -0xC0C
    ctx->r7 = ADD32(ctx->r8, -0XC0C);
    // lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(0X2, ctx->r16);
    // lbu         $v0, -0xC0C($t0)
    ctx->r2 = MEM_BU(-0XC0C, ctx->r8);
    // addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // sb          $v1, 0x1CC($a3)
    MEM_B(0X1CC, ctx->r7) = ctx->r3;
    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // sb          $v0, -0xC0C($t0)
    MEM_B(-0XC0C, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x14($a3)
    ctx->r2 = MEM_BU(0X14, ctx->r7);
    // lbu         $v1, 0x28($a3)
    ctx->r3 = MEM_BU(0X28, ctx->r7);
    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // sb          $v0, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r2;
    // lbu         $v0, 0x3C($a3)
    ctx->r2 = MEM_BU(0X3C, ctx->r7);
    // ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // sb          $v1, 0x28($a3)
    MEM_B(0X28, ctx->r7) = ctx->r3;
    // lbu         $v1, 0x104($a3)
    ctx->r3 = MEM_BU(0X104, ctx->r7);
    // ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // sb          $v0, 0x3C($a3)
    MEM_B(0X3C, ctx->r7) = ctx->r2;
    // jal         0x80026228
    // sb          $v1, 0x104($a3)
    MEM_B(0X104, ctx->r7) = ctx->r3;
    sub_80026228(rdram, ctx);
    goto after_0;
    // sb          $v1, 0x104($a3)
    MEM_B(0X104, ctx->r7) = ctx->r3;
    after_0:
    // addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(0X6, ctx->r16);
    // jal         0x80026228
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    sub_80026228(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_1:
    // sb          $zero, 0x186($s0)
    MEM_B(0X186, ctx->r16) = 0;
L_800265E8:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_800265EC:
    // addiu       $a3, $v0, -0x70D8
    ctx->r7 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v0, 0x186($a3)
    ctx->r2 = MEM_BU(0X186, ctx->r7);
    // nop

    // bne         $v0, $zero, L_8002666C
    if (ctx->r2 != 0) {
        // lui         $a1, 0x6666
        ctx->r5 = S32(0X6666 << 16);
        goto L_8002666C;
    }
    // lui         $a1, 0x6666
    ctx->r5 = S32(0X6666 << 16);
    // lhu         $v0, 0x17E($a3)
    ctx->r2 = MEM_HU(0X17E, ctx->r7);
    // ori         $a1, $a1, 0x6667
    ctx->r5 = ctx->r5 | 0X6667;
    // sll         $a0, $v0, 3
    ctx->r4 = S32(ctx->r2) << 3;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4) << 4;
    // mult        $a0, $a1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x182($a3)
    ctx->r2 = MEM_HU(0X182, ctx->r7);
    // nop

    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // mfhi        $a2
    ctx->r6 = hi;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // mult        $v1, $a1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // addiu       $a1, $a1, -0xC0C
    ctx->r5 = ADD32(ctx->r5, -0XC0C);
    // sra         $v0, $a2, 11
    ctx->r2 = S32(ctx->r6) >> 11;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // addiu       $v0, $zero, 0x133
    ctx->r2 = ADD32(0, 0X133);
    // mfhi        $t0
    ctx->r8 = hi;
    // sra         $a0, $t0, 11
    ctx->r4 = S32(ctx->r8) >> 11;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sh          $a0, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = ctx->r4;
    // sh          $v0, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r2;
L_8002666C:
    // lw          $v1, 0x2C($a3)
    ctx->r3 = MEM_W(0X2C, ctx->r7);
    // nop

    // andi        $v0, $v1, 0x7
    ctx->r2 = ctx->r3 & 0X7;
    // beq         $v0, $zero, L_800266B4
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
        goto L_800266B4;
    }
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a0, $v0, -0xC0C
    ctx->r4 = ADD32(ctx->r2, -0XC0C);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x50($a0)
    MEM_B(0X50, ctx->r4) = ctx->r2;
    // andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // beq         $v0, $zero, L_800266A0
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
        goto L_800266A0;
    }
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // j           L_800266BC
    // sb          $v0, 0x50($a0)
    MEM_B(0X50, ctx->r4) = ctx->r2;
    goto L_800266BC;
    // sb          $v0, 0x50($a0)
    MEM_B(0X50, ctx->r4) = ctx->r2;
L_800266A0:
    // andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // beq         $v0, $zero, L_800266BC
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_800266BC;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // j           L_800266BC
    // sb          $v0, 0x50($a0)
    MEM_B(0X50, ctx->r4) = ctx->r2;
    goto L_800266BC;
    // sb          $v0, 0x50($a0)
    MEM_B(0X50, ctx->r4) = ctx->r2;
L_800266B4:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sb          $zero, -0xBBC($v0)
    MEM_B(-0XBBC, ctx->r2) = 0;
L_800266BC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v1, -0x70AC($v0)
    ctx->r3 = MEM_W(-0X70AC, ctx->r2);
    // nop

    // andi        $v0, $v1, 0x18
    ctx->r2 = ctx->r3 & 0X18;
    // beq         $v0, $zero, L_800266F4
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
        goto L_800266F4;
    }
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a0, $v0, -0xC0C
    ctx->r4 = ADD32(ctx->r2, -0XC0C);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x8C($a0)
    MEM_B(0X8C, ctx->r4) = ctx->r2;
    // andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // beq         $v0, $zero, L_800266FC
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
        goto L_800266FC;
    }
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // j           L_800266FC
    // sb          $v0, 0x8C($a0)
    MEM_B(0X8C, ctx->r4) = ctx->r2;
    goto L_800266FC;
    // sb          $v0, 0x8C($a0)
    MEM_B(0X8C, ctx->r4) = ctx->r2;
L_800266F4:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sb          $zero, -0xB80($v0)
    MEM_B(-0XB80, ctx->r2) = 0;
L_800266FC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v1, -0x70AC($v0)
    ctx->r3 = MEM_W(-0X70AC, ctx->r2);
    // nop

    // andi        $v0, $v1, 0x60
    ctx->r2 = ctx->r3 & 0X60;
    // beq         $v0, $zero, L_80026734
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
        goto L_80026734;
    }
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a0, $v0, -0xC0C
    ctx->r4 = ADD32(ctx->r2, -0XC0C);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0xB4($a0)
    MEM_B(0XB4, ctx->r4) = ctx->r2;
    // andi        $v0, $v1, 0x40
    ctx->r2 = ctx->r3 & 0X40;
    // beq         $v0, $zero, L_8002673C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
        goto L_8002673C;
    }
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // j           L_8002673C
    // sb          $v0, 0xB4($a0)
    MEM_B(0XB4, ctx->r4) = ctx->r2;
    goto L_8002673C;
    // sb          $v0, 0xB4($a0)
    MEM_B(0XB4, ctx->r4) = ctx->r2;
L_80026734:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sb          $zero, -0xB58($v0)
    MEM_B(-0XB58, ctx->r2) = 0;
L_8002673C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x70AC($v0)
    ctx->r2 = MEM_W(-0X70AC, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8002676C
    if (ctx->r2 == 0) {
        // lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
        goto L_8002676C;
    }
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, -0xC0C
    ctx->r3 = ADD32(ctx->r3, -0XC0C);
    // lbu         $v0, 0xDC($v1)
    ctx->r2 = MEM_BU(0XDC, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // j           L_80026774
    // sb          $v0, 0xDC($v1)
    MEM_B(0XDC, ctx->r3) = ctx->r2;
    goto L_80026774;
    // sb          $v0, 0xDC($v1)
    MEM_B(0XDC, ctx->r3) = ctx->r2;
L_8002676C:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sb          $zero, -0xB30($v0)
    MEM_B(-0XB30, ctx->r2) = 0;
L_80026774:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x70AC($v0)
    ctx->r2 = MEM_W(-0X70AC, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // beq         $v0, $zero, L_800267A4
    if (ctx->r2 == 0) {
        // lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
        goto L_800267A4;
    }
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, -0xC0C
    ctx->r3 = ADD32(ctx->r3, -0XC0C);
    // lbu         $v0, 0xF0($v1)
    ctx->r2 = MEM_BU(0XF0, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // j           L_800267AC
    // sb          $v0, 0xF0($v1)
    MEM_B(0XF0, ctx->r3) = ctx->r2;
    goto L_800267AC;
    // sb          $v0, 0xF0($v1)
    MEM_B(0XF0, ctx->r3) = ctx->r2;
L_800267A4:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sb          $zero, -0xB1C($v0)
    MEM_B(-0XB1C, ctx->r2) = 0;
L_800267AC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x6F34($v0)
    ctx->r2 = MEM_W(-0X6F34, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800267CC
    if (ctx->r2 != 0) {
        // lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
        goto L_800267CC;
    }
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // j           L_800267E0
    // sb          $zero, -0x928($v0)
    MEM_B(-0X928, ctx->r2) = 0;
    goto L_800267E0;
    // sb          $zero, -0x928($v0)
    MEM_B(-0X928, ctx->r2) = 0;
L_800267CC:
    // addiu       $v1, $v1, -0xC0C
    ctx->r3 = ADD32(ctx->r3, -0XC0C);
    // lbu         $v0, 0x2E4($v1)
    ctx->r2 = MEM_BU(0X2E4, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // sb          $v0, 0x2E4($v1)
    MEM_B(0X2E4, ctx->r3) = ctx->r2;
L_800267E0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x6F18($v0)
    ctx->r2 = MEM_W(-0X6F18, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80026800
    if (ctx->r2 != 0) {
        // lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
        goto L_80026800;
    }
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // j           L_80026814
    // sb          $zero, -0x914($v0)
    MEM_B(-0X914, ctx->r2) = 0;
    goto L_80026814;
    // sb          $zero, -0x914($v0)
    MEM_B(-0X914, ctx->r2) = 0;
L_80026800:
    // addiu       $v1, $v1, -0xC0C
    ctx->r3 = ADD32(ctx->r3, -0XC0C);
    // lbu         $v0, 0x2F8($v1)
    ctx->r2 = MEM_BU(0X2F8, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // sb          $v0, 0x2F8($v1)
    MEM_B(0X2F8, ctx->r3) = ctx->r2;
L_80026814:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x6F2C($v0)
    ctx->r2 = MEM_W(-0X6F2C, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80026834
    if (ctx->r2 != 0) {
        // lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
        goto L_80026834;
    }
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // j           L_80026848
    // sb          $zero, -0x900($v0)
    MEM_B(-0X900, ctx->r2) = 0;
    goto L_80026848;
    // sb          $zero, -0x900($v0)
    MEM_B(-0X900, ctx->r2) = 0;
L_80026834:
    // addiu       $v1, $v1, -0xC0C
    ctx->r3 = ADD32(ctx->r3, -0XC0C);
    // lbu         $v0, 0x30C($v1)
    ctx->r2 = MEM_BU(0X30C, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // sb          $v0, 0x30C($v1)
    MEM_B(0X30C, ctx->r3) = ctx->r2;
L_80026848:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x6F28($v0)
    ctx->r2 = MEM_W(-0X6F28, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80026868
    if (ctx->r2 != 0) {
        // lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
        goto L_80026868;
    }
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // j           L_8002687C
    // sb          $zero, -0x8EC($v0)
    MEM_B(-0X8EC, ctx->r2) = 0;
    goto L_8002687C;
    // sb          $zero, -0x8EC($v0)
    MEM_B(-0X8EC, ctx->r2) = 0;
L_80026868:
    // addiu       $v1, $v1, -0xC0C
    ctx->r3 = ADD32(ctx->r3, -0XC0C);
    // lbu         $v0, 0x320($v1)
    ctx->r2 = MEM_BU(0X320, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // sb          $v0, 0x320($v1)
    MEM_B(0X320, ctx->r3) = ctx->r2;
L_8002687C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x6F24($v0)
    ctx->r2 = MEM_W(-0X6F24, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8002689C
    if (ctx->r2 != 0) {
        // lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
        goto L_8002689C;
    }
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // j           L_800268B0
    // sb          $zero, -0x8D8($v0)
    MEM_B(-0X8D8, ctx->r2) = 0;
    goto L_800268B0;
    // sb          $zero, -0x8D8($v0)
    MEM_B(-0X8D8, ctx->r2) = 0;
L_8002689C:
    // addiu       $v1, $v1, -0xC0C
    ctx->r3 = ADD32(ctx->r3, -0XC0C);
    // lbu         $v0, 0x334($v1)
    ctx->r2 = MEM_BU(0X334, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // sb          $v0, 0x334($v1)
    MEM_B(0X334, ctx->r3) = ctx->r2;
L_800268B0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x6F20($v0)
    ctx->r2 = MEM_W(-0X6F20, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800268D0
    if (ctx->r2 != 0) {
        // lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
        goto L_800268D0;
    }
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // j           L_800268E4
    // sb          $zero, -0x8C4($v0)
    MEM_B(-0X8C4, ctx->r2) = 0;
    goto L_800268E4;
    // sb          $zero, -0x8C4($v0)
    MEM_B(-0X8C4, ctx->r2) = 0;
L_800268D0:
    // addiu       $v1, $v1, -0xC0C
    ctx->r3 = ADD32(ctx->r3, -0XC0C);
    // lbu         $v0, 0x348($v1)
    ctx->r2 = MEM_BU(0X348, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // sb          $v0, 0x348($v1)
    MEM_B(0X348, ctx->r3) = ctx->r2;
L_800268E4:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x6F1C($v0)
    ctx->r2 = MEM_W(-0X6F1C, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80026904
    if (ctx->r2 != 0) {
        // lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
        goto L_80026904;
    }
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // j           L_80026918
    // sb          $zero, -0x8B0($v0)
    MEM_B(-0X8B0, ctx->r2) = 0;
    goto L_80026918;
    // sb          $zero, -0x8B0($v0)
    MEM_B(-0X8B0, ctx->r2) = 0;
L_80026904:
    // addiu       $v1, $v1, -0xC0C
    ctx->r3 = ADD32(ctx->r3, -0XC0C);
    // lbu         $v0, 0x35C($v1)
    ctx->r2 = MEM_BU(0X35C, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // sb          $v0, 0x35C($v1)
    MEM_B(0X35C, ctx->r3) = ctx->r2;
L_80026918:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x70AC($v0)
    ctx->r2 = MEM_W(-0X70AC, ctx->r2);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_80026948
    if (ctx->r2 == 0) {
        // lui         $v1, 0x8008
        ctx->r3 = S32(0X8008 << 16);
        goto L_80026948;
    }
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, -0xC0C
    ctx->r3 = ADD32(ctx->r3, -0XC0C);
    // lbu         $v0, 0x370($v1)
    ctx->r2 = MEM_BU(0X370, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // j           L_80026950
    // sb          $v0, 0x370($v1)
    MEM_B(0X370, ctx->r3) = ctx->r2;
    goto L_80026950;
    // sb          $v0, 0x370($v1)
    MEM_B(0X370, ctx->r3) = ctx->r2;
L_80026948:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sb          $zero, -0x89C($v0)
    MEM_B(-0X89C, ctx->r2) = 0;
L_80026950:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
