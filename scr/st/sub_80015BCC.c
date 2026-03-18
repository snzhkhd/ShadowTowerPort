#include "recomp.h"
#include "disable_warnings.h"

void sub_80015BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a3, $zero
    ctx->r19 = ADD32(ctx->r7, 0);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // addiu       $s5, $v0, -0x7E00
    ctx->r21 = ADD32(ctx->r2, -0X7E00);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $s4, 0x9D4($s5)
    ctx->r20 = MEM_W(0X9D4, ctx->r21);
    // lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(0X40, ctx->r29);
    // jal         0x80015B2C
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    sub_80015B2C(rdram, ctx);
    goto after_0;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_0:
    // sb          $s2, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r18;
    // sb          $zero, 0x1($s4)
    MEM_B(0X1, ctx->r20) = 0;
    // lwl         $v0, 0x3($s6)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r22);
    // lwr         $v0, 0x0($s6)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r22);
    // nop

    // swl         $v0, 0x1B($s4)
    do_swl(rdram, 0X1B, ctx->r20, ctx->r2);
    // swr         $v0, 0x18($s4)
    do_swr(rdram, 0X18, ctx->r20, ctx->r2);
    // addiu       $s0, $s0, 0x7FF
    ctx->r16 = ADD32(ctx->r16, 0X7FF);
    // srl         $s0, $s0, 11
    ctx->r16 = S32(U32(ctx->r16) >> 11);
    // sw          $s3, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->r19;
    // sw          $s0, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->r16;
    // sw          $s1, 0x2C($s4)
    MEM_W(0X2C, ctx->r20) = ctx->r17;
    // lw          $v0, 0x9D4($s5)
    ctx->r2 = MEM_W(0X9D4, ctx->r21);
    // addiu       $v1, $s5, 0x9D4
    ctx->r3 = ADD32(ctx->r21, 0X9D4);
    // addiu       $v0, $v0, 0x34
    ctx->r2 = ADD32(ctx->r2, 0X34);
    // bne         $v0, $v1, L_80015C64
    if (ctx->r2 != ctx->r3) {
        // sw          $v0, 0x9D4($s5)
        MEM_W(0X9D4, ctx->r21) = ctx->r2;
        goto L_80015C64;
    }
    // sw          $v0, 0x9D4($s5)
    MEM_W(0X9D4, ctx->r21) = ctx->r2;
    // addiu       $v0, $s5, 0x14
    ctx->r2 = ADD32(ctx->r21, 0X14);
    // sw          $v0, 0x9D4($s5)
    MEM_W(0X9D4, ctx->r21) = ctx->r2;
L_80015C64:
    // lw          $v0, 0x9D8($s5)
    ctx->r2 = MEM_W(0X9D8, ctx->r21);
    // nop

    // bne         $v0, $s4, L_80015CA4
    if (ctx->r2 != ctx->r20) {
        // addu        $v0, $s4, $zero
        ctx->r2 = ADD32(ctx->r20, 0);
        goto L_80015CA4;
    }
    // addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // jal         0x80068CCC
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    CdReadyCallback(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80068CB8
    // addiu       $a0, $a0, 0x561C
    ctx->r4 = ADD32(ctx->r4, 0X561C);
    CdSyncCallback(rdram, ctx);
    goto after_2;
    // addiu       $a0, $a0, 0x561C
    ctx->r4 = ADD32(ctx->r4, 0X561C);
    after_2:
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
L_80015C8C:
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // beq         $v0, $zero, L_80015C8C
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
        goto L_80015C8C;
    }
    // addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
L_80015CA4:
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
