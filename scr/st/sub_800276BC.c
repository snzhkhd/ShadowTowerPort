#include "recomp.h"
#include "disable_warnings.h"

void sub_800276BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // srl         $v0, $a0, 24
    ctx->r2 = S32(U32(ctx->r4) >> 24);
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // andi        $s2, $v0, 0xF
    ctx->r18 = ctx->r2 & 0XF;
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // addu        $s7, $a3, $zero
    ctx->r23 = ADD32(ctx->r7, 0);
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    // lui         $v0, 0xF000
    ctx->r2 = S32(0XF000 << 16);
    // and         $t2, $a0, $v0
    ctx->r10 = ctx->r4 & ctx->r2;
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // bgez        $v0, L_80027724
    if (SIGNED(ctx->r2) >= 0) {
        // sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
        goto L_80027724;
    }
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // negu        $t0, $a0
    ctx->r8 = SUB32(0, ctx->r4);
    // addu        $t1, $s6, $zero
    ctx->r9 = ADD32(ctx->r22, 0);
L_80027724:
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // bne         $v0, $zero, L_80027760
    if (ctx->r2 != 0) {
        // addiu       $s0, $s2, -0x1
        ctx->r16 = ADD32(ctx->r18, -0X1);
        goto L_80027760;
    }
    // addiu       $s0, $s2, -0x1
    ctx->r16 = ADD32(ctx->r18, -0X1);
    // addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // addiu       $v0, $s2, -0x1
    ctx->r2 = ADD32(ctx->r18, -0X1);
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
    // addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
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
    // j           L_800278D0
    // nop

    goto L_800278D0;
    // nop

L_80027760:
    // beq         $s0, $a2, L_80027780
    if (ctx->r16 == ctx->r6) {
        // addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
        goto L_80027780;
    }
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_8002776C:
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $a0, L_8002776C
    if (ctx->r16 != ctx->r4) {
        // sll         $v1, $v0, 1
        ctx->r3 = S32(ctx->r2) << 1;
        goto L_8002776C;
    }
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
L_80027780:
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_8002780C
    if (ctx->r2 == 0) {
        // addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
        goto L_8002780C;
    }
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // beq         $s2, $zero, L_80027838
    if (ctx->r18 == 0) {
        // addiu       $s0, $s2, -0x1
        ctx->r16 = ADD32(ctx->r18, -0X1);
        goto L_80027838;
    }
    // addiu       $s0, $s2, -0x1
    ctx->r16 = ADD32(ctx->r18, -0X1);
    // lui         $a3, 0xCCCC
    ctx->r7 = S32(0XCCCC << 16);
    // ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
    // sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16) << 1;
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
L_800277B4:
    // multu       $a1, $a3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // mfhi        $t3
    ctx->r11 = hi;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // srl         $a1, $t3, 3
    ctx->r5 = S32(U32(ctx->r11) >> 3);
    // divu        $zero, $v0, $a1
    lo = S32(U32(ctx->r2) / U32(ctx->r5)); hi = S32(U32(ctx->r2) % U32(ctx->r5));
    // bne         $a1, $zero, L_800277D8
    if (ctx->r5 != 0) {
        // nop
    
        goto L_800277D8;
    }
    // nop

    // break       7
    do_break(2147645396);
L_800277D8:
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
    // bne         $s0, $a2, L_800277B4
    if (ctx->r16 != ctx->r6) {
        // subu        $t0, $t0, $t3
        ctx->r8 = SUB32(ctx->r8, ctx->r11);
        goto L_800277B4;
    }
    // subu        $t0, $t0, $t3
    ctx->r8 = SUB32(ctx->r8, ctx->r11);
    // j           L_8002783C
    // andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
    goto L_8002783C;
    // andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
L_8002780C:
    // beq         $s2, $zero, L_80027838
    if (ctx->r18 == 0) {
        // addiu       $s0, $s2, -0x1
        ctx->r16 = ADD32(ctx->r18, -0X1);
        goto L_80027838;
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
L_80027828:
    // sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $a0, L_80027828
    if (ctx->r16 != ctx->r4) {
        // addiu       $v0, $v0, -0x2
        ctx->r2 = ADD32(ctx->r2, -0X2);
        goto L_80027828;
    }
    // addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_80027838:
    // andi        $v0, $t1, 0xFF
    ctx->r2 = ctx->r9 & 0XFF;
L_8002783C:
    // bne         $v0, $zero, L_8002784C
    if (ctx->r2 != 0) {
        // addiu       $a0, $zero, 0xD
        ctx->r4 = ADD32(0, 0XD);
        goto L_8002784C;
    }
    // addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // beq         $t2, $zero, L_80027860
    if (ctx->r10 == 0) {
        // addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
        goto L_80027860;
    }
    // addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_8002784C:
    // subu        $a1, $s5, $s1
    ctx->r5 = SUB32(ctx->r21, ctx->r17);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
    // jal         0x80026ECC
    // addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    sub_80026ECC(rdram, ctx);
    goto after_1;
    // addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    after_1:
L_80027860:
    // beq         $s2, $zero, L_800278D0
    if (ctx->r18 == 0) {
        // addiu       $s0, $s2, -0x1
        ctx->r16 = ADD32(ctx->r18, -0X1);
        goto L_800278D0;
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
L_80027878:
    // lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(0X0, ctx->r17);
    // nop

    // beq         $a0, $zero, L_80027890
    if (ctx->r4 == 0) {
        // andi        $v0, $s6, 0xFF
        ctx->r2 = ctx->r22 & 0XFF;
        goto L_80027890;
    }
    // andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
L_80027890:
    // bne         $v0, $zero, L_800278C0
    if (ctx->r2 != 0) {
        // subu        $v0, $s2, $s0
        ctx->r2 = SUB32(ctx->r18, ctx->r16);
        goto L_800278C0;
    }
    // subu        $v0, $s2, $s0
    ctx->r2 = SUB32(ctx->r18, ctx->r16);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // mult        $s3, $v0
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // andi        $a2, $s4, 0xFFFF
    ctx->r6 = ctx->r20 & 0XFFFF;
    // addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    // mflo        $t3
    ctx->r11 = lo;
    // addu        $a1, $s5, $t3
    ctx->r5 = ADD32(ctx->r21, ctx->r11);
    // jal         0x80026ECC
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_80026ECC(rdram, ctx);
    goto after_2;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_2:
L_800278C0:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_80027878
    if (ctx->r16 != ctx->r2) {
        // addiu       $s1, $s1, -0x2
        ctx->r17 = ADD32(ctx->r17, -0X2);
        goto L_80027878;
    }
    // addiu       $s1, $s1, -0x2
    ctx->r17 = ADD32(ctx->r17, -0X2);
L_800278D0:
    // lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(0X40, ctx->r29);
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
