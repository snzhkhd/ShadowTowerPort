#include "recomp.h"
#include "disable_warnings.h"

void sub_80063CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
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
    // addiu       $s2, $v0, -0x2E80
    ctx->r18 = ADD32(ctx->r2, -0X2E80);
    // lhu         $v1, 0xC($s2)
    ctx->r3 = MEM_HU(0XC, ctx->r18);
    // nop

    // andi        $v0, $v1, 0x20
    ctx->r2 = ctx->r3 & 0X20;
    // beq         $v0, $zero, L_80063D44
    if (ctx->r2 == 0) {
        // lui         $s0, 0x1F80
        ctx->r16 = S32(0X1F80 << 16);
        goto L_80063D44;
    }
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // addiu       $a0, $a1, 0xCE8
    ctx->r4 = ADD32(ctx->r5, 0XCE8);
    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(0X8, ctx->r4);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $v1, $v0, L_80063D28
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_80063D28;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // j           L_80063D3C
    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    goto L_80063D3C;
    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
L_80063D28:
    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
L_80063D3C:
    // j           L_80063DC8
    // sw          $v0, 0xCE8($a1)
    MEM_W(0XCE8, ctx->r5) = ctx->r2;
    goto L_80063DC8;
    // sw          $v0, 0xCE8($a1)
    MEM_W(0XCE8, ctx->r5) = ctx->r2;
L_80063D44:
    // andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // beq         $v0, $zero, L_80063DD8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063DD8;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $a0, $v0, 0xCE8
    ctx->r4 = ADD32(ctx->r2, 0XCE8);
    // lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(0X8, ctx->r4);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_80063D88
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80063D88;
    }
    // nop

    // lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(0X8, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // j           L_80063D8C
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    goto L_80063D8C;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80063D88:
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
L_80063D8C:
    // sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $v0, $a0, 0xCE8
    ctx->r2 = ADD32(ctx->r4, 0XCE8);
    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_80063DB0
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80063DB0;
    }
    // nop

    // j           L_80063DC8
    // sw          $v1, 0xCE8($a0)
    MEM_W(0XCE8, ctx->r4) = ctx->r3;
    goto L_80063DC8;
    // sw          $v1, 0xCE8($a0)
    MEM_W(0XCE8, ctx->r4) = ctx->r3;
L_80063DB0:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lh          $v0, 0x0($v1)
    ctx->r2 = MEM_HS(0X0, ctx->r3);
    // nop

    // sw          $v0, 0xCE8($a0)
    MEM_W(0XCE8, ctx->r4) = ctx->r2;
L_80063DC8:
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // j           L_80064238
    // sw          $v0, 0xCF4($v1)
    MEM_W(0XCF4, ctx->r3) = ctx->r2;
    goto L_80064238;
    // sw          $v0, 0xCF4($v1)
    MEM_W(0XCF4, ctx->r3) = ctx->r2;
