#include "recomp.h"
#include "disable_warnings.h"

void sub_80014450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
    // addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // beq         $a2, $v0, L_800144E4
    if (ctx->r6 == ctx->r2) {
        // sw          $v1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r3;
        goto L_800144E4;
    }
    // sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // addiu       $t3, $zero, 0x2D
    ctx->r11 = ADD32(0, 0X2D);
    // addu        $t2, $v0, $zero
    ctx->r10 = ADD32(ctx->r2, 0);
L_80014480:
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // bne         $v0, $t3, L_800144A0
    if (ctx->r2 != ctx->r11) {
        // addiu       $v0, $v0, -0x30
        ctx->r2 = ADD32(ctx->r2, -0X30);
        goto L_800144A0;
    }
    // addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // j           L_800144D0
    // addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    goto L_800144D0;
    // addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
L_800144A0:
    // sltiu       $v0, $v0, 0xA
    ctx->r2 = ctx->r2 < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_800144D0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800144D0;
    }
    // nop

    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // addiu       $v0, $v0, -0x30
    ctx->r2 = ADD32(ctx->r2, -0X30);
    // mult        $v0, $a3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7) << 2;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // sll         $a3, $v0, 1
    ctx->r7 = S32(ctx->r2) << 1;
    // mflo        $t4
    ctx->r12 = lo;
    // addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
L_800144D0:
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bne         $a2, $t2, L_80014480
    if (ctx->r6 != ctx->r10) {
        // sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_80014480;
    }
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_800144E4:
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // addiu       $v1, $a1, 0x2
    ctx->r3 = ADD32(ctx->r5, 0X2);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // beq         $v1, $v0, L_80014528
    if (ctx->r3 == ctx->r2) {
        // mult        $t0, $t1
        result = S64(S32(ctx->r8)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80014528;
    }
    // mult        $t0, $t1
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
L_80014508:
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // nop

    // addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(0X1, ctx->r2);
    // nop

    // bne         $v0, $a1, L_80014508
    if (ctx->r2 != ctx->r5) {
        // mult        $t0, $t1
        result = S64(S32(ctx->r8)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80014508;
    }
    // mult        $t0, $t1
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
L_80014528:
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // mflo        $v0
    ctx->r2 = lo;
    // jr          $ra
    // nop

    return;
    // nop

;}
