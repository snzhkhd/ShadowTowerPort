#include "recomp.h"
#include "disable_warnings.h"

void sub_8004FDE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // lhu         $v1, 0xC($s2)
    ctx->r3 = MEM_HU(0XC, ctx->r18);
    // lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(0X64, ctx->r29);
    // beq         $v1, $zero, L_8004FE28
    if (ctx->r3 == 0) {
        // addu        $s6, $a3, $zero
        ctx->r22 = ADD32(ctx->r7, 0);
        goto L_8004FE28;
    }
    // addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_8004FF3C
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
       /* goto L_8004FF3C;*/
        recomp_vram_call(rdram, ctx, 0x8004FF3C);
        return;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_80050080
    recomp_vram_call(rdram, ctx, 0x80050080);
    return;
    // nop

L_8004FE28:
    // lbu         $v1, 0x48($s2)
    ctx->r3 = MEM_BU(0X48, ctx->r18);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_80050080
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        /*goto L_80050080;*/
        recomp_vram_call(rdram, ctx, 0x80050080);
        return;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lbu         $v0, 0x48($s1)
    ctx->r2 = MEM_BU(0X48, ctx->r17);
    // nop

    // bne         $v0, $zero, L_8004FE50
    if (ctx->r2 != 0) {
        // addiu       $v0, $s3, -0x1
        ctx->r2 = ADD32(ctx->r19, -0X1);
        goto L_8004FE50;
    }
    // addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // j           L_8004FE54
    // sb          $zero, 0x50($s2)
    MEM_B(0X50, ctx->r18) = 0;
    goto L_8004FE54;
    // sb          $zero, 0x50($s2)
    MEM_B(0X50, ctx->r18) = 0;
L_8004FE50:
    // sb          $v0, 0x50($s2)
    MEM_B(0X50, ctx->r18) = ctx->r2;
L_8004FE54:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jal         0x8004EE00
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    sub_8004EE00(rdram, ctx);
    goto after_0;
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    after_0:
    // addiu       $v0, $zero, 0x70
    ctx->r2 = ADD32(0, 0X70);
    // sb          $v0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(0X1, ctx->r18);
    // lhu         $v1, 0xA($s1)
    ctx->r3 = MEM_HU(0XA, ctx->r17);
    // sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x85
    ctx->r2 = ADD32(0, 0X85);
    // beq         $v1, $v0, L_8004FE98
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x88
        ctx->r2 = ADD32(0, 0X88);
        goto L_8004FE98;
    }
    // addiu       $v0, $zero, 0x88
    ctx->r2 = ADD32(0, 0X88);
    // bne         $v1, $v0, L_8004FEA0
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x400
        ctx->r2 = ADD32(0, 0X400);
        goto L_8004FEA0;
    }
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // sh          $v0, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r2;
    // j           L_8004FE9C
    // addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    goto L_8004FE9C;
    // addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
L_8004FE98:
    // addiu       $v0, $zero, -0xDC
    ctx->r2 = ADD32(0, -0XDC);
L_8004FE9C:
    // sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
L_8004FEA0:
    // beq         $s4, $zero, L_8004FEB0
    if (ctx->r20 == 0) {
        // addiu       $v0, $zero, 0x80
        ctx->r2 = ADD32(0, 0X80);
        goto L_8004FEB0;
    }
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // j           L_8004FEB4
    // sb          $zero, 0x2($s1)
    MEM_B(0X2, ctx->r17) = 0;
    goto L_8004FEB4;
    // sb          $zero, 0x2($s1)
    MEM_B(0X2, ctx->r17) = 0;
L_8004FEB0:
    // sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
L_8004FEB4:
    // addiu       $a0, $s2, 0x34
    ctx->r4 = ADD32(ctx->r18, 0X34);
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // jal         0x8004A078
    // addiu       $a2, $s1, 0x24
    ctx->r6 = ADD32(ctx->r17, 0X24);
    sub_8004A078(rdram, ctx);
    goto after_1;
    // addiu       $a2, $s1, 0x24
    ctx->r6 = ADD32(ctx->r17, 0X24);
    after_1:
    // lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(0X24, ctx->r17);
    // lw          $v1, 0x24($s2)
    ctx->r3 = MEM_W(0X24, ctx->r18);
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
;}
