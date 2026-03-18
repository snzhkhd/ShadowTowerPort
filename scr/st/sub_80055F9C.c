#include "recomp.h"
#include "disable_warnings.h"

void sub_80055F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a1, $v0, -0x5EC8
    ctx->r5 = ADD32(ctx->r2, -0X5EC8);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a2, $v0, -0x51F8
    ctx->r6 = ADD32(ctx->r2, -0X51F8);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $t3, $v0, 0x2230
    ctx->r11 = ADD32(ctx->r2, 0X2230);
    // addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x45F8
    ctx->r2 = ADD32(ctx->r2, -0X45F8);
    // sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4) << 3;
    // addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
L_80055FD0:
    // bgez        $t1, L_80055FDC
    if (SIGNED(ctx->r9) >= 0) {
        // addu        $v0, $t1, $zero
        ctx->r2 = ADD32(ctx->r9, 0);
        goto L_80055FDC;
    }
    // addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
    // addiu       $v0, $t1, 0x1F
    ctx->r2 = ADD32(ctx->r9, 0X1F);
L_80055FDC:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // sllv        $v0, $t2, $v0
    ctx->r2 = S32(ctx->r10) << (ctx->r2 & 31);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // beq         $v1, $zero, L_80056008
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80056008;
    }
    // nop

    // sb          $t0, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r8;
L_80056008:
    // addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // slti        $v0, $t1, 0x40
    ctx->r2 = SIGNED(ctx->r9) < 0X40 ? 1 : 0;
    // bne         $v0, $zero, L_80055FD0
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0xD4
        ctx->r5 = ADD32(ctx->r5, 0XD4);
        goto L_80055FD0;
    }
    // addiu       $a1, $a1, 0xD4
    ctx->r5 = ADD32(ctx->r5, 0XD4);
    // addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $v1, $v1, -0x45F8
    ctx->r3 = ADD32(ctx->r3, -0X45F8);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $a1, $v0, 0x180
    ctx->r5 = ADD32(ctx->r2, 0X180);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80056034:
    // bgez        $t1, L_80056040
    if (SIGNED(ctx->r9) >= 0) {
        // addu        $v0, $t1, $zero
        ctx->r2 = ADD32(ctx->r9, 0);
        goto L_80056040;
    }
    // addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
    // addiu       $v0, $t1, 0x1F
    ctx->r2 = ADD32(ctx->r9, 0X1F);
L_80056040:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // sllv        $v0, $a3, $v0
    ctx->r2 = S32(ctx->r7) << (ctx->r2 & 31);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // beq         $v1, $zero, L_8005606C
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8005606C;
    }
    // nop

    // sb          $zero, 0x22($a2)
    MEM_B(0X22, ctx->r6) = 0;
L_8005606C:
    // addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // slti        $v0, $t1, 0x20
    ctx->r2 = SIGNED(ctx->r9) < 0X20 ? 1 : 0;
    // bne         $v0, $zero, L_80056034
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x30
        ctx->r6 = ADD32(ctx->r6, 0X30);
        goto L_80056034;
    }
    // addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x45F8
    ctx->r2 = ADD32(ctx->r2, -0X45F8);
    // sll         $v1, $a0, 5
    ctx->r3 = S32(ctx->r4) << 5;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $t9, $v1, 0x240
    ctx->r25 = ADD32(ctx->r3, 0X240);
    // addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // addiu       $t6, $v1, 0x840
    ctx->r14 = ADD32(ctx->r3, 0X840);
    // addiu       $t5, $v1, 0xE40
    ctx->r13 = ADD32(ctx->r3, 0XE40);
    // addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $t4, $v0, -0x4130
    ctx->r12 = ADD32(ctx->r2, -0X4130);
    // addiu       $a3, $t3, 0x2
    ctx->r7 = ADD32(ctx->r11, 0X2);
L_800560B0:
    // bgez        $t1, L_800560BC
    if (SIGNED(ctx->r9) >= 0) {
        // addu        $v0, $t1, $zero
        ctx->r2 = ADD32(ctx->r9, 0);
        goto L_800560BC;
    }
    // addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
    // addiu       $v0, $t1, 0x1F
    ctx->r2 = ADD32(ctx->r9, 0X1F);
L_800560BC:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // addu        $v1, $a0, $t9
    ctx->r3 = ADD32(ctx->r4, ctx->r25);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // sllv        $a1, $t8, $v0
    ctx->r5 = S32(ctx->r24) << (ctx->r2 & 31);
    // and         $v1, $v1, $a1
    ctx->r3 = ctx->r3 & ctx->r5;
    // beq         $v1, $zero, L_800560EC
    if (ctx->r3 == 0) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_800560EC;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // j           L_8005627C
    // sh          $v0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r2;
    goto L_8005627C;
    // sh          $v0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r2;
L_800560EC:
    // lbu         $v1, 0x3($a3)
    ctx->r3 = MEM_BU(0X3, ctx->r7);
    // nop

    // bltz        $v1, L_80056110
    if (SIGNED(ctx->r3) < 0) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_80056110;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80056148
    if (ctx->r2 != 0) {
        // addu        $v0, $a0, $t6
        ctx->r2 = ADD32(ctx->r4, ctx->r14);
        goto L_80056148;
    }
    // addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
    // beq         $v1, $v0, L_80056240
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $a0, $t6
        ctx->r2 = ADD32(ctx->r4, ctx->r14);
        goto L_80056240;
    }
    // addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
