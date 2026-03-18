#include "recomp.h"
#include "disable_warnings.h"

void sub_800774A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // addiu       $s0, $s0, 0x6B08
    ctx->r16 = ADD32(ctx->r16, 0X6B08);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(0X0, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80077570
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_80077570;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7B94($v1)
    ctx->r3 = MEM_W(0X7B94, ctx->r3);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7B98($v0)
    ctx->r2 = MEM_W(0X7B98, ctx->r2);
    // lui         $a1, 0x3333
    ctx->r5 = S32(0X3333 << 16);
    // sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(0X0, ctx->r2);
    // ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7B9C($v0)
    ctx->r2 = MEM_W(0X7B9C, ctx->r2);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // jal         0x800779B0
    // addiu       $a1, $zero, 0x41A
    ctx->r5 = ADD32(0, 0X41A);
    sub_800779B0(rdram, ctx);
    goto after_0;
    // addiu       $a1, $zero, 0x41A
    ctx->r5 = ADD32(0, 0X41A);
    after_0:
    // jal         0x80078A54
    // addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    setjmp_recomp(rdram, ctx);
    goto after_1;
    // addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    after_1:
    // beq         $v0, $zero, L_80077520
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80077520;
    }
    // nop

    // jal         0x80077580
    // nop

    sub_80077580(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_80077520:
    // lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // addiu       $s0, $s0, 0x6B44
    ctx->r16 = ADD32(ctx->r16, 0X6B44);
    // addiu       $a0, $s0, -0x4
    ctx->r4 = ADD32(ctx->r16, -0X4);
    // addiu       $v0, $s0, 0xFDC
    ctx->r2 = ADD32(ctx->r16, 0XFDC);
    // jal         0x80077E84
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    HookEntryInt(rdram, ctx);
    goto after_3;
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    after_3:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jal         0x800779D4
    // sh          $v0, -0x3C($s0)
    MEM_H(-0X3C, ctx->r16) = ctx->r2;
    sub_800779D4(rdram, ctx);
    goto after_4;
    // sh          $v0, -0x3C($s0)
    MEM_H(-0X3C, ctx->r16) = ctx->r2;
    after_4:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7B90($v1)
    ctx->r3 = MEM_W(0X7B90, ctx->r3);
    // jal         0x80077AF4
    // sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    startIntrDMA(rdram, ctx);
    goto after_5;
    // sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
    after_5:
    // lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // lw          $a0, 0x7B90($a0)
    ctx->r4 = MEM_W(0X7B90, ctx->r4);
    // jal         0x80077DDC
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    sub_80077DDC(rdram, ctx);
    goto after_6;
    // sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    after_6:
    // jal         0x80077EA4
    // addiu       $s0, $s0, -0x3C
    ctx->r16 = ADD32(ctx->r16, -0X3C);
    ExitCriticalSection(rdram, ctx);
    goto after_7;
    // addiu       $s0, $s0, -0x3C
    ctx->r16 = ADD32(ctx->r16, -0X3C);
    after_7:
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_80077570:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
