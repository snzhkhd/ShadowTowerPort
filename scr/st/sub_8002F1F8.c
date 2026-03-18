#include "recomp.h"
#include "disable_warnings.h"

void sub_8002F1F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // lh          $a0, 0x0($t1)
    ctx->r4 = MEM_HS(0X0, ctx->r9);
    // nop

    // bgez        $a0, L_8002F248
    if (SIGNED(ctx->r4) >= 0) {
        // addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
        goto L_8002F248;
    }
    // addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // addiu       $v0, $a0, 0x3F
    ctx->r2 = ADD32(ctx->r4, 0X3F);
L_8002F248:
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lh          $v1, 0x2($t1)
    ctx->r3 = MEM_HS(0X2, ctx->r9);
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // bgez        $v1, L_8002F270
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
        goto L_8002F270;
    }
    // addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // addiu       $a1, $v1, 0xFF
    ctx->r5 = ADD32(ctx->r3, 0XFF);
L_8002F270:
    // sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $s5, $v0, 0x5090
    ctx->r21 = ADD32(ctx->r2, 0X5090);
    // addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // sra         $v0, $a1, 8
    ctx->r2 = S32(ctx->r5) >> 8;
    // sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2) << 8;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $s6, $v0, 16
    ctx->r22 = S32(ctx->r2) >> 16;
L_8002F294:
    // addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
    // beq         $t2, $zero, L_8002F448
    if (ctx->r10 == 0) {
        // addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
        goto L_8002F448;
    }
    // addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // addu        $fp, $s6, $zero
    ctx->r30 = ADD32(ctx->r22, 0);
    // addiu       $s7, $s6, 0xA
    ctx->r23 = ADD32(ctx->r22, 0XA);
    // addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
    // lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(0X1C, ctx->r29);
L_8002F2B0:
    // lw          $a0, 0x304($s5)
    ctx->r4 = MEM_W(0X304, ctx->r21);
    // nop

    // lw          $s1, 0x8($a0)
    ctx->r17 = MEM_W(0X8, ctx->r4);
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // addiu       $v1, $s1, 0x28
    ctx->r3 = ADD32(ctx->r17, 0X28);
    // sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // bne         $v0, $zero, L_8002F464
    if (ctx->r2 != 0) {
        // addiu       $s0, $a2, 0xA
        ctx->r16 = ADD32(ctx->r6, 0XA);
        goto L_8002F464;
    }
    // addiu       $s0, $a2, 0xA
    ctx->r16 = ADD32(ctx->r6, 0XA);
    // sw          $v1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r3;
    // lw          $v0, 0x328($s5)
    ctx->r2 = MEM_W(0X328, ctx->r21);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sw          $v0, 0x328($s5)
    MEM_W(0X328, ctx->r21) = ctx->r2;
    // sb          $a2, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r6;
    // sb          $fp, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r30;
    // sb          $s0, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r16;
    // sb          $fp, 0x15($s1)
    MEM_B(0X15, ctx->r17) = ctx->r30;
    // sb          $a2, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r6;
    // sb          $s7, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r23;
    // sb          $s0, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r16;
    // sb          $s7, 0x25($s1)
    MEM_B(0X25, ctx->r17) = ctx->r23;
    // lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(0X0, ctx->r8);
    // nop

    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // sh          $v0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(0X0, ctx->r8);
    // nop

    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // sh          $v0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r2;
    // sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x2($t0)
    ctx->r2 = MEM_HU(0X2, ctx->r8);
    // nop

    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // sh          $v0, 0x12($s1)
    MEM_H(0X12, ctx->r17) = ctx->r2;
    // sh          $v0, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r2;
    // lhu         $v0, 0x2($t0)
    ctx->r2 = MEM_HU(0X2, ctx->r8);
    // nop

    // addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // sh          $v0, 0x22($s1)
    MEM_H(0X22, ctx->r17) = ctx->r2;
    // sh          $v0, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r2;
    // lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(0X5C, ctx->r29);
    // nop

    // lwl         $v0, 0x3($t2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r10);
    // lwr         $v0, 0x0($t2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r10);
    // nop

    // swl         $v0, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r2);
    // swr         $v0, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r2);
    // lbu         $v0, 0x10($sp)
    ctx->r2 = MEM_BU(0X10, ctx->r29);
    // nop

    // sb          $v0, 0x4($s1)
    MEM_B(0X4, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x11($sp)
    ctx->r2 = MEM_BU(0X11, ctx->r29);
    // nop

    // sb          $v0, 0x5($s1)
    MEM_B(0X5, ctx->r17) = ctx->r2;
    // lbu         $v0, 0x12($sp)
    ctx->r2 = MEM_BU(0X12, ctx->r29);
    // nop

    // sb          $v0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r2;
    // lbu         $a1, 0x3($t2)
    ctx->r5 = MEM_BU(0X3, ctx->r10);
    // lh          $a2, 0x0($t1)
    ctx->r6 = MEM_HS(0X0, ctx->r9);
    // lh          $a3, 0x2($t1)
    ctx->r7 = MEM_HS(0X2, ctx->r9);
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // jal         0x8007C704
    // andi        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 & 0X3;
    GetTPage(rdram, ctx);
    goto after_0;
    // andi        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 & 0X3;
    after_0:
    // sh          $v0, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r2;
    // lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(0X58, ctx->r29);
    // nop

    // lh          $a0, 0x0($t2)
    ctx->r4 = MEM_HS(0X0, ctx->r10);
    // lh          $a1, 0x2($t2)
    ctx->r5 = MEM_HS(0X2, ctx->r10);
    // jal         0x8007C744
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    GetClut(rdram, ctx);
    goto after_1;
    // addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    after_1:
    // lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // sh          $v0, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // sb          $v0, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    // lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // addiu       $s2, $s2, 0xB
    ctx->r18 = ADD32(ctx->r18, 0XB);
    // sb          $v0, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r2;
    // lw          $v1, 0xE4($s5)
    ctx->r3 = MEM_W(0XE4, ctx->r21);
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(0X0, ctx->r3);
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // lw          $v1, 0xE4($s5)
    ctx->r3 = MEM_W(0XE4, ctx->r21);
    // nop

    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // and         $a0, $s1, $a0
    ctx->r4 = ctx->r17 & ctx->r4;
    // and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // slti        $v0, $s3, 0x19
    ctx->r2 = SIGNED(ctx->r19) < 0X19 ? 1 : 0;
    // lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(0X20, ctx->r29);
    // lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(0X24, ctx->r29);
    // bne         $v0, $zero, L_8002F2B0
    if (ctx->r2 != 0) {
        // addu        $a2, $s0, $zero
        ctx->r6 = ADD32(ctx->r16, 0);
        goto L_8002F2B0;
    }
    // addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
L_8002F448:
    // addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(0X18, ctx->r29);
    // addiu       $s6, $s6, 0xA
    ctx->r22 = ADD32(ctx->r22, 0XA);
    // addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // slti        $v0, $t2, 0x5
    ctx->r2 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_8002F294
    if (ctx->r2 != 0) {
        // sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
        goto L_8002F294;
    }
    // sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_8002F464:
    // lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(0X4C, ctx->r29);
    // lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(0X48, ctx->r29);
    // lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(0X44, ctx->r29);
    // lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(0X40, ctx->r29);
    // lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(0X3C, ctx->r29);
    // lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(0X38, ctx->r29);
    // lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(0X34, ctx->r29);
    // lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(0X30, ctx->r29);
    // lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(0X2C, ctx->r29);
    // lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(0X28, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
