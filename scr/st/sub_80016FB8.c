#include "recomp.h"
#include "disable_warnings.h"

void sub_80016FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // jal         0x800796E4
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    ResetGraph(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // jal         0x80079858
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    SetGraphDebug(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // jal         0x8007463C
    // addiu       $s2, $zero, 0xF0
    ctx->r18 = ADD32(0, 0XF0);
    sub_8007463C(rdram, ctx);
    goto after_2;
    // addiu       $s2, $zero, 0xF0
    ctx->r18 = ADD32(0, 0XF0);
    after_2:
    // addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // sll         $t4, $t1, 16
    ctx->r12 = S32(ctx->r9) << 16;
    // sll         $t5, $t2, 16
    ctx->r13 = S32(ctx->r10) << 16;
    // ctc2        $t4, $24
    gte_ctc2(ctx, 12, 24);
    // ctc2        $t5, $25
    gte_ctc2(ctx, 13, 25);
    // addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // ctc2        $t3, $26
    gte_ctc2(ctx, 11, 26);
    // lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // addiu       $s0, $s0, -0x2F70
    ctx->r16 = ADD32(ctx->r16, -0X2F70);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    // jal         0x800795F4
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    sub_800795F4(rdram, ctx);
    goto after_3;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_3:
    // addiu       $s3, $s0, 0xB8
    ctx->r19 = ADD32(ctx->r16, 0XB8);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    // jal         0x800796A8
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    sub_800796A8(rdram, ctx);
    goto after_4;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_4:
    // addiu       $s1, $s0, 0x5C
    ctx->r17 = ADD32(ctx->r16, 0X5C);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    // jal         0x800795F4
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    sub_800795F4(rdram, ctx);
    goto after_5;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_5:
    // addiu       $a0, $s0, 0xCC
    ctx->r4 = ADD32(ctx->r16, 0XCC);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    // jal         0x800796A8
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    sub_800796A8(rdram, ctx);
    goto after_6;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_6:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x16($s0)
    MEM_B(0X16, ctx->r16) = ctx->r2;
    // sb          $v0, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r2;
    // sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
    // sb          $v0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r2;
    // sb          $zero, 0x19($s0)
    MEM_B(0X19, ctx->r16) = 0;
    // sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // sb          $zero, 0x19($s1)
    MEM_B(0X19, ctx->r17) = 0;
    // sb          $zero, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = 0;
    // jal         0x8007A290
    // sb          $zero, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = 0;
    PutDispEnv(rdram, ctx);
    goto after_7;
    // sb          $zero, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = 0;
    after_7:
    // jal         0x8007A0C4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    PutDrawEnv(rdram, ctx);
    goto after_8;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // addu        $t2, $t1, $zero
    ctx->r10 = ADD32(ctx->r9, 0);
    // addu        $t3, $t1, $zero
    ctx->r11 = ADD32(ctx->r9, 0);
    // sll         $t4, $t1, 4
    ctx->r12 = S32(ctx->r9) << 4;
    // sll         $t5, $t2, 4
    ctx->r13 = S32(ctx->r10) << 4;
    // sll         $t6, $t3, 4
    ctx->r14 = S32(ctx->r11) << 4;
    // ctc2        $t4, $13
    gte_ctc2(ctx, 12, 13);
    // ctc2        $t5, $14
    gte_ctc2(ctx, 13, 14);
    // ctc2        $t6, $15
    gte_ctc2(ctx, 14, 15);
    // lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $a2, $v0, -0x42AB
    ctx->r6 = ADD32(ctx->r2, -0X42AB);
    // addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    // addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // sb          $v0, 0x6CC2($a0)
    MEM_B(0X6CC2, ctx->r4) = ctx->r2;
    // lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // addiu       $v0, $v0, -0x3B78
    ctx->r2 = ADD32(ctx->r2, -0X3B78);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // sw          $v0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->r2;
    // addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // lui         $v1, 0x2
    ctx->r3 = S32(0X2 << 16);
    // sw          $v0, 0x2EC($s0)
    MEM_W(0X2EC, ctx->r16) = ctx->r2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x2F0($s0)
    MEM_W(0X2F0, ctx->r16) = ctx->r2;
    // sw          $v0, 0x2F8($s0)
    MEM_W(0X2F8, ctx->r16) = ctx->r2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x2FC($s0)
    MEM_W(0X2FC, ctx->r16) = ctx->r2;
    // sb          $zero, 0x6CCF($a0)
    MEM_B(0X6CCF, ctx->r4) = 0;
    // sb          $zero, 0x6CCD($a0)
    MEM_B(0X6CCD, ctx->r4) = 0;
    // sb          $zero, 0x6CCE($a0)
    MEM_B(0X6CCE, ctx->r4) = 0;
L_8001713C:
    // sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // bne         $a1, $a3, L_8001713C
    if (ctx->r5 != ctx->r7) {
        // addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8001713C;
    }
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // jal         0x80016878
    // lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    sub_80016878(rdram, ctx);
    goto after_9;
    // lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    after_9:
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // addiu       $s0, $s0, -0x2F70
    ctx->r16 = ADD32(ctx->r16, -0X2F70);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x6CD2($s0)
    MEM_B(0X6CD2, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x6CC3($s0)
    MEM_B(0X6CC3, ctx->r16) = ctx->r2;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // sb          $zero, 0x6E15($s0)
    MEM_B(0X6E15, ctx->r16) = 0;
    // sw          $zero, 0x6DF0($s0)
    MEM_W(0X6DF0, ctx->r16) = 0;
    // sw          $zero, 0x6DF4($s0)
    MEM_W(0X6DF4, ctx->r16) = 0;
    // jal         0x800340C4
    // sw          $zero, -0x3B78($v0)
    MEM_W(-0X3B78, ctx->r2) = 0;
    sub_800340C4(rdram, ctx);
    goto after_10;
    // sw          $zero, -0x3B78($v0)
    MEM_W(-0X3B78, ctx->r2) = 0;
    after_10:
    // jal         0x80034F48
    // nop

    sub_80034F48(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // sb          $v0, 0x6DFC($s0)
    MEM_B(0X6DFC, ctx->r16) = ctx->r2;
    // sb          $zero, 0x6DFD($s0)
    MEM_B(0X6DFD, ctx->r16) = 0;
    // sb          $zero, 0x6DFE($s0)
    MEM_B(0X6DFE, ctx->r16) = 0;
    // sb          $zero, 0x6E16($s0)
    MEM_B(0X6E16, ctx->r16) = 0;
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
