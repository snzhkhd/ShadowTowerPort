#include "recomp.h"
#include "disable_warnings.h"

void sub_800339C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lhu         $a2, 0x0($a1)
    ctx->r6 = MEM_HU(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // beq         $v0, $v1, L_80033A40
    if (ctx->r2 == ctx->r3) {
        // lui         $t2, 0x1F80
        ctx->r10 = S32(0X1F80 << 16);
        goto L_80033A40;
    }
    // lui         $t2, 0x1F80
    ctx->r10 = S32(0X1F80 << 16);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $t1, $v0, -0x2F70
    ctx->r9 = ADD32(ctx->r2, -0X2F70);
    // ori         $t0, $zero, 0x834C
    ctx->r8 = 0 | 0X834C;
    // addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
L_800339F4:
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // nop

    // sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80033A28
    if (ctx->r2 != 0) {
        // andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
        goto L_80033A28;
    }
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(0X8, ctx->r5);
    // nop

    // addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // sw          $v0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r2;
L_80033A28:
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // bne         $v0, $a3, L_800339F4
    if (ctx->r2 != ctx->r7) {
        // addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
        goto L_800339F4;
    }
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80033A40:
    // jr          $ra
    // nop

    return;
    // nop

;}
