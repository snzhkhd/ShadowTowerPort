#include "recomp.h"
#include "disable_warnings.h"

void sub_80059DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
L_80059DEC:
    // sh          $zero, 0x25C($v1)
    MEM_H(0X25C, ctx->r3) = 0;
    // lhu         $v0, 0x9A($a0)
    ctx->r2 = MEM_HU(0X9A, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sh          $v0, 0x240($v1)
    MEM_H(0X240, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x7E($a0)
    ctx->r2 = MEM_HU(0X7E, ctx->r4);
    // addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // sh          $zero, 0x208($v1)
    MEM_H(0X208, ctx->r3) = 0;
    // sh          $v0, 0x224($v1)
    MEM_H(0X224, ctx->r3) = ctx->r2;
    // slti        $v0, $s0, 0xE
    ctx->r2 = SIGNED(ctx->r16) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_80059DEC
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
        goto L_80059DEC;
    }
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s1, $v0, -0x70A0
    ctx->r17 = ADD32(ctx->r2, -0X70A0);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // ori         $a3, $zero, 0xFFFF
    ctx->r7 = 0 | 0XFFFF;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a2, $v0, 0x76F8
    ctx->r6 = ADD32(ctx->r2, 0X76F8);
L_80059E30:
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // nop

    // beq         $v0, $a3, L_80059E90
    if (ctx->r2 == ctx->r7) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_80059E90;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80059E48:
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // nop

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
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lbu         $v1, 0x128($v0)
    ctx->r3 = MEM_BU(0X128, ctx->r2);
    // lhu         $v0, 0x208($a0)
    ctx->r2 = MEM_HU(0X208, ctx->r4);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x208($a0)
    MEM_H(0X208, ctx->r4) = ctx->r2;
    // slti        $v0, $a1, 0xE
    ctx->r2 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_80059E48
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
        goto L_80059E48;
    }
    // addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80059E90:
    // bne         $s0, $v0, L_80059EA0
    if (ctx->r16 != ctx->r2) {
        // addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
        goto L_80059EA0;
    }
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // j           L_80059EC4
    // addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    goto L_80059EC4;
    // addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_80059EA0:
    // bne         $s0, $v0, L_80059EB0
    if (ctx->r16 != ctx->r2) {
        // addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
        goto L_80059EB0;
    }
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // j           L_80059EC4
    // addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    goto L_80059EC4;
    // addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
