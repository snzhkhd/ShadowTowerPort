#include "recomp.h"
#include "disable_warnings.h"

void sub_80016030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4) << 1;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $v0, $v0, -0x7424
    ctx->r2 = ADD32(ctx->r2, -0X7424);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(0X0, ctx->r2);
    // lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(0X2, ctx->r2);
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // jal         0x80015A94
    // subu        $s0, $v0, $a1
    ctx->r16 = SUB32(ctx->r2, ctx->r5);
    sub_80015A94(rdram, ctx);
    goto after_0;
    // subu        $s0, $v0, $a1
    ctx->r16 = SUB32(ctx->r2, ctx->r5);
    after_0:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_8001608C:
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x80015F0C
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    KF_CDReadSectorsInternal(rdram, ctx);
    goto after_1;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // jal         0x80015B78
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    VerifyChecksum(rdram, ctx);
    goto after_2;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_2:
    // bne         $v0, $zero, L_8001608C
    if (ctx->r2 != 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_8001608C;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
