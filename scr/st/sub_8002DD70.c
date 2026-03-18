#include "recomp.h"
#include "disable_warnings.h"

void sub_8002DD70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // lui         $s4, 0x1F80
    ctx->r20 = S32(0X1F80 << 16);
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // lhu         $v0, 0xA($s4)
    ctx->r2 = MEM_HU(0XA, ctx->r20);
    // nop

    // bne         $v0, $zero, L_8002DDB4
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x69
        ctx->r2 = ADD32(0, 0X69);
        goto L_8002DDB4;
    }
    // addiu       $v0, $zero, 0x69
    ctx->r2 = ADD32(0, 0X69);
    // addiu       $v0, $zero, 0xA7
    ctx->r2 = ADD32(0, 0XA7);
L_8002DDB4:
    // sh          $v0, 0x33C($s4)
    MEM_H(0X33C, ctx->r20) = ctx->r2;
    // ori         $a0, $s4, 0x33C
    ctx->r4 = ctx->r20 | 0X33C;
    // ori         $a1, $s4, 0x32C
    ctx->r5 = ctx->r20 | 0X32C;
    // addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // addiu       $v0, $zero, 0xCE
    ctx->r2 = ADD32(0, 0XCE);
    // sh          $v0, 0x33E($s4)
    MEM_H(0X33E, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // sh          $v0, 0x340($s4)
    MEM_H(0X340, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // jal         0x80027D18
    // sh          $v0, 0x342($s4)
    MEM_H(0X342, ctx->r20) = ctx->r2;
    sub_80027D18(rdram, ctx);
    goto after_0;
    // sh          $v0, 0x342($s4)
    MEM_H(0X342, ctx->r20) = ctx->r2;
    after_0:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_1;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_1:
    // lhu         $v1, 0x2DC($s4)
    ctx->r3 = MEM_HU(0X2DC, ctx->r20);
    // nop

    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // beq         $v0, $zero, L_8002DE68
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x78
        ctx->r5 = ADD32(0, 0X78);
        goto L_8002DE68;
    }
    // addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0xD2($a0)
    ctx->r2 = MEM_HU(0XD2, ctx->r4);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // lhu         $v1, 0x2E0($s4)
    ctx->r3 = MEM_HU(0X2E0, ctx->r20);
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // lhu         $v0, 0x2E2($s4)
    ctx->r2 = MEM_HU(0X2E2, ctx->r20);
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x4($s4)
    ctx->r3 = MEM_W(0X4, ctx->r20);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v0, 0x0($v0)
    ctx->r2 = MEM_HS(0X0, ctx->r2);
    // addiu       $t0, $t0, 0x7590
    ctx->r8 = ADD32(ctx->r8, 0X7590);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // lhu         $fp, 0x13A($v0)
    ctx->r30 = MEM_HU(0X13A, ctx->r2);
    // j           L_8002DEDC
    // ori         $a3, $s4, 0x300
    ctx->r7 = ctx->r20 | 0X300;
    goto L_8002DEDC;
    // ori         $a3, $s4, 0x300
    ctx->r7 = ctx->r20 | 0X300;
L_8002DE68:
    // andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // beq         $v0, $zero, L_8002DE90
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x6E
        ctx->r5 = ADD32(0, 0X6E);
        goto L_8002DE90;
    }
    // addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    // addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // ori         $a3, $s4, 0x300
    ctx->r7 = ctx->r20 | 0X300;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xD50
    ctx->r2 = ADD32(ctx->r2, 0XD50);
    // lhu         $a0, 0xD4($v0)
    ctx->r4 = MEM_HU(0XD4, ctx->r2);
    // j           L_8002DEAC
    // addiu       $v1, $v0, 0xC00
    ctx->r3 = ADD32(ctx->r2, 0XC00);
    goto L_8002DEAC;
    // addiu       $v1, $v0, 0xC00
    ctx->r3 = ADD32(ctx->r2, 0XC00);
L_8002DE90:
    // addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // ori         $a3, $s4, 0x300
    ctx->r7 = ctx->r20 | 0X300;
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $v0, $v0, 0xD50
    ctx->r2 = ADD32(ctx->r2, 0XD50);
    // addiu       $v1, $v0, 0xC00
    ctx->r3 = ADD32(ctx->r2, 0XC00);
    // lhu         $a0, 0xD6($v0)
    ctx->r4 = MEM_HU(0XD6, ctx->r2);
L_8002DEAC:
    // lhu         $v0, 0x2E2($s4)
    ctx->r2 = MEM_HU(0X2E2, ctx->r20);
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lhu         $v1, 0x2E0($s4)
    ctx->r3 = MEM_HU(0X2E0, ctx->r20);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x4($s4)
    ctx->r3 = MEM_W(0X4, ctx->r20);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $fp, 0x0($v0)
    ctx->r30 = MEM_HU(0X0, ctx->r2);
