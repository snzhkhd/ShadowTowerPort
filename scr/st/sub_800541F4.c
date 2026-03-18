#include "recomp.h"
#include "disable_warnings.h"

void sub_800541F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x6EFC
    ctx->r16 = ADD32(ctx->r16, -0X6EFC);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // jal         0x80015950
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80015950(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // addiu       $a0, $s0, -0x4
    ctx->r4 = ADD32(ctx->r16, -0X4);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // jal         0x80015950
    // addiu       $s0, $s0, -0x1DC
    ctx->r16 = ADD32(ctx->r16, -0X1DC);
    sub_80015950(rdram, ctx);
    goto after_1;
    // addiu       $s0, $s0, -0x1DC
    ctx->r16 = ADD32(ctx->r16, -0X1DC);
    after_1:
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x1E8($s0)
    ctx->r2 = MEM_W(0X1E8, ctx->r16);
    // lw          $v1, -0x7DFC($v1)
    ctx->r3 = MEM_W(-0X7DFC, ctx->r3);
    // addiu       $v0, $v0, 0xE10
    ctx->r2 = ADD32(ctx->r2, 0XE10);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80054260
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80054260;
    }
    // nop

    // lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(0X14, ctx->r29);
    // lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(0X10, ctx->r29);
    // lw          $v1, 0x1E0($s0)
    ctx->r3 = MEM_W(0X1E0, ctx->r16);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // j           L_80054264
    // xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    goto L_80054264;
    // xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_80054260:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80054264:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
