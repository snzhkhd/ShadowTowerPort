#include "recomp.h"
#include "disable_warnings.h"

void sub_80057F3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x8006D044
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    SsSetMVol(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // addiu       $s1, $zero, 0x141
    ctx->r17 = ADD32(0, 0X141);
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, -0x2E18
    ctx->r2 = ADD32(ctx->r2, -0X2E18);
    // addiu       $s0, $v0, 0x4
    ctx->r16 = ADD32(ctx->r2, 0X4);
L_80057F70:
    // lh          $a0, 0x0($s0)
    ctx->r4 = MEM_HS(0X0, ctx->r16);
    // nop

    // beq         $a0, $s2, L_80057F8C
    if (ctx->r4 == ctx->r18) {
        // nop
    
        goto L_80057F8C;
    }
    // nop

    // jal         0x80073564
    // nop

    sub_80073564(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // sh          $s2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r18;
L_80057F8C:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s2, L_80057F70
    if (ctx->r17 != ctx->r18) {
        // addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_80057F70;
    }
    // addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // jal         0x8006C974
    // nop

    SsEnd(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x8006CB64
    // nop

    SsQuit(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
