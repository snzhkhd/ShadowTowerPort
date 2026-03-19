#include "recomp.h"
#include "disable_warnings.h"

void AsyncStructForcedLoadSync(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $v0, $v0, -0x7E00
    ctx->r2 = ADD32(ctx->r2, -0X7E00);
    // j           L_80015AF8
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    goto L_80015AF8;
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
L_80015AE8:
    // jal         0x8001531C
    // nop

    AsyncDataLoad(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $v0, $v0, -0x7E00
    ctx->r2 = ADD32(ctx->r2, -0X7E00);
L_80015AF8:
    // lw          $v1, 0x9D8($v0)
    ctx->r3 = MEM_W(0X9D8, ctx->r2);
    // lw          $v0, 0x9D4($v0)
    ctx->r2 = MEM_W(0X9D4, ctx->r2);
    // nop

    // bne         $v1, $v0, L_80015AE8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80015AE8;
    }
    // nop

    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // bne         $v0, $zero, L_80015AE8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80015AE8;
    }
    // nop

    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
