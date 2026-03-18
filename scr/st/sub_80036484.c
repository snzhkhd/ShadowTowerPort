#include "recomp.h"
#include "disable_warnings.h"

void sub_80036484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // andi        $v0, $s0, 0x20
    ctx->r2 = ctx->r16 & 0X20;
    // sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // srl         $s4, $v0, 5
    ctx->r20 = S32(U32(ctx->r2) >> 5);
    // sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
    // sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // jal         0x80036370
    // sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    sub_80036370(rdram, ctx);
    goto after_0;
    // sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    after_0:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // beq         $s2, $zero, L_80037DE4
    if (ctx->r18 == 0) {
        // addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
        goto L_80037DE4;
    }
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // sb          $s0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r16;
    // beq         $s5, $zero, L_80036500
    if (ctx->r21 == 0) {
        // sb          $s1, 0x1($s2)
        MEM_B(0X1, ctx->r18) = ctx->r17;
        goto L_80036500;
    }
    // sb          $s1, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r17;
    // lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(0X0, ctx->r21);
    // lw          $v1, 0x4($s5)
    ctx->r3 = MEM_W(0X4, ctx->r21);
    // lw          $a0, 0x8($s5)
    ctx->r4 = MEM_W(0X8, ctx->r21);
    // lw          $a1, 0xC($s5)
    ctx->r5 = MEM_W(0XC, ctx->r21);
    // sw          $v0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r2;
    // sw          $v1, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r3;
    // sw          $a0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r4;
    // sw          $a1, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r5;
L_80036500:
    // lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(0X70, ctx->r29);
    // nop

    // beq         $a2, $zero, L_80036538
    if (ctx->r6 == 0) {
        // nop
    
        goto L_80036538;
    }
    // nop

    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // swl         $v0, 0x43($s2)
    do_swl(rdram, 0X43, ctx->r18, ctx->r2);
    // swr         $v0, 0x40($s2)
    do_swr(rdram, 0X40, ctx->r18, ctx->r2);
    // swl         $v1, 0x47($s2)
    do_swl(rdram, 0X47, ctx->r18, ctx->r3);
    // swr         $v1, 0x44($s2)
    do_swr(rdram, 0X44, ctx->r18, ctx->r3);
    // j           L_80036544
    // nop

    goto L_80036544;
    // nop

L_80036538:
    // sh          $zero, 0x44($s2)
    MEM_H(0X44, ctx->r18) = 0;
    // sh          $zero, 0x42($s2)
    MEM_H(0X42, ctx->r18) = 0;
    // sh          $zero, 0x40($s2)
    MEM_H(0X40, ctx->r18) = 0;
