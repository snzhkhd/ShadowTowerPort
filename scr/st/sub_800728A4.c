#include "recomp.h"
#include "disable_warnings.h"

void sub_800728A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x6914($v0)
    ctx->r2 = MEM_W(-0X6914, ctx->r2);
    // lui         $t0, 0x801F
    ctx->r8 = S32(0X801F << 16);
    // addiu       $t0, $t0, -0x68EE
    ctx->r8 = ADD32(ctx->r8, -0X68EE);
    // lbu         $a0, 0x18($v0)
    ctx->r4 = MEM_BU(0X18, ctx->r2);
    // lb          $v1, -0x16($t0)
    ctx->r3 = MEM_BS(-0X16, ctx->r8);
    // sll         $v0, $a0, 14
    ctx->r2 = S32(ctx->r4) << 14;
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
    // lb          $a0, -0x10($t0)
    ctx->r4 = MEM_BS(-0X10, ctx->r8);
    // mfhi        $v0
    ctx->r2 = hi;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 13
    ctx->r2 = S32(ctx->r2) >> 13;
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // subu        $a3, $v0, $v1
    ctx->r7 = SUB32(ctx->r2, ctx->r3);
    // mult        $a3, $a0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lb          $v0, -0xD($t0)
    ctx->r2 = MEM_BS(-0XD, ctx->r8);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $a0, 0x40C
    ctx->r4 = S32(0X40C << 16);
    // ori         $a0, $a0, 0x2051
    ctx->r4 = ctx->r4 | 0X2051;
    // multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lh          $v1, 0x0($t0)
    ctx->r3 = MEM_HS(0X0, ctx->r8);
    // addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // sll         $t2, $v1, 3
    ctx->r10 = S32(ctx->r3) << 3;
    // mfhi        $a0
    ctx->r4 = hi;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // srl         $a2, $a0, 13
    ctx->r6 = S32(U32(ctx->r4) >> 13);
    // lhu         $a0, -0x4($t0)
    ctx->r4 = MEM_HU(-0X4, ctx->r8);
    // nop

    // andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
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
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // lw          $v1, -0x79A0($v1)
    ctx->r3 = MEM_W(-0X79A0, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    // beq         $a0, $v0, L_800729E4
    if (ctx->r4 == ctx->r2) {
        // addu        $a3, $a2, $zero
        ctx->r7 = ADD32(ctx->r6, 0);
        goto L_800729E4;
    }
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // lhu         $v0, 0x58($v1)
    ctx->r2 = MEM_HU(0X58, ctx->r3);
    // nop

    // mult        $a2, $v0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // lhu         $v1, 0x5A($v1)
    ctx->r3 = MEM_HU(0X5A, ctx->r3);
    // nop

    // mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lui         $a0, 0x204
    ctx->r4 = S32(0X204 << 16);
    // ori         $a0, $a0, 0x811
    ctx->r4 = ctx->r4 | 0X811;
    // multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $a1
    ctx->r5 = hi;
    // nop

    // nop

    // multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // srl         $a3, $a1, 6
    ctx->r7 = S32(U32(ctx->r5) >> 6);
    // mfhi        $a0
    ctx->r4 = hi;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // srl         $a2, $a0, 6
    ctx->r6 = S32(U32(ctx->r4) >> 6);
L_800729E4:
    // lbu         $v1, -0xC($t0)
    ctx->r3 = MEM_BU(-0XC, ctx->r8);
    // nop

    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80072A24
    if (ctx->r2 == 0) {
        // mult        $a2, $v1
        result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80072A24;
    }
    // mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $v1, 0x410
    ctx->r3 = S32(0X410 << 16);
    // ori         $v1, $v1, 0x4105
    ctx->r3 = ctx->r3 | 0X4105;
    // multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $a3, $zero
    ctx->r4 = ADD32(ctx->r7, 0);
    // mfhi        $v1
    ctx->r3 = hi;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // j           L_80072A58
    // srl         $a1, $v1, 5
    ctx->r5 = S32(U32(ctx->r3) >> 5);
    goto L_80072A58;
    // srl         $a1, $v1, 5
    ctx->r5 = S32(U32(ctx->r3) >> 5);
L_80072A24:
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // mult        $a3, $v0
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $v1, 0x410
    ctx->r3 = S32(0X410 << 16);
    // ori         $v1, $v1, 0x4105
    ctx->r3 = ctx->r3 | 0X4105;
    // multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
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
L_80072A58:
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lbu         $v1, -0x68FD($v1)
    ctx->r3 = MEM_BU(-0X68FD, ctx->r3);
    // nop

    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80072A98
    if (ctx->r2 == 0) {
        // mult        $a1, $v1
        result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80072A98;
    }
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
    // j           L_80072AC8
    // srl         $a1, $v1, 5
    ctx->r5 = S32(U32(ctx->r3) >> 5);
    goto L_80072AC8;
    // srl         $a1, $v1, 5
    ctx->r5 = S32(U32(ctx->r3) >> 5);
L_80072A98:
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
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
L_80072AC8:
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lbu         $v1, -0x6903($v1)
    ctx->r3 = MEM_BU(-0X6903, ctx->r3);
    // nop

    // sltiu       $v0, $v1, 0x40
    ctx->r2 = ctx->r3 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80072B08
    if (ctx->r2 == 0) {
        // mult        $a1, $v1
        result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80072B08;
    }
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
    // j           L_80072B38
    // srl         $a1, $v1, 5
    ctx->r5 = S32(U32(ctx->r3) >> 5);
    goto L_80072B38;
    // srl         $a1, $v1, 5
    ctx->r5 = S32(U32(ctx->r3) >> 5);
L_80072B08:
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
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
L_80072B38:
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lh          $v1, -0x6920($v1)
    ctx->r3 = MEM_HS(-0X6920, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80072B60
    if (ctx->r3 != ctx->r2) {
        // sltu        $v0, $a0, $a1
        ctx->r2 = ctx->r4 < ctx->r5 ? 1 : 0;
        goto L_80072B60;
    }
    // sltu        $v0, $a0, $a1
    ctx->r2 = ctx->r4 < ctx->r5 ? 1 : 0;
    // beq         $v0, $zero, L_80072B5C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80072B5C;
    }
    // nop

    // j           L_80072B60
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    goto L_80072B60;
    // addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_80072B5C:
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_80072B60:
    // lui         $a2, 0x801F
    ctx->r6 = S32(0X801F << 16);
    // addiu       $a2, $a2, -0x68F2
    ctx->r6 = ADD32(ctx->r6, -0X68F2);
    // lh          $v1, 0x0($a2)
    ctx->r3 = MEM_HS(0X0, ctx->r6);
    // addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    // beq         $v1, $v0, L_80072BCC
    if (ctx->r3 == ctx->r2) {
        // mult        $a0, $a0
        result = S64(S32(ctx->r4)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80072BCC;
    }
    // mult        $a0, $a0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // nop

    // nop

    // mult        $a1, $a1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // lui         $v0, 0x4
    ctx->r2 = S32(0X4 << 16);
    // ori         $v0, $v0, 0x11
    ctx->r2 = ctx->r2 | 0X11;
    // multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $v1
    ctx->r3 = hi;
    // nop

    // nop

    // multu       $a1, $v0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // srl         $a0, $a0, 1
    ctx->r4 = S32(U32(ctx->r4) >> 1);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // srl         $a0, $v1, 13
    ctx->r4 = S32(U32(ctx->r3) >> 13);
    // mfhi        $v0
    ctx->r2 = hi;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // srl         $a1, $a1, 1
    ctx->r5 = S32(U32(ctx->r5) >> 1);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // srl         $a1, $v0, 13
    ctx->r5 = S32(U32(ctx->r2) >> 13);
L_80072BCC:
    // andi        $v0, $t2, 0xFFFF
    ctx->r2 = ctx->r10 & 0XFFFF;
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $t1, -0x6BCC($at)
    MEM_H(-0X6BCC, ctx->r1) = ctx->r9;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $a0, -0x6BD0($at)
    MEM_H(-0X6BD0, ctx->r1) = ctx->r4;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $a1, -0x6BCE($at)
    MEM_H(-0X6BCE, ctx->r1) = ctx->r5;
    // lh          $v1, 0x4($a2)
    ctx->r3 = MEM_HS(0X4, ctx->r6);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, -0x6BF0($v0)
    ctx->r2 = MEM_BU(-0X6BF0, ctx->r2);
    // nop

    // ori         $v0, $v0, 0x7
    ctx->r2 = ctx->r2 | 0X7;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sb          $v0, -0x6BF0($at)
    MEM_B(-0X6BF0, ctx->r1) = ctx->r2;
    // lh          $v1, 0x4($a2)
    ctx->r3 = MEM_HS(0X4, ctx->r6);
    // nop

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
    // sh          $t1, -0x70FC($at)
    MEM_H(-0X70FC, ctx->r1) = ctx->r9;
    // lh          $v1, 0x4($a2)
    ctx->r3 = MEM_HS(0X4, ctx->r6);
    // nop

    // slti        $v0, $v1, 0x10
    ctx->r2 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_80072C64
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80072C64;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sllv        $a2, $v0, $v1
    ctx->r6 = S32(ctx->r2) << (ctx->r3 & 31);
    // j           L_80072C70
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    goto L_80072C70;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80072C64:
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // sllv        $a1, $v0, $v1
    ctx->r5 = S32(ctx->r2) << (ctx->r3 & 31);
L_80072C70:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lbu         $v0, -0x68F4($v0)
    ctx->r2 = MEM_BU(-0X68F4, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // beq         $v0, $zero, L_80072CB8
    if (ctx->r2 == 0) {
        // nor         $v1, $zero, $a2
        ctx->r3 = ~(0 | ctx->r6);
        goto L_80072CB8;
    }
    // nor         $v1, $zero, $a2
    ctx->r3 = ~(0 | ctx->r6);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x710C($v0)
    ctx->r2 = MEM_HU(-0X710C, ctx->r2);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lhu         $v1, -0x710A($v1)
    ctx->r3 = MEM_HU(-0X710A, ctx->r3);
    // or          $v0, $v0, $a2
    ctx->r2 = ctx->r2 | ctx->r6;
    // or          $v1, $v1, $a1
    ctx->r3 = ctx->r3 | ctx->r5;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v0, -0x710C($at)
    MEM_H(-0X710C, ctx->r1) = ctx->r2;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v1, -0x710A($at)
    MEM_H(-0X710A, ctx->r1) = ctx->r3;
    // j           L_80072CEC
    // nor         $v1, $zero, $a2
    ctx->r3 = ~(0 | ctx->r6);
    goto L_80072CEC;
    // nor         $v1, $zero, $a2
    ctx->r3 = ~(0 | ctx->r6);
L_80072CB8:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x710C($v0)
    ctx->r2 = MEM_HU(-0X710C, ctx->r2);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v0, -0x710C($at)
    MEM_H(-0X710C, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x710A($v0)
    ctx->r2 = MEM_HU(-0X710A, ctx->r2);
    // nor         $v1, $zero, $a1
    ctx->r3 = ~(0 | ctx->r5);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v0, -0x710A($at)
    MEM_H(-0X710A, ctx->r1) = ctx->r2;
    // nor         $v1, $zero, $a2
    ctx->r3 = ~(0 | ctx->r6);
L_80072CEC:
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x7108($v0)
    ctx->r2 = MEM_HU(-0X7108, ctx->r2);
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // lhu         $a0, -0x710E($a0)
    ctx->r4 = MEM_HU(-0X710E, ctx->r4);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v0, -0x7108($at)
    MEM_H(-0X7108, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x7106($v0)
    ctx->r2 = MEM_HU(-0X7106, ctx->r2);
    // nor         $v1, $zero, $a1
    ctx->r3 = ~(0 | ctx->r5);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lhu         $v1, -0x7110($v1)
    ctx->r3 = MEM_HU(-0X7110, ctx->r3);
    // or          $a0, $a0, $a1
    ctx->r4 = ctx->r4 | ctx->r5;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $a0, -0x710E($at)
    MEM_H(-0X710E, ctx->r1) = ctx->r4;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v0, -0x7106($at)
    MEM_H(-0X7106, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x6A08($v0)
    ctx->r2 = MEM_HU(-0X6A08, ctx->r2);
    // or          $v1, $v1, $a2
    ctx->r3 = ctx->r3 | ctx->r6;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v1, -0x7110($at)
    MEM_H(-0X7110, ctx->r1) = ctx->r3;
    // nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v0, -0x6A08($at)
    MEM_H(-0X6A08, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x6A06($v0)
    ctx->r2 = MEM_HU(-0X6A06, ctx->r2);
    // nor         $a0, $zero, $a0
    ctx->r4 = ~(0 | ctx->r4);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // jr          $ra
    // sh          $v0, -0x6A06($at)
    MEM_H(-0X6A06, ctx->r1) = ctx->r2;
    return;
    // sh          $v0, -0x6A06($at)
    MEM_H(-0X6A06, ctx->r1) = ctx->r2;
;}
