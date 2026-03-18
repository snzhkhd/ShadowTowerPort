#include "recomp.h"
#include "disable_warnings.h"

void sub_8007E234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
    // sb          $v0, 0x36($a0)
    MEM_B(0X36, ctx->r4) = ctx->r2;
    // sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // jr          $ra
    // sb          $zero, 0x35($a0)
    MEM_B(0X35, ctx->r4) = 0;
    return;
    // sb          $zero, 0x35($a0)
    MEM_B(0X35, ctx->r4) = 0;
;}
