#include "recomp.h"
#include "disable_warnings.h"

void sub_8001CAB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addiu       $s2, $v0, -0x51F8
    ctx->r18 = ADD32(ctx->r2, -0X51F8);
    // addiu       $v1, $s2, -0x3710
    ctx->r3 = ADD32(ctx->r18, -0X3710);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addiu       $s1, $zero, 0x3F
    ctx->r17 = ADD32(0, 0X3F);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addiu       $s4, $v0, 0x5920
    ctx->r20 = ADD32(ctx->r2, 0X5920);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $s2, 0x2
    ctx->r16 = ADD32(ctx->r18, 0X2);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sb          $zero, 0x6($v1)
    MEM_B(0X6, ctx->r3) = 0;
L_8001CAF8:
    // lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(0X0, ctx->r18);
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_8001CB50
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8001CB50;
    }
    // nop

    // lbu         $v1, 0x2A($s0)
    ctx->r3 = MEM_BU(0X2A, ctx->r16);
    // lbu         $v0, 0x9($s4)
    ctx->r2 = MEM_BU(0X9, ctx->r20);
    // nop

    // bne         $v1, $v0, L_8001CB50
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8001CB50;
    }
    // nop

    // lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(0X0, ctx->r16);
    // jal         0x8001C88C
    // nop

    sub_8001C88C(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // beq         $v0, $zero, L_8001CB50
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0x3F
        ctx->r3 = ADD32(0, 0X3F);
        goto L_8001CB50;
    }
    // addiu       $v1, $zero, 0x3F
    ctx->r3 = ADD32(0, 0X3F);
    // lbu         $v0, 0x6($s3)
    ctx->r2 = MEM_BU(0X6, ctx->r19);
    // subu        $v1, $v1, $s1
    ctx->r3 = SUB32(ctx->r3, ctx->r17);
    // addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
    // lbu         $v0, 0x6($s3)
    ctx->r2 = MEM_BU(0X6, ctx->r19);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x6($s3)
    MEM_B(0X6, ctx->r19) = ctx->r2;
L_8001CB50:
    // addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s1, $v0, L_8001CAF8
    if (ctx->r17 != ctx->r2) {
        // addiu       $s2, $s2, 0x30
        ctx->r18 = ADD32(ctx->r18, 0X30);
        goto L_8001CAF8;
    }
    // addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
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