L_80036544:
    // lbu         $v1, 0x1($s2)
    ctx->r3 = MEM_BU(0X1, ctx->r18);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // sb          $zero, 0x5($s2)
    MEM_B(0X5, ctx->r18) = 0;
    // sb          $s6, 0x4($s2)
    MEM_B(0X4, ctx->r18) = ctx->r22;
    // sh          $zero, 0x34($s2)
    MEM_H(0X34, ctx->r18) = 0;
    // sh          $zero, 0x32($s2)
    MEM_H(0X32, ctx->r18) = 0;
    // sh          $zero, 0x30($s2)
    MEM_H(0X30, ctx->r18) = 0;
    // sh          $zero, 0x14($s2)
    MEM_H(0X14, ctx->r18) = 0;
    // sb          $zero, 0x3($s2)
    MEM_B(0X3, ctx->r18) = 0;
    // sb          $zero, 0x8($s2)
    MEM_B(0X8, ctx->r18) = 0;
    // sh          $zero, 0x12($s2)
    MEM_H(0X12, ctx->r18) = 0;
    // sb          $zero, 0x7($s2)
    MEM_B(0X7, ctx->r18) = 0;
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // sh          $zero, 0xE($s2)
    MEM_H(0XE, ctx->r18) = 0;
    // sltiu       $v0, $v1, 0xF6
    ctx->r2 = ctx->r3 < 0XF6 ? 1 : 0;
    // beq         $v0, $zero, L_80037DD8
    if (ctx->r2 == 0) {
        // sw          $zero, 0x1C($s2)
        MEM_W(0X1C, ctx->r18) = 0;
        goto L_80037DD8;
    }
    // sw          $zero, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = 0;
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x14CC
    ctx->r2 = ADD32(ctx->r2, 0X14CC);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_800365C0;
    jr_addend_800365C0 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_800365C0 >> 2) {
        case 0: goto L_800365C8; break;
        case 1: goto L_800369E4; break;
        case 2: goto L_80037DD8; break;
        case 3: goto L_800368C0; break;
        case 4: goto L_800369E4; break;
        case 5: goto L_80037DD8; break;
        case 6: goto L_80036984; break;
        case 7: goto L_80036708; break;
        case 8: goto L_80037DD8; break;
        case 9: goto L_800368E0; break;
        case 10: goto L_800365C8; break;
        case 11: goto L_80037DD8; break;
        case 12: goto L_80036934; break;
        case 13: goto L_800369E4; break;
        case 14: goto L_80037DD8; break;
        case 15: goto L_800369B4; break;
        case 16: goto L_800369E4; break;
        case 17: goto L_80037DD8; break;
        case 18: goto L_80037DD8; break;
        case 19: goto L_80037DD8; break;
        case 20: goto L_80037DD8; break;
        case 21: goto L_80037DD8; break;
        case 22: goto L_80037DD8; break;
        case 23: goto L_80037DD8; break;
        case 24: goto L_80037DD8; break;
        case 25: goto L_80037DD8; break;
        case 26: goto L_80037DD8; break;
        case 27: goto L_80037DD8; break;
        case 28: goto L_80037DD8; break;
        case 29: goto L_80037DD8; break;
        case 30: goto L_80037DD8; break;
        case 31: goto L_80037DD8; break;
        case 32: goto L_80037DD8; break;
        case 33: goto L_80037DD8; break;
        case 34: goto L_80037DD8; break;
        case 35: goto L_80037DD8; break;
        case 36: goto L_80037DD8; break;
        case 37: goto L_80037DD8; break;
        case 38: goto L_80037DD8; break;
        case 39: goto L_80037DD8; break;
        case 40: goto L_80037DD8; break;
        case 41: goto L_80037DD8; break;
        case 42: goto L_80037DD8; break;
        case 43: goto L_80036AE0; break;
        case 44: goto L_80036B10; break;
        case 45: goto L_80036B10; break;
        case 46: goto L_80036B10; break;
        case 47: goto L_80036B10; break;
        case 48: goto L_80036B98; break;
        case 49: goto L_80036DC0; break;
        case 50: goto L_80036DC0; break;
        case 51: goto L_80036DC0; break;
        case 52: goto L_80036DC0; break;
        case 53: goto L_80037004; break;
        case 54: goto L_80036DC0; break;
        case 55: goto L_80036DC0; break;
        case 56: goto L_80036B98; break;
        case 57: goto L_80036DC0; break;
        case 58: goto L_80037430; break;
        case 59: goto L_80037DD8; break;
        case 60: goto L_80036DC0; break;
        case 61: goto L_8003719C; break;
        case 62: goto L_80037440; break;
        case 63: goto L_80036DC0; break;
        case 64: goto L_80037A30; break;
        case 65: goto L_80037440; break;
        case 66: goto L_80036DC0; break;
        case 67: goto L_80036DC0; break;
        case 68: goto L_80037DD8; break;
        case 69: goto L_80036DC0; break;
        case 70: goto L_8003719C; break;
        case 71: goto L_80036DC0; break;
        case 72: goto L_80037440; break;
        case 73: goto L_80036DC0; break;
        case 74: goto L_80036DC0; break;
        case 75: goto L_80036DC0; break;
        case 76: goto L_80037DD8; break;
        case 77: goto L_80036DC0; break;
        case 78: goto L_80037DD8; break;
        case 79: goto L_80036DC0; break;
        case 80: goto L_80037DD8; break;
        case 81: goto L_80036DC0; break;
        case 82: goto L_8003719C; break;
        case 83: goto L_80037004; break;
        case 84: goto L_80037DD8; break;
        case 85: goto L_800376F0; break;
        case 86: goto L_80036DC0; break;
        case 87: goto L_80037580; break;
        case 88: goto L_80037580; break;
        case 89: goto L_80037780; break;
        case 90: goto L_8003719C; break;
        case 91: goto L_80037DD8; break;
        case 92: goto L_80037580; break;
        case 93: goto L_80037924; break;
        case 94: goto L_80037440; break;
        case 95: goto L_80036DC0; break;
        case 96: goto L_80036DC0; break;
        case 97: goto L_80037580; break;
        case 98: goto L_80037580; break;
        case 99: goto L_80037580; break;
        case 100: goto L_8003719C; break;
        case 101: goto L_800378A0; break;
        case 102: goto L_80036C50; break;
        case 103: goto L_80037580; break;
        case 104: goto L_80037580; break;
        case 105: goto L_80037950; break;
        case 106: goto L_80036DC0; break;
        case 107: goto L_80036DC0; break;
        case 108: goto L_80037440; break;
        case 109: goto L_80036DC0; break;
        case 110: goto L_80036DC0; break;
        case 111: goto L_80036DC0; break;
        case 112: goto L_80036DC0; break;
        case 113: goto L_80037440; break;
        case 114: goto L_80036DC0; break;
        case 115: goto L_80036DC0; break;
        case 116: goto L_80037580; break;
        case 117: goto L_800378A0; break;
        case 118: goto L_800379F8; break;
        case 119: goto L_800378A0; break;
        case 120: goto L_80037B14; break;
        case 121: goto L_80037B14; break;
        case 122: goto L_80037440; break;
        case 123: goto L_80036DC0; break;
        case 124: goto L_80037BBC; break;
        case 125: goto L_80036D08; break;
        case 126: goto L_80037260; break;
        case 127: goto L_80036DC0; break;
        case 128: goto L_800378A0; break;
        case 129: goto L_80037260; break;
        case 130: goto L_80037004; break;
        case 131: goto L_80037BBC; break;
        case 132: goto L_80037BBC; break;
        case 133: goto L_80036DC0; break;
        case 134: goto L_8003719C; break;
        case 135: goto L_80036DC0; break;
        case 136: goto L_80037A30; break;
        case 137: goto L_80037440; break;
        case 138: goto L_80037260; break;
        case 139: goto L_80037A30; break;
        case 140: goto L_80037580; break;
        case 141: goto L_80037004; break;
        case 142: goto L_80037BBC; break;
        case 143: goto L_80036DC0; break;
        case 144: goto L_80036DC0; break;
        case 145: goto L_80037BBC; break;
        case 146: goto L_80036DC0; break;
        case 147: goto L_80037440; break;
        case 148: goto L_80036DC0; break;
        case 149: goto L_80037580; break;
        case 150: goto L_80037BBC; break;
        case 151: goto L_80037810; break;
        case 152: goto L_80036DC0; break;
        case 153: goto L_80036DC0; break;
        case 154: goto L_800374FC; break;
        case 155: goto L_80036DC0; break;
        case 156: goto L_80037580; break;
        case 157: goto L_80036DC0; break;
        case 158: goto L_80037580; break;
        case 159: goto L_80036DC0; break;
        case 160: goto L_80037BBC; break;
        case 161: goto L_80036D08; break;
        case 162: goto L_80037A30; break;
        case 163: goto L_80036DC0; break;
        case 164: goto L_80037440; break;
        case 165: goto L_80036DC0; break;
        case 166: goto L_800378A0; break;
        case 167: goto L_80037BBC; break;
        case 168: goto L_80037A30; break;
        case 169: goto L_80037BBC; break;
        case 170: goto L_80036688; break;
        case 171: goto L_80036664; break;
        case 172: goto L_80036698; break;
        case 173: goto L_80036698; break;
        case 174: goto L_80036698; break;
        case 175: goto L_800367D4; break;
        case 176: goto L_80036828; break;
        case 177: goto L_80036854; break;
        case 178: goto L_80036878; break;
        case 179: goto L_8003689C; break;
        case 180: goto L_80037DD8; break;
        case 181: goto L_80037DD8; break;
        case 182: goto L_80037DD8; break;
        case 183: goto L_80037DD8; break;
        case 184: goto L_80037DD8; break;
        case 185: goto L_80037DD8; break;
        case 186: goto L_80037DD8; break;
        case 187: goto L_80037DD8; break;
        case 188: goto L_80037DD8; break;
        case 189: goto L_80037DD8; break;
        case 190: goto L_80037DD8; break;
        case 191: goto L_80037DD8; break;
        case 192: goto L_80037DD8; break;
        case 193: goto L_80037DD8; break;
        case 194: goto L_80037DD8; break;
        case 195: goto L_80037DD8; break;
        case 196: goto L_80037DD8; break;
        case 197: goto L_80037DD8; break;
        case 198: goto L_80037DD8; break;
        case 199: goto L_80037DD8; break;
        case 200: goto L_80036F38; break;
        case 201: goto L_80036FEC; break;
        case 202: goto L_800370C0; break;
        case 203: goto L_8003732C; break;
        case 204: goto L_800373F4; break;
        case 205: goto L_800370C0; break;
        case 206: goto L_8003732C; break;
        case 207: goto L_800373F4; break;
        case 208: goto L_800370C0; break;
        case 209: goto L_8003732C; break;
        case 210: goto L_800373F4; break;
        case 211: goto L_80036F38; break;
        case 212: goto L_80036FEC; break;
        case 213: goto L_80037534; break;
        case 214: goto L_8003763C; break;
        case 215: goto L_80037660; break;
        case 216: goto L_800370C0; break;
        case 217: goto L_8003732C; break;
        case 218: goto L_800373F4; break;
        case 219: goto L_800370C0; break;
        case 220: goto L_8003732C; break;
        case 221: goto L_800373F4; break;
        case 222: goto L_800370C0; break;
        case 223: goto L_8003732C; break;
        case 224: goto L_800373F4; break;
        case 225: goto L_800370C0; break;
        case 226: goto L_8003732C; break;
        case 227: goto L_800373F4; break;
        case 228: goto L_80036F38; break;
        case 229: goto L_80036FEC; break;
        case 230: goto L_800370C0; break;
        case 231: goto L_8003732C; break;
        case 232: goto L_800373F4; break;
        case 233: goto L_80037D84; break;
        case 234: goto L_80037D84; break;
        case 235: goto L_800370C0; break;
        case 236: goto L_8003732C; break;
        case 237: goto L_800373F4; break;
        case 238: goto L_80036F38; break;
        case 239: goto L_80036FEC; break;
        case 240: goto L_800374FC; break;
        case 241: goto L_800374FC; break;
        case 242: goto L_800374FC; break;
        case 243: goto L_800374FC; break;
        case 244: goto L_800374FC; break;
        case 245: goto L_800374FC; break;
        default: switch_error(__func__, 0x800365C0, 0x800114CC);
    }
    // nop

