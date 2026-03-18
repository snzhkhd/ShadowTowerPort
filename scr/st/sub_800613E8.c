#include "recomp.h"
#include "disable_warnings.h"

void sub_800613E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x80060C54
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80060C54(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // addiu       $s2, $zero, 0x9
    ctx->r18 = ADD32(0, 0X9);
    // lui         $v1, 0x1F80
    ctx->r3 = S32(0X1F80 << 16);
    // sll         $v0, $s3, 3
    ctx->r2 = S32(ctx->r19) << 3;
    // subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_80061440:
    // jal         0x80060BAC
    // nop

    sub_80060BAC(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x80068664
    // sll         $a0, $s3, 4
    ctx->r4 = S32(ctx->r19) << 4;
    _card_info(rdram, ctx);
    goto after_2;
    // sll         $a0, $s3, 4
    ctx->r4 = S32(ctx->r19) << 4;
    after_2:
    // jal         0x80060ED4
    // nop

    sub_80060ED4(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // bne         $v1, $zero, L_8006146C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8006146C;
    }
    // nop

    // j           L_800614A8
    // sh          $zero, 0x104($s1)
    MEM_H(0X104, ctx->r17) = 0;
    goto L_800614A8;
    // sh          $zero, 0x104($s1)
    MEM_H(0X104, ctx->r17) = 0;
L_8006146C:
    // bne         $v1, $s4, L_80061484
    if (ctx->r3 != ctx->r20) {
        // nop
    
        goto L_80061484;
    }
    // nop

    // bne         $s2, $zero, L_80061534
    if (ctx->r18 != 0) {
        // nop
    
        goto L_80061534;
    }
    // nop

    // j           L_80061544
    // sh          $s5, 0x104($s1)
    MEM_H(0X104, ctx->r17) = ctx->r21;
    goto L_80061544;
    // sh          $s5, 0x104($s1)
    MEM_H(0X104, ctx->r17) = ctx->r21;
L_80061484:
    // bne         $v1, $s5, L_8006149C
    if (ctx->r3 != ctx->r21) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8006149C;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // bne         $s2, $zero, L_80061534
    if (ctx->r18 != 0) {
        // nop
    
        goto L_80061534;
    }
    // nop

    // j           L_80061544
    // sh          $v1, 0x104($s1)
    MEM_H(0X104, ctx->r17) = ctx->r3;
    goto L_80061544;
    // sh          $v1, 0x104($s1)
    MEM_H(0X104, ctx->r17) = ctx->r3;
L_8006149C:
    // bne         $v1, $v0, L_800614A8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800614A8;
    }
    // nop

    // sh          $s4, 0x104($s1)
    MEM_H(0X104, ctx->r17) = ctx->r20;
L_800614A8:
    // bne         $s6, $s4, L_80061534
    if (ctx->r22 != ctx->r20) {
        // nop
    
        goto L_80061534;
    }
    // nop

    // jal         0x80060C00
    // sll         $s0, $s3, 4
    ctx->r16 = S32(ctx->r19) << 4;
    sub_80060C00(rdram, ctx);
    goto after_4;
    // sll         $s0, $s3, 4
    ctx->r16 = S32(ctx->r19) << 4;
    after_4:
    // jal         0x80068684
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    _card_clear(rdram, ctx);
    goto after_5;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_5:
    // jal         0x80060F88
    // nop

    sub_80060F88(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // beq         $v0, $zero, L_800614D8
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_800614D8;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // j           L_80061534
    // sh          $v0, 0x104($s1)
    MEM_H(0X104, ctx->r17) = ctx->r2;
    goto L_80061534;
    // sh          $v0, 0x104($s1)
    MEM_H(0X104, ctx->r17) = ctx->r2;
L_800614D8:
    // jal         0x80060BAC
    // nop

    sub_80060BAC(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // jal         0x80068674
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    _card_load(rdram, ctx);
    goto after_8;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // jal         0x80060ED4
    // nop

    sub_80060ED4(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80061514
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80061514;
    }
    // nop

    // bne         $s2, $zero, L_80061534
    if (ctx->r18 != 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_80061534;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // j           L_80061544
    // sh          $v0, 0x104($s1)
    MEM_H(0X104, ctx->r17) = ctx->r2;
    goto L_80061544;
    // sh          $v0, 0x104($s1)
    MEM_H(0X104, ctx->r17) = ctx->r2;
L_80061514:
    // bne         $v1, $zero, L_80061524
    if (ctx->r3 != 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_80061524;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // j           L_80061544
    // sh          $zero, 0x104($s1)
    MEM_H(0X104, ctx->r17) = 0;
    goto L_80061544;
    // sh          $zero, 0x104($s1)
    MEM_H(0X104, ctx->r17) = 0;
L_80061524:
    // bne         $v1, $v0, L_80061544
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80061544;
    }
    // nop

    // j           L_80061544
    // sh          $v1, 0x104($s1)
    MEM_H(0X104, ctx->r17) = ctx->r3;
    goto L_80061544;
    // sh          $v1, 0x104($s1)
    MEM_H(0X104, ctx->r17) = ctx->r3;
L_80061534:
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s2, $v0, L_80061440
    if (ctx->r18 != ctx->r2) {
        // nop
    
        goto L_80061440;
    }
    // nop

L_80061544:
    // jal         0x80060DE4
    // nop

    sub_80060DE4(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
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
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
