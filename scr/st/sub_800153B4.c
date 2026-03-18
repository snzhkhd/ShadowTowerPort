#include "recomp.h"
#include "disable_warnings.h"

void sub_800153B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // addiu       $a0, $a0, -0x7E00
    ctx->r4 = ADD32(ctx->r4, -0X7E00);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(0XC, ctx->r4);
    // lbu         $v1, 0x33($a1)
    ctx->r3 = MEM_BU(0X33, ctx->r5);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // sb          $v1, 0x33($a1)
    MEM_B(0X33, ctx->r5) = ctx->r3;
    // andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // bne         $v1, $v0, L_80015414
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80015414;
    }
    // nop

    // lw          $v0, 0x34($a1)
    ctx->r2 = MEM_W(0X34, ctx->r5);
    // sb          $zero, 0x33($a1)
    MEM_B(0X33, ctx->r5) = 0;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r2;
L_80015414:
    // jal         0x80057744
    // nop

    sub_80057744(rdram, ctx);
    goto after_0;
    // nop

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
