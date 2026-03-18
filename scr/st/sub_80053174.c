#include "recomp.h"
#include "disable_warnings.h"

void sub_80053174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // lui         $s5, 0x7FFF
    ctx->r21 = S32(0X7FFF << 16);
    // ori         $s5, $s5, 0xFFFF
    ctx->r21 = ctx->r21 | 0XFFFF;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addiu       $s2, $v0, -0x51F8
    ctx->r18 = ADD32(ctx->r2, -0X51F8);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // addiu       $fp, $s2, -0x35F8
    ctx->r30 = ADD32(ctx->r18, -0X35F8);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addiu       $s4, $v0, -0x70D8
    ctx->r20 = ADD32(ctx->r2, -0X70D8);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $s2, 0x10
    ctx->r16 = ADD32(ctx->r18, 0X10);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
L_800531CC:
    // lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(0X12, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80053310
    if (ctx->r2 == 0) {
        // lui         $a3, 0x801B
        ctx->r7 = S32(0X801B << 16);
        goto L_80053310;
    }
    // lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // addiu       $a3, $a3, 0x5920
    ctx->r7 = ADD32(ctx->r7, 0X5920);
    // lbu         $v1, 0x1C($s0)
    ctx->r3 = MEM_BU(0X1C, ctx->r16);
    // lbu         $v0, 0x9($a3)
    ctx->r2 = MEM_BU(0X9, ctx->r7);
    // nop

    // bne         $v1, $v0, L_80053310
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80053310;
    }
    // nop

    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // nop

    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $s3, $v1, $fp
    ctx->r19 = ADD32(ctx->r3, ctx->r30);
    // lbu         $v0, 0x1($s3)
    ctx->r2 = MEM_BU(0X1, ctx->r19);
    // nop

    // beq         $v0, $zero, L_80053310
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80053310;
    }
    // nop

    // lw          $v1, 0x24C($s4)
    ctx->r3 = MEM_W(0X24C, ctx->r20);
    // lw          $a0, -0x4($s0)
    ctx->r4 = MEM_W(-0X4, ctx->r16);
    // addiu       $v0, $v1, -0x400
    ctx->r2 = ADD32(ctx->r3, -0X400);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_80053310
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, 0xA40
        ctx->r2 = ADD32(ctx->r3, 0XA40);
        goto L_80053310;
    }
    // addiu       $v0, $v1, 0xA40
    ctx->r2 = ADD32(ctx->r3, 0XA40);
    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_80053310
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80053310;
    }
    // nop

    // lw          $v1, -0x8($s0)
    ctx->r3 = MEM_W(-0X8, ctx->r16);
    // lw          $a0, 0x248($s4)
    ctx->r4 = MEM_W(0X248, ctx->r20);
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // lw          $a1, 0x250($s4)
    ctx->r5 = MEM_W(0X250, ctx->r20);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x8004A1B4
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    sub_8004A1B4(rdram, ctx);
    goto after_0;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_0:
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // lh          $a0, 0x27A($s4)
    ctx->r4 = MEM_HS(0X27A, ctx->r20);
    // jal         0x8004A148
    // addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    sub_8004A148(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x12C
    ctx->r6 = ADD32(0, 0X12C);
    after_1:
    // beq         $v0, $zero, L_80053310
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80053310;
    }
    // nop

    // lw          $v1, -0x8($s0)
    ctx->r3 = MEM_W(-0X8, ctx->r16);
    // lw          $v0, 0x4($s7)
    ctx->r2 = MEM_W(0X4, ctx->r23);
    // nop

    // subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
    // addiu       $v0, $a0, 0x2800
    ctx->r2 = ADD32(ctx->r4, 0X2800);
    // sltiu       $v0, $v0, 0x5001
    ctx->r2 = ctx->r2 < 0X5001 ? 1 : 0;
    // beq         $v0, $zero, L_80053310
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80053310;
    }
    // nop

    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // lw          $v0, 0xC($s7)
    ctx->r2 = MEM_W(0XC, ctx->r23);
    // nop

    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // addiu       $v0, $v1, 0x2800
    ctx->r2 = ADD32(ctx->r3, 0X2800);
    // sltiu       $v0, $v0, 0x5001
    ctx->r2 = ctx->r2 < 0X5001 ? 1 : 0;
    // beq         $v0, $zero, L_80053310
    if (ctx->r2 == 0) {
        // mult        $a0, $a0
        result = S64(S32(ctx->r4)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80053310;
    }
    // mult        $a0, $a0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // jal         0x800746C4
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    SquareRoot0(rdram, ctx);
    goto after_2;
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    after_2:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // lbu         $v0, 0x1($s3)
    ctx->r2 = MEM_BU(0X1, ctx->r19);
    // lhu         $v1, 0x1C($s7)
    ctx->r3 = MEM_HU(0X1C, ctx->r23);
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80053310
    if (ctx->r2 == 0) {
        // slt         $v0, $a0, $s5
        ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r21) ? 1 : 0;
        goto L_80053310;
    }
    // slt         $v0, $a0, $s5
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r21) ? 1 : 0;
    // beq         $v0, $zero, L_80053310
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80053310;
    }
    // nop

    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // addu        $s6, $s1, $zero
    ctx->r22 = ADD32(ctx->r17, 0);
L_80053310:
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // slti        $v0, $s1, 0x40
    ctx->r2 = SIGNED(ctx->r17) < 0X40 ? 1 : 0;
    // bne         $v0, $zero, L_800531CC
    if (ctx->r2 != 0) {
        // addiu       $s2, $s2, 0x30
        ctx->r18 = ADD32(ctx->r18, 0X30);
        goto L_800531CC;
    }
    // addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
    // addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(0X30, ctx->r29);
    // lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(0X2C, ctx->r29);
    // lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
