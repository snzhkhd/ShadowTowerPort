#include "recomp.h"
#include "disable_warnings.h"

void sub_8002D1DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // lhu         $v1, 0x2DC($s2)
    ctx->r3 = MEM_HU(0X2DC, ctx->r18);
    // addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    // sh          $v0, 0x33C($s2)
    MEM_H(0X33C, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // sh          $v0, 0x33E($s2)
    MEM_H(0X33E, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x342($s2)
    MEM_H(0X342, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x35C($s2)
    MEM_H(0X35C, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1FF
    ctx->r2 = ADD32(0, 0X1FF);
    // sh          $v0, 0x35E($s2)
    MEM_H(0X35E, ctx->r18) = ctx->r2;
    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // beq         $v0, $zero, L_8002D2AC
    if (ctx->r2 == 0) {
        // addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
        goto L_8002D2AC;
    }
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // ori         $a0, $a0, 0x33C
    ctx->r4 = ctx->r4 | 0X33C;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // ori         $a2, $a2, 0x35C
    ctx->r6 = ctx->r6 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // sh          $v0, 0x340($s2)
    MEM_H(0X340, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x277
    ctx->r2 = ADD32(0, 0X277);
    // sh          $v0, 0x358($s2)
    MEM_H(0X358, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1D0
    ctx->r2 = ADD32(0, 0X1D0);
    // addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // sh          $v0, 0x35A($s2)
    MEM_H(0X35A, ctx->r18) = ctx->r2;
    // jal         0x80028364
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80028364(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // ori         $a0, $a0, 0x33C
    ctx->r4 = ctx->r4 | 0X33C;
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // ori         $a1, $a1, 0x358
    ctx->r5 = ctx->r5 | 0X358;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // ori         $a2, $a2, 0x35C
    ctx->r6 = ctx->r6 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lhu         $v1, 0x33C($s2)
    ctx->r3 = MEM_HU(0X33C, ctx->r18);
    // addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
    // sh          $v0, 0x340($s2)
    MEM_H(0X340, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x270
    ctx->r2 = ADD32(0, 0X270);
    // sh          $v0, 0x358($s2)
    MEM_H(0X358, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // sh          $v0, 0x35A($s2)
    MEM_H(0X35A, ctx->r18) = ctx->r2;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // j           L_8002D4C4
    // addiu       $v1, $v1, 0x25
    ctx->r3 = ADD32(ctx->r3, 0X25);
    goto L_8002D4C4;
    // addiu       $v1, $v1, 0x25
    ctx->r3 = ADD32(ctx->r3, 0X25);
L_8002D2AC:
    // andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // beq         $v0, $zero, L_8002D374
    if (ctx->r2 == 0) {
        // lui         $a0, 0x1F80
        ctx->r4 = S32(0X1F80 << 16);
        goto L_8002D374;
    }
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
    // addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // sh          $v0, 0x340($s2)
    MEM_H(0X340, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x24C
    ctx->r2 = ADD32(0, 0X24C);
    // addiu       $s1, $zero, 0x1D0
    ctx->r17 = ADD32(0, 0X1D0);
    // addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // sh          $v0, 0x358($s2)
    MEM_H(0X358, ctx->r18) = ctx->r2;
    // sh          $s1, 0x35A($s2)
    MEM_H(0X35A, ctx->r18) = ctx->r17;
    // jal         0x80028364
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80028364(rdram, ctx);
    goto after_1;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_1:
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
    // addiu       $v0, $zero, 0x99
    ctx->r2 = ADD32(0, 0X99);
    // sh          $v0, 0x33C($s2)
    MEM_H(0X33C, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x36
    ctx->r2 = ADD32(0, 0X36);
    // sh          $v0, 0x340($s2)
    MEM_H(0X340, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x269
    ctx->r2 = ADD32(0, 0X269);
    // sh          $v0, 0x358($s2)
    MEM_H(0X358, ctx->r18) = ctx->r2;
    // sh          $s1, 0x35A($s2)
    MEM_H(0X35A, ctx->r18) = ctx->r17;
    // jal         0x80028364
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80028364(rdram, ctx);
    goto after_2;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
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
    // addiu       $v0, $zero, 0x83
    ctx->r2 = ADD32(0, 0X83);
    // sh          $v0, 0x33C($s2)
    MEM_H(0X33C, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // sh          $v0, 0x340($s2)
    MEM_H(0X340, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x264
    ctx->r2 = ADD32(0, 0X264);
    // sh          $v0, 0x358($s2)
    MEM_H(0X358, ctx->r18) = ctx->r2;
    // sh          $s1, 0x35A($s2)
    MEM_H(0X35A, ctx->r18) = ctx->r17;
    // j           L_8002D4C8
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    goto L_8002D4C8;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_8002D374:
    // andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // beq         $v0, $zero, L_8002D43C
    if (ctx->r2 == 0) {
        // ori         $a0, $a0, 0x33C
        ctx->r4 = ctx->r4 | 0X33C;
        goto L_8002D43C;
    }
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
    // addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // sh          $v0, 0x340($s2)
    MEM_H(0X340, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x24C
    ctx->r2 = ADD32(0, 0X24C);
    // addiu       $s1, $zero, 0x1D0
    ctx->r17 = ADD32(0, 0X1D0);
    // addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // sh          $v0, 0x358($s2)
    MEM_H(0X358, ctx->r18) = ctx->r2;
    // sh          $s1, 0x35A($s2)
    MEM_H(0X35A, ctx->r18) = ctx->r17;
    // jal         0x80028364
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80028364(rdram, ctx);
    goto after_3;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_3:
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
    // addiu       $v0, $zero, 0x99
    ctx->r2 = ADD32(0, 0X99);
    // sh          $v0, 0x33C($s2)
    MEM_H(0X33C, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x36
    ctx->r2 = ADD32(0, 0X36);
    // sh          $v0, 0x340($s2)
    MEM_H(0X340, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x269
    ctx->r2 = ADD32(0, 0X269);
    // sh          $v0, 0x358($s2)
    MEM_H(0X358, ctx->r18) = ctx->r2;
    // sh          $s1, 0x35A($s2)
    MEM_H(0X35A, ctx->r18) = ctx->r17;
    // jal         0x80028364
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80028364(rdram, ctx);
    goto after_4;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_4:
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
    // addiu       $v0, $zero, 0x82
    ctx->r2 = ADD32(0, 0X82);
    // sh          $v0, 0x33C($s2)
    MEM_H(0X33C, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // sh          $v0, 0x340($s2)
    MEM_H(0X340, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x24F
    ctx->r2 = ADD32(0, 0X24F);
    // sh          $v0, 0x358($s2)
    MEM_H(0X358, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1B0
    ctx->r2 = ADD32(0, 0X1B0);
    // sh          $v0, 0x35A($s2)
    MEM_H(0X35A, ctx->r18) = ctx->r2;
    // j           L_8002D4C8
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    goto L_8002D4C8;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_8002D43C:
    // andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // beq         $v0, $zero, L_8002D4D0
    if (ctx->r2 == 0) {
        // lui         $a0, 0x1F80
        ctx->r4 = S32(0X1F80 << 16);
        goto L_8002D4D0;
    }
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
    // addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // sh          $v0, 0x340($s2)
    MEM_H(0X340, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x240
    ctx->r2 = ADD32(0, 0X240);
    // sh          $v0, 0x358($s2)
    MEM_H(0X358, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1E0
    ctx->r2 = ADD32(0, 0X1E0);
    // addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // sh          $v0, 0x35A($s2)
    MEM_H(0X35A, ctx->r18) = ctx->r2;
    // jal         0x80028364
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_80028364(rdram, ctx);
    goto after_5;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_5:
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
    // lhu         $v1, 0x33C($s2)
    ctx->r3 = MEM_HU(0X33C, ctx->r18);
    // addiu       $v0, $zero, 0x24
    ctx->r2 = ADD32(0, 0X24);
    // sh          $v0, 0x340($s2)
    MEM_H(0X340, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x270
    ctx->r2 = ADD32(0, 0X270);
    // sh          $v0, 0x358($s2)
    MEM_H(0X358, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // sh          $v0, 0x35A($s2)
    MEM_H(0X35A, ctx->r18) = ctx->r2;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addiu       $v1, $v1, 0x3F
    ctx->r3 = ADD32(ctx->r3, 0X3F);
L_8002D4C4:
    // sh          $v1, 0x33C($s2)
    MEM_H(0X33C, ctx->r18) = ctx->r3;
L_8002D4C8:
    // jal         0x80028364
    // nop

    sub_80028364(rdram, ctx);
    goto after_6;
    // nop

    after_6:
L_8002D4D0:
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // addiu       $a2, $zero, 0x120
    ctx->r6 = ADD32(0, 0X120);
    // jal         0x80029618
    // addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    sub_80029618(rdram, ctx);
    goto after_7;
    // addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    after_7:
    // lhu         $v0, 0x2DC($s2)
    ctx->r2 = MEM_HU(0X2DC, ctx->r18);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8002D558
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8008
        ctx->r2 = S32(0X8008 << 16);
        goto L_8002D558;
    }
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F1C
    ctx->r6 = ADD32(ctx->r2, 0X7F1C);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r3);
    // swr         $v1, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r3);
    // swl         $a0, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r4);
    // swr         $a0, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r4);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F60
    ctx->r6 = ADD32(ctx->r2, 0X7F60);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r3);
    // swr         $v1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r3);
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // jal         0x80028220
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sub_80028220(rdram, ctx);
    goto after_8;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_9;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_9:
L_8002D558:
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
