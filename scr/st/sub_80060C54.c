#include "recomp.h"
#include "disable_warnings.h"

void sub_80060C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // jal         0x80077E94
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    EnterCriticalSection(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // lui         $a0, 0xF400
    ctx->r4 = S32(0XF400 << 16);
    // ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    // addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // jal         0x80077E04
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    OpenEvent(rdram, ctx);
    goto after_1;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
    // lui         $a0, 0xF400
    ctx->r4 = S32(0XF400 << 16);
    // ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    // ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sw          $v0, 0x4($at)
    MEM_W(0X4, ctx->r1) = ctx->r2;
    // jal         0x80077E04
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    OpenEvent(rdram, ctx);
    goto after_2;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // lui         $a0, 0xF400
    ctx->r4 = S32(0XF400 << 16);
    // ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    // addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sw          $v0, 0x8($at)
    MEM_W(0X8, ctx->r1) = ctx->r2;
    // jal         0x80077E04
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    OpenEvent(rdram, ctx);
    goto after_3;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // lui         $a0, 0xF400
    ctx->r4 = S32(0XF400 << 16);
    // ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    // addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sw          $v0, 0xC($at)
    MEM_W(0XC, ctx->r1) = ctx->r2;
    // jal         0x80077E04
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    OpenEvent(rdram, ctx);
    goto after_4;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_4:
    // lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // ori         $a0, $a0, 0x11
    ctx->r4 = ctx->r4 | 0X11;
    // addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sw          $v0, 0x10($at)
    MEM_W(0X10, ctx->r1) = ctx->r2;
    // jal         0x80077E04
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    OpenEvent(rdram, ctx);
    goto after_5;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
    // lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // ori         $a0, $a0, 0x11
    ctx->r4 = ctx->r4 | 0X11;
    // ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sw          $v0, 0x14($at)
    MEM_W(0X14, ctx->r1) = ctx->r2;
    // jal         0x80077E04
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    OpenEvent(rdram, ctx);
    goto after_6;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
    // lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // ori         $a0, $a0, 0x11
    ctx->r4 = ctx->r4 | 0X11;
    // addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sw          $v0, 0x18($at)
    MEM_W(0X18, ctx->r1) = ctx->r2;
    // jal         0x80077E04
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    OpenEvent(rdram, ctx);
    goto after_7;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_7:
    // lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // ori         $a0, $a0, 0x11
    ctx->r4 = ctx->r4 | 0X11;
    // addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sw          $v0, 0x1C($at)
    MEM_W(0X1C, ctx->r1) = ctx->r2;
    // jal         0x80077E04
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    OpenEvent(rdram, ctx);
    goto after_8;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_8:
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // lui         $at, 0x1F80
    ctx->r1 = S32(0X1F80 << 16);
    // sw          $v0, 0x20($at)
    MEM_W(0X20, ctx->r1) = ctx->r2;
    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // jal         0x80077E44
    // nop

    EnableEvent(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(0X8, ctx->r16);
    // jal         0x80077E44
    // nop

    EnableEvent(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(0XC, ctx->r16);
    // jal         0x80077E44
    // nop

    EnableEvent(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(0X10, ctx->r16);
    // jal         0x80077E44
    // nop

    EnableEvent(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(0X14, ctx->r16);
    // jal         0x80077E44
    // nop

    EnableEvent(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(0X18, ctx->r16);
    // jal         0x80077E44
    // nop

    EnableEvent(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(0X1C, ctx->r16);
    // jal         0x80077E44
    // nop

    EnableEvent(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(0X20, ctx->r16);
    // jal         0x80077E44
    // nop

    EnableEvent(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // jal         0x80077EA4
    // nop

    ExitCriticalSection(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
