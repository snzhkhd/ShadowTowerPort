#include "recomp.h"
#include "disable_warnings.h"

void sub_8005755C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a0, $v0, -0x2E80
    ctx->r4 = ADD32(ctx->r2, -0X2E80);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lbu         $v1, 0x15($a0)
    ctx->r3 = MEM_BU(0X15, ctx->r4);
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // bne         $v1, $v0, L_8005758C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005758C;
    }
    // nop

    // jal         0x800574C0
    // nop

    sub_800574C0(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_80057590
    // nop

    goto L_80057590;
    // nop

L_8005758C:
    // sb          $zero, 0x18($a0)
    MEM_B(0X18, ctx->r4) = 0;
L_80057590:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
