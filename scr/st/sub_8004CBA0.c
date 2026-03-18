#include "recomp.h"
#include "disable_warnings.h"

void sub_8004CBA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // jal         0x80078AC4
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    rand_recomp(rdram, ctx);
    goto after_0;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    after_0:
    // lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(0X0, ctx->r16);
    // bgez        $v0, L_8004CBD4
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_8004CBD4;
    }
    // addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // addiu       $v0, $v0, 0x7FF
    ctx->r2 = ADD32(ctx->r2, 0X7FF);
L_8004CBD4:
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // jal         0x80078AC4
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_1;
    // sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    after_1:
    // lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(0X2, ctx->r16);
    // bgez        $v0, L_8004CBF4
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $v1, $v1, -0x10
        ctx->r3 = ADD32(ctx->r3, -0X10);
        goto L_8004CBF4;
    }
    // addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
L_8004CBF4:
    // sra         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) >> 10;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // jal         0x80078AC4
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_2;
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    after_2:
    // lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(0X4, ctx->r16);
    // bgez        $v0, L_8004CC14
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
        goto L_8004CC14;
    }
    // addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // addiu       $v0, $v0, 0x7FF
    ctx->r2 = ADD32(ctx->r2, 0X7FF);
L_8004CC14:
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // lh          $v1, 0x0($s0)
    ctx->r3 = MEM_HS(0X0, ctx->r16);
    // sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // lh          $v1, 0x4($s0)
    ctx->r3 = MEM_HS(0X4, ctx->r16);
    // lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(0X8, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r2;
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
