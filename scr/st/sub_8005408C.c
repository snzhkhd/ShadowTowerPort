#include "recomp.h"
#include "disable_warnings.h"

void sub_8005408C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // jal         0x80015AD4
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // lui         $a0, 0x8005
    ctx->r4 = S32(0X8005 << 16);
    // jal         0x80068CCC
    // addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    CdReadyCallback(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    after_1:
    // addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $v0, $zero, 0xCC
    ctx->r2 = ADD32(0, 0XCC);
    // jal         0x80068F50
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    CdControlB(rdram, ctx);
    goto after_2;
    // sb          $v0, 0x10($sp)
    MEM_B(0X10, ctx->r29) = ctx->r2;
    after_2:
    // jal         0x80077104
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    VSync(rdram, ctx);
    goto after_3;
    // addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_3:
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x70D8
    ctx->r16 = ADD32(ctx->r16, -0X70D8);
    // addiu       $s1, $s0, 0x1DC
    ctx->r17 = ADD32(ctx->r16, 0X1DC);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // andi        $a3, $s5, 0xFF
    ctx->r7 = ctx->r21 & 0XFF;
    // lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // addiu       $t0, $t0, -0x45F8
    ctx->r8 = ADD32(ctx->r8, -0X45F8);
    // sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7) << 2;
    // addu        $a1, $v0, $t0
    ctx->r5 = ADD32(ctx->r2, ctx->r8);
    // addiu       $a1, $a1, 0x1618
    ctx->r5 = ADD32(ctx->r5, 0X1618);
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0x4AC
    ctx->r3 = ADD32(ctx->r3, 0X4AC);
    // sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7) << 1;
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // andi        $v1, $s4, 0xFF
    ctx->r3 = ctx->r20 & 0XFF;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // addiu       $s3, $t0, 0x1618
    ctx->r19 = ADD32(ctx->r8, 0X1618);
    // jal         0x80078AA4
    // sw          $v0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r2;
    memcpy_recomp(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r2;
    after_4:
    // addiu       $a0, $s0, 0x1D8
    ctx->r4 = ADD32(ctx->r16, 0X1D8);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x80078AA4
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    memcpy_recomp(rdram, ctx);
    goto after_5;
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8005415C:
    // addu        $a1, $s2, $s3
    ctx->r5 = ADD32(ctx->r18, ctx->r19);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_6;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
    // beq         $v0, $zero, L_8005415C
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
        goto L_8005415C;
    }
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
    // sb          $s4, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r20;
    // addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
L_80054180:
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // jal         0x80068CE0
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControl(rdram, ctx);
    goto after_7;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_7:
    // beq         $v0, $zero, L_80054180
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0xD
        ctx->r4 = ADD32(0, 0XD);
        goto L_80054180;
    }
    // addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2) << 2;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s1, $v0, -0x2FE0
    ctx->r17 = ADD32(ctx->r2, -0X2FE0);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lw          $v1, -0x7DFC($v0)
    ctx->r3 = MEM_W(-0X7DFC, ctx->r2);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sw          $v1, -0x6EF0($v0)
    MEM_W(-0X6EF0, ctx->r2) = ctx->r3;
    // addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
L_800541B8:
    // addu        $a1, $s0, $s1
    ctx->r5 = ADD32(ctx->r16, ctx->r17);
    // jal         0x80068F50
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    CdControlB(rdram, ctx);
    goto after_8;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_8:
    // beq         $v0, $zero, L_800541B8
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x1B
        ctx->r4 = ADD32(0, 0X1B);
        goto L_800541B8;
    }
    // addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
