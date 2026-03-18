#include "recomp.h"
#include "disable_warnings.h"

void sub_8002916C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // addu        $t6, $zero, $zero
    ctx->r14 = ADD32(0, 0);
    // addu        $t2, $t6, $zero
    ctx->r10 = ADD32(ctx->r14, 0);
    // addu        $t5, $t2, $zero
    ctx->r13 = ADD32(ctx->r10, 0);
    // addu        $t4, $t2, $zero
    ctx->r12 = ADD32(ctx->r10, 0);
    // addu        $t0, $t2, $zero
    ctx->r8 = ADD32(ctx->r10, 0);
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // addiu       $v0, $zero, 0x400
    ctx->r2 = ADD32(0, 0X400);
    // beq         $a2, $v0, L_800291F8
    if (ctx->r6 == ctx->r2) {
        // addu        $t3, $t0, $zero
        ctx->r11 = ADD32(ctx->r8, 0);
        goto L_800291F8;
    }
    // addu        $t3, $t0, $zero
    ctx->r11 = ADD32(ctx->r8, 0);
    // slti        $v0, $a2, 0x401
    ctx->r2 = SIGNED(ctx->r6) < 0X401 ? 1 : 0;
    // beq         $v0, $zero, L_800291B0
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x800
        ctx->r2 = ADD32(0, 0X800);
        goto L_800291B0;
    }
    // addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // beq         $a2, $zero, L_800291C8
    if (ctx->r6 == 0) {
        // lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
        goto L_800291C8;
    }
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // j           L_80029304
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    goto L_80029304;
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
L_800291B0:
    // beq         $a2, $v0, L_8002924C
    if (ctx->r6 == ctx->r2) {
        // addiu       $v0, $zero, 0xC00
        ctx->r2 = ADD32(0, 0XC00);
        goto L_8002924C;
    }
    // addiu       $v0, $zero, 0xC00
    ctx->r2 = ADD32(0, 0XC00);
    // beq         $a2, $v0, L_800292A8
    if (ctx->r6 == ctx->r2) {
        // lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
        goto L_800292A8;
    }
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // j           L_80029304
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    goto L_80029304;
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
L_800291C8:
    // lhu         $v0, 0x6($a3)
    ctx->r2 = MEM_HU(0X6, ctx->r7);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(0X0, ctx->r7);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // subu        $a0, $v0, $v1
    ctx->r4 = SUB32(ctx->r2, ctx->r3);
    // addu        $t6, $a0, $zero
    ctx->r14 = ADD32(ctx->r4, 0);
    // j           L_80029278
    // addu        $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    goto L_80029278;
    // addu        $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
