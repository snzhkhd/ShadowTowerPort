#include "recomp.h"
#include "disable_warnings.h"

void sub_8001618C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // addiu       $a3, $v0, 0x7ECC
    ctx->r7 = ADD32(ctx->r2, 0X7ECC);
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // lb          $a0, 0x4($a3)
    ctx->r4 = MEM_BS(0X4, ctx->r7);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // sb          $a0, 0x14($sp)
    MEM_B(0X14, ctx->r29) = ctx->r4;
    // addiu       $s0, $sp, 0x10
    ctx->r16 = ADD32(ctx->r29, 0X10);
    // jal         0x80078A64
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    strcat_recomp(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // jal         0x80078A64
    // addiu       $a1, $a1, 0x7ED4
    ctx->r5 = ADD32(ctx->r5, 0X7ED4);
    strcat_recomp(rdram, ctx);
    goto after_1;
    // addiu       $a1, $a1, 0x7ED4
    ctx->r5 = ADD32(ctx->r5, 0X7ED4);
    after_1:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800161EC:
    // jal         0x8006AA24
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    CdSearchFile(rdram, ctx);
    goto after_3;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_3:
    // bne         $v0, $zero, L_80016210
    if (ctx->r2 != 0) {
        // addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
        goto L_80016210;
    }
    // addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80068CE0
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    CdControl(rdram, ctx);
    goto after_4;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_4:
    // j           L_800161EC
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    goto L_800161EC;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80016210:
    // bne         $s1, $zero, L_8001621C
    if (ctx->r17 != 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8001621C;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(0X54, ctx->r29);
L_8001621C:
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addiu       $a2, $s1, 0x7FF
    ctx->r6 = ADD32(ctx->r17, 0X7FF);
    // jal         0x80015F0C
    // srl         $a2, $a2, 11
    ctx->r6 = S32(U32(ctx->r6) >> 11);
    sub_80015F0C(rdram, ctx);
    goto after_5;
    // srl         $a2, $a2, 11
    ctx->r6 = S32(U32(ctx->r6) >> 11);
    after_5:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(0X7C, ctx->r29);
    // lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(0X78, ctx->r29);
    // lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(0X74, ctx->r29);
    // lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(0X70, ctx->r29);
    // addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // jr          $ra
    // nop

    return;
    // nop

;}
