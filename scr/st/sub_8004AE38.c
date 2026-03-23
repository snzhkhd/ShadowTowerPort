#include "recomp.h"
#include "disable_warnings.h"

void sub_8004AE38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $a0, $v1, -0x29C8
    ctx->r4 = ADD32(ctx->r3, -0X29C8);
    // addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x5($a1)
    ctx->r3 = MEM_BU(0X5, ctx->r5);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bne         $v1, $v0, L_8004AE90
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $a0, -0xD40
        ctx->r2 = ADD32(ctx->r4, -0XD40);
        goto L_8004AE90;
    }
    // addiu       $v0, $a0, -0xD40
    ctx->r2 = ADD32(ctx->r4, -0XD40);
    // addiu       $v1, $a0, -0x3500
    ctx->r3 = ADD32(ctx->r4, -0X3500);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sh          $v0, 0x615E($v1)
    MEM_H(0X615E, ctx->r3) = ctx->r2;
    // sh          $v0, 0x615C($v1)
    MEM_H(0X615C, ctx->r3) = ctx->r2;
    // sh          $v0, 0x615A($v1)
    MEM_H(0X615A, ctx->r3) = ctx->r2;
    // j           L_8004AED4
    // sh          $v0, 0x6158($v1)
    MEM_H(0X6158, ctx->r3) = ctx->r2;
    goto L_8004AED4;
    // sh          $v0, 0x6158($v1)
    MEM_H(0X6158, ctx->r3) = ctx->r2;
L_8004AE90:
    // sltu        $v0, $a1, $v0
    ctx->r2 = ctx->r5 < ctx->r2 ? 1 : 0;
    // beq         $v0, $zero, L_8004AED4
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_8004AED4;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // lbu         $v1, 0x5929($v1)
    ctx->r3 = MEM_BU(0X5929, ctx->r3);
    // addiu       $v0, $v0, -0x45F8
    ctx->r2 = ADD32(ctx->r2, -0X45F8);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x16E4($v1)
    ctx->r2 = MEM_BU(0X16E4, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x16E4($v1)
    MEM_B(0X16E4, ctx->r3) = ctx->r2;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lhu         $v0, 0x30($v1)
    ctx->r2 = MEM_HU(0X30, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r2;
L_8004AED4:
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x5EC8
    ctx->r3 = ADD32(ctx->r3, -0X5EC8);
    // sb          $v0, 0x5($a1)
    MEM_B(0X5, ctx->r5) = ctx->r2;
    // lhu         $a0, 0x12($a2)
    ctx->r4 = MEM_HU(0X12, ctx->r6);
    // lw          $v0, 0x612C($v1)
    ctx->r2 = MEM_W(0X612C, ctx->r3);
    // nop

    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sw          $v0, 0x612C($v1)
    MEM_W(0X612C, ctx->r3) = ctx->r2;
    // lbu         $a0, 0xD($a1)
    ctx->r4 = MEM_BU(0XD, ctx->r5);
    // lw          $v0, 0x6128($v1)
    ctx->r2 = MEM_W(0X6128, ctx->r3);
    // nop

    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // jal         0x8004AC38
    // sw          $v0, 0x6128($v1)
    MEM_W(0X6128, ctx->r3) = ctx->r2;
    sub_8004AC38(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x6128($v1)
    MEM_W(0X6128, ctx->r3) = ctx->r2;
    after_0:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
