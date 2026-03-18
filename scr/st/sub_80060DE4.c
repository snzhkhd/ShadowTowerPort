#include "recomp.h"
#include "disable_warnings.h"

void sub_80060DE4(uint8_t* rdram, recomp_context* ctx) {
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
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // jal         0x80077E54
    // nop

    DisableEvent(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(0X8, ctx->r16);
    // jal         0x80077E54
    // nop

    DisableEvent(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(0XC, ctx->r16);
    // jal         0x80077E54
    // nop

    DisableEvent(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(0X10, ctx->r16);
    // jal         0x80077E54
    // nop

    DisableEvent(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(0X14, ctx->r16);
    // jal         0x80077E54
    // nop

    DisableEvent(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(0X18, ctx->r16);
    // jal         0x80077E54
    // nop

    DisableEvent(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(0X1C, ctx->r16);
    // jal         0x80077E54
    // nop

    DisableEvent(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(0X20, ctx->r16);
    // jal         0x80077E54
    // nop

    DisableEvent(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // jal         0x80077E14
    // nop

    CloseEvent(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(0X8, ctx->r16);
    // jal         0x80077E14
    // nop

    CloseEvent(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(0XC, ctx->r16);
    // jal         0x80077E14
    // nop

    CloseEvent(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(0X10, ctx->r16);
    // jal         0x80077E14
    // nop

    CloseEvent(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(0X14, ctx->r16);
    // jal         0x80077E14
    // nop

    CloseEvent(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(0X18, ctx->r16);
    // jal         0x80077E14
    // nop

    CloseEvent(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(0X1C, ctx->r16);
    // jal         0x80077E14
    // nop

    CloseEvent(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(0X20, ctx->r16);
    // jal         0x80077E14
    // nop

    CloseEvent(rdram, ctx);
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
