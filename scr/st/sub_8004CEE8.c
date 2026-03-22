#include "recomp.h"
#include "disable_warnings.h"

void sub_8004CEE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $fp, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r30;
    // addu        $fp, $a1, $zero
    ctx->r30 = ADD32(ctx->r5, 0);
    // sw          $s7, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r23;
    // addu        $s7, $a2, $zero
    ctx->r23 = ADD32(ctx->r6, 0);
    // addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sw          $ra, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r31;
    // sw          $s6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r22;
    // sw          $s5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r21;
    // sw          $s4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r20;
    // sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // lbu         $v0, 0x2($s3)
    ctx->r2 = MEM_BU(0X2, ctx->r19);
    // addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3) << 6;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x29C8
    ctx->r2 = ADD32(ctx->r2, -0X29C8);
    // jal         0x80078AB4
    // addu        $s5, $v1, $v0
    ctx->r21 = ADD32(ctx->r3, ctx->r2);
    memset_recomp(rdram, ctx);
    goto after_0;
    // addu        $s5, $v1, $v0
    ctx->r21 = ADD32(ctx->r3, ctx->r2);
    after_0:
    // addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    memset_recomp(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_1:
    // lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(0X0, ctx->r23);
    // nop

    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // lw          $v0, 0x4($s7)
    ctx->r2 = MEM_W(0X4, ctx->r23);
    // nop

    // sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // lw          $v0, 0x8($s7)
    ctx->r2 = MEM_W(0X8, ctx->r23);
    // addiu       $v1, $fp, -0x30
    ctx->r3 = ADD32(ctx->r30, -0X30);
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s6, $v0, -0x6E90
    ctx->r22 = ADD32(ctx->r2, -0X6E90);
    // sltiu       $v0, $v1, 0xC7
    ctx->r2 = ctx->r3 < 0XC7 ? 1 : 0;
    // beq         $v0, $zero, L_8004D728
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_8004D728;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x22B4
    ctx->r2 = ADD32(ctx->r2, 0X22B4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_8004CFA8;
    jr_addend_8004CFA8 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8004CFA8 >> 2) {
        case 0: goto L_8004CFB0; break;
        case 1: goto L_8004D430; break;
        case 2: goto L_8004D430; break;
        case 3: goto L_8004D530; break;
        case 4: goto L_8004D530; break;
        case 5: goto L_8004D728; break;
        case 6: goto L_8004D530; break;
        case 7: goto L_8004D530; break;
        case 8: goto L_8004CFB0; break;
        case 9: goto L_8004D530; break;
        case 10: goto L_8004D050; break;
        case 11: goto L_8004D650; break;
        case 12: goto L_8004D530; break;
        case 13: goto L_8004D728; break;
        case 14: goto L_8004D0F8; break;
        case 15: goto L_8004D728; break;
        case 16: goto L_8004D1FC; break;
        case 17: goto L_8004D2B0; break;
        case 18: goto L_8004D728; break;
        case 19: goto L_8004D530; break;
        case 20: goto L_8004D658; break;
        case 21: goto L_8004D530; break;
        case 22: goto L_8004D728; break;
        case 23: goto L_8004D4B8; break;
        case 24: goto L_8004D0F8; break;
        case 25: goto L_8004D728; break;
        case 26: goto L_8004D530; break;
        case 27: goto L_8004D530; break;
        case 28: goto L_8004D660; break;
        case 29: goto L_8004D530; break;
        case 30: goto L_8004D658; break;
        case 31: goto L_8004D530; break;
        case 32: goto L_8004D650; break;
        case 33: goto L_8004D530; break;
        case 34: goto L_8004D728; break;
        case 35: goto L_8004D728; break;
        case 36: goto L_8004D650; break;
        case 37: goto L_8004D3B8; break;
        case 38: goto L_8004D318; break;
        case 39: goto L_8004D198; break;
        case 40: goto L_8004D24C; break;
        case 41: goto L_8004D3B8; break;
        case 42: goto L_8004D728; break;
        case 43: goto L_8004D728; break;
        case 44: goto L_8004D24C; break;
        case 45: goto L_8004D1FC; break;
        case 46: goto L_8004D0F8; break;
        case 47: goto L_8004D318; break;
        case 48: goto L_8004D530; break;
        case 49: goto L_8004D198; break;
        case 50: goto L_8004D24C; break;
        case 51: goto L_8004D24C; break;
        case 52: goto L_8004D728; break;
        case 53: goto L_8004D1FC; break;
        case 54: goto L_8004CFB0; break;
        case 55: goto L_8004D24C; break;
        case 56: goto L_8004D198; break;
        case 57: goto L_8004D1FC; break;
        case 58: goto L_8004D430; break;
        case 59: goto L_8004D4B8; break;
        case 60: goto L_8004D0F8; break;
        case 61: goto L_8004D728; break;
        case 62: goto L_8004D530; break;
        case 63: goto L_8004D530; break;
        case 64: goto L_8004D318; break;
        case 65: goto L_8004D0F8; break;
        case 66: goto L_8004D728; break;
        case 67: goto L_8004D530; break;
        case 68: goto L_8004D198; break;
        case 69: goto L_8004D1FC; break;
        case 70: goto L_8004D1FC; break;
        case 71: goto L_8004D1FC; break;
        case 72: goto L_8004D1FC; break;
        case 73: goto L_8004D1FC; break;
        case 74: goto L_8004D0F8; break;
        case 75: goto L_8004D728; break;
        case 76: goto L_8004D6AC; break;
        case 77: goto L_8004CFB0; break;
        case 78: goto L_8004D728; break;
        case 79: goto L_8004D530; break;
        case 80: goto L_8004D1FC; break;
        case 81: goto L_8004D728; break;
        case 82: goto L_8004D728; break;
        case 83: goto L_8004D6AC; break;
        case 84: goto L_8004D6AC; break;
        case 85: goto L_8004D530; break;
        case 86: goto L_8004D728; break;
        case 87: goto L_8004D530; break;
        case 88: goto L_8004D1FC; break;
        case 89: goto L_8004D0F8; break;
        case 90: goto L_8004D728; break;
        case 91: goto L_8004D1FC; break;
        case 92: goto L_8004D24C; break;
        case 93: goto L_8004D728; break;
        case 94: goto L_8004D6AC; break;
        case 95: goto L_8004D530; break;
        case 96: goto L_8004D530; break;
        case 97: goto L_8004D6AC; break;
        case 98: goto L_8004D530; break;
        case 99: goto L_8004D0F8; break;
        case 100: goto L_8004D728; break;
        case 101: goto L_8004D24C; break;
        case 102: goto L_8004D6AC; break;
        case 103: goto L_8004D3B8; break;
        case 104: goto L_8004D530; break;
        case 105: goto L_8004D530; break;
        case 106: goto L_8004D684; break;
        case 107: goto L_8004D4B8; break;
        case 108: goto L_8004D24C; break;
        case 109: goto L_8004D530; break;
        case 110: goto L_8004D24C; break;
        case 111: goto L_8004D530; break;
        case 112: goto L_8004D6AC; break;
        case 113: goto L_8004CFB0; break;
        case 114: goto L_8004D1FC; break;
        case 115: goto L_8004D4B8; break;
        case 116: goto L_8004D1FC; break;
        case 117: goto L_8004D530; break;
        case 118: goto L_8004D1FC; break;
        case 119: goto L_8004D6AC; break;
        case 120: goto L_8004D1FC; break;
        case 121: goto L_8004D6AC; break;
        case 122: goto L_8004D728; break;
        case 123: goto L_8004D728; break;
        case 124: goto L_8004D728; break;
        case 125: goto L_8004D728; break;
        case 126: goto L_8004D728; break;
        case 127: goto L_8004D728; break;
        case 128: goto L_8004D728; break;
        case 129: goto L_8004D728; break;
        case 130: goto L_8004D728; break;
        case 131: goto L_8004D728; break;
        case 132: goto L_8004D728; break;
        case 133: goto L_8004D728; break;
        case 134: goto L_8004D728; break;
        case 135: goto L_8004D728; break;
        case 136: goto L_8004D728; break;
        case 137: goto L_8004D728; break;
        case 138: goto L_8004D728; break;
        case 139: goto L_8004D728; break;
        case 140: goto L_8004D728; break;
        case 141: goto L_8004D728; break;
        case 142: goto L_8004D728; break;
        case 143: goto L_8004D728; break;
        case 144: goto L_8004D728; break;
        case 145: goto L_8004D728; break;
        case 146: goto L_8004D728; break;
        case 147: goto L_8004D728; break;
        case 148: goto L_8004D728; break;
        case 149: goto L_8004D728; break;
        case 150: goto L_8004D728; break;
        case 151: goto L_8004D728; break;
        case 152: goto L_8004D5D0; break;
        case 153: goto L_8004D728; break;
        case 154: goto L_8004D5D0; break;
        case 155: goto L_8004D728; break;
        case 156: goto L_8004D728; break;
        case 157: goto L_8004D5D0; break;
        case 158: goto L_8004D728; break;
        case 159: goto L_8004D728; break;
        case 160: goto L_8004D5D0; break;
        case 161: goto L_8004D728; break;
        case 162: goto L_8004D728; break;
        case 163: goto L_8004D5D0; break;
        case 164: goto L_8004D728; break;
        case 165: goto L_8004D728; break;
        case 166: goto L_8004D728; break;
        case 167: goto L_8004D728; break;
        case 168: goto L_8004D5D0; break;
        case 169: goto L_8004D728; break;
        case 170: goto L_8004D728; break;
        case 171: goto L_8004D5D0; break;
        case 172: goto L_8004D728; break;
        case 173: goto L_8004D728; break;
        case 174: goto L_8004D5D0; break;
        case 175: goto L_8004D728; break;
        case 176: goto L_8004D728; break;
        case 177: goto L_8004D5D0; break;
        case 178: goto L_8004D728; break;
        case 179: goto L_8004D728; break;
        case 180: goto L_8004D5D0; break;
        case 181: goto L_8004D728; break;
        case 182: goto L_8004D5D0; break;
        case 183: goto L_8004D728; break;
        case 184: goto L_8004D728; break;
        case 185: goto L_8004D728; break;
        case 186: goto L_8004D728; break;
        case 187: goto L_8004D5D0; break;
        case 188: goto L_8004D728; break;
        case 189: goto L_8004D728; break;
        case 190: goto L_8004D5D0; break;
        case 191: goto L_8004D728; break;
        case 192: goto L_8004D684; break;
        case 193: goto L_8004D684; break;
        case 194: goto L_8004D684; break;
        case 195: goto L_8004D684; break;
        case 196: goto L_8004D684; break;
        case 197: goto L_8004D684; break;
        case 198: goto L_8004D668; break;
        default: switch_error(__func__, 0x8004CFA8, 0x800122B4);
    }
    // nop

