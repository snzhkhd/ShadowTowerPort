#include "recomp.h"
#include "disable_warnings.h"

void sub_8003216C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $a0, $v0, -0x4930
    ctx->r4 = ADD32(ctx->r2, -0X4930);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(0X2, ctx->r4);
    // nop

    // beq         $v0, $zero, L_800321F4
    if (ctx->r2 == 0) {
        // addiu       $s0, $a0, 0x6C
        ctx->r16 = ADD32(ctx->r4, 0X6C);
        goto L_800321F4;
    }
    // addiu       $s0, $a0, 0x6C
    ctx->r16 = ADD32(ctx->r4, 0X6C);
    // addiu       $s1, $zero, 0x3F
    ctx->r17 = ADD32(0, 0X3F);
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_800321A0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // jal         0x80049AAC
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80049AAC(rdram, ctx);
    goto after_0;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    // jal         0x80049AAC
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sub_80049AAC(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // jal         0x80049AAC
    // addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    sub_80049AAC(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $s0, 0x3C
    ctx->r5 = ADD32(ctx->r16, 0X3C);
    // jal         0x80049AAC
    // addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    sub_80049AAC(rdram, ctx);
    goto after_3;
    // addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s2, L_800321A0
    if (ctx->r17 != ctx->r18) {
        // addiu       $s0, $s0, 0x6C
        ctx->r16 = ADD32(ctx->r16, 0X6C);
        goto L_800321A0;
    }
    // addiu       $s0, $s0, 0x6C
    ctx->r16 = ADD32(ctx->r16, 0X6C);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // sb          $zero, -0x492E($v0)
    MEM_B(-0X492E, ctx->r2) = 0;
L_800321F4:
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
