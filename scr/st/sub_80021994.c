#include "recomp.h"
#include "disable_warnings.h"

void sub_80021994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lw          $t0, 0x10($sp)
    ctx->r8 = MEM_W(0X10, ctx->r29);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $t0, $v0, L_80021A44
    if (ctx->r8 == ctx->r2) {
        // slti        $v0, $t0, 0x3
        ctx->r2 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
        goto L_80021A44;
    }
    // slti        $v0, $t0, 0x3
    ctx->r2 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // beq         $v0, $zero, L_800219BC
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_800219BC;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $t0, $v0, L_800219CC
    if (ctx->r8 == ctx->r2) {
        // mult        $a0, $a3
        result = S64(S32(ctx->r4)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_800219CC;
    }
    // mult        $a0, $a3
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // j           L_80021ABC
    // nop

    goto L_80021ABC;
    // nop

L_800219BC:
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // bne         $t0, $v0, L_80021ABC
    if (ctx->r8 != ctx->r2) {
        // nop
    
        goto L_80021ABC;
    }
    // nop

    // mult        $a0, $a3
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
L_800219CC:
    // mflo        $t1
    ctx->r9 = lo;
    // nop

    // nop

    // mult        $a1, $a3
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x6CD6($v1)
    ctx->r2 = MEM_BU(0X6CD6, ctx->r3);
    // mflo        $a1
    ctx->r5 = lo;
    // sb          $t0, 0x6CD8($v1)
    MEM_B(0X6CD8, ctx->r3) = ctx->r8;
    // nop

    // mult        $a2, $a3
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x6CD6($v1)
    MEM_B(0X6CD6, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x6CDA($v1)
    ctx->r2 = MEM_HU(0X6CDA, ctx->r3);
    // sra         $a0, $t1, 12
    ctx->r4 = S32(ctx->r9) >> 12;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x6CDA($v1)
    MEM_H(0X6CDA, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x6CDE($v1)
    ctx->r2 = MEM_HU(0X6CDE, ctx->r3);
    // sra         $a0, $a1, 12
    ctx->r4 = S32(ctx->r5) >> 12;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x6CDE($v1)
    MEM_H(0X6CDE, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x6CE2($v1)
    ctx->r2 = MEM_HU(0X6CE2, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // sra         $a0, $t0, 12
    ctx->r4 = S32(ctx->r8) >> 12;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // j           L_80021ABC
    // sh          $v0, 0x6CE2($v1)
    MEM_H(0X6CE2, ctx->r3) = ctx->r2;
    goto L_80021ABC;
    // sh          $v0, 0x6CE2($v1)
    MEM_H(0X6CE2, ctx->r3) = ctx->r2;
L_80021A44:
    // mult        $a0, $a3
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t1
    ctx->r9 = lo;
    // nop

    // nop

    // mult        $a1, $a3
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x6CD7($v1)
    ctx->r2 = MEM_BU(0X6CD7, ctx->r3);
    // mflo        $a1
    ctx->r5 = lo;
    // sb          $t0, 0x6CD9($v1)
    MEM_B(0X6CD9, ctx->r3) = ctx->r8;
    // nop

    // mult        $a2, $a3
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x6CD7($v1)
    MEM_B(0X6CD7, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x6CDC($v1)
    ctx->r2 = MEM_HU(0X6CDC, ctx->r3);
    // sra         $a0, $t1, 12
    ctx->r4 = S32(ctx->r9) >> 12;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x6CDC($v1)
    MEM_H(0X6CDC, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x6CE0($v1)
    ctx->r2 = MEM_HU(0X6CE0, ctx->r3);
    // sra         $a0, $a1, 12
    ctx->r4 = S32(ctx->r5) >> 12;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x6CE0($v1)
    MEM_H(0X6CE0, ctx->r3) = ctx->r2;
    // lhu         $v0, 0x6CE4($v1)
    ctx->r2 = MEM_HU(0X6CE4, ctx->r3);
    // mflo        $t0
    ctx->r8 = lo;
    // sra         $a0, $t0, 12
    ctx->r4 = S32(ctx->r8) >> 12;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x6CE4($v1)
    MEM_H(0X6CE4, ctx->r3) = ctx->r2;
L_80021ABC:
    // jr          $ra
    // nop

    return;
    // nop

;}
