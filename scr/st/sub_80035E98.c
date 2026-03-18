#include "recomp.h"
#include "disable_warnings.h"

void sub_80035E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // addu        $s6, $a3, $zero
    ctx->r22 = ADD32(ctx->r7, 0);
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(0X70, ctx->r29);
    // addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // jal         0x80078AB4
    // sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    memset_recomp(rdram, ctx);
    goto after_0;
    // sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    after_0:
    // andi        $v0, $s1, 0x20
    ctx->r2 = ctx->r17 & 0X20;
    // srl         $s4, $v0, 5
    ctx->r20 = S32(U32(ctx->r2) >> 5);
    // lui         $v1, 0xFFF0
    ctx->r3 = S32(0XFFF0 << 16);
    // ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // lui         $v0, 0xF
    ctx->r2 = S32(0XF << 16);
    // and         $s5, $s0, $v0
    ctx->r21 = ctx->r16 & ctx->r2;
    // and         $s0, $s0, $v1
    ctx->r16 = ctx->r16 & ctx->r3;
    // andi        $v0, $s0, 0x80
    ctx->r2 = ctx->r16 & 0X80;
    // beq         $v0, $zero, L_80035F18
    if (ctx->r2 == 0) {
        // addiu       $a0, $s3, 0x4
        ctx->r4 = ADD32(ctx->r19, 0X4);
        goto L_80035F18;
    }
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    // addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    // lhu         $a2, 0x16($s3)
    ctx->r6 = MEM_HU(0X16, ctx->r19);
    // jal         0x8003DBE0
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    sub_8003DBE0(rdram, ctx);
    goto after_1;
    // addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_1:
L_80035F18:
    // andi        $v0, $s0, 0x10
    ctx->r2 = ctx->r16 & 0X10;
    // beq         $v0, $zero, L_80036124
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80036124;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lw          $v1, 0x59A4($v0)
    ctx->r3 = MEM_W(0X59A4, ctx->r2);
    // nop

    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $v1, $v1, -0x5EC8
    ctx->r3 = ADD32(ctx->r3, -0X5EC8);
    // beq         $s2, $zero, L_80035F8C
    if (ctx->r18 == 0) {
        // addu        $s0, $v0, $v1
        ctx->r16 = ADD32(ctx->r2, ctx->r3);
        goto L_80035F8C;
    }
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // lw          $v1, 0x74($s0)
    ctx->r3 = MEM_W(0X74, ctx->r16);
    // lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(0X0, ctx->r18);
    // lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(0X7C, ctx->r16);
    // lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(0X8, ctx->r18);
    // subu        $a0, $v1, $a0
    ctx->r4 = SUB32(ctx->r3, ctx->r4);
    // jal         0x8004A1B4
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    sub_8004A1B4(rdram, ctx);
    goto after_2;
    // subu        $a1, $v0, $a1
    ctx->r5 = SUB32(ctx->r2, ctx->r5);
    after_2:
    // addiu       $a1, $v0, 0x800
    ctx->r5 = ADD32(ctx->r2, 0X800);
    // lh          $a0, 0x8E($s0)
    ctx->r4 = MEM_HS(0X8E, ctx->r16);
    // jal         0x8004A148
    // addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    sub_8004A148(rdram, ctx);
    goto after_3;
    // addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    after_3:
    // beq         $v0, $zero, L_80036124
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80036124;
    }
    // nop

L_80035F8C:
    // lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // and         $v0, $s5, $v0
    ctx->r2 = ctx->r21 & ctx->r2;
    // beq         $v0, $zero, L_80035FA4
    if (ctx->r2 == 0) {
        // andi        $s1, $s1, 0xC0
        ctx->r17 = ctx->r17 & 0XC0;
        goto L_80035FA4;
    }
    // andi        $s1, $s1, 0xC0
    ctx->r17 = ctx->r17 & 0XC0;
    // j           L_80035FA8
    // ori         $s1, $s1, 0x10
    ctx->r17 = ctx->r17 | 0X10;
    goto L_80035FA8;
    // ori         $s1, $s1, 0x10
    ctx->r17 = ctx->r17 | 0X10;
L_80035FA4:
    // ori         $s1, $s1, 0x20
    ctx->r17 = ctx->r17 | 0X20;
L_80035FA8:
    // andi        $v0, $s4, 0xFF
    ctx->r2 = ctx->r20 & 0XFF;
    // beq         $v0, $zero, L_80035FC0
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80035FC0;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v1, -0x7088($v0)
    ctx->r3 = MEM_HU(-0X7088, ctx->r2);
    // j           L_80035FC8
    // nop

    goto L_80035FC8;
    // nop

L_80035FC0:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lhu         $v1, -0x7094($v0)
    ctx->r3 = MEM_HU(-0X7094, ctx->r2);
