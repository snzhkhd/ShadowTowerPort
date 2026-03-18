#include "recomp.h"
#include "disable_warnings.h"

void sub_80028DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // addu        $t3, $a0, $zero
    ctx->r11 = ADD32(ctx->r4, 0);
    // addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // lwl         $v0, 0x3($t3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r11);
    // lwr         $v0, 0x0($t3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r11);
    // lwl         $v1, 0x7($t3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r11);
    // lwr         $v1, 0x4($t3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r11);
    // swl         $v0, 0x3($sp)
    do_swl(rdram, 0X3, ctx->r29, ctx->r2);
    // swr         $v0, 0x0($sp)
    do_swr(rdram, 0X0, ctx->r29, ctx->r2);
    // swl         $v1, 0x7($sp)
    do_swl(rdram, 0X7, ctx->r29, ctx->r3);
    // swr         $v1, 0x4($sp)
    do_swr(rdram, 0X4, ctx->r29, ctx->r3);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // lhu         $a0, 0x6($sp)
    ctx->r4 = MEM_HU(0X6, ctx->r29);
    // lw          $v1, 0x304($a1)
    ctx->r3 = MEM_W(0X304, ctx->r5);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 17
    ctx->r4 = S32(ctx->r4) >> 17;
    // sh          $a0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r4;
    // lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(0X8, ctx->r3);
    // lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(0X4, ctx->r3);
    // addiu       $a0, $t0, 0x24
    ctx->r4 = ADD32(ctx->r8, 0X24);
    // sltu        $v0, $v0, $a0
    ctx->r2 = ctx->r2 < ctx->r4 ? 1 : 0;
    // bne         $v0, $zero, L_80029160
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80029160;
    }
    // nop

    // sw          $a0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r4;
    // lw          $v0, 0x328($a1)
    ctx->r2 = MEM_W(0X328, ctx->r5);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // bne         $a3, $zero, L_80028E40
    if (ctx->r7 != 0) {
        // sw          $v0, 0x328($a1)
        MEM_W(0X328, ctx->r5) = ctx->r2;
        goto L_80028E40;
    }
    // sw          $v0, 0x328($a1)
    MEM_W(0X328, ctx->r5) = ctx->r2;
    // j           L_80028E44
    // addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    goto L_80028E44;
    // addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
L_80028E40:
    // addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
