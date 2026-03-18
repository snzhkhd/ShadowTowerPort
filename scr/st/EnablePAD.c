#include "recomp.h"
#include "disable_warnings.h"

void EnablePAD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $t1, 0x801F
    ctx->r9 = S32(0X801F << 16);
    // lw          $t1, -0x66E0($t1)
    ctx->r9 = MEM_W(-0X66E0, ctx->r9);
    // nop

    // jr          $t1
    // nop

    LOOKUP_FUNC(ctx->r9)(rdram, ctx);
    return;
    // nop

;}
