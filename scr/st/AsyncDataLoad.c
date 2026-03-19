#include "recomp.h"
#include "disable_warnings.h"

void AsyncDataLoad(uint8_t* rdram, recomp_context* ctx) 
{
    printf("AsyncDataLoad\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x80058620
    // nop

    ProcessCDAudioLoad(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // jal         0x80045FFC
    // nop

    ProcessAssetLoadQueue(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x800214CC
    // nop

    sub_800214CC(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ST_DrawSync(rdram, ctx);
    goto after_3;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
    // jal         0x80077104
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    VSync(rdram, ctx);
    goto after_4;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
