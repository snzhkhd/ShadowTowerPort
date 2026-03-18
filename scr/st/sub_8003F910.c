#include "recomp.h"
#include "disable_warnings.h"

void sub_8003F910(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // sll         $fp, $s7, 5
    ctx->r30 = S32(ctx->r23) << 5;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // addu        $v0, $s7, $v0
    ctx->r2 = ADD32(ctx->r23, ctx->r2);
    // sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // lbu         $v0, 0x157($v0)
    ctx->r2 = MEM_BU(0X157, ctx->r2);
    // nop

    // addiu       $s4, $v0, -0x1
    ctx->r20 = ADD32(ctx->r2, -0X1);
    // sltiu       $v0, $a0, 0x30
    ctx->r2 = ctx->r4 < 0X30 ? 1 : 0;
    // beq         $v0, $zero, L_8003FFF0
    if (ctx->r2 == 0) {
        // lui         $s6, 0x1F80
        ctx->r22 = S32(0X1F80 << 16);
        goto L_8003FFF0;
    }
    // lui         $s6, 0x1F80
    ctx->r22 = S32(0X1F80 << 16);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x1D3C
    ctx->r2 = ADD32(ctx->r2, 0X1D3C);
    // sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_8003F990;
    jr_addend_8003F990 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_8003F990 >> 2) {
        case 0: goto L_8003F998; break;
        case 1: goto L_8003FAB0; break;
        case 2: goto L_8003FFF0; break;
        case 3: goto L_8003FAB8; break;
        case 4: goto L_8003FB04; break;
        case 5: goto L_8003FFF0; break;
        case 6: goto L_8003FAF4; break;
        case 7: goto L_8003FA08; break;
        case 8: goto L_8003FFF0; break;
        case 9: goto L_8003FACC; break;
        case 10: goto L_8003F9A0; break;
        case 11: goto L_8003FFF0; break;
        case 12: goto L_8003FB0C; break;
        case 13: goto L_8003FB1C; break;
        case 14: goto L_8003FFF0; break;
        case 15: goto L_8003FB2C; break;
        case 16: goto L_8003FB34; break;
        case 17: goto L_8003FFF0; break;
        case 18: goto L_8003FFF0; break;
        case 19: goto L_8003FFF0; break;
        case 20: goto L_8003FFF0; break;
        case 21: goto L_8003FFF0; break;
        case 22: goto L_8003FFF0; break;
        case 23: goto L_8003FFF0; break;
        case 24: goto L_8003FFF0; break;
        case 25: goto L_8003FFF0; break;
        case 26: goto L_8003FFF0; break;
        case 27: goto L_8003FFF0; break;
        case 28: goto L_8003FFF0; break;
        case 29: goto L_8003FFF0; break;
        case 30: goto L_8003FFF0; break;
        case 31: goto L_8003FFF0; break;
        case 32: goto L_8003FFF0; break;
        case 33: goto L_8003FFF0; break;
        case 34: goto L_8003FFF0; break;
        case 35: goto L_8003FFF0; break;
        case 36: goto L_8003FFF0; break;
        case 37: goto L_8003FFF0; break;
        case 38: goto L_8003FFF0; break;
        case 39: goto L_8003FFF0; break;
        case 40: goto L_8003FFF0; break;
        case 41: goto L_8003FFF0; break;
        case 42: goto L_8003FFF0; break;
        case 43: goto L_8003FFF0; break;
        case 44: goto L_8003FBCC; break;
        case 45: goto L_8003FBCC; break;
        case 46: goto L_8003FBCC; break;
        case 47: goto L_8003FBCC; break;
        default: switch_error(__func__, 0x8003F990, 0x80011D3C);
    }
    // nop

L_8003F998:
    // j           L_8003F9A4
    // addiu       $s3, $zero, 0x1000
    ctx->r19 = ADD32(0, 0X1000);
    goto L_8003F9A4;
    // addiu       $s3, $zero, 0x1000
    ctx->r19 = ADD32(0, 0X1000);
L_8003F9A0:
    // addiu       $s3, $zero, 0x800
    ctx->r19 = ADD32(0, 0X800);
