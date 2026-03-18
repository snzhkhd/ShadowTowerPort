#include "recomp.h"
#include "disable_warnings.h"

void sub_80077CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0x7BE4
    ctx->r3 = ADD32(ctx->r3, 0X7BE4);
    // sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6) << 2;
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(0X0, ctx->r3);
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // beq         $a0, $a3, L_80077D64
    if (ctx->r4 == ctx->r7) {
        // addu        $v0, $a3, $zero
        ctx->r2 = ADD32(ctx->r7, 0);
        goto L_80077D64;
    }
    // addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // beq         $a0, $zero, L_80077D28
    if (ctx->r4 == 0) {
        // lui         $v0, 0xFF
        ctx->r2 = S32(0XFF << 16);
        goto L_80077D28;
    }
    // lui         $v0, 0xFF
    ctx->r2 = S32(0XFF << 16);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0x7BE0($a1)
    ctx->r5 = MEM_W(0X7BE0, ctx->r5);
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(0X0, ctx->r5);
    // addiu       $v1, $a2, 0x10
    ctx->r3 = ADD32(ctx->r6, 0X10);
    // and         $a0, $a0, $v0
    ctx->r4 = ctx->r4 & ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sllv        $v0, $v0, $v1
    ctx->r2 = S32(ctx->r2) << (ctx->r3 & 31);
    // lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    // sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // j           L_80077D64
    // addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    goto L_80077D64;
    // addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
L_80077D28:
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0x7BE0($a1)
    ctx->r5 = MEM_W(0X7BE0, ctx->r5);
    // ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // addiu       $a0, $a2, 0x10
    ctx->r4 = ADD32(ctx->r6, 0X10);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // lui         $v0, 0x80
    ctx->r2 = S32(0X80 << 16);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sllv        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2) << (ctx->r4 & 31);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
L_80077D64:
    // jr          $ra
    // nop

    return;
    // nop

;}
