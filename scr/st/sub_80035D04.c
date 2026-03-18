#include "recomp.h"
#include "disable_warnings.h"

void sub_80035D04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // lw          $s0, 0xF1C($v0)
    ctx->r16 = MEM_W(0XF1C, ctx->r2);
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(0X8, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80035E70
    if (ctx->r2 != 0) {
        // addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
        goto L_80035E70;
    }
    // addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // lui         $v1, 0xFFF
    ctx->r3 = S32(0XFFF << 16);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(0X20, ctx->r16);
    // and         $v1, $a3, $v1
    ctx->r3 = ctx->r7 & ctx->r3;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(0X24, ctx->r16);
    // lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(0X28, ctx->r16);
    // addiu       $s1, $s2, 0x5948
    ctx->r17 = ADD32(ctx->r18, 0X5948);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // lw          $v1, 0x14($sp)
    ctx->r3 = MEM_W(0X14, ctx->r29);
    // lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(0X18, ctx->r29);
    // lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(0X1C, ctx->r29);
    // sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
    // sw          $a0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r4;
    // sw          $a1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r5;
    // sh          $t0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r8;
    // sh          $a3, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r7;
    // lwl         $v0, 0x43($s0)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X43, ctx->r16);
    // lwr         $v0, 0x40($s0)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X40, ctx->r16);
    // lwl         $v1, 0x47($s0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X47, ctx->r16);
    // lwr         $v1, 0x44($s0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X44, ctx->r16);
    // swl         $v0, 0x17($s1)
    do_swl(rdram, 0X17, ctx->r17, ctx->r2);
    // swr         $v0, 0x14($s1)
    do_swr(rdram, 0X14, ctx->r17, ctx->r2);
    // swl         $v1, 0x1B($s1)
    do_swl(rdram, 0X1B, ctx->r17, ctx->r3);
    // swr         $v1, 0x18($s1)
    do_swr(rdram, 0X18, ctx->r17, ctx->r3);
    // lh          $v0, 0x40($s0)
    ctx->r2 = MEM_HS(0X40, ctx->r16);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lh          $v0, 0x44($s0)
    ctx->r2 = MEM_HS(0X44, ctx->r16);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a3
    ctx->r7 = lo;
    // jal         0x800746C4
    // addu        $a0, $v1, $a3
    ctx->r4 = ADD32(ctx->r3, ctx->r7);
    SquareRoot0(rdram, ctx);
    goto after_0;
    // addu        $a0, $v1, $a3
    ctx->r4 = ADD32(ctx->r3, ctx->r7);
    after_0:
    // sh          $v0, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r2;
    // lh          $a0, 0x44($s0)
    ctx->r4 = MEM_HS(0X44, ctx->r16);
    // lh          $a1, 0x40($s0)
    ctx->r5 = MEM_HS(0X40, ctx->r16);
    // jal         0x80076EA4
    // nop

    ratan2(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // sh          $v0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // andi        $v1, $v0, 0x7
    ctx->r3 = ctx->r2 & 0X7;
    // beq         $v1, $a0, L_80035E38
    if (ctx->r3 == ctx->r4) {
        // slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
        goto L_80035E38;
    }
    // slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // beq         $v0, $zero, L_80035E1C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80035E1C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_80035E44
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80035E44;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_80035E7C
    // nop

    goto L_80035E7C;
    // nop

L_80035E1C:
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $v0, L_80035E50
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_80035E50;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_80035E5C
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80035E5C;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // j           L_80035E7C
    // nop

    goto L_80035E7C;
    // nop

L_80035E38:
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // j           L_80035E60
    // sw          $v0, 0x5948($s2)
    MEM_W(0X5948, ctx->r18) = ctx->r2;
    goto L_80035E60;
    // sw          $v0, 0x5948($s2)
    MEM_W(0X5948, ctx->r18) = ctx->r2;
L_80035E44:
    // addiu       $v0, $zero, 0xA2
    ctx->r2 = ADD32(0, 0XA2);
    // j           L_80035E60
    // sw          $v0, 0x5948($s2)
    MEM_W(0X5948, ctx->r18) = ctx->r2;
    goto L_80035E60;
    // sw          $v0, 0x5948($s2)
    MEM_W(0X5948, ctx->r18) = ctx->r2;
L_80035E50:
    // addiu       $v0, $zero, 0xB2
    ctx->r2 = ADD32(0, 0XB2);
    // j           L_80035E60
    // sw          $v0, 0x5948($s2)
    MEM_W(0X5948, ctx->r18) = ctx->r2;
    goto L_80035E60;
    // sw          $v0, 0x5948($s2)
    MEM_W(0X5948, ctx->r18) = ctx->r2;
L_80035E5C:
    // sw          $a0, 0x5948($s2)
    MEM_W(0X5948, ctx->r18) = ctx->r4;
L_80035E60:
    // jal         0x80049544
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_80049544(rdram, ctx);
    goto after_2;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // j           L_80035E7C
    // nop

    goto L_80035E7C;
    // nop

L_80035E70:
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80035E7C:
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
