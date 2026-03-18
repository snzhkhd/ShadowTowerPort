#include "recomp.h"
#include "disable_warnings.h"

void sub_800385B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x190
    ctx->r29 = ADD32(ctx->r29, -0X190);
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // sw          $s6, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r22;
    // lw          $s6, 0xF1C($v0)
    ctx->r22 = MEM_W(0XF1C, ctx->r2);
    // sw          $s0, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r16;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // sw          $s3, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r19;
    // sw          $ra, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r30;
    // sw          $s7, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r23;
    // sw          $s5, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r20;
    // sw          $s2, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r18;
    // sw          $s1, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r17;
    // lbu         $s1, 0x1($s6)
    ctx->r17 = MEM_BU(0X1, ctx->r22);
    // lbu         $s2, 0x5($s6)
    ctx->r18 = MEM_BU(0X5, ctx->r22);
    // sltiu       $v0, $s1, 0xF6
    ctx->r2 = ctx->r17 < 0XF6 ? 1 : 0;
    // beq         $v0, $zero, L_8003BBDC
    if (ctx->r2 == 0) {
        // addu        $s3, $s0, $zero
        ctx->r19 = ADD32(ctx->r16, 0);
        goto L_8003BBDC;
    }
    // addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x18A4
    ctx->r2 = ADD32(ctx->r2, 0X18A4);
    // sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_80038614;
    jr_addend_80038614 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80038614 >> 2) {
        case 0: goto L_8003861C; break;
        case 1: goto L_800395F8; break;
        case 2: goto L_8003BBDC; break;
        case 3: goto L_80039430; break;
        case 4: goto L_800394E4; break;
        case 5: goto L_8003BBDC; break;
        case 6: goto L_80039464; break;
        case 7: goto L_80038BF8; break;
        case 8: goto L_8003BBDC; break;
        case 9: goto L_8003946C; break;
        case 10: goto L_8003861C; break;
        case 11: goto L_8003BBDC; break;
        case 12: goto L_800394F0; break;
        case 13: goto L_800394F8; break;
        case 14: goto L_8003BBDC; break;
        case 15: goto L_80039504; break;
        case 16: goto L_800395F8; break;
        case 17: goto L_8003BBDC; break;
        case 18: goto L_8003BBDC; break;
        case 19: goto L_8003BBDC; break;
        case 20: goto L_8003BBDC; break;
        case 21: goto L_8003BBDC; break;
        case 22: goto L_8003BBDC; break;
        case 23: goto L_8003BBDC; break;
        case 24: goto L_8003BBDC; break;
        case 25: goto L_8003BBDC; break;
        case 26: goto L_8003BBDC; break;
        case 27: goto L_8003BBDC; break;
        case 28: goto L_8003BBDC; break;
        case 29: goto L_8003BBDC; break;
        case 30: goto L_8003BBDC; break;
        case 31: goto L_8003BBDC; break;
        case 32: goto L_8003BBDC; break;
        case 33: goto L_8003BBDC; break;
        case 34: goto L_8003BBDC; break;
        case 35: goto L_8003BBDC; break;
        case 36: goto L_8003BBDC; break;
        case 37: goto L_8003BBDC; break;
        case 38: goto L_8003BBDC; break;
        case 39: goto L_8003BBDC; break;
        case 40: goto L_8003BBDC; break;
        case 41: goto L_8003BBDC; break;
        case 42: goto L_8003BBDC; break;
        case 43: goto L_800397B0; break;
        case 44: goto L_8003986C; break;
        case 45: goto L_8003986C; break;
        case 46: goto L_8003986C; break;
        case 47: goto L_8003986C; break;
        case 48: goto L_80039928; break;
        case 49: goto L_80039A9C; break;
        case 50: goto L_80039A9C; break;
        case 51: goto L_80039A9C; break;
        case 52: goto L_80039A9C; break;
        case 53: goto L_80039D84; break;
        case 54: goto L_80039A9C; break;
        case 55: goto L_80039A9C; break;
        case 56: goto L_80039928; break;
        case 57: goto L_80039A9C; break;
        case 58: goto L_80039DD0; break;
        case 59: goto L_8003BBDC; break;
        case 60: goto L_80039A9C; break;
        case 61: goto L_8003A7DC; break;
        case 62: goto L_80039E28; break;
        case 63: goto L_80039A9C; break;
        case 64: goto L_8003BB1C; break;
        case 65: goto L_80039FFC; break;
        case 66: goto L_80039A9C; break;
        case 67: goto L_80039A9C; break;
        case 68: goto L_8003BBDC; break;
        case 69: goto L_80039A9C; break;
        case 70: goto L_8003A7DC; break;
        case 71: goto L_8003AF84; break;
        case 72: goto L_80039E28; break;
        case 73: goto L_80039A9C; break;
        case 74: goto L_80039A9C; break;
        case 75: goto L_80039A9C; break;
        case 76: goto L_8003BBDC; break;
        case 77: goto L_80039A9C; break;
        case 78: goto L_8003BBDC; break;
        case 79: goto L_80039A9C; break;
        case 80: goto L_8003BBDC; break;
        case 81: goto L_80039A9C; break;
        case 82: goto L_8003A7DC; break;
        case 83: goto L_80039D84; break;
        case 84: goto L_8003BBDC; break;
        case 85: goto L_8003B79C; break;
        case 86: goto L_8003B53C; break;
        case 87: goto L_8003B274; break;
        case 88: goto L_8003B274; break;
        case 89: goto L_8003B79C; break;
        case 90: goto L_8003A7DC; break;
        case 91: goto L_8003BBDC; break;
        case 92: goto L_8003B274; break;
        case 93: goto L_8003B86C; break;
        case 94: goto L_8003BB1C; break;
        case 95: goto L_8003B53C; break;
        case 96: goto L_80039A9C; break;
        case 97: goto L_8003B274; break;
        case 98: goto L_8003B274; break;
        case 99: goto L_8003B274; break;
        case 100: goto L_8003A7DC; break;
        case 101: goto L_8003B86C; break;
        case 102: goto L_8003996C; break;
        case 103: goto L_8003B274; break;
        case 104: goto L_8003B274; break;
        case 105: goto L_8003BB1C; break;
        case 106: goto L_80039A9C; break;
        case 107: goto L_80039A9C; break;
        case 108: goto L_80039E28; break;
        case 109: goto L_80039A9C; break;
        case 110: goto L_80039A9C; break;
        case 111: goto L_80039A9C; break;
        case 112: goto L_8003B53C; break;
        case 113: goto L_80039E28; break;
        case 114: goto L_80039A9C; break;
        case 115: goto L_80039A9C; break;
        case 116: goto L_8003B274; break;
        case 117: goto L_8003B86C; break;
        case 118: goto L_8003BB1C; break;
        case 119: goto L_8003B86C; break;
        case 120: goto L_8003B86C; break;
        case 121: goto L_8003B86C; break;
        case 122: goto L_80039E28; break;
        case 123: goto L_80039A9C; break;
        case 124: goto L_8003B8AC; break;
        case 125: goto L_800399CC; break;
        case 126: goto L_8003AA98; break;
        case 127: goto L_80039A9C; break;
        case 128: goto L_8003B86C; break;
        case 129: goto L_8003AA98; break;
        case 130: goto L_80039D84; break;
        case 131: goto L_8003B8AC; break;
        case 132: goto L_8003B8AC; break;
        case 133: goto L_80039A9C; break;
        case 134: goto L_8003A7DC; break;
        case 135: goto L_80039A9C; break;
        case 136: goto L_8003BB1C; break;
        case 137: goto L_8003BB1C; break;
        case 138: goto L_8003AA98; break;
        case 139: goto L_8003BB1C; break;
        case 140: goto L_8003B274; break;
        case 141: goto L_80039D84; break;
        case 142: goto L_8003B8AC; break;
        case 143: goto L_80039A9C; break;
        case 144: goto L_80039A9C; break;
        case 145: goto L_8003B8AC; break;
        case 146: goto L_80039A9C; break;
        case 147: goto L_80039E28; break;
        case 148: goto L_80039A9C; break;
        case 149: goto L_8003B274; break;
        case 150: goto L_8003B8AC; break;
        case 151: goto L_8003B79C; break;
        case 152: goto L_80039A9C; break;
        case 153: goto L_80039A9C; break;
        case 154: goto L_8003B104; break;
        case 155: goto L_8003AF84; break;
        case 156: goto L_8003B274; break;
        case 157: goto L_80039A9C; break;
        case 158: goto L_8003B274; break;
        case 159: goto L_80039A9C; break;
        case 160: goto L_8003B8AC; break;
        case 161: goto L_800399CC; break;
        case 162: goto L_8003BB1C; break;
        case 163: goto L_80039A9C; break;
        case 164: goto L_8003BB1C; break;
        case 165: goto L_80039A9C; break;
        case 166: goto L_8003B86C; break;
        case 167: goto L_8003B8AC; break;
        case 168: goto L_8003BB1C; break;
        case 169: goto L_8003B8AC; break;
        case 170: goto L_80038990; break;
        case 171: goto L_80038940; break;
        case 172: goto L_80038A48; break;
        case 173: goto L_80038AE0; break;
        case 174: goto L_80038B74; break;
        case 175: goto L_80039120; break;
        case 176: goto L_800391DC; break;
        case 177: goto L_800392A4; break;
        case 178: goto L_80039328; break;
        case 179: goto L_800393AC; break;
        case 180: goto L_8003BBDC; break;
        case 181: goto L_8003BBDC; break;
        case 182: goto L_8003BBDC; break;
        case 183: goto L_8003BBDC; break;
        case 184: goto L_8003BBDC; break;
        case 185: goto L_8003BBDC; break;
        case 186: goto L_8003BBDC; break;
        case 187: goto L_8003BBDC; break;
        case 188: goto L_8003BBDC; break;
        case 189: goto L_8003BBDC; break;
        case 190: goto L_8003BBDC; break;
        case 191: goto L_8003BBDC; break;
        case 192: goto L_8003BBDC; break;
        case 193: goto L_8003BBDC; break;
        case 194: goto L_8003BBDC; break;
        case 195: goto L_8003BBDC; break;
        case 196: goto L_8003BBDC; break;
        case 197: goto L_8003BBDC; break;
        case 198: goto L_8003BBDC; break;
        case 199: goto L_8003BBDC; break;
        case 200: goto L_80039B3C; break;
        case 201: goto L_80039D5C; break;
        case 202: goto L_8003A270; break;
        case 203: goto L_8003AD24; break;
        case 204: goto L_8003AF00; break;
        case 205: goto L_8003A270; break;
        case 206: goto L_8003AD24; break;
        case 207: goto L_8003AF00; break;
        case 208: goto L_8003A270; break;
        case 209: goto L_8003AD24; break;
        case 210: goto L_8003AF00; break;
        case 211: goto L_80039B3C; break;
        case 212: goto L_80039D5C; break;
        case 213: goto L_8003B758; break;
        case 214: goto L_8003B448; break;
        case 215: goto L_8003B500; break;
        case 216: goto L_8003A270; break;
        case 217: goto L_8003AD24; break;
        case 218: goto L_8003AF00; break;
        case 219: goto L_8003A270; break;
        case 220: goto L_8003AD24; break;
        case 221: goto L_8003AF00; break;
        case 222: goto L_8003A270; break;
        case 223: goto L_8003ADF8; break;
        case 224: goto L_8003AF00; break;
        case 225: goto L_8003A270; break;
        case 226: goto L_8003ADF8; break;
        case 227: goto L_8003AF00; break;
        case 228: goto L_80039B3C; break;
        case 229: goto L_80039D5C; break;
        case 230: goto L_8003A270; break;
        case 231: goto L_8003AD24; break;
        case 232: goto L_8003AF00; break;
        case 233: goto L_8003B924; break;
        case 234: goto L_8003B9EC; break;
        case 235: goto L_8003A270; break;
        case 236: goto L_8003ADF8; break;
        case 237: goto L_8003AF00; break;
        case 238: goto L_80039B3C; break;
        case 239: goto L_80039D5C; break;
        case 240: goto L_8003B0F4; break;
        case 241: goto L_8003B0FC; break;
        case 242: goto L_8003B104; break;
        case 243: goto L_8003B1B0; break;
        case 244: goto L_8003B1B8; break;
        case 245: goto L_8003B1C0; break;
        default: switch_error(__func__, 0x80038614, 0x800118A4);
    }
    // nop

L_8003861C:
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lw          $a1, 0x18($s6)
    ctx->r5 = MEM_W(0X18, ctx->r22);
    // jal         0x80038300
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80038300(rdram, ctx);
    goto after_0;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8003BBDC
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x10
        ctx->r2 = ctx->r16 & 0X10;
        goto L_8003BBDC;
    }
    // andi        $v0, $s0, 0x10
    ctx->r2 = ctx->r16 & 0X10;
    // beq         $v0, $zero, L_80038690
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80038690;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v1, 0x59A4($v0)
    ctx->r3 = MEM_W(0X59A4, ctx->r2);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x5EC8
    ctx->r3 = ADD32(ctx->r3, -0X5EC8);
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v0, 0x2C($v1)
    ctx->r2 = MEM_HU(0X2C, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80038698
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80038698;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lbu         $v1, 0x1F($v1)
    ctx->r3 = MEM_BU(0X1F, ctx->r3);
    // nop

    // beq         $v1, $v0, L_80038698
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80038698;
    }
    // nop

L_80038690:
    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
L_80038698:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // srl         $a1, $a1, 2
    ctx->r5 = S32(U32(ctx->r5) >> 2);
    // andi        $a1, $a1, 0x8
    ctx->r5 = ctx->r5 & 0X8;
    // jal         0x80035CC8
    // addiu       $a1, $a1, 0x1D
    ctx->r5 = ADD32(ctx->r5, 0X1D);
    sub_80035CC8(rdram, ctx);
    goto after_2;
    // addiu       $a1, $a1, 0x1D
    ctx->r5 = ADD32(ctx->r5, 0X1D);
    after_2:
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // nop

    // sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // nop

    // sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // lw          $v0, 0x28($s6)
    ctx->r2 = MEM_W(0X28, ctx->r22);
    // nop

    // sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x40($s6)
    ctx->r2 = MEM_HU(0X40, ctx->r22);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // sh          $v0, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x42($s6)
    ctx->r2 = MEM_HU(0X42, ctx->r22);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // sh          $v0, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x44($s6)
    ctx->r2 = MEM_HU(0X44, ctx->r22);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // sh          $v0, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r2;
    // andi        $v0, $s0, 0x1
    ctx->r2 = ctx->r16 & 0X1;
    // beq         $v0, $zero, L_80038724
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
        goto L_80038724;
    }
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // j           L_800387EC
    // sh          $v0, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r2;
    goto L_800387EC;
    // sh          $v0, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r2;
L_80038724:
    // andi        $v0, $s0, 0x2
    ctx->r2 = ctx->r16 & 0X2;
    // beq         $v0, $zero, L_800387D4
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_800387D4;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v0, $v0, 0x5948
    ctx->r2 = ADD32(ctx->r2, 0X5948);
    // lh          $a0, 0x90($v0)
    ctx->r4 = MEM_HS(0X90, ctx->r2);
    // lh          $a1, 0x8C($v0)
    ctx->r5 = MEM_HS(0X8C, ctx->r2);
    // jal         0x80076EA4
    // nop

    ratan2(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lh          $a0, 0x6C($sp)
    ctx->r4 = MEM_HS(0X6C, ctx->r29);
    // lh          $a1, 0x68($sp)
    ctx->r5 = MEM_HS(0X68, ctx->r29);
    // jal         0x80076EA4
    // addiu       $s0, $v0, 0x400
    ctx->r16 = ADD32(ctx->r2, 0X400);
    ratan2(rdram, ctx);
    goto after_4;
    // addiu       $s0, $v0, 0x400
    ctx->r16 = ADD32(ctx->r2, 0X400);
    after_4:
    // jal         0x800744C4
    // subu        $a0, $v0, $s0
    ctx->r4 = SUB32(ctx->r2, ctx->r16);
    rcos(rdram, ctx);
    goto after_5;
    // subu        $a0, $v0, $s0
    ctx->r4 = SUB32(ctx->r2, ctx->r16);
    after_5:
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // bgez        $v0, L_8003877C
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8003877C;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_8003877C:
    // jal         0x800744C4
    // sra         $s1, $v0, 12
    ctx->r17 = S32(ctx->r2) >> 12;
    rcos(rdram, ctx);
    goto after_6;
    // sra         $s1, $v0, 12
    ctx->r17 = S32(ctx->r2) >> 12;
    after_6:
    // mult        $s1, $v0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_80038798
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80038798;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80038798:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r2;
    // jal         0x800743F4
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rsin(rdram, ctx);
    goto after_7;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_7:
    // mult        $s1, $v0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_800387BC
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800387BC;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_800387BC:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // sh          $v0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r2;
    // j           L_800387F4
    // sh          $s0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r16;
    goto L_800387F4;
    // sh          $s0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r16;
L_800387D4:
    // andi        $v0, $s0, 0x4
    ctx->r2 = ctx->r16 & 0X4;
    // beq         $v0, $zero, L_800387EC
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x800
        ctx->r2 = ADD32(0, 0X800);
        goto L_800387EC;
    }
    // addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // sh          $zero, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = 0;
    // j           L_800387F0
    // sh          $v0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r2;
    goto L_800387F0;
    // sh          $v0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r2;
L_800387EC:
    // sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
L_800387F0:
    // sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
L_800387F4:
    // sh          $zero, 0x64($sp)
    MEM_H(0X64, ctx->r29) = 0;
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xAC
    ctx->r6 = ADD32(0, 0XAC);
    // addiu       $s5, $sp, 0x50
    ctx->r21 = ADD32(ctx->r29, 0X50);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // addiu       $s4, $sp, 0x68
    ctx->r20 = ADD32(ctx->r29, 0X68);
    // addiu       $s0, $zero, 0x400
    ctx->r16 = ADD32(0, 0X400);
    // addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s3, $sp, 0x60
    ctx->r19 = ADD32(ctx->r29, 0X60);
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // jal         0x80036484
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    sub_80036484(rdram, ctx);
    goto after_8;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    after_8:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xAD
    ctx->r6 = ADD32(0, 0XAD);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s2, $zero, 0xF
    ctx->r18 = ADD32(0, 0XF);
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // jal         0x80036484
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    sub_80036484(rdram, ctx);
    goto after_9;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    after_9:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xAE
    ctx->r6 = ADD32(0, 0XAE);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // addiu       $s1, $zero, 0x800
    ctx->r17 = ADD32(0, 0X800);
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // jal         0x80036484
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    sub_80036484(rdram, ctx);
    goto after_10;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    after_10:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xAE
    ctx->r6 = ADD32(0, 0XAE);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $v0, $zero, 0x7E8
    ctx->r2 = ADD32(0, 0X7E8);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // jal         0x80036484
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    sub_80036484(rdram, ctx);
    goto after_11;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    after_11:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xAE
    ctx->r6 = ADD32(0, 0XAE);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // jal         0x80036484
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    sub_80036484(rdram, ctx);
    goto after_12;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    after_12:
    // j           L_80039A94
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    goto L_80039A94;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80038940:
    // lw          $a2, 0x1C($s6)
    ctx->r6 = MEM_W(0X1C, ctx->r22);
    // nop

    // lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(0X0, ctx->r6);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_80038980
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80038980;
    }
    // nop

    // lw          $v0, 0x20($a2)
    ctx->r2 = MEM_W(0X20, ctx->r6);
    // lw          $v1, 0x24($a2)
    ctx->r3 = MEM_W(0X24, ctx->r6);
    // lw          $a0, 0x28($a2)
    ctx->r4 = MEM_W(0X28, ctx->r6);
    // lw          $a1, 0x2C($a2)
    ctx->r5 = MEM_W(0X2C, ctx->r6);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // sw          $v1, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r3;
    // sw          $a0, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r4;
    // sw          $a1, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->r5;
    // j           L_80038984
    // nop

    goto L_80038984;
    // nop

L_80038980:
    // sb          $v1, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r3;
L_80038984:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // j           L_8003AEF0
    // slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    goto L_8003AEF0;
    // slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
