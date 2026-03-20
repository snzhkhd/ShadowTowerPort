#include "recomp.h"
#include "disable_warnings.h"

void sub_8003C17C(uint8_t* rdram, recomp_context* ctx) 
{
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lhu         $t0, 0x0($a0)
    ctx->r8 = MEM_HU(0X0, ctx->r4);
    // lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(0X10, ctx->r29);
    // beq         $a1, $zero, L_8003C190
    if (ctx->r5 == 0) {
        // addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
        goto L_8003C190;
    }
    // addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // lhu         $t2, 0x0($a1)
    ctx->r10 = MEM_HU(0X0, ctx->r5);
L_8003C190:
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // sra         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2) >> 16;
    // bne         $t1, $zero, L_8003C1A8
    if (ctx->r9 != 0) {
        // sll         $v0, $t2, 16
        ctx->r2 = S32(ctx->r10) << 16;
        goto L_8003C1A8;
    }
    // sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10) << 16;
    // beq         $t2, $zero, L_8003C240
    if (ctx->r10 == 0) {
        // nop
    
        goto L_8003C240;
    }
    // nop

L_8003C1A8:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $t1, $v0
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003C1C0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003C1C0;
    }
    // nop

    // j           L_8003C1C8
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    goto L_8003C1C8;
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_8003C1C0:
    // addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_8003C1C8:
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // slt         $v0, $v1, $a2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // beq         $v0, $zero, L_8003C21C
    if (ctx->r2 == 0) {
        // mult        $v1, $a3
        result = S64(S32(ctx->r3)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_8003C21C;
    }
    // mult        $v1, $a3
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // bne         $a2, $zero, L_8003C1F8
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8003C1F8;
    }
    // nop

    // break       7
    do_break(2147729908);
L_8003C1F8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a2, $at, L_8003C210
    if (ctx->r6 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003C210;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003C210
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003C210;
    }
    // nop

    // break       6
    do_break(2147729932);
L_8003C210:
    // mflo        $v0
    ctx->r2 = lo;
    // j           L_8003C220
    // nop

    goto L_8003C220;
    // nop

L_8003C21C:
    // addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
L_8003C220:
    // beq         $t3, $zero, L_8003C234
    if (ctx->r11 == 0) {
        // nop
    
        goto L_8003C234;
    }
    // nop

    // beq         $a1, $zero, L_8003C234
    if (ctx->r5 == 0) {
        // sh          $t0, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r8;
        goto L_8003C234;
    }
    // sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // sh          $t2, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r10;
L_8003C234:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // j           L_8003C244
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    goto L_8003C244;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
L_8003C240:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8003C244:
    // jr          $ra
    // nop

    return;
    // nop

;}