L_8004CFB0:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addiu       $s4, $sp, 0x38
    ctx->r20 = ADD32(ctx->r29, 0X38);
    // addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // addiu       $s1, $zero, 0x100
    ctx->r17 = ADD32(0, 0X100);
L_8004CFC0:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // jal         0x8004CC70
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sub_8004CC70(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // sh          $zero, 0x40($sp)
    MEM_H(0X40, ctx->r29) = 0;
    // sh          $zero, 0x44($sp)
    MEM_H(0X44, ctx->r29) = 0;
    // lbu         $a0, 0x8($s5)
    ctx->r4 = MEM_BU(0X8, ctx->r21);
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lbu         $v0, 0xB($s3)
    ctx->r2 = MEM_BU(0XB, ctx->r19);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_3;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_8004D038
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8004D038;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
L_8004D038:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x3
    ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_8004CFC0
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x40
        ctx->r17 = ADD32(ctx->r17, 0X40);
        goto L_8004CFC0;
    }
    // addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // j           L_8004D728
    // nop

    goto L_8004D728;
    // nop

L_8004D050:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    // addiu       $s4, $sp, 0x40
    ctx->r20 = ADD32(ctx->r29, 0X40);
    // addiu       $s1, $zero, 0x200
    ctx->r17 = ADD32(0, 0X200);
