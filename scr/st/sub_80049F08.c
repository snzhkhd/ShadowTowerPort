#include "recomp.h"
#include "disable_warnings.h"

void sub_80049F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sw          $ra, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r31;
    // sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // sh          $zero, 0x50($sp)
    MEM_H(0X50, ctx->r29) = 0;
    // sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
    // sh          $v0, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r2;
    // lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(0X0, ctx->r16);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x80049CD4
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_80049CD4(rdram, ctx);
    goto after_0;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_0:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $s3, $sp, 0x50
    ctx->r19 = ADD32(ctx->r29, 0X50);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // addiu       $s2, $sp, 0x58
    ctx->r18 = ADD32(ctx->r29, 0X58);
    // jal         0x80074CA4
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    ApplyMatrix(rdram, ctx);
    goto after_1;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_1:
    // lhu         $v0, 0x58($sp)
    ctx->r2 = MEM_HU(0X58, ctx->r29);
    // lhu         $v1, 0x5C($sp)
    ctx->r3 = MEM_HU(0X5C, ctx->r29);
    // lhu         $a0, 0x60($sp)
    ctx->r4 = MEM_HU(0X60, ctx->r29);
    // sh          $v0, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r2;
    // sh          $v1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r3;
    // sh          $a0, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r4;
    // lh          $a0, 0x2($s0)
    ctx->r4 = MEM_HS(0X2, ctx->r16);
    // addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // jal         0x80049D48
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_80049D48(rdram, ctx);
    goto after_2;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // jal         0x80074CA4
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    ApplyMatrix(rdram, ctx);
    goto after_3;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_3:
    // lhu         $v0, 0x58($sp)
    ctx->r2 = MEM_HU(0X58, ctx->r29);
    // nop

    // sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x5C($sp)
    ctx->r2 = MEM_HU(0X5C, ctx->r29);
    // nop

    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x60($sp)
    ctx->r2 = MEM_HU(0X60, ctx->r29);
    // nop

    // sh          $v0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r2;
    // lw          $ra, 0x78($sp)
    ctx->r31 = MEM_W(0X78, ctx->r29);
    // lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(0X74, ctx->r29);
    // lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(0X70, ctx->r29);
    // lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(0X6C, ctx->r29);
    // lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(0X68, ctx->r29);
    // addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // jr          $ra
    // nop

    return;
    // nop

;}
