#include "recomp.h"
#include "disable_warnings.h"

void sub_80029618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // addu        $s7, $a2, $zero
    ctx->r23 = ADD32(ctx->r6, 0);
    // sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, 0x7F30
    ctx->r6 = ADD32(ctx->r2, 0X7F30);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r3);
    // swr         $v1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r3);
    // lui         $a0, 0x1F80
    ctx->r4 = S32(0X1F80 << 16);
    // ori         $a0, $a0, 0x33C
    ctx->r4 = ctx->r4 | 0X33C;
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // lui         $a2, 0x1F80
    ctx->r6 = S32(0X1F80 << 16);
    // ori         $a2, $a2, 0x35C
    ctx->r6 = ctx->r6 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lui         $fp, 0x1F80
    ctx->r30 = S32(0X1F80 << 16);
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x340($fp)
    MEM_H(0X340, ctx->r30) = ctx->r2;
    // sh          $v0, 0x342($fp)
    MEM_H(0X342, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x35C($fp)
    MEM_H(0X35C, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x1F8
    ctx->r2 = ADD32(0, 0X1F8);
    // sh          $v0, 0x35E($fp)
    MEM_H(0X35E, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x264
    ctx->r2 = ADD32(0, 0X264);
    // sh          $v0, 0x358($fp)
    MEM_H(0X358, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // sh          $s5, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r21;
    // sh          $s4, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r20;
    // sh          $v0, 0x35A($fp)
    MEM_H(0X35A, ctx->r30) = ctx->r2;
    // jal         0x80028364
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    sub_80028364(rdram, ctx);
    goto after_0;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_0:
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // ori         $a0, $a0, 0x33C
    ctx->r4 = ctx->r4 | 0X33C;
    // addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    // ori         $a2, $a2, 0x35C
    ctx->r6 = ctx->r6 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addu        $s0, $s4, $s6
    ctx->r16 = ADD32(ctx->r20, ctx->r22);
    // addiu       $s3, $s0, -0x10
    ctx->r19 = ADD32(ctx->r16, -0X10);
    // addiu       $s1, $zero, 0x41
    ctx->r17 = ADD32(0, 0X41);
    // sh          $s3, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r19;
    // jal         0x80028364
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    sub_80028364(rdram, ctx);
    goto after_1;
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_1:
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // ori         $a0, $a0, 0x33C
    ctx->r4 = ctx->r4 | 0X33C;
    // addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    // ori         $a2, $a2, 0x35C
    ctx->r6 = ctx->r6 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addu        $v0, $s5, $s7
    ctx->r2 = ADD32(ctx->r21, ctx->r23);
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // lhu         $t0, 0x38($sp)
    ctx->r8 = MEM_HU(0X38, ctx->r29);
    // addiu       $v0, $zero, 0x26C
    ctx->r2 = ADD32(0, 0X26C);
    // sh          $s4, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r20;
    // sh          $v0, 0x358($fp)
    MEM_H(0X358, ctx->r30) = ctx->r2;
    // sh          $t0, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r8;
    // jal         0x80028364
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    sub_80028364(rdram, ctx);
    goto after_2;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_2:
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // ori         $a0, $a0, 0x33C
    ctx->r4 = ctx->r4 | 0X33C;
    // addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    // ori         $a2, $a2, 0x35C
    ctx->r6 = ctx->r6 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $s3, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r19;
    // jal         0x80028364
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    sub_80028364(rdram, ctx);
    goto after_3;
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_3:
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // ori         $a0, $a0, 0x33C
    ctx->r4 = ctx->r4 | 0X33C;
    // addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    // ori         $a2, $a2, 0x35C
    ctx->r6 = ctx->r6 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $s3, $s4, 0x10
    ctx->r19 = ADD32(ctx->r20, 0X10);
    // addiu       $v0, $zero, 0x25C
    ctx->r2 = ADD32(0, 0X25C);
    // sh          $s5, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r21;
    // sh          $s3, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r19;
    // sh          $v0, 0x358($fp)
    MEM_H(0X358, ctx->r30) = ctx->r2;
    // jal         0x80028364
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    sub_80028364(rdram, ctx);
    goto after_4;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_4:
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // ori         $a0, $a0, 0x33C
    ctx->r4 = ctx->r4 | 0X33C;
    // addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    // ori         $a2, $a2, 0x35C
    ctx->r6 = ctx->r6 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $s0, $s0, -0x20
    ctx->r16 = ADD32(ctx->r16, -0X20);
    // sh          $s0, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r16;
    // jal         0x80028364
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    sub_80028364(rdram, ctx);
    goto after_5;
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_5:
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // ori         $a0, $a0, 0x33C
    ctx->r4 = ctx->r4 | 0X33C;
    // addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    // ori         $a2, $a2, 0x35C
    ctx->r6 = ctx->r6 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lhu         $t0, 0x38($sp)
    ctx->r8 = MEM_HU(0X38, ctx->r29);
    // addiu       $v0, $zero, 0x254
    ctx->r2 = ADD32(0, 0X254);
    // sh          $s3, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r19;
    // sh          $v0, 0x358($fp)
    MEM_H(0X358, ctx->r30) = ctx->r2;
    // sh          $t0, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r8;
    // jal         0x80028364
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    sub_80028364(rdram, ctx);
    goto after_6;
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_6:
    // addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    // ori         $a0, $a0, 0x33C
    ctx->r4 = ctx->r4 | 0X33C;
    // addu        $a1, $fp, $zero
    ctx->r5 = ADD32(ctx->r30, 0);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    // ori         $a2, $a2, 0x35C
    ctx->r6 = ctx->r6 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // sh          $s0, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r16;
    // jal         0x80028364
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    sub_80028364(rdram, ctx);
    goto after_7;
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_7:
    // sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // addiu       $v0, $s4, 0x20
    ctx->r2 = ADD32(ctx->r20, 0X20);
    // sh          $v0, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x270
    ctx->r2 = ADD32(0, 0X270);
    // sh          $s5, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r21;
    // sh          $v0, 0x358($fp)
    MEM_H(0X358, ctx->r30) = ctx->r2;
    // sh          $s7, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r23;
    // bgez        $v1, L_80029860
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $s6, 0x30($sp)
        MEM_H(0X30, ctx->r29) = ctx->r22;
        goto L_80029860;
    }
    // sh          $s6, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r22;
    // addiu       $v1, $v1, 0xF
    ctx->r3 = ADD32(ctx->r3, 0XF);
L_80029860:
    // sra         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) >> 4;
    // addiu       $s1, $v0, -0x5
    ctx->r17 = ADD32(ctx->r2, -0X5);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s1, $v0, L_800298E8
    if (ctx->r17 == ctx->r2) {
        // lui         $s0, 0x1F80
        ctx->r16 = S32(0X1F80 << 16);
        goto L_800298E8;
    }
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // lui         $s3, 0x1F80
    ctx->r19 = S32(0X1F80 << 16);
    // ori         $s3, $s3, 0x33C
    ctx->r19 = ctx->r19 | 0X33C;
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // ori         $s2, $s2, 0x358
    ctx->r18 = ctx->r18 | 0X358;
    // ori         $s0, $s0, 0x35C
    ctx->r16 = ctx->r16 | 0X35C;
    // lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(0X38, ctx->r29);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_80029890:
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    // sh          $s5, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r21;
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_8;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $s6, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r22;
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_9;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_9:
    // lhu         $v0, 0x33E($fp)
    ctx->r2 = MEM_HU(0X33E, ctx->r30);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // sh          $v0, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s1, $v0, L_80029890
    if (ctx->r17 != ctx->r2) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_80029890;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_800298E8:
    // lhu         $t0, 0x28($sp)
    ctx->r8 = MEM_HU(0X28, ctx->r29);
    // nop

    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // addiu       $v0, $s5, 0x10
    ctx->r2 = ADD32(ctx->r21, 0X10);
    // sh          $v0, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x268
    ctx->r2 = ADD32(0, 0X268);
    // bgez        $v1, L_80029910
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0x358($fp)
        MEM_H(0X358, ctx->r30) = ctx->r2;
        goto L_80029910;
    }
    // sh          $v0, 0x358($fp)
    MEM_H(0X358, ctx->r30) = ctx->r2;
    // addiu       $v1, $v1, 0xF
    ctx->r3 = ADD32(ctx->r3, 0XF);
L_80029910:
    // sra         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) >> 4;
    // addiu       $s0, $v0, -0x3
    ctx->r16 = ADD32(ctx->r2, -0X3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_80029998
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_80029998;
    }
    // nop

    // addiu       $s3, $fp, 0x33C
    ctx->r19 = ADD32(ctx->r30, 0X33C);
    // addiu       $s2, $fp, 0x358
    ctx->r18 = ADD32(ctx->r30, 0X358);
    // lhu         $t0, 0x30($sp)
    ctx->r8 = MEM_HU(0X30, ctx->r29);
    // addiu       $s1, $fp, 0x35C
    ctx->r17 = ADD32(ctx->r30, 0X35C);
    // addu        $v0, $s4, $t0
    ctx->r2 = ADD32(ctx->r20, ctx->r8);
    // addiu       $s6, $v0, -0x10
    ctx->r22 = ADD32(ctx->r2, -0X10);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_80029940:
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $s4, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r20;
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_10;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_10:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
    // sh          $s6, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r22;
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_11;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_11:
    // lhu         $v0, 0x33C($fp)
    ctx->r2 = MEM_HU(0X33C, ctx->r30);
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // sh          $v0, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_80029940
    if (ctx->r16 != ctx->r2) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_80029940;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_80029998:
    // lhu         $t0, 0x28($sp)
    ctx->r8 = MEM_HU(0X28, ctx->r29);
    // nop

    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // addiu       $v0, $s5, 0x10
    ctx->r2 = ADD32(ctx->r21, 0X10);
    // sh          $v0, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x260
    ctx->r2 = ADD32(0, 0X260);
    // bgez        $v1, L_800299C0
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0x358($fp)
        MEM_H(0X358, ctx->r30) = ctx->r2;
        goto L_800299C0;
    }
    // sh          $v0, 0x358($fp)
    MEM_H(0X358, ctx->r30) = ctx->r2;
    // addiu       $v1, $v1, 0xF
    ctx->r3 = ADD32(ctx->r3, 0XF);
L_800299C0:
    // sra         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) >> 4;
    // addiu       $s0, $v0, -0x3
    ctx->r16 = ADD32(ctx->r2, -0X3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_80029A4C
    if (ctx->r16 == ctx->r2) {
        // addiu       $s1, $fp, 0x35C
        ctx->r17 = ADD32(ctx->r30, 0X35C);
        goto L_80029A4C;
    }
    // addiu       $s1, $fp, 0x35C
    ctx->r17 = ADD32(ctx->r30, 0X35C);
    // addiu       $s7, $s4, 0x10
    ctx->r23 = ADD32(ctx->r20, 0X10);
    // addiu       $s3, $fp, 0x33C
    ctx->r19 = ADD32(ctx->r30, 0X33C);
    // addiu       $s2, $fp, 0x358
    ctx->r18 = ADD32(ctx->r30, 0X358);
    // lhu         $t0, 0x30($sp)
    ctx->r8 = MEM_HU(0X30, ctx->r29);
    // nop

    // addu        $v0, $s4, $t0
    ctx->r2 = ADD32(ctx->r20, ctx->r8);
    // addiu       $s6, $v0, -0x20
    ctx->r22 = ADD32(ctx->r2, -0X20);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_800299F4:
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $s7, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r23;
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_12;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_12:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
    // sh          $s6, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r22;
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_13;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_13:
    // lhu         $v0, 0x33C($fp)
    ctx->r2 = MEM_HU(0X33C, ctx->r30);
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // sh          $v0, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_800299F4
    if (ctx->r16 != ctx->r2) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_800299F4;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_80029A4C:
    // lhu         $t0, 0x30($sp)
    ctx->r8 = MEM_HU(0X30, ctx->r29);
    // nop

    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // addiu       $v0, $s4, 0x20
    ctx->r2 = ADD32(ctx->r20, 0X20);
    // sh          $v0, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r2;
    // addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
    // bgez        $v1, L_80029A74
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0x358($fp)
        MEM_H(0X358, ctx->r30) = ctx->r2;
        goto L_80029A74;
    }
    // sh          $v0, 0x358($fp)
    MEM_H(0X358, ctx->r30) = ctx->r2;
    // addiu       $v1, $v1, 0xF
    ctx->r3 = ADD32(ctx->r3, 0XF);
L_80029A74:
    // sra         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) >> 4;
    // addiu       $s1, $v0, -0x5
    ctx->r17 = ADD32(ctx->r2, -0X5);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s1, $v0, L_80029B0C
    if (ctx->r17 == ctx->r2) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_80029B0C;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_80029A90:
    // addiu       $v0, $s5, 0x10
    ctx->r2 = ADD32(ctx->r21, 0X10);
    // sh          $v0, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r2;
    // lhu         $t0, 0x28($sp)
    ctx->r8 = MEM_HU(0X28, ctx->r29);
    // nop

    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bgez        $v0, L_80029AB4
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80029AB4;
    }
    // nop

    // addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
