#include "recomp.h"
#include "disable_warnings.h"

void sub_800194C4(uint8_t* rdram, recomp_context* ctx) {
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
    // beq         $v1, $zero, L_80019680
    if (ctx->r3 == 0) {
        // sw          $v0, 0x8C($t3)
        MEM_W(0X8C, ctx->r11) = ctx->r2;
        goto L_80019680;
    }
    // sw          $v0, 0x8C($t3)
    MEM_W(0X8C, ctx->r11) = ctx->r2;
    // andi        $v0, $a3, 0x2
    ctx->r2 = ctx->r7 & 0X2;
    // ori         $t7, $v0, 0x24
    ctx->r15 = ctx->r2 | 0X24;
    // lui         $v0, 0x60
    ctx->r2 = S32(0X60 << 16);
    // and         $a3, $a3, $v0
    ctx->r7 = ctx->r7 & ctx->r2;
    // lui         $t5, 0xFF
    ctx->r13 = S32(0XFF << 16);
    // ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
L_80019510:
    // lhu         $v1, 0xE($t0)
    ctx->r3 = MEM_HU(0XE, ctx->r8);
    // lw          $v0, 0x40($t3)
    ctx->r2 = MEM_W(0X40, ctx->r11);
    // lhu         $a0, 0x12($t0)
    ctx->r4 = MEM_HU(0X12, ctx->r8);
    // addu        $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v1, 0x10($t0)
    ctx->r3 = MEM_HU(0X10, ctx->r8);
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
    // addiu       $t6, $t0, 0x14
    ctx->r14 = ADD32(ctx->r8, 0X14);
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

    // blez        $v0, L_80019670
    if (SIGNED(ctx->r2) <= 0) {
        // lui         $a1, 0x5555
        ctx->r5 = S32(0X5555 << 16);
        goto L_80019670;
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
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // slt         $v1, $a0, $v1
    ctx->r3 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v1, $zero, L_80019670
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80019670;
    }
    // nop

    // lw          $v0, 0x80($t3)
    ctx->r2 = MEM_W(0X80, ctx->r11);
    // nop

    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_80019670
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80019670;
    }
    // nop

    // lw          $a1, 0x10($t3)
    ctx->r5 = MEM_W(0X10, ctx->r11);
    // nop

    // addiu       $v0, $a1, 0x20
    ctx->r2 = ADD32(ctx->r5, 0X20);
    // sw          $v0, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r2;
    // swc2        $12, 0x8($a1)
    gte_swc2(rdram, ctx, 12, 5, 8);
    // swc2        $13, 0x10($a1)
    gte_swc2(rdram, ctx, 13, 5, 16);
    // swc2        $14, 0x18($a1)
    gte_swc2(rdram, ctx, 14, 5, 24);
    // lhu         $v1, 0xC($t0)
    ctx->r3 = MEM_HU(0XC, ctx->r8);
    // lw          $v0, 0x24($t3)
    ctx->r2 = MEM_W(0X24, ctx->r11);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // addiu       $v0, $t3, 0x60
    ctx->r2 = ADD32(ctx->r11, 0X60);
    // lwc2        $6, 0x0($v0)
    gte_lwc2(rdram, ctx, 6, 2, 0);
    // lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(0X0, ctx->r8);
    // nop

    // sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // .word       0x4B08041B                   # INVALID     $t8, $t0, 0x41B # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B08041B);
    // lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(0X4, ctx->r8);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
    // sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x8($t0)
    ctx->r2 = MEM_HU(0X8, ctx->r8);
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // sh          $v0, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r2;
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // lui         $v1, 0x700
    ctx->r3 = S32(0X700 << 16);
    // and         $v0, $v0, $t5
    ctx->r2 = ctx->r2 & ctx->r13;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // and         $v0, $a1, $t5
    ctx->r2 = ctx->r5 & ctx->r13;
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // swc2        $22, 0x0($a1)
    gte_swc2(rdram, ctx, 22, 5, 0);
L_80019670:
    // addu        $t0, $t6, $zero
    ctx->r8 = ADD32(ctx->r14, 0);
    // addu        $v0, $t4, $zero
    ctx->r2 = ADD32(ctx->r12, 0);
    // bne         $v0, $zero, L_80019510
    if (ctx->r2 != 0) {
        // addiu       $t4, $t4, -0x1
        ctx->r12 = ADD32(ctx->r12, -0X1);
        goto L_80019510;
    }
    // addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
L_80019680:
    // lw          $v0, 0x10($t3)
    ctx->r2 = MEM_W(0X10, ctx->r11);
    // nop

    // subu        $v0, $v0, $t8
    ctx->r2 = SUB32(ctx->r2, ctx->r24);
    // sra         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) >> 2;
    // bgez        $v1, L_8001969C
    if (SIGNED(ctx->r3) >= 0) {
        // sw          $t0, 0x1C($t3)
        MEM_W(0X1C, ctx->r11) = ctx->r8;
        goto L_8001969C;
    }
    // sw          $t0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r8;
    // addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
L_8001969C:
    // lw          $v0, 0x90($t3)
    ctx->r2 = MEM_W(0X90, ctx->r11);
    // sra         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3) >> 3;
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
