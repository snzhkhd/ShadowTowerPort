#include "recomp.h"
#include "disable_warnings.h"

void sub_8006D094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addiu       $v0, $zero, 0x3E7
    ctx->r2 = ADD32(0, 0X3E7);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8006D0B0:
    // bgez        $v0, L_8006D0B0
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_8006D0B0;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $s2, 0xF200
    ctx->r18 = S32(0XF200 << 16);
    // ori         $s2, $s2, 0x2
    ctx->r18 = ctx->r18 | 0X2;
    // addiu       $s1, $zero, 0x44E8
    ctx->r17 = ADD32(0, 0X44E8);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // addiu       $a1, $a1, 0xEB0
    ctx->r5 = ADD32(ctx->r5, 0XEB0);
    // lw          $v1, -0x10($a1)
    ctx->r3 = MEM_W(-0X10, ctx->r5);
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // beq         $v1, $v0, L_8006D204
    if (ctx->r3 == ctx->r2) {
        // sw          $zero, -0x4($a1)
        MEM_W(-0X4, ctx->r5) = 0;
        goto L_8006D204;
    }
    // sw          $zero, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = 0;
    // slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // beq         $v0, $zero, L_8006D108
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8006D108;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $zero, L_8006D120
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x7F
        ctx->r2 = ADD32(0, 0X7F);
        goto L_8006D120;
    }
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // j           L_8006D154
    // nop

    goto L_8006D154;
    // nop

L_8006D108:
    // beq         $v1, $v0, L_8006D14C
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_8006D14C;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // beq         $v1, $v0, L_8006D128
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8006D128;
    }
    // nop

    // j           L_8006D154
    // nop

    goto L_8006D154;
    // nop

L_8006D120:
    // j           L_8006D2AC
    // sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    goto L_8006D2AC;
    // sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
L_8006D128:
    // bne         $a0, $zero, L_8006D13C
    if (ctx->r4 != 0) {
        // sb          $zero, 0x2($a1)
        MEM_B(0X2, ctx->r5) = 0;
        goto L_8006D13C;
    }
    // sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // j           L_8006D204
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    goto L_8006D204;
    // sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_8006D13C:
    // lui         $s2, 0xF200
    ctx->r18 = S32(0XF200 << 16);
    // ori         $s2, $s2, 0x3
    ctx->r18 = ctx->r18 | 0X3;
    // j           L_8006D204
    // addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    goto L_8006D204;
    // addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8006D14C:
    // j           L_8006D204
    // ori         $s1, $zero, 0x89D0
    ctx->r17 = 0 | 0X89D0;
    goto L_8006D204;
    // ori         $s1, $zero, 0x89D0
    ctx->r17 = 0 | 0X89D0;
L_8006D154:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0xEA4
    ctx->r3 = ADD32(ctx->r3, 0XEA4);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // bne         $v0, $zero, L_8006D2AC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8006D2AC;
    }
    // nop

    // lw          $a0, -0x4($v1)
    ctx->r4 = MEM_W(-0X4, ctx->r3);
    // nop

    // slti        $v0, $a0, 0x46
    ctx->r2 = SIGNED(ctx->r4) < 0X46 ? 1 : 0;
    // beq         $v0, $zero, L_8006D1CC
    if (ctx->r2 == 0) {
        // addiu       $a1, $v1, -0x4
        ctx->r5 = ADD32(ctx->r3, -0X4);
        goto L_8006D1CC;
    }
    // addiu       $a1, $v1, -0x4
    ctx->r5 = ADD32(ctx->r3, -0X4);
    // lui         $v1, 0x20
    ctx->r3 = S32(0X20 << 16);
    // ori         $v1, $v1, 0x4CC0
    ctx->r3 = ctx->r3 | 0X4CC0;
    // div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // bne         $a0, $zero, L_8006D198
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8006D198;
    }
    // nop

    // break       7
    do_break(2147930516);
L_8006D198:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_8006D1B0
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8006D1B0;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8006D1B0
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8006D1B0;
    }
    // nop

    // break       6
    do_break(2147930540);
L_8006D1B0:
    // mflo        $v1
    ctx->r3 = lo;
    // lbu         $v0, 0x11($a1)
    ctx->r2 = MEM_BU(0X11, ctx->r5);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x11($a1)
    MEM_B(0X11, ctx->r5) = ctx->r2;
    // j           L_8006D204
    // addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
    goto L_8006D204;
    // addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
L_8006D1CC:
    // lui         $v0, 0x40
    ctx->r2 = S32(0X40 << 16);
    // ori         $v0, $v0, 0x9980
    ctx->r2 = ctx->r2 | 0X9980;
    // div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // bne         $a0, $zero, L_8006D1E4
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8006D1E4;
    }
    // nop

    // break       7
    do_break(2147930592);
L_8006D1E4:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_8006D1FC
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8006D1FC;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8006D1FC
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8006D1FC;
    }
    // nop

    // break       6
    do_break(2147930616);
L_8006D1FC:
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_8006D204:
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // addiu       $s0, $s0, 0xEB0
    ctx->r16 = ADD32(ctx->r16, 0XEB0);
    // lb          $v0, 0x0($s0)
    ctx->r2 = MEM_BS(0X0, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8006D238
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006D238;
    }
    // nop

    // jal         0x80077E94
    // nop

    EnterCriticalSection(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $a0, -0x8($s0)
    ctx->r4 = MEM_W(-0X8, ctx->r16);
    // jal         0x800773A4
    // nop

    VSyncCallback(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_8006D2A4
    // nop

    goto L_8006D2A4;
    // nop

L_8006D238:
    // jal         0x80077E94
    // nop

    EnterCriticalSection(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x8007807C
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    ResetRCnt(rdram, ctx);
    goto after_3;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_3:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    // jal         0x80077F44
    // addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    SetRCnt(rdram, ctx);
    goto after_4;
    // addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    after_4:
    // lb          $a0, 0x2($s0)
    ctx->r4 = MEM_BS(0X2, ctx->r16);
    // nop

    // bne         $a0, $zero, L_8006D288
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8006D288;
    }
    // nop

    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80077344
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    InterruptCallback(rdram, ctx);
    goto after_5;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
    // lb          $a0, 0x2($s0)
    ctx->r4 = MEM_BS(0X2, ctx->r16);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // addiu       $a1, $a1, -0x2CFC
    ctx->r5 = ADD32(ctx->r5, -0X2CFC);
    // j           L_8006D29C
    // sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    goto L_8006D29C;
    // sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
L_8006D288:
    // lb          $v0, 0x1($s0)
    ctx->r2 = MEM_BS(0X1, ctx->r16);
    // lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // bne         $v0, $zero, L_8006D29C
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, -0x2CB0
        ctx->r5 = ADD32(ctx->r5, -0X2CB0);
        goto L_8006D29C;
    }
    // addiu       $a1, $a1, -0x2CB0
    ctx->r5 = ADD32(ctx->r5, -0X2CB0);
    // lw          $a1, -0x8($s0)
    ctx->r5 = MEM_W(-0X8, ctx->r16);
L_8006D29C:
    // jal         0x80077344
    // nop

    InterruptCallback(rdram, ctx);
    goto after_6;
    // nop

    after_6:
L_8006D2A4:
    // jal         0x80077EA4
    // nop

    ExitCriticalSection(rdram, ctx);
    goto after_7;
    // nop

    after_7:
L_8006D2AC:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
