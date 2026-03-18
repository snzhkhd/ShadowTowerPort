#include "recomp.h"
#include "disable_warnings.h"

void sub_80041D4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v1, $v0, -0x2E80
    ctx->r3 = ADD32(ctx->r2, -0X2E80);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(0X2, ctx->r3);
    // lhu         $v0, 0x26($v1)
    ctx->r2 = MEM_HU(0X26, ctx->r3);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_80041DB0
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80041DB0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lw          $a0, 0x2E8($a1)
    ctx->r4 = MEM_W(0X2E8, ctx->r5);
    // lhu         $v0, 0x2CA($a1)
    ctx->r2 = MEM_HU(0X2CA, ctx->r5);
    // sra         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) >> 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x2CA($a1)
    MEM_H(0X2CA, ctx->r5) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $a0, $a0, $v0
    ctx->r4 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $a0, $zero, L_80041E74
    if (ctx->r4 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80041E74;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, 0x2E8($a1)
    ctx->r2 = MEM_HU(0X2E8, ctx->r5);
    // j           L_80041E70
    // sh          $v0, 0x2CA($a1)
    MEM_H(0X2CA, ctx->r5) = ctx->r2;
    goto L_80041E70;
    // sh          $v0, 0x2CA($a1)
    MEM_H(0X2CA, ctx->r5) = ctx->r2;
L_80041DB0:
    // lhu         $v0, 0x28($v1)
    ctx->r2 = MEM_HU(0X28, ctx->r3);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_80041E08
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80041E08;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lw          $a0, 0x2E8($a1)
    ctx->r4 = MEM_W(0X2E8, ctx->r5);
    // lhu         $v0, 0x2CA($a1)
    ctx->r2 = MEM_HU(0X2CA, ctx->r5);
    // sra         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) >> 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x2CA($a1)
    MEM_H(0X2CA, ctx->r5) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_80041E74
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80041E74;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, 0x2E8($a1)
    ctx->r2 = MEM_HU(0X2E8, ctx->r5);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // j           L_80041E70
    // sh          $v0, 0x2CA($a1)
    MEM_H(0X2CA, ctx->r5) = ctx->r2;
    goto L_80041E70;
    // sh          $v0, 0x2CA($a1)
    MEM_H(0X2CA, ctx->r5) = ctx->r2;
L_80041E08:
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lh          $v0, 0x2CA($a0)
    ctx->r2 = MEM_HS(0X2CA, ctx->r4);
    // lhu         $v1, 0x2CA($a0)
    ctx->r3 = MEM_HU(0X2CA, ctx->r4);
    // blez        $v0, L_80041E44
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80041E44;
    }
    // nop

    // lw          $v0, 0x2E8($a0)
    ctx->r2 = MEM_W(0X2E8, ctx->r4);
    // nop

    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sh          $v0, 0x2CA($a0)
    MEM_H(0X2CA, ctx->r4) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_80041E74
    if (SIGNED(ctx->r2) >= 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80041E74;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // j           L_80041E74
    // sh          $zero, 0x2CA($a0)
    MEM_H(0X2CA, ctx->r4) = 0;
    goto L_80041E74;
    // sh          $zero, 0x2CA($a0)
    MEM_H(0X2CA, ctx->r4) = 0;
L_80041E44:
    // bgez        $v0, L_80041E74
    if (SIGNED(ctx->r2) >= 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80041E74;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, 0x2E8($a0)
    ctx->r2 = MEM_W(0X2E8, ctx->r4);
    // nop

    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sh          $v0, 0x2CA($a0)
    MEM_H(0X2CA, ctx->r4) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_80041E74
    if (SIGNED(ctx->r2) <= 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80041E74;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sh          $zero, 0x2CA($a0)
    MEM_H(0X2CA, ctx->r4) = 0;
L_80041E70:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80041E74:
    // addiu       $a2, $v0, -0x70D8
    ctx->r6 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, 0x27A($a2)
    ctx->r3 = MEM_HU(0X27A, ctx->r6);
    // lhu         $v0, 0x2CA($a2)
    ctx->r2 = MEM_HU(0X2CA, ctx->r6);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a1, $v0, -0x2E80
    ctx->r5 = ADD32(ctx->r2, -0X2E80);
    // lhu         $a0, 0x2($a1)
    ctx->r4 = MEM_HU(0X2, ctx->r5);
    // lhu         $v0, 0x2E($a1)
    ctx->r2 = MEM_HU(0X2E, ctx->r5);
    // andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_80041F84
    if (ctx->r2 == 0) {
        // sh          $v1, 0x27A($a2)
        MEM_H(0X27A, ctx->r6) = ctx->r3;
        goto L_80041F84;
    }
    // sh          $v1, 0x27A($a2)
    MEM_H(0X27A, ctx->r6) = ctx->r3;
    // lhu         $v0, 0x30($a1)
    ctx->r2 = MEM_HU(0X30, ctx->r5);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_80041F58
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80041F58;
    }
    // nop

    // lh          $a0, 0x278($a2)
    ctx->r4 = MEM_HS(0X278, ctx->r6);
    // lhu         $a1, 0x278($a2)
    ctx->r5 = MEM_HU(0X278, ctx->r6);
    // slti        $v0, $a0, 0x801
    ctx->r2 = SIGNED(ctx->r4) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_80041F10
    if (ctx->r2 != 0) {
        // slti        $v0, $a0, 0x800
        ctx->r2 = SIGNED(ctx->r4) < 0X800 ? 1 : 0;
        goto L_80041F10;
    }
    // slti        $v0, $a0, 0x800
    ctx->r2 = SIGNED(ctx->r4) < 0X800 ? 1 : 0;
    // addiu       $a3, $zero, 0x1080
    ctx->r7 = ADD32(0, 0X1080);
    // subu        $v1, $a3, $a0
    ctx->r3 = SUB32(ctx->r7, ctx->r4);
    // lhu         $v0, 0x2CC($a2)
    ctx->r2 = MEM_HU(0X2CC, ctx->r6);
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // sh          $v0, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80042014
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80042014;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // bne         $v1, $zero, L_80042014
    if (ctx->r3 != 0) {
        // sh          $v1, 0x2CC($a2)
        MEM_H(0X2CC, ctx->r6) = ctx->r3;
        goto L_80042014;
    }
    // sh          $v1, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r3;
    // subu        $v0, $a3, $a1
    ctx->r2 = SUB32(ctx->r7, ctx->r5);
    // j           L_80042010
    // sh          $v0, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r2;
    goto L_80042010;
    // sh          $v0, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r2;
L_80041F10:
    // beq         $v0, $zero, L_80042010
    if (ctx->r2 == 0) {
        // addiu       $v0, $a0, -0x80
        ctx->r2 = ADD32(ctx->r4, -0X80);
        goto L_80042010;
    }
    // addiu       $v0, $a0, -0x80
    ctx->r2 = ADD32(ctx->r4, -0X80);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // lhu         $v1, 0x2CC($a2)
    ctx->r3 = MEM_HU(0X2CC, ctx->r6);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // addiu       $v1, $v1, -0x8
    ctx->r3 = ADD32(ctx->r3, -0X8);
    // sh          $v1, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r3;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_80042010
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80042010;
    }
    // nop

    // bne         $v0, $zero, L_80042010
    if (ctx->r2 != 0) {
        // sh          $v0, 0x2CC($a2)
        MEM_H(0X2CC, ctx->r6) = ctx->r2;
        goto L_80042010;
    }
    // sh          $v0, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r2;
    // addiu       $v0, $a1, -0x80
    ctx->r2 = ADD32(ctx->r5, -0X80);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // j           L_80042010
    // sh          $v0, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r2;
    goto L_80042010;
    // sh          $v0, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r2;
L_80041F58:
    // lhu         $v0, 0x2CC($a2)
    ctx->r2 = MEM_HU(0X2CC, ctx->r6);
    // nop

    // addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // sh          $v0, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, -0x20
    ctx->r2 = SIGNED(ctx->r2) < -0X20 ? 1 : 0;
    // beq         $v0, $zero, L_80042010
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x20
        ctx->r2 = ADD32(0, -0X20);
        goto L_80042010;
    }
    // addiu       $v0, $zero, -0x20
    ctx->r2 = ADD32(0, -0X20);
    // j           L_80042010
    // sh          $v0, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r2;
    goto L_80042010;
    // sh          $v0, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r2;