L_80038990:
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // nop

    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_80038A38
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
        goto L_80038A38;
    }
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7FE8
    ctx->r6 = ADD32(ctx->r2, -0X7FE8);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lb          $a0, 0x4($a2)
    ctx->r4 = MEM_BS(0X4, ctx->r6);
    // lb          $a1, 0x5($a2)
    ctx->r5 = MEM_BS(0X5, ctx->r6);
    // swl         $v1, 0x73($sp)
    do_swl(rdram, 0X73, ctx->r29, ctx->r3);
    // swr         $v1, 0x70($sp)
    do_swr(rdram, 0X70, ctx->r29, ctx->r3);
    // sb          $a0, 0x74($sp)
    MEM_B(0X74, ctx->r29) = ctx->r4;
    // sb          $a1, 0x75($sp)
    MEM_B(0X75, ctx->r29) = ctx->r5;
    // lbu         $v0, 0x50($s6)
    ctx->r2 = MEM_BU(0X50, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x50($s6)
    MEM_B(0X50, ctx->r22) = ctx->r2;
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_800389F4
    if (ctx->r2 != 0) {
        // addiu       $v1, $sp, 0x70
        ctx->r3 = ADD32(ctx->r29, 0X70);
        goto L_800389F4;
    }
    // addiu       $v1, $sp, 0x70
    ctx->r3 = ADD32(ctx->r29, 0X70);
    // sb          $zero, 0x50($s6)
    MEM_B(0X50, ctx->r22) = 0;
L_800389F4:
    // lb          $v0, 0x50($s6)
    ctx->r2 = MEM_BS(0X50, ctx->r22);
    // nop

    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // lw          $v1, 0x1C($s6)
    ctx->r3 = MEM_W(0X1C, ctx->r22);
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sb          $v0, 0x2($s6)
    MEM_B(0X2, ctx->r22) = ctx->r2;
    // lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(0X20, ctx->r3);
    // lw          $a0, 0x24($v1)
    ctx->r4 = MEM_W(0X24, ctx->r3);
    // lw          $a1, 0x28($v1)
    ctx->r5 = MEM_W(0X28, ctx->r3);
    // lw          $a2, 0x2C($v1)
    ctx->r6 = MEM_W(0X2C, ctx->r3);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // sw          $a0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r4;
    // sw          $a1, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r5;
    // sw          $a2, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->r6;
    // j           L_80038A3C
    // nop

    goto L_80038A3C;
    // nop

L_80038A38:
    // sb          $v1, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r3;
L_80038A3C:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // j           L_8003AEF0
    // slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    goto L_8003AEF0;
    // slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
L_80038A48:
    // lhu         $v0, 0x42($s6)
    ctx->r2 = MEM_HU(0X42, ctx->r22);
    // lhu         $v1, 0x52($s6)
    ctx->r3 = MEM_HU(0X52, ctx->r22);
    // lh          $a0, 0x40($s6)
    ctx->r4 = MEM_HS(0X40, ctx->r22);
    // lh          $a1, 0x44($s6)
    ctx->r5 = MEM_HS(0X44, ctx->r22);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r2;
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // lw          $v1, 0x28($s6)
    ctx->r3 = MEM_W(0X28, ctx->r22);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lh          $a0, 0x42($s6)
    ctx->r4 = MEM_HS(0X42, ctx->r22);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v1, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r3;
    // lbu         $v1, 0x5($s6)
    ctx->r3 = MEM_BU(0X5, ctx->r22);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sltiu       $v1, $v1, 0x6
    ctx->r3 = ctx->r3 < 0X6 ? 1 : 0;
    // beq         $v1, $zero, L_80038AA4
    if (ctx->r3 == 0) {
        // sw          $v0, 0x24($s6)
        MEM_W(0X24, ctx->r22) = ctx->r2;
        goto L_80038AA4;
    }
    // sw          $v0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lhu         $v1, 0x50($s6)
    ctx->r3 = MEM_HU(0X50, ctx->r22);
    // j           L_80038AB4
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    goto L_80038AB4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_80038AA4:
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lhu         $v1, 0x50($s6)
    ctx->r3 = MEM_HU(0X50, ctx->r22);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80038AB4:
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // nop

    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // sh          $v0, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r2;
    // lbu         $v0, 0x5($s6)
    ctx->r2 = MEM_BU(0X5, ctx->r22);
    // sh          $v1, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r3;
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8003AEEC
    // sb          $v0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r2;
    goto L_8003AEEC;
    // sb          $v0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r2;
L_80038AE0:
    // lhu         $v1, 0x42($s6)
    ctx->r3 = MEM_HU(0X42, ctx->r22);
    // lh          $a1, 0x40($s6)
    ctx->r5 = MEM_HS(0X40, ctx->r22);
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // lhu         $a0, 0x52($s6)
    ctx->r4 = MEM_HU(0X52, ctx->r22);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lh          $a1, 0x44($s6)
    ctx->r5 = MEM_HS(0X44, ctx->r22);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v1, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r3;
    // lhu         $v1, 0x38($s6)
    ctx->r3 = MEM_HU(0X38, ctx->r22);
    // lhu         $a0, 0x50($s6)
    ctx->r4 = MEM_HU(0X50, ctx->r22);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lw          $v0, 0x28($s6)
    ctx->r2 = MEM_W(0X28, ctx->r22);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lh          $a0, 0x42($s6)
    ctx->r4 = MEM_HS(0X42, ctx->r22);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sw          $v0, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // sh          $v1, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r3;
    // sh          $v1, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r3;
    // lbu         $v1, 0x5($s6)
    ctx->r3 = MEM_BU(0X5, ctx->r22);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sltiu       $v1, $v1, 0x3
    ctx->r3 = ctx->r3 < 0X3 ? 1 : 0;
    // beq         $v1, $zero, L_80038B4C
    if (ctx->r3 == 0) {
        // sw          $v0, 0x24($s6)
        MEM_W(0X24, ctx->r22) = ctx->r2;
        goto L_80038B4C;
    }
    // sw          $v0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r2;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_80038B5C
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    goto L_80038B5C;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
L_80038B4C:
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // lhu         $v1, 0x50($s6)
    ctx->r3 = MEM_HU(0X50, ctx->r22);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80038B5C:
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // lbu         $v0, 0x5($s6)
    ctx->r2 = MEM_BU(0X5, ctx->r22);
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8003AEEC
    // sb          $v0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r2;
    goto L_8003AEEC;
    // sb          $v0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r2;
L_80038B74:
    // lhu         $v0, 0x42($s6)
    ctx->r2 = MEM_HU(0X42, ctx->r22);
    // lhu         $v1, 0x52($s6)
    ctx->r3 = MEM_HU(0X52, ctx->r22);
    // lh          $a0, 0x40($s6)
    ctx->r4 = MEM_HS(0X40, ctx->r22);
    // lh          $a1, 0x44($s6)
    ctx->r5 = MEM_HS(0X44, ctx->r22);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r2;
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // lw          $v1, 0x28($s6)
    ctx->r3 = MEM_W(0X28, ctx->r22);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lbu         $v0, 0x5($s6)
    ctx->r2 = MEM_BU(0X5, ctx->r22);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v1, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r3;
    // lhu         $v1, 0x50($s6)
    ctx->r3 = MEM_HU(0X50, ctx->r22);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lbu         $a0, 0x5($s6)
    ctx->r4 = MEM_BU(0X5, ctx->r22);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x42($s6)
    ctx->r3 = MEM_HS(0X42, ctx->r22);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // sb          $a0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r4;
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // sh          $v0, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // lh          $a0, 0x10($s6)
    ctx->r4 = MEM_HS(0X10, ctx->r22);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r2;
    // slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_8003BBDC
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 9
        ctx->r2 = S32(ctx->r4) << 9;
        goto L_8003BBDC;
    }
    // sll         $v0, $a0, 9
    ctx->r2 = S32(ctx->r4) << 9;
    // j           L_8003BBDC
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
    goto L_8003BBDC;
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
L_80038BF8:
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7FE0
    ctx->r6 = ADD32(ctx->r2, -0X7FE0);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x7B($sp)
    do_swl(rdram, 0X7B, ctx->r29, ctx->r3);
    // swr         $v1, 0x78($sp)
    do_swr(rdram, 0X78, ctx->r29, ctx->r3);
    // swl         $a0, 0x7F($sp)
    do_swl(rdram, 0X7F, ctx->r29, ctx->r4);
    // swr         $a0, 0x7C($sp)
    do_swr(rdram, 0X7C, ctx->r29, ctx->r4);
    // addiu       $a1, $s6, 0x50
    ctx->r5 = ADD32(ctx->r22, 0X50);
    // addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // addiu       $v0, $zero, 0x310
    ctx->r2 = ADD32(0, 0X310);
    // sh          $v0, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x160
    ctx->r2 = ADD32(0, 0X160);
    // sh          $v0, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r2;
    // lbu         $a0, 0x0($s6)
    ctx->r4 = MEM_BU(0X0, ctx->r22);
    // addiu       $a3, $sp, 0x80
    ctx->r7 = ADD32(ctx->r29, 0X80);
    // andi        $a0, $a0, 0x20
    ctx->r4 = ctx->r4 & 0X20;
    // jal         0x80038464
    // sltu        $a0, $zero, $a0
    ctx->r4 = 0 < ctx->r4 ? 1 : 0;
    sub_80038464(rdram, ctx);
    goto after_13;
    // sltu        $a0, $zero, $a0
    ctx->r4 = 0 < ctx->r4 ? 1 : 0;
    after_13:
    // lbu         $v0, 0x50($s6)
    ctx->r2 = MEM_BU(0X50, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // bne         $s2, $zero, L_80038ECC
    if (ctx->r18 != 0) {
        // sb          $v0, 0x50($s6)
        MEM_B(0X50, ctx->r22) = ctx->r2;
        goto L_80038ECC;
    }
    // sb          $v0, 0x50($s6)
    MEM_B(0X50, ctx->r22) = ctx->r2;
    // lbu         $v0, 0x51($s6)
    ctx->r2 = MEM_BU(0X51, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x51($s6)
    MEM_B(0X51, ctx->r22) = ctx->r2;
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // beq         $v0, $zero, L_80038C94
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80038C94;
    }
    // nop

    // lhu         $v0, 0x42($s6)
    ctx->r2 = MEM_HU(0X42, ctx->r22);
    // nop

    // addiu       $v0, $v0, -0x38
    ctx->r2 = ADD32(ctx->r2, -0X38);
    // sh          $v0, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r2;
L_80038C94:
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lw          $a1, 0x18($s6)
    ctx->r5 = MEM_W(0X18, ctx->r22);
    // jal         0x80038300
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80038300(rdram, ctx);
    goto after_14;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_14:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_80038E10
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x10
        ctx->r2 = ctx->r16 & 0X10;
        goto L_80038E10;
    }
    // andi        $v0, $s0, 0x10
    ctx->r2 = ctx->r16 & 0X10;
    // beq         $v0, $zero, L_80038D08
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80038D08;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v1, 0x59A4($v0)
    ctx->r3 = MEM_W(0X59A4, ctx->r2);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x5EC8
    ctx->r3 = ADD32(ctx->r3, -0X5EC8);
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v0, 0x2C($v1)
    ctx->r2 = MEM_HU(0X2C, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80038D10
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80038D10;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lbu         $v1, 0x1F($v1)
    ctx->r3 = MEM_BU(0X1F, ctx->r3);
    // nop

    // beq         $v1, $v0, L_80038D10
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_80038D10;
    }
    // nop

L_80038D08:
    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_15;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_15:
L_80038D10:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // srl         $a1, $a1, 2
    ctx->r5 = S32(U32(ctx->r5) >> 2);
    // andi        $a1, $a1, 0x8
    ctx->r5 = ctx->r5 & 0X8;
    // jal         0x80035CC8
    // addiu       $a1, $a1, 0x1D
    ctx->r5 = ADD32(ctx->r5, 0X1D);
    sub_80035CC8(rdram, ctx);
    goto after_16;
    // addiu       $a1, $a1, 0x1D
    ctx->r5 = ADD32(ctx->r5, 0X1D);
    after_16:
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // nop

    // sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // nop

    // sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // lw          $v0, 0x28($s6)
    ctx->r2 = MEM_W(0X28, ctx->r22);
    // nop

    // sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x40($s6)
    ctx->r2 = MEM_HU(0X40, ctx->r22);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // sh          $v0, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x42($s6)
    ctx->r2 = MEM_HU(0X42, ctx->r22);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // sh          $v0, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x44($s6)
    ctx->r2 = MEM_HU(0X44, ctx->r22);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    // andi        $v0, $s0, 0x11
    ctx->r2 = ctx->r16 & 0X11;
    // beq         $v0, $zero, L_80038DF8
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
        goto L_80038DF8;
    }
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xB3
    ctx->r6 = ADD32(0, 0XB3);
    // addiu       $a3, $sp, 0x90
    ctx->r7 = ADD32(ctx->r29, 0X90);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r2;
    // sh          $zero, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = 0;
    // sh          $zero, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = 0;
    // sh          $zero, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = 0;
    // sh          $zero, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = 0;
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $v0, $sp, 0x88
    ctx->r2 = ADD32(ctx->r29, 0X88);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // jal         0x80036484
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_17;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_17:
    // sb          $zero, 0x52($s6)
    MEM_B(0X52, ctx->r22) = 0;
    // j           L_80038E10
    // sb          $zero, 0x53($s6)
    MEM_B(0X53, ctx->r22) = 0;
    goto L_80038E10;
    // sb          $zero, 0x53($s6)
    MEM_B(0X53, ctx->r22) = 0;
L_80038DF8:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r2;
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // sh          $zero, 0x40($s6)
    MEM_H(0X40, ctx->r22) = 0;
    // sh          $v0, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r2;
    // sh          $zero, 0x44($s6)
    MEM_H(0X44, ctx->r22) = 0;
L_80038E10:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $a0, $v0, 0x5948
    ctx->r4 = ADD32(ctx->r2, 0X5948);
    // lhu         $v1, 0x30($a0)
    ctx->r3 = MEM_HU(0X30, ctx->r4);
    // addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2) << 16;
    // blez        $t0, L_8003BBDC
    if (SIGNED(ctx->r8) <= 0) {
        // addiu       $a2, $zero, 0xB1
        ctx->r6 = ADD32(0, 0XB1);
        goto L_8003BBDC;
    }
    // addiu       $a2, $zero, 0xB1
    ctx->r6 = ADD32(0, 0XB1);
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // nop

    // sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(0X30, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // lw          $v0, 0x28($s6)
    ctx->r2 = MEM_W(0X28, ctx->r22);
    // nop

    // sw          $v0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x40($s6)
    ctx->r2 = MEM_HU(0X40, ctx->r22);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // sh          $v0, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x42($s6)
    ctx->r2 = MEM_HU(0X42, ctx->r22);
    // addiu       $a3, $sp, 0x90
    ctx->r7 = ADD32(ctx->r29, 0X90);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // sh          $v0, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x44($s6)
    ctx->r2 = MEM_HU(0X44, ctx->r22);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $v0, $sp, 0x88
    ctx->r2 = ADD32(ctx->r29, 0X88);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sra         $v0, $t0, 18
    ctx->r2 = S32(ctx->r8) >> 18;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sra         $v0, $t0, 19
    ctx->r2 = S32(ctx->r8) >> 19;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // j           L_8003AD14
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    goto L_8003AD14;
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80038ECC:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $s2, $v0, L_800390F8
    if (ctx->r18 != ctx->r2) {
        // nop
    
        goto L_800390F8;
    }
    // nop

    // lbu         $v0, 0x52($s6)
    ctx->r2 = MEM_BU(0X52, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x52($s6)
    MEM_B(0X52, ctx->r22) = ctx->r2;
    // lbu         $v0, 0x53($s6)
    ctx->r2 = MEM_BU(0X53, ctx->r22);
    // lb          $v1, 0x52($s6)
    ctx->r3 = MEM_BS(0X52, ctx->r22);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x53($s6)
    MEM_B(0X53, ctx->r22) = ctx->r2;
    // slti        $v0, $v1, 0xE
    ctx->r2 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // beq         $v0, $zero, L_80039A90
    if (ctx->r2 == 0) {
        // slti        $v0, $v1, 0x8
        ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
        goto L_80039A90;
    }
    // slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_8003BBDC
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0xE0
        ctx->r4 = ADD32(ctx->r29, 0XE0);
        goto L_8003BBDC;
    }
    // addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // lhu         $v0, 0x40($s6)
    ctx->r2 = MEM_HU(0X40, ctx->r22);
    // sh          $zero, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = 0;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // sh          $v0, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x44($s6)
    ctx->r2 = MEM_HU(0X44, ctx->r22);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 17
    ctx->r2 = S32(ctx->r2) >> 17;
    // sh          $v0, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x30($s6)
    ctx->r2 = MEM_HU(0X30, ctx->r22);
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x32($s6)
    ctx->r2 = MEM_HU(0X32, ctx->r22);
    // addiu       $s1, $sp, 0xC0
    ctx->r17 = ADD32(ctx->r29, 0XC0);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x34($s6)
    ctx->r2 = MEM_HU(0X34, ctx->r22);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // jal         0x80075154
    // sh          $v0, 0xE4($sp)
    MEM_H(0XE4, ctx->r29) = ctx->r2;
    RotMatrixZYX(rdram, ctx);
    goto after_18;
    // sh          $v0, 0xE4($sp)
    MEM_H(0XE4, ctx->r29) = ctx->r2;
    after_18:
    // lb          $a0, 0x52($s6)
    ctx->r4 = MEM_BS(0X52, ctx->r22);
    // nop

    // sll         $a0, $a0, 9
    ctx->r4 = S32(ctx->r4) << 9;
    // jal         0x800744C4
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    rcos(rdram, ctx);
    goto after_19;
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    after_19:
    // bgez        $v0, L_80038F88
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80038F88;
    }
    // nop

    // addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
L_80038F88:
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // sh          $v0, 0xB8($sp)
    MEM_H(0XB8, ctx->r29) = ctx->r2;
    // sh          $zero, 0xBA($sp)
    MEM_H(0XBA, ctx->r29) = 0;
    // lb          $a0, 0x52($s6)
    ctx->r4 = MEM_BS(0X52, ctx->r22);
    // nop

    // sll         $a0, $a0, 9
    ctx->r4 = S32(ctx->r4) << 9;
    // jal         0x800743F4
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    rsin(rdram, ctx);
    goto after_20;
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    after_20:
    // bgez        $v0, L_80038FB8
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80038FB8;
    }
    // nop

    // addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
L_80038FB8:
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $s0, $sp, 0xB8
    ctx->r16 = ADD32(ctx->r29, 0XB8);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // jal         0x80074CF4
    // sh          $v0, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r2;
    ApplyMatrixSV(rdram, ctx);
    goto after_21;
    // sh          $v0, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r2;
    after_21:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xB2
    ctx->r6 = ADD32(0, 0XB2);
    // addiu       $s3, $sp, 0xA8
    ctx->r19 = ADD32(ctx->r29, 0XA8);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // addiu       $s2, $sp, 0xA0
    ctx->r18 = ADD32(ctx->r29, 0XA0);
    // addiu       $fp, $zero, 0x80
    ctx->r30 = ADD32(0, 0X80);
    // lh          $v1, 0xB8($sp)
    ctx->r3 = MEM_HS(0XB8, ctx->r29);
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // addiu       $s7, $zero, 0x6
    ctx->r23 = ADD32(0, 0X6);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // lh          $v1, 0xBC($sp)
    ctx->r3 = MEM_HS(0XBC, ctx->r29);
    // addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // lw          $v0, 0x28($s6)
    ctx->r2 = MEM_W(0X28, ctx->r22);
    // addiu       $s4, $zero, 0xF
    ctx->r20 = ADD32(0, 0XF);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    // sw          $s5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r21;
    // jal         0x80036484
    // sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    sub_80036484(rdram, ctx);
    goto after_22;
    // sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    after_22:
    // lb          $a0, 0x52($s6)
    ctx->r4 = MEM_BS(0X52, ctx->r22);
    // jal         0x800744C4
    // sll         $a0, $a0, 9
    ctx->r4 = S32(ctx->r4) << 9;
    rcos(rdram, ctx);
    goto after_23;
    // sll         $a0, $a0, 9
    ctx->r4 = S32(ctx->r4) << 9;
    after_23:
    // bgez        $v0, L_8003905C
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8003905C;
    }
    // nop

    // addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
L_8003905C:
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // addiu       $v0, $v0, -0x100
    ctx->r2 = ADD32(ctx->r2, -0X100);
    // sh          $v0, 0xB8($sp)
    MEM_H(0XB8, ctx->r29) = ctx->r2;
    // sh          $zero, 0xBA($sp)
    MEM_H(0XBA, ctx->r29) = 0;
    // lb          $a0, 0x52($s6)
    ctx->r4 = MEM_BS(0X52, ctx->r22);
    // jal         0x800743F4
    // sll         $a0, $a0, 9
    ctx->r4 = S32(ctx->r4) << 9;
    rsin(rdram, ctx);
    goto after_24;
    // sll         $a0, $a0, 9
    ctx->r4 = S32(ctx->r4) << 9;
    after_24:
    // bgez        $v0, L_80039084
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_80039084;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
L_80039084:
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // jal         0x80074CF4
    // sh          $v0, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r2;
    ApplyMatrixSV(rdram, ctx);
    goto after_25;
    // sh          $v0, 0xBC($sp)
    MEM_H(0XBC, ctx->r29) = ctx->r2;
    after_25:
    // lh          $v1, 0xB8($sp)
    ctx->r3 = MEM_HS(0XB8, ctx->r29);
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // lh          $v1, 0xBC($sp)
    ctx->r3 = MEM_HS(0XBC, ctx->r29);
    // addiu       $a2, $zero, 0xB2
    ctx->r6 = ADD32(0, 0XB2);
    // sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // lw          $v0, 0x28($s6)
    ctx->r2 = MEM_W(0X28, ctx->r22);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $t1, $zero, 0x100
    ctx->r9 = ADD32(0, 0X100);
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    // sw          $s5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r21;
    // jal         0x80036484
    // sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    sub_80036484(rdram, ctx);
    goto after_26;
    // sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    after_26:
    // j           L_8003BBDC
    // nop

    goto L_8003BBDC;
    // nop

L_800390F8:
    // lhu         $v0, 0x30($s6)
    ctx->r2 = MEM_HU(0X30, ctx->r22);
    // lbu         $v1, 0x5($s6)
    ctx->r3 = MEM_BU(0X5, ctx->r22);
    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // sh          $v0, 0x30($s6)
    MEM_H(0X30, ctx->r22) = ctx->r2;
    // addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // sltiu       $v1, $v1, 0xE
    ctx->r3 = ctx->r3 < 0XE ? 1 : 0;
    // bne         $v1, $zero, L_8003BBDC
    if (ctx->r3 != 0) {
        // sb          $v0, 0x5($s6)
        MEM_B(0X5, ctx->r22) = ctx->r2;
        goto L_8003BBDC;
    }
    // sb          $v0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r2;
    // j           L_80039A94
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    goto L_80039A94;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80039120:
    // lw          $a2, 0x1C($s6)
    ctx->r6 = MEM_W(0X1C, ctx->r22);
    // nop

    // lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(0X0, ctx->r6);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_800391C8
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_800391C8;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lbu         $v1, 0x5($a2)
    ctx->r3 = MEM_BU(0X5, ctx->r6);
    // nop

    // beq         $v1, $v0, L_800391CC
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_800391CC;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // bne         $v1, $zero, L_80039178
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80039178;
    }
    // nop

    // lw          $v0, 0x20($a2)
    ctx->r2 = MEM_W(0X20, ctx->r6);
    // lw          $v1, 0x24($a2)
    ctx->r3 = MEM_W(0X24, ctx->r6);
    // lw          $a0, 0x28($a2)
    ctx->r4 = MEM_W(0X28, ctx->r6);
    // lw          $a1, 0x2C($a2)
    ctx->r5 = MEM_W(0X2C, ctx->r6);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // sw          $v1, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r3;
    // sw          $a0, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r4;
    // sw          $a1, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->r5;
    // j           L_80039198
    // nop

    goto L_80039198;
    // nop

