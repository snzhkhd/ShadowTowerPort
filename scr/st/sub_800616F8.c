#include "recomp.h"
#include "disable_warnings.h"

void sub_800616F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sh          $zero, 0x1F8($s0)
    MEM_H(0X1F8, ctx->r16) = 0;
    // jal         0x80057A3C
    // sb          $zero, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = 0;
    sub_80057A3C(rdram, ctx);
    goto after_0;
    // sb          $zero, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = 0;
    after_0:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s1, $v0, -0x2E80
    ctx->r17 = ADD32(ctx->r2, -0X2E80);
L_80061720:
    // lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(0X4, ctx->r17);
    // nop

    // andi        $v0, $v1, 0x4000
    ctx->r2 = ctx->r3 & 0X4000;
    // beq         $v0, $zero, L_80061770
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x2000
        ctx->r2 = ctx->r3 & 0X2000;
        goto L_80061770;
    }
    // andi        $v0, $v1, 0x2000
    ctx->r2 = ctx->r3 & 0X2000;
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lhu         $v1, 0x1F8($s0)
    ctx->r3 = MEM_HU(0X1F8, ctx->r16);
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addiu       $v0, $v0, 0x24
    ctx->r2 = ADD32(ctx->r2, 0X24);
    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // j           L_80061814
    // sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    goto L_80061814;
    // sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
L_80061770:
    // beq         $v0, $zero, L_80061790
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80061790;
    }
    // nop

    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // j           L_80061814
    // sh          $v0, 0x1F8($s0)
    MEM_H(0X1F8, ctx->r16) = ctx->r2;
    goto L_80061814;
    // sh          $v0, 0x1F8($s0)
    MEM_H(0X1F8, ctx->r16) = ctx->r2;
L_80061790:
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_800617B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800617B8;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // sh          $zero, 0x1F8($s0)
    MEM_H(0X1F8, ctx->r16) = 0;
    // sb          $zero, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = 0;
L_800617B8:
    // lhu         $v0, 0xC($s1)
    ctx->r2 = MEM_HU(0XC, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_800617E4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800617E4;
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
    // sh          $zero, 0xC($s1)
    MEM_H(0XC, ctx->r17) = 0;
    // sh          $v0, 0x1F8($s0)
    MEM_H(0X1F8, ctx->r16) = ctx->r2;
    // sb          $zero, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = 0;
L_800617E4:
    // jal         0x8002CA84
    // nop

    sub_8002CA84(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // lbu         $a0, 0x2E4($s0)
    ctx->r4 = MEM_BU(0X2E4, ctx->r16);
    // nop

    // addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // bgez        $v1, L_80061804
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80061804;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_80061804:
    // andi        $v0, $v0, 0x1E0
    ctx->r2 = ctx->r2 & 0X1E0;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // j           L_80061720
    // sb          $v0, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = ctx->r2;
    goto L_80061720;
    // sb          $v0, 0x2E4($s0)
    MEM_B(0X2E4, ctx->r16) = ctx->r2;
L_80061814:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lhu         $v0, 0x1F8($s0)
    ctx->r2 = MEM_HU(0X1F8, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
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
