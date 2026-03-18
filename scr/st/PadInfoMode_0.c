#include "recomp.h"
#include "disable_warnings.h"

void PadInfoMode_0(uint8_t* rdram, recomp_context* ctx) {
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
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $s0, $v0, L_8007CA58
    if (ctx->r16 == ctx->r2) {
        // slti        $v0, $s0, 0x4
        ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
        goto L_8007CA58;
    }
    // slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_8007CA24
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007CA24;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $s0, $v0, L_8007CA40
    if (ctx->r16 == ctx->r2) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8007CA40;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $s0, $v0, L_8007CA4C
    if (ctx->r16 == ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007CA4C;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_8007CAB4
    // nop

    goto L_8007CAB4;
    // nop

L_8007CA24:
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $s0, $v0, L_8007CA64
    if (ctx->r16 == ctx->r2) {
        // addiu       $v0, $zero, 0x64
        ctx->r2 = ADD32(0, 0X64);
        goto L_8007CA64;
    }
    // addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // beq         $s0, $v0, L_8007CAA4
    if (ctx->r16 == ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007CAA4;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_8007CAB4
    // nop

    goto L_8007CAB4;
    // nop

L_8007CA40:
    // lbu         $v0, 0xE8($v1)
    ctx->r2 = MEM_BU(0XE8, ctx->r3);
    // j           L_8007CAB4
    // nop

    goto L_8007CAB4;
    // nop

L_8007CA4C:
    // lhu         $v0, 0xE6($v1)
    ctx->r2 = MEM_HU(0XE6, ctx->r3);
    // j           L_8007CAB4
    // nop

    goto L_8007CAB4;
    // nop

L_8007CA58:
    // lbu         $v0, 0xE4($v1)
    ctx->r2 = MEM_BU(0XE4, ctx->r3);
    // j           L_8007CAB4
    // nop

    goto L_8007CAB4;
    // nop

L_8007CA64:
    // bgez        $s1, L_8007CA78
    if (SIGNED(ctx->r17) >= 0) {
        // nop
    
        goto L_8007CA78;
    }
    // nop

    // lbu         $v0, 0xE3($v1)
    ctx->r2 = MEM_BU(0XE3, ctx->r3);
    // j           L_8007CAB4
    // nop

    goto L_8007CAB4;
    // nop

L_8007CA78:
    // lbu         $v0, 0xE3($v1)
    ctx->r2 = MEM_BU(0XE3, ctx->r3);
    // nop

    // slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8007CAB0
    if (ctx->r2 == 0) {
        // sll         $v0, $s1, 1
        ctx->r2 = S32(ctx->r17) << 1;
        goto L_8007CAB0;
    }
    // sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17) << 1;
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // j           L_8007CAB4
    // nop

    goto L_8007CAB4;
    // nop

L_8007CAA4:
    // lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(0X4C, ctx->r3);
    // j           L_8007CAB4
    // nop

    goto L_8007CAB4;
    // nop

L_8007CAB0:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007CAB4:
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