L_800365C8:
    // addiu       $s1, $s2, 0x20
    ctx->r17 = ADD32(ctx->r18, 0X20);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // addiu       $v0, $zero, 0x7148
    ctx->r2 = ADD32(0, 0X7148);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // srl         $a0, $a0, 2
    ctx->r4 = S32(U32(ctx->r4) >> 2);
    // andi        $a0, $a0, 0x8
    ctx->r4 = ctx->r4 & 0X8;
    // jal         0x80058254
    // addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    sub_80058254(rdram, ctx);
    goto after_1;
    // addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // ori         $v1, $v1, 0x40
    ctx->r3 = ctx->r3 | 0X40;
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $a2, $zero, 0xAB
    ctx->r6 = ADD32(0, 0XAB);
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addiu       $s0, $s2, 0x40
    ctx->r16 = ADD32(ctx->r18, 0X40);
    // sb          $zero, 0x50($s2)
    MEM_B(0X50, ctx->r18) = 0;
    // sb          $zero, 0x51($s2)
    MEM_B(0X51, ctx->r18) = 0;
    // sb          $zero, 0x6($s2)
    MEM_B(0X6, ctx->r18) = 0;
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // sw          $v1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r3;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(0X4, ctx->r19);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // jal         0x80036484
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_2:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addiu       $a2, $zero, 0xAA
    ctx->r6 = ADD32(0, 0XAA);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(0X4, ctx->r19);
    // j           L_80036ACC
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    goto L_80036ACC;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
L_80036664:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // sll         $a1, $s4, 3
    ctx->r5 = S32(ctx->r20) << 3;
    // ori         $a1, $a1, 0x4
    ctx->r5 = ctx->r5 | 0X4;
    // lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(0X4, ctx->r19);
    // jal         0x800363EC
    // addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    sub_800363EC(rdram, ctx);
    goto after_3;
    // addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    after_3:
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // j           L_80036B04
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    goto L_80036B04;
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
L_80036688:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // sll         $a1, $s4, 3
    ctx->r5 = S32(ctx->r20) << 3;
    // j           L_80036AEC
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    goto L_80036AEC;
    // ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
L_80036698:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // sll         $a1, $s4, 3
    ctx->r5 = S32(ctx->r20) << 3;
    // lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(0X4, ctx->r19);
    // lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(0X10, ctx->r19);
    // lw          $a3, 0x18($s3)
    ctx->r7 = MEM_W(0X18, ctx->r19);
    // jal         0x800363B4
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    sub_800363B4(rdram, ctx);
    goto after_4;
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    after_4:
    // lhu         $v0, 0x8($s3)
    ctx->r2 = MEM_HU(0X8, ctx->r19);
    // nop

    // sh          $v0, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r2;
    // lhu         $v0, 0xC($s3)
    ctx->r2 = MEM_HU(0XC, ctx->r19);
    // nop

    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x14($s3)
    ctx->r2 = MEM_HU(0X14, ctx->r19);
    // nop

    // sh          $v0, 0x52($s2)
    MEM_H(0X52, ctx->r18) = ctx->r2;
    // lw          $v0, 0x1C($s3)
    ctx->r2 = MEM_W(0X1C, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // j           L_80037DE4
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    goto L_80037DE4;
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_80036708:
    // addiu       $s1, $s2, 0x20
    ctx->r17 = ADD32(ctx->r18, 0X20);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // addiu       $v0, $zero, 0x7148
    ctx->r2 = ADD32(0, 0X7148);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // srl         $a0, $a0, 2
    ctx->r4 = S32(U32(ctx->r4) >> 2);
    // andi        $a0, $a0, 0x8
    ctx->r4 = ctx->r4 & 0X8;
    // jal         0x80058254
    // addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    sub_80058254(rdram, ctx);
    goto after_5;
    // addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_5:
    // lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // ori         $a1, $a1, 0x40
    ctx->r5 = ctx->r5 | 0X40;
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // addiu       $a2, $zero, 0xAF
    ctx->r6 = ADD32(0, 0XAF);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $t0, 0x7($v0)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X7, ctx->r2);
    // lwr         $t0, 0x4($v0)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $t0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r8);
    // swr         $t0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r8);
    // lhu         $v1, 0x32($s2)
    ctx->r3 = MEM_HU(0X32, ctx->r18);
    // addiu       $s0, $s2, 0x40
    ctx->r16 = ADD32(ctx->r18, 0X40);
    // sw          $a1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r5;
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sb          $zero, 0x50($s2)
    MEM_B(0X50, ctx->r18) = 0;
    // sb          $zero, 0x51($s2)
    MEM_B(0X51, ctx->r18) = 0;
    // sb          $zero, 0x6($s2)
    MEM_B(0X6, ctx->r18) = 0;
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x800
    ctx->r3 = ADD32(ctx->r3, 0X800);
    // sh          $v1, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r3;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(0X4, ctx->r19);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // jal         0x80036484
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_6;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_6:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(0X4, ctx->r19);
    // j           L_80036ACC
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    goto L_80036ACC;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
L_800367D4:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // sll         $a1, $s4, 3
    ctx->r5 = S32(ctx->r20) << 3;
    // lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(0X4, ctx->r19);
    // jal         0x800363B4
    // addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    sub_800363B4(rdram, ctx);
    goto after_7;
    // addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_7:
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // sb          $zero, 0x50($s2)
    MEM_B(0X50, ctx->r18) = 0;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // lwl         $v1, 0x33($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X33, ctx->r2);
    // lwr         $v1, 0x30($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X30, ctx->r2);
    // lwl         $a0, 0x37($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X37, ctx->r2);
    // lwr         $a0, 0x34($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X34, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // j           L_80037DE4
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    goto L_80037DE4;
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_80036828:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // sll         $a1, $s4, 3
    ctx->r5 = S32(ctx->r20) << 3;
    // ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(0X4, ctx->r19);
    // jal         0x800363EC
    // addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    sub_800363EC(rdram, ctx);
    goto after_8;
    // addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_8:
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // sb          $zero, 0x50($s2)
    MEM_B(0X50, ctx->r18) = 0;
    // j           L_80036B04
    // sb          $zero, 0x51($s2)
    MEM_B(0X51, ctx->r18) = 0;
    goto L_80036B04;
    // sb          $zero, 0x51($s2)
    MEM_B(0X51, ctx->r18) = 0;
L_80036854:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // sll         $a1, $s4, 3
    ctx->r5 = S32(ctx->r20) << 3;
    // lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(0X4, ctx->r19);
    // lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(0X10, ctx->r19);
    // lw          $a3, 0x14($s3)
    ctx->r7 = MEM_W(0X14, ctx->r19);
    // jal         0x800363EC
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    sub_800363EC(rdram, ctx);
    goto after_9;
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    after_9:
    // j           L_80037418
    // nop

    goto L_80037418;
    // nop

L_80036878:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // sll         $a1, $s4, 3
    ctx->r5 = S32(ctx->r20) << 3;
    // lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(0X4, ctx->r19);
    // lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(0X10, ctx->r19);
    // lw          $a3, 0x14($s3)
    ctx->r7 = MEM_W(0X14, ctx->r19);
    // jal         0x800363EC
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    sub_800363EC(rdram, ctx);
    goto after_10;
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    after_10:
    // j           L_80037418
    // nop

    goto L_80037418;
    // nop

L_8003689C:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // sll         $a1, $s4, 3
    ctx->r5 = S32(ctx->r20) << 3;
    // lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(0X4, ctx->r19);
    // lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(0X10, ctx->r19);
    // lw          $a3, 0x14($s3)
    ctx->r7 = MEM_W(0X14, ctx->r19);
    // jal         0x800363B4
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    sub_800363B4(rdram, ctx);
    goto after_11;
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    after_11:
    // j           L_80037418
    // nop

    goto L_80037418;
    // nop

L_800368C0:
    // lh          $a0, 0x38($s2)
    ctx->r4 = MEM_HS(0X38, ctx->r18);
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // bgez        $a0, L_800368D4
    if (SIGNED(ctx->r4) >= 0) {
        // sb          $v0, 0x50($s2)
        MEM_B(0X50, ctx->r18) = ctx->r2;
        goto L_800368D4;
    }
    // sb          $v0, 0x50($s2)
    MEM_B(0X50, ctx->r18) = ctx->r2;
    // addiu       $a0, $a0, 0xF
    ctx->r4 = ADD32(ctx->r4, 0XF);
L_800368D4:
    // lh          $v1, 0x3A($s2)
    ctx->r3 = MEM_HS(0X3A, ctx->r18);
    // j           L_80036A00
    // sra         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4) >> 4;
    goto L_80036A00;
    // sra         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4) >> 4;
