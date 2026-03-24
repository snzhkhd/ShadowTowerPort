#include "recomp.h"
#include "disable_warnings.h"

void PreviewPickUp(uint8_t* rdram, recomp_context* ctx) 
{
 
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // sw          $ra, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r31;
    // sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(0X0, ctx->r17);
    // addiu       $t0, $s1, 0x30
    ctx->r8 = ADD32(ctx->r17, 0X30);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x7810
    ctx->r2 = ADD32(ctx->r2, 0X7810);
    // addu        $t1, $v1, $v0
    ctx->r9 = ADD32(ctx->r3, ctx->r2);
L_800533AC:

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
    // bne         $a2, $t0, L_800533AC
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_800533AC;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a2, $v0, -0x70D8
    ctx->r6 = ADD32(ctx->r2, -0X70D8);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // addiu       $t2, $t2, -0x6E40
    ctx->r10 = ADD32(ctx->r10, -0X6E40);
    // sb          $v0, 0x218($a2)
    MEM_B(0X218, ctx->r6) = ctx->r2;
    // lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(0X0, ctx->r10);
    // lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(0X4, ctx->r10);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(0X8, ctx->r10);
    // lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(0XC, ctx->r10);
    // lw          $t6, 0x10($t2)
    ctx->r14 = MEM_W(0X10, ctx->r10);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // addiu       $v0, $t1, 0x8
    ctx->r2 = ADD32(ctx->r9, 0X8);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // nop

    // nop

    // .word       0x4A486012                   # INVALID     $s2, $t0, 0x6012 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A486012);
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(0X40, ctx->r29);
    // lw          $v1, 0x248($a2)
    ctx->r3 = MEM_W(0X248, ctx->r6);
    // addiu       $a0, $a2, 0x248
    ctx->r4 = ADD32(ctx->r6, 0X248);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(0X44, ctx->r29);
    // lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(0X4, ctx->r4);
    // lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(0X48, ctx->r29);
    // lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(0X8, ctx->r4);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // lbu         $v1, 0x7($t1)
    ctx->r3 = MEM_BU(0X7, ctx->r9);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_800534CC
    if (ctx->r3 == ctx->r2) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_800534CC;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8005349C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8005349C;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $v1, $zero, L_800534B4
    if (ctx->r3 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_800534B4;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // j           L_8005364C
    // nop

    goto L_8005364C;
    // nop

L_8005349C:
    // beq         $v1, $v0, L_800534E0
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_800534E0;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $v0, L_80053630
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80053630;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // j           L_8005364C
    // nop

    goto L_8005364C;
    // nop

L_800534B4:
    // lhu         $v0, 0x268($a2)
    ctx->r2 = MEM_HU(0X268, ctx->r6);
    // sh          $zero, 0x64($sp)
    MEM_H(0X64, ctx->r29) = 0;
    // sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // j           L_80053648
    // sh          $v0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r2;
    goto L_80053648;
    // sh          $v0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r2;
L_800534CC:
    // sh          $zero, 0x64($sp)
    MEM_H(0X64, ctx->r29) = 0;
    // sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // lhu         $v1, 0x268($a2)
    ctx->r3 = MEM_HU(0X268, ctx->r6);
    // j           L_800534F0
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    goto L_800534F0;
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
L_800534E0:
    // sh          $zero, 0x64($sp)
    MEM_H(0X64, ctx->r29) = 0;
    // sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // lhu         $v1, 0x268($a2)
    ctx->r3 = MEM_HU(0X268, ctx->r6);
    // addiu       $v0, $zero, -0x400
    ctx->r2 = ADD32(0, -0X400);
L_800534F0:
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // j           L_80053648
    // sh          $v0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r2;
    goto L_80053648;
    // sh          $v0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r2;
L_800534FC:
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(0X8, ctx->r17);
    // lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(0XC, ctx->r17);
    // lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(0X10, ctx->r17);
    // lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(0X14, ctx->r17);
    // sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(0X1C, ctx->r29);
    // lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(0X20, ctx->r29);
    // lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(0X24, ctx->r29);
    // sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // lwl         $v0, 0x1B($s1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X1B, ctx->r17);
    // lwr         $v0, 0x18($s1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X18, ctx->r17);
    // lwl         $v1, 0x1F($s1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X1F, ctx->r17);
    // lwr         $v1, 0x1C($s1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X1C, ctx->r17);
    // swl         $v0, 0x63($sp)
    do_swl(rdram, 0X63, ctx->r29, ctx->r2);
    // swr         $v0, 0x60($sp)
    do_swr(rdram, 0X60, ctx->r29, ctx->r2);
    // swl         $v1, 0x67($sp)
    do_swl(rdram, 0X67, ctx->r29, ctx->r3);
    // swr         $v1, 0x64($sp)
    do_swr(rdram, 0X64, ctx->r29, ctx->r3);
    // lwl         $v0, 0x2B($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X2B, ctx->r29);
    // lwr         $v0, 0x28($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X28, ctx->r29);
    // lwl         $v1, 0x2F($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X2F, ctx->r29);
    // lwr         $v1, 0x2C($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X2C, ctx->r29);
    // swl         $v0, 0x6B($sp)
    do_swl(rdram, 0X6B, ctx->r29, ctx->r2);
    // swr         $v0, 0x68($sp)
    do_swr(rdram, 0X68, ctx->r29, ctx->r2);
    // swl         $v1, 0x6F($sp)
    do_swl(rdram, 0X6F, ctx->r29, ctx->r3);
    // swr         $v1, 0x6C($sp)
    do_swr(rdram, 0X6C, ctx->r29, ctx->r3);
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // j           L_800538AC
    // subu        $s0, $v0, $s0
    ctx->r16 = SUB32(ctx->r2, ctx->r16);
    goto L_800538AC;
    // subu        $s0, $v0, $s0
    ctx->r16 = SUB32(ctx->r2, ctx->r16);
L_8005358C:
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(0X8, ctx->r17);
    // lw          $v1, 0xC($s1)
    ctx->r3 = MEM_W(0XC, ctx->r17);
    // lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(0X10, ctx->r17);
    // lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(0X14, ctx->r17);
    // sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // lw          $v1, 0x248($v0)
    ctx->r3 = MEM_W(0X248, ctx->r2);
    // lw          $a0, 0x24C($v0)
    ctx->r4 = MEM_W(0X24C, ctx->r2);
    // lw          $a1, 0x250($v0)
    ctx->r5 = MEM_W(0X250, ctx->r2);
    // lw          $a2, 0x254($v0)
    ctx->r6 = MEM_W(0X254, ctx->r2);
    // sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    // sw          $a1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r5;
    // sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    // lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(0X54, ctx->r29);
    // nop

    // addiu       $v0, $v0, 0x320
    ctx->r2 = ADD32(ctx->r2, 0X320);
    // sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // lwl         $v0, 0x1B($s1)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X1B, ctx->r17);
    // lwr         $v0, 0x18($s1)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X18, ctx->r17);
    // lwl         $v1, 0x1F($s1)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X1F, ctx->r17);
    // lwr         $v1, 0x1C($s1)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X1C, ctx->r17);
    // swl         $v0, 0x63($sp)
    do_swl(rdram, 0X63, ctx->r29, ctx->r2);
    // swr         $v0, 0x60($sp)
    do_swr(rdram, 0X60, ctx->r29, ctx->r2);
    // swl         $v1, 0x67($sp)
    do_swl(rdram, 0X67, ctx->r29, ctx->r3);
    // swr         $v1, 0x64($sp)
    do_swr(rdram, 0X64, ctx->r29, ctx->r3);
    // lwl         $v0, 0x63($sp)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X63, ctx->r29);
    // lwr         $v0, 0x60($sp)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X60, ctx->r29);
    // lwl         $v1, 0x67($sp)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X67, ctx->r29);
    // lwr         $v1, 0x64($sp)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X64, ctx->r29);
    // swl         $v0, 0x6B($sp)
    do_swl(rdram, 0X6B, ctx->r29, ctx->r2);
    // swr         $v0, 0x68($sp)
    do_swr(rdram, 0X68, ctx->r29, ctx->r2);
    // swl         $v1, 0x6F($sp)
    do_swl(rdram, 0X6F, ctx->r29, ctx->r3);
    // swr         $v1, 0x6C($sp)
    do_swr(rdram, 0X6C, ctx->r29, ctx->r3);
    // j           L_800538AC
    // addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
    goto L_800538AC;
    // addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
L_80053630:
    // sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
    // lhu         $v0, 0x268($a2)
    ctx->r2 = MEM_HU(0X268, ctx->r6);
    // addiu       $v1, $zero, 0x400
    ctx->r3 = ADD32(0, 0X400);
    // sh          $v1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r3;
    // addiu       $v0, $v0, -0x100
    ctx->r2 = ADD32(ctx->r2, -0X100);
    // sh          $v0, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r2;
L_80053648:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_8005364C:
    // lhu         $v1, 0x62($sp)
    ctx->r3 = MEM_HU(0X62, ctx->r29);
    // lhu         $v0, -0x6E6E($v0)
    ctx->r2 = MEM_HU(-0X6E6E, ctx->r2);
    // nop

    // addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // lh          $v0, 0x60($sp)
    ctx->r2 = MEM_HS(0X60, ctx->r29);
    // sh          $a0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r4;
    // lh          $v1, 0x18($s1)
    ctx->r3 = MEM_HS(0X18, ctx->r17);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, 0x801
    ctx->r2 = SIGNED(ctx->r2) < 0X801 ? 1 : 0;
    // lhu         $v1, 0x60($sp)
    ctx->r3 = MEM_HU(0X60, ctx->r29);
    // bne         $v0, $zero, L_80053684
    if (ctx->r2 != 0) {
        // addiu       $v0, $v1, -0x1000
        ctx->r2 = ADD32(ctx->r3, -0X1000);
        goto L_80053684;
    }
    // addiu       $v0, $v1, -0x1000
    ctx->r2 = ADD32(ctx->r3, -0X1000);
    // sh          $v0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r2;
L_80053684:
    // lh          $v0, 0x60($sp)
    ctx->r2 = MEM_HS(0X60, ctx->r29);
    // lh          $v1, 0x18($s1)
    ctx->r3 = MEM_HS(0X18, ctx->r17);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, -0x800
    ctx->r2 = SIGNED(ctx->r2) < -0X800 ? 1 : 0;
    // lhu         $v1, 0x60($sp)
    ctx->r3 = MEM_HU(0X60, ctx->r29);
    // beq         $v0, $zero, L_800536A8
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x1000
        ctx->r2 = ADD32(ctx->r3, 0X1000);
        goto L_800536A8;
    }
    // addiu       $v0, $v1, 0x1000
    ctx->r2 = ADD32(ctx->r3, 0X1000);
    // sh          $v0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r2;
L_800536A8:
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // lh          $v1, 0x1A($s1)
    ctx->r3 = MEM_HS(0X1A, ctx->r17);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, 0x801
    ctx->r2 = SIGNED(ctx->r2) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_800536C8
    if (ctx->r2 != 0) {
        // addiu       $v0, $a0, -0x1000
        ctx->r2 = ADD32(ctx->r4, -0X1000);
        goto L_800536C8;
    }
    // addiu       $v0, $a0, -0x1000
    ctx->r2 = ADD32(ctx->r4, -0X1000);
    // sh          $v0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r2;
L_800536C8:
    // lh          $v0, 0x62($sp)
    ctx->r2 = MEM_HS(0X62, ctx->r29);
    // lh          $v1, 0x1A($s1)
    ctx->r3 = MEM_HS(0X1A, ctx->r17);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, -0x800
    ctx->r2 = SIGNED(ctx->r2) < -0X800 ? 1 : 0;
    // lhu         $v1, 0x62($sp)
    ctx->r3 = MEM_HU(0X62, ctx->r29);
    // beq         $v0, $zero, L_800536EC
    if (ctx->r2 == 0) {
        // addiu       $v0, $v1, 0x1000
        ctx->r2 = ADD32(ctx->r3, 0X1000);
        goto L_800536EC;
    }
    // addiu       $v0, $v1, 0x1000
    ctx->r2 = ADD32(ctx->r3, 0X1000);
    // sh          $v0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r2;
L_800536EC:
    // addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
    // lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // lbu         $v0, 0x2D($s1)
    ctx->r2 = MEM_BU(0X2D, ctx->r17);
    // addiu       $s2, $v1, -0x2E80
    ctx->r18 = ADD32(ctx->r3, -0X2E80);
    // addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // sb          $v0, 0x2D($s1)
    MEM_B(0X2D, ctx->r17) = ctx->r2;
L_80053704:
    // bne         $s3, $zero, L_80053724
    if (ctx->r19 != 0) {
        // nop
    
        goto L_80053724;
    }
    // nop

    // lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(0X4, ctx->r18);
    // lhu         $v1, 0x38($s2)
    ctx->r3 = MEM_HU(0X38, ctx->r18);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_800534FC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_800534FC;
    }
    // nop

