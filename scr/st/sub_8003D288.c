#include "recomp.h"
#include "disable_warnings.h"

void sub_8003D288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addiu       $a3, $v0, 0x1CA4
    ctx->r7 = ADD32(ctx->r2, 0X1CA4);
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(0X4, ctx->r7);
    // lw          $a2, 0x8($a3)
    ctx->r6 = MEM_W(0X8, ctx->r7);
    // sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // sw          $a0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r4;
    // sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // lw          $v1, 0xC($a3)
    ctx->r3 = MEM_W(0XC, ctx->r7);
    // nop

    // sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // lui         $a2, 0x801A
    ctx->r6 = S32(0X801A << 16);
    // addiu       $a3, $a2, -0x70D8
    ctx->r7 = ADD32(ctx->r6, -0X70D8);
    // lbu         $v0, 0x189($a3)
    ctx->r2 = MEM_BU(0X189, ctx->r7);
    // nop

    // beq         $v0, $zero, L_8003D430
    if (ctx->r2 == 0) {
        // ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
        goto L_8003D430;
    }
    // ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // lhu         $v1, 0x58($a3)
    ctx->r3 = MEM_HU(0X58, ctx->r7);
    // nop

    // beq         $v1, $v0, L_8003D430
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $t0, 2
        ctx->r2 = S32(ctx->r8) << 2;
        goto L_8003D430;
    }
    // sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8) << 2;
    // addu        $a0, $v0, $t0
    ctx->r4 = ADD32(ctx->r2, ctx->r8);
    // lhu         $v1, -0x70D8($a2)
    ctx->r3 = MEM_HU(-0X70D8, ctx->r6);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8003D32C
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4) << 1;
        goto L_8003D32C;
    }
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // lbu         $v0, 0x219($a3)
    ctx->r2 = MEM_BU(0X219, ctx->r7);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8003D380
    // sb          $v0, 0x219($a3)
    MEM_B(0X219, ctx->r7) = ctx->r2;
    goto L_8003D380;
    // sb          $v0, 0x219($a3)
    MEM_B(0X219, ctx->r7) = ctx->r2;
L_8003D32C:
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_8003D33C
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8003D33C;
    }
    // nop

    // break       7
    do_break(2147734328);
L_8003D33C:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_8003D354
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003D354;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003D354
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003D354;
    }
    // nop

    // break       6
    do_break(2147734352);
L_8003D354:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // addiu       $a2, $v0, 0x1
    ctx->r6 = ADD32(ctx->r2, 0X1);
    // blez        $a2, L_8003D56C
    if (SIGNED(ctx->r6) <= 0) {
        // sll         $v0, $a2, 1
        ctx->r2 = S32(ctx->r6) << 1;
        goto L_8003D56C;
    }
    // sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6) << 1;
    // lbu         $v1, 0x219($a3)
    ctx->r3 = MEM_BU(0X219, ctx->r7);
    // lbu         $a0, 0x21A($a3)
    ctx->r4 = MEM_BU(0X21A, ctx->r7);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // sb          $v1, 0x219($a3)
    MEM_B(0X219, ctx->r7) = ctx->r3;
    // sb          $a0, 0x21A($a3)
    MEM_B(0X21A, ctx->r7) = ctx->r4;
