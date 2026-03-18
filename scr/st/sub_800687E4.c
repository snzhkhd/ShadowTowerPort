#include "recomp.h"
#include "disable_warnings.h"

void sub_800687E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lhu         $t7, 0xA($v1)
    ctx->r15 = MEM_HU(0XA, ctx->r3);
    // lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // or          $t8, $t7, $v0
    ctx->r24 = ctx->r15 | ctx->r2;
    // ori         $t9, $t8, 0x12
    ctx->r25 = ctx->r24 | 0X12;
;}
