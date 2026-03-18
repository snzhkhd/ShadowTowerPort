#include "recomp.h"
#include "disable_warnings.h"

void SetDrawTPage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r2;
    // beq         $a2, $zero, L_8007C848
    if (ctx->r6 == 0) {
        // lui         $v1, 0xE100
        ctx->r3 = S32(0XE100 << 16);
        goto L_8007C848;
    }
    // lui         $v1, 0xE100
    ctx->r3 = S32(0XE100 << 16);
    // ori         $v1, $v1, 0x200
    ctx->r3 = ctx->r3 | 0X200;
L_8007C848:
    // beq         $a1, $zero, L_8007C854
    if (ctx->r5 == 0) {
        // andi        $v0, $a3, 0x9FF
        ctx->r2 = ctx->r7 & 0X9FF;
        goto L_8007C854;
    }
    // andi        $v0, $a3, 0x9FF
    ctx->r2 = ctx->r7 & 0X9FF;
    // ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_8007C854:
    // or          $v0, $v1, $v0
    ctx->r2 = ctx->r3 | ctx->r2;
    // jr          $ra
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    return;
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
;}
