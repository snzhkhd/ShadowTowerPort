#include "recomp.h"
#include "disable_warnings.h"

void sub_8003C054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // sh          $zero, 0x2CE($v0)
    MEM_H(0X2CE, ctx->r2) = 0;
    // sh          $zero, 0x2D0($v0)
    MEM_H(0X2D0, ctx->r2) = 0;
    // sh          $zero, 0x2D2($v0)
    MEM_H(0X2D2, ctx->r2) = 0;
    // sb          $zero, 0x239($v0)
    MEM_B(0X239, ctx->r2) = 0;
    // sh          $zero, 0x2D4($v0)
    MEM_H(0X2D4, ctx->r2) = 0;
    // sb          $zero, 0x218($v0)
    MEM_B(0X218, ctx->r2) = 0;
    // sh          $zero, 0x294($v0)
    MEM_H(0X294, ctx->r2) = 0;
    // sh          $zero, 0x292($v0)
    MEM_H(0X292, ctx->r2) = 0;
    // sh          $zero, 0x290($v0)
    MEM_H(0X290, ctx->r2) = 0;
    // sh          $zero, 0x28C($v0)
    MEM_H(0X28C, ctx->r2) = 0;
    // sh          $zero, 0x28A($v0)
    MEM_H(0X28A, ctx->r2) = 0;
    // sh          $zero, 0x288($v0)
    MEM_H(0X288, ctx->r2) = 0;
    // sh          $zero, 0x284($v0)
    MEM_H(0X284, ctx->r2) = 0;
    // sh          $zero, 0x282($v0)
    MEM_H(0X282, ctx->r2) = 0;
    // sh          $zero, 0x280($v0)
    MEM_H(0X280, ctx->r2) = 0;
    // lwl         $v1, 0x27B($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X27B, ctx->r2);
    // lwr         $v1, 0x278($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X278, ctx->r2);
    // lwl         $a0, 0x27F($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X27F, ctx->r2);
    // lwr         $a0, 0x27C($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X27C, ctx->r2);
    // swl         $v1, 0x26B($v0)
    do_swl(rdram, 0X26B, ctx->r2, ctx->r3);
    // swr         $v1, 0x268($v0)
    do_swr(rdram, 0X268, ctx->r2, ctx->r3);
    // swl         $a0, 0x26F($v0)
    do_swl(rdram, 0X26F, ctx->r2, ctx->r4);
    // swr         $a0, 0x26C($v0)
    do_swr(rdram, 0X26C, ctx->r2, ctx->r4);
    // addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // sb          $v1, 0x155($v0)
    MEM_B(0X155, ctx->r2) = ctx->r3;
    // sb          $v1, 0x156($v0)
    MEM_B(0X156, ctx->r2) = ctx->r3;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // sw          $zero, 0x2F0($v0)
    MEM_W(0X2F0, ctx->r2) = 0;
    // sw          $zero, 0x2EC($v0)
    MEM_W(0X2EC, ctx->r2) = 0;
    // sw          $zero, -0x5EDC($v1)
    MEM_W(-0X5EDC, ctx->r3) = 0;
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // jr          $ra
    // sw          $v1, 0x2F4($v0)
    MEM_W(0X2F4, ctx->r2) = ctx->r3;
    return;
    // sw          $v1, 0x2F4($v0)
    MEM_W(0X2F4, ctx->r2) = ctx->r3;
;}
