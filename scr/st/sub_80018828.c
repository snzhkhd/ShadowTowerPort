#include "recomp.h"
#include "disable_warnings.h"

void sub_80018828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // addu        $s7, $a2, $zero
    ctx->r23 = ADD32(ctx->r6, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lw          $v1, 0x8C($s0)
    ctx->r3 = MEM_W(0X8C, ctx->r16);
    // lbu         $a0, 0x6DFC($v0)
    ctx->r4 = MEM_BU(0X6DFC, ctx->r2);
    // lw          $s6, 0x10($s0)
    ctx->r22 = MEM_W(0X10, ctx->r16);
    // addu        $v1, $v1, $s1
    ctx->r3 = ADD32(ctx->r3, ctx->r17);
    // andi        $v0, $a0, 0x2
    ctx->r2 = ctx->r4 & 0X2;
    // beq         $v0, $zero, L_800188A0
    if (ctx->r2 == 0) {
        // sw          $v1, 0x8C($s0)
        MEM_W(0X8C, ctx->r16) = ctx->r3;
        goto L_800188A0;
    }
    // sw          $v1, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r3;
    // lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // j           L_800188B0
    // addiu       $s3, $v0, -0x785C
    ctx->r19 = ADD32(ctx->r2, -0X785C);
    goto L_800188B0;
    // addiu       $s3, $v0, -0x785C
    ctx->r19 = ADD32(ctx->r2, -0X785C);
L_800188A0:
    // andi        $v0, $a0, 0x4
    ctx->r2 = ctx->r4 & 0X4;
    // beq         $v0, $zero, L_800188B0
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8002
        ctx->r2 = S32(0X8002 << 16);
        goto L_800188B0;
    }
    // lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // addiu       $s3, $v0, -0x781C
    ctx->r19 = ADD32(ctx->r2, -0X781C);
