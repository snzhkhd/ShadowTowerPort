#include "recomp.h"
#include "disable_warnings.h"

void sub_8001A038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x388
    ctx->r29 = ADD32(ctx->r29, -0X388);
    // sw          $s6, 0x378($sp)
    MEM_W(0X378, ctx->r29) = ctx->r22;
    // addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x364($sp)
    MEM_W(0X364, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // sw          $s2, 0x368($sp)
    MEM_W(0X368, ctx->r29) = ctx->r18;
    // lui         $s2, 0x1F80
    ctx->r18 = S32(0X1F80 << 16);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $ra, 0x384($sp)
    MEM_W(0X384, ctx->r29) = ctx->r31;
    // sw          $fp, 0x380($sp)
    MEM_W(0X380, ctx->r29) = ctx->r30;
    // sw          $s7, 0x37C($sp)
    MEM_W(0X37C, ctx->r29) = ctx->r23;
    // sw          $s5, 0x374($sp)
    MEM_W(0X374, ctx->r29) = ctx->r21;
    // sw          $s4, 0x370($sp)
    MEM_W(0X370, ctx->r29) = ctx->r20;
    // sw          $s3, 0x36C($sp)
    MEM_W(0X36C, ctx->r29) = ctx->r19;
    // sw          $s0, 0x360($sp)
    MEM_W(0X360, ctx->r29) = ctx->r16;
    // sw          $a2, 0x390($sp)
    MEM_W(0X390, ctx->r29) = ctx->r6;
    // sw          $a3, 0x394($sp)
    MEM_W(0X394, ctx->r29) = ctx->r7;
    // sw          $zero, 0x350($sp)
    MEM_W(0X350, ctx->r29) = 0;
    // lw          $v1, 0x8C($s2)
    ctx->r3 = MEM_W(0X8C, ctx->r18);
    // lbu         $a0, 0x6DFC($v0)
    ctx->r4 = MEM_BU(0X6DFC, ctx->r2);
    // lw          $t0, 0x10($s2)
    ctx->r8 = MEM_W(0X10, ctx->r18);
    // addu        $v1, $v1, $s6
    ctx->r3 = ADD32(ctx->r3, ctx->r22);
    // andi        $v0, $a0, 0x2
    ctx->r2 = ctx->r4 & 0X2;
    // sw          $v1, 0x8C($s2)
    MEM_W(0X8C, ctx->r18) = ctx->r3;
    // beq         $v0, $zero, L_8001A0BC
    if (ctx->r2 == 0) {
        // sw          $t0, 0x348($sp)
        MEM_W(0X348, ctx->r29) = ctx->r8;
        goto L_8001A0BC;
    }
    // sw          $t0, 0x348($sp)
    MEM_W(0X348, ctx->r29) = ctx->r8;
    // lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // j           L_8001A0CC
    // addiu       $v0, $v0, -0x604C
    ctx->r2 = ADD32(ctx->r2, -0X604C);
    goto L_8001A0CC;
    // addiu       $v0, $v0, -0x604C
    ctx->r2 = ADD32(ctx->r2, -0X604C);
L_8001A0BC:
    // andi        $v0, $a0, 0x4
    ctx->r2 = ctx->r4 & 0X4;
    // beq         $v0, $zero, L_8001A0D0
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8002
        ctx->r2 = S32(0X8002 << 16);
        goto L_8001A0D0;
    }
    // lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // addiu       $v0, $v0, -0x600C
    ctx->r2 = ADD32(ctx->r2, -0X600C);
L_8001A0CC:
    // sw          $v0, 0x350($sp)
    MEM_W(0X350, ctx->r29) = ctx->r2;
