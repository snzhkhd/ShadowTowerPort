#include "recomp.h"
#include "disable_warnings.h"

void sub_8007ADF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // beq         $a1, $zero, L_8007ADFC
    if (ctx->r5 == 0) {
        // lui         $v1, 0xE100
        ctx->r3 = S32(0XE100 << 16);
        goto L_8007ADFC;
    }
    // lui         $v1, 0xE100
    ctx->r3 = S32(0XE100 << 16);
    // ori         $v1, $v1, 0x200
    ctx->r3 = ctx->r3 | 0X200;
L_8007ADFC:
    // beq         $a0, $zero, L_8007AE08
    if (ctx->r4 == 0) {
        // andi        $v0, $a2, 0x9FF
        ctx->r2 = ctx->r6 & 0X9FF;
        goto L_8007AE08;
    }
    // andi        $v0, $a2, 0x9FF
    ctx->r2 = ctx->r6 & 0X9FF;
    // ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_8007AE08:
    // jr          $ra
    // or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    return;
    // or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
;}
