#include "recomp.h"
#include "disable_warnings.h"

void sub_8007E994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v0, 0x49($a0)
    ctx->r2 = MEM_BU(0X49, ctx->r4);
    // nop

    // beq         $v0, $zero, L_8007E9F4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007E9F4;
    }
    // nop

    // addiu       $v1, $a0, 0x5D
    ctx->r3 = ADD32(ctx->r4, 0X5D);
    // addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sb          $zero, 0x49($a0)
    MEM_B(0X49, ctx->r4) = 0;
    // sb          $zero, 0x46($a0)
    MEM_B(0X46, ctx->r4) = 0;
    // sh          $zero, 0xE6($a0)
    MEM_H(0XE6, ctx->r4) = 0;
    // sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // sb          $zero, 0xE3($a0)
    MEM_B(0XE3, ctx->r4) = 0;
    // sb          $zero, 0xE4($a0)
    MEM_B(0XE4, ctx->r4) = 0;
    // sh          $zero, 0xE6($a0)
    MEM_H(0XE6, ctx->r4) = 0;
    // sb          $zero, 0xE9($a0)
    MEM_B(0XE9, ctx->r4) = 0;
    // sb          $zero, 0xEA($a0)
    MEM_B(0XEA, ctx->r4) = 0;
    // sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
L_8007E9E4:
    // sb          $a1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r5;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bgez        $v0, L_8007E9E4
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8007E9E4;
    }
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8007E9F4:
    // jr          $ra
    // nop

    return;
    // nop

;}
