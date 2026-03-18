#include "recomp.h"
#include "disable_warnings.h"

void sub_8003CF94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(0X6, ctx->r5);
    // nop

    // addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // bgtz        $v1, L_8003CFB8
    if (SIGNED(ctx->r3) > 0) {
        // nop
    
        goto L_8003CFB8;
    }
    // nop

    // j           L_8003CFD0
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    goto L_8003CFD0;
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8003CFB8:
    // lhu         $a0, 0x4($a1)
    ctx->r4 = MEM_HU(0X4, ctx->r5);
    // nop

    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8003CFD4
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003CFD4;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_8003CFD0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8003CFD4:
    // jr          $ra
    // sh          $v1, -0x70D2($v0)
    MEM_H(-0X70D2, ctx->r2) = ctx->r3;
    return;
    // sh          $v1, -0x70D2($v0)
    MEM_H(-0X70D2, ctx->r2) = ctx->r3;
;}
