#include "recomp.h"
#include "disable_warnings.h"

void sub_80042D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // sw          $ra, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r31;
    // sw          $s4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r20;
    // sw          $s3, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r19;
    // sw          $s2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r18;
    // sw          $s1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r17;
    // jal         0x8003C24C
    // sw          $s0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r16;
    sub_8003C24C(rdram, ctx);
    goto after_0;
    // sw          $s0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r16;
    after_0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v1, -0x6EC0($v0)
    ctx->r3 = MEM_BU(-0X6EC0, ctx->r2);
    // nop

    // beq         $v1, $zero, L_80042DC4
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_80042DC4;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_80042DC4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
        goto L_80042DC4;
    }
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // beq         $v1, $v0, L_80042DC4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80042DC4;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_800443C8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800443C8;
    }
    // nop

L_80042DC4:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v1, $v0, -0x2E80
    ctx->r3 = ADD32(ctx->r2, -0X2E80);
    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_80042DF0
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80042DF0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v1, 0x14($v1)
    ctx->r3 = MEM_BU(0X14, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80043174
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80043174;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80042DF0:
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lw          $a1, 0x130($a0)
    ctx->r5 = MEM_W(0X130, ctx->r4);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $a1, $v0, L_80043174
    if (ctx->r5 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80043174;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v1, 0x218($a0)
    ctx->r3 = MEM_BU(0X218, ctx->r4);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // beq         $v1, $a2, L_80043170
    if (ctx->r3 == ctx->r6) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_80043170;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_80043174
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80043174;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(0X2C, ctx->r4);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // bne         $v0, $zero, L_80043174
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80043174;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lh          $v1, 0x5920($v0)
    ctx->r3 = MEM_HS(0X5920, ctx->r2);
    // nop

    // bne         $v1, $zero, L_80043170
    if (ctx->r3 != 0) {
        // addiu       $a0, $v0, 0x5920
        ctx->r4 = ADD32(ctx->r2, 0X5920);
        goto L_80043170;
    }
    // addiu       $a0, $v0, 0x5920
    ctx->r4 = ADD32(ctx->r2, 0X5920);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lbu         $v0, 0x2A1($v0)
    ctx->r2 = MEM_BU(0X2A1, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80043174
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80043174;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(0X18, ctx->r4);
    // nop

    // bne         $v0, $a1, L_80043174
    if (ctx->r2 != ctx->r5) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80043174;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // jal         0x80057CC8
    // sb          $a2, -0x4926($v0)
    MEM_B(-0X4926, ctx->r2) = ctx->r6;
    sub_80057CC8(rdram, ctx);
    goto after_1;
    // sb          $a2, -0x4926($v0)
    MEM_B(-0X4926, ctx->r2) = ctx->r6;
    after_1:
    // jal         0x80042CFC
    // addiu       $s2, $zero, 0xEF
    ctx->r18 = ADD32(0, 0XEF);
    sub_80042CFC(rdram, ctx);
    goto after_2;
    // addiu       $s2, $zero, 0xEF
    ctx->r18 = ADD32(0, 0XEF);
    after_2:
    // jal         0x80057A3C
    // addiu       $s4, $zero, 0xEC
    ctx->r20 = ADD32(0, 0XEC);
    sub_80057A3C(rdram, ctx);
    goto after_3;
    // addiu       $s4, $zero, 0xEC
    ctx->r20 = ADD32(0, 0XEC);
    after_3:
    // jal         0x80057A68
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80057A68(rdram, ctx);
    goto after_4;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x2230
    ctx->r2 = ADD32(ctx->r2, 0X2230);
    // addiu       $s0, $v0, 0x54
    ctx->r16 = ADD32(ctx->r2, 0X54);
L_80042EA0:
    // lbu         $v0, -0x4F($s0)
    ctx->r2 = MEM_BU(-0X4F, ctx->r16);
    // nop

    // bne         $v0, $s4, L_80042ED0
    if (ctx->r2 != ctx->r20) {
        // nop
    
        goto L_80042ED0;
    }
    // nop

    // lh          $a0, 0x0($s0)
    ctx->r4 = MEM_HS(0X0, ctx->r16);
    // nop

    // beq         $a0, $s3, L_80042ED0
    if (ctx->r4 == ctx->r19) {
        // nop
    
        goto L_80042ED0;
    }
    // nop

    // lbu         $a1, -0xA($s0)
    ctx->r5 = MEM_BU(-0XA, ctx->r16);
    // jal         0x8005850C
    // addiu       $a1, $a1, 0x454
    ctx->r5 = ADD32(ctx->r5, 0X454);
    sub_8005850C(rdram, ctx);
    goto after_5;
    // addiu       $a1, $a1, 0x454
    ctx->r5 = ADD32(ctx->r5, 0X454);
    after_5:
    // sh          $s3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r19;
L_80042ED0:
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // bne         $s2, $s3, L_80042EA0
    if (ctx->r18 != ctx->r19) {
        // addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
        goto L_80042EA0;
    }
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // sb          $zero, 0x21D($s0)
    MEM_B(0X21D, ctx->r16) = 0;
    // sb          $zero, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = 0;
    // jal         0x80058EF4
    // sb          $zero, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = 0;
    sub_80058EF4(rdram, ctx);
    goto after_6;
    // sb          $zero, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = 0;
    after_6:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v0, -0x2EDD($v0)
    ctx->r2 = MEM_BU(-0X2EDD, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80042F10
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80042F10;
    }
    // nop

    // jal         0x8003E840
    // nop

    sub_8003E840(rdram, ctx);
    goto after_7;
    // nop

    after_7:
L_80042F10:
    // lbu         $v0, 0x2A($s0)
    ctx->r2 = MEM_BU(0X2A, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8004301C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004301C;
    }
    // nop

    // jal         0x8003E840
    // nop

    sub_8003E840(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jal         0x80016508
    // sb          $v0, -0x2E70($v1)
    MEM_B(-0X2E70, ctx->r3) = ctx->r2;
    sub_80016508(rdram, ctx);
    goto after_10;
    // sb          $v0, -0x2E70($v1)
    MEM_B(-0X2E70, ctx->r3) = ctx->r2;
    after_10:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $zero, 0x2DC($s0)
    MEM_H(0X2DC, ctx->r16) = 0;
    // sh          $zero, 0x2DA($s0)
    MEM_H(0X2DA, ctx->r16) = 0;
    // sh          $zero, 0x2D8($s0)
    MEM_H(0X2D8, ctx->r16) = 0;
    // jal         0x800500AC
    // sh          $zero, 0x2D6($s0)
    MEM_H(0X2D6, ctx->r16) = 0;
    sub_800500AC(rdram, ctx);
    goto after_11;
    // sh          $zero, 0x2D6($s0)
    MEM_H(0X2D6, ctx->r16) = 0;
    after_11:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x800500AC
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_800500AC(rdram, ctx);
    goto after_12;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_12:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // jal         0x8003C0E0
    // nop

    sub_8003C0E0(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x5EC8
    ctx->r2 = ADD32(ctx->r2, -0X5EC8);
    // addiu       $v1, $zero, 0xFE
    ctx->r3 = ADD32(0, 0XFE);
    // sb          $v1, 0x6168($v0)
    MEM_B(0X6168, ctx->r2) = ctx->r3;
    // addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // sh          $v1, 0x615E($v0)
    MEM_H(0X615E, ctx->r2) = ctx->r3;
    // sh          $v1, 0x615C($v0)
    MEM_H(0X615C, ctx->r2) = ctx->r3;
    // sh          $v1, 0x615A($v0)
    MEM_H(0X615A, ctx->r2) = ctx->r3;
    // jal         0x80057A68
    // sh          $v1, 0x6158($v0)
    MEM_H(0X6158, ctx->r2) = ctx->r3;
    sub_80057A68(rdram, ctx);
    goto after_15;
    // sh          $v1, 0x6158($v0)
    MEM_H(0X6158, ctx->r2) = ctx->r3;
    after_15:
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, -0x1CE8
    ctx->r2 = ADD32(ctx->r2, -0X1CE8);
    // addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80042FC8:
    // sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bne         $v1, $a0, L_80042FC8
    if (ctx->r3 != ctx->r4) {
        // addiu       $v0, $v0, 0x58
        ctx->r2 = ADD32(ctx->r2, 0X58);
        goto L_80042FC8;
    }
    // addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // addiu       $v1, $v1, 0x5920
    ctx->r3 = ADD32(ctx->r3, 0X5920);
    // lbu         $a0, 0x4($v1)
    ctx->r4 = MEM_BU(0X4, ctx->r3);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $a3, 0x7($v1)
    ctx->r7 = MEM_BU(0X7, ctx->r3);
    // lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(0X8, ctx->r3);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // jal         0x8003C95C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8003C95C(rdram, ctx);
    goto after_16;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_16:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // jal         0x8003EAD0
    // nop

    sub_8003EAD0(rdram, ctx);
    goto after_18;
    // nop

    after_18:
    // j           L_8004315C
    // nop

    goto L_8004315C;
    // nop

L_8004301C:
    // lbu         $v0, 0x21D($s0)
    ctx->r2 = MEM_BU(0X21D, ctx->r16);
    // nop

    // beq         $v0, $zero, L_800430A8
    if (ctx->r2 == 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_800430A8;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s1, $v0, L_8004306C
    if (ctx->r17 == ctx->r2) {
        // addu        $s0, $v0, $zero
        ctx->r16 = ADD32(ctx->r2, 0);
        goto L_8004306C;
    }
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $a0, $s1, 0x80
    ctx->r4 = ADD32(ctx->r17, 0X80);
L_8004303C:
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // jal         0x80033DB8
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    sub_80033DB8(rdram, ctx);
    goto after_19;
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_19:
    // lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(0X20, ctx->r29);
    // nop

    // beq         $a0, $zero, L_80043060
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80043060;
    }
    // nop

    // jal         0x80015230
    // nop

    sub_80015230(rdram, ctx);
    goto after_20;
    // nop

    after_20:
L_80043060:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s0, L_8004303C
    if (ctx->r17 != ctx->r16) {
        // addiu       $a0, $s1, 0x80
        ctx->r4 = ADD32(ctx->r17, 0X80);
        goto L_8004303C;
    }
    // addiu       $a0, $s1, 0x80
    ctx->r4 = ADD32(ctx->r17, 0X80);
L_8004306C:
    // addiu       $s1, $zero, 0x7F
    ctx->r17 = ADD32(0, 0X7F);
    // addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // addiu       $a0, $s1, 0x24C
    ctx->r4 = ADD32(ctx->r17, 0X24C);
L_80043078:
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // jal         0x80033DB8
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    sub_80033DB8(rdram, ctx);
    goto after_21;
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_21:
    // lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(0X20, ctx->r29);
    // nop

    // beq         $a0, $zero, L_8004309C
    if (ctx->r4 == 0) {
        // nop
    
        goto L_8004309C;
    }
    // nop

    // jal         0x80015230
    // nop

    sub_80015230(rdram, ctx);
    goto after_22;
    // nop

    after_22:
L_8004309C:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s0, L_80043078
    if (ctx->r17 != ctx->r16) {
        // addiu       $a0, $s1, 0x24C
        ctx->r4 = ADD32(ctx->r17, 0X24C);
        goto L_80043078;
    }
    // addiu       $a0, $s1, 0x24C
    ctx->r4 = ADD32(ctx->r17, 0X24C);
L_800430A8:
    // jal         0x8003CB88
    // nop

    sub_8003CB88(rdram, ctx);
    goto after_23;
    // nop

    after_23:
    // jal         0x8003D030
    // nop

    sub_8003D030(rdram, ctx);
    goto after_24;
    // nop

    after_24:
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $s2, $v1, -0x2F70
    ctx->r18 = ADD32(ctx->r3, -0X2F70);
    // addu        $a2, $s2, $v0
    ctx->r6 = ADD32(ctx->r18, ctx->r2);
    // lbu         $v0, 0x6CC2($a2)
    ctx->r2 = MEM_BU(0X6CC2, ctx->r6);
    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // sh          $zero, 0x6($s2)
    MEM_H(0X6, ctx->r18) = 0;
    // sh          $zero, 0x60($s2)
    MEM_H(0X60, ctx->r18) = 0;
    // sh          $zero, 0x62($s2)
    MEM_H(0X62, ctx->r18) = 0;
    // bne         $v0, $zero, L_800430F0
    if (ctx->r2 != 0) {
        // sh          $zero, 0x18($sp)
        MEM_H(0X18, ctx->r29) = 0;
        goto L_800430F0;
    }
    // sh          $zero, 0x18($sp)
    MEM_H(0X18, ctx->r29) = 0;
    // addiu       $v1, $zero, 0xF0
    ctx->r3 = ADD32(0, 0XF0);
L_800430F0:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $s1, $zero, 0x140
    ctx->r17 = ADD32(0, 0X140);
    // sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    // sh          $s1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r17;
    // lbu         $v0, 0x6CC2($a2)
    ctx->r2 = MEM_BU(0X6CC2, ctx->r6);
    // addiu       $s0, $zero, 0xF0
    ctx->r16 = ADD32(0, 0XF0);
    // sh          $s0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r16;
    // sll         $a2, $v0, 4
    ctx->r6 = S32(ctx->r2) << 4;
    // subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // jal         0x80079DCC
    // sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6) << 4;
    MoveImage(rdram, ctx);
    goto after_25;
    // sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6) << 4;
    after_25:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ST_DrawSync(rdram, ctx);
    goto after_26;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_26:
    // jal         0x8003C24C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8003C24C(rdram, ctx);
    goto after_27;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_27:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80026AFC
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    DrawScene_80026AFC(rdram, ctx);
    goto after_28;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_28:
    // jal         0x8003C24C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8003C24C(rdram, ctx);
    goto after_29;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_29:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_30;
    // nop

    after_30:
    // sh          $s1, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r17;
    // sh          $s0, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r16;
    // sh          $s1, 0x60($s2)
    MEM_H(0X60, ctx->r18) = ctx->r17;
    // sh          $s0, 0x62($s2)
    MEM_H(0X62, ctx->r18) = ctx->r16;
L_8004315C:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_31;
    // nop

    after_31:
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, -0x4926($v1)
    MEM_B(-0X4926, ctx->r3) = ctx->r2;
L_80043170:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80043174:
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v0, 0x2B($s0)
    ctx->r2 = MEM_BU(0X2B, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80043194
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80043194;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // jal         0x80052C24
    // nop

    sub_80052C24(rdram, ctx);
    goto after_32;
    // nop

    after_32:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_80043194:
    // addiu       $s1, $v0, -0x2E80
    ctx->r17 = ADD32(ctx->r2, -0X2E80);
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // beq         $v0, $zero, L_80043238
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_80043238;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // lbu         $v1, 0x218($s0)
    ctx->r3 = MEM_BU(0X218, ctx->r16);
    // nop

    // beq         $v1, $v0, L_80043238
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80043238;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lh          $v1, 0x5920($v0)
    ctx->r3 = MEM_HS(0X5920, ctx->r2);
    // nop

    // bne         $v1, $zero, L_80043238
    if (ctx->r3 != 0) {
        // addiu       $a0, $v0, 0x5920
        ctx->r4 = ADD32(ctx->r2, 0X5920);
        goto L_80043238;
    }
    // addiu       $a0, $v0, 0x5920
    ctx->r4 = ADD32(ctx->r2, 0X5920);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lbu         $v0, 0x2A1($v0)
    ctx->r2 = MEM_BU(0X2A1, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8004323C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8004323C;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(0X18, ctx->r4);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_8004323C
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8004323C;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // addiu       $s0, $s0, -0x4930
    ctx->r16 = ADD32(ctx->r16, -0X4930);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jal         0x80057CC8
    // sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
    sub_80057CC8(rdram, ctx);
    goto after_33;
    // sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
    after_33:
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // andi        $v0, $v0, 0xFFF7
    ctx->r2 = ctx->r2 & 0XFFF7;
    // jal         0x80057A3C
    // sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
    sub_80057A3C(rdram, ctx);
    goto after_34;
    // sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
    after_34:
    // jal         0x80057A68
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80057A68(rdram, ctx);
    goto after_35;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_35:
    // jal         0x800631AC
    // nop

    sub_800631AC(rdram, ctx);
    goto after_36;
    // nop

    after_36:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_37;
    // nop

    after_37:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
L_80043238:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8004323C:
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // addiu       $v0, $zero, 0xC0
    ctx->r2 = ADD32(0, 0XC0);
    // sw          $v0, 0x2E4($a1)
    MEM_W(0X2E4, ctx->r5) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sw          $v0, 0x2E8($a1)
    MEM_W(0X2E8, ctx->r5) = ctx->r2;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x2E80
    ctx->r2 = ADD32(ctx->r2, -0X2E80);
    // lhu         $v1, 0x22($v0)
    ctx->r3 = MEM_HU(0X22, ctx->r2);
    // lhu         $a0, 0x24($v0)
    ctx->r4 = MEM_HU(0X24, ctx->r2);
    // lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(0X2, ctx->r2);
    // or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_80043278
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x28
        ctx->r2 = ADD32(0, 0X28);
        goto L_80043278;
    }
    // addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // sw          $v0, 0x2E8($a1)
    MEM_W(0X2E8, ctx->r5) = ctx->r2;
L_80043278:
    // lh          $v0, 0x19C($a1)
    ctx->r2 = MEM_HS(0X19C, ctx->r5);
    // nop

    // beq         $v0, $zero, L_8004328C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x60
        ctx->r2 = ADD32(0, 0X60);
        goto L_8004328C;
    }
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sw          $v0, 0x2E4($a1)
    MEM_W(0X2E4, ctx->r5) = ctx->r2;
L_8004328C:
    // lhu         $v0, 0x194($a1)
    ctx->r2 = MEM_HU(0X194, ctx->r5);
    // nop

    // sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2) << 16;
    // sra         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6) >> 16;
    // beq         $a0, $zero, L_80043304
    if (ctx->r4 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80043304;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, 0x2C($a1)
    ctx->r2 = MEM_W(0X2C, ctx->r5);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_800432BC
    if (ctx->r2 == 0) {
        // sw          $zero, 0x2E4($a1)
        MEM_W(0X2E4, ctx->r5) = 0;
        goto L_800432BC;
    }
    // sw          $zero, 0x2E4($a1)
    MEM_W(0X2E4, ctx->r5) = 0;
    // sw          $zero, 0x2E8($a1)
    MEM_W(0X2E8, ctx->r5) = 0;
L_800432BC:
    // lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $a2, 31
    ctx->r2 = S32(ctx->r6) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v1, $t2, 3
    ctx->r3 = S32(ctx->r10) >> 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bne         $v0, $zero, L_80043304
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80043304;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // jal         0x800582F0
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    sub_800582F0(rdram, ctx);
    goto after_38;
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_38:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80043304:
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, 0x22($a1)
    ctx->r3 = MEM_HU(0X22, ctx->r5);
    // lhu         $v0, 0x24($a1)
    ctx->r2 = MEM_HU(0X24, ctx->r5);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_8004335C
    if (ctx->r2 == 0) {
        // lui         $a0, 0x6666
        ctx->r4 = S32(0X6666 << 16);
        goto L_8004335C;
    }
    // lui         $a0, 0x6666
    ctx->r4 = S32(0X6666 << 16);
    // lhu         $v0, 0x24($a1)
    ctx->r2 = MEM_HU(0X24, ctx->r5);
    // ori         $a0, $a0, 0x6667
    ctx->r4 = ctx->r4 | 0X6667;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // lw          $a0, 0x2E4($a1)
    ctx->r4 = MEM_W(0X2E4, ctx->r5);
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10) >> 1;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // bgez        $a0, L_80043358
    if (SIGNED(ctx->r4) >= 0) {
        // nop
    
        goto L_80043358;
    }
    // nop

    // j           L_8004335C
    // sw          $zero, 0x2E4($a1)
    MEM_W(0X2E4, ctx->r5) = 0;
    goto L_8004335C;
    // sw          $zero, 0x2E4($a1)
    MEM_W(0X2E4, ctx->r5) = 0;
L_80043358:
    // sw          $a0, 0x2E4($a1)
    MEM_W(0X2E4, ctx->r5) = ctx->r4;
L_8004335C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v1, -0x6EC0($v0)
    ctx->r3 = MEM_BU(-0X6EC0, ctx->r2);
    // nop

    // sltiu       $v0, $v1, 0x11
    ctx->r2 = ctx->r3 < 0X11 ? 1 : 0;
    // beq         $v0, $zero, L_80043C8C
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_80043C8C;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x1EBC
    ctx->r2 = ADD32(ctx->r2, 0X1EBC);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_80043388;
    jr_addend_80043388 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80043388 >> 2) {
        case 0: goto L_80043390; break;
        case 1: goto L_80043490; break;
        case 2: goto L_80043C8C; break;
        case 3: goto L_80043C8C; break;
        case 4: goto L_80043848; break;
        case 5: goto L_80043C34; break;
        case 6: goto L_80043C34; break;
        case 7: goto L_80043C8C; break;
        case 8: goto L_80043C8C; break;
        case 9: goto L_80043C8C; break;
        case 10: goto L_80043C8C; break;
        case 11: goto L_80043C8C; break;
        case 12: goto L_80043C8C; break;
        case 13: goto L_80043C8C; break;
        case 14: goto L_80043C8C; break;
        case 15: goto L_80043C8C; break;
        case 16: goto L_80043BCC; break;
        default: switch_error(__func__, 0x80043388, 0x80011EBC);
    }
    // nop

L_80043390:
    // jal         0x80042900
    // nop

    sub_80042900(rdram, ctx);
    goto after_39;
    // nop

    after_39:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lh          $v1, 0x5920($v0)
    ctx->r3 = MEM_HS(0X5920, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_80043C24
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_80043C24;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lbu         $v0, 0x2A1($v0)
    ctx->r2 = MEM_BU(0X2A1, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80043C24
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80043C24;
    }
    // nop

    // jal         0x80041D4C
    // nop

    sub_80041D4C(rdram, ctx);
    goto after_40;
    // nop

    after_40:
    // jal         0x800420A0
    // nop

    sub_800420A0(rdram, ctx);
    goto after_41;
    // nop

    after_41:
    // jal         0x8004162C
    // nop

    sub_8004162C(rdram, ctx);
    goto after_42;
    // nop

    after_42:
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a1, $v0, -0x2E80
    ctx->r5 = ADD32(ctx->r2, -0X2E80);
    // lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(0X4, ctx->r5);
    // lhu         $v1, 0x38($a1)
    ctx->r3 = MEM_HU(0X38, ctx->r5);
    // addiu       $a0, $a0, -0x70D8
    ctx->r4 = ADD32(ctx->r4, -0X70D8);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_80043C24
    if (ctx->r2 == 0) {
        // sb          $zero, 0x21E($a0)
        MEM_B(0X21E, ctx->r4) = 0;
        goto L_80043C24;
    }
    // sb          $zero, 0x21E($a0)
    MEM_B(0X21E, ctx->r4) = 0;
    // lbu         $v0, 0x12($a1)
    ctx->r2 = MEM_BU(0X12, ctx->r5);
    // nop

    // bne         $v0, $zero, L_80043C24
    if (ctx->r2 != 0) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80043C24;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lhu         $v1, 0x42($a0)
    ctx->r3 = MEM_HU(0X42, ctx->r4);
    // nop

    // bne         $v1, $v0, L_80043458
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80043458;
    }
    // nop

    // lhu         $v0, 0x5E($a0)
    ctx->r2 = MEM_HU(0X5E, ctx->r4);
    // nop

    // bne         $v0, $v1, L_80043458
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_80043458;
    }
    // nop

    // lhu         $v1, 0x4E($a0)
    ctx->r3 = MEM_HU(0X4E, ctx->r4);
    // nop

    // bne         $v1, $v0, L_80043458
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80043458;
    }
    // nop

    // lhu         $a1, 0x60($a0)
    ctx->r5 = MEM_HU(0X60, ctx->r4);
    // nop

    // bne         $a1, $v1, L_80043458
    if (ctx->r5 != ctx->r3) {
        // nop
    
        goto L_80043458;
    }
    // nop

    // lhu         $v0, 0x5C($a0)
    ctx->r2 = MEM_HU(0X5C, ctx->r4);
    // nop

    // beq         $v0, $a1, L_80043C24
    if (ctx->r2 == ctx->r5) {
        // nop
    
        goto L_80043C24;
    }
    // nop

L_80043458:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_43;
    // nop

    after_43:
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // addiu       $a0, $a0, -0x2E80
    ctx->r4 = ADD32(ctx->r4, -0X2E80);
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(0X4, ctx->r4);
    // lhu         $a1, 0x38($a0)
    ctx->r5 = MEM_HU(0X38, ctx->r4);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, -0x6EC0($a2)
    MEM_B(-0X6EC0, ctx->r6) = ctx->r2;
    // and         $v1, $v1, $a1
    ctx->r3 = ctx->r3 & ctx->r5;
    // jal         0x80057A3C
    // sh          $v1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r3;
    sub_80057A3C(rdram, ctx);
    goto after_44;
    // sh          $v1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r3;
    after_44:
    // j           L_80043C24
    // nop

    goto L_80043C24;
    // nop

L_80043490:
    // jal         0x80042900
    // nop

    sub_80042900(rdram, ctx);
    goto after_45;
    // nop

    after_45:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lh          $v1, 0x5920($v0)
    ctx->r3 = MEM_HS(0X5920, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_80043C24
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_80043C24;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lbu         $v0, 0x2A1($v0)
    ctx->r2 = MEM_BU(0X2A1, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80043C24
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80043C24;
    }
    // nop

    // jal         0x80041D4C
    // nop

    sub_80041D4C(rdram, ctx);
    goto after_46;
    // nop

    after_46:
    // jal         0x800420A0
    // nop

    sub_800420A0(rdram, ctx);
    goto after_47;
    // nop

    after_47:
    // jal         0x8004162C
    // nop

    sub_8004162C(rdram, ctx);
    goto after_48;
    // nop

    after_48:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $s0, $v1, -0x2E80
    ctx->r16 = ADD32(ctx->r3, -0X2E80);
    // lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(0X4, ctx->r16);
    // lhu         $v1, 0x32($s0)
    ctx->r3 = MEM_HU(0X32, ctx->r16);
    // addiu       $s1, $v0, -0x70D8
    ctx->r17 = ADD32(ctx->r2, -0X70D8);
    // and         $v1, $a0, $v1
    ctx->r3 = ctx->r4 & ctx->r3;
    // beq         $v1, $zero, L_8004353C
    if (ctx->r3 == 0) {
        // sb          $zero, 0x21E($s1)
        MEM_B(0X21E, ctx->r17) = 0;
        goto L_8004353C;
    }
    // sb          $zero, 0x21E($s1)
    MEM_B(0X21E, ctx->r17) = 0;
    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_49;
    // nop

    after_49:
    // lhu         $a0, 0x32($s0)
    ctx->r4 = MEM_HU(0X32, ctx->r16);
    // lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(0X4, ctx->r16);
    // lbu         $v0, 0x15E($s1)
    ctx->r2 = MEM_BU(0X15E, ctx->r17);
    // nor         $a0, $zero, $a0
    ctx->r4 = ~(0 | ctx->r4);
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    // sb          $v0, 0x15E($s1)
    MEM_B(0X15E, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80043C24
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80043C24;
    }
    // nop

    // j           L_80043C24
    // sb          $zero, 0x15E($s1)
    MEM_B(0X15E, ctx->r17) = 0;
    goto L_80043C24;
    // sb          $zero, 0x15E($s1)
    MEM_B(0X15E, ctx->r17) = 0;
L_8004353C:
    // lhu         $v0, 0x34($s0)
    ctx->r2 = MEM_HU(0X34, ctx->r16);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_8004358C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004358C;
    }
    // nop

    // jal         0x80057D10
    // nop

    sub_80057D10(rdram, ctx);
    goto after_50;
    // nop

    after_50:
    // lhu         $v0, 0x34($s0)
    ctx->r2 = MEM_HU(0X34, ctx->r16);
    // lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(0X4, ctx->r16);
    // lbu         $a0, 0x15E($s1)
    ctx->r4 = MEM_BU(0X15E, ctx->r17);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    // sb          $a0, 0x15E($s1)
    MEM_B(0X15E, ctx->r17) = ctx->r4;
    // sll         $a0, $a0, 24
    ctx->r4 = S32(ctx->r4) << 24;
    // bgez        $a0, L_80043C24
    if (SIGNED(ctx->r4) >= 0) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_80043C24;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // j           L_80043C24
    // sb          $v0, 0x15E($s1)
    MEM_B(0X15E, ctx->r17) = ctx->r2;
    goto L_80043C24;
    // sb          $v0, 0x15E($s1)
    MEM_B(0X15E, ctx->r17) = ctx->r2;
L_8004358C:
    // lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(0X38, ctx->r16);
    // nop

    // and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // beq         $v0, $zero, L_800435E4
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_800435E4;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(0X12, ctx->r16);
    // nop

    // bne         $v0, $zero, L_800435E4
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_800435E4;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_51;
    // nop

    after_51:
    // lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(0X38, ctx->r16);
    // sb          $zero, 0x218($s1)
    MEM_B(0X218, ctx->r17) = 0;
    // lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(0X4, ctx->r16);
    // lhu         $a0, 0x36($s0)
    ctx->r4 = MEM_HU(0X36, ctx->r16);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // nor         $a0, $zero, $a0
    ctx->r4 = ~(0 | ctx->r4);
    // sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // j           L_80043838
    // sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    goto L_80043838;
    // sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
L_800435E4:
    // addiu       $a3, $v0, -0x2E80
    ctx->r7 = ADD32(ctx->r2, -0X2E80);
    // lhu         $v0, 0x4($a3)
    ctx->r2 = MEM_HU(0X4, ctx->r7);
    // lhu         $v1, 0x36($a3)
    ctx->r3 = MEM_HU(0X36, ctx->r7);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_80043C24
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80043C24;
    }
    // nop

    // lbu         $v0, 0x12($a3)
    ctx->r2 = MEM_BU(0X12, ctx->r7);
    // nop

    // bne         $v0, $zero, L_80043C24
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80043C24;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s1, $v0, -0x70D8
    ctx->r17 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v0, 0x42($s1)
    ctx->r2 = MEM_HU(0X42, ctx->r17);
    // lhu         $v1, 0x5E($s1)
    ctx->r3 = MEM_HU(0X5E, ctx->r17);
    // lhu         $a0, 0x4E($s1)
    ctx->r4 = MEM_HU(0X4E, ctx->r17);
    // lhu         $a1, 0x60($s1)
    ctx->r5 = MEM_HU(0X60, ctx->r17);
    // lhu         $a2, 0x5C($s1)
    ctx->r6 = MEM_HU(0X5C, ctx->r17);
    // sb          $zero, 0x218($s1)
    MEM_B(0X218, ctx->r17) = 0;
    // sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // lhu         $v1, 0x32($a3)
    ctx->r3 = MEM_HU(0X32, ctx->r7);
    // lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(0X40, ctx->r29);
    // lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(0X44, ctx->r29);
    // lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(0X48, ctx->r29);
    // lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(0X4C, ctx->r29);
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(0X50, ctx->r29);
    // nop

    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x4($a3)
    ctx->r2 = MEM_HU(0X4, ctx->r7);
    // lhu         $a0, 0x38($a3)
    ctx->r4 = MEM_HU(0X38, ctx->r7);
    // nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // nor         $a0, $zero, $a0
    ctx->r4 = ~(0 | ctx->r4);
    // sh          $v0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r2;
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // lhu         $v1, 0x34($a3)
    ctx->r3 = MEM_HU(0X34, ctx->r7);
    // lhu         $a0, 0x36($a3)
    ctx->r4 = MEM_HU(0X36, ctx->r7);
    // addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // sh          $v0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r2;
    // nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // nor         $a0, $zero, $a0
    ctx->r4 = ~(0 | ctx->r4);
    // sh          $v0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r2;
    // lb          $v1, 0x15E($s1)
    ctx->r3 = MEM_BS(0X15E, ctx->r17);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sh          $v0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r2;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $a0, $v1, $s0
    ctx->r4 = ADD32(ctx->r3, ctx->r16);
    // lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(0X10, ctx->r4);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_80043830
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80043830;
    }
    // nop

    // sb          $zero, 0x2B($s1)
    MEM_B(0X2B, ctx->r17) = 0;
    // lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(0X10, ctx->r4);
    // jal         0x80054A54
    // nop

    sub_80054A54(rdram, ctx);
    goto after_52;
    // nop

    after_52:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lw          $v1, -0x2F20($v0)
    ctx->r3 = MEM_W(-0X2F20, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80043828
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_80043828;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_53;
    // nop

    after_53:
    // lb          $v0, 0x15E($s1)
    ctx->r2 = MEM_BS(0X15E, ctx->r17);
    // nop

    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(0X10, ctx->r2);
    // addiu       $v0, $zero, 0x120
    ctx->r2 = ADD32(0, 0X120);
    // bne         $v1, $v0, L_80043724
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80043724;
    }
    // nop

    // jal         0x8005A3A8
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8005A3A8(rdram, ctx);
    goto after_54;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_54:
