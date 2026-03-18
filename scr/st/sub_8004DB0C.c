#include "recomp.h"
#include "disable_warnings.h"

void sub_8004DB0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a1, $v0, -0x70D8
    ctx->r5 = ADD32(ctx->r2, -0X70D8);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(0X2, ctx->r4);
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3) << 6;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x29C8
    ctx->r2 = ADD32(ctx->r2, -0X29C8);
    // addu        $t0, $v1, $v0
    ctx->r8 = ADD32(ctx->r3, ctx->r2);
L_8004DB40:
    // addu        $a0, $t0, $a2
    ctx->r4 = ADD32(ctx->r8, ctx->r6);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // lbu         $v1, 0x24($a0)
    ctx->r3 = MEM_BU(0X24, ctx->r4);
    // lhu         $v0, 0x9A($a1)
    ctx->r2 = MEM_HU(0X9A, ctx->r5);
    // sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3) << 24;
    // sra         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3) >> 24;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x9A($a1)
    MEM_H(0X9A, ctx->r5) = ctx->r2;
    // lbu         $v1, 0x24($a0)
    ctx->r3 = MEM_BU(0X24, ctx->r4);
    // lhu         $v0, 0x8($a3)
    ctx->r2 = MEM_HU(0X8, ctx->r7);
    // sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3) << 24;
    // sra         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3) >> 24;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r2;
    // slti        $v0, $a2, 0xE
    ctx->r2 = SIGNED(ctx->r6) < 0XE ? 1 : 0;
    // bne         $v0, $zero, L_8004DB40
    if (ctx->r2 != 0) {
        // addiu       $a1, $a1, 0x2
        ctx->r5 = ADD32(ctx->r5, 0X2);
        goto L_8004DB40;
    }
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // jal         0x8005A3A8
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8005A3A8(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
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
