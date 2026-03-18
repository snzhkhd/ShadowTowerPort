#include "recomp.h"
#include "disable_warnings.h"

void sub_80054A54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // lw          $v1, 0x248($v0)
    ctx->r3 = MEM_W(0X248, ctx->r2);
    // lw          $a0, 0x24C($v0)
    ctx->r4 = MEM_W(0X24C, ctx->r2);
    // lw          $a1, 0x250($v0)
    ctx->r5 = MEM_W(0X250, ctx->r2);
    // lw          $a2, 0x254($v0)
    ctx->r6 = MEM_W(0X254, ctx->r2);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(0X14, ctx->r29);
    // addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // sw          $v1, -0x2F20($a0)
    MEM_W(-0X2F20, ctx->r4) = ctx->r3;
    // addiu       $v1, $s3, -0x10A
    ctx->r3 = ADD32(ctx->r19, -0X10A);
    // addiu       $v0, $v0, 0x640
    ctx->r2 = ADD32(ctx->r2, 0X640);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sltiu       $v0, $v1, 0x30
    ctx->r2 = ctx->r3 < 0X30 ? 1 : 0;
    // beq         $v0, $zero, L_800551D0
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_800551D0;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x2794
    ctx->r2 = ADD32(ctx->r2, 0X2794);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_80054AD8;
    jr_addend_80054AD8 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80054AD8 >> 2) {
        case 0: goto L_800551D0; break;
        case 1: goto L_800551D0; break;
        case 2: goto L_80054AE0; break;
        case 3: goto L_80054B14; break;
        case 4: goto L_80054B58; break;
        case 5: goto L_800551D0; break;
        case 6: goto L_80054BAC; break;
        case 7: goto L_80054BAC; break;
        case 8: goto L_80054BAC; break;
        case 9: goto L_80054BAC; break;
        case 10: goto L_80054BAC; break;
        case 11: goto L_80054BAC; break;
        case 12: goto L_80054BAC; break;
        case 13: goto L_80054BAC; break;
        case 14: goto L_80054BAC; break;
        case 15: goto L_800551D0; break;
        case 16: goto L_800551D0; break;
        case 17: goto L_800551D0; break;
        case 18: goto L_80054CF4; break;
        case 19: goto L_80054D20; break;
        case 20: goto L_80054D4C; break;
        case 21: goto L_80054D80; break;
        case 22: goto L_80054DB4; break;
        case 23: goto L_800551D0; break;
        case 24: goto L_80054E00; break;
        case 25: goto L_80054E38; break;
        case 26: goto L_80054E70; break;
        case 27: goto L_80054EA8; break;
        case 28: goto L_80054EE0; break;
        case 29: goto L_80054F18; break;
        case 30: goto L_80054F50; break;
        case 31: goto L_8005513C; break;
        case 32: goto L_8005513C; break;
        case 33: goto L_8005513C; break;
        case 34: goto L_800551D0; break;
        case 35: goto L_800551D0; break;
        case 36: goto L_80054F88; break;
        case 37: goto L_8005513C; break;
        case 38: goto L_8005513C; break;
        case 39: goto L_80055160; break;
        case 40: goto L_800551D0; break;
        case 41: goto L_800551D0; break;
        case 42: goto L_800551D0; break;
        case 43: goto L_800551D0; break;
        case 44: goto L_80055184; break;
        case 45: goto L_80055194; break;
        case 46: goto L_800551A4; break;
        case 47: goto L_800551B4; break;
        default: switch_error(__func__, 0x80054AD8, 0x80012794);
    }
    // nop