L_8003F9A4:
    // addiu       $a0, $zero, 0x2BC
    ctx->r4 = ADD32(0, 0X2BC);
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x70D8
    ctx->r16 = ADD32(ctx->r16, -0X70D8);
    // lhu         $v0, 0x270($s0)
    ctx->r2 = MEM_HU(0X270, ctx->r16);
    // lhu         $v1, 0x272($s0)
    ctx->r3 = MEM_HU(0X272, ctx->r16);
    // lhu         $t0, 0x274($s0)
    ctx->r8 = MEM_HU(0X274, ctx->r16);
    // addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    // sh          $v1, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r3;
    // sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // jal         0x8003F704
    // sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    sub_8003F704(rdram, ctx);
    goto after_0;
    // sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    after_0:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // ori         $a1, $fp, 0x42
    ctx->r5 = ctx->r30 | 0X42;
    // andi        $a1, $a1, 0xE2
    ctx->r5 = ctx->r5 & 0XE2;
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // lbu         $a2, 0x80($sp)
    ctx->r6 = MEM_BU(0X80, ctx->r29);
    // addiu       $s0, $s0, 0x268
    ctx->r16 = ADD32(ctx->r16, 0X268);
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // j           L_8003FFE8
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    goto L_8003FFE8;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
L_8003FA08:
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // addiu       $s4, $sp, 0x48
    ctx->r20 = ADD32(ctx->r29, 0X48);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s1, $v0, -0x70D8
    ctx->r17 = ADD32(ctx->r2, -0X70D8);
    // sll         $v0, $s7, 3
    ctx->r2 = S32(ctx->r23) << 3;
    // addu        $s3, $v0, $s1
    ctx->r19 = ADD32(ctx->r2, ctx->r17);
    // addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
