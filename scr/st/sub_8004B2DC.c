#include "recomp.h"
#include "disable_warnings.h"

void sub_8004B2DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a1, $v0, -0x5EC8
    ctx->r5 = ADD32(ctx->r2, -0X5EC8);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $s1, 0x6138($a1)
    ctx->r17 = MEM_W(0X6138, ctx->r5);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lbu         $v1, 0x5($s1)
    ctx->r3 = MEM_BU(0X5, ctx->r17);
    // lw          $s3, 0x6134($a1)
    ctx->r19 = MEM_W(0X6134, ctx->r5);
    // beq         $v1, $v0, L_8004B510
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_8004B510;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8004B32C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8004B32C;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $v1, $zero, L_8004B33C
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8004B33C;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // j           L_8004B5B8
    // nop

    goto L_8004B5B8;
    // nop

L_8004B32C:
    // beq         $v1, $v0, L_8004B554
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004B554;
    }
    // nop

    // j           L_8004B5B8
    // nop

    goto L_8004B5B8;
    // nop

L_8004B33C:
    // lbu         $v1, 0x7($s1)
    ctx->r3 = MEM_BU(0X7, ctx->r17);
    // nop

    // bne         $v1, $v0, L_8004B360
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004B360;
    }
    // nop

    // lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(0X40, ctx->r17);
    // nop

    // slti        $v0, $v0, 0x7000
    ctx->r2 = SIGNED(ctx->r2) < 0X7000 ? 1 : 0;
    // bne         $v0, $zero, L_8004B3C4
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_8004B3C4;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
L_8004B360:
    // lbu         $v1, 0x6168($a1)
    ctx->r3 = MEM_BU(0X6168, ctx->r5);
    // lhu         $v0, 0x6158($a1)
    ctx->r2 = MEM_HU(0X6158, ctx->r5);
    // nop

    // bne         $v1, $v0, L_8004B3A4
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_8004B3A4;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lhu         $v0, 0x615A($a1)
    ctx->r2 = MEM_HU(0X615A, ctx->r5);
    // nop

    // bne         $v1, $v0, L_8004B3A4
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_8004B3A4;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lhu         $v0, 0x615C($a1)
    ctx->r2 = MEM_HU(0X615C, ctx->r5);
    // nop

    // bne         $v1, $v0, L_8004B3A4
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_8004B3A4;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lhu         $v0, 0x615E($a1)
    ctx->r2 = MEM_HU(0X615E, ctx->r5);
    // nop

    // beq         $v1, $v0, L_8004B5B8
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_8004B5B8;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
L_8004B3A4:
    // lbu         $v1, 0x2A0($v0)
    ctx->r3 = MEM_BU(0X2A0, ctx->r2);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8004B5B8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004B5B8;
    }
    // nop

    // lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(0X7, ctx->r17);
    // nop

    // bne         $v1, $v0, L_8004B5B8
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_8004B5B8;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
L_8004B3C4:
    // addiu       $s2, $v0, -0x5EC8
    ctx->r18 = ADD32(ctx->r2, -0X5EC8);
    // lbu         $v1, 0xD($s1)
    ctx->r3 = MEM_BU(0XD, ctx->r17);
    // lw          $v0, 0x6128($s2)
    ctx->r2 = MEM_W(0X6128, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, 0x65
    ctx->r2 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
    // bne         $v0, $zero, L_8004B3F8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004B3F8;
    }
    // nop

    // lw          $v0, 0x6144($s2)
    ctx->r2 = MEM_W(0X6144, ctx->r18);
    // nop

    // slti        $v0, $v0, 0x20
    ctx->r2 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // bne         $v0, $zero, L_8004B5B8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004B5B8;
    }
    // nop

L_8004B3F8:
    // lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(0X40, ctx->r17);
    // nop

    // slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // beq         $v0, $zero, L_8004B420
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004B420;
    }
    // nop

    // lw          $v0, 0x6144($s2)
    ctx->r2 = MEM_W(0X6144, ctx->r18);
    // nop

    // slti        $v0, $v0, 0x38
    ctx->r2 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
    // bne         $v0, $zero, L_8004B5B8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004B5B8;
    }
    // nop

