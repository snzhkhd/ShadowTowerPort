#include "recomp.h"
#include "disable_warnings.h"

void sub_8007B7E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v0, -0x6650($v0)
    ctx->r2 = MEM_BU(-0X6650, ctx->r2);
    // jr          $ra
    // nop

    return;
    // nop

;}
