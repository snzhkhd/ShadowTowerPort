#include "recomp.h"
#include "disable_warnings.h"

void sub_8002C090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lhu         $v1, 0x1F8($s2)
    ctx->r3 = MEM_HU(0X1F8, ctx->r18);
    // addiu       $v0, $zero, 0x5E
    ctx->r2 = ADD32(0, 0X5E);
    // sh          $v0, 0x330($s2)
    MEM_H(0X330, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x8A
    ctx->r2 = ADD32(0, 0X8A);
    // sh          $v0, 0x334($s2)
    MEM_H(0X334, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // bne         $v1, $zero, L_8002C0D0
    if (ctx->r3 != 0) {
        // sh          $v0, 0x336($s2)
        MEM_H(0X336, ctx->r18) = ctx->r2;
        goto L_8002C0D0;
    }
    // sh          $v0, 0x336($s2)
    MEM_H(0X336, ctx->r18) = ctx->r2;
    // j           L_8002C0D4
    // addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    goto L_8002C0D4;
    // addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
L_8002C0D0:
    // addiu       $v0, $zero, 0x84
    ctx->r2 = ADD32(0, 0X84);
L_8002C0D4:
    // sh          $v0, 0x332($s2)
    MEM_H(0X332, ctx->r18) = ctx->r2;
    // ori         $a0, $s2, 0x330
    ctx->r4 = ctx->r18 | 0X330;
    // ori         $a1, $s2, 0x32C
    ctx->r5 = ctx->r18 | 0X32C;
    // addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
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
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $a3, $v0, -0x4150
    ctx->r7 = ADD32(ctx->r2, -0X4150);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7E10
    ctx->r6 = ADD32(ctx->r2, -0X7E10);
L_8002C110:
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // slti        $a0, $a0, 0x7
    ctx->r4 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // bne         $a0, $zero, L_8002C110
    if (ctx->r4 != 0) {
        // sh          $zero, 0x0($v0)
        MEM_H(0X0, ctx->r2) = 0;
        goto L_8002C110;
    }
    // sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    // addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    // addiu       $s2, $s2, 0x300
    ctx->r18 = ADD32(ctx->r18, 0X300);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // addiu       $s0, $s0, 0xD50
    ctx->r16 = ADD32(ctx->r16, 0XD50);
    // lhu         $a0, 0x280($s0)
    ctx->r4 = MEM_HU(0X280, ctx->r16);
    // addiu       $s1, $s0, 0xC00
    ctx->r17 = ADD32(ctx->r16, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    sub_8002732C(rdram, ctx);
    goto after_2;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_2:
    // addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    // addiu       $a2, $zero, 0x86
    ctx->r6 = ADD32(0, 0X86);
    // lhu         $a0, 0x282($s0)
    ctx->r4 = MEM_HU(0X282, ctx->r16);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // jal         0x8002732C
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    sub_8002732C(rdram, ctx);
    goto after_3;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_3:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
