#include "recomp.h"
#include "disable_warnings.h"

void sub_8003C24C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a3, $v0, -0x70D8
    ctx->r7 = ADD32(ctx->r2, -0X70D8);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lh          $v0, 0x2D6($a3)
    ctx->r2 = MEM_HS(0X2D6, ctx->r7);
    // lhu         $v1, 0x2D6($a3)
    ctx->r3 = MEM_HU(0X2D6, ctx->r7);
    // beq         $v0, $zero, L_8003C2CC
    if (ctx->r2 == 0) {
        // addu        $s2, $a0, $zero
        ctx->r18 = ADD32(ctx->r4, 0);
        goto L_8003C2CC;
    }
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // lhu         $v0, 0x2D8($a3)
    ctx->r2 = MEM_HU(0X2D8, ctx->r7);
    // nop

    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sh          $v0, 0x2D6($a3)
    MEM_H(0X2D6, ctx->r7) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_8003C298
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8003C298;
    }
    // nop

    // sh          $zero, 0x2D6($a3)
    MEM_H(0X2D6, ctx->r7) = 0;
L_8003C298:
    // lh          $v0, 0x2D6($a3)
    ctx->r2 = MEM_HS(0X2D6, ctx->r7);
    // lhu         $a3, 0x2D6($a3)
    ctx->r7 = MEM_HU(0X2D6, ctx->r7);
    // slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_8003C2B0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8003C2B0;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
L_8003C2B0:
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) << 16;
    // jal         0x80021994
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    sub_80021994(rdram, ctx);
    goto after_0;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    after_0:
L_8003C2CC:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a3, $v0, -0x70D8
    ctx->r7 = ADD32(ctx->r2, -0X70D8);
    // lh          $v0, 0x2DA($a3)
    ctx->r2 = MEM_HS(0X2DA, ctx->r7);
    // lhu         $v1, 0x2DA($a3)
    ctx->r3 = MEM_HU(0X2DA, ctx->r7);
    // beq         $v0, $zero, L_8003C338
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003C338;
    }
    // nop

    // lhu         $v0, 0x2DC($a3)
    ctx->r2 = MEM_HU(0X2DC, ctx->r7);
    // nop

    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sh          $v0, 0x2DA($a3)
    MEM_H(0X2DA, ctx->r7) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_8003C304
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8003C304;
    }
    // nop

    // sh          $zero, 0x2DA($a3)
    MEM_H(0X2DA, ctx->r7) = 0;
L_8003C304:
    // lh          $v0, 0x2DA($a3)
    ctx->r2 = MEM_HS(0X2DA, ctx->r7);
    // lhu         $a3, 0x2DA($a3)
    ctx->r7 = MEM_HU(0X2DA, ctx->r7);
    // slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_8003C31C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8003C31C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
L_8003C31C:
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) << 16;
    // jal         0x80021994
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    sub_80021994(rdram, ctx);
    goto after_1;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    after_1:
