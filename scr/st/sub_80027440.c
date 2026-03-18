#include "recomp.h"
#include "disable_warnings.h"

void sub_80027440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // addu        $fp, $a3, $zero
    ctx->r30 = ADD32(ctx->r7, 0);
    // addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
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
    // lbu         $v0, 0x3($fp)
    ctx->r2 = MEM_BU(0X3, ctx->r30);
    // addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // srl         $s1, $v0, 2
    ctx->r17 = S32(U32(ctx->r2) >> 2);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lhu         $v0, -0x7E52($v0)
    ctx->r2 = MEM_HU(-0X7E52, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8002749C
    if (ctx->r2 == 0) {
        // addu        $s5, $a2, $zero
        ctx->r21 = ADD32(ctx->r6, 0);
        goto L_8002749C;
    }
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
L_8002749C:
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
    // lbu         $v0, 0x2E5($v0)
    ctx->r2 = MEM_BU(0X2E5, ctx->r2);
    // nop

    // bne         $v0, $zero, L_800274B4
    if (ctx->r2 != 0) {
        // addiu       $s4, $zero, 0x4
        ctx->r20 = ADD32(0, 0X4);
        goto L_800274B4;
    }
    // addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // addiu       $s4, $zero, 0x40
    ctx->r20 = ADD32(0, 0X40);
L_800274B4:
    // srl         $v0, $a0, 24
    ctx->r2 = S32(U32(ctx->r4) >> 24);
    // andi        $s2, $v0, 0xF
    ctx->r18 = ctx->r2 & 0XF;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // and         $t2, $a0, $v0
    ctx->r10 = ctx->r4 & ctx->r2;
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // bgez        $v0, L_800274DC
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $a3, $zero, -0x1
        ctx->r7 = ADD32(0, -0X1);
        goto L_800274DC;
    }
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // negu        $a2, $a0
    ctx->r6 = SUB32(0, ctx->r4);
    // addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800274DC:
    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
    // bne         $v0, $zero, L_80027518
    if (ctx->r2 != 0) {
        // addiu       $s0, $s2, -0x1
        ctx->r16 = ADD32(ctx->r18, -0X1);
        goto L_80027518;
    }
    // addiu       $s0, $s2, -0x1
    ctx->r16 = ADD32(ctx->r18, -0X1);
    // andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
    // addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // andi        $a2, $s5, 0xFFFF
    ctx->r6 = ctx->r21 & 0XFFFF;
    // addu        $a3, $fp, $zero
    ctx->r7 = ADD32(ctx->r30, 0);
    // mflo        $t3
    ctx->r11 = lo;
    // addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // jal         0x80026ECC
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_80026ECC(rdram, ctx);
    goto after_0;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_0:
    // j           L_80027688
    // nop

    goto L_80027688;
    // nop

L_80027518:
    // beq         $s0, $a3, L_80027538
    if (ctx->r16 == ctx->r7) {
        // addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
        goto L_80027538;
    }
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_80027524:
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $a0, L_80027524
    if (ctx->r16 != ctx->r4) {
        // sll         $v1, $v0, 1
        ctx->r3 = S32(ctx->r2) << 1;
        goto L_80027524;
    }
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
L_80027538:
    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_800275C4
    if (ctx->r2 == 0) {
        // addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
        goto L_800275C4;
    }
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // beq         $s2, $zero, L_800275F0
    if (ctx->r18 == 0) {
        // addiu       $s0, $s2, -0x1
        ctx->r16 = ADD32(ctx->r18, -0X1);
        goto L_800275F0;
    }
    // addiu       $s0, $s2, -0x1
    ctx->r16 = ADD32(ctx->r18, -0X1);
    // lui         $t0, 0xCCCC
    ctx->r8 = S32(0XCCCC << 16);
    // ori         $t0, $t0, 0xCCCD
    ctx->r8 = ctx->r8 | 0XCCCD;
    // addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16) << 1;
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
L_8002756C:
    // multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
    // mfhi        $t3
    ctx->r11 = hi;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // srl         $a1, $t3, 3
    ctx->r5 = S32(U32(ctx->r11) >> 3);
    // divu        $zero, $v0, $a1
    lo = S32(U32(ctx->r2) / U32(ctx->r5)); hi = S32(U32(ctx->r2) % U32(ctx->r5));
    // bne         $a1, $zero, L_80027590
    if (ctx->r5 != 0) {
        // nop
    
        goto L_80027590;
    }
    // nop

    // break       7
    do_break(2147644812);