L_80028E44:
    // sb          $v0, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r2;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // ori         $v1, $zero, 0x8000
    ctx->r3 = 0 | 0X8000;
    // addu        $t2, $v0, $v1
    ctx->r10 = ADD32(ctx->r2, ctx->r3);
    // lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // lw          $v0, 0xE4($t2)
    ctx->r2 = MEM_W(0XE4, ctx->r10);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(0X0, ctx->r6);
    // nop

    // sb          $v0, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(0X1, ctx->r6);
    // nop

    // sb          $v0, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x2($a2)
    ctx->r2 = MEM_BU(0X2, ctx->r6);
    // nop

    // sb          $v0, 0x6($t0)
    MEM_B(0X6, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(0X0, ctx->r6);
    // nop

    // sb          $v0, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(0X1, ctx->r6);
    // nop

    // sb          $v0, 0xD($t0)
    MEM_B(0XD, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x2($a2)
    ctx->r2 = MEM_BU(0X2, ctx->r6);
    // nop

    // sb          $v0, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(0X0, ctx->r9);
    // nop

    // sb          $v0, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(0X1, ctx->r9);
    // nop

    // sb          $v0, 0x15($t0)
    MEM_B(0X15, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x2($t1)
    ctx->r2 = MEM_BU(0X2, ctx->r9);
    // nop

    // sb          $v0, 0x16($t0)
    MEM_B(0X16, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(0X0, ctx->r9);
    // nop

    // sb          $v0, 0x1C($t0)
    MEM_B(0X1C, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(0X1, ctx->r9);
    // nop

    // sb          $v0, 0x1D($t0)
    MEM_B(0X1D, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x2($t1)
    ctx->r2 = MEM_BU(0X2, ctx->r9);
    // nop

    // sb          $v0, 0x1E($t0)
    MEM_B(0X1E, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($sp)
    ctx->r2 = MEM_HU(0X0, ctx->r29);
    // nop

    // sh          $v0, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($sp)
    ctx->r2 = MEM_HU(0X2, ctx->r29);
    // nop

    // sh          $v0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($sp)
    ctx->r2 = MEM_HU(0X0, ctx->r29);
    // lhu         $v1, 0x4($sp)
    ctx->r3 = MEM_HU(0X4, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($sp)
    ctx->r2 = MEM_HU(0X2, ctx->r29);
    // nop

    // sh          $v0, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($sp)
    ctx->r2 = MEM_HU(0X0, ctx->r29);
    // nop

    // sh          $v0, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($sp)
    ctx->r2 = MEM_HU(0X2, ctx->r29);
    // lhu         $v1, 0x6($sp)
    ctx->r3 = MEM_HU(0X6, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($sp)
    ctx->r2 = MEM_HU(0X0, ctx->r29);
    // lhu         $v1, 0x4($sp)
    ctx->r3 = MEM_HU(0X4, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($sp)
    ctx->r2 = MEM_HU(0X2, ctx->r29);
    // lhu         $v1, 0x6($sp)
    ctx->r3 = MEM_HU(0X6, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x22($t0)
    MEM_H(0X22, ctx->r8) = ctx->r2;
    // lw          $v0, 0xE4($t2)
    ctx->r2 = MEM_W(0XE4, ctx->r10);
    // and         $a0, $t0, $a0
    ctx->r4 = ctx->r8 & ctx->r4;
    // sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // lwl         $v0, 0x3($t3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r11);
    // lwr         $v0, 0x0($t3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r11);
    // lwl         $v1, 0x7($t3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r11);
    // lwr         $v1, 0x4($t3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r11);
    // swl         $v0, 0x3($sp)
    do_swl(rdram, 0X3, ctx->r29, ctx->r2);
    // swr         $v0, 0x0($sp)
    do_swr(rdram, 0X0, ctx->r29, ctx->r2);
    // swl         $v1, 0x7($sp)
    do_swl(rdram, 0X7, ctx->r29, ctx->r3);
    // swr         $v1, 0x4($sp)
    do_swr(rdram, 0X4, ctx->r29, ctx->r3);
    // lhu         $v1, 0x6($sp)
    ctx->r3 = MEM_HU(0X6, ctx->r29);
    // lhu         $v0, 0x2($sp)
    ctx->r2 = MEM_HU(0X2, ctx->r29);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $v1, $v1, 17
    ctx->r3 = S32(ctx->r3) >> 17;
    // sh          $v1, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r3;
    // lw          $a0, 0x304($t2)
    ctx->r4 = MEM_W(0X304, ctx->r10);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x2($sp)
    MEM_H(0X2, ctx->r29) = ctx->r2;
    // lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(0X8, ctx->r4);
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // addiu       $v1, $t0, 0x24
    ctx->r3 = ADD32(ctx->r8, 0X24);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_80029160
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80029160;
    }
    // nop

    // sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // lw          $v0, 0x328($t2)
    ctx->r2 = MEM_W(0X328, ctx->r10);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // bne         $a3, $zero, L_8002900C
    if (ctx->r7 != 0) {
        // sw          $v0, 0x328($t2)
        MEM_W(0X328, ctx->r10) = ctx->r2;
        goto L_8002900C;
    }
    // sw          $v0, 0x328($t2)
    MEM_W(0X328, ctx->r10) = ctx->r2;
    // j           L_80029010
    // addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
    goto L_80029010;
    // addiu       $v0, $zero, 0x38
    ctx->r2 = ADD32(0, 0X38);
L_8002900C:
    // addiu       $v0, $zero, 0x3A
    ctx->r2 = ADD32(0, 0X3A);
L_80029010:
    // sb          $v0, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r2;
    // lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // addiu       $a0, $a0, -0x2F70
    ctx->r4 = ADD32(ctx->r4, -0X2F70);
    // ori         $v0, $zero, 0x8000
    ctx->r2 = 0 | 0X8000;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // lw          $v0, 0xE4($a0)
    ctx->r2 = MEM_W(0XE4, ctx->r4);
    // ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(0X0, ctx->r9);
    // nop

    // sb          $v0, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(0X1, ctx->r9);
    // nop

    // sb          $v0, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x2($t1)
    ctx->r2 = MEM_BU(0X2, ctx->r9);
    // nop

    // sb          $v0, 0x6($t0)
    MEM_B(0X6, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(0X0, ctx->r9);
    // nop

    // sb          $v0, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(0X1, ctx->r9);
    // nop

    // sb          $v0, 0xD($t0)
    MEM_B(0XD, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x2($t1)
    ctx->r2 = MEM_BU(0X2, ctx->r9);
    // nop

    // sb          $v0, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(0X0, ctx->r6);
    // nop

    // sb          $v0, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(0X1, ctx->r6);
    // nop

    // sb          $v0, 0x15($t0)
    MEM_B(0X15, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x2($a2)
    ctx->r2 = MEM_BU(0X2, ctx->r6);
    // nop

    // sb          $v0, 0x16($t0)
    MEM_B(0X16, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(0X0, ctx->r6);
    // nop

    // sb          $v0, 0x1C($t0)
    MEM_B(0X1C, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(0X1, ctx->r6);
    // nop

    // sb          $v0, 0x1D($t0)
    MEM_B(0X1D, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x2($a2)
    ctx->r2 = MEM_BU(0X2, ctx->r6);
    // nop

    // sb          $v0, 0x1E($t0)
    MEM_B(0X1E, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($sp)
    ctx->r2 = MEM_HU(0X0, ctx->r29);
    // nop

    // sh          $v0, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($sp)
    ctx->r2 = MEM_HU(0X2, ctx->r29);
    // nop

    // sh          $v0, 0xA($t0)
    MEM_H(0XA, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($sp)
    ctx->r2 = MEM_HU(0X0, ctx->r29);
    // lhu         $v1, 0x4($sp)
    ctx->r3 = MEM_HU(0X4, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x10($t0)
    MEM_H(0X10, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($sp)
    ctx->r2 = MEM_HU(0X2, ctx->r29);
    // nop

    // sh          $v0, 0x12($t0)
    MEM_H(0X12, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($sp)
    ctx->r2 = MEM_HU(0X0, ctx->r29);
    // nop

    // sh          $v0, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($sp)
    ctx->r2 = MEM_HU(0X2, ctx->r29);
    // lhu         $v1, 0x6($sp)
    ctx->r3 = MEM_HU(0X6, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x0($sp)
    ctx->r2 = MEM_HU(0X0, ctx->r29);
    // lhu         $v1, 0x4($sp)
    ctx->r3 = MEM_HU(0X4, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r2;
    // lhu         $v0, 0x2($sp)
    ctx->r2 = MEM_HU(0X2, ctx->r29);
    // lhu         $v1, 0x6($sp)
    ctx->r3 = MEM_HU(0X6, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x22($t0)
    MEM_H(0X22, ctx->r8) = ctx->r2;
    // lw          $v0, 0xE4($a0)
    ctx->r2 = MEM_W(0XE4, ctx->r4);
    // and         $a1, $t0, $a1
    ctx->r5 = ctx->r8 & ctx->r5;
    // sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_80029160:
    // addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // jr          $ra
    // nop

    return;
    // nop

;}
