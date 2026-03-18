#include "recomp.h"
#include "disable_warnings.h"

void sub_8004656C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v1, $v0, 0x5948
    ctx->r3 = ADD32(ctx->r2, 0X5948);
    // lhu         $a2, 0x44CA($v1)
    ctx->r6 = MEM_HU(0X44CA, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // beq         $a2, $v0, L_800465FC
    if (ctx->r6 == ctx->r2) {
        // lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
        goto L_800465FC;
    }
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $t1, $v0, -0x4130
    ctx->r9 = ADD32(ctx->r2, -0X4130);
    // addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // sll         $v0, $a2, 4
    ctx->r2 = S32(ctx->r6) << 4;
    // addu        $a1, $v0, $a0
    ctx->r5 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6) << 1;
    // addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
L_800465A0:
    // lhu         $v0, 0x44CE($a3)
    ctx->r2 = MEM_HU(0X44CE, ctx->r7);
    // nop

    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(0X8, ctx->r4);
    // addiu       $a3, $a3, -0x2
    ctx->r7 = ADD32(ctx->r7, -0X2);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // lbu         $v1, 0x9($a0)
    ctx->r3 = MEM_BU(0X9, ctx->r4);
    // lbu         $v0, 0xB($a0)
    ctx->r2 = MEM_BU(0XB, ctx->r4);
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // lbu         $v0, 0xA($a0)
    ctx->r2 = MEM_BU(0XA, ctx->r4);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // bne         $a2, $t0, L_800465A0
    if (ctx->r6 != ctx->r8) {
        // addiu       $a1, $a1, -0x10
        ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800465A0;
    }
    // addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800465FC:
    // jr          $ra
    // nop

    return;
    // nop

;}
