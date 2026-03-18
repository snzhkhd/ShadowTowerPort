#include "recomp.h"
#include "disable_warnings.h"

void sub_80031DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addiu       $s2, $v0, -0x3B74
    ctx->r18 = ADD32(ctx->r2, -0X3B74);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addiu       $s4, $zero, 0x7F
    ctx->r20 = ADD32(0, 0X7F);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $s3, 0xE
    ctx->r16 = ADD32(ctx->r19, 0XE);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addiu       $s1, $s2, 0x5
    ctx->r17 = ADD32(ctx->r18, 0X5);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_80031E18:
    // lhu         $a0, 0x0($s3)
    ctx->r4 = MEM_HU(0X0, ctx->r19);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // beq         $v1, $v0, L_80031EB8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80031EB8;
    }
    // nop

    // sh          $a0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r4;
    // lbu         $v0, -0x6($s0)
    ctx->r2 = MEM_BU(-0X6, ctx->r16);
    // lbu         $v1, -0xA($s0)
    ctx->r3 = MEM_BU(-0XA, ctx->r16);
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sb          $v1, -0x3($s1)
    MEM_B(-0X3, ctx->r17) = ctx->r3;
    // lbu         $v0, -0xC($s0)
    ctx->r2 = MEM_BU(-0XC, ctx->r16);
    // nop

    // sb          $v0, -0x2($s1)
    MEM_B(-0X2, ctx->r17) = ctx->r2;
    // lbu         $v0, -0xB($s0)
    ctx->r2 = MEM_BU(-0XB, ctx->r16);
    // nop

    // sb          $v0, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r2;
    // lbu         $v0, -0x9($s0)
    ctx->r2 = MEM_BU(-0X9, ctx->r16);
    // lh          $v1, -0x4($s0)
    ctx->r3 = MEM_HS(-0X4, ctx->r16);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x3($s1)
    MEM_W(0X3, ctx->r17) = ctx->r2;
    // lbu         $v0, -0x8($s0)
    ctx->r2 = MEM_BU(-0X8, ctx->r16);
    // lh          $v1, -0x2($s0)
    ctx->r3 = MEM_HS(-0X2, ctx->r16);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x7($s1)
    MEM_W(0X7, ctx->r17) = ctx->r2;
    // lbu         $v0, -0x7($s0)
    ctx->r2 = MEM_BU(-0X7, ctx->r16);
    // lh          $v1, 0x0($s0)
    ctx->r3 = MEM_HS(0X0, ctx->r16);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80078AC4
    // sw          $v0, 0xB($s1)
    MEM_W(0XB, ctx->r17) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_0;
    // sw          $v0, 0xB($s1)
    MEM_W(0XB, ctx->r17) = ctx->r2;
    after_0:
    // lbu         $v1, -0x2($s1)
    ctx->r3 = MEM_BU(-0X2, ctx->r17);
    // nop

    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // sra         $v0, $a1, 15
    ctx->r2 = S32(ctx->r5) >> 15;
    // j           L_80031EBC
    // sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    goto L_80031EBC;
    // sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
L_80031EB8:
    // sh          $v1, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r3;
L_80031EBC:
    // addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s4, $v0, L_80031E18
    if (ctx->r20 != ctx->r2) {
        // addiu       $s3, $s3, 0x10
        ctx->r19 = ADD32(ctx->r19, 0X10);
        goto L_80031E18;
    }
    // addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
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
