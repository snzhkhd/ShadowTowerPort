#include "recomp.h"
#include "disable_warnings.h"

void sub_80035604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // lui         $v1, 0x1F80
    ctx->r3 = S32(0X1F80 << 16);
    // lw          $v1, 0xA4($v1)
    ctx->r3 = MEM_W(0XA4, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $s1, 0x4($v1)
    ctx->r17 = MEM_W(0X4, ctx->r3);
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // beq         $s1, $v0, L_8003567C
    if (ctx->r17 == ctx->r2) {
        // addu        $s2, $v0, $zero
        ctx->r18 = ADD32(ctx->r2, 0);
        goto L_8003567C;
    }
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // addiu       $s0, $v1, 0x4
    ctx->r16 = ADD32(ctx->r3, 0X4);
L_80035644:
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // nop

    // beq         $v0, $s2, L_80035670
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_80035670;
    }
    // nop

    // lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(0X4, ctx->r16);
    // nop

    // beq         $v0, $s3, L_80035670
    if (ctx->r2 == ctx->r19) {
        // nop
    
        goto L_80035670;
    }
    // nop

    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // jal         0x80035260
    // nop

    sub_80035260(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_80035670:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s2, L_80035644
    if (ctx->r17 != ctx->r18) {
        // addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
        goto L_80035644;
    }
    // addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_8003567C:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
