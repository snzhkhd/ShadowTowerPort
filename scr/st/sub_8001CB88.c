#include "recomp.h"
#include "disable_warnings.h"

void sub_8001CB88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v1, $v0, 0x5948
    ctx->r3 = ADD32(ctx->r2, 0X5948);
    // lhu         $a3, 0x44CC($v1)
    ctx->r7 = MEM_HU(0X44CC, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // beq         $a3, $v0, L_8001CDF0
    if (ctx->r7 == ctx->r2) {
        // lui         $a1, 0x1F80
        ctx->r5 = S32(0X1F80 << 16);
        goto L_8001CDF0;
    }
    // lui         $a1, 0x1F80
    ctx->r5 = S32(0X1F80 << 16);
    // addu        $t6, $v1, $zero
    ctx->r14 = ADD32(ctx->r3, 0);
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $t5, $v0, -0x4130
    ctx->r13 = ADD32(ctx->r2, -0X4130);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $t0, $v0, -0x70D8
    ctx->r8 = ADD32(ctx->r2, -0X70D8);
    // ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // addiu       $t3, $zero, 0x7FFF
    ctx->r11 = ADD32(0, 0X7FFF);
    // sll         $v0, $a3, 4
    ctx->r2 = S32(ctx->r7) << 4;
    // addu        $a2, $v0, $a0
    ctx->r6 = ADD32(ctx->r2, ctx->r4);
L_8001CBCC:
    // sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7) << 1;
    // addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // lhu         $v0, 0x45CE($v0)
    ctx->r2 = MEM_HU(0X45CE, ctx->r2);
    // nop

    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(0X8, ctx->r4);
    // nop

    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // sw          $v0, 0x128($a1)
    MEM_W(0X128, ctx->r5) = ctx->r2;
    // lbu         $v1, 0x9($a0)
    ctx->r3 = MEM_BU(0X9, ctx->r4);
    // lbu         $v0, 0xB($a0)
    ctx->r2 = MEM_BU(0XB, ctx->r4);
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // addiu       $v0, $v0, -0x80
    ctx->r2 = ADD32(ctx->r2, -0X80);
    // sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2) << 7;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x128($a1)
    ctx->r2 = MEM_W(0X128, ctx->r5);
    // sw          $v1, 0x12C($a1)
    MEM_W(0X12C, ctx->r5) = ctx->r3;
    // lw          $v1, 0x248($t0)
    ctx->r3 = MEM_W(0X248, ctx->r8);
    // lbu         $a0, 0xA($a0)
    ctx->r4 = MEM_BU(0XA, ctx->r4);
    // sw          $zero, 0x20C($a1)
    MEM_W(0X20C, ctx->r5) = 0;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x128($a1)
    MEM_W(0X128, ctx->r5) = ctx->r2;
    // lh          $v0, 0x2CE($t0)
    ctx->r2 = MEM_HS(0X2CE, ctx->r8);
    // lw          $v1, 0x24C($t0)
    ctx->r3 = MEM_W(0X24C, ctx->r8);
    // sll         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4) << 12;
    // sw          $a0, 0x130($a1)
    MEM_W(0X130, ctx->r5) = ctx->r4;
    // lh          $a0, 0x2D2($t0)
    ctx->r4 = MEM_HS(0X2D2, ctx->r8);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x12C($a1)
    ctx->r2 = MEM_W(0X12C, ctx->r5);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // lw          $v1, 0x130($a1)
    ctx->r3 = MEM_W(0X130, ctx->r5);
    // sw          $v0, 0x12C($a1)
    MEM_W(0X12C, ctx->r5) = ctx->r2;
    // lw          $a0, 0x250($t0)
    ctx->r4 = MEM_W(0X250, ctx->r8);
    // lw          $v0, 0x128($a1)
    ctx->r2 = MEM_W(0X128, ctx->r5);
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // sltu        $v0, $t1, $v0
    ctx->r2 = ctx->r9 < ctx->r2 ? 1 : 0;
    // bne         $v0, $zero, L_8001CCA0
    if (ctx->r2 != 0) {
        // sw          $v1, 0x130($a1)
        MEM_W(0X130, ctx->r5) = ctx->r3;
        goto L_8001CCA0;
    }
    // sw          $v1, 0x130($a1)
    MEM_W(0X130, ctx->r5) = ctx->r3;
    // lw          $v1, 0x12C($a1)
    ctx->r3 = MEM_W(0X12C, ctx->r5);
    // nop

    // slt         $v0, $t3, $v1
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8001CCA0
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, -0x8000
        ctx->r2 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
        goto L_8001CCA0;
    }
    // slti        $v0, $v1, -0x8000
    ctx->r2 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // bne         $v0, $zero, L_8001CCA0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001CCA0;
    }
    // nop

    // lw          $v1, 0x130($a1)
    ctx->r3 = MEM_W(0X130, ctx->r5);
    // j           L_8001CD08
    // slt         $v0, $t3, $v1
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
    goto L_8001CD08;
    // slt         $v0, $t3, $v1
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r3) ? 1 : 0;
L_8001CCA0:
    // lw          $v0, 0x128($a1)
    ctx->r2 = MEM_W(0X128, ctx->r5);
    // lw          $v1, 0x130($a1)
    ctx->r3 = MEM_W(0X130, ctx->r5);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sw          $v0, 0x128($a1)
    MEM_W(0X128, ctx->r5) = ctx->r2;
    // lw          $v0, 0x12C($a1)
    ctx->r2 = MEM_W(0X12C, ctx->r5);
    // sra         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) >> 1;
    // sw          $v1, 0x130($a1)
    MEM_W(0X130, ctx->r5) = ctx->r3;
    // lw          $v1, 0x20C($a1)
    ctx->r3 = MEM_W(0X20C, ctx->r5);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // sw          $v0, 0x12C($a1)
    MEM_W(0X12C, ctx->r5) = ctx->r2;
    // lw          $v0, 0x128($a1)
    ctx->r2 = MEM_W(0X128, ctx->r5);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // sltu        $v0, $t1, $v0
    ctx->r2 = ctx->r9 < ctx->r2 ? 1 : 0;
    // bne         $v0, $zero, L_8001CCA0
    if (ctx->r2 != 0) {
        // sw          $v1, 0x20C($a1)
        MEM_W(0X20C, ctx->r5) = ctx->r3;
        goto L_8001CCA0;
    }
    // sw          $v1, 0x20C($a1)
    MEM_W(0X20C, ctx->r5) = ctx->r3;
    // lw          $v1, 0x12C($a1)
    ctx->r3 = MEM_W(0X12C, ctx->r5);
    // addiu       $a0, $zero, 0x7FFF
    ctx->r4 = ADD32(0, 0X7FFF);
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8001CCA0
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, -0x8000
        ctx->r2 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
        goto L_8001CCA0;
    }
    // slti        $v0, $v1, -0x8000
    ctx->r2 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // bne         $v0, $zero, L_8001CCA0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001CCA0;
    }
    // nop

    // lw          $v1, 0x130($a1)
    ctx->r3 = MEM_W(0X130, ctx->r5);
    // nop

    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
