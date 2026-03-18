#include "recomp.h"
#include "disable_warnings.h"

void sub_8007D8C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E7C($v1)
    ctx->r3 = MEM_W(0X7E7C, ctx->r3);
    // nop

L_8007D8D4:
    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // beq         $v0, $zero, L_8007D8D4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007D8D4;
    }
    // nop

    // jr          $ra
    // nop

    return;
    // nop

;}
