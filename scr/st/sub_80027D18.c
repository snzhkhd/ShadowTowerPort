#include "recomp.h"
#include "disable_warnings.h"

void sub_80027D18(uint8_t* rdram, recomp_context* ctx) 
{
   // printf("80027D18\n");
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // addu        $t4, $a1, $zero
    ctx->r12 = ADD32(ctx->r5, 0);
    // andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // srl         $t3, $v0, 8
    ctx->r11 = S32(U32(ctx->r2) >> 8);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x304($a1)
    ctx->r3 = MEM_W(0X304, ctx->r5);
    // nop

    // lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $a0, $t0, 0x18
    ctx->r4 = ADD32(ctx->r8, 0X18);
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_80028218
    if (ctx->r2 != 0) {
        // andi        $t2, $a2, 0xFF
        ctx->r10 = ctx->r6 & 0XFF;
        goto L_80028218;
    }
    // andi        $t2, $a2, 0xFF
    ctx->r10 = ctx->r6 & 0XFF;
    // sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // lw          $v0, 0x328($a1)
    ctx->r2 = MEM_W(0X328, ctx->r5);
    // andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($a1)
    MEM_W(0X328, ctx->r5) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80027D7C
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x28
        ctx->r2 = ADD32(0, 0X28);
        goto L_80027D7C;
    }
    // addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
L_80027D7C:
    // sb          $v0, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r2;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // lw          $v0, 0xE4($a1)
    ctx->r2 = MEM_W(0XE4, ctx->r5);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x500
    ctx->r3 = S32(0X500 << 16);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // nop

    // sh          $v0, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($t1)
    ctx->r2 = MEM_HU(0X2, ctx->r9);
    // nop

    // sh          $v0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // lhu         $v1, 0x4($t1)
    ctx->r3 = MEM_HU(0X4, ctx->r9);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($t1)
    ctx->r2 = MEM_HU(0X2, ctx->r9);
    // nop

    // sh          $v0, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // nop

    // sh          $v0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($t1)
    ctx->r2 = MEM_HU(0X2, ctx->r9);
    // nop

    // addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // sh          $v0, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // lhu         $v1, 0x4($t1)
    ctx->r3 = MEM_HU(0X4, ctx->r9);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($t1)
    ctx->r2 = MEM_HU(0X2, ctx->r9);
    // nop

    // addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // sh          $v0, 0x16($t0)
    MEM_H(0X16, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($t4)
    ctx->r2 = MEM_BU(0X0, ctx->r12);
    // nop

    // sb          $v0, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x1($t4)
    ctx->r2 = MEM_BU(0X1, ctx->r12);
    // nop

    // sb          $v0, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x2($t4)
    ctx->r2 = MEM_BU(0X2, ctx->r12);
    // nop

    // sb          $v0, 0x6($t0)
    MEM_B(0X6, ctx->r8) = ctx->r2;
    // lw          $v0, 0xE4($a1)
    ctx->r2 = MEM_W(0XE4, ctx->r5);
    // and         $a0, $t0, $a0
    ctx->r4 = ctx->r8 & ctx->r4;
    // sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // lw          $v1, 0x304($a1)
    ctx->r3 = MEM_W(0X304, ctx->r5);
    // nop

    // lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $a0, $t0, 0x18
    ctx->r4 = ADD32(ctx->r8, 0X18);
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_80028218
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80028218;
    }
    // nop

    // sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // lw          $v0, 0x328($a1)
    ctx->r2 = MEM_W(0X328, ctx->r5);
    // andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($a1)
    MEM_W(0X328, ctx->r5) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80027E9C
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x28
        ctx->r2 = ADD32(0, 0X28);
        goto L_80027E9C;
    }
    // addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
