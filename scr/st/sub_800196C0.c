#include "recomp.h"
#include "disable_warnings.h"

void sub_800196C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // addu        $t5, $a0, $zero
    ctx->r13 = ADD32(ctx->r4, 0);
    // addu        $t0, $a1, $zero
    ctx->r8 = ADD32(ctx->r5, 0);
    // sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // lui         $t2, 0x1F80
    ctx->r10 = S32(0X1F80 << 16);
    // addu        $v1, $t5, $zero
    ctx->r3 = ADD32(ctx->r13, 0);
    // sw          $s3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r19;
    // sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // lw          $v0, 0x8C($t2)
    ctx->r2 = MEM_W(0X8C, ctx->r10);
    // lw          $t9, 0x10($t2)
    ctx->r25 = MEM_W(0X10, ctx->r10);
    // addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // addiu       $t5, $t5, -0x1
    ctx->r13 = ADD32(ctx->r13, -0X1);
    // beq         $v1, $zero, L_800198A0
    if (ctx->r3 == 0) {
        // sw          $v0, 0x8C($t2)
        MEM_W(0X8C, ctx->r10) = ctx->r2;
        goto L_800198A0;
    }
    // sw          $v0, 0x8C($t2)
    MEM_W(0X8C, ctx->r10) = ctx->r2;
    // andi        $v0, $a3, 0x2
    ctx->r2 = ctx->r7 & 0X2;
    // ori         $t8, $v0, 0x2C
    ctx->r24 = ctx->r2 | 0X2C;
    // lui         $v0, 0x60
    ctx->r2 = S32(0X60 << 16);
    // and         $a3, $a3, $v0
    ctx->r7 = ctx->r7 & ctx->r2;
    // lui         $t6, 0xFF
    ctx->r14 = S32(0XFF << 16);
    // ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
L_80019718:
    // lhu         $v1, 0x12($t0)
    ctx->r3 = MEM_HU(0X12, ctx->r8);
    // lw          $v0, 0x40($t2)
    ctx->r2 = MEM_W(0X40, ctx->r10);
    // lhu         $a0, 0x16($t0)
    ctx->r4 = MEM_HU(0X16, ctx->r8);
    // addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // addu        $t4, $v0, $a0
    ctx->r12 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v1, 0x14($t0)
    ctx->r3 = MEM_HU(0X14, ctx->r8);
    // lw          $s1, 0x0($t3)
    ctx->r17 = MEM_W(0X0, ctx->r11);
    // lw          $s3, 0x0($t4)
    ctx->r19 = MEM_W(0X0, ctx->r12);
    // addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    // lw          $s2, 0x0($t1)
    ctx->r18 = MEM_W(0X0, ctx->r9);
    // mtc2        $s1, $12
    gte_mtc2(ctx, 17, 12);
    // mtc2        $s3, $14
    gte_mtc2(ctx, 19, 14);
    // mtc2        $s2, $13
    gte_mtc2(ctx, 18, 13);
    // addiu       $t7, $t0, 0x1C
    ctx->r15 = ADD32(ctx->r8, 0X1C);
    // nop

    // nop

    // .word       0x4B400006                   # INVALID     $k0, $zero, 0x6 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B400006);
    // lbu         $v0, 0xB($t0)
    ctx->r2 = MEM_BU(0XB, ctx->r8);
    // nop

    // or          $v0, $v0, $t8
    ctx->r2 = ctx->r2 | ctx->r24;
    // sb          $v0, 0x63($t2)
    MEM_B(0X63, ctx->r10) = ctx->r2;
    // addiu       $v0, $t2, 0x70
    ctx->r2 = ADD32(ctx->r10, 0X70);
    // swc2        $24, 0x0($v0)
    gte_swc2(rdram, ctx, 24, 2, 0);
    // lw          $v0, 0x70($t2)
    ctx->r2 = MEM_W(0X70, ctx->r10);
    // nop

    // blez        $v0, L_80019890
    if (SIGNED(ctx->r2) <= 0) {
        // nop
    
        goto L_80019890;
    }
    // nop

    // lbu         $v1, 0xA($t0)
    ctx->r3 = MEM_BU(0XA, ctx->r8);
    // lhu         $a2, 0x18($t0)
    ctx->r6 = MEM_HU(0X18, ctx->r8);
    // lw          $a1, 0x40($t2)
    ctx->r5 = MEM_W(0X40, ctx->r10);
    // lh          $v0, 0x4($t3)
    ctx->r2 = MEM_HS(0X4, ctx->r11);
    // lh          $a0, 0x4($t1)
    ctx->r4 = MEM_HS(0X4, ctx->r9);
    // sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3) << 24;
    // sra         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3) >> 24;
    // addu        $a2, $a1, $a2
    ctx->r6 = ADD32(ctx->r5, ctx->r6);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lh          $a0, 0x4($t4)
    ctx->r4 = MEM_HS(0X4, ctx->r12);
    // lh          $a1, 0x4($a2)
    ctx->r5 = MEM_HS(0X4, ctx->r6);
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
    // lw          $v0, 0x4($t2)
    ctx->r2 = MEM_W(0X4, ctx->r10);
    // sra         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3) >> 16;
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_80019890
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80019890;
    }
    // nop

    // lw          $v0, 0x80($t2)
    ctx->r2 = MEM_W(0X80, ctx->r10);
    // nop

    // slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // beq         $v0, $zero, L_80019890
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80019890;
    }
    // nop

    // lw          $a1, 0x10($t2)
    ctx->r5 = MEM_W(0X10, ctx->r10);
    // nop

    // addiu       $v0, $a1, 0x28
    ctx->r2 = ADD32(ctx->r5, 0X28);
    // sw          $v0, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r2;
    // swc2        $12, 0x8($a1)
    gte_swc2(rdram, ctx, 12, 5, 8);
    // swc2        $13, 0x10($a1)
    gte_swc2(rdram, ctx, 13, 5, 16);
    // swc2        $14, 0x18($a1)
    gte_swc2(rdram, ctx, 14, 5, 24);
    // lhu         $v1, 0x10($t0)
    ctx->r3 = MEM_HU(0X10, ctx->r8);
    // lw          $v0, 0x24($t2)
    ctx->r2 = MEM_W(0X24, ctx->r10);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // addiu       $v0, $t2, 0x60
    ctx->r2 = ADD32(ctx->r10, 0X60);
    // lwc2        $6, 0x0($v0)
    gte_lwc2(rdram, ctx, 6, 2, 0);
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // nop

    // sw          $v0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r2;
    // .word       0x4B08041B                   # INVALID     $t8, $t0, 0x41B # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4B08041B);
    // lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(0X0, ctx->r8);
    // nop

    // sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(0X4, ctx->r8);
    // nop

    // or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
    // sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    // lhu         $v0, 0x8($t0)
    ctx->r2 = MEM_HU(0X8, ctx->r8);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // sh          $v0, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r2;
    // lhu         $v0, 0xC($t0)
    ctx->r2 = MEM_HU(0XC, ctx->r8);
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // sh          $v0, 0x24($a1)
    MEM_H(0X24, ctx->r5) = ctx->r2;
    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // lui         $v1, 0x900
    ctx->r3 = S32(0X900 << 16);
    // and         $v0, $v0, $t6
    ctx->r2 = ctx->r2 & ctx->r14;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // and         $v0, $a1, $t6
    ctx->r2 = ctx->r5 & ctx->r14;
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // swc2        $22, 0x0($a1)
    gte_swc2(rdram, ctx, 22, 5, 0);
