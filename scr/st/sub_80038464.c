#include "recomp.h"
#include "disable_warnings.h"

void sub_80038464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // lwl         $v0, 0x3($a3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r7);
    // lwr         $v0, 0x0($a3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r7);
    // nop

    // swl         $v0, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r2);
    // swr         $v0, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r2);
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // swl         $v0, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r2);
    // swr         $v0, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r2);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // beq         $a0, $zero, L_800384D0
    if (ctx->r4 == 0) {
        // addiu       $a2, $sp, 0x18
        ctx->r6 = ADD32(ctx->r29, 0X18);
        goto L_800384D0;
    }
    // addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(0X18, ctx->r29);
    // lhu         $v1, 0x20($sp)
    ctx->r3 = MEM_HU(0X20, ctx->r29);
    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // sh          $v1, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r3;
L_800384D0:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // bne         $v0, $zero, L_800384F0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800384F0;
    }
    // nop

    // jal         0x80038438
    // addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    sub_80038438(rdram, ctx);
    goto after_0;
    // addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    after_0:
    // j           L_80038508
    // nop

    goto L_80038508;
    // nop

L_800384F0:
    // lh          $v1, 0x1E($sp)
    ctx->r3 = MEM_HS(0X1E, ctx->r29);
    // nop

    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80038508
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80038508;
    }
    // nop

    // sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80038508:
    // lhu         $v0, 0x20($sp)
    ctx->r2 = MEM_HU(0X20, ctx->r29);
    // lhu         $v1, 0x22($sp)
    ctx->r3 = MEM_HU(0X22, ctx->r29);
    // lhu         $a1, 0x18($sp)
    ctx->r5 = MEM_HU(0X18, ctx->r29);
    // lhu         $a2, 0x1A($sp)
    ctx->r6 = MEM_HU(0X1A, ctx->r29);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // sh          $a1, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r5;
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // sh          $v1, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r3;
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // lhu         $v0, 0x1C($sp)
    ctx->r2 = MEM_HU(0X1C, ctx->r29);
    // addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // sh          $a2, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r6;
    // sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) << 16;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(0X0, ctx->r16);
    // lhu         $v0, 0x1E($sp)
    ctx->r2 = MEM_HU(0X1E, ctx->r29);
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x80079DCC
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    MoveImage(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    after_1:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8003859C
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_8003859C;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lhu         $a2, 0x1A($sp)
    ctx->r6 = MEM_HU(0X1A, ctx->r29);
    // lhu         $v0, 0x16($sp)
    ctx->r2 = MEM_HU(0X16, ctx->r29);
    // lh          $a1, 0x20($sp)
    ctx->r5 = MEM_HS(0X20, ctx->r29);
    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // sh          $a2, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r6;
    // sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) << 16;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // jal         0x80079DCC
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    MoveImage(rdram, ctx);
    goto after_2;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    after_2:
L_8003859C:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
