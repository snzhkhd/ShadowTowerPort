#include "recomp.h"
#include "disable_warnings.h"

void SsSetTickMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // jal         0x80077DA8
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    GetVideoMode(rdram, ctx);
    goto after_0;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // andi        $v0, $s0, 0x1000
    ctx->r2 = ctx->r16 & 0X1000;
    // beq         $v0, $zero, L_8006E9C0
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
        goto L_8006E9C0;
    }
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, 0xEA4
    ctx->r2 = ADD32(ctx->r2, 0XEA4);
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // andi        $v1, $s0, 0xFFF
    ctx->r3 = ctx->r16 & 0XFFF;
    // j           L_8006E9D0
    // sw          $v1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r3;
    goto L_8006E9D0;
    // sw          $v1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r3;
L_8006E9C0:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, 0xEA4
    ctx->r2 = ADD32(ctx->r2, 0XEA4);
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // sw          $s0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r16;
L_8006E9D0:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xEA0($v1)
    ctx->r3 = MEM_W(0XEA0, ctx->r3);
    // nop

    // slti        $v0, $v1, 0x6
    ctx->r2 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_8006EAB4
    if (ctx->r2 == 0) {
        // sltiu       $v0, $v1, 0x6
        ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
        goto L_8006EAB4;
    }
    // sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_8006EAA4
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8006EAA4;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // addu        $at, $at, $v0
    gpr jr_addend_8006EA00;
    jr_addend_8006EA00 = ctx->r2;
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lw          $v0, 0x3EE0($at)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8006EA00 >> 2) {
        case 0: goto L_8006EA84; break;
        case 1: goto L_8006EA2C; break;
        case 2: goto L_8006EA5C; break;
        case 3: goto L_8006EA4C; break;
        case 4: goto L_8006EA08; break;
        case 5: goto L_8006EA6C; break;
        default: switch_error(__func__, 0x8006EA00, 0x80013EE0);
    }
    // nop

L_8006EA08:
    // addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v1, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = ctx->r3;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $a0, $v0, L_8006EA40
    if (ctx->r4 == ctx->r2) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_8006EA40;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // j           L_8006EABC
    // sw          $v1, 0xEA0($at)
    MEM_W(0XEA0, ctx->r1) = ctx->r3;
    goto L_8006EABC;
    // sw          $v1, 0xEA0($at)
    MEM_W(0XEA0, ctx->r1) = ctx->r3;
L_8006EA2C:
    // addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // bne         $a0, $zero, L_8006EA40
    if (ctx->r4 != 0) {
        // sw          $v0, -0x79A4($at)
        MEM_W(-0X79A4, ctx->r1) = ctx->r2;
        goto L_8006EA40;
    }
    // sw          $v0, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = ctx->r2;
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8006EA40:
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // j           L_8006EABC
    // sw          $v0, 0xEA0($at)
    MEM_W(0XEA0, ctx->r1) = ctx->r2;
    goto L_8006EABC;
    // sw          $v0, 0xEA0($at)
    MEM_W(0XEA0, ctx->r1) = ctx->r2;
L_8006EA4C:
    // addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // j           L_8006EABC
    // sw          $v0, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = ctx->r2;
    goto L_8006EABC;
    // sw          $v0, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = ctx->r2;
L_8006EA5C:
    // addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // j           L_8006EABC
    // sw          $v0, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = ctx->r2;
    goto L_8006EABC;
    // sw          $v0, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = ctx->r2;
L_8006EA6C:
    // beq         $a0, $zero, L_8006EAA4
    if (ctx->r4 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8006EAA4;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $a0, $v0, L_8006EA94
    if (ctx->r4 == ctx->r2) {
        // addiu       $v0, $zero, 0x3C
        ctx->r2 = ADD32(0, 0X3C);
        goto L_8006EA94;
    }
    // addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // j           L_8006EAA8
    // nop

    goto L_8006EAA8;
    // nop

L_8006EA84:
    // beq         $a0, $zero, L_8006EAA4
    if (ctx->r4 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8006EAA4;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $a0, $v0, L_8006EAA8
    if (ctx->r4 != ctx->r2) {
        // addiu       $v0, $zero, 0x3C
        ctx->r2 = ADD32(0, 0X3C);
        goto L_8006EAA8;
    }
    // addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_8006EA94:
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // j           L_8006EABC
    // sw          $v0, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = ctx->r2;
    goto L_8006EABC;
    // sw          $v0, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = ctx->r2;
L_8006EAA4:
    // addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_8006EAA8:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // j           L_8006EABC
    // sw          $v0, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = ctx->r2;
    goto L_8006EABC;
    // sw          $v0, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = ctx->r2;
L_8006EAB4:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v1, -0x79A4($at)
    MEM_W(-0X79A4, ctx->r1) = ctx->r3;
L_8006EABC:
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
