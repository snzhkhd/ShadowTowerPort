#include "recomp.h"
#include "disable_warnings.h"

void sub_80042CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // jr          $ra
    // sb          $v0, -0x6EC0($v1)
    MEM_B(-0X6EC0, ctx->r3) = ctx->r2;
    return;
    // sb          $v0, -0x6EC0($v1)
    MEM_B(-0X6EC0, ctx->r3) = ctx->r2;
;}
