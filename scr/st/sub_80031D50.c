#include "recomp.h"
#include "disable_warnings.h"

void sub_80031D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // jal         0x800174C4
    // nop

    sub_800174C4(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // jal         0x800175A4
    // nop

    sub_800175A4(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x8002948C
    // nop

    sub_8002948C(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // addiu       $v0, $zero, 0x90
    ctx->r2 = ADD32(0, 0X90);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x7FE2
    ctx->r2 = ADD32(0, 0X7FE2);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // addiu       $a3, $zero, 0x88
    ctx->r7 = ADD32(0, 0X88);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // jal         0x80021518
    // sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    sub_80021518(rdram, ctx);
    goto after_3;
    // sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    after_3:
    // jal         0x80017634
    // nop

    sub_80017634(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
