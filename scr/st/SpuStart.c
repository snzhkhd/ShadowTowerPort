#include "recomp.h"
#include "disable_warnings.h"

void SpuStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE10($v0)
    ctx->r2 = MEM_W(0XE10, ctx->r2);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // bne         $v0, $zero, L_8006C92C
    if (ctx->r2 != 0) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_8006C92C;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // jal         0x80077E94
    // sw          $v0, 0xE10($at)
    MEM_W(0XE10, ctx->r1) = ctx->r2;
    EnterCriticalSection(rdram, ctx);
    goto after_0;
    // sw          $v0, 0xE10($at)
    MEM_W(0XE10, ctx->r1) = ctx->r2;
    after_0:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // jal         0x8006C944
    // addiu       $a0, $a0, -0x3F1C
    ctx->r4 = ADD32(ctx->r4, -0X3F1C);
    _SpuDataCallback(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, -0x3F1C
    ctx->r4 = ADD32(ctx->r4, -0X3F1C);
    after_1:
    // lui         $a0, 0xF000
    ctx->r4 = S32(0XF000 << 16);
    // ori         $a0, $a0, 0x9
    ctx->r4 = ctx->r4 | 0X9;
    // addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // jal         0x80077E04
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    OpenEvent(rdram, ctx);
    goto after_2;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // jal         0x80077E44
    // sw          $a0, 0xDA8($at)
    MEM_W(0XDA8, ctx->r1) = ctx->r4;
    EnableEvent(rdram, ctx);
    goto after_3;
    // sw          $a0, 0xDA8($at)
    MEM_W(0XDA8, ctx->r1) = ctx->r4;
    after_3:
    // jal         0x80077EA4
    // nop

    ExitCriticalSection(rdram, ctx);
    goto after_4;
    // nop

    after_4:
L_8006C92C:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