L_800368E0:
    // lh          $a0, 0x38($s2)
    ctx->r4 = MEM_HS(0X38, ctx->r18);
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // bgez        $a0, L_800368F4
    if (SIGNED(ctx->r4) >= 0) {
        // sb          $v0, 0x50($s2)
        MEM_B(0X50, ctx->r18) = ctx->r2;
        goto L_800368F4;
    }
    // sb          $v0, 0x50($s2)
    MEM_B(0X50, ctx->r18) = ctx->r2;
    // addiu       $a0, $a0, 0xF
    ctx->r4 = ADD32(ctx->r4, 0XF);
L_800368F4:
    // lh          $v1, 0x3A($s2)
    ctx->r3 = MEM_HS(0X3A, ctx->r18);
    // sra         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4) >> 4;
    // bgez        $v1, L_80036908
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0xC($s2)
        MEM_H(0XC, ctx->r18) = ctx->r2;
        goto L_80036908;
    }
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0xF
    ctx->r3 = ADD32(ctx->r3, 0XF);
L_80036908:
    // sra         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) >> 4;
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // jal         0x80078AC4
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_12;
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    after_12:
    // bgez        $v0, L_80036928
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80036928;
    }
    // nop

    // addiu       $v0, $v0, 0x7F
    ctx->r2 = ADD32(ctx->r2, 0X7F);
L_80036928:
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // j           L_80036A1C
    // sh          $v0, 0x52($s2)
    MEM_H(0X52, ctx->r18) = ctx->r2;
    goto L_80036A1C;
    // sh          $v0, 0x52($s2)
    MEM_H(0X52, ctx->r18) = ctx->r2;
L_80036934:
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_80036958
    if (SIGNED(ctx->r2) >= 0) {
        // sb          $zero, 0x50($s2)
        MEM_B(0X50, ctx->r18) = 0;
        goto L_80036958;
    }
    // sb          $zero, 0x50($s2)
    MEM_B(0X50, ctx->r18) = 0;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80036958:
    // lh          $v1, 0x3A($s2)
    ctx->r3 = MEM_HS(0X3A, ctx->r18);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_8003697C
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8003697C;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_8003697C:
    // j           L_80036A10
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    goto L_80036A10;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
L_80036984:
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_HS(0X38, ctx->r18);
    // nop

    // bgez        $v0, L_80036998
    if (SIGNED(ctx->r2) >= 0) {
        // sb          $zero, 0x50($s2)
        MEM_B(0X50, ctx->r18) = 0;
        goto L_80036998;
    }
    // sb          $zero, 0x50($s2)
    MEM_B(0X50, ctx->r18) = 0;
    // addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
L_80036998:
    // lh          $v1, 0x3A($s2)
    ctx->r3 = MEM_HS(0X3A, ctx->r18);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // bgez        $v1, L_800369AC
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0xC($s2)
        MEM_H(0XC, ctx->r18) = ctx->r2;
        goto L_800369AC;
    }
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x3F
    ctx->r3 = ADD32(ctx->r3, 0X3F);
L_800369AC:
    // j           L_80036A10
    // sra         $v0, $v1, 6
    ctx->r2 = S32(ctx->r3) >> 6;
    goto L_80036A10;
    // sra         $v0, $v1, 6
    ctx->r2 = S32(ctx->r3) >> 6;
L_800369B4:
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_HS(0X38, ctx->r18);
    // nop

    // bgez        $v0, L_800369C8
    if (SIGNED(ctx->r2) >= 0) {
        // sb          $zero, 0x50($s2)
        MEM_B(0X50, ctx->r18) = 0;
        goto L_800369C8;
    }
    // sb          $zero, 0x50($s2)
    MEM_B(0X50, ctx->r18) = 0;
    // addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
L_800369C8:
    // lh          $v1, 0x3A($s2)
    ctx->r3 = MEM_HS(0X3A, ctx->r18);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // bgez        $v1, L_800369DC
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0xC($s2)
        MEM_H(0XC, ctx->r18) = ctx->r2;
        goto L_800369DC;
    }
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0xFF
    ctx->r3 = ADD32(ctx->r3, 0XFF);
L_800369DC:
    // j           L_80036A10
    // sra         $v0, $v1, 8
    ctx->r2 = S32(ctx->r3) >> 8;
    goto L_80036A10;
    // sra         $v0, $v1, 8
    ctx->r2 = S32(ctx->r3) >> 8;
L_800369E4:
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_HS(0X38, ctx->r18);
    // nop

    // bgez        $v0, L_800369F8
    if (SIGNED(ctx->r2) >= 0) {
        // sb          $zero, 0x50($s2)
        MEM_B(0X50, ctx->r18) = 0;
        goto L_800369F8;
    }
    // sb          $zero, 0x50($s2)
    MEM_B(0X50, ctx->r18) = 0;
    // addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
L_800369F8:
    // lh          $v1, 0x3A($s2)
    ctx->r3 = MEM_HS(0X3A, ctx->r18);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
L_80036A00:
    // bgez        $v1, L_80036A0C
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0xC($s2)
        MEM_H(0XC, ctx->r18) = ctx->r2;
        goto L_80036A0C;
    }
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0xF
    ctx->r3 = ADD32(ctx->r3, 0XF);
L_80036A0C:
    // sra         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) >> 4;
L_80036A10:
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
L_80036A1C:
    // addiu       $s0, $s2, 0x20
    ctx->r16 = ADD32(ctx->r18, 0X20);
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    // lbu         $a0, 0x0($s2)
    ctx->r4 = MEM_BU(0X0, ctx->r18);
    // addiu       $v0, $zero, 0x7148
    ctx->r2 = ADD32(0, 0X7148);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // srl         $a0, $a0, 2
    ctx->r4 = S32(U32(ctx->r4) >> 2);
    // andi        $a0, $a0, 0x8
    ctx->r4 = ctx->r4 & 0X8;
    // jal         0x80058254
    // addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    sub_80058254(rdram, ctx);
    goto after_13;
    // addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_13:
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // sll         $v0, $s4, 3
    ctx->r2 = S32(ctx->r20) << 3;
    // sh          $v0, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // sb          $v0, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // addiu       $a2, $zero, 0x2B
    ctx->r6 = ADD32(0, 0X2B);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a1, 0x7($v0)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X7, ctx->r2);
    // lwr         $a1, 0x4($v0)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a1, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r5);
    // swr         $a1, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r5);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addiu       $v0, $s2, 0x40
    ctx->r2 = ADD32(ctx->r18, 0X40);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(0X4, ctx->r19);
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
L_80036ACC:
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // jal         0x80036484
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_14;
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_14:
    // j           L_80037DE4
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    goto L_80037DE4;
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_80036AE0:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // sll         $a1, $s4, 3
    ctx->r5 = S32(ctx->r20) << 3;
    // ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
L_80036AEC:
    // lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(0X4, ctx->r19);
    // jal         0x800363EC
    // addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    sub_800363EC(rdram, ctx);
    goto after_15;
    // addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_15:
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // sb          $zero, 0x50($s2)
    MEM_B(0X50, ctx->r18) = 0;
L_80036B04:
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // j           L_80037DE0
    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    goto L_80037DE0;
    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
L_80036B10:
    // lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(0X4, ctx->r19);
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // lwl         $a0, 0x3($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X3, ctx->r2);
    // lwr         $a0, 0x0($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X0, ctx->r2);
    // lwl         $a1, 0x7($v0)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X7, ctx->r2);
    // lwr         $a1, 0x4($v0)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X4, ctx->r2);
    // swl         $a0, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r4);
    // swr         $a0, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r4);
    // swl         $a1, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r5);
    // swr         $a1, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r5);
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // sb          $v0, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(0X1, ctx->r18);
    // ori         $v1, $v1, 0x20
    ctx->r3 = ctx->r3 | 0X20;
    // sw          $v1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r3;
    // addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // sb          $zero, 0x7($s2)
    MEM_B(0X7, ctx->r18) = 0;
    // sb          $v1, 0x50($s2)
    MEM_B(0X50, ctx->r18) = ctx->r3;
    // addiu       $v0, $v0, -0x5E
    ctx->r2 = ADD32(ctx->r2, -0X5E);
    // sh          $v0, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x8($s3)
    ctx->r2 = MEM_HU(0X8, ctx->r19);
    // j           L_80037DE0
    // sh          $v0, 0x52($s2)
    MEM_H(0X52, ctx->r18) = ctx->r2;
    goto L_80037DE0;
    // sh          $v0, 0x52($s2)
    MEM_H(0X52, ctx->r18) = ctx->r2;
