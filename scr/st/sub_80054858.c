#include "recomp.h"
#include "disable_warnings.h"

void sub_80054858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sb          $v1, 0x6E18($v0)
    MEM_B(0X6E18, ctx->r2) = ctx->r3;
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $v1, 0x6E16($v0)
    MEM_B(0X6E16, ctx->r2) = ctx->r3;
    // addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // sb          $v1, 0x6E17($v0)
    MEM_B(0X6E17, ctx->r2) = ctx->r3;
    // sb          $zero, 0x6E19($v0)
    MEM_B(0X6E19, ctx->r2) = 0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800548AC:
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // jal         0x80026DD4
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    sub_80026DD4(rdram, ctx);
    goto after_0;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_0:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $s1, L_800548AC
    if (ctx->r16 != ctx->r17) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_800548AC;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addiu       $a0, $s2, 0x12C
    ctx->r4 = ADD32(ctx->r18, 0X12C);
    // jal         0x800542D0
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    sub_800542D0(rdram, ctx);
    goto after_1;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // addiu       $s0, $s0, -0x2F70
    ctx->r16 = ADD32(ctx->r16, -0X2F70);
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0x6E16($s0)
    MEM_B(0X6E16, ctx->r16) = ctx->r2;
    // jal         0x80057A3C
    // sb          $zero, 0x6E19($s0)
    MEM_B(0X6E19, ctx->r16) = 0;
    sub_80057A3C(rdram, ctx);
    goto after_2;
    // sb          $zero, 0x6E19($s0)
    MEM_B(0X6E19, ctx->r16) = 0;
    after_2:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s1, $v0, -0x2E80
    ctx->r17 = ADD32(ctx->r2, -0X2E80);
L_800548FC:
    // lhu         $v0, 0x4($s1)
    ctx->r2 = MEM_HU(0X4, ctx->r17);
    // nop

    // beq         $v0, $zero, L_80054924
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_80054924;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // lbu         $v1, 0x6E16($s0)
    ctx->r3 = MEM_BU(0X6E16, ctx->r16);
    // nop

    // bne         $v1, $v0, L_80054920
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_80054920;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // sb          $zero, 0x6E19($s0)
    MEM_B(0X6E19, ctx->r16) = 0;
L_80054920:
    // sb          $v0, 0x6E16($s0)
    MEM_B(0X6E16, ctx->r16) = ctx->r2;
L_80054924:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // jal         0x80026DD4
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    sub_80026DD4(rdram, ctx);
    goto after_3;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_3:
    // lbu         $v1, 0x6E16($s0)
    ctx->r3 = MEM_BU(0X6E16, ctx->r16);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bne         $v1, $v0, L_800548FC
    if (ctx->r3 != ctx->r2) {
        // lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
        goto L_800548FC;
    }
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
    // addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // sb          $v1, 0x6E18($v0)
    MEM_B(0X6E18, ctx->r2) = ctx->r3;
    // addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // sb          $v1, 0x6E16($v0)
    MEM_B(0X6E16, ctx->r2) = ctx->r3;
    // sb          $zero, 0x6E19($v0)
    MEM_B(0X6E19, ctx->r2) = 0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80054974:
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // jal         0x80026DD4
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    sub_80026DD4(rdram, ctx);
    goto after_4;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_4:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $s1, L_80054974
    if (ctx->r16 != ctx->r17) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80054974;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
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
    // sb          $zero, 0x6E16($v0)
    MEM_B(0X6E16, ctx->r2) = 0;
    // jal         0x80057A3C
    // sb          $zero, 0x6E17($v0)
    MEM_B(0X6E17, ctx->r2) = 0;
    sub_80057A3C(rdram, ctx);
    goto after_5;
    // sb          $zero, 0x6E17($v0)
    MEM_B(0X6E17, ctx->r2) = 0;
    after_5:
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