L_80041F84:
    // lhu         $v0, 0x30($a1)
    ctx->r2 = MEM_HU(0X30, ctx->r5);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_80041FC8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80041FC8;
    }
    // nop

    // lhu         $v0, 0x2CC($a2)
    ctx->r2 = MEM_HU(0X2CC, ctx->r6);
    // nop

    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // sh          $v0, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x21
    ctx->r2 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // bne         $v0, $zero, L_80042014
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80042014;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // j           L_80042010
    // sh          $v0, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r2;
    goto L_80042010;
    // sh          $v0, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r2;
L_80041FC8:
    // lh          $v1, 0x2CC($a2)
    ctx->r3 = MEM_HS(0X2CC, ctx->r6);
    // lhu         $v0, 0x2CC($a2)
    ctx->r2 = MEM_HU(0X2CC, ctx->r6);
    // blez        $v1, L_80041FF4
    if (SIGNED(ctx->r3) <= 0) {
        // nop
    
        goto L_80041FF4;
    }
    // nop

    // addiu       $v0, $v0, -0x3
    ctx->r2 = ADD32(ctx->r2, -0X3);
    // sh          $v0, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_80042014
    if (SIGNED(ctx->r2) >= 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80042014;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // j           L_80042014
    // sh          $zero, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = 0;
    goto L_80042014;
    // sh          $zero, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = 0;
L_80041FF4:
    // bgez        $v1, L_80042010
    if (SIGNED(ctx->r3) >= 0) {
        // addiu       $v0, $v0, 0x3
        ctx->r2 = ADD32(ctx->r2, 0X3);
        goto L_80042010;
    }
    // addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // sh          $v0, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_80042054
    if (SIGNED(ctx->r2) <= 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80042054;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sh          $zero, 0x2CC($a2)
    MEM_H(0X2CC, ctx->r6) = 0;
L_80042010:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80042014:
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lh          $v0, 0x2CC($s0)
    ctx->r2 = MEM_HS(0X2CC, ctx->r16);
    // lhu         $v1, 0x2CC($s0)
    ctx->r3 = MEM_HU(0X2CC, ctx->r16);
    // blez        $v0, L_80042050
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $a1, $zero, 0x2BC
        ctx->r5 = ADD32(0, 0X2BC);
        goto L_80042050;
    }
    // addiu       $a1, $zero, 0x2BC
    ctx->r5 = ADD32(0, 0X2BC);
    // lhu         $a0, 0x278($s0)
    ctx->r4 = MEM_HU(0X278, ctx->r16);
    // nop

    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // jal         0x8004A194
    // sh          $a0, 0x278($s0)
    MEM_H(0X278, ctx->r16) = ctx->r4;
    sub_8004A194(rdram, ctx);
    goto after_0;
    // sh          $a0, 0x278($s0)
    MEM_H(0X278, ctx->r16) = ctx->r4;
    after_0:
    // beq         $v0, $zero, L_8004208C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2BC
        ctx->r2 = ADD32(0, 0X2BC);
        goto L_8004208C;
    }
    // addiu       $v0, $zero, 0x2BC
    ctx->r2 = ADD32(0, 0X2BC);
    // j           L_8004208C
    // sh          $v0, 0x278($s0)
    MEM_H(0X278, ctx->r16) = ctx->r2;
    goto L_8004208C;
    // sh          $v0, 0x278($s0)
    MEM_H(0X278, ctx->r16) = ctx->r2;
