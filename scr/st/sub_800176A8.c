#include "recomp.h"
#include "disable_warnings.h"

void sub_800176A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // beq         $a3, $zero, L_800176F4
    if (ctx->r7 == 0) {
        // sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
        goto L_800176F4;
    }
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(0X4, ctx->r7);
    // lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(0X8, ctx->r7);
    // lw          $a2, 0xC($a3)
    ctx->r6 = MEM_W(0XC, ctx->r7);
    // sw          $v1, 0x6DC8($v0)
    MEM_W(0X6DC8, ctx->r2) = ctx->r3;
    // sw          $a0, 0x6DCC($v0)
    MEM_W(0X6DCC, ctx->r2) = ctx->r4;
    // sw          $a1, 0x6DD0($v0)
    MEM_W(0X6DD0, ctx->r2) = ctx->r5;
    // sw          $a2, 0x6DD4($v0)
    MEM_W(0X6DD4, ctx->r2) = ctx->r6;
L_800176F4:
    // beq         $t0, $zero, L_8001772C
    if (ctx->r8 == 0) {
        // lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
        goto L_8001772C;
    }
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwl         $v1, 0x3($t0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r8);
    // lwr         $v1, 0x0($t0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r8);
    // lwl         $a0, 0x7($t0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r8);
    // lwr         $a0, 0x4($t0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r8);
    // swl         $v1, 0x6DDB($v0)
    do_swl(rdram, 0X6DDB, ctx->r2, ctx->r3);
    // swr         $v1, 0x6DD8($v0)
    do_swr(rdram, 0X6DD8, ctx->r2, ctx->r3);
    // swl         $a0, 0x6DDF($v0)
    do_swl(rdram, 0X6DDF, ctx->r2, ctx->r4);
    // swr         $a0, 0x6DDC($v0)
    do_swr(rdram, 0X6DDC, ctx->r2, ctx->r4);
L_8001772C:
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // addiu       $s0, $s0, -0x4288
    ctx->r16 = ADD32(ctx->r16, -0X4288);
    // lhu         $v1, 0x6DD8($v0)
    ctx->r3 = MEM_HU(0X6DD8, ctx->r2);
    // lhu         $a2, 0x6DDC($v0)
    ctx->r6 = MEM_HU(0X6DDC, ctx->r2);
    // lhu         $v0, 0x6DDA($v0)
    ctx->r2 = MEM_HU(0X6DDA, ctx->r2);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // sh          $v1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r3;
    // sh          $a2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r6;
    // jal         0x80074EC4
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    RotMatrix(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    after_0:
    // lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // lh          $a0, 0x10($sp)
    ctx->r4 = MEM_HS(0X10, ctx->r29);
    // jal         0x80049CD4
    // addiu       $a1, $a1, -0x41C8
    ctx->r5 = ADD32(ctx->r5, -0X41C8);
    sub_80049CD4(rdram, ctx);
    goto after_1;
    // addiu       $a1, $a1, -0x41C8
    ctx->r5 = ADD32(ctx->r5, -0X41C8);
    after_1:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // jal         0x800498CC
    // addiu       $a1, $a1, -0x4248
    ctx->r5 = ADD32(ctx->r5, -0X4248);
    sub_800498CC(rdram, ctx);
    goto after_2;
    // addiu       $a1, $a1, -0x4248
    ctx->r5 = ADD32(ctx->r5, -0X4248);
    after_2:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
