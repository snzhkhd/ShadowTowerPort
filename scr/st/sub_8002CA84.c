#include "recomp.h"
#include "disable_warnings.h"

void sub_8002CA84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // jal         0x800174C4
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    ST_BeginDraw2D(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // lbu         $v1, 0x2E4($s0)
    ctx->r3 = MEM_BU(0X2E4, ctx->r16);
    // addiu       $v0, $zero, 0x48
    ctx->r2 = ADD32(0, 0X48);
    // sb          $v0, 0x300($s0)
    MEM_B(0X300, ctx->r16) = ctx->r2;
    // sb          $v0, 0x301($s0)
    MEM_B(0X301, ctx->r16) = ctx->r2;
    // sb          $v0, 0x302($s0)
    MEM_B(0X302, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x62
    ctx->r2 = ADD32(0, 0X62);
    // sb          $v0, 0x308($s0)
    MEM_B(0X308, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
    // sb          $v0, 0x309($s0)
    MEM_B(0X309, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sb          $v0, 0x30A($s0)
    MEM_B(0X30A, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sb          $v0, 0x30C($s0)
    MEM_B(0X30C, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sb          $v0, 0x30D($s0)
    MEM_B(0X30D, ctx->r16) = ctx->r2;
    // sb          $v0, 0x30E($s0)
    MEM_B(0X30E, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x39
    ctx->r2 = ADD32(0, 0X39);
    // sb          $v0, 0x30F($s0)
    MEM_B(0X30F, ctx->r16) = ctx->r2;
    // sb          $v0, 0x30B($s0)
    MEM_B(0X30B, ctx->r16) = ctx->r2;
    // sltiu       $v1, $v1, 0x10
    ctx->r3 = ctx->r3 < 0X10 ? 1 : 0;
    // beq         $v1, $zero, L_8002CB00
    if (ctx->r3 == 0) {
        // sb          $v0, 0x303($s0)
        MEM_B(0X303, ctx->r16) = ctx->r2;
        goto L_8002CB00;
    }
    // sb          $v0, 0x303($s0)
    MEM_B(0X303, ctx->r16) = ctx->r2;
    // lbu         $v1, 0x2E4($s0)
    ctx->r3 = MEM_BU(0X2E4, ctx->r16);
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // j           L_8002CB0C
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_8002CB0C;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8002CB00:
    // lbu         $v0, 0x2E4($s0)
    ctx->r2 = MEM_BU(0X2E4, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
L_8002CB0C:
    // sh          $v0, 0x360($s0)
    MEM_H(0X360, ctx->r16) = ctx->r2;
    // ori         $a0, $s0, 0x33C
    ctx->r4 = ctx->r16 | 0X33C;
    // ori         $a1, $s0, 0x358
    ctx->r5 = ctx->r16 | 0X358;
    // ori         $a2, $s0, 0x35C
    ctx->r6 = ctx->r16 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // lbu         $v1, 0x360($s0)
    ctx->r3 = MEM_BU(0X360, ctx->r16);
    // addiu       $v0, $zero, 0x240
    ctx->r2 = ADD32(0, 0X240);
    // sh          $v0, 0x358($s0)
    MEM_H(0X358, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // sh          $v0, 0x35A($s0)
    MEM_H(0X35A, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x220
    ctx->r2 = ADD32(0, 0X220);
    // sh          $v0, 0x35C($s0)
    MEM_H(0X35C, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x1FF
    ctx->r2 = ADD32(0, 0X1FF);
    // sh          $v0, 0x35E($s0)
    MEM_H(0X35E, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x51
    ctx->r2 = ADD32(0, 0X51);
    // sh          $v0, 0x33C($s0)
    MEM_H(0X33C, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    // sh          $v0, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // sh          $v0, 0x340($s0)
    MEM_H(0X340, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x342($s0)
    MEM_H(0X342, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sb          $zero, 0x32E($s0)
    MEM_B(0X32E, ctx->r16) = 0;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lbu         $v0, 0x360($s0)
    ctx->r2 = MEM_BU(0X360, ctx->r16);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // sb          $v1, 0x32C($s0)
    MEM_B(0X32C, ctx->r16) = ctx->r3;
    // jal         0x80028364
    // sb          $v0, 0x32D($s0)
    MEM_B(0X32D, ctx->r16) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_1;
    // sb          $v0, 0x32D($s0)
    MEM_B(0X32D, ctx->r16) = ctx->r2;
    after_1:
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // addiu       $v1, $zero, 0x2C
    ctx->r3 = ADD32(0, 0X2C);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // beq         $v0, $zero, L_8002CBAC
    if (ctx->r2 == 0) {
        // sh          $v1, 0x33E($s0)
        MEM_H(0X33E, ctx->r16) = ctx->r3;
        goto L_8002CBAC;
    }
    // sh          $v1, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r3;
    // j           L_8002CBB0
    // addiu       $v0, $zero, 0x24A
    ctx->r2 = ADD32(0, 0X24A);
    goto L_8002CBB0;
    // addiu       $v0, $zero, 0x24A
    ctx->r2 = ADD32(0, 0X24A);
L_8002CBAC:
    // addiu       $v0, $zero, 0x265
    ctx->r2 = ADD32(0, 0X265);
L_8002CBB0:
    // sh          $v0, 0x358($s0)
    MEM_H(0X358, ctx->r16) = ctx->r2;
    // ori         $a0, $s0, 0x33C
    ctx->r4 = ctx->r16 | 0X33C;
    // ori         $a1, $s0, 0x358
    ctx->r5 = ctx->r16 | 0X358;
    // ori         $a2, $s0, 0x35C
    ctx->r6 = ctx->r16 | 0X35C;
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sh          $v0, 0x33C($s0)
    MEM_H(0X33C, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // sh          $v0, 0x340($s0)
    MEM_H(0X340, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // lhu         $v1, 0x2DC($s0)
    ctx->r3 = MEM_HU(0X2DC, ctx->r16);
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // beq         $v1, $v0, L_8002CD38
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x81
        ctx->r2 = SIGNED(ctx->r3) < 0X81 ? 1 : 0;
        goto L_8002CD38;
    }
    // slti        $v0, $v1, 0x81
    ctx->r2 = SIGNED(ctx->r3) < 0X81 ? 1 : 0;
    // beq         $v0, $zero, L_8002CC58
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_8002CC58;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // beq         $v1, $v0, L_8002CCF8
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x9
        ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
        goto L_8002CCF8;
    }
    // slti        $v0, $v1, 0x9
    ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // beq         $v0, $zero, L_8002CC20
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8002CC20;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $v1, $v0, L_8002CCD8
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_8002CCD8;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $v1, $v0, L_8002CCE8
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
        goto L_8002CCE8;
    }
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // j           L_8002CD48
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    goto L_8002CD48;
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
L_8002CC20:
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // beq         $v1, $v0, L_8002CD18
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x21
        ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
        goto L_8002CD18;
    }
    // slti        $v0, $v1, 0x21
    ctx->r2 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    // beq         $v0, $zero, L_8002CC44
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x10
        ctx->r2 = ADD32(0, 0X10);
        goto L_8002CC44;
    }
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // beq         $v1, $v0, L_8002CD08
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
        goto L_8002CD08;
    }
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // j           L_8002CD48
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    goto L_8002CD48;
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
L_8002CC44:
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // beq         $v1, $v0, L_8002CD28
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
        goto L_8002CD28;
    }
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // j           L_8002CD48
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    goto L_8002CD48;
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
L_8002CC58:
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // beq         $v1, $v0, L_8002CD08
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x1001
        ctx->r2 = SIGNED(ctx->r3) < 0X1001 ? 1 : 0;
        goto L_8002CD08;
    }
    // slti        $v0, $v1, 0x1001
    ctx->r2 = SIGNED(ctx->r3) < 0X1001 ? 1 : 0;
    // beq         $v0, $zero, L_8002CCA0
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x400
        ctx->r2 = ADD32(0, 0X400);
        goto L_8002CCA0;
    }
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // beq         $v1, $v0, L_8002CCE8
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x401
        ctx->r2 = SIGNED(ctx->r3) < 0X401 ? 1 : 0;
        goto L_8002CCE8;
    }
    // slti        $v0, $v1, 0x401
    ctx->r2 = SIGNED(ctx->r3) < 0X401 ? 1 : 0;
    // beq         $v0, $zero, L_8002CC8C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x200
        ctx->r2 = ADD32(0, 0X200);
        goto L_8002CC8C;
    }
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // beq         $v1, $v0, L_8002CCD8
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
        goto L_8002CCD8;
    }
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // j           L_8002CD48
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    goto L_8002CD48;
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
L_8002CC8C:
    // addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // beq         $v1, $v0, L_8002CCF8
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
        goto L_8002CCF8;
    }
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // j           L_8002CD48
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    goto L_8002CD48;
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
L_8002CCA0:
    // addiu       $v0, $zero, 0x4000
    ctx->r2 = ADD32(0, 0X4000);
    // beq         $v1, $v0, L_8002CD28
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x4001
        ctx->r2 = SIGNED(ctx->r3) < 0X4001 ? 1 : 0;
        goto L_8002CD28;
    }
    // slti        $v0, $v1, 0x4001
    ctx->r2 = SIGNED(ctx->r3) < 0X4001 ? 1 : 0;
    // beq         $v0, $zero, L_8002CCC4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2000
        ctx->r2 = ADD32(0, 0X2000);
        goto L_8002CCC4;
    }
    // addiu       $v0, $zero, 0x2000
    ctx->r2 = ADD32(0, 0X2000);
    // beq         $v1, $v0, L_8002CD18
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
        goto L_8002CD18;
    }
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // j           L_8002CD48
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    goto L_8002CD48;
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
L_8002CCC4:
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // beq         $v1, $v0, L_8002CD38
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
        goto L_8002CD38;
    }
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // j           L_8002CD48
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    goto L_8002CD48;
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
L_8002CCD8:
    // jal         0x8002C090
    // nop

    sub_8002C090(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // j           L_8002CD44
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    goto L_8002CD44;
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_8002CCE8:
    // jal         0x8002C050
    // nop

    sub_8002C050(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // j           L_8002CD44
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    goto L_8002CD44;
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_8002CCF8:
    // jal         0x8002C1A4
    // nop

    sub_8002C1A4(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // j           L_8002CD44
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    goto L_8002CD44;
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_8002CD08:
    // jal         0x8002C2B8
    // nop

    sub_8002C2B8(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // j           L_8002CD44
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    goto L_8002CD44;
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_8002CD18:
    // jal         0x8002C8BC
    // nop

    sub_8002C8BC(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // j           L_8002CD44
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    goto L_8002CD44;
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_8002CD28:
    // jal         0x8002C958
    // nop

    sub_8002C958(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // j           L_8002CD44
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    goto L_8002CD44;
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_8002CD38:
    // jal         0x8002C998
    // nop

    sub_8002C998(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_8002CD44:
    // addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
L_8002CD48:
    // addiu       $a2, $zero, 0x120
    ctx->r6 = ADD32(0, 0X120);
    // jal         0x80029548
    // addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    sub_80029548(rdram, ctx);
    goto after_10;
    // addiu       $a3, $zero, 0xC0
    ctx->r7 = ADD32(0, 0XC0);
    after_10:
    // jal         0x800175A4
    // nop

    sub_800175A4(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // lhu         $v0, 0x206($s0)
    ctx->r2 = MEM_HU(0X206, ctx->r16);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v0, $v1, L_8002CD7C
    if (ctx->r2 != ctx->r3) {
        // nop
    
        goto L_8002CD7C;
    }
    // nop

    // jal         0x8002948C
    // nop

    sub_8002948C(rdram, ctx);
    goto after_12;
    // nop

    after_12:
L_8002CD7C:
    // jal         0x80017634
    // nop

    sub_80017634(rdram, ctx);
    goto after_13;
    // nop

    after_13:
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