L_80056110:
    // addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // beq         $v0, $zero, L_8005612C
    if (ctx->r2 == 0) {
        // addu        $v0, $a0, $t5
        ctx->r2 = ADD32(ctx->r4, ctx->r13);
        goto L_8005612C;
    }
    // addu        $v0, $a0, $t5
    ctx->r2 = ADD32(ctx->r4, ctx->r13);
    // sb          $t7, 0x4D($a3)
    MEM_B(0X4D, ctx->r7) = ctx->r15;
L_8005612C:
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // beq         $v0, $zero, L_8005627C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005627C;
    }
    // nop

    // j           L_8005627C
    // sh          $t7, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r15;
    goto L_8005627C;
    // sh          $t7, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r15;
L_80056148:
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // beq         $v0, $zero, L_80056160
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_80056160;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x4D($a3)
    MEM_B(0X4D, ctx->r7) = ctx->r2;
L_80056160:
    // addu        $v0, $a0, $t5
    ctx->r2 = ADD32(ctx->r4, ctx->r13);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // beq         $v0, $zero, L_8005627C
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_8005627C;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lbu         $t0, 0x4C($a3)
    ctx->r8 = MEM_BU(0X4C, ctx->r7);
    // nop

    // addiu       $v1, $t0, -0x1
    ctx->r3 = ADD32(ctx->r8, -0X1);
    // addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
    // andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // beq         $v1, $v0, L_80056204
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80056204;
    }
    // nop

    // addu        $t2, $v0, $zero
    ctx->r10 = ADD32(ctx->r2, 0);
L_80056198:
    // andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    // lhu         $v0, 0x4A($a3)
    ctx->r2 = MEM_HU(0X4A, ctx->r7);
    // lhu         $v1, 0x48($a3)
    ctx->r3 = MEM_HU(0X48, ctx->r7);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // lbu         $a2, 0x0($a0)
    ctx->r6 = MEM_BU(0X0, ctx->r4);
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // addiu       $a0, $t0, -0x1
    ctx->r4 = ADD32(ctx->r8, -0X1);
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // lhu         $v1, 0x48($a3)
    ctx->r3 = MEM_HU(0X48, ctx->r7);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // bne         $a0, $t2, L_80056198
    if (ctx->r4 != ctx->r10) {
        // sb          $a2, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r6;
        goto L_80056198;
    }
    // sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
L_80056204:
    // lhu         $v1, 0x8($a3)
    ctx->r3 = MEM_HU(0X8, ctx->r7);
    // addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
    // bne         $v1, $v0, L_8005621C
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8005621C;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // j           L_80056230
    // sb          $v0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r2;
    goto L_80056230;
    // sb          $v0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r2;
L_8005621C:
    // lbu         $v0, 0x3($a3)
    ctx->r2 = MEM_BU(0X3, ctx->r7);
    // nop

    // bne         $v0, $t8, L_80056234
    if (ctx->r2 != ctx->r24) {
        // addiu       $v0, $zero, 0xFFF
        ctx->r2 = ADD32(0, 0XFFF);
        goto L_80056234;
    }
    // addiu       $v0, $zero, 0xFFF
    ctx->r2 = ADD32(0, 0XFFF);
    // sb          $t8, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r24;
L_80056230:
    // addiu       $v0, $zero, 0xFFF
    ctx->r2 = ADD32(0, 0XFFF);
L_80056234:
    // sh          $t7, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r15;
    // j           L_8005627C
    // sh          $v0, 0xE($a3)
    MEM_H(0XE, ctx->r7) = ctx->r2;
    goto L_8005627C;
    // sh          $v0, 0xE($a3)
    MEM_H(0XE, ctx->r7) = ctx->r2;
L_80056240:
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // beq         $v0, $zero, L_80056258
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_80056258;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x4D($a3)
    MEM_B(0X4D, ctx->r7) = ctx->r2;
L_80056258:
    // addu        $v0, $a0, $t5
    ctx->r2 = ADD32(ctx->r4, ctx->r13);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // beq         $v0, $zero, L_8005627C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005627C;
    }
    // nop

    // sh          $t7, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r15;
    // sh          $zero, 0xE($a3)
    MEM_H(0XE, ctx->r7) = 0;
    // sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
L_8005627C:
    // addiu       $a3, $a3, 0x58
    ctx->r7 = ADD32(ctx->r7, 0X58);
    // addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // slti        $v0, $t1, 0xF0
    ctx->r2 = SIGNED(ctx->r9) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_800560B0
    if (ctx->r2 != 0) {
        // addiu       $t3, $t3, 0x58
        ctx->r11 = ADD32(ctx->r11, 0X58);
        goto L_800560B0;
    }
    // addiu       $t3, $t3, 0x58
    ctx->r11 = ADD32(ctx->r11, 0X58);
    // lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // addiu       $a0, $a0, 0x5948
    ctx->r4 = ADD32(ctx->r4, 0X5948);
    // lw          $v0, 0x47E0($a0)
    ctx->r2 = MEM_W(0X47E0, ctx->r4);
    // addiu       $v1, $zero, -0x21
    ctx->r3 = ADD32(0, -0X21);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addiu       $v1, $zero, -0x11
    ctx->r3 = ADD32(0, -0X11);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addiu       $v1, $zero, -0x9
    ctx->r3 = ADD32(0, -0X9);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addiu       $v1, $zero, -0x5
    ctx->r3 = ADD32(0, -0X5);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addiu       $v1, $zero, -0x3
    ctx->r3 = ADD32(0, -0X3);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // addiu       $v1, $zero, -0x2
    ctx->r3 = ADD32(0, -0X2);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // jr          $ra
    // sw          $v0, 0x47E0($a0)
    MEM_W(0X47E0, ctx->r4) = ctx->r2;
    return;
    // sw          $v0, 0x47E0($a0)
    MEM_W(0X47E0, ctx->r4) = ctx->r2;
;}
