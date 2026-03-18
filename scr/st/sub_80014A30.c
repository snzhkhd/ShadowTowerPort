#include "recomp.h"
#include "disable_warnings.h"

void sub_80014A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // jal         0x80016374
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    sub_80016374(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    after_0:
    // jal         0x80016FB8
    // nop

    sub_80016FB8(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x800210F4
    // nop

    sub_800210F4(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x80021158
    // nop

    sub_80021158(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x80057DA0
    // nop

    sub_80057DA0(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x8004EDA8
    // nop

    sub_8004EDA8(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // jal         0x8004AFDC
    // nop

    sub_8004AFDC(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // jal         0x80052CA4
    // nop

    sub_80052CA4(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // jal         0x8003BC10
    // nop

    sub_8003BC10(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // jal         0x80044674
    // nop

    sub_80044674(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // jal         0x800559BC
    // nop

    sub_800559BC(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // jal         0x80032058
    // nop

    sub_80032058(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // jal         0x80016508
    // nop

    sub_80016508(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // jal         0x8003216C
    // nop

    sub_8003216C(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // jal         0x8006D044
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    SsSetMVol(rdram, ctx);
    goto after_14;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_14:
    // lui         $v1, 0x8001
    ctx->r3 = S32(0X8001 << 16);
    // lbu         $v1, 0x3F1($v1)
    ctx->r3 = MEM_BU(0X3F1, ctx->r3);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_80014B74
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
        goto L_80014B74;
    }
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7EC4
    ctx->r6 = ADD32(ctx->r2, 0X7EC4);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r3);
    // swr         $v1, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r3);
    // swl         $a0, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r4);
    // swr         $a0, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r4);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x80079BE4
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    ClearImage(rdram, ctx);
    goto after_15;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_15:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80058DC4
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    sub_80058DC4(rdram, ctx);
    goto after_16;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_16:
    // jal         0x80057A28
    // addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    sub_80057A28(rdram, ctx);
    goto after_17;
    // addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_17:
    // jal         0x80062C28
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80062C28(rdram, ctx);
    goto after_18;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_18:
    // bne         $v0, $s0, L_80014B58
    if (ctx->r2 != ctx->r16) {
        // nop
    
        goto L_80014B58;
    }
    // nop

    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_19;
    // nop

    after_19:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // jal         0x80058ED4
    // sb          $s0, -0x2E70($v0)
    MEM_B(-0X2E70, ctx->r2) = ctx->r16;
    sub_80058ED4(rdram, ctx);
    goto after_20;
    // sb          $s0, -0x2E70($v0)
    MEM_B(-0X2E70, ctx->r2) = ctx->r16;
    after_20:
    // jal         0x80021158
    // nop

    sub_80021158(rdram, ctx);
    goto after_21;
    // nop

    after_21:
    // jal         0x8003C0E0
    // nop

    sub_8003C0E0(rdram, ctx);
    goto after_22;
    // nop

    after_22:
    // j           L_80014B7C
    // nop

    goto L_80014B7C;
    // nop

L_80014B58:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_23;
    // nop

    after_23:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // jal         0x80058ED4
    // sb          $s0, -0x2E70($v0)
    MEM_B(-0X2E70, ctx->r2) = ctx->r16;
    sub_80058ED4(rdram, ctx);
    goto after_24;
    // sb          $s0, -0x2E70($v0)
    MEM_B(-0X2E70, ctx->r2) = ctx->r16;
    after_24:
    // jal         0x80021158
    // nop

    sub_80021158(rdram, ctx);
    goto after_25;
    // nop

    after_25:
L_80014B74:
    // jal         0x80014544
    // nop

    sub_80014544(rdram, ctx);
    goto after_26;
    // nop

    after_26:
L_80014B7C:
    // jal         0x8003306C
    // nop

    sub_8003306C(rdram, ctx);
    goto after_27;
    // nop

    after_27:
    // jal         0x80044EE8
    // nop

    sub_80044EE8(rdram, ctx);
    goto after_28;
    // nop

    after_28:
    // jal         0x8003EAF8
    // nop

    sub_8003EAF8(rdram, ctx);
    goto after_29;
    // nop

    after_29:
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // addiu       $a0, $a0, -0x3778
    ctx->r4 = ADD32(ctx->r4, -0X3778);
    // lui         $a1, 0x5
    ctx->r5 = S32(0X5 << 16);
    // jal         0x80015144
    // ori         $a1, $a1, 0x6400
    ctx->r5 = ctx->r5 | 0X6400;
    sub_80015144(rdram, ctx);
    goto after_30;
    // ori         $a1, $a1, 0x6400
    ctx->r5 = ctx->r5 | 0X6400;
    after_30:
    // jal         0x800214A4
    // nop

    sub_800214A4(rdram, ctx);
    goto after_31;
    // nop

    after_31:
    // jal         0x80057A28
    // nop

    sub_80057A28(rdram, ctx);
    goto after_32;
    // nop

    after_32:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_33;
    // nop

    after_33:
    // sw          $zero, 0x2E4($gp)
    MEM_W(0X2E4, ctx->r28) = 0;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s2, $v0, -0x70D8
    ctx->r18 = ADD32(ctx->r2, -0X70D8);
    // addiu       $s1, $sp, 0x18
    ctx->r17 = ADD32(ctx->r29, 0X18);
    // addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
L_80014BD4:
    // jal         0x800164B4
    // nop

    sub_800164B4(rdram, ctx);
    goto after_34;
    // nop

    after_34:
    // jal         0x80016508
    // nop

    sub_80016508(rdram, ctx);
    goto after_35;
    // nop

    after_35:
    // jal         0x80042D74
    // nop

    sub_80042D74(rdram, ctx);
    goto after_36;
    // nop

    after_36:
    // jal         0x80050768
    // nop

    sub_80050768(rdram, ctx);
    goto after_37;
    // nop

    after_37:
    // jal         0x8004E324
    // nop

    sub_8004E324(rdram, ctx);
    goto after_38;
    // nop

    after_38:
    // jal         0x80053AA4
    // nop

    sub_80053AA4(rdram, ctx);
    goto after_39;
    // nop

    after_39:
    // jal         0x8003BC40
    // nop

    sub_8003BC40(rdram, ctx);
    goto after_40;
    // nop

    after_40:
    // jal         0x8005735C
    // sb          $zero, 0x21C($s2)
    MEM_B(0X21C, ctx->r18) = 0;
    sub_8005735C(rdram, ctx);
    goto after_41;
    // sb          $zero, 0x21C($s2)
    MEM_B(0X21C, ctx->r18) = 0;
    after_41:
    // jal         0x800456F8
    // nop

    sub_800456F8(rdram, ctx);
    goto after_42;
    // nop

    after_42:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x8003E734
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_8003E734(rdram, ctx);
    goto after_43;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_43:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80058288
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_80058288(rdram, ctx);
    goto after_44;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_44:
    // jal         0x80045FFC
    // nop

    sub_80045FFC(rdram, ctx);
    goto after_45;
    // nop

    after_45:
    // jal         0x80058620
    // nop

    sub_80058620(rdram, ctx);
    goto after_46;
    // nop

    after_46:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80026AFC
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_80026AFC(rdram, ctx);
    goto after_47;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_47:
    // lw          $v0, 0x2E4($gp)
    ctx->r2 = MEM_W(0X2E4, ctx->r28);
    // nop

    // beq         $v0, $zero, L_80014BD4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80014BD4;
    }
    // nop

    // jal         0x80077104
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    VSync(rdram, ctx);
    goto after_48;
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_48:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    // jal         0x800500AC
    // addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    sub_800500AC(rdram, ctx);
    goto after_49;
    // addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_49:
    // jal         0x80077104
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    VSync(rdram, ctx);
    goto after_50;
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_50:
    // lw          $v1, 0x2E4($gp)
    ctx->r3 = MEM_W(0X2E4, ctx->r28);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $v1, $v0, L_80014CA4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_80014CA4;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $v0, L_80014CB4
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80014CB4;
    }
    // nop

    // j           L_80014BD4
    // nop

    goto L_80014BD4;
    // nop

L_80014CA4:
    // jal         0x80014410
    // nop

    sub_80014410(rdram, ctx);
    goto after_51;
    // nop

    after_51:
    // j           L_80014CC8
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_80014CC8;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80014CB4:
    // jal         0x800633D4
    // nop

    sub_800633D4(rdram, ctx);
    goto after_52;
    // nop

    after_52:
    // jal         0x80014410
    // nop

    sub_80014410(rdram, ctx);
    goto after_53;
    // nop

    after_53:
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80014CC8:
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // sb          $v0, 0x3F0($at)
    MEM_B(0X3F0, ctx->r1) = ctx->r2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // sb          $zero, 0x3F1($at)
    MEM_B(0X3F1, ctx->r1) = 0;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // sb          $zero, 0x3F2($at)
    MEM_B(0X3F2, ctx->r1) = 0;
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