L_8001CD08:
    // bne         $v0, $zero, L_8001CCA0
    if (ctx->r2 != 0) {
        // slti        $v0, $v1, -0x8000
        ctx->r2 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
        goto L_8001CCA0;
    }
    // slti        $v0, $v1, -0x8000
    ctx->r2 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // bne         $v0, $zero, L_8001CCA0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001CCA0;
    }
    // nop

    // lhu         $v0, 0x128($a1)
    ctx->r2 = MEM_HU(0X128, ctx->r5);
    // lhu         $v1, 0x12C($a1)
    ctx->r3 = MEM_HU(0X12C, ctx->r5);
    // lhu         $a0, 0x130($a1)
    ctx->r4 = MEM_HU(0X130, ctx->r5);
    // sh          $v0, 0x120($a1)
    MEM_H(0X120, ctx->r5) = ctx->r2;
    // addiu       $v0, $a1, 0x120
    ctx->r2 = ADD32(ctx->r5, 0X120);
    // sh          $v1, 0x122($a1)
    MEM_H(0X122, ctx->r5) = ctx->r3;
    // sh          $a0, 0x124($a1)
    MEM_H(0X124, ctx->r5) = ctx->r4;
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // nop

    // nop

    // .word       0x4A480012                   # INVALID     $s2, $t0, 0x12 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A480012);
    // addiu       $v0, $a1, 0xA8
    ctx->r2 = ADD32(ctx->r5, 0XA8);
    // swc2        $25, 0x0($v0)
    gte_swc2(rdram, ctx, 25, 2, 0);
    // swc2        $26, 0x4($v0)
    gte_swc2(rdram, ctx, 26, 2, 4);
    // swc2        $27, 0x8($v0)
    gte_swc2(rdram, ctx, 27, 2, 8);
    // addiu       $v0, $a1, 0x58
    ctx->r2 = ADD32(ctx->r5, 0X58);
    // cfc2        $t4, $31
    ctx->r12 = gte_cfc2(ctx, 31);
    // nop

    // sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // lw          $v0, 0x20C($a1)
    ctx->r2 = MEM_W(0X20C, ctx->r5);
    // nop

    // sw          $v0, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r2;
    // lw          $v1, 0x20C($a1)
    ctx->r3 = MEM_W(0X20C, ctx->r5);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // beq         $v1, $v0, L_8001CDC0
    if (ctx->r3 == ctx->r2) {
        // sw          $v1, 0x20C($a1)
        MEM_W(0X20C, ctx->r5) = ctx->r3;
        goto L_8001CDC0;
    }
    // sw          $v1, 0x20C($a1)
    MEM_W(0X20C, ctx->r5) = ctx->r3;
    // addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_8001CD8C:
    // lw          $v0, 0xA8($a1)
    ctx->r2 = MEM_W(0XA8, ctx->r5);
    // lw          $v1, 0xAC($a1)
    ctx->r3 = MEM_W(0XAC, ctx->r5);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // sw          $v0, 0xA8($a1)
    MEM_W(0XA8, ctx->r5) = ctx->r2;
    // lw          $v0, 0xB0($a1)
    ctx->r2 = MEM_W(0XB0, ctx->r5);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // sw          $v1, 0xAC($a1)
    MEM_W(0XAC, ctx->r5) = ctx->r3;
    // lw          $v1, 0x20C($a1)
    ctx->r3 = MEM_W(0X20C, ctx->r5);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // sw          $v0, 0xB0($a1)
    MEM_W(0XB0, ctx->r5) = ctx->r2;
    // bne         $v1, $a0, L_8001CD8C
    if (ctx->r3 != ctx->r4) {
        // sw          $v1, 0x20C($a1)
        MEM_W(0X20C, ctx->r5) = ctx->r3;
        goto L_8001CD8C;
    }
    // sw          $v1, 0x20C($a1)
    MEM_W(0X20C, ctx->r5) = ctx->r3;
L_8001CDC0:
    // lw          $v0, 0xA8($a1)
    ctx->r2 = MEM_W(0XA8, ctx->r5);
    // nop

    // sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // lw          $v0, 0xAC($a1)
    ctx->r2 = MEM_W(0XAC, ctx->r5);
    // nop

    // sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // lw          $v0, 0xB0($a1)
    ctx->r2 = MEM_W(0XB0, ctx->r5);
    // addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // sw          $v0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r2;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $a3, $v0, L_8001CBCC
    if (ctx->r7 != ctx->r2) {
        // addiu       $a2, $a2, -0x10
        ctx->r6 = ADD32(ctx->r6, -0X10);
        goto L_8001CBCC;
    }
    // addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
L_8001CDF0:
    // jr          $ra
    // nop

    return;
    // nop

;}
