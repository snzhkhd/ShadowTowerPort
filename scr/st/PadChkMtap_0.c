#include "recomp.h"
#include "disable_warnings.h"

void PadChkMtap_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(0X7E64, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8007C8E0
    if (ctx->r2 != 0) {
        // sra         $v1, $a0, 4
        ctx->r3 = S32(ctx->r4) >> 4;
        goto L_8007C8E0;
    }
    // sra         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4) >> 4;
    // j           L_8007C908
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8007C908;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007C8E0:
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E4C($v1)
    ctx->r3 = MEM_W(0X7E4C, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0xE8($v0)
    ctx->r2 = MEM_BU(0XE8, ctx->r2);
    // nop

    // xori        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 ^ 0X8;
    // sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8007C908:
    // jr          $ra
    // nop

    return;
    // nop

;}