L_80027E9C:
    // sb          $v0, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r2;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // lw          $v0, 0xE4($a1)
    ctx->r2 = MEM_W(0XE4, ctx->r5);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x500
    ctx->r3 = S32(0X500 << 16);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // nop

    // sh          $v0, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($t1)
    ctx->r2 = MEM_HU(0X2, ctx->r9);
    // lhu         $v1, 0x6($t1)
    ctx->r3 = MEM_HU(0X6, ctx->r9);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // sh          $v0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // lhu         $v1, 0x4($t1)
    ctx->r3 = MEM_HU(0X4, ctx->r9);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($t1)
    ctx->r2 = MEM_HU(0X2, ctx->r9);
    // lhu         $v1, 0x6($t1)
    ctx->r3 = MEM_HU(0X6, ctx->r9);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $v0, $v0, $t2
    ctx->r2 = SUB32(ctx->r2, ctx->r10);
    // sh          $v0, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // nop

    // sh          $v0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r2;
    // lhu         $v1, 0x2($t1)
    ctx->r3 = MEM_HU(0X2, ctx->r9);
    // lhu         $v0, 0x6($t1)
    ctx->r2 = MEM_HU(0X6, ctx->r9);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // lhu         $v1, 0x4($t1)
    ctx->r3 = MEM_HU(0X4, ctx->r9);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r2;
    // lhu         $v1, 0x2($t1)
    ctx->r3 = MEM_HU(0X2, ctx->r9);
    // lhu         $v0, 0x6($t1)
    ctx->r2 = MEM_HU(0X6, ctx->r9);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x16($t0)
    MEM_H(0X16, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($t4)
    ctx->r2 = MEM_BU(0X0, ctx->r12);
    // nop

    // sb          $v0, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x1($t4)
    ctx->r2 = MEM_BU(0X1, ctx->r12);
    // nop

    // sb          $v0, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x2($t4)
    ctx->r2 = MEM_BU(0X2, ctx->r12);
    // nop

    // sb          $v0, 0x6($t0)
    MEM_B(0X6, ctx->r8) = ctx->r2;
    // lw          $v0, 0xE4($a1)
    ctx->r2 = MEM_W(0XE4, ctx->r5);
    // and         $a0, $t0, $a0
    ctx->r4 = ctx->r8 & ctx->r4;
    // sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // lw          $v1, 0x304($a1)
    ctx->r3 = MEM_W(0X304, ctx->r5);
    // nop

    // lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $a0, $t0, 0x18
    ctx->r4 = ADD32(ctx->r8, 0X18);
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_80028218
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80028218;
    }
    // nop

    // sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // lw          $v0, 0x328($a1)
    ctx->r2 = MEM_W(0X328, ctx->r5);
    // andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($a1)
    MEM_W(0X328, ctx->r5) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80027FDC
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x28
        ctx->r2 = ADD32(0, 0X28);
        goto L_80027FDC;
    }
    // addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
L_80027FDC:
    // sb          $v0, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r2;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $a2, $v0, $v1
    ctx->r6 = ADD32(ctx->r2, ctx->r3);
    // lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // lw          $v0, 0xE4($a2)
    ctx->r2 = MEM_W(0XE4, ctx->r6);
    // ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x500
    ctx->r3 = S32(0X500 << 16);
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // nop

    // sh          $v0, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($t1)
    ctx->r2 = MEM_HU(0X2, ctx->r9);
    // nop

    // addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // sh          $v0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // nop

    // addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // sh          $v0, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($t1)
    ctx->r2 = MEM_HU(0X2, ctx->r9);
    // nop

    // addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // sh          $v0, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // sll         $a0, $t2, 1
    ctx->r4 = S32(ctx->r10) << 1;
    // sh          $v0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r2;
    // lhu         $v1, 0x2($t1)
    ctx->r3 = MEM_HU(0X2, ctx->r9);
    // lhu         $v0, 0x6($t1)
    ctx->r2 = MEM_HU(0X6, ctx->r9);
    // addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r3;
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // nop

    // addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // sh          $v0, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r2;
    // lhu         $v1, 0x2($t1)
    ctx->r3 = MEM_HU(0X2, ctx->r9);
    // lhu         $v0, 0x6($t1)
    ctx->r2 = MEM_HU(0X6, ctx->r9);
    // addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x16($t0)
    MEM_H(0X16, ctx->r8) = ctx->r3;
    // lbu         $v0, 0x0($t4)
    ctx->r2 = MEM_BU(0X0, ctx->r12);
    // nop

    // sb          $v0, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x1($t4)
    ctx->r2 = MEM_BU(0X1, ctx->r12);
    // nop

    // sb          $v0, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x2($t4)
    ctx->r2 = MEM_BU(0X2, ctx->r12);
    // nop

    // sb          $v0, 0x6($t0)
    MEM_B(0X6, ctx->r8) = ctx->r2;
    // lw          $v0, 0xE4($a2)
    ctx->r2 = MEM_W(0XE4, ctx->r6);
    // and         $a1, $t0, $a1
    ctx->r5 = ctx->r8 & ctx->r5;
    // sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // lw          $v1, 0x304($a2)
    ctx->r3 = MEM_W(0X304, ctx->r6);
    // nop

    // lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $a0, $t0, 0x18
    ctx->r4 = ADD32(ctx->r8, 0X18);
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_80028218
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80028218;
    }
    // nop

    // sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // lw          $v0, 0x328($a2)
    ctx->r2 = MEM_W(0X328, ctx->r6);
    // andi        $v1, $a3, 0xFFFF
    ctx->r3 = ctx->r7 & 0XFFFF;
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($a2)
    MEM_W(0X328, ctx->r6) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_8002810C
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x28
        ctx->r2 = ADD32(0, 0X28);
        goto L_8002810C;
    }
    // addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
