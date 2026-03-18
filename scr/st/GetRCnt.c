#include "recomp.h"
#include "disable_warnings.h"

void GetRCnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // beq         $v0, $zero, L_8007800C
    if (ctx->r2 == 0) {
        // sll         $v1, $v1, 4
        ctx->r3 = S32(ctx->r3) << 4;
        goto L_8007800C;
    }
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7C24($v0)
    ctx->r2 = MEM_W(0X7C24, ctx->r2);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // j           L_80078010
    // nop

    goto L_80078010;
    // nop

L_8007800C:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80078010:
    // jr          $ra
    // nop

    return;
    // nop

;}
