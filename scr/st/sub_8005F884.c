#include "recomp.h"
#include "disable_warnings.h"

void sub_8005F884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $s5, $v0, 0x76F8
    ctx->r21 = ADD32(ctx->r2, 0X76F8);
    // lui         $s6, 0x801D
    ctx->r22 = S32(0X801D << 16);
    // addiu       $s4, $s6, -0x2E80
    ctx->r20 = ADD32(ctx->r22, -0X2E80);
    // lhu         $v0, 0x2DC($s2)
    ctx->r2 = MEM_HU(0X2DC, ctx->r18);
;}
