#include "recomp.h"
#include "disable_warnings.h"

void sub_80067580(uint8_t* rdram, recomp_context* ctx) {
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
L_80067590:
    // jal         0x8006616C
    // nop

    sub_8006616C(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bne         $v0, $zero, L_80067590
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80067590;
    }
    // nop

    // jal         0x80058C4C
    // nop

    sub_80058C4C(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(0X4, ctx->r16);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(0X8, ctx->r16);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(0X14, ctx->r16);
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x80058D30
    // nop

    sub_80058D30(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_6;
    // nop

    after_6:
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
