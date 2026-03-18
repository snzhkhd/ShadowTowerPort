#include "recomp.h"
#include "disable_warnings.h"

void sub_80062BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // addiu       $a3, $v0, -0x7F34
    ctx->r7 = ADD32(ctx->r2, -0X7F34);
    // lh          $v1, 0x0($a3)
    ctx->r3 = MEM_HS(0X0, ctx->r7);
    // lb          $a1, 0x2($a3)
    ctx->r5 = MEM_BS(0X2, ctx->r7);
    // sh          $v1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r3;
    // sb          $a1, 0x12($sp)
    MEM_B(0X12, ctx->r29) = ctx->r5;
    // jal         0x80078AE4
    // nop

    itoa(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80078A64
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    strcat_recomp(rdram, ctx);
    goto after_1;
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_1:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // jal         0x80078A64
    // addiu       $a1, $a1, -0x7F2C
    ctx->r5 = ADD32(ctx->r5, -0X7F2C);
    strcat_recomp(rdram, ctx);
    goto after_2;
    // addiu       $a1, $a1, -0x7F2C
    ctx->r5 = ADD32(ctx->r5, -0X7F2C);
    after_2:
    // jal         0x80077F04
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    format(rdram, ctx);
    goto after_3;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(0X30, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
