#include "recomp.h"
#include "disable_warnings.h"

void _SsVmVSetUp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_800734F4
    if (ctx->r2 == 0) {
        // addu        $t0, $a1, $zero
        ctx->r8 = ADD32(ctx->r5, 0);
        goto L_800734F4;
    }
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lbu         $v1, -0x68E8($v1)
    ctx->r3 = MEM_BU(-0X68E8, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8007355C
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8007355C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5) << 16;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lh          $v0, -0x691E($v0)
    ctx->r2 = MEM_HS(-0X691E, ctx->r2);
    // sra         $a2, $v1, 16
    ctx->r6 = S32(ctx->r3) >> 16;
    // slt         $v0, $a2, $v0
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_800734FC
    if (ctx->r2 != 0) {
        // sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4) << 2;
        goto L_800734FC;
    }
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
L_800734F4:
    // j           L_8007355C
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8007355C;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800734FC:
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v1, -0x69A8($v1)
    ctx->r3 = MEM_W(-0X69A8, ctx->r3);
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // lw          $a1, -0x69E8($a1)
    ctx->r5 = MEM_W(-0X69E8, ctx->r5);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, -0x6960($at)
    ctx->r2 = MEM_W(-0X6960, ctx->r1);
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addiu       $a0, $a0, -0x6907
    ctx->r4 = ADD32(ctx->r4, -0X6907);
    // sb          $a3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r7;
    // sb          $t0, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r8;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v0, -0x6910($at)
    MEM_W(-0X6910, ctx->r1) = ctx->r2;
    // sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6) << 4;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v1, -0x6914($at)
    MEM_W(-0X6914, ctx->r1) = ctx->r3;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $a1, -0x691C($at)
    MEM_W(-0X691C, ctx->r1) = ctx->r5;
    // lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(0X8, ctx->r2);
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // sb          $v1, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r3;
L_8007355C:
    // jr          $ra
    // nop

    return;
    // nop

;}
