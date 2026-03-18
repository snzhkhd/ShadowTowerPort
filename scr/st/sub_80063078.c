#include "recomp.h"
#include "disable_warnings.h"

void sub_80063078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x1F80
    ctx->r17 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x80057A3C
    // sh          $v0, 0x2E0($s1)
    MEM_H(0X2E0, ctx->r17) = ctx->r2;
    sub_80057A3C(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x2E0($s1)
    MEM_H(0X2E0, ctx->r17) = ctx->r2;
    after_0:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s0, $v0, -0x2E80
    ctx->r16 = ADD32(ctx->r2, -0X2E80);
L_800630A0:
    // lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(0X4, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 & 0X2000;
    // beq         $v0, $zero, L_800630C4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800630C4;
    }
    // nop

    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // j           L_80063188
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    goto L_80063188;
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
L_800630C4:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_800630E8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800630E8;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // sh          $zero, 0x2E0($s1)
    MEM_H(0X2E0, ctx->r17) = 0;
L_800630E8:
    // lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(0XC, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_80063110
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063110;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // sh          $v0, 0x2E0($s1)
    MEM_H(0X2E0, ctx->r17) = ctx->r2;
L_80063110:
    // lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(0X4, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 & 0X4000;
    // beq         $v0, $zero, L_80063150
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80063150;
    }
    // nop

    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lhu         $v0, 0x2E0($s1)
    ctx->r2 = MEM_HU(0X2E0, ctx->r17);
    // nop

    // bne         $v0, $zero, L_80063188
    if (ctx->r2 != 0) {
        // sh          $zero, 0x4($s0)
        MEM_H(0X4, ctx->r16) = 0;
        goto L_80063188;
    }
    // sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sw          $v0, -0x7E5C($at)
    MEM_W(-0X7E5C, ctx->r1) = ctx->r2;
    // j           L_80063194
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_80063194;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80063150:
    // jal         0x800164B4
    // nop

    sub_800164B4(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // jal         0x8002CE84
    // nop

    sub_8002CE84(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lbu         $a0, 0x2E4($s1)
    ctx->r4 = MEM_BU(0X2E4, ctx->r17);
    // nop

    // addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // bgez        $v1, L_80063178
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80063178;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_80063178:
    // andi        $v0, $v0, 0x1E0
    ctx->r2 = ctx->r2 & 0X1E0;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // j           L_800630A0
    // sb          $v0, 0x2E4($s1)
    MEM_B(0X2E4, ctx->r17) = ctx->r2;
    goto L_800630A0;
    // sb          $v0, 0x2E4($s1)
    MEM_B(0X2E4, ctx->r17) = ctx->r2;
L_80063188:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80063194:
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
