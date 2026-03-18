#include "recomp.h"
#include "disable_warnings.h"

void sub_800164B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a1, $v0, -0x7E00
    ctx->r5 = ADD32(ctx->r2, -0X7E00);
    // lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(0X8, ctx->r5);
    // lw          $a2, 0x4($a1)
    ctx->r6 = MEM_W(0X4, ctx->r5);
    // addiu       $v0, $v0, 0x3B
    ctx->r2 = ADD32(ctx->r2, 0X3B);
    // sltu        $v0, $v0, $a2
    ctx->r2 = ctx->r2 < ctx->r6 ? 1 : 0;
    // beq         $v0, $zero, L_80016500
    if (ctx->r2 == 0) {
        // lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
        goto L_80016500;
    }
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $a0, 0x6CC0($v0)
    ctx->r4 = MEM_BU(0X6CC0, ctx->r2);
    // lw          $v1, 0x10($a1)
    ctx->r3 = MEM_W(0X10, ctx->r5);
    // sb          $zero, 0x6CC0($v0)
    MEM_B(0X6CC0, ctx->r2) = 0;
    // sw          $a2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r6;
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sb          $a0, 0x6CC1($v0)
    MEM_B(0X6CC1, ctx->r2) = ctx->r4;
    // sw          $v1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r3;
L_80016500:
    // jr          $ra
    // nop

    return;
    // nop

;}