L_80029AB4:
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // addiu       $s0, $v0, -0x3
    ctx->r16 = ADD32(ctx->r2, -0X3);
    // beq         $s0, $s3, L_80029AF4
    if (ctx->r16 == ctx->r19) {
        // nop
    
        goto L_80029AF4;
    }
    // nop

    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_80029AC8:
    // addiu       $a0, $fp, 0x33C
    ctx->r4 = ADD32(ctx->r30, 0X33C);
    // addiu       $a1, $fp, 0x358
    ctx->r5 = ADD32(ctx->r30, 0X358);
    // addiu       $a2, $fp, 0x35C
    ctx->r6 = ADD32(ctx->r30, 0X35C);
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // jal         0x80028364
    // sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    sub_80028364(rdram, ctx);
    goto after_14;
    // sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    after_14:
    // lhu         $v0, 0x33C($fp)
    ctx->r2 = MEM_HU(0X33C, ctx->r30);
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // bne         $s0, $s2, L_80029AC8
    if (ctx->r16 != ctx->r18) {
        // sh          $v0, 0x33C($fp)
        MEM_H(0X33C, ctx->r30) = ctx->r2;
        goto L_80029AC8;
    }
    // sh          $v0, 0x33C($fp)
    MEM_H(0X33C, ctx->r30) = ctx->r2;