L_80039178:
    // lbu         $v0, 0x50($s6)
    ctx->r2 = MEM_BU(0X50, ctx->r22);
    // lw          $v1, 0x24($s6)
    ctx->r3 = MEM_W(0X24, ctx->r22);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x50($s6)
    MEM_B(0X50, ctx->r22) = ctx->r2;
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 20
    ctx->r2 = S32(ctx->r2) >> 20;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r3;
L_80039198:
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // nop

    // lwl         $v1, 0x33($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X33, ctx->r2);
    // lwr         $v1, 0x30($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X30, ctx->r2);
    // lwl         $a0, 0x37($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X37, ctx->r2);
    // lwr         $a0, 0x34($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X34, ctx->r2);
    // swl         $v1, 0x33($s6)
    do_swl(rdram, 0X33, ctx->r22, ctx->r3);
    // swr         $v1, 0x30($s6)
    do_swr(rdram, 0X30, ctx->r22, ctx->r3);
    // swl         $a0, 0x37($s6)
    do_swl(rdram, 0X37, ctx->r22, ctx->r4);
    // swr         $a0, 0x34($s6)
    do_swr(rdram, 0X34, ctx->r22, ctx->r4);
    // j           L_800391D0
    // nop

    goto L_800391D0;
    // nop

L_800391C8:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800391CC:
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_800391D0:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // j           L_8003AEF0
    // slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    goto L_8003AEF0;
    // slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
L_800391DC:
    // lw          $a2, 0x1C($s6)
    ctx->r6 = MEM_W(0X1C, ctx->r22);
    // nop

    // lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(0X0, ctx->r6);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_80039290
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80039290;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lbu         $v1, 0x5($a2)
    ctx->r3 = MEM_BU(0X5, ctx->r6);
    // nop

    // beq         $v1, $v0, L_80039294
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_80039294;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // bne         $v1, $zero, L_80039234
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80039234;
    }
    // nop

    // lw          $v0, 0x20($a2)
    ctx->r2 = MEM_W(0X20, ctx->r6);
    // lw          $v1, 0x24($a2)
    ctx->r3 = MEM_W(0X24, ctx->r6);
    // lw          $a0, 0x28($a2)
    ctx->r4 = MEM_W(0X28, ctx->r6);
    // lw          $a1, 0x2C($a2)
    ctx->r5 = MEM_W(0X2C, ctx->r6);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // sw          $v1, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r3;
    // sw          $a0, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r4;
    // sw          $a1, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->r5;
    // j           L_80039254
    // nop

    goto L_80039254;
    // nop

L_80039234:
    // lbu         $v0, 0x50($s6)
    ctx->r2 = MEM_BU(0X50, ctx->r22);
    // lw          $v1, 0x24($s6)
    ctx->r3 = MEM_W(0X24, ctx->r22);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x50($s6)
    MEM_B(0X50, ctx->r22) = ctx->r2;
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 22
    ctx->r2 = S32(ctx->r2) >> 22;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r3;
L_80039254:
    // lbu         $v0, 0x51($s6)
    ctx->r2 = MEM_BU(0X51, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x51($s6)
    MEM_B(0X51, ctx->r22) = ctx->r2;
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_8003927C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003927C;
    }
    // nop

    // sb          $zero, 0x51($s6)
    MEM_B(0X51, ctx->r22) = 0;
L_8003927C:
    // lbu         $v0, 0x51($s6)
    ctx->r2 = MEM_BU(0X51, ctx->r22);
    // nop

    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // j           L_80039298
    // sb          $v0, 0x2($s6)
    MEM_B(0X2, ctx->r22) = ctx->r2;
    goto L_80039298;
    // sb          $v0, 0x2($s6)
    MEM_B(0X2, ctx->r22) = ctx->r2;
L_80039290:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80039294:
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_80039298:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // j           L_8003AEF0
    // slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    goto L_8003AEF0;
    // slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
L_800392A4:
    // lh          $v1, 0x40($s6)
    ctx->r3 = MEM_HS(0X40, ctx->r22);
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // lh          $a0, 0x42($s6)
    ctx->r4 = MEM_HS(0X42, ctx->r22);
    // lh          $a1, 0x44($s6)
    ctx->r5 = MEM_HS(0X44, ctx->r22);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // lw          $v1, 0x28($s6)
    ctx->r3 = MEM_W(0X28, ctx->r22);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lhu         $a0, 0x50($s6)
    ctx->r4 = MEM_HU(0X50, ctx->r22);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v1, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r3;
    // lbu         $v1, 0x5($s6)
    ctx->r3 = MEM_BU(0X5, ctx->r22);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sltiu       $v1, $v1, 0x3
    ctx->r3 = ctx->r3 < 0X3 ? 1 : 0;
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // beq         $v1, $zero, L_80039300
    if (ctx->r3 == 0) {
        // sh          $v0, 0x3C($s6)
        MEM_H(0X3C, ctx->r22) = ctx->r2;
        goto L_80039300;
    }
    // sh          $v0, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r2;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_80039310
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    goto L_80039310;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
L_80039300:
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // lhu         $v1, 0x50($s6)
    ctx->r3 = MEM_HU(0X50, ctx->r22);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80039310:
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // lbu         $v0, 0x5($s6)
    ctx->r2 = MEM_BU(0X5, ctx->r22);
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8003AEEC
    // sb          $v0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r2;
    goto L_8003AEEC;
    // sb          $v0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r2;
L_80039328:
    // lh          $v1, 0x40($s6)
    ctx->r3 = MEM_HS(0X40, ctx->r22);
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // lh          $a0, 0x42($s6)
    ctx->r4 = MEM_HS(0X42, ctx->r22);
    // lh          $a1, 0x44($s6)
    ctx->r5 = MEM_HS(0X44, ctx->r22);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // lw          $v1, 0x28($s6)
    ctx->r3 = MEM_W(0X28, ctx->r22);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lhu         $a0, 0x50($s6)
    ctx->r4 = MEM_HU(0X50, ctx->r22);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v1, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r3;
    // lbu         $v1, 0x5($s6)
    ctx->r3 = MEM_BU(0X5, ctx->r22);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sltiu       $v1, $v1, 0x3
    ctx->r3 = ctx->r3 < 0X3 ? 1 : 0;
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // beq         $v1, $zero, L_80039384
    if (ctx->r3 == 0) {
        // sh          $v0, 0x3C($s6)
        MEM_H(0X3C, ctx->r22) = ctx->r2;
        goto L_80039384;
    }
    // sh          $v0, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r2;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_80039394
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    goto L_80039394;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
L_80039384:
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // lhu         $v1, 0x50($s6)
    ctx->r3 = MEM_HU(0X50, ctx->r22);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80039394:
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // lbu         $v0, 0x5($s6)
    ctx->r2 = MEM_BU(0X5, ctx->r22);
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8003AEEC
    // sb          $v0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r2;
    goto L_8003AEEC;
    // sb          $v0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r2;
L_800393AC:
    // lh          $v1, 0x40($s6)
    ctx->r3 = MEM_HS(0X40, ctx->r22);
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // lh          $a0, 0x42($s6)
    ctx->r4 = MEM_HS(0X42, ctx->r22);
    // lh          $a1, 0x44($s6)
    ctx->r5 = MEM_HS(0X44, ctx->r22);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // lw          $v1, 0x28($s6)
    ctx->r3 = MEM_W(0X28, ctx->r22);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lhu         $a0, 0x50($s6)
    ctx->r4 = MEM_HU(0X50, ctx->r22);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v1, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r3;
    // lbu         $v1, 0x5($s6)
    ctx->r3 = MEM_BU(0X5, ctx->r22);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sltiu       $v1, $v1, 0x3
    ctx->r3 = ctx->r3 < 0X3 ? 1 : 0;
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // beq         $v1, $zero, L_80039408
    if (ctx->r3 == 0) {
        // sh          $v0, 0x3C($s6)
        MEM_H(0X3C, ctx->r22) = ctx->r2;
        goto L_80039408;
    }
    // sh          $v0, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r2;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_80039418
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    goto L_80039418;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
L_80039408:
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // lhu         $v1, 0x50($s6)
    ctx->r3 = MEM_HU(0X50, ctx->r22);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80039418:
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // lbu         $v0, 0x5($s6)
    ctx->r2 = MEM_BU(0X5, ctx->r22);
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8003AEEC
    // sb          $v0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r2;
    goto L_8003AEEC;
    // sb          $v0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r2;
L_80039430:
    // lhu         $v0, 0x10($s6)
    ctx->r2 = MEM_HU(0X10, ctx->r22);
    // nop

    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80039454
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80039454;
    }
    // nop

    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // j           L_80039460
    // addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    goto L_80039460;
    // addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
L_80039454:
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
L_80039460:
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
L_80039464:
    // j           L_80039514
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    goto L_80039514;
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8003946C:
    // lhu         $v0, 0x32($s6)
    ctx->r2 = MEM_HU(0X32, ctx->r22);
    // lhu         $v1, 0x52($s6)
    ctx->r3 = MEM_HU(0X52, ctx->r22);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80078AC4
    // sh          $v0, 0x32($s6)
    MEM_H(0X32, ctx->r22) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_27;
    // sh          $v0, 0x32($s6)
    MEM_H(0X32, ctx->r22) = ctx->r2;
    after_27:
    // lhu         $v1, 0x40($s6)
    ctx->r3 = MEM_HU(0X40, ctx->r22);
    // bgez        $v0, L_80039494
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $v1, $v1, 0x20
        ctx->r3 = ADD32(ctx->r3, 0X20);
        goto L_80039494;
    }
    // addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // addiu       $v0, $v0, 0x1FF
    ctx->r2 = ADD32(ctx->r2, 0X1FF);
L_80039494:
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // jal         0x80078AC4
    // sh          $v0, 0x40($s6)
    MEM_H(0X40, ctx->r22) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_28;
    // sh          $v0, 0x40($s6)
    MEM_H(0X40, ctx->r22) = ctx->r2;
    after_28:
    // lhu         $v1, 0x42($s6)
    ctx->r3 = MEM_HU(0X42, ctx->r22);
    // bgez        $v0, L_800394B4
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
        goto L_800394B4;
    }
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
L_800394B4:
    // sra         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) >> 10;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // jal         0x80078AC4
    // sh          $v0, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_29;
    // sh          $v0, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r2;
    after_29:
    // lhu         $v1, 0x44($s6)
    ctx->r3 = MEM_HU(0X44, ctx->r22);
    // bgez        $v0, L_800394D4
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $v1, $v1, 0x20
        ctx->r3 = ADD32(ctx->r3, 0X20);
        goto L_800394D4;
    }
    // addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // addiu       $v0, $v0, 0x1FF
    ctx->r2 = ADD32(ctx->r2, 0X1FF);
L_800394D4:
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // j           L_80039514
    // sh          $v0, 0x44($s6)
    MEM_H(0X44, ctx->r22) = ctx->r2;
    goto L_80039514;
    // sh          $v0, 0x44($s6)
    MEM_H(0X44, ctx->r22) = ctx->r2;
L_800394E4:
    // addiu       $s0, $zero, 0x80
    ctx->r16 = ADD32(0, 0X80);
    // j           L_80039514
    // addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    goto L_80039514;
    // addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800394F0:
    // j           L_80039514
    // addiu       $s0, $zero, 0x180
    ctx->r16 = ADD32(0, 0X180);
    goto L_80039514;
    // addiu       $s0, $zero, 0x180
    ctx->r16 = ADD32(0, 0X180);
L_800394F8:
    // addiu       $s0, $zero, 0x180
    ctx->r16 = ADD32(0, 0X180);
    // j           L_80039514
    // addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    goto L_80039514;
    // addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80039504:
    // lhu         $v0, 0x32($s6)
    ctx->r2 = MEM_HU(0X32, ctx->r22);
    // sh          $zero, 0x30($s6)
    MEM_H(0X30, ctx->r22) = 0;
    // addiu       $v0, $v0, 0x180
    ctx->r2 = ADD32(ctx->r2, 0X180);
    // sh          $v0, 0x32($s6)
    MEM_H(0X32, ctx->r22) = ctx->r2;
L_80039514:
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lw          $a1, 0x18($s6)
    ctx->r5 = MEM_W(0X18, ctx->r22);
    // jal         0x80038300
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sub_80038300(rdram, ctx);
    goto after_30;
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_30:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_800395D4
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x10
        ctx->r2 = ctx->r16 & 0X10;
        goto L_800395D4;
    }
    // andi        $v0, $s0, 0x10
    ctx->r2 = ctx->r16 & 0X10;
    // beq         $v0, $zero, L_8003959C
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8003959C;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v1, 0x59A4($v0)
    ctx->r3 = MEM_W(0X59A4, ctx->r2);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x5EC8
    ctx->r3 = ADD32(ctx->r3, -0X5EC8);
    // addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v0, 0x2C($s1)
    ctx->r2 = MEM_HU(0X2C, ctx->r17);
    // nop

    // beq         $v0, $zero, L_800395A4
    if (ctx->r2 == 0) {
        // addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
        goto L_800395A4;
    }
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // lbu         $v0, 0x1F($s1)
    ctx->r2 = MEM_BU(0X1F, ctx->r17);
    // nop

    // beq         $v0, $s2, L_800395A4
    if (ctx->r2 == ctx->r18) {
        // nop
    
        goto L_800395A4;
    }
    // nop

    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_31;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_31:
    // sb          $s2, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r18;
    // j           L_800395A4
    // sw          $s1, 0x54($s6)
    MEM_W(0X54, ctx->r22) = ctx->r17;
    goto L_800395A4;
    // sw          $s1, 0x54($s6)
    MEM_W(0X54, ctx->r22) = ctx->r17;
L_8003959C:
    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_32;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_32:
L_800395A4:
    // bne         $s3, $zero, L_800395B0
    if (ctx->r19 != 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_800395B0;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_800395B0:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // srl         $a1, $a1, 2
    ctx->r5 = S32(U32(ctx->r5) >> 2);
    // andi        $a1, $a1, 0x8
    ctx->r5 = ctx->r5 & 0X8;
    // jal         0x80035CC8
    // addiu       $a1, $a1, 0x1D
    ctx->r5 = ADD32(ctx->r5, 0X1D);
    sub_80035CC8(rdram, ctx);
    goto after_33;
    // addiu       $a1, $a1, 0x1D
    ctx->r5 = ADD32(ctx->r5, 0X1D);
    after_33:
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // j           L_800395EC
    // sb          $v0, 0x8($s6)
    MEM_B(0X8, ctx->r22) = ctx->r2;
    goto L_800395EC;
    // sb          $v0, 0x8($s6)
    MEM_B(0X8, ctx->r22) = ctx->r2;
L_800395D4:
    // lbu         $v0, 0x50($s6)
    ctx->r2 = MEM_BU(0X50, ctx->r22);
    // lhu         $v1, 0x42($s6)
    ctx->r3 = MEM_HU(0X42, ctx->r22);
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r3;
L_800395EC:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // j           L_8003BB0C
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    goto L_8003BB0C;
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
L_800395F8:
    // lhu         $v0, 0x32($s6)
    ctx->r2 = MEM_HU(0X32, ctx->r22);
    // lbu         $v1, 0x5($s6)
    ctx->r3 = MEM_BU(0X5, ctx->r22);
    // sh          $zero, 0x30($s6)
    MEM_H(0X30, ctx->r22) = 0;
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // beq         $v1, $zero, L_800396C4
    if (ctx->r3 == 0) {
        // sh          $v0, 0x32($s6)
        MEM_H(0X32, ctx->r22) = ctx->r2;
        goto L_800396C4;
    }
    // sh          $v0, 0x32($s6)
    MEM_H(0X32, ctx->r22) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $s1, $v0, L_8003962C
    if (ctx->r17 != ctx->r2) {
        // nop
    
        goto L_8003962C;
    }
    // nop

    // lhu         $v0, 0x34($s6)
    ctx->r2 = MEM_HU(0X34, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // sh          $v0, 0x34($s6)
    MEM_H(0X34, ctx->r22) = ctx->r2;
L_8003962C:
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lhu         $v1, 0x3C($s6)
    ctx->r3 = MEM_HU(0X3C, ctx->r22);
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // lh          $a0, 0x38($s6)
    ctx->r4 = MEM_HS(0X38, ctx->r22);
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // sh          $v1, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r3;
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // bgez        $a0, L_8003965C
    if (SIGNED(ctx->r4) >= 0) {
        // sh          $v0, 0x3A($s6)
        MEM_H(0X3A, ctx->r22) = ctx->r2;
        goto L_8003965C;
    }
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // addiu       $a0, $a0, 0xF
    ctx->r4 = ADD32(ctx->r4, 0XF);
L_8003965C:
    // lh          $v1, 0x38($s6)
    ctx->r3 = MEM_HS(0X38, ctx->r22);
    // sra         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4) >> 4;
    // bgez        $v1, L_80039670
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0xC($s6)
        MEM_H(0XC, ctx->r22) = ctx->r2;
        goto L_80039670;
    }
    // sh          $v0, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r2;
    // addiu       $v1, $v1, 0xF
    ctx->r3 = ADD32(ctx->r3, 0XF);
L_80039670:
    // sra         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) >> 4;
    // lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // lh          $v1, 0x38($s6)
    ctx->r3 = MEM_HS(0X38, ctx->r22);
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // slti        $v1, $v1, 0x1800
    ctx->r3 = SIGNED(ctx->r3) < 0X1800 ? 1 : 0;
    // bne         $v1, $zero, L_800397A4
    if (ctx->r3 != 0) {
        // sw          $v0, 0x18($s6)
        MEM_W(0X18, ctx->r22) = ctx->r2;
        goto L_800397A4;
    }
    // sw          $v0, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r2;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // jal         0x80035D04
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
    sub_80035D04(rdram, ctx);
    goto after_34;
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
    after_34:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // andi        $v0, $a0, 0x10
    ctx->r2 = ctx->r4 & 0X10;
    // beq         $v0, $zero, L_800397A4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800397A4;
    }
    // nop

    // jal         0x8003618C
    // nop

    sub_8003618C(rdram, ctx);
    goto after_35;
    // nop

    after_35:
    // j           L_800397A4
    // nop

    goto L_800397A4;
    // nop

L_800396C4:
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lw          $a1, 0x18($s6)
    ctx->r5 = MEM_W(0X18, ctx->r22);
    // jal         0x80038300
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80038300(rdram, ctx);
    goto after_36;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_36:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_800397A4
    if (ctx->r16 == 0) {
        // addu        $a0, $s6, $zero
        ctx->r4 = ADD32(ctx->r22, 0);
        goto L_800397A4;
    }
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // nop

    // srl         $a1, $a1, 2
    ctx->r5 = S32(U32(ctx->r5) >> 2);
    // andi        $a1, $a1, 0x8
    ctx->r5 = ctx->r5 & 0X8;
    // jal         0x80035CC8
    // addiu       $a1, $a1, 0x1D
    ctx->r5 = ADD32(ctx->r5, 0X1D);
    sub_80035CC8(rdram, ctx);
    goto after_37;
    // addiu       $a1, $a1, 0x1D
    ctx->r5 = ADD32(ctx->r5, 0X1D);
    after_37:
    // andi        $v0, $s0, 0x10
    ctx->r2 = ctx->r16 & 0X10;
    // beq         $v0, $zero, L_80039794
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80039794;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v1, 0x59A4($v0)
    ctx->r3 = MEM_W(0X59A4, ctx->r2);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x5EC8
    ctx->r3 = ADD32(ctx->r3, -0X5EC8);
    // addu        $s2, $v0, $v1
    ctx->r18 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v0, 0x2C($s2)
    ctx->r2 = MEM_HU(0X2C, ctx->r18);
    // nop

    // beq         $v0, $zero, L_8003979C
    if (ctx->r2 == 0) {
        // addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
        goto L_8003979C;
    }
    // addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // lbu         $v0, 0x1F($s2)
    ctx->r2 = MEM_BU(0X1F, ctx->r18);
    // nop

    // beq         $v0, $s3, L_800397A0
    if (ctx->r2 == ctx->r19) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_800397A0;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_38;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_38:
    // lh          $v0, 0x10($s6)
    ctx->r2 = MEM_HS(0X10, ctx->r22);
    // nop

    // slti        $v0, $v0, 0x20
    ctx->r2 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // bne         $v0, $zero, L_80039774
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x20
        ctx->r2 = ADD32(0, 0X20);
        goto L_80039774;
    }
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sh          $v0, 0x10($s6)
    MEM_H(0X10, ctx->r22) = ctx->r2;
L_80039774:
    // sb          $s3, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r19;
    // beq         $s1, $s3, L_8003BBDC
    if (ctx->r17 == ctx->r19) {
        // sw          $s2, 0x54($s6)
        MEM_W(0X54, ctx->r22) = ctx->r18;
        goto L_8003BBDC;
    }
    // sw          $s2, 0x54($s6)
    MEM_W(0X54, ctx->r22) = ctx->r18;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // beq         $s1, $v0, L_8003BBDC
    if (ctx->r17 == ctx->r2) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8003BBDC;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // j           L_800397A4
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
    goto L_800397A4;
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_80039794:
    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_39;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_39:
L_8003979C:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800397A0:
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_800397A4:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // j           L_8003BB0C
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    goto L_8003BB0C;
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
L_800397B0:
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // nop

    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8003984C
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
        goto L_8003984C;
    }
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7FD8
    ctx->r6 = ADD32(ctx->r2, -0X7FD8);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0xA3($sp)
    do_swl(rdram, 0XA3, ctx->r29, ctx->r3);
    // swr         $v1, 0xA0($sp)
    do_swr(rdram, 0XA0, ctx->r29, ctx->r3);
    // lbu         $v0, 0x50($s6)
    ctx->r2 = MEM_BU(0X50, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x50($s6)
    MEM_B(0X50, ctx->r22) = ctx->r2;
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_80039808
    if (ctx->r2 != 0) {
        // addiu       $v1, $sp, 0xA0
        ctx->r3 = ADD32(ctx->r29, 0XA0);
        goto L_80039808;
    }
    // addiu       $v1, $sp, 0xA0
    ctx->r3 = ADD32(ctx->r29, 0XA0);
    // sb          $zero, 0x50($s6)
    MEM_B(0X50, ctx->r22) = 0;
L_80039808:
    // lb          $v0, 0x50($s6)
    ctx->r2 = MEM_BS(0X50, ctx->r22);
    // nop

    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // lw          $v1, 0x1C($s6)
    ctx->r3 = MEM_W(0X1C, ctx->r22);
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sb          $v0, 0x2($s6)
    MEM_B(0X2, ctx->r22) = ctx->r2;
    // lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(0X20, ctx->r3);
    // lw          $a0, 0x24($v1)
    ctx->r4 = MEM_W(0X24, ctx->r3);
    // lw          $a1, 0x28($v1)
    ctx->r5 = MEM_W(0X28, ctx->r3);
    // lw          $a2, 0x2C($v1)
    ctx->r6 = MEM_W(0X2C, ctx->r3);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // sw          $a0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r4;
    // sw          $a1, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r5;
    // sw          $a2, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->r6;
    // j           L_80039850
    // nop

    goto L_80039850;
    // nop

L_8003984C:
    // sb          $v1, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r3;
L_80039850:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // nop

    // slti        $v0, $v1, 0x10
    ctx->r2 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_8003BBDC
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 8
        ctx->r2 = S32(ctx->r3) << 8;
        goto L_8003BBDC;
    }
    // sll         $v0, $v1, 8
    ctx->r2 = S32(ctx->r3) << 8;
    // j           L_8003BBDC
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
    goto L_8003BBDC;
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
L_8003986C:
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lw          $a1, 0x18($s6)
    ctx->r5 = MEM_W(0X18, ctx->r22);
    // jal         0x80038300
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80038300(rdram, ctx);
    goto after_40;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_40:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_800398F0
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x10
        ctx->r2 = ctx->r16 & 0X10;
        goto L_800398F0;
    }
    // andi        $v0, $s0, 0x10
    ctx->r2 = ctx->r16 & 0X10;
    // beq         $v0, $zero, L_800398E0
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_800398E0;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v1, 0x59A4($v0)
    ctx->r3 = MEM_W(0X59A4, ctx->r2);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x5EC8
    ctx->r3 = ADD32(ctx->r3, -0X5EC8);
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // lhu         $v0, 0x2C($v1)
    ctx->r2 = MEM_HU(0X2C, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80039A90
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80039A90;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lbu         $v1, 0x1F($v1)
    ctx->r3 = MEM_BU(0X1F, ctx->r3);
    // nop

    // beq         $v1, $v0, L_80039A94
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_80039A94;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800398E0:
    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_41;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_41:
    // j           L_80039A94
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    goto L_80039A94;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_800398F0:
    // addiu       $a3, $s6, 0x30
    ctx->r7 = ADD32(ctx->r22, 0X30);
    // lh          $a0, 0x40($s6)
    ctx->r4 = MEM_HS(0X40, ctx->r22);
    // lbu         $v0, 0x50($s6)
    ctx->r2 = MEM_BU(0X50, ctx->r22);
    // lh          $a2, 0x44($s6)
    ctx->r6 = MEM_HS(0X44, ctx->r22);
    // lhu         $v1, 0x42($s6)
    ctx->r3 = MEM_HU(0X42, ctx->r22);
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // jal         0x8004A40C
    // sh          $v1, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r3;
    sub_8004A40C(rdram, ctx);
    goto after_42;
    // sh          $v1, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r3;
    after_42:
    // j           L_8003BBDC
    // nop

    goto L_8003BBDC;
    // nop

L_80039928:
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // lh          $v1, 0x38($s6)
    ctx->r3 = MEM_HS(0X38, ctx->r22);
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_80039960
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80039960;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80039960:
    // lh          $v1, 0x38($s6)
    ctx->r3 = MEM_HS(0X38, ctx->r22);
    // j           L_80039A3C
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    goto L_80039A3C;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
L_8003996C:
    // lui         $v0, 0x5555
    ctx->r2 = S32(0X5555 << 16);
    // lhu         $v1, 0x10($s6)
    ctx->r3 = MEM_HU(0X10, ctx->r22);
    // ori         $v0, $v0, 0x5556
    ctx->r2 = ctx->r2 | 0X5556;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3) >> 16;
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // lh          $a1, 0x38($s6)
    ctx->r5 = MEM_HS(0X38, ctx->r22);
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5) << 3;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $a1, $v0, 7
    ctx->r5 = S32(ctx->r2) << 7;
    // mfhi        $t1
    ctx->r9 = hi;
    // subu        $v1, $t1, $v1
    ctx->r3 = SUB32(ctx->r9, ctx->r3);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // j           L_80039A28
    // ori         $a0, $a0, 0x80
    ctx->r4 = ctx->r4 | 0X80;
    goto L_80039A28;
    // ori         $a0, $a0, 0x80
    ctx->r4 = ctx->r4 | 0X80;
L_800399CC:
    // lui         $v0, 0x5555
    ctx->r2 = S32(0X5555 << 16);
    // lhu         $v1, 0x10($s6)
    ctx->r3 = MEM_HU(0X10, ctx->r22);
    // ori         $v0, $v0, 0x5556
    ctx->r2 = ctx->r2 | 0X5556;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3) >> 16;
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // lh          $a1, 0x38($s6)
    ctx->r5 = MEM_HS(0X38, ctx->r22);
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5) << 3;
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $a1, $v0, 7
    ctx->r5 = S32(ctx->r2) << 7;
    // mfhi        $t1
    ctx->r9 = hi;
    // subu        $v1, $t1, $v1
    ctx->r3 = SUB32(ctx->r9, ctx->r3);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // ori         $a0, $a0, 0x84
    ctx->r4 = ctx->r4 | 0X84;
L_80039A28:
    // bgez        $a1, L_80039A34
    if (SIGNED(ctx->r5) >= 0) {
        // sb          $a0, 0x2($s6)
        MEM_B(0X2, ctx->r22) = ctx->r4;
        goto L_80039A34;
    }
    // sb          $a0, 0x2($s6)
    MEM_B(0X2, ctx->r22) = ctx->r4;
    // addiu       $a1, $a1, 0xFFF
    ctx->r5 = ADD32(ctx->r5, 0XFFF);
L_80039A34:
    // lh          $v1, 0x38($s6)
    ctx->r3 = MEM_HS(0X38, ctx->r22);
    // sra         $v0, $a1, 12
    ctx->r2 = S32(ctx->r5) >> 12;
L_80039A3C:
    // sh          $v0, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_80039A5C
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $a1, $v0, 12
        ctx->r5 = S32(ctx->r2) >> 12;
        goto L_80039A5C;
    }
    // sra         $a1, $v0, 12
    ctx->r5 = S32(ctx->r2) >> 12;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
    // sra         $a1, $v0, 12
    ctx->r5 = S32(ctx->r2) >> 12;
L_80039A5C:
    // lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // jal         0x80038300
    // sw          $a1, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r5;
    sub_80038300(rdram, ctx);
    goto after_43;
    // sw          $a1, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r5;
    after_43:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8003BBDC
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
        goto L_8003BBDC;
    }
    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // bne         $v0, $zero, L_8003BBCC
    if (ctx->r2 != 0) {
        // andi        $v0, $s0, 0xF
        ctx->r2 = ctx->r16 & 0XF;
        goto L_8003BBCC;
    }
    // andi        $v0, $s0, 0xF
    ctx->r2 = ctx->r16 & 0XF;
    // beq         $v0, $zero, L_8003BBDC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003BBDC;
    }
    // nop

L_80039A90:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80039A94:
    // j           L_8003BBDC
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
    goto L_8003BBDC;
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_80039A9C:
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // lh          $v1, 0x38($s6)
    ctx->r3 = MEM_HS(0X38, ctx->r22);
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_80039AD4
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80039AD4;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80039AD4:
    // lh          $v1, 0x38($s6)
    ctx->r3 = MEM_HS(0X38, ctx->r22);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_80039AFC
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $a1, $v0, 12
        ctx->r5 = S32(ctx->r2) >> 12;
        goto L_80039AFC;
    }
    // sra         $a1, $v0, 12
    ctx->r5 = S32(ctx->r2) >> 12;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
    // sra         $a1, $v0, 12
    ctx->r5 = S32(ctx->r2) >> 12;
L_80039AFC:
    // lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lb          $a2, 0x50($s6)
    ctx->r6 = MEM_BS(0X50, ctx->r22);
    // or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // jal         0x800381A8
    // sw          $a1, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r5;
    sub_800381A8(rdram, ctx);
    goto after_44;
    // sw          $a1, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r5;
    after_44:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8003B72C
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
        goto L_8003B72C;
    }
    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // beq         $v0, $zero, L_8003B72C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B72C;
    }
    // nop

    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_45;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_45:
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // j           L_8003B72C
    // sb          $v0, 0x8($s6)
    MEM_B(0X8, ctx->r22) = ctx->r2;
    goto L_8003B72C;
    // sb          $v0, 0x8($s6)
    MEM_B(0X8, ctx->r22) = ctx->r2;
L_80039B3C:
    // lhu         $v0, 0x34($s6)
    ctx->r2 = MEM_HU(0X34, ctx->r22);
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sh          $v0, 0x34($s6)
    MEM_H(0X34, ctx->r22) = ctx->r2;
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // bne         $v1, $v0, L_80039CF4
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0xC8
        ctx->r2 = ADD32(0, 0XC8);
        goto L_80039CF4;
    }
    // addiu       $v0, $zero, 0xC8
    ctx->r2 = ADD32(0, 0XC8);
    // bne         $s1, $v0, L_80039BBC
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0xEE
        ctx->r2 = ADD32(0, 0XEE);
        goto L_80039BBC;
    }
    // addiu       $v0, $zero, 0xEE
    ctx->r2 = ADD32(0, 0XEE);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0x35
    ctx->r6 = ADD32(0, 0X35);
    // addiu       $s2, $s6, 0x20
    ctx->r18 = ADD32(ctx->r22, 0X20);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s0, $s6, 0x40
    ctx->r16 = ADD32(ctx->r22, 0X40);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // addiu       $s1, $s6, 0x30
    ctx->r17 = ADD32(ctx->r22, 0X30);
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_46;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_46:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_80039CD4
    // addiu       $a2, $zero, 0xC9
    ctx->r6 = ADD32(0, 0XC9);
    goto L_80039CD4;
    // addiu       $a2, $zero, 0xC9
    ctx->r6 = ADD32(0, 0XC9);
L_80039BBC:
    // bne         $s1, $v0, L_80039C1C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0xE4
        ctx->r2 = ADD32(0, 0XE4);
        goto L_80039C1C;
    }
    // addiu       $v0, $zero, 0xE4
    ctx->r2 = ADD32(0, 0XE4);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0x8D
    ctx->r6 = ADD32(0, 0X8D);
    // addiu       $s2, $s6, 0x20
    ctx->r18 = ADD32(ctx->r22, 0X20);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s0, $s6, 0x40
    ctx->r16 = ADD32(ctx->r22, 0X40);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // addiu       $s1, $s6, 0x30
    ctx->r17 = ADD32(ctx->r22, 0X30);
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_47;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_47:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_80039CD4
    // addiu       $a2, $zero, 0xEF
    ctx->r6 = ADD32(0, 0XEF);
    goto L_80039CD4;
    // addiu       $a2, $zero, 0xEF
    ctx->r6 = ADD32(0, 0XEF);
L_80039C1C:
    // bne         $s1, $v0, L_80039C7C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0xD3
        ctx->r2 = ADD32(0, 0XD3);
        goto L_80039C7C;
    }
    // addiu       $v0, $zero, 0xD3
    ctx->r2 = ADD32(0, 0XD3);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0x82
    ctx->r6 = ADD32(0, 0X82);
    // addiu       $s2, $s6, 0x20
    ctx->r18 = ADD32(ctx->r22, 0X20);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s0, $s6, 0x40
    ctx->r16 = ADD32(ctx->r22, 0X40);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // addiu       $s1, $s6, 0x30
    ctx->r17 = ADD32(ctx->r22, 0X30);
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_48;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_48:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_80039CD4
    // addiu       $a2, $zero, 0xE5
    ctx->r6 = ADD32(0, 0XE5);
    goto L_80039CD4;
    // addiu       $a2, $zero, 0xE5
    ctx->r6 = ADD32(0, 0XE5);
L_80039C7C:
    // bne         $s1, $v0, L_80039CF4
    if (ctx->r17 != ctx->r2) {
        // addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
        goto L_80039CF4;
    }
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0x53
    ctx->r6 = ADD32(0, 0X53);
    // addiu       $s2, $s6, 0x20
    ctx->r18 = ADD32(ctx->r22, 0X20);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s0, $s6, 0x40
    ctx->r16 = ADD32(ctx->r22, 0X40);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // addiu       $s1, $s6, 0x30
    ctx->r17 = ADD32(ctx->r22, 0X30);
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_49;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_49:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // addiu       $a2, $zero, 0xD4
    ctx->r6 = ADD32(0, 0XD4);
L_80039CD4:
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_50;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_50:
L_80039CF4:
    // lh          $v0, 0x10($s6)
    ctx->r2 = MEM_HS(0X10, ctx->r22);
    // nop

    // slti        $v0, $v0, 0x10
    ctx->r2 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_80039D2C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80039D2C;
    }
    // nop

    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lhu         $v1, 0x3C($s6)
    ctx->r3 = MEM_HU(0X3C, ctx->r22);
    // addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // sh          $v1, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r3;
    // j           L_80039D4C
    // addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    goto L_80039D4C;
    // addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
L_80039D2C:
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lhu         $v1, 0x3C($s6)
    ctx->r3 = MEM_HU(0X3C, ctx->r22);
    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // sh          $v1, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r3;
    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
L_80039D4C:
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // j           L_8003BB0C
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    goto L_8003BB0C;
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
L_80039D5C:
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lw          $a1, 0x18($s6)
    ctx->r5 = MEM_W(0X18, ctx->r22);
    // jal         0x80038300
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    sub_80038300(rdram, ctx);
    goto after_51;
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_51:
    // beq         $v0, $zero, L_80039D78
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_80039D78;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_80039D78:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // j           L_8003BB0C
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    goto L_8003BB0C;
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
L_80039D84:
    // addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lhu         $v0, 0x3C($s6)
    ctx->r2 = MEM_HU(0X3C, ctx->r22);
    // lw          $a1, 0x18($s6)
    ctx->r5 = MEM_W(0X18, ctx->r22);
    // addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, 0XE0);
    // jal         0x80038300
    // sh          $v0, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r2;
    sub_80038300(rdram, ctx);
    goto after_52;
    // sh          $v0, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r2;
    after_52:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_80039DC4
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
        goto L_80039DC4;
    }
    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // beq         $v0, $zero, L_80039DC0
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_80039DC0;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_53;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_53:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80039DC0:
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_80039DC4:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // j           L_8003BB0C
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    goto L_8003BB0C;
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
L_80039DD0:
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lw          $a1, 0x18($s6)
    ctx->r5 = MEM_W(0X18, ctx->r22);
    // jal         0x80038300
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    sub_80038300(rdram, ctx);
    goto after_54;
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_54:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_80039E04
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
        goto L_80039E04;
    }
    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // beq         $v0, $zero, L_80039E00
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_80039E00;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_55;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_55:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80039E00:
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_80039E04:
    // lh          $v0, 0x10($s6)
    ctx->r2 = MEM_HS(0X10, ctx->r22);
    // nop

    // slti        $v0, $v0, 0x20
    ctx->r2 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // beq         $v0, $zero, L_8003B744
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0xD
        ctx->r3 = ADD32(0, 0XD);
        goto L_8003B744;
    }
    // addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
    // lh          $v0, 0x10($s6)
    ctx->r2 = MEM_HS(0X10, ctx->r22);
    // sb          $v1, 0x7($s6)
    MEM_B(0X7, ctx->r22) = ctx->r3;
    // j           L_8003B740
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    goto L_8003B740;
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
L_80039E28:
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lw          $a1, 0x18($s6)
    ctx->r5 = MEM_W(0X18, ctx->r22);
    // jal         0x80038300
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    sub_80038300(rdram, ctx);
    goto after_56;
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_56:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_80039FC4
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
        goto L_80039FC4;
    }
    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // beq         $v0, $zero, L_80039E58
    if (ctx->r2 == 0) {
        // addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
        goto L_80039E58;
    }
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_57;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_57:
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_80039E58:
    // lui         $s4, 0x8184
    ctx->r20 = S32(0X8184 << 16);
    // ori         $s4, $s4, 0x8DA9
    ctx->r20 = ctx->r20 | 0X8DA9;
    // addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // addiu       $s0, $sp, 0xA8
    ctx->r16 = ADD32(ctx->r29, 0XA8);
    // addiu       $s2, $zero, 0x600
    ctx->r18 = ADD32(0, 0X600);
L_80039E6C:
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_58;
    // nop

    after_58:
    // mult        $v0, $s4
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t1
    ctx->r9 = hi;
    // addu        $v1, $t1, $v0
    ctx->r3 = ADD32(ctx->r9, ctx->r2);
    // sra         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3) >> 10;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // subu        $v1, $s5, $v1
    ctx->r3 = SUB32(ctx->r21, ctx->r3);
    // jal         0x80078AC4
    // sh          $v1, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_59;
    // sh          $v1, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = ctx->r3;
    after_59:
    // bgez        $v0, L_80039EA8
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $v1, $v0, 10
        ctx->r3 = S32(ctx->r2) >> 10;
        goto L_80039EA8;
    }
    // sra         $v1, $v0, 10
    ctx->r3 = S32(ctx->r2) >> 10;
    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
    // sra         $v1, $v0, 10
    ctx->r3 = S32(ctx->r2) >> 10;
L_80039EA8:
    // addiu       $v0, $zero, -0x30
    ctx->r2 = ADD32(0, -0X30);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x80078AC4
    // sh          $v0, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_60;
    // sh          $v0, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = ctx->r2;
    after_60:
    // mult        $v0, $s4
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lh          $a0, 0xA8($sp)
    ctx->r4 = MEM_HS(0XA8, ctx->r29);
    // mfhi        $t1
    ctx->r9 = hi;
    // addu        $v1, $t1, $v0
    ctx->r3 = ADD32(ctx->r9, ctx->r2);
    // sra         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3) >> 10;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // subu        $v1, $s5, $v1
    ctx->r3 = SUB32(ctx->r21, ctx->r3);
    // sh          $v1, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r3;
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // nop

    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // lw          $v0, 0x28($s6)
    ctx->r2 = MEM_W(0X28, ctx->r22);
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x3E
    ctx->r2 = ADD32(0, 0X3E);
    // bne         $s1, $v0, L_80039F24
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x6C
        ctx->r2 = ADD32(0, 0X6C);
        goto L_80039F24;
    }
    // addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // j           L_80039F94
    // addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
    goto L_80039F94;
    // addiu       $a2, $zero, 0x3F
    ctx->r6 = ADD32(0, 0X3F);
L_80039F24:
    // bne         $s1, $v0, L_80039F3C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x48
        ctx->r2 = ADD32(0, 0X48);
        goto L_80039F3C;
    }
    // addiu       $v0, $zero, 0x48
    ctx->r2 = ADD32(0, 0X48);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // j           L_80039F94
    // addiu       $a2, $zero, 0x6D
    ctx->r6 = ADD32(0, 0X6D);
    goto L_80039F94;
    // addiu       $a2, $zero, 0x6D
    ctx->r6 = ADD32(0, 0X6D);
L_80039F3C:
    // bne         $s1, $v0, L_80039F54
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x93
        ctx->r2 = ADD32(0, 0X93);
        goto L_80039F54;
    }
    // addiu       $v0, $zero, 0x93
    ctx->r2 = ADD32(0, 0X93);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // j           L_80039F94
    // addiu       $a2, $zero, 0x49
    ctx->r6 = ADD32(0, 0X49);
    goto L_80039F94;
    // addiu       $a2, $zero, 0x49
    ctx->r6 = ADD32(0, 0X49);
L_80039F54:
    // bne         $s1, $v0, L_80039F6C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x71
        ctx->r2 = ADD32(0, 0X71);
        goto L_80039F6C;
    }
    // addiu       $v0, $zero, 0x71
    ctx->r2 = ADD32(0, 0X71);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // j           L_80039F94
    // addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
    goto L_80039F94;
    // addiu       $a2, $zero, 0x94
    ctx->r6 = ADD32(0, 0X94);
L_80039F6C:
    // bne         $s1, $v0, L_80039F84
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x7A
        ctx->r2 = ADD32(0, 0X7A);
        goto L_80039F84;
    }
    // addiu       $v0, $zero, 0x7A
    ctx->r2 = ADD32(0, 0X7A);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // j           L_80039F94
    // addiu       $a2, $zero, 0x72
    ctx->r6 = ADD32(0, 0X72);
    goto L_80039F94;
    // addiu       $a2, $zero, 0x72
    ctx->r6 = ADD32(0, 0X72);
L_80039F84:
    // bne         $s1, $v0, L_80039FB0
    if (ctx->r17 != ctx->r2) {
        // addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
        goto L_80039FB0;
    }
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $a2, $zero, 0x7B
    ctx->r6 = ADD32(0, 0X7B);
L_80039F94:
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addiu       $a3, $sp, 0xB0
    ctx->r7 = ADD32(ctx->r29, 0XB0);
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_61;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_61:
L_80039FB0:
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // slti        $v0, $s3, 0x4
    ctx->r2 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // bne         $v0, $zero, L_80039E6C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_80039E6C;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_80039FC4:
    // lh          $v0, 0x10($s6)
    ctx->r2 = MEM_HS(0X10, ctx->r22);
    // nop

    // slti        $v0, $v0, 0x20
    ctx->r2 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // beq         $v0, $zero, L_80039FE8
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0xD
        ctx->r3 = ADD32(0, 0XD);
        goto L_80039FE8;
    }
    // addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
    // lh          $v0, 0x10($s6)
    ctx->r2 = MEM_HS(0X10, ctx->r22);
    // sb          $v1, 0x7($s6)
    MEM_B(0X7, ctx->r22) = ctx->r3;
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
L_80039FE8:
    // lhu         $v0, 0x42($s6)
    ctx->r2 = MEM_HU(0X42, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // j           L_8003BBDC
    // sh          $v0, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r2;
    goto L_8003BBDC;
    // sh          $v0, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r2;
L_80039FFC:
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lw          $a1, 0x18($s6)
    ctx->r5 = MEM_W(0X18, ctx->r22);
    // jal         0x80038300
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80038300(rdram, ctx);
    goto after_62;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_62:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8003A114
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
        goto L_8003A114;
    }
    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // beq         $v0, $zero, L_8003A028
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003A028;
    }
    // nop

    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_63;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_63:
L_8003A028:
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lui         $s1, 0x8184
    ctx->r17 = S32(0X8184 << 16);
    // ori         $s1, $s1, 0x8DA9
    ctx->r17 = ctx->r17 | 0X8DA9;
    // addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
L_8003A038:
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_64;
    // nop

    after_64:
    // mult        $v0, $s1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t1
    ctx->r9 = hi;
    // addu        $v1, $t1, $v0
    ctx->r3 = ADD32(ctx->r9, ctx->r2);
    // sra         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3) >> 10;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // subu        $v1, $s2, $v1
    ctx->r3 = SUB32(ctx->r18, ctx->r3);
    // jal         0x80078AC4
    // sh          $v1, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_65;
    // sh          $v1, 0xC0($sp)
    MEM_H(0XC0, ctx->r29) = ctx->r3;
    after_65:
    // bgez        $v0, L_8003A074
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $v1, $v0, 10
        ctx->r3 = S32(ctx->r2) >> 10;
        goto L_8003A074;
    }
    // sra         $v1, $v0, 10
    ctx->r3 = S32(ctx->r2) >> 10;
    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
    // sra         $v1, $v0, 10
    ctx->r3 = S32(ctx->r2) >> 10;
L_8003A074:
    // addiu       $v0, $zero, -0x30
    ctx->r2 = ADD32(0, -0X30);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x80078AC4
    // sh          $v0, 0xC2($sp)
    MEM_H(0XC2, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_66;
    // sh          $v0, 0xC2($sp)
    MEM_H(0XC2, ctx->r29) = ctx->r2;
    after_66:
    // mult        $v0, $s1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    // lh          $a1, 0xC0($sp)
    ctx->r5 = MEM_HS(0XC0, ctx->r29);
    // mfhi        $t1
    ctx->r9 = hi;
    // addu        $v1, $t1, $v0
    ctx->r3 = ADD32(ctx->r9, ctx->r2);
    // sra         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3) >> 10;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // subu        $v1, $s2, $v1
    ctx->r3 = SUB32(ctx->r18, ctx->r3);
    // sh          $v1, 0xC4($sp)
    MEM_H(0XC4, ctx->r29) = ctx->r3;
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // addiu       $a3, $sp, 0xC8
    ctx->r7 = ADD32(ctx->r29, 0XC8);
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sw          $v0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sw          $v0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r2;
    // lw          $v0, 0x28($s6)
    ctx->r2 = MEM_W(0X28, ctx->r22);
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r2;
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $v0, $sp, 0xC0
    ctx->r2 = ADD32(ctx->r29, 0XC0);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x600
    ctx->r2 = ADD32(0, 0X600);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_67;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_67:
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_8003A038
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8003A038;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_8003A114:
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // lhu         $v0, 0x10($s6)
    ctx->r2 = MEM_HU(0X10, ctx->r22);
    // ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v1, $t1, 1
    ctx->r3 = S32(ctx->r9) >> 1;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // bne         $a0, $zero, L_8003A238
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8003A238;
    }
    // nop

    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // lui         $s1, 0x8184
    ctx->r17 = S32(0X8184 << 16);
    // ori         $s1, $s1, 0x8DA9
    ctx->r17 = ctx->r17 | 0X8DA9;
    // addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
L_8003A164:
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_68;
    // nop

    after_68:
    // mult        $v0, $s1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t1
    ctx->r9 = hi;
    // addu        $v1, $t1, $v0
    ctx->r3 = ADD32(ctx->r9, ctx->r2);
    // sra         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3) >> 10;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // subu        $v1, $s2, $v1
    ctx->r3 = SUB32(ctx->r18, ctx->r3);
    // jal         0x80078AC4
    // sh          $v1, 0xD8($sp)
    MEM_H(0XD8, ctx->r29) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_69;
    // sh          $v1, 0xD8($sp)
    MEM_H(0XD8, ctx->r29) = ctx->r3;
    after_69:
    // bgez        $v0, L_8003A1A0
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $v1, $v0, 10
        ctx->r3 = S32(ctx->r2) >> 10;
        goto L_8003A1A0;
    }
    // sra         $v1, $v0, 10
    ctx->r3 = S32(ctx->r2) >> 10;
    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
    // sra         $v1, $v0, 10
    ctx->r3 = S32(ctx->r2) >> 10;
L_8003A1A0:
    // addiu       $v0, $zero, -0x30
    ctx->r2 = ADD32(0, -0X30);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // jal         0x80078AC4
    // sh          $v0, 0xDA($sp)
    MEM_H(0XDA, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_70;
    // sh          $v0, 0xDA($sp)
    MEM_H(0XDA, ctx->r29) = ctx->r2;
    after_70:
    // mult        $v0, $s1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    // lh          $a1, 0xD8($sp)
    ctx->r5 = MEM_HS(0XD8, ctx->r29);
    // mfhi        $t1
    ctx->r9 = hi;
    // addu        $v1, $t1, $v0
    ctx->r3 = ADD32(ctx->r9, ctx->r2);
    // sra         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3) >> 10;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // subu        $v1, $s2, $v1
    ctx->r3 = SUB32(ctx->r18, ctx->r3);
    // sh          $v1, 0xDC($sp)
    MEM_H(0XDC, ctx->r29) = ctx->r3;
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // addiu       $a3, $sp, 0xE8
    ctx->r7 = ADD32(ctx->r29, 0XE8);
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sw          $v0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sw          $v0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r2;
    // lw          $v0, 0x28($s6)
    ctx->r2 = MEM_W(0X28, ctx->r22);
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r2;
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $v0, $sp, 0xD8
    ctx->r2 = ADD32(ctx->r29, 0XD8);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x600
    ctx->r2 = ADD32(0, 0X600);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_71;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_71:
    // blez        $s0, L_8003A164
    if (SIGNED(ctx->r16) <= 0) {
        // nop
    
        goto L_8003A164;
    }
    // nop

L_8003A238:
    // lh          $v0, 0x10($s6)
    ctx->r2 = MEM_HS(0X10, ctx->r22);
    // nop

    // slti        $v0, $v0, 0x20
    ctx->r2 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // beq         $v0, $zero, L_8003A25C
    if (ctx->r2 == 0) {
        // addiu       $v1, $zero, 0xD
        ctx->r3 = ADD32(0, 0XD);
        goto L_8003A25C;
    }
    // addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
    // lh          $v0, 0x10($s6)
    ctx->r2 = MEM_HS(0X10, ctx->r22);
    // sb          $v1, 0x7($s6)
    MEM_B(0X7, ctx->r22) = ctx->r3;
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
L_8003A25C:
    // lhu         $v0, 0x42($s6)
    ctx->r2 = MEM_HU(0X42, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // j           L_8003BBDC
    // sh          $v0, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r2;
    goto L_8003BBDC;
    // sh          $v0, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r2;
L_8003A270:
    // lhu         $v0, 0x34($s6)
    ctx->r2 = MEM_HU(0X34, ctx->r22);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // sh          $v0, 0x34($s6)
    MEM_H(0X34, ctx->r22) = ctx->r2;
    // lh          $v0, 0x50($s6)
    ctx->r2 = MEM_HS(0X50, ctx->r22);
    // lw          $s2, 0x4C($s6)
    ctx->r18 = MEM_W(0X4C, ctx->r22);
    // beq         $v0, $v1, L_8003A3C8
    if (ctx->r2 == ctx->r3) {
        // addiu       $v0, $zero, 0xCA
        ctx->r2 = ADD32(0, 0XCA);
        goto L_8003A3C8;
    }
    // addiu       $v0, $zero, 0xCA
    ctx->r2 = ADD32(0, 0XCA);
    // beq         $s1, $v0, L_8003A2D8
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8003A2D8;
    }
    // nop

    // addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // beq         $s1, $v0, L_8003A2D8
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8003A2D8;
    }
    // nop

    // addiu       $v0, $zero, 0xD0
    ctx->r2 = ADD32(0, 0XD0);
    // beq         $s1, $v0, L_8003A2D8
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8003A2D8;
    }
    // nop

    // addiu       $v0, $zero, 0xE6
    ctx->r2 = ADD32(0, 0XE6);
    // beq         $s1, $v0, L_8003A2D8
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8003A2D8;
    }
    // nop

    // addiu       $v0, $zero, 0xDB
    ctx->r2 = ADD32(0, 0XDB);
    // beq         $s1, $v0, L_8003A2D8
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8003A2D8;
    }
    // nop

    // addiu       $v0, $zero, 0xDE
    ctx->r2 = ADD32(0, 0XDE);
    // bne         $s1, $v0, L_8003A300
    if (ctx->r17 != ctx->r2) {
        // nop
    
        goto L_8003A300;
    }
    // nop

L_8003A2D8:
    // lbu         $a0, 0xB($s2)
    ctx->r4 = MEM_BU(0XB, ctx->r18);
    // lbu         $a1, 0x8($s2)
    ctx->r5 = MEM_BU(0X8, ctx->r18);
    // lh          $a2, 0x2A($s2)
    ctx->r6 = MEM_HS(0X2A, ctx->r18);
    // lh          $a3, 0x50($s6)
    ctx->r7 = MEM_HS(0X50, ctx->r22);
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // jal         0x80033E30
    // addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    sub_80033E30(rdram, ctx);
    goto after_72;
    // addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_72:
    // j           L_8003A360
    // addiu       $a0, $sp, 0x118
    ctx->r4 = ADD32(ctx->r29, 0X118);
    goto L_8003A360;
    // addiu       $a0, $sp, 0x118
    ctx->r4 = ADD32(ctx->r29, 0X118);
L_8003A300:
    // addiu       $v0, $zero, 0xCD
    ctx->r2 = ADD32(0, 0XCD);
    // beq         $s1, $v0, L_8003A324
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8003A324;
    }
    // nop

    // addiu       $v0, $zero, 0xEB
    ctx->r2 = ADD32(0, 0XEB);
    // beq         $s1, $v0, L_8003A324
    if (ctx->r17 == ctx->r2) {
        // nop
    
        goto L_8003A324;
    }
    // nop

    // addiu       $v0, $zero, 0xD8
    ctx->r2 = ADD32(0, 0XD8);
    // bne         $s1, $v0, L_8003A360
    if (ctx->r17 != ctx->r2) {
        // addiu       $a0, $sp, 0x118
        ctx->r4 = ADD32(ctx->r29, 0X118);
        goto L_8003A360;
    }
    // addiu       $a0, $sp, 0x118
    ctx->r4 = ADD32(ctx->r29, 0X118);
L_8003A324:
    // lbu         $a1, 0xB($s2)
    ctx->r5 = MEM_BU(0XB, ctx->r18);
    // lh          $a2, 0x52($s6)
    ctx->r6 = MEM_HS(0X52, ctx->r22);
    // lh          $a3, 0x50($s6)
    ctx->r7 = MEM_HS(0X50, ctx->r22);
    // addiu       $v0, $sp, 0x120
    ctx->r2 = ADD32(ctx->r29, 0X120);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $a0, 0xA4($s2)
    ctx->r4 = MEM_W(0XA4, ctx->r18);
    // jal         0x80035B80
    // addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    sub_80035B80(rdram, ctx);
    goto after_73;
    // addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    after_73:
    // lhu         $v0, 0x120($sp)
    ctx->r2 = MEM_HU(0X120, ctx->r29);
    // lhu         $v1, 0x124($sp)
    ctx->r3 = MEM_HU(0X124, ctx->r29);
    // lhu         $a0, 0x128($sp)
    ctx->r4 = MEM_HU(0X128, ctx->r29);
    // sh          $v0, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r2;
    // sh          $v1, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = ctx->r3;
    // sh          $a0, 0xE4($sp)
    MEM_H(0XE4, ctx->r29) = ctx->r4;
    // addiu       $a0, $sp, 0x118
    ctx->r4 = ADD32(ctx->r29, 0X118);
L_8003A360:
    // addiu       $s0, $sp, 0xF8
    ctx->r16 = ADD32(ctx->r29, 0XF8);
    // sh          $zero, 0x118($sp)
    MEM_H(0X118, ctx->r29) = 0;
    // lhu         $v0, 0x8E($s2)
    ctx->r2 = MEM_HU(0X8E, ctx->r18);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // sh          $zero, 0x11C($sp)
    MEM_H(0X11C, ctx->r29) = 0;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // jal         0x80074EC4
    // sh          $v0, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = ctx->r2;
    RotMatrix(rdram, ctx);
    goto after_74;
    // sh          $v0, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = ctx->r2;
    after_74:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0xE0
    ctx->r5 = ADD32(ctx->r29, 0XE0);
    // jal         0x80074CF4
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    ApplyMatrixSV(rdram, ctx);
    goto after_75;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_75:
    // lh          $v1, 0xE0($sp)
    ctx->r3 = MEM_HS(0XE0, ctx->r29);
    // lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(0X74, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lh          $v1, 0xE2($sp)
    ctx->r3 = MEM_HS(0XE2, ctx->r29);
    // lw          $v0, 0x78($s2)
    ctx->r2 = MEM_W(0X78, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r2;
    // lh          $v1, 0xE4($sp)
    ctx->r3 = MEM_HS(0XE4, ctx->r29);
    // lw          $v0, 0x7C($s2)
    ctx->r2 = MEM_W(0X7C, ctx->r18);
    // j           L_8003A3E4
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    goto L_8003A3E4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8003A3C8:
    // lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(0X74, ctx->r18);
    // nop

    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lw          $v0, 0x78($s2)
    ctx->r2 = MEM_W(0X78, ctx->r18);
    // nop

    // sw          $v0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r2;
    // lw          $v0, 0x7C($s2)
    ctx->r2 = MEM_W(0X7C, ctx->r18);
L_8003A3E4:
    // nop

    // sw          $v0, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r2;
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    // bne         $v1, $v0, L_8003A774
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0xCA
        ctx->r2 = ADD32(0, 0XCA);
        goto L_8003A774;
    }
    // addiu       $v0, $zero, 0xCA
    ctx->r2 = ADD32(0, 0XCA);
    // bne         $s1, $v0, L_8003A45C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0xEB
        ctx->r2 = ADD32(0, 0XEB);
        goto L_8003A45C;
    }
    // addiu       $v0, $zero, 0xEB
    ctx->r2 = ADD32(0, 0XEB);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xCB
    ctx->r6 = ADD32(0, 0XCB);
    // addiu       $s2, $s6, 0x20
    ctx->r18 = ADD32(ctx->r22, 0X20);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s0, $s6, 0x40
    ctx->r16 = ADD32(ctx->r22, 0X40);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // addiu       $s1, $s6, 0x30
    ctx->r17 = ADD32(ctx->r22, 0X30);
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_76;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_76:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_8003A754
    // addiu       $a2, $zero, 0x3D
    ctx->r6 = ADD32(0, 0X3D);
    goto L_8003A754;
    // addiu       $a2, $zero, 0x3D
    ctx->r6 = ADD32(0, 0X3D);
L_8003A45C:
    // bne         $s1, $v0, L_8003A4BC
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0xCD
        ctx->r2 = ADD32(0, 0XCD);
        goto L_8003A4BC;
    }
    // addiu       $v0, $zero, 0xCD
    ctx->r2 = ADD32(0, 0XCD);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xEC
    ctx->r6 = ADD32(0, 0XEC);
    // addiu       $s2, $s6, 0x20
    ctx->r18 = ADD32(ctx->r22, 0X20);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s0, $s6, 0x40
    ctx->r16 = ADD32(ctx->r22, 0X40);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // addiu       $s1, $s6, 0x30
    ctx->r17 = ADD32(ctx->r22, 0X30);
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_77;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_77:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_8003A754
    // addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
    goto L_8003A754;
    // addiu       $a2, $zero, 0x8A
    ctx->r6 = ADD32(0, 0X8A);
L_8003A4BC:
    // bne         $s1, $v0, L_8003A51C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0xE1
        ctx->r2 = ADD32(0, 0XE1);
        goto L_8003A51C;
    }
    // addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xCE
    ctx->r6 = ADD32(0, 0XCE);
    // addiu       $s2, $s6, 0x20
    ctx->r18 = ADD32(ctx->r22, 0X20);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s0, $s6, 0x40
    ctx->r16 = ADD32(ctx->r22, 0X40);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // addiu       $s1, $s6, 0x30
    ctx->r17 = ADD32(ctx->r22, 0X30);
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_78;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_78:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_8003A754
    // addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    goto L_8003A754;
    // addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
L_8003A51C:
    // bne         $s1, $v0, L_8003A57C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0xD0
        ctx->r2 = ADD32(0, 0XD0);
        goto L_8003A57C;
    }
    // addiu       $v0, $zero, 0xD0
    ctx->r2 = ADD32(0, 0XD0);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xE2
    ctx->r6 = ADD32(0, 0XE2);
    // addiu       $s2, $s6, 0x20
    ctx->r18 = ADD32(ctx->r22, 0X20);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s0, $s6, 0x40
    ctx->r16 = ADD32(ctx->r22, 0X40);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // addiu       $s1, $s6, 0x30
    ctx->r17 = ADD32(ctx->r22, 0X30);
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_79;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_79:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_8003A754
    // addiu       $a2, $zero, 0x81
    ctx->r6 = ADD32(0, 0X81);
    goto L_8003A754;
    // addiu       $a2, $zero, 0x81
    ctx->r6 = ADD32(0, 0X81);
L_8003A57C:
    // bne         $s1, $v0, L_8003A5DC
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0xE6
        ctx->r2 = ADD32(0, 0XE6);
        goto L_8003A5DC;
    }
    // addiu       $v0, $zero, 0xE6
    ctx->r2 = ADD32(0, 0XE6);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xD1
    ctx->r6 = ADD32(0, 0XD1);
    // addiu       $s2, $s6, 0x20
    ctx->r18 = ADD32(ctx->r22, 0X20);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s0, $s6, 0x40
    ctx->r16 = ADD32(ctx->r22, 0X40);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // addiu       $s1, $s6, 0x30
    ctx->r17 = ADD32(ctx->r22, 0X30);
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_80;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_80:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_8003A754
    // addiu       $a2, $zero, 0x52
    ctx->r6 = ADD32(0, 0X52);
    goto L_8003A754;
    // addiu       $a2, $zero, 0x52
    ctx->r6 = ADD32(0, 0X52);
L_8003A5DC:
    // bne         $s1, $v0, L_8003A63C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0xD8
        ctx->r2 = ADD32(0, 0XD8);
        goto L_8003A63C;
    }
    // addiu       $v0, $zero, 0xD8
    ctx->r2 = ADD32(0, 0XD8);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xE7
    ctx->r6 = ADD32(0, 0XE7);
    // addiu       $s2, $s6, 0x20
    ctx->r18 = ADD32(ctx->r22, 0X20);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s0, $s6, 0x40
    ctx->r16 = ADD32(ctx->r22, 0X40);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // addiu       $s1, $s6, 0x30
    ctx->r17 = ADD32(ctx->r22, 0X30);
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_81;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_81:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_8003A754
    // addiu       $a2, $zero, 0x86
    ctx->r6 = ADD32(0, 0X86);
    goto L_8003A754;
    // addiu       $a2, $zero, 0x86
    ctx->r6 = ADD32(0, 0X86);
L_8003A63C:
    // bne         $s1, $v0, L_8003A69C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0xDB
        ctx->r2 = ADD32(0, 0XDB);
        goto L_8003A69C;
    }
    // addiu       $v0, $zero, 0xDB
    ctx->r2 = ADD32(0, 0XDB);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xD9
    ctx->r6 = ADD32(0, 0XD9);
    // addiu       $s2, $s6, 0x20
    ctx->r18 = ADD32(ctx->r22, 0X20);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s0, $s6, 0x40
    ctx->r16 = ADD32(ctx->r22, 0X40);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // addiu       $s1, $s6, 0x30
    ctx->r17 = ADD32(ctx->r22, 0X30);
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_82;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_82:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_8003A754
    // addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    goto L_8003A754;
    // addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
L_8003A69C:
    // bne         $s1, $v0, L_8003A6FC
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0xDE
        ctx->r2 = ADD32(0, 0XDE);
        goto L_8003A6FC;
    }
    // addiu       $v0, $zero, 0xDE
    ctx->r2 = ADD32(0, 0XDE);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xDC
    ctx->r6 = ADD32(0, 0XDC);
    // addiu       $s2, $s6, 0x20
    ctx->r18 = ADD32(ctx->r22, 0X20);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s0, $s6, 0x40
    ctx->r16 = ADD32(ctx->r22, 0X40);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // addiu       $s1, $s6, 0x30
    ctx->r17 = ADD32(ctx->r22, 0X30);
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_83;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_83:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_8003A754
    // addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    goto L_8003A754;
    // addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
L_8003A6FC:
    // bne         $s1, $v0, L_8003A774
    if (ctx->r17 != ctx->r2) {
        // addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
        goto L_8003A774;
    }
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xDF
    ctx->r6 = ADD32(0, 0XDF);
    // addiu       $s2, $s6, 0x20
    ctx->r18 = ADD32(ctx->r22, 0X20);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $s0, $s6, 0x40
    ctx->r16 = ADD32(ctx->r22, 0X40);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // addiu       $s1, $s6, 0x30
    ctx->r17 = ADD32(ctx->r22, 0X30);
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_84;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_84:
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // addiu       $a2, $zero, 0x7E
    ctx->r6 = ADD32(0, 0X7E);
L_8003A754:
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_85;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_85:
L_8003A774:
    // lh          $v0, 0x10($s6)
    ctx->r2 = MEM_HS(0X10, ctx->r22);
    // nop

    // slti        $v0, $v0, 0x18
    ctx->r2 = SIGNED(ctx->r2) < 0X18 ? 1 : 0;
    // beq         $v0, $zero, L_8003A7AC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003A7AC;
    }
    // nop

    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lhu         $v1, 0x3C($s6)
    ctx->r3 = MEM_HU(0X3C, ctx->r22);
    // addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // sh          $v1, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r3;
    // j           L_8003A7CC
    // addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
    goto L_8003A7CC;
    // addiu       $v0, $v0, -0x40
    ctx->r2 = ADD32(ctx->r2, -0X40);