L_800291F8:
    // lhu         $v0, 0x4($a3)
    ctx->r2 = MEM_HU(0X4, ctx->r7);
    // lhu         $a0, 0x2($a3)
    ctx->r4 = MEM_HU(0X2, ctx->r7);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(0X0, ctx->r7);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // subu        $t6, $v0, $v1
    ctx->r14 = SUB32(ctx->r2, ctx->r3);
    // addu        $t2, $v0, $zero
    ctx->r10 = ADD32(ctx->r2, 0);
    // lhu         $v0, 0x6($a3)
    ctx->r2 = MEM_HU(0X6, ctx->r7);
    // addu        $t5, $t2, $v1
    ctx->r13 = ADD32(ctx->r10, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
    // addu        $t4, $v0, $zero
    ctx->r12 = ADD32(ctx->r2, 0);
    // j           L_800292F8
    // addu        $t0, $a0, $v1
    ctx->r8 = ADD32(ctx->r4, ctx->r3);
    goto L_800292F8;
    // addu        $t0, $a0, $v1
    ctx->r8 = ADD32(ctx->r4, ctx->r3);
L_8002924C:
    // lhu         $v0, 0x6($a3)
    ctx->r2 = MEM_HU(0X6, ctx->r7);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(0X0, ctx->r7);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // addu        $t6, $a0, $zero
    ctx->r14 = ADD32(ctx->r4, 0);
    // subu        $t2, $v0, $v1
    ctx->r10 = SUB32(ctx->r2, ctx->r3);
L_80029278:
    // lhu         $v0, 0x4($a3)
    ctx->r2 = MEM_HU(0X4, ctx->r7);
    // addu        $t5, $a0, $zero
    ctx->r13 = ADD32(ctx->r4, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x2($a3)
    ctx->r2 = MEM_HU(0X2, ctx->r7);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // subu        $t4, $v0, $v1
    ctx->r12 = SUB32(ctx->r2, ctx->r3);
    // addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // j           L_800292FC
    // addu        $t3, $t0, $v1
    ctx->r11 = ADD32(ctx->r8, ctx->r3);
    goto L_800292FC;
    // addu        $t3, $t0, $v1
    ctx->r11 = ADD32(ctx->r8, ctx->r3);
L_800292A8:
    // lhu         $v0, 0x4($a3)
    ctx->r2 = MEM_HU(0X4, ctx->r7);
    // lhu         $a0, 0x2($a3)
    ctx->r4 = MEM_HU(0X2, ctx->r7);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(0X0, ctx->r7);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // subu        $t6, $v0, $v1
    ctx->r14 = SUB32(ctx->r2, ctx->r3);
    // addu        $t2, $v0, $zero
    ctx->r10 = ADD32(ctx->r2, 0);
    // lhu         $v0, 0x6($a3)
    ctx->r2 = MEM_HU(0X6, ctx->r7);
    // addu        $t5, $t2, $v1
    ctx->r13 = ADD32(ctx->r10, ctx->r3);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // addu        $t4, $v0, $zero
    ctx->r12 = ADD32(ctx->r2, 0);
    // subu        $t0, $a0, $v1
    ctx->r8 = SUB32(ctx->r4, ctx->r3);
L_800292F8:
    // addu        $t3, $v0, $zero
    ctx->r11 = ADD32(ctx->r2, 0);
L_800292FC:
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
L_80029304:
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $t1, $v0, $v1
    ctx->r9 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x304($t1)
    ctx->r3 = MEM_W(0X304, ctx->r9);
    // nop

    // lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $a0, $a2, 0x14
    ctx->r4 = ADD32(ctx->r6, 0X14);
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_80029484
    if (ctx->r2 != 0) {
        // addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
        goto L_80029484;
    }
    // addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // lw          $v0, 0x328($t1)
    ctx->r2 = MEM_W(0X328, ctx->r9);
    // addiu       $t8, $zero, 0x22
    ctx->r24 = ADD32(0, 0X22);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($t1)
    MEM_W(0X328, ctx->r9) = ctx->r2;
    // sb          $t9, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r25;
    // sb          $t8, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r24;
    // sh          $t6, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r14;
    // sh          $t4, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r12;
    // sh          $t2, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r10;
    // sh          $t0, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r8;
    // sh          $t5, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r13;
    // sh          $t3, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r11;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // lui         $a3, 0xFF
    ctx->r7 = S32(0XFF << 16);
    // sb          $v0, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r2;
    // lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(0X1, ctx->r5);
    // ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // sb          $v0, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r2;
    // lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(0X2, ctx->r5);
    // lui         $t7, 0xFF00
    ctx->r15 = S32(0XFF00 << 16);
    // sb          $v0, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r2;
    // lw          $v0, 0xE4($t1)
    ctx->r2 = MEM_W(0XE4, ctx->r9);
    // lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(0X0, ctx->r6);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // and         $v1, $v1, $t7
    ctx->r3 = ctx->r3 & ctx->r15;
    // and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // lw          $a0, 0xE4($t1)
    ctx->r4 = MEM_W(0XE4, ctx->r9);
    // nop

    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // and         $v1, $a2, $a3
    ctx->r3 = ctx->r6 & ctx->r7;
    // and         $v0, $v0, $t7
    ctx->r2 = ctx->r2 & ctx->r15;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // lw          $v1, 0x304($t1)
    ctx->r3 = MEM_W(0X304, ctx->r9);
    // nop

    // lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $a0, $a2, 0x14
    ctx->r4 = ADD32(ctx->r6, 0X14);
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_80029484
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80029484;
    }
    // nop

    // sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // lw          $v0, 0x328($t1)
    ctx->r2 = MEM_W(0X328, ctx->r9);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($t1)
    MEM_W(0X328, ctx->r9) = ctx->r2;
    // addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // sh          $v0, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r2;
    // addiu       $v0, $t4, 0x1
    ctx->r2 = ADD32(ctx->r12, 0X1);
    // sh          $v0, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r2;
    // addiu       $v0, $t2, 0x1
    ctx->r2 = ADD32(ctx->r10, 0X1);
    // sh          $v0, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r2;
    // addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // sh          $v0, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r2;
    // addiu       $v0, $t5, 0x1
    ctx->r2 = ADD32(ctx->r13, 0X1);
    // sh          $v0, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r2;
    // addiu       $v0, $t3, 0x1
    ctx->r2 = ADD32(ctx->r11, 0X1);
    // sb          $t9, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r25;
    // sb          $t8, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r24;
    // sh          $v0, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r2;
    // lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(0X0, ctx->r5);
    // nop

    // sb          $v0, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r2;
    // lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(0X1, ctx->r5);
    // nop

    // sb          $v0, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r2;
    // lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(0X2, ctx->r5);
    // nop

    // sb          $v0, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r2;
    // lw          $v0, 0xE4($t1)
    ctx->r2 = MEM_W(0XE4, ctx->r9);
    // lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(0X0, ctx->r6);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // and         $v1, $v1, $t7
    ctx->r3 = ctx->r3 & ctx->r15;
    // and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // lw          $a0, 0xE4($t1)
    ctx->r4 = MEM_W(0XE4, ctx->r9);
    // nop

    // lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(0X0, ctx->r4);
    // and         $v1, $a2, $a3
    ctx->r3 = ctx->r6 & ctx->r7;
    // and         $v0, $v0, $t7
    ctx->r2 = ctx->r2 & ctx->r15;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_80029484:
    // jr          $ra
    // nop

    return;
    // nop

;}
