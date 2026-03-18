#include "recomp.h"
#include "disable_warnings.h"

void sub_80036150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v1, $v1, -0x2D68
    ctx->r3 = ADD32(ctx->r3, -0X2D68);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lw          $v0, 0x3C84($v1)
    ctx->r2 = MEM_W(0X3C84, ctx->r3);
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(0X0, ctx->r2);
    // sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // lw          $a2, 0x3C80($v1)
    ctx->r6 = MEM_W(0X3C80, ctx->r3);
    // jal         0x80035E98
    // nop

    sub_80035E98(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
