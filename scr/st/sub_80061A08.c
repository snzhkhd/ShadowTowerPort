#include "recomp.h"
#include "disable_warnings.h"

void sub_80061A08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 & 0XFF00;
    // beq         $v0, $zero, L_80061A7C
    if (ctx->r2 == 0) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_80061A7C;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(0X1F4, ctx->r16);
    // nop

    // lh          $v0, 0xE4($v1)
    ctx->r2 = MEM_HS(0XE4, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80061A7C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80061A7C;
    }
    // nop

    // lhu         $v0, 0xE2($v1)
    ctx->r2 = MEM_HU(0XE2, ctx->r3);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sh          $v1, 0x1FC($s0)
    MEM_H(0X1FC, ctx->r16) = ctx->r3;
    // j           L_80061A8C
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    goto L_80061A8C;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80061A64:
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // j           L_80061CD4
    // sh          $v0, 0x1FE($s0)
    MEM_H(0X1FE, ctx->r16) = ctx->r2;
    goto L_80061CD4;
    // sh          $v0, 0x1FE($s0)
    MEM_H(0X1FE, ctx->r16) = ctx->r2;
L_80061A7C:
    // lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(0X1F4, ctx->r16);
    // nop

    // lhu         $v0, 0xE2($v0)
    ctx->r2 = MEM_HU(0XE2, ctx->r2);
    // sh          $zero, 0x1FC($s0)
    MEM_H(0X1FC, ctx->r16) = 0;
L_80061A8C:
    // sh          $v0, 0x1FA($s0)
    MEM_H(0X1FA, ctx->r16) = ctx->r2;
    // sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // sh          $zero, 0x1FE($s0)
    MEM_H(0X1FE, ctx->r16) = 0;
    // sh          $zero, 0x200($s0)
    MEM_H(0X200, ctx->r16) = 0;
    // jal         0x80057A3C
    // sb          $zero, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = 0;
    sub_80057A3C(rdram, ctx);
    goto after_1;
    // sb          $zero, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = 0;
    after_1:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s1, $v0, -0x2E80
    ctx->r17 = ADD32(ctx->r2, -0X2E80);
    // addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80061AB0:
    // bne         $s2, $zero, L_80061AD4
    if (ctx->r18 != 0) {
        // nop
    
        goto L_80061AD4;
    }
    // nop

    // lhu         $a0, 0x1F8($s0)
    ctx->r4 = MEM_HU(0X1F8, ctx->r16);
    // nop

    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x80061578
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_80061578(rdram, ctx);
    goto after_2;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_2:
    // beq         $v0, $zero, L_80061D08
    if (ctx->r2 == 0) {
        // addiu       $s2, $zero, 0x14
        ctx->r18 = ADD32(0, 0X14);
        goto L_80061D08;
    }
    // addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
L_80061AD4:
    // lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(0X4, ctx->r17);
    // nop

    // andi        $v0, $v1, 0x4000
    ctx->r2 = ctx->r3 & 0X4000;
    // beq         $v0, $zero, L_80061BA8
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x2000
        ctx->r2 = ctx->r3 & 0X2000;
        goto L_80061BA8;
    }
    // andi        $v0, $v1, 0x2000
    ctx->r2 = ctx->r3 & 0X2000;
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // sh          $s3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r19;
    // sb          $v0, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = ctx->r2;
    // sh          $s3, 0x202($s0)
    MEM_H(0X202, ctx->r16) = ctx->r19;
L_80061B04:
    // lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(0X4, ctx->r17);
    // nop

    // andi        $v0, $v1, 0x4000
    ctx->r2 = ctx->r3 & 0X4000;
    // bne         $v0, $zero, L_80061B98
    if (ctx->r2 != 0) {
        // andi        $v0, $v1, 0x2000
        ctx->r2 = ctx->r3 & 0X2000;
        goto L_80061B98;
    }
    // andi        $v0, $v1, 0x2000
    ctx->r2 = ctx->r3 & 0X2000;
    // bne         $v0, $zero, L_80061B84
    if (ctx->r2 != 0) {
        // andi        $v0, $v1, 0x80
        ctx->r2 = ctx->r3 & 0X80;
        goto L_80061B84;
    }
    // andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // beq         $v0, $zero, L_80061B38
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80061B38;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // sh          $s3, 0x202($s0)
    MEM_H(0X202, ctx->r16) = ctx->r19;
L_80061B38:
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_80061B5C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80061B5C;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // sh          $zero, 0x202($s0)
    MEM_H(0X202, ctx->r16) = 0;
