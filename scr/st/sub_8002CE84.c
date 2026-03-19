#include "recomp.h"
#include "disable_warnings.h"

void sub_8002CE84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // jal         0x800174C4
    // nop

    ST_BeginDraw2D(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v1, 0x1F80
    ctx->r3 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sb          $v0, 0x300($v1)
    MEM_B(0X300, ctx->r3) = ctx->r2;
    // sb          $v0, 0x301($v1)
    MEM_B(0X301, ctx->r3) = ctx->r2;
    // sb          $v0, 0x302($v1)
    MEM_B(0X302, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x62
    ctx->r2 = ADD32(0, 0X62);
    // sb          $v0, 0x308($v1)
    MEM_B(0X308, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
    // sb          $v0, 0x309($v1)
    MEM_B(0X309, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sb          $v0, 0x30A($v1)
    MEM_B(0X30A, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    // sb          $v0, 0x30B($v1)
    MEM_B(0X30B, ctx->r3) = ctx->r2;
    // jal         0x8002CD98
    // sb          $v0, 0x303($v1)
    MEM_B(0X303, ctx->r3) = ctx->r2;
    sub_8002CD98(rdram, ctx);
    goto after_1;
    // sb          $v0, 0x303($v1)
    MEM_B(0X303, ctx->r3) = ctx->r2;
    after_1:
    // jal         0x800175A4
    // nop

    sub_800175A4(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x8002948C
    // nop

    sub_8002948C(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x80017634
    // nop

    sub_80017634(rdram, ctx);
    goto after_4;
    // nop

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
