#include "recomp.h"
#include "disable_warnings.h"

void SpuSetNoiseClock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // bltz        $v0, L_80072764
    if (SIGNED(ctx->r2) < 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_80072764;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // slti        $v0, $a1, 0x40
    ctx->r2 = SIGNED(ctx->r5) < 0X40 ? 1 : 0;
    // bne         $v0, $zero, L_80072764
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80072764;
    }
    // nop

    // addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
L_80072764:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0xD40($a0)
    ctx->r4 = MEM_W(0XD40, ctx->r4);
    // andi        $v0, $a1, 0x3F
    ctx->r2 = ctx->r5 & 0X3F;
    // lhu         $v1, 0x1AA($a0)
    ctx->r3 = MEM_HU(0X1AA, ctx->r4);
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // andi        $v1, $v1, 0xC0FF
    ctx->r3 = ctx->r3 & 0XC0FF;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // jr          $ra
    // sh          $v1, 0x1AA($a0)
    MEM_H(0X1AA, ctx->r4) = ctx->r3;
    return;
    // sh          $v1, 0x1AA($a0)
    MEM_H(0X1AA, ctx->r4) = ctx->r3;
;}
