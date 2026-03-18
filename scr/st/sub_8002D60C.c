#include "recomp.h"
#include "disable_warnings.h"

void sub_8002D60C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lhu         $v0, 0x8($s2)
    ctx->r2 = MEM_HU(0X8, ctx->r18);
    // addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slti        $v0, $v1, 0x6
    ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_8002D65C
    if (ctx->r2 == 0) {
        // sw          $t0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r8;
        goto L_8002D65C;
    }
    // sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
L_8002D65C:
    // addiu       $a1, $zero, 0xF4
    ctx->r5 = ADD32(0, 0XF4);
    // addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // ori         $a3, $a3, 0x318
    ctx->r7 = ctx->r7 | 0X318;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s3, $v0, 0x7590
    ctx->r19 = ADD32(ctx->r2, 0X7590);
    // lbu         $a0, 0x10A($s3)
    ctx->r4 = MEM_BU(0X10A, ctx->r19);
    // lui         $v0, 0x300
    ctx->r2 = S32(0X300 << 16);
    // andi        $a0, $a0, 0x7F
    ctx->r4 = ctx->r4 & 0X7F;
    // jal         0x80027440
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    sub_80027440(rdram, ctx);
    goto after_0;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    after_0:
    // addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // ori         $a3, $a3, 0x308
    ctx->r7 = ctx->r7 | 0X308;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $s0, $v0, 0xD50
    ctx->r16 = ADD32(ctx->r2, 0XD50);
    // lhu         $a0, 0xC8($s0)
    ctx->r4 = MEM_HU(0XC8, ctx->r16);
    // addiu       $s1, $s0, 0xC00
    ctx->r17 = ADD32(ctx->r16, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    sub_8002732C(rdram, ctx);
    goto after_1;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_1:
    // lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(0X10, ctx->r29);
    // nop

    // blez        $t0, L_8002D8B4
    if (SIGNED(ctx->r8) <= 0) {
        // addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
        goto L_8002D8B4;
    }
    // addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // addiu       $fp, $zero, 0x3E
    ctx->r30 = ADD32(0, 0X3E);
    // addiu       $s7, $zero, 0x30
    ctx->r23 = ADD32(0, 0X30);
    // addu        $s6, $s5, $zero
    ctx->r22 = ADD32(ctx->r21, 0);
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
L_8002D6D0:
    // lhu         $v0, 0x2E2($s2)
    ctx->r2 = MEM_HU(0X2E2, ctx->r18);
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
    // addiu       $t0, $t0, 0x7590
    ctx->r8 = ADD32(ctx->r8, 0X7590);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // lhu         $s1, 0x13A($v0)
    ctx->r17 = MEM_HU(0X13A, ctx->r2);
    // addiu       $t0, $t0, 0x76F8
    ctx->r8 = ADD32(ctx->r8, 0X76F8);
    // sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17) << 1;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // addiu       $t0, $t0, 0x7590
    ctx->r8 = ADD32(ctx->r8, 0X7590);
    // lbu         $v1, 0x10A($t0)
    ctx->r3 = MEM_BU(0X10A, ctx->r8);
    // lbu         $v0, 0x11A($v0)
    ctx->r2 = MEM_BU(0X11A, ctx->r2);
    // andi        $v1, $v1, 0x7F
    ctx->r3 = ctx->r3 & 0X7F;
    // sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // bne         $v1, $zero, L_8002D74C
    if (ctx->r3 != 0) {
        // addiu       $s4, $s2, 0x30C
        ctx->r20 = ADD32(ctx->r18, 0X30C);
        goto L_8002D74C;
    }
    // addiu       $s4, $s2, 0x30C
    ctx->r20 = ADD32(ctx->r18, 0X30C);
    // addiu       $s4, $s2, 0x300
    ctx->r20 = ADD32(ctx->r18, 0X300);
    // j           L_8002D750
    // addiu       $s3, $s2, 0x310
    ctx->r19 = ADD32(ctx->r18, 0X310);
    goto L_8002D750;
    // addiu       $s3, $s2, 0x310
    ctx->r19 = ADD32(ctx->r18, 0X310);
L_8002D74C:
    // addiu       $s3, $s2, 0x31C
    ctx->r19 = ADD32(ctx->r18, 0X31C);
L_8002D750:
    // addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // andi        $a2, $s7, 0xFFFF
    ctx->r6 = ctx->r23 & 0XFFFF;
    // sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17) << 1;
    // lbu         $v1, 0x30F($s2)
    ctx->r3 = MEM_BU(0X30F, ctx->r18);
    // lbu         $v0, 0x303($s2)
    ctx->r2 = MEM_BU(0X303, ctx->r18);
    // ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    // sb          $v1, 0x30F($s2)
    MEM_B(0X30F, ctx->r18) = ctx->r3;
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sb          $v0, 0x303($s2)
    MEM_B(0X303, ctx->r18) = ctx->r2;
    // addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(0X0, ctx->r2);
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_2;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_2:
    // addu        $s0, $s0, $s1
    ctx->r16 = ADD32(ctx->r16, ctx->r17);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // subu        $s0, $s0, $s1
    ctx->r16 = SUB32(ctx->r16, ctx->r17);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // addiu       $t0, $t0, 0x76F8
    ctx->r8 = ADD32(ctx->r8, 0X76F8);
    // addu        $s1, $s0, $t0
    ctx->r17 = ADD32(ctx->r16, ctx->r8);
    // lbu         $v0, 0x303($s2)
    ctx->r2 = MEM_BU(0X303, ctx->r18);
    // lbu         $v1, 0x30F($s2)
    ctx->r3 = MEM_BU(0X30F, ctx->r18);
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // andi        $v1, $v1, 0x7F
    ctx->r3 = ctx->r3 & 0X7F;
    // sb          $v0, 0x303($s2)
    MEM_B(0X303, ctx->r18) = ctx->r2;
    // sb          $v1, 0x30F($s2)
    MEM_B(0X30F, ctx->r18) = ctx->r3;
    // lbu         $v0, 0x13F($s1)
    ctx->r2 = MEM_BU(0X13F, ctx->r17);
    // nop

    // beq         $v0, $zero, L_8002D848
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x48
        ctx->r5 = ADD32(0, 0X48);
        goto L_8002D848;
    }
    // addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // andi        $s0, $fp, 0xFFFF
    ctx->r16 = ctx->r30 & 0XFFFF;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // addiu       $t0, $t0, 0xD50
    ctx->r8 = ADD32(ctx->r8, 0XD50);
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // lhu         $a0, 0xDA($t0)
    ctx->r4 = MEM_HU(0XDA, ctx->r8);
    // lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // addiu       $t0, $t0, 0x1950
    ctx->r8 = ADD32(ctx->r8, 0X1950);
    // jal         0x8002732C
    // addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    sub_8002732C(rdram, ctx);
    goto after_3;
    // addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    after_3:
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // lbu         $a0, 0x140($s1)
    ctx->r4 = MEM_BU(0X140, ctx->r17);
    // lui         $t0, 0x300
    ctx->r8 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    sub_80027440(rdram, ctx);
    goto after_4;
    // or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    after_4:
    // addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // jal         0x80026ECC
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    sub_80026ECC(rdram, ctx);
    goto after_5;
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_5:
    // addiu       $a1, $zero, 0xAC
    ctx->r5 = ADD32(0, 0XAC);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // lbu         $a0, 0x13F($s1)
    ctx->r4 = MEM_BU(0X13F, ctx->r17);
    // lui         $t0, 0x300
    ctx->r8 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    sub_80027440(rdram, ctx);
    goto after_6;
    // or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    after_6:
L_8002D848:
    // addiu       $a1, $zero, 0xF4
    ctx->r5 = ADD32(0, 0XF4);
    // addiu       $s0, $s6, 0x3E
    ctx->r16 = ADD32(ctx->r22, 0X3E);
    // andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // addiu       $fp, $fp, 0x24
    ctx->r30 = ADD32(ctx->r30, 0X24);
    // addiu       $s7, $s7, 0x24
    ctx->r23 = ADD32(ctx->r23, 0X24);
    // addiu       $s6, $s6, 0x24
    ctx->r22 = ADD32(ctx->r22, 0X24);
    // lbu         $a0, 0x11A($s1)
    ctx->r4 = MEM_BU(0X11A, ctx->r17);
    // lui         $t0, 0x300
    ctx->r8 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    sub_80027440(rdram, ctx);
    goto after_7;
    // or          $a0, $a0, $t0
    ctx->r4 = ctx->r4 | ctx->r8;
    after_7:
    // addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // addiu       $t0, $t0, 0xD50
    ctx->r8 = ADD32(ctx->r8, 0XD50);
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // lhu         $a0, 0xCC($t0)
    ctx->r4 = MEM_HU(0XCC, ctx->r8);
    // lui         $t0, 0x801E
    ctx->r8 = S32(0X801E << 16);
    // addiu       $t0, $t0, 0x1950
    ctx->r8 = ADD32(ctx->r8, 0X1950);
    // jal         0x8002732C
    // addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    sub_8002732C(rdram, ctx);
    goto after_8;
    // addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    after_8:
    // lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(0X10, ctx->r29);
    // addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // slt         $v0, $s5, $t0
    ctx->r2 = SIGNED(ctx->r21) < SIGNED(ctx->r8) ? 1 : 0;
    // bne         $v0, $zero, L_8002D6D0
    if (ctx->r2 != 0) {
        // lui         $t0, 0x801C
        ctx->r8 = S32(0X801C << 16);
        goto L_8002D6D0;
    }
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
L_8002D8B4:
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(0X38, ctx->r29);
    // lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