L_80036B98:
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // sb          $v0, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // nop

    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_80036C28
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80036C28;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80036C28:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_80036C48
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80036C48;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80036C48:
    // j           L_80037BAC
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    goto L_80037BAC;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
L_80036C50:
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // sb          $v0, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // nop

    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_80036CE0
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80036CE0;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80036CE0:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_80036D00
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80036D00;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80036D00:
    // j           L_80037BAC
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    goto L_80037BAC;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
L_80036D08:
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x84
    ctx->r2 = ADD32(0, 0X84);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x33
    ctx->r2 = ADD32(0, 0X33);
    // sb          $v0, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // nop

    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_80036D98
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80036D98;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80036D98:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // bgez        $v0, L_80036DB8
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80036DB8;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80036DB8:
    // j           L_80037BAC
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    goto L_80037BAC;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
L_80036DC0:
    // lbu         $v1, 0x1($s2)
    ctx->r3 = MEM_BU(0X1, ctx->r18);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x87
    ctx->r2 = ADD32(0, 0X87);
    // bne         $v1, $v0, L_80036DDC
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x40
        ctx->r2 = ADD32(0, 0X40);
        goto L_80036DDC;
    }
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_80036DDC:
    // jal         0x80078AC4
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_16;
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    after_16:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // bgez        $v1, L_80036DF8
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80036DF8;
    }
    // nop

    // addiu       $v1, $v1, 0x7FFF
    ctx->r3 = ADD32(ctx->r3, 0X7FFF);
L_80036DF8:
    // srl         $v1, $v1, 15
    ctx->r3 = S32(U32(ctx->r3) >> 15);
    // andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_80036E10
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80036E10;
    }
    // nop

    // addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80036E10:
    // lbu         $a0, 0x1($s2)
    ctx->r4 = MEM_BU(0X1, ctx->r18);
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // bne         $a0, $v0, L_80036E24
    if (ctx->r4 != ctx->r2) {
        // addiu       $a2, $zero, 0x99
        ctx->r6 = ADD32(0, 0X99);
        goto L_80036E24;
    }
    // addiu       $a2, $zero, 0x99
    ctx->r6 = ADD32(0, 0X99);
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80036E24:
    // bne         $a0, $a2, L_80036E30
    if (ctx->r4 != ctx->r6) {
        // addiu       $v0, $zero, 0x79
        ctx->r2 = ADD32(0, 0X79);
        goto L_80036E30;
    }
    // addiu       $v0, $zero, 0x79
    ctx->r2 = ADD32(0, 0X79);
    // addiu       $v1, $v1, 0x3
    ctx->r3 = ADD32(ctx->r3, 0X3);
L_80036E30:
    // bne         $a0, $v0, L_80036E3C
    if (ctx->r4 != ctx->r2) {
        // addiu       $a1, $zero, 0x85
        ctx->r5 = ADD32(0, 0X85);
        goto L_80036E3C;
    }
    // addiu       $a1, $zero, 0x85
    ctx->r5 = ADD32(0, 0X85);
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_80036E3C:
    // bne         $a0, $a1, L_80036E48
    if (ctx->r4 != ctx->r5) {
        // addiu       $v0, $zero, 0xA3
        ctx->r2 = ADD32(0, 0XA3);
        goto L_80036E48;
    }
    // addiu       $v0, $zero, 0xA3
    ctx->r2 = ADD32(0, 0XA3);
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80036E48:
    // bne         $a0, $v0, L_80036E58
    if (ctx->r4 != ctx->r2) {
        // ori         $v0, $v1, 0x80
        ctx->r2 = ctx->r3 | 0X80;
        goto L_80036E58;
    }
    // ori         $v0, $v1, 0x80
    ctx->r2 = ctx->r3 | 0X80;
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // ori         $v0, $v1, 0x80
    ctx->r2 = ctx->r3 | 0X80;
L_80036E58:
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v0, 0x8($s3)
    ctx->r2 = MEM_BU(0X8, ctx->r19);
    // lbu         $v1, 0x1($s2)
    ctx->r3 = MEM_BU(0X1, ctx->r18);
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // sh          $v0, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
    // beq         $v1, $v0, L_80036EA0
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x8F
        ctx->r2 = ADD32(0, 0X8F);
        goto L_80036EA0;
    }
    // addiu       $v0, $zero, 0x8F
    ctx->r2 = ADD32(0, 0X8F);
    // beq         $v1, $v0, L_80036EA4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xE
        ctx->r2 = ADD32(0, 0XE);
        goto L_80036EA4;
    }
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // beq         $v1, $a1, L_80036EA0
    if (ctx->r3 == ctx->r5) {
        // addiu       $v0, $zero, 0x4B
        ctx->r2 = ADD32(0, 0X4B);
        goto L_80036EA0;
    }
    // addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
    // beq         $v1, $v0, L_80036EA0
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x73
        ctx->r2 = ADD32(0, 0X73);
        goto L_80036EA0;
    }
    // addiu       $v0, $zero, 0x73
    ctx->r2 = ADD32(0, 0X73);
    // beq         $v1, $v0, L_80036EA4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xE
        ctx->r2 = ADD32(0, 0XE);
        goto L_80036EA4;
    }
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // bne         $v1, $a2, L_80036EA4
    if (ctx->r3 != ctx->r6) {
        // addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
        goto L_80036EA4;
    }
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80036EA0:
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_80036EA4:
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // bgez        $v1, L_80036ED4
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0x38($s2)
        MEM_H(0X38, ctx->r18) = ctx->r2;
        goto L_80036ED4;
    }
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
L_80036ED4:
    // lh          $a0, 0x38($s2)
    ctx->r4 = MEM_HS(0X38, ctx->r18);
    // sra         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) >> 3;
    // bgez        $a0, L_80036EE8
    if (SIGNED(ctx->r4) >= 0) {
        // sh          $v0, 0xC($s2)
        MEM_H(0XC, ctx->r18) = ctx->r2;
        goto L_80036EE8;
    }
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
L_80036EE8:
    // sra         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4) >> 3;
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // lbu         $v1, 0x1($s2)
    ctx->r3 = MEM_BU(0X1, ctx->r18);
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x56
    ctx->r2 = ADD32(0, 0X56);
    // beq         $v1, $v0, L_80036F20
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x5F
        ctx->r2 = ADD32(0, 0X5F);
        goto L_80036F20;
    }
    // addiu       $v0, $zero, 0x5F
    ctx->r2 = ADD32(0, 0X5F);
    // beq         $v1, $v0, L_80036F20
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x79
        ctx->r2 = ADD32(0, 0X79);
        goto L_80036F20;
    }
    // addiu       $v0, $zero, 0x79
    ctx->r2 = ADD32(0, 0X79);
    // beq         $v1, $v0, L_80036F20
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x70
        ctx->r2 = ADD32(0, 0X70);
        goto L_80036F20;
    }
    // addiu       $v0, $zero, 0x70
    ctx->r2 = ADD32(0, 0X70);
    // bne         $v1, $v0, L_800376D8
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800376D8;
    }
    // nop

L_80036F20:
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_17;
    // nop

    after_17:
    // sra         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) >> 9;
    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // j           L_80037DE0
    // sb          $v0, 0x50($s2)
    MEM_B(0X50, ctx->r18) = ctx->r2;
    goto L_80037DE0;
    // sb          $v0, 0x50($s2)
    MEM_B(0X50, ctx->r18) = ctx->r2;
