#include "recomp.h"
#include "disable_warnings.h"

void sub_8001535C(uint8_t* rdram, recomp_context* ctx) 
{
    MEM_W(0, 0x8008820C) = 1;

//    uint64_t hi = 0, lo = 0, result = 0;
//    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
//    int c1cs = 0; 
//    // addiu       $sp, $sp, -0x18
//    ctx->r29 = ADD32(ctx->r29, -0X18);
//    // lui         $v0, 0x8009
//    ctx->r2 = S32(0X8009 << 16);
//    // addiu       $v1, $v0, -0x7E00
//    ctx->r3 = ADD32(ctx->r2, -0X7E00);
//    // sw          $ra, 0x14($sp)
//    MEM_W(0X14, ctx->r29) = ctx->r31;
//    // sw          $s0, 0x10($sp)
//    MEM_W(0X10, ctx->r29) = ctx->r16;
//    // lw          $v0, 0xC($v1)
//    ctx->r2 = MEM_W(0XC, ctx->r3);
//    // nop
//
//    // bne         $v0, $zero, L_8001539C
//    if (ctx->r2 != 0) {
//        // lui         $v0, 0x8009
//        ctx->r2 = S32(0X8009 << 16);
//        goto L_8001539C;
//    }
//    // lui         $v0, 0x8009
//    ctx->r2 = S32(0X8009 << 16);
//    // addu        $s0, $v1, $zero
//    ctx->r16 = ADD32(ctx->r3, 0);
//L_80015384:
//    // jal         0x80077104
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//
//    printf("sub_8001535C loop\n");
//    VSync(rdram, ctx);
//    goto after_0;
//    // addu        $a0, $zero, $zero
//    ctx->r4 = ADD32(0, 0);
//    after_0:
//    // lw          $v0, 0xC($s0)
//    ctx->r2 = MEM_W(0XC, ctx->r16);
//    // nop
//
//    // beq         $v0, $zero, L_80015384
//    if (ctx->r2 == 0) {
//        // lui         $v0, 0x8009
//        ctx->r2 = S32(0X8009 << 16);
//        goto L_80015384;
//    }
//    // lui         $v0, 0x8009
//    ctx->r2 = S32(0X8009 << 16);
//L_8001539C:
//    // sw          $zero, -0x7DF4($v0)
//    MEM_W(-0X7DF4, ctx->r2) = 0;
//    // lw          $ra, 0x14($sp)
//    ctx->r31 = MEM_W(0X14, ctx->r29);
//    // lw          $s0, 0x10($sp)
//    ctx->r16 = MEM_W(0X10, ctx->r29);
//    // addiu       $sp, $sp, 0x18
//    ctx->r29 = ADD32(ctx->r29, 0X18);
//    // jr          $ra
//    // nop

    return;
    // nop

;}
