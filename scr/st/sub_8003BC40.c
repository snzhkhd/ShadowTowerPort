#include "recomp.h"
#include "disable_warnings.h"

void sub_8003BC40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addiu       $s1, $v0, -0x1CE8
    ctx->r17 = ADD32(ctx->r2, -0X1CE8);
    // addiu       $v0, $s1, -0x1080
    ctx->r2 = ADD32(ctx->r17, -0X1080);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $s1, 0x10
    ctx->r16 = ADD32(ctx->r17, 0X10);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $zero, 0x3C88($v0)
    MEM_W(0X3C88, ctx->r2) = 0;
L_8003BC74:
    // lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(0X0, ctx->r17);
    // nop

    // beq         $v0, $s3, L_8003BCD4
    if (ctx->r2 == ctx->r19) {
        // nop
    
        goto L_8003BCD4;
    }
    // nop

    // sw          $s1, 0x3C84($s2)
    MEM_W(0X3C84, ctx->r18) = ctx->r17;
    // lbu         $v1, -0xF($s0)
    ctx->r3 = MEM_BU(-0XF, ctx->r16);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sw          $v0, 0x3C80($s2)
    MEM_W(0X3C80, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_8003BCCC
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8003BCCC;
    }
    // nop

    // j           L_8003BCD4
    // sb          $s3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r19;
    goto L_8003BCD4;
    // sb          $s3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r19;
L_8003BCCC:
    // jal         0x800385B0
    // nop

    sub_800385B0(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_8003BCD4:
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // lw          $v0, 0x3C88($s2)
    ctx->r2 = MEM_W(0X3C88, ctx->r18);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x3C88($s2)
    MEM_W(0X3C88, ctx->r18) = ctx->r2;
    // slti        $v0, $v0, 0x80
    ctx->r2 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_8003BC74
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x58
        ctx->r17 = ADD32(ctx->r17, 0X58);
        goto L_8003BC74;
    }
    // addiu       $s1, $s1, 0x58
    ctx->r17 = ADD32(ctx->r17, 0X58);
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
