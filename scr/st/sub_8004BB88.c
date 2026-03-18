#include "recomp.h"
#include "disable_warnings.h"

void sub_8004BB88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // lui         $fp, 0x7FFF
    ctx->r30 = S32(0X7FFF << 16);
    // ori         $fp, $fp, 0xFFFF
    ctx->r30 = ctx->r30 | 0XFFFF;
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // andi        $s3, $a1, 0x5
    ctx->r19 = ctx->r5 & 0X5;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // addiu       $s6, $v0, -0x5EC8
    ctx->r22 = ADD32(ctx->r2, -0X5EC8);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // addiu       $s7, $v0, -0x70D8
    ctx->r23 = ADD32(ctx->r2, -0X70D8);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addiu       $s2, $s6, 0x30
    ctx->r18 = ADD32(ctx->r22, 0X30);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
L_8004BBE8:
    // lbu         $a0, -0x2B($s2)
    ctx->r4 = MEM_BU(-0X2B, ctx->r18);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $a0, $v0, L_8004BE2C
    if (ctx->r4 != ctx->r2) {
        // lui         $a3, 0x801C
        ctx->r7 = S32(0X801C << 16);
        goto L_8004BE2C;
    }
    // lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // addiu       $a3, $a3, -0x5EC8
    ctx->r7 = ADD32(ctx->r7, -0X5EC8);
    // lbu         $v1, 0x6101($a3)
    ctx->r3 = MEM_BU(0X6101, ctx->r7);
    // lw          $v0, 0x40($s2)
    ctx->r2 = MEM_W(0X40, ctx->r18);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8004BE2C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004BE2C;
    }
    // nop

    // lw          $v0, 0x6138($a3)
    ctx->r2 = MEM_W(0X6138, ctx->r7);
    // nop

    // beq         $s6, $v0, L_8004BE2C
    if (ctx->r22 == ctx->r2) {
        // lui         $a3, 0x801C
        ctx->r7 = S32(0X801C << 16);
        goto L_8004BE2C;
    }
    // lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // lbu         $v1, -0x2E($s2)
    ctx->r3 = MEM_BU(-0X2E, ctx->r18);
    // addiu       $a3, $a3, -0x29C8
    ctx->r7 = ADD32(ctx->r7, -0X29C8);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // bne         $s3, $a0, L_8004BC78
    if (ctx->r19 != ctx->r4) {
        // addu        $s0, $v0, $a3
        ctx->r16 = ADD32(ctx->r2, ctx->r7);
        goto L_8004BC78;
    }
    // addu        $s0, $v0, $a3
    ctx->r16 = ADD32(ctx->r2, ctx->r7);
    // lw          $v1, 0x44($s2)
    ctx->r3 = MEM_W(0X44, ctx->r18);
    // lw          $a0, 0x248($s7)
    ctx->r4 = MEM_W(0X248, ctx->r23);
    // lw          $v0, 0x4C($s2)
    ctx->r2 = MEM_W(0X4C, ctx->r18);
    // lw          $a1, 0x250($s7)
    ctx->r5 = MEM_W(0X250, ctx->r23);
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
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // lh          $a0, 0x27A($s7)
    ctx->r4 = MEM_HS(0X27A, ctx->r23);
    // jal         0x8004A148
    // addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    sub_8004A148(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    after_1:
    // beq         $v0, $zero, L_8004BE2C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004BE2C;
    }
    // nop

L_8004BC78:
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // bne         $s3, $v0, L_8004BCBC
    if (ctx->r19 != ctx->r2) {
        // nop
    
        goto L_8004BCBC;
    }
    // nop

    // lw          $v1, 0x44($s2)
    ctx->r3 = MEM_W(0X44, ctx->r18);
    // lw          $a0, 0x248($s7)
    ctx->r4 = MEM_W(0X248, ctx->r23);
    // lw          $v0, 0x4C($s2)
    ctx->r2 = MEM_W(0X4C, ctx->r18);
    // lw          $a1, 0x250($s7)
    ctx->r5 = MEM_W(0X250, ctx->r23);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x8004A1B4
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    sub_8004A1B4(rdram, ctx);
    goto after_2;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_2:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // lh          $a0, 0x27A($s7)
    ctx->r4 = MEM_HS(0X27A, ctx->r23);
    // jal         0x8004A148
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    sub_8004A148(rdram, ctx);
    goto after_3;
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    after_3:
    // beq         $v0, $zero, L_8004BE2C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004BE2C;
    }
    // nop