L_80054AE0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lw          $a1, 0x2C($a0)
    ctx->r5 = MEM_W(0X2C, ctx->r4);
    // lui         $v0, 0x3
    ctx->r2 = S32(0X3 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // bne         $v0, $zero, L_800551D0
    if (ctx->r2 != 0) {
        // lui         $v1, 0x801D
        ctx->r3 = S32(0X801D << 16);
        goto L_800551D0;
    }
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, -0x2F20($v1)
    MEM_W(-0X2F20, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0xBB8
    ctx->r2 = ADD32(0, 0XBB8);
    // sh          $v0, 0x1A6($a0)
    MEM_H(0X1A6, ctx->r4) = ctx->r2;
    // j           L_80054B48
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    goto L_80054B48;
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
L_80054B14:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lw          $a1, 0x2C($a0)
    ctx->r5 = MEM_W(0X2C, ctx->r4);
    // lui         $v0, 0x3
    ctx->r2 = S32(0X3 << 16);
    // and         $v0, $a1, $v0
    ctx->r2 = ctx->r5 & ctx->r2;
    // bne         $v0, $zero, L_800551D4
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_800551D4;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, -0x2F20($v1)
    MEM_W(-0X2F20, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x4650
    ctx->r2 = ADD32(0, 0X4650);
    // sh          $v0, 0x1A6($a0)
    MEM_H(0X1A6, ctx->r4) = ctx->r2;
    // lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
L_80054B48:
    // or          $v0, $a1, $v0
    ctx->r2 = ctx->r5 | ctx->r2;
    // sh          $zero, 0x1A4($a0)
    MEM_H(0X1A4, ctx->r4) = 0;
    // j           L_800551D0
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
    goto L_800551D0;
    // sw          $v0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r2;
L_80054B58:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $a1, $v0, 0x5920
    ctx->r5 = ADD32(ctx->r2, 0X5920);
    // lbu         $v1, 0x9($a1)
    ctx->r3 = MEM_BU(0X9, ctx->r5);
    // addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // beq         $v1, $v0, L_800551D0
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_800551D0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v1, 0x22C($a0)
    ctx->r3 = MEM_BU(0X22C, ctx->r4);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_800551D0
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_800551D0;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
    // sw          $zero, 0x2F0($a0)
    MEM_W(0X2F0, ctx->r4) = 0;
    // sw          $zero, 0x2EC($a0)
    MEM_W(0X2EC, ctx->r4) = 0;
    // lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(0XC, ctx->r5);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, -0x2F20($v1)
    MEM_W(-0X2F20, ctx->r3) = ctx->r2;
    // lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(0X30, ctx->r4);
    // j           L_8005514C
    // nop

    goto L_8005514C;
    // nop

L_80054BAC:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // addiu       $v1, $a0, 0x5948
    ctx->r3 = ADD32(ctx->r4, 0X5948);
    // lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(0X10, ctx->r29);
    // lw          $a1, 0x14($sp)
    ctx->r5 = MEM_W(0X14, ctx->r29);
    // lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(0X18, ctx->r29);
    // lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(0X1C, ctx->r29);
    // sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // sw          $a1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r5;
    // sw          $a2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r6;
    // sw          $a3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r7;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s4, $v0, 0x2230
    ctx->r20 = ADD32(ctx->r2, 0X2230);
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $s1, $v0, -0x45F8
    ctx->r17 = ADD32(ctx->r2, -0X45F8);
    // addiu       $v0, $zero, 0x420
    ctx->r2 = ADD32(0, 0X420);
    // sh          $v0, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x640
    ctx->r2 = ADD32(0, 0X640);
    // sh          $v0, 0x1E($v1)
    MEM_H(0X1E, ctx->r3) = ctx->r2;
    // sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
    // sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // sh          $zero, 0x22($v1)
    MEM_H(0X22, ctx->r3) = 0;
    // sh          $zero, 0x20($v1)
    MEM_H(0X20, ctx->r3) = 0;
    // sw          $zero, 0x5948($a0)
    MEM_W(0X5948, ctx->r4) = 0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80054C18:
    // lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // jal         0x8004F718
    // addiu       $a1, $a1, 0x5948
    ctx->r5 = ADD32(ctx->r5, 0X5948);
    sub_8004F718(rdram, ctx);
    goto after_0;
    // addiu       $a1, $a1, 0x5948
    ctx->r5 = ADD32(ctx->r5, 0X5948);
    after_0:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_800551D0
    if (ctx->r16 == ctx->r2) {
        // sll         $a0, $s0, 1
        ctx->r4 = S32(ctx->r16) << 1;
        goto L_800551D0;
    }
    // sll         $a0, $s0, 1
    ctx->r4 = S32(ctx->r16) << 1;
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    // sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4) << 3;
    // addu        $a0, $a0, $s4
    ctx->r4 = ADD32(ctx->r4, ctx->r20);
    // jal         0x8004FB88
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    sub_8004FB88(rdram, ctx);
    goto after_1;
    // addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_1:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $s2, L_80054C90
    if (ctx->r3 == ctx->r18) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_80054C90;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_80054C74
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_80054C74;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $zero, L_80054C84
    if (ctx->r3 == 0) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80054C84;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // j           L_80054C18
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    goto L_80054C18;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80054C74:
    // beq         $v1, $v0, L_80054CE4
    if (ctx->r3 == ctx->r2) {
        // addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80054CE4;
    }
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // j           L_80054C18
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    goto L_80054C18;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_80054C84:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // j           L_800551EC
    // sw          $v0, 0x16D8($s1)
    MEM_W(0X16D8, ctx->r17) = ctx->r2;
    goto L_800551EC;
    // sw          $v0, 0x16D8($s1)
    MEM_W(0X16D8, ctx->r17) = ctx->r2;
L_80054C90:
    // addiu       $v0, $zero, 0x114
    ctx->r2 = ADD32(0, 0X114);
    // bne         $s3, $v0, L_80054CBC
    if (ctx->r19 != ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80054CBC;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v0, 0x592C($v0)
    ctx->r2 = MEM_W(0X592C, ctx->r2);
    // nop

    // lw          $v0, 0x30($v0)
    ctx->r2 = MEM_W(0X30, ctx->r2);
    // nop

    // jalr        $v0
    // ori         $a0, $s0, 0x4000
    ctx->r4 = ctx->r16 | 0X4000;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // ori         $a0, $s0, 0x4000
    ctx->r4 = ctx->r16 | 0X4000;
    after_2:
    // j           L_80054CC8
    // sw          $s2, 0x16D8($s1)
    MEM_W(0X16D8, ctx->r17) = ctx->r18;
    goto L_80054CC8;
    // sw          $s2, 0x16D8($s1)
    MEM_W(0X16D8, ctx->r17) = ctx->r18;
L_80054CBC:
    // jal         0x80057D58
    // nop

    sub_80057D58(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // sw          $s2, 0x16D8($s1)
    MEM_W(0X16D8, ctx->r17) = ctx->r18;
L_80054CC8:
    // addiu       $v0, $zero, 0x114
    ctx->r2 = ADD32(0, 0X114);
    // beq         $s3, $v0, L_800551D0
    if (ctx->r19 == ctx->r2) {
        // addiu       $v0, $zero, 0x116
        ctx->r2 = ADD32(0, 0X116);
        goto L_800551D0;
    }
    // addiu       $v0, $zero, 0x116
    ctx->r2 = ADD32(0, 0X116);
    // beq         $s3, $v0, L_800551D4
    if (ctx->r19 == ctx->r2) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_800551D4;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // j           L_800551EC
    // nop

    goto L_800551EC;
    // nop

L_80054CE4:
    // jal         0x80057CEC
    // nop

    sub_80057CEC(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // j           L_800551EC
    // sw          $s2, 0x16D8($s1)
    MEM_W(0X16D8, ctx->r17) = ctx->r18;
    goto L_800551EC;
    // sw          $s2, 0x16D8($s1)
    MEM_W(0X16D8, ctx->r17) = ctx->r18;
L_80054CF4:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a2, $v0, -0x70D8
    ctx->r6 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, -0x70D8($v0)
    ctx->r3 = MEM_HU(-0X70D8, ctx->r2);
    // lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(0X2, ctx->r6);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_800551D0
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
        goto L_800551D0;
    }
    // addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // j           L_80054DE8
    // sh          $v1, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r3;
    goto L_80054DE8;
    // sh          $v1, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r3;
L_80054D20:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lhu         $a2, 0x4($v1)
    ctx->r6 = MEM_HU(0X4, ctx->r3);
    // lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(0X6, ctx->r3);
    // nop

    // sltu        $v0, $v0, $a2
    ctx->r2 = ctx->r2 < ctx->r6 ? 1 : 0;
    // beq         $v0, $zero, L_800551D0
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
        goto L_800551D0;
    }
    // addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // j           L_80054DE8
    // sh          $a2, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r6;
    goto L_80054DE8;
    // sh          $a2, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r6;
L_80054D4C:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $a2, 0x2C($v1)
    ctx->r6 = MEM_W(0X2C, ctx->r3);
    // nop

    // andi        $v0, $a2, 0x7
    ctx->r2 = ctx->r6 & 0X7;
    // beq         $v0, $zero, L_800551D0
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
        goto L_800551D0;
    }
    // addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // addiu       $v0, $zero, -0x8
    ctx->r2 = ADD32(0, -0X8);
    // and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // sh          $zero, 0x192($v1)
    MEM_H(0X192, ctx->r3) = 0;
    // j           L_80054DE4
    // sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    goto L_80054DE4;
    // sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
L_80054D80:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $a2, 0x2C($v1)
    ctx->r6 = MEM_W(0X2C, ctx->r3);
    // nop

    // andi        $v0, $a2, 0x18
    ctx->r2 = ctx->r6 & 0X18;
    // beq         $v0, $zero, L_800551D0
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
        goto L_800551D0;
    }
    // addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // addiu       $v0, $zero, -0x19
    ctx->r2 = ADD32(0, -0X19);
    // and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // sh          $zero, 0x196($v1)
    MEM_H(0X196, ctx->r3) = 0;
    // j           L_80054DE4
    // sh          $zero, 0x194($v1)
    MEM_H(0X194, ctx->r3) = 0;
    goto L_80054DE4;
    // sh          $zero, 0x194($v1)
    MEM_H(0X194, ctx->r3) = 0;
L_80054DB4:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $a2, 0x2C($v1)
    ctx->r6 = MEM_W(0X2C, ctx->r3);
    // nop

    // andi        $v0, $a2, 0x100
    ctx->r2 = ctx->r6 & 0X100;
    // beq         $v0, $zero, L_800551D0
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x8
        ctx->r4 = ADD32(0, 0X8);
        goto L_800551D0;
    }
    // addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // addiu       $v0, $zero, -0x101
    ctx->r2 = ADD32(0, -0X101);
    // and         $v0, $a2, $v0
    ctx->r2 = ctx->r6 & ctx->r2;
    // sh          $zero, 0x1A2($v1)
    MEM_H(0X1A2, ctx->r3) = 0;
    // sh          $zero, 0x1A0($v1)
    MEM_H(0X1A0, ctx->r3) = 0;
L_80054DE4:
    // sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
L_80054DE8:
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // jal         0x800582F0
    // sw          $v0, -0x2F20($v1)
    MEM_W(-0X2F20, ctx->r3) = ctx->r2;
    sub_800582F0(rdram, ctx);
    goto after_5;
    // sw          $v0, -0x2F20($v1)
    MEM_W(-0X2F20, ctx->r3) = ctx->r2;
    after_5:
    // j           L_800551D4
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    goto L_800551D4;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_80054E00:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(0X2C, ctx->r3);
    // lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    // and         $v0, $a0, $a1
    ctx->r2 = ctx->r4 & ctx->r5;
    // bne         $v0, $zero, L_800551D0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x12C
        ctx->r2 = ADD32(0, 0X12C);
        goto L_800551D0;
    }
    // addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    // sh          $v0, 0x1AA($v1)
    MEM_H(0X1AA, ctx->r3) = ctx->r2;
    // or          $v0, $a0, $a1
    ctx->r2 = ctx->r4 | ctx->r5;
    // sh          $zero, 0x1A8($v1)
    MEM_H(0X1A8, ctx->r3) = 0;
    // sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // j           L_800551CC
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_800551CC;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80054E38:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(0X2C, ctx->r3);
    // lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    // and         $v0, $a0, $a1
    ctx->r2 = ctx->r4 & ctx->r5;
    // bne         $v0, $zero, L_800551D0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0xBB8
        ctx->r2 = ADD32(0, 0XBB8);
        goto L_800551D0;
    }
    // addiu       $v0, $zero, 0xBB8
    ctx->r2 = ADD32(0, 0XBB8);
    // sh          $v0, 0x1AE($v1)
    MEM_H(0X1AE, ctx->r3) = ctx->r2;
    // or          $v0, $a0, $a1
    ctx->r2 = ctx->r4 | ctx->r5;
    // sh          $zero, 0x1AC($v1)
    MEM_H(0X1AC, ctx->r3) = 0;
    // sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // j           L_800551CC
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_800551CC;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80054E70:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(0X2C, ctx->r3);
    // lui         $a1, 0x10
    ctx->r5 = S32(0X10 << 16);
    // and         $v0, $a0, $a1
    ctx->r2 = ctx->r4 & ctx->r5;
    // bne         $v0, $zero, L_800551D0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x258
        ctx->r2 = ADD32(0, 0X258);
        goto L_800551D0;
    }
    // addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
    // sh          $v0, 0x1B2($v1)
    MEM_H(0X1B2, ctx->r3) = ctx->r2;
    // or          $v0, $a0, $a1
    ctx->r2 = ctx->r4 | ctx->r5;
    // sh          $zero, 0x1B0($v1)
    MEM_H(0X1B0, ctx->r3) = 0;
    // sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // j           L_800551CC
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_800551CC;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80054EA8:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(0X2C, ctx->r3);
    // lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // and         $v0, $a0, $a1
    ctx->r2 = ctx->r4 & ctx->r5;
    // bne         $v0, $zero, L_800551D0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x12C
        ctx->r2 = ADD32(0, 0X12C);
        goto L_800551D0;
    }
    // addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    // sh          $v0, 0x1B6($v1)
    MEM_H(0X1B6, ctx->r3) = ctx->r2;
    // or          $v0, $a0, $a1
    ctx->r2 = ctx->r4 | ctx->r5;
    // sh          $zero, 0x1B4($v1)
    MEM_H(0X1B4, ctx->r3) = 0;
    // sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // j           L_800551CC
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_800551CC;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80054EE0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(0X2C, ctx->r3);
    // lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // and         $v0, $a0, $a1
    ctx->r2 = ctx->r4 & ctx->r5;
    // bne         $v0, $zero, L_800551D0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1770
        ctx->r2 = ADD32(0, 0X1770);
        goto L_800551D0;
    }
    // addiu       $v0, $zero, 0x1770
    ctx->r2 = ADD32(0, 0X1770);
    // sh          $v0, 0x1BA($v1)
    MEM_H(0X1BA, ctx->r3) = ctx->r2;
    // or          $v0, $a0, $a1
    ctx->r2 = ctx->r4 | ctx->r5;
    // sh          $zero, 0x1B8($v1)
    MEM_H(0X1B8, ctx->r3) = 0;
    // sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // j           L_800551CC
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_800551CC;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80054F18:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(0X2C, ctx->r3);
    // lui         $a1, 0x80
    ctx->r5 = S32(0X80 << 16);
    // and         $v0, $a0, $a1
    ctx->r2 = ctx->r4 & ctx->r5;
    // bne         $v0, $zero, L_800551D0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0xBB8
        ctx->r2 = ADD32(0, 0XBB8);
        goto L_800551D0;
    }
    // addiu       $v0, $zero, 0xBB8
    ctx->r2 = ADD32(0, 0XBB8);
    // sh          $v0, 0x1BE($v1)
    MEM_H(0X1BE, ctx->r3) = ctx->r2;
    // or          $v0, $a0, $a1
    ctx->r2 = ctx->r4 | ctx->r5;
    // sh          $zero, 0x1BC($v1)
    MEM_H(0X1BC, ctx->r3) = 0;
    // sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // j           L_800551CC
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_800551CC;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80054F50:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(0X2C, ctx->r3);
    // nop

    // andi        $v0, $a0, 0x800
    ctx->r2 = ctx->r4 & 0X800;
    // bne         $v0, $zero, L_800551D0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1770
        ctx->r2 = ADD32(0, 0X1770);
        goto L_800551D0;
    }
    // addiu       $v0, $zero, 0x1770
    ctx->r2 = ADD32(0, 0X1770);
    // sh          $v0, 0x1C2($v1)
    MEM_H(0X1C2, ctx->r3) = ctx->r2;
    // ori         $v0, $a0, 0x800
    ctx->r2 = ctx->r4 | 0X800;
    // sh          $zero, 0x1C0($v1)
    MEM_H(0X1C0, ctx->r3) = 0;
    // sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // j           L_800551CC
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_800551CC;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80054F88:
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x274C
    ctx->r6 = ADD32(ctx->r2, 0X274C);
    // addiu       $t0, $a2, 0x30
    ctx->r8 = ADD32(ctx->r6, 0X30);
