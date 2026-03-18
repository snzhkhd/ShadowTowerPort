#include "recomp.h"
#include "disable_warnings.h"

void sub_8001CDF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v1, $v0, 0x5948
    ctx->r3 = ADD32(ctx->r2, 0X5948);
    // sw          $s3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r19;
    // sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // lhu         $t2, 0x44CC($v1)
    ctx->r10 = MEM_HU(0X44CC, ctx->r3);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // beq         $t2, $v0, L_8001D208
    if (ctx->r10 == ctx->r2) {
        // lui         $t0, 0x1F80
        ctx->r8 = S32(0X1F80 << 16);
        goto L_8001D208;
    }
    // lui         $t0, 0x1F80
    ctx->r8 = S32(0X1F80 << 16);
    // addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $s0, $v0, -0x4130
    ctx->r16 = ADD32(ctx->r2, -0X4130);
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $t9, $v0, -0x4248
    ctx->r25 = ADD32(ctx->r2, -0X4248);
    // addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // addiu       $t8, $zero, 0xFE1
    ctx->r24 = ADD32(0, 0XFE1);
L_8001CE48:
    // sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10) << 1;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // lhu         $v0, 0x45CE($v0)
    ctx->r2 = MEM_HU(0X45CE, ctx->r2);
    // nop

    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(0X3, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // sw          $v0, 0x1E4($t0)
    MEM_W(0X1E4, ctx->r8) = ctx->r2;
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
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
    // sll         $v0, $t2, 4
    ctx->r2 = S32(ctx->r10) << 4;
    // addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(0X0, ctx->r2);
    // lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(0X4, ctx->r2);
    // lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(0X8, ctx->r2);
    // ctc2        $t4, $5
    gte_ctc2(ctx, 12, 5);
    // ctc2        $t5, $6
    gte_ctc2(ctx, 13, 6);
    // ctc2        $t6, $7
    gte_ctc2(ctx, 14, 7);
    // lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(0X0, ctx->r3);
    // nop

    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // lw          $v1, 0xC($t0)
    ctx->r3 = MEM_W(0XC, ctx->r8);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r3;
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // lw          $v1, 0xC($t0)
    ctx->r3 = MEM_W(0XC, ctx->r8);
    // lw          $a0, 0x20($t0)
    ctx->r4 = MEM_W(0X20, ctx->r8);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x34($t0)
    ctx->r2 = MEM_W(0X34, ctx->r8);
    // sw          $v1, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r3;
    // sw          $v1, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->r3;
    // sw          $v0, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r2;
    // lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(0X4, ctx->r4);
    // lui         $v0, 0xAAAA
    ctx->r2 = S32(0XAAAA << 16);
    // ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $a3, 0x34($t0)
    ctx->r7 = MEM_W(0X34, ctx->r8);
    // lw          $t1, 0x3C($t0)
    ctx->r9 = MEM_W(0X3C, ctx->r8);
    // mfhi        $s3
    ctx->r19 = hi;
    // srl         $a2, $s3, 1
    ctx->r6 = S32(U32(ctx->r19) >> 1);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // beq         $a2, $t7, L_8001D0D8
    if (ctx->r6 == ctx->r15) {
        // nop
    
        goto L_8001D0D8;
    }
    // nop

    // addiu       $a1, $a3, 0x16
    ctx->r5 = ADD32(ctx->r7, 0X16);
L_8001CF40:
    // lwc2        $0, 0x0($t1)
    gte_lwc2(rdram, ctx, 0, 9, 0);
    // lwc2        $1, 0x4($t1)
    gte_lwc2(rdram, ctx, 1, 9, 4);
    // lwc2        $2, 0x8($t1)
    gte_lwc2(rdram, ctx, 2, 9, 8);
    // lwc2        $3, 0xC($t1)
    gte_lwc2(rdram, ctx, 3, 9, 12);
    // lwc2        $4, 0x10($t1)
    gte_lwc2(rdram, ctx, 4, 9, 16);
    // lwc2        $5, 0x14($t1)
    gte_lwc2(rdram, ctx, 5, 9, 20);
    // nop

    // nop

    // .word       0x4A280030                   # INVALID     $s1, $t0, 0x30 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A280030);
    // addiu       $v1, $a3, 0x8
    ctx->r3 = ADD32(ctx->r7, 0X8);
    // addiu       $v0, $a3, 0x10
    ctx->r2 = ADD32(ctx->r7, 0X10);
    // swc2        $12, 0x0($a3)
    gte_swc2(rdram, ctx, 12, 7, 0);
    // swc2        $13, 0x0($v1)
    gte_swc2(rdram, ctx, 13, 3, 0);
    // swc2        $14, 0x0($v0)
    gte_swc2(rdram, ctx, 14, 2, 0);
    // addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    // addiu       $v1, $a3, 0xC
    ctx->r3 = ADD32(ctx->r7, 0XC);
    // addiu       $v0, $a3, 0x14
    ctx->r2 = ADD32(ctx->r7, 0X14);
    // swc2        $17, 0x0($a0)
    gte_swc2(rdram, ctx, 17, 4, 0);
    // swc2        $18, 0x0($v1)
    gte_swc2(rdram, ctx, 18, 3, 0);
    // swc2        $19, 0x0($v0)
    gte_swc2(rdram, ctx, 19, 2, 0);
    // lw          $a0, 0x64($t0)
    ctx->r4 = MEM_W(0X64, ctx->r8);
    // lw          $v0, 0x68($t0)
    ctx->r2 = MEM_W(0X68, ctx->r8);
    // nop

    // beq         $a0, $v0, L_8001D07C
    if (ctx->r4 == ctx->r2) {
        // subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
        goto L_8001D07C;
    }
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // lh          $v1, -0x12($a1)
    ctx->r3 = MEM_HS(-0X12, ctx->r5);
    // nop

    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_8001CFC4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001CFC4;
    }
    // nop

    // break       7
    do_break(2147602368);
