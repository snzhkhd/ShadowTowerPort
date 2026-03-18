#include "recomp.h"
#include "disable_warnings.h"

void sub_80065770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // lhu         $v1, 0x22($v0)
    ctx->r3 = MEM_HU(0X22, ctx->r2);
    // lhu         $v0, 0x24($v0)
    ctx->r2 = MEM_HU(0X24, ctx->r2);
    // nop

    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_800657D4
    if (ctx->r2 == 0) {
        // lui         $s6, 0x1F80
        ctx->r22 = S32(0X1F80 << 16);
        goto L_800657D4;
    }
    // lui         $s6, 0x1F80
    ctx->r22 = S32(0X1F80 << 16);
    // addu        $t1, $s6, $zero
    ctx->r9 = ADD32(ctx->r22, 0);
    // ori         $t1, $t1, 0x308
    ctx->r9 = ctx->r9 | 0X308;
    // sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // addu        $t1, $s6, $zero
    ctx->r9 = ADD32(ctx->r22, 0);
    // j           L_800657E8
    // ori         $t1, $t1, 0x318
    ctx->r9 = ctx->r9 | 0X318;
    goto L_800657E8;
    // ori         $t1, $t1, 0x318
    ctx->r9 = ctx->r9 | 0X318;
L_800657D4:
    // lui         $t1, 0x1F80
    ctx->r9 = S32(0X1F80 << 16);
    // ori         $t1, $t1, 0x300
    ctx->r9 = ctx->r9 | 0X300;
    // sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // lui         $t1, 0x1F80
    ctx->r9 = S32(0X1F80 << 16);
    // ori         $t1, $t1, 0x310
    ctx->r9 = ctx->r9 | 0X310;