L_8002DEDC:
    // jal         0x8002732C
    // addiu       $s3, $s4, 0x300
    ctx->r19 = ADD32(ctx->r20, 0X300);
    sub_8002732C(rdram, ctx);
    goto after_2;
    // addiu       $s3, $s4, 0x300
    ctx->r19 = ADD32(ctx->r20, 0X300);
    after_2:
    // addiu       $a1, $zero, 0xAC
    ctx->r5 = ADD32(0, 0XAC);
    // addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $s5, $v0, 0xD50
    ctx->r21 = ADD32(ctx->r2, 0XD50);
    // lhu         $a0, 0xD8($s5)
    ctx->r4 = MEM_HU(0XD8, ctx->r21);
    // addiu       $s6, $s5, 0xC00
    ctx->r22 = ADD32(ctx->r21, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    sub_8002732C(rdram, ctx);
    goto after_3;
    // addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    after_3:
    // addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // sll         $s1, $fp, 16
    ctx->r17 = S32(ctx->r30) << 16;
    // sra         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17) >> 16;
    // sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17) << 1;
    // lbu         $v0, 0x303($s4)
    ctx->r2 = MEM_BU(0X303, ctx->r20);
    // lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(0X0, ctx->r20);
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sb          $v0, 0x303($s4)
    MEM_B(0X303, ctx->r20) = ctx->r2;
    // addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(0X0, ctx->r2);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_4;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_4:
    // addu        $s0, $s0, $s1
    ctx->r16 = ADD32(ctx->r16, ctx->r17);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // subu        $s0, $s0, $s1
    ctx->r16 = SUB32(ctx->r16, ctx->r17);
    // lbu         $v0, 0x303($s4)
    ctx->r2 = MEM_BU(0X303, ctx->r20);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // sb          $v0, 0x303($s4)
    MEM_B(0X303, ctx->r20) = ctx->r2;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x76F8
    ctx->r2 = ADD32(ctx->r2, 0X76F8);
    // addu        $s2, $s0, $v0
    ctx->r18 = ADD32(ctx->r16, ctx->r2);
    // lbu         $v0, 0x13F($s2)
    ctx->r2 = MEM_BU(0X13F, ctx->r18);
    // nop

    // beq         $v0, $zero, L_8002DFDC
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
        goto L_8002DFDC;
    }
    // addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    // lhu         $a0, 0xDA($s5)
    ctx->r4 = MEM_HU(0XDA, ctx->r21);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // jal         0x8002732C
    // addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    sub_8002732C(rdram, ctx);
    goto after_5;
    // addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    after_5:
    // addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    // addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    // addiu       $s1, $s4, 0x310
    ctx->r17 = ADD32(ctx->r20, 0X310);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // lbu         $a0, 0x140($s2)
    ctx->r4 = MEM_BU(0X140, ctx->r18);
    // lui         $s0, 0x300
    ctx->r16 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    sub_80027440(rdram, ctx);
    goto after_6;
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    after_6:
    // addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    // addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    // jal         0x80026ECC
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    sub_80026ECC(rdram, ctx);
    goto after_7;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_7:
    // addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    // addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    // lbu         $a0, 0x13F($s2)
    ctx->r4 = MEM_BU(0X13F, ctx->r18);
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    sub_80027440(rdram, ctx);
    goto after_8;
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    after_8:
L_8002DFDC:
    // lhu         $v1, 0x2DC($s4)
    ctx->r3 = MEM_HU(0X2DC, ctx->r20);
    // nop

    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // beq         $v0, $zero, L_8002E028
    if (ctx->r2 == 0) {
        // addiu       $a1, $zero, 0xF4
        ctx->r5 = ADD32(0, 0XF4);
        goto L_8002E028;
    }
    // addiu       $a1, $zero, 0xF4
    ctx->r5 = ADD32(0, 0XF4);
    // addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    // ori         $a3, $s4, 0x310
    ctx->r7 = ctx->r20 | 0X310;
    // lbu         $a0, 0x11A($s2)
    ctx->r4 = MEM_BU(0X11A, ctx->r18);
    // lui         $v0, 0x300
    ctx->r2 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    sub_80027440(rdram, ctx);
    goto after_9;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    after_9:
    // addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    // addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    // lhu         $a0, 0xCC($s5)
    ctx->r4 = MEM_HU(0XCC, ctx->r21);
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // jal         0x8002732C
    // addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    sub_8002732C(rdram, ctx);
    goto after_10;
    // addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    after_10:
    // j           L_8002E08C
    // addiu       $a1, $zero, 0xA5
    ctx->r5 = ADD32(0, 0XA5);
    goto L_8002E08C;
    // addiu       $a1, $zero, 0xA5
    ctx->r5 = ADD32(0, 0XA5);
