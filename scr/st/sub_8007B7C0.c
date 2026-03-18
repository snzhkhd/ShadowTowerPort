#include "recomp.h"
#include "disable_warnings.h"

void sub_8007B7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DC8($v0)
    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
    // nop

    // sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // srl         $v0, $a0, 24
    ctx->r2 = S32(U32(ctx->r4) >> 24);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // jr          $ra
    // sb          $a0, -0x6650($at)
    MEM_B(-0X6650, ctx->r1) = ctx->r4;
    return;
    // sb          $a0, -0x6650($at)
    MEM_B(-0X6650, ctx->r1) = ctx->r4;
;}
