#include "recomp.h"
#include "disable_warnings.h"

void sub_800796A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(0X10, ctx->r29);
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // sh          $a1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r5;
    // sh          $a2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r6;
    // sh          $a3, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r7;
    // sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // sb          $zero, 0x11($v0)
    MEM_B(0X11, ctx->r2) = 0;
    // sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    // sb          $zero, 0x13($v0)
    MEM_B(0X13, ctx->r2) = 0;
    // sb          $zero, 0x12($v0)
    MEM_B(0X12, ctx->r2) = 0;
    // jr          $ra
    // sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    return;
    // sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
;}
