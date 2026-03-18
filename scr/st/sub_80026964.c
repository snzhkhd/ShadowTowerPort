#include "recomp.h"
#include "disable_warnings.h"

void sub_80026964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addiu       $a3, $v0, 0x7F14
    ctx->r7 = ADD32(ctx->r2, 0X7F14);
    // lwl         $v1, 0x3($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r7);
    // lwr         $v1, 0x0($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r7);
    // nop

    // swl         $v1, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r3);
    // swr         $v1, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r3);
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) << 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0xC0C
    ctx->r2 = ADD32(ctx->r2, -0XC0C);
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_80026A68
    if (ctx->r3 == ctx->r2) {
        // addiu       $s3, $zero, 0x60
        ctx->r19 = ADD32(0, 0X60);
        goto L_80026A68;
    }
    // addiu       $s3, $zero, 0x60
    ctx->r19 = ADD32(0, 0X60);
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // addiu       $s0, $s1, 0x1
    ctx->r16 = ADD32(ctx->r17, 0X1);
L_800269CC:
    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // beq         $v0, $zero, L_80026A3C
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x4
        ctx->r2 = ctx->r3 & 0X4;
        goto L_80026A3C;
    }
    // andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // beq         $v0, $zero, L_800269E8
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x8
        ctx->r2 = ctx->r3 & 0X8;
        goto L_800269E8;
    }
    // andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // j           L_80026A04
    // sb          $zero, 0x12($sp)
    MEM_B(0X12, ctx->r29) = 0;
    goto L_80026A04;
    // sb          $zero, 0x12($sp)
    MEM_B(0X12, ctx->r29) = 0;
L_800269E8:
    // beq         $v0, $zero, L_800269FC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800269FC;
    }
    // nop

    // sb          $zero, 0x11($sp)
    MEM_B(0X11, ctx->r29) = 0;
    // j           L_80026A04
    // sb          $zero, 0x12($sp)
    MEM_B(0X12, ctx->r29) = 0;
    goto L_80026A04;
    // sb          $zero, 0x12($sp)
    MEM_B(0X12, ctx->r29) = 0;
L_800269FC:
    // sb          $s3, 0x11($sp)
    MEM_B(0X11, ctx->r29) = ctx->r19;
    // sb          $s3, 0x12($sp)
    MEM_B(0X12, ctx->r29) = ctx->r19;
L_80026A04:
    // lhu         $v0, 0x9($s0)
    ctx->r2 = MEM_HU(0X9, ctx->r16);
    // nop

    // beq         $v0, $s2, L_80026A28
    if (ctx->r2 == ctx->r18) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_80026A28;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(0X0, ctx->r16);
    // jal         0x80025E00
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    sub_80025E00(rdram, ctx);
    goto after_0;
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_0:
    // j           L_80026A58
    // addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    goto L_80026A58;
    // addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_80026A28:
    // lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(0X0, ctx->r16);
    // jal         0x80025C24
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    sub_80025C24(rdram, ctx);
    goto after_1;
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_1:
    // j           L_80026A58
    // addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    goto L_80026A58;
    // addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_80026A3C:
    // andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // beq         $v0, $zero, L_80026A54
    if (ctx->r2 == 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_80026A54;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(0X0, ctx->r16);
    // jal         0x80026020
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    sub_80026020(rdram, ctx);
    goto after_2;
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_2:
L_80026A54:
    // addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_80026A58:
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // nop

    // bne         $v1, $s2, L_800269CC
    if (ctx->r3 != ctx->r18) {
        // addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
        goto L_800269CC;
    }
    // addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_80026A68:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
