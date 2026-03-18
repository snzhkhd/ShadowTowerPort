#include "recomp.h"
#include "disable_warnings.h"

void _spu_FgetRXXa(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD40($v0)
    ctx->r2 = MEM_W(0XD40, ctx->r2);
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lhu         $a0, 0x0($a0)
    ctx->r4 = MEM_HU(0X0, ctx->r4);
    // beq         $a1, $v0, L_8006C6C8
    if (ctx->r5 == ctx->r2) {
        // nop
    
        goto L_8006C6C8;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xD68($v0)
    ctx->r2 = MEM_W(0XD68, ctx->r2);
    // j           L_8006C6CC
    // sllv        $v0, $a0, $v0
    ctx->r2 = S32(ctx->r4) << (ctx->r2 & 31);
    goto L_8006C6CC;
    // sllv        $v0, $a0, $v0
    ctx->r2 = S32(ctx->r4) << (ctx->r2 & 31);
L_8006C6C8:
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_8006C6CC:
    // jr          $ra
    // nop

    return;
    // nop

;}
