#include "recomp.h"
#include "disable_warnings.h"

void sub_8007E0EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lbu         $v1, 0x46($a0)
    ctx->r3 = MEM_BU(0X46, ctx->r4);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $v1, $v0, L_8007E10C
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8007E10C;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $v0, L_8007E124
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x4D
        ctx->r2 = ADD32(0, 0X4D);
        goto L_8007E124;
    }
    // addiu       $v0, $zero, 0x4D
    ctx->r2 = ADD32(0, 0X4D);
    // j           L_8007E138
    // nop

    goto L_8007E138;
    // nop

L_8007E10C:
    // addiu       $v0, $zero, 0x44
    ctx->r2 = ADD32(0, 0X44);
    // sb          $v0, 0x36($a0)
    MEM_B(0X36, ctx->r4) = ctx->r2;
    // addiu       $v0, $a0, 0x51
    ctx->r2 = ADD32(ctx->r4, 0X51);
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    // j           L_8007E138
    // sb          $v1, 0x35($a0)
    MEM_B(0X35, ctx->r4) = ctx->r3;
    goto L_8007E138;
    // sb          $v1, 0x35($a0)
    MEM_B(0X35, ctx->r4) = ctx->r3;
L_8007E124:
    // sb          $v0, 0x36($a0)
    MEM_B(0X36, ctx->r4) = ctx->r2;
    // addiu       $v0, $a0, 0x5D
    ctx->r2 = ADD32(ctx->r4, 0X5D);
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // sb          $v0, 0x35($a0)
    MEM_B(0X35, ctx->r4) = ctx->r2;
L_8007E138:
    // jr          $ra
    // nop

    return;
    // nop

;}