L_80036F38:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x82
    ctx->r2 = ADD32(0, 0X82);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_HS(0X38, ctx->r18);
    // nop

    // bgez        $v0, L_80036FBC
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80036FBC;
    }
    // nop

    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
L_80036FBC:
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // bgez        $v1, L_80036FD0
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0xC($s2)
        MEM_H(0XC, ctx->r18) = ctx->r2;
        goto L_80036FD0;
    }
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
L_80036FD0:
    // sra         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) >> 3;
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(0X10, ctx->r19);
    // j           L_80037DE0
    // sw          $v0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->r2;
    goto L_80037DE0;
    // sw          $v0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->r2;
L_80036FEC:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // j           L_80037018
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    goto L_80037018;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_80037004:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x81
    ctx->r2 = ADD32(0, 0X81);
L_80037018:
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_HS(0X38, ctx->r18);
    // nop

    // bgez        $v0, L_80037088
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80037088;
    }
    // nop

    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
L_80037088:
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // bgez        $v1, L_8003709C
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0xC($s2)
        MEM_H(0XC, ctx->r18) = ctx->r2;
        goto L_8003709C;
    }
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
L_8003709C:
    // sra         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) >> 3;
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, -0x380
    ctx->r2 = ADD32(0, -0X380);
    // sh          $v0, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r2;
    // lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(0X10, ctx->r19);
    // j           L_80037DE0
    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    goto L_80037DE0;
    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
L_800370C0:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x24
    ctx->r2 = ADD32(0, 0X24);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x82
    ctx->r2 = ADD32(0, 0X82);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_HS(0X38, ctx->r18);
    // nop

    // bgez        $v0, L_80037144
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80037144;
    }
    // nop

    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
L_80037144:
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // bgez        $v1, L_80037158
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0xC($s2)
        MEM_H(0XC, ctx->r18) = ctx->r2;
        goto L_80037158;
    }
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
L_80037158:
    // sra         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) >> 3;
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(0X10, ctx->r19);
    // nop

    // sw          $v0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->r2;
    // lw          $v0, 0xA8($v0)
    ctx->r2 = MEM_W(0XA8, ctx->r2);
    // lw          $v1, 0x4C($s2)
    ctx->r3 = MEM_W(0X4C, ctx->r18);
    // lhu         $v0, 0x1C($v0)
    ctx->r2 = MEM_HU(0X1C, ctx->r2);
    // nop

    // sh          $v0, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r2;
    // lw          $v0, 0xA8($v1)
    ctx->r2 = MEM_W(0XA8, ctx->r3);
    // nop

    // lhu         $v0, 0x22($v0)
    ctx->r2 = MEM_HU(0X22, ctx->r2);
    // j           L_80037DE0
    // sh          $v0, 0x52($s2)
    MEM_H(0X52, ctx->r18) = ctx->r2;
    goto L_80037DE0;
    // sh          $v0, 0x52($s2)
    MEM_H(0X52, ctx->r18) = ctx->r2;
L_8003719C:
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // lhu         $v1, 0x38($s2)
    ctx->r3 = MEM_HU(0X38, ctx->r18);
    // addiu       $v0, $zero, -0x380
    ctx->r2 = ADD32(0, -0X380);
    // sh          $v0, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r2;
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_HS(0X38, ctx->r18);
    // sh          $v1, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r3;
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(0X10, ctx->r19);
    // nop

    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // lw          $v0, 0x4C($v0)
    ctx->r2 = MEM_W(0X4C, ctx->r2);
    // nop

    // sw          $v0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->r2;
    // lw          $v0, 0x78($v0)
    ctx->r2 = MEM_W(0X78, ctx->r2);
    // sh          $zero, 0x32($s2)
    MEM_H(0X32, ctx->r18) = 0;
    // sh          $zero, 0x40($s2)
    MEM_H(0X40, ctx->r18) = 0;
    // sh          $zero, 0x42($s2)
    MEM_H(0X42, ctx->r18) = 0;
    // sh          $zero, 0x44($s2)
    MEM_H(0X44, ctx->r18) = 0;
    // j           L_80037DE0
    // sw          $v0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r2;
    goto L_80037DE0;
    // sw          $v0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r2;
L_80037260:
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // lhu         $v1, 0x38($s2)
    ctx->r3 = MEM_HU(0X38, ctx->r18);
    // addiu       $v0, $zero, -0x380
    ctx->r2 = ADD32(0, -0X380);
    // sh          $v0, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r2;
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_HS(0X38, ctx->r18);
    // sh          $v1, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r3;
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(0X10, ctx->r19);
    // nop

    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // lw          $v0, 0x4C($v0)
    ctx->r2 = MEM_W(0X4C, ctx->r2);
    // nop

    // sw          $v0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lw          $v0, -0x6E8C($v0)
    ctx->r2 = MEM_W(-0X6E8C, ctx->r2);
    // sh          $zero, 0x32($s2)
    MEM_H(0X32, ctx->r18) = 0;
    // sh          $zero, 0x40($s2)
    MEM_H(0X40, ctx->r18) = 0;
    // sh          $zero, 0x42($s2)
    MEM_H(0X42, ctx->r18) = 0;
    // sh          $zero, 0x44($s2)
    MEM_H(0X44, ctx->r18) = 0;
    // addiu       $v0, $v0, 0x640
    ctx->r2 = ADD32(ctx->r2, 0X640);
    // j           L_80037DE0
    // sw          $v0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r2;
    goto L_80037DE0;
    // sw          $v0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r2;
L_8003732C:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x81
    ctx->r2 = ADD32(0, 0X81);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_HS(0X38, ctx->r18);
    // nop

    // bgez        $v0, L_800373B0
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800373B0;
    }
    // nop

    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
L_800373B0:
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // bgez        $v1, L_800373C4
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0xC($s2)
        MEM_H(0XC, ctx->r18) = ctx->r2;
        goto L_800373C4;
    }
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
L_800373C4:
    // sra         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) >> 3;
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, -0x380
    ctx->r2 = ADD32(0, -0X380);
    // sh          $v0, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r2;
    // lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(0X10, ctx->r19);
    // nop

    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    // lw          $v0, 0x4C($v0)
    ctx->r2 = MEM_W(0X4C, ctx->r2);
    // j           L_80037DE0
    // sw          $v0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->r2;
    goto L_80037DE0;
    // sw          $v0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->r2;
L_800373F4:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(0X4, ctx->r19);
    // lw          $a1, 0x10($s3)
    ctx->r5 = MEM_W(0X10, ctx->r19);
    // lw          $a3, 0x14($s3)
    ctx->r7 = MEM_W(0X14, ctx->r19);
    // addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // jal         0x800363EC
    // ori         $a3, $a3, 0x4
    ctx->r7 = ctx->r7 | 0X4;
    sub_800363EC(rdram, ctx);
    goto after_18;
    // ori         $a3, $a3, 0x4
    ctx->r7 = ctx->r7 | 0X4;
    after_18:
    // addiu       $v0, $zero, 0x83
    ctx->r2 = ADD32(0, 0X83);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
L_80037418:
    // lhu         $v0, 0x8($s3)
    ctx->r2 = MEM_HU(0X8, ctx->r19);
    // nop

    // sh          $v0, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r2;
    // lhu         $v0, 0xC($s3)
    ctx->r2 = MEM_HU(0XC, ctx->r19);
    // j           L_80037DE0
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    goto L_80037DE0;
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
L_80037430:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // j           L_80037B20
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    goto L_80037B20;
    // addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_80037440:
    // lbu         $v1, 0x1($s2)
    ctx->r3 = MEM_BU(0X1, ctx->r18);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x83
    ctx->r2 = ADD32(0, 0X83);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0xA4
    ctx->r2 = ADD32(0, 0XA4);
    // bne         $v1, $v0, L_8003746C
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x85
        ctx->r2 = ADD32(0, 0X85);
        goto L_8003746C;
    }
    // addiu       $v0, $zero, 0x85
    ctx->r2 = ADD32(0, 0X85);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
