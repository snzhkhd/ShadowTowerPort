#include "recomp.h"
#include "disable_warnings.h"

void sub_8001C60C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $a3, $v0, -0x2F70
    ctx->r7 = ADD32(ctx->r2, -0X2F70);
    // addu        $a0, $a3, $a0
    ctx->r4 = ADD32(ctx->r7, ctx->r4);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x6E00($a0)
    ctx->r2 = MEM_W(0X6E00, ctx->r4);
    // nop

    // srl         $v0, $v0, 11
    ctx->r2 = S32(U32(ctx->r2) >> 11);
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $a2, $v0, 0x5948
    ctx->r6 = ADD32(ctx->r2, 0X5948);
    // lw          $v0, 0x6E04($a0)
    ctx->r2 = MEM_W(0X6E04, ctx->r4);
    // mflo        $s7
    ctx->r23 = lo;
    // srl         $v0, $v0, 11
    ctx->r2 = S32(U32(ctx->r2) >> 11);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x6E08($a0)
    ctx->r3 = MEM_W(0X6E08, ctx->r4);
    // lui         $s4, 0x1F80
    ctx->r20 = S32(0X1F80 << 16);
    // lh          $v1, 0x6A($v1)
    ctx->r3 = MEM_HS(0X6A, ctx->r3);
    // lhu         $s1, 0x44CC($a2)
    ctx->r17 = MEM_HU(0X44CC, ctx->r6);
    // mflo        $s6
    ctx->r22 = lo;
    // bgez        $v1, L_8001C698
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
        goto L_8001C698;
    }
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // addiu       $a1, $v1, 0x7FF
    ctx->r5 = ADD32(ctx->r3, 0X7FF);
L_8001C698:
    // sra         $v0, $a1, 11
    ctx->r2 = S32(ctx->r5) >> 11;
    // addiu       $a0, $v0, 0x2
    ctx->r4 = ADD32(ctx->r2, 0X2);
    // mult        $a0, $a0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // mflo        $s5
    ctx->r21 = lo;
    // beq         $s1, $v0, L_8001C7CC
    if (ctx->r17 == ctx->r2) {
        // addu        $s3, $a2, $zero
        ctx->r19 = ADD32(ctx->r6, 0);
        goto L_8001C7CC;
    }
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // addu        $fp, $a3, $zero
    ctx->r30 = ADD32(ctx->r7, 0);
    // sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17) << 1;
L_8001C6C0:
    // addu        $s2, $v0, $s3
    ctx->r18 = ADD32(ctx->r2, ctx->r19);
    // lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // addiu       $t0, $t0, -0x4130
    ctx->r8 = ADD32(ctx->r8, -0X4130);
    // lhu         $v1, 0x45CE($s2)
    ctx->r3 = MEM_HU(0X45CE, ctx->r18);
    // ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $s0, $v0, $t0
    ctx->r16 = ADD32(ctx->r2, ctx->r8);
    // lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(0X8, ctx->r16);
    // addu        $a0, $fp, $a0
    ctx->r4 = ADD32(ctx->r30, ctx->r4);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // sw          $v0, 0x128($s4)
    MEM_W(0X128, ctx->r20) = ctx->r2;
    // lbu         $v1, 0x9($s0)
    ctx->r3 = MEM_BU(0X9, ctx->r16);
    // lbu         $v0, 0xB($s0)
    ctx->r2 = MEM_BU(0XB, ctx->r16);
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x12C($s4)
    MEM_W(0X12C, ctx->r20) = ctx->r3;
    // lbu         $v0, 0xA($s0)
    ctx->r2 = MEM_BU(0XA, ctx->r16);
    // lbu         $v1, 0x6E15($a0)
    ctx->r3 = MEM_BU(0X6E15, ctx->r4);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // sb          $v1, 0x1E8($s4)
    MEM_B(0X1E8, ctx->r20) = ctx->r3;
    // sw          $v0, 0x130($s4)
    MEM_W(0X130, ctx->r20) = ctx->r2;
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // jal         0x8001C4C8
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    sub_8001C4C8(rdram, ctx);
    goto after_0;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
    after_0:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // slt         $v0, $s5, $v1
    ctx->r2 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8001C79C
    if (ctx->r2 == 0) {
        // slt         $v0, $v1, $s7
        ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r23) ? 1 : 0;
        goto L_8001C79C;
    }
    // slt         $v0, $v1, $s7
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r23) ? 1 : 0;
    // lhu         $v0, 0x44CC($s3)
    ctx->r2 = MEM_HU(0X44CC, ctx->r19);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x44CC($s3)
    MEM_H(0X44CC, ctx->r19) = ctx->r2;
    // lhu         $v0, 0x44CC($s3)
    ctx->r2 = MEM_HU(0X44CC, ctx->r19);
    // nop

    // slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8001C7BC
    if (ctx->r2 == 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8001C7BC;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
L_8001C774:
    // lhu         $v0, 0x45D0($v1)
    ctx->r2 = MEM_HU(0X45D0, ctx->r3);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // sh          $v0, 0x45CE($v1)
    MEM_H(0X45CE, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x44CC($s3)
    ctx->r2 = MEM_HU(0X44CC, ctx->r19);
    // nop

    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8001C774
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
        goto L_8001C774;
    }
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // j           L_8001C7C0
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    goto L_8001C7C0;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8001C79C:
    // beq         $v0, $zero, L_8001C7AC
    if (ctx->r2 == 0) {
        // slt         $v0, $s6, $v1
        ctx->r2 = SIGNED(ctx->r22) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_8001C7AC;
    }
    // slt         $v0, $s6, $v1
    ctx->r2 = SIGNED(ctx->r22) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8001C7BC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001C7BC;
    }
    // nop

L_8001C7AC:
    // lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(0X4, ctx->r16);
    // nop

    // ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // sb          $v0, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r2;
L_8001C7BC:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8001C7C0:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s1, $v0, L_8001C6C0
    if (ctx->r17 != ctx->r2) {
        // sll         $v0, $s1, 1
        ctx->r2 = S32(ctx->r17) << 1;
        goto L_8001C6C0;
    }
    // sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17) << 1;
L_8001C7CC:
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
