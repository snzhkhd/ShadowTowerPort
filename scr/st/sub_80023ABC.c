#include "recomp.h"
#include "disable_warnings.h"

void sub_80023ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // andi        $s0, $s2, 0xFFFF
    ctx->r16 = ctx->r18 & 0XFFFF;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addiu       $s4, $s3, 0x1
    ctx->r20 = ADD32(ctx->r19, 0X1);
    // andi        $a1, $s4, 0xFFFF
    ctx->r5 = ctx->r20 & 0XFFFF;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // jal         0x80015EC8
    // addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    sub_80015EC8(rdram, ctx);
    goto after_0;
    // addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // andi        $a1, $s3, 0xFFFF
    ctx->r5 = ctx->r19 & 0XFFFF;
    // jal         0x80015EC8
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    sub_80015EC8(rdram, ctx);
    goto after_1;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // sltu        $v0, $a1, $s0
    ctx->r2 = ctx->r5 < ctx->r16 ? 1 : 0;
    // beq         $v0, $zero, L_80023B24
    if (ctx->r2 == 0) {
        // lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
        goto L_80023B24;
    }
    // lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_80023B24:
    // addiu       $a0, $a0, -0x3778
    ctx->r4 = ADD32(ctx->r4, -0X3778);
    // andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17) << 2;
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
    // beq         $s0, $zero, L_80023B9C
    if (ctx->r16 == 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80023B9C;
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
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    sub_80015278(rdram, ctx);
    goto after_4;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
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
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lui         $a3, 0x8002
    ctx->r7 = S32(0X8002 << 16);
    // jal         0x80015D54
    // addiu       $a3, $a3, 0x3604
    ctx->r7 = ADD32(ctx->r7, 0X3604);
    sub_80015D54(rdram, ctx);
    goto after_6;
    // addiu       $a3, $a3, 0x3604
    ctx->r7 = ADD32(ctx->r7, 0X3604);
    after_6:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lui         $a3, 0x8002
    ctx->r7 = S32(0X8002 << 16);
    // jal         0x80015D54
    // addiu       $a3, $a3, 0x3470
    ctx->r7 = ADD32(ctx->r7, 0X3470);
    sub_80015D54(rdram, ctx);
    goto after_7;
    // addiu       $a3, $a3, 0x3470
    ctx->r7 = ADD32(ctx->r7, 0X3470);
    after_7:
L_80023B9C:
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
