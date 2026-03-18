#include "recomp.h"
#include "disable_warnings.h"

void sub_8004E324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $a1, -0x6F64($v0)
    ctx->r5 = MEM_W(-0X6F64, ctx->r2);
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // beq         $a1, $zero, L_8004E4EC
    if (ctx->r5 == 0) {
        // sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
        goto L_8004E4EC;
    }
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lbu         $v1, 0x7($a1)
    ctx->r3 = MEM_BU(0X7, ctx->r5);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8004E4EC
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_8004E4EC;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x5EC8
    ctx->r2 = ADD32(ctx->r2, -0X5EC8);
    // lbu         $a0, 0x6168($v0)
    ctx->r4 = MEM_BU(0X6168, ctx->r2);
    // nop

    // sb          $a0, 0x6103($v0)
    MEM_B(0X6103, ctx->r2) = ctx->r4;
    // lbu         $v1, 0x7($a1)
    ctx->r3 = MEM_BU(0X7, ctx->r5);
    // nop

    // beq         $a0, $v1, L_8004E4EC
    if (ctx->r4 == ctx->r3) {
        // sb          $v1, 0x6168($v0)
        MEM_B(0X6168, ctx->r2) = ctx->r3;
        goto L_8004E4EC;
    }
    // sb          $v1, 0x6168($v0)
    MEM_B(0X6168, ctx->r2) = ctx->r3;
    // jal         0x800341A0
    // addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
    sub_800341A0(rdram, ctx);
    goto after_0;
    // addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
    after_0:
    // jal         0x8003509C
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    sub_8003509C(rdram, ctx);
    goto after_1;
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    after_1:
    // jal         0x80034224
    // nop

    sub_80034224(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x80035120
    // nop

    sub_80035120(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
L_8004E3AC:
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // jal         0x80033DB8
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    sub_80033DB8(rdram, ctx);
    goto after_4;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_4:
    // lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(0X10, ctx->r29);
    // nop

    // beq         $a0, $zero, L_8004E3D0
    if (ctx->r4 == 0) {
        // nop
    
        goto L_8004E3D0;
    }
    // nop

    // jal         0x80015230
    // nop

    sub_80015230(rdram, ctx);
    goto after_5;
    // nop

    after_5:
L_8004E3D0:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $s1, L_8004E3AC
    if (ctx->r16 != ctx->r17) {
        // addiu       $a0, $s0, 0x80
        ctx->r4 = ADD32(ctx->r16, 0X80);
        goto L_8004E3AC;
    }
    // addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    // jal         0x8004E2D8
    // addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
    sub_8004E2D8(rdram, ctx);
    goto after_6;
    // addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
    after_6:
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
L_8004E3EC:
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // jal         0x80033DB8
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    sub_80033DB8(rdram, ctx);
    goto after_7;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_7:
    // lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(0X10, ctx->r29);
    // nop

    // beq         $a0, $zero, L_8004E410
    if (ctx->r4 == 0) {
        // nop
    
        goto L_8004E410;
    }
    // nop

    // jal         0x80015230
    // nop

    sub_80015230(rdram, ctx);
    goto after_8;
    // nop

    after_8:
L_8004E410:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $s1, L_8004E3EC
    if (ctx->r16 != ctx->r17) {
        // addiu       $a0, $s0, 0x70
        ctx->r4 = ADD32(ctx->r16, 0X70);
        goto L_8004E3EC;
    }
    // addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s3, $v0, -0x5EC8
    ctx->r19 = ADD32(ctx->r2, -0X5EC8);
    // sw          $zero, 0x6144($s3)
    MEM_W(0X6144, ctx->r19) = 0;
    // addiu       $s4, $s3, 0x3500
    ctx->r20 = ADD32(ctx->r19, 0X3500);
    // addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    // addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // addiu       $s0, $s3, 0x5
    ctx->r16 = ADD32(ctx->r19, 0X5);
L_8004E438:
    // lbu         $v1, -0x3($s0)
    ctx->r3 = MEM_BU(-0X3, ctx->r16);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // addu        $a0, $v0, $s4
    ctx->r4 = ADD32(ctx->r2, ctx->r20);
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8004E4CC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004E4CC;
    }
    // nop

    // lbu         $v1, 0x6168($s1)
    ctx->r3 = MEM_BU(0X6168, ctx->r17);
    // nop

    // beq         $v1, $s2, L_8004E4F0
    if (ctx->r3 == ctx->r18) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_8004E4F0;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(0X2, ctx->r16);
    // nop

    // beq         $v1, $v0, L_8004E4CC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004E4CC;
    }
    // nop

    // bne         $v0, $s2, L_8004E49C
    if (ctx->r2 != ctx->r18) {
        // nop
    
        goto L_8004E49C;
    }
    // nop

    // lw          $v0, 0x3B($s0)
    ctx->r2 = MEM_W(0X3B, ctx->r16);
    // nop

    // slti        $v0, $v0, 0x7000
    ctx->r2 = SIGNED(ctx->r2) < 0X7000 ? 1 : 0;
    // bne         $v0, $zero, L_8004E4F0
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_8004E4F0;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
L_8004E49C:
    // lhu         $v1, 0x12($a0)
    ctx->r3 = MEM_HU(0X12, ctx->r4);
    // lw          $v0, 0x612C($s1)
    ctx->r2 = MEM_W(0X612C, ctx->r17);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x612C($s1)
    MEM_W(0X612C, ctx->r17) = ctx->r2;
    // lbu         $v1, 0x8($s0)
    ctx->r3 = MEM_BU(0X8, ctx->r16);
    // lw          $v0, 0x6128($s1)
    ctx->r2 = MEM_W(0X6128, ctx->r17);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x6128($s1)
    MEM_W(0X6128, ctx->r17) = ctx->r2;
    // jal         0x8004AC38
    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    sub_8004AC38(rdram, ctx);
    goto after_9;
    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    after_9:
