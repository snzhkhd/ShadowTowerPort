#include "recomp.h"
#include "disable_warnings.h"

void VectorNormalS(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(0X0, ctx->r4);
    // lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(0X4, ctx->r4);
    // lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(0X8, ctx->r4);
    // b           L_80074830
    // nop

    goto L_80074830;
    // nop

    // lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(0X0, ctx->r4);
    // lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(0X4, ctx->r4);
    // lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(0X8, ctx->r4);
    // addu        $a3, $ra, $zero
    ctx->r7 = ADD32(ctx->r31, 0);
    // jal         0x80074854
    // nop

    sub_80074854(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // sw          $t2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r10;
    // addu        $ra, $a3, $zero
    ctx->r31 = ADD32(ctx->r7, 0);
    // jr          $ra
    // nop

    return;
    // nop

    // lh          $t0, 0x0($a0)
    ctx->r8 = MEM_HS(0X0, ctx->r4);
    // lh          $t1, 0x2($a0)
    ctx->r9 = MEM_HS(0X2, ctx->r4);
    // lh          $t2, 0x4($a0)
    ctx->r10 = MEM_HS(0X4, ctx->r4);
L_80074830:
    // addu        $a3, $ra, $zero
    ctx->r7 = ADD32(ctx->r31, 0);
    // jal         0x80074854
    // nop

    sub_80074854(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
    // sh          $t2, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r10;
    // addu        $ra, $a3, $zero
    ctx->r31 = ADD32(ctx->r7, 0);
    // jr          $ra
    // nop

    return;
    // nop

;}