L_8003746C:
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // lhu         $v0, 0x38($s2)
    ctx->r2 = MEM_HU(0X38, ctx->r18);
    // lhu         $a0, 0x38($s2)
    ctx->r4 = MEM_HU(0X38, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) >> 16;
    // srl         $a0, $a0, 31
    ctx->r4 = S32(U32(ctx->r4) >> 31);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // j           L_80037BAC
    // sh          $v1, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r3;
    goto L_80037BAC;
    // sh          $v1, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r3;
L_800374FC:
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // sb          $zero, 0x6($s2)
    MEM_B(0X6, ctx->r18) = 0;
    // lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(0X4, ctx->r19);
    // nop

    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // sw          $v0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0xFFF
    ctx->r2 = ADD32(0, 0XFFF);
    // j           L_80037DE0
    // sh          $v0, 0x36($v1)
    MEM_H(0X36, ctx->r3) = ctx->r2;
    goto L_80037DE0;
    // sh          $v0, 0x36($v1)
    MEM_H(0X36, ctx->r3) = ctx->r2;
L_80037534:
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // jal         0x80078AC4
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_19;
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    after_19:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // bgez        $v1, L_8003755C
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003755C;
    }
    // nop

    // addiu       $v1, $v1, 0x7FFF
    ctx->r3 = ADD32(ctx->r3, 0X7FFF);
L_8003755C:
    // srl         $v1, $v1, 15
    ctx->r3 = S32(U32(ctx->r3) >> 15);
    // andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_80037574
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80037574;
    }
    // nop

    // addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80037574:
    // addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // j           L_800376A4
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    goto L_800376A4;
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
L_80037580:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x83
    ctx->r2 = ADD32(0, 0X83);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0x8($s3)
    ctx->r3 = MEM_BU(0X8, ctx->r19);
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $a0, 0x4($s3)
    ctx->r4 = MEM_HU(0X4, ctx->r19);
    // nop

    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) << 9;
    // sh          $a0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r4;
    // sh          $a0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r4;
    // bgez        $v0, L_800375E4
    if (SIGNED(ctx->r2) >= 0) {
        // sh          $a0, 0x38($s2)
        MEM_H(0X38, ctx->r18) = ctx->r4;
        goto L_800375E4;
    }
    // sh          $a0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r4;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_800375E4:
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) << 9;
    // bgez        $v0, L_80037608
    if (SIGNED(ctx->r2) >= 0) {
        // addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
        goto L_80037608;
    }
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80037608:
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    // addiu       $v0, $s2, 0x40
    ctx->r2 = ADD32(ctx->r18, 0X40);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_HS(0X38, ctx->r18);
    // addiu       $a2, $zero, 0xD6
    ctx->r6 = ADD32(0, 0XD6);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // lh          $v0, 0xA($s2)
    ctx->r2 = MEM_HS(0XA, ctx->r18);
    // j           L_80037D6C
    // addiu       $a3, $s2, 0x20
    ctx->r7 = ADD32(ctx->r18, 0X20);
    goto L_80037D6C;
    // addiu       $a3, $s2, 0x20
    ctx->r7 = ADD32(ctx->r18, 0X20);
L_8003763C:
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0x8($s3)
    ctx->r3 = MEM_BU(0X8, ctx->r19);
    // j           L_80037DA4
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    goto L_80037DA4;
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80037660:
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // jal         0x80078AC4
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_20;
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    after_20:
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // bgez        $v1, L_80037688
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80037688;
    }
    // nop

    // addiu       $v1, $v1, 0x7FFF
    ctx->r3 = ADD32(ctx->r3, 0X7FFF);
L_80037688:
    // srl         $v1, $v1, 15
    ctx->r3 = S32(U32(ctx->r3) >> 15);
    // andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // sltiu       $v0, $v0, 0x3
    ctx->r2 = ctx->r2 < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_800376A4
    if (ctx->r2 != 0) {
        // ori         $v0, $v1, 0x80
        ctx->r2 = ctx->r3 | 0X80;
        goto L_800376A4;
    }
    // ori         $v0, $v1, 0x80
    ctx->r2 = ctx->r3 | 0X80;
    // addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // ori         $v0, $v1, 0x80
    ctx->r2 = ctx->r3 | 0X80;
L_800376A4:
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0x8($s3)
    ctx->r3 = MEM_BU(0X8, ctx->r19);
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
L_800376D8:
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_21;
    // nop

    after_21:
    // sra         $v0, $v0, 11
    ctx->r2 = S32(ctx->r2) >> 11;
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // j           L_80037DE0
    // sb          $v0, 0x50($s2)
    MEM_B(0X50, ctx->r18) = ctx->r2;
    goto L_80037DE0;
    // sb          $v0, 0x50($s2)
    MEM_B(0X50, ctx->r18) = ctx->r2;
L_800376F0:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x86
    ctx->r2 = ADD32(0, 0X86);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0x8($s3)
    ctx->r3 = MEM_BU(0X8, ctx->r19);
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $a0, 0x4($s3)
    ctx->r4 = MEM_HU(0X4, ctx->r19);
    // nop

    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) << 9;
    // sh          $a0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r4;
    // sh          $a0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r4;
    // bgez        $v0, L_80037754
    if (SIGNED(ctx->r2) >= 0) {
        // sh          $a0, 0x38($s2)
        MEM_H(0X38, ctx->r18) = ctx->r4;
        goto L_80037754;
    }
    // sh          $a0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r4;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80037754:
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) << 9;
    // bgez        $v0, L_80037778
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80037778;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80037778:
    // j           L_80037BAC
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    goto L_80037BAC;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
L_80037780:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x83
    ctx->r2 = ADD32(0, 0X83);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0x8($s3)
    ctx->r3 = MEM_BU(0X8, ctx->r19);
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $a0, 0x4($s3)
    ctx->r4 = MEM_HU(0X4, ctx->r19);
    // nop

    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) << 9;
    // sh          $a0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r4;
    // sh          $a0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r4;
    // bgez        $v0, L_800377E4
    if (SIGNED(ctx->r2) >= 0) {
        // sh          $a0, 0x38($s2)
        MEM_H(0X38, ctx->r18) = ctx->r4;
        goto L_800377E4;
    }
    // sh          $a0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r4;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_800377E4:
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) << 9;
    // bgez        $v0, L_80037808
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80037808;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80037808:
    // j           L_80037BAC
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    goto L_80037BAC;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
L_80037810:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x84
    ctx->r2 = ADD32(0, 0X84);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0x8($s3)
    ctx->r3 = MEM_BU(0X8, ctx->r19);
    // addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $a0, 0x4($s3)
    ctx->r4 = MEM_HU(0X4, ctx->r19);
    // nop

    // sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) << 9;
    // sh          $a0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r4;
    // sh          $a0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r4;
    // bgez        $v0, L_80037874
    if (SIGNED(ctx->r2) >= 0) {
        // sh          $a0, 0x38($s2)
        MEM_H(0X38, ctx->r18) = ctx->r4;
        goto L_80037874;
    }
    // sh          $a0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r4;
    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80037874:
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 9
    ctx->r2 = S32(ctx->r2) << 9;
    // bgez        $v0, L_80037898
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80037898;
    }
    // nop

    // addiu       $v0, $v0, 0xFFF
    ctx->r2 = ADD32(ctx->r2, 0XFFF);
L_80037898:
    // j           L_80037BAC
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    goto L_80037BAC;
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
L_800378A0:
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_HS(0X38, ctx->r18);
    // sh          $zero, 0x30($s2)
    MEM_H(0X30, ctx->r18) = 0;
    // sh          $zero, 0x32($s2)
    MEM_H(0X32, ctx->r18) = 0;
    // j           L_80037B84
    // sh          $zero, 0x34($s2)
    MEM_H(0X34, ctx->r18) = 0;
    goto L_80037B84;
    // sh          $zero, 0x34($s2)
    MEM_H(0X34, ctx->r18) = 0;
