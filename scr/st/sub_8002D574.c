#include "recomp.h"
#include "disable_warnings.h"

void sub_8002D574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // lui         $a3, 0x1F80
    ctx->r7 = S32(0X1F80 << 16);
    // sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // lhu         $v0, 0x2DC($a3)
    ctx->r2 = MEM_HU(0X2DC, ctx->r7);
    // nop

    // andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // beq         $v0, $zero, L_8002D59C
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0x36
        ctx->r3 = ADD32(0, 0X36);
        goto L_8002D59C;
    }
    // addiu       $v1, $zero, 0x36
    ctx->r3 = ADD32(0, 0X36);
    // j           L_8002D5A4
    // addiu       $v0, $zero, 0xDA
    ctx->r2 = ADD32(0, 0XDA);
    goto L_8002D5A4;
    // addiu       $v0, $zero, 0xDA
    ctx->r2 = ADD32(0, 0XDA);
L_8002D59C:
    // addiu       $v1, $zero, 0x1C
    ctx->r3 = ADD32(0, 0X1C);
    // addiu       $v0, $zero, 0x110
    ctx->r2 = ADD32(0, 0X110);
L_8002D5A4:
    // sh          $v0, 0x334($a3)
    MEM_H(0X334, ctx->r7) = ctx->r2;
    // ori         $a0, $a3, 0x330
    ctx->r4 = ctx->r7 | 0X330;
    // ori         $a1, $a3, 0x32C
    ctx->r5 = ctx->r7 | 0X32C;
    // addiu       $v0, $v1, -0x4
    ctx->r2 = ADD32(ctx->r3, -0X4);
    // lhu         $v1, 0x2E0($a3)
    ctx->r3 = MEM_HU(0X2E0, ctx->r7);
    // addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // sh          $v0, 0x330($a3)
    MEM_H(0X330, ctx->r7) = ctx->r2;
    // addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    // sh          $v0, 0x336($a3)
    MEM_H(0X336, ctx->r7) = ctx->r2;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
    // sh          $v0, 0x332($a3)
    MEM_H(0X332, ctx->r7) = ctx->r2;
    // jal         0x80027D18
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    sub_80027D18(rdram, ctx);
    goto after_0;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_1;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_1:
    // lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