L_8003A7AC:
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lhu         $v1, 0x3C($s6)
    ctx->r3 = MEM_HU(0X3C, ctx->r22);
    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // sh          $v1, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r3;
    // addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
L_8003A7CC:
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // j           L_8003BB0C
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    goto L_8003BB0C;
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
L_8003A7DC:
    // lh          $a0, 0x10($s6)
    ctx->r4 = MEM_HS(0X10, ctx->r22);
    // jal         0x800744C4
    // sll         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) << 11;
    rcos(rdram, ctx);
    goto after_86;
    // sll         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) << 11;
    after_86:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // bgez        $v1, L_8003A7F8
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003A7F8;
    }
    // nop

    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_8003A7F8:
    // lhu         $v0, 0x50($s6)
    ctx->r2 = MEM_HU(0X50, ctx->r22);
    // lw          $s2, 0x4C($s6)
    ctx->r18 = MEM_W(0X4C, ctx->r22);
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // sh          $v1, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r3;
    // sh          $v1, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r3;
    // sh          $v1, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r3;
    // addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // sh          $v0, 0x50($s6)
    MEM_H(0X50, ctx->r22) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, -0x80
    ctx->r2 = SIGNED(ctx->r2) < -0X80 ? 1 : 0;
    // bne         $v0, $zero, L_8003A830
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x80
        ctx->r2 = ADD32(0, -0X80);
        goto L_8003A830;
    }
    // addiu       $v0, $zero, -0x80
    ctx->r2 = ADD32(0, -0X80);
    // sh          $v0, 0x50($s6)
    MEM_H(0X50, ctx->r22) = ctx->r2;
L_8003A830:
    // lh          $a0, 0x50($s6)
    ctx->r4 = MEM_HS(0X50, ctx->r22);
    // jal         0x800744C4
    // nop

    rcos(rdram, ctx);
    goto after_87;
    // nop

    after_87:
    // lh          $a0, 0x50($s6)
    ctx->r4 = MEM_HS(0X50, ctx->r22);
    // jal         0x800743F4
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    rsin(rdram, ctx);
    goto after_88;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_88:
    // lw          $a1, 0x1C($s6)
    ctx->r5 = MEM_W(0X1C, ctx->r22);
    // lw          $v1, 0x78($s2)
    ctx->r3 = MEM_W(0X78, ctx->r18);
    // lw          $a0, 0x24($a1)
    ctx->r4 = MEM_W(0X24, ctx->r5);
    // nop

    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // mult        $v1, $s0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // nop

    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_8003A87C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003A87C;
    }
    // nop

    // break       7
    do_break(2147723384);
L_8003A87C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8003A894
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003A894;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8003A894
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8003A894;
    }
    // nop

    // break       6
    do_break(2147723408);
L_8003A894:
    // mflo        $s0
    ctx->r16 = lo;
    // lh          $a0, 0x32($a1)
    ctx->r4 = MEM_HS(0X32, ctx->r5);
    // jal         0x800744C4
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    rcos(rdram, ctx);
    goto after_89;
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_89:
    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8003A8BC
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003A8BC;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8003A8BC:
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(0X20, ctx->r2);
    // lw          $a0, 0x1C($s6)
    ctx->r4 = MEM_W(0X1C, ctx->r22);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lh          $a0, 0x32($a0)
    ctx->r4 = MEM_HS(0X32, ctx->r4);
    // jal         0x800743F4
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    rsin(rdram, ctx);
    goto after_90;
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_90:
    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x1C($s6)
    ctx->r3 = MEM_W(0X1C, ctx->r22);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_8003A8F4
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8003A8F4;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_8003A8F4:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // lw          $v1, 0x28($v1)
    ctx->r3 = MEM_W(0X28, ctx->r3);
    // lh          $a0, 0x10($s6)
    ctx->r4 = MEM_HS(0X10, ctx->r22);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slti        $v0, $a0, 0x20
    ctx->r2 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // beq         $v0, $zero, L_8003A918
    if (ctx->r2 == 0) {
        // sw          $v1, 0x28($s6)
        MEM_W(0X28, ctx->r22) = ctx->r3;
        goto L_8003A918;
    }
    // sw          $v1, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r3;
    // sll         $v0, $a0, 7
    ctx->r2 = S32(ctx->r4) << 7;
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
L_8003A918:
    // addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // ori         $a1, $a1, 0x400
    ctx->r5 = ctx->r5 | 0X400;
    // jal         0x80035D04
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80035D04(rdram, ctx);
    goto after_91;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_91:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8003A948
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
        goto L_8003A948;
    }
    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // beq         $v0, $zero, L_8003A948
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003A948;
    }
    // nop

    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_92;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_92:
L_8003A948:
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // lh          $v1, 0xA($s6)
    ctx->r3 = MEM_HS(0XA, ctx->r22);
    // sw          $v0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // nop

    // sw          $v0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r2;
    // lw          $v0, 0x28($s6)
    ctx->r2 = MEM_W(0X28, ctx->r22);
    // sh          $zero, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = 0;
    // sh          $zero, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = 0;
    // sh          $zero, 0xE4($sp)
    MEM_H(0XE4, ctx->r29) = 0;
    // sw          $v0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x3D
    ctx->r2 = ADD32(0, 0X3D);
    // bne         $s1, $v0, L_8003A998
    if (ctx->r17 != ctx->r2) {
        // addiu       $v1, $v1, -0x10
        ctx->r3 = ADD32(ctx->r3, -0X10);
        goto L_8003A998;
    }
    // addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xCC
    ctx->r6 = ADD32(0, 0XCC);
    // addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // j           L_8003ACF0
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
    goto L_8003ACF0;
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
L_8003A998:
    // addiu       $v0, $zero, 0x8A
    ctx->r2 = ADD32(0, 0X8A);
    // bne         $s1, $v0, L_8003A9BC
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x46
        ctx->r2 = ADD32(0, 0X46);
        goto L_8003A9BC;
    }
    // addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xED
    ctx->r6 = ADD32(0, 0XED);
    // addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // j           L_8003ACF0
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
    goto L_8003ACF0;
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
L_8003A9BC:
    // bne         $s1, $v0, L_8003A9DC
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x81
        ctx->r2 = ADD32(0, 0X81);
        goto L_8003A9DC;
    }
    // addiu       $v0, $zero, 0x81
    ctx->r2 = ADD32(0, 0X81);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xCF
    ctx->r6 = ADD32(0, 0XCF);
    // addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // j           L_8003ACF0
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
    goto L_8003ACF0;
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
L_8003A9DC:
    // bne         $s1, $v0, L_8003A9FC
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x52
        ctx->r2 = ADD32(0, 0X52);
        goto L_8003A9FC;
    }
    // addiu       $v0, $zero, 0x52
    ctx->r2 = ADD32(0, 0X52);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xE3
    ctx->r6 = ADD32(0, 0XE3);
    // addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // j           L_8003ACF0
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
    goto L_8003ACF0;
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
L_8003A9FC:
    // bne         $s1, $v0, L_8003AA1C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x86
        ctx->r2 = ADD32(0, 0X86);
        goto L_8003AA1C;
    }
    // addiu       $v0, $zero, 0x86
    ctx->r2 = ADD32(0, 0X86);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xD2
    ctx->r6 = ADD32(0, 0XD2);
    // addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // j           L_8003ACF0
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
    goto L_8003ACF0;
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
L_8003AA1C:
    // bne         $s1, $v0, L_8003AA3C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x5A
        ctx->r2 = ADD32(0, 0X5A);
        goto L_8003AA3C;
    }
    // addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xE8
    ctx->r6 = ADD32(0, 0XE8);
    // addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // j           L_8003ACF0
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
    goto L_8003ACF0;
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
L_8003AA3C:
    // bne         $s1, $v0, L_8003AA5C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x64
        ctx->r2 = ADD32(0, 0X64);
        goto L_8003AA5C;
    }
    // addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xDA
    ctx->r6 = ADD32(0, 0XDA);
    // addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // j           L_8003ACF0
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
    goto L_8003ACF0;
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
L_8003AA5C:
    // bne         $s1, $v0, L_8003AA7C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x7E
        ctx->r2 = ADD32(0, 0X7E);
        goto L_8003AA7C;
    }
    // addiu       $v0, $zero, 0x7E
    ctx->r2 = ADD32(0, 0X7E);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xDD
    ctx->r6 = ADD32(0, 0XDD);
    // addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // j           L_8003ACF0
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
    goto L_8003ACF0;
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
L_8003AA7C:
    // bne         $s1, $v0, L_8003BBDC
    if (ctx->r17 != ctx->r2) {
        // addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
        goto L_8003BBDC;
    }
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xE0
    ctx->r6 = ADD32(0, 0XE0);
    // addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // j           L_8003ACF0
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
    goto L_8003ACF0;
    // addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
L_8003AA98:
    // lh          $a0, 0x10($s6)
    ctx->r4 = MEM_HS(0X10, ctx->r22);
    // jal         0x800744C4
    // sll         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) << 11;
    rcos(rdram, ctx);
    goto after_93;
    // sll         $a0, $a0, 11
    ctx->r4 = S32(ctx->r4) << 11;
    after_93:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // bgez        $v1, L_8003AAB4
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003AAB4;
    }
    // nop

    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_8003AAB4:
    // lhu         $v0, 0x50($s6)
    ctx->r2 = MEM_HU(0X50, ctx->r22);
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // sh          $v1, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r3;
    // sh          $v1, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r3;
    // sh          $v1, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r3;
    // addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // sh          $v0, 0x50($s6)
    MEM_H(0X50, ctx->r22) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, -0x80
    ctx->r2 = SIGNED(ctx->r2) < -0X80 ? 1 : 0;
    // bne         $v0, $zero, L_8003AAE8
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x80
        ctx->r2 = ADD32(0, -0X80);
        goto L_8003AAE8;
    }
    // addiu       $v0, $zero, -0x80
    ctx->r2 = ADD32(0, -0X80);
    // sh          $v0, 0x50($s6)
    MEM_H(0X50, ctx->r22) = ctx->r2;
L_8003AAE8:
    // lh          $a0, 0x50($s6)
    ctx->r4 = MEM_HS(0X50, ctx->r22);
    // jal         0x800744C4
    // nop

    rcos(rdram, ctx);
    goto after_94;
    // nop

    after_94:
    // lh          $a0, 0x50($s6)
    ctx->r4 = MEM_HS(0X50, ctx->r22);
    // jal         0x800743F4
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    rsin(rdram, ctx);
    goto after_95;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_95:
    // lw          $a1, 0x1C($s6)
    ctx->r5 = MEM_W(0X1C, ctx->r22);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $v1, 0x24($a1)
    ctx->r3 = MEM_W(0X24, ctx->r5);
    // lw          $a0, -0x6E8C($a0)
    ctx->r4 = MEM_W(-0X6E8C, ctx->r4);
    // addiu       $v1, $v1, -0x640
    ctx->r3 = ADD32(ctx->r3, -0X640);
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // mult        $a0, $s0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // nop

    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_8003AB38
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003AB38;
    }
    // nop

    // break       7
    do_break(2147724084);
L_8003AB38:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8003AB50
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003AB50;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8003AB50
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8003AB50;
    }
    // nop

    // break       6
    do_break(2147724108);
L_8003AB50:
    // mflo        $s0
    ctx->r16 = lo;
    // lh          $a0, 0x32($a1)
    ctx->r4 = MEM_HS(0X32, ctx->r5);
    // jal         0x800744C4
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    rcos(rdram, ctx);
    goto after_96;
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_96:
    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8003AB78
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003AB78;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8003AB78:
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(0X20, ctx->r2);
    // lw          $a0, 0x1C($s6)
    ctx->r4 = MEM_W(0X1C, ctx->r22);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lh          $a0, 0x32($a0)
    ctx->r4 = MEM_HS(0X32, ctx->r4);
    // jal         0x800743F4
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    rsin(rdram, ctx);
    goto after_97;
    // addiu       $a0, $a0, 0x400
    ctx->r4 = ADD32(ctx->r4, 0X400);
    after_97:
    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x1C($s6)
    ctx->r3 = MEM_W(0X1C, ctx->r22);
    // mflo        $v0
    ctx->r2 = lo;
    // bgez        $v0, L_8003ABB0
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8003ABB0;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_8003ABB0:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // lw          $v1, 0x28($v1)
    ctx->r3 = MEM_W(0X28, ctx->r3);
    // lh          $a0, 0x10($s6)
    ctx->r4 = MEM_HS(0X10, ctx->r22);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // slti        $v0, $a0, 0x20
    ctx->r2 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // beq         $v0, $zero, L_8003ABD4
    if (ctx->r2 == 0) {
        // sw          $v1, 0x28($s6)
        MEM_W(0X28, ctx->r22) = ctx->r3;
        goto L_8003ABD4;
    }
    // sw          $v1, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r3;
    // sll         $v0, $a0, 7
    ctx->r2 = S32(ctx->r4) << 7;
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
L_8003ABD4:
    // addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // ori         $a1, $a1, 0x400
    ctx->r5 = ctx->r5 | 0X400;
    // jal         0x80035D04
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    sub_80035D04(rdram, ctx);
    goto after_98;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_98:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8003AC04
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
        goto L_8003AC04;
    }
    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // beq         $v0, $zero, L_8003AC04
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003AC04;
    }
    // nop

    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_99;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_99:
L_8003AC04:
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // lh          $v1, 0xA($s6)
    ctx->r3 = MEM_HS(0XA, ctx->r22);
    // sw          $v0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // nop

    // sw          $v0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r2;
    // lw          $v0, 0x28($s6)
    ctx->r2 = MEM_W(0X28, ctx->r22);
    // sh          $zero, 0x108($sp)
    MEM_H(0X108, ctx->r29) = 0;
    // sh          $zero, 0x10A($sp)
    MEM_H(0X10A, ctx->r29) = 0;
    // sh          $zero, 0x10C($sp)
    MEM_H(0X10C, ctx->r29) = 0;
    // sw          $v0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x3D
    ctx->r2 = ADD32(0, 0X3D);
    // bne         $s1, $v0, L_8003AC48
    if (ctx->r17 != ctx->r2) {
        // addiu       $v1, $v1, -0x10
        ctx->r3 = ADD32(ctx->r3, -0X10);
        goto L_8003AC48;
    }
    // addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // j           L_8003ACE4
    // addiu       $a2, $zero, 0xCC
    ctx->r6 = ADD32(0, 0XCC);
    goto L_8003ACE4;
    // addiu       $a2, $zero, 0xCC
    ctx->r6 = ADD32(0, 0XCC);
L_8003AC48:
    // addiu       $v0, $zero, 0x8A
    ctx->r2 = ADD32(0, 0X8A);
    // bne         $s1, $v0, L_8003AC60
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x46
        ctx->r2 = ADD32(0, 0X46);
        goto L_8003AC60;
    }
    // addiu       $v0, $zero, 0x46
    ctx->r2 = ADD32(0, 0X46);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // j           L_8003ACE4
    // addiu       $a2, $zero, 0xED
    ctx->r6 = ADD32(0, 0XED);
    goto L_8003ACE4;
    // addiu       $a2, $zero, 0xED
    ctx->r6 = ADD32(0, 0XED);
L_8003AC60:
    // bne         $s1, $v0, L_8003AC74
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x81
        ctx->r2 = ADD32(0, 0X81);
        goto L_8003AC74;
    }
    // addiu       $v0, $zero, 0x81
    ctx->r2 = ADD32(0, 0X81);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // j           L_8003ACE4
    // addiu       $a2, $zero, 0xCF
    ctx->r6 = ADD32(0, 0XCF);
    goto L_8003ACE4;
    // addiu       $a2, $zero, 0xCF
    ctx->r6 = ADD32(0, 0XCF);
L_8003AC74:
    // bne         $s1, $v0, L_8003AC88
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x52
        ctx->r2 = ADD32(0, 0X52);
        goto L_8003AC88;
    }
    // addiu       $v0, $zero, 0x52
    ctx->r2 = ADD32(0, 0X52);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // j           L_8003ACE4
    // addiu       $a2, $zero, 0xE3
    ctx->r6 = ADD32(0, 0XE3);
    goto L_8003ACE4;
    // addiu       $a2, $zero, 0xE3
    ctx->r6 = ADD32(0, 0XE3);
L_8003AC88:
    // bne         $s1, $v0, L_8003AC9C
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x86
        ctx->r2 = ADD32(0, 0X86);
        goto L_8003AC9C;
    }
    // addiu       $v0, $zero, 0x86
    ctx->r2 = ADD32(0, 0X86);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // j           L_8003ACE4
    // addiu       $a2, $zero, 0xD2
    ctx->r6 = ADD32(0, 0XD2);
    goto L_8003ACE4;
    // addiu       $a2, $zero, 0xD2
    ctx->r6 = ADD32(0, 0XD2);
L_8003AC9C:
    // bne         $s1, $v0, L_8003ACB0
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x5A
        ctx->r2 = ADD32(0, 0X5A);
        goto L_8003ACB0;
    }
    // addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // j           L_8003ACE4
    // addiu       $a2, $zero, 0xE8
    ctx->r6 = ADD32(0, 0XE8);
    goto L_8003ACE4;
    // addiu       $a2, $zero, 0xE8
    ctx->r6 = ADD32(0, 0XE8);
L_8003ACB0:
    // bne         $s1, $v0, L_8003ACC4
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x64
        ctx->r2 = ADD32(0, 0X64);
        goto L_8003ACC4;
    }
    // addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // j           L_8003ACE4
    // addiu       $a2, $zero, 0xDA
    ctx->r6 = ADD32(0, 0XDA);
    goto L_8003ACE4;
    // addiu       $a2, $zero, 0xDA
    ctx->r6 = ADD32(0, 0XDA);
L_8003ACC4:
    // bne         $s1, $v0, L_8003ACD8
    if (ctx->r17 != ctx->r2) {
        // addiu       $v0, $zero, 0x7E
        ctx->r2 = ADD32(0, 0X7E);
        goto L_8003ACD8;
    }
    // addiu       $v0, $zero, 0x7E
    ctx->r2 = ADD32(0, 0X7E);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // j           L_8003ACE4
    // addiu       $a2, $zero, 0xDD
    ctx->r6 = ADD32(0, 0XDD);
    goto L_8003ACE4;
    // addiu       $a2, $zero, 0xDD
    ctx->r6 = ADD32(0, 0XDD);
L_8003ACD8:
    // bne         $s1, $v0, L_8003BBDC
    if (ctx->r17 != ctx->r2) {
        // addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
        goto L_8003BBDC;
    }
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xE0
    ctx->r6 = ADD32(0, 0XE0);
L_8003ACE4:
    // addiu       $a3, $sp, 0x110
    ctx->r7 = ADD32(ctx->r29, 0X110);
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $v0, $sp, 0x108
    ctx->r2 = ADD32(ctx->r29, 0X108);
L_8003ACF0:
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
L_8003AD14:
    // jal         0x80036484
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_100;
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_100:
    // j           L_8003BBDC
    // nop

    goto L_8003BBDC;
    // nop

L_8003AD24:
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // lw          $v1, 0x1C($s6)
    ctx->r3 = MEM_W(0X1C, ctx->r22);
    // lw          $s1, 0x4C($s6)
    ctx->r17 = MEM_W(0X4C, ctx->r22);
    // lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(0X20, ctx->r2);
    // nop

    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(0X24, ctx->r3);
    // nop

    // sw          $v0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x50($s6)
    ctx->r2 = MEM_HU(0X50, ctx->r22);
    // lw          $v1, 0x28($v1)
    ctx->r3 = MEM_W(0X28, ctx->r3);
    // addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // sh          $v0, 0x50($s6)
    MEM_H(0X50, ctx->r22) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, -0x80
    ctx->r2 = SIGNED(ctx->r2) < -0X80 ? 1 : 0;
    // bne         $v0, $zero, L_8003AD74
    if (ctx->r2 != 0) {
        // sw          $v1, 0x28($s6)
        MEM_W(0X28, ctx->r22) = ctx->r3;
        goto L_8003AD74;
    }
    // sw          $v1, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r3;
    // addiu       $v0, $zero, -0x80
    ctx->r2 = ADD32(0, -0X80);
    // sh          $v0, 0x50($s6)
    MEM_H(0X50, ctx->r22) = ctx->r2;
L_8003AD74:
    // lh          $a0, 0x50($s6)
    ctx->r4 = MEM_HS(0X50, ctx->r22);
    // jal         0x800744C4
    // nop

    rcos(rdram, ctx);
    goto after_101;
    // nop

    after_101:
    // lh          $a0, 0x50($s6)
    ctx->r4 = MEM_HS(0X50, ctx->r22);
    // jal         0x800743F4
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    rsin(rdram, ctx);
    goto after_102;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_102:
    // lw          $a0, 0x1C($s6)
    ctx->r4 = MEM_W(0X1C, ctx->r22);
    // lw          $v1, 0x78($s1)
    ctx->r3 = MEM_W(0X78, ctx->r17);
    // lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(0X24, ctx->r4);
    // nop

    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // mult        $v1, $s0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // nop

    // nop

    // div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_8003ADC0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003ADC0;
    }
    // nop

    // break       7
    do_break(2147724732);
L_8003ADC0:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8003ADD8
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003ADD8;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $a0, $at, L_8003ADD8
    if (ctx->r4 != ctx->r1) {
        // nop
    
        goto L_8003ADD8;
    }
    // nop

    // break       6
    do_break(2147724756);
L_8003ADD8:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // j           L_8003AECC
    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    goto L_8003AECC;
    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8003ADF8:
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // lw          $v1, 0x1C($s6)
    ctx->r3 = MEM_W(0X1C, ctx->r22);
    // lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(0X20, ctx->r2);
    // nop

    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(0X24, ctx->r3);
    // nop

    // sw          $v0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x50($s6)
    ctx->r2 = MEM_HU(0X50, ctx->r22);
    // lw          $v1, 0x28($v1)
    ctx->r3 = MEM_W(0X28, ctx->r3);
    // addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // sh          $v0, 0x50($s6)
    MEM_H(0X50, ctx->r22) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, -0x80
    ctx->r2 = SIGNED(ctx->r2) < -0X80 ? 1 : 0;
    // bne         $v0, $zero, L_8003AE44
    if (ctx->r2 != 0) {
        // sw          $v1, 0x28($s6)
        MEM_W(0X28, ctx->r22) = ctx->r3;
        goto L_8003AE44;
    }
    // sw          $v1, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r3;
    // addiu       $v0, $zero, -0x80
    ctx->r2 = ADD32(0, -0X80);
    // sh          $v0, 0x50($s6)
    MEM_H(0X50, ctx->r22) = ctx->r2;