L_8003FA24:
    // addiu       $a0, $zero, 0x2BC
    ctx->r4 = ADD32(0, 0X2BC);
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // lhu         $v0, 0x270($s1)
    ctx->r2 = MEM_HU(0X270, ctx->r17);
    // addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // addiu       $v0, $v0, -0x200
    ctx->r2 = ADD32(ctx->r2, -0X200);
    // sh          $v0, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x272($s1)
    ctx->r2 = MEM_HU(0X272, ctx->r17);
    // lhu         $v1, 0x274($s1)
    ctx->r3 = MEM_HU(0X274, ctx->r17);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // sh          $v0, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r2;
    // sh          $v1, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r3;
    // jal         0x8003F704
    // sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    sub_8003F704(rdram, ctx);
    goto after_1;
    // sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    after_1:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // ori         $a1, $fp, 0x42
    ctx->r5 = ctx->r30 | 0X42;
    // andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // lbu         $a2, 0x80($sp)
    ctx->r6 = MEM_BU(0X80, ctx->r29);
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $s1, 0x268
    ctx->r2 = ADD32(ctx->r17, 0X268);
    // sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // jal         0x80036484
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sub_80036484(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // lhu         $v0, 0x160($s3)
    ctx->r2 = MEM_HU(0X160, ctx->r19);
    // nop

    // addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, 0X400);
    // sh          $v0, 0x160($s3)
    MEM_H(0X160, ctx->r19) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s2, $v0, L_8003FA24
    if (ctx->r18 != ctx->r2) {
        // addiu       $s0, $s0, -0x20
        ctx->r16 = ADD32(ctx->r16, -0X20);
        goto L_8003FA24;
    }
    // addiu       $s0, $s0, -0x20
    ctx->r16 = ADD32(ctx->r16, -0X20);
    // j           L_8003FFF0
    // nop

    goto L_8003FFF0;
    // nop

L_8003FAB0:
    // j           L_8003FB38
    // addiu       $s0, $zero, 0x100
    ctx->r16 = ADD32(0, 0X100);
    goto L_8003FB38;
    // addiu       $s0, $zero, 0x100
    ctx->r16 = ADD32(0, 0X100);
L_8003FAB8:
    // addiu       $s0, $zero, 0x180
    ctx->r16 = ADD32(0, 0X180);
    // sll         $v0, $s4, 5
    ctx->r2 = S32(ctx->r20) << 5;
    // addiu       $t0, $v0, -0x50
    ctx->r8 = ADD32(ctx->r2, -0X50);
    // j           L_8003FB40
    // addiu       $s3, $zero, 0x200
    ctx->r19 = ADD32(0, 0X200);
    goto L_8003FB40;
    // addiu       $s3, $zero, 0x200
    ctx->r19 = ADD32(0, 0X200);
L_8003FACC:
    // jal         0x80078AC4
    // addiu       $s0, $zero, 0x100
    ctx->r16 = ADD32(0, 0X100);
    rand_recomp(rdram, ctx);
    goto after_3;
    // addiu       $s0, $zero, 0x100
    ctx->r16 = ADD32(0, 0X100);
    after_3:
    // bgez        $v0, L_8003FAE4
    if (SIGNED(ctx->r2) >= 0) {
        // sra         $v1, $v0, 7
        ctx->r3 = S32(ctx->r2) >> 7;
        goto L_8003FAE4;
    }
    // sra         $v1, $v0, 7
    ctx->r3 = S32(ctx->r2) >> 7;
    // addiu       $v0, $v0, 0x7F
    ctx->r2 = ADD32(ctx->r2, 0X7F);
    // sra         $v1, $v0, 7
    ctx->r3 = S32(ctx->r2) >> 7;
L_8003FAE4:
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // subu        $t0, $v0, $v1
    ctx->r8 = SUB32(ctx->r2, ctx->r3);
    // j           L_8003FB40
    // addiu       $s3, $zero, 0x300
    ctx->r19 = ADD32(0, 0X300);
    goto L_8003FB40;
    // addiu       $s3, $zero, 0x300
    ctx->r19 = ADD32(0, 0X300);
L_8003FAF4:
    // addiu       $s0, $zero, 0x200
    ctx->r16 = ADD32(0, 0X200);
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // j           L_8003FB40
    // addiu       $s3, $zero, 0xC00
    ctx->r19 = ADD32(0, 0XC00);
    goto L_8003FB40;
    // addiu       $s3, $zero, 0xC00
    ctx->r19 = ADD32(0, 0XC00);
L_8003FB04:
    // j           L_8003FB20
    // addiu       $s0, $zero, 0x180
    ctx->r16 = ADD32(0, 0X180);
    goto L_8003FB20;
    // addiu       $s0, $zero, 0x180
    ctx->r16 = ADD32(0, 0X180);
L_8003FB0C:
    // addiu       $s0, $zero, 0x180
    ctx->r16 = ADD32(0, 0X180);
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // j           L_8003FB40
    // addiu       $s3, $zero, 0x800
    ctx->r19 = ADD32(0, 0X800);
    goto L_8003FB40;
    // addiu       $s3, $zero, 0x800
    ctx->r19 = ADD32(0, 0X800);
L_8003FB1C:
    // addiu       $s0, $zero, 0x140
    ctx->r16 = ADD32(0, 0X140);
L_8003FB20:
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // j           L_8003FB40
    // addiu       $s3, $zero, 0x2000
    ctx->r19 = ADD32(0, 0X2000);
    goto L_8003FB40;
    // addiu       $s3, $zero, 0x2000
    ctx->r19 = ADD32(0, 0X2000);
L_8003FB2C:
    // j           L_8003FB38
    // addiu       $s0, $zero, 0x300
    ctx->r16 = ADD32(0, 0X300);
    goto L_8003FB38;
    // addiu       $s0, $zero, 0x300
    ctx->r16 = ADD32(0, 0X300);
L_8003FB34:
    // addiu       $s0, $zero, 0x140
    ctx->r16 = ADD32(0, 0X140);
L_8003FB38:
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // addiu       $s3, $zero, 0x400
    ctx->r19 = ADD32(0, 0X400);
L_8003FB40:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // addiu       $s2, $sp, 0x48
    ctx->r18 = ADD32(ctx->r29, 0X48);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x70D8
    ctx->r16 = ADD32(ctx->r16, -0X70D8);
    // addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // lhu         $v0, 0x270($s0)
    ctx->r2 = MEM_HU(0X270, ctx->r16);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x272($s0)
    ctx->r2 = MEM_HU(0X272, ctx->r16);
    // lhu         $v1, 0x274($s0)
    ctx->r3 = MEM_HU(0X274, ctx->r16);
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    // sh          $v1, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r3;
    // jal         0x8003F704
    // sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    sub_8003F704(rdram, ctx);
    goto after_4;
    // sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    after_4:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // ori         $a1, $fp, 0x42
    ctx->r5 = ctx->r30 | 0X42;
    // lhu         $v0, 0x270($s0)
    ctx->r2 = MEM_HU(0X270, ctx->r16);
    // andi        $a1, $a1, 0xE2
    ctx->r5 = ctx->r5 & 0XE2;
    // sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x272($s0)
    ctx->r2 = MEM_HU(0X272, ctx->r16);
    // lhu         $v1, 0x274($s0)
    ctx->r3 = MEM_HU(0X274, ctx->r16);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    // sh          $v1, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r3;
    // lbu         $a2, 0x80($sp)
    ctx->r6 = MEM_BU(0X80, ctx->r29);
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // j           L_8003FFE8
    // sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    goto L_8003FFE8;
    // sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
L_8003FBCC:
    // addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s4, $v0, -0x70D8
    ctx->r20 = ADD32(ctx->r2, -0X70D8);
    // lw          $v0, 0xE8($s4)
    ctx->r2 = MEM_W(0XE8, ctx->r20);
    // lbu         $a1, 0x150($s4)
    ctx->r5 = MEM_BU(0X150, ctx->r20);
    // lhu         $a2, 0x6($v0)
    ctx->r6 = MEM_HU(0X6, ctx->r2);
    // lh          $a3, 0x12($v0)
    ctx->r7 = MEM_HS(0X12, ctx->r2);
    // addiu       $s5, $sp, 0x48
    ctx->r21 = ADD32(ctx->r29, 0X48);
    // jal         0x80033E30
    // sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    sub_80033E30(rdram, ctx);
    goto after_5;
    // sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_5:
    // sll         $s0, $s7, 2
    ctx->r16 = S32(ctx->r23) << 2;
    // addu        $s0, $s0, $s4
    ctx->r16 = ADD32(ctx->r16, ctx->r20);
    // lw          $v0, 0xE8($s0)
    ctx->r2 = MEM_W(0XE8, ctx->r16);
    // nop

    // lh          $v0, 0xC($v0)
    ctx->r2 = MEM_HS(0XC, ctx->r2);
    // nop

    // sw          $v0, 0xBC($s6)
    MEM_W(0XBC, ctx->r22) = ctx->r2;
    // lw          $v0, 0xE8($s0)
    ctx->r2 = MEM_W(0XE8, ctx->r16);
    // nop

    // lh          $v0, 0xE($v0)
    ctx->r2 = MEM_HS(0XE, ctx->r2);
    // nop

    // sw          $v0, 0xC0($s6)
    MEM_W(0XC0, ctx->r22) = ctx->r2;
    // lw          $v0, 0xE8($s0)
    ctx->r2 = MEM_W(0XE8, ctx->r16);
    // nop

    // lh          $v0, 0x10($v0)
    ctx->r2 = MEM_HS(0X10, ctx->r2);
    // addiu       $s1, $s6, 0xA8
    ctx->r17 = ADD32(ctx->r22, 0XA8);
    // sw          $v0, 0xC4($s6)
    MEM_W(0XC4, ctx->r22) = ctx->r2;
    // lw          $a0, 0xE8($s0)
    ctx->r4 = MEM_W(0XE8, ctx->r16);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x80074EC4
    // addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    RotMatrix(rdram, ctx);
    goto after_6;
    // addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_6:
    // lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(0X0, ctx->r17);
    // lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(0X4, ctx->r17);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($s1)
    ctx->r12 = MEM_W(0X8, ctx->r17);
    // lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(0XC, ctx->r17);
    // lw          $t6, 0x10($s1)
    ctx->r14 = MEM_W(0X10, ctx->r17);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lw          $t4, 0x14($s1)
    ctx->r12 = MEM_W(0X14, ctx->r17);
    // lw          $t5, 0x18($s1)
    ctx->r13 = MEM_W(0X18, ctx->r17);
    // ctc2        $t4, $5
    gte_ctc2(ctx, 12, 5);
    // lw          $t6, 0x1C($s1)
    ctx->r14 = MEM_W(0X1C, ctx->r17);
    // ctc2        $t5, $6
    gte_ctc2(ctx, 13, 6);
    // ctc2        $t6, $7
    gte_ctc2(ctx, 14, 7);
    // lwc2        $0, 0x0($s5)
    gte_lwc2(rdram, ctx, 0, 21, 0);
    // lwc2        $1, 0x4($s5)
    gte_lwc2(rdram, ctx, 1, 21, 4);
    // nop

    // nop

    // .word       0x4A480012                   # INVALID     $s2, $t0, 0x12 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A480012);
    // addiu       $s2, $sp, 0x20
    ctx->r18 = ADD32(ctx->r29, 0X20);
    // swc2        $25, 0x0($s2)
    gte_swc2(rdram, ctx, 25, 18, 0);
    // swc2        $26, 0x4($s2)
    gte_swc2(rdram, ctx, 26, 18, 4);
    // swc2        $27, 0x8($s2)
    gte_swc2(rdram, ctx, 27, 18, 8);
    // addiu       $s3, $sp, 0x40
    ctx->r19 = ADD32(ctx->r29, 0X40);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // lhu         $v0, 0x20($sp)
    ctx->r2 = MEM_HU(0X20, ctx->r29);
    // lhu         $v1, 0x24($sp)
    ctx->r3 = MEM_HU(0X24, ctx->r29);
    // lhu         $a2, 0x28($sp)
    ctx->r6 = MEM_HU(0X28, ctx->r29);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // sh          $v0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r2;
    // sh          $v1, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r3;
    // sh          $a2, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r6;
    // lw          $v0, 0x248($s4)
    ctx->r2 = MEM_W(0X248, ctx->r20);
    // lw          $v1, 0x24C($s4)
    ctx->r3 = MEM_W(0X24C, ctx->r20);
    // lw          $a2, 0x250($s4)
    ctx->r6 = MEM_W(0X250, ctx->r20);
    // lwl         $a3, 0x273($s4)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0X273, ctx->r20);
    // lwr         $a3, 0x270($s4)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X270, ctx->r20);
    // lwl         $t0, 0x277($s4)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X277, ctx->r20);
    // lwr         $t0, 0x274($s4)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X274, ctx->r20);
    // swl         $a3, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r7);
    // swr         $a3, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r7);
    // swl         $t0, 0x47($sp)
    do_swl(rdram, 0X47, ctx->r29, ctx->r8);
    // swr         $t0, 0x44($sp)
    do_swr(rdram, 0X44, ctx->r29, ctx->r8);
    // sw          $v0, 0xBC($s6)
    MEM_W(0XBC, ctx->r22) = ctx->r2;
    // sw          $v1, 0xC0($s6)
    MEM_W(0XC0, ctx->r22) = ctx->r3;
    // jal         0x80075154
    // sw          $a2, 0xC4($s6)
    MEM_W(0XC4, ctx->r22) = ctx->r6;
    RotMatrixZYX(rdram, ctx);
    goto after_7;
    // sw          $a2, 0xC4($s6)
    MEM_W(0XC4, ctx->r22) = ctx->r6;
    after_7:
    // lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(0X0, ctx->r17);
    // lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(0X4, ctx->r17);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($s1)
    ctx->r12 = MEM_W(0X8, ctx->r17);
    // lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(0XC, ctx->r17);
    // lw          $t6, 0x10($s1)
    ctx->r14 = MEM_W(0X10, ctx->r17);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lw          $t4, 0x14($s1)
    ctx->r12 = MEM_W(0X14, ctx->r17);
    // lw          $t5, 0x18($s1)
    ctx->r13 = MEM_W(0X18, ctx->r17);
    // ctc2        $t4, $5
    gte_ctc2(ctx, 12, 5);
    // lw          $t6, 0x1C($s1)
    ctx->r14 = MEM_W(0X1C, ctx->r17);
    // ctc2        $t5, $6
    gte_ctc2(ctx, 13, 6);
    // ctc2        $t6, $7
    gte_ctc2(ctx, 14, 7);
    // lwc2        $0, 0x0($s5)
    gte_lwc2(rdram, ctx, 0, 21, 0);
    // lwc2        $1, 0x4($s5)
    gte_lwc2(rdram, ctx, 1, 21, 4);
    // nop

    // nop

    // .word       0x4A480012                   # INVALID     $s2, $t0, 0x12 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A480012);
    // swc2        $25, 0x0($s2)
    gte_swc2(rdram, ctx, 25, 18, 0);
    // swc2        $26, 0x4($s2)
    gte_swc2(rdram, ctx, 26, 18, 4);
    // swc2        $27, 0x8($s2)
    gte_swc2(rdram, ctx, 27, 18, 8);
    // lw          $v0, 0xE8($s4)
    ctx->r2 = MEM_W(0XE8, ctx->r20);
    // lbu         $a1, 0x150($s4)
    ctx->r5 = MEM_BU(0X150, ctx->r20);
    // lhu         $a2, 0x6($v0)
    ctx->r6 = MEM_HU(0X6, ctx->r2);
    // lh          $a3, 0x1A($v0)
    ctx->r7 = MEM_HS(0X1A, ctx->r2);
    // addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // jal         0x80033E30
    // sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    sub_80033E30(rdram, ctx);
    goto after_8;
    // sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_8:
    // lw          $v0, 0xE8($s0)
    ctx->r2 = MEM_W(0XE8, ctx->r16);
    // nop

    // lh          $v0, 0xC($v0)
    ctx->r2 = MEM_HS(0XC, ctx->r2);
    // nop

    // sw          $v0, 0xBC($s6)
    MEM_W(0XBC, ctx->r22) = ctx->r2;
    // lw          $v0, 0xE8($s0)
    ctx->r2 = MEM_W(0XE8, ctx->r16);
    // nop

    // lh          $v0, 0xE($v0)
    ctx->r2 = MEM_HS(0XE, ctx->r2);
    // nop

    // sw          $v0, 0xC0($s6)
    MEM_W(0XC0, ctx->r22) = ctx->r2;
    // lw          $v0, 0xE8($s0)
    ctx->r2 = MEM_W(0XE8, ctx->r16);
    // nop

    // lh          $v0, 0x10($v0)
    ctx->r2 = MEM_HS(0X10, ctx->r2);
    // nop

    // sw          $v0, 0xC4($s6)
    MEM_W(0XC4, ctx->r22) = ctx->r2;
    // lw          $a0, 0xE8($s0)
    ctx->r4 = MEM_W(0XE8, ctx->r16);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // jal         0x80074EC4
    // addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    RotMatrix(rdram, ctx);
    goto after_9;
    // addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_9:
    // lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(0X0, ctx->r17);
    // lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(0X4, ctx->r17);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($s1)
    ctx->r12 = MEM_W(0X8, ctx->r17);
    // lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(0XC, ctx->r17);
    // lw          $t6, 0x10($s1)
    ctx->r14 = MEM_W(0X10, ctx->r17);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lw          $t4, 0x14($s1)
    ctx->r12 = MEM_W(0X14, ctx->r17);
    // lw          $t5, 0x18($s1)
    ctx->r13 = MEM_W(0X18, ctx->r17);
    // ctc2        $t4, $5
    gte_ctc2(ctx, 12, 5);
    // lw          $t6, 0x1C($s1)
    ctx->r14 = MEM_W(0X1C, ctx->r17);
    // ctc2        $t5, $6
    gte_ctc2(ctx, 13, 6);
    // ctc2        $t6, $7
    gte_ctc2(ctx, 14, 7);
    // lwc2        $0, 0x0($s5)
    gte_lwc2(rdram, ctx, 0, 21, 0);
    // lwc2        $1, 0x4($s5)
    gte_lwc2(rdram, ctx, 1, 21, 4);
    // nop

    // nop

    // .word       0x4A480012                   # INVALID     $s2, $t0, 0x12 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A480012);
    // addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // swc2        $25, 0x0($s0)
    gte_swc2(rdram, ctx, 25, 16, 0);
    // swc2        $26, 0x4($s0)
    gte_swc2(rdram, ctx, 26, 16, 4);
    // swc2        $27, 0x8($s0)
    gte_swc2(rdram, ctx, 27, 16, 8);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // lhu         $v0, 0x30($sp)
    ctx->r2 = MEM_HU(0X30, ctx->r29);
    // lhu         $v1, 0x34($sp)
    ctx->r3 = MEM_HU(0X34, ctx->r29);
    // lhu         $a2, 0x38($sp)
    ctx->r6 = MEM_HU(0X38, ctx->r29);
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // sh          $v0, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r2;
    // sh          $v1, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r3;
    // sh          $a2, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r6;
    // lw          $v0, 0x248($s4)
    ctx->r2 = MEM_W(0X248, ctx->r20);
    // lw          $v1, 0x24C($s4)
    ctx->r3 = MEM_W(0X24C, ctx->r20);
    // lw          $a2, 0x250($s4)
    ctx->r6 = MEM_W(0X250, ctx->r20);
    // lwl         $a3, 0x273($s4)
    ctx->r7 = do_lwl(rdram, ctx->r7, 0X273, ctx->r20);
    // lwr         $a3, 0x270($s4)
    ctx->r7 = do_lwr(rdram, ctx->r7, 0X270, ctx->r20);
    // lwl         $t0, 0x277($s4)
    ctx->r8 = do_lwl(rdram, ctx->r8, 0X277, ctx->r20);
    // lwr         $t0, 0x274($s4)
    ctx->r8 = do_lwr(rdram, ctx->r8, 0X274, ctx->r20);
    // swl         $a3, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r7);
    // swr         $a3, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r7);
    // swl         $t0, 0x47($sp)
    do_swl(rdram, 0X47, ctx->r29, ctx->r8);
    // swr         $t0, 0x44($sp)
    do_swr(rdram, 0X44, ctx->r29, ctx->r8);
    // sw          $v0, 0xBC($s6)
    MEM_W(0XBC, ctx->r22) = ctx->r2;
    // sw          $v1, 0xC0($s6)
    MEM_W(0XC0, ctx->r22) = ctx->r3;
    // jal         0x80075154
    // sw          $a2, 0xC4($s6)
    MEM_W(0XC4, ctx->r22) = ctx->r6;
    RotMatrixZYX(rdram, ctx);
    goto after_10;
    // sw          $a2, 0xC4($s6)
    MEM_W(0XC4, ctx->r22) = ctx->r6;
    after_10:
    // lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(0X0, ctx->r17);
    // lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(0X4, ctx->r17);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($s1)
    ctx->r12 = MEM_W(0X8, ctx->r17);
    // lw          $t5, 0xC($s1)
    ctx->r13 = MEM_W(0XC, ctx->r17);
    // lw          $t6, 0x10($s1)
    ctx->r14 = MEM_W(0X10, ctx->r17);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lw          $t4, 0x14($s1)
    ctx->r12 = MEM_W(0X14, ctx->r17);
    // lw          $t5, 0x18($s1)
    ctx->r13 = MEM_W(0X18, ctx->r17);
    // ctc2        $t4, $5
    gte_ctc2(ctx, 12, 5);
    // lw          $t6, 0x1C($s1)
    ctx->r14 = MEM_W(0X1C, ctx->r17);
    // ctc2        $t5, $6
    gte_ctc2(ctx, 13, 6);
    // ctc2        $t6, $7
    gte_ctc2(ctx, 14, 7);
    // lwc2        $0, 0x0($s5)
    gte_lwc2(rdram, ctx, 0, 21, 0);
    // lwc2        $1, 0x4($s5)
    gte_lwc2(rdram, ctx, 1, 21, 4);
    // nop

    // nop

    // .word       0x4A480012                   # INVALID     $s2, $t0, 0x12 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A480012);
    // swc2        $25, 0x0($s0)
    gte_swc2(rdram, ctx, 25, 16, 0);
    // swc2        $26, 0x4($s0)
    gte_swc2(rdram, ctx, 26, 16, 4);
    // swc2        $27, 0x8($s0)
    gte_swc2(rdram, ctx, 27, 16, 8);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(0X20, ctx->r29);
    // lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(0X30, ctx->r29);
    // lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(0X24, ctx->r29);
    // lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(0X34, ctx->r29);
    // lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(0X38, ctx->r29);
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(0X28, ctx->r29);
    // subu        $a1, $v1, $a1
    ctx->r5 = SUB32(ctx->r3, ctx->r5);
    // jal         0x8004A40C
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    sub_8004A40C(rdram, ctx);
    goto after_11;
    // subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    after_11:
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x80049FE4
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    sub_80049FE4(rdram, ctx);
    goto after_12;
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_12:
    // lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(0X80, ctx->r29);
    // addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    // bne         $v1, $v0, L_8003FF68
    if (ctx->r3 != ctx->r2) {
        // addu        $a1, $s5, $zero
        ctx->r5 = ADD32(ctx->r21, 0);
        goto L_8003FF68;
    }
    // addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // lhu         $v0, 0x180($s4)
    ctx->r2 = MEM_HU(0X180, ctx->r20);
    // ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4) << 8;
    // mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // j           L_8003FF84
    // sra         $v0, $t1, 11
    ctx->r2 = S32(ctx->r9) >> 11;
    goto L_8003FF84;
    // sra         $v0, $t1, 11
    ctx->r2 = S32(ctx->r9) >> 11;
L_8003FF68:
    // lui         $v0, 0x6666
    ctx->r2 = S32(0X6666 << 16);
    // lhu         $a0, 0x180($s4)
    ctx->r4 = MEM_HU(0X180, ctx->r20);
    // ori         $v0, $v0, 0x6667
    ctx->r2 = ctx->r2 | 0X6667;
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // mfhi        $t1
    ctx->r9 = hi;
    // sra         $v0, $t1, 1
    ctx->r2 = S32(ctx->r9) >> 1;
L_8003FF84:
    // jal         0x8004A0F8
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    sub_8004A0F8(rdram, ctx);
    goto after_13;
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    after_13:
    // addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // ori         $a1, $fp, 0x42
    ctx->r5 = ctx->r30 | 0X42;
    // andi        $a1, $a1, 0xE2
    ctx->r5 = ctx->r5 & 0XE2;
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // addiu       $t0, $t0, -0x70D8
    ctx->r8 = ADD32(ctx->r8, -0X70D8);
    // addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // lh          $a2, 0x2CE($t0)
    ctx->r6 = MEM_HS(0X2CE, ctx->r8);
    // lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(0X34, ctx->r29);
    // lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(0X30, ctx->r29);
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // lh          $v1, 0x2D2($t0)
    ctx->r3 = MEM_HS(0X2D2, ctx->r8);
    // lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(0X38, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // lbu         $a2, 0x80($sp)
    ctx->r6 = MEM_BU(0X80, ctx->r29);
    // addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lhu         $v1, 0x180($t0)
    ctx->r3 = MEM_HU(0X180, ctx->r8);
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
L_8003FFE8:
    // jal         0x80036484
    // nop

    sub_80036484(rdram, ctx);
    goto after_14;
    // nop

    after_14:
L_8003FFF0:
    // lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(0X7C, ctx->r29);
    // lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(0X78, ctx->r29);
    // lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(0X74, ctx->r29);
    // lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(0X70, ctx->r29);
    // lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(0X6C, ctx->r29);
    // lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(0X68, ctx->r29);
    // lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(0X64, ctx->r29);
    // lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(0X60, ctx->r29);
    // lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(0X5C, ctx->r29);
    // lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(0X58, ctx->r29);
    // addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // jr          $ra
    // nop

    return;
    // nop

;}
