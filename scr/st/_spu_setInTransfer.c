#include "recomp.h"
#include "disable_warnings.h"

void _spu_setInTransfer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $a0, $v0, L_80071EDC
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_80071EDC;
    }
    // nop

    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // j           L_80071EE4
    // sw          $zero, 0xD74($at)
    MEM_W(0XD74, ctx->r1) = 0;
    goto L_80071EE4;
    // sw          $zero, 0xD74($at)
    MEM_W(0XD74, ctx->r1) = 0;
L_80071EDC:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0xD74($at)
    MEM_W(0XD74, ctx->r1) = ctx->r2;
L_80071EE4:
    // jr          $ra
    // nop

    return;
    // nop

;}
