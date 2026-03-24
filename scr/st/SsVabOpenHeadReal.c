#include "recomp.h"
#include "disable_warnings.h"

void SsVabOpenHeadReal(uint8_t* rdram, recomp_context* ctx) 
{
    printf("SsVabOpenHeadReal (SsVabOpenHeadReal) - call from 800588B4 (OnAudioStreamComplete)\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // jal         0x800739F4
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    SsVabOpenHeadWithMode(rdram, ctx);
    goto after_0;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
