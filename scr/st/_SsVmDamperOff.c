#include "recomp.h"
#include "disable_warnings.h"

void _SsVmDamperOff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // jr          $ra
    // sh          $zero, -0x6968($at)
    MEM_H(-0X6968, ctx->r1) = 0;
    return;
    // sh          $zero, -0x6968($at)
    MEM_H(-0X6968, ctx->r1) = 0;
;}
