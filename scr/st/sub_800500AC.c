#include "recomp.h"
#include "disable_warnings.h"

void sub_800500AC(uint8_t* rdram, recomp_context* ctx) 
{
    printf("Call sub_800500AC, another's loop \n\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // addiu       $s1, $sp, 0x28
    ctx->r17 = ADD32(ctx->r29, 0X28);
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
L_800500DC:
    // mult        $s0, $s0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // sra         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3) >> 16;
    // slti        $v0, $a0, 0x100
    ctx->r2 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // bne         $v0, $zero, L_800500F8
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800500F8;
    }
    // nop

    // addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800500F8:
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // jal         0x80021994
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    sub_80021994(rdram, ctx);
    goto after_0;
    // addiu       $a3, $zero, 0x1000
    ctx->r7 = ADD32(0, 0X1000);
    after_0:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // jal         0x80058620
    // nop

    ProcessCDAudioLoad(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x80045FFC
    // nop

    ProcessAssetLoadQueue(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // jal         0x8003E734
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    sub_8003E734(rdram, ctx);
    goto after_4;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // jal         0x80026AFC
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    DrawScene_80026AFC(rdram, ctx);
    goto after_5;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_5:
    // jal         0x8003C24C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8003C24C(rdram, ctx);
    goto after_6;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_6:
    // bne         $s0, $s4, L_800500DC
    if (ctx->r16 != ctx->r20) {
        // addu        $s0, $s0, $s2
        ctx->r16 = ADD32(ctx->r16, ctx->r18);
        goto L_800500DC;
    }
    // addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
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
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
