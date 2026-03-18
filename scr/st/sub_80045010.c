#include "recomp.h"
#include "disable_warnings.h"

void sub_80045010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lw          $v0, 0x248($v1)
    ctx->r2 = MEM_W(0X248, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, 0x248($v1)
    MEM_W(0X248, ctx->r3) = ctx->r2;
    // lw          $v0, 0x250($v1)
    ctx->r2 = MEM_W(0X250, ctx->r3);
    // lw          $a0, 0x24C($v1)
    ctx->r4 = MEM_W(0X24C, ctx->r3);
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // addu        $a0, $a0, $a1
    ctx->r4 = ADD32(ctx->r4, ctx->r5);
    // sw          $v0, 0x250($v1)
    MEM_W(0X250, ctx->r3) = ctx->r2;
    // jr          $ra
    // sw          $a0, 0x24C($v1)
    MEM_W(0X24C, ctx->r3) = ctx->r4;
    return;
    // sw          $a0, 0x24C($v1)
    MEM_W(0X24C, ctx->r3) = ctx->r4;
;}
