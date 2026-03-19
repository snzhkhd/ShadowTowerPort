#include "recomp.h"
#include "disable_warnings.h"

void sub_800173A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addiu       $s2, $zero, 0xF0
    ctx->r18 = ADD32(0, 0XF0);
    // addiu       $v1, $zero, 0xA0
    ctx->r3 = ADD32(0, 0XA0);
    // addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3) << 16;
    // sll         $t5, $t0, 16
    ctx->r13 = S32(ctx->r8) << 16;
    // ctc2        $t4, $24
    gte_ctc2(ctx, 12, 24);
    // ctc2        $t5, $25
    gte_ctc2(ctx, 13, 25);
    // addiu       $v1, $zero, 0x12C
    ctx->r3 = ADD32(0, 0X12C);
    // ctc2        $v1, $26
    gte_ctc2(ctx, 3, 26);
    // lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // addiu       $s0, $s0, -0x2F70
    ctx->r16 = ADD32(ctx->r16, -0X2F70);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    // jal         0x800795F4
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    ST_SetDefDrawEnv(rdram, ctx);
    goto after_0;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_0:
    // addiu       $s4, $s0, 0xB8
    ctx->r20 = ADD32(ctx->r16, 0XB8);
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    // jal         0x800796A8
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    ST_SetDefDispEnv(rdram, ctx);
    goto after_1;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_1:
    // addiu       $s1, $s0, 0x5C
    ctx->r17 = ADD32(ctx->r16, 0X5C);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    // jal         0x800795F4
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    ST_SetDefDrawEnv(rdram, ctx);
    goto after_2;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_2:
    // addiu       $s3, $s0, 0xCC
    ctx->r19 = ADD32(ctx->r16, 0XCC);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    // jal         0x800796A8
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    ST_SetDefDispEnv(rdram, ctx);
    goto after_3;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_3:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x16($a0)
    MEM_B(0X16, ctx->r4) = ctx->r2;
    // sb          $v0, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r2;
    // sb          $zero, 0x19($a0)
    MEM_B(0X19, ctx->r4) = 0;
    // sb          $zero, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = 0;
    // sb          $zero, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = 0;
    // sb          $zero, 0x19($s1)
    MEM_B(0X19, ctx->r17) = 0;
    // sb          $zero, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = 0;
    // jal         0x8007A0C4
    // sb          $zero, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = 0;
    PutDrawEnv(rdram, ctx);
    goto after_4;
    // sb          $zero, 0x1B($s1)
    MEM_B(0X1B, ctx->r17) = 0;
    after_4:
    // jal         0x8007A0C4
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    PutDrawEnv(rdram, ctx);
    goto after_5;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // jal         0x8007A290
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    PutDispEnv(rdram, ctx);
    goto after_6;
    // addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_6:
    // jal         0x8007A290
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    PutDispEnv(rdram, ctx);
    goto after_7;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_7:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
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

    return;
    // nop

;}
