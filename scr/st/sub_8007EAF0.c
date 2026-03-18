#include "recomp.h"
#include "disable_warnings.h"

void sub_8007EAF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v0, 0x36($a0)
    ctx->r2 = MEM_BU(0X36, ctx->r4);
    // sb          $zero, 0x36($a0)
    MEM_B(0X36, ctx->r4) = 0;
    // jr          $ra
    // sb          $v0, 0x37($a0)
    MEM_B(0X37, ctx->r4) = ctx->r2;
    return;
    // sb          $v0, 0x37($a0)
    MEM_B(0X37, ctx->r4) = ctx->r2;
;}
