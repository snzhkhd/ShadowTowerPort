#include "recomp.h"
#include "disable_warnings.h"

void sub_8004567C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // sb          $zero, 0x2A1($v0)
    MEM_B(0X2A1, ctx->r2) = 0;
    // addiu       $v0, $a1, 0x5920
    ctx->r2 = ADD32(ctx->r5, 0X5920);
    // lbu         $v1, 0x10($v0)
    ctx->r3 = MEM_BU(0X10, ctx->r2);
    // addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // beq         $v1, $a0, L_800456A0
    if (ctx->r3 == ctx->r4) {
        // sb          $zero, 0x1E($v0)
        MEM_B(0X1E, ctx->r2) = 0;
        goto L_800456A0;
    }
    // sb          $zero, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = 0;
    // sb          $v1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r3;
L_800456A0:
    // lbu         $v1, 0x11($v0)
    ctx->r3 = MEM_BU(0X11, ctx->r2);
    // nop

    // beq         $v1, $a0, L_800456B4
    if (ctx->r3 == ctx->r4) {
        // nop
    
        goto L_800456B4;
    }
    // nop

    // sb          $v1, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r3;
L_800456B4:
    // lbu         $v1, 0x12($v0)
    ctx->r3 = MEM_BU(0X12, ctx->r2);
    // nop

    // beq         $v1, $a0, L_800456C8
    if (ctx->r3 == ctx->r4) {
        // nop
    
        goto L_800456C8;
    }
    // nop

    // sb          $v1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r3;
L_800456C8:
    // lbu         $v1, 0x13($v0)
    ctx->r3 = MEM_BU(0X13, ctx->r2);
    // nop

    // beq         $v1, $a0, L_800456DC
    if (ctx->r3 == ctx->r4) {
        // nop
    
        goto L_800456DC;
    }
    // nop

    // sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
L_800456DC:
    // lbu         $v1, 0x14($v0)
    ctx->r3 = MEM_BU(0X14, ctx->r2);
    // nop

    // beq         $v1, $a0, L_800456F0
    if (ctx->r3 == ctx->r4) {
        // nop
    
        goto L_800456F0;
    }
    // nop

    // sb          $v1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r3;
L_800456F0:
    // jr          $ra
    // sh          $zero, 0x5920($a1)
    MEM_H(0X5920, ctx->r5) = 0;
    return;
    // sh          $zero, 0x5920($a1)
    MEM_H(0X5920, ctx->r5) = 0;
;}
