#include "recomp.h"
#include "disable_warnings.h"

void SetSemiTrans(uint8_t* rdram, recomp_context* ctx) 
{

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // beq         $a1, $zero, L_8007C7F8
    if (ctx->r5 == 0) {
        // nop
    
        goto L_8007C7F8;
    }
    // nop

    // lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(0X7, ctx->r4);
    // j           L_8007C804
    // ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    goto L_8007C804;
    // ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
L_8007C7F8:
    // lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(0X7, ctx->r4);
    // nop

    // andi        $v0, $v0, 0xFD
    ctx->r2 = ctx->r2 & 0XFD;
L_8007C804:
    // jr          $ra
    // sb          $v0, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r2;
    return;
    // sb          $v0, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r2;
;}