L_8004B420:
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // beq         $v0, $zero, L_8004B5B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004B5B8;
    }
    // nop

    // jal         0x80078AC4
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    rand_recomp(rdram, ctx);
    goto after_0;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_0:
    // lui         $v1, 0xC86A
    ctx->r3 = S32(0XC86A << 16);
    // ori         $v1, $v1, 0x7891
    ctx->r3 = ctx->r3 | 0X7891;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $a2
    ctx->r6 = hi;
    // addu        $v1, $a2, $v0
    ctx->r3 = ADD32(ctx->r6, ctx->r2);
    // sra         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) >> 8;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // slt         $s0, $s0, $v1
    ctx->r16 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $s0, $zero, L_8004B4E4
    if (ctx->r16 != 0) {
        // nop
    
        goto L_8004B4E4;
    }
    // nop

    // lhu         $v1, 0x12($s3)
    ctx->r3 = MEM_HU(0X12, ctx->r19);
    // lw          $v0, 0x612C($s2)
    ctx->r2 = MEM_W(0X612C, ctx->r18);
    // lw          $a0, 0x6138($s2)
    ctx->r4 = MEM_W(0X6138, ctx->r18);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x612C($s2)
    MEM_W(0X612C, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xD($s1)
    ctx->r3 = MEM_BU(0XD, ctx->r17);
    // lw          $v0, 0x6128($s2)
    ctx->r2 = MEM_W(0X6128, ctx->r18);
    // lw          $a1, 0x6134($s2)
    ctx->r5 = MEM_W(0X6134, ctx->r18);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x8004AF24
    // sw          $v0, 0x6128($s2)
    MEM_W(0X6128, ctx->r18) = ctx->r2;
    sub_8004AF24(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x6128($s2)
    MEM_W(0X6128, ctx->r18) = ctx->r2;
    after_1:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = ctx->r2;
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // sh          $v0, 0x60($s1)
    MEM_H(0X60, ctx->r17) = ctx->r2;
    // sh          $v0, 0x54($s1)
    MEM_H(0X54, ctx->r17) = ctx->r2;
    // sw          $zero, 0x44($s1)
    MEM_W(0X44, ctx->r17) = 0;
    // lw          $v0, 0x1C($s3)
    ctx->r2 = MEM_W(0X1C, ctx->r19);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8004B4C0
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x80
        ctx->r2 = ADD32(0, 0X80);
        goto L_8004B4C0;
    }
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sw          $v0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->r2;
L_8004B4C0:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v0, 0x592C($v0)
    ctx->r2 = MEM_W(0X592C, ctx->r2);
    // nop

    // lw          $v0, 0x40($v0)
    ctx->r2 = MEM_W(0X40, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_8004B5B8
    // nop

    goto L_8004B5B8;
    // nop

L_8004B4E4:
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // beq         $v0, $zero, L_8004B5B8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004B5B8;
    }
    // nop

    // lw          $v0, 0x6144($s2)
    ctx->r2 = MEM_W(0X6144, ctx->r18);
    // nop

    // slti        $v0, $v0, 0x20
    ctx->r2 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // beq         $v0, $zero, L_8004B5B8
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFD
        ctx->r2 = ADD32(0, 0XFD);
        goto L_8004B5B8;
    }
    // addiu       $v0, $zero, 0xFD
    ctx->r2 = ADD32(0, 0XFD);
    // j           L_8004B5B8
    // sb          $v0, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r2;
    goto L_8004B5B8;
    // sb          $v0, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r2;
L_8004B510:
    // lbu         $v1, 0x6168($a1)
    ctx->r3 = MEM_BU(0X6168, ctx->r5);
    // addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // beq         $v1, $a0, L_8004B5B8
    if (ctx->r3 == ctx->r4) {
        // nop
    
        goto L_8004B5B8;
    }
    // nop

    // lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(0X7, ctx->r17);
    // nop

    // beq         $v1, $v0, L_8004B5B8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004B5B8;
    }
    // nop

    // bne         $v0, $a0, L_8004B588
    if (ctx->r2 != ctx->r4) {
        // nop
    
        goto L_8004B588;
    }
    // nop

    // lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(0X40, ctx->r17);
    // nop

    // slti        $v0, $v0, 0x7000
    ctx->r2 = SIGNED(ctx->r2) < 0X7000 ? 1 : 0;
    // beq         $v0, $zero, L_8004B588
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004B588;
    }
    // nop

    // j           L_8004B5B8
    // nop

    goto L_8004B5B8;
    // nop

L_8004B554:
    // lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(0X40, ctx->r17);
    // nop

    // slti        $v0, $v0, 0x7000
    ctx->r2 = SIGNED(ctx->r2) < 0X7000 ? 1 : 0;
    // beq         $v0, $zero, L_8004B588
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8004B588;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // lbu         $v1, 0x6168($a1)
    ctx->r3 = MEM_BU(0X6168, ctx->r5);
    // nop

    // beq         $v1, $v0, L_8004B5B8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004B5B8;
    }
    // nop

    // lbu         $v0, 0x7($s1)
    ctx->r2 = MEM_BU(0X7, ctx->r17);
    // nop

    // beq         $v1, $v0, L_8004B5B8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004B5B8;
    }
    // nop

L_8004B588:
    // lhu         $v1, 0x12($s3)
    ctx->r3 = MEM_HU(0X12, ctx->r19);
    // lw          $v0, 0x612C($a1)
    ctx->r2 = MEM_W(0X612C, ctx->r5);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x612C($a1)
    MEM_W(0X612C, ctx->r5) = ctx->r2;
    // lbu         $v1, 0xD($s1)
    ctx->r3 = MEM_BU(0XD, ctx->r17);
    // lw          $v0, 0x6128($a1)
    ctx->r2 = MEM_W(0X6128, ctx->r5);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x6128($a1)
    MEM_W(0X6128, ctx->r5) = ctx->r2;
    // jal         0x8004AC38
    // sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    sub_8004AC38(rdram, ctx);
    goto after_3;
    // sb          $zero, 0x5($a0)
    MEM_B(0X5, ctx->r4) = 0;
    after_3:
L_8004B5B8:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
