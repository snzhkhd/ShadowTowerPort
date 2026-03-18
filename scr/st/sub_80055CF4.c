#include "recomp.h"
#include "disable_warnings.h"

void sub_80055CF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a2, $v0, -0x5EC8
    ctx->r6 = ADD32(ctx->r2, -0X5EC8);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $t0, $v0, -0x51F8
    ctx->r8 = ADD32(ctx->r2, -0X51F8);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $t6, $v0, 0x2230
    ctx->r14 = ADD32(ctx->r2, 0X2230);
    // addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x45F8
    ctx->r2 = ADD32(ctx->r2, -0X45F8);
    // sll         $v1, $t2, 3
    ctx->r3 = S32(ctx->r10) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_80055D28:
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_80055D28
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
        goto L_80055D28;
    }
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x45F8
    ctx->r2 = ADD32(ctx->r2, -0X45F8);
    // sll         $v1, $t2, 3
    ctx->r3 = S32(ctx->r10) << 3;
    // addu        $a3, $v1, $v0
    ctx->r7 = ADD32(ctx->r3, ctx->r2);
    // addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80055D60:
    // lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(0X0, ctx->r6);
    // nop

    // beq         $v0, $t5, L_80055DB8
    if (ctx->r2 == ctx->r13) {
        // nop
    
        goto L_80055DB8;
    }
    // nop

    // lbu         $v0, 0x5($a2)
    ctx->r2 = MEM_BU(0X5, ctx->r6);
    // nop

    // beq         $v0, $t4, L_80055D88
    if (ctx->r2 == ctx->r12) {
        // nop
    
        goto L_80055D88;
    }
    // nop

    // bne         $v0, $t3, L_80055DB8
    if (ctx->r2 != ctx->r11) {
        // nop
    
        goto L_80055DB8;
    }
    // nop

L_80055D88:
    // bgez        $a1, L_80055D94
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_80055D94;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // addiu       $v0, $a1, 0x1F
    ctx->r2 = ADD32(ctx->r5, 0X1F);
L_80055D94:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $a3
    ctx->r4 = ADD32(ctx->r4, ctx->r7);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // sllv        $v0, $t1, $v0
    ctx->r2 = S32(ctx->r9) << (ctx->r2 & 31);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_80055DB8:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x40
    ctx->r2 = SIGNED(ctx->r5) < 0X40 ? 1 : 0;
    // bne         $v0, $zero, L_80055D60
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0xD4
        ctx->r6 = ADD32(ctx->r6, 0XD4);
        goto L_80055D60;
    }
    // addiu       $a2, $a2, 0xD4
    ctx->r6 = ADD32(ctx->r6, 0XD4);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $v1, $v1, -0x45F8
    ctx->r3 = ADD32(ctx->r3, -0X45F8);
    // sll         $v0, $t2, 2
    ctx->r2 = S32(ctx->r10) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v1, $v0, 0x180
    ctx->r3 = ADD32(ctx->r2, 0X180);
L_80055DE4:
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_80055DE4
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
        goto L_80055DE4;
    }
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $v1, $v1, -0x45F8
    ctx->r3 = ADD32(ctx->r3, -0X45F8);
    // sll         $v0, $t2, 2
    ctx->r2 = S32(ctx->r10) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $a2, $v0, 0x180
    ctx->r6 = ADD32(ctx->r2, 0X180);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80055E14:
    // lbu         $v0, 0x22($t0)
    ctx->r2 = MEM_BU(0X22, ctx->r8);
    // nop

    // bne         $v0, $zero, L_80055E54
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80055E54;
    }
    // nop

    // bgez        $a1, L_80055E30
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_80055E30;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // addiu       $v0, $a1, 0x1F
    ctx->r2 = ADD32(ctx->r5, 0X1F);