L_8004D060:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // jal         0x8004CC70
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sub_8004CC70(rdram, ctx);
    goto after_4;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_4:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // jal         0x8004CBA0
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    sub_8004CBA0(rdram, ctx);
    goto after_5;
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    after_5:
    // addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // lbu         $a0, 0x8($s5)
    ctx->r4 = MEM_BU(0X8, ctx->r21);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // lbu         $v0, 0xB($s3)
    ctx->r2 = MEM_BU(0XB, ctx->r19);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_6;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_6:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_8004D0E0
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8004D0E0;
    }
    // nop

    // sb          $zero, 0x8($v1)
    MEM_B(0X8, ctx->r3) = 0;
L_8004D0E0:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x3
    ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_8004D060
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, 0x80
        ctx->r17 = ADD32(ctx->r17, 0X80);
        goto L_8004D060;
    }
    // addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // j           L_8004D728
    // nop

    goto L_8004D728;
    // nop

L_8004D0F8:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_8004D108:
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // jal         0x8004CC70
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sub_8004CC70(rdram, ctx);
    goto after_7;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_7:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // jal         0x8004CBA0
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    sub_8004CBA0(rdram, ctx);
    goto after_8;
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    after_8:
    // addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // lbu         $a0, 0x8($s5)
    ctx->r4 = MEM_BU(0X8, ctx->r21);
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lbu         $v0, 0xB($s3)
    ctx->r2 = MEM_BU(0XB, ctx->r19);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_9;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_9:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_8004D184
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8004D184;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
L_8004D184:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // blez        $s0, L_8004D108
    if (SIGNED(ctx->r16) <= 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_8004D108;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // j           L_8004D728
    // nop

    goto L_8004D728;
    // nop

L_8004D198:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x8004CC70
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sub_8004CC70(rdram, ctx);
    goto after_10;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_10:
    // addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // lbu         $a0, 0x8($s5)
    ctx->r4 = MEM_BU(0X8, ctx->r21);
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xB($s3)
    ctx->r2 = MEM_BU(0XB, ctx->r19);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // j           L_8004D710
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    goto L_8004D710;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_8004D1FC:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x8004CC70
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sub_8004CC70(rdram, ctx);
    goto after_11;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_11:
    // addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // lbu         $a0, 0x8($s5)
    ctx->r4 = MEM_BU(0X8, ctx->r21);
    // j           L_8004D6F8
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    goto L_8004D6F8;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
L_8004D24C:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x8004CC70
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sub_8004CC70(rdram, ctx);
    goto after_12;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_12:
    // addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // lbu         $a0, 0x8($s5)
    ctx->r4 = MEM_BU(0X8, ctx->r21);
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xB($s3)
    ctx->r2 = MEM_BU(0XB, ctx->r19);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // j           L_8004D710
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    goto L_8004D710;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_8004D2B0:
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x8004CA90
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_8004CA90(rdram, ctx);
    goto after_13;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_13:
    // addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // sh          $zero, 0x40($sp)
    MEM_H(0X40, ctx->r29) = 0;
    // sh          $zero, 0x42($sp)
    MEM_H(0X42, ctx->r29) = 0;
    // sh          $zero, 0x44($sp)
    MEM_H(0X44, ctx->r29) = 0;
    // lbu         $a0, 0x8($s5)
    ctx->r4 = MEM_BU(0X8, ctx->r21);
    // addiu       $v0, $zero, 0x600
    ctx->r2 = ADD32(0, 0X600);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xB($s3)
    ctx->r2 = MEM_BU(0XB, ctx->r19);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_14;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_14:
    // j           L_8004D640
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    goto L_8004D640;
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8004D318:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_8004D324:
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // jal         0x8004CC70
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sub_8004CC70(rdram, ctx);
    goto after_15;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_15:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // jal         0x8004CBA0
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    sub_8004CBA0(rdram, ctx);
    goto after_16;
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    after_16:
    // addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // lbu         $a0, 0x8($s5)
    ctx->r4 = MEM_BU(0X8, ctx->r21);
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xB($s3)
    ctx->r2 = MEM_BU(0XB, ctx->r19);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // jal         0x80036484
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_17;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_17:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_8004D3A0
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8004D3A0;
    }
    // nop

    // sb          $zero, 0x8($v1)
    MEM_B(0X8, ctx->r3) = 0;
