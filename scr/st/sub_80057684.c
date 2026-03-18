#include "recomp.h"
#include "disable_warnings.h"

void sub_80057684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // addiu       $s0, $s0, -0x2ED0
    ctx->r16 = ADD32(ctx->r16, -0X2ED0);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sb          $v0, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r2;
    // sb          $v0, 0x48($s0)
    MEM_B(0X48, ctx->r16) = ctx->r2;
    // sb          $zero, 0x45($s0)
    MEM_B(0X45, ctx->r16) = 0;
    // sb          $zero, 0x49($s0)
    MEM_B(0X49, ctx->r16) = 0;
    // sb          $v0, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r2;
    // sb          $v0, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r2;
    // sb          $zero, 0x47($s0)
    MEM_B(0X47, ctx->r16) = 0;
    // sb          $zero, 0x4B($s0)
    MEM_B(0X4B, ctx->r16) = 0;
    // jal         0x8007E834
    // addiu       $a1, $s0, 0x22
    ctx->r5 = ADD32(ctx->r16, 0X22);
    PadInitDirect(rdram, ctx);
    goto after_0;
    // addiu       $a1, $s0, 0x22
    ctx->r5 = ADD32(ctx->r16, 0X22);
    after_0:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // jal         0x8007CCC4
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    sub_8007CCC4(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // jal         0x8007C884
    // nop

    PadStartCom_0(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x80057428
    // nop

    sub_80057428(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // jal         0x8005755C
    // nop

    sub_8005755C(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // addiu       $v0, $a0, -0x2E80
    ctx->r2 = ADD32(ctx->r4, -0X2E80);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // sb          $v1, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r3;
    // sb          $zero, 0x13($v0)
    MEM_B(0X13, ctx->r2) = 0;
    // sb          $zero, 0x11($v0)
    MEM_B(0X11, ctx->r2) = 0;
    // sb          $zero, 0x12($v0)
    MEM_B(0X12, ctx->r2) = 0;
    // sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    // sb          $zero, 0x18($v0)
    MEM_B(0X18, ctx->r2) = 0;
    // sw          $zero, -0x2E80($a0)
    MEM_W(-0X2E80, ctx->r4) = 0;
    // sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // jal         0x800573BC
    // sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    sub_800573BC(rdram, ctx);
    goto after_5;
    // sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    after_5:
    // jal         0x8005738C
    // nop

    sub_8005738C(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // jr          $ra
    // nop

    return;
    // nop

;}
