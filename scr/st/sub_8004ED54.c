#include "recomp.h"
#include "disable_warnings.h"

void sub_8004ED54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // lui         $v1, 0x801E
    ctx->r3 = S32(0X801E << 16);
    // addiu       $v1, $v1, -0x2E40
    ctx->r3 = ADD32(ctx->r3, -0X2E40);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lh          $v1, 0xA84($v0)
    ctx->r3 = MEM_HS(0XA84, ctx->r2);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_8004ED98
    if (ctx->r3 == ctx->r2) {
        // addiu       $a1, $a2, 0x24
        ctx->r5 = ADD32(ctx->r6, 0X24);
        goto L_8004ED98;
    }
    // addiu       $a1, $a2, 0x24
    ctx->r5 = ADD32(ctx->r6, 0X24);
    // addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // jal         0x80058220
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    sub_80058220(rdram, ctx);
    goto after_0;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_0:
L_8004ED98:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
