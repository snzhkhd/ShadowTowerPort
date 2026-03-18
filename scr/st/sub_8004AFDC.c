#include "recomp.h"
#include "disable_warnings.h"

void sub_8004AFDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x5EC8
    ctx->r2 = ADD32(ctx->r2, -0X5EC8);
    // sw          $zero, 0x6150($v0)
    MEM_W(0X6150, ctx->r2) = 0;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // addiu       $v1, $a0, 0xA4
    ctx->r3 = ADD32(ctx->r4, 0XA4);
L_8004AFF8:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // sb          $a2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r6;
    // sb          $zero, -0x9F($v1)
    MEM_B(-0X9F, ctx->r3) = 0;
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // addiu       $v1, $v1, 0xD4
    ctx->r3 = ADD32(ctx->r3, 0XD4);
    // andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // sltiu       $v0, $v0, 0x40
    ctx->r2 = ctx->r2 < 0X40 ? 1 : 0;
    // bne         $v0, $zero, L_8004AFF8
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0xD4
        ctx->r4 = ADD32(ctx->r4, 0XD4);
        goto L_8004AFF8;
    }
    // addiu       $a0, $a0, 0xD4
    ctx->r4 = ADD32(ctx->r4, 0XD4);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x5EC8
    ctx->r2 = ADD32(ctx->r2, -0X5EC8);
    // addiu       $v1, $zero, 0xFE
    ctx->r3 = ADD32(0, 0XFE);
    // sb          $v1, 0x6168($v0)
    MEM_B(0X6168, ctx->r2) = ctx->r3;
    // addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // sb          $zero, 0x6101($v0)
    MEM_B(0X6101, ctx->r2) = 0;
    // sh          $v1, 0x615E($v0)
    MEM_H(0X615E, ctx->r2) = ctx->r3;
    // sh          $v1, 0x615C($v0)
    MEM_H(0X615C, ctx->r2) = ctx->r3;
    // sh          $v1, 0x615A($v0)
    MEM_H(0X615A, ctx->r2) = ctx->r3;
    // sh          $v1, 0x6158($v0)
    MEM_H(0X6158, ctx->r2) = ctx->r3;
    // sb          $v1, 0x6103($v0)
    MEM_B(0X6103, ctx->r2) = ctx->r3;
    // sw          $zero, 0x6130($v0)
    MEM_W(0X6130, ctx->r2) = 0;
    // sw          $zero, 0x612C($v0)
    MEM_W(0X612C, ctx->r2) = 0;
    // jr          $ra
    // sw          $zero, 0x6128($v0)
    MEM_W(0X6128, ctx->r2) = 0;
    return;
    // sw          $zero, 0x6128($v0)
    MEM_W(0X6128, ctx->r2) = 0;
;}
