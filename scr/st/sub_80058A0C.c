#include "recomp.h"
#include "disable_warnings.h"

void sub_80058A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sll         $v0, $s3, 3
    ctx->r2 = S32(ctx->r19) << 3;
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x2E18
    ctx->r3 = ADD32(ctx->r3, -0X2E18);
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // sltiu       $v0, $s3, 0x18
    ctx->r2 = ctx->r19 < 0X18 ? 1 : 0;
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // beq         $v0, $zero, L_80058B34
    if (ctx->r2 == 0) {
        // sw          $s1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r17;
        goto L_80058B34;
    }
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x2870
    ctx->r2 = ADD32(ctx->r2, 0X2870);
    // sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_80058A68;
    jr_addend_80058A68 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80058A68 >> 2) {
        case 0: goto L_80058AA4; break;
        case 1: goto L_80058A90; break;
        case 2: goto L_80058A70; break;
        case 3: goto L_80058A70; break;
        case 4: goto L_80058A70; break;
        case 5: goto L_80058A70; break;
        case 6: goto L_80058AB4; break;
        case 7: goto L_80058AB4; break;
        case 8: goto L_80058AE4; break;
        case 9: goto L_80058AE4; break;
        case 10: goto L_80058AE4; break;
        case 11: goto L_80058AE4; break;
        case 12: goto L_80058AE4; break;
        case 13: goto L_80058AE4; break;
        case 14: goto L_80058AE4; break;
        case 15: goto L_80058AE4; break;
        case 16: goto L_80058AE4; break;
        case 17: goto L_80058AE4; break;
        case 18: goto L_80058AE4; break;
        case 19: goto L_80058AE4; break;
        case 20: goto L_80058AE4; break;
        case 21: goto L_80058AE4; break;
        case 22: goto L_80058AE4; break;
        case 23: goto L_80058AE4; break;
        default: switch_error(__func__, 0x80058A68, 0x80012870);
    }
    // nop

L_80058A70:
    // sll         $v1, $s3, 3
    ctx->r3 = S32(ctx->r19) << 3;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xCA4
    ctx->r2 = ADD32(ctx->r2, 0XCA4);
    // addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    // lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // ori         $a0, $a0, 0x9800
    ctx->r4 = ctx->r4 | 0X9800;
    // j           L_80058AD0
    // addiu       $v1, $s3, -0x2
    ctx->r3 = ADD32(ctx->r19, -0X2);
    goto L_80058AD0;
    // addiu       $v1, $s3, -0x2
    ctx->r3 = ADD32(ctx->r19, -0X2);
L_80058A90:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $s2, $v0, 0xCD4
    ctx->r18 = ADD32(ctx->r2, 0XCD4);
    // lui         $s1, 0x6
    ctx->r17 = S32(0X6 << 16);
    // j           L_80058B90
    // ori         $s1, $s1, 0x5400
    ctx->r17 = ctx->r17 | 0X5400;
    goto L_80058B90;
    // ori         $s1, $s1, 0x5400
    ctx->r17 = ctx->r17 | 0X5400;
L_80058AA4:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $s2, $v0, 0xCDC
    ctx->r18 = ADD32(ctx->r2, 0XCDC);
    // j           L_80058B90
    // addiu       $s1, $zero, 0x1000
    ctx->r17 = ADD32(0, 0X1000);
    goto L_80058B90;
    // addiu       $s1, $zero, 0x1000
    ctx->r17 = ADD32(0, 0X1000);
L_80058AB4:
    // sll         $v1, $s3, 3
    ctx->r3 = S32(ctx->r19) << 3;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xC34
    ctx->r2 = ADD32(ctx->r2, 0XC34);
    // addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    // lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // ori         $a0, $a0, 0x5800
    ctx->r4 = ctx->r4 | 0X5800;
    // addiu       $v1, $s3, -0x6
    ctx->r3 = ADD32(ctx->r19, -0X6);
L_80058AD0:
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // j           L_80058B90
    // addu        $s1, $v0, $a0
    ctx->r17 = ADD32(ctx->r2, ctx->r4);
    goto L_80058B90;
    // addu        $s1, $v0, $a0
    ctx->r17 = ADD32(ctx->r2, ctx->r4);
L_80058AE4:
    // addiu       $v0, $s3, -0x8
    ctx->r2 = ADD32(ctx->r19, -0X8);
    // bgez        $v0, L_80058AF4
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_80058AF4;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v1, $s3, -0x5
    ctx->r3 = ADD32(ctx->r19, -0X5);
L_80058AF4:
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
    // sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3) << 3;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xC74
    ctx->r2 = ADD32(ctx->r2, 0XC74);
    // addu        $s2, $a0, $v0
    ctx->r18 = ADD32(ctx->r4, ctx->r2);
    // lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    // ori         $a0, $a0, 0xE400
    ctx->r4 = ctx->r4 | 0XE400;
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) << 10;
    // j           L_80058B90
    // addu        $s1, $v0, $a0
    ctx->r17 = ADD32(ctx->r2, ctx->r4);
    goto L_80058B90;
    // addu        $s1, $v0, $a0
    ctx->r17 = ADD32(ctx->r2, ctx->r4);
L_80058B34:
    // slti        $v0, $s3, 0x144
    ctx->r2 = SIGNED(ctx->r19) < 0X144 ? 1 : 0;
    // beq         $v0, $zero, L_80058B7C
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
        goto L_80058B7C;
    }
    // addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // jal         0x80058770
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80058770(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(0X18, ctx->r29);
    // ori         $a0, $a0, 0xB800
    ctx->r4 = ctx->r4 | 0XB800;
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) << 10;
    // j           L_80058B84
    // addu        $s1, $v0, $a0
    ctx->r17 = ADD32(ctx->r2, ctx->r4);
    goto L_80058B84;
    // addu        $s1, $v0, $a0
    ctx->r17 = ADD32(ctx->r2, ctx->r4);
L_80058B7C:
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
L_80058B84:
    // beq         $s2, $zero, L_80058BDC
    if (ctx->r18 == 0) {
        // addiu       $v0, $zero, 0xFE
        ctx->r2 = ADD32(0, 0XFE);
        goto L_80058BDC;
    }
    // addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
L_80058B90:
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // sh          $v0, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r2;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lw          $s0, -0x742C($v0)
    ctx->r16 = MEM_W(-0X742C, ctx->r2);
    // jal         0x80015B2C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80015B2C(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // sb          $zero, 0x11($s0)
    MEM_B(0X11, ctx->r16) = 0;
    // sw          $s2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r18;
    // sh          $s3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r19;
    // sw          $s1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r17;
    // sb          $a0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r4;
    // sh          $a1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r5;
    // lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(0X0, ctx->r18);
    // jal         0x80015DA8
    // addiu       $a3, $a3, -0x774C
    ctx->r7 = ADD32(ctx->r7, -0X774C);
    sub_80015DA8(rdram, ctx);
    goto after_2;
    // addiu       $a3, $a3, -0x774C
    ctx->r7 = ADD32(ctx->r7, -0X774C);
    after_2:
L_80058BDC:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