L_8001CFC4:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8001CFDC
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8001CFDC;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8001CFDC
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8001CFDC;
    }
    // nop

    // break       6
    do_break(2147602392);
L_8001CFDC:
    // mflo        $v1
    ctx->r3 = lo;
    // lh          $v0, -0xA($a1)
    ctx->r2 = MEM_HS(-0XA, ctx->r5);
    // sh          $v1, -0x10($a1)
    MEM_H(-0X10, ctx->r5) = ctx->r3;
    // lw          $a0, 0x64($t0)
    ctx->r4 = MEM_W(0X64, ctx->r8);
    // lw          $v1, 0x68($t0)
    ctx->r3 = MEM_W(0X68, ctx->r8);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_8001D00C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8001D00C;
    }
    // nop

    // break       7
    do_break(2147602440);
L_8001D00C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8001D024
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8001D024;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8001D024
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8001D024;
    }
    // nop

    // break       6
    do_break(2147602464);
L_8001D024:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // sh          $v0, -0x8($a1)
    MEM_H(-0X8, ctx->r5) = ctx->r2;
    // lh          $v0, -0x2($a1)
    ctx->r2 = MEM_HS(-0X2, ctx->r5);
    // lw          $a0, 0x64($t0)
    ctx->r4 = MEM_W(0X64, ctx->r8);
    // lw          $v1, 0x68($t0)
    ctx->r3 = MEM_W(0X68, ctx->r8);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_8001D058
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8001D058;
    }
    // nop

    // break       7
    do_break(2147602516);
L_8001D058:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8001D070
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8001D070;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8001D070
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8001D070;
    }
    // nop

    // break       6
    do_break(2147602540);
L_8001D070:
    // mflo        $v0
    ctx->r2 = lo;
    // j           L_8001D088
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    goto L_8001D088;
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_8001D07C:
    // sh          $zero, -0x10($a1)
    MEM_H(-0X10, ctx->r5) = 0;
    // sh          $zero, -0x8($a1)
    MEM_H(-0X8, ctx->r5) = 0;
    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_8001D088:
    // lh          $v0, -0x10($a1)
    ctx->r2 = MEM_HS(-0X10, ctx->r5);
    // nop

    // bgez        $v0, L_8001D09C
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8001D09C;
    }
    // nop

    // sh          $zero, -0x10($a1)
    MEM_H(-0X10, ctx->r5) = 0;
L_8001D09C:
    // lh          $v0, -0x8($a1)
    ctx->r2 = MEM_HS(-0X8, ctx->r5);
    // nop

    // bgez        $v0, L_8001D0B0
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8001D0B0;
    }
    // nop

    // sh          $zero, -0x8($a1)
    MEM_H(-0X8, ctx->r5) = 0;
L_8001D0B0:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // bgez        $v0, L_8001D0C4
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8001D0C4;
    }
    // nop

    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_8001D0C4:
    // addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // bne         $a2, $t7, L_8001CF40
    if (ctx->r6 != ctx->r15) {
        // addiu       $t1, $t1, 0x18
        ctx->r9 = ADD32(ctx->r9, 0X18);
        goto L_8001CF40;
    }
    // addiu       $t1, $t1, 0x18
    ctx->r9 = ADD32(ctx->r9, 0X18);
