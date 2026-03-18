#include "recomp.h"
#include "disable_warnings.h"

void sub_80068A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
L_80068A44:
    // jal         0x80068B70
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    CdReset(rdram, ctx);
    goto after_0;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // bne         $v0, $v1, L_80068A8C
    if (ctx->r2 != ctx->r3) {
        // addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
        goto L_80068A8C;
    }
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // jal         0x80068CB8
    // addiu       $a0, $a0, -0x7548
    ctx->r4 = ADD32(ctx->r4, -0X7548);
    CdSyncCallback(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, -0x7548
    ctx->r4 = ADD32(ctx->r4, -0X7548);
    after_1:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // jal         0x80068CCC
    // addiu       $a0, $a0, -0x7520
    ctx->r4 = ADD32(ctx->r4, -0X7520);
    CdReadyCallback(rdram, ctx);
    goto after_2;
    // addiu       $a0, $a0, -0x7520
    ctx->r4 = ADD32(ctx->r4, -0X7520);
    after_2:
    // lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // jal         0x8006BB0C
    // addiu       $a0, $a0, -0x74F8
    ctx->r4 = ADD32(ctx->r4, -0X74F8);
    sub_8006BB0C(rdram, ctx);
    goto after_3;
    // addiu       $a0, $a0, -0x74F8
    ctx->r4 = ADD32(ctx->r4, -0X74F8);
    after_3:
    // jal         0x8006BB20
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8006BB20(rdram, ctx);
    goto after_4;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
    // j           L_80068AA8
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_80068AA8;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80068A8C:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_80068A44
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_80068A44;
    }
    // nop

    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // jal         0x80078AD4
    // addiu       $a0, $a0, 0x3990
    ctx->r4 = ADD32(ctx->r4, 0X3990);
    printf(rdram, ctx);
    goto after_5;
    // addiu       $a0, $a0, 0x3990
    ctx->r4 = ADD32(ctx->r4, 0X3990);
    after_5:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80068AA8:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