L_8002E028:
    // andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // beq         $v0, $zero, L_8002E088
    if (ctx->r2 == 0) {
        // lui         $v1, 0x5555
        ctx->r3 = S32(0X5555 << 16);
        goto L_8002E088;
    }
    // lui         $v1, 0x5555
    ctx->r3 = S32(0X5555 << 16);
    // lbu         $v0, 0x11B($s2)
    ctx->r2 = MEM_BU(0X11B, ctx->r18);
    // ori         $v1, $v1, 0x5556
    ctx->r3 = ctx->r3 | 0X5556;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lbu         $v0, 0x13F($s2)
    ctx->r2 = MEM_BU(0X13F, ctx->r18);
    // lbu         $v1, 0x140($s2)
    ctx->r3 = MEM_BU(0X140, ctx->r18);
    // mfhi        $a0
    ctx->r4 = hi;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // nop

    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // bne         $v1, $zero, L_8002E06C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8002E06C;
    }
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
L_8002E06C:
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // lui         $a0, 0x400
    ctx->r4 = S32(0X400 << 16);
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    // addiu       $a1, $zero, 0xF4
    ctx->r5 = ADD32(0, 0XF4);
    // addiu       $a2, $zero, 0xBE
    ctx->r6 = ADD32(0, 0XBE);
    // jal         0x80027440
    // ori         $a3, $s4, 0x310
    ctx->r7 = ctx->r20 | 0X310;
    sub_80027440(rdram, ctx);
    goto after_11;
    // ori         $a3, $s4, 0x310
    ctx->r7 = ctx->r20 | 0X310;
    after_11:
L_8002E088:
    // addiu       $a1, $zero, 0xA5
    ctx->r5 = ADD32(0, 0XA5);
