#include "recomp.h"
#include "disable_warnings.h"

void SpuFree(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xE20($v1)
    ctx->r3 = MEM_W(0XE20, ctx->r3);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // blez        $v1, L_80073648
    if (SIGNED(ctx->r3) <= 0) {
        // sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
        goto L_80073648;
    }
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $t1, 0x4000
    ctx->r9 = S32(0X4000 << 16);
    // lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // or          $t0, $a0, $v0
    ctx->r8 = ctx->r4 | ctx->r2;
    // addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0xE28($a1)
    ctx->r5 = MEM_W(0XE28, ctx->r5);
    // nop

L_80073618:
    // lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(0X0, ctx->r5);
    // nop

    // and         $v0, $v1, $t1
    ctx->r2 = ctx->r3 & ctx->r9;
    // bne         $v0, $zero, L_80073648
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80073648;
    }
    // nop

    // bne         $v1, $a0, L_8007363C
    if (ctx->r3 != ctx->r4) {
        // addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8007363C;
    }
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // j           L_80073648
    // sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    goto L_80073648;
    // sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
L_8007363C:
    // slt         $v0, $a2, $a3
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_80073618
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
        goto L_80073618;
    }
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_80073648:
    // jal         0x80073664
    // nop

    _spu_gcSPU(rdram, ctx);
    goto after_0;
    // nop

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