L_800188B0:
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // beq         $v0, $zero, L_80018AB4
    if (ctx->r2 == 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_80018AB4;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // andi        $v0, $a3, 0x2
    ctx->r2 = ctx->r7 & 0X2;
    // ori         $s5, $v0, 0x2C
    ctx->r21 = ctx->r2 | 0X2C;
    // lui         $v0, 0x60
    ctx->r2 = S32(0X60 << 16);
    // and         $s4, $a3, $v0
    ctx->r20 = ctx->r7 & ctx->r2;
L_800188CC:
    // lhu         $v1, 0x12($t0)
    ctx->r3 = MEM_HU(0X12, ctx->r8);
    // lw          $v0, 0x40($s0)
    ctx->r2 = MEM_W(0X40, ctx->r16);
    // lhu         $a0, 0x16($t0)
    ctx->r4 = MEM_HU(0X16, ctx->r8);
    // addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // addu        $t3, $v0, $a0
    ctx->r11 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v1, 0x14($t0)
    ctx->r3 = MEM_HU(0X14, ctx->r8);
    // lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(0X0, ctx->r12);
    // lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(0X0, ctx->r11);
    // addu        $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(0X0, ctx->r10);
    // mtc2        $t5, $12
    gte_mtc2(ctx, 13, 12);
    // mtc2        $t7, $14
    gte_mtc2(ctx, 15, 14);
    // mtc2        $t6, $13
    gte_mtc2(ctx, 14, 13);
    // addiu       $s2, $t0, 0x1C
    ctx->r18 = ADD32(ctx->r8, 0X1C);
    // nop

    // nop

    // .word       0x4B400006                   # INVALID     $k0, $zero, 0x6 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B400006);
    // lbu         $v0, 0xB($t0)
    ctx->r2 = MEM_BU(0XB, ctx->r8);
    // nop

    // or          $v0, $v0, $s5
    ctx->r2 = ctx->r2 | ctx->r21;
    // sb          $v0, 0x63($s0)
    MEM_B(0X63, ctx->r16) = ctx->r2;
    // addiu       $v0, $s0, 0x70
    ctx->r2 = ADD32(ctx->r16, 0X70);
    // swc2        $24, 0x0($v0)
    gte_swc2(rdram, ctx, 24, 2, 0);
    // lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(0X70, ctx->r16);
    // nop

    // blez        $v0, L_80018AA4
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80018AA4;
    }
    // nop

    // lbu         $v1, 0xA($t0)
    ctx->r3 = MEM_BU(0XA, ctx->r8);
    // lhu         $a2, 0x18($t0)
    ctx->r6 = MEM_HU(0X18, ctx->r8);
    // lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(0X40, ctx->r16);
    // lh          $v0, 0x4($t4)
    ctx->r2 = MEM_HS(0X4, ctx->r12);
    // lh          $a0, 0x4($t2)
    ctx->r4 = MEM_HS(0X4, ctx->r10);
    // sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3) << 24;
    // sra         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3) >> 24;
    // addu        $a3, $a1, $a2
    ctx->r7 = ADD32(ctx->r5, ctx->r6);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lh          $a0, 0x4($t3)
    ctx->r4 = MEM_HS(0X4, ctx->r11);
    // lh          $a1, 0x4($a3)
    ctx->r5 = MEM_HS(0X4, ctx->r7);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sra         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) >> 7;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // sra         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3) >> 16;
    // slt         $v0, $t1, $v0
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80018AA4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80018AA4;
    }
    // nop

    // lw          $v0, 0x80($s0)
    ctx->r2 = MEM_W(0X80, ctx->r16);
    // nop

    // slt         $v0, $v0, $t1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // beq         $v0, $zero, L_80018AA4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80018AA4;
    }
    // nop

    // lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(0X10, ctx->r16);
    // nop

    // addiu       $v0, $a2, 0x28
    ctx->r2 = ADD32(ctx->r6, 0X28);
    // sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // swc2        $12, 0x8($a2)
    gte_swc2(rdram, ctx, 12, 6, 8);
    // swc2        $13, 0x10($a2)
    gte_swc2(rdram, ctx, 13, 6, 16);
    // swc2        $14, 0x18($a2)
    gte_swc2(rdram, ctx, 14, 6, 24);
    // lhu         $v1, 0x10($t0)
    ctx->r3 = MEM_HU(0X10, ctx->r8);
    // lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(0X24, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // nop

    // sw          $v0, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r2;
    // addiu       $v0, $s0, 0x60
    ctx->r2 = ADD32(ctx->r16, 0X60);
    // lwc2        $6, 0x0($v0)
    gte_lwc2(rdram, ctx, 6, 2, 0);
    // lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(0X0, ctx->r8);
    // nop

    // sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // lh          $v0, 0x6($t4)
    ctx->r2 = MEM_HS(0X6, ctx->r12);
    // lh          $v1, 0x6($t2)
    ctx->r3 = MEM_HS(0X6, ctx->r10);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x6($t3)
    ctx->r3 = MEM_HS(0X6, ctx->r11);
    // lh          $a0, 0x6($a3)
    ctx->r4 = MEM_HS(0X6, ctx->r7);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // mtc2        $v0, $8
    gte_mtc2(ctx, 2, 8);
    // lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(0X4, ctx->r8);
    // nop

    // or          $v0, $v0, $s4
    ctx->r2 = ctx->r2 | ctx->r20;
    // sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // .word       0x4AE80413                   # INVALID     $s7, $t0, 0x413 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4AE80413);
    // lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // sll         $a0, $t1, 2
    ctx->r4 = S32(ctx->r9) << 2;
    // lhu         $v0, 0x8($t0)
    ctx->r2 = MEM_HU(0X8, ctx->r8);
    // addu        $a0, $a0, $s7
    ctx->r4 = ADD32(ctx->r4, ctx->r23);
    // sh          $v0, 0x1C($a2)
    MEM_H(0X1C, ctx->r6) = ctx->r2;
    // lhu         $v0, 0xC($t0)
    ctx->r2 = MEM_HU(0XC, ctx->r8);
    // ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // sh          $v0, 0x24($a2)
    MEM_H(0X24, ctx->r6) = ctx->r2;
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // lui         $v0, 0x900
    ctx->r2 = S32(0X900 << 16);
    // and         $v1, $v1, $a1
    ctx->r3 = ctx->r3 & ctx->r5;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // and         $a1, $a2, $a1
    ctx->r5 = ctx->r6 & ctx->r5;
    // sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    // swc2        $22, 0x0($a0)
    gte_swc2(rdram, ctx, 22, 4, 0);
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0x6DFC($v0)
    ctx->r2 = MEM_BU(0X6DFC, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x6
    ctx->r2 = ctx->r2 & 0X6;
    // beq         $v0, $zero, L_80018AA8
    if (ctx->r2 == 0) {
        // addu        $t0, $s2, $zero
        ctx->r8 = ADD32(ctx->r18, 0);
        goto L_80018AA8;
    }
    // addu        $t0, $s2, $zero
    ctx->r8 = ADD32(ctx->r18, 0);
    // jalr        $s3
    // nop

    LOOKUP_FUNC(ctx->r19)(rdram, ctx);
    goto after_0;
    // nop

    after_0:
L_80018AA4:
    // addu        $t0, $s2, $zero
    ctx->r8 = ADD32(ctx->r18, 0);
L_80018AA8:
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // bne         $v0, $zero, L_800188CC
    if (ctx->r2 != 0) {
        // addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_800188CC;
    }
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80018AB4:
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(0X10, ctx->r16);
    // ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // subu        $a0, $a0, $s6
    ctx->r4 = SUB32(ctx->r4, ctx->r22);
    // sra         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) >> 2;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sw          $t0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r8;
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // lw          $v0, 0x90($s0)
    ctx->r2 = MEM_W(0X90, ctx->r16);
    // mfhi        $t5
    ctx->r13 = hi;
    // sra         $v1, $t5, 2
    ctx->r3 = S32(ctx->r13) >> 2;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r2;
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(0X2C, ctx->r29);
    // lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
