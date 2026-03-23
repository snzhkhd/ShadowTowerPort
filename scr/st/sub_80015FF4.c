#include "recomp.h"
#include "disable_warnings.h"



void sub_80015FF4(uint8_t* rdram, recomp_context* ctx) 
{

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // bne         $a2, $zero, L_8001600C
    if (ctx->r6 != 0) {
        // addu        $a0, $a1, $zero
        ctx->r4 = ADD32(ctx->r5, 0);
        goto L_8001600C;
    }
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(0X4, ctx->r4);
L_8001600C:
    // nop

    // addiu       $a2, $a2, 0x7FF
    ctx->r6 = ADD32(ctx->r6, 0X7FF);
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // jal         0x80015F0C
    // srl         $a2, $a2, 11
    ctx->r6 = S32(U32(ctx->r6) >> 11);

    KF_CDReadSectorsInternal(rdram, ctx);

    goto after_0;
    // srl         $a2, $a2, 11
    ctx->r6 = S32(U32(ctx->r6) >> 11);
    after_0:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
