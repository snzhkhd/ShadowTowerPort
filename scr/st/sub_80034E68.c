#include "recomp.h"
#include "disable_warnings.h"

void sub_80034E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(0X4, ctx->r5);
    // lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(0X48, ctx->r29);
    // lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(0X4C, ctx->r29);
    // lhu         $s1, 0x2($a1)
    ctx->r17 = MEM_HU(0X2, ctx->r5);
    // sltu        $a0, $a0, $v0
    ctx->r4 = ctx->r4 < ctx->r2 ? 1 : 0;
    // bne         $a0, $zero, L_80034EE0
    if (ctx->r4 != 0) {
        // addu        $s5, $a3, $zero
        ctx->r21 = ADD32(ctx->r7, 0);
        goto L_80034EE0;
    }
    // addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // beq         $s1, $zero, L_80034EE0
    if (ctx->r17 == 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_80034EE0;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_80034EB4:
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // jal         0x800349D0
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    sub_800349D0(rdram, ctx);
    goto after_0;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_0:
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // sltu        $v0, $s0, $s1
    ctx->r2 = ctx->r16 < ctx->r17 ? 1 : 0;
    // bne         $v0, $zero, L_80034EB4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80034EB4;
    }
    // nop

L_80034EE0:
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
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
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
