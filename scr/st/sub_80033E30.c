#include "recomp.h"
#include "disable_warnings.h"

void sub_80033E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(0X60, ctx->r29);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // jal         0x80033DB8
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    sub_80033DB8(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    after_0:
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // nop

    // bne         $s0, $zero, L_80033E88
    if (ctx->r16 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_80033E88;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // sh          $zero, 0x2($s2)
    MEM_H(0X2, ctx->r18) = 0;
    // j           L_80034038
    // sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    goto L_80034038;
    // sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
L_80033E88:
    // lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(0X8, ctx->r16);
    // nop

    // addu        $a2, $s0, $v0
    ctx->r6 = ADD32(ctx->r16, ctx->r2);
    // slti        $v0, $s1, 0x80
    ctx->r2 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    // bne         $v0, $zero, L_80033EF0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80033EF0;
    }
    // nop

L_80033EA0:
    // andi        $v1, $s1, 0x7F
    ctx->r3 = ctx->r17 & 0X7F;
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(0XC, ctx->r2);
    // nop

    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $s1, $a2, $v0
    ctx->r17 = ADD32(ctx->r6, ctx->r2);
    // sll         $v0, $s4, 3
    ctx->r2 = S32(ctx->r20) << 3;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // lwl         $v1, 0x3($v0)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r2);
    // lwr         $v1, 0x0($v0)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r2);
    // lwl         $a0, 0x7($v0)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r2);
    // lwr         $a0, 0x4($v0)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r2);
    // swl         $v1, 0x3($s2)
    do_swl(rdram, 0X3, ctx->r18, ctx->r3);
    // swr         $v1, 0x0($s2)
    do_swr(rdram, 0X0, ctx->r18, ctx->r3);
    // swl         $a0, 0x7($s2)
    do_swl(rdram, 0X7, ctx->r18, ctx->r4);
    // j           L_80034034
    // swr         $a0, 0x4($s2)
    do_swr(rdram, 0X4, ctx->r18, ctx->r4);
    goto L_80034034;
    // swr         $a0, 0x4($s2)
    do_swr(rdram, 0X4, ctx->r18, ctx->r4);
L_80033EF0:
    // lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(0X4, ctx->r16);
    // nop

    // bne         $v0, $zero, L_80033F08
    if (ctx->r2 != 0) {
        // addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
        goto L_80033F08;
    }
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // j           L_80033EA0
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    goto L_80033EA0;
    // addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80033F08:
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // addiu       $v1, $sp, 0x34
    ctx->r3 = ADD32(ctx->r29, 0X34);
    // lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(0XC, ctx->r6);
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $s1, $a2, $v0
    ctx->r17 = ADD32(ctx->r6, ctx->r2);
    // jal         0x80033CFC
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    sub_80033CFC(rdram, ctx);
    goto after_1;
    // addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_1:
    // lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(0XC, ctx->r16);
    // lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(0X3, ctx->r2);
    // lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(0X2, ctx->r2);
    // addu        $a0, $s0, $a0
    ctx->r4 = ADD32(ctx->r16, ctx->r4);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $a0, $s4, 3
    ctx->r4 = S32(ctx->r20) << 3;
    // addu        $a2, $a0, $s1
    ctx->r6 = ADD32(ctx->r4, ctx->r17);
    // lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(0X0, ctx->r3);
    // lhu         $t0, 0x0($a2)
    ctx->r8 = MEM_HU(0X0, ctx->r6);
    // addu        $a1, $s0, $a1
    ctx->r5 = ADD32(ctx->r16, ctx->r5);
    // addu        $a1, $a0, $a1
    ctx->r5 = ADD32(ctx->r4, ctx->r5);
    // lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(0X0, ctx->r5);
    // lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(0X0, ctx->r2);
    // addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // sh          $t0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r8;
    // lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(0X2, ctx->r6);
    // lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(0X2, ctx->r5);
    // addu        $a3, $s0, $a3
    ctx->r7 = ADD32(ctx->r16, ctx->r7);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x4($a2)
    ctx->r2 = MEM_HU(0X4, ctx->r6);
    // lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(0X4, ctx->r5);
    // addu        $a0, $a0, $a3
    ctx->r4 = ADD32(ctx->r4, ctx->r7);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(0X0, ctx->r4);
    // lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(0X0, ctx->r5);
    // lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(0X34, ctx->r29);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $v1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r3;
    // lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(0X2, ctx->r4);
    // lhu         $v1, 0x2($a1)
    ctx->r3 = MEM_HU(0X2, ctx->r5);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(0X4, ctx->r4);
    // lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(0X4, ctx->r5);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sh          $v0, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r2;
    // mflo        $t1
    ctx->r9 = lo;
    // sra         $v0, $t1, 12
    ctx->r2 = S32(ctx->r9) >> 12;
    // addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // sh          $t0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r8;
    // lh          $v0, 0x2A($sp)
    ctx->r2 = MEM_HS(0X2A, ctx->r29);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x22($sp)
    ctx->r2 = MEM_HU(0X22, ctx->r29);
    // mflo        $t1
    ctx->r9 = lo;
    // sra         $v1, $t1, 12
    ctx->r3 = S32(ctx->r9) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
    // lh          $v0, 0x2C($sp)
    ctx->r2 = MEM_HS(0X2C, ctx->r29);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lhu         $v0, 0x24($sp)
    ctx->r2 = MEM_HU(0X24, ctx->r29);
    // mflo        $t1
    ctx->r9 = lo;
    // sra         $v1, $t1, 12
    ctx->r3 = S32(ctx->r9) >> 12;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r2;
L_80034034:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80034038:
    // lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(0X4C, ctx->r29);
    // lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(0X48, ctx->r29);
    // lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(0X44, ctx->r29);
    // lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(0X40, ctx->r29);
    // lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(0X3C, ctx->r29);
    // lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(0X38, ctx->r29);
    // addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // jr          $ra
    // nop

    return;
    // nop

;}
