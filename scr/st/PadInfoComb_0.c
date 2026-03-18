#include "recomp.h"
#include "disable_warnings.h"

void PadInfoComb_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // jalr        $v0
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    after_0:
    // bgez        $s0, L_8007CBD4
    if (SIGNED(ctx->r16) >= 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8007CBD4;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // lbu         $v0, 0xEA($v1)
    ctx->r2 = MEM_BU(0XEA, ctx->r3);
    // j           L_8007CC30
    // nop

    goto L_8007CC30;
    // nop

L_8007CBD4:
    // lbu         $v0, 0xEA($v1)
    ctx->r2 = MEM_BU(0XEA, ctx->r3);
    // nop

    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8007CC2C
    if (ctx->r2 == 0) {
        // sll         $v0, $s0, 3
        ctx->r2 = S32(ctx->r16) << 3;
        goto L_8007CC2C;
    }
    // sll         $v0, $s0, 3
    ctx->r2 = S32(ctx->r16) << 3;
    // lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(0X8, ctx->r3);
    // bgez        $s1, L_8007CC00
    if (SIGNED(ctx->r17) >= 0) {
        // addu        $v1, $v1, $v0
        ctx->r3 = ADD32(ctx->r3, ctx->r2);
        goto L_8007CC00;
    }
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // j           L_8007CC30
    // nop

    goto L_8007CC30;
    // nop

L_8007CC00:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // nop

    // slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8007CC30
    if (ctx->r2 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007CC30;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // nop

    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // j           L_8007CC30
    // nop

    goto L_8007CC30;
    // nop

L_8007CC2C:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007CC30:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
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
