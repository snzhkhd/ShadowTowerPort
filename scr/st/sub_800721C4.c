#include "recomp.h"
#include "disable_warnings.h"

void sub_800721C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lw          $v0, -0x6914($v0)
    ctx->r2 = MEM_W(-0X6914, ctx->r2);
    // lui         $t0, 0x801F
    ctx->r8 = S32(0X801F << 16);
    // addiu       $t0, $t0, -0x68F2
    ctx->r8 = ADD32(ctx->r8, -0X68F2);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lbu         $a0, 0x18($v0)
    ctx->r4 = MEM_BU(0X18, ctx->r2);
    // lb          $v1, -0x12($t0)
    ctx->r3 = MEM_BS(-0X12, ctx->r8);
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
    // lb          $a0, -0xC($t0)
    ctx->r4 = MEM_BS(-0XC, ctx->r8);
    // mfhi        $a1
    ctx->r5 = hi;
    // addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
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
    // lb          $v0, -0x9($t0)
    ctx->r2 = MEM_BS(-0X9, ctx->r8);
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
    // lhu         $a0, 0x0($t0)
    ctx->r4 = MEM_HU(0X0, ctx->r8);
    // nop

    // andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5) << 2;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // mfhi        $v1
    ctx->r3 = hi;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // srl         $a2, $v1, 13
    ctx->r6 = S32(U32(ctx->r3) >> 13);
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
    // beq         $a0, $v0, L_80072314
    if (ctx->r4 == ctx->r2) {
        // addu        $a3, $a2, $zero
        ctx->r7 = ADD32(ctx->r6, 0);
        goto L_80072314;
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
L_80072314:
    // lb          $a0, -0x8($t0)
    ctx->r4 = MEM_BS(-0X8, ctx->r8);
    // nop

    // sltiu       $v0, $a0, 0x40
    ctx->r2 = ctx->r4 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80072354
    if (ctx->r2 == 0) {
        // mult        $a2, $a0
        result = S64(S32(ctx->r6)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80072354;
    }
    // mult        $a2, $a0
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // lui         $v1, 0x410
    ctx->r3 = S32(0X410 << 16);
    // ori         $v1, $v1, 0x4105
    ctx->r3 = ctx->r3 | 0X4105;
    // multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // mfhi        $v1
    ctx->r3 = hi;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // j           L_80072388
    // srl         $s1, $v1, 5
    ctx->r17 = S32(U32(ctx->r3) >> 5);
    goto L_80072388;
    // srl         $s1, $v1, 5
    ctx->r17 = S32(U32(ctx->r3) >> 5);
L_80072354:
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
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
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // mfhi        $v1
    ctx->r3 = hi;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // srl         $s2, $v1, 5
    ctx->r18 = S32(U32(ctx->r3) >> 5);
L_80072388:
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // lb          $a0, -0x68FD($a0)
    ctx->r4 = MEM_BS(-0X68FD, ctx->r4);
    // nop

    // sltiu       $v0, $a0, 0x40
    ctx->r2 = ctx->r4 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_800723C8
    if (ctx->r2 == 0) {
        // mult        $s1, $a0
        result = S64(S32(ctx->r17)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_800723C8;
    }
    // mult        $s1, $a0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
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
    // j           L_800723F8
    // srl         $s1, $v1, 5
    ctx->r17 = S32(U32(ctx->r3) >> 5);
    goto L_800723F8;
    // srl         $s1, $v1, 5
    ctx->r17 = S32(U32(ctx->r3) >> 5);
L_800723C8:
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // mult        $s2, $v0
    result = S64(S32(ctx->r18)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
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
    // srl         $s2, $v1, 5
    ctx->r18 = S32(U32(ctx->r3) >> 5);
L_800723F8:
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // lb          $a0, -0x6903($a0)
    ctx->r4 = MEM_BS(-0X6903, ctx->r4);
    // nop

    // sltiu       $v0, $a0, 0x40
    ctx->r2 = ctx->r4 < 0X40 ? 1 : 0;
    // beq         $v0, $zero, L_80072438
    if (ctx->r2 == 0) {
        // mult        $a0, $s1
        result = S64(S32(ctx->r4)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_80072438;
    }
    // mult        $a0, $s1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
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
    // j           L_80072468
    // srl         $s1, $v1, 5
    ctx->r17 = S32(U32(ctx->r3) >> 5);
    goto L_80072468;
    // srl         $s1, $v1, 5
    ctx->r17 = S32(U32(ctx->r3) >> 5);
L_80072438:
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // mult        $s2, $v0
    result = S64(S32(ctx->r18)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
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
    // srl         $s2, $v1, 5
    ctx->r18 = S32(U32(ctx->r3) >> 5);
L_80072468:
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lh          $v1, -0x6920($v1)
    ctx->r3 = MEM_HS(-0X6920, ctx->r3);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80072490
    if (ctx->r3 != ctx->r2) {
        // sltu        $v0, $s2, $s1
        ctx->r2 = ctx->r18 < ctx->r17 ? 1 : 0;
        goto L_80072490;
    }
    // sltu        $v0, $s2, $s1
    ctx->r2 = ctx->r18 < ctx->r17 ? 1 : 0;
    // beq         $v0, $zero, L_8007248C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007248C;
    }
    // nop

    // j           L_80072490
    // addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
    goto L_80072490;
    // addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
L_8007248C:
    // addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
L_80072490:
    // lui         $a2, 0x801F
    ctx->r6 = S32(0X801F << 16);
    // addiu       $a2, $a2, -0x68F2
    ctx->r6 = ADD32(ctx->r6, -0X68F2);
    // lh          $v1, 0x0($a2)
    ctx->r3 = MEM_HS(0X0, ctx->r6);
    // addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    // beq         $v1, $v0, L_800724FC
    if (ctx->r3 == ctx->r2) {
        // mult        $s2, $s2
        result = S64(S32(ctx->r18)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_800724FC;
    }
    // mult        $s2, $s2
    result = S64(S32(ctx->r18)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // nop

    // nop

    // mult        $s1, $s1
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
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
    // srl         $s2, $v1, 13
    ctx->r18 = S32(U32(ctx->r3) >> 13);
    // mfhi        $v0
    ctx->r2 = hi;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // srl         $a1, $a1, 1
    ctx->r5 = S32(U32(ctx->r5) >> 1);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // srl         $s1, $v0, 13
    ctx->r17 = S32(U32(ctx->r2) >> 13);
L_800724FC:
    // lb          $a0, -0x14($a2)
    ctx->r4 = MEM_BS(-0X14, ctx->r6);
    // lb          $v0, -0x6($a2)
    ctx->r2 = MEM_BS(-0X6, ctx->r6);
    // nop

    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // jal         0x80072744
    // andi        $a0, $a0, 0x3F
    ctx->r4 = ctx->r4 & 0X3F;
    SpuSetNoiseClock(rdram, ctx);
    goto after_0;
    // andi        $a0, $a0, 0x3F
    ctx->r4 = ctx->r4 & 0X3F;
    after_0:
    // andi        $s0, $s3, 0xFF
    ctx->r16 = ctx->r19 & 0XFF;
    // sll         $v1, $s0, 4
    ctx->r3 = S32(ctx->r16) << 4;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $s1, -0x6BCE($at)
    MEM_H(-0X6BCE, ctx->r1) = ctx->r17;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // lbu         $v0, -0x6BF0($v0)
    ctx->r2 = MEM_BU(-0X6BF0, ctx->r2);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $s2, -0x6BD0($at)
    MEM_H(-0X6BD0, ctx->r1) = ctx->r18;
    // ori         $v0, $v0, 0x3
    ctx->r2 = ctx->r2 | 0X3;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // sb          $v0, -0x6BF0($at)
    MEM_B(-0X6BF0, ctx->r1) = ctx->r2;
    // sltiu       $v0, $s0, 0x10
    ctx->r2 = ctx->r16 < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_80072568
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80072568;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sllv        $a3, $v0, $s0
    ctx->r7 = S32(ctx->r2) << (ctx->r16 & 31);
    // j           L_80072574
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    goto L_80072574;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80072568:
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $v1, $s0, -0x10
    ctx->r3 = ADD32(ctx->r16, -0X10);
    // sllv        $a2, $v0, $v1
    ctx->r6 = S32(ctx->r2) << (ctx->r3 & 31);
L_80072574:
    // andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
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
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // lb          $a0, -0x690C($a0)
    ctx->r4 = MEM_BS(-0X690C, ctx->r4);
    // addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, -0x70FC($at)
    MEM_H(-0X70FC, ctx->r1) = ctx->r3;
    // blez        $a0, L_80072628
    if (SIGNED(ctx->r4) <= 0) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_80072628;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
L_800725B4:
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0xE60($v0)
    ctx->r2 = MEM_W(0XE60, ctx->r2);
    // sllv        $v1, $t0, $a0
    ctx->r3 = S32(ctx->r8) << (ctx->r4 & 31);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_80072608
    if (ctx->r2 != 0) {
        // addiu       $v0, $a1, 0x1
        ctx->r2 = ADD32(ctx->r5, 0X1);
        goto L_80072608;
    }
    // addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // sll         $v0, $a0, 3
    ctx->r2 = S32(ctx->r4) << 3;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v1, -0x70E3($v1)
    ctx->r3 = MEM_BU(-0X70E3, ctx->r3);
    // nop

    // andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $v1, -0x70E3($at)
    MEM_B(-0X70E3, ctx->r1) = ctx->r3;
    // addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
L_80072608:
    // addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
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
    // bne         $v0, $zero, L_800725B4
    if (ctx->r2 != 0) {
        // sll         $v0, $a1, 16
        ctx->r2 = S32(ctx->r5) << 16;
        goto L_800725B4;
    }
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
L_80072628:
    // andi        $v1, $s3, 0xFF
    ctx->r3 = ctx->r19 & 0XFF;
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
    // addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sb          $v1, -0x70E3($at)
    MEM_B(-0X70E3, ctx->r1) = ctx->r3;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lhu         $v1, -0x7110($v1)
    ctx->r3 = MEM_HU(-0X7110, ctx->r3);
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // lhu         $a0, -0x710E($a0)
    ctx->r4 = MEM_HU(-0X710E, ctx->r4);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x6A08($v0)
    ctx->r2 = MEM_HU(-0X6A08, ctx->r2);
    // or          $v1, $v1, $a3
    ctx->r3 = ctx->r3 | ctx->r7;
    // or          $a0, $a0, $a2
    ctx->r4 = ctx->r4 | ctx->r6;
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
    // sh          $a0, -0x710E($at)
    MEM_H(-0X710E, ctx->r1) = ctx->r4;
    // nor         $a0, $zero, $a0
    ctx->r4 = ~(0 | ctx->r4);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v0, -0x6A08($at)
    MEM_H(-0X6A08, ctx->r1) = ctx->r2;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x6A06($v0)
    ctx->r2 = MEM_HU(-0X6A06, ctx->r2);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lbu         $v1, -0x68F4($v1)
    ctx->r3 = MEM_BU(-0X68F4, ctx->r3);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // andi        $v1, $v1, 0x4
    ctx->r3 = ctx->r3 & 0X4;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v0, -0x6A06($at)
    MEM_H(-0X6A06, ctx->r1) = ctx->r2;
    // beq         $v1, $zero, L_800726E8
    if (ctx->r3 == 0) {
        // nor         $v1, $zero, $a3
        ctx->r3 = ~(0 | ctx->r7);
        goto L_800726E8;
    }
    // nor         $v1, $zero, $a3
    ctx->r3 = ~(0 | ctx->r7);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // lhu         $v0, -0x710C($v0)
    ctx->r2 = MEM_HU(-0X710C, ctx->r2);
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lhu         $v1, -0x710A($v1)
    ctx->r3 = MEM_HU(-0X710A, ctx->r3);
    // or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
    // or          $v1, $v1, $a2
    ctx->r3 = ctx->r3 | ctx->r6;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v0, -0x710C($at)
    MEM_H(-0X710C, ctx->r1) = ctx->r2;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // j           L_80072718
    // sh          $v1, -0x710A($at)
    MEM_H(-0X710A, ctx->r1) = ctx->r3;
    goto L_80072718;
    // sh          $v1, -0x710A($at)
    MEM_H(-0X710A, ctx->r1) = ctx->r3;
L_800726E8:
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
    // nor         $v1, $zero, $a2
    ctx->r3 = ~(0 | ctx->r6);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $v0, -0x710A($at)
    MEM_H(-0X710A, ctx->r1) = ctx->r2;
L_80072718:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $a3, -0x7108($at)
    MEM_H(-0X7108, ctx->r1) = ctx->r7;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sh          $a2, -0x7106($at)
    MEM_H(-0X7106, ctx->r1) = ctx->r6;
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
