#include "recomp.h"
#include "disable_warnings.h"

void sub_8004B058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v0, 0xF($a0)
    ctx->r2 = MEM_BU(0XF, ctx->r4);
    // beq         $a1, $zero, L_8004B078
    if (ctx->r5 == 0) {
        // sb          $v0, 0x19($a0)
        MEM_B(0X19, ctx->r4) = ctx->r2;
        goto L_8004B078;
    }
    // sb          $v0, 0x19($a0)
    MEM_B(0X19, ctx->r4) = ctx->r2;
    // sw          $a1, 0xA8($a0)
    MEM_W(0XA8, ctx->r4) = ctx->r5;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // sb          $zero, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = 0;
    // j           L_8004B088
    // sb          $v0, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r2;
    goto L_8004B088;
    // sb          $v0, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r2;
L_8004B078:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sw          $zero, 0xA8($a0)
    MEM_W(0XA8, ctx->r4) = 0;
    // sb          $v0, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r2;
    // sb          $v0, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r2;
L_8004B088:
    // jr          $ra
    // nop

    return;
    // nop

;}