L_8002E08C:
    // addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    // addiu       $s2, $s4, 0x300
    ctx->r18 = ADD32(ctx->r20, 0X300);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // lui         $s0, 0x801E
    ctx->r16 = S32(0X801E << 16);
    // addiu       $s0, $s0, 0xD50
    ctx->r16 = ADD32(ctx->r16, 0XD50);
    // lhu         $a0, 0xCE($s0)
    ctx->r4 = MEM_HU(0XCE, ctx->r16);
    // addiu       $s1, $s0, 0xC00
    ctx->r17 = ADD32(ctx->r16, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    sub_8002732C(rdram, ctx);
    goto after_12;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_12:
    // addiu       $a1, $zero, 0xA5
    ctx->r5 = ADD32(0, 0XA5);
    // addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // lhu         $a0, 0xCE($s0)
    ctx->r4 = MEM_HU(0XCE, ctx->r16);
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // jal         0x8002732C
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    sub_8002732C(rdram, ctx);
    goto after_13;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_13:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // addiu       $a0, $a0, 0x76F8
    ctx->r4 = ADD32(ctx->r4, 0X76F8);
    // sll         $v1, $fp, 16
    ctx->r3 = S32(ctx->r30) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
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
    // addu        $s7, $v0, $a0
    ctx->r23 = ADD32(ctx->r2, ctx->r4);
    // addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
L_8002E0FC:
    // andi        $s2, $s5, 0xFFFF
    ctx->r18 = ctx->r21 & 0XFFFF;
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // addiu       $s6, $s4, 0x310
    ctx->r22 = ADD32(ctx->r20, 0X310);
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // addiu       $s5, $s5, 0xE
    ctx->r21 = ADD32(ctx->r21, 0XE);
    // addu        $s1, $s7, $s3
    ctx->r17 = ADD32(ctx->r23, ctx->r19);
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // lbu         $a0, 0x128($s1)
    ctx->r4 = MEM_BU(0X128, ctx->r17);
    // lui         $s0, 0x1300
    ctx->r16 = S32(0X1300 << 16);
    // jal         0x800276BC
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    sub_800276BC(rdram, ctx);
    goto after_14;
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    after_14:
    // addiu       $a1, $zero, 0x111
    ctx->r5 = ADD32(0, 0X111);
    // addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // lbu         $a0, 0x12F($s1)
    ctx->r4 = MEM_BU(0X12F, ctx->r17);
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // jal         0x800276BC
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    sub_800276BC(rdram, ctx);
    goto after_15;
    // or          $a0, $a0, $s0
    ctx->r4 = ctx->r4 | ctx->r16;
    after_15:
    // slti        $v0, $s3, 0x7
    ctx->r2 = SIGNED(ctx->r19) < 0X7 ? 1 : 0;
    // bne         $v0, $zero, L_8002E0FC
    if (ctx->r2 != 0) {
        // addiu       $a1, $zero, 0xCF
        ctx->r5 = ADD32(0, 0XCF);
        goto L_8002E0FC;
    }
    // addiu       $a1, $zero, 0xCF
    ctx->r5 = ADD32(0, 0XCF);
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // addiu       $a0, $a0, 0x76F8
    ctx->r4 = ADD32(ctx->r4, 0X76F8);
    // sll         $v1, $fp, 16
    ctx->r3 = S32(ctx->r30) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
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
    // addu        $a1, $v0, $a0
    ctx->r5 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v0, 0x13C($a1)
    ctx->r2 = MEM_HU(0X13C, ctx->r5);
    // nop

    // beq         $v0, $zero, L_8002E294
    if (ctx->r2 == 0) {
        // lui         $a0, 0x2416
        ctx->r4 = S32(0X2416 << 16);
        goto L_8002E294;
    }
    // lui         $a0, 0x2416
    ctx->r4 = S32(0X2416 << 16);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // ori         $a0, $a0, 0x8E19
    ctx->r4 = ctx->r4 | 0X8E19;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2) << 5;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // mfhi        $t0
    ctx->r8 = hi;
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    // mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    // addiu       $s0, $s4, 0x300
    ctx->r16 = ADD32(ctx->r20, 0X300);
    // lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // lhu         $v0, 0xD0($a0)
    ctx->r2 = MEM_HU(0XD0, ctx->r4);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // sra         $v0, $t0, 6
    ctx->r2 = S32(ctx->r8) >> 6;
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E62($at)
    MEM_H(-0X7E62, ctx->r1) = ctx->r2;
    // mfhi        $t2
    ctx->r10 = hi;
    // sra         $v0, $t2, 6
    ctx->r2 = S32(ctx->r10) >> 6;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E78($at)
    MEM_H(-0X7E78, ctx->r1) = ctx->r2;
    // jal         0x8002732C
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sub_8002732C(rdram, ctx);
    goto after_16;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_16:
    // addiu       $a1, $zero, 0xF8
    ctx->r5 = ADD32(0, 0XF8);
    // addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // lhu         $v0, -0x7E62($v0)
    ctx->r2 = MEM_HU(-0X7E62, ctx->r2);
    // lui         $a0, 0x300
    ctx->r4 = S32(0X300 << 16);
    // jal         0x800276BC
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    sub_800276BC(rdram, ctx);
    goto after_17;
    // or          $a0, $v0, $a0
    ctx->r4 = ctx->r2 | ctx->r4;
    after_17:
    // addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // addiu       $a1, $zero, 0x10D
    ctx->r5 = ADD32(0, 0X10D);
    // addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    // jal         0x80026ECC
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sub_80026ECC(rdram, ctx);
    goto after_18;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_18:
    // addiu       $a1, $zero, 0x113
    ctx->r5 = ADD32(0, 0X113);
    // addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    // addu        $a3, $s6, $zero
    ctx->r7 = ADD32(ctx->r22, 0);
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E62($v1)
    ctx->r3 = MEM_HU(-0X7E62, ctx->r3);
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // lhu         $a0, -0x7E78($a0)
    ctx->r4 = MEM_HU(-0X7E78, ctx->r4);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // jal         0x800276BC
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    sub_800276BC(rdram, ctx);
    goto after_19;
    // or          $a0, $a0, $v0
    ctx->r4 = ctx->r4 | ctx->r2;
    after_19:
    // addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    // addiu       $a1, $zero, 0x119
    ctx->r5 = ADD32(0, 0X119);
    // addiu       $a2, $zero, 0x9C
    ctx->r6 = ADD32(0, 0X9C);
    // jal         0x80026ECC
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sub_80026ECC(rdram, ctx);
    goto after_20;
    // addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_20:
L_8002E294:
    // ori         $a0, $s4, 0x350
    ctx->r4 = ctx->r20 | 0X350;
    // ori         $a1, $s4, 0x358
    ctx->r5 = ctx->r20 | 0X358;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // sh          $v0, 0x350($s4)
    MEM_H(0X350, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // sh          $v0, 0x352($s4)
    MEM_H(0X352, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sh          $v0, 0x354($s4)
    MEM_H(0X354, ctx->r20) = ctx->r2;
    // sh          $v0, 0x356($s4)
    MEM_H(0X356, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // sh          $v0, 0x358($s4)
    MEM_H(0X358, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $v0, 0x35A($s4)
    MEM_H(0X35A, ctx->r20) = ctx->r2;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_21;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_21:
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
    // lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(0X40, ctx->r29);
    // lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(0X3C, ctx->r29);
    // lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(0X38, ctx->r29);
    // lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(0X34, ctx->r29);
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
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
