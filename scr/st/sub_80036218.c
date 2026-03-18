#include "recomp.h"
#include "disable_warnings.h"

void sub_80036218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // addiu       $s2, $sp, 0x20
    ctx->r18 = ADD32(ctx->r29, 0X20);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // lh          $a0, 0xA($s0)
    ctx->r4 = MEM_HS(0XA, ctx->r16);
    // lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(0X2, ctx->r16);
    // lhu         $a2, 0x14($s0)
    ctx->r6 = MEM_HU(0X14, ctx->r16);
    // addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // jal         0x80033E30
    // addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    sub_80033E30(rdram, ctx);
    goto after_0;
    // addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // lh          $v1, 0x20($sp)
    ctx->r3 = MEM_HS(0X20, ctx->r29);
    // lh          $v0, 0x0($s1)
    ctx->r2 = MEM_HS(0X0, ctx->r17);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lh          $v1, 0x22($sp)
    ctx->r3 = MEM_HS(0X22, ctx->r29);
    // mflo        $t0
    ctx->r8 = lo;
    // sra         $v0, $t0, 12
    ctx->r2 = S32(ctx->r8) >> 12;
    // sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    // lh          $v0, 0x2($s1)
    ctx->r2 = MEM_HS(0X2, ctx->r17);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lh          $v1, 0x24($sp)
    ctx->r3 = MEM_HS(0X24, ctx->r29);
    // mflo        $t0
    ctx->r8 = lo;
    // sra         $v0, $t0, 12
    ctx->r2 = S32(ctx->r8) >> 12;
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // lh          $v0, 0x4($s1)
    ctx->r2 = MEM_HS(0X4, ctx->r17);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t0
    ctx->r8 = lo;
    // sra         $v0, $t0, 12
    ctx->r2 = S32(ctx->r8) >> 12;
    // sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x30($s0)
    ctx->r2 = MEM_HU(0X30, ctx->r16);
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x32($s0)
    ctx->r2 = MEM_HU(0X32, ctx->r16);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $v0, $v0, 0x800
    ctx->r2 = ADD32(ctx->r2, 0X800);
    // sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x34($s0)
    ctx->r2 = MEM_HU(0X34, ctx->r16);
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // jal         0x8004A078
    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    sub_8004A078(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