L_800657E8:
    // sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // lui         $s2, 0x2416
    ctx->r18 = S32(0X2416 << 16);
    // lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // addiu       $s0, $s0, -0x70D8
    ctx->r16 = ADD32(ctx->r16, -0X70D8);
    // lhu         $v1, 0x22($s0)
    ctx->r3 = MEM_HU(0X22, ctx->r16);
    // ori         $s2, $s2, 0x8E19
    ctx->r18 = ctx->r18 | 0X8E19;
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
    // mult        $v0, $s2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2) << 5;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // mult        $v1, $s2
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // lui         $s1, 0x801E
    ctx->r17 = S32(0X801E << 16);
    // addiu       $s1, $s1, 0xD50
    ctx->r17 = ADD32(ctx->r17, 0XD50);
    // addiu       $s3, $s1, 0xC00
    ctx->r19 = ADD32(ctx->r17, 0XC00);
    // lhu         $a0, 0x726($s1)
    ctx->r4 = MEM_HU(0X726, ctx->r17);
    // lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(0X28, ctx->r29);
    // sra         $v0, $t0, 6
    ctx->r2 = S32(ctx->r8) >> 6;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
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
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    sub_8002732C(rdram, ctx);
    goto after_0;
    // addu        $a0, $a0, $s3
    ctx->r4 = ADD32(ctx->r4, ctx->r19);
    after_0:
    // addiu       $a1, $zero, 0xB5
    ctx->r5 = ADD32(0, 0XB5);
    // addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // lui         $s5, 0x300
    ctx->r21 = S32(0X300 << 16);
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // lhu         $a0, -0x7E62($a0)
    ctx->r4 = MEM_HU(-0X7E62, ctx->r4);
    // lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(0X2C, ctx->r29);
    // jal         0x80027440
    // or          $a0, $a0, $s5
    ctx->r4 = ctx->r4 | ctx->r21;
    sub_80027440(rdram, ctx);
    goto after_1;
    // or          $a0, $a0, $s5
    ctx->r4 = ctx->r4 | ctx->r21;
    after_1:
    // addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // addiu       $a1, $zero, 0xD4
    ctx->r5 = ADD32(0, 0XD4);
    // lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(0X28, ctx->r29);
    // jal         0x80026ECC
    // addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    sub_80026ECC(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    after_2:
    // addiu       $a1, $zero, 0xD9
    ctx->r5 = ADD32(0, 0XD9);
    // addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // lui         $s4, 0x100
    ctx->r20 = S32(0X100 << 16);
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E62($v1)
    ctx->r3 = MEM_HU(-0X7E62, ctx->r3);
    // lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(0X2C, ctx->r29);
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
    // jal         0x80027440
    // or          $a0, $a0, $s4
    ctx->r4 = ctx->r4 | ctx->r20;
    sub_80027440(rdram, ctx);
    goto after_3;
    // or          $a0, $a0, $s4
    ctx->r4 = ctx->r4 | ctx->r20;
    after_3:
    // addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(0X28, ctx->r29);
    // jal         0x80026ECC
    // addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    sub_80026ECC(rdram, ctx);
    goto after_4;
    // addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    after_4:
    // lhu         $v1, 0x24($s0)
    ctx->r3 = MEM_HU(0X24, ctx->r16);
    // nop

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
    // mult        $v0, $s2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2) << 5;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // mfhi        $a0
    ctx->r4 = hi;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) << 3;
    // mult        $v1, $s2
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // addiu       $s7, $zero, 0x30
    ctx->r23 = ADD32(0, 0X30);
    // addiu       $a1, $zero, 0xF3
    ctx->r5 = ADD32(0, 0XF3);
    // lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(0X2C, ctx->r29);
    // addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // sra         $v0, $a0, 6
    ctx->r2 = S32(ctx->r4) >> 6;
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E62($at)
    MEM_H(-0X7E62, ctx->r1) = ctx->r2;
    // lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // lhu         $a0, -0x7E62($a0)
    ctx->r4 = MEM_HU(-0X7E62, ctx->r4);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // mfhi        $t0
    ctx->r8 = hi;
    // sra         $v0, $t0, 6
    ctx->r2 = S32(ctx->r8) >> 6;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E78($at)
    MEM_H(-0X7E78, ctx->r1) = ctx->r2;
    // jal         0x80027440
    // or          $a0, $a0, $s5
    ctx->r4 = ctx->r4 | ctx->r21;
    sub_80027440(rdram, ctx);
    goto after_5;
    // or          $a0, $a0, $s5
    ctx->r4 = ctx->r4 | ctx->r21;
    after_5:
    // addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // addiu       $a1, $zero, 0x112
    ctx->r5 = ADD32(0, 0X112);
    // lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(0X28, ctx->r29);
    // jal         0x80026ECC
    // addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    sub_80026ECC(rdram, ctx);
    goto after_6;
    // addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    after_6:
    // addiu       $a1, $zero, 0x117
    ctx->r5 = ADD32(0, 0X117);
    // addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E62($v1)
    ctx->r3 = MEM_HU(-0X7E62, ctx->r3);
    // lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(0X2C, ctx->r29);
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
    // jal         0x80027440
    // or          $a0, $a0, $s4
    ctx->r4 = ctx->r4 | ctx->r20;
    sub_80027440(rdram, ctx);
    goto after_7;
    // or          $a0, $a0, $s4
    ctx->r4 = ctx->r4 | ctx->r20;
    after_7:
L_800659E4:
    // addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // andi        $a2, $s7, 0xFFFF
    ctx->r6 = ctx->r23 & 0XFFFF;
    // lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // addiu       $t1, $t1, 0xD50
    ctx->r9 = ADD32(ctx->r9, 0XD50);
    // lhu         $v0, 0x2E2($s6)
    ctx->r2 = MEM_HU(0X2E2, ctx->r22);
    // addiu       $a3, $s6, 0x300
    ctx->r7 = ADD32(ctx->r22, 0X300);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // lhu         $a0, 0x708($v0)
    ctx->r4 = MEM_HU(0X708, ctx->r2);
    // addiu       $t1, $t1, 0x1950
    ctx->r9 = ADD32(ctx->r9, 0X1950);
    // jal         0x8002732C
    // addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    sub_8002732C(rdram, ctx);
    goto after_8;
    // addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    after_8:
    // lhu         $v0, 0x2E2($s6)
    ctx->r2 = MEM_HU(0X2E2, ctx->r22);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v1, $v0, $fp
    ctx->r3 = ADD32(ctx->r2, ctx->r30);
    // sltiu       $v0, $v1, 0xF
    ctx->r2 = ctx->r3 < 0XF ? 1 : 0;
    // beq         $v0, $zero, L_80065B14
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_80065B14;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x3938
    ctx->r2 = ADD32(ctx->r2, 0X3938);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_80065A58;
    jr_addend_80065A58 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80065A58 >> 2) {
        case 0: goto L_80065A60; break;
        case 1: goto L_80065A6C; break;
        case 2: goto L_80065A78; break;
        case 3: goto L_80065A84; break;
        case 4: goto L_80065A90; break;
        case 5: goto L_80065A9C; break;
        case 6: goto L_80065AA8; break;
        case 7: goto L_80065AB4; break;
        case 8: goto L_80065AC0; break;
        case 9: goto L_80065ACC; break;
        case 10: goto L_80065AD8; break;
        case 11: goto L_80065AE4; break;
        case 12: goto L_80065AF0; break;
        case 13: goto L_80065AFC; break;
        case 14: goto L_80065B08; break;
        default: switch_error(__func__, 0x80065A58, 0x80013938);
    }
    // nop

L_80065A60:
    // lhu         $s0, 0x48($s3)
    ctx->r16 = MEM_HU(0X48, ctx->r19);
    // j           L_80065B18
    // nop

    goto L_80065B18;
    // nop

L_80065A6C:
    // lhu         $s0, 0x4A($s3)
    ctx->r16 = MEM_HU(0X4A, ctx->r19);
    // j           L_80065B18
    // nop

    goto L_80065B18;
    // nop

L_80065A78:
    // lhu         $s0, 0x3C($s3)
    ctx->r16 = MEM_HU(0X3C, ctx->r19);
    // j           L_80065B18
    // nop

    goto L_80065B18;
    // nop

L_80065A84:
    // lhu         $s0, 0x4C($s3)
    ctx->r16 = MEM_HU(0X4C, ctx->r19);
    // j           L_80065B18
    // nop

    goto L_80065B18;
    // nop

L_80065A90:
    // lhu         $s0, 0x3E($s3)
    ctx->r16 = MEM_HU(0X3E, ctx->r19);
    // j           L_80065B18
    // nop

    goto L_80065B18;
    // nop

L_80065A9C:
    // lhu         $s0, 0x40($s3)
    ctx->r16 = MEM_HU(0X40, ctx->r19);
    // j           L_80065B18
    // nop

    goto L_80065B18;
    // nop

L_80065AA8:
    // lhu         $s0, 0x58($s3)
    ctx->r16 = MEM_HU(0X58, ctx->r19);
    // j           L_80065B18
    // nop

    goto L_80065B18;
    // nop

L_80065AB4:
    // lhu         $s0, 0x5A($s3)
    ctx->r16 = MEM_HU(0X5A, ctx->r19);
    // j           L_80065B18
    // nop

    goto L_80065B18;
    // nop

L_80065AC0:
    // lhu         $s0, 0x3A($s3)
    ctx->r16 = MEM_HU(0X3A, ctx->r19);
    // j           L_80065B18
    // nop

    goto L_80065B18;
    // nop

L_80065ACC:
    // lhu         $s0, 0x54($s3)
    ctx->r16 = MEM_HU(0X54, ctx->r19);
    // j           L_80065B18
    // nop

    goto L_80065B18;
    // nop

L_80065AD8:
    // lhu         $s0, 0x46($s3)
    ctx->r16 = MEM_HU(0X46, ctx->r19);
    // j           L_80065B18
    // nop

    goto L_80065B18;
    // nop

L_80065AE4:
    // lhu         $s0, 0x38($s3)
    ctx->r16 = MEM_HU(0X38, ctx->r19);
    // j           L_80065B18
    // nop

    goto L_80065B18;
    // nop

