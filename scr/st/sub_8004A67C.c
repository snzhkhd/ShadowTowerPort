#include "recomp.h"
#include "disable_warnings.h"

void sub_8004A67C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $s1
    ctx->r16 = ADD32(ctx->r5, ctx->r17);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(0X0, ctx->r8);
    // negu        $a3, $s0
    ctx->r7 = SUB32(0, ctx->r16);
    // subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
    // slt         $v0, $a0, $a3
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8004A77C
    if (ctx->r2 != 0) {
        // lui         $v0, 0xFF67
        ctx->r2 = S32(0XFF67 << 16);
        goto L_8004A77C;
    }
    // lui         $v0, 0xFF67
    ctx->r2 = S32(0XFF67 << 16);
    // slt         $v0, $s0, $a0
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // bne         $v0, $zero, L_8004A77C
    if (ctx->r2 != 0) {
        // lui         $v0, 0xFF67
        ctx->r2 = S32(0XFF67 << 16);
        goto L_8004A77C;
    }
    // lui         $v0, 0xFF67
    ctx->r2 = S32(0XFF67 << 16);
    // lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(0X8, ctx->r6);
    // lw          $v1, 0x8($t0)
    ctx->r3 = MEM_W(0X8, ctx->r8);
    // nop

    // subu        $a1, $v0, $v1
    ctx->r5 = SUB32(ctx->r2, ctx->r3);
    // slt         $v0, $a1, $a3
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8004A77C
    if (ctx->r2 != 0) {
        // lui         $v0, 0xFF67
        ctx->r2 = S32(0XFF67 << 16);
        goto L_8004A77C;
    }
    // lui         $v0, 0xFF67
    ctx->r2 = S32(0XFF67 << 16);
    // slt         $v0, $s0, $a1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_8004A77C
    if (ctx->r2 != 0) {
        // lui         $v0, 0xFF67
        ctx->r2 = S32(0XFF67 << 16);
        goto L_8004A77C;
    }
    // lui         $v0, 0xFF67
    ctx->r2 = S32(0XFF67 << 16);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(0X4, ctx->r8);
    // nop

    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(0X30, ctx->r29);
    // nop

    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // slt         $v0, $v1, $a3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $v0, $zero, L_8004A77C
    if (ctx->r2 != 0) {
        // lui         $v0, 0xFF67
        ctx->r2 = S32(0XFF67 << 16);
        goto L_8004A77C;
    }
    // lui         $v0, 0xFF67
    ctx->r2 = S32(0XFF67 << 16);
    // slt         $v0, $s0, $v1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8004A77C
    if (ctx->r2 != 0) {
        // lui         $v0, 0xFF67
        ctx->r2 = S32(0XFF67 << 16);
        goto L_8004A77C;
    }
    // lui         $v0, 0xFF67
    ctx->r2 = S32(0XFF67 << 16);
    // sra         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) >> 3;
    // mult        $a0, $a0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // sra         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5) >> 3;
    // nop

    // mult        $a1, $a1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // sra         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) >> 3;
    // nop

    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // mflo        $v1
    ctx->r3 = lo;
    // jal         0x800746C4
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    SquareRoot0(rdram, ctx);
    goto after_0;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    after_0:
    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // slt         $v0, $s0, $v1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8004A77C
    if (ctx->r2 != 0) {
        // lui         $v0, 0xFF67
        ctx->r2 = S32(0XFF67 << 16);
        goto L_8004A77C;
    }
    // lui         $v0, 0xFF67
    ctx->r2 = S32(0XFF67 << 16);
    // slt         $v0, $s1, $v1
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8004A780
    if (ctx->r2 != 0) {
        // subu        $v0, $v1, $s1
        ctx->r2 = SUB32(ctx->r3, ctx->r17);
        goto L_8004A780;
    }
    // subu        $v0, $v1, $s1
    ctx->r2 = SUB32(ctx->r3, ctx->r17);
    // j           L_8004A780
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_8004A780;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004A77C:
    // ori         $v0, $v0, 0x6981
    ctx->r2 = ctx->r2 | 0X6981;
L_8004A780:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
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