L_8003C338:
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x6F48
    ctx->r16 = ADD32(ctx->r2, -0X6F48);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // jal         0x8003C17C
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_8003C17C(rdram, ctx);
    goto after_2;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_2:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a3, $v0, L_8003C3A4
    if (ctx->r7 == ctx->r2) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_8003C3A4;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jal         0x80021994
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80021994(rdram, ctx);
    goto after_3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // addiu       $a0, $s0, -0x190
    ctx->r4 = ADD32(ctx->r16, -0X190);
    // lw          $v0, 0x190($a0)
    ctx->r2 = MEM_W(0X190, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8003C3A4
    if (ctx->r2 != 0) {
        // addiu       $v1, $zero, -0x8
        ctx->r3 = ADD32(0, -0X8);
        goto L_8003C3A4;
    }
    // addiu       $v1, $zero, -0x8
    ctx->r3 = ADD32(0, -0X8);
    // lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(0X2C, ctx->r4);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
L_8003C3A4:
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x6F44
    ctx->r16 = ADD32(ctx->r2, -0X6F44);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // jal         0x8003C17C
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_8003C17C(rdram, ctx);
    goto after_4;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_4:
    // addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_8003C484
    if (ctx->r2 == ctx->r3) {
        // addiu       $v1, $zero, 0x3
        ctx->r3 = ADD32(0, 0X3);
        goto L_8003C484;
    }
    // addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // bne         $v0, $v1, L_8003C3F4
    if (ctx->r2 != ctx->r3) {
        // addiu       $a3, $a3, -0x200
        ctx->r7 = ADD32(ctx->r7, -0X200);
        goto L_8003C3F4;
    }
    // addiu       $a3, $a3, -0x200
    ctx->r7 = ADD32(ctx->r7, -0X200);
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
L_8003C3F4:
    // addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) << 16;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jal         0x80021994
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80021994(rdram, ctx);
    goto after_5;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
    // jal         0x8003EAD0
    // nop

    sub_8003EAD0(rdram, ctx);
    goto after_6;
    // nop

    after_6:
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
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v1, 0x194($a0)
    ctx->r3 = MEM_W(0X194, ctx->r4);
    // addiu       $v0, $v0, -0x5EC8
    ctx->r2 = ADD32(ctx->r2, -0X5EC8);
    // sh          $zero, 0x6164($v0)
    MEM_H(0X6164, ctx->r2) = 0;
    // sh          $zero, 0x6162($v0)
    MEM_H(0X6162, ctx->r2) = 0;
    // sh          $zero, 0x6160($v0)
    MEM_H(0X6160, ctx->r2) = 0;
    // sh          $zero, 0x1D0($a0)
    MEM_H(0X1D0, ctx->r4) = 0;
    // sh          $zero, 0x1CE($a0)
    MEM_H(0X1CE, ctx->r4) = 0;
    // bne         $v1, $zero, L_8003C484
    if (ctx->r3 != 0) {
        // sh          $zero, 0x1CC($a0)
        MEM_H(0X1CC, ctx->r4) = 0;
        goto L_8003C484;
    }
    // sh          $zero, 0x1CC($a0)
    MEM_H(0X1CC, ctx->r4) = 0;
    // lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(0X2C, ctx->r4);
    // addiu       $v1, $zero, -0x19
    ctx->r3 = ADD32(0, -0X19);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
L_8003C484:
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x6F40
    ctx->r16 = ADD32(ctx->r2, -0X6F40);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003C17C
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_8003C17C(rdram, ctx);
    goto after_7;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_7:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a3, $v0, L_8003C500
    if (ctx->r7 == ctx->r2) {
        // addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
        goto L_8003C500;
    }
    // addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // jal         0x80021994
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80021994(rdram, ctx);
    goto after_8;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // addiu       $a2, $s0, -0x198
    ctx->r6 = ADD32(ctx->r16, -0X198);
    // lw          $v0, 0x198($a2)
    ctx->r2 = MEM_W(0X198, ctx->r6);
    // nop

    // bne         $v0, $zero, L_8003C500
    if (ctx->r2 != 0) {
        // addiu       $a1, $zero, -0x61
        ctx->r5 = ADD32(0, -0X61);
        goto L_8003C500;
    }
    // addiu       $a1, $zero, -0x61
    ctx->r5 = ADD32(0, -0X61);
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // addiu       $a0, $a0, -0x4930
    ctx->r4 = ADD32(ctx->r4, -0X4930);
    // lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(0X2C, ctx->r6);
    // lbu         $v1, 0x4($a0)
    ctx->r3 = MEM_BU(0X4, ctx->r4);
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    // sw          $v0, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r2;
    // sb          $v1, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r3;
L_8003C500:
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s1, $v0, -0x6F3C
    ctx->r17 = ADD32(ctx->r2, -0X6F3C);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $s1, 0x2
    ctx->r5 = ADD32(ctx->r17, 0X2);
    // addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // jal         0x8003C17C
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_8003C17C(rdram, ctx);
    goto after_9;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_9:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_8003C574
    if (ctx->r2 == ctx->r3) {
        // addiu       $s0, $s1, -0x19C
        ctx->r16 = ADD32(ctx->r17, -0X19C);
        goto L_8003C574;
    }
    // addiu       $s0, $s1, -0x19C
    ctx->r16 = ADD32(ctx->r17, -0X19C);
    // lw          $v0, 0x19C($s0)
    ctx->r2 = MEM_W(0X19C, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8003C574
    if (ctx->r2 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_8003C574;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(0X2C, ctx->r16);
    // addiu       $v1, $zero, -0x81
    ctx->r3 = ADD32(0, -0X81);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // jal         0x8005A3A8
    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    sub_8005A3A8(rdram, ctx);
    goto after_10;
    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    after_10:
    // lhu         $a0, -0x19C($s1)
    ctx->r4 = MEM_HU(-0X19C, ctx->r17);
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_8003C574
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003C574;
    }
    // nop

    // sh          $a0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r4;
L_8003C574:
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s1, $v0, -0x6F38
    ctx->r17 = ADD32(ctx->r2, -0X6F38);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $s1, 0x2
    ctx->r5 = ADD32(ctx->r17, 0X2);
    // addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // jal         0x8003C17C
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_8003C17C(rdram, ctx);
    goto after_11;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_11:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $a3, $v0, L_8003C604
    if (ctx->r7 == ctx->r2) {
        // addiu       $a0, $zero, 0x28
        ctx->r4 = ADD32(0, 0X28);
        goto L_8003C604;
    }
    // addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jal         0x80021994
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80021994(rdram, ctx);
    goto after_12;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_12:
    // addiu       $s0, $s1, -0x1A0
    ctx->r16 = ADD32(ctx->r17, -0X1A0);
    // lw          $v0, 0x1A0($s0)
    ctx->r2 = MEM_W(0X1A0, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8003C608
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003C608;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(0X2C, ctx->r16);
    // addiu       $v1, $zero, -0x101
    ctx->r3 = ADD32(0, -0X101);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // jal         0x8005A3A8
    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    sub_8005A3A8(rdram, ctx);
    goto after_13;
    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    after_13:
    // lhu         $a0, -0x1A0($s1)
    ctx->r4 = MEM_HU(-0X1A0, ctx->r17);
    // lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(0X2, ctx->r16);
    // nop

    // sltu        $v0, $a0, $v0
    ctx->r2 = ctx->r4 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_8003C608
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003C608;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sh          $a0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r4;
L_8003C604:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8003C608:
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // lw          $v0, 0x2EC($s0)
    ctx->r2 = MEM_W(0X2EC, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8003C634
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8003C634;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // jal         0x80021994
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_80021994(rdram, ctx);
    goto after_14;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_14:
L_8003C634:
    // lw          $v0, 0x2F0($s0)
    ctx->r2 = MEM_W(0X2F0, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8003C65C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8003C65C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80021994
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_80021994(rdram, ctx);
    goto after_15;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_15:
L_8003C65C:
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // addiu       $a0, $s0, 0x1A4
    ctx->r4 = ADD32(ctx->r16, 0X1A4);
    // addiu       $a1, $s0, 0x1A6
    ctx->r5 = ADD32(ctx->r16, 0X1A6);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003C17C
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_8003C17C(rdram, ctx);
    goto after_16;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_16:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_8003C6D0
    if (ctx->r2 == ctx->r3) {
        // lui         $v1, 0x8019
        ctx->r3 = S32(0X8019 << 16);
        goto L_8003C6D0;
    }
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v1, $v1, -0x4930
    ctx->r3 = ADD32(ctx->r3, -0X4930);
    // lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(0X4, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(0X3, ctx->r3);
    // lw          $a0, 0x1A4($s0)
    ctx->r4 = MEM_W(0X1A4, ctx->r16);
    // ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // bne         $a0, $zero, L_8003C6D0
    if (ctx->r4 != 0) {
        // sb          $v0, 0x3($v1)
        MEM_B(0X3, ctx->r3) = ctx->r2;
        goto L_8003C6D0;
    }
    // sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // lui         $a0, 0xFFFD
    ctx->r4 = S32(0XFFFD << 16);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // lui         $v1, 0xFFFE
    ctx->r3 = S32(0XFFFE << 16);
    // lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(0X2C, ctx->r16);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
L_8003C6D0:
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x6F30
    ctx->r16 = ADD32(ctx->r2, -0X6F30);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003C17C
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_8003C17C(rdram, ctx);
    goto after_17;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_17:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_8003C724
    if (ctx->r2 == ctx->r3) {
        // addiu       $a0, $s0, -0x1A8
        ctx->r4 = ADD32(ctx->r16, -0X1A8);
        goto L_8003C724;
    }
    // addiu       $a0, $s0, -0x1A8
    ctx->r4 = ADD32(ctx->r16, -0X1A8);
    // lw          $v0, 0x1A8($a0)
    ctx->r2 = MEM_W(0X1A8, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8003C724
    if (ctx->r2 != 0) {
        // lui         $v1, 0xFFFB
        ctx->r3 = S32(0XFFFB << 16);
        goto L_8003C724;
    }
    // lui         $v1, 0xFFFB
    ctx->r3 = S32(0XFFFB << 16);
    // lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(0X2C, ctx->r4);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
L_8003C724:
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x6F2C
    ctx->r16 = ADD32(ctx->r2, -0X6F2C);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003C17C
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_8003C17C(rdram, ctx);
    goto after_18;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_18:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_8003C778
    if (ctx->r2 == ctx->r3) {
        // addiu       $a0, $s0, -0x1AC
        ctx->r4 = ADD32(ctx->r16, -0X1AC);
        goto L_8003C778;
    }
    // addiu       $a0, $s0, -0x1AC
    ctx->r4 = ADD32(ctx->r16, -0X1AC);
    // lw          $v0, 0x1AC($a0)
    ctx->r2 = MEM_W(0X1AC, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8003C778
    if (ctx->r2 != 0) {
        // lui         $v1, 0xFFF7
        ctx->r3 = S32(0XFFF7 << 16);
        goto L_8003C778;
    }
    // lui         $v1, 0xFFF7
    ctx->r3 = S32(0XFFF7 << 16);
    // lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(0X2C, ctx->r4);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
L_8003C778:
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x6F28
    ctx->r16 = ADD32(ctx->r2, -0X6F28);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003C17C
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_8003C17C(rdram, ctx);
    goto after_19;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_19:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_8003C7CC
    if (ctx->r2 == ctx->r3) {
        // addiu       $a0, $s0, -0x1B0
        ctx->r4 = ADD32(ctx->r16, -0X1B0);
        goto L_8003C7CC;
    }
    // addiu       $a0, $s0, -0x1B0
    ctx->r4 = ADD32(ctx->r16, -0X1B0);
    // lw          $v0, 0x1B0($a0)
    ctx->r2 = MEM_W(0X1B0, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8003C7CC
    if (ctx->r2 != 0) {
        // lui         $v1, 0xFFEF
        ctx->r3 = S32(0XFFEF << 16);
        goto L_8003C7CC;
    }
    // lui         $v1, 0xFFEF
    ctx->r3 = S32(0XFFEF << 16);
    // lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(0X2C, ctx->r4);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
L_8003C7CC:
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x6F24
    ctx->r16 = ADD32(ctx->r2, -0X6F24);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003C17C
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_8003C17C(rdram, ctx);
    goto after_20;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_20:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_8003C820
    if (ctx->r2 == ctx->r3) {
        // addiu       $a0, $s0, -0x1B4
        ctx->r4 = ADD32(ctx->r16, -0X1B4);
        goto L_8003C820;
    }
    // addiu       $a0, $s0, -0x1B4
    ctx->r4 = ADD32(ctx->r16, -0X1B4);
    // lw          $v0, 0x1B4($a0)
    ctx->r2 = MEM_W(0X1B4, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8003C820
    if (ctx->r2 != 0) {
        // lui         $v1, 0xFFDF
        ctx->r3 = S32(0XFFDF << 16);
        goto L_8003C820;
    }
    // lui         $v1, 0xFFDF
    ctx->r3 = S32(0XFFDF << 16);
    // lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(0X2C, ctx->r4);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
L_8003C820:
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x6F20
    ctx->r16 = ADD32(ctx->r2, -0X6F20);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003C17C
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_8003C17C(rdram, ctx);
    goto after_21;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_21:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_8003C898
    if (ctx->r2 == ctx->r3) {
        // lui         $v1, 0x8019
        ctx->r3 = S32(0X8019 << 16);
        goto L_8003C898;
    }
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // addiu       $v1, $v1, -0x4930
    ctx->r3 = ADD32(ctx->r3, -0X4930);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(0X4, ctx->r3);
    // addiu       $a1, $s0, -0x1B8
    ctx->r5 = ADD32(ctx->r16, -0X1B8);
    // sb          $a0, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r4;
    // ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(0X3, ctx->r3);
    // lw          $a0, 0x1B8($a1)
    ctx->r4 = MEM_W(0X1B8, ctx->r5);
    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // bne         $a0, $zero, L_8003C898
    if (ctx->r4 != 0) {
        // sb          $v0, 0x3($v1)
        MEM_B(0X3, ctx->r3) = ctx->r2;
        goto L_8003C898;
    }
    // sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // lui         $v1, 0xFFBF
    ctx->r3 = S32(0XFFBF << 16);
    // lw          $v0, 0x2C($a1)
    ctx->r2 = MEM_W(0X2C, ctx->r5);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r2;
L_8003C898:
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x6F1C
    ctx->r16 = ADD32(ctx->r2, -0X6F1C);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003C17C
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_8003C17C(rdram, ctx);
    goto after_22;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_22:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_8003C8EC
    if (ctx->r2 == ctx->r3) {
        // addiu       $a0, $s0, -0x1BC
        ctx->r4 = ADD32(ctx->r16, -0X1BC);
        goto L_8003C8EC;
    }
    // addiu       $a0, $s0, -0x1BC
    ctx->r4 = ADD32(ctx->r16, -0X1BC);
    // lw          $v0, 0x1BC($a0)
    ctx->r2 = MEM_W(0X1BC, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8003C8EC
    if (ctx->r2 != 0) {
        // lui         $v1, 0xFF7F
        ctx->r3 = S32(0XFF7F << 16);
        goto L_8003C8EC;
    }
    // lui         $v1, 0xFF7F
    ctx->r3 = S32(0XFF7F << 16);
    // lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(0X2C, ctx->r4);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
L_8003C8EC:
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s0, $v0, -0x6F18
    ctx->r16 = ADD32(ctx->r2, -0X6F18);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x8003C17C
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_8003C17C(rdram, ctx);
    goto after_23;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_23:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // beq         $v0, $v1, L_8003C940
    if (ctx->r2 == ctx->r3) {
        // addiu       $a0, $s0, -0x1C0
        ctx->r4 = ADD32(ctx->r16, -0X1C0);
        goto L_8003C940;
    }
    // addiu       $a0, $s0, -0x1C0
    ctx->r4 = ADD32(ctx->r16, -0X1C0);
    // lw          $v0, 0x1C0($a0)
    ctx->r2 = MEM_W(0X1C0, ctx->r4);
    // nop

    // bne         $v0, $zero, L_8003C940
    if (ctx->r2 != 0) {
        // addiu       $v1, $zero, -0x801
        ctx->r3 = ADD32(0, -0X801);
        goto L_8003C940;
    }
    // addiu       $v1, $zero, -0x801
    ctx->r3 = ADD32(0, -0X801);
    // lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(0X2C, ctx->r4);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
L_8003C940:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
