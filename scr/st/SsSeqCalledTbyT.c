#include "recomp.h"
#include "disable_warnings.h"

void SsSeqCalledTbyT(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x79AC($v0)
    ctx->r2 = MEM_W(-0X79AC, ctx->r2);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
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
    // beq         $v0, $v1, L_8006D5E4
    if (ctx->r2 == ctx->r3) {
        // sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
        goto L_8006D5E4;
    }
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v1, -0x79AC($at)
    MEM_W(-0X79AC, ctx->r1) = ctx->r3;
    // jal         0x80070894
    // addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    _SsVmFlush(rdram, ctx);
    goto after_0;
    // addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    after_0:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lh          $v0, -0x7120($v0)
    ctx->r2 = MEM_HS(-0X7120, ctx->r2);
    // nop

    // blez        $v0, L_8006D5DC
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_8006D5DC;
    }
    // nop

    // lui         $fp, 0x801F
    ctx->r30 = S32(0X801F << 16);
    // addiu       $fp, $fp, -0x79A0
    ctx->r30 = ADD32(ctx->r30, -0X79A0);
L_8006D40C:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lw          $v1, -0x79A8($v1)
    ctx->r3 = MEM_W(-0X79A8, ctx->r3);
    // sllv        $v0, $v0, $s7
    ctx->r2 = S32(ctx->r2) << (ctx->r23 & 31);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // beq         $v1, $zero, L_8006D5C4
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8006D5C4;
    }
    // nop

    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lh          $v0, -0x711E($v0)
    ctx->r2 = MEM_HS(-0X711E, ctx->r2);
    // nop

    // blez        $v0, L_8006D5C4
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $s6, $zero, $zero
        ctx->r22 = ADD32(0, 0);
        goto L_8006D5C4;
    }
    // addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // addu        $s2, $fp, $zero
    ctx->r18 = ADD32(ctx->r30, 0);
    // sll         $s5, $s7, 16
    ctx->r21 = S32(ctx->r23) << 16;
    // sra         $s4, $s5, 16
    ctx->r20 = S32(ctx->r21) >> 16;
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8006D450:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lw          $v0, 0x98($v0)
    ctx->r2 = MEM_W(0X98, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8006D51C
    if (ctx->r2 == 0) {
        // addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
        goto L_8006D51C;
    }
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // sra         $s1, $s3, 16
    ctx->r17 = S32(ctx->r19) >> 16;
    // jal         0x8006DD64
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    _SsSndPlay(rdram, ctx);
    goto after_1;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lw          $v0, 0x98($v0)
    ctx->r2 = MEM_W(0X98, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8006D4A4
    if (ctx->r2 == 0) {
        // addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
        goto L_8006D4A4;
    }
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // jal         0x8006D614
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    sub_8006D614(rdram, ctx);
    goto after_2;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
L_8006D4A4:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lw          $v0, 0x98($v0)
    ctx->r2 = MEM_W(0X98, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // beq         $v0, $zero, L_8006D4CC
    if (ctx->r2 == 0) {
        // addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
        goto L_8006D4CC;
    }
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // jal         0x8006D924
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    sub_8006D924(rdram, ctx);
    goto after_3;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
L_8006D4CC:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lw          $v0, 0x98($v0)
    ctx->r2 = MEM_W(0X98, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    // beq         $v0, $zero, L_8006D4F4
    if (ctx->r2 == 0) {
        // addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
        goto L_8006D4F4;
    }
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // jal         0x8006EAD4
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    _SsSndTempo(rdram, ctx);
    goto after_4;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
L_8006D4F4:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lw          $v0, 0x98($v0)
    ctx->r2 = MEM_W(0X98, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8006D51C
    if (ctx->r2 == 0) {
        // addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
        goto L_8006D51C;
    }
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // jal         0x8006EAD4
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    _SsSndTempo(rdram, ctx);
    goto after_5;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_5:
L_8006D51C:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lw          $v0, 0x98($v0)
    ctx->r2 = MEM_W(0X98, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // beq         $v0, $zero, L_8006D544
    if (ctx->r2 == 0) {
        // sra         $a0, $s5, 16
        ctx->r4 = S32(ctx->r21) >> 16;
        goto L_8006D544;
    }
    // sra         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21) >> 16;
    // jal         0x8006DCC4
    // sra         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19) >> 16;
    _SsSndPause(rdram, ctx);
    goto after_6;
    // sra         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19) >> 16;
    after_6:
L_8006D544:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lw          $v0, 0x98($v0)
    ctx->r2 = MEM_W(0X98, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // beq         $v0, $zero, L_8006D56C
    if (ctx->r2 == 0) {
        // sra         $a0, $s5, 16
        ctx->r4 = S32(ctx->r21) >> 16;
        goto L_8006D56C;
    }
    // sra         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21) >> 16;
    // jal         0x8006E634
    // sra         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19) >> 16;
    _SsSndReplay(rdram, ctx);
    goto after_7;
    // sra         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19) >> 16;
    after_7:
L_8006D56C:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // lw          $v0, 0x98($v0)
    ctx->r2 = MEM_W(0X98, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // beq         $v0, $zero, L_8006D5A4
    if (ctx->r2 == 0) {
        // sra         $a0, $s5, 16
        ctx->r4 = S32(ctx->r21) >> 16;
        goto L_8006D5A4;
    }
    // sra         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21) >> 16;
    // jal         0x8006E694
    // sra         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19) >> 16;
    _SsSndStop(rdram, ctx);
    goto after_8;
    // sra         $a1, $s3, 16
    ctx->r5 = S32(ctx->r19) >> 16;
    after_8:
    // lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(0X0, ctx->r18);
    // nop

    // addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // sw          $zero, 0x98($v0)
    MEM_W(0X98, ctx->r2) = 0;
L_8006D5A4:
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lh          $v0, -0x711E($v0)
    ctx->r2 = MEM_HS(-0X711E, ctx->r2);
    // addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // slt         $v0, $s6, $v0
    ctx->r2 = SIGNED(ctx->r22) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8006D450
    if (ctx->r2 != 0) {
        // addiu       $s0, $s0, 0xB0
        ctx->r16 = ADD32(ctx->r16, 0XB0);
        goto L_8006D450;
    }
    // addiu       $s0, $s0, 0xB0
    ctx->r16 = ADD32(ctx->r16, 0XB0);
L_8006D5C4:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lh          $v0, -0x7120($v0)
    ctx->r2 = MEM_HS(-0X7120, ctx->r2);
    // addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // slt         $v0, $s7, $v0
    ctx->r2 = SIGNED(ctx->r23) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8006D40C
    if (ctx->r2 != 0) {
        // addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
        goto L_8006D40C;
    }
    // addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
L_8006D5DC:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $zero, -0x79AC($at)
    MEM_W(-0X79AC, ctx->r1) = 0;
L_8006D5E4:
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
    // jr          $ra
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
