#include "recomp.h"
#include "disable_warnings.h"

void sub_80016454(uint8_t* rdram, recomp_context* ctx) {
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
    // lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // lw          $a0, -0x7E00($s0)
    ctx->r4 = MEM_W(-0X7E00, ctx->r16);
    // jal         0x80077E14
    // addiu       $s0, $s0, -0x7E00
    ctx->r16 = ADD32(ctx->r16, -0X7E00);
    CloseEvent(rdram, ctx);
    goto after_1;
    // addiu       $s0, $s0, -0x7E00
    ctx->r16 = ADD32(ctx->r16, -0X7E00);
    after_1:
    // jal         0x80077EA4
    // nop

    ExitCriticalSection(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $a0, 0x9F4($s0)
    ctx->r4 = MEM_W(0X9F4, ctx->r16);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lw          $a0, 0x9E8($s0)
    ctx->r4 = MEM_W(0X9E8, ctx->r16);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lw          $a0, 0x9DC($s0)
    ctx->r4 = MEM_W(0X9DC, ctx->r16);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_5;
    // nop

    after_5:
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
