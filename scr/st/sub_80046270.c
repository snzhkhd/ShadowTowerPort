#include "recomp.h"
#include "disable_warnings.h"

void sub_80046270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // nop

    // bgez        $v0, L_80046284
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $sp, $sp, -0x40
        ctx->r29 = ADD32(ctx->r29, -0X40);
        goto L_80046284;
    }
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80046284:
    // lw          $a3, 0x4($a0)
    ctx->r7 = MEM_W(0X4, ctx->r4);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $t1, $v1, 0x56D0
    ctx->r9 = ADD32(ctx->r3, 0X56D0);
    // bgez        $a3, L_800462A4
    if (SIGNED(ctx->r7) >= 0) {
        // addu        $t4, $v0, $t1
        ctx->r12 = ADD32(ctx->r2, ctx->r9);
        goto L_800462A4;
    }
    // addu        $t4, $v0, $t1
    ctx->r12 = ADD32(ctx->r2, ctx->r9);
    // addiu       $a3, $a3, 0xFFF
    ctx->r7 = ADD32(ctx->r7, 0XFFF);
L_800462A4:
    // lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(0X8, ctx->r4);
    // sra         $v0, $a3, 12
    ctx->r2 = S32(ctx->r7) >> 12;
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // addiu       $v1, $t1, 0x2000
    ctx->r3 = ADD32(ctx->r9, 0X2000);
    // bgez        $a0, L_800462C0
    if (SIGNED(ctx->r4) >= 0) {
        // addu        $v0, $v0, $v1
        ctx->r2 = ADD32(ctx->r2, ctx->r3);
        goto L_800462C0;
    }
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $a0, $a0, 0xFFF
    ctx->r4 = ADD32(ctx->r4, 0XFFF);
L_800462C0:
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addu        $t3, $sp, $zero
    ctx->r11 = ADD32(ctx->r29, 0);
    // addu        $t2, $v0, $zero
    ctx->r10 = ADD32(ctx->r2, 0);
    // sra         $v0, $a0, 12
    ctx->r2 = S32(ctx->r4) >> 12;
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // addiu       $v1, $t1, 0x4000
    ctx->r3 = ADD32(ctx->r9, 0X4000);
    // addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    // addu        $a3, $t4, $zero
    ctx->r7 = ADD32(ctx->r12, 0);
L_800462E0:
    // lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(0X0, ctx->r10);
    // addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(0X0, ctx->r9);
    // addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // slti        $v0, $t0, 0x10
    ctx->r2 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_800462E0
    if (ctx->r2 != 0) {
        // addiu       $t3, $t3, 0x4
        ctx->r11 = ADD32(ctx->r11, 0X4);
        goto L_800462E0;
    }
    // addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // beq         $a1, $zero, L_800463C8
    if (ctx->r5 == 0) {
        // nop
    
        goto L_800463C8;
    }
    // nop

    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // nop

    // bgez        $v0, L_80046330
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80046330;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80046330:
    // lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(0X4, ctx->r5);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $t1, $v1, 0x56D0
    ctx->r9 = ADD32(ctx->r3, 0X56D0);
    // bgez        $a0, L_80046350
    if (SIGNED(ctx->r4) >= 0) {
        // addu        $t3, $v0, $t1
        ctx->r11 = ADD32(ctx->r2, ctx->r9);
        goto L_80046350;
    }
    // addu        $t3, $v0, $t1
    ctx->r11 = ADD32(ctx->r2, ctx->r9);
    // addiu       $a0, $a0, 0xFFF
    ctx->r4 = ADD32(ctx->r4, 0XFFF);
L_80046350:
    // lw          $a1, 0x8($a1)
    ctx->r5 = MEM_W(0X8, ctx->r5);
    // sra         $v0, $a0, 12
    ctx->r2 = S32(ctx->r4) >> 12;
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // addiu       $v1, $t1, 0x2000
    ctx->r3 = ADD32(ctx->r9, 0X2000);
    // bgez        $a1, L_8004636C
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v0, $v0, $v1
        ctx->r2 = ADD32(ctx->r2, ctx->r3);
        goto L_8004636C;
    }
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $a1, $a1, 0xFFF
    ctx->r5 = ADD32(ctx->r5, 0XFFF);
L_8004636C:
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addu        $a3, $sp, $zero
    ctx->r7 = ADD32(ctx->r29, 0);
    // addu        $t2, $v0, $zero
    ctx->r10 = ADD32(ctx->r2, 0);
    // sra         $v0, $a1, 12
    ctx->r2 = S32(ctx->r5) >> 12;
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // addiu       $v1, $t1, 0x4000
    ctx->r3 = ADD32(ctx->r9, 0X4000);
    // addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    // addu        $a1, $t3, $zero
    ctx->r5 = ADD32(ctx->r11, 0);