L_8004BCBC:
    // lhu         $v0, 0x16($s0)
    ctx->r2 = MEM_HU(0X16, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8004BE2C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004BE2C;
    }
    // nop

    // lw          $v1, 0x44($s2)
    ctx->r3 = MEM_W(0X44, ctx->r18);
    // lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(0X4, ctx->r21);
    // nop

    // subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
    // addiu       $v0, $s1, 0x2800
    ctx->r2 = ADD32(ctx->r17, 0X2800);
    // sltiu       $v0, $v0, 0x5001
    ctx->r2 = ctx->r2 < 0X5001 ? 1 : 0;
    // beq         $v0, $zero, L_8004BE2C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004BE2C;
    }
    // nop

    // lw          $v1, 0x4C($s2)
    ctx->r3 = MEM_W(0X4C, ctx->r18);
    // lw          $v0, 0xC($s5)
    ctx->r2 = MEM_W(0XC, ctx->r21);
    // nop

    // subu        $s0, $v1, $v0
    ctx->r16 = SUB32(ctx->r3, ctx->r2);
    // addiu       $v0, $s0, 0x2800
    ctx->r2 = ADD32(ctx->r16, 0X2800);
    // sltiu       $v0, $v0, 0x5001
    ctx->r2 = ctx->r2 < 0X5001 ? 1 : 0;
    // beq         $v0, $zero, L_8004BE2C
    if (ctx->r2 == 0) {
        // mult        $s1, $s1
        result = S64(S32(ctx->r17)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_8004BE2C;
    }
    // mult        $s1, $s1
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // mult        $s0, $s0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // jal         0x800746C4
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    SquareRoot0(rdram, ctx);
    goto after_4;
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    after_4:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x80076EA4
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    ratan2(rdram, ctx);
    goto after_5;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_5:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lh          $a0, 0x20($s5)
    ctx->r4 = MEM_HS(0X20, ctx->r21);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // jal         0x800744C4
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    rcos(rdram, ctx);
    goto after_6;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    after_6:
    // lh          $v1, 0x22($s5)
    ctx->r3 = MEM_HS(0X22, ctx->r21);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8004BD68
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8004BD68;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8004BD68:
    // lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(0X44, ctx->r29);
    // nop

    // andi        $v0, $a3, 0x2
    ctx->r2 = ctx->r7 & 0X2;
    // beq         $v0, $zero, L_8004BD94
    if (ctx->r2 == 0) {
        // sra         $a1, $v1, 12
        ctx->r5 = S32(ctx->r3) >> 12;
        goto L_8004BD94;
    }
    // sra         $a1, $v1, 12
    ctx->r5 = S32(ctx->r3) >> 12;
    // lhu         $v0, -0x2($s2)
    ctx->r2 = MEM_HU(-0X2, ctx->r18);
    // lhu         $v1, 0x1C($s5)
    ctx->r3 = MEM_HU(0X1C, ctx->r21);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // j           L_8004BDA4
    // addiu       $v1, $v0, 0x200
    ctx->r3 = ADD32(ctx->r2, 0X200);
    goto L_8004BDA4;
    // addiu       $v1, $v0, 0x200
    ctx->r3 = ADD32(ctx->r2, 0X200);
L_8004BD94:
    // lhu         $v1, -0x2($s2)
    ctx->r3 = MEM_HU(-0X2, ctx->r18);
    // lhu         $v0, 0x1C($s5)
    ctx->r2 = MEM_HU(0X1C, ctx->r21);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_8004BDA4:
    // subu        $v0, $s0, $a1
    ctx->r2 = SUB32(ctx->r16, ctx->r5);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8004BE2C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004BE2C;
    }
    // nop

    // lw          $a0, 0x48($s2)
    ctx->r4 = MEM_W(0X48, ctx->r18);
    // lw          $v1, 0x8($s5)
    ctx->r3 = MEM_W(0X8, ctx->r21);
    // nop

    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8004BDE0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004BDE0;
    }
    // nop

    // lhu         $v0, 0x1E($s5)
    ctx->r2 = MEM_HU(0X1E, ctx->r21);
    // nop

    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // j           L_8004BDF0
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    goto L_8004BDF0;
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
L_8004BDE0:
    // lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(0X0, ctx->r18);
    // nop

    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_8004BDF0:
    // beq         $v0, $zero, L_8004BE08
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004BE08;
    }
    // nop

    // bne         $s3, $zero, L_8004BE30
    if (ctx->r19 != 0) {
        // addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_8004BE30;
    }
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // j           L_8004BE4C
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8004BE4C;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8004BE08:
    // bne         $s3, $zero, L_8004BE18
    if (ctx->r19 != 0) {
        // subu        $v1, $s0, $a1
        ctx->r3 = SUB32(ctx->r16, ctx->r5);
        goto L_8004BE18;
    }
    // subu        $v1, $s0, $a1
    ctx->r3 = SUB32(ctx->r16, ctx->r5);
    // j           L_8004BE4C
    // addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    goto L_8004BE4C;
    // addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
L_8004BE18:
    // slt         $v0, $v1, $fp
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r30) ? 1 : 0;
    // beq         $v0, $zero, L_8004BE2C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8004BE2C;
    }
    // nop

    // addu        $fp, $v1, $zero
    ctx->r30 = ADD32(ctx->r3, 0);
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
L_8004BE2C:
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8004BE30:
    // addiu       $s2, $s2, 0xD4
    ctx->r18 = ADD32(ctx->r18, 0XD4);
    // slti        $v0, $s4, 0x40
    ctx->r2 = SIGNED(ctx->r20) < 0X40 ? 1 : 0;
    // bne         $v0, $zero, L_8004BBE8
    if (ctx->r2 != 0) {
        // addiu       $s6, $s6, 0xD4
        ctx->r22 = ADD32(ctx->r22, 0XD4);
        goto L_8004BBE8;
    }
    // addiu       $s6, $s6, 0xD4
    ctx->r22 = ADD32(ctx->r22, 0XD4);
    // beq         $s3, $zero, L_8004BE4C
    if (ctx->r19 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8004BE4C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
L_8004BE4C:
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(0X38, ctx->r29);
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
