#include "recomp.h"
#include "disable_warnings.h"

void sub_80026AFC(uint8_t* rdram, recomp_context* ctx) 
{

    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // jal         0x80057B10
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    sub_80057B10(rdram, ctx);
    goto after_0;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x800176A8
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    sub_800176A8(rdram, ctx);
    goto after_1;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // jal         0x80016A14
    // nop

    sub_80016A14(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v1, -0x6EC0($v0)
    ctx->r3 = MEM_BU(-0X6EC0, ctx->r2);
    // nop

    // beq         $v1, $zero, L_80026B64
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_80026B64;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // beq         $v1, $v0, L_80026B64
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
        goto L_80026B64;
    }
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // beq         $v1, $v0, L_80026B64
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80026B64;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80026B6C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80026B6C;
    }
    // nop

L_80026B64:
    // jal         0x80033110
    // nop

    sub_80033110(rdram, ctx);
    goto after_3;
    // nop

    after_3:
L_80026B6C:
    // jal         0x800174C4
    // nop

    ST_BeginDraw2D(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // jal         0x800340F8
    // nop

    sub_800340F8(rdram, ctx);
    goto after_5;
    // nop

    after_5:
    // jal         0x80034FC4
    // nop

    sub_80034FC4(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $zero, 0x320($v0)
    MEM_W(0X320, ctx->r2) = 0;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v1, 0x218($a0)
    ctx->r3 = MEM_BU(0X218, ctx->r4);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80026C48
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80026C48;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lw          $a3, 0x58($gp)
    ctx->r7 = MEM_W(0X58, ctx->r28);
    // lb          $v0, 0x15E($a0)
    ctx->r2 = MEM_BS(0X15E, ctx->r4);
    // addiu       $a1, $a3, 0x1
    ctx->r5 = ADD32(ctx->r7, 0X1);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $v0, $v0, -0xA04
    ctx->r2 = ADD32(ctx->r2, -0XA04);
    // bgez        $a1, L_80026BE0
    if (SIGNED(ctx->r5) >= 0) {
        // addu        $a0, $v1, $v0
        ctx->r4 = ADD32(ctx->r3, ctx->r2);
        goto L_80026BE0;
    }
    // addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // addiu       $a2, $a3, 0x20
    ctx->r6 = ADD32(ctx->r7, 0X20);
L_80026BE0:
    // sra         $v0, $a2, 5
    ctx->r2 = S32(ctx->r6) >> 5;
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // sw          $v0, 0x58($gp)
    MEM_W(0X58, ctx->r28) = ctx->r2;
    // slti        $v0, $v0, 0x10
    ctx->r2 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_80026C08
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
        goto L_80026C08;
    }
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // lhu         $v1, 0x58($gp)
    ctx->r3 = MEM_HU(0X58, ctx->r28);
    // j           L_80026C14
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_80026C14;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80026C08:
    // lhu         $v0, 0x58($gp)
    ctx->r2 = MEM_HU(0X58, ctx->r28);
    // nop

    // addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
L_80026C14:
    // addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
    // sb          $v0, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r2;
    // jal         0x80027D18
    // sb          $v0, 0x1A($sp)
    MEM_B(0X1A, ctx->r29) = ctx->r2;
    sub_80027D18(rdram, ctx);
    goto after_7;
    // sb          $v0, 0x1A($sp)
    MEM_B(0X1A, ctx->r29) = ctx->r2;
    after_7:
    // jal         0x80026964
    // addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    sub_80026964(rdram, ctx);
    goto after_8;
    // addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_8:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_80026C48:
    // lbu         $v0, -0x2EDD($v0)
    ctx->r2 = MEM_BU(-0X2EDD, ctx->r2);
    // nop

    // beq         $v0, $zero, L_80026CFC
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80026CFC;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v0, 0x5929($v0)
    ctx->r2 = MEM_BU(0X5929, ctx->r2);
    // nop

    // sltiu       $v0, $v0, 0x2C
    ctx->r2 = ctx->r2 < 0X2C ? 1 : 0;
    // beq         $v0, $zero, L_80026CFC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026CFC;
    }
    // nop

    // jal         0x80026508
    // addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    sub_80026508(rdram, ctx);
    goto after_9;
    // addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    after_9:
    // jal         0x80026964
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80026964(rdram, ctx);
    goto after_10;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_10:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $s3, $v0, -0xC0C
    ctx->r19 = ADD32(ctx->r2, -0XC0C);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // addiu       $s2, $v0, 0x8
    ctx->r18 = ADD32(ctx->r2, 0X8);
    // addiu       $s0, $zero, 0xD0
    ctx->r16 = ADD32(0, 0XD0);
    // addiu       $s1, $v0, 0x10
    ctx->r17 = ADD32(ctx->r2, 0X10);
