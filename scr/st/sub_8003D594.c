#include "recomp.h"
#include "disable_warnings.h"

void sub_8003D594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addiu       $s2, $v0, -0x70D8
    ctx->r18 = ADD32(ctx->r2, -0X70D8);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $a0, 0x2F4($s2)
    ctx->r4 = MEM_W(0X2F4, ctx->r18);
    // nop

    // bltz        $a0, L_8003D76C
    if (SIGNED(ctx->r4) < 0) {
        // lui         $v0, 0x5555
        ctx->r2 = S32(0X5555 << 16);
        goto L_8003D76C;
    }
    // lui         $v0, 0x5555
    ctx->r2 = S32(0X5555 << 16);
    // ori         $v0, $v0, 0x5556
    ctx->r2 = ctx->r2 | 0X5556;
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $a0, 31
    ctx->r3 = S32(ctx->r4) >> 31;
    // mfhi        $a1
    ctx->r5 = hi;
    // subu        $v1, $a1, $v1
    ctx->r3 = SUB32(ctx->r5, ctx->r3);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // bne         $a0, $v0, L_8003D660
    if (ctx->r4 != ctx->r2) {
        // nop
    
        goto L_8003D660;
    }
    // nop

    // jal         0x80078AC4
    // lui         $s1, 0x6666
    ctx->r17 = S32(0X6666 << 16);
    rand_recomp(rdram, ctx);
    goto after_0;
    // lui         $s1, 0x6666
    ctx->r17 = S32(0X6666 << 16);
    after_0:
    // ori         $s1, $s1, 0x6667
    ctx->r17 = ctx->r17 | 0X6667;
    // lw          $a0, 0x2F4($s2)
    ctx->r4 = MEM_W(0X2F4, ctx->r18);
    // addiu       $s0, $zero, 0x1E
    ctx->r16 = ADD32(0, 0X1E);
    // subu        $a0, $s0, $a0
    ctx->r4 = SUB32(ctx->r16, ctx->r4);
    // mult        $a0, $s1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $v0, $v0, -0x4000
    ctx->r2 = ADD32(ctx->r2, -0X4000);
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // mfhi        $a1
    ctx->r5 = hi;
    // sra         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5) >> 1;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
    // srav        $v0, $v0, $v1
    ctx->r2 = S32(ctx->r2) >> (ctx->r3 & 31);
    // sh          $v0, 0x310($gp)
    MEM_H(0X310, ctx->r28) = ctx->r2;
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // lw          $v1, 0x2F4($s2)
    ctx->r3 = MEM_W(0X2F4, ctx->r18);
    // nop

    // subu        $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
    // mult        $s0, $s1
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $v0, $v0, -0x4000
    ctx->r2 = ADD32(ctx->r2, -0X4000);
    // sra         $s0, $s0, 31
    ctx->r16 = S32(ctx->r16) >> 31;
    // mfhi        $a1
    ctx->r5 = hi;
    // sra         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5) >> 1;
    // subu        $v1, $v1, $s0
    ctx->r3 = SUB32(ctx->r3, ctx->r16);
    // addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
    // srav        $v0, $v0, $v1
    ctx->r2 = S32(ctx->r2) >> (ctx->r3 & 31);
    // sh          $v0, 0x312($gp)
    MEM_H(0X312, ctx->r28) = ctx->r2;
    // j           L_8003D680
    // nop

    goto L_8003D680;
    // nop

L_8003D660:
    // lhu         $v0, 0x310($gp)
    ctx->r2 = MEM_HU(0X310, ctx->r28);
    // lhu         $v1, 0x312($gp)
    ctx->r3 = MEM_HU(0X312, ctx->r28);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 17
    ctx->r3 = S32(ctx->r3) >> 17;
    // sh          $v0, 0x310($gp)
    MEM_H(0X310, ctx->r28) = ctx->r2;
    // sh          $v1, 0x312($gp)
    MEM_H(0X312, ctx->r28) = ctx->r3;
