#include "recomp.h"
#include "disable_warnings.h"

void _SsVmSetSeqVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7) << 2;
    // andi        $v1, $a0, 0xFF00
    ctx->r3 = ctx->r4 & 0XFF00;
    // sra         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3) >> 8;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // lw          $v1, -0x79A0($v1)
    ctx->r3 = MEM_W(-0X79A0, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $s1, $v1, $v0
    ctx->r17 = ADD32(ctx->r3, ctx->r2);
    // sh          $a1, 0x58($s1)
    MEM_H(0X58, ctx->r17) = ctx->r5;
    // lhu         $v0, 0x58($s1)
    ctx->r2 = MEM_HU(0X58, ctx->r17);
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // sltiu       $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 < 0X7F ? 1 : 0;
    // bne         $v0, $zero, L_80072DF4
    if (ctx->r2 != 0) {
        // sh          $a2, 0x5A($s1)
        MEM_H(0X5A, ctx->r17) = ctx->r6;
        goto L_80072DF4;
    }
    // sh          $a2, 0x5A($s1)
    MEM_H(0X5A, ctx->r17) = ctx->r6;
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sh          $v0, 0x58($s1)
    MEM_H(0X58, ctx->r17) = ctx->r2;
L_80072DF4:
    // lhu         $v0, 0x5A($s1)
    ctx->r2 = MEM_HU(0X5A, ctx->r17);
    // nop

    // sltiu       $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 < 0X7F ? 1 : 0;
    // bne         $v0, $zero, L_80072E0C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x7F
        ctx->r2 = ADD32(0, 0X7F);
        goto L_80072E0C;
    }
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sh          $v0, 0x5A($s1)
    MEM_H(0X5A, ctx->r17) = ctx->r2;