L_80053724:
    // lhu         $v0, 0x4($s2)
    ctx->r2 = MEM_HU(0X4, ctx->r18);
    // lhu         $v1, 0x36($s2)
    ctx->r3 = MEM_HU(0X36, ctx->r18);
    // nop

    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_8005374C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005374C;
    }
    // nop

    // lbu         $v0, 0x12($s2)
    ctx->r2 = MEM_BU(0X12, ctx->r18);
    // nop

    // beq         $v0, $zero, L_8005358C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8005358C;
    }
    // nop

L_8005374C:
    // lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(0X18, ctx->r29);
    // nop

    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(0X40, ctx->r29);
    // mflo        $a0
    ctx->r4 = lo;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // subu        $a1, $v0, $s0
    ctx->r5 = SUB32(ctx->r2, ctx->r16);
    // mult        $a1, $v1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(0X1C, ctx->r29);
    // nop

    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(0X44, ctx->r29);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(0X20, ctx->r29);
    // nop

    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(0X48, ctx->r29);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // slti        $v0, $s0, 0x9
    ctx->r2 = SIGNED(ctx->r16) < 0X9 ? 1 : 0;
    // bne         $v0, $zero, L_80053824
    if (ctx->r2 != 0) {
        // addiu       $v1, $zero, 0x8
        ctx->r3 = ADD32(0, 0X8);
        goto L_80053824;
    }
    // addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // lhu         $v0, 0x28($sp)
    ctx->r2 = MEM_HU(0X28, ctx->r29);
    // nop

    // sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // lh          $v1, 0x2A($sp)
    ctx->r3 = MEM_HS(0X2A, ctx->r29);
    // addiu       $v0, $s0, -0x8
    ctx->r2 = ADD32(ctx->r16, -0X8);
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lh          $v0, 0x62($sp)
    ctx->r2 = MEM_HS(0X62, ctx->r29);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sh          $v0, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x2C($sp)
    ctx->r2 = MEM_HU(0X2C, ctx->r29);
    // j           L_80053888
    // sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
    goto L_80053888;
    // sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