L_8003D680:
    // lhu         $a0, 0x310($gp)
    ctx->r4 = MEM_HU(0X310, ctx->r28);
    // nop

    // addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_8003D6B0
    if (ctx->r2 != 0) {
        // lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
        goto L_8003D6B0;
    }
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lhu         $v0, 0x288($v1)
    ctx->r2 = MEM_HU(0X288, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x288($v1)
    MEM_H(0X288, ctx->r3) = ctx->r2;
L_8003D6B0:
    // lhu         $a0, 0x312($gp)
    ctx->r4 = MEM_HU(0X312, ctx->r28);
    // nop

    // addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_8003D6E8
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003D6E8;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lhu         $v0, 0x28C($v1)
    ctx->r2 = MEM_HU(0X28C, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x28C($v1)
    MEM_H(0X28C, ctx->r3) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8003D6E8:
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v0, 0x288($v1)
    ctx->r2 = MEM_HU(0X288, ctx->r3);
    // nop

    // addiu       $v0, $v0, -0x801
    ctx->r2 = ADD32(ctx->r2, -0X801);
    // sltiu       $v0, $v0, 0x7BF
    ctx->r2 = ctx->r2 < 0X7BF ? 1 : 0;
    // beq         $v0, $zero, L_8003D708
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFC0
        ctx->r2 = ADD32(0, 0XFC0);
        goto L_8003D708;
    }
    // addiu       $v0, $zero, 0xFC0
    ctx->r2 = ADD32(0, 0XFC0);
    // sh          $v0, 0x288($v1)
    MEM_H(0X288, ctx->r3) = ctx->r2;
L_8003D708:
    // lhu         $v0, 0x288($v1)
    ctx->r2 = MEM_HU(0X288, ctx->r3);
    // nop

    // addiu       $v0, $v0, -0x41
    ctx->r2 = ADD32(ctx->r2, -0X41);
    // sltiu       $v0, $v0, 0x7BF
    ctx->r2 = ctx->r2 < 0X7BF ? 1 : 0;
    // beq         $v0, $zero, L_8003D724
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x40
        ctx->r2 = ADD32(0, 0X40);
        goto L_8003D724;
    }
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x288($v1)
    MEM_H(0X288, ctx->r3) = ctx->r2;
L_8003D724:
    // lhu         $v0, 0x28C($v1)
    ctx->r2 = MEM_HU(0X28C, ctx->r3);
    // nop

    // addiu       $v0, $v0, -0x801
    ctx->r2 = ADD32(ctx->r2, -0X801);
    // sltiu       $v0, $v0, 0x7BF
    ctx->r2 = ctx->r2 < 0X7BF ? 1 : 0;
    // beq         $v0, $zero, L_8003D740
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFC0
        ctx->r2 = ADD32(0, 0XFC0);
        goto L_8003D740;
    }
    // addiu       $v0, $zero, 0xFC0
    ctx->r2 = ADD32(0, 0XFC0);
    // sh          $v0, 0x28C($v1)
    MEM_H(0X28C, ctx->r3) = ctx->r2;
L_8003D740:
    // lhu         $v0, 0x28C($v1)
    ctx->r2 = MEM_HU(0X28C, ctx->r3);
    // nop

    // addiu       $v0, $v0, -0x41
    ctx->r2 = ADD32(ctx->r2, -0X41);
    // sltiu       $v0, $v0, 0x7BF
    ctx->r2 = ctx->r2 < 0X7BF ? 1 : 0;
    // beq         $v0, $zero, L_8003D75C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x40
        ctx->r2 = ADD32(0, 0X40);
        goto L_8003D75C;
    }
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x28C($v1)
    MEM_H(0X28C, ctx->r3) = ctx->r2;
L_8003D75C:
    // lw          $v0, 0x2F4($v1)
    ctx->r2 = MEM_W(0X2F4, ctx->r3);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x2F4($v1)
    MEM_W(0X2F4, ctx->r3) = ctx->r2;
L_8003D76C:
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
