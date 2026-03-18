#include "recomp.h"
#include "disable_warnings.h"

void sub_8002C9E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sh          $v0, 0x354($s0)
    MEM_H(0X354, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // sh          $v0, 0x356($s0)
    MEM_H(0X356, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x300
    ctx->r2 = ADD32(0, 0X300);
    // sh          $v0, 0x358($s0)
    MEM_H(0X358, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $zero, 0x352($s0)
    MEM_H(0X352, ctx->r16) = 0;
    // sh          $zero, 0x350($s0)
    MEM_H(0X350, ctx->r16) = 0;
    // sh          $v0, 0x35A($s0)
    MEM_H(0X35A, ctx->r16) = ctx->r2;
L_8002CA38:
    // addiu       $a0, $s0, 0x350
    ctx->r4 = ADD32(ctx->r16, 0X350);
    // addiu       $a1, $s0, 0x358
    ctx->r5 = ADD32(ctx->r16, 0X358);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // jal         0x80028364
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    sub_80028364(rdram, ctx);
    goto after_0;
    // sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_0:
    // lhu         $v0, 0x350($s0)
    ctx->r2 = MEM_HU(0X350, ctx->r16);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // bne         $s1, $s2, L_8002CA38
    if (ctx->r17 != ctx->r18) {
        // sh          $v0, 0x350($s0)
        MEM_H(0X350, ctx->r16) = ctx->r2;
        goto L_8002CA38;
    }
    // sh          $v0, 0x350($s0)
    MEM_H(0X350, ctx->r16) = ctx->r2;
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