L_80054F98:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_80054F98
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_80054F98;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // addiu       $a0, $a1, -0x70D8
    ctx->r4 = ADD32(ctx->r5, -0X70D8);
    // lhu         $v0, 0x6($a0)
    ctx->r2 = MEM_HU(0X6, ctx->r4);
    // nop

    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(0X4, ctx->r4);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80054FF4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80054FF4;
    }
    // nop

    // break       7
    do_break(2147831792);
L_80054FF4:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8005500C
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8005500C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8005500C
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8005500C;
    }
    // nop

    // break       6
    do_break(2147831816);
L_8005500C:
    // mflo        $v1
    ctx->r3 = lo;
    // lhu         $a0, 0x2($a0)
    ctx->r4 = MEM_HU(0X2, ctx->r4);
    // nop

    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lhu         $a0, -0x70D8($a1)
    ctx->r4 = MEM_HU(-0X70D8, ctx->r5);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // div         $zero, $v0, $a0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r4)));
    // bne         $a0, $zero, L_80055038
    if (ctx->r4 != 0) {
        // nop
    
        goto L_80055038;
    }
    // nop

    // break       7
    do_break(2147831860);
L_80055038:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a0, $at, L_80055050
    if (ctx->r4 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80055050;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80055050
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80055050;
    }
    // nop

    // break       6
    do_break(2147831884);