L_80042050:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80042054:
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lh          $v0, 0x2CC($s0)
    ctx->r2 = MEM_HS(0X2CC, ctx->r16);
    // lhu         $v1, 0x2CC($s0)
    ctx->r3 = MEM_HU(0X2CC, ctx->r16);
    // bgez        $v0, L_8004208C
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $a0, $zero, 0xD44
        ctx->r4 = ADD32(0, 0XD44);
        goto L_8004208C;
    }
    // addiu       $a0, $zero, 0xD44
    ctx->r4 = ADD32(0, 0XD44);
    // lhu         $a1, 0x278($s0)
    ctx->r5 = MEM_HU(0X278, ctx->r16);
    // nop

    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // andi        $a1, $a1, 0xFFF
    ctx->r5 = ctx->r5 & 0XFFF;
    // jal         0x8004A194
    // sh          $a1, 0x278($s0)
    MEM_H(0X278, ctx->r16) = ctx->r5;
    sub_8004A194(rdram, ctx);
    goto after_1;
    // sh          $a1, 0x278($s0)
    MEM_H(0X278, ctx->r16) = ctx->r5;
    after_1:
    // beq         $v0, $zero, L_8004208C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xD44
        ctx->r2 = ADD32(0, 0XD44);
        goto L_8004208C;
    }
    // addiu       $v0, $zero, 0xD44
    ctx->r2 = ADD32(0, 0XD44);
    // sh          $v0, 0x278($s0)
    MEM_H(0X278, ctx->r16) = ctx->r2;
L_8004208C:
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
