#include "recomp.h"
#include "disable_warnings.h"

void MemCardInit(uint8_t* rdram, recomp_context* ctx) 
{
    printf("MemCardInit\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x80077314
    // nop
    printf("MemCardInit  ResetCallback\n");
    ResetCallback(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // jal         0x8006CA54
    // nop
    printf("MemCardInit  MemCardEnd\n");
    MemCardEnd(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x8006CA74
    // nop
    printf("MemCardInit  sub_8006CA74\n");
    sub_8006CA74(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop
    printf("MemCardInit  end\n");
    return;
    // nop

;}