L_80029AF4:
    // lhu         $v0, 0x33E($fp)
    ctx->r2 = MEM_HU(0X33E, ctx->r30);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // bne         $s1, $s3, L_80029A90
    if (ctx->r17 != ctx->r19) {
        // sh          $v0, 0x33E($fp)
        MEM_H(0X33E, ctx->r30) = ctx->r2;
        goto L_80029A90;
    }
    // sh          $v0, 0x33E($fp)
    MEM_H(0X33E, ctx->r30) = ctx->r2;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_80029B0C:
    // lhu         $t0, 0x28($sp)
    ctx->r8 = MEM_HU(0X28, ctx->r29);
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // sh          $t0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r8;
    // lhu         $t0, 0x30($sp)
    ctx->r8 = MEM_HU(0X30, ctx->r29);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // sh          $s5, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r21;
    // sh          $s4, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r20;
    // jal         0x80028220
    // sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
    sub_80028220(rdram, ctx);
    goto after_15;
    // sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
    after_15:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_16;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_16:
    // lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(0X64, ctx->r29);
    // lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(0X60, ctx->r29);
    // lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(0X5C, ctx->r29);
    // lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(0X58, ctx->r29);
    // lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(0X54, ctx->r29);
    // lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(0X50, ctx->r29);
    // lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(0X4C, ctx->r29);
    // lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(0X48, ctx->r29);
    // lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(0X44, ctx->r29);
    // lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // jr          $ra
    // nop

    return;
    // nop

;}
