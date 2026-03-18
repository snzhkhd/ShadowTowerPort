#include "recomp.h"
#include "disable_warnings.h"

void CdIntstr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // sltiu       $v0, $a0, 0x7
    ctx->r2 = ctx->r4 < 0X7 ? 1 : 0;
    // beq         $v0, $zero, L_80068C68
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4) << 2;
        goto L_80068C68;
    }
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0xA80($at)
    ctx->r2 = MEM_W(0XA80, ctx->r1);
    // j           L_80068C70
    // nop

    goto L_80068C70;
    // nop

L_80068C68:
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x39B0
    ctx->r2 = ADD32(ctx->r2, 0X39B0);
L_80068C70:
    // jr          $ra
    // nop

    return;
    // nop

;}
