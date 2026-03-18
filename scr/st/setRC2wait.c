#include "recomp.h"
#include "disable_warnings.h"

void setRC2wait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
    // ori         $v0, $v0, 0x1120
    ctx->r2 = ctx->r2 | 0X1120;
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $a0, -0x4AA4($at)
    MEM_W(-0X4AA4, ctx->r1) = ctx->r4;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // jr          $ra
    // sw          $v0, -0x4AA8($at)
    MEM_W(-0X4AA8, ctx->r1) = ctx->r2;
    return;
    // sw          $v0, -0x4AA8($at)
    MEM_W(-0X4AA8, ctx->r1) = ctx->r2;
;}
