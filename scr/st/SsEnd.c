#include "recomp.h"
#include "disable_warnings.h"

void SsEnd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // addiu       $s0, $s0, 0xEA4
    ctx->r16 = ADD32(ctx->r16, 0XEA4);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8006CA10
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x7F
        ctx->r2 = ADD32(0, 0X7F);
        goto L_8006CA10;
    }
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // lb          $v1, 0xE($s0)
    ctx->r3 = MEM_BS(0XE, ctx->r16);
    // nop

    // beq         $v1, $v0, L_8006CA10
    if (ctx->r3 == ctx->r2) {
        // sb          $zero, 0xD($s0)
        MEM_B(0XD, ctx->r16) = 0;
        goto L_8006CA10;
    }
    // sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    // jal         0x80077E94
    // nop

    EnterCriticalSection(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lb          $v0, 0xC($s0)
    ctx->r2 = MEM_BS(0XC, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8006C9D0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006C9D0;
    }
    // nop

    // jal         0x800773A4
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    VSyncCallback(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // j           L_8006C9FC
    // sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    goto L_8006C9FC;
    // sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
L_8006C9D0:
    // lb          $v0, 0xE($s0)
    ctx->r2 = MEM_BS(0XE, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8006C9F4
    if (ctx->r2 != 0) {
        // addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
        goto L_8006C9F4;
    }
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(0X8, ctx->r16);
    // jal         0x80077344
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    InterruptCallback(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // j           L_8006C9FC
    // sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    goto L_8006C9FC;
    // sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
L_8006C9F4:
    // jal         0x80077344
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    InterruptCallback(rdram, ctx);
    goto after_3;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_3:
L_8006C9FC:
    // jal         0x80077EA4
    // nop

    ExitCriticalSection(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sb          $v0, 0xEB2($at)
    MEM_B(0XEB2, ctx->r1) = ctx->r2;
L_8006CA10:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