L_80043724:
    // lb          $v0, 0x15E($s1)
    ctx->r2 = MEM_BS(0X15E, ctx->r17);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(0X10, ctx->r2);
    // addiu       $v1, $v1, 0x7590
    ctx->r3 = ADD32(ctx->r3, 0X7590);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // bne         $v0, $zero, L_80043838
    if (ctx->r2 != 0) {
        // lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
        goto L_80043838;
    }
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lb          $a3, 0x15E($s1)
    ctx->r7 = MEM_BS(0X15E, ctx->r17);
    // addiu       $a2, $v0, -0x7FAC
    ctx->r6 = ADD32(ctx->r2, -0X7FAC);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r3);
    // swr         $v1, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r3);
    // swl         $a0, 0x47($sp)
    do_swl(rdram, 0X47, ctx->r29, ctx->r4);
    // swr         $a0, 0x44($sp)
    do_swr(rdram, 0X44, ctx->r29, ctx->r4);
    // sltiu       $v0, $a3, 0x5
    ctx->r2 = ctx->r7 < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_800437F0
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_800437F0;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x1F04
    ctx->r2 = ADD32(ctx->r2, 0X1F04);
    // sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_8004379C;
    jr_addend_8004379C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8004379C >> 2) {
        case 0: goto L_800437A4; break;
        case 1: goto L_800437B4; break;
        case 2: goto L_800437C4; break;
        case 3: goto L_800437D4; break;
        case 4: goto L_800437E4; break;
        default: switch_error(__func__, 0x8004379C, 0x80011F04);
    }
    // nop