L_80055050:
    // mflo        $v0
    ctx->r2 = lo;
    // addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(0X20, ctx->r29);
    // addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // beq         $a0, $zero, L_8005512C
    if (ctx->r4 == 0) {
        // addu        $t0, $v0, $v1
        ctx->r8 = ADD32(ctx->r2, ctx->r3);
        goto L_8005512C;
    }
    // addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // ori         $t4, $zero, 0xFFFF
    ctx->r12 = 0 | 0XFFFF;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $t3, $v0, 0x7810
    ctx->r11 = ADD32(ctx->r2, 0X7810);
    // lui         $a3, 0x51EB
    ctx->r7 = S32(0X51EB << 16);
    // ori         $a3, $a3, 0x851F
    ctx->r7 = ctx->r7 | 0X851F;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $t2, $v0, -0x45F8
    ctx->r10 = ADD32(ctx->r2, -0X45F8);
    // addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80055088:
    // lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(0X0, ctx->r6);
    // nop

    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // beq         $v0, $t4, L_80055118
    if (ctx->r2 == ctx->r12) {
        // addu        $v1, $v0, $zero
        ctx->r3 = ADD32(ctx->r2, 0);
        goto L_80055118;
    }
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // lbu         $a1, 0x27($a0)
    ctx->r5 = MEM_BU(0X27, ctx->r4);
    // nop

    // mult        $a1, $t0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // mult        $v0, $a3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t5
    ctx->r13 = hi;
    // sra         $v1, $t5, 5
    ctx->r3 = S32(ctx->r13) >> 5;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // bne         $v1, $zero, L_800550F0
    if (ctx->r3 != 0) {
        // nop
    
        goto L_800550F0;
    }
    // nop

    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800550F0:
    // lbu         $v0, 0x28($a0)
    ctx->r2 = MEM_BU(0X28, ctx->r4);
    // nop

    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_80055110
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80055110;
    }
    // nop

    // j           L_80055114
    // sb          $a1, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r5;
    goto L_80055114;
    // sb          $a1, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r5;
