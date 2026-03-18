#include "recomp.h"
#include "disable_warnings.h"

void sub_8003F670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lw          $v1, 0x13C($a0)
    ctx->r3 = MEM_W(0X13C, ctx->r4);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_8003F6FC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8003F6FC;
    }
    // nop

    // lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(0X130, ctx->r4);
    // nop

    // bne         $v0, $v1, L_8003F6FC
    if (ctx->r2 != ctx->r3) {
        // andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
        goto L_8003F6FC;
    }
    // andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // lbu         $v1, 0x14C($v0)
    ctx->r3 = MEM_BU(0X14C, ctx->r2);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8003F6FC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003F6FC;
    }
    // nop

    // lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(0X2C, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // bne         $v0, $zero, L_8003F6FC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003F6FC;
    }
    // nop

    // lbu         $v0, 0x1CB($a0)
    ctx->r2 = MEM_BU(0X1CB, ctx->r4);
    // nop

    // beq         $v0, $zero, L_8003F6E0
    if (ctx->r2 == 0) {
        // sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5) << 1;
        goto L_8003F6E0;
    }
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // lh          $v0, 0x1C0($a0)
    ctx->r2 = MEM_HS(0X1C0, ctx->r4);
    // nop

    // beq         $v0, $zero, L_8003F6FC
    if (ctx->r2 == 0) {
        // sll         $v0, $a1, 1
        ctx->r2 = S32(ctx->r5) << 1;
        goto L_8003F6FC;
    }
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
L_8003F6E0:
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $zero, 0x13C($v0)
    MEM_H(0X13C, ctx->r2) = 0;
    // lhu         $v1, 0x182($a0)
    ctx->r3 = MEM_HU(0X182, ctx->r4);
    // addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // sh          $zero, 0x182($a0)
    MEM_H(0X182, ctx->r4) = 0;
    // sb          $v0, 0x188($a0)
    MEM_B(0X188, ctx->r4) = ctx->r2;
    // sh          $v1, 0x184($a0)
    MEM_H(0X184, ctx->r4) = ctx->r3;
L_8003F6FC:
    // jr          $ra
    // nop

    return;
    // nop

;}
