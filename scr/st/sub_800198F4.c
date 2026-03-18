#include "recomp.h"
#include "disable_warnings.h"

void sub_800198F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // addu        $t4, $a0, $zero
    ctx->r12 = ADD32(ctx->r4, 0);
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // lui         $t3, 0x1F80
    ctx->r11 = S32(0X1F80 << 16);
    // addu        $v1, $t4, $zero
    ctx->r3 = ADD32(ctx->r12, 0);
    // sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // lw          $v0, 0x8C($t3)
    ctx->r2 = MEM_W(0X8C, ctx->r11);
    // lw          $t8, 0x10($t3)
    ctx->r24 = MEM_W(0X10, ctx->r11);
    // addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // beq         $v1, $zero, L_80019AE8
    if (ctx->r3 == 0) {
        // sw          $v0, 0x8C($t3)
        MEM_W(0X8C, ctx->r11) = ctx->r2;
        goto L_80019AE8;
    }
    // sw          $v0, 0x8C($t3)
    MEM_W(0X8C, ctx->r11) = ctx->r2;
    // andi        $v0, $a3, 0x2
    ctx->r2 = ctx->r7 & 0X2;
    // ori         $t7, $v0, 0x34
    ctx->r15 = ctx->r2 | 0X34;
    // lui         $v0, 0x60
    ctx->r2 = S32(0X60 << 16);
    // and         $a3, $a3, $v0
    ctx->r7 = ctx->r7 & ctx->r2;
    // lui         $t5, 0xFF
    ctx->r13 = S32(0XFF << 16);
    // ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
