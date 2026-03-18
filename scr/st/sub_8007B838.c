#include "recomp.h"
#include "disable_warnings.h"

void sub_8007B838(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DC8($v0)
    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
    // ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DCC($v0)
    ctx->r2 = MEM_W(0X7DCC, ctx->r2);
    // nop

    // sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DD0($v0)
    ctx->r2 = MEM_W(0X7DD0, ctx->r2);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DD4($v0)
    ctx->r2 = MEM_W(0X7DD4, ctx->r2);
    // ori         $v1, $v1, 0x401
    ctx->r3 = ctx->r3 | 0X401;
    // jr          $ra
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    return;
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
;}
