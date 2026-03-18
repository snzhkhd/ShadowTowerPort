#include "recomp.h"
#include "disable_warnings.h"

void sub_8005E924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lui         $v1, 0x1F80
    ctx->r3 = S32(0X1F80 << 16);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sh          $a0, 0x20($at)
    MEM_H(0X20, ctx->r1) = ctx->r4;
    // sh          $zero, 0x22($s0)
    MEM_H(0X22, ctx->r16) = 0;
L_8005E954:
    // lhu         $v0, 0x9A($a1)
    ctx->r2 = MEM_HU(0X9A, ctx->r5);
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // sh          $zero, 0x40($v1)
    MEM_H(0X40, ctx->r3) = 0;
    // sh          $v0, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r2;
    // slti        $v0, $a2, 0xE
    ctx->r2 = SIGNED(ctx->r6) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_8005E954
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
        goto L_8005E954;
    }
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s1, $v0, -0x2E80
    ctx->r17 = ADD32(ctx->r2, -0X2E80);
L_8005E984:
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // beq         $v0, $zero, L_8005E9A8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005E9A8;
    }
    // nop

    // jal         0x80057CEC
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    sub_80057CEC(rdram, ctx);
    goto after_1;
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    after_1:
    // j           L_8005EBEC
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    goto L_8005EBEC;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8005E9A8:
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8005EA10
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005EA10;
    }
    // nop

    // jal         0x80057D10
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    sub_80057D10(rdram, ctx);
    goto after_2;
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    after_2:
    // lui         $v1, 0x9249
    ctx->r3 = S32(0X9249 << 16);
    // lhu         $a1, 0x22($s0)
    ctx->r5 = MEM_HU(0X22, ctx->r16);
    // ori         $v1, $v1, 0x2493
    ctx->r3 = ctx->r3 | 0X2493;
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v1, $t0, $a0
    ctx->r3 = ADD32(ctx->r8, ctx->r4);
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // bne         $a0, $zero, L_8005EA0C
    if (ctx->r4 != 0) {
        // addiu       $v0, $a1, -0x1
        ctx->r2 = ADD32(ctx->r5, -0X1);
        goto L_8005EA0C;
    }
    // addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // addiu       $v0, $a1, 0x6
    ctx->r2 = ADD32(ctx->r5, 0X6);
L_8005EA0C:
    // sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
L_8005EA10:
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_8005EA80
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005EA80;
    }
    // nop

    // jal         0x80057D10
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    sub_80057D10(rdram, ctx);
    goto after_3;
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    after_3:
    // lui         $v1, 0x9249
    ctx->r3 = S32(0X9249 << 16);
    // lhu         $a1, 0x22($s0)
    ctx->r5 = MEM_HU(0X22, ctx->r16);
    // ori         $v1, $v1, 0x2493
    ctx->r3 = ctx->r3 | 0X2493;
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v1, $t0, $a0
    ctx->r3 = ADD32(ctx->r8, ctx->r4);
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // bne         $a0, $v0, L_8005EA7C
    if (ctx->r4 != ctx->r2) {
        // addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
        goto L_8005EA7C;
    }
    // addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // addiu       $v0, $a1, -0x6
    ctx->r2 = ADD32(ctx->r5, -0X6);
L_8005EA7C:
    // sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
L_8005EA80:
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // andi        $v0, $v0, 0xA0
    ctx->r2 = ctx->r2 & 0XA0;
    // beq         $v0, $zero, L_8005EAC0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005EAC0;
    }
    // nop

    // jal         0x80057D10
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    sub_80057D10(rdram, ctx);
    goto after_4;
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    after_4:
    // lhu         $v1, 0x22($s0)
    ctx->r3 = MEM_HU(0X22, ctx->r16);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x7
    ctx->r2 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // bne         $v0, $zero, L_8005EABC
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, 0x7
        ctx->r2 = ADD32(ctx->r3, 0X7);
        goto L_8005EABC;
    }
    // addiu       $v0, $v1, 0x7
    ctx->r2 = ADD32(ctx->r3, 0X7);
    // addiu       $v0, $v1, -0x7
    ctx->r2 = ADD32(ctx->r3, -0X7);
L_8005EABC:
    // sh          $v0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r2;
L_8005EAC0:
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // beq         $v0, $zero, L_8005EB70
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005EB70;
    }
    // nop

    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(0X20, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // blez        $a0, L_8005EB70
    if (SIGNED(ctx->r4) <= 0) {
        // nop
    
        goto L_8005EB70;
    }
    // nop

    // lhu         $v0, 0x22($s0)
    ctx->r2 = MEM_HU(0X22, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lh          $v1, 0x24($v0)
    ctx->r3 = MEM_HS(0X24, ctx->r2);
    // lh          $v0, 0x40($v0)
    ctx->r2 = MEM_HS(0X40, ctx->r2);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slti        $v1, $v1, 0x3E7
    ctx->r3 = SIGNED(ctx->r3) < 0X3E7 ? 1 : 0;
    // beq         $v1, $zero, L_8005EB68
    if (ctx->r3 == 0) {
        // slti        $v0, $a0, 0x2
        ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
        goto L_8005EB68;
    }
    // slti        $v0, $a0, 0x2
    ctx->r2 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8005EB30
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8005EB30;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_5;
    // nop

    after_5:
L_8005EB30:
    // lhu         $v0, 0x22($s0)
    ctx->r2 = MEM_HU(0X22, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 15
    ctx->r2 = S32(ctx->r2) >> 15;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lhu         $v1, 0x40($v0)
    ctx->r3 = MEM_HU(0X40, ctx->r2);
    // nop

    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sh          $v1, 0x40($v0)
    MEM_H(0X40, ctx->r2) = ctx->r3;
    // lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(0X20, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // j           L_8005EB70
    // sh          $v0, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r2;
    goto L_8005EB70;
    // sh          $v0, 0x20($s0)
    MEM_H(0X20, ctx->r16) = ctx->r2;
L_8005EB68:
    // jal         0x80057D34
    // nop

    sub_80057D34(rdram, ctx);
    goto after_6;
    // nop

    after_6:
L_8005EB70:
    // jal         0x800164B4
    // nop

    sub_800164B4(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // jal         0x8002A5A4
    // nop

    sub_8002A5A4(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(0X20, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_8005E984
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8005E984;
    }
    // nop

    // jal         0x8002A5A4
    // nop

    sub_8002A5A4(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a3, $v0, -0x70D8
    ctx->r7 = ADD32(ctx->r2, -0X70D8);
    // addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
L_8005EBB0:
    // lhu         $v0, 0x9A($a0)
    ctx->r2 = MEM_HU(0X9A, ctx->r4);
    // lhu         $v1, 0x40($a1)
    ctx->r3 = MEM_HU(0X40, ctx->r5);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r2;
    // lhu         $v1, 0x40($a1)
    ctx->r3 = MEM_HU(0X40, ctx->r5);
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // lhu         $v0, 0x8($a3)
    ctx->r2 = MEM_HU(0X8, ctx->r7);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r2;
    // slti        $v0, $a2, 0xE
    ctx->r2 = SIGNED(ctx->r6) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_8005EBB0
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
        goto L_8005EBB0;
    }
    // addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8005EBEC:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