L_80065AF0:
    // lhu         $s0, 0x44($s3)
    ctx->r16 = MEM_HU(0X44, ctx->r19);
    // j           L_80065B18
    // nop

    goto L_80065B18;
    // nop

L_80065AFC:
    // lhu         $s0, 0x52($s3)
    ctx->r16 = MEM_HU(0X52, ctx->r19);
    // j           L_80065B18
    // nop

    goto L_80065B18;
    // nop

L_80065B08:
    // lhu         $s0, 0x50($s3)
    ctx->r16 = MEM_HU(0X50, ctx->r19);
    // j           L_80065B18
    // nop

    goto L_80065B18;
    // nop

L_80065B14:
    // ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
L_80065B18:
    // lhu         $v0, 0x2E2($s6)
    ctx->r2 = MEM_HU(0X2E2, ctx->r22);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v1, $v0, $fp
    ctx->r3 = ADD32(ctx->r2, ctx->r30);
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // beq         $v1, $v0, L_80065B40
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xE
        ctx->r2 = ADD32(0, 0XE);
        goto L_80065B40;
    }
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // bne         $v1, $v0, L_80065BEC
    if (ctx->r3 != ctx->r2) {
        // andi        $a0, $s0, 0xFFFF
        ctx->r4 = ctx->r16 & 0XFFFF;
        goto L_80065BEC;
    }
    // andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
L_80065B40:
    // andi        $a3, $s0, 0xFFFF
    ctx->r7 = ctx->r16 & 0XFFFF;
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $a3, $v0, L_80065BD4
    if (ctx->r7 == ctx->r2) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_80065BD4;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $a2, $v0, 0x388C
    ctx->r6 = ADD32(ctx->r2, 0X388C);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // lwl         $a1, 0xB($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XB, ctx->r6);
    // lwr         $a1, 0x8($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X8, ctx->r6);
    // swl         $v1, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r3);
    // swr         $v1, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r3);
    // swl         $a0, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r4);
    // swr         $a0, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r4);
    // swl         $a1, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r5);
    // swr         $a1, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r5);
    // lwl         $v1, 0xF($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0XF, ctx->r6);
    // lwr         $v1, 0xC($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0XC, ctx->r6);
    // lb          $a0, 0x10($a2)
    ctx->r4 = MEM_BS(0X10, ctx->r6);
    // lb          $a1, 0x11($a2)
    ctx->r5 = MEM_BS(0X11, ctx->r6);
    // swl         $v1, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r3);
    // swr         $v1, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r3);
    // sb          $a0, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r4;
    // sb          $a1, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r5;
    // addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // addu        $v0, $sp, $a3
    ctx->r2 = ADD32(ctx->r29, ctx->r7);
    // andi        $a2, $s7, 0xFFFF
    ctx->r6 = ctx->r23 & 0XFFFF;
    // lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // addiu       $t1, $t1, 0xD50
    ctx->r9 = ADD32(ctx->r9, 0XD50);
    // lbu         $v0, 0x10($v0)
    ctx->r2 = MEM_BU(0X10, ctx->r2);
    // addiu       $a3, $s6, 0x300
    ctx->r7 = ADD32(ctx->r22, 0X300);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // lhu         $a0, 0x728($v0)
    ctx->r4 = MEM_HU(0X728, ctx->r2);
    // j           L_80065C68
    // lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    goto L_80065C68;
    // lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
L_80065BD4:
    // addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // addiu       $t1, $t1, 0xD50
    ctx->r9 = ADD32(ctx->r9, 0XD50);
    // lhu         $a0, 0x74E($t1)
    ctx->r4 = MEM_HU(0X74E, ctx->r9);
    // j           L_80065C60
    // andi        $a2, $s7, 0xFFFF
    ctx->r6 = ctx->r23 & 0XFFFF;
    goto L_80065C60;
    // andi        $a2, $s7, 0xFFFF
    ctx->r6 = ctx->r23 & 0XFFFF;