L_8003AE44:
    // lh          $a0, 0x50($s6)
    ctx->r4 = MEM_HS(0X50, ctx->r22);
    // jal         0x800744C4
    // nop

    rcos(rdram, ctx);
    goto after_103;
    // nop

    after_103:
    // lh          $a0, 0x50($s6)
    ctx->r4 = MEM_HS(0X50, ctx->r22);
    // jal         0x800743F4
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    rsin(rdram, ctx);
    goto after_104;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_104:
    // lw          $v1, 0x1C($s6)
    ctx->r3 = MEM_W(0X1C, ctx->r22);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $v1, 0x24($v1)
    ctx->r3 = MEM_W(0X24, ctx->r3);
    // lw          $a0, -0x6E8C($a0)
    ctx->r4 = MEM_W(-0X6E8C, ctx->r4);
    // addiu       $v1, $v1, -0x640
    ctx->r3 = ADD32(ctx->r3, -0X640);
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // mult        $a0, $s0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // nop

    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_8003AE94
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003AE94;
    }
    // nop

    // break       7
    do_break(2147724944);
L_8003AE94:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8003AEAC
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003AEAC;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8003AEAC
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8003AEAC;
    }
    // nop

    // break       6
    do_break(2147724968);
L_8003AEAC:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // mult        $a0, $a0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
L_8003AECC:
    // mflo        $v1
    ctx->r3 = lo;
    // jal         0x800746C4
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    SquareRoot0(rdram, ctx);
    goto after_105;
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    after_105:
    // sh          $v0, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x50($s6)
    ctx->r2 = MEM_HU(0X50, ctx->r22);
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sh          $v0, 0x30($s6)
    MEM_H(0X30, ctx->r22) = ctx->r2;
L_8003AEEC:
    // slti        $v0, $v1, 0x8
    ctx->r2 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
L_8003AEF0:
    // beq         $v0, $zero, L_8003BBDC
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 9
        ctx->r2 = S32(ctx->r3) << 9;
        goto L_8003BBDC;
    }
    // sll         $v0, $v1, 9
    ctx->r2 = S32(ctx->r3) << 9;
    // j           L_8003BBDC
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
    goto L_8003BBDC;
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
L_8003AF00:
    // lh          $v1, 0x40($s6)
    ctx->r3 = MEM_HS(0X40, ctx->r22);
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // lh          $a0, 0x42($s6)
    ctx->r4 = MEM_HS(0X42, ctx->r22);
    // lh          $a1, 0x44($s6)
    ctx->r5 = MEM_HS(0X44, ctx->r22);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // lw          $v1, 0x28($s6)
    ctx->r3 = MEM_W(0X28, ctx->r22);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sw          $v0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lhu         $a0, 0x50($s6)
    ctx->r4 = MEM_HU(0X50, ctx->r22);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // sw          $v1, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r3;
    // lbu         $v1, 0x5($s6)
    ctx->r3 = MEM_BU(0X5, ctx->r22);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sltiu       $v1, $v1, 0x3
    ctx->r3 = ctx->r3 < 0X3 ? 1 : 0;
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // beq         $v1, $zero, L_8003AF5C
    if (ctx->r3 == 0) {
        // sh          $v0, 0x3C($s6)
        MEM_H(0X3C, ctx->r22) = ctx->r2;
        goto L_8003AF5C;
    }
    // sh          $v0, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r2;
    // lh          $v0, 0x38($s6)
    ctx->r2 = MEM_HS(0X38, ctx->r22);
    // j           L_8003AF6C
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    goto L_8003AF6C;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
L_8003AF5C:
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // lhu         $v1, 0x50($s6)
    ctx->r3 = MEM_HU(0X50, ctx->r22);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8003AF6C:
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // lbu         $v0, 0x5($s6)
    ctx->r2 = MEM_BU(0X5, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8003BBDC
    // sb          $v0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r2;
    goto L_8003BBDC;
    // sb          $v0, 0x5($s6)
    MEM_B(0X5, ctx->r22) = ctx->r2;
L_8003AF84:
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // lh          $v1, 0x38($s6)
    ctx->r3 = MEM_HS(0X38, ctx->r22);
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_8003AFBC
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8003AFBC;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_8003AFBC:
    // lh          $v1, 0x38($s6)
    ctx->r3 = MEM_HS(0X38, ctx->r22);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_8003AFE4
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $a1, $v0, 12
        ctx->r5 = S32(ctx->r2) >> 12;
        goto L_8003AFE4;
    }
    // sra         $a1, $v0, 12
    ctx->r5 = S32(ctx->r2) >> 12;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
    // sra         $a1, $v0, 12
    ctx->r5 = S32(ctx->r2) >> 12;
L_8003AFE4:
    // lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lb          $a2, 0x50($s6)
    ctx->r6 = MEM_BS(0X50, ctx->r22);
    // or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // jal         0x800381A8
    // sw          $a1, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r5;
    sub_800381A8(rdram, ctx);
    goto after_106;
    // sw          $a1, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r5;
    after_106:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // nop

    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // beq         $v0, $zero, L_8003B014
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 7
        ctx->r2 = S32(ctx->r3) << 7;
        goto L_8003B014;
    }
    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
L_8003B014:
    // lhu         $v0, 0x42($s6)
    ctx->r2 = MEM_HU(0X42, ctx->r22);
    // lbu         $v1, 0x8($s6)
    ctx->r3 = MEM_BU(0X8, ctx->r22);
    // addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // bne         $v1, $zero, L_8003B04C
    if (ctx->r3 != 0) {
        // sh          $v0, 0x42($s6)
        MEM_H(0X42, ctx->r22) = ctx->r2;
        goto L_8003B04C;
    }
    // sh          $v0, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r2;
    // lh          $v0, 0x10($s6)
    ctx->r2 = MEM_HS(0X10, ctx->r22);
    // nop

    // slti        $v0, $v0, 0x30
    ctx->r2 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // bne         $v0, $zero, L_8003B04C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8003B04C;
    }
    // nop

    // jal         0x8003618C
    // addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    sub_8003618C(rdram, ctx);
    goto after_107;
    // addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_107:
    // j           L_8003B058
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    goto L_8003B058;
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8003B04C:
    // lbu         $v0, 0x8($s6)
    ctx->r2 = MEM_BU(0X8, ctx->r22);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8003B058:
    // jal         0x80078AC4
    // sb          $v0, 0x8($s6)
    MEM_B(0X8, ctx->r22) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_108;
    // sb          $v0, 0x8($s6)
    MEM_B(0X8, ctx->r22) = ctx->r2;
    after_108:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // subu        $v1, $a1, $v1
    ctx->r3 = SUB32(ctx->r5, ctx->r3);
    // bgez        $v1, L_8003B078
    if (SIGNED(ctx->r3) >= 0) {
        // addiu       $a0, $v0, -0x4000
        ctx->r4 = ADD32(ctx->r2, -0X4000);
        goto L_8003B078;
    }
    // addiu       $a0, $v0, -0x4000
    ctx->r4 = ADD32(ctx->r2, -0X4000);
    // addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
L_8003B078:
    // sra         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) >> 3;
    // addiu       $v0, $v0, 0x9
    ctx->r2 = ADD32(ctx->r2, 0X9);
    // srav        $a0, $a0, $v0
    ctx->r4 = S32(ctx->r4) >> (ctx->r2 & 31);
    // addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // sltiu       $v0, $v0, 0x5
    ctx->r2 = ctx->r2 < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_8003B0B4
    if (ctx->r2 != 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_8003B0B4;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // lhu         $v0, 0x28C($v1)
    ctx->r2 = MEM_HU(0X28C, ctx->r3);
    // nop

    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sh          $v0, 0x28C($v1)
    MEM_H(0X28C, ctx->r3) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8003B0B4:
    // addiu       $v1, $v0, -0x70D8
    ctx->r3 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v0, 0x28C($v1)
    ctx->r2 = MEM_HU(0X28C, ctx->r3);
    // nop

    // addiu       $v0, $v0, -0x801
    ctx->r2 = ADD32(ctx->r2, -0X801);
    // sltiu       $v0, $v0, 0x7BF
    ctx->r2 = ctx->r2 < 0X7BF ? 1 : 0;
    // beq         $v0, $zero, L_8003B0D4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFC0
        ctx->r2 = ADD32(0, 0XFC0);
        goto L_8003B0D4;
    }
    // addiu       $v0, $zero, 0xFC0
    ctx->r2 = ADD32(0, 0XFC0);
    // sh          $v0, 0x28C($v1)
    MEM_H(0X28C, ctx->r3) = ctx->r2;
L_8003B0D4:
    // lhu         $v0, 0x28C($v1)
    ctx->r2 = MEM_HU(0X28C, ctx->r3);
    // nop

    // addiu       $v0, $v0, -0x41
    ctx->r2 = ADD32(ctx->r2, -0X41);
    // sltiu       $v0, $v0, 0x7BF
    ctx->r2 = ctx->r2 < 0X7BF ? 1 : 0;
    // beq         $v0, $zero, L_8003BBDC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003BBDC;
    }
    // nop

    // j           L_8003BBDC
    // sh          $a1, 0x28C($v1)
    MEM_H(0X28C, ctx->r3) = ctx->r5;
    goto L_8003BBDC;
    // sh          $a1, 0x28C($v1)
    MEM_H(0X28C, ctx->r3) = ctx->r5;
L_8003B0F4:
    // j           L_8003B108
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    goto L_8003B108;
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8003B0FC:
    // j           L_8003B108
    // addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    goto L_8003B108;
    // addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_8003B104:
    // addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_8003B108:
    // lh          $a0, 0x10($s6)
    ctx->r4 = MEM_HS(0X10, ctx->r22);
    // nop

    // slti        $v0, $a0, 0x10
    ctx->r2 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_8003B13C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003B13C;
    }
    // nop

    // lw          $v0, 0x4C($s6)
    ctx->r2 = MEM_W(0X4C, ctx->r22);
    // nop

    // lbu         $v1, 0x1E($v0)
    ctx->r3 = MEM_BU(0X1E, ctx->r2);
    // sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) << 8;
    // sh          $a0, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r4;
    // ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // j           L_8003B170
    // sb          $v1, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r3;
    goto L_8003B170;
    // sb          $v1, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r3;
L_8003B13C:
    // bgtz        $a0, L_8003B170
    if (SIGNED(ctx->r4) > 0) {
        // nop
    
        goto L_8003B170;
    }
    // nop

    // lw          $a0, 0x4C($s6)
    ctx->r4 = MEM_W(0X4C, ctx->r22);
    // nop

    // lbu         $v1, 0x1E($a0)
    ctx->r3 = MEM_BU(0X1E, ctx->r4);
    // nop

    // andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // beq         $v0, $zero, L_8003B168
    if (ctx->r2 == 0) {
        // sh          $zero, 0x36($a0)
        MEM_H(0X36, ctx->r4) = 0;
        goto L_8003B168;
    }
    // sh          $zero, 0x36($a0)
    MEM_H(0X36, ctx->r4) = 0;
    // j           L_8003B16C
    // andi        $v0, $v1, 0xF7
    ctx->r2 = ctx->r3 & 0XF7;
    goto L_8003B16C;
    // andi        $v0, $v1, 0xF7
    ctx->r2 = ctx->r3 & 0XF7;
L_8003B168:
    // andi        $v0, $v1, 0xF2
    ctx->r2 = ctx->r3 & 0XF2;
L_8003B16C:
    // sb          $v0, 0x1E($a0)
    MEM_B(0X1E, ctx->r4) = ctx->r2;
L_8003B170:
    // lbu         $v0, 0x8($s6)
    ctx->r2 = MEM_BU(0X8, ctx->r22);
    // nop

    // bne         $v0, $zero, L_8003BBD8
    if (ctx->r2 != 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_8003BBD8;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(0X6, ctx->r4);
    // nop

    // subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgez        $v0, L_8003B1A8
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8003B1A8;
    }
    // nop

    // addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8003B1A8:
    // j           L_8003BBDC
    // sh          $v1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r3;
    goto L_8003BBDC;
    // sh          $v1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r3;
L_8003B1B0:
    // j           L_8003B1C4
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    goto L_8003B1C4;
    // addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8003B1B8:
    // j           L_8003B1C4
    // addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    goto L_8003B1C4;
    // addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_8003B1C0:
    // addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_8003B1C4:
    // lh          $a0, 0x10($s6)
    ctx->r4 = MEM_HS(0X10, ctx->r22);
    // nop

    // slti        $v0, $a0, 0x10
    ctx->r2 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_8003B1F0
    if (ctx->r2 == 0) {
        // sll         $a0, $a0, 8
        ctx->r4 = S32(ctx->r4) << 8;
        goto L_8003B1F0;
    }
    // sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) << 8;
    // lw          $v0, 0x4C($s6)
    ctx->r2 = MEM_W(0X4C, ctx->r22);
    // nop

    // lbu         $v1, 0x1E($v0)
    ctx->r3 = MEM_BU(0X1E, ctx->r2);
    // sh          $a0, 0x36($v0)
    MEM_H(0X36, ctx->r2) = ctx->r4;
    // ori         $v1, $v1, 0xD
    ctx->r3 = ctx->r3 | 0XD;
    // sb          $v1, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r3;
L_8003B1F0:
    // lh          $v0, 0x10($s6)
    ctx->r2 = MEM_HS(0X10, ctx->r22);
    // nop

    // bgtz        $v0, L_8003B22C
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8003B22C;
    }
    // nop

    // lw          $a0, 0x4C($s6)
    ctx->r4 = MEM_W(0X4C, ctx->r22);
    // nop

    // lbu         $v1, 0x1E($a0)
    ctx->r3 = MEM_BU(0X1E, ctx->r4);
    // nop

    // andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // beq         $v0, $zero, L_8003B224
    if (ctx->r2 == 0) {
        // sh          $zero, 0x36($a0)
        MEM_H(0X36, ctx->r4) = 0;
        goto L_8003B224;
    }
    // sh          $zero, 0x36($a0)
    MEM_H(0X36, ctx->r4) = 0;
    // j           L_8003B228
    // andi        $v0, $v1, 0xF7
    ctx->r2 = ctx->r3 & 0XF7;
    goto L_8003B228;
    // andi        $v0, $v1, 0xF7
    ctx->r2 = ctx->r3 & 0XF7;
L_8003B224:
    // andi        $v0, $v1, 0xF2
    ctx->r2 = ctx->r3 & 0XF2;
L_8003B228:
    // sb          $v0, 0x1E($a0)
    MEM_B(0X1E, ctx->r4) = ctx->r2;
L_8003B22C:
    // lbu         $v0, 0x8($s6)
    ctx->r2 = MEM_BU(0X8, ctx->r22);
    // nop

    // bne         $v0, $zero, L_8003BBD8
    if (ctx->r2 != 0) {
        // addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_8003BBD8;
    }
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s1, $v0, -0x70D8
    ctx->r17 = ADD32(ctx->r2, -0X70D8);
    // lhu         $s0, 0x2($s1)
    ctx->r16 = MEM_HU(0X2, ctx->r17);
    // nop

    // subu        $v0, $s0, $a1
    ctx->r2 = SUB32(ctx->r16, ctx->r5);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bgtz        $v0, L_8003B26C
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8003B26C;
    }
    // nop

    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // jal         0x8003BD14
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8003BD14(rdram, ctx);
    goto after_109;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_109:
L_8003B26C:
    // j           L_8003BBDC
    // sh          $s0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r16;
    goto L_8003BBDC;
    // sh          $s0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r16;
L_8003B274:
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lhu         $v1, 0x3C($s6)
    ctx->r3 = MEM_HU(0X3C, ctx->r22);
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // lh          $a0, 0x38($s6)
    ctx->r4 = MEM_HS(0X38, ctx->r22);
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // sh          $v1, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r3;
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // bgez        $a0, L_8003B2A4
    if (SIGNED(ctx->r4) >= 0) {
        // sh          $v0, 0x3A($s6)
        MEM_H(0X3A, ctx->r22) = ctx->r2;
        goto L_8003B2A4;
    }
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
L_8003B2A4:
    // lh          $a1, 0x38($s6)
    ctx->r5 = MEM_HS(0X38, ctx->r22);
    // sra         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) >> 2;
    // bgez        $a1, L_8003B2B8
    if (SIGNED(ctx->r5) >= 0) {
        // sh          $v0, 0xC($s6)
        MEM_H(0XC, ctx->r22) = ctx->r2;
        goto L_8003B2B8;
    }
    // sh          $v0, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r2;
    // addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
L_8003B2B8:
    // sra         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) >> 2;
    // lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
    // jal         0x80038300
    // sw          $a1, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r5;
    sub_80038300(rdram, ctx);
    goto after_110;
    // sw          $a1, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r5;
    after_110:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8003B2F8
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
        goto L_8003B2F8;
    }
    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // beq         $v0, $zero, L_8003B2F4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8003B2F4;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_111;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_111:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8003B2F4:
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_8003B2F8:
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // lhu         $v0, 0x10($s6)
    ctx->r2 = MEM_HU(0X10, ctx->r22);
    // ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v1, $t1, 1
    ctx->r3 = S32(ctx->r9) >> 1;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // bne         $a0, $zero, L_8003B43C
    if (ctx->r4 != 0) {
        // addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
        goto L_8003B43C;
    }
    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8003B338:
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_112;
    // nop

    after_112:
    // lh          $v1, 0x40($s6)
    ctx->r3 = MEM_HS(0X40, ctx->r22);
    // nop

    // bgez        $v1, L_8003B354
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003B354;
    }
    // nop

    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_8003B354:
    // bgez        $v0, L_8003B360
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3) >> 2;
        goto L_8003B360;
    }
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
L_8003B360:
    // sra         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) >> 10;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // jal         0x80078AC4
    // sh          $v0, 0x120($sp)
    MEM_H(0X120, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_113;
    // sh          $v0, 0x120($sp)
    MEM_H(0X120, ctx->r29) = ctx->r2;
    after_113:
    // lh          $v1, 0x42($s6)
    ctx->r3 = MEM_HS(0X42, ctx->r22);
    // nop

    // bgez        $v1, L_8003B388
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003B388;
    }
    // nop

    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_8003B388:
    // bgez        $v0, L_8003B394
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3) >> 2;
        goto L_8003B394;
    }
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
L_8003B394:
    // sra         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) >> 10;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // jal         0x80078AC4
    // sh          $v0, 0x122($sp)
    MEM_H(0X122, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_114;
    // sh          $v0, 0x122($sp)
    MEM_H(0X122, ctx->r29) = ctx->r2;
    after_114:
    // lh          $v1, 0x44($s6)
    ctx->r3 = MEM_HS(0X44, ctx->r22);
    // nop

    // bgez        $v1, L_8003B3B8
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003B3B8;
    }
    // nop

    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_8003B3B8:
    // bgez        $v0, L_8003B3C4
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $a1, $v1, 2
        ctx->r5 = S32(ctx->r3) >> 2;
        goto L_8003B3C4;
    }
    // sra         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3) >> 2;
    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
L_8003B3C4:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sra         $v1, $v0, 10
    ctx->r3 = S32(ctx->r2) >> 10;
    // addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // subu        $v1, $a1, $v1
    ctx->r3 = SUB32(ctx->r5, ctx->r3);
    // lh          $a1, 0x120($sp)
    ctx->r5 = MEM_HS(0X120, ctx->r29);
    // addiu       $a2, $zero, 0xD7
    ctx->r6 = ADD32(0, 0XD7);
    // sh          $v1, 0x124($sp)
    MEM_H(0X124, ctx->r29) = ctx->r3;
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // addiu       $a3, $sp, 0x128
    ctx->r7 = ADD32(ctx->r29, 0X128);
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sw          $v0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sw          $v0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r2;
    // lw          $v0, 0x28($s6)
    ctx->r2 = MEM_W(0X28, ctx->r22);
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r2;
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $v0, $sp, 0x120
    ctx->r2 = ADD32(ctx->r29, 0X120);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_115;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_115:
    // blez        $s0, L_8003B338
    if (SIGNED(ctx->r16) <= 0) {
        // nop
    
        goto L_8003B338;
    }
    // nop

L_8003B43C:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // j           L_8003BB0C
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    goto L_8003BB0C;
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
L_8003B448:
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // lw          $v1, 0x1C($s6)
    ctx->r3 = MEM_W(0X1C, ctx->r22);
    // lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(0X20, ctx->r2);
    // nop

    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(0X24, ctx->r3);
    // lui         $a0, 0x5555
    ctx->r4 = S32(0X5555 << 16);
    // sw          $v0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r2;
    // lw          $v0, 0x28($v1)
    ctx->r2 = MEM_W(0X28, ctx->r3);
    // lhu         $v1, 0x10($s6)
    ctx->r3 = MEM_HU(0X10, ctx->r22);
    // ori         $a0, $a0, 0x5556
    ctx->r4 = ctx->r4 | 0X5556;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3) >> 16;
    // mult        $a1, $a0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sw          $v0, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r2;
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // lw          $a0, 0x1C($s6)
    ctx->r4 = MEM_W(0X1C, ctx->r22);
    // lhu         $v0, 0x38($v0)
    ctx->r2 = MEM_HU(0X38, ctx->r2);
    // nop

    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x3A($a0)
    ctx->r2 = MEM_HU(0X3A, ctx->r4);
    // nop

    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x3C($a0)
    ctx->r2 = MEM_HU(0X3C, ctx->r4);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // sh          $v0, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r2;
    // mfhi        $t1
    ctx->r9 = hi;
    // subu        $v1, $t1, $v1
    ctx->r3 = SUB32(ctx->r9, ctx->r3);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // ori         $a1, $a1, 0x80
    ctx->r5 = ctx->r5 | 0X80;
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // beq         $v0, $zero, L_8003B4E0
    if (ctx->r2 == 0) {
        // sb          $a1, 0x2($s6)
        MEM_B(0X2, ctx->r22) = ctx->r5;
        goto L_8003B4E0;
    }
    // sb          $a1, 0x2($s6)
    MEM_B(0X2, ctx->r22) = ctx->r5;
    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
