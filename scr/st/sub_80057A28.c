#include "recomp.h"
#include "disable_warnings.h"

void sub_80057A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x2E80
    ctx->r2 = ADD32(ctx->r2, -0X2E80);
    // sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    // jr          $ra
    // sb          $zero, 0xE($v0)
    MEM_B(0XE, ctx->r2) = 0;
    return;
    // sb          $zero, 0xE($v0)
    MEM_B(0XE, ctx->r2) = 0;
;}
