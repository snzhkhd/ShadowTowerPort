#include "recomp.h"
#include "disable_warnings.h"

void SpuQuit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xE10($v1)
    ctx->r3 = MEM_W(0XE10, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8006CBE8
    if (ctx->r3 != ctx->r2) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_8006CBE8;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // jal         0x80077E94
    // sw          $zero, 0xE10($at)
    MEM_W(0XE10, ctx->r1) = 0;
    EnterCriticalSection(rdram, ctx);
    goto after_0;
    // sw          $zero, 0xE10($at)
    MEM_W(0XE10, ctx->r1) = 0;
    after_0:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0xD78($at)
    MEM_W(0XD78, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // jal         0x8006C944
    // sw          $zero, 0xD7C($at)
    MEM_W(0XD7C, ctx->r1) = 0;
    _SpuDataCallback(rdram, ctx);
    goto after_1;
    // sw          $zero, 0xD7C($at)
    MEM_W(0XD7C, ctx->r1) = 0;
    after_1:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xDA8($a0)
    ctx->r4 = MEM_W(0XDA8, ctx->r4);
    // jal         0x80077E14
    // nop

    CloseEvent(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xDA8($a0)
    ctx->r4 = MEM_W(0XDA8, ctx->r4);
    // jal         0x80077E54
    // nop

    DisableEvent(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x80077EA4
    // nop

    ExitCriticalSection(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_8006CBE8:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