L_8004E4CC:
    // addiu       $s0, $s0, 0xD4
    ctx->r16 = ADD32(ctx->r16, 0XD4);
    // lw          $v0, 0x6144($s1)
    ctx->r2 = MEM_W(0X6144, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x6144($s1)
    MEM_W(0X6144, ctx->r17) = ctx->r2;
    // slti        $v0, $v0, 0x40
    ctx->r2 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // bne         $v0, $zero, L_8004E438
    if (ctx->r2 != 0) {
        // addiu       $s3, $s3, 0xD4
        ctx->r19 = ADD32(ctx->r19, 0XD4);
        goto L_8004E438;
    }
    // addiu       $s3, $s3, 0xD4
    ctx->r19 = ADD32(ctx->r19, 0XD4);
L_8004E4EC:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
L_8004E4F0:
    // addiu       $v0, $v0, -0x5EC8
    ctx->r2 = ADD32(ctx->r2, -0X5EC8);
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s5, $v0, -0x70D8
    ctx->r21 = ADD32(ctx->r2, -0X70D8);
    // ori         $s6, $zero, 0x8000
    ctx->r22 = 0 | 0X8000;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $s7, $v0, 0x5920
    ctx->r23 = ADD32(ctx->r2, 0X5920);
    // addu        $s4, $s3, $zero
    ctx->r20 = ADD32(ctx->r19, 0);
    // addiu       $s0, $s4, 0x23
    ctx->r16 = ADD32(ctx->r20, 0X23);
    // sw          $zero, 0x614C($s3)
    MEM_W(0X614C, ctx->r19) = 0;
    // sw          $zero, 0x6144($s3)
    MEM_W(0X6144, ctx->r19) = 0;
L_8004E51C:
    // lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(0X0, ctx->r19);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8004E7C0
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004E7C0;
    }
    // nop

    // jal         0x8004C03C
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8004C03C(rdram, ctx);
    goto after_10;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_10:
    // lw          $v1, 0x51($s0)
    ctx->r3 = MEM_W(0X51, ctx->r16);
    // lw          $v0, 0x248($s5)
    ctx->r2 = MEM_W(0X248, ctx->r21);
    // lw          $a1, 0x55($s0)
    ctx->r5 = MEM_W(0X55, ctx->r16);
    // lw          $a0, 0x59($s0)
    ctx->r4 = MEM_W(0X59, ctx->r16);
    // subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
    // lw          $v1, 0x24C($s5)
    ctx->r3 = MEM_W(0X24C, ctx->r21);
    // lw          $v0, 0x250($s5)
    ctx->r2 = MEM_W(0X250, ctx->r21);
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // subu        $s1, $a0, $v0
    ctx->r17 = SUB32(ctx->r4, ctx->r2);
    // addu        $v1, $s2, $s6
    ctx->r3 = ADD32(ctx->r18, ctx->r22);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8004E59C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x4000
        ctx->r2 = S32(0X4000 << 16);
        goto L_8004E59C;
    }
    // lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // slt         $v0, $s6, $a1
    ctx->r2 = SIGNED(ctx->r22) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_8004E59C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x4000
        ctx->r2 = S32(0X4000 << 16);
        goto L_8004E59C;
    }
    // lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // slti        $v0, $a1, -0x8000
    ctx->r2 = SIGNED(ctx->r5) < -0X8000 ? 1 : 0;
    // bne         $v0, $zero, L_8004E59C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x4000
        ctx->r2 = S32(0X4000 << 16);
        goto L_8004E59C;
    }
    // lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // slt         $v0, $s6, $s1
    ctx->r2 = SIGNED(ctx->r22) < SIGNED(ctx->r17) ? 1 : 0;
    // bne         $v0, $zero, L_8004E59C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x4000
        ctx->r2 = S32(0X4000 << 16);
        goto L_8004E59C;
    }
    // lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
    // slti        $v0, $s1, -0x8000
    ctx->r2 = SIGNED(ctx->r17) < -0X8000 ? 1 : 0;
    // beq         $v0, $zero, L_8004E5A8
    if (ctx->r2 == 0) {
        // lui         $v0, 0x4000
        ctx->r2 = S32(0X4000 << 16);
        goto L_8004E5A8;
    }
    // lui         $v0, 0x4000
    ctx->r2 = S32(0X4000 << 16);
