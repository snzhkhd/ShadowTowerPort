#include "recomp.h"
#include "disable_warnings.h"

void sub_8007CEC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E68($v1)
    ctx->r3 = MEM_W(0X7E68, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // beq         $v1, $zero, L_8007CF00
    if (ctx->r3 == 0) {
        // sw          $v0, 0x7E80($at)
        MEM_W(0X7E80, ctx->r1) = ctx->r2;
        goto L_8007CF00;
    }
    // sw          $v0, 0x7E80($at)
    MEM_W(0X7E80, ctx->r1) = ctx->r2;
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addiu       $a0, $a0, -0x4D38
    ctx->r4 = ADD32(ctx->r4, -0X4D38);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // slti        $v0, $v1, 0x96
    ctx->r2 = SIGNED(ctx->r3) < 0X96 ? 1 : 0;
    // beq         $v0, $zero, L_8007CF00
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_8007CF00;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8007CF00:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E6C($v0)
    ctx->r2 = MEM_W(0X7E6C, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8007CF34
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007CF34;
    }
    // nop

    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addiu       $a0, $a0, -0x4D34
    ctx->r4 = ADD32(ctx->r4, -0X4D34);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // nop

    // slti        $v0, $v1, 0x96
    ctx->r2 = SIGNED(ctx->r3) < 0X96 ? 1 : 0;
    // beq         $v0, $zero, L_8007CF34
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x1
        ctx->r2 = ADD32(ctx->r3, 0X1);
        goto L_8007CF34;
    }
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_8007CF34:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E50($v0)
    ctx->r2 = MEM_W(0X7E50, ctx->r2);
    // nop

    // beq         $v0, $zero, L_8007D01C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007D01C;
    }
    // nop

    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E68($v1)
    ctx->r3 = MEM_W(0X7E68, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E6C($v0)
    ctx->r2 = MEM_W(0X7E6C, ctx->r2);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8007D01C
    if (ctx->r2 != 0) {
        // sll         $a0, $v1, 4
        ctx->r4 = S32(ctx->r3) << 4;
        goto L_8007D01C;
    }
    // sll         $a0, $v1, 4
    ctx->r4 = S32(ctx->r3) << 4;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E4C($v0)
    ctx->r2 = MEM_W(0X7E4C, ctx->r2);
    // sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4) << 4;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x7E5C($at)
    MEM_W(0X7E5C, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v1, 0x7E58($at)
    MEM_W(0X7E58, ctx->r1) = ctx->r3;
    // jal         0x8007D150
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8007D150(rdram, ctx);
    goto after_0;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // bne         $v0, $zero, L_8007CFAC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007CFAC;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E18($v0)
    ctx->r2 = MEM_W(0X7E18, ctx->r2);
    // nop

    // jalr        $v0
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    after_1:
L_8007CFAC:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E58($v1)
    ctx->r3 = MEM_W(0X7E58, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E6C($v0)
    ctx->r2 = MEM_W(0X7E6C, ctx->r2);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x7E60($at)
    MEM_W(0X7E60, ctx->r1) = 0;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8007D00C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007D00C;
    }
    // nop

L_8007CFD0:
    // sll         $a0, $v1, 4
    ctx->r4 = S32(ctx->r3) << 4;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E4C($v0)
    ctx->r2 = MEM_W(0X7E4C, ctx->r2);
    // sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4) << 4;
    // jal         0x8007D364
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    sub_8007D364(rdram, ctx);
    goto after_2;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_2:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E58($v1)
    ctx->r3 = MEM_W(0X7E58, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E6C($v0)
    ctx->r2 = MEM_W(0X7E6C, ctx->r2);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8007CFD0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007CFD0;
    }
    // nop

L_8007D00C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E7C($v1)
    ctx->r3 = MEM_W(0X7E7C, ctx->r3);
    // addiu       $v0, $zero, 0x88
    ctx->r2 = ADD32(0, 0X88);
    // sh          $v0, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r2;
L_8007D01C:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