L_80055E30:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // sllv        $v0, $a3, $v0
    ctx->r2 = S32(ctx->r7) << (ctx->r2 & 31);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_80055E54:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x20
    ctx->r2 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    // bne         $v0, $zero, L_80055E14
    if (ctx->r2 != 0) {
        // addiu       $t0, $t0, 0x30
        ctx->r8 = ADD32(ctx->r8, 0X30);
        goto L_80055E14;
    }
    // addiu       $t0, $t0, 0x30
    ctx->r8 = ADD32(ctx->r8, 0X30);
    // addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $v1, $v1, -0x45F8
    ctx->r3 = ADD32(ctx->r3, -0X45F8);
    // sll         $v0, $t2, 5
    ctx->r2 = S32(ctx->r10) << 5;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $a2, $v0, 0xE40
    ctx->r6 = ADD32(ctx->r2, 0XE40);
    // addiu       $a0, $v0, 0x840
    ctx->r4 = ADD32(ctx->r2, 0X840);
    // addiu       $v1, $v0, 0x240
    ctx->r3 = ADD32(ctx->r2, 0X240);
L_80055E88:
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_80055E88
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
        goto L_80055E88;
    }
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x45F8
    ctx->r2 = ADD32(ctx->r2, -0X45F8);
    // sll         $v1, $t2, 5
    ctx->r3 = S32(ctx->r10) << 5;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $t3, $v1, 0x240
    ctx->r11 = ADD32(ctx->r3, 0X240);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // addiu       $t2, $v1, 0x840
    ctx->r10 = ADD32(ctx->r3, 0X840);
    // addiu       $t1, $v1, 0xE40
    ctx->r9 = ADD32(ctx->r3, 0XE40);
    // addiu       $a2, $t6, 0xC
    ctx->r6 = ADD32(ctx->r14, 0XC);
L_80055ED8:
    // lhu         $v1, -0x2($a2)
    ctx->r3 = MEM_HU(-0X2, ctx->r6);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // bne         $v1, $v0, L_80055F04
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80055F04;
    }
    // nop

    // bgez        $a1, L_80055EF4
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_80055EF4;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // addiu       $v0, $a1, 0x1F
    ctx->r2 = ADD32(ctx->r5, 0X1F);
L_80055EF4:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // j           L_80055F6C
    // addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    goto L_80055F6C;
    // addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
L_80055F04:
    // lbu         $v0, 0x43($a2)
    ctx->r2 = MEM_BU(0X43, ctx->r6);
    // nop

    // bne         $v0, $t0, L_80055F44
    if (ctx->r2 != ctx->r8) {
        // nop
    
        goto L_80055F44;
    }
    // nop

    // bgez        $a1, L_80055F20
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_80055F20;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // addiu       $v0, $a1, 0x1F
    ctx->r2 = ADD32(ctx->r5, 0X1F);
L_80055F20:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // sllv        $v0, $a3, $v0
    ctx->r2 = S32(ctx->r7) << (ctx->r2 & 31);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_80055F44:
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // nop

    // bne         $v0, $t0, L_80055F84
    if (ctx->r2 != ctx->r8) {
        // nop
    
        goto L_80055F84;
    }
    // nop

    // bgez        $a1, L_80055F60
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_80055F60;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // addiu       $v0, $a1, 0x1F
    ctx->r2 = ADD32(ctx->r5, 0X1F);
L_80055F60:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
L_80055F6C:
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // sllv        $v0, $a3, $v0
    ctx->r2 = S32(ctx->r7) << (ctx->r2 & 31);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_80055F84:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0xF0
    ctx->r2 = SIGNED(ctx->r5) < 0XF0 ? 1 : 0;
    // bne         $v0, $zero, L_80055ED8
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x58
        ctx->r6 = ADD32(ctx->r6, 0X58);
        goto L_80055ED8;
    }
    // addiu       $a2, $a2, 0x58
    ctx->r6 = ADD32(ctx->r6, 0X58);
    // jr          $ra
    // nop

    return;
    // nop

;}
