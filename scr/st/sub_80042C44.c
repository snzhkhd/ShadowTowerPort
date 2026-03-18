#include "recomp.h"
#include "disable_warnings.h"

void sub_80042C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $v1, -0x70D8
    ctx->r16 = ADD32(ctx->r3, -0X70D8);
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sb          $v0, 0x218($s0)
    MEM_B(0X218, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xDAC
    ctx->r2 = ADD32(0, 0XDAC);
    // sh          $v0, 0x2D6($s0)
    MEM_H(0X2D6, ctx->r16) = ctx->r2;
    // sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7) << 2;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // sh          $a2, 0x2D8($s0)
    MEM_H(0X2D8, ctx->r16) = ctx->r6;
    // lhu         $v1, -0x70D8($v1)
    ctx->r3 = MEM_HU(-0X70D8, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_80042C8C
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80042C8C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x14E($s0)
    MEM_B(0X14E, ctx->r16) = ctx->r2;
L_80042C8C:
    // lhu         $v1, 0x58($s0)
    ctx->r3 = MEM_HU(0X58, ctx->r16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_80042CD8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80042CD8;
    }
    // nop

    // lbu         $v0, 0x189($s0)
    ctx->r2 = MEM_BU(0X189, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80042CD8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80042CD8;
    }
    // nop

    // lw          $v1, 0x190($gp)
    ctx->r3 = MEM_W(0X190, ctx->r28);
    // lw          $v0, 0x23C($s0)
    ctx->r2 = MEM_W(0X23C, ctx->r16);
    // nop

    // beq         $v1, $v0, L_80042CD8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80042CD8;
    }
    // nop

    // lbu         $a0, 0x1D5($s0)
    ctx->r4 = MEM_BU(0X1D5, ctx->r16);
    // jal         0x800582F0
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    sub_800582F0(rdram, ctx);
    goto after_0;
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_0:
    // lw          $v0, 0x23C($s0)
    ctx->r2 = MEM_W(0X23C, ctx->r16);
    // nop

    // sw          $v0, 0x190($gp)
    MEM_W(0X190, ctx->r28) = ctx->r2;
L_80042CD8:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
