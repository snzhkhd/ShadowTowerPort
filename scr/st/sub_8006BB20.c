#include "recomp.h"
#include "disable_warnings.h"

void sub_8006BB20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0xD34
    ctx->r3 = ADD32(ctx->r3, 0XD34);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // addiu       $v1, $v1, -0x30
    ctx->r3 = ADD32(ctx->r3, -0X30);
    // jr          $ra
    // sw          $a0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r4;
    return;
    // sw          $a0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r4;
;}