L_80037924:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x84
    ctx->r2 = ADD32(0, 0X84);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // j           L_80037B38
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    goto L_80037B38;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
L_80037950:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x84
    ctx->r2 = ADD32(0, 0X84);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // lhu         $v0, 0x38($s2)
    ctx->r2 = MEM_HU(0X38, ctx->r18);
    // lhu         $a0, 0x38($s2)
    ctx->r4 = MEM_HU(0X38, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) >> 16;
    // srl         $a0, $a0, 31
    ctx->r4 = S32(U32(ctx->r4) >> 31);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // j           L_80037BAC
    // sh          $v1, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r3;
    goto L_80037BAC;
    // sh          $v1, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r3;
L_800379F8:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x81
    ctx->r2 = ADD32(0, 0X81);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // j           L_80037A9C
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    goto L_80037A9C;
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
L_80037A30:
    // lbu         $v1, 0x1($s2)
    ctx->r3 = MEM_BU(0X1, ctx->r18);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0xA8
    ctx->r2 = ADD32(0, 0XA8);
    // bne         $v1, $v0, L_80037A5C
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x84
        ctx->r2 = ADD32(0, 0X84);
        goto L_80037A5C;
    }
    // addiu       $v0, $zero, 0x84
    ctx->r2 = ADD32(0, 0X84);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
L_80037A5C:
    // lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(0X1, ctx->r18);
    // addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // bne         $v0, $a0, L_80037A70
    if (ctx->r2 != ctx->r4) {
        // addiu       $v0, $zero, 0x84
        ctx->r2 = ADD32(0, 0X84);
        goto L_80037A70;
    }
    // addiu       $v0, $zero, 0x84
    ctx->r2 = ADD32(0, 0X84);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
L_80037A70:
    // lbu         $v0, 0xC($s3)
    ctx->r2 = MEM_BU(0XC, ctx->r19);
    // lbu         $v1, 0x1($s2)
    ctx->r3 = MEM_BU(0X1, ctx->r18);
    // addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // bne         $v1, $a0, L_80037A8C
    if (ctx->r3 != ctx->r4) {
        // sh          $v0, 0xA($s2)
        MEM_H(0XA, ctx->r18) = ctx->r2;
        goto L_80037A8C;
    }
    // sh          $v0, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r2;
    // j           L_80037A90
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    goto L_80037A90;
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_80037A8C:
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_80037A90:
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
L_80037A9C:
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // lhu         $v0, 0x38($s2)
    ctx->r2 = MEM_HU(0X38, ctx->r18);
    // lhu         $a0, 0x3A($s2)
    ctx->r4 = MEM_HU(0X3A, ctx->r18);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) >> 16;
    // srl         $a0, $a0, 31
    ctx->r4 = S32(U32(ctx->r4) >> 31);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sh          $v1, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r3;
    // j           L_80037DE0
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    goto L_80037DE0;
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
L_80037B14:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_80037B20:
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sb          $zero, 0x7($s2)
    MEM_B(0X7, ctx->r18) = 0;
L_80037B38:
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_HS(0X38, ctx->r18);
L_80037B84:
    // nop

    // bgez        $v0, L_80037B94
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80037B94;
    }
    // nop

    // addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
L_80037B94:
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // bgez        $v1, L_80037BA8
    if (SIGNED(ctx->r3) >= 0) {
        // sh          $v0, 0xC($s2)
        MEM_H(0XC, ctx->r18) = ctx->r2;
        goto L_80037BA8;
    }
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
L_80037BA8:
    // sra         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) >> 3;
L_80037BAC:
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // j           L_80037DE0
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    goto L_80037DE0;
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
L_80037BBC:
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0xC($s3)
    ctx->r3 = MEM_BU(0XC, ctx->r19);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x33($s2)
    do_swl(rdram, 0X33, ctx->r18, ctx->r3);
    // swr         $v1, 0x30($s2)
    do_swr(rdram, 0X30, ctx->r18, ctx->r3);
    // swl         $a0, 0x37($s2)
    do_swl(rdram, 0X37, ctx->r18, ctx->r4);
    // swr         $a0, 0x34($s2)
    do_swr(rdram, 0X34, ctx->r18, ctx->r4);
    // lhu         $v0, 0x38($s2)
    ctx->r2 = MEM_HU(0X38, ctx->r18);
    // lui         $v1, 0x8000
    ctx->r3 = S32(0X8000 << 16);
    // sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // lh          $v0, 0x38($s2)
    ctx->r2 = MEM_HS(0X38, ctx->r18);
    // lh          $a0, 0x34($s2)
    ctx->r4 = MEM_HS(0X34, ctx->r18);
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // jal         0x800744C4
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    rcos(rdram, ctx);
    goto after_22;
    // sw          $v0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r2;
    after_22:
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_80037C68
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80037C68;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80037C68:
    // lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(0X20, ctx->r18);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // lh          $a0, 0x34($s2)
    ctx->r4 = MEM_HS(0X34, ctx->r18);
    // jal         0x800743F4
    // nop

    rsin(rdram, ctx);
    goto after_23;
    // nop

    after_23:
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_80037CA0
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80037CA0;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80037CA0:
    // lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(0X24, ctx->r18);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // lh          $a0, 0x34($s2)
    ctx->r4 = MEM_HS(0X34, ctx->r18);
    // jal         0x800744C4
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    rcos(rdram, ctx);
    goto after_24;
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    after_24:
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_80037CD8
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_80037CD8;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80037CD8:
    // lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(0X20, ctx->r18);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lh          $a0, 0x34($s2)
    ctx->r4 = MEM_HS(0X34, ctx->r18);
    // jal         0x800743F4
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    rsin(rdram, ctx);
    goto after_25;
    // addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    after_25:
    // lh          $v1, 0x38($s2)
    ctx->r3 = MEM_HS(0X38, ctx->r18);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_80037D10
    if (SIGNED(ctx->r3) >= 0) {
        // addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
        goto L_80037D10;
    }
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_80037D10:
    // addiu       $a2, $zero, 0xE9
    ctx->r6 = ADD32(0, 0XE9);
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(0X24, ctx->r18);
    // addiu       $s1, $s2, 0x40
    ctx->r17 = ADD32(ctx->r18, 0X40);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addiu       $s0, $zero, 0x400
    ctx->r16 = ADD32(0, 0X400);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // lh          $v0, 0xA($s2)
    ctx->r2 = MEM_HS(0XA, ctx->r18);
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_26;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_26:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(0X0, ctx->r18);
    // addiu       $a2, $zero, 0xEA
    ctx->r6 = ADD32(0, 0XEA);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // lh          $v0, 0xA($s2)
    ctx->r2 = MEM_HS(0XA, ctx->r18);
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
L_80037D6C:
    // sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // jal         0x80036484
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_27;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_27:
    // j           L_80037DE4
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    goto L_80037DE4;
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_80037D84:
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // sh          $v0, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x83
    ctx->r2 = ADD32(0, 0X83);
    // sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // lbu         $v1, 0x8($s3)
    ctx->r3 = MEM_BU(0X8, ctx->r19);
    // addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_80037DA4:
    // sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r2;
    // addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // lhu         $v0, 0x4($s3)
    ctx->r2 = MEM_HU(0X4, ctx->r19);
    // nop

    // sh          $v0, 0x3C($s2)
    MEM_H(0X3C, ctx->r18) = ctx->r2;
    // sh          $v0, 0x3A($s2)
    MEM_H(0X3A, ctx->r18) = ctx->r2;
    // sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // lw          $v0, 0xC($s3)
    ctx->r2 = MEM_W(0XC, ctx->r19);
    // j           L_80037DE0
    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
    goto L_80037DE0;
    // sw          $v0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r2;
L_80037DD8:
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_80037DE0:
    // addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_80037DE4:
    // lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(0X5C, ctx->r29);
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
    // addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // jr          $ra
    // nop

    return;
    // nop

;}