L_80026C98:
    // lw          $v0, 0x1EC($s1)
    ctx->r2 = MEM_W(0X1EC, ctx->r17);
    // nop

    // beq         $v0, $zero, L_80026CDC
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x20
        ctx->r5 = ADD32(0, 0X20);
        goto L_80026CDC;
    }
    // addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // sh          $s0, 0x2C4($s3)
    MEM_H(0X2C4, ctx->r19) = ctx->r16;
    // sh          $s0, 0x2B0($s3)
    MEM_H(0X2B0, ctx->r19) = ctx->r16;
    // sh          $s0, 0x29C($s3)
    MEM_H(0X29C, ctx->r19) = ctx->r16;
    // sh          $s0, 0x288($s3)
    MEM_H(0X288, ctx->r19) = ctx->r16;
    // lh          $a0, 0x20C($s2)
    ctx->r4 = MEM_HS(0X20C, ctx->r18);
    // jal         0x80026228
    // addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    sub_80026228(rdram, ctx);
    goto after_11;
    // addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_11:
    // jal         0x80026964
    // addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    sub_80026964(rdram, ctx);
    goto after_12;
    // addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_12:
    // lw          $v0, 0x1EC($s1)
    ctx->r2 = MEM_W(0X1EC, ctx->r17);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sw          $v0, 0x1EC($s1)
    MEM_W(0X1EC, ctx->r17) = ctx->r2;
L_80026CDC:
    // addiu       $s2, $s2, -0x2
    ctx->r18 = ADD32(ctx->r18, -0X2);
    // addiu       $s0, $s0, -0x10
    ctx->r16 = ADD32(ctx->r16, -0X10);
    // addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s4, $v0, L_80026C98
    if (ctx->r20 != ctx->r2) {
        // addiu       $s1, $s1, -0x4
        ctx->r17 = ADD32(ctx->r17, -0X4);
        goto L_80026C98;
    }
    // addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // jal         0x80026964
    // addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    sub_80026964(rdram, ctx);
    goto after_13;
    // addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_13:
L_80026CFC:
    // jal         0x8002181C
    // nop

    sub_8002181C(rdram, ctx);
    goto after_14;
    // nop

    after_14:
    // jal         0x800218D8
    // nop

    sub_800218D8(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // jal         0x80021654
    // nop

    sub_80021654(rdram, ctx);
    goto after_16;
    // nop

    after_16:
    // jal         0x80021AC4
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_80021AC4(rdram, ctx);
    goto after_17;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_17:
    // jal         0x80021AC4
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sub_80021AC4(rdram, ctx);
    goto after_18;
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_18:
    // jal         0x80020A80
    // nop

    sub_80020A80(rdram, ctx);
    goto after_19;
    // nop

    after_19:
    // jal         0x8001C8E0
    // nop

    sub_8001C8E0(rdram, ctx);
    goto after_20;
    // nop

    after_20:
    // jal         0x8001C9C8
    // nop

    sub_8001C9C8(rdram, ctx);
    goto after_21;
    // nop

    after_21:
    // jal         0x8001CAB8
    // nop

    sub_8001CAB8(rdram, ctx);
    goto after_22;
    // nop

    after_22:
    // jal         0x800241D0
    // nop

    sub_800241D0(rdram, ctx);
    goto after_23;
    // nop

    after_23:
    // jal         0x800246E4
    // nop

    sub_800246E4(rdram, ctx);
    goto after_24;
    // nop

    after_24:
    // jal         0x800251C8
    // nop

    sub_800251C8(rdram, ctx);
    goto after_25;
    // nop

    after_25:
    // jal         0x800255F0
    // nop

    sub_800255F0(rdram, ctx);
    goto after_26;
    // nop

    after_26:
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x6E16($s0)
    ctx->r2 = MEM_BU(0X6E16, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80026D90
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80026D90;
    }
    // nop

    // jal         0x80028784
    // nop

    sub_80028784(rdram, ctx);
    goto after_27;
    // nop

    after_27:
L_80026D90:
    // jal         0x80017680
    // nop
  
    sub_80017680(rdram, ctx);
    goto after_28;
    // nop

    after_28:
    // jal         0x8001535C
    // nop

    sub_8001535C(rdram, ctx);
    goto after_29;
    // nop

    after_29:
    // lbu         $v0, 0x6CC0($s0)
    ctx->r2 = MEM_BU(0X6CC0, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x6CC0($s0)
    MEM_B(0X6CC0, ctx->r16) = ctx->r2;
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