L_80053824:
    // lh          $v0, 0x28($sp)
    ctx->r2 = MEM_HS(0X28, ctx->r29);
    // nop

    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x60($sp)
    ctx->r2 = MEM_HS(0X60, ctx->r29);
    // subu        $v1, $v1, $s0
    ctx->r3 = SUB32(ctx->r3, ctx->r16);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x62($sp)
    ctx->r2 = MEM_HU(0X62, ctx->r29);
    // nop

    // sh          $v0, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r2;
    // lh          $v0, 0x2C($sp)
    ctx->r2 = MEM_HS(0X2C, ctx->r29);
    // nop

    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x64($sp)
    ctx->r2 = MEM_HS(0X64, ctx->r29);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
L_80053888:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80026AFC
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    DrawScene_80026AFC(rdram, ctx);
    goto after_0;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_0:
    // jal         0x8003C24C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8003C24C(rdram, ctx);
    goto after_1;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_1:
    // blez        $s0, L_80053704
    if (SIGNED(ctx->r16) <= 0) {
        // nop
    
        goto L_80053704;
    }
    // nop

    // j           L_80053704
    // addiu       $s0, $s0, -0x1

    //pickup anim speed
    ctx->r16 = ADD32(ctx->r16, -0X2); //ADD32(ctx->r16, -0X1);
    goto L_80053704;
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_800538AC:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // j           L_80053A0C
    // sh          $zero, -0x2E7C($v0)
    MEM_H(-0X2E7C, ctx->r2) = 0;
    goto L_80053A0C;
    // sh          $zero, -0x2E7C($v0)
    MEM_H(-0X2E7C, ctx->r2) = 0;