L_80061B5C:
    // jal         0x8002CA84
    // nop

    sub_8002CA84(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // j           L_80061B04
    // nop

    goto L_80061B04;
    // nop

L_80061B6C:
    // lhu         $v0, 0x202($s0)
    ctx->r2 = MEM_HU(0X202, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80061CD4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80061CD4;
    }
    // nop

    // j           L_80061AB0
    // sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    goto L_80061AB0;
    // sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
L_80061B84:
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // j           L_80061B6C
    // sh          $zero, 0x202($s0)
    MEM_H(0X202, ctx->r16) = 0;
    goto L_80061B6C;
    // sh          $zero, 0x202($s0)
    MEM_H(0X202, ctx->r16) = 0;
L_80061B98:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // j           L_80061B6C
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    goto L_80061B6C;
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
L_80061BA8:
    // bne         $v0, $zero, L_80061A64
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80061A64;
    }
    // nop

    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_80061C04
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80061C04;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lhu         $v0, 0x1FE($s0)
    ctx->r2 = MEM_HU(0X1FE, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80061BF8
    if (ctx->r2 != 0) {
        // sh          $zero, 0xC($s1)
        MEM_H(0XC, ctx->r17) = 0;
        goto L_80061BF8;
    }
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // lhu         $v1, 0x200($s0)
    ctx->r3 = MEM_HU(0X200, ctx->r16);
    // nop

    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // blez        $v0, L_80061C00
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
        goto L_80061C00;
    }
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // j           L_80061C00
    // sh          $v0, 0x200($s0)
    MEM_H(0X200, ctx->r16) = ctx->r2;
    goto L_80061C00;
    // sh          $v0, 0x200($s0)
    MEM_H(0X200, ctx->r16) = ctx->r2;
L_80061BF8:
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x1FE($s0)
    MEM_H(0X1FE, ctx->r16) = ctx->r2;
L_80061C00:
    // sb          $zero, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = 0;
L_80061C04:
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_80061CA0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80061CA0;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // lhu         $a1, 0x1FE($s0)
    ctx->r5 = MEM_HU(0X1FE, ctx->r16);
    // nop

    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $a0, $v0, L_80061C6C
    if (ctx->r4 != ctx->r2) {
        // sh          $zero, 0xC($s1)
        MEM_H(0XC, ctx->r17) = 0;
        goto L_80061C6C;
    }
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // lhu         $a0, 0x200($s0)
    ctx->r4 = MEM_HU(0X200, ctx->r16);
    // lhu         $v0, 0x1FA($s0)
    ctx->r2 = MEM_HU(0X1FA, ctx->r16);
    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_80061C9C
    if (ctx->r3 == 0) {
        // addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
        goto L_80061C9C;
    }
    // addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // j           L_80061C9C
    // sh          $v0, 0x200($s0)
    MEM_H(0X200, ctx->r16) = ctx->r2;
    goto L_80061C9C;
    // sh          $v0, 0x200($s0)
    MEM_H(0X200, ctx->r16) = ctx->r2;
L_80061C6C:
    // lhu         $v1, 0x200($s0)
    ctx->r3 = MEM_HU(0X200, ctx->r16);
    // lhu         $v0, 0x1FA($s0)
    ctx->r2 = MEM_HU(0X1FA, ctx->r16);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_80061C9C
    if (ctx->r3 == 0) {
        // addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
        goto L_80061C9C;
    }
    // addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // sh          $v0, 0x1FE($s0)
    MEM_H(0X1FE, ctx->r16) = ctx->r2;
L_80061C9C:
    // sb          $zero, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = 0;
L_80061CA0:
    // jal         0x8002CA84
    // nop

    sub_8002CA84(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // lbu         $a0, 0x2E4($s0)
    ctx->r4 = MEM_BU(0X2E4, ctx->r16);
    // nop

    // addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // bgez        $v1, L_80061CC0
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80061CC0;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_80061CC0:
    // andi        $v0, $v0, 0x1E0
    ctx->r2 = ctx->r2 & 0X1E0;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sb          $v0, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = ctx->r2;
    // j           L_80061AB0
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    goto L_80061AB0;
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80061CD4:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // lhu         $a0, 0x1FE($s0)
    ctx->r4 = MEM_HU(0X1FE, ctx->r16);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // beq         $v0, $v1, L_80061D10
    if (ctx->r2 == ctx->r3) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80061D10;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lhu         $v1, 0x200($s0)
    ctx->r3 = MEM_HU(0X200, ctx->r16);
    // nop

    // addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // j           L_80061D14
    // sh          $v1, 0x1FE($s0)
    MEM_H(0X1FE, ctx->r16) = ctx->r3;
    goto L_80061D14;
    // sh          $v1, 0x1FE($s0)
    MEM_H(0X1FE, ctx->r16) = ctx->r3;
L_80061D08:
    // j           L_80061D14
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80061D14;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80061D10:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80061D14:
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