L_8001A0D0:
    // addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
    // beq         $v0, $zero, L_8001A600
    if (ctx->r2 == 0) {
        // addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
        goto L_8001A600;
    }
    // addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // lui         $t1, 0x5555
    ctx->r9 = S32(0X5555 << 16);
    // lw          $t2, 0x394($sp)
    ctx->r10 = MEM_W(0X394, ctx->r29);
    // ori         $t1, $t1, 0x5556
    ctx->r9 = ctx->r9 | 0X5556;
    // sw          $t1, 0x354($sp)
    MEM_W(0X354, ctx->r29) = ctx->r9;
    // sra         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10) >> 16;
    // andi        $v0, $v0, 0x60
    ctx->r2 = ctx->r2 & 0X60;
    // sw          $v0, 0x358($sp)
    MEM_W(0X358, ctx->r29) = ctx->r2;
    // lui         $v0, 0x60
    ctx->r2 = S32(0X60 << 16);
    // and         $fp, $t2, $v0
    ctx->r30 = ctx->r10 & ctx->r2;
L_8001A100:
    // lhu         $v1, 0xE($s1)
    ctx->r3 = MEM_HU(0XE, ctx->r17);
    // lw          $v0, 0x40($s2)
    ctx->r2 = MEM_W(0X40, ctx->r18);
    // lhu         $a0, 0x12($s1)
    ctx->r4 = MEM_HU(0X12, ctx->r17);
    // addu        $s3, $v0, $v1
    ctx->r19 = ADD32(ctx->r2, ctx->r3);
    // addu        $s5, $v0, $a0
    ctx->r21 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v1, 0x10($s1)
    ctx->r3 = MEM_HU(0X10, ctx->r17);
    // lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(0X0, ctx->r19);
    // lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(0X0, ctx->r21);
    // addu        $s4, $v0, $v1
    ctx->r20 = ADD32(ctx->r2, ctx->r3);
    // lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(0X0, ctx->r20);
    // mtc2        $t0, $12
    gte_mtc2(ctx, 8, 12);
    // mtc2        $t2, $14
    gte_mtc2(ctx, 10, 14);
    // mtc2        $t1, $13
    gte_mtc2(ctx, 9, 13);
    // addiu       $t0, $s1, 0x14
    ctx->r8 = ADD32(ctx->r17, 0X14);
    // sw          $t0, 0x34C($sp)
    MEM_W(0X34C, ctx->r29) = ctx->r8;
    // nop

    // nop

    // .word       0x4B400006                   # INVALID     $k0, $zero, 0x6 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B400006);
    // lw          $t1, 0x394($sp)
    ctx->r9 = MEM_W(0X394, ctx->r29);
    // lbu         $v1, 0xB($s1)
    ctx->r3 = MEM_BU(0XB, ctx->r17);
    // andi        $v0, $t1, 0x2
    ctx->r2 = ctx->r9 & 0X2;
    // ori         $v0, $v0, 0x24
    ctx->r2 = ctx->r2 | 0X24;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // addiu       $v0, $s2, 0x70
    ctx->r2 = ADD32(ctx->r18, 0X70);
    // sb          $v1, 0x63($s2)
    MEM_B(0X63, ctx->r18) = ctx->r3;
    // swc2        $24, 0x0($v0)
    gte_swc2(rdram, ctx, 24, 2, 0);
    // lw          $a1, 0x70($s2)
    ctx->r5 = MEM_W(0X70, ctx->r18);
    // nop

    // blez        $a1, L_8001A5F0
    if (SIGNED(ctx->r5) <= 0) {
        // nop
    
        goto L_8001A5F0;
    }
    // nop

    // lh          $v1, 0x4($s3)
    ctx->r3 = MEM_HS(0X4, ctx->r19);
    // lh          $v0, 0x4($s4)
    ctx->r2 = MEM_HS(0X4, ctx->r20);
    // lh          $a0, 0x4($s5)
    ctx->r4 = MEM_HS(0X4, ctx->r21);
    // lw          $t2, 0x354($sp)
    ctx->r10 = MEM_W(0X354, ctx->r29);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sra         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) >> 5;
    // mult        $v0, $t2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lbu         $v0, 0xA($s1)
    ctx->r2 = MEM_BU(0XA, ctx->r17);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // mfhi        $t0
    ctx->r8 = hi;
    // subu        $v1, $t0, $v1
    ctx->r3 = SUB32(ctx->r8, ctx->r3);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(0X4, ctx->r18);
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // slt         $v1, $a0, $v1
    ctx->r3 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v1, $zero, L_8001A5F0
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8001A5F0;
    }
    // nop

    // lw          $v0, 0x80($s2)
    ctx->r2 = MEM_W(0X80, ctx->r18);
    // nop

    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_8001A5F0
    if (ctx->r2 == 0) {
        // slti        $v0, $a1, 0x4001
        ctx->r2 = SIGNED(ctx->r5) < 0X4001 ? 1 : 0;
        goto L_8001A5F0;
    }
    // slti        $v0, $a1, 0x4001
    ctx->r2 = SIGNED(ctx->r5) < 0X4001 ? 1 : 0;
    // bne         $v0, $zero, L_8001A4A4
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8001A4A4;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v1, 0x70($s2)
    ctx->r3 = MEM_W(0X70, ctx->r18);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8001A220
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8001A220;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // lw          $v1, 0x70($s2)
    ctx->r3 = MEM_W(0X70, ctx->r18);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8001A220
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_8001A220;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_8001A220:
    // lhu         $v1, 0xC($s1)
    ctx->r3 = MEM_HU(0XC, ctx->r17);
    // lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(0X24, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // addiu       $v0, $s2, 0x60
    ctx->r2 = ADD32(ctx->r18, 0X60);
    // lwc2        $6, 0x0($v0)
    gte_lwc2(rdram, ctx, 6, 2, 0);
    // lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // addiu       $t1, $t1, 0x5090
    ctx->r9 = ADD32(ctx->r9, 0X5090);
    // lbu         $v0, 0x6DFC($t1)
    ctx->r2 = MEM_BU(0X6DFC, ctx->r9);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // bne         $v0, $zero, L_8001A300
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001A300;
    }
    // nop

    // lh          $v0, 0x6($s3)
    ctx->r2 = MEM_HS(0X6, ctx->r19);
    // lh          $v1, 0x6($s4)
    ctx->r3 = MEM_HS(0X6, ctx->r20);
    // lh          $a0, 0x6($s5)
    ctx->r4 = MEM_HS(0X6, ctx->r21);
    // lw          $t2, 0x354($sp)
    ctx->r10 = MEM_W(0X354, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // mult        $v0, $t2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t0
    ctx->r8 = hi;
    // subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // mtc2        $v0, $8
    gte_mtc2(ctx, 2, 8);
    // nop

    // nop

    // .word       0x4AE80413                   # INVALID     $s7, $t0, 0x413 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AE80413);
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // lhu         $v1, 0x98($s2)
    ctx->r3 = MEM_HU(0X98, ctx->r18);
    // lw          $t1, 0x358($sp)
    ctx->r9 = MEM_W(0X358, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // or          $v0, $v0, $t1
    ctx->r2 = ctx->r2 | ctx->r9;
    // sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // swc2        $22, 0x0($a0)
    gte_swc2(rdram, ctx, 22, 4, 0);
    // lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // addiu       $t2, $t2, 0x5090
    ctx->r10 = ADD32(ctx->r10, 0X5090);
    // lbu         $v0, 0x6DFC($t2)
    ctx->r2 = MEM_BU(0X6DFC, ctx->r10);
    // nop

    // andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // beq         $v0, $zero, L_8001A33C
    if (ctx->r2 == 0) {
        // sll         $v0, $s7, 16
        ctx->r2 = S32(ctx->r23) << 16;
        goto L_8001A33C;
    }
    // sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23) << 16;
    // lw          $t0, 0x350($sp)
    ctx->r8 = MEM_W(0X350, ctx->r29);
    // nop

    // jalr        $t0
    // nop

    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // j           L_8001A33C
    // sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23) << 16;
    goto L_8001A33C;
    // sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23) << 16;
L_8001A300:
    // nop

    // nop

    // .word       0x4B08041B                   # INVALID     $t8, $t0, 0x41B # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B08041B);
    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // lhu         $v1, 0x98($s2)
    ctx->r3 = MEM_HU(0X98, ctx->r18);
    // lw          $t1, 0x358($sp)
    ctx->r9 = MEM_W(0X358, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x6($s1)
    ctx->r2 = MEM_HU(0X6, ctx->r17);
    // nop

    // or          $v0, $v0, $t1
    ctx->r2 = ctx->r2 | ctx->r9;
    // sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // swc2        $22, 0x0($v0)
    gte_swc2(rdram, ctx, 22, 2, 0);
    // sll         $v0, $s7, 16
    ctx->r2 = S32(ctx->r23) << 16;
L_8001A33C:
    // lw          $t2, 0x390($sp)
    ctx->r10 = MEM_W(0X390, ctx->r29);
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // addu        $v0, $t2, $v0
    ctx->r2 = ADD32(ctx->r10, ctx->r2);
    // sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // sw          $v0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
    // addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // sw          $v0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r2;
    // lwl         $v0, 0x3($s3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r19);
    // lwr         $v0, 0x0($s3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r19);
    // nop

    // swl         $v0, 0x3B($sp)
    do_swl(rdram, 0X3B, ctx->r29, ctx->r2);
    // swr         $v0, 0x38($sp)
    do_swr(rdram, 0X38, ctx->r29, ctx->r2);
    // lwl         $v0, 0x3($s4)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r20);
    // lwr         $v0, 0x0($s4)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r20);
    // nop

    // swl         $v0, 0x53($sp)
    do_swl(rdram, 0X53, ctx->r29, ctx->r2);
    // swr         $v0, 0x50($sp)
    do_swr(rdram, 0X50, ctx->r29, ctx->r2);
    // lwl         $v0, 0x3($s5)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r21);
    // lwr         $v0, 0x0($s5)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r21);
    // nop

    // swl         $v0, 0x6B($sp)
    do_swl(rdram, 0X6B, ctx->r29, ctx->r2);
    // swr         $v0, 0x68($sp)
    do_swr(rdram, 0X68, ctx->r29, ctx->r2);
    // lh          $v0, 0x4($s3)
    ctx->r2 = MEM_HS(0X4, ctx->r19);
    // nop

    // sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // lh          $v0, 0x4($s4)
    ctx->r2 = MEM_HS(0X4, ctx->r20);
    // nop

    // sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // lh          $v0, 0x4($s5)
    ctx->r2 = MEM_HS(0X4, ctx->r21);
    // nop

    // sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // lhu         $v1, 0xE($s1)
    ctx->r3 = MEM_HU(0XE, ctx->r17);
    // lw          $v0, 0x48($s2)
    ctx->r2 = MEM_W(0X48, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r3);
    // swr         $v1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r3);
    // swl         $a0, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r4);
    // swr         $a0, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r4);
    // lhu         $v1, 0x10($s1)
    ctx->r3 = MEM_HU(0X10, ctx->r17);
    // lw          $v0, 0x48($s2)
    ctx->r2 = MEM_W(0X48, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x43($sp)
    do_swl(rdram, 0X43, ctx->r29, ctx->r3);
    // swr         $v1, 0x40($sp)
    do_swr(rdram, 0X40, ctx->r29, ctx->r3);
    // swl         $a0, 0x47($sp)
    do_swl(rdram, 0X47, ctx->r29, ctx->r4);
    // swr         $a0, 0x44($sp)
    do_swr(rdram, 0X44, ctx->r29, ctx->r4);
    // lhu         $v1, 0x12($s1)
    ctx->r3 = MEM_HU(0X12, ctx->r17);
    // lw          $v0, 0x48($s2)
    ctx->r2 = MEM_W(0X48, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x5B($sp)
    do_swl(rdram, 0X5B, ctx->r29, ctx->r3);
    // swr         $v1, 0x58($sp)
    do_swr(rdram, 0X58, ctx->r29, ctx->r3);
    // swl         $a0, 0x5F($sp)
    do_swl(rdram, 0X5F, ctx->r29, ctx->r4);
    // swr         $a0, 0x5C($sp)
    do_swr(rdram, 0X5C, ctx->r29, ctx->r4);
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // or          $v0, $v0, $fp
    ctx->r2 = ctx->r2 | ctx->r30;
    // sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(0X8, ctx->r17);
    // nop

    // sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(0X10, ctx->r18);
    // jal         0x80075AC4
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    RCpolyFT3(rdram, ctx);
    goto after_1;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_1:
    // lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(0X14, ctx->r18);
    // nop

    // sltu        $v1, $v1, $v0
    ctx->r3 = ctx->r3 < ctx->r2 ? 1 : 0;
    // bne         $v1, $zero, L_8001A634
    if (ctx->r3 != 0) {
        // sw          $v0, 0x10($s2)
        MEM_W(0X10, ctx->r18) = ctx->r2;
        goto L_8001A634;
    }
    // sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // j           L_8001A5F0
    // nop

    goto L_8001A5F0;
    // nop

L_8001A4A4:
    // lw          $s0, 0x10($s2)
    ctx->r16 = MEM_W(0X10, ctx->r18);
    // nop

    // addiu       $v0, $s0, 0x20
    ctx->r2 = ADD32(ctx->r16, 0X20);
    // sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // swc2        $12, 0x8($s0)
    gte_swc2(rdram, ctx, 12, 16, 8);
    // swc2        $13, 0x10($s0)
    gte_swc2(rdram, ctx, 13, 16, 16);
    // swc2        $14, 0x18($s0)
    gte_swc2(rdram, ctx, 14, 16, 24);
    // lhu         $v1, 0xC($s1)
    ctx->r3 = MEM_HU(0XC, ctx->r17);
    // lw          $v0, 0x24($s2)
    ctx->r2 = MEM_W(0X24, ctx->r18);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // addiu       $v0, $s2, 0x60
    ctx->r2 = ADD32(ctx->r18, 0X60);
    // lwc2        $6, 0x0($v0)
    gte_lwc2(rdram, ctx, 6, 2, 0);
    // lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // addiu       $t0, $t0, 0x5090
    ctx->r8 = ADD32(ctx->r8, 0X5090);
    // lbu         $v0, 0x6DFC($t0)
    ctx->r2 = MEM_BU(0X6DFC, ctx->r8);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // bne         $v0, $zero, L_8001A58C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001A58C;
    }
    // nop

    // lh          $v0, 0x6($s3)
    ctx->r2 = MEM_HS(0X6, ctx->r19);
    // lh          $v1, 0x6($s4)
    ctx->r3 = MEM_HS(0X6, ctx->r20);
    // lh          $a0, 0x6($s5)
    ctx->r4 = MEM_HS(0X6, ctx->r21);
    // lw          $t1, 0x354($sp)
    ctx->r9 = MEM_W(0X354, ctx->r29);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // mult        $v0, $t1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // mfhi        $t2
    ctx->r10 = hi;
    // subu        $v0, $t2, $v0
    ctx->r2 = SUB32(ctx->r10, ctx->r2);
    // mtc2        $v0, $8
    gte_mtc2(ctx, 2, 8);
    // nop

    // nop

    // .word       0x4AE80413                   # INVALID     $s7, $t0, 0x413 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AE80413);
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // or          $v0, $v0, $fp
    ctx->r2 = ctx->r2 | ctx->r30;
    // sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // swc2        $22, 0x0($a0)
    gte_swc2(rdram, ctx, 22, 4, 0);
    // lbu         $v0, 0x6DFC($t0)
    ctx->r2 = MEM_BU(0X6DFC, ctx->r8);
    // nop

    // andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // beq         $v0, $zero, L_8001A5C0
    if (ctx->r2 == 0) {
        // lui         $a1, 0xFF
        ctx->r5 = S32(0XFF << 16);
        goto L_8001A5C0;
    }
    // lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // lw          $t0, 0x350($sp)
    ctx->r8 = MEM_W(0X350, ctx->r29);
    // nop

    // jalr        $t0
    // nop

    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // j           L_8001A5C0
    // lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    goto L_8001A5C0;
    // lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
L_8001A58C:
    // nop

    // nop

    // .word       0x4B08041B                   # INVALID     $t8, $t0, 0x41B # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B08041B);
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // or          $v0, $v0, $fp
    ctx->r2 = ctx->r2 | ctx->r30;
    // sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(0X8, ctx->r17);
    // nop

    // sh          $v0, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r2;
    // addiu       $v0, $s0, 0x4
    ctx->r2 = ADD32(ctx->r16, 0X4);
    // swc2        $22, 0x0($v0)
    gte_swc2(rdram, ctx, 22, 2, 0);
    // lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
L_8001A5C0:
    // sll         $a0, $s7, 16
    ctx->r4 = S32(ctx->r23) << 16;
    // sra         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4) >> 14;
    // lw          $t1, 0x390($sp)
    ctx->r9 = MEM_W(0X390, ctx->r29);
    // ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // lui         $v0, 0x700
    ctx->r2 = S32(0X700 << 16);
    // and         $v1, $v1, $a1
    ctx->r3 = ctx->r3 & ctx->r5;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // and         $a1, $s0, $a1
    ctx->r5 = ctx->r16 & ctx->r5;
    // sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_8001A5F0:
    // lw          $s1, 0x34C($sp)
    ctx->r17 = MEM_W(0X34C, ctx->r29);
    // addu        $v0, $s6, $zero
    ctx->r2 = ADD32(ctx->r22, 0);
    // bne         $v0, $zero, L_8001A100
    if (ctx->r2 != 0) {
        // addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
        goto L_8001A100;
    }
    // addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
L_8001A600:
    // lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(0X10, ctx->r18);
    // sw          $s1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r17;
    // lw          $t2, 0x348($sp)
    ctx->r10 = MEM_W(0X348, ctx->r29);
    // nop

    // subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // sra         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) >> 2;
    // bgez        $v1, L_8001A624
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8001A624;
    }
    // nop

    // addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
L_8001A624:
    // lw          $v0, 0x90($s2)
    ctx->r2 = MEM_W(0X90, ctx->r18);
    // sra         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) >> 3;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x90($s2)
    MEM_W(0X90, ctx->r18) = ctx->r2;
L_8001A634:
    // lw          $ra, 0x384($sp)
    ctx->r31 = MEM_W(0X384, ctx->r29);
    // lw          $fp, 0x380($sp)
    ctx->r30 = MEM_W(0X380, ctx->r29);
    // lw          $s7, 0x37C($sp)
    ctx->r23 = MEM_W(0X37C, ctx->r29);
    // lw          $s6, 0x378($sp)
    ctx->r22 = MEM_W(0X378, ctx->r29);
    // lw          $s5, 0x374($sp)
    ctx->r21 = MEM_W(0X374, ctx->r29);
    // lw          $s4, 0x370($sp)
    ctx->r20 = MEM_W(0X370, ctx->r29);
    // lw          $s3, 0x36C($sp)
    ctx->r19 = MEM_W(0X36C, ctx->r29);
    // lw          $s2, 0x368($sp)
    ctx->r18 = MEM_W(0X368, ctx->r29);
    // lw          $s1, 0x364($sp)
    ctx->r17 = MEM_W(0X364, ctx->r29);
    // lw          $s0, 0x360($sp)
    ctx->r16 = MEM_W(0X360, ctx->r29);
    // addiu       $sp, $sp, 0x388
    ctx->r29 = ADD32(ctx->r29, 0X388);
    // jr          $ra
    // nop

    return;
    // nop

;}
