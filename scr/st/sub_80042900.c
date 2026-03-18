#include "recomp.h"
#include "disable_warnings.h"

void sub_80042900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a0, $v0, -0x2E80
    ctx->r4 = ADD32(ctx->r2, -0X2E80);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lbu         $v1, 0x14($a0)
    ctx->r3 = MEM_BU(0X14, ctx->r4);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_80042968
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80042968;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sb          $zero, 0x14($a0)
    MEM_B(0X14, ctx->r4) = 0;
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(0X130, ctx->r4);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_80042968
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80042968;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lhu         $v1, 0x40($a0)
    ctx->r3 = MEM_HU(0X40, ctx->r4);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_80042964
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80042964;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80042620
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    sub_80042620(rdram, ctx);
    goto after_0;
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // jal         0x8003D030
    // nop

    sub_8003D030(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_80042964:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_80042968:
    // addiu       $a0, $v0, -0x2E80
    ctx->r4 = ADD32(ctx->r2, -0X2E80);
    // lbu         $v1, 0x14($a0)
    ctx->r3 = MEM_BU(0X14, ctx->r4);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // bne         $v1, $v0, L_800429BC
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_800429BC;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sb          $zero, 0x14($a0)
    MEM_B(0X14, ctx->r4) = 0;
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lw          $v1, 0x130($a0)
    ctx->r3 = MEM_W(0X130, ctx->r4);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_800429BC
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_800429BC;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lhu         $v1, 0x5A($a0)
    ctx->r3 = MEM_HU(0X5A, ctx->r4);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_800429B8
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_800429B8;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // jal         0x80042620
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    sub_80042620(rdram, ctx);
    goto after_2;
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // jal         0x8003D030
    // nop

    sub_8003D030(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_800429B8:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_800429BC:
    // addiu       $a0, $v0, -0x2E80
    ctx->r4 = ADD32(ctx->r2, -0X2E80);
    // lbu         $v1, 0x14($a0)
    ctx->r3 = MEM_BU(0X14, ctx->r4);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // bne         $v1, $v0, L_800429F8
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_800429F8;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x6F56($v0)
    ctx->r2 = MEM_HU(-0X6F56, ctx->r2);
    // nop

    // sltiu       $v0, $v0, 0x1400
    ctx->r2 = ctx->r2 < 0X1400 ? 1 : 0;
    // bne         $v0, $zero, L_800429F4
    if (ctx->r2 != 0) {
        // sb          $zero, 0x14($a0)
        MEM_B(0X14, ctx->r4) = 0;
        goto L_800429F4;
    }
    // sb          $zero, 0x14($a0)
    MEM_B(0X14, ctx->r4) = 0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x8003F670
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    sub_8003F670(rdram, ctx);
    goto after_4;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_4:
L_800429F4:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_800429F8:
    // addiu       $a0, $v0, -0x2E80
    ctx->r4 = ADD32(ctx->r2, -0X2E80);
    // lbu         $v1, 0x14($a0)
    ctx->r3 = MEM_BU(0X14, ctx->r4);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bne         $v1, $v0, L_80042A34
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80042A34;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x6F56($v0)
    ctx->r2 = MEM_HU(-0X6F56, ctx->r2);
    // nop

    // sltiu       $v0, $v0, 0x1400
    ctx->r2 = ctx->r2 < 0X1400 ? 1 : 0;
    // bne         $v0, $zero, L_80042A30
    if (ctx->r2 != 0) {
        // sb          $zero, 0x14($a0)
        MEM_B(0X14, ctx->r4) = 0;
        goto L_80042A30;
    }
    // sb          $zero, 0x14($a0)
    MEM_B(0X14, ctx->r4) = 0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x8003F670
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sub_8003F670(rdram, ctx);
    goto after_5;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_80042A30:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80042A34:
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v0, 0x155($s0)
    ctx->r2 = MEM_BU(0X155, ctx->r16);
    // addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // beq         $v0, $s1, L_80042AA4
    if (ctx->r2 == ctx->r17) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80042AA4;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, 0x15B($s0)
    ctx->r2 = MEM_BU(0X15B, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sb          $v0, 0x15B($s0)
    MEM_B(0X15B, ctx->r16) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // bne         $v0, $zero, L_80042AA4
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80042AA4;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $a0, 0x155($s0)
    ctx->r4 = MEM_BU(0X155, ctx->r16);
    // jal         0x8003F910
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_8003F910(rdram, ctx);
    goto after_6;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_6:
    // lbu         $v0, 0x157($s0)
    ctx->r2 = MEM_BU(0X157, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sb          $v0, 0x157($s0)
    MEM_B(0X157, ctx->r16) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // bne         $v0, $zero, L_80042A94
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80042A94;
    }
    // nop

    // j           L_80042AA0
    // sb          $s1, 0x155($s0)
    MEM_B(0X155, ctx->r16) = ctx->r17;
    goto L_80042AA0;
    // sb          $s1, 0x155($s0)
    MEM_B(0X155, ctx->r16) = ctx->r17;
L_80042A94:
    // lbu         $v0, 0x159($s0)
    ctx->r2 = MEM_BU(0X159, ctx->r16);
    // nop

    // sb          $v0, 0x15B($s0)
    MEM_B(0X15B, ctx->r16) = ctx->r2;
L_80042AA0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80042AA4:
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v0, 0x156($s0)
    ctx->r2 = MEM_BU(0X156, ctx->r16);
    // addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // beq         $v0, $s1, L_80042B14
    if (ctx->r2 == ctx->r17) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80042B14;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(0X15C, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sb          $v0, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // bne         $v0, $zero, L_80042B14
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80042B14;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $a0, 0x156($s0)
    ctx->r4 = MEM_BU(0X156, ctx->r16);
    // jal         0x8003F910
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sub_8003F910(rdram, ctx);
    goto after_7;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // lbu         $v0, 0x158($s0)
    ctx->r2 = MEM_BU(0X158, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sb          $v0, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r2;
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // bne         $v0, $zero, L_80042B04
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80042B04;
    }
    // nop

    // j           L_80042B10
    // sb          $s1, 0x156($s0)
    MEM_B(0X156, ctx->r16) = ctx->r17;
    goto L_80042B10;
    // sb          $s1, 0x156($s0)
    MEM_B(0X156, ctx->r16) = ctx->r17;
L_80042B04:
    // lbu         $v0, 0x15A($s0)
    ctx->r2 = MEM_BU(0X15A, ctx->r16);
    // nop

    // sb          $v0, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r2;
L_80042B10:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80042B14:
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v1, 0x218($a0)
    ctx->r3 = MEM_BU(0X218, ctx->r4);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_80042B84
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80042B84;
    }
    // nop

    // lbu         $v0, 0x187($a0)
    ctx->r2 = MEM_BU(0X187, ctx->r4);
    // nop

    // bne         $v0, $zero, L_80042B60
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80042B60;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x2E80
    ctx->r2 = ADD32(ctx->r2, -0X2E80);
    // lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(0X4, ctx->r2);
    // lhu         $v0, 0x32($v0)
    ctx->r2 = MEM_HU(0X32, ctx->r2);
    // nop

    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // beq         $v1, $zero, L_80042B5C
    if (ctx->r3 == 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80042B5C;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x8003F4EC
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    sub_8003F4EC(rdram, ctx);
    goto after_8;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_8:
L_80042B5C:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_80042B60:
    // addiu       $v0, $v0, -0x2E80
    ctx->r2 = ADD32(ctx->r2, -0X2E80);
    // lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(0X4, ctx->r2);
    // lhu         $v0, 0x34($v0)
    ctx->r2 = MEM_HU(0X34, ctx->r2);
    // nop

    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // beq         $v1, $zero, L_80042B84
    if (ctx->r3 == 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80042B84;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x8003F4EC
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sub_8003F4EC(rdram, ctx);
    goto after_9;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_80042B84:
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