L_8004E59C:
    // sw          $v0, 0x19($s0)
    MEM_W(0X19, ctx->r16) = ctx->r2;
    // j           L_8004E5E8
    // sw          $s6, 0x1D($s0)
    MEM_W(0X1D, ctx->r16) = ctx->r22;
    goto L_8004E5E8;
    // sw          $s6, 0x1D($s0)
    MEM_W(0X1D, ctx->r16) = ctx->r22;
L_8004E5A8:
    // mult        $s2, $s2
    result = S64(S32(ctx->r18)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // mult        $s1, $s1
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // nop

    // mult        $a1, $a1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // mflo        $a2
    ctx->r6 = lo;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x800746C4
    // sw          $v0, 0x19($s0)
    MEM_W(0X19, ctx->r16) = ctx->r2;
    SquareRoot0(rdram, ctx);
    goto after_11;
    // sw          $v0, 0x19($s0)
    MEM_W(0X19, ctx->r16) = ctx->r2;
    after_11:
    // sw          $v0, 0x1D($s0)
    MEM_W(0X1D, ctx->r16) = ctx->r2;
L_8004E5E8:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80076EA4
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    ratan2(rdram, ctx);
    goto after_12;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_12:
    // addiu       $v0, $v0, -0x400
    ctx->r2 = ADD32(ctx->r2, -0X400);
    // lhu         $v1, 0x6B($s0)
    ctx->r3 = MEM_HU(0X6B, ctx->r16);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sh          $v0, 0x33($s0)
    MEM_H(0X33, ctx->r16) = ctx->r2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // slti        $v0, $v1, 0x801
    ctx->r2 = SIGNED(ctx->r3) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_8004E624
    if (ctx->r2 != 0) {
        // sh          $v1, 0x35($s0)
        MEM_H(0X35, ctx->r16) = ctx->r3;
        goto L_8004E624;
    }
    // sh          $v1, 0x35($s0)
    MEM_H(0X35, ctx->r16) = ctx->r3;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x35($s0)
    MEM_H(0X35, ctx->r16) = ctx->r2;
L_8004E624:
    // sh          $zero, 0x7D($s0)
    MEM_H(0X7D, ctx->r16) = 0;
    // sh          $zero, 0x7B($s0)
    MEM_H(0X7B, ctx->r16) = 0;
    // sh          $zero, 0x79($s0)
    MEM_H(0X79, ctx->r16) = 0;
    // lw          $v1, 0x6150($s4)
    ctx->r3 = MEM_W(0X6150, ctx->r20);
    // lbu         $v0, -0x1C($s0)
    ctx->r2 = MEM_BU(-0X1C, ctx->r16);
    // andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // beq         $v1, $v0, L_8004E658
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8004E658;
    }
    // nop

    // lbu         $v0, 0x21C($s5)
    ctx->r2 = MEM_BU(0X21C, ctx->r21);
    // nop

    // beq         $v0, $zero, L_8004E660
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004E660;
    }
    // nop

