#include "recomp.h"
#include "disable_warnings.h"

void sub_80060F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // lui         $s4, 0x1F80
    ctx->r20 = S32(0X1F80 << 16);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80060FAC:
    // lw          $a0, 0x14($s4)
    ctx->r4 = MEM_W(0X14, ctx->r20);
    // jal         0x80077E34
    // nop

    TestEvent(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lw          $a0, 0x18($s4)
    ctx->r4 = MEM_W(0X18, ctx->r20);
    // jal         0x80077E34
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    TestEvent(rdram, ctx);
    goto after_1;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // lw          $a0, 0x1C($s4)
    ctx->r4 = MEM_W(0X1C, ctx->r20);
    // jal         0x80077E34
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    TestEvent(rdram, ctx);
    goto after_2;
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    after_2:
    // lw          $a0, 0x20($s4)
    ctx->r4 = MEM_W(0X20, ctx->r20);
    // jal         0x80077E34
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    TestEvent(rdram, ctx);
    goto after_3;
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_3:
    // bne         $s0, $s3, L_80060FEC
    if (ctx->r16 != ctx->r19) {
        // nop
    
        goto L_80060FEC;
    }
    // nop

    // j           L_80061018
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80061018;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80060FEC:
    // bne         $s2, $s3, L_80060FFC
    if (ctx->r18 != ctx->r19) {
        // nop
    
        goto L_80060FFC;
    }
    // nop

    // j           L_80061018
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_80061018;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060FFC:
    // beq         $s1, $s3, L_80061014
    if (ctx->r17 == ctx->r19) {
        // nop
    
        goto L_80061014;
    }
    // nop

    // bne         $v0, $s3, L_80060FAC
    if (ctx->r2 != ctx->r19) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_80060FAC;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // j           L_80061018
    // nop

    goto L_80061018;
    // nop

L_80061014:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80061018:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
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
