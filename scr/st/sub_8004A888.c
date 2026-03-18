#include "recomp.h"
#include "disable_warnings.h"

void sub_8004A888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) << 16;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    // addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_8004A89C:
    // lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(0X0, ctx->r5);
    // lhu         $a0, 0x0($t1)
    ctx->r4 = MEM_HU(0X0, ctx->r9);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // mult        $v1, $a3
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // mflo        $t3
    ctx->r11 = lo;
    // sra         $v0, $t3, 12
    ctx->r2 = S32(ctx->r11) >> 12;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sh          $a0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r4;
    // bne         $t0, $t2, L_8004A89C
    if (ctx->r8 != ctx->r10) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_8004A89C;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // jr          $ra
    // nop

    return;
    // nop

;}
