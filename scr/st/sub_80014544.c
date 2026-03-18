#include "recomp.h"
#include "disable_warnings.h"

void sub_80014544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // jal         0x800152D0
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    sub_800152D0(rdram, ctx);
    goto after_0;
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_0:
    // addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // addiu       $a1, $a1, 0x7EC0
    ctx->r5 = ADD32(ctx->r5, 0X7EC0);
    // jal         0x8001618C
    // addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    sub_8001618C(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    after_1:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // jal         0x80014450
    // sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    sub_80014450(rdram, ctx);
    goto after_2;
    // sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    after_2:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // addiu       $v1, $v1, 0x5920
    ctx->r3 = ADD32(ctx->r3, 0X5920);
    // sb          $v0, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r2;
    // sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
    // sb          $v0, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r2;
    // sb          $v0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r2;
    // sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // jal         0x80014450
    // sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    sub_80014450(rdram, ctx);
    goto after_3;
    // sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    after_3:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x70D8
    ctx->r16 = ADD32(ctx->r16, -0X70D8);
    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // jal         0x80014450
    // sw          $v0, 0x248($s0)
    MEM_W(0X248, ctx->r16) = ctx->r2;
    sub_80014450(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x248($s0)
    MEM_W(0X248, ctx->r16) = ctx->r2;
    after_4:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addiu       $v0, $v0, -0x640
    ctx->r2 = ADD32(ctx->r2, -0X640);
    // jal         0x80014450
    // sw          $v0, 0x24C($s0)
    MEM_W(0X24C, ctx->r16) = ctx->r2;
    sub_80014450(rdram, ctx);
    goto after_5;
    // sw          $v0, 0x24C($s0)
    MEM_W(0X24C, ctx->r16) = ctx->r2;
    after_5:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // jal         0x80014450
    // sw          $v0, 0x250($s0)
    MEM_W(0X250, ctx->r16) = ctx->r2;
    sub_80014450(rdram, ctx);
    goto after_6;
    // sw          $v0, 0x250($s0)
    MEM_W(0X250, ctx->r16) = ctx->r2;
    after_6:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // jal         0x80014450
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    sub_80014450(rdram, ctx);
    goto after_7;
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    after_7:
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // addiu       $s1, $zero, 0x3E7
    ctx->r17 = ADD32(0, 0X3E7);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $fp, $v0, 0x7590
    ctx->r30 = ADD32(ctx->r2, 0X7590);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s3, $v0, 0x76F8
    ctx->r19 = ADD32(ctx->r2, 0X76F8);
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80014654:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80014658:
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // jal         0x80014450
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_80014450(rdram, ctx);
    goto after_8;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_8:
    // addiu       $a0, $sp, 0x14
    ctx->r4 = ADD32(ctx->r29, 0X14);
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // jal         0x80014450
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    sub_80014450(rdram, ctx);
    goto after_9;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_9:
    // beq         $s0, $s1, L_8001482C
    if (ctx->r16 == ctx->r17) {
        // addu        $a1, $v0, $zero
        ctx->r5 = ADD32(ctx->r2, 0);
        goto L_8001482C;
    }
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, 0x3E6
    ctx->r2 = ADD32(0, 0X3E6);
    // bne         $s0, $v0, L_8001469C
    if (ctx->r16 != ctx->r2) {
        // addiu       $v0, $zero, 0x3E5
        ctx->r2 = ADD32(0, 0X3E5);
        goto L_8001469C;
    }
    // addiu       $v0, $zero, 0x3E5
    ctx->r2 = ADD32(0, 0X3E5);
    // bne         $a1, $s1, L_80014658
    if (ctx->r5 != ctx->r17) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80014658;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $v0, $zero, 0x3E5
    ctx->r2 = ADD32(0, 0X3E5);
L_8001469C:
    // bne         $s0, $v0, L_800146B4
    if (ctx->r16 != ctx->r2) {
        // addiu       $v0, $zero, 0x3E4
        ctx->r2 = ADD32(0, 0X3E4);
        goto L_800146B4;
    }
    // addiu       $v0, $zero, 0x3E4
    ctx->r2 = ADD32(0, 0X3E4);
    // beq         $a1, $s1, L_800146B4
    if (ctx->r5 == ctx->r17) {
        // nop
    
        goto L_800146B4;
    }
    // nop

    // j           L_80014654
    // addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    goto L_80014654;
    // addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_800146B4:
    // bne         $s0, $v0, L_800146CC
    if (ctx->r16 != ctx->r2) {
        // addiu       $v1, $s0, -0x3CA
        ctx->r3 = ADD32(ctx->r16, -0X3CA);
        goto L_800146CC;
    }
    // addiu       $v1, $s0, -0x3CA
    ctx->r3 = ADD32(ctx->r16, -0X3CA);
    // beq         $a1, $s1, L_800146CC
    if (ctx->r5 == ctx->r17) {
        // addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
        goto L_800146CC;
    }
    // addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // j           L_80014654
    // sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    goto L_80014654;
    // sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
L_800146CC:
    // sltiu       $v0, $v1, 0x15
    ctx->r2 = ctx->r3 < 0X15 ? 1 : 0;
    // beq         $v0, $zero, L_80014780
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80014780;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // beq         $a1, $s1, L_80014654
    if (ctx->r5 == ctx->r17) {
        // addiu       $a2, $v0, -0x70A0
        ctx->r6 = ADD32(ctx->r2, -0X70A0);
        goto L_80014654;
    }
    // addiu       $a2, $v0, -0x70A0
    ctx->r6 = ADD32(ctx->r2, -0X70A0);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // addu        $a0, $a1, $fp
    ctx->r4 = ADD32(ctx->r5, ctx->r30);
    // sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // nop

    // andi        $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 & 0X7F;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // andi        $v1, $v1, 0x80
    ctx->r3 = ctx->r3 & 0X80;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // slti        $v0, $a1, 0x10A
    ctx->r2 = SIGNED(ctx->r5) < 0X10A ? 1 : 0;
    // beq         $v0, $zero, L_8001475C
    if (ctx->r2 == 0) {
        // sb          $v1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r3;
        goto L_8001475C;
    }
    // sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // bgez        $a1, L_80014724
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_80014724;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // addiu       $v0, $a1, 0x1F
    ctx->r2 = ADD32(ctx->r5, 0X1F);
L_80014724:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // lw          $v1, 0x70($v1)
    ctx->r3 = MEM_W(0X70, ctx->r3);
    // sllv        $v0, $s2, $v0
    ctx->r2 = S32(ctx->r18) << (ctx->r2 & 31);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // bne         $v1, $zero, L_8001475C
    if (ctx->r3 != 0) {
        // addiu       $v1, $a2, -0x38
        ctx->r3 = ADD32(ctx->r6, -0X38);
        goto L_8001475C;
    }
    // addiu       $v1, $a2, -0x38
    ctx->r3 = ADD32(ctx->r6, -0X38);
    // lhu         $v0, 0x28($v1)
    ctx->r2 = MEM_HU(0X28, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r2;
L_8001475C:
    // bgez        $a1, L_80014768
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_80014768;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // addiu       $v0, $a1, 0x1F
    ctx->r2 = ADD32(ctx->r5, 0X1F);
L_80014768:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // j           L_80014818
    // subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    goto L_80014818;
    // subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
L_80014780:
    // beq         $a1, $s1, L_80014658
    if (ctx->r5 == ctx->r17) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80014658;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // blez        $a1, L_80014654
    if (SIGNED(ctx->r5) <= 0) {
        // addu        $a0, $s0, $fp
        ctx->r4 = ADD32(ctx->r16, ctx->r30);
        goto L_80014654;
    }
    // addu        $a0, $s0, $fp
    ctx->r4 = ADD32(ctx->r16, ctx->r30);
    // lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(0X0, ctx->r4);
    // andi        $v1, $a1, 0x7F
    ctx->r3 = ctx->r5 & 0X7F;
    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // slti        $v0, $s0, 0x10A
    ctx->r2 = SIGNED(ctx->r16) < 0X10A ? 1 : 0;
    // beq         $v0, $zero, L_800147F8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800147F8;
    }
    // nop

    // bgez        $s0, L_800147BC
    if (SIGNED(ctx->r16) >= 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_800147BC;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // addiu       $v0, $s0, 0x1F
    ctx->r2 = ADD32(ctx->r16, 0X1F);
L_800147BC:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
    // lw          $v1, 0x70($v1)
    ctx->r3 = MEM_W(0X70, ctx->r3);
    // sllv        $v0, $s2, $v0
    ctx->r2 = S32(ctx->r18) << (ctx->r2 & 31);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // bne         $v1, $zero, L_800147F8
    if (ctx->r3 != 0) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_800147F8;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lhu         $v0, 0x28($v1)
    ctx->r2 = MEM_HU(0X28, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r2;
L_800147F8:
    // bgez        $s0, L_80014804
    if (SIGNED(ctx->r16) >= 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_80014804;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // addiu       $v0, $s0, 0x1F
    ctx->r2 = ADD32(ctx->r16, 0X1F);
L_80014804:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2) << 2;
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v0, $s0, $v0
    ctx->r2 = SUB32(ctx->r16, ctx->r2);
L_80014818:
    // lw          $v1, 0x70($a0)
    ctx->r3 = MEM_W(0X70, ctx->r4);
    // sllv        $v0, $s2, $v0
    ctx->r2 = S32(ctx->r18) << (ctx->r2 & 31);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // j           L_80014654
    // sw          $v1, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r3;
    goto L_80014654;
    // sw          $v1, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->r3;
L_8001482C:
    // jal         0x8003CEDC
    // nop

    sub_8003CEDC(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // beq         $s4, $zero, L_80014848
    if (ctx->r20 == 0) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_80014848;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v0, $v1, -0x70D8
    ctx->r2 = ADD32(ctx->r3, -0X70D8);
    // sh          $s4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r20;
    // sh          $s4, -0x70D8($v1)
    MEM_H(-0X70D8, ctx->r3) = ctx->r20;
L_80014848:
    // beq         $s5, $zero, L_8001485C
    if (ctx->r21 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8001485C;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // sh          $s5, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r21;
    // sh          $s5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r21;
L_8001485C:
    // jal         0x800152F8
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    __builtin_delete(rdram, ctx);
    goto after_11;
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_11:
    // beq         $s7, $zero, L_8001494C
    if (ctx->r23 == 0) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_8001494C;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $t2, $v0, 0x7590
    ctx->r10 = ADD32(ctx->r2, 0X7590);
    // addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $t0, $v0, -0x70D8
    ctx->r8 = ADD32(ctx->r2, -0X70D8);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a3, $v0, 0x76F8
    ctx->r7 = ADD32(ctx->r2, 0X76F8);
    // addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
L_8001488C:
    // lbu         $v1, 0x11C($a2)
    ctx->r3 = MEM_BU(0X11C, ctx->r6);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_800148BC
    if (ctx->r3 == ctx->r2) {
        // addu        $a0, $a1, $t2
        ctx->r4 = ADD32(ctx->r5, ctx->r10);
        goto L_800148BC;
    }
    // addu        $a0, $a1, $t2
    ctx->r4 = ADD32(ctx->r5, ctx->r10);
    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // nop

    // andi        $v0, $v1, 0x7F
    ctx->r2 = ctx->r3 & 0X7F;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // andi        $v1, $v1, 0x80
    ctx->r3 = ctx->r3 & 0X80;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
L_800148BC:
    // slti        $v0, $a1, 0x10A
    ctx->r2 = SIGNED(ctx->r5) < 0X10A ? 1 : 0;
    // beq         $v0, $zero, L_8001490C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001490C;
    }
    // nop

    // bgez        $a1, L_800148D4
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_800148D4;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // addiu       $v0, $a1, 0x1F
    ctx->r2 = ADD32(ctx->r5, 0X1F);
L_800148D4:
    // sra         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) >> 5;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // lw          $v1, 0x70($v1)
    ctx->r3 = MEM_W(0X70, ctx->r3);
    // sllv        $v0, $t1, $v0
    ctx->r2 = S32(ctx->r9) << (ctx->r2 & 31);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // bne         $v1, $zero, L_8001490C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8001490C;
    }
    // nop

    // lhu         $v0, 0x28($t0)
    ctx->r2 = MEM_HU(0X28, ctx->r8);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r2;
L_8001490C:
    // bgez        $a1, L_80014918
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
        goto L_80014918;
    }
    // addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // addiu       $v1, $a1, 0x1F
    ctx->r3 = ADD32(ctx->r5, 0X1F);
L_80014918:
    // sra         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) >> 5;
    // sll         $a0, $v1, 5
    ctx->r4 = S32(ctx->r3) << 5;
    // subu        $a0, $a1, $a0
    ctx->r4 = SUB32(ctx->r5, ctx->r4);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // lw          $v0, 0x70($v1)
    ctx->r2 = MEM_W(0X70, ctx->r3);
    // sllv        $a0, $t1, $a0
    ctx->r4 = S32(ctx->r9) << (ctx->r4 & 31);
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // sw          $v0, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->r2;
    // slti        $v0, $a1, 0x13A
    ctx->r2 = SIGNED(ctx->r5) < 0X13A ? 1 : 0;
    // bne         $v0, $zero, L_8001488C
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2C
        ctx->r6 = ADD32(ctx->r6, 0X2C);
        goto L_8001488C;
    }
    // addiu       $a2, $a2, 0x2C
    ctx->r6 = ADD32(ctx->r6, 0X2C);
L_8001494C:
    // lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(0X18, ctx->r29);
    // nop

    // beq         $t3, $zero, L_8001499C
    if (ctx->r11 == 0) {
        // lui         $s0, 0x801D
        ctx->r16 = S32(0X801D << 16);
        goto L_8001499C;
    }
    // lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // addiu       $s0, $s0, -0x313C
    ctx->r16 = ADD32(ctx->r16, -0X313C);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    sub_80014D5C(rdram, ctx);
    goto after_12;
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_12:
    // addiu       $a0, $s0, -0x14
    ctx->r4 = ADD32(ctx->r16, -0X14);
    // addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    sub_80014D5C(rdram, ctx);
    goto after_13;
    // addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_13:
    // addiu       $a0, $zero, -0x4001
    ctx->r4 = ADD32(0, -0X4001);
    // lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(0X10, ctx->r16);
    // lw          $v1, -0x4($s0)
    ctx->r3 = MEM_W(-0X4, ctx->r16);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // sw          $v1, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r3;
L_8001499C:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x70D8
    ctx->r16 = ADD32(ctx->r16, -0X70D8);
    // lhu         $a0, 0x3E($s0)
    ctx->r4 = MEM_HU(0X3E, ctx->r16);
    // jal         0x8003F12C
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_8003F12C(rdram, ctx);
    goto after_14;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_14:
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // lhu         $a0, 0x58($s0)
    ctx->r4 = MEM_HU(0X58, ctx->r16);
    // jal         0x8003F12C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_8003F12C(rdram, ctx);
    goto after_15;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_15:
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // lhu         $a0, 0x40($s0)
    ctx->r4 = MEM_HU(0X40, ctx->r16);
    // jal         0x8003F12C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_8003F12C(rdram, ctx);
    goto after_16;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_16:
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // lhu         $a0, 0x5A($s0)
    ctx->r4 = MEM_HU(0X5A, ctx->r16);
    // jal         0x8003F12C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_8003F12C(rdram, ctx);
    goto after_17;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_17:
    // lhu         $a0, 0x44($s0)
    ctx->r4 = MEM_HU(0X44, ctx->r16);
    // jal         0x8003EE38
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_8003EE38(rdram, ctx);
    goto after_18;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_18:
    // lhu         $a0, 0x50($s0)
    ctx->r4 = MEM_HU(0X50, ctx->r16);
    // jal         0x8003EE38
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sub_8003EE38(rdram, ctx);
    goto after_19;
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
    // lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(0X40, ctx->r29);
    // lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(0X3C, ctx->r29);
    // lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(0X38, ctx->r29);
    // lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