L_8001D0D8:
    // lw          $v0, 0x20($t0)
    ctx->r2 = MEM_W(0X20, ctx->r8);
    // nop

    // lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(0X4, ctx->r2);
    // lui         $v0, 0xAAAA
    ctx->r2 = S32(0XAAAA << 16);
    // ori         $v0, $v0, 0xAAAB
    ctx->r2 = ctx->r2 | 0XAAAB;
    // multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $s3
    ctx->r19 = hi;
    // srl         $a2, $s3, 1
    ctx->r6 = S32(U32(ctx->r19) >> 1);
    // sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6) << 1;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // subu        $a2, $v1, $v0
    ctx->r6 = SUB32(ctx->r3, ctx->r2);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // beq         $a2, $t7, L_8001D1D4
    if (ctx->r6 == ctx->r15) {
        // nop
    
        goto L_8001D1D4;
    }
    // nop

    // addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // addiu       $a1, $a3, 0x6
    ctx->r5 = ADD32(ctx->r7, 0X6);
L_8001D118:
    // lwc2        $0, 0x0($t1)
    gte_lwc2(rdram, ctx, 0, 9, 0);
    // lwc2        $1, 0x4($t1)
    gte_lwc2(rdram, ctx, 1, 9, 4);
    // nop

    // nop

    // .word       0x4A180001                   # INVALID     $s0, $t8, 0x1 # 00000000 <InstrIdType: CPU_COP2>
    gte_command(ctx, 0x4A180001);
    // swc2        $14, 0x0($a3)
    gte_swc2(rdram, ctx, 14, 7, 0);
    // addiu       $v0, $a3, 0x4
    ctx->r2 = ADD32(ctx->r7, 0X4);
    // swc2        $19, 0x0($v0)
    gte_swc2(rdram, ctx, 19, 2, 0);
    // lw          $a0, 0x64($t0)
    ctx->r4 = MEM_W(0X64, ctx->r8);
    // lw          $v0, 0x68($t0)
    ctx->r2 = MEM_W(0X68, ctx->r8);
    // nop

    // beq         $a0, $v0, L_8001D190
    if (ctx->r4 == ctx->r2) {
        // subu        $v0, $v0, $a0
        ctx->r2 = SUB32(ctx->r2, ctx->r4);
        goto L_8001D190;
    }
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // lh          $v1, -0x2($a1)
    ctx->r3 = MEM_HS(-0X2, ctx->r5);
    // nop

    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // sll         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) << 12;
    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_8001D16C
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001D16C;
    }
    // nop

    // break       7
    do_break(2147602792);
L_8001D16C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8001D184
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8001D184;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8001D184
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8001D184;
    }
    // nop

    // break       6
    do_break(2147602816);
L_8001D184:
    // mflo        $v1
    ctx->r3 = lo;
    // j           L_8001D194
    // sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
    goto L_8001D194;
    // sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_8001D190:
    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_8001D194:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // slti        $v0, $v0, 0xFE2
    ctx->r2 = SIGNED(ctx->r2) < 0XFE2 ? 1 : 0;
    // bne         $v0, $zero, L_8001D1AC
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001D1AC;
    }
    // nop

    // sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
L_8001D1AC:
    // lh          $v0, 0x0($a1)
    ctx->r2 = MEM_HS(0X0, ctx->r5);
    // nop

    // bgez        $v0, L_8001D1C0
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8001D1C0;
    }
    // nop

    // sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_8001D1C0:
    // addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // bne         $a2, $t3, L_8001D118
    if (ctx->r6 != ctx->r11) {
        // addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_8001D118;
    }
    // addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_8001D1D4:
    // addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // lw          $v1, 0x20($t0)
    ctx->r3 = MEM_W(0X20, ctx->r8);
    // lw          $v0, 0x1B0($t0)
    ctx->r2 = MEM_W(0X1B0, ctx->r8);
    // lw          $v1, 0x4($v1)
    ctx->r3 = MEM_W(0X4, ctx->r3);
    // lw          $a0, 0x20($t0)
    ctx->r4 = MEM_W(0X20, ctx->r8);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sw          $v0, 0x1B0($t0)
    MEM_W(0X1B0, ctx->r8) = ctx->r2;
    // lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(0X4, ctx->r4);
    // lw          $v1, 0x34($t0)
    ctx->r3 = MEM_W(0X34, ctx->r8);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // bne         $t2, $t7, L_8001CE48
    if (ctx->r10 != ctx->r15) {
        // sw          $v1, 0x34($t0)
        MEM_W(0X34, ctx->r8) = ctx->r3;
        goto L_8001CE48;
    }
    // sw          $v1, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r3;
L_8001D208:
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