L_800437A4:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // j           L_800437F0
    // sh          $v0, -0x7096($v1)
    MEM_H(-0X7096, ctx->r3) = ctx->r2;
    goto L_800437F0;
    // sh          $v0, -0x7096($v1)
    MEM_H(-0X7096, ctx->r3) = ctx->r2;
L_800437B4:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // j           L_800437F0
    // sh          $v0, -0x707A($v1)
    MEM_H(-0X707A, ctx->r3) = ctx->r2;
    goto L_800437F0;
    // sh          $v0, -0x707A($v1)
    MEM_H(-0X707A, ctx->r3) = ctx->r2;
L_800437C4:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // j           L_800437F0
    // sh          $v0, -0x708A($v1)
    MEM_H(-0X708A, ctx->r3) = ctx->r2;
    goto L_800437F0;
    // sh          $v0, -0x708A($v1)
    MEM_H(-0X708A, ctx->r3) = ctx->r2;
L_800437D4:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // j           L_800437F0
    // sh          $v0, -0x7078($v1)
    MEM_H(-0X7078, ctx->r3) = ctx->r2;
    goto L_800437F0;
    // sh          $v0, -0x7078($v1)
    MEM_H(-0X7078, ctx->r3) = ctx->r2;
L_800437E4:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sh          $v0, -0x707C($v1)
    MEM_H(-0X707C, ctx->r3) = ctx->r2;
