#include "recomp.h"
#include "disable_warnings.h"

void sub_8003BD14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $v0, -0x70D8
    ctx->r16 = ADD32(ctx->r2, -0X70D8);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lbu         $v0, 0x218($s0)
    ctx->r2 = MEM_BU(0X218, ctx->r16);
    // addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // beq         $v0, $v1, L_8003BD9C
    if (ctx->r2 == ctx->r3) {
        // nop
    
        goto L_8003BD9C;
    }
    // nop

    // sb          $v1, 0x218($s0)
    MEM_B(0X218, ctx->r16) = ctx->r3;
    // jal         0x80057C0C
    // sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    sub_80057C0C(rdram, ctx);
    goto after_0;
    // sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    after_0:
    // lui         $v1, 0x2AAA
    ctx->r3 = S32(0X2AAA << 16);
    // ori         $v1, $v1, 0xAAAB
    ctx->r3 = ctx->r3 | 0XAAAB;
    // lhu         $v0, 0x268($s0)
    ctx->r2 = MEM_HU(0X268, ctx->r16);
    // addiu       $a0, $zero, -0x400
    ctx->r4 = ADD32(0, -0X400);
    // andi        $v0, $v0, 0x7FF
    ctx->r2 = ctx->r2 & 0X7FF;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $v1, 0x6E15($v0)
    MEM_B(0X6E15, ctx->r2) = ctx->r3;
    // addiu       $v0, $zero, 0xAA
    ctx->r2 = ADD32(0, 0XAA);
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // sh          $zero, 0x286($s0)
    MEM_H(0X286, ctx->r16) = 0;
    // sh          $v0, 0x17C($s0)
    MEM_H(0X17C, ctx->r16) = ctx->r2;
    // mfhi        $a1
    ctx->r5 = hi;
    // sra         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5) >> 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sh          $v0, 0x17A($s0)
    MEM_H(0X17A, ctx->r16) = ctx->r2;
L_8003BD9C:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
