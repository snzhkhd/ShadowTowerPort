#include "recomp.h"
#include "disable_warnings.h"

void sub_8007EE70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addiu       $v0, $v0, -0x4C88
    ctx->r2 = ADD32(ctx->r2, -0X4C88);
    // andi        $a0, $a0, 0xF0
    ctx->r4 = ctx->r4 & 0XF0;
    // beq         $a0, $zero, L_8007EE88
    if (ctx->r4 == 0) {
        // nop
    
        goto L_8007EE88;
    }
    // nop

    // addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, 0XF0);
L_8007EE88:
    // jr          $ra
    // nop

    return;
    // nop

;}
