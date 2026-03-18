#include "recomp.h"
#include "disable_warnings.h"

void sub_8003F4EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // bne         $a1, $zero, L_8003F5A0
    if (ctx->r5 != 0) {
        // addu        $t1, $a0, $zero
        ctx->r9 = ADD32(ctx->r4, 0);
        goto L_8003F5A0;
    }
    // addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a2, $v0, -0x70D8
    ctx->r6 = ADD32(ctx->r2, -0X70D8);
    // lh          $v1, 0x130($a2)
    ctx->r3 = MEM_HS(0X130, ctx->r6);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_8003F668
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8003F668;
    }
    // nop

    // lh          $v0, 0x132($a2)
    ctx->r2 = MEM_HS(0X132, ctx->r6);
    // nop

    // slti        $v0, $v0, 0x800
    ctx->r2 = SIGNED(ctx->r2) < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_8003F534
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003F534;
    }
    // nop

    // lbu         $v0, 0x14F($a2)
    ctx->r2 = MEM_BU(0X14F, ctx->r6);
    // nop

    // beq         $v0, $zero, L_8003F668
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003F668;
    }
    // nop

L_8003F534:
    // lbu         $v1, 0x148($a2)
    ctx->r3 = MEM_BU(0X148, ctx->r6);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8003F668
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003F668;
    }
    // nop

    // lh          $v0, 0x194($a2)
    ctx->r2 = MEM_HS(0X194, ctx->r6);
    // nop

    // bne         $v0, $zero, L_8003F668
    if (ctx->r2 != 0) {
        // lui         $v1, 0x801D
        ctx->r3 = S32(0X801D << 16);
        goto L_8003F668;
    }
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $v1, $v1, -0x2E80
    ctx->r3 = ADD32(ctx->r3, -0X2E80);
    // sb          $t1, 0x150($a2)
    MEM_B(0X150, ctx->r6) = ctx->r9;
    // sh          $zero, 0x130($a2)
    MEM_H(0X130, ctx->r6) = 0;
    // lhu         $a0, 0x32($v1)
    ctx->r4 = MEM_HU(0X32, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x154($a2)
    MEM_B(0X154, ctx->r6) = ctx->r2;
    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // lw          $a1, 0xE8($a2)
    ctx->r5 = MEM_W(0XE8, ctx->r6);
    // nor         $a0, $zero, $a0
    ctx->r4 = ~(0 | ctx->r4);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(0X6, ctx->r5);
    // nop

    // sh          $v0, 0x134($a2)
    MEM_H(0X134, ctx->r6) = ctx->r2;
    // lhu         $v1, 0x8($a1)
    ctx->r3 = MEM_HU(0X8, ctx->r5);
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // sb          $v0, 0x187($a2)
    MEM_B(0X187, ctx->r6) = ctx->r2;
    // j           L_8003F668
    // sh          $v1, 0x138($a2)
    MEM_H(0X138, ctx->r6) = ctx->r3;
    goto L_8003F668;
    // sh          $v1, 0x138($a2)
    MEM_H(0X138, ctx->r6) = ctx->r3;
L_8003F5A0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a2, $v0, -0x70D8
    ctx->r6 = ADD32(ctx->r2, -0X70D8);
    // sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5) << 1;
    // addu        $a3, $v0, $a2
    ctx->r7 = ADD32(ctx->r2, ctx->r6);
    // lh          $v1, 0x130($a3)
    ctx->r3 = MEM_HS(0X130, ctx->r7);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_8003F668
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8003F668;
    }
    // nop

    // lh          $v0, 0x130($a2)
    ctx->r2 = MEM_HS(0X130, ctx->r6);
    // nop

    // bne         $v0, $v1, L_8003F668
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8003F668;
    }
    // nop

    // lh          $v1, 0x13C($a3)
    ctx->r3 = MEM_HS(0X13C, ctx->r7);
    // nop

    // bne         $v1, $v0, L_8003F668
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8003F668;
    }
    // nop

    // lh          $v0, 0x13C($a2)
    ctx->r2 = MEM_HS(0X13C, ctx->r6);
    // nop

    // bne         $v0, $v1, L_8003F668
    if (ctx->r2 != ctx->r3) {
        // addu        $t0, $a1, $a2
        ctx->r8 = ADD32(ctx->r5, ctx->r6);
        goto L_8003F668;
    }
    // addu        $t0, $a1, $a2
    ctx->r8 = ADD32(ctx->r5, ctx->r6);
    // lbu         $v1, 0x148($t0)
    ctx->r3 = MEM_BU(0X148, ctx->r8);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8003F668
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003F668;
    }
    // nop

    // lh          $v0, 0x194($a2)
    ctx->r2 = MEM_HS(0X194, ctx->r6);
    // nop

    // bne         $v0, $zero, L_8003F668
    if (ctx->r2 != 0) {
        // lui         $a0, 0x801D
        ctx->r4 = S32(0X801D << 16);
        goto L_8003F668;
    }
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // addiu       $a0, $a0, -0x2E80
    ctx->r4 = ADD32(ctx->r4, -0X2E80);
    // lhu         $v0, 0x34($a0)
    ctx->r2 = MEM_HU(0X34, ctx->r4);
    // lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(0X4, ctx->r4);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $v1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r3;
    // sb          $t1, 0x150($t0)
    MEM_B(0X150, ctx->r8) = ctx->r9;
    // sh          $zero, 0x130($a3)
    MEM_H(0X130, ctx->r7) = 0;
    // sb          $v0, 0x154($a2)
    MEM_B(0X154, ctx->r6) = ctx->r2;
    // sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) << 2;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // lw          $v1, 0xE8($v0)
    ctx->r3 = MEM_W(0XE8, ctx->r2);
    // nop

    // lhu         $v1, 0x6($v1)
    ctx->r3 = MEM_HU(0X6, ctx->r3);
    // nop

    // sh          $v1, 0x134($a3)
    MEM_H(0X134, ctx->r7) = ctx->r3;
    // lw          $v0, 0xE8($v0)
    ctx->r2 = MEM_W(0XE8, ctx->r2);
    // nop

    // lhu         $v0, 0x8($v0)
    ctx->r2 = MEM_HU(0X8, ctx->r2);
    // nop

    // sh          $v0, 0x138($a3)
    MEM_H(0X138, ctx->r7) = ctx->r2;
L_8003F668:
    // jr          $ra
    // nop

    return;
    // nop

;}