L_80059EB0:
    // bne         $s0, $v0, L_80059EC0
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_80059EC0;
    }
    // nop

    // j           L_80059EC4
    // addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    goto L_80059EC4;
    // addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80059EC0:
    // addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_80059EC4:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0xB
    ctx->r2 = SIGNED(ctx->r16) < 0XB ? 1 : 0;
    // bne         $v0, $zero, L_80059E30
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80059E30;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x70AC($v0)
    ctx->r2 = MEM_W(-0X70AC, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_80059F08
    if (ctx->r2 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80059F08;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lhu         $v0, 0x20A($s2)
    ctx->r2 = MEM_HU(0X20A, ctx->r18);
    // lhu         $v1, 0x242($s2)
    ctx->r3 = MEM_HU(0X242, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 17
    ctx->r3 = S32(ctx->r3) >> 17;
    // sh          $v0, 0x20A($s2)
    MEM_H(0X20A, ctx->r18) = ctx->r2;
    // sh          $v1, 0x242($s2)
    MEM_H(0X242, ctx->r18) = ctx->r3;
L_80059F08:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80059F0C:
    // lhu         $v0, 0x208($a0)
    ctx->r2 = MEM_HU(0X208, ctx->r4);
    // lhu         $v1, 0x224($a0)
    ctx->r3 = MEM_HU(0X224, ctx->r4);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x25C($a0)
    MEM_H(0X25C, ctx->r4) = ctx->r2;
    // slti        $v0, $s0, 0xE
    ctx->r2 = SIGNED(ctx->r16) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_80059F0C
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
        goto L_80059F0C;
    }
    // addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // addiu       $a2, $zero, 0x3E7
    ctx->r6 = ADD32(0, 0X3E7);
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addiu       $a1, $s2, 0x1C
    ctx->r5 = ADD32(ctx->r18, 0X1C);
L_80059F38:
    // lhu         $v0, 0x240($a0)
    ctx->r2 = MEM_HU(0X240, ctx->r4);
    // lhu         $v1, 0x208($a0)
    ctx->r3 = MEM_HU(0X208, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1EC($a0)
    MEM_H(0X1EC, ctx->r4) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x3E8
    ctx->r2 = SIGNED(ctx->r2) < 0X3E8 ? 1 : 0;
    // bne         $v0, $zero, L_80059F64
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80059F64;
    }
    // nop

    // sh          $a2, 0x1EC($a0)
    MEM_H(0X1EC, ctx->r4) = ctx->r6;
L_80059F64:
    // lh          $v0, 0x1EC($a0)
    ctx->r2 = MEM_HS(0X1EC, ctx->r4);
    // lhu         $v1, 0x1EC($a0)
    ctx->r3 = MEM_HU(0X1EC, ctx->r4);
    // bgez        $v0, L_80059F7C
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80059F7C;
    }
    // nop

    // j           L_80059F80
    // sh          $zero, 0x1B4($a0)
    MEM_H(0X1B4, ctx->r4) = 0;
    goto L_80059F80;
    // sh          $zero, 0x1B4($a0)
    MEM_H(0X1B4, ctx->r4) = 0;
L_80059F7C:
    // sh          $v1, 0x1B4($a0)
    MEM_H(0X1B4, ctx->r4) = ctx->r3;
L_80059F80:
    // lh          $v0, 0x208($a0)
    ctx->r2 = MEM_HS(0X208, ctx->r4);
    // lhu         $v1, 0x208($a0)
    ctx->r3 = MEM_HU(0X208, ctx->r4);
    // bgez        $v0, L_80059F98
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80059F98;
    }
    // nop

    // j           L_80059F9C
    // sh          $zero, 0x1D0($a0)
    MEM_H(0X1D0, ctx->r4) = 0;
    goto L_80059F9C;
    // sh          $zero, 0x1D0($a0)
    MEM_H(0X1D0, ctx->r4) = 0;
L_80059F98:
    // sh          $v1, 0x1D0($a0)
    MEM_H(0X1D0, ctx->r4) = ctx->r3;
L_80059F9C:
    // addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // slt         $v0, $a0, $a1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_80059F38
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80059F38;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s1, $v0, -0x70A0
    ctx->r17 = ADD32(ctx->r2, -0X70A0);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s3, $v0, 0x7810
    ctx->r19 = ADD32(ctx->r2, 0X7810);
    // addiu       $v0, $s2, 0x8
    ctx->r2 = ADD32(ctx->r18, 0X8);
    // sw          $v0, 0x168($s2)
    MEM_W(0X168, ctx->r18) = ctx->r2;
    // sh          $zero, 0x2BC($s2)
    MEM_H(0X2BC, ctx->r18) = 0;
