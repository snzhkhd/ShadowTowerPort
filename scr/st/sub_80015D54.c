#include "recomp.h"
#include "disable_warnings.h"

void sub_80015D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addu        $s0, $a3, $zero
    ctx->r16 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // jal         0x80015CD0
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    sub_80015CD0(rdram, ctx);
    goto after_0;
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_0:
    // beq         $v0, $zero, L_80015D90
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
        goto L_80015D90;
    }
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // jal         0x80015BCC
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    sub_80015BCC(rdram, ctx);
    goto after_1;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_1:
L_80015D90:
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
