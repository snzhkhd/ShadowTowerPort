#include "recomp.h"
#include "disable_warnings.h"

void ProcessCDAudioLoad(uint8_t* rdram, recomp_context* ctx) 
{
   /* printf("ProcessCDAudioLoad\n");*/
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $s1, -0x7428($v0)
    ctx->r17 = MEM_W(-0X7428, ctx->r2);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(0X0, ctx->r17);
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // bne         $v1, $v0, L_8005874C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8005874C;
    }
    // nop

    // lbu         $v1, 0x11($s1)
    ctx->r3 = MEM_BU(0X11, ctx->r17);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_8005874C
    if (ctx->r3 != ctx->r2) {
        // addiu       $s4, $s1, 0x18
        ctx->r20 = ADD32(ctx->r17, 0X18);
        goto L_8005874C;
    }
    // addiu       $s4, $s1, 0x18
    ctx->r20 = ADD32(ctx->r17, 0X18);
    // lh          $v1, 0x4($s1)
    ctx->r3 = MEM_HS(0X4, ctx->r17);
    // addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, -0x2E18
    ctx->r2 = ADD32(ctx->r2, -0X2E18);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addu        $s2, $v1, $v0
    ctx->r18 = ADD32(ctx->r3, ctx->r2);
L_8005867C:
    // lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(0X20, ctx->r17);
    // lh          $a2, 0x4($s2)
    ctx->r6 = MEM_HS(0X4, ctx->r18);
    // jal         0x80074094
    // ori         $a1, $zero, 0xA000
    ctx->r5 = 0 | 0XA000;
    sub_80074094(rdram, ctx);
    goto after_0;
    // ori         $a1, $zero, 0xA000
    ctx->r5 = 0 | 0XA000;
    after_0:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_800586D4
    if (ctx->r16 != ctx->r2) {
        // addiu       $v0, $zero, -0x2
        ctx->r2 = ADD32(0, -0X2);
        goto L_800586D4;
    }
    // addiu       $v0, $zero, -0x2
    ctx->r2 = ADD32(0, -0X2);
    // lh          $a0, 0x4($s2)
    ctx->r4 = MEM_HS(0X4, ctx->r18);
    // jal         0x80073564
    // nop

    sub_80073564(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80015848
    // sh          $s0, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r16;
    NextCdTask(rdram, ctx);
    goto after_2;
    // sh          $s0, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r16;
    after_2:
    // lbu         $a0, 0x10($s1)
    ctx->r4 = MEM_BU(0X10, ctx->r17);
    // lh          $a1, 0x6($s1)
    ctx->r5 = MEM_HS(0X6, ctx->r17);
    // lh          $a2, 0x4($s1)
    ctx->r6 = MEM_HS(0X4, ctx->r17);
    // jal         0x80058A0C
    // nop

    sub_80058A0C(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // j           L_8005867C
    // nop

    goto L_8005867C;
    // nop

L_800586D4:
    // bne         $s0, $v0, L_8005871C
    if (ctx->r16 != ctx->r2) {
        // addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
        goto L_8005871C;
    }
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // lw          $a1, 0x28($s1)
    ctx->r5 = MEM_W(0X28, ctx->r17);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // sb          $zero, 0x1($s1)
    MEM_B(0X1, ctx->r17) = 0;
    // sb          $s3, 0x11($s1)
    MEM_B(0X11, ctx->r17) = ctx->r19;
    // jal         0x80015A94
    // nop

    sub_80015A94(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x80074314
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    SsVabTransCompleted(rdram, ctx);
    goto after_5;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
L_80058700:
    // addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
    // beq         $v0, $zero, L_80058700
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
        goto L_80058700;
    }
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // j           L_8005874C
    // nop

    goto L_8005874C;
    // nop

L_8005871C:
    // lh          $v0, 0x4($s2)
    ctx->r2 = MEM_HS(0X4, ctx->r18);
    // nop

    // bne         $s0, $v0, L_8005874C
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_8005874C;
    }
    // nop

    // jal         0x80074314
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    SsVabTransCompleted(rdram, ctx);
    goto after_7;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // jal         0x80015848
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    NextCdTask(rdram, ctx);
    goto after_8;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_8:
    // lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(0X8, ctx->r17);
    // nop

    // sh          $s3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r19;
    // sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
L_8005874C:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
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
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