L_8003D380:
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $t0, $v0, -0x70D8
    ctx->r8 = ADD32(ctx->r2, -0X70D8);
    // lbu         $v1, 0x219($t0)
    ctx->r3 = MEM_BU(0X219, ctx->r8);
    // lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $a2
    ctx->r6 = hi;
    // lbu         $a0, 0x21A($t0)
    ctx->r4 = MEM_BU(0X21A, ctx->r8);
    // nop

    // multu       $a0, $v0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // srl         $v0, $a2, 2
    ctx->r2 = S32(U32(ctx->r6) >> 2);
    // andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // mfhi        $a3
    ctx->r7 = hi;
    // srl         $v0, $a3, 2
    ctx->r2 = S32(U32(ctx->r7) >> 2);
    // andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6) << 2;
    // addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17) << 2;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // andi        $v0, $a1, 0x400
    ctx->r2 = ctx->r5 & 0X400;
    // sb          $v1, 0x219($t0)
    MEM_B(0X219, ctx->r8) = ctx->r3;
    // beq         $v0, $zero, L_8003D400
    if (ctx->r2 == 0) {
        // sb          $a0, 0x21A($t0)
        MEM_B(0X21A, ctx->r8) = ctx->r4;
        goto L_8003D400;
    }
    // sb          $a0, 0x21A($t0)
    MEM_B(0X21A, ctx->r8) = ctx->r4;
    // lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(0X2C, ctx->r8);
    // lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8003D404
    if (ctx->r2 != 0) {
        // andi        $v0, $a1, 0x1000
        ctx->r2 = ctx->r5 & 0X1000;
        goto L_8003D404;
    }
    // andi        $v0, $a1, 0x1000
    ctx->r2 = ctx->r5 & 0X1000;
    // sll         $a2, $a2, 1
    ctx->r6 = S32(ctx->r6) << 1;
    // sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17) << 1;
L_8003D400:
    // andi        $v0, $a1, 0x1000
    ctx->r2 = ctx->r5 & 0X1000;
L_8003D404:
    // beq         $v0, $zero, L_8003D418
    if (ctx->r2 == 0) {
        // sll         $v0, $a2, 2
        ctx->r2 = S32(ctx->r6) << 2;
        goto L_8003D418;
    }
    // sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6) << 2;
    // addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17) << 2;
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
L_8003D418:
    // addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // jal         0x8003D104
    // addiu       $a1, $a1, -0x7080
    ctx->r5 = ADD32(ctx->r5, -0X7080);
    sub_8003D104(rdram, ctx);
    goto after_0;
    // addiu       $a1, $a1, -0x7080
    ctx->r5 = ADD32(ctx->r5, -0X7080);
    after_0:
    // j           L_8003D524
    // addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    goto L_8003D524;
    // addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_8003D430:
    // sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8) << 2;
    // addu        $a0, $v0, $t0
    ctx->r4 = ADD32(ctx->r2, ctx->r8);
    // sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4) << 2;
    // lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // lhu         $a2, -0x70D8($v1)
    ctx->r6 = MEM_HU(-0X70D8, ctx->r3);
    // nop

    // slt         $v0, $v0, $a2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // bne         $v0, $zero, L_8003D56C
    if (ctx->r2 != 0) {
        // addiu       $a3, $v1, -0x70D8
        ctx->r7 = ADD32(ctx->r3, -0X70D8);
        goto L_8003D56C;
    }
    // addiu       $a3, $v1, -0x70D8
    ctx->r7 = ADD32(ctx->r3, -0X70D8);
    // sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4) << 1;
    // div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // bne         $a2, $zero, L_8003D468
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8003D468;
    }
    // nop

    // break       7
    do_break(2147734628);
L_8003D468:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a2, $at, L_8003D480
    if (ctx->r6 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8003D480;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8003D480
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8003D480;
    }
    // nop

    // break       6
    do_break(2147734652);
