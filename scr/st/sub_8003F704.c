#include "recomp.h"
#include "disable_warnings.h"

void sub_8003F704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // beq         $a1, $zero, L_8003F7D0
    if (ctx->r5 == 0) {
        // sw          $s0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r16;
        goto L_8003F7D0;
    }
    // sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // addiu       $t0, $t0, -0x6E40
    ctx->r8 = ADD32(ctx->r8, -0X6E40);
    // lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(0X0, ctx->r8);
    // lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(0X4, ctx->r8);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($t0)
    ctx->r12 = MEM_W(0X8, ctx->r8);
    // lw          $t5, 0xC($t0)
    ctx->r13 = MEM_W(0XC, ctx->r8);
    // lw          $t6, 0x10($t0)
    ctx->r14 = MEM_W(0X10, ctx->r8);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(0X60, ctx->r29);
    // addiu       $a0, $a0, -0x6F78
    ctx->r4 = ADD32(ctx->r4, -0X6F78);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // nop

    // nop

    // .word       0x4A486012                   # INVALID     $s2, $t0, 0x6012 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A486012);
    // swc2        $25, 0x0($a1)
    gte_swc2(rdram, ctx, 25, 5, 0);
    // swc2        $26, 0x4($a1)
    gte_swc2(rdram, ctx, 26, 5, 4);
    // swc2        $27, 0x8($a1)
    gte_swc2(rdram, ctx, 27, 5, 8);
    // addiu       $a0, $a0, -0x160
    ctx->r4 = ADD32(ctx->r4, -0X160);
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // lw          $v1, 0x248($a0)
    ctx->r3 = MEM_W(0X248, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(0X4, ctx->r5);
    // lw          $v1, 0x24C($a0)
    ctx->r3 = MEM_W(0X24C, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(0X8, ctx->r5);
    // lw          $v1, 0x250($a0)
    ctx->r3 = MEM_W(0X250, ctx->r4);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
L_8003F7D0:
    // beq         $s2, $zero, L_8003F864
    if (ctx->r18 == 0) {
        // nop
    
        goto L_8003F864;
    }
    // nop

    // beq         $s1, $zero, L_8003F8EC
    if (ctx->r17 == 0) {
        // addiu       $s0, $sp, 0x30
        ctx->r16 = ADD32(ctx->r29, 0X30);
        goto L_8003F8EC;
    }
    // addiu       $s0, $sp, 0x30
    ctx->r16 = ADD32(ctx->r29, 0X30);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    memset_recomp(rdram, ctx);
    goto after_0;
    // addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r2;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x80075154
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    RotMatrixZYX(rdram, ctx);
    goto after_1;
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_1:
    // addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(0X0, ctx->r2);
    // lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(0X4, ctx->r2);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(0X8, ctx->r2);
    // lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(0XC, ctx->r2);
    // lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(0X10, ctx->r2);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // lwc2        $0, 0x0($s0)
    gte_lwc2(rdram, ctx, 0, 16, 0);
    // lwc2        $1, 0x4($s0)
    gte_lwc2(rdram, ctx, 1, 16, 4);
    // nop

    // nop

    // .word       0x4A486012                   # INVALID     $s2, $t0, 0x6012 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A486012);
    // mfc2        $t4, $9
    ctx->r12 = gte_mfc2(ctx, 9);
    // mfc2        $t5, $10
    ctx->r13 = gte_mfc2(ctx, 10);
    // mfc2        $t6, $11
    ctx->r14 = gte_mfc2(ctx, 11);
    // sh          $t4, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r12;
    // sh          $t5, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r13;
    // sh          $t6, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r14;
    // j           L_8003F8E4
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    goto L_8003F8E4;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_8003F864:
    // beq         $s1, $zero, L_8003F8EC
    if (ctx->r17 == 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_8003F8EC;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80078AB4
    // addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    memset_recomp(rdram, ctx);
    goto after_2;
    // addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // addiu       $t0, $t0, -0x6E40
    ctx->r8 = ADD32(ctx->r8, -0X6E40);
    // lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(0X0, ctx->r8);
    // lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(0X4, ctx->r8);
    // ctc2        $t4, $0
    gte_ctc2(ctx, 12, 0);
    // ctc2        $t5, $1
    gte_ctc2(ctx, 13, 1);
    // lw          $t4, 0x8($t0)
    ctx->r12 = MEM_W(0X8, ctx->r8);
    // lw          $t5, 0xC($t0)
    ctx->r13 = MEM_W(0XC, ctx->r8);
    // lw          $t6, 0x10($t0)
    ctx->r14 = MEM_W(0X10, ctx->r8);
    // ctc2        $t4, $2
    gte_ctc2(ctx, 12, 2);
    // ctc2        $t5, $3
    gte_ctc2(ctx, 13, 3);
    // ctc2        $t6, $4
    gte_ctc2(ctx, 14, 4);
    // addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // lwc2        $0, 0x0($v0)
    gte_lwc2(rdram, ctx, 0, 2, 0);
    // lwc2        $1, 0x4($v0)
    gte_lwc2(rdram, ctx, 1, 2, 4);
    // nop

    // nop

    // .word       0x4A486012                   # INVALID     $s2, $t0, 0x6012 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A486012);
    // mfc2        $t4, $9
    ctx->r12 = gte_mfc2(ctx, 9);
    // mfc2        $t5, $10
    ctx->r13 = gte_mfc2(ctx, 10);
    // mfc2        $t6, $11
    ctx->r14 = gte_mfc2(ctx, 11);
    // sh          $t4, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r12;
    // sh          $t5, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r13;
    // sh          $t6, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r14;
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_8003F8E4:
    // jal         0x8004A0F8
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    sub_8004A0F8(rdram, ctx);
    goto after_3;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_3:
L_8003F8EC:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(0X48, ctx->r29);
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