L_80072E0C:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lb          $v0, -0x690C($v0)
    ctx->r2 = MEM_BS(-0X690C, ctx->r2);
    // nop

    // blez        $v0, L_800732C0
    if (SIGNED(ctx->r2) <= 0) {
        // addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
        goto L_800732C0;
    }
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // lui         $s5, 0x204
    ctx->r21 = S32(0X204 << 16);
    // ori         $s5, $s5, 0x811
    ctx->r21 = ctx->r21 | 0X811;
    // addiu       $s7, $zero, 0x7F
    ctx->r23 = ADD32(0, 0X7F);
    // lui         $s3, 0x8208
    ctx->r19 = S32(0X8208 << 16);
    // ori         $s3, $s3, 0x2083
    ctx->r19 = ctx->r19 | 0X2083;
    // lui         $s4, 0x8002
    ctx->r20 = S32(0X8002 << 16);
    // ori         $s4, $s4, 0x9
    ctx->r20 = ctx->r20 | 0X9;
    // lui         $fp, 0x801F
    ctx->r30 = S32(0X801F << 16);
    // addiu       $fp, $fp, -0x6BD0
    ctx->r30 = ADD32(ctx->r30, -0X6BD0);
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
L_80072E48:
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0xE60($v1)
    ctx->r3 = MEM_W(0XE60, ctx->r3);
    // sllv        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2) << (ctx->r4 & 31);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // bne         $v1, $zero, L_800732A0
    if (ctx->r3 != 0) {
        // addiu       $v0, $s2, 0x1
        ctx->r2 = ADD32(ctx->r18, 0X1);
        goto L_800732A0;
    }
    // addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
    // sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4) << 3;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $s0, $v0, 1
    ctx->r16 = S32(ctx->r2) << 1;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // lh          $v1, -0x70F0($v1)
    ctx->r3 = MEM_HS(-0X70F0, ctx->r3);
    // sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bne         $v1, $v0, L_800732A0
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $s2, 0x1
        ctx->r2 = ADD32(ctx->r18, 0X1);
        goto L_800732A0;
    }
    // addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // lh          $a0, -0x70E8($a0)
    ctx->r4 = MEM_HS(-0X70E8, ctx->r4);
    // lb          $v0, 0x26($s1)
    ctx->r2 = MEM_BS(0X26, ctx->r17);
    // nop

    // bne         $a0, $v0, L_800732A0
    if (ctx->r4 != ctx->r2) {
        // addiu       $v0, $s2, 0x1
        ctx->r2 = ADD32(ctx->r18, 0X1);
        goto L_800732A0;
    }
    // addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // lh          $a1, -0x70EE($a1)
    ctx->r5 = MEM_HS(-0X70EE, ctx->r5);
    // jal         0x800734A4
    // nop

    _SsVmVSetUp(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lh          $v0, -0x70F4($v0)
    ctx->r2 = MEM_HS(-0X70F4, ctx->r2);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // lh          $v1, -0x70F8($v1)
    ctx->r3 = MEM_HS(-0X70F8, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // lh          $v0, 0x60($v0)
    ctx->r2 = MEM_HS(0X60, ctx->r2);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lui         $v0, 0x8102
    ctx->r2 = S32(0X8102 << 16);
    // ori         $v0, $v0, 0x409
    ctx->r2 = ctx->r2 | 0X409;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $a3
    ctx->r7 = hi;
    // addu        $a0, $a3, $v1
    ctx->r4 = ADD32(ctx->r7, ctx->r3);
    // sra         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4) >> 6;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lw          $v1, -0x6914($v1)
    ctx->r3 = MEM_W(-0X6914, ctx->r3);
    // sll         $v0, $a0, 14
    ctx->r2 = S32(ctx->r4) << 14;
    // lbu         $v1, 0x18($v1)
    ctx->r3 = MEM_BU(0X18, ctx->r3);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lui         $v0, 0x8206
    ctx->r2 = S32(0X8206 << 16);
    // ori         $v0, $v0, 0x1029
    ctx->r2 = ctx->r2 | 0X1029;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lh          $v0, -0x70EC($v0)
    ctx->r2 = MEM_HS(-0X70EC, ctx->r2);
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // lw          $a0, -0x691C($a0)
    ctx->r4 = MEM_W(-0X691C, ctx->r4);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(0X1, ctx->r2);
    // mfhi        $a3
    ctx->r7 = hi;
    // addu        $a1, $a3, $v1
    ctx->r5 = ADD32(ctx->r7, ctx->r3);
    // sra         $a1, $a1, 13
    ctx->r5 = S32(ctx->r5) >> 13;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $a0, $a1, $v1
    ctx->r4 = SUB32(ctx->r5, ctx->r3);
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lui         $a2, 0x801F
    ctx->r6 = S32(0X801F << 16);
    // addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // lh          $a2, -0x70EE($a2)
    ctx->r6 = MEM_HS(-0X70EE, ctx->r6);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lh          $v0, -0x70EA($v0)
    ctx->r2 = MEM_HS(-0X70EA, ctx->r2);
    // sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6) << 4;
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x6910($v0)
    ctx->r2 = MEM_W(-0X6910, ctx->r2);
    // sll         $a2, $a2, 5
    ctx->r6 = S32(ctx->r6) << 5;
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // mflo        $v1
    ctx->r3 = lo;
    // lbu         $v0, 0x2($a2)
    ctx->r2 = MEM_BU(0X2, ctx->r6);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $v1, 0x40C
    ctx->r3 = S32(0X40C << 16);
    // ori         $v1, $v1, 0x2051
    ctx->r3 = ctx->r3 | 0X2051;
    // multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v1
    ctx->r3 = hi;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x58($s1)
    ctx->r2 = MEM_HU(0X58, ctx->r17);
    // srl         $a1, $v1, 13
    ctx->r5 = S32(U32(ctx->r3) >> 13);
    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // lhu         $v1, 0x5A($s1)
    ctx->r3 = MEM_HU(0X5A, ctx->r17);
    // nop

    // mult        $a1, $v1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // nop

    // multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $a0
    ctx->r4 = hi;
    // nop

    // nop

    // multu       $v1, $s5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // srl         $a0, $a0, 6
    ctx->r4 = S32(U32(ctx->r4) >> 6);
    // mfhi        $a1
    ctx->r5 = hi;
    // subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // lbu         $v1, 0x3($a2)
    ctx->r3 = MEM_BU(0X3, ctx->r6);
    // nop

    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80073074
    if (ctx->r2 == 0) {
        // srl         $a1, $a1, 6
        ctx->r5 = S32(U32(ctx->r5) >> 6);
        goto L_80073074;
    }
    // srl         $a1, $a1, 6
    ctx->r5 = S32(U32(ctx->r5) >> 6);
    // mult        $a1, $v1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $v1, 0x410
    ctx->r3 = S32(0X410 << 16);
    // ori         $v1, $v1, 0x4105
    ctx->r3 = ctx->r3 | 0X4105;
    // multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v1
    ctx->r3 = hi;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // j           L_800730A0
    // srl         $a1, $v1, 5
    ctx->r5 = S32(U32(ctx->r3) >> 5);
    goto L_800730A0;
    // srl         $a1, $v1, 5
    ctx->r5 = S32(U32(ctx->r3) >> 5);
L_80073074:
    // subu        $v0, $s7, $v1
    ctx->r2 = SUB32(ctx->r23, ctx->r3);
    // mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $v1, 0x410
    ctx->r3 = S32(0X410 << 16);
    // ori         $v1, $v1, 0x4105
    ctx->r3 = ctx->r3 | 0X4105;
    // multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v1
    ctx->r3 = hi;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // srl         $a0, $v1, 5
    ctx->r4 = S32(U32(ctx->r3) >> 5);
L_800730A0:
    // sll         $v1, $s2, 16
    ctx->r3 = S32(ctx->r18) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // lh          $v0, -0x70EC($at)
    ctx->r2 = MEM_HS(-0X70EC, ctx->r1);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lw          $v1, -0x691C($v1)
    ctx->r3 = MEM_W(-0X691C, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(0X4, ctx->r2);
    // nop

    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80073110
    if (ctx->r2 == 0) {
        // andi        $v0, $a1, 0xFFFF
        ctx->r2 = ctx->r5 & 0XFFFF;
        goto L_80073110;
    }
    // andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // j           L_80073140
    // srl         $a1, $v0, 5
    ctx->r5 = S32(U32(ctx->r2) >> 5);
    goto L_80073140;
    // srl         $a1, $v0, 5
    ctx->r5 = S32(U32(ctx->r2) >> 5);
L_80073110:
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // subu        $v1, $s7, $v1
    ctx->r3 = SUB32(ctx->r23, ctx->r3);
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // sra         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) >> 5;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
L_80073140:
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // lbu         $v1, -0x70F6($at)
    ctx->r3 = MEM_BU(-0X70F6, ctx->r1);
    // nop

    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_8007319C
    if (ctx->r2 == 0) {
        // andi        $v0, $a1, 0xFFFF
        ctx->r2 = ctx->r5 & 0XFFFF;
        goto L_8007319C;
    }
    // andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // j           L_800731CC
    // srl         $a1, $v0, 5
    ctx->r5 = S32(U32(ctx->r2) >> 5);
    goto L_800731CC;
    // srl         $a1, $v0, 5
    ctx->r5 = S32(U32(ctx->r2) >> 5);
L_8007319C:
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // subu        $v1, $s7, $v1
    ctx->r3 = SUB32(ctx->r23, ctx->r3);
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t0
    ctx->r8 = hi;
    // addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // sra         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3) >> 5;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // subu        $a0, $v1, $v0
    ctx->r4 = SUB32(ctx->r3, ctx->r2);
L_800731CC:
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lh          $v1, -0x6920($v1)
    ctx->r3 = MEM_HS(-0X6920, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80073200
    if (ctx->r3 != ctx->r2) {
        // andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
        goto L_80073200;
    }
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // beq         $v0, $zero, L_800731F8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800731F8;
    }
    // nop

    // j           L_800731FC
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    goto L_800731FC;
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_800731F8:
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_800731FC:
    // andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_80073200:
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // andi        $v1, $a1, 0xFFFF
    ctx->r3 = ctx->r5 & 0XFFFF;
    // nop

    // mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // nop

    // nop

    // mult        $v0, $s4
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t1
    ctx->r9 = hi;
    // nop

    // nop

    // mult        $v1, $s4
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $a2, $s2, 16
    ctx->r6 = S32(ctx->r18) << 16;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // sll         $a1, $a2, 4
    ctx->r5 = S32(ctx->r6) << 4;
    // lui         $t0, 0x801F
    ctx->r8 = S32(0X801F << 16);
    // addiu       $t0, $t0, -0x6BCE
    ctx->r8 = ADD32(ctx->r8, -0X6BCE);
    // addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    // sra         $a0, $a0, 13
    ctx->r4 = S32(ctx->r4) >> 13;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // addu        $v0, $a1, $fp
    ctx->r2 = ADD32(ctx->r5, ctx->r30);
    // addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // mfhi        $a3
    ctx->r7 = hi;
    // addu        $v0, $a3, $v1
    ctx->r2 = ADD32(ctx->r7, ctx->r3);
    // sra         $v0, $v0, 13
    ctx->r2 = S32(ctx->r2) >> 13;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // lbu         $v0, -0x6BF0($v0)
    ctx->r2 = MEM_BU(-0X6BF0, ctx->r2);
    // nop

    // ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $a2
    ctx->r1 = ADD32(ctx->r1, ctx->r6);
    // sb          $v0, -0x6BF0($at)
    MEM_B(-0X6BF0, ctx->r1) = ctx->r2;
    // addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
L_800732A0:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lb          $v1, -0x690C($v1)
    ctx->r3 = MEM_BS(-0X690C, ctx->r3);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_80072E48
    if (ctx->r2 != 0) {
        // sll         $v0, $s2, 16
        ctx->r2 = S32(ctx->r18) << 16;
        goto L_80072E48;
    }
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
L_800732C0:
    // sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(0X3C, ctx->r29);
    // lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(0X38, ctx->r29);
    // lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(0X34, ctx->r29);
    // lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
