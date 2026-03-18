#include "recomp.h"
#include "disable_warnings.h"

void gteMIMefunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sll         $a2, $a2, 3
    ctx->r6 = S32(ctx->r6) << 3;
    // add         $a2, $a2, $a1
    ctx->r6 = ADD32(ctx->r6, ctx->r5);
    // mtc2        $a3, $8
    gte_mtc2(ctx, 7, 8);
L_80074A10:
    // lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(0X0, ctx->r5);
    // lh          $t2, 0x4($a1)
    ctx->r10 = MEM_HS(0X4, ctx->r5);
    // sra         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8) >> 16;
    // andi        $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 & 0XFFFF;
    // mtc2        $t0, $9
    gte_mtc2(ctx, 8, 9);
    // mtc2        $t1, $10
    gte_mtc2(ctx, 9, 10);
    // mtc2        $t2, $11
    gte_mtc2(ctx, 10, 11);
    // nop

    // nop

    // .word       0x4B98003D                   # INVALID     $gp, $t8, 0x3D # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B98003D);
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // lh          $a3, 0x4($a0)
    ctx->r7 = MEM_HS(0X4, ctx->r4);
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // addi        $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // mfc2        $t0, $9
    ctx->r8 = gte_mfc2(ctx, 9);
    // mfc2        $t1, $10
    ctx->r9 = gte_mfc2(ctx, 10);
    // mfc2        $t2, $11
    ctx->r10 = gte_mfc2(ctx, 11);
    // add         $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // add         $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // add         $a3, $a3, $t2
    ctx->r7 = ADD32(ctx->r7, ctx->r10);
    // sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // sh          $v1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r3;
    // sh          $a3, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r7;
    // addi        $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // bne         $a1, $a2, L_80074A10
    if (ctx->r5 != ctx->r6) {
        // nop
    
        goto L_80074A10;
    }
    // nop

    // jr          $ra
    // nop

    return;
    // nop

;}
