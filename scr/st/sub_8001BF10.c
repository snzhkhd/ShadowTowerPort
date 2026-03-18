#include "recomp.h"
#include "disable_warnings.h"

void sub_8001BF10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // srl         $v0, $a1, 1
    ctx->r2 = S32(U32(ctx->r5) >> 1);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // andi        $s1, $v0, 0x2
    ctx->r17 = ctx->r2 & 0X2;
    // andi        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 & 0X3;
    // sll         $a1, $a1, 21
    ctx->r5 = S32(ctx->r5) << 21;
    // or          $s1, $s1, $a1
    ctx->r17 = ctx->r17 | ctx->r5;
    // lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    // andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(0XC, ctx->r16);
    // ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(0X8, ctx->r2);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $a2, $v0, $a1
    ctx->r6 = ADD32(ctx->r2, ctx->r5);
    // lbu         $a1, 0x6DFC($a2)
    ctx->r5 = MEM_BU(0X6DFC, ctx->r6);
    // addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // andi        $v0, $a1, 0x2
    ctx->r2 = ctx->r5 & 0X2;
    // beq         $v0, $zero, L_8001BFBC
    if (ctx->r2 == 0) {
        // sw          $a0, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r4;
        goto L_8001BFBC;
    }
    // sw          $a0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r4;
    // andi        $v0, $a1, 0x10
    ctx->r2 = ctx->r5 & 0X10;
    // beq         $v0, $zero, L_8001BFA8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001BFA8;
    }
    // nop

    // lw          $v1, 0x6DF8($a2)
    ctx->r3 = MEM_W(0X6DF8, ctx->r6);
    // addiu       $v0, $zero, -0x78
    ctx->r2 = ADD32(0, -0X78);
    // sra         $v1, $v1, 13
    ctx->r3 = S32(ctx->r3) >> 13;
    // j           L_8001BFC0
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_8001BFC0;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8001BFA8:
    // lw          $v1, 0x6DF8($a2)
    ctx->r3 = MEM_W(0X6DF8, ctx->r6);
    // addiu       $v0, $zero, -0x60
    ctx->r2 = ADD32(0, -0X60);
    // sra         $v1, $v1, 11
    ctx->r3 = S32(ctx->r3) >> 11;
    // j           L_8001BFC0
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_8001BFC0;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_8001BFBC:
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
L_8001BFC0:
    // sb          $v0, 0x62($s0)
    MEM_B(0X62, ctx->r16) = ctx->r2;
    // sb          $v0, 0x61($s0)
    MEM_B(0X61, ctx->r16) = ctx->r2;
    // sb          $v0, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r2;
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v1, 0x6DFC($v1)
    ctx->r3 = MEM_BU(0X6DFC, ctx->r3);
    // nop

    // andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // beq         $v0, $zero, L_8001C01C
    if (ctx->r2 == 0) {
        // addiu       $t0, $zero, 0x6
        ctx->r8 = ADD32(0, 0X6);
        goto L_8001C01C;
    }
    // addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // sll         $t4, $t0, 4
    ctx->r12 = S32(ctx->r8) << 4;
    // sll         $t5, $t1, 4
    ctx->r13 = S32(ctx->r9) << 4;
    // sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10) << 4;
    // ctc2        $t4, $21
    gte_ctc2(ctx, 12, 21);
    // ctc2        $t5, $22
    gte_ctc2(ctx, 13, 22);
    // ctc2        $t6, $23
    gte_ctc2(ctx, 14, 23);
    // j           L_8001C074
    // nop

    goto L_8001C074;
    // nop

L_8001C01C:
    // andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // beq         $v0, $zero, L_8001C050
    if (ctx->r2 == 0) {
        // addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
        goto L_8001C050;
    }
    // addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // addu        $t2, $t1, $zero
    ctx->r10 = ADD32(ctx->r9, 0);
    // sll         $t4, $t0, 4
    ctx->r12 = S32(ctx->r8) << 4;
    // sll         $t5, $t1, 4
    ctx->r13 = S32(ctx->r9) << 4;
    // sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10) << 4;
    // ctc2        $t4, $21
    gte_ctc2(ctx, 12, 21);
    // ctc2        $t5, $22
    gte_ctc2(ctx, 13, 22);
    // ctc2        $t6, $23
    gte_ctc2(ctx, 14, 23);
    // j           L_8001C074
    // nop

    goto L_8001C074;
    // nop

L_8001C050:
    // addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // addu        $t1, $t0, $zero
    ctx->r9 = ADD32(ctx->r8, 0);
    // addu        $t2, $t0, $zero
    ctx->r10 = ADD32(ctx->r8, 0);
    // sll         $t4, $t0, 4
    ctx->r12 = S32(ctx->r8) << 4;
    // sll         $t5, $t1, 4
    ctx->r13 = S32(ctx->r9) << 4;
    // sll         $t6, $t2, 4
    ctx->r14 = S32(ctx->r10) << 4;
    // ctc2        $t4, $21
    gte_ctc2(ctx, 12, 21);
    // ctc2        $t5, $22
    gte_ctc2(ctx, 13, 22);
    // ctc2        $t6, $23
    gte_ctc2(ctx, 14, 23);
L_8001C074:
    // lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(0X20, ctx->r16);
    // lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(0X0, ctx->r16);
    // lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(0XC, ctx->r16);
    // lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(0X10, ctx->r2);
    // lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(0X20, ctx->r16);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sw          $a1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r5;
    // lhu         $a0, 0x18($v1)
    ctx->r4 = MEM_HU(0X18, ctx->r3);
    // jal         0x8001A038
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    sub_8001A038(rdram, ctx);
    goto after_0;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_0:
    // lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(0X1C, ctx->r16);
    // lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(0X20, ctx->r16);
    // lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(0X0, ctx->r16);
    // lhu         $a0, 0x1C($v0)
    ctx->r4 = MEM_HU(0X1C, ctx->r2);
    // jal         0x8001A6EC
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    sub_8001A6EC(rdram, ctx);
    goto after_1;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_1:
    // lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(0X1C, ctx->r16);
    // lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(0X20, ctx->r16);
    // lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(0X0, ctx->r16);
    // lhu         $a0, 0x1A($v0)
    ctx->r4 = MEM_HU(0X1A, ctx->r2);
    // jal         0x8001AE7C
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    sub_8001AE7C(rdram, ctx);
    goto after_2;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_2:
    // lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(0X1C, ctx->r16);
    // lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(0X20, ctx->r16);
    // lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(0X0, ctx->r16);
    // lhu         $a0, 0x1E($v0)
    ctx->r4 = MEM_HU(0X1E, ctx->r2);
    // jal         0x8001B5DC
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    sub_8001B5DC(rdram, ctx);
    goto after_3;
    // addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_3:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // jr          $ra
    // nop

    return;
    // nop

;}
