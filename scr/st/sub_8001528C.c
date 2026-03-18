#include "recomp.h"
#include "disable_warnings.h"

void sub_8001528C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x80078834
    // nop

    malloc3(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $a0, 0x1F
    ctx->r4 = S32(0X1F << 16);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // subu        $v1, $a1, $v1
    ctx->r3 = SUB32(ctx->r5, ctx->r3);
    // sltu        $a0, $a0, $v1
    ctx->r4 = ctx->r4 < ctx->r3 ? 1 : 0;
    // bne         $a0, $zero, L_800152C0
    if (ctx->r4 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_800152C0;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_800152C0:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
