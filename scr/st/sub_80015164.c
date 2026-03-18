#include "recomp.h"
#include "disable_warnings.h"

void sub_80015164(uint8_t* rdram, recomp_context* ctx) {
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
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // jal         0x80014E4C
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    sub_80014E4C(rdram, ctx);
    goto after_0;
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    after_0:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // bne         $v1, $zero, L_800151B4
    if (ctx->r3 != 0) {
        // nop
    
        goto L_800151B4;
    }
    // nop

    // jal         0x80015024
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_80015024(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x80014E4C
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    sub_80014E4C(rdram, ctx);
    goto after_2;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_2:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_80015214
    if (ctx->r3 == 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80015214;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800151B4:
    // lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(0X4, ctx->r3);
    // nop

    // addiu       $v0, $a0, -0xC
    ctx->r2 = ADD32(ctx->r4, -0XC);
    // subu        $a1, $v0, $s1
    ctx->r5 = SUB32(ctx->r2, ctx->r17);
    // slti        $v0, $a1, 0x80C
    ctx->r2 = SIGNED(ctx->r5) < 0X80C ? 1 : 0;
    // bne         $v0, $zero, L_800151EC
    if (ctx->r2 != 0) {
        // addu        $v0, $v1, $s1
        ctx->r2 = ADD32(ctx->r3, ctx->r17);
        goto L_800151EC;
    }
    // addu        $v0, $v1, $s1
    ctx->r2 = ADD32(ctx->r3, ctx->r17);
    // sb          $zero, 0xC($v0)
    MEM_B(0XC, ctx->r2) = 0;
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // j           L_800151F0
    // sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    goto L_800151F0;
    // sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
L_800151EC:
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
L_800151F0:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // addiu       $v0, $v1, 0xC
    ctx->r2 = ADD32(ctx->r3, 0XC);
    // sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // beq         $s2, $zero, L_80015214
    if (ctx->r18 == 0) {
        // sw          $s2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r18;
        goto L_80015214;
    }
    // sw          $s2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r18;
    // sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
L_80015214:
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
