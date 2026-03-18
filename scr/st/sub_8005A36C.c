#include "recomp.h"
#include "disable_warnings.h"

void sub_8005A36C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $a0, 0x1F80
    ctx->r4 = S32(0X1F80 << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
L_8005A37C:
    // lhu         $v0, 0x1EC($a0)
    ctx->r2 = MEM_HU(0X1EC, ctx->r4);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // sh          $v0, 0x62($v1)
    MEM_H(0X62, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x208($a0)
    ctx->r2 = MEM_HU(0X208, ctx->r4);
    // addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // sh          $v0, 0x7E($v1)
    MEM_H(0X7E, ctx->r3) = ctx->r2;
    // slti        $v0, $a1, 0xE
    ctx->r2 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_8005A37C
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
        goto L_8005A37C;
    }
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // jr          $ra
    // nop

    return;
    // nop

;}