L_8003D480:
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // addiu       $a2, $v0, 0x1
    ctx->r6 = ADD32(ctx->r2, 0X1);
    // blez        $a2, L_8003D56C
    if (SIGNED(ctx->r6) <= 0) {
        // sll         $v1, $a2, 1
        ctx->r3 = S32(ctx->r6) << 1;
        goto L_8003D56C;
    }
    // sll         $v1, $a2, 1
    ctx->r3 = S32(ctx->r6) << 1;
    // lbu         $v0, 0x21A($a3)
    ctx->r2 = MEM_BU(0X21A, ctx->r7);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $v0, 0x21A($a3)
    MEM_B(0X21A, ctx->r7) = ctx->r2;
    // lbu         $v1, 0x21A($a3)
    ctx->r3 = MEM_BU(0X21A, ctx->r7);
    // lui         $v0, 0xCCCC
    ctx->r2 = S32(0XCCCC << 16);
    // ori         $v0, $v0, 0xCCCD
    ctx->r2 = ctx->r2 | 0XCCCD;
    // multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t1
    ctx->r9 = hi;
    // srl         $v0, $t1, 2
    ctx->r2 = S32(U32(ctx->r9) >> 2);
    // andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17) << 2;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // andi        $v0, $a1, 0x400
    ctx->r2 = ctx->r5 & 0X400;
    // beq         $v0, $zero, L_8003D4F0
    if (ctx->r2 == 0) {
        // sb          $v1, 0x21A($a3)
        MEM_B(0X21A, ctx->r7) = ctx->r3;
        goto L_8003D4F0;
    }
    // sb          $v1, 0x21A($a3)
    MEM_B(0X21A, ctx->r7) = ctx->r3;
    // lw          $v0, 0x2C($a3)
    ctx->r2 = MEM_W(0X2C, ctx->r7);
    // lui         $v1, 0x80
    ctx->r3 = S32(0X80 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8003D4F4
    if (ctx->r2 != 0) {
        // andi        $v0, $a1, 0x1000
        ctx->r2 = ctx->r5 & 0X1000;
        goto L_8003D4F4;
    }
    // andi        $v0, $a1, 0x1000
    ctx->r2 = ctx->r5 & 0X1000;
    // sll         $s1, $s1, 1
    ctx->r17 = S32(ctx->r17) << 1;
L_8003D4F0:
    // andi        $v0, $a1, 0x1000
    ctx->r2 = ctx->r5 & 0X1000;
L_8003D4F4:
    // beq         $v0, $zero, L_8003D500
    if (ctx->r2 == 0) {
        // sll         $v0, $s1, 2
        ctx->r2 = S32(ctx->r17) << 2;
        goto L_8003D500;
    }
    // sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17) << 2;
    // addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
L_8003D500:
    // jal         0x80078AC4
    // nop

    rand_recomp(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2) << 2;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $s3, $v1, 15
    ctx->r19 = S32(ctx->r3) >> 15;
    // slti        $v0, $s3, 0x5
    ctx->r2 = SIGNED(ctx->r19) < 0X5 ? 1 : 0;
    // bne         $v0, $zero, L_8003D528
    if (ctx->r2 != 0) {
        // addiu       $s0, $zero, 0x3
        ctx->r16 = ADD32(0, 0X3);
        goto L_8003D528;
    }
    // addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_8003D524:
    // addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_8003D528:
    // ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // addiu       $s2, $sp, 0x1C
    ctx->r18 = ADD32(ctx->r29, 0X1C);
L_8003D534:
    // lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(0X0, ctx->r18);
    // nop

    // lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(0X0, ctx->r5);
    // nop

    // beq         $v0, $s5, L_8003D560
    if (ctx->r2 == ctx->r21) {
        // nop
    
        goto L_8003D560;
    }
    // nop

    // bne         $s0, $s3, L_8003D558
    if (ctx->r16 != ctx->r19) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8003D558;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // sll         $a0, $s1, 1
    ctx->r4 = S32(ctx->r17) << 1;
L_8003D558:
    // jal         0x8003D104
    // nop

    sub_8003D104(rdram, ctx);
    goto after_2;
    // nop

    after_2:
L_8003D560:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // bne         $s0, $s4, L_8003D534
    if (ctx->r16 != ctx->r20) {
        // addiu       $s2, $s2, -0x4
        ctx->r18 = ADD32(ctx->r18, -0X4);
        goto L_8003D534;
    }
    // addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
L_8003D56C:
    // lw          $ra, 0x38($sp)
    ctx->r31 = MEM_W(0X38, ctx->r29);
    // lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(0X34, ctx->r29);
    // lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(0X30, ctx->r29);
    // lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(0X2C, ctx->r29);
    // lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(0X28, ctx->r29);
    // lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // jr          $ra
    // nop

    return;
    // nop

;}