L_80063DD8:
    // lhu         $v1, 0x4($s2)
    ctx->r3 = MEM_HU(0X4, ctx->r18);
    // nop

    // andi        $v0, $v1, 0x2000
    ctx->r2 = ctx->r3 & 0X2000;
    // beq         $v0, $zero, L_80063E14
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x4000
        ctx->r2 = ctx->r3 & 0X4000;
        goto L_80063E14;
    }
    // andi        $v0, $v1, 0x4000
    ctx->r2 = ctx->r3 & 0X4000;
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // andi        $v0, $v0, 0xFFF7
    ctx->r2 = ctx->r2 & 0XFFF7;
    // jal         0x800152F8
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
    __builtin_delete(rdram, ctx);
    goto after_3;
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
    after_3:
    // j           L_8006423C
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    goto L_8006423C;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
L_80063E14:
    // beq         $v0, $zero, L_80064238
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80064238;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $s1, $v0, 0xCE8
    ctx->r17 = ADD32(ctx->r2, 0XCE8);
    // lw          $a0, 0xCE8($v0)
    ctx->r4 = MEM_W(0XCE8, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a0, $v0, L_800641D0
    if (ctx->r4 == ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_800641D0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v1, 0x10($s1)
    ctx->r3 = MEM_W(0X10, ctx->r17);
    // addiu       $v0, $v0, -0x70A0
    ctx->r2 = ADD32(ctx->r2, -0X70A0);
    // beq         $v1, $v0, L_80063E94
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $v0, 0x1A
        ctx->r2 = ADD32(ctx->r2, 0X1A);
        goto L_80063E94;
    }
    // addiu       $v0, $v0, 0x1A
    ctx->r2 = ADD32(ctx->r2, 0X1A);
    // beq         $v1, $v0, L_80063E94
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_80063E94;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x76F8
    ctx->r2 = ADD32(ctx->r2, 0X76F8);
    // sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4) << 1;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x13F($v1)
    ctx->r2 = MEM_BU(0X13F, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80063E94
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063E94;
    }
    // nop

    // lbu         $v0, 0x140($v1)
    ctx->r2 = MEM_BU(0X140, ctx->r3);
    // nop

    // bne         $v0, $zero, L_80063E94
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80063E94;
    }
    // nop

    // jal         0x80057D34
    // nop

    sub_80057D34(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // j           L_80064228
    // nop

    goto L_80064228;
    // nop

L_80063E94:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // sh          $zero, -0x2E7C($v1)
    MEM_H(-0X2E7C, ctx->r3) = 0;
    // andi        $v0, $v0, 0xFFF7
    ctx->r2 = ctx->r2 & 0XFFF7;
    // jal         0x800152F8
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
    __builtin_delete(rdram, ctx);
    goto after_6;
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
    after_6:
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // addiu       $v1, $a1, 0xCE8
    ctx->r3 = ADD32(ctx->r5, 0XCE8);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v1, 0x10($v1)
    ctx->r3 = MEM_W(0X10, ctx->r3);
    // addiu       $v0, $v0, -0x70A0
    ctx->r2 = ADD32(ctx->r2, -0X70A0);
    // bne         $v1, $v0, L_80063EF8
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $a1, 0xCE8
        ctx->r2 = ADD32(ctx->r5, 0XCE8);
        goto L_80063EF8;
    }
    // addiu       $v0, $a1, 0xCE8
    ctx->r2 = ADD32(ctx->r5, 0XCE8);
    // addiu       $a0, $v1, -0x38
    ctx->r4 = ADD32(ctx->r3, -0X38);
    // lhu         $v1, 0x38($a0)
    ctx->r3 = MEM_HU(0X38, ctx->r4);
    // lw          $v0, 0xCE8($a1)
    ctx->r2 = MEM_W(0XCE8, ctx->r5);
    // nop

    // beq         $v0, $v1, L_80063EF4
    if (ctx->r2 == ctx->r3) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80063EF4;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sh          $v0, 0x44($a0)
    MEM_H(0X44, ctx->r4) = ctx->r2;
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
L_80063EF4:
    // addiu       $v0, $a1, 0xCE8
    ctx->r2 = ADD32(ctx->r5, 0XCE8);
L_80063EF8:
    // lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(0X10, ctx->r2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x7086
    ctx->r2 = ADD32(ctx->r2, -0X7086);
    // bne         $v1, $v0, L_80063F24
    if (ctx->r3 != ctx->r2) {
        // addiu       $a0, $v1, -0x52
        ctx->r4 = ADD32(ctx->r3, -0X52);
        goto L_80063F24;
    }
    // addiu       $a0, $v1, -0x52
    ctx->r4 = ADD32(ctx->r3, -0X52);
    // lhu         $v1, 0x52($a0)
    ctx->r3 = MEM_HU(0X52, ctx->r4);
    // lw          $v0, 0xCE8($a1)
    ctx->r2 = MEM_W(0XCE8, ctx->r5);
    // nop

    // beq         $v0, $v1, L_80063F24
    if (ctx->r2 == ctx->r3) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80063F24;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sh          $v0, 0x50($a0)
    MEM_H(0X50, ctx->r4) = ctx->r2;