L_80065BEC:
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $a0, $v0, L_80065C50
    if (ctx->r4 == ctx->r2) {
        // addiu       $a1, $zero, 0x5C
        ctx->r5 = ADD32(0, 0X5C);
        goto L_80065C50;
    }
    // addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // andi        $a2, $s7, 0xFFFF
    ctx->r6 = ctx->r23 & 0XFFFF;
    // lbu         $v1, 0x30F($s6)
    ctx->r3 = MEM_BU(0X30F, ctx->r22);
    // lbu         $v0, 0x303($s6)
    ctx->r2 = MEM_BU(0X303, ctx->r22);
    // ori         $v1, $v1, 0x80
    ctx->r3 = ctx->r3 | 0X80;
    // sb          $v1, 0x30F($s6)
    MEM_B(0X30F, ctx->r22) = ctx->r3;
    // lw          $v1, 0x0($s6)
    ctx->r3 = MEM_W(0X0, ctx->r22);
    // ori         $v0, $v0, 0x80
    ctx->r2 = ctx->r2 | 0X80;
    // sb          $v0, 0x303($s6)
    MEM_B(0X303, ctx->r22) = ctx->r2;
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(0X0, ctx->r2);
    // addiu       $a3, $s6, 0x300
    ctx->r7 = ADD32(ctx->r22, 0X300);
    // addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // jal         0x8002732C
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    sub_8002732C(rdram, ctx);
    goto after_9;
    // addu        $a0, $v1, $a0
    ctx->r4 = ADD32(ctx->r3, ctx->r4);
    after_9:
    // lbu         $v0, 0x303($s6)
    ctx->r2 = MEM_BU(0X303, ctx->r22);
    // lbu         $v1, 0x30F($s6)
    ctx->r3 = MEM_BU(0X30F, ctx->r22);
    // andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // andi        $v1, $v1, 0x7F
    ctx->r3 = ctx->r3 & 0X7F;
    // sb          $v0, 0x303($s6)
    MEM_B(0X303, ctx->r22) = ctx->r2;
    // j           L_80065C74
    // sb          $v1, 0x30F($s6)
    MEM_B(0X30F, ctx->r22) = ctx->r3;
    goto L_80065C74;
    // sb          $v1, 0x30F($s6)
    MEM_B(0X30F, ctx->r22) = ctx->r3;
L_80065C50:
    // andi        $a2, $s7, 0xFFFF
    ctx->r6 = ctx->r23 & 0XFFFF;
    // lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // addiu       $t1, $t1, 0xD50
    ctx->r9 = ADD32(ctx->r9, 0XD50);
    // lhu         $a0, 0x74C($t1)
    ctx->r4 = MEM_HU(0X74C, ctx->r9);
L_80065C60:
    // addiu       $a3, $s6, 0x300
    ctx->r7 = ADD32(ctx->r22, 0X300);
    // lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
L_80065C68:
    // addiu       $t1, $t1, 0x1950
    ctx->r9 = ADD32(ctx->r9, 0X1950);
    // jal         0x8002732C
    // addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    sub_8002732C(rdram, ctx);
    goto after_10;
    // addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    after_10:
L_80065C74:
    // lhu         $v0, 0x2E2($s6)
    ctx->r2 = MEM_HU(0X2E2, ctx->r22);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v1, $v0, $fp
    ctx->r3 = ADD32(ctx->r2, ctx->r30);
    // addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // beq         $v1, $v0, L_80065D90
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xE
        ctx->r2 = ADD32(0, 0XE);
        goto L_80065D90;
    }
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // beq         $v1, $v0, L_80065D90
    if (ctx->r3 == ctx->r2) {
        // andi        $v1, $s0, 0xFFFF
        ctx->r3 = ctx->r16 & 0XFFFF;
        goto L_80065D90;
    }
    // andi        $v1, $s0, 0xFFFF
    ctx->r3 = ctx->r16 & 0XFFFF;
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // beq         $v1, $v0, L_80065D90
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 1
        ctx->r2 = S32(ctx->r3) << 1;
        goto L_80065D90;
    }
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
    // lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // addiu       $t1, $t1, 0x76F8
    ctx->r9 = ADD32(ctx->r9, 0X76F8);
    // addu        $v1, $v0, $t1
    ctx->r3 = ADD32(ctx->r2, ctx->r9);
    // lbu         $v0, 0x13F($v1)
    ctx->r2 = MEM_BU(0X13F, ctx->r3);
    // nop

    // beq         $v0, $zero, L_80065D90
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80065D90;
    }
    // nop

    // lbu         $v0, 0x140($v1)
    ctx->r2 = MEM_BU(0X140, ctx->r3);
    // nop

    // sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_80065CF0
    if (ctx->r2 == 0) {
        // addiu       $s4, $s6, 0x308
        ctx->r20 = ADD32(ctx->r22, 0X308);
        goto L_80065CF0;
    }
    // addiu       $s4, $s6, 0x308
    ctx->r20 = ADD32(ctx->r22, 0X308);
    // j           L_80065CF8
    // addiu       $s5, $s6, 0x318
    ctx->r21 = ADD32(ctx->r22, 0X318);
    goto L_80065CF8;
    // addiu       $s5, $s6, 0x318
    ctx->r21 = ADD32(ctx->r22, 0X318);
L_80065CF0:
    // addiu       $s4, $s6, 0x300
    ctx->r20 = ADD32(ctx->r22, 0X300);
    // addiu       $s5, $s6, 0x310
    ctx->r21 = ADD32(ctx->r22, 0X310);
L_80065CF8:
    // addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // addiu       $t1, $t1, 0xD50
    ctx->r9 = ADD32(ctx->r9, 0XD50);
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    // lhu         $a0, 0xDA($t1)
    ctx->r4 = MEM_HU(0XDA, ctx->r9);
    // lui         $t1, 0x801E
    ctx->r9 = S32(0X801E << 16);
    // lhu         $s1, 0x38($sp)
    ctx->r17 = MEM_HU(0X38, ctx->r29);
    // addiu       $t1, $t1, 0x1950
    ctx->r9 = ADD32(ctx->r9, 0X1950);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // jal         0x8002732C
    // addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    sub_8002732C(rdram, ctx);
    goto after_11;
    // addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    after_11:
    // addiu       $a1, $zero, 0xAC
    ctx->r5 = ADD32(0, 0XAC);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // sll         $s0, $v0, 1
    ctx->r16 = S32(ctx->r2) << 1;
    // addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16) << 2;
    // lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // addiu       $t1, $t1, 0x76F8
    ctx->r9 = ADD32(ctx->r9, 0X76F8);
    // addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
    // lbu         $a0, 0x140($s0)
    ctx->r4 = MEM_BU(0X140, ctx->r16);
    // lui         $s2, 0x300
    ctx->r18 = S32(0X300 << 16);
    // jal         0x80027440
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    sub_80027440(rdram, ctx);
    goto after_12;
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    after_12:
    // addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // jal         0x80026ECC
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    sub_80026ECC(rdram, ctx);
    goto after_13;
    // addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_13:
    // addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // lbu         $a0, 0x13F($s0)
    ctx->r4 = MEM_BU(0X13F, ctx->r16);
    // addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // jal         0x80027440
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    sub_80027440(rdram, ctx);
    goto after_14;
    // or          $a0, $a0, $s2
    ctx->r4 = ctx->r4 | ctx->r18;
    after_14:
L_80065D90:
    // addiu       $s7, $s7, 0x24
    ctx->r23 = ADD32(ctx->r23, 0X24);
    // addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(0X38, ctx->r29);
    // slti        $v0, $fp, 0x5
    ctx->r2 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
    // addiu       $t1, $t1, 0x24
    ctx->r9 = ADD32(ctx->r9, 0X24);
    // bne         $v0, $zero, L_800659E4
    if (ctx->r2 != 0) {
        // sw          $t1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r9;
        goto L_800659E4;
    }
    // sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
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
