#include "recomp.h"
#include "disable_warnings.h"

void sub_8004EDA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x2230
    ctx->r2 = ADD32(ctx->r2, 0X2230);
    // addiu       $v1, $v0, 0x44
    ctx->r3 = ADD32(ctx->r2, 0X44);
L_8004EDC0:
    // sh          $a1, -0x3A($v1)
    MEM_H(-0X3A, ctx->r3) = ctx->r5;
    // sb          $a2, -0x3F($v1)
    MEM_B(-0X3F, ctx->r3) = ctx->r6;
    // sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $a1, L_8004EDC0
    if (ctx->r2 != ctx->r5) {
        // addiu       $v1, $v1, 0x58
        ctx->r3 = ADD32(ctx->r3, 0X58);
        goto L_8004EDC0;
    }
    // addiu       $v1, $v1, 0x58
    ctx->r3 = ADD32(ctx->r3, 0X58);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x310
    ctx->r2 = ADD32(ctx->r2, 0X310);
    // sh          $zero, 0x727A($v0)
    MEM_H(0X727A, ctx->r2) = 0;
    // sh          $zero, 0x7278($v0)
    MEM_H(0X7278, ctx->r2) = 0;
    // jr          $ra
    // sh          $zero, 0x7276($v0)
    MEM_H(0X7276, ctx->r2) = 0;
    return;
    // sh          $zero, 0x7276($v0)
    MEM_H(0X7276, ctx->r2) = 0;
;}
