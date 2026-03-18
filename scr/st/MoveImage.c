#include "recomp.h"
#include "disable_warnings.h"

void MoveImage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // lui         $a0, 0x8001
    ctx->r4 = S32(0X8001 << 16);
    // addiu       $a0, $a0, 0x4220
    ctx->r4 = ADD32(ctx->r4, 0X4220);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // jal         0x80079AC8
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    sub_80079AC8(rdram, ctx);
    goto after_0;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // lh          $v0, 0x4($s0)
    ctx->r2 = MEM_HS(0X4, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80079E6C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_80079E6C;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lh          $v0, 0x6($s0)
    ctx->r2 = MEM_HS(0X6, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80079E24
    if (ctx->r2 != 0) {
        // sll         $v0, $s1, 16
        ctx->r2 = S32(ctx->r17) << 16;
        goto L_80079E24;
    }
    // sll         $v0, $s1, 16
    ctx->r2 = S32(ctx->r17) << 16;
    // j           L_80079E6C
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_80079E6C;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80079E24:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, 0x7D60
    ctx->r3 = ADD32(ctx->r3, 0X7D60);
    // andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(0X0, ctx->r16);
    // lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // lw          $a3, 0x7CB8($a3)
    ctx->r7 = MEM_W(0X7CB8, ctx->r7);
    // addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // addiu       $a1, $v1, -0x8
    ctx->r5 = ADD32(ctx->r3, -0X8);
    // sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // lw          $a0, 0x18($a3)
    ctx->r4 = MEM_W(0X18, ctx->r7);
    // lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(0X8, ctx->r7);
    // nop

    // jalr        $v0
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
L_80079E6C:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