L_80019890:
    // addu        $t0, $t7, $zero
    ctx->r8 = ADD32(ctx->r15, 0);
    // addu        $v0, $t5, $zero
    ctx->r2 = ADD32(ctx->r13, 0);
    // bne         $v0, $zero, L_80019718
    if (ctx->r2 != 0) {
        // addiu       $t5, $t5, -0x1
        ctx->r13 = ADD32(ctx->r13, -0X1);
        goto L_80019718;
    }
    // addiu       $t5, $t5, -0x1
    ctx->r13 = ADD32(ctx->r13, -0X1);
L_800198A0:
    // lui         $v1, 0x6666
    ctx->r3 = S32(0X6666 << 16);
    // lw          $a0, 0x10($t2)
    ctx->r4 = MEM_W(0X10, ctx->r10);
    // ori         $v1, $v1, 0x6667
    ctx->r3 = ctx->r3 | 0X6667;
    // subu        $a0, $a0, $t9
    ctx->r4 = SUB32(ctx->r4, ctx->r25);
    // sra         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) >> 2;
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sw          $t0, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r8;
    // sra         $a0, $a0, 31
    ctx->r4 = S32(ctx->r4) >> 31;
    // lw          $v0, 0x90($t2)
    ctx->r2 = MEM_W(0X90, ctx->r10);
    // mfhi        $s1
    ctx->r17 = hi;
    // sra         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17) >> 2;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x90($t2)
    MEM_W(0X90, ctx->r10) = ctx->r2;
    // lw          $s3, 0xC($sp)
    ctx->r19 = MEM_W(0XC, ctx->r29);
    // lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(0X8, ctx->r29);
    // lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(0X4, ctx->r29);
    // lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(0X0, ctx->r29);
    // addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // jr          $ra
    // nop

    return;
    // nop

;}
