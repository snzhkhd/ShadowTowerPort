#include "recomp.h"
#include "disable_warnings.h"

void sub_800615D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sb          $zero, 0x2E4($s2)
    MEM_B(0X2E4, ctx->r18) = 0;
    // jal         0x80057A3C
    // sh          $zero, 0x202($s2)
    MEM_H(0X202, ctx->r18) = 0;
    sub_80057A3C(rdram, ctx);
    goto after_0;
    // sh          $zero, 0x202($s2)
    MEM_H(0X202, ctx->r18) = 0;
    after_0:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s1, $v0, -0x2E80
    ctx->r17 = ADD32(ctx->r2, -0X2E80);
L_80061608:
    // bne         $s0, $zero, L_80061634
    if (ctx->r16 != 0) {
        // nop
    
        goto L_80061634;
    }
    // nop

    // lhu         $a0, 0x1F8($s2)
    ctx->r4 = MEM_HU(0X1F8, ctx->r18);
    // nop

    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x80061578
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_80061578(rdram, ctx);
    goto after_1;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_1:
    // bne         $v0, $zero, L_80061634
    if (ctx->r2 != 0) {
        // addiu       $s0, $zero, 0x3
        ctx->r16 = ADD32(0, 0X3);
        goto L_80061634;
    }
    // addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // j           L_800616DC
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_800616DC;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80061634:
    // lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(0X4, ctx->r17);
    // nop

    // andi        $v0, $v1, 0x4000
    ctx->r2 = ctx->r3 & 0X4000;
    // beq         $v0, $zero, L_80061658
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x2000
        ctx->r2 = ctx->r3 & 0X2000;
        goto L_80061658;
    }
    // andi        $v0, $v1, 0x2000
    ctx->r2 = ctx->r3 & 0X2000;
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_800616C4
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    goto L_800616C4;
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
L_80061658:
    // beq         $v0, $zero, L_80061674
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x80
        ctx->r2 = ctx->r3 & 0X80;
        goto L_80061674;
    }
    // andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // j           L_800616C4
    // sh          $zero, 0x202($s2)
    MEM_H(0X202, ctx->r18) = 0;
    goto L_800616C4;
    // sh          $zero, 0x202($s2)
    MEM_H(0X202, ctx->r18) = 0;
L_80061674:
    // beq         $v0, $zero, L_80061690
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80061690;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // sh          $v0, 0x202($s2)
    MEM_H(0X202, ctx->r18) = ctx->r2;
L_80061690:
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_800616B4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800616B4;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // sh          $zero, 0x202($s2)
    MEM_H(0X202, ctx->r18) = 0;
L_800616B4:
    // jal         0x8002CA84
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    sub_8002CA84(rdram, ctx);
    goto after_6;
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    after_6:
    // j           L_80061608
    // nop

    goto L_80061608;
    // nop

L_800616C4:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lhu         $v0, 0x202($s2)
    ctx->r2 = MEM_HU(0X202, ctx->r18);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
L_800616DC:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
