#include "recomp.h"
#include "disable_warnings.h"

void sub_800455F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v0, 0x10($a0)
    ctx->r2 = MEM_BU(0X10, ctx->r4);
    // nop

    // bne         $v0, $zero, L_80045610
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80045610;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r2;
    // j           L_80045640
    // nop

    goto L_80045640;
    // nop

L_80045610:
    // lbu         $v1, 0x10($a0)
    ctx->r3 = MEM_BU(0X10, ctx->r4);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_80045640
    if (ctx->r3 != ctx->r2) {
        // lui         $v1, 0x801B
        ctx->r3 = S32(0X801B << 16);
        goto L_80045640;
    }
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // addiu       $v1, $v1, 0x5920
    ctx->r3 = ADD32(ctx->r3, 0X5920);
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // sh          $v0, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r2;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $a0, -0x2EE0($v0)
    ctx->r4 = MEM_BU(-0X2EE0, ctx->r2);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // sw          $zero, -0x2E34($v0)
    MEM_W(-0X2E34, ctx->r2) = 0;
    // sh          $a0, 0x26($v1)
    MEM_H(0X26, ctx->r3) = ctx->r4;
L_80045640:
    // jr          $ra
    // nop

    return;
    // nop

;}