L_80059FC8:
    // addiu       $v0, $s0, -0x4
    ctx->r2 = ADD32(ctx->r16, -0X4);
    // sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_8005A0EC
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0xB
        ctx->r2 = ADD32(0, 0XB);
        goto L_8005A0EC;
    }
    // addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // beq         $s0, $v0, L_8005A0EC
    if (ctx->r16 == ctx->r2) {
        // addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
        goto L_8005A0EC;
    }
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // beq         $s0, $v0, L_8005A0EC
    if (ctx->r16 == ctx->r2) {
        // addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
        goto L_8005A0EC;
    }
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // beq         $s0, $v0, L_8005A0EC
    if (ctx->r16 == ctx->r2) {
        // slti        $v0, $s0, 0x11
        ctx->r2 = SIGNED(ctx->r16) < 0X11 ? 1 : 0;
        goto L_8005A0EC;
    }
    // slti        $v0, $s0, 0x11
    ctx->r2 = SIGNED(ctx->r16) < 0X11 ? 1 : 0;
    // beq         $v0, $zero, L_8005A0EC
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_8005A0EC;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // nop

    // bne         $v1, $v0, L_8005A020
    if (ctx->r3 != ctx->r2) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_8005A020;
    }
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // lw          $a0, 0x168($s2)
    ctx->r4 = MEM_W(0X168, ctx->r18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    sub_80014D5C(rdram, ctx);
    goto after_0;
    // addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // j           L_8005A0DC
    // nop

    goto L_8005A0DC;
    // nop

L_8005A020:
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a2, $v0, $s3
    ctx->r6 = ADD32(ctx->r2, ctx->r19);
    // lw          $v1, 0x168($s2)
    ctx->r3 = MEM_W(0X168, ctx->r18);
    // lbu         $v0, 0x24($a2)
    ctx->r2 = MEM_BU(0X24, ctx->r6);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
L_8005A048:
    // addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // lw          $v1, 0x168($s2)
    ctx->r3 = MEM_W(0X168, ctx->r18);
    // lbu         $a0, 0x10($a0)
    ctx->r4 = MEM_BU(0X10, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $a0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r4;
    // slti        $v0, $a1, 0xE
    ctx->r2 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_8005A048
    if (ctx->r2 != 0) {
        // sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5) << 1;
        goto L_8005A048;
    }
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // lw          $v0, 0x168($s2)
    ctx->r2 = MEM_W(0X168, ctx->r18);
    // nop

    // sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // lw          $v0, 0x168($s2)
    ctx->r2 = MEM_W(0X168, ctx->r18);
    // nop

    // sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // lbu         $a0, 0x22($a2)
    ctx->r4 = MEM_BU(0X22, ctx->r6);
    // nop

    // sltiu       $v0, $a0, 0x9
    ctx->r2 = ctx->r4 < 0X9 ? 1 : 0;
    // bne         $v0, $zero, L_8005A0B8
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_8005A0B8;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // lw          $v1, 0x168($s2)
    ctx->r3 = MEM_W(0X168, ctx->r18);
    // addiu       $v0, $a0, -0x9
    ctx->r2 = ADD32(ctx->r4, -0X9);
    // sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // lw          $v1, 0x168($s2)
    ctx->r3 = MEM_W(0X168, ctx->r18);
    // lbu         $v0, 0x23($a2)
    ctx->r2 = MEM_BU(0X23, ctx->r6);
    // nop

    // sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8005A0B8:
    // beq         $s0, $v0, L_8005A0DC
    if (ctx->r16 == ctx->r2) {
        // addiu       $v0, $zero, 0x11
        ctx->r2 = ADD32(0, 0X11);
        goto L_8005A0DC;
    }
    // addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // beq         $s0, $v0, L_8005A0DC
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_8005A0DC;
    }
    // nop

    // lhu         $v0, 0x2BC($s2)
    ctx->r2 = MEM_HU(0X2BC, ctx->r18);
    // lhu         $v1, 0x24($a2)
    ctx->r3 = MEM_HU(0X24, ctx->r6);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x2BC($s2)
    MEM_H(0X2BC, ctx->r18) = ctx->r2;
L_8005A0DC:
    // lw          $v0, 0x168($s2)
    ctx->r2 = MEM_W(0X168, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // sw          $v0, 0x168($s2)
    MEM_W(0X168, ctx->r18) = ctx->r2;
L_8005A0EC:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x15
    ctx->r2 = SIGNED(ctx->r16) < 0X15 ? 1 : 0;
    // bne         $v0, $zero, L_80059FC8
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
        goto L_80059FC8;
    }
    // addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, 0x44($a0)
    ctx->r3 = MEM_HU(0X44, ctx->r4);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_8005A15C
    if (ctx->r3 == ctx->r2) {
        // lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
        goto L_8005A15C;
    }
    // lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // lui         $v0, 0xAAAA
    ctx->r2 = S32(0XAAAA << 16);
    // ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $a1, -0x2D5E
    ctx->r5 = ADD32(ctx->r5, -0X2D5E);
    // mfhi        $t0
    ctx->r8 = hi;
    // srl         $v0, $t0, 1
    ctx->r2 = S32(U32(ctx->r8) >> 1);
    // sh          $v0, 0x16C($s2)
    MEM_H(0X16C, ctx->r18) = ctx->r2;
    // lhu         $v1, 0x16C($s2)
    ctx->r3 = MEM_HU(0X16C, ctx->r18);
    // lhu         $a0, 0x44($a0)
    ctx->r4 = MEM_HU(0X44, ctx->r4);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // j           L_8005A164
    // sh          $v0, 0x16E($s2)
    MEM_H(0X16E, ctx->r18) = ctx->r2;
    goto L_8005A164;
    // sh          $v0, 0x16E($s2)
    MEM_H(0X16E, ctx->r18) = ctx->r2;
L_8005A15C:
    // sh          $v1, 0x16C($s2)
    MEM_H(0X16C, ctx->r18) = ctx->r3;
    // sh          $zero, 0x16E($s2)
    MEM_H(0X16E, ctx->r18) = 0;
L_8005A164:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, 0x50($a0)
    ctx->r3 = MEM_HU(0X50, ctx->r4);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_8005A1C4
    if (ctx->r3 == ctx->r2) {
        // lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
        goto L_8005A1C4;
    }
    // lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // lui         $v0, 0xAAAA
    ctx->r2 = S32(0XAAAA << 16);
    // ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $a1, -0x2D5E
    ctx->r5 = ADD32(ctx->r5, -0X2D5E);
    // mfhi        $t0
    ctx->r8 = hi;
    // srl         $v0, $t0, 1
    ctx->r2 = S32(U32(ctx->r8) >> 1);
    // sh          $v0, 0x170($s2)
    MEM_H(0X170, ctx->r18) = ctx->r2;
    // lhu         $v1, 0x170($s2)
    ctx->r3 = MEM_HU(0X170, ctx->r18);
    // lhu         $a0, 0x50($a0)
    ctx->r4 = MEM_HU(0X50, ctx->r4);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // j           L_8005A1CC
    // sh          $v0, 0x172($s2)
    MEM_H(0X172, ctx->r18) = ctx->r2;
    goto L_8005A1CC;
    // sh          $v0, 0x172($s2)
    MEM_H(0X172, ctx->r18) = ctx->r2;
L_8005A1C4:
    // sh          $v1, 0x170($s2)
    MEM_H(0X170, ctx->r18) = ctx->r3;
    // sh          $zero, 0x172($s2)
    MEM_H(0X172, ctx->r18) = 0;
L_8005A1CC:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
L_8005A1D4:
    // sh          $zero, 0x286($v1)
    MEM_H(0X286, ctx->r3) = 0;
    // sh          $zero, 0x27A($v1)
    MEM_H(0X27A, ctx->r3) = 0;
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x6
    ctx->r2 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_8005A1D4
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
        goto L_8005A1D4;
    }
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // lbu         $v1, 0x9($s2)
    ctx->r3 = MEM_BU(0X9, ctx->r18);
    // lhu         $a0, 0xA($s2)
    ctx->r4 = MEM_HU(0XA, ctx->r18);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // lhu         $v0, 0x27A($v1)
    ctx->r2 = MEM_HU(0X27A, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x27A($v1)
    MEM_H(0X27A, ctx->r3) = ctx->r2;
    // lbu         $v1, 0x109($s2)
    ctx->r3 = MEM_BU(0X109, ctx->r18);
    // lhu         $a0, 0x10A($s2)
    ctx->r4 = MEM_HU(0X10A, ctx->r18);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // lhu         $v0, 0x27A($v1)
    ctx->r2 = MEM_HU(0X27A, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x27A($v1)
    MEM_H(0X27A, ctx->r3) = ctx->r2;
    // lbu         $v1, 0x29($s2)
    ctx->r3 = MEM_BU(0X29, ctx->r18);
    // lhu         $a0, 0x2A($s2)
    ctx->r4 = MEM_HU(0X2A, ctx->r18);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // lhu         $v0, 0x27A($v1)
    ctx->r2 = MEM_HU(0X27A, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x27A($v1)
    MEM_H(0X27A, ctx->r3) = ctx->r2;
    // lbu         $v1, 0x129($s2)
    ctx->r3 = MEM_BU(0X129, ctx->r18);
    // lhu         $a0, 0x12A($s2)
    ctx->r4 = MEM_HU(0X12A, ctx->r18);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // lhu         $v0, 0x27A($v1)
    ctx->r2 = MEM_HU(0X27A, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x27A($v1)
    MEM_H(0X27A, ctx->r3) = ctx->r2;
    // lbu         $v1, 0x89($s2)
    ctx->r3 = MEM_BU(0X89, ctx->r18);
    // lhu         $a0, 0x8A($s2)
    ctx->r4 = MEM_HU(0X8A, ctx->r18);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // lhu         $v0, 0x27A($v1)
    ctx->r2 = MEM_HU(0X27A, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x27A($v1)
    MEM_H(0X27A, ctx->r3) = ctx->r2;
    // lbu         $v1, 0xA9($s2)
    ctx->r3 = MEM_BU(0XA9, ctx->r18);
    // lhu         $a0, 0xAA($s2)
    ctx->r4 = MEM_HU(0XAA, ctx->r18);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // lhu         $v0, 0x286($v1)
    ctx->r2 = MEM_HU(0X286, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x286($v1)
    MEM_H(0X286, ctx->r3) = ctx->r2;
    // lbu         $v1, 0xC9($s2)
    ctx->r3 = MEM_BU(0XC9, ctx->r18);
    // lhu         $a0, 0xCA($s2)
    ctx->r4 = MEM_HU(0XCA, ctx->r18);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // lhu         $v0, 0x286($v1)
    ctx->r2 = MEM_HU(0X286, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x286($v1)
    MEM_H(0X286, ctx->r3) = ctx->r2;
    // lbu         $v1, 0x49($s2)
    ctx->r3 = MEM_BU(0X49, ctx->r18);
    // lhu         $a0, 0x4A($s2)
    ctx->r4 = MEM_HU(0X4A, ctx->r18);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // lhu         $v0, 0x286($v1)
    ctx->r2 = MEM_HU(0X286, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x286($v1)
    MEM_H(0X286, ctx->r3) = ctx->r2;
    // lbu         $v1, 0xE9($s2)
    ctx->r3 = MEM_BU(0XE9, ctx->r18);
    // lhu         $a0, 0xEA($s2)
    ctx->r4 = MEM_HU(0XEA, ctx->r18);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // lhu         $v0, 0x286($v1)
    ctx->r2 = MEM_HU(0X286, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x286($v1)
    MEM_H(0X286, ctx->r3) = ctx->r2;
    // lbu         $v1, 0x29($s2)
    ctx->r3 = MEM_BU(0X29, ctx->r18);
    // lhu         $a0, 0x2A($s2)
    ctx->r4 = MEM_HU(0X2A, ctx->r18);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // lhu         $v0, 0x286($v1)
    ctx->r2 = MEM_HU(0X286, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x286($v1)
    MEM_H(0X286, ctx->r3) = ctx->r2;
    // lbu         $v1, 0x129($s2)
    ctx->r3 = MEM_BU(0X129, ctx->r18);
    // lhu         $a0, 0x12A($s2)
    ctx->r4 = MEM_HU(0X12A, ctx->r18);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // lhu         $v0, 0x286($v1)
    ctx->r2 = MEM_HU(0X286, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x286($v1)
    MEM_H(0X286, ctx->r3) = ctx->r2;
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
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
