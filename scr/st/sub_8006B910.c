#include "recomp.h"
#include "disable_warnings.h"

void sub_8006B910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // beq         $v0, $zero, L_8006B928
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
        goto L_8006B928;
    }
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // lw          $a0, 0x2C($s1)
    ctx->r4 = MEM_W(0X2C, ctx->r17);
    // jal         0x800690FC
    // nop

    CdDataCallback(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
L_8006B928:
    // jal         0x80068E1C
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    CdControlF(rdram, ctx);
    goto after_1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
