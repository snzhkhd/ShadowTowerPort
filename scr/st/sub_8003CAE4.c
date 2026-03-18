#include "recomp.h"
#include "disable_warnings.h"

void sub_8003CAE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
    // addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // addiu       $v0, $v0, 0x1A
    ctx->r2 = ADD32(ctx->r2, 0X1A);
L_8003CB00:
    // sh          $a0, 0x9A($v0)
    MEM_H(0X9A, ctx->r2) = ctx->r4;
    // sh          $a0, 0x62($v0)
    MEM_H(0X62, ctx->r2) = ctx->r4;
    // sh          $zero, 0x7E($v0)
    MEM_H(0X7E, ctx->r2) = 0;
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bne         $v1, $a1, L_8003CB00
    if (ctx->r3 != ctx->r5) {
        // addiu       $v0, $v0, -0x2
        ctx->r2 = ADD32(ctx->r2, -0X2);
        goto L_8003CB00;
    }
    // addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // sb          $zero, 0x26($v1)
    MEM_B(0X26, ctx->r3) = 0;
    // sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // sh          $zero, -0x70D8($v0)
    MEM_H(-0X70D8, ctx->r2) = 0;
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sh          $v0, 0x60($v1)
    MEM_H(0X60, ctx->r3) = ctx->r2;
    // sh          $v0, 0x5E($v1)
    MEM_H(0X5E, ctx->r3) = ctx->r2;
    // sh          $v0, 0x5C($v1)
    MEM_H(0X5C, ctx->r3) = ctx->r2;
    // sh          $v0, 0x40($v1)
    MEM_H(0X40, ctx->r3) = ctx->r2;
    // sh          $v0, 0x3E($v1)
    MEM_H(0X3E, ctx->r3) = ctx->r2;
    // sh          $v0, 0x3C($v1)
    MEM_H(0X3C, ctx->r3) = ctx->r2;
    // sh          $v0, 0x3A($v1)
    MEM_H(0X3A, ctx->r3) = ctx->r2;
    // sh          $v0, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r2;
    // sh          $v0, 0x44($v1)
    MEM_H(0X44, ctx->r3) = ctx->r2;
    // sh          $v0, 0x4E($v1)
    MEM_H(0X4E, ctx->r3) = ctx->r2;
    // sh          $v0, 0x4C($v1)
    MEM_H(0X4C, ctx->r3) = ctx->r2;
    // sh          $v0, 0x4A($v1)
    MEM_H(0X4A, ctx->r3) = ctx->r2;
    // sh          $v0, 0x48($v1)
    MEM_H(0X48, ctx->r3) = ctx->r2;
    // sh          $v0, 0x46($v1)
    MEM_H(0X46, ctx->r3) = ctx->r2;
    // sh          $v0, 0x50($v1)
    MEM_H(0X50, ctx->r3) = ctx->r2;
    // sh          $v0, 0x42($v1)
    MEM_H(0X42, ctx->r3) = ctx->r2;
    // sh          $v0, 0x5A($v1)
    MEM_H(0X5A, ctx->r3) = ctx->r2;
    // sh          $v0, 0x58($v1)
    MEM_H(0X58, ctx->r3) = ctx->r2;
    // sh          $v0, 0x56($v1)
    MEM_H(0X56, ctx->r3) = ctx->r2;
    // sh          $v0, 0x54($v1)
    MEM_H(0X54, ctx->r3) = ctx->r2;
    // jr          $ra
    // sh          $v0, 0x52($v1)
    MEM_H(0X52, ctx->r3) = ctx->r2;
    return;
    // sh          $v0, 0x52($v1)
    MEM_H(0X52, ctx->r3) = ctx->r2;
;}
