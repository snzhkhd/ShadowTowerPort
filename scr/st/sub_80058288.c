#include "recomp.h"
#include "disable_warnings.h"

void sub_80058288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // beq         $a3, $zero, L_800582BC
    if (ctx->r7 == 0) {
        // addu        $t0, $a1, $zero
        ctx->r8 = ADD32(ctx->r5, 0);
        goto L_800582BC;
    }
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, -0x2E40
    ctx->r2 = ADD32(ctx->r2, -0X2E40);
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(0X4, ctx->r7);
    // lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(0X8, ctx->r7);
    // lw          $a2, 0xC($a3)
    ctx->r6 = MEM_W(0XC, ctx->r7);
    // sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
    // sw          $a1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r5;
    // sw          $a2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r6;
L_800582BC:
    // beq         $t0, $zero, L_800582E8
    if (ctx->r8 == 0) {
        // lui         $v0, 0x801E
        ctx->r2 = S32(0X801E << 16);
        goto L_800582E8;
    }
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, -0x2E40
    ctx->r2 = ADD32(ctx->r2, -0X2E40);
    // lwl         $v1, 0x3($t0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r8);
    // lwr         $v1, 0x0($t0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r8);
    // lwl         $a0, 0x7($t0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r8);
    // lwr         $a0, 0x4($t0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r8);
    // swl         $v1, 0x23($v0)
    do_swl(rdram, 0X23, ctx->r2, ctx->r3);
    // swr         $v1, 0x20($v0)
    do_swr(rdram, 0X20, ctx->r2, ctx->r3);
    // swl         $a0, 0x27($v0)
    do_swl(rdram, 0X27, ctx->r2, ctx->r4);
    // swr         $a0, 0x24($v0)
    do_swr(rdram, 0X24, ctx->r2, ctx->r4);
L_800582E8:
    // jr          $ra
    // nop

    return;
    // nop

;}
