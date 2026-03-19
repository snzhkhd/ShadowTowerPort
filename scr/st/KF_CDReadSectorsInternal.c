#include "recomp.h"
#include "disable_warnings.h"

void KF_CDReadSectorsInternal(uint8_t* rdram, recomp_context* ctx)
{
    printf("CDReadSectorsInternal\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // jal         0x80068F50
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    CdControlB(rdram, ctx);
    goto after_0;
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    after_0:
    // jal         0x80077104
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    VSync(rdram, ctx);
    goto after_1;
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80015F5C:
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // beq         $v0, $zero, L_80015F5C
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
        goto L_80015F5C;
    }
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // jal         0x8006B944
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    CdReadWithRetry(rdram, ctx);
    goto after_4;
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_4:
    // bne         $v0, $zero, L_80015F9C
    if (ctx->r2 != 0) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_80015F9C;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80068C78
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    CdSync(rdram, ctx);
    goto after_5;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_5:
    // j           L_80015F5C
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    goto L_80015F5C;
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80015F9C:
    // jal         0x8006BA44
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    CdCheckStatus(rdram, ctx);
    goto after_6;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_6:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // blez        $s0, L_80015FC0
    if (SIGNED(ctx->r16) <= 0) {
        // addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
        goto L_80015FC0;
    }
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // jal         0x800214CC
    // nop

    sub_800214CC(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // j           L_80015F9C
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    goto L_80015F9C;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80015FC0:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80068CE0
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    CdControl(rdram, ctx);
    goto after_8;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_8:
    // bne         $s0, $zero, L_80015F5C
    if (ctx->r16 != 0) {
        // addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
        goto L_80015F5C;
    }
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop
    printf("CDReadSectorsInternal end\n");
    return;
    // nop

;}
