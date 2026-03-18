#include "recomp.h"
#include "disable_warnings.h"

void sub_80058318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // beq         $s6, $v0, L_800584DC
    if (ctx->r22 == ctx->r2) {
        // sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
        goto L_800584DC;
    }
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $a1, $v0, -0x2EE0
    ctx->r5 = ADD32(ctx->r2, -0X2EE0);
    // lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(0X1, ctx->r5);
    // nop

    // beq         $v0, $zero, L_800584DC
    if (ctx->r2 == 0) {
        // andi        $v0, $s6, 0x7FF
        ctx->r2 = ctx->r22 & 0X7FF;
        goto L_800584DC;
    }
    // andi        $v0, $s6, 0x7FF
    ctx->r2 = ctx->r22 & 0X7FF;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, -0x23BC
    ctx->r2 = ADD32(ctx->r2, -0X23BC);
    // addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
    // lh          $v1, 0x0($s2)
    ctx->r3 = MEM_HS(0X0, ctx->r18);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // beq         $v1, $a0, L_800584DC
    if (ctx->r3 == ctx->r4) {
        // addiu       $v0, $v0, -0xA5C
        ctx->r2 = ADD32(ctx->r2, -0XA5C);
        goto L_800584DC;
    }
    // addiu       $v0, $v0, -0xA5C
    ctx->r2 = ADD32(ctx->r2, -0XA5C);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $s3, $v1, $v0
    ctx->r19 = ADD32(ctx->r3, ctx->r2);
    // lh          $v1, 0x4($s3)
    ctx->r3 = MEM_HS(0X4, ctx->r19);
    // nop

    // beq         $v1, $a0, L_800584DC
    if (ctx->r3 == ctx->r4) {
        // addiu       $v0, $zero, 0xFE
        ctx->r2 = ADD32(0, 0XFE);
        goto L_800584DC;
    }
    // addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // beq         $v1, $v0, L_800584E0
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_800584E0;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // lh          $v1, 0x4($v0)
    ctx->r3 = MEM_HS(0X4, ctx->r2);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $v0, L_800584E0
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_800584E0;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(0X1, ctx->r5);
    // nop

    // mult        $s4, $v0
    result = S64(S32(ctx->r20)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // nop

    // nop

    // mult        $s5, $v0
    result = S64(S32(ctx->r21)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lh          $v0, 0x6($s2)
    ctx->r2 = MEM_HS(0X6, ctx->r18);
    // sra         $s4, $t1, 7
    ctx->r20 = S32(ctx->r9) >> 7;
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $s1, L_80058460
    if (SIGNED(ctx->r17) >= 0) {
        // sra         $s5, $v1, 7
        ctx->r21 = S32(ctx->r3) >> 7;
        goto L_80058460;
    }
    // sra         $s5, $v1, 7
    ctx->r21 = S32(ctx->r3) >> 7;
    // j           L_80058470
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    goto L_80058470;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80058408:
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x8006F504
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_8006F504(rdram, ctx);
    goto after_0;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_0:
L_80058414:
    // sll         $a3, $s1, 16
    ctx->r7 = S32(ctx->r17) << 16;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    // sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20) << 16;
    // lh          $a0, 0x4($s3)
    ctx->r4 = MEM_HS(0X4, ctx->r19);
    // lh          $a1, 0x2($s2)
    ctx->r5 = MEM_HS(0X2, ctx->r18);
    // lh          $a2, 0x4($s2)
    ctx->r6 = MEM_HS(0X4, ctx->r18);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x8006ECF4
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    SsUtKeyOn(rdram, ctx);
    goto after_1;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // j           L_800584E0
    // sh          $s6, 0xA50($v1)
    MEM_H(0XA50, ctx->r3) = ctx->r22;
    goto L_800584E0;
    // sh          $s6, 0xA50($v1)
    MEM_H(0XA50, ctx->r3) = ctx->r22;
L_80058460:
    // slti        $v0, $s1, 0x80
    ctx->r2 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_80058474
    if (ctx->r2 != 0) {
        // lui         $s0, 0x801E
        ctx->r16 = S32(0X801E << 16);
        goto L_80058474;
    }
    // lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // addiu       $s1, $zero, 0x7F
    ctx->r17 = ADD32(0, 0X7F);
L_80058470:
    // lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
L_80058474:
    // addiu       $s0, $s0, -0x2408
    ctx->r16 = ADD32(ctx->r16, -0X2408);
    // jal         0x8006BC18
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    SpuGetAllKeysStatus(rdram, ctx);
    goto after_2;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // addiu       $s0, $s0, -0xA38
    ctx->r16 = ADD32(ctx->r16, -0XA38);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // addu        $v0, $a0, $s0
    ctx->r2 = ADD32(ctx->r4, ctx->r16);
L_80058490:
    // lbu         $v0, 0xA38($v0)
    ctx->r2 = MEM_BU(0XA38, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80058414
    if (ctx->r2 == 0) {
        // addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
        goto L_80058414;
    }
    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // bne         $a0, $v1, L_80058490
    if (ctx->r4 != ctx->r3) {
        // addu        $v0, $a0, $s0
        ctx->r2 = ADD32(ctx->r4, ctx->r16);
        goto L_80058490;
    }
    // addu        $v0, $a0, $s0
    ctx->r2 = ADD32(ctx->r4, ctx->r16);
    // addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $s0, $v0, -0x2E40
    ctx->r16 = ADD32(ctx->r2, -0X2E40);
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // addu        $v0, $a0, $s0
    ctx->r2 = ADD32(ctx->r4, ctx->r16);
L_800584C0:
    // lbu         $v0, 0xA38($v0)
    ctx->r2 = MEM_BU(0XA38, ctx->r2);
    // nop

    // beq         $v0, $a1, L_80058408
    if (ctx->r2 == ctx->r5) {
        // nop
    
        goto L_80058408;
    }
    // nop

    // addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // bne         $a0, $v1, L_800584C0
    if (ctx->r4 != ctx->r3) {
        // addu        $v0, $a0, $s0
        ctx->r2 = ADD32(ctx->r4, ctx->r16);
        goto L_800584C0;
    }
    // addu        $v0, $a0, $s0
    ctx->r2 = ADD32(ctx->r4, ctx->r16);
L_800584DC:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800584E0:
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
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
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