L_80063F24:
    // lui         $a1, 0x801E
    ctx->r5 = S32(0X801E << 16);
    // addiu       $a2, $a1, 0xCE8
    ctx->r6 = ADD32(ctx->r5, 0XCE8);
    // lw          $v1, 0x10($a2)
    ctx->r3 = MEM_W(0X10, ctx->r6);
    // lhu         $v0, 0xCE8($a1)
    ctx->r2 = MEM_HU(0XCE8, ctx->r5);
    // nop

    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v1, 0x10($a2)
    ctx->r3 = MEM_W(0X10, ctx->r6);
    // addiu       $a0, $v0, -0x709C
    ctx->r4 = ADD32(ctx->r2, -0X709C);
    // bne         $v1, $a0, L_80063F64
    if (ctx->r3 != ctx->r4) {
        // addiu       $v0, $a0, 0xE
        ctx->r2 = ADD32(ctx->r4, 0XE);
        goto L_80063F64;
    }
    // addiu       $v0, $a0, 0xE
    ctx->r2 = ADD32(ctx->r4, 0XE);
    // lhu         $v0, 0xCE8($a1)
    ctx->r2 = MEM_HU(0XCE8, ctx->r5);
    // nop

    // sh          $v0, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r2;
    // lw          $v1, 0x10($a2)
    ctx->r3 = MEM_W(0X10, ctx->r6);
    // addiu       $v0, $a0, 0xE
    ctx->r2 = ADD32(ctx->r4, 0XE);