L_8003B4E0:
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // nop

    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // bne         $v1, $v0, L_8003BBDC
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8003BBDC;
    }
    // nop

L_8003B4F8:
    // j           L_8003BBDC
    // sb          $v1, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r3;
    goto L_8003BBDC;
    // sb          $v1, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r3;
L_8003B500:
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lw          $a1, 0x18($s6)
    ctx->r5 = MEM_W(0X18, ctx->r22);
    // lb          $a2, 0x50($s6)
    ctx->r6 = MEM_BS(0X50, ctx->r22);
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lhu         $v1, 0x3A($s6)
    ctx->r3 = MEM_HU(0X3A, ctx->r22);
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // jal         0x800381A8
    // sh          $v1, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r3;
    sub_800381A8(rdram, ctx);
    goto after_116;
    // sh          $v1, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r3;
    after_116:
    // lh          $v0, 0x10($s6)
    ctx->r2 = MEM_HS(0X10, ctx->r22);
    // lhu         $v1, 0x42($s6)
    ctx->r3 = MEM_HU(0X42, ctx->r22);
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // j           L_8003B790
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    goto L_8003B790;
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8003B53C:
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x3A($s6)
    ctx->r2 = MEM_HU(0X3A, ctx->r22);
    // lh          $v1, 0x38($s6)
    ctx->r3 = MEM_HS(0X38, ctx->r22);
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_8003B574
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8003B574;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_8003B574:
    // lh          $v1, 0x38($s6)
    ctx->r3 = MEM_HS(0X38, ctx->r22);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_8003B59C
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $a1, $v0, 12
        ctx->r5 = S32(ctx->r2) >> 12;
        goto L_8003B59C;
    }
    // sra         $a1, $v0, 12
    ctx->r5 = S32(ctx->r2) >> 12;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
    // sra         $a1, $v0, 12
    ctx->r5 = S32(ctx->r2) >> 12;
L_8003B59C:
    // lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lb          $a2, 0x50($s6)
    ctx->r6 = MEM_BS(0X50, ctx->r22);
    // or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // jal         0x80038300
    // sw          $a1, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r5;
    sub_80038300(rdram, ctx);
    goto after_117;
    // sw          $a1, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r5;
    after_117:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8003B5E0
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
        goto L_8003B5E0;
    }
    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // beq         $v0, $zero, L_8003B5DC
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8003B5DC;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_118;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_118:
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sb          $v0, 0x8($s6)
    MEM_B(0X8, ctx->r22) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8003B5DC:
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_8003B5E0:
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // lhu         $v0, 0x10($s6)
    ctx->r2 = MEM_HU(0X10, ctx->r22);
    // ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v1, $t1, 1
    ctx->r3 = S32(ctx->r9) >> 1;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // bne         $a0, $zero, L_8003B72C
    if (ctx->r4 != 0) {
        // nop
    
        goto L_8003B72C;
    }
    // nop

    // addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_8003B624:
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_119;
    // nop

    after_119:
    // lh          $v1, 0x40($s6)
    ctx->r3 = MEM_HS(0X40, ctx->r22);
    // nop

    // bgez        $v1, L_8003B640
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003B640;
    }
    // nop

    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_8003B640:
    // bgez        $v0, L_8003B64C
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3) >> 2;
        goto L_8003B64C;
    }
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
L_8003B64C:
    // sra         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) >> 10;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // jal         0x80078AC4
    // sh          $v0, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_120;
    // sh          $v0, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r2;
    after_120:
    // lh          $v1, 0x42($s6)
    ctx->r3 = MEM_HS(0X42, ctx->r22);
    // nop

    // bgez        $v1, L_8003B674
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003B674;
    }
    // nop

    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_8003B674:
    // bgez        $v0, L_8003B680
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3) >> 2;
        goto L_8003B680;
    }
    // sra         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) >> 2;
    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
L_8003B680:
    // sra         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) >> 10;
    // addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // jal         0x80078AC4
    // sh          $v0, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_121;
    // sh          $v0, 0x13A($sp)
    MEM_H(0X13A, ctx->r29) = ctx->r2;
    after_121:
    // lh          $v1, 0x44($s6)
    ctx->r3 = MEM_HS(0X44, ctx->r22);
    // nop

    // bgez        $v1, L_8003B6A8
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003B6A8;
    }
    // nop

    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_8003B6A8:
    // bgez        $v0, L_8003B6B4
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $a1, $v1, 2
        ctx->r5 = S32(ctx->r3) >> 2;
        goto L_8003B6B4;
    }
    // sra         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3) >> 2;
    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
L_8003B6B4:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sra         $v1, $v0, 10
    ctx->r3 = S32(ctx->r2) >> 10;
    // addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // subu        $v1, $a1, $v1
    ctx->r3 = SUB32(ctx->r5, ctx->r3);
    // lh          $a1, 0x138($sp)
    ctx->r5 = MEM_HS(0X138, ctx->r29);
    // addiu       $a2, $zero, 0xD5
    ctx->r6 = ADD32(0, 0XD5);
    // sh          $v1, 0x13C($sp)
    MEM_H(0X13C, ctx->r29) = ctx->r3;
    // lw          $v0, 0x20($s6)
    ctx->r2 = MEM_W(0X20, ctx->r22);
    // addiu       $a3, $sp, 0x140
    ctx->r7 = ADD32(ctx->r29, 0X140);
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sw          $v0, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r2;
    // lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(0X24, ctx->r22);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sw          $v0, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r2;
    // lw          $v0, 0x28($s6)
    ctx->r2 = MEM_W(0X28, ctx->r22);
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r2;
    // lbu         $a1, 0x0($s6)
    ctx->r5 = MEM_BU(0X0, ctx->r22);
    // addiu       $v0, $sp, 0x138
    ctx->r2 = ADD32(ctx->r29, 0X138);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s6)
    ctx->r2 = MEM_HS(0XA, ctx->r22);
    // addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_122;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_122:
    // blez        $s0, L_8003B624
    if (SIGNED(ctx->r16) <= 0) {
        // nop
    
        goto L_8003B624;
    }
    // nop

L_8003B72C:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // nop

    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // beq         $v0, $zero, L_8003B744
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 7
        ctx->r2 = S32(ctx->r3) << 7;
        goto L_8003B744;
    }
    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
L_8003B740:
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
L_8003B744:
    // lhu         $v0, 0x42($s6)
    ctx->r2 = MEM_HU(0X42, ctx->r22);
    // nop

    // addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // j           L_8003BBDC
    // sh          $v0, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r2;
    goto L_8003BBDC;
    // sh          $v0, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r2;
L_8003B758:
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lw          $a1, 0x18($s6)
    ctx->r5 = MEM_W(0X18, ctx->r22);
    // lb          $a2, 0x50($s6)
    ctx->r6 = MEM_BS(0X50, ctx->r22);
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lhu         $v1, 0x3A($s6)
    ctx->r3 = MEM_HU(0X3A, ctx->r22);
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // jal         0x800381A8
    // sh          $v1, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r3;
    sub_800381A8(rdram, ctx);
    goto after_123;
    // sh          $v1, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r3;
    after_123:
    // lh          $v0, 0x10($s6)
    ctx->r2 = MEM_HS(0X10, ctx->r22);
    // lhu         $v1, 0x42($s6)
    ctx->r3 = MEM_HU(0X42, ctx->r22);
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
L_8003B790:
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
    // j           L_8003BBDC
    // sh          $v1, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r3;
    goto L_8003BBDC;
    // sh          $v1, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r3;
L_8003B79C:
    // lh          $v0, 0x10($s6)
    ctx->r2 = MEM_HS(0X10, ctx->r22);
    // addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // jal         0x800744C4
    // sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4) << 6;
    rcos(rdram, ctx);
    goto after_124;
    // sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4) << 6;
    after_124:
    // lhu         $v1, 0x38($s6)
    ctx->r3 = MEM_HU(0X38, ctx->r22);
    // sh          $v0, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x3C($s6)
    ctx->r2 = MEM_HU(0X3C, ctx->r22);
    // addiu       $v1, $v1, 0xC0
    ctx->r3 = ADD32(ctx->r3, 0XC0);
    // sh          $v1, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r3;
    // lh          $v1, 0x38($s6)
    ctx->r3 = MEM_HS(0X38, ctx->r22);
    // addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
    // sh          $v0, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) << 9;
    // bgez        $v0, L_8003B7E8
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8003B7E8;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_8003B7E8:
    // lh          $v1, 0x38($s6)
    ctx->r3 = MEM_HS(0X38, ctx->r22);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) << 9;
    // bgez        $v0, L_8003B80C
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
        goto L_8003B80C;
    }
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_8003B80C:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x32($s6)
    ctx->r2 = MEM_HU(0X32, ctx->r22);
    // lw          $a1, 0x18($s6)
    ctx->r5 = MEM_W(0X18, ctx->r22);
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // jal         0x800381A8
    // sh          $v0, 0x32($s6)
    MEM_H(0X32, ctx->r22) = ctx->r2;
    sub_800381A8(rdram, ctx);
    goto after_125;
    // sh          $v0, 0x32($s6)
    MEM_H(0X32, ctx->r22) = ctx->r2;
    after_125:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8003B860
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
        goto L_8003B860;
    }
    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // beq         $v0, $zero, L_8003B85C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8003B85C;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_126;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_126:
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sb          $v0, 0x8($s6)
    MEM_B(0X8, ctx->r22) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8003B85C:
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_8003B860:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // j           L_8003BB0C
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    goto L_8003BB0C;
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
L_8003B86C:
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lw          $a1, 0x18($s6)
    ctx->r5 = MEM_W(0X18, ctx->r22);
    // jal         0x80038300
    // addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    sub_80038300(rdram, ctx);
    goto after_127;
    // addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    after_127:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8003B8A0
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
        goto L_8003B8A0;
    }
    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // beq         $v0, $zero, L_8003B89C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8003B89C;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_128;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_128:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8003B89C:
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_8003B8A0:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // j           L_8003BB0C
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    goto L_8003BB0C;
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
L_8003B8AC:
    // lui         $v0, 0x5555
    ctx->r2 = S32(0X5555 << 16);
    // lhu         $v1, 0x10($s6)
    ctx->r3 = MEM_HU(0X10, ctx->r22);
    // ori         $v0, $v0, 0x5556
    ctx->r2 = ctx->r2 | 0X5556;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $a3, $v1, 16
    ctx->r7 = S32(ctx->r3) >> 16;
    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a2, $zero, -0x100
    ctx->r6 = ADD32(0, -0X100);
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // lw          $a1, 0x18($s6)
    ctx->r5 = MEM_W(0X18, ctx->r22);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // subu        $v1, $t1, $v1
    ctx->r3 = SUB32(ctx->r9, ctx->r3);
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $a3, $a3, $v0
    ctx->r7 = SUB32(ctx->r7, ctx->r2);
    // ori         $a3, $a3, 0x80
    ctx->r7 = ctx->r7 | 0X80;
    // jal         0x80038300
    // sb          $a3, 0x2($s6)
    MEM_B(0X2, ctx->r22) = ctx->r7;
    sub_80038300(rdram, ctx);
    goto after_129;
    // sb          $a3, 0x2($s6)
    MEM_B(0X2, ctx->r22) = ctx->r7;
    after_129:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8003B918
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
        goto L_8003B918;
    }
    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // beq         $v0, $zero, L_8003B914
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8003B914;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_130;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_130:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8003B914:
    // sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
L_8003B918:
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // j           L_8003BB0C
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    goto L_8003BB0C;
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
L_8003B924:
    // lw          $a0, 0x1C($s6)
    ctx->r4 = MEM_W(0X1C, ctx->r22);
    // nop

    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8003B4F8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003B4F8;
    }
    // nop

    // lh          $a0, 0x34($a0)
    ctx->r4 = MEM_HS(0X34, ctx->r4);
    // jal         0x800744C4
    // nop

    rcos(rdram, ctx);
    goto after_131;
    // nop

    after_131:
    // lw          $a0, 0x1C($s6)
    ctx->r4 = MEM_W(0X1C, ctx->r22);
    // nop

    // lh          $v1, 0x38($a0)
    ctx->r3 = MEM_HS(0X38, ctx->r4);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8003B96C
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003B96C;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8003B96C:
    // lh          $a0, 0x32($a0)
    ctx->r4 = MEM_HS(0X32, ctx->r4);
    // jal         0x800744C4
    // sra         $s0, $v1, 12
    ctx->r16 = S32(ctx->r3) >> 12;
    rcos(rdram, ctx);
    goto after_132;
    // sra         $s0, $v1, 12
    ctx->r16 = S32(ctx->r3) >> 12;
    after_132:
    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8003B98C
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003B98C;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8003B98C:
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // nop

    // lh          $a0, 0x32($v0)
    ctx->r4 = MEM_HS(0X32, ctx->r2);
    // jal         0x800743F4
    // sra         $s1, $v1, 12
    ctx->r17 = S32(ctx->r3) >> 12;
    rsin(rdram, ctx);
    goto after_133;
    // sra         $s1, $v1, 12
    ctx->r17 = S32(ctx->r3) >> 12;
    after_133:
    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8003B9B4
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003B9B4;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8003B9B4:
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // nop

    // lh          $a0, 0x34($v0)
    ctx->r4 = MEM_HS(0X34, ctx->r2);
    // jal         0x800743F4
    // sra         $s0, $v1, 12
    ctx->r16 = S32(ctx->r3) >> 12;
    rsin(rdram, ctx);
    goto after_134;
    // sra         $s0, $v1, 12
    ctx->r16 = S32(ctx->r3) >> 12;
    after_134:
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // nop

    // lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(0X20, ctx->r2);
    // lw          $v1, 0x1C($s6)
    ctx->r3 = MEM_W(0X1C, ctx->r22);
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lh          $a0, 0x34($v1)
    ctx->r4 = MEM_HS(0X34, ctx->r3);
    // j           L_8003BAB8
    // nop

    goto L_8003BAB8;
    // nop

L_8003B9EC:
    // lw          $a0, 0x1C($s6)
    ctx->r4 = MEM_W(0X1C, ctx->r22);
    // nop

    // lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(0X0, ctx->r4);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8003B4F8
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8003B4F8;
    }
    // nop

    // lh          $a0, 0x34($a0)
    ctx->r4 = MEM_HS(0X34, ctx->r4);
    // jal         0x800744C4
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    rcos(rdram, ctx);
    goto after_135;
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    after_135:
    // lw          $a0, 0x1C($s6)
    ctx->r4 = MEM_W(0X1C, ctx->r22);
    // nop

    // lh          $v1, 0x38($a0)
    ctx->r3 = MEM_HS(0X38, ctx->r4);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8003BA34
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003BA34;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8003BA34:
    // lh          $a0, 0x32($a0)
    ctx->r4 = MEM_HS(0X32, ctx->r4);
    // jal         0x800744C4
    // sra         $s0, $v1, 12
    ctx->r16 = S32(ctx->r3) >> 12;
    rcos(rdram, ctx);
    goto after_136;
    // sra         $s0, $v1, 12
    ctx->r16 = S32(ctx->r3) >> 12;
    after_136:
    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8003BA54
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003BA54;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8003BA54:
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // nop

    // lh          $a0, 0x32($v0)
    ctx->r4 = MEM_HS(0X32, ctx->r2);
    // jal         0x800743F4
    // sra         $s1, $v1, 12
    ctx->r17 = S32(ctx->r3) >> 12;
    rsin(rdram, ctx);
    goto after_137;
    // sra         $s1, $v1, 12
    ctx->r17 = S32(ctx->r3) >> 12;
    after_137:
    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8003BA7C
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003BA7C;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8003BA7C:
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // nop

    // lh          $a0, 0x34($v0)
    ctx->r4 = MEM_HS(0X34, ctx->r2);
    // sra         $s0, $v1, 12
    ctx->r16 = S32(ctx->r3) >> 12;
    // jal         0x800743F4
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    rsin(rdram, ctx);
    goto after_138;
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    after_138:
    // lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(0X1C, ctx->r22);
    // nop

    // lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(0X20, ctx->r2);
    // lw          $v1, 0x1C($s6)
    ctx->r3 = MEM_W(0X1C, ctx->r22);
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // sw          $v0, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->r2;
    // lh          $a0, 0x34($v1)
    ctx->r4 = MEM_HS(0X34, ctx->r3);
    // nop

    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
L_8003BAB8:
    // jal         0x800743F4
    // nop

    rsin(rdram, ctx);
    goto after_139;
    // nop

    after_139:
    // lw          $a0, 0x1C($s6)
    ctx->r4 = MEM_W(0X1C, ctx->r22);
    // nop

    // lh          $v1, 0x38($a0)
    ctx->r3 = MEM_HS(0X38, ctx->r4);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8003BAE4
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003BAE4;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8003BAE4:
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(0X24, ctx->r4);
    // lw          $a0, 0x1C($s6)
    ctx->r4 = MEM_W(0X1C, ctx->r22);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->r2;
    // lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(0X28, ctx->r4);
    // lh          $v1, 0x10($s6)
    ctx->r3 = MEM_HS(0X10, ctx->r22);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sw          $v0, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r2;
    // slti        $v0, $v1, 0x20
    ctx->r2 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
L_8003BB0C:
    // beq         $v0, $zero, L_8003BBDC
    if (ctx->r2 == 0) {
        // sll         $v0, $v1, 7
        ctx->r2 = S32(ctx->r3) << 7;
        goto L_8003BBDC;
    }
    // sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3) << 7;
    // j           L_8003BBDC
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
    goto L_8003BBDC;
    // sh          $v0, 0x12($s6)
    MEM_H(0X12, ctx->r22) = ctx->r2;
L_8003BB1C:
    // addiu       $v0, $zero, 0x5E
    ctx->r2 = ADD32(0, 0X5E);
    // beq         $s1, $v0, L_8003BB44
    if (ctx->r17 == ctx->r2) {
        // addiu       $a0, $zero, 0x40
        ctx->r4 = ADD32(0, 0X40);
        goto L_8003BB44;
    }
    // addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // lh          $v0, 0x10($s6)
    ctx->r2 = MEM_HS(0X10, ctx->r22);
    // jal         0x800743F4
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    rsin(rdram, ctx);
    goto after_140;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    after_140:
    // lhu         $v1, 0x32($s6)
    ctx->r3 = MEM_HU(0X32, ctx->r22);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x32($s6)
    MEM_H(0X32, ctx->r22) = ctx->r3;
L_8003BB44:
    // lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // lhu         $v0, 0x38($s6)
    ctx->r2 = MEM_HU(0X38, ctx->r22);
    // lhu         $v1, 0x3A($s6)
    ctx->r3 = MEM_HU(0X3A, ctx->r22);
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // sh          $v1, 0x3A($s6)
    MEM_H(0X3A, ctx->r22) = ctx->r3;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $a2, $v1, 16
    ctx->r6 = S32(ctx->r3) >> 16;
    // srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // sra         $a3, $a2, 1
    ctx->r7 = S32(ctx->r6) >> 1;
    // or          $a1, $a3, $a1
    ctx->r5 = ctx->r7 | ctx->r5;
    // srl         $a2, $a2, 31
    ctx->r6 = S32(U32(ctx->r6) >> 31);
    // addu        $a2, $a3, $a2
    ctx->r6 = ADD32(ctx->r7, ctx->r6);
    // sh          $v0, 0x38($s6)
    MEM_H(0X38, ctx->r22) = ctx->r2;
    // lhu         $v0, 0x3C($s6)
    ctx->r2 = MEM_HU(0X3C, ctx->r22);
    // lhu         $v1, 0x38($s6)
    ctx->r3 = MEM_HU(0X38, ctx->r22);
    // addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, 0X80);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sh          $v0, 0x3C($s6)
    MEM_H(0X3C, ctx->r22) = ctx->r2;
    // sra         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) >> 16;
    // srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v0, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r2;
    // lhu         $a0, 0xC($s6)
    ctx->r4 = MEM_HU(0XC, ctx->r22);
    // sra         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6) >> 1;
    // jal         0x80035D04
    // sw          $a3, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r7;
    sub_80035D04(rdram, ctx);
    goto after_141;
    // sw          $a3, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r7;
    after_141:
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // beq         $s0, $zero, L_8003BBDC
    if (ctx->r16 == 0) {
        // andi        $v0, $s0, 0x80
        ctx->r2 = ctx->r16 & 0X80;
        goto L_8003BBDC;
    }
    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // beq         $v0, $zero, L_8003BBDC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003BBDC;
    }
    // nop

L_8003BBCC:
    // jal         0x8003618C
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8003618C(rdram, ctx);
    goto after_142;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_142:
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8003BBD8:
    // sb          $v0, 0x8($s6)
    MEM_B(0X8, ctx->r22) = ctx->r2;
L_8003BBDC:
    // lw          $ra, 0x18C($sp)
    ctx->r31 = MEM_W(0X18C, ctx->r29);
    // lw          $fp, 0x188($sp)
    ctx->r30 = MEM_W(0X188, ctx->r29);
    // lw          $s7, 0x184($sp)
    ctx->r23 = MEM_W(0X184, ctx->r29);
    // lw          $s6, 0x180($sp)
    ctx->r22 = MEM_W(0X180, ctx->r29);
    // lw          $s5, 0x17C($sp)
    ctx->r21 = MEM_W(0X17C, ctx->r29);
    // lw          $s4, 0x178($sp)
    ctx->r20 = MEM_W(0X178, ctx->r29);
    // lw          $s3, 0x174($sp)
    ctx->r19 = MEM_W(0X174, ctx->r29);
    // lw          $s2, 0x170($sp)
    ctx->r18 = MEM_W(0X170, ctx->r29);
    // lw          $s1, 0x16C($sp)
    ctx->r17 = MEM_W(0X16C, ctx->r29);
    // lw          $s0, 0x168($sp)
    ctx->r16 = MEM_W(0X168, ctx->r29);
    // addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
    // jr          $ra
    // nop

    return;
    // nop

;}
