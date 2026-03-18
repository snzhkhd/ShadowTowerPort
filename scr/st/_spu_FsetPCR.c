#include "recomp.h"
#include "disable_warnings.h"

void _spu_FsetPCR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0xD50($a1)
    ctx->r5 = MEM_W(0XD50, ctx->r5);
    // lui         $v1, 0xFFF8
    ctx->r3 = S32(0XFFF8 << 16);
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $a0, $zero, L_8006C70C
    if (ctx->r4 == 0) {
        // sw          $v0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_8006C70C;
    }
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD50($v0)
    ctx->r2 = MEM_W(0XD50, ctx->r2);
    // nop

    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // j           L_8006C720
    // lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
    goto L_8006C720;
    // lui         $a0, 0x3
    ctx->r4 = S32(0X3 << 16);
L_8006C70C:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD50($v0)
    ctx->r2 = MEM_W(0XD50, ctx->r2);
    // nop

    // lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(0X0, ctx->r2);
    // lui         $a0, 0x5
    ctx->r4 = S32(0X5 << 16);
L_8006C720:
    // or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // jr          $ra
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    return;
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
;}
