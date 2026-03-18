#include "recomp.h"
#include "disable_warnings.h"

void sub_80077750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // addiu       $a1, $a1, 0x6B0C
    ctx->r5 = ADD32(ctx->r5, 0X6B0C);
    // sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17) << 2;
    // addu        $a0, $v0, $a1
    ctx->r4 = ADD32(ctx->r2, ctx->r5);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $s4, 0x0($a0)
    ctx->r20 = MEM_W(0X0, ctx->r4);
    // nop

    // beq         $s2, $s4, L_80077878
    if (ctx->r18 == ctx->r20) {
        // addu        $v0, $s4, $zero
        ctx->r2 = ADD32(ctx->r20, 0);
        goto L_80077878;
    }
    // addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // lhu         $v0, -0x4($a1)
    ctx->r2 = MEM_HU(-0X4, ctx->r5);
    // nop

    // beq         $v0, $zero, L_80077874
    if (ctx->r2 == 0) {
        // addiu       $a2, $a1, -0x4
        ctx->r6 = ADD32(ctx->r5, -0X4);
        goto L_80077874;
    }
    // addiu       $a2, $a1, -0x4
    ctx->r6 = ADD32(ctx->r5, -0X4);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7B98($v0)
    ctx->r2 = MEM_W(0X7B98, ctx->r2);
    // nop

    // lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(0X0, ctx->r2);
    // sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // beq         $s2, $zero, L_800777E0
    if (ctx->r18 == 0) {
        // andi        $s3, $v1, 0xFFFF
        ctx->r19 = ctx->r3 & 0XFFFF;
        goto L_800777E0;
    }
    // andi        $s3, $v1, 0xFFFF
    ctx->r19 = ctx->r3 & 0XFFFF;
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sllv        $v1, $v1, $s1
    ctx->r3 = S32(ctx->r3) << (ctx->r17 & 31);
    // sw          $s2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r18;
    // lhu         $v0, 0x30($a2)
    ctx->r2 = MEM_HU(0X30, ctx->r6);
    // or          $s3, $s3, $v1
    ctx->r19 = ctx->r19 | ctx->r3;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // j           L_80077800
    // sh          $v0, 0x30($a2)
    MEM_H(0X30, ctx->r6) = ctx->r2;
    goto L_80077800;
    // sh          $v0, 0x30($a2)
    MEM_H(0X30, ctx->r6) = ctx->r2;
L_800777E0:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sllv        $v0, $v0, $s1
    ctx->r2 = S32(ctx->r2) << (ctx->r17 & 31);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // lhu         $v1, 0x2C($a1)
    ctx->r3 = MEM_HU(0X2C, ctx->r5);
    // and         $s3, $s3, $v0
    ctx->r19 = ctx->r19 & ctx->r2;
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // sh          $v1, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = ctx->r3;
L_80077800:
    // bne         $s1, $zero, L_80077824
    if (ctx->r17 != 0) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_80077824;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // sltiu       $s0, $s2, 0x1
    ctx->r16 = ctx->r18 < 0X1 ? 1 : 0;
    // jal         0x80077F24
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    ChangeClearPAD(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // jal         0x80077F34
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    ChangeClearRCnt(rdram, ctx);
    goto after_1;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80077824:
    // bne         $s1, $v0, L_8007783C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_8007783C;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80077F34
    // sltiu       $a1, $s2, 0x1
    ctx->r5 = ctx->r18 < 0X1 ? 1 : 0;
    ChangeClearRCnt(rdram, ctx);
    goto after_2;
    // sltiu       $a1, $s2, 0x1
    ctx->r5 = ctx->r18 < 0X1 ? 1 : 0;
    after_2:
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8007783C:
    // bne         $s1, $v0, L_80077854
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
        goto L_80077854;
    }
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // jal         0x80077F34
    // sltiu       $a1, $s2, 0x1
    ctx->r5 = ctx->r18 < 0X1 ? 1 : 0;
    ChangeClearRCnt(rdram, ctx);
    goto after_3;
    // sltiu       $a1, $s2, 0x1
    ctx->r5 = ctx->r18 < 0X1 ? 1 : 0;
    after_3:
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_80077854:
    // bne         $s1, $v0, L_80077864
    if (ctx->r17 != ctx->r2) {
        // addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
        goto L_80077864;
    }
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // jal         0x80077F34
    // sltiu       $a1, $s2, 0x1
    ctx->r5 = ctx->r18 < 0X1 ? 1 : 0;
    ChangeClearRCnt(rdram, ctx);
    goto after_4;
    // sltiu       $a1, $s2, 0x1
    ctx->r5 = ctx->r18 < 0X1 ? 1 : 0;
    after_4:
L_80077864:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7B98($v0)
    ctx->r2 = MEM_W(0X7B98, ctx->r2);
    // nop

    // sh          $s3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r19;
L_80077874:
    // addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
L_80077878:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
