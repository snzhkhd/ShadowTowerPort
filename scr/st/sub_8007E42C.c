#include "recomp.h"
#include "disable_warnings.h"

void sub_8007E42C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // bne         $v0, $v1, L_8007E464
    if (ctx->r2 != ctx->r3) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_8007E464;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lbu         $v0, 0x36($s0)
    ctx->r2 = MEM_BU(0X36, ctx->r16);
    // nop

    // sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
L_8007E464:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E20($v0)
    ctx->r2 = MEM_W(0X7E20, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x8007D604
    // andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    sub_8007D604(rdram, ctx);
    goto after_1;
    // andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_1:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // beq         $v1, $v0, L_8007E4A8
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_8007E4A8;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // beq         $v1, $zero, L_8007E4A8
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8007E4A8;
    }
    // nop

    // bgez        $v1, L_8007E4A8
    if (SIGNED(ctx->r3) >= 0) {
        // addiu       $v0, $zero, -0x9
        ctx->r2 = ADD32(0, -0X9);
        goto L_8007E4A8;
    }
    // addiu       $v0, $zero, -0x9
    ctx->r2 = ADD32(0, -0X9);
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8007E4A8:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
