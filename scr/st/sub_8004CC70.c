#include "recomp.h"
#include "disable_warnings.h"

void sub_8004CC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(0X4, ctx->r5);
    // lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(0X8, ctx->r5);
    // lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(0XC, ctx->r5);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // addiu       $s6, $zero, 0x1000
    ctx->r22 = ADD32(0, 0X1000);
    // lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(0X6C, ctx->r29);
    // lw          $s1, 0x70($sp)
    ctx->r17 = MEM_W(0X70, ctx->r29);
    // lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(0X60, ctx->r29);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $s3, $v0, 4
    ctx->r19 = S32(ctx->r2) >> 4;
    // lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(0X14, ctx->r29);
    // lhu         $s2, 0x68($sp)
    ctx->r18 = MEM_HU(0X68, ctx->r29);
    // addiu       $v0, $v0, 0x320
    ctx->r2 = ADD32(ctx->r2, 0X320);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
L_8004CCF0:
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(0X4, ctx->r16);
    // lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(0X8, ctx->r16);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // jal         0x8004A390
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    sub_8004A390(rdram, ctx);
    goto after_0;
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    after_0:
    // lh          $a0, 0x22($sp)
    ctx->r4 = MEM_HS(0X22, ctx->r29);
    // lh          $v0, 0x8E($s7)
    ctx->r2 = MEM_HS(0X8E, ctx->r23);
    // lhu         $a1, 0x8E($s7)
    ctx->r5 = MEM_HU(0X8E, ctx->r23);
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // andi        $a2, $v0, 0xFFF
    ctx->r6 = ctx->r2 & 0XFFF;
    // slti        $v0, $a2, 0x800
    ctx->r2 = SIGNED(ctx->r6) < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_8004CD40
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004CD40;
    }
    // nop

    // subu        $a2, $s6, $a2
    ctx->r6 = SUB32(ctx->r22, ctx->r6);
L_8004CD40:
    // beq         $a2, $zero, L_8004CD7C
    if (ctx->r6 == 0) {
        // slti        $v0, $a2, 0x1001
        ctx->r2 = SIGNED(ctx->r6) < 0X1001 ? 1 : 0;
        goto L_8004CD7C;
    }
    // slti        $v0, $a2, 0x1001
    ctx->r2 = SIGNED(ctx->r6) < 0X1001 ? 1 : 0;
    // div         $zero, $s3, $a2
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r6)));
    // bne         $a2, $zero, L_8004CD58
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8004CD58;
    }
    // nop

    // break       7
    do_break(2147798356);
L_8004CD58:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a2, $at, L_8004CD70
    if (ctx->r6 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8004CD70;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $s3, $at, L_8004CD70
    if (ctx->r19 != ctx->r1) {
        // nop
    
        goto L_8004CD70;
    }
    // nop

    // break       6
    do_break(2147798380);
L_8004CD70:
    // mflo        $a2
    ctx->r6 = lo;
    // nop

    // slti        $v0, $a2, 0x1001
    ctx->r2 = SIGNED(ctx->r6) < 0X1001 ? 1 : 0;
L_8004CD7C:
    // bne         $v0, $zero, L_8004CD88
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004CD88;
    }
    // nop

    // addiu       $a2, $zero, 0x1000
    ctx->r6 = ADD32(0, 0X1000);
L_8004CD88:
    // addiu       $a1, $a1, 0x800
    ctx->r5 = ADD32(ctx->r5, 0X800);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // jal         0x8004A848
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    sub_8004A848(rdram, ctx);
    goto after_1;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    after_1:
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // bne         $v0, $v1, L_8004CDE4
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8004CDE4;
    }
    // nop

    // lh          $a0, 0x20($sp)
    ctx->r4 = MEM_HS(0X20, ctx->r29);
    // lh          $a1, 0x8C($s7)
    ctx->r5 = MEM_HS(0X8C, ctx->r23);
    // nop

    // subu        $v0, $a0, $a1
    ctx->r2 = SUB32(ctx->r4, ctx->r5);
    // andi        $a2, $v0, 0xFFF
    ctx->r6 = ctx->r2 & 0XFFF;
    // slti        $v0, $a2, 0x800
    ctx->r2 = SIGNED(ctx->r6) < 0X800 ? 1 : 0;
    // bne         $v0, $zero, L_8004CDD4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8004CDD4;
    }
    // nop

    // subu        $a2, $s6, $a2
    ctx->r6 = SUB32(ctx->r22, ctx->r6);
L_8004CDD4:
    // jal         0x8004A848
    // nop

    sub_8004A848(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_8004CDE8
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    goto L_8004CDE8;
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
L_8004CDE4:
    // sh          $s2, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r18;
L_8004CDE8:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // jal         0x80049F08
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    sub_80049F08(rdram, ctx);
    goto after_3;
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_3:
    // sll         $a0, $s4, 16
    ctx->r4 = S32(ctx->r20) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // jal         0x8004A0F8
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    sub_8004A0F8(rdram, ctx);
    goto after_4;
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_4:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // beq         $s1, $zero, L_8004CE80
    if (ctx->r17 == 0) {
        // nop
    
        goto L_8004CE80;
    }
    // nop

    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(0X10, ctx->r29);
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // lw          $a1, 0x14($sp)
    ctx->r5 = MEM_W(0X14, ctx->r29);
    // lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(0X18, ctx->r29);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // jal         0x8004A340
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    sub_8004A340(rdram, ctx);
    goto after_5;
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    after_5:
    // div         $zero, $v0, $s4
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r20)));
    // bne         $s4, $zero, L_8004CE48
    if (ctx->r20 != 0) {
        // nop
    
        goto L_8004CE48;
    }
    // nop

    // break       7
    do_break(2147798596);
L_8004CE48:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $s4, $at, L_8004CE60
    if (ctx->r20 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8004CE60;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8004CE60
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8004CE60;
    }
    // nop

    // break       6
    do_break(2147798620);
L_8004CE60:
    // mflo        $a2
    ctx->r6 = lo;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a1, $a1, -0x6E78
    ctx->r5 = ADD32(ctx->r5, -0X6E78);
    // jal         0x8004A8E8
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    sub_8004A8E8(rdram, ctx);
    goto after_6;
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    after_6:
    // j           L_8004CCF0
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    goto L_8004CCF0;
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
L_8004CE80:
    // lhu         $v0, 0x22($sp)
    ctx->r2 = MEM_HU(0X22, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(0X64, ctx->r29);
    // lwl         $v1, 0x23($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X23, ctx->r29);
    // lwr         $v1, 0x20($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X20, ctx->r29);
    // lwl         $a0, 0x27($sp)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X27, ctx->r29);
    // lwr         $a0, 0x24($sp)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X24, ctx->r29);
    // swl         $v1, 0x3($v0)
    do_swl(rdram, 0X3, ctx->r2, ctx->r3);
    // swr         $v1, 0x0($v0)
    do_swr(rdram, 0X0, ctx->r2, ctx->r3);
    // swl         $a0, 0x7($v0)
    do_swl(rdram, 0X7, ctx->r2, ctx->r4);
    // swr         $a0, 0x4($v0)
    do_swr(rdram, 0X4, ctx->r2, ctx->r4);
    // lh          $v0, 0x22($sp)
    ctx->r2 = MEM_HS(0X22, ctx->r29);
    // lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(0X48, ctx->r29);
    // lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(0X44, ctx->r29);
    // lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(0X40, ctx->r29);
    // lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(0X3C, ctx->r29);
    // lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
