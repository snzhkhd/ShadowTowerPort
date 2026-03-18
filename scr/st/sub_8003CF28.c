#include "recomp.h"
#include "disable_warnings.h"

void sub_8003CF28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v0, $v1, -0x70D8
    ctx->r2 = ADD32(ctx->r3, -0X70D8);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(0X2, ctx->r2);
    // nop

    // addu        $s0, $v0, $a0
    ctx->r16 = ADD32(ctx->r2, ctx->r4);
    // bgtz        $s0, L_8003CF64
    if (SIGNED(ctx->r16) > 0) {
        // nop
    
        goto L_8003CF64;
    }
    // nop

    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // jal         0x8003BD14
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003BD14(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // j           L_8003CF7C
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    goto L_8003CF7C;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8003CF64:
    // lhu         $v1, -0x70D8($v1)
    ctx->r3 = MEM_HU(-0X70D8, ctx->r3);
    // nop

    // slt         $v0, $v1, $s0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // beq         $v0, $zero, L_8003CF7C
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003CF7C;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_8003CF7C:
    // sh          $s0, -0x70D6($v0)
    MEM_H(-0X70D6, ctx->r2) = ctx->r16;
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