L_8004D3A0:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_8004D324
    if (ctx->r2 != 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_8004D324;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // j           L_8004D728
    // nop

    goto L_8004D728;
    // nop

L_8004D3B8:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // jal         0x8004CC70
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sub_8004CC70(rdram, ctx);
    goto after_18;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_18:
    // addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // lbu         $a0, 0x8($s5)
    ctx->r4 = MEM_BU(0X8, ctx->r21);
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xB($s3)
    ctx->r2 = MEM_BU(0XB, ctx->r19);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // jal         0x80036484
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_19;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_19:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_8004D728
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8004D728;
    }
    // nop

    // j           L_8004D728
    // sh          $zero, 0x42($v1)
    MEM_H(0X42, ctx->r3) = 0;
    goto L_8004D728;
    // sh          $zero, 0x42($v1)
    MEM_H(0X42, ctx->r3) = 0;
L_8004D430:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8004D43C:
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // lhu         $v0, 0x30($s3)
    ctx->r2 = MEM_HU(0X30, ctx->r19);
    // addiu       $v1, $zero, -0x30
    ctx->r3 = ADD32(0, -0X30);
    // sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // jal         0x8004CA90
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_8004CA90(rdram, ctx);
    goto after_20;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_20:
    // addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // lbu         $a0, 0x8($s5)
    ctx->r4 = MEM_BU(0X8, ctx->r21);
    // addiu       $v0, $zero, 0x600
    ctx->r2 = ADD32(0, 0X600);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xB($s3)
    ctx->r2 = MEM_BU(0XB, ctx->r19);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // jal         0x80036484
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_21;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_21:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_8004D4A0
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8004D4A0;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
L_8004D4A0:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_8004D43C
    if (ctx->r2 != 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8004D43C;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // j           L_8004D728
    // nop

    goto L_8004D728;
    // nop

L_8004D4B8:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8004D4C4:
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // addiu       $v0, $zero, -0x30
    ctx->r2 = ADD32(0, -0X30);
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // jal         0x8004CA90
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_8004CA90(rdram, ctx);
    goto after_22;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_22:
    // addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // lbu         $a0, 0x8($s5)
    ctx->r4 = MEM_BU(0X8, ctx->r21);
    // addiu       $v0, $zero, 0x600
    ctx->r2 = ADD32(0, 0X600);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xB($s3)
    ctx->r2 = MEM_BU(0XB, ctx->r19);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // jal         0x80036484
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_23;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_23:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_8004D518
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8004D518;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
L_8004D518:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_8004D4C4
    if (ctx->r2 != 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8004D4C4;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // j           L_8004D728
    // nop

    goto L_8004D728;
    // nop

L_8004D530:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_8004D53C:
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // jal         0x8004CC70
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sub_8004CC70(rdram, ctx);
    goto after_24;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_24:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // jal         0x8004CBA0
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    sub_8004CBA0(rdram, ctx);
    goto after_25;
    // addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    after_25:
    // addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // lbu         $a0, 0x8($s5)
    ctx->r4 = MEM_BU(0X8, ctx->r21);
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lbu         $v0, 0xB($s3)
    ctx->r2 = MEM_BU(0XB, ctx->r19);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // jal         0x80036484
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_26;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_26:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_8004D5B8
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8004D5B8;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
L_8004D5B8:
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_8004D53C
    if (ctx->r2 != 0) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_8004D53C;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // j           L_8004D728
    // nop

    goto L_8004D728;
    // nop

L_8004D5D0:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // addiu       $a2, $zero, 0x300
    ctx->r6 = ADD32(0, 0X300);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x8004CC70
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sub_8004CC70(rdram, ctx);
    goto after_27;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_27:
    // addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // lbu         $a0, 0x8($s5)
    ctx->r4 = MEM_BU(0X8, ctx->r21);
    // addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // lbu         $v0, 0xB($s3)
    ctx->r2 = MEM_BU(0XB, ctx->r19);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_28;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_28:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_8004D640:
    // beq         $v1, $zero, L_8004D728
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8004D728;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // j           L_8004D728
    // sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
    goto L_8004D728;
    // sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
L_8004D650:
    // j           L_8004D66C
    // addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    goto L_8004D66C;
    // addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
L_8004D658:
    // j           L_8004D66C
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    goto L_8004D66C;
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
L_8004D660:
    // j           L_8004D66C
    // addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    goto L_8004D66C;
    // addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
L_8004D668:
    // addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
L_8004D66C:
    // addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // jal         0x8003DBE0
    // addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    sub_8003DBE0(rdram, ctx);
    goto after_29;
    // addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    after_29:
    // j           L_8004D728
    // nop

    goto L_8004D728;
    // nop

L_8004D684:
    // addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // lbu         $a0, 0x8($s5)
    ctx->r4 = MEM_BU(0X8, ctx->r21);
    // addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // jal         0x80036484
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    sub_80036484(rdram, ctx);
    goto after_30;
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_30:
    // j           L_8004D728
    // nop

    goto L_8004D728;
    // nop

L_8004D6AC:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // jal         0x8004CC70
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sub_8004CC70(rdram, ctx);
    goto after_31;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_31:
    // addiu       $a1, $zero, 0x81
    ctx->r5 = ADD32(0, 0X81);
    // andi        $a2, $fp, 0xFF
    ctx->r6 = ctx->r30 & 0XFF;
    // lbu         $a0, 0x8($s5)
    ctx->r4 = MEM_BU(0X8, ctx->r21);
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
L_8004D6F8:
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // lbu         $v0, 0xB($s3)
    ctx->r2 = MEM_BU(0XB, ctx->r19);
    // addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_8004D710:
    // jal         0x80036484
    // nop

    sub_80036484(rdram, ctx);
    goto after_32;
    // nop

    after_32:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_8004D728
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8004D728;
    }
    // nop

    // sb          $zero, 0x8($v1)
    MEM_B(0X8, ctx->r3) = 0;
L_8004D728:
    // lw          $ra, 0x94($sp)
    ctx->r31 = MEM_W(0X94, ctx->r29);
    // lw          $fp, 0x90($sp)
    ctx->r30 = MEM_W(0X90, ctx->r29);
    // lw          $s7, 0x8C($sp)
    ctx->r23 = MEM_W(0X8C, ctx->r29);
    // lw          $s6, 0x88($sp)
    ctx->r22 = MEM_W(0X88, ctx->r29);
    // lw          $s5, 0x84($sp)
    ctx->r21 = MEM_W(0X84, ctx->r29);
    // lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(0X80, ctx->r29);
    // lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(0X7C, ctx->r29);
    // lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(0X78, ctx->r29);
    // lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(0X74, ctx->r29);
    // lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(0X70, ctx->r29);
    // addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // jr          $ra
    // nop

    return;
    // nop

;}