L_80027590:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(0X0, ctx->r4);
    // nop

    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // mflo        $t3
    ctx->r11 = lo;
    // bne         $s0, $a3, L_8002756C
    if (ctx->r16 != ctx->r7) {
        // subu        $a2, $a2, $t3
        ctx->r6 = SUB32(ctx->r6, ctx->r11);
        goto L_8002756C;
    }
    // subu        $a2, $a2, $t3
    ctx->r6 = SUB32(ctx->r6, ctx->r11);
    // j           L_800275F4
    // andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    goto L_800275F4;
    // andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
L_800275C4:
    // beq         $s2, $zero, L_800275F0
    if (ctx->r18 == 0) {
        // addiu       $s0, $s2, -0x1
        ctx->r16 = ADD32(ctx->r18, -0X1);
        goto L_800275F0;
    }
    // addiu       $s0, $s2, -0x1
    ctx->r16 = ADD32(ctx->r18, -0X1);
    // addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_800275E0:
    // sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $a0, L_800275E0
    if (ctx->r16 != ctx->r4) {
        // addiu       $v0, $v0, -0x2
        ctx->r2 = ADD32(ctx->r2, -0X2);
        goto L_800275E0;
    }
    // addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_800275F0:
    // andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
L_800275F4:
    // bne         $v0, $zero, L_80027604
    if (ctx->r2 != 0) {
        // addiu       $a0, $s4, 0xD
        ctx->r4 = ADD32(ctx->r20, 0XD);
        goto L_80027604;
    }
    // addiu       $a0, $s4, 0xD
    ctx->r4 = ADD32(ctx->r20, 0XD);
    // beq         $t2, $zero, L_80027618
    if (ctx->r10 == 0) {
        // addiu       $a0, $s4, 0xC
        ctx->r4 = ADD32(ctx->r20, 0XC);
        goto L_80027618;
    }
    // addiu       $a0, $s4, 0xC
    ctx->r4 = ADD32(ctx->r20, 0XC);
L_80027604:
    // subu        $a1, $s6, $s1
    ctx->r5 = SUB32(ctx->r22, ctx->r17);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // andi        $a2, $s5, 0xFFFF
    ctx->r6 = ctx->r21 & 0XFFFF;
    // jal         0x80026ECC
    // addu        $a3, $fp, $zero
    ctx->r7 = ADD32(ctx->r30, 0);
    sub_80026ECC(rdram, ctx);
    goto after_1;
    // addu        $a3, $fp, $zero
    ctx->r7 = ADD32(ctx->r30, 0);
    after_1:
L_80027618:
    // beq         $s2, $zero, L_80027688
    if (ctx->r18 == 0) {
        // addiu       $s0, $s2, -0x1
        ctx->r16 = ADD32(ctx->r18, -0X1);
        goto L_80027688;
    }
    // addiu       $s0, $s2, -0x1
    ctx->r16 = ADD32(ctx->r18, -0X1);
    // andi        $s3, $s1, 0xFFFF
    ctx->r19 = ctx->r17 & 0XFFFF;
    // addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16) << 1;
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
L_80027630:
    // lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(0X0, ctx->r17);
    // nop

    // beq         $v1, $zero, L_80027648
    if (ctx->r3 == 0) {
        // andi        $v0, $s7, 0xFF
        ctx->r2 = ctx->r23 & 0XFF;
        goto L_80027648;
    }
    // andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
L_80027648:
    // bne         $v0, $zero, L_80027678
    if (ctx->r2 != 0) {
        // subu        $v0, $s2, $s0
        ctx->r2 = SUB32(ctx->r18, ctx->r16);
        goto L_80027678;
    }
    // subu        $v0, $s2, $s0
    ctx->r2 = SUB32(ctx->r18, ctx->r16);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // mult        $s3, $v0
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $s4, $v1
    ctx->r4 = ADD32(ctx->r20, ctx->r3);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // andi        $a2, $s5, 0xFFFF
    ctx->r6 = ctx->r21 & 0XFFFF;
    // addu        $a3, $fp, $zero
    ctx->r7 = ADD32(ctx->r30, 0);
    // mflo        $t3
    ctx->r11 = lo;
    // addu        $a1, $s6, $t3
    ctx->r5 = ADD32(ctx->r22, ctx->r11);
    // jal         0x80026ECC
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_80026ECC(rdram, ctx);
    goto after_2;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_2:
L_80027678:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_80027630
    if (ctx->r16 != ctx->r2) {
        // addiu       $s1, $s1, -0x2
        ctx->r17 = ADD32(ctx->r17, -0X2);
        goto L_80027630;
    }
    // addiu       $s1, $s1, -0x2
    ctx->r17 = ADD32(ctx->r17, -0X2);
L_80027688:
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
