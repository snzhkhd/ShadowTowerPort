#include "recomp.h"
#include "disable_warnings.h"

void sub_8007CAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E2C($v0)
    ctx->r2 = MEM_W(0X7E2C, ctx->r2);
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
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
    // bgez        $s0, L_8007CB00
    if (SIGNED(ctx->r16) >= 0) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_8007CB00;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // lbu         $v0, 0xE9($v1)
    ctx->r2 = MEM_BU(0XE9, ctx->r3);
    // j           L_8007CB88
    // nop

    goto L_8007CB88;
    // nop

L_8007CB00:
    // lbu         $v0, 0xE9($v1)
    ctx->r2 = MEM_BU(0XE9, ctx->r3);
    // nop

    // slt         $v0, $s0, $v0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8007CB84
    if (ctx->r2 == 0) {
        // sll         $v0, $s0, 2
        ctx->r2 = S32(ctx->r16) << 2;
        goto L_8007CB84;
    }
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
    // lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(0X4, ctx->r3);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // addiu       $a2, $s1, -0x1
    ctx->r6 = ADD32(ctx->r17, -0X1);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sltiu       $v0, $a2, 0x5
    ctx->r2 = ctx->r6 < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_8007CB84
    if (ctx->r2 == 0) {
        // sll         $v0, $a2, 2
        ctx->r2 = S32(ctx->r6) << 2;
        goto L_8007CB84;
    }
    // sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addu        $at, $at, $v0
    gpr jr_addend_8007CB40;
    jr_addend_8007CB40 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x4300($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8007CB40 >> 2) {
        case 0: goto L_8007CB48; break;
        case 1: goto L_8007CB54; break;
        case 2: goto L_8007CB60; break;
        case 3: goto L_8007CB6C; break;
        case 4: goto L_8007CB78; break;
        default: switch_error(__func__, 0x8007CB40, 0x80014300);
    }
    // nop

L_8007CB48:
    // lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(0X0, ctx->r3);
    // j           L_8007CB88
    // nop

    goto L_8007CB88;
    // nop

L_8007CB54:
    // lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(0X1, ctx->r3);
    // j           L_8007CB88
    // nop

    goto L_8007CB88;
    // nop

L_8007CB60:
    // lbu         $v0, 0x2($v1)
    ctx->r2 = MEM_BU(0X2, ctx->r3);
    // j           L_8007CB88
    // nop

    goto L_8007CB88;
    // nop

L_8007CB6C:
    // lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(0X3, ctx->r3);
    // j           L_8007CB88
    // nop

    goto L_8007CB88;
    // nop

L_8007CB78:
    // lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(0X4, ctx->r3);
    // j           L_8007CB88
    // nop

    goto L_8007CB88;
    // nop

L_8007CB84:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007CB88:
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
