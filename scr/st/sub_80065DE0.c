#include "recomp.h"
#include "disable_warnings.h"

void sub_80065DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // lui         $s5, 0x1F80
    ctx->r21 = S32(0X1F80 << 16);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // addiu       $fp, $v0, 0xD08
    ctx->r30 = ADD32(ctx->r2, 0XD08);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $s5, $zero
    ctx->r20 = ADD32(ctx->r21, 0);
    // ori         $s4, $s4, 0x300
    ctx->r20 = ctx->r20 | 0X300;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addiu       $s6, $v0, 0xD50
    ctx->r22 = ADD32(ctx->r2, 0XD50);
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // addiu       $s7, $s6, 0xC00
    ctx->r23 = ADD32(ctx->r22, 0XC00);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addiu       $s3, $zero, 0x40
    ctx->r19 = ADD32(0, 0X40);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addiu       $s2, $zero, 0x30
    ctx->r18 = ADD32(0, 0X30);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80065E38:
    // lhu         $v0, 0x2E2($s5)
    ctx->r2 = MEM_HU(0X2E2, ctx->r21);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // addu        $a0, $v0, $fp
    ctx->r4 = ADD32(ctx->r2, ctx->r30);
    // lbu         $v1, 0x8($a0)
    ctx->r3 = MEM_BU(0X8, ctx->r4);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_80065EFC
    if (ctx->r3 == ctx->r2) {
        // addiu       $a1, $zero, 0x1C
        ctx->r5 = ADD32(0, 0X1C);
        goto L_80065EFC;
    }
    // addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // andi        $a2, $s2, 0xFFFF
    ctx->r6 = ctx->r18 & 0XFFFF;
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, 0x92C
    ctx->r2 = ADD32(ctx->r2, 0X92C);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // andi        $s0, $s3, 0xFFFF
    ctx->r16 = ctx->r19 & 0XFFFF;
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // addiu       $s3, $s3, 0x24
    ctx->r19 = ADD32(ctx->r19, 0X24);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // lhu         $a0, 0x728($v0)
    ctx->r4 = MEM_HU(0X728, ctx->r2);
    // addiu       $s2, $s2, 0x24
    ctx->r18 = ADD32(ctx->r18, 0X24);
    // jal         0x8002732C
    // addu        $a0, $a0, $s7
    ctx->r4 = ADD32(ctx->r4, ctx->r23);
    sub_8002732C(rdram, ctx);
    goto after_0;
    // addu        $a0, $a0, $s7
    ctx->r4 = ADD32(ctx->r4, ctx->r23);
    after_0:
    // addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // lhu         $a0, 0x750($s6)
    ctx->r4 = MEM_HU(0X750, ctx->r22);
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // jal         0x8002732C
    // addu        $a0, $a0, $s7
    ctx->r4 = ADD32(ctx->r4, ctx->r23);
    sub_8002732C(rdram, ctx);
    goto after_1;
    // addu        $a0, $a0, $s7
    ctx->r4 = ADD32(ctx->r4, ctx->r23);
    after_1:
    // addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addiu       $a3, $s5, 0x310
    ctx->r7 = ADD32(ctx->r21, 0X310);
    // lhu         $v0, 0x2E2($s5)
    ctx->r2 = MEM_HU(0X2E2, ctx->r21);
    // lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(0X8, ctx->r2);
    // addiu       $t0, $t0, -0x2D68
    ctx->r8 = ADD32(ctx->r8, -0X2D68);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(0X2, ctx->r2);
    // lui         $a0, 0x300
    ctx->r4 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    sub_80027440(rdram, ctx);
    goto after_2;
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    after_2:
L_80065EFC:
    // addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // slti        $v0, $s1, 0x5
    ctx->r2 = SIGNED(ctx->r17) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80065E38
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80065E38;
    }
    // nop

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
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
