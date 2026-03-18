#include "recomp.h"
#include "disable_warnings.h"

void sub_800286A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // addu        $t2, $a1, $zero
    ctx->r10 = ADD32(ctx->r5, 0);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lw          $v1, 0x304($s1)
    ctx->r3 = MEM_W(0X304, ctx->r17);
    // nop

    // lw          $s0, 0x8($v1)
    ctx->r16 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $t0, $s0, 0xC
    ctx->r8 = ADD32(ctx->r16, 0XC);
    // sltu        $v0, $v0, $t0
    ctx->r2 = ctx->r2 < ctx->r8 ? 1 : 0;
    // bne         $v0, $zero, L_8002876C
    if (ctx->r2 != 0) {
        // addu        $a3, $a2, $zero
        ctx->r7 = ADD32(ctx->r6, 0);
        goto L_8002876C;
    }
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $t1, $zero
    ctx->r5 = ADD32(ctx->r9, 0);
    // sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // lw          $v0, 0x328($s1)
    ctx->r2 = MEM_W(0X328, ctx->r17);
    // addu        $a2, $t2, $zero
    ctx->r6 = ADD32(ctx->r10, 0);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // jal         0x8007C704
    // sw          $v0, 0x328($s1)
    MEM_W(0X328, ctx->r17) = ctx->r2;
    GetTPage(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x328($s1)
    MEM_W(0X328, ctx->r17) = ctx->r2;
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    // jal         0x8007A934
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sub_8007A934(rdram, ctx);
    goto after_1;
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // lw          $v0, 0xE4($s1)
    ctx->r2 = MEM_W(0XE4, ctx->r17);
    // lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(0X0, ctx->r16);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // and         $v1, $v1, $a1
    ctx->r3 = ctx->r3 & ctx->r5;
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // lw          $v1, 0xE4($s1)
    ctx->r3 = MEM_W(0XE4, ctx->r17);
    // nop

    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // and         $a0, $s0, $a0
    ctx->r4 = ctx->r16 & ctx->r4;
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8002876C:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
