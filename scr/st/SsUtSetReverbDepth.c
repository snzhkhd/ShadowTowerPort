#include "recomp.h"
#include "disable_warnings.h"

void SsUtSetReverbDepth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8102
    ctx->r2 = S32(0X8102 << 16);
    // ori         $v0, $v0, 0x409
    ctx->r2 = ctx->r2 | 0X409;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // sll         $v1, $a0, 15
    ctx->r3 = S32(ctx->r4) << 15;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // mfhi        $t0
    ctx->r8 = hi;
    // sll         $a2, $a1, 15
    ctx->r6 = S32(ctx->r5) << 15;
    // subu        $a2, $a2, $a1
    ctx->r6 = SUB32(ctx->r6, ctx->r5);
    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addiu       $a0, $a0, -0x6A00
    ctx->r4 = ADD32(ctx->r4, -0X6A00);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r2;
    // mfhi        $a1
    ctx->r5 = hi;
    // addu        $v0, $a1, $a2
    ctx->r2 = ADD32(ctx->r5, ctx->r6);
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // sra         $a2, $a2, 31
    ctx->r6 = S32(ctx->r6) >> 31;
    // subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // jal         0x8006F614
    // sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
    SpuSetReverbModeParam(rdram, ctx);
    goto after_0;
    // sh          $v0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r2;
    after_0:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
