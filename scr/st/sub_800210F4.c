#include "recomp.h"
#include "disable_warnings.h"

void sub_800210F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, 0x1000
    ctx->r6 = ADD32(ctx->r2, 0X1000);
    // lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(0X0, ctx->r6);
    // lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(0X4, ctx->r6);
    // lw          $a1, 0x8($a2)
    ctx->r5 = MEM_W(0X8, ctx->r6);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // lh          $v1, 0xC($a2)
    ctx->r3 = MEM_HS(0XC, ctx->r6);
    // nop

    // sh          $v1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r3;
    // lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // addiu       $a0, $s0, -0x7394
    ctx->r4 = ADD32(ctx->r16, -0X7394);
L_80021134:
    // jal         0x8006AA24
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    CdSearchFile(rdram, ctx);
    goto after_0;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_0:
    // beq         $v0, $zero, L_80021134
    if (ctx->r2 == 0) {
        // addiu       $a0, $s0, -0x7394
        ctx->r4 = ADD32(ctx->r16, -0X7394);
        goto L_80021134;
    }
    // addiu       $a0, $s0, -0x7394
    ctx->r4 = ADD32(ctx->r16, -0X7394);
    // lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(0X54, ctx->r29);
    // lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(0X50, ctx->r29);
    // addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // jr          $ra
    // nop

    return;
    // nop

;}
