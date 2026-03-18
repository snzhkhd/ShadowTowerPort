#include "recomp.h"
#include "disable_warnings.h"

void sub_8007AFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0x7DE4($a1)
    ctx->r5 = MEM_W(0X7DE4, ctx->r5);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DE0($v0)
    ctx->r2 = MEM_W(0X7DE0, ctx->r2);
    // nop

    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16) << 2;
    // addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DD8($v1)
    ctx->r3 = MEM_W(0X7DD8, ctx->r3);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DDC($v0)
    ctx->r2 = MEM_W(0X7DDC, ctx->r2);
    // lui         $v1, 0x1100
    ctx->r3 = S32(0X1100 << 16);
    // sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DE0($v0)
    ctx->r2 = MEM_W(0X7DE0, ctx->r2);
    // ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // jal         0x8007C070
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    sub_8007C070(rdram, ctx);
    goto after_0;
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    after_0:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DE0($v0)
    ctx->r2 = MEM_W(0X7DE0, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x100
    ctx->r3 = S32(0X100 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8007B0C0
    if (ctx->r2 == 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_8007B0C0;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // lui         $s1, 0x100
    ctx->r17 = S32(0X100 << 16);
L_8007B090:
    // jal         0x8007C0A4
    // nop

    sub_8007C0A4(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // bne         $v0, $zero, L_8007B0C0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8007B0C0;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DE0($v0)
    ctx->r2 = MEM_W(0X7DE0, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // and         $v0, $v0, $s1
    ctx->r2 = ctx->r2 & ctx->r17;
    // bne         $v0, $zero, L_8007B090
    if (ctx->r2 != 0) {
        // addu        $v0, $s0, $zero
        ctx->r2 = ADD32(ctx->r16, 0);
        goto L_8007B090;
    }
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8007B0C0:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
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