L_8004638C:
    // lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(0X0, ctx->r10);
    // addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(0X0, ctx->r9);
    // addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // slti        $v0, $t0, 0x10
    ctx->r2 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_8004638C
    if (ctx->r2 != 0) {
        // addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
        goto L_8004638C;
    }
    // addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_800463C8:
    // beq         $a2, $zero, L_8004647C
    if (ctx->r6 == 0) {
        // nop
    
        goto L_8004647C;
    }
    // nop

    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // nop

    // bgez        $v0, L_800463E4
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800463E4;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_800463E4:
    // lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(0X4, ctx->r6);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // addiu       $a3, $v1, 0x56D0
    ctx->r7 = ADD32(ctx->r3, 0X56D0);
    // bgez        $a0, L_80046404
    if (SIGNED(ctx->r4) >= 0) {
        // addu        $t2, $v0, $a3
        ctx->r10 = ADD32(ctx->r2, ctx->r7);
        goto L_80046404;
    }
    // addu        $t2, $v0, $a3
    ctx->r10 = ADD32(ctx->r2, ctx->r7);
    // addiu       $a0, $a0, 0xFFF
    ctx->r4 = ADD32(ctx->r4, 0XFFF);
L_80046404:
    // lw          $a2, 0x8($a2)
    ctx->r6 = MEM_W(0X8, ctx->r6);
    // sra         $v0, $a0, 12
    ctx->r2 = S32(ctx->r4) >> 12;
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // addiu       $v1, $a3, 0x2000
    ctx->r3 = ADD32(ctx->r7, 0X2000);
    // bgez        $a2, L_80046420
    if (SIGNED(ctx->r6) >= 0) {
        // addu        $v0, $v0, $v1
        ctx->r2 = ADD32(ctx->r2, ctx->r3);
        goto L_80046420;
    }
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $a2, $a2, 0xFFF
    ctx->r6 = ADD32(ctx->r6, 0XFFF);
L_80046420:
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addu        $a1, $sp, $zero
    ctx->r5 = ADD32(ctx->r29, 0);
    // addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // sra         $v0, $a2, 12
    ctx->r2 = S32(ctx->r6) >> 12;
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // addiu       $v1, $a3, 0x4000
    ctx->r3 = ADD32(ctx->r7, 0X4000);
    // addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
    // addu        $a2, $t2, $zero
    ctx->r6 = ADD32(ctx->r10, 0);
L_80046440:
    // lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(0X0, ctx->r9);
    // addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(0X0, ctx->r6);
    // addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // slti        $v0, $t0, 0x10
    ctx->r2 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80046440
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
        goto L_80046440;
    }
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8004647C:
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // addiu       $t4, $t2, 0x5920
    ctx->r12 = ADD32(ctx->r10, 0X5920);
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $t3, $v0, -0x4130
    ctx->r11 = ADD32(ctx->r2, -0X4130);
    // addu        $a0, $sp, $zero
    ctx->r4 = ADD32(ctx->r29, 0);
L_80046498:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $t1, $v0, 0x5090
    ctx->r9 = ADD32(ctx->r2, 0X5090);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $a3, $v0, 0x5948
    ctx->r7 = ADD32(ctx->r2, 0X5948);
L_800464AC:
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80046534
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80046534;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lh          $v1, 0x5920($t2)
    ctx->r3 = MEM_HS(0X5920, ctx->r10);
    // nop

    // bne         $v1, $v0, L_80046510
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80046510;
    }
    // nop

    // lbu         $v0, 0x1D($t4)
    ctx->r2 = MEM_BU(0X1D, ctx->r12);
    // nop

    // beq         $v0, $zero, L_80046510
    if (ctx->r2 == 0) {
        // sll         $v1, $a2, 16
        ctx->r3 = S32(ctx->r6) << 16;
        goto L_80046510;
    }
    // sll         $v1, $a2, 16
    ctx->r3 = S32(ctx->r6) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lw          $v1, 0x30C($t1)
    ctx->r3 = MEM_W(0X30C, ctx->r9);
    // addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(0X4, ctx->r3);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_80046534
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80046534;
    }
    // nop

L_80046510:
    // lhu         $v0, 0x44CA($a3)
    ctx->r2 = MEM_HU(0X44CA, ctx->r7);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // sh          $a2, 0x44CE($v0)
    MEM_H(0X44CE, ctx->r2) = ctx->r6;
    // lhu         $v0, 0x44CA($a3)
    ctx->r2 = MEM_HU(0X44CA, ctx->r7);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0x44CA($a3)
    MEM_H(0X44CA, ctx->r7) = ctx->r2;
L_80046534:
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // slti        $v0, $a1, 0x20
    ctx->r2 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // bne         $v0, $zero, L_800464AC
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_800464AC;
    }
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // slti        $v0, $t0, 0x10
    ctx->r2 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80046498
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_80046498;
    }
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
