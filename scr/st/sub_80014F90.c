#include "recomp.h"
#include "disable_warnings.h"

void sub_80014F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_80015004
    if (ctx->r3 == ctx->r2) {
        // addiu       $s3, $zero, 0x3
        ctx->r19 = ADD32(0, 0X3);
        goto L_80015004;
    }
    // addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
L_80014FC0:
    // bne         $v1, $s3, L_80014FE4
    if (ctx->r3 != ctx->r19) {
        // nop
    
        goto L_80014FE4;
    }
    // nop

    // addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
L_80014FCC:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // beq         $v0, $s1, L_80014FCC
    if (ctx->r2 == ctx->r17) {
        // nop
    
        goto L_80014FCC;
    }
    // nop

L_80014FE4:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // nop

    // bne         $v1, $s2, L_80014FC0
    if (ctx->r3 != ctx->r18) {
        // nop
    
        goto L_80014FC0;
    }
    // nop

L_80015004:
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