L_800538B8:
    // lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(0X40, ctx->r29);
    // nop

    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(0X50, ctx->r29);
    // mflo        $a0
    ctx->r4 = lo;
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // subu        $a1, $v0, $s0
    ctx->r5 = SUB32(ctx->r2, ctx->r16);
    // mult        $a1, $v1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(0X44, ctx->r29);
    // nop

    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(0X54, ctx->r29);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(0X48, ctx->r29);
    // nop

    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(0X58, ctx->r29);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // slti        $v0, $s0, 0x9
    ctx->r2 = SIGNED(ctx->r16) < 0X9 ? 1 : 0;
    // bne         $v0, $zero, L_800539B0
    if (ctx->r2 != 0) {
        // addiu       $v1, $s0, -0x8
        ctx->r3 = ADD32(ctx->r16, -0X8);
        goto L_800539B0;
    }
    // addiu       $v1, $s0, -0x8
    ctx->r3 = ADD32(ctx->r16, -0X8);
    // lh          $v0, 0x60($sp)
    ctx->r2 = MEM_HS(0X60, ctx->r29);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x68($sp)
    ctx->r2 = MEM_HS(0X68, ctx->r29);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // addu        $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x62($sp)
    ctx->r2 = MEM_HU(0X62, ctx->r29);
    // nop

    // sh          $v0, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r2;
    // lh          $v0, 0x64($sp)
    ctx->r2 = MEM_HS(0X64, ctx->r29);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // lh          $v0, 0x6C($sp)
    ctx->r2 = MEM_HS(0X6C, ctx->r29);
    // nop

    // mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // j           L_800539F0
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    goto L_800539F0;
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
L_800539B0:
    // lhu         $v0, 0x68($sp)
    ctx->r2 = MEM_HU(0X68, ctx->r29);
    // nop

    // sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // lh          $v0, 0x62($sp)
    ctx->r2 = MEM_HS(0X62, ctx->r29);
    // nop

    // mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lh          $v1, 0x6A($sp)
    ctx->r3 = MEM_HS(0X6A, ctx->r29);
    // mflo        $a0
    ctx->r4 = lo;
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sh          $v0, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x6C($sp)
    ctx->r2 = MEM_HU(0X6C, ctx->r29);
