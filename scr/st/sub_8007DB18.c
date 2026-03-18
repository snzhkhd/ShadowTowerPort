#include "recomp.h"
#include "disable_warnings.h"

void sub_8007DB18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // beq         $s1, $zero, L_8007DB60
    if (ctx->r17 == 0) {
        // sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
        goto L_8007DB60;
    }
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8007DBD8
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8007DBD8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E34($v0)
    ctx->r2 = MEM_W(0X7E34, ctx->r2);
    // nop

    // jalr        $v0
    // nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // beq         $v0, $zero, L_8007DB68
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007DB68;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007DB60:
    // j           L_8007DBD8
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8007DBD8;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007DB68:
    // addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // addiu       $a1, $s1, 0x3
    ctx->r5 = ADD32(ctx->r17, 0X3);
    // sra         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) >> 2;
    // sb          $v1, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r3;
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $v1, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r3;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // addiu       $v1, $v1, -0x2414
    ctx->r3 = ADD32(ctx->r3, -0X2414);
    // sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // lbu         $v1, 0xE3($s0)
    ctx->r3 = MEM_BU(0XE3, ctx->r16);
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // addiu       $a0, $a0, -0x236C
    ctx->r4 = ADD32(ctx->r4, -0X236C);
    // sw          $a0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r4;
    // lbu         $a0, 0xE9($s0)
    ctx->r4 = MEM_BU(0XE9, ctx->r16);
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
    // sb          $zero, 0x47($s0)
    MEM_B(0X47, ctx->r16) = 0;
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) << 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
    // andi        $v1, $v1, 0xFFC
    ctx->r3 = ctx->r3 & 0XFFC;
    // sw          $a1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r5;
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // sw          $a1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r5;
L_8007DBD8:
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