L_80019940:
    // lhu         $v1, 0xE($t0)
    ctx->r3 = MEM_HU(0XE, ctx->r8);
    // lw          $v0, 0x40($t3)
    ctx->r2 = MEM_W(0X40, ctx->r11);
    // lhu         $a0, 0x16($t0)
    ctx->r4 = MEM_HU(0X16, ctx->r8);
    // addu        $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v1, 0x12($t0)
    ctx->r3 = MEM_HU(0X12, ctx->r8);
    // lw          $s0, 0x0($t2)
    ctx->r16 = MEM_W(0X0, ctx->r10);
    // lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(0X0, ctx->r4);
    // addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    // lw          $s1, 0x0($t1)
    ctx->r17 = MEM_W(0X0, ctx->r9);
    // mtc2        $s0, $12
    gte_mtc2(ctx, 16, 12);
    // mtc2        $t9, $14
    gte_mtc2(ctx, 25, 14);
    // mtc2        $s1, $13
    gte_mtc2(ctx, 17, 13);
    // addiu       $t6, $t0, 0x18
    ctx->r14 = ADD32(ctx->r8, 0X18);
    // nop

    // nop

    // .word       0x4B400006                   # INVALID     $k0, $zero, 0x6 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B400006);
    // lbu         $v0, 0xB($t0)
    ctx->r2 = MEM_BU(0XB, ctx->r8);
    // nop

    // or          $v0, $v0, $t7
    ctx->r2 = ctx->r2 | ctx->r15;
    // sb          $v0, 0x63($t3)
    MEM_B(0X63, ctx->r11) = ctx->r2;
    // addiu       $v0, $t3, 0x70
    ctx->r2 = ADD32(ctx->r11, 0X70);
    // swc2        $24, 0x0($v0)
    gte_swc2(rdram, ctx, 24, 2, 0);
    // lw          $v0, 0x70($t3)
    ctx->r2 = MEM_W(0X70, ctx->r11);
    // nop

    // blez        $v0, L_80019AD8
    if (SIGNED(ctx->r2) <= 0) {
        // lui         $a1, 0x5555
        ctx->r5 = S32(0X5555 << 16);
        goto L_80019AD8;
    }
    // lui         $a1, 0x5555
    ctx->r5 = S32(0X5555 << 16);
    // ori         $a1, $a1, 0x5556
    ctx->r5 = ctx->r5 | 0X5556;
    // lh          $v1, 0x4($t2)
    ctx->r3 = MEM_HS(0X4, ctx->r10);
    // lh          $v0, 0x4($t1)
    ctx->r2 = MEM_HS(0X4, ctx->r9);
    // lh          $a0, 0x4($a0)
    ctx->r4 = MEM_HS(0X4, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sra         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3) >> 5;
    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lbu         $v0, 0xA($t0)
    ctx->r2 = MEM_BU(0XA, ctx->r8);
    // sra         $v1, $v1, 31
    ctx->r3 = S32(ctx->r3) >> 31;
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // mfhi        $s0
    ctx->r16 = hi;
    // subu        $v1, $s0, $v1
    ctx->r3 = SUB32(ctx->r16, ctx->r3);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lw          $v1, 0x4($t3)
    ctx->r3 = MEM_W(0X4, ctx->r11);
    // sra         $t1, $v0, 16
    ctx->r9 = S32(ctx->r2) >> 16;
    // slt         $v1, $t1, $v1
    ctx->r3 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v1, $zero, L_80019AD8
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80019AD8;
    }
    // nop

    // lw          $v0, 0x80($t3)
    ctx->r2 = MEM_W(0X80, ctx->r11);
    // nop

    // slt         $v0, $v0, $t1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // beq         $v0, $zero, L_80019AD8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80019AD8;
    }
    // nop

    // lw          $s1, 0x10($t3)
    ctx->r17 = MEM_W(0X10, ctx->r11);
    // nop

    // swc2        $12, 0x8($s1)
    gte_swc2(rdram, ctx, 12, 17, 8);
    // swc2        $13, 0x14($s1)
    gte_swc2(rdram, ctx, 13, 17, 20);
    // swc2        $14, 0x20($s1)
    gte_swc2(rdram, ctx, 14, 17, 32);
    // lhu         $a1, 0xC($t0)
    ctx->r5 = MEM_HU(0XC, ctx->r8);
    // lw          $v0, 0x24($t3)
    ctx->r2 = MEM_W(0X24, ctx->r11);
    // lhu         $v1, 0x10($t0)
    ctx->r3 = MEM_HU(0X10, ctx->r8);
    // lhu         $a0, 0x14($t0)
    ctx->r4 = MEM_HU(0X14, ctx->r8);
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lwc2        $0, 0x0($a1)
    gte_lwc2(rdram, ctx, 0, 5, 0);
    // lwc2        $1, 0x4($a1)
    gte_lwc2(rdram, ctx, 1, 5, 4);
    // lwc2        $2, 0x0($v1)
    gte_lwc2(rdram, ctx, 2, 3, 0);
    // lwc2        $3, 0x4($v1)
    gte_lwc2(rdram, ctx, 3, 3, 4);
    // lwc2        $4, 0x0($v0)
    gte_lwc2(rdram, ctx, 4, 2, 0);
    // lwc2        $5, 0x4($v0)
    gte_lwc2(rdram, ctx, 5, 2, 4);
    // lw          $a0, 0x10($t3)
    ctx->r4 = MEM_W(0X10, ctx->r11);
    // nop

    // addiu       $v0, $a0, 0x28
    ctx->r2 = ADD32(ctx->r4, 0X28);
    // sw          $v0, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r2;
    // lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(0X0, ctx->r8);
    // nop

    // sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // addiu       $v0, $t3, 0x60
    ctx->r2 = ADD32(ctx->r11, 0X60);
    // lwc2        $6, 0x0($v0)
    gte_lwc2(rdram, ctx, 6, 2, 0);
    // lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(0X4, ctx->r8);
    // nop

    // or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
    // sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // .word       0x4B18043F                   # INVALID     $t8, $t8, 0x43F # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B18043F);
    // sll         $a1, $t1, 2
    ctx->r5 = S32(ctx->r9) << 2;
    // lhu         $v0, 0x8($t0)
    ctx->r2 = MEM_HU(0X8, ctx->r8);
    // addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // sh          $v0, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r2;
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // lui         $v1, 0x900
    ctx->r3 = S32(0X900 << 16);
    // and         $v0, $v0, $t5
    ctx->r2 = ctx->r2 & ctx->r13;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // and         $v0, $a0, $t5
    ctx->r2 = ctx->r4 & ctx->r13;
    // addiu       $v1, $a0, 0x4
    ctx->r3 = ADD32(ctx->r4, 0X4);
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // swc2        $20, 0x0($v1)
    gte_swc2(rdram, ctx, 20, 3, 0);
    // swc2        $21, 0x0($v0)
    gte_swc2(rdram, ctx, 21, 2, 0);
    // swc2        $22, 0x0($a0)
    gte_swc2(rdram, ctx, 22, 4, 0);
L_80019AD8:
    // addu        $t0, $t6, $zero
    ctx->r8 = ADD32(ctx->r14, 0);
    // addu        $v0, $t4, $zero
    ctx->r2 = ADD32(ctx->r12, 0);
    // bne         $v0, $zero, L_80019940
    if (ctx->r2 != 0) {
        // addiu       $t4, $t4, -0x1
        ctx->r12 = ADD32(ctx->r12, -0X1);
        goto L_80019940;
    }
    // addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
L_80019AE8:
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // lw          $a0, 0x10($t3)
    ctx->r4 = MEM_W(0X10, ctx->r11);
    // ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // subu        $a0, $a0, $t8
    ctx->r4 = SUB32(ctx->r4, ctx->r24);
    // sra         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) >> 2;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sw          $t0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r8;
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // lw          $v0, 0x90($t3)
    ctx->r2 = MEM_W(0X90, ctx->r11);
    // mfhi        $t9
    ctx->r25 = hi;
    // sra         $v1, $t9, 2
    ctx->r3 = S32(ctx->r25) >> 2;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x90($t3)
    MEM_W(0X90, ctx->r11) = ctx->r2;
    // lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(0X4, ctx->r29);
    // lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(0X0, ctx->r29);
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // jr          $ra
    // nop

    return;
    // nop

;}