L_80055110:
    // sb          $v1, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r3;
L_80055114:
    // sw          $t1, 0x16D8($t2)
    MEM_W(0X16D8, ctx->r10) = ctx->r9;
L_80055118:
    // addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // nop

    // bne         $v0, $zero, L_80055088
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80055088;
    }
    // nop

L_8005512C:
    // jal         0x8003D030
    // nop

    sub_8003D030(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // j           L_800551D4
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    goto L_800551D4;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_8005513C:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v0, 0x592C($v0)
    ctx->r2 = MEM_W(0X592C, ctx->r2);
    // nop

    // lw          $v0, 0x30($v0)
    ctx->r2 = MEM_W(0X30, ctx->r2);
L_8005514C:
    // nop

    // jalr        $v0
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_7;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_7:
    // j           L_800551D4
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    goto L_800551D4;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_80055160:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v0, 0x592C($v0)
    ctx->r2 = MEM_W(0X592C, ctx->r2);
    // nop

    // lw          $v0, 0x30($v0)
    ctx->r2 = MEM_W(0X30, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_8;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_8:
    // j           L_800551EC
    // nop

    goto L_800551EC;
    // nop

L_80055184:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // j           L_800551C0
    // addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    goto L_800551C0;
    // addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_80055194:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // j           L_800551C0
    // addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    goto L_800551C0;
    // addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
L_800551A4:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // j           L_800551C0
    // addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    goto L_800551C0;
    // addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
L_800551B4:
    // jal         0x80057CC8
    // nop

    sub_80057CC8(rdram, ctx);
    goto after_12;
    // nop

    after_12:
    // addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
L_800551C0:
    // jal         0x8005E924
    // nop

    sub_8005E924(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
L_800551CC:
    // sw          $v0, -0x2F20($v1)
    MEM_W(-0X2F20, ctx->r3) = ctx->r2;
L_800551D0:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_800551D4:
    // lw          $v1, -0x2F20($v0)
    ctx->r3 = MEM_W(-0X2F20, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_800551EC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800551EC;
    }
    // nop

    // jal         0x800552BC
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    sub_800552BC(rdram, ctx);
    goto after_14;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_14:
L_800551EC:
    // jal         0x8003EAD0
    // nop

    sub_8003EAD0(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x277C
    ctx->r6 = ADD32(ctx->r2, 0X277C);
    // lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(0X0, ctx->r6);
    // lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(0X4, ctx->r6);
    // lw          $a1, 0x8($a2)
    ctx->r5 = MEM_W(0X8, ctx->r6);
    // sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    // sw          $a1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r5;
    // lw          $v1, 0xC($a2)
    ctx->r3 = MEM_W(0XC, ctx->r6);
    // lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(0X10, ctx->r6);
    // sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    // sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $a3, $v0, 0x7590
    ctx->r7 = ADD32(ctx->r2, 0X7590);
    // ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_80055238:
    // lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(0X40, ctx->r4);
    // nop

    // lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(0X0, ctx->r3);
    // nop

    // bne         $v0, $s3, L_80055268
    if (ctx->r2 != ctx->r19) {
        // addu        $v0, $v0, $a3
        ctx->r2 = ADD32(ctx->r2, ctx->r7);
        goto L_80055268;
    }
    // addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // bne         $v0, $zero, L_80055268
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80055268;
    }
    // nop

    // sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
L_80055268:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x5
    ctx->r2 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_80055238
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_80055238;
    }
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(0X7C, ctx->r29);
    // lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(0X78, ctx->r29);
    // lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(0X74, ctx->r29);
    // lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(0X70, ctx->r29);
    // lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(0X6C, ctx->r29);
    // lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(0X68, ctx->r29);
    // addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // jr          $ra
    // nop

    return;
    // nop

;}