L_8004E658:
    // jal         0x8004B2DC
    // nop

    sub_8004B2DC(rdram, ctx);
    goto after_13;
    // nop

    after_13:
L_8004E660:
    // lbu         $v1, -0x1E($s0)
    ctx->r3 = MEM_BU(-0X1E, ctx->r16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8004E7A0
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_8004E7A0;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // lw          $v1, 0x6150($s4)
    ctx->r3 = MEM_W(0X6150, ctx->r20);
    // lw          $v0, 0x614C($s4)
    ctx->r2 = MEM_W(0X614C, ctx->r20);
    // andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // bne         $v1, $v0, L_8004E6A0
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004E6A0;
    }
    // nop

    // lw          $v0, 0xC($s7)
    ctx->r2 = MEM_W(0XC, ctx->r23);
    // nop

    // lw          $v0, 0x40($v0)
    ctx->r2 = MEM_W(0X40, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_14;
    // nop

    after_14:
L_8004E6A0:
    // lw          $v0, 0xC($s7)
    ctx->r2 = MEM_W(0XC, ctx->r23);
    // nop

    // lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(0X44, ctx->r2);
    // nop

    // jalr        $v0
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_15;
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    after_15:
    // lh          $v0, 0x13($s0)
    ctx->r2 = MEM_HS(0X13, ctx->r16);
    // nop

    // beq         $v0, $s1, L_8004E710
    if (ctx->r2 == ctx->r17) {
        // addiu       $a1, $sp, 0x14
        ctx->r5 = ADD32(ctx->r29, 0X14);
        goto L_8004E710;
    }
    // addiu       $a1, $sp, 0x14
    ctx->r5 = ADD32(ctx->r29, 0X14);
    // lbu         $a0, -0x18($s0)
    ctx->r4 = MEM_BU(-0X18, ctx->r16);
    // jal         0x80033DB8
    // addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    sub_80033DB8(rdram, ctx);
    goto after_16;
    // addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_16:
    // lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(0X14, ctx->r29);
    // nop

    // beq         $v0, $zero, L_8004E710
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004E710;
    }
    // nop

    // lhu         $v0, 0x13($s0)
    ctx->r2 = MEM_HU(0X13, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // sh          $v0, 0x13($s0)
    MEM_H(0X13, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_8004E710
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8004E710;
    }
    // nop

    // lbu         $v0, -0x5($s0)
    ctx->r2 = MEM_BU(-0X5, ctx->r16);
    // sh          $s1, 0x13($s0)
    MEM_H(0X13, ctx->r16) = ctx->r17;
    // andi        $v0, $v0, 0xF2
    ctx->r2 = ctx->r2 & 0XF2;
    // sb          $v0, -0x5($s0)
    MEM_B(-0X5, ctx->r16) = ctx->r2;
L_8004E710:
    // lw          $v0, 0x79($s0)
    ctx->r2 = MEM_W(0X79, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8004E740
    if (ctx->r2 != 0) {
        // sb          $zero, 0x16($s0)
        MEM_B(0X16, ctx->r16) = 0;
        goto L_8004E740;
    }
    // sb          $zero, 0x16($s0)
    MEM_B(0X16, ctx->r16) = 0;
    // lh          $v0, 0x7D($s0)
    ctx->r2 = MEM_HS(0X7D, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8004E740
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004E740;
    }
    // nop

    // lh          $v0, -0xD($s0)
    ctx->r2 = MEM_HS(-0XD, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8004E78C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004E78C;
    }
    // nop

L_8004E740:
    // jal         0x8004C1B4
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_8004C1B4(rdram, ctx);
    goto after_17;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_17:
    // lw          $v0, 0x2C($s5)
    ctx->r2 = MEM_W(0X2C, ctx->r21);
    // lui         $v1, 0x4
    ctx->r3 = S32(0X4 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8004E78C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004E78C;
    }
    // nop

    // lh          $v1, 0x79($s0)
    ctx->r3 = MEM_HS(0X79, ctx->r16);
    // lw          $v0, 0x51($s0)
    ctx->r2 = MEM_W(0X51, ctx->r16);
    // lh          $a0, 0x7B($s0)
    ctx->r4 = MEM_HS(0X7B, ctx->r16);
    // lh          $a1, 0x7D($s0)
    ctx->r5 = MEM_HS(0X7D, ctx->r16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x51($s0)
    MEM_W(0X51, ctx->r16) = ctx->r2;
    // lw          $v0, 0x55($s0)
    ctx->r2 = MEM_W(0X55, ctx->r16);
    // lw          $v1, 0x59($s0)
    ctx->r3 = MEM_W(0X59, ctx->r16);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v0, 0x55($s0)
    MEM_W(0X55, ctx->r16) = ctx->r2;
    // sw          $v1, 0x59($s0)
    MEM_W(0X59, ctx->r16) = ctx->r3;
L_8004E78C:
    // lw          $v0, 0x614C($s4)
    ctx->r2 = MEM_W(0X614C, ctx->r20);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8004E7C0
    // sw          $v0, 0x614C($s4)
    MEM_W(0X614C, ctx->r20) = ctx->r2;
    goto L_8004E7C0;
    // sw          $v0, 0x614C($s4)
    MEM_W(0X614C, ctx->r20) = ctx->r2;
L_8004E7A0:
    // bne         $v1, $v0, L_8004E7C0
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8004E7C0;
    }
    // nop

    // lw          $v0, 0xC($s7)
    ctx->r2 = MEM_W(0XC, ctx->r23);
    // nop

    // lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(0X44, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_18;
    // nop

    after_18:
L_8004E7C0:
    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // addiu       $s0, $s0, 0xD4
    ctx->r16 = ADD32(ctx->r16, 0XD4);
    // lw          $v0, 0x6144($s4)
    ctx->r2 = MEM_W(0X6144, ctx->r20);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x6144($s4)
    MEM_W(0X6144, ctx->r20) = ctx->r2;
    // slti        $v0, $v0, 0x40
    ctx->r2 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // bne         $v0, $zero, L_8004E51C
    if (ctx->r2 != 0) {
        // addiu       $s3, $s3, 0xD4
        ctx->r19 = ADD32(ctx->r19, 0XD4);
        goto L_8004E51C;
    }
    // addiu       $s3, $s3, 0xD4
    ctx->r19 = ADD32(ctx->r19, 0XD4);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a2, $v0, -0x5EC8
    ctx->r6 = ADD32(ctx->r2, -0X5EC8);
    // lhu         $v0, 0x615C($a2)
    ctx->r2 = MEM_HU(0X615C, ctx->r6);
    // lhu         $v1, 0x615A($a2)
    ctx->r3 = MEM_HU(0X615A, ctx->r6);
    // lhu         $a0, 0x6158($a2)
    ctx->r4 = MEM_HU(0X6158, ctx->r6);
    // lbu         $a1, 0x6168($a2)
    ctx->r5 = MEM_BU(0X6168, ctx->r6);
    // sh          $v0, 0x615E($a2)
    MEM_H(0X615E, ctx->r6) = ctx->r2;
    // lw          $v0, 0x6150($a2)
    ctx->r2 = MEM_W(0X6150, ctx->r6);
    // sh          $v1, 0x615C($a2)
    MEM_H(0X615C, ctx->r6) = ctx->r3;
    // lhu         $v1, 0x6160($a2)
    ctx->r3 = MEM_HU(0X6160, ctx->r6);
    // sh          $a0, 0x615A($a2)
    MEM_H(0X615A, ctx->r6) = ctx->r4;
    // lhu         $a0, 0x6162($a2)
    ctx->r4 = MEM_HU(0X6162, ctx->r6);
    // sh          $a1, 0x6158($a2)
    MEM_H(0X6158, ctx->r6) = ctx->r5;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 17
    ctx->r3 = S32(ctx->r3) >> 17;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 17
    ctx->r4 = S32(ctx->r4) >> 17;
    // sh          $v1, 0x6160($a2)
    MEM_H(0X6160, ctx->r6) = ctx->r3;
    // bgez        $v1, L_8004E83C
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8004E83C;
    }
    // nop

    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_8004E83C:
    // sw          $v0, 0x6150($a2)
    MEM_W(0X6150, ctx->r6) = ctx->r2;
    // lhu         $v0, 0x6164($a2)
    ctx->r2 = MEM_HU(0X6164, ctx->r6);
    // slti        $v1, $v1, 0x4
    ctx->r3 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // sh          $a0, 0x6162($a2)
    MEM_H(0X6162, ctx->r6) = ctx->r4;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 17
    ctx->r5 = S32(ctx->r2) >> 17;
    // beq         $v1, $zero, L_8004E860
    if (ctx->r3 == 0) {
        // sh          $a1, 0x6164($a2)
        MEM_H(0X6164, ctx->r6) = ctx->r5;
        goto L_8004E860;
    }
    // sh          $a1, 0x6164($a2)
    MEM_H(0X6164, ctx->r6) = ctx->r5;
    // sh          $zero, 0x6160($a2)
    MEM_H(0X6160, ctx->r6) = 0;
L_8004E860:
    // bgez        $a0, L_8004E86C
    if (SIGNED(ctx->r4) >= 0) {
        // addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
        goto L_8004E86C;
    }
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8004E86C:
    // slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8004E87C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004E87C;
    }
    // nop

    // sh          $zero, 0x6162($a2)
    MEM_H(0X6162, ctx->r6) = 0;
L_8004E87C:
    // bgez        $a1, L_8004E888
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
        goto L_8004E888;
    }
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8004E888:
    // slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8004E898
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004E898;
    }
    // nop

    // sh          $zero, 0x6164($a2)
    MEM_H(0X6164, ctx->r6) = 0;
L_8004E898:
    // jal         0x8004C03C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8004C03C(rdram, ctx);
    goto after_19;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_19:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v0, -0x2F1C($v0)
    ctx->r2 = MEM_BU(-0X2F1C, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8004E8BC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004E8BC;
    }
    // nop

    // jal         0x80052C5C
    // nop

    sub_80052C5C(rdram, ctx);
    goto after_20;
    // nop

    after_20:
L_8004E8BC:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