L_800437F0:
    // addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lb          $v1, -0x6F7A($v0)
    ctx->r3 = MEM_BS(-0X6F7A, ctx->r2);
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // jal         0x80079BE4
    // sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    ClearImage(rdram, ctx);
    goto after_55;
    // sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    after_55:
    // j           L_80043838
    // nop

    goto L_80043838;
    // nop

L_80043828:
    // bne         $v1, $v0, L_80043838
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80043838;
    }
    // nop

L_80043830:
    // jal         0x80057D34
    // nop

    sub_80057D34(rdram, ctx);
    goto after_56;
    // nop

    after_56:
L_80043838:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_57;
    // nop

    after_57:
    // j           L_80043C24
    // nop

    goto L_80043C24;
    // nop

L_80043848:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lh          $a3, 0x286($s0)
    ctx->r7 = MEM_HS(0X286, ctx->r16);
    // nop

    // slti        $v0, $a3, 0x11
    ctx->r2 = SIGNED(ctx->r7) < 0X11 ? 1 : 0;
    // beq         $v0, $zero, L_800438E0
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
        goto L_800438E0;
    }
    // addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // sll         $a3, $a3, 8
    ctx->r7 = S32(ctx->r7) << 8;
    // addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // jal         0x80021994
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    sub_80021994(rdram, ctx);
    goto after_58;
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_58:
    // lhu         $v0, 0x280($s0)
    ctx->r2 = MEM_HU(0X280, ctx->r16);
    // lhu         $v1, 0x17A($s0)
    ctx->r3 = MEM_HU(0X17A, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x286($s0)
    ctx->r3 = MEM_HS(0X286, ctx->r16);
    // sh          $v0, 0x280($s0)
    MEM_H(0X280, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // bne         $v1, $v0, L_80043BB4
    if (ctx->r3 != ctx->r2) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_80043BB4;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v0, 0x592C($v0)
    ctx->r2 = MEM_W(0X592C, ctx->r2);
    // nop

    // lw          $v0, 0x34($v0)
    ctx->r2 = MEM_W(0X34, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_59;
    // nop

    after_59:
    // addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // lh          $a3, 0x286($s0)
    ctx->r7 = MEM_HS(0X286, ctx->r16);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // jal         0x80021994
    // sll         $a3, $a3, 8
    ctx->r7 = S32(ctx->r7) << 8;
    sub_80021994(rdram, ctx);
    goto after_60;
    // sll         $a3, $a3, 8
    ctx->r7 = S32(ctx->r7) << 8;
    after_60:
    // j           L_80043BB4
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    goto L_80043BB4;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
L_800438E0:
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // jal         0x80021994
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80021994(rdram, ctx);
    goto after_61;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_61:
    // lh          $v1, 0x286($s0)
    ctx->r3 = MEM_HS(0X286, ctx->r16);
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // bne         $v1, $v0, L_80043BB4
    if (ctx->r3 != ctx->r2) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_80043BB4;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7FA4
    ctx->r6 = ADD32(ctx->r2, -0X7FA4);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r3);
    // swr         $v1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r3);
    // swl         $a0, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r4);
    // swr         $a0, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r4);
    // jal         0x800341A0
    // nop

    sub_800341A0(rdram, ctx);
    goto after_62;
    // nop

    after_62:
    // jal         0x8003509C
    // nop

    sub_8003509C(rdram, ctx);
    goto after_63;
    // nop

    after_63:
    // jal         0x80034224
    // nop

    sub_80034224(rdram, ctx);
    goto after_64;
    // nop

    after_64:
    // jal         0x80035120
    // nop

    sub_80035120(rdram, ctx);
    goto after_65;
    // nop

    after_65:
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, -0x1CE8
    ctx->r2 = ADD32(ctx->r2, -0X1CE8);
    // addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80043964:
    // sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bne         $v1, $a0, L_80043964
    if (ctx->r3 != ctx->r4) {
        // addiu       $v0, $v0, 0x58
        ctx->r2 = ADD32(ctx->r2, 0X58);
        goto L_80043964;
    }
    // addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s3, $v0, -0x70D8
    ctx->r19 = ADD32(ctx->r2, -0X70D8);
    // addiu       $s4, $zero, 0xEC
    ctx->r20 = ADD32(0, 0XEC);
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
L_80043988:
    // jal         0x80063260
    // nop

    sub_80063260(rdram, ctx);
    goto after_66;
    // nop

    after_66:
    // bne         $v0, $zero, L_80043A34
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80043A34;
    }
    // nop

    // lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // jal         0x80016508
    // addiu       $s0, $s0, 0x2230
    ctx->r16 = ADD32(ctx->r16, 0X2230);
    sub_80016508(rdram, ctx);
    goto after_67;
    // addiu       $s0, $s0, 0x2230
    ctx->r16 = ADD32(ctx->r16, 0X2230);
    after_67:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // sh          $zero, 0x2DC($s3)
    MEM_H(0X2DC, ctx->r19) = 0;
    // sh          $zero, 0x2DA($s3)
    MEM_H(0X2DA, ctx->r19) = 0;
    // sh          $zero, 0x2D8($s3)
    MEM_H(0X2D8, ctx->r19) = 0;
    // jal         0x800500AC
    // sh          $zero, 0x2D6($s3)
    MEM_H(0X2D6, ctx->r19) = 0;
    sub_800500AC(rdram, ctx);
    goto after_68;
    // sh          $zero, 0x2D6($s3)
    MEM_H(0X2D6, ctx->r19) = 0;
    after_68:
    // addiu       $s1, $zero, 0xEF
    ctx->r17 = ADD32(0, 0XEF);
    // addiu       $s0, $s0, 0x54
    ctx->r16 = ADD32(ctx->r16, 0X54);
L_800439D0:
    // lbu         $v0, -0x4F($s0)
    ctx->r2 = MEM_BU(-0X4F, ctx->r16);
    // nop

    // bne         $v0, $s4, L_80043A00
    if (ctx->r2 != ctx->r20) {
        // nop
    
        goto L_80043A00;
    }
    // nop

    // lh          $a0, 0x0($s0)
    ctx->r4 = MEM_HS(0X0, ctx->r16);
    // nop

    // beq         $a0, $s2, L_80043A00
    if (ctx->r4 == ctx->r18) {
        // nop
    
        goto L_80043A00;
    }
    // nop

    // lbu         $a1, -0xA($s0)
    ctx->r5 = MEM_BU(-0XA, ctx->r16);
    // jal         0x8005850C
    // addiu       $a1, $a1, 0x454
    ctx->r5 = ADD32(ctx->r5, 0X454);
    sub_8005850C(rdram, ctx);
    goto after_69;
    // addiu       $a1, $a1, 0x454
    ctx->r5 = ADD32(ctx->r5, 0X454);
    after_69:
    // sh          $s2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r18;
L_80043A00:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s2, L_800439D0
    if (ctx->r17 != ctx->r18) {
        // addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
        goto L_800439D0;
    }
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sw          $v0, -0x7E5C($at)
    MEM_W(-0X7E5C, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_80043BB0
    // sb          $zero, 0x6E15($v0)
    MEM_B(0X6E15, ctx->r2) = 0;
    goto L_80043BB0;
    // sb          $zero, 0x6E15($v0)
    MEM_B(0X6E15, ctx->r2) = 0;
L_80043A34:
    // jal         0x8003E840
    // nop

    sub_8003E840(rdram, ctx);
    goto after_70;
    // nop

    after_70:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x80079BE4
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    ClearImage(rdram, ctx);
    goto after_71;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_71:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ST_DrawSync(rdram, ctx);
    goto after_72;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_72:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80058DC4
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sub_80058DC4(rdram, ctx);
    goto after_73;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_73:
    // jal         0x80062C28
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sub_80062C28(rdram, ctx);
    goto after_74;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_74:
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // bne         $v0, $v1, L_80043B7C
    if (ctx->r2 != ctx->r3) {
        // addiu       $s1, $zero, 0xEF
        ctx->r17 = ADD32(0, 0XEF);
        goto L_80043B7C;
    }
    // addiu       $s1, $zero, 0xEF
    ctx->r17 = ADD32(0, 0XEF);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x2230
    ctx->r2 = ADD32(ctx->r2, 0X2230);
    // addiu       $s0, $v0, 0x54
    ctx->r16 = ADD32(ctx->r2, 0X54);
L_80043A84:
    // lbu         $v0, -0x4F($s0)
    ctx->r2 = MEM_BU(-0X4F, ctx->r16);
    // nop

    // bne         $v0, $s4, L_80043AB4
    if (ctx->r2 != ctx->r20) {
        // nop
    
        goto L_80043AB4;
    }
    // nop

    // lh          $a0, 0x0($s0)
    ctx->r4 = MEM_HS(0X0, ctx->r16);
    // nop

    // beq         $a0, $s2, L_80043AB4
    if (ctx->r4 == ctx->r18) {
        // nop
    
        goto L_80043AB4;
    }
    // nop

    // lbu         $a1, -0xA($s0)
    ctx->r5 = MEM_BU(-0XA, ctx->r16);
    // jal         0x8005850C
    // addiu       $a1, $a1, 0x454
    ctx->r5 = ADD32(ctx->r5, 0X454);
    sub_8005850C(rdram, ctx);
    goto after_75;
    // addiu       $a1, $a1, 0x454
    ctx->r5 = ADD32(ctx->r5, 0X454);
    after_75:
    // sh          $s2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r18;
L_80043AB4:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s2, L_80043A84
    if (ctx->r17 != ctx->r18) {
        // addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
        goto L_80043A84;
    }
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_76;
    // nop

    after_76:
    // jal         0x80058ED4
    // nop

    sub_80058ED4(rdram, ctx);
    goto after_77;
    // nop

    after_77:
    // jal         0x80016508
    // nop

    sub_80016508(rdram, ctx);
    goto after_78;
    // nop

    after_78:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
    // addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // sh          $zero, 0x2DC($s3)
    MEM_H(0X2DC, ctx->r19) = 0;
    // sh          $zero, 0x2DA($s3)
    MEM_H(0X2DA, ctx->r19) = 0;
    // sh          $zero, 0x2D8($s3)
    MEM_H(0X2D8, ctx->r19) = 0;
    // jal         0x800500AC
    // sh          $zero, 0x2D6($s3)
    MEM_H(0X2D6, ctx->r19) = 0;
    sub_800500AC(rdram, ctx);
    goto after_79;
    // sh          $zero, 0x2D6($s3)
    MEM_H(0X2D6, ctx->r19) = 0;
    after_79:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_80;
    // nop

    after_80:
    // jal         0x8003C0E0
    // nop

    sub_8003C0E0(rdram, ctx);
    goto after_81;
    // nop

    after_81:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x5EC8
    ctx->r2 = ADD32(ctx->r2, -0X5EC8);
    // addiu       $v1, $zero, 0xFE
    ctx->r3 = ADD32(0, 0XFE);
    // sb          $v1, 0x6168($v0)
    MEM_B(0X6168, ctx->r2) = ctx->r3;
    // addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // sh          $v1, 0x615E($v0)
    MEM_H(0X615E, ctx->r2) = ctx->r3;
    // sh          $v1, 0x615C($v0)
    MEM_H(0X615C, ctx->r2) = ctx->r3;
    // sh          $v1, 0x615A($v0)
    MEM_H(0X615A, ctx->r2) = ctx->r3;
    // jal         0x80057A68
    // sh          $v1, 0x6158($v0)
    MEM_H(0X6158, ctx->r2) = ctx->r3;
    sub_80057A68(rdram, ctx);
    goto after_82;
    // sh          $v1, 0x6158($v0)
    MEM_H(0X6158, ctx->r2) = ctx->r3;
    after_82:
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // addiu       $v1, $v1, 0x5920
    ctx->r3 = ADD32(ctx->r3, 0X5920);
    // lbu         $a0, 0x4($v1)
    ctx->r4 = MEM_BU(0X4, ctx->r3);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $a3, 0x7($v1)
    ctx->r7 = MEM_BU(0X7, ctx->r3);
    // lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(0X8, ctx->r3);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // jal         0x8003C95C
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8003C95C(rdram, ctx);
    goto after_83;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_83:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_84;
    // nop

    after_84:
    // jal         0x8003EAD0
    // nop

    sub_8003EAD0(rdram, ctx);
    goto after_85;
    // nop

    after_85:
    // j           L_80043BB4
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    goto L_80043BB4;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
L_80043B7C:
    // jal         0x80057A3C
    // nop

    sub_80057A3C(rdram, ctx);
    goto after_86;
    // nop

    after_86:
    // jal         0x80058ED4
    // nop

    sub_80058ED4(rdram, ctx);
    goto after_87;
    // nop

    after_87:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // jal         0x80079BE4
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    ClearImage(rdram, ctx);
    goto after_88;
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_88:
    // jal         0x80079A60
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    ST_DrawSync(rdram, ctx);
    goto after_89;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_89:
    // j           L_80043988
    // nop

    goto L_80043988;
    // nop

L_80043BB0:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
L_80043BB4:
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lhu         $v0, 0x286($v1)
    ctx->r2 = MEM_HU(0X286, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_80043C8C
    // sh          $v0, 0x286($v1)
    MEM_H(0X286, ctx->r3) = ctx->r2;
    goto L_80043C8C;
    // sh          $v0, 0x286($v1)
    MEM_H(0X286, ctx->r3) = ctx->r2;
L_80043BCC:
    // jal         0x80042900
    // nop

    sub_80042900(rdram, ctx);
    goto after_90;
    // nop

    after_90:
    // jal         0x80041D4C
    // nop

    sub_80041D4C(rdram, ctx);
    goto after_91;
    // nop

    after_91:
    // jal         0x800420A0
    // nop

    sub_800420A0(rdram, ctx);
    goto after_92;
    // nop

    after_92:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $v0, 0x280($v1)
    ctx->r2 = MEM_W(0X280, ctx->r3);
    // nop

    // bne         $v0, $zero, L_80043C14
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80043C14;
    }
    // nop

    // lh          $v0, 0x284($v1)
    ctx->r2 = MEM_HS(0X284, ctx->r3);
    // nop

    // bne         $v0, $zero, L_80043C14
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80043C14;
    }
    // nop

    // jal         0x80042C10
    // nop

    sub_80042C10(rdram, ctx);
    goto after_93;
    // nop

    after_93:
L_80043C14:
    // jal         0x8004162C
    // nop

    sub_8004162C(rdram, ctx);
    goto after_94;
    // nop

    after_94:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sb          $zero, -0x6EBA($v0)
    MEM_B(-0X6EBA, ctx->r2) = 0;
L_80043C24:
    // jal         0x80042B9C
    // nop

    sub_80042B9C(rdram, ctx);
    goto after_95;
    // nop

    after_95:
    // j           L_80043C90
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    goto L_80043C90;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_80043C34:
    // jal         0x8003EAD0
    // nop

    sub_8003EAD0(rdram, ctx);
    goto after_96;
    // nop

    after_96:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x310
    ctx->r2 = ADD32(ctx->r2, 0X310);
    // sh          $zero, 0x71A8($v0)
    MEM_H(0X71A8, ctx->r2) = 0;
    // sh          $zero, 0x71A6($v0)
    MEM_H(0X71A6, ctx->r2) = 0;
    // sh          $zero, 0x71A4($v0)
    MEM_H(0X71A4, ctx->r2) = 0;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v0, $v0, 0x5948
    ctx->r2 = ADD32(ctx->r2, 0X5948);
    // sh          $zero, 0x47D2($v0)
    MEM_H(0X47D2, ctx->r2) = 0;
    // sh          $zero, 0x47D0($v0)
    MEM_H(0X47D0, ctx->r2) = 0;
    // sh          $zero, 0x47CE($v0)
    MEM_H(0X47CE, ctx->r2) = 0;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x5EC8
    ctx->r2 = ADD32(ctx->r2, -0X5EC8);
    // sh          $zero, 0x6164($v0)
    MEM_H(0X6164, ctx->r2) = 0;
    // sh          $zero, 0x6162($v0)
    MEM_H(0X6162, ctx->r2) = 0;
    // sh          $zero, 0x6160($v0)
    MEM_H(0X6160, ctx->r2) = 0;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // sh          $zero, 0x1D0($v0)
    MEM_H(0X1D0, ctx->r2) = 0;
    // sh          $zero, 0x1CE($v0)
    MEM_H(0X1CE, ctx->r2) = 0;
    // sh          $zero, 0x1CC($v0)
    MEM_H(0X1CC, ctx->r2) = 0;
L_80043C8C:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_80043C90:
    // addiu       $v1, $v0, 0x5948
    ctx->r3 = ADD32(ctx->r2, 0X5948);
    // lw          $v0, 0x47DC($v1)
    ctx->r2 = MEM_W(0X47DC, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_80043CF8
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80043CF8;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(0X30, ctx->r3);
    // nop

    // slti        $v0, $v0, 0x641
    ctx->r2 = SIGNED(ctx->r2) < 0X641 ? 1 : 0;
    // beq         $v0, $zero, L_80043CF4
    if (ctx->r2 == 0) {
        // addiu       $s1, $sp, 0x28
        ctx->r17 = ADD32(ctx->r29, 0X28);
        goto L_80043CF4;
    }
    // addiu       $s1, $sp, 0x28
    ctx->r17 = ADD32(ctx->r29, 0X28);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    memset_recomp(rdram, ctx);
    goto after_97;
    // addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_97:
    // addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    memset_recomp(rdram, ctx);
    goto after_98;
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_98:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // jal         0x8003DBE0
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sub_8003DBE0(rdram, ctx);
    goto after_99;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_99:
L_80043CF4:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_80043CF8:
    // addiu       $v1, $v0, 0x5948
    ctx->r3 = ADD32(ctx->r2, 0X5948);
    // lw          $v0, 0x47DC($v1)
    ctx->r2 = MEM_W(0X47DC, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_80043D60
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80043D60;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(0X30, ctx->r3);
    // nop

    // slti        $v0, $v0, 0x641
    ctx->r2 = SIGNED(ctx->r2) < 0X641 ? 1 : 0;
    // beq         $v0, $zero, L_80043D5C
    if (ctx->r2 == 0) {
        // addiu       $s1, $sp, 0x58
        ctx->r17 = ADD32(ctx->r29, 0X58);
        goto L_80043D5C;
    }
    // addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    memset_recomp(rdram, ctx);
    goto after_100;
    // addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_100:
    // addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    memset_recomp(rdram, ctx);
    goto after_101;
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_101:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // jal         0x8003DBE0
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sub_8003DBE0(rdram, ctx);
    goto after_102;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_102:
L_80043D5C:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_80043D60:
    // addiu       $v1, $v0, 0x5948
    ctx->r3 = ADD32(ctx->r2, 0X5948);
    // lw          $v0, 0x47DC($v1)
    ctx->r2 = MEM_W(0X47DC, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // beq         $v0, $zero, L_80043DD0
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80043DD0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(0X30, ctx->r3);
    // nop

    // slti        $v0, $v0, 0x641
    ctx->r2 = SIGNED(ctx->r2) < 0X641 ? 1 : 0;
    // beq         $v0, $zero, L_80043DCC
    if (ctx->r2 == 0) {
        // addiu       $s0, $sp, 0x80
        ctx->r16 = ADD32(ctx->r29, 0X80);
        goto L_80043DCC;
    }
    // addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    memset_recomp(rdram, ctx);
    goto after_103;
    // addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_103:
    // addiu       $v0, $zero, 0x96
    ctx->r2 = ADD32(0, 0X96);
    // sh          $v0, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r2;
    // addiu       $s1, $sp, 0x98
    ctx->r17 = ADD32(ctx->r29, 0X98);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    memset_recomp(rdram, ctx);
    goto after_104;
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_104:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003DBE0
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    sub_8003DBE0(rdram, ctx);
    goto after_105;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_105:
L_80043DCC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80043DD0:
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lh          $v0, 0x190($v1)
    ctx->r2 = MEM_HS(0X190, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80043E80
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80043E80;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v1, 0x2C($v1)
    ctx->r3 = MEM_W(0X2C, ctx->r3);
    // nop

    // andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // beq         $v0, $zero, L_80043E00
    if (ctx->r2 == 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_80043E00;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // j           L_80043E20
    // addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
    goto L_80043E20;
    // addiu       $a1, $zero, -0x100
    ctx->r5 = ADD32(0, -0X100);
L_80043E00:
    // andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // beq         $v0, $zero, L_80043E14
    if (ctx->r2 == 0) {
        // andi        $v0, $v1, 0x1
        ctx->r2 = ctx->r3 & 0X1;
        goto L_80043E14;
    }
    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // j           L_80043E20
    // addiu       $a1, $zero, -0x40
    ctx->r5 = ADD32(0, -0X40);
    goto L_80043E20;
    // addiu       $a1, $zero, -0x40
    ctx->r5 = ADD32(0, -0X40);
L_80043E14:
    // beq         $v0, $zero, L_80043E24
    if (ctx->r2 == 0) {
        // lui         $v1, 0x6666
        ctx->r3 = S32(0X6666 << 16);
        goto L_80043E24;
    }
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // addiu       $a1, $zero, -0x10
    ctx->r5 = ADD32(0, -0X10);
L_80043E20:
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
L_80043E24:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, -0x6F48($v0)
    ctx->r2 = MEM_HU(-0X6F48, ctx->r2);
    // ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v1, $t2, 3
    ctx->r3 = S32(ctx->r10) >> 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // bne         $a0, $zero, L_80043E80
    if (ctx->r4 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80043E80;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // jal         0x8003CF28
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    sub_8003CF28(rdram, ctx);
    goto after_106;
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    after_106:
    // addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // jal         0x800582F0
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    sub_800582F0(rdram, ctx);
    goto after_107;
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_107:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80043E80:
    // lhu         $v0, -0x6F38($v0)
    ctx->r2 = MEM_HU(-0X6F38, ctx->r2);
    // nop

    // sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) << 16;
    // sra         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5) >> 16;
    // beq         $a0, $zero, L_80043EDC
    if (ctx->r4 == 0) {
        // lui         $v0, 0x6666
        ctx->r2 = S32(0X6666 << 16);
        goto L_80043EDC;
    }
    // lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $a1, 31
    ctx->r2 = S32(ctx->r5) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v1, $t2, 3
    ctx->r3 = S32(ctx->r10) >> 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bne         $v0, $zero, L_80043EE0
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80043EE0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // jal         0x8003CF28
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    sub_8003CF28(rdram, ctx);
    goto after_108;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_108:
    // jal         0x8003CF94
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    sub_8003CF94(rdram, ctx);
    goto after_109;
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_109:
L_80043EDC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80043EE0:
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, 0x22($a1)
    ctx->r3 = MEM_HU(0X22, ctx->r5);
    // lhu         $v0, 0x24($a1)
    ctx->r2 = MEM_HU(0X24, ctx->r5);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_80043F64
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80043F64;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $a0, 0x23C($a1)
    ctx->r4 = MEM_W(0X23C, ctx->r5);
    // lui         $a2, 0xCCCC
    ctx->r6 = S32(0XCCCC << 16);
    // ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t2
    ctx->r10 = hi;
    // srl         $v1, $t2, 4
    ctx->r3 = S32(U32(ctx->r10) >> 4);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // bne         $a0, $v0, L_80043F64
    if (ctx->r4 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80043F64;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, 0x24($a1)
    ctx->r2 = MEM_HU(0X24, ctx->r5);
    // nop

    // multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t0
    ctx->r8 = hi;
    // lhu         $v0, 0x22($a1)
    ctx->r2 = MEM_HU(0X22, ctx->r5);
    // nop

    // multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // srl         $v0, $t0, 3
    ctx->r2 = S32(U32(ctx->r8) >> 3);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // mfhi        $v1
    ctx->r3 = hi;
    // srl         $a0, $v1, 3
    ctx->r4 = S32(U32(ctx->r3) >> 3);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // jal         0x8003CF28
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    sub_8003CF28(rdram, ctx);
    goto after_110;
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    after_110:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80043F64:
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // lw          $a2, 0x2C($a1)
    ctx->r6 = MEM_W(0X2C, ctx->r5);
    // nop

    // andi        $v0, $a2, 0x400
    ctx->r2 = ctx->r6 & 0X400;
    // bne         $v0, $zero, L_80043F8C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80043F8C;
    }
    // nop

    // lw          $v0, 0x2F0($a1)
    ctx->r2 = MEM_W(0X2F0, ctx->r5);
    // nop

    // beq         $v0, $zero, L_8004418C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004418C;
    }
    // nop

L_80043F8C:
    // lw          $a0, 0x23C($a1)
    ctx->r4 = MEM_W(0X23C, ctx->r5);
    // lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t2
    ctx->r10 = hi;
    // srl         $v1, $t2, 4
    ctx->r3 = S32(U32(ctx->r10) >> 4);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // bne         $a0, $v0, L_80044000
    if (ctx->r4 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80044000;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v0, 0xDE($a1)
    ctx->r2 = MEM_HU(0XDE, ctx->r5);
    // nop

    // addiu       $a0, $v0, -0x100
    ctx->r4 = ADD32(ctx->r2, -0X100);
    // bgez        $a0, L_80043FD0
    if (SIGNED(ctx->r4) >= 0) {
        // nop
    
        goto L_80043FD0;
    }
    // nop

    // addiu       $a0, $v0, -0xFD
    ctx->r4 = ADD32(ctx->r2, -0XFD);
L_80043FD0:
    // lui         $v0, 0x80
    ctx->r2 = S32(0X80 << 16);
    // and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // beq         $v0, $zero, L_80043FF0
    if (ctx->r2 == 0) {
        // sra         $v1, $a0, 2
        ctx->r3 = S32(ctx->r4) >> 2;
        goto L_80043FF0;
    }
    // sra         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) >> 2;
    // srl         $a0, $a0, 31
    ctx->r4 = S32(U32(ctx->r4) >> 31);
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    // j           L_80043FF4
    // sra         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) >> 1;
    goto L_80043FF4;
    // sra         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) >> 1;
L_80043FF0:
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
L_80043FF4:
    // jal         0x8003CF28
    // nop

    sub_8003CF28(rdram, ctx);
    goto after_111;
    // nop

    after_111:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80044000:
    // lw          $a0, -0x6E9C($v0)
    ctx->r4 = MEM_W(-0X6E9C, ctx->r2);
    // lui         $v0, 0x8888
    ctx->r2 = S32(0X8888 << 16);
    // ori         $v0, $v0, 0x8889
    ctx->r2 = ctx->r2 | 0X8889;
    // multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t2
    ctx->r10 = hi;
    // srl         $v1, $t2, 5
    ctx->r3 = S32(U32(ctx->r10) >> 5);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // bne         $a0, $v0, L_80044178
    if (ctx->r4 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80044178;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a3, $sp, 0xA8
    ctx->r7 = ADD32(ctx->r29, 0XA8);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x1CD4
    ctx->r6 = ADD32(ctx->r2, 0X1CD4);
    // addiu       $t0, $a2, 0x20
    ctx->r8 = ADD32(ctx->r6, 0X20);
L_8004403C:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_8004403C
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8004403C;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // nop

    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $v0, 0x2F0($v1)
    ctx->r2 = MEM_W(0X2F0, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80044120
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80044120;
    }
    // nop

    // lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(0X2C, ctx->r3);
    // lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_800440E0
    if (ctx->r2 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_800440E0;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // addiu       $s1, $sp, 0x18
    ctx->r17 = ADD32(ctx->r29, 0X18);
L_800440A8:
    // lw          $a1, 0x90($s1)
    ctx->r5 = MEM_W(0X90, ctx->r17);
    // nop

    // lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(0X0, ctx->r5);
    // nop

    // beq         $v0, $s2, L_800440C8
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_800440C8;
    }
    // nop

    // jal         0x8003D104
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sub_8003D104(rdram, ctx);
    goto after_112;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_112:
L_800440C8:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_800440A8
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
        goto L_800440A8;
    }
    // addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // j           L_80044178
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    goto L_80044178;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_800440E0:
    // ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // addiu       $s1, $sp, 0x18
    ctx->r17 = ADD32(ctx->r29, 0X18);
L_800440E8:
    // lw          $a1, 0x90($s1)
    ctx->r5 = MEM_W(0X90, ctx->r17);
    // nop

    // lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(0X0, ctx->r5);
    // nop

    // beq         $v0, $s2, L_80044108
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_80044108;
    }
    // nop

    // jal         0x8003D104
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    sub_8003D104(rdram, ctx);
    goto after_113;
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_113:
L_80044108:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // bne         $v0, $zero, L_800440E8
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
        goto L_800440E8;
    }
    // addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // j           L_80044178
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    goto L_80044178;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80044120:
    // lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(0X2C, ctx->r3);
    // lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_80044154
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_80044154;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lw          $a1, 0xB0($sp)
    ctx->r5 = MEM_W(0XB0, ctx->r29);
    // nop

    // lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(0X0, ctx->r5);
    // nop

    // beq         $v1, $v0, L_80044174
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_80044174;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // j           L_8004416C
    // nop

    goto L_8004416C;
    // nop

L_80044154:
    // lw          $a1, 0xB0($sp)
    ctx->r5 = MEM_W(0XB0, ctx->r29);
    // nop

    // lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(0X0, ctx->r5);
    // nop

    // beq         $v1, $v0, L_80044174
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
        goto L_80044174;
    }
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8004416C:
    // jal         0x8003D104
    // nop

    sub_8003D104(rdram, ctx);
    goto after_114;
    // nop

    after_114:
L_80044174:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80044178:
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lw          $v1, 0x2C($v0)
    ctx->r3 = MEM_W(0X2C, ctx->r2);
    // addiu       $a0, $zero, -0x401
    ctx->r4 = ADD32(0, -0X401);
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
L_8004418C:
    // jal         0x8003D594
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    sub_8003D594(rdram, ctx);
    goto after_115;
    // lui         $s1, 0x801A
    ctx->r17 = S32(0X801A << 16);
    after_115:
    // addiu       $s0, $s1, -0x70D8
    ctx->r16 = ADD32(ctx->r17, -0X70D8);
    // addiu       $a0, $s0, 0x270
    ctx->r4 = ADD32(ctx->r16, 0X270);
    // lhu         $v0, 0x278($s0)
    ctx->r2 = MEM_HU(0X278, ctx->r16);
    // lhu         $a2, 0x280($s0)
    ctx->r6 = MEM_HU(0X280, ctx->r16);
    // lhu         $v1, 0x288($s0)
    ctx->r3 = MEM_HU(0X288, ctx->r16);
    // lhu         $t0, 0x28A($s0)
    ctx->r8 = MEM_HU(0X28A, ctx->r16);
    // lhu         $t1, 0x28C($s0)
    ctx->r9 = MEM_HU(0X28C, ctx->r16);
    // lhu         $a3, 0x290($s0)
    ctx->r7 = MEM_HU(0X290, ctx->r16);
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // lhu         $v0, 0x27A($s0)
    ctx->r2 = MEM_HU(0X27A, ctx->r16);
    // lhu         $a2, 0x282($s0)
    ctx->r6 = MEM_HU(0X282, ctx->r16);
    // lhu         $v1, 0x284($s0)
    ctx->r3 = MEM_HU(0X284, ctx->r16);
    // addiu       $a1, $s0, 0x298
    ctx->r5 = ADD32(ctx->r16, 0X298);
    // sh          $zero, 0x28C($s0)
    MEM_H(0X28C, ctx->r16) = 0;
    // sh          $zero, 0x28A($s0)
    MEM_H(0X28A, ctx->r16) = 0;
    // sh          $zero, 0x288($s0)
    MEM_H(0X288, ctx->r16) = 0;
    // sh          $a3, 0x268($s0)
    MEM_H(0X268, ctx->r16) = ctx->r7;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // lhu         $a2, 0x292($s0)
    ctx->r6 = MEM_HU(0X292, ctx->r16);
    // lhu         $v0, 0x27C($s0)
    ctx->r2 = MEM_HU(0X27C, ctx->r16);
    // addu        $a2, $a2, $t0
    ctx->r6 = ADD32(ctx->r6, ctx->r8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // lhu         $v1, 0x294($s0)
    ctx->r3 = MEM_HU(0X294, ctx->r16);
    // subu        $a3, $v0, $a3
    ctx->r7 = SUB32(ctx->r2, ctx->r7);
    // sh          $a2, 0x26A($s0)
    MEM_H(0X26A, ctx->r16) = ctx->r6;
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    // sh          $a3, 0x270($s0)
    MEM_H(0X270, ctx->r16) = ctx->r7;
    // sh          $a2, 0x272($s0)
    MEM_H(0X272, ctx->r16) = ctx->r6;
    // addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v1, 0x26C($s0)
    MEM_H(0X26C, ctx->r16) = ctx->r3;
    // jal         0x80075154
    // sh          $v0, 0x274($s0)
    MEM_H(0X274, ctx->r16) = ctx->r2;
    RotMatrixZYX(rdram, ctx);
    goto after_116;
    // sh          $v0, 0x274($s0)
    MEM_H(0X274, ctx->r16) = ctx->r2;
    after_116:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $a2, $v0, 0x5948
    ctx->r6 = ADD32(ctx->r2, 0X5948);
    // lhu         $v0, 0x47CE($a2)
    ctx->r2 = MEM_HU(0X47CE, ctx->r6);
    // lhu         $v1, 0x47D2($a2)
    ctx->r3 = MEM_HU(0X47D2, ctx->r6);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sra         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) >> 1;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sh          $a1, 0x47CE($a2)
    MEM_H(0X47CE, ctx->r6) = ctx->r5;
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // lhu         $v0, 0x47D0($a2)
    ctx->r2 = MEM_HU(0X47D0, ctx->r6);
    // sltiu       $a1, $a1, 0x8
    ctx->r5 = ctx->r5 < 0X8 ? 1 : 0;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sra         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) >> 1;
    // sra         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) >> 16;
    // srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) >> 1;
    // sh          $a0, 0x47D0($a2)
    MEM_H(0X47D0, ctx->r6) = ctx->r4;
    // beq         $a1, $zero, L_8004429C
    if (ctx->r5 == 0) {
        // sh          $v1, 0x47D2($a2)
        MEM_H(0X47D2, ctx->r6) = ctx->r3;
        goto L_8004429C;
    }
    // sh          $v1, 0x47D2($a2)
    MEM_H(0X47D2, ctx->r6) = ctx->r3;
    // sh          $zero, 0x47CE($a2)
    MEM_H(0X47CE, ctx->r6) = 0;
L_8004429C:
    // addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_800442B4
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x4
        ctx->r2 = ADD32(ctx->r3, 0X4);
        goto L_800442B4;
    }
    // addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // sh          $zero, 0x47D0($a2)
    MEM_H(0X47D0, ctx->r6) = 0;
L_800442B4:
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_800442C8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800442C8;
    }
    // nop

    // sh          $zero, 0x47D2($a2)
    MEM_H(0X47D2, ctx->r6) = 0;
L_800442C8:
    // jal         0x800402AC
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_800402AC(rdram, ctx);
    goto after_117;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_117:
    // jal         0x800402AC
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sub_800402AC(rdram, ctx);
    goto after_118;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_118:
    // jal         0x80040024
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80040024(rdram, ctx);
    goto after_119;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_119:
    // jal         0x80040024
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sub_80040024(rdram, ctx);
    goto after_120;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_120:
    // lbu         $v1, 0x218($s0)
    ctx->r3 = MEM_BU(0X218, ctx->r16);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_800443B4
    if (ctx->r3 == ctx->r2) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_800443B4;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // lhu         $v1, -0x70D8($s1)
    ctx->r3 = MEM_HU(-0X70D8, ctx->r17);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80044354
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80044354;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v0, 0x1C4($s0)
    ctx->r2 = MEM_BU(0X1C4, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80044350
    if (ctx->r2 == 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_80044350;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // lw          $v0, 0x23C($s0)
    ctx->r2 = MEM_W(0X23C, ctx->r16);
    // nop

    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_80044338
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80044338;
    }
    // nop

    // break       7
    do_break(2147762996);
L_80044338:
    // mfhi        $v1
    ctx->r3 = hi;
    // nop

    // bne         $v1, $zero, L_80044354
    if (ctx->r3 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80044354;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // jal         0x8003CF28
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sub_8003CF28(rdram, ctx);
    goto after_121;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_121:
L_80044350:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80044354:
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(0X6, ctx->r4);
    // lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(0X4, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_800443B4
    if (ctx->r2 == 0) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_800443B4;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lbu         $v0, 0x1C5($a0)
    ctx->r2 = MEM_BU(0X1C5, ctx->r4);
    // nop

    // beq         $v0, $zero, L_800443B0
    if (ctx->r2 == 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_800443B0;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // lw          $v0, 0x23C($a0)
    ctx->r2 = MEM_W(0X23C, ctx->r4);
    // nop

    // divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // bne         $v1, $zero, L_80044398
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80044398;
    }
    // nop

    // break       7
    do_break(2147763092);
L_80044398:
    // mfhi        $v1
    ctx->r3 = hi;
    // nop

    // bne         $v1, $zero, L_800443B4
    if (ctx->r3 != 0) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_800443B4;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // jal         0x8003CF94
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sub_8003CF94(rdram, ctx);
    goto after_122;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_122:
L_800443B0:
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
L_800443B4:
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lw          $v0, 0x23C($v1)
    ctx->r2 = MEM_W(0X23C, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x23C($v1)
    MEM_W(0X23C, ctx->r3) = ctx->r2;
L_800443C8:
    // lw          $ra, 0xE4($sp)
    ctx->r31 = MEM_W(0XE4, ctx->r29);
    // lw          $s4, 0xE0($sp)
    ctx->r20 = MEM_W(0XE0, ctx->r29);
    // lw          $s3, 0xDC($sp)
    ctx->r19 = MEM_W(0XDC, ctx->r29);
    // lw          $s2, 0xD8($sp)
    ctx->r18 = MEM_W(0XD8, ctx->r29);
    // lw          $s1, 0xD4($sp)
    ctx->r17 = MEM_W(0XD4, ctx->r29);
    // lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(0XD0, ctx->r29);
    // addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // jr          $ra
    // nop

    return;
    // nop

;}
