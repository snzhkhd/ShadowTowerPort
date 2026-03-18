#include "recomp.h"
#include "disable_warnings.h"

void sub_800237A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // addu        $fp, $a0, $zero
    ctx->r30 = ADD32(ctx->r4, 0);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // andi        $s3, $fp, 0xFFFF
    ctx->r19 = ctx->r30 & 0XFFFF;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addiu       $s4, $s6, 0x1
    ctx->r20 = ADD32(ctx->r22, 0X1);
    // andi        $a1, $s4, 0xFFFF
    ctx->r5 = ctx->r20 & 0XFFFF;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // jal         0x80015EC8
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    sub_80015EC8(rdram, ctx);
    goto after_0;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // andi        $a1, $s6, 0xFFFF
    ctx->r5 = ctx->r22 & 0XFFFF;
    // jal         0x80015EC8
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    sub_80015EC8(rdram, ctx);
    goto after_1;
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_1:
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // sltu        $v0, $a1, $s1
    ctx->r2 = ctx->r5 < ctx->r17 ? 1 : 0;
    // beq         $v0, $zero, L_8002381C
    if (ctx->r2 == 0) {
        // lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
        goto L_8002381C;
    }
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
L_8002381C:
    // addiu       $a0, $a0, -0x3778
    ctx->r4 = ADD32(ctx->r4, -0X3778);
    // andi        $s2, $s0, 0xFFFF
    ctx->r18 = ctx->r16 & 0XFFFF;
    // sll         $v0, $s2, 2
    ctx->r2 = S32(ctx->r18) << 2;
    // lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // addiu       $a2, $a2, 0x53DC
    ctx->r6 = ADD32(ctx->r6, 0X53DC);
    // jal         0x80015164
    // addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    sub_80015164(rdram, ctx);
    goto after_2;
    // addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    after_2:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_800239B8
    if (ctx->r16 == 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_800239B8;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80015250
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    sub_80015250(rdram, ctx);
    goto after_3;
    // addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80015278
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    sub_80015278(rdram, ctx);
    goto after_4;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_4:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80015264
    // andi        $a1, $s5, 0xFF
    ctx->r5 = ctx->r21 & 0XFF;
    sub_80015264(rdram, ctx);
    goto after_5;
    // andi        $a1, $s5, 0xFF
    ctx->r5 = ctx->r21 & 0XFF;
    after_5:
    // beq         $s1, $zero, L_80023880
    if (ctx->r17 == 0) {
        // addu        $a0, $fp, $zero
        ctx->r4 = ADD32(ctx->r30, 0);
        goto L_80023880;
    }
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lui         $a3, 0x8002
    ctx->r7 = S32(0X8002 << 16);
    // jal         0x80015D54
    // addiu       $a3, $a3, 0x3388
    ctx->r7 = ADD32(ctx->r7, 0X3388);
    sub_80015D54(rdram, ctx);
    goto after_6;
    // addiu       $a3, $a3, 0x3388
    ctx->r7 = ADD32(ctx->r7, 0X3388);
    after_6:
L_80023880:
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lui         $a3, 0x8002
    ctx->r7 = S32(0X8002 << 16);
    // jal         0x80015D54
    // addiu       $a3, $a3, 0x3288
    ctx->r7 = ADD32(ctx->r7, 0X3288);
    sub_80015D54(rdram, ctx);
    goto after_7;
    // addiu       $a3, $a3, 0x3288
    ctx->r7 = ADD32(ctx->r7, 0X3288);
    after_7:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addiu       $a1, $s6, 0x2
    ctx->r5 = ADD32(ctx->r22, 0X2);
    // jal         0x80015EC8
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sub_80015EC8(rdram, ctx);
    goto after_8;
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_8:
    // beq         $v0, $zero, L_800239B8
    if (ctx->r2 == 0) {
        // lui         $v0, 0x6666
        ctx->r2 = S32(0X6666 << 16);
        goto L_800239B8;
    }
    // lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // mult        $s6, $v0
    result = S64(S32(ctx->r22)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $s6, 31
    ctx->r2 = S32(ctx->r22) >> 31;
    // mfhi        $t0
    ctx->r8 = hi;
    // sra         $v1, $t0, 1
    ctx->r3 = S32(ctx->r8) >> 1;
    // subu        $s4, $v1, $v0
    ctx->r20 = SUB32(ctx->r3, ctx->r2);
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // sll         $v1, $s4, 3
    ctx->r3 = S32(ctx->r20) << 3;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $a1, $v0, -0x2DD8
    ctx->r5 = ADD32(ctx->r2, -0X2DD8);
    // bgez        $s4, L_800238E4
    if (SIGNED(ctx->r20) >= 0) {
        // addu        $s3, $v1, $a1
        ctx->r19 = ADD32(ctx->r3, ctx->r5);
        goto L_800238E4;
    }
    // addu        $s3, $v1, $a1
    ctx->r19 = ADD32(ctx->r3, ctx->r5);
    // addiu       $a0, $s4, 0x3
    ctx->r4 = ADD32(ctx->r20, 0X3);
L_800238E4:
    // sra         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) >> 2;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $s4, $v0
    ctx->r2 = SUB32(ctx->r20, ctx->r2);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $s0, $v0, $a1
    ctx->r16 = ADD32(ctx->r2, ctx->r5);
    // addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // addu        $s7, $s2, $zero
    ctx->r23 = ADD32(ctx->r18, 0);
    // addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
L_80023904:
    // bne         $s0, $s3, L_80023914
    if (ctx->r16 != ctx->r19) {
        // nop
    
        goto L_80023914;
    }
    // nop

    // j           L_80023970
    // addiu       $s0, $s3, 0x20
    ctx->r16 = ADD32(ctx->r19, 0X20);
    goto L_80023970;
    // addiu       $s0, $s3, 0x20
    ctx->r16 = ADD32(ctx->r19, 0X20);
L_80023914:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8002396C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8002396C;
    }
    // nop

    // lh          $v0, 0x4($v0)
    ctx->r2 = MEM_HS(0X4, ctx->r2);
    // nop

    // bne         $v0, $s7, L_80023958
    if (ctx->r2 != ctx->r23) {
        // nop
    
        goto L_80023958;
    }
    // nop

    // addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
L_80023938:
    // jal         0x8001531C
    // nop

    sub_8001531C(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // lh          $v0, 0x4($v0)
    ctx->r2 = MEM_HS(0X4, ctx->r2);
    // nop

    // beq         $v0, $s1, L_80023938
    if (ctx->r2 == ctx->r17) {
        // nop
    
        goto L_80023938;
    }
    // nop

L_80023958:
    // lh          $a0, 0x4($s0)
    ctx->r4 = MEM_HS(0X4, ctx->r16);
    // jal         0x80073564
    // nop

    sub_80073564(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // sh          $s5, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r21;
    // sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_8002396C:
    // addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
L_80023970:
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // bne         $s2, $s5, L_80023904
    if (ctx->r18 != ctx->r21) {
        // nop
    
        goto L_80023904;
    }
    // nop

    // lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(0X0, ctx->r19);
    // nop

    // bne         $a0, $zero, L_800239A4
    if (ctx->r4 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_800239A4;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // addiu       $a1, $s6, 0x2
    ctx->r5 = ADD32(ctx->r22, 0X2);
    // jal         0x80058A0C
    // addiu       $a2, $s4, 0x8
    ctx->r6 = ADD32(ctx->r20, 0X8);
    sub_80058A0C(rdram, ctx);
    goto after_11;
    // addiu       $a2, $s4, 0x8
    ctx->r6 = ADD32(ctx->r20, 0X8);
    after_11:
    // j           L_800239B8
    // nop

    goto L_800239B8;
    // nop

L_800239A4:
    // lh          $v1, 0x4($a0)
    ctx->r3 = MEM_HS(0X4, ctx->r4);
    // nop

    // bne         $v1, $v0, L_800239B8
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_800239B8;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
L_800239B8:
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
