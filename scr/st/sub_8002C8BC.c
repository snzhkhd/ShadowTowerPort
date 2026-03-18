#include "recomp.h"
#include "disable_warnings.h"

void sub_8002C8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
    // lbu         $v0, 0x2DC($v0)
    ctx->r2 = MEM_BU(0X2DC, ctx->r2);
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // beq         $v0, $zero, L_8002C8F8
    if (ctx->r2 == 0) {
        // sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
        goto L_8002C8F8;
    }
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // addiu       $a2, $zero, 0x4A
    ctx->r6 = ADD32(0, 0X4A);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x294($a0)
    ctx->r2 = MEM_HU(0X294, ctx->r4);
    // j           L_8002C914
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    goto L_8002C914;
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
L_8002C8F8:
    // addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // addiu       $a2, $zero, 0x4A
    ctx->r6 = ADD32(0, 0X4A);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // ori         $a3, $a3, 0x300
    ctx->r7 = ctx->r7 | 0X300;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x296($a0)
    ctx->r2 = MEM_HU(0X296, ctx->r4);
L_8002C914:
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_0;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // ori         $a3, $s0, 0x300
    ctx->r7 = ctx->r16 | 0X300;
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0x298($a0)
    ctx->r2 = MEM_HU(0X298, ctx->r4);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_1;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_1:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