L_80063F64:
    // bne         $v1, $v0, L_80063FBC
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80063FBC;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $a1, $a0, -0x3C
    ctx->r5 = ADD32(ctx->r4, -0X3C);
    // lhu         $v0, 0x4A($a1)
    ctx->r2 = MEM_HU(0X4A, ctx->r5);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // beq         $v0, $a2, L_80063FB8
    if (ctx->r2 == ctx->r6) {
        // lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
        goto L_80063FB8;
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
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // bne         $v1, $v0, L_80063FBC
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80063FBC;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // sh          $a2, 0x3C($a1)
    MEM_H(0X3C, ctx->r5) = ctx->r6;
    // sh          $a2, 0x4C($a1)
    MEM_H(0X4C, ctx->r5) = ctx->r6;
L_80063FB8:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
L_80063FBC:
    // lw          $a0, 0xCF8($v0)
    ctx->r4 = MEM_W(0XCF8, ctx->r2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x708C
    ctx->r3 = ADD32(ctx->r2, -0X708C);
    // beq         $a0, $v1, L_80063FD8
    if (ctx->r4 == ctx->r3) {
        // addiu       $v0, $v1, -0x10
        ctx->r2 = ADD32(ctx->r3, -0X10);
        goto L_80063FD8;
    }
    // addiu       $v0, $v1, -0x10
    ctx->r2 = ADD32(ctx->r3, -0X10);
    // bne         $a0, $v0, L_80064034
    if (ctx->r4 != ctx->r2) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80064034;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
L_80063FD8:
    // addiu       $a2, $v1, -0x4C
    ctx->r6 = ADD32(ctx->r3, -0X4C);
    // lhu         $v0, 0x4A($a2)
    ctx->r2 = MEM_HU(0X4A, ctx->r6);
    // ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // beq         $v0, $a1, L_80064034
    if (ctx->r2 == ctx->r5) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80064034;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // nop

    // beq         $v0, $a1, L_80064030
    if (ctx->r2 == ctx->r5) {
        // lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
        goto L_80064030;
    }
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lhu         $v1, 0x4A($a2)
    ctx->r3 = MEM_HU(0X4A, ctx->r6);
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
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // bne         $v1, $v0, L_80064034
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80064034;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // sh          $a1, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = ctx->r5;
L_80064030:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
L_80064034:
    // lw          $v1, 0xCF8($v0)
    ctx->r3 = MEM_W(0XCF8, ctx->r2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x709A
    ctx->r2 = ADD32(ctx->r2, -0X709A);
    // bne         $v1, $v0, L_80064094
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80064094;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $a1, $v1, -0x3E
    ctx->r5 = ADD32(ctx->r3, -0X3E);
    // lhu         $v0, 0x3E($a1)
    ctx->r2 = MEM_HU(0X3E, ctx->r5);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // beq         $v0, $a2, L_80064090
    if (ctx->r2 == ctx->r6) {
        // lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
        goto L_80064090;
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
    // bne         $v1, $v0, L_80064094
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80064094;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // sh          $a2, 0x58($a1)
    MEM_H(0X58, ctx->r5) = ctx->r6;
L_80064090:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
L_80064094:
    // lw          $v1, 0xCF8($v0)
    ctx->r3 = MEM_W(0XCF8, ctx->r2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x7098
    ctx->r2 = ADD32(ctx->r2, -0X7098);
    // bne         $v1, $v0, L_800640F4
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_800640F4;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $a1, $v1, -0x40
    ctx->r5 = ADD32(ctx->r3, -0X40);
    // lhu         $v0, 0x40($a1)
    ctx->r2 = MEM_HU(0X40, ctx->r5);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // beq         $v0, $a2, L_800640F0
    if (ctx->r2 == ctx->r6) {
        // lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
        goto L_800640F0;
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
    // bne         $v1, $v0, L_800640F4
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_800640F4;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // sh          $a2, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = ctx->r6;
L_800640F0:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
L_800640F4:
    // lw          $v1, 0xCF8($v0)
    ctx->r3 = MEM_W(0XCF8, ctx->r2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x7080
    ctx->r2 = ADD32(ctx->r2, -0X7080);
    // bne         $v1, $v0, L_80064164
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80064164;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $a1, $v1, -0x58
    ctx->r5 = ADD32(ctx->r3, -0X58);
    // lhu         $v0, 0x3E($a1)
    ctx->r2 = MEM_HU(0X3E, ctx->r5);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // beq         $v0, $a2, L_80064164
    if (ctx->r2 == ctx->r6) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80064164;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lhu         $v0, 0x58($a1)
    ctx->r2 = MEM_HU(0X58, ctx->r5);
    // nop

    // beq         $v0, $a2, L_80064160
    if (ctx->r2 == ctx->r6) {
        // lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
        goto L_80064160;
    }
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lhu         $v1, 0x3E($a1)
    ctx->r3 = MEM_HU(0X3E, ctx->r5);
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
    // bne         $v1, $v0, L_80064164
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_80064164;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // sh          $a2, 0x3E($a1)
    MEM_H(0X3E, ctx->r5) = ctx->r6;
L_80064160:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
L_80064164:
    // lw          $v1, 0xCF8($v0)
    ctx->r3 = MEM_W(0XCF8, ctx->r2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x707E
    ctx->r2 = ADD32(ctx->r2, -0X707E);
    // bne         $v1, $v0, L_80064228
    if (ctx->r3 != ctx->r2) {
        // addiu       $a1, $v1, -0x5A
        ctx->r5 = ADD32(ctx->r3, -0X5A);
        goto L_80064228;
    }
    // addiu       $a1, $v1, -0x5A
    ctx->r5 = ADD32(ctx->r3, -0X5A);
    // lhu         $v0, 0x40($a1)
    ctx->r2 = MEM_HU(0X40, ctx->r5);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // beq         $v0, $a2, L_80064228
    if (ctx->r2 == ctx->r6) {
        // nop
    
        goto L_80064228;
    }
    // nop

    // lhu         $v0, 0x5A($a1)
    ctx->r2 = MEM_HU(0X5A, ctx->r5);
    // nop

    // beq         $v0, $a2, L_80064228
    if (ctx->r2 == ctx->r6) {
        // lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
        goto L_80064228;
    }
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // lhu         $v1, 0x40($a1)
    ctx->r3 = MEM_HU(0X40, ctx->r5);
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
    // bne         $v1, $v0, L_80064228
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80064228;
    }
    // nop

    // j           L_80064228
    // sh          $a2, 0x40($a1)
    MEM_H(0X40, ctx->r5) = ctx->r6;
    goto L_80064228;
    // sh          $a2, 0x40($a1)
    MEM_H(0X40, ctx->r5) = ctx->r6;
L_800641D0:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // andi        $v0, $v0, 0xFFF7
    ctx->r2 = ctx->r2 & 0XFFF7;
    // jal         0x800152F8
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
    __builtin_delete(rdram, ctx);
    goto after_8;
    // sh          $v0, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = ctx->r2;
    after_8:
    // lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(0X10, ctx->r17);
    // ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v1, 0x10($s1)
    ctx->r3 = MEM_W(0X10, ctx->r17);
    // addiu       $a0, $v0, -0x70A0
    ctx->r4 = ADD32(ctx->r2, -0X70A0);
    // bne         $v1, $a0, L_80064218
    if (ctx->r3 != ctx->r4) {
        // addiu       $v0, $a0, 0x1A
        ctx->r2 = ADD32(ctx->r4, 0X1A);
        goto L_80064218;
    }
    // addiu       $v0, $a0, 0x1A
    ctx->r2 = ADD32(ctx->r4, 0X1A);
    // sh          $a1, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r5;
    // lw          $v1, 0x10($s1)
    ctx->r3 = MEM_W(0X10, ctx->r17);
L_80064218:
    // nop

    // bne         $v1, $v0, L_80064228
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80064228;
    }
    // nop

    // sh          $a1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r5;
L_80064228:
    // jal         0x80063BDC
    // nop

    sub_80063BDC(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // sh          $zero, -0x2E7C($v0)
    MEM_H(-0X2E7C, ctx->r2) = 0;
L_80064238:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
L_8006423C:
    // addiu       $v1, $v0, 0xCE8
    ctx->r3 = ADD32(ctx->r2, 0XCE8);
    // lw          $a1, 0xCE8($v0)
    ctx->r5 = MEM_W(0XCE8, ctx->r2);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // nop

    // beq         $a1, $v0, L_800642CC
    if (ctx->r5 == ctx->r2) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_800642CC;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $a1, $v0, L_8006426C
    if (ctx->r5 != ctx->r2) {
        // addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
        goto L_8006426C;
    }
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // addiu       $a1, $zero, 0x321
    ctx->r5 = ADD32(0, 0X321);
    // lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // j           L_8006429C
    // addiu       $a2, $a2, -0x7378
    ctx->r6 = ADD32(ctx->r6, -0X7378);
    goto L_8006429C;
    // addiu       $a2, $a2, -0x7378
    ctx->r6 = ADD32(ctx->r6, -0X7378);
L_8006426C:
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, 0x76F8
    ctx->r3 = ADD32(ctx->r3, 0X76F8);
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $a1, 0x11D($v0)
    ctx->r5 = MEM_BU(0X11D, ctx->r2);
    // lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // addiu       $a2, $a2, -0x7378
    ctx->r6 = ADD32(ctx->r6, -0X7378);
    // addiu       $a1, $a1, 0x258
    ctx->r5 = ADD32(ctx->r5, 0X258);
L_8006429C:
    // jal         0x80016030
    // nop

    sub_80016030(rdram, ctx);
    goto after_10;
    // nop

    after_10:
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
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // lw          $v1, 0xCE8($v0)
    ctx->r3 = MEM_W(0XCE8, ctx->r2);
    // addiu       $v0, $v0, 0xCE8
    ctx->r2 = ADD32(ctx->r2, 0XCE8);
    // sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
L_800642CC:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
