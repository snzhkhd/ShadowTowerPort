#include "recomp.h"
#include "disable_warnings.h"

void sub_80060BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // jal         0x80077E34
    // nop

    TestEvent(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(0X8, ctx->r16);
    // jal         0x80077E34
    // nop

    TestEvent(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(0XC, ctx->r16);
    // jal         0x80077E34
    // nop

    TestEvent(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(0X10, ctx->r16);
    // jal         0x80077E34
    // nop

    TestEvent(rdram, ctx);
    goto after_3;
    // nop

    after_3:
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
