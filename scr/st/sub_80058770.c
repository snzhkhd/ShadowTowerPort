#include "recomp.h"
#include "disable_warnings.h"

void sub_80058770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xC64
    ctx->r2 = ADD32(ctx->r2, 0XC64);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(0X40, ctx->r29);
    // addiu       $t0, $a3, -0x1
    ctx->r8 = ADD32(ctx->r7, -0X1);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // beq         $a3, $zero, L_800587E4
    if (ctx->r7 == 0) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_800587E4;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800587B4:
    // lh          $v0, 0x4($s1)
    ctx->r2 = MEM_HS(0X4, ctx->r17);
    // nop

    // bne         $v0, $zero, L_800587D0
    if (ctx->r2 != 0) {
        // addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
        goto L_800587D0;
    }
    // addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // sw          $s4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r20;
    // j           L_8005888C
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    goto L_8005888C;
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_800587D0:
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // bne         $t0, $v1, L_800587B4
    if (ctx->r8 != ctx->r3) {
        // addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
        goto L_800587B4;
    }
    // addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // sll         $v1, $a2, 3
    ctx->r3 = S32(ctx->r6) << 3;
L_800587E4:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xC64
    ctx->r2 = ADD32(ctx->r2, 0XC64);
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // beq         $a3, $zero, L_80058888
    if (ctx->r7 == 0) {
        // addiu       $t0, $a3, -0x1
        ctx->r8 = ADD32(ctx->r7, -0X1);
        goto L_80058888;
    }
    // addiu       $t0, $a3, -0x1
    ctx->r8 = ADD32(ctx->r7, -0X1);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // addiu       $a2, $v0, -0x3A7C
    ctx->r6 = ADD32(ctx->r2, -0X3A7C);
    // addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // addiu       $s2, $s1, 0x4
    ctx->r18 = ADD32(ctx->r17, 0X4);
L_80058808:
    // lh          $v1, 0x0($s2)
    ctx->r3 = MEM_HS(0X0, ctx->r18);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_80058874
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80058874;
    }
    // nop

    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // beq         $a1, $s3, L_80058850
    if (ctx->r5 == ctx->r19) {
        // addu        $s0, $a0, $a2
        ctx->r16 = ADD32(ctx->r4, ctx->r6);
        goto L_80058850;
    }
    // addu        $s0, $a0, $a2
    ctx->r16 = ADD32(ctx->r4, ctx->r6);
L_80058824:
    // lh          $a0, 0x4($s0)
    ctx->r4 = MEM_HS(0X4, ctx->r16);
    // nop

    // beq         $a0, $s3, L_80058844
    if (ctx->r4 == ctx->r19) {
        // nop
    
        goto L_80058844;
    }
    // nop

    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // beq         $v0, $s1, L_80058860
    if (ctx->r2 == ctx->r17) {
        // nop
    
        goto L_80058860;
    }
    // nop

L_80058844:
    // addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // bne         $a1, $s3, L_80058824
    if (ctx->r5 != ctx->r19) {
        // addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_80058824;
    }
    // addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80058850:
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    // j           L_8005888C
    // sw          $s4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r20;
    goto L_8005888C;
    // sw          $s4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r20;
L_80058860:
    // jal         0x80073564
    // nop

    ST_SsVabClose(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sh          $s3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r19;
    // j           L_80058850
    // sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    goto L_80058850;
    // sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_80058874:
    // addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // bne         $t0, $s3, L_80058808
    if (ctx->r8 != ctx->r19) {
        // addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
        goto L_80058808;
    }
    // addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_80058888:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005888C:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
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
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