L_80035FC8:
    // lui         $v0, 0xAAAA
    ctx->r2 = S32(0XAAAA << 16);
    // ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t2
    ctx->r10 = hi;
    // srl         $t0, $t2, 2
    ctx->r8 = S32(U32(ctx->r10) >> 2);
    // andi        $v1, $t0, 0xFF
    ctx->r3 = ctx->r8 & 0XFF;
    // sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_80036018
    if (ctx->r2 == 0) {
        // sll         $a1, $v1, 2
        ctx->r5 = S32(ctx->r3) << 2;
        goto L_80036018;
    }
    // sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3) << 2;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // addiu       $v1, $v1, -0x70D8
    ctx->r3 = ADD32(ctx->r3, -0X70D8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lhu         $a0, 0x78($v0)
    ctx->r4 = MEM_HU(0X78, ctx->r2);
    // addu        $v0, $sp, $a1
    ctx->r2 = ADD32(ctx->r29, ctx->r5);
    // sh          $a0, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r4;
    // sh          $a0, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r4;
    // lhu         $a3, 0xB8($v1)
    ctx->r7 = MEM_HU(0XB8, ctx->r3);
    // j           L_80036020
    // andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    goto L_80036020;
    // andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
L_80036018:
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
L_80036020:
    // sltiu       $v0, $v0, 0x6
    ctx->r2 = ctx->r2 < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_80036034
    if (ctx->r2 != 0) {
        // addiu       $a2, $s3, 0x4
        ctx->r6 = ADD32(ctx->r19, 0X4);
        goto L_80036034;
    }
    // addiu       $a2, $s3, 0x4
    ctx->r6 = ADD32(ctx->r19, 0X4);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a2, $v0, -0x701E
    ctx->r6 = ADD32(ctx->r2, -0X701E);
L_80036034:
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $v1, $sp, 0x18
    ctx->r3 = ADD32(ctx->r29, 0X18);
L_8003603C:
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(0X0, ctx->r6);
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // bne         $v0, $zero, L_8003603C
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
        goto L_8003603C;
    }
    // addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // addiu       $a2, $s3, 0xA
    ctx->r6 = ADD32(ctx->r19, 0XA);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $t1, 0xAAAA
    ctx->r9 = S32(0XAAAA << 16);
    // ori         $t1, $t1, 0xAAAB
    ctx->r9 = ctx->r9 | 0XAAAB;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_8003606C:
    // lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(0X0, ctx->r6);
    // nop

    // bne         $v1, $zero, L_80036084
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80036084;
    }
    // nop

    // j           L_800360A4
    // sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
    goto L_800360A4;
    // sh          $zero, 0x6($a0)
    MEM_H(0X6, ctx->r4) = 0;
L_80036084:
    // lhu         $v0, 0x18($a0)
    ctx->r2 = MEM_HU(0X18, ctx->r4);
    // nop

    // multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $v1, $a3
    ctx->r2 = ADD32(ctx->r3, ctx->r7);
    // mfhi        $t2
    ctx->r10 = hi;
    // srl         $v1, $t2, 2
    ctx->r3 = S32(U32(ctx->r10) >> 2);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
L_800360A4:
    // addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // slti        $v0, $a1, 0x6
    ctx->r2 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // bne         $v0, $zero, L_8003606C
    if (ctx->r2 != 0) {
        // addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
        goto L_8003606C;
    }
    // addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // sltiu       $v0, $v0, 0x6
    ctx->r2 = ctx->r2 < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_800360D0
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_800360D0;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // j           L_800360D4
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    goto L_800360D4;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_800360D0:
    // sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_800360D4:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    // jal         0x8004DEF8
    // addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    sub_8004DEF8(rdram, ctx);
    goto after_4;
    // addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    after_4:
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // andi        $v0, $s1, 0x40
    ctx->r2 = ctx->r17 & 0X40;
    // beq         $v0, $zero, L_80036108
    if (ctx->r2 == 0) {
        // lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
        goto L_80036108;
    }
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x80026A88
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_80026A88(rdram, ctx);
    goto after_5;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_5:
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
L_80036108:
    // and         $v0, $s5, $v0
    ctx->r2 = ctx->r21 & ctx->r2;
    // beq         $v0, $zero, L_80036124
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80036124;
    }
    // nop

    // lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(0X70, ctx->r16);
    // nop

    // ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
    // sw          $v0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r2;
L_80036124:
    // lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(0X5C, ctx->r29);
    // lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(0X58, ctx->r29);
    // lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(0X54, ctx->r29);
    // lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(0X50, ctx->r29);
    // lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(0X4C, ctx->r29);
    // lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(0X48, ctx->r29);
    // lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(0X44, ctx->r29);
    // lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // jr          $ra
    // nop

    return;
    // nop

;}
