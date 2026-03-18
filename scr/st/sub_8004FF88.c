#include "recomp.h"
#include "disable_warnings.h"

void sub_8004FF88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // jal         0x8004A078
    // addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    sub_8004A078(rdram, ctx);
    goto after_0;
    // addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_0:
    // lbu         $v0, 0x50($s2)
    ctx->r2 = MEM_BU(0X50, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x50($s2)
    MEM_B(0X50, ctx->r18) = ctx->r2;
    // lbu         $s0, 0x50($s2)
    ctx->r16 = MEM_BU(0X50, ctx->r18);
    // nop

    // sll         $s0, $s0, 12
    ctx->r16 = S32(ctx->r16) << 12;
    // div         $zero, $s0, $s3
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r19)));
    // bne         $s3, $zero, L_8004FFBC
    if (ctx->r19 != 0) {
        // nop
    
        goto L_8004FFBC;
    }
    // nop

    // break       7
    do_break(2147811256);
L_8004FFBC:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s3, $at, L_8004FFD4
    if (ctx->r19 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8004FFD4;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $s0, $at, L_8004FFD4
    if (ctx->r16 != ctx->r1) {
        // nop
    
        goto L_8004FFD4;
    }
    // nop

    // break       6
    do_break(2147811280);
L_8004FFD4:
    // mflo        $s0
    ctx->r16 = lo;
    // lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(0X10, ctx->r29);
    // lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(0X20, ctx->r29);
    // jal         0x8004A830
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_8004A830(rdram, ctx);
    goto after_1;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // lw          $v1, 0x24($s2)
    ctx->r3 = MEM_W(0X24, ctx->r18);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r3;
    // lw          $a0, 0x14($sp)
    ctx->r4 = MEM_W(0X14, ctx->r29);
    // lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(0X24, ctx->r29);
    // jal         0x8004A830
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_8004A830(rdram, ctx);
    goto after_2;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_2:
    // lw          $v1, 0x28($s2)
    ctx->r3 = MEM_W(0X28, ctx->r18);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r3;
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(0X28, ctx->r29);
    // jal         0x8004A830
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_8004A830(rdram, ctx);
    goto after_3;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_3:
    // lw          $v1, 0x2C($s2)
    ctx->r3 = MEM_W(0X2C, ctx->r18);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r3;
    // lbu         $v0, 0x50($s2)
    ctx->r2 = MEM_BU(0X50, ctx->r18);
    // nop

    // slt         $v0, $v0, $s3
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // bne         $v0, $zero, L_80050080
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80050080;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // beq         $s4, $zero, L_80050058
    if (ctx->r20 == 0) {
        // addiu       $v0, $zero, 0xFFF
        ctx->r2 = ADD32(0, 0XFFF);
        goto L_80050058;
    }
    // addiu       $v0, $zero, 0xFFF
    ctx->r2 = ADD32(0, 0XFFF);
    // sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
L_80050058:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lh          $v0, 0x5920($v0)
    ctx->r2 = MEM_HS(0X5920, ctx->r2);
    // nop

    // bne         $v0, $zero, L_80050074
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80050074;
    }
    // nop

    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x48($s1)
    MEM_B(0X48, ctx->r17) = ctx->r2;
L_80050074:
    // addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80050080:
    // lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(0X4C, ctx->r29);
    // lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(0X48, ctx->r29);
    // lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(0X44, ctx->r29);
    // lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(0X40, ctx->r29);
    // lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(0X3C, ctx->r29);
    // lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(0X38, ctx->r29);
    // lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