L_8002810C:
    // sb          $v0, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r2;
    // lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // addiu       $a1, $a1, -0x2F70
    ctx->r5 = ADD32(ctx->r5, -0X2F70);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // lui         $a2, 0xFF
    ctx->r6 = S32(0XFF << 16);
    // lw          $v0, 0xE4($a1)
    ctx->r2 = MEM_W(0XE4, ctx->r5);
    // ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x500
    ctx->r3 = S32(0X500 << 16);
    // and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // lhu         $v1, 0x4($t1)
    ctx->r3 = MEM_HU(0X4, ctx->r9);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $v0, $v0, $t3
    ctx->r2 = SUB32(ctx->r2, ctx->r11);
    // sh          $v0, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($t1)
    ctx->r2 = MEM_HU(0X2, ctx->r9);
    // nop

    // addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // sh          $v0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r2;
    // lhu         $v1, 0x0($t1)
    ctx->r3 = MEM_HU(0X0, ctx->r9);
    // lhu         $v0, 0x4($t1)
    ctx->r2 = MEM_HU(0X4, ctx->r9);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($t1)
    ctx->r2 = MEM_HU(0X2, ctx->r9);
    // nop

    // addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // sh          $v0, 0xE($t0)
    MEM_H(0XE, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($t1)
    ctx->r2 = MEM_HU(0X0, ctx->r9);
    // lhu         $v1, 0x4($t1)
    ctx->r3 = MEM_HU(0X4, ctx->r9);
    // sll         $a0, $t2, 1
    ctx->r4 = S32(ctx->r10) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // subu        $v0, $v0, $t3
    ctx->r2 = SUB32(ctx->r2, ctx->r11);
    // sh          $v0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r2;
    // lhu         $v1, 0x2($t1)
    ctx->r3 = MEM_HU(0X2, ctx->r9);
    // lhu         $v0, 0x6($t1)
    ctx->r2 = MEM_HU(0X6, ctx->r9);
    // addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r3;
    // lhu         $v1, 0x0($t1)
    ctx->r3 = MEM_HU(0X0, ctx->r9);
    // lhu         $v0, 0x4($t1)
    ctx->r2 = MEM_HU(0X4, ctx->r9);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x14($t0)
    MEM_H(0X14, ctx->r8) = ctx->r2;
    // lhu         $v1, 0x2($t1)
    ctx->r3 = MEM_HU(0X2, ctx->r9);
    // lhu         $v0, 0x6($t1)
    ctx->r2 = MEM_HU(0X6, ctx->r9);
    // addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sh          $v1, 0x16($t0)
    MEM_H(0X16, ctx->r8) = ctx->r3;
    // lbu         $v0, 0x0($t4)
    ctx->r2 = MEM_BU(0X0, ctx->r12);
    // nop

    // sb          $v0, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x1($t4)
    ctx->r2 = MEM_BU(0X1, ctx->r12);
    // nop

    // sb          $v0, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x2($t4)
    ctx->r2 = MEM_BU(0X2, ctx->r12);
    // nop

    // sb          $v0, 0x6($t0)
    MEM_B(0X6, ctx->r8) = ctx->r2;
    // lw          $v0, 0xE4($a1)
    ctx->r2 = MEM_W(0XE4, ctx->r5);
    // and         $a2, $t0, $a2
    ctx->r6 = ctx->r8 & ctx->r6;
    // sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_80028218:
    // jr          $ra
    // nop

    return;
    // nop

;}