L_800539F0:
    // nop

    // sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // jal         0x80026AFC
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    DrawScene_80026AFC(rdram, ctx);
    goto after_2;
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_2:
    // jal         0x8003C24C
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    sub_8003C24C(rdram, ctx);
    goto after_3;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_3:
L_80053A0C:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $s0, $v0, L_800538B8
    if (ctx->r16 != ctx->r2) {
        // nop
    
        goto L_800538B8;
    }
    // nop

    // lbu         $v0, 0x2D($s1)
    ctx->r2 = MEM_BU(0X2D, ctx->r17);
    // nop

    // addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // bne         $s2, $zero, L_80053A74
    if (ctx->r18 != 0) {
        // sb          $v0, 0x2D($s1)
        MEM_B(0X2D, ctx->r17) = ctx->r2;
        goto L_80053A74;
    }
    // sb          $v0, 0x2D($s1)
    MEM_B(0X2D, ctx->r17) = ctx->r2;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // addiu       $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
L_80053A3C:
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
    // bne         $a2, $t0, L_80053A3C
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_80053A3C;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // lbu         $v0, 0x23($s1)
    ctx->r2 = MEM_BU(0X23, ctx->r17);
    // j           L_80053A84
    // sb          $v0, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r2;
    goto L_80053A84;
    // sb          $v0, 0x22($s1)
    MEM_B(0X22, ctx->r17) = ctx->r2;
L_80053A74:
    // jal         0x80052D98
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_80052D98(rdram, ctx);
    goto after_4;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
    // jal         0x80052E50
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    sub_80052E50(rdram, ctx);
    goto after_5;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
L_80053A84:
    // lw          $ra, 0x80($sp)
    ctx->r31 = MEM_W(0X80, ctx->r29);
    // lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(0X7C, ctx->r29);
    // lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(0X78, ctx->r29);
    // lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(0X74, ctx->r29);
    // lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(0X70, ctx->r29);
    // addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // jr          $ra
    // nop

    return;
    // nop

;}
