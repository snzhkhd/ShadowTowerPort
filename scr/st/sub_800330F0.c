#include "recomp.h"
#include "disable_warnings.h"

void sub_800330F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, -0x4930
    ctx->r2 = ADD32(ctx->r2, -0X4930);
    // sb          $zero, 0x9($v0)
    MEM_B(0X9, ctx->r2) = 0;
    // sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // jr          $ra
    // sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    return;
    // sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
;}
