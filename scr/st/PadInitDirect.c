#include "recomp.h"
#include "disable_warnings.h"

void PadInitDirect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x7E50($at)
    MEM_W(0X7E50, ctx->r1) = 0;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = 0;
    // jal         0x8007EEA4
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    sub_8007EEA4(rdram, ctx);
    goto after_0;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    after_0:
    // lui         $s0, 0x801F
    ctx->r16 = S32(0X801F << 16);
    // addiu       $s0, $s0, -0x4C88
    ctx->r16 = ADD32(ctx->r16, -0X4C88);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0x1604
    ctx->r2 = ADD32(ctx->r2, -0X1604);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7E18($at)
    MEM_W(0X7E18, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0x166C
    ctx->r2 = ADD32(ctx->r2, -0X166C);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7E1C($at)
    MEM_W(0X7E1C, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0x1500
    ctx->r2 = ADD32(ctx->r2, -0X1500);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7E20($at)
    MEM_W(0X7E20, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0x1444
    ctx->r2 = ADD32(ctx->r2, -0X1444);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7E24($at)
    MEM_W(0X7E24, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0x11C8
    ctx->r2 = ADD32(ctx->r2, -0X11C8);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7E28($at)
    MEM_W(0X7E28, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0x1190
    ctx->r2 = ADD32(ctx->r2, -0X1190);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7E2C($at)
    MEM_W(0X7E2C, ctx->r1) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0x1510
    ctx->r2 = ADD32(ctx->r2, -0X1510);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $s0, 0x7E4C($at)
    MEM_W(0X7E4C, ctx->r1) = ctx->r16;
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7E3C($at)
    MEM_W(0X7E3C, ctx->r1) = ctx->r2;
    // jal         0x8007EE94
    // addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    bzero_recomp(rdram, ctx);
    goto after_1;
    // addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    after_1:
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // lui         $a3, 0x801F
    ctx->r7 = S32(0X801F << 16);
    // addiu       $a3, $a3, -0x4CD0
    ctx->r7 = ADD32(ctx->r7, -0X4CD0);
    // lui         $a2, 0x801F
    ctx->r6 = S32(0X801F << 16);
    // addiu       $a2, $a2, -0x4D18
    ctx->r6 = ADD32(ctx->r6, -0X4D18);
    // sw          $s1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r17;
    // sw          $s2, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->r18;
L_8007E914:
    // lw          $v0, -0x10($a0)
    ctx->r2 = MEM_W(-0X10, ctx->r4);
    // addiu       $a1, $s0, 0x5D
    ctx->r5 = ADD32(ctx->r16, 0X5D);
    // sw          $zero, -0x34($a0)
    MEM_W(-0X34, ctx->r4) = 0;
    // sw          $s0, -0x30($a0)
    MEM_W(-0X30, ctx->r4) = ctx->r16;
    // sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // lw          $v0, -0x10($a0)
    ctx->r2 = MEM_W(-0X10, ctx->r4);
    // addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // sw          $a2, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r6;
    // sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
L_8007E93C:
    // sb          $t1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r9;
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // bgez        $v1, L_8007E93C
    if (SIGNED(ctx->r3) >= 0) {
        // addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_8007E93C;
    }
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // addiu       $a3, $a3, 0x23
    ctx->r7 = ADD32(ctx->r7, 0X23);
    // addiu       $a2, $a2, 0x23
    ctx->r6 = ADD32(ctx->r6, 0X23);
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // addiu       $a0, $a0, 0xF0
    ctx->r4 = ADD32(ctx->r4, 0XF0);
    // slti        $v0, $t0, 0x2
    ctx->r2 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8007E914
    if (ctx->r2 != 0) {
        // addiu       $s0, $s0, 0xF0
        ctx->r16 = ADD32(ctx->r16, 0XF0);
        goto L_8007E914;
    }
    // addiu       $s0, $s0, 0xF0
    ctx->r16 = ADD32(ctx->r16, 0XF0);
    // jal         0x8007CE2C
    // nop

    sub_8007CE2C(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v0, 0x7E50($at)
    MEM_W(0X7E50, ctx->r1) = ctx->r2;
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
