#include "recomp.h"
#include "disable_warnings.h"

void sub_8003E794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v0, $v1, -0x70D8
    ctx->r2 = ADD32(ctx->r3, -0X70D8);
    // lhu         $v1, -0x70D8($v1)
    ctx->r3 = MEM_HU(-0X70D8, ctx->r3);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lhu         $a0, 0x4($v0)
    ctx->r4 = MEM_HU(0X4, ctx->r2);
    // sh          $zero, 0x1C2($v0)
    MEM_H(0X1C2, ctx->r2) = 0;
    // sh          $zero, 0x1C0($v0)
    MEM_H(0X1C0, ctx->r2) = 0;
    // sh          $zero, 0x1BE($v0)
    MEM_H(0X1BE, ctx->r2) = 0;
    // sh          $zero, 0x1BC($v0)
    MEM_H(0X1BC, ctx->r2) = 0;
    // sh          $zero, 0x1BA($v0)
    MEM_H(0X1BA, ctx->r2) = 0;
    // sh          $zero, 0x1B8($v0)
    MEM_H(0X1B8, ctx->r2) = 0;
    // sh          $zero, 0x1B6($v0)
    MEM_H(0X1B6, ctx->r2) = 0;
    // sh          $zero, 0x1B4($v0)
    MEM_H(0X1B4, ctx->r2) = 0;
    // sh          $zero, 0x1B2($v0)
    MEM_H(0X1B2, ctx->r2) = 0;
    // sh          $zero, 0x1B0($v0)
    MEM_H(0X1B0, ctx->r2) = 0;
    // sh          $zero, 0x1AE($v0)
    MEM_H(0X1AE, ctx->r2) = 0;
    // sh          $zero, 0x1AC($v0)
    MEM_H(0X1AC, ctx->r2) = 0;
    // sh          $zero, 0x1AA($v0)
    MEM_H(0X1AA, ctx->r2) = 0;
    // sh          $zero, 0x1A8($v0)
    MEM_H(0X1A8, ctx->r2) = 0;
    // sh          $zero, 0x1A6($v0)
    MEM_H(0X1A6, ctx->r2) = 0;
    // sh          $zero, 0x1A4($v0)
    MEM_H(0X1A4, ctx->r2) = 0;
    // sh          $zero, 0x1A2($v0)
    MEM_H(0X1A2, ctx->r2) = 0;
    // sh          $zero, 0x1A0($v0)
    MEM_H(0X1A0, ctx->r2) = 0;
    // sh          $zero, 0x19E($v0)
    MEM_H(0X19E, ctx->r2) = 0;
    // sh          $zero, 0x19C($v0)
    MEM_H(0X19C, ctx->r2) = 0;
    // sh          $zero, 0x19A($v0)
    MEM_H(0X19A, ctx->r2) = 0;
    // sh          $zero, 0x198($v0)
    MEM_H(0X198, ctx->r2) = 0;
    // sh          $zero, 0x196($v0)
    MEM_H(0X196, ctx->r2) = 0;
    // sh          $zero, 0x194($v0)
    MEM_H(0X194, ctx->r2) = 0;
    // sh          $zero, 0x192($v0)
    MEM_H(0X192, ctx->r2) = 0;
    // sh          $zero, 0x190($v0)
    MEM_H(0X190, ctx->r2) = 0;
    // sb          $zero, 0x238($v0)
    MEM_B(0X238, ctx->r2) = 0;
    // sh          $v1, 0x18A($v0)
    MEM_H(0X18A, ctx->r2) = ctx->r3;
    // sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // sh          $a0, 0x18C($v0)
    MEM_H(0X18C, ctx->r2) = ctx->r4;
    // sh          $a0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r4;
    // jal         0x8003C054
    // sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    sub_8003C054(rdram, ctx);
    goto after_0;
    // sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    after_0:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
