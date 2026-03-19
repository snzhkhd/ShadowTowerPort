#include "recomp.h"
#include "disable_warnings.h"

void sub_800214CC(uint8_t* rdram, recomp_context* ctx) 
{
    printf("sub_800214CC - draw someone\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lbu         $v0, 0x6CC4($v1)
    ctx->r2 = MEM_BU(0X6CC4, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80021508
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80021508;
    }
    // nop

    // jal         0x800174C4
    // nop

    ST_BeginDraw2D(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // jal         0x80017680
    // nop

    sub_80017680(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_80021508:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
