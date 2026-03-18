#include "recomp.h"
#include "disable_warnings.h"

void sub_80054368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(0X2, ctx->r17);
    // nop

    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 6
    ctx->r3 = S32(ctx->r3) << 6;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, -0x29C8
    ctx->r2 = ADD32(ctx->r2, -0X29C8);
    // addu        $s3, $v1, $v0
    ctx->r19 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(0X70, ctx->r17);
    // lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // beq         $v0, $zero, L_80054834
    if (ctx->r2 == 0) {
        // addu        $s0, $a2, $zero
        ctx->r16 = ADD32(ctx->r6, 0);
        goto L_80054834;
    }
    // addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // bne         $s4, $zero, L_8005446C
    if (ctx->r20 != 0) {
        // lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
        goto L_8005446C;
    }
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // lh          $v1, 0x36($s1)
    ctx->r3 = MEM_HS(0X36, ctx->r17);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $v1, $v0, L_80054834
    if (ctx->r3 != ctx->r2) {
        // addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
        goto L_80054834;
    }
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x8004B1E8
    // addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    sub_8004B1E8(rdram, ctx);
    goto after_0;
    // addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    after_0:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_80054834
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80054834;
    }
    // nop

    // lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(0X1, ctx->r3);
    // nop

    // sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(0XC, ctx->r3);
    // nop

    // sh          $v0, 0xB0($s1)
    MEM_H(0XB0, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_80054418
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $v0, $zero, 0x1000
        ctx->r2 = ADD32(0, 0X1000);
        goto L_80054418;
    }
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // j           L_8005441C
    // sh          $zero, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = 0;
    goto L_8005441C;
    // sh          $zero, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = 0;
L_80054418:
    // sh          $v0, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r2;
L_8005441C:
    // lh          $v0, 0xC($v1)
    ctx->r2 = MEM_HS(0XC, ctx->r3);
    // addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80054434
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80054434;
    }
    // nop

    // break       7
    do_break(2147828784);
L_80054434:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_8005444C
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8005444C;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_8005444C
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_8005444C;
    }
    // nop

    // break       6
    do_break(2147828808);
L_8005444C:
    // mflo        $v1
    ctx->r3 = lo;
    // lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // j           L_80054484
    // sb          $v1, 0x6E18($v0)
    MEM_B(0X6E18, ctx->r2) = ctx->r3;
    goto L_80054484;
    // sb          $v1, 0x6E18($v0)
    MEM_B(0X6E18, ctx->r2) = ctx->r3;
L_8005446C:
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // sb          $v0, 0x6E18($v1)
    MEM_B(0X6E18, ctx->r3) = ctx->r2;
L_80054484:
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
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $s0, $zero, L_800544B0
    if (ctx->r16 == 0) {
        // sb          $v0, 0x6E16($v1)
        MEM_B(0X6E16, ctx->r3) = ctx->r2;
        goto L_800544B0;
    }
    // sb          $v0, 0x6E16($v1)
    MEM_B(0X6E16, ctx->r3) = ctx->r2;
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // j           L_800544B4
    // sb          $v0, 0x6E17($v1)
    MEM_B(0X6E17, ctx->r3) = ctx->r2;
    goto L_800544B4;
    // sb          $v0, 0x6E17($v1)
    MEM_B(0X6E17, ctx->r3) = ctx->r2;
L_800544B0:
    // sb          $zero, 0x6E17($v1)
    MEM_B(0X6E17, ctx->r3) = 0;
L_800544B4:
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sb          $zero, 0x6E19($v0)
    MEM_B(0X6E19, ctx->r2) = 0;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_800544D4:
    // bne         $s4, $zero, L_80054524
    if (ctx->r20 != 0) {
        // nop
    
        goto L_80054524;
    }
    // nop

    // lhu         $v1, 0x2A($s1)
    ctx->r3 = MEM_HU(0X2A, ctx->r17);
    // lhu         $v0, 0xB0($s1)
    ctx->r2 = MEM_HU(0XB0, ctx->r17);
    // lh          $a0, 0xB0($s1)
    ctx->r4 = MEM_HS(0XB0, ctx->r17);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // blez        $a0, L_80054508
    if (SIGNED(ctx->r4) <= 0) {
        // sh          $v1, 0x2A($s1)
        MEM_H(0X2A, ctx->r17) = ctx->r3;
        goto L_80054508;
    }
    // sh          $v1, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r3;
    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // beq         $v0, $zero, L_8005451C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1000
        ctx->r2 = ADD32(0, 0X1000);
        goto L_8005451C;
    }
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
L_80054508:
    // bgez        $a0, L_80054534
    if (SIGNED(ctx->r4) >= 0) {
        // sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3) << 16;
        goto L_80054534;
    }
    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // bgez        $v0, L_80054538
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80054538;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
L_8005451C:
    // j           L_8005454C
    // sh          $v0, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r2;
    goto L_8005454C;
    // sh          $v0, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r2;
L_80054524:
    // lbu         $v0, 0x6E18($s0)
    ctx->r2 = MEM_BU(0X6E18, ctx->r16);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // beq         $s2, $v0, L_8005454C
    if (ctx->r18 == ctx->r2) {
        // nop
    
        goto L_8005454C;
    }
    // nop

L_80054534:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80054538:
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // jal         0x80026DD4
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    sub_80026DD4(rdram, ctx);
    goto after_1;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_1:
    // j           L_800544D4
    // nop

    goto L_800544D4;
    // nop

L_8005454C:
    // bne         $s4, $zero, L_80054588
    if (ctx->r20 != 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80054588;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x8004B1E8
    // addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    sub_8004B1E8(rdram, ctx);
    goto after_2;
    // addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    after_2:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_80054588
    if (ctx->r3 == 0) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80054588;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(0X1, ctx->r3);
    // sh          $zero, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = 0;
    // sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(0XC, ctx->r3);
    // nop

    // sh          $v0, 0xB0($s1)
    MEM_H(0XB0, ctx->r17) = ctx->r2;
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
L_80054588:
    // lbu         $v1, -0x2EDC($v0)
    ctx->r3 = MEM_BU(-0X2EDC, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_800545C0
    if (ctx->r3 != ctx->r2) {
        // addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
        goto L_800545C0;
    }
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v1, 0x9($s3)
    ctx->r3 = MEM_BU(0X9, ctx->r19);
    // addiu       $v0, $v0, -0x45F8
    ctx->r2 = ADD32(ctx->r2, -0X45F8);
    // sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3) << 1;
    // addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x1448($v1)
    ctx->r2 = MEM_BU(0X1448, ctx->r3);
    // sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4) << 1;
    // jal         0x800542D0
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    sub_800542D0(rdram, ctx);
    goto after_3;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_3:
L_800545C0:
    // lbu         $v0, 0x9($s3)
    ctx->r2 = MEM_BU(0X9, ctx->r19);
    // lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v0, -0x7E70($at)
    MEM_H(-0X7E70, ctx->r1) = ctx->r2;
    // lbu         $a0, 0x9($s3)
    ctx->r4 = MEM_BU(0X9, ctx->r19);
    // addiu       $s0, $s0, -0x45F8
    ctx->r16 = ADD32(ctx->r16, -0X45F8);
    // addu        $v0, $a0, $s0
    ctx->r2 = ADD32(ctx->r4, ctx->r16);
    // lbu         $a1, 0x1448($v0)
    ctx->r5 = MEM_BU(0X1448, ctx->r2);
    // jal         0x8005408C
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    sub_8005408C(rdram, ctx);
    goto after_4;
    // addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    after_4:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // lbu         $v1, 0x9($s3)
    ctx->r3 = MEM_BU(0X9, ctx->r19);
    // addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // lbu         $v0, 0x1448($v1)
    ctx->r2 = MEM_BU(0X1448, ctx->r3);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // jal         0x8006E874
    // sb          $v0, 0x1448($v1)
    MEM_B(0X1448, ctx->r3) = ctx->r2;
    SsSetSerialVol(rdram, ctx);
    goto after_5;
    // sb          $v0, 0x1448($v1)
    MEM_B(0X1448, ctx->r3) = ctx->r2;
    after_5:
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // sb          $v0, 0x6E16($s0)
    MEM_B(0X6E16, ctx->r16) = ctx->r2;
    // sb          $zero, 0x6E19($s0)
    MEM_B(0X6E19, ctx->r16) = 0;
L_80054630:
    // jal         0x800541F4
    // nop

    sub_800541F4(rdram, ctx);
    goto after_6;
    // nop

    after_6:
    // beq         $v0, $zero, L_80054660
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80054660;
    }
    // nop

    // jal         0x80054278
    // nop

    sub_80054278(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // lbu         $v1, 0x6E16($s0)
    ctx->r3 = MEM_BU(0X6E16, ctx->r16);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // bne         $v1, $v0, L_8005465C
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
        goto L_8005465C;
    }
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // sb          $zero, 0x6E19($s0)
    MEM_B(0X6E19, ctx->r16) = 0;
L_8005465C:
    // sb          $v0, 0x6E16($s0)
    MEM_B(0X6E16, ctx->r16) = ctx->r2;
L_80054660:
    // bne         $s4, $zero, L_80054698
    if (ctx->r20 != 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80054698;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lhu         $v0, 0x2A($s1)
    ctx->r2 = MEM_HU(0X2A, ctx->r17);
    // lhu         $v1, 0xB0($s1)
    ctx->r3 = MEM_HU(0XB0, ctx->r17);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // bne         $v0, $zero, L_8005469C
    if (ctx->r2 != 0) {
        // addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
        goto L_8005469C;
    }
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // sh          $zero, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = 0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80054698:
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_8005469C:
    // jal         0x80026DD4
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    sub_80026DD4(rdram, ctx);
    goto after_8;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_8:
    // lbu         $v1, 0x6E16($s0)
    ctx->r3 = MEM_BU(0X6E16, ctx->r16);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bne         $v1, $v0, L_80054630
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80054630;
    }
    // nop

    // bne         $s4, $zero, L_80054768
    if (ctx->r20 != 0) {
        // lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
        goto L_80054768;
    }
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // jal         0x8004B1E8
    // addiu       $a1, $zero, 0x72
    ctx->r5 = ADD32(0, 0X72);
    sub_8004B1E8(rdram, ctx);
    goto after_9;
    // addiu       $a1, $zero, 0x72
    ctx->r5 = ADD32(0, 0X72);
    after_9:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // beq         $v1, $zero, L_80054704
    if (ctx->r3 == 0) {
        // nop
    
        goto L_80054704;
    }
    // nop

    // lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(0X1, ctx->r3);
    // nop

    // sb          $v0, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r2;
    // lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(0XC, ctx->r3);
    // nop

    // sh          $v0, 0xB0($s1)
    MEM_H(0XB0, ctx->r17) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // blez        $v0, L_80054700
    if (SIGNED(ctx->r2) <= 0) {
        // addiu       $v0, $zero, 0x1000
        ctx->r2 = ADD32(0, 0X1000);
        goto L_80054700;
    }
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // j           L_80054704
    // sh          $zero, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = 0;
    goto L_80054704;
    // sh          $zero, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = 0;
L_80054700:
    // sh          $v0, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r2;
L_80054704:
    // lh          $v0, 0xC($v1)
    ctx->r2 = MEM_HS(0XC, ctx->r3);
    // addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
    // bgez        $v0, L_80054718
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_80054718;
    }
    // nop

    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80054718:
    // div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // bne         $v0, $zero, L_80054728
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80054728;
    }
    // nop

    // break       7
    do_break(2147829540);
L_80054728:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v0, $at, L_80054740
    if (ctx->r2 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80054740;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v1, $at, L_80054740
    if (ctx->r3 != ctx->r1) {
        // nop
    
        goto L_80054740;
    }
    // nop

    // break       6
    do_break(2147829564);
L_80054740:
    // mflo        $v1
    ctx->r3 = lo;
    // lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // ori         $a0, $a0, 0x8000
    ctx->r4 = ctx->r4 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // j           L_80054780
    // sb          $v1, 0x6E18($v0)
    MEM_B(0X6E18, ctx->r2) = ctx->r3;
    goto L_80054780;
    // sb          $v1, 0x6E18($v0)
    MEM_B(0X6E18, ctx->r2) = ctx->r3;
L_80054760:
    // j           L_80054818
    // sh          $v0, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r2;
    goto L_80054818;
    // sh          $v0, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r2;
L_80054768:
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // sb          $v0, 0x6E18($v1)
    MEM_B(0X6E18, ctx->r3) = ctx->r2;
L_80054780:
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
    // addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // sb          $v0, 0x6E16($s0)
    MEM_B(0X6E16, ctx->r16) = ctx->r2;
    // sb          $zero, 0x6E19($s0)
    MEM_B(0X6E19, ctx->r16) = 0;
L_800547A4:
    // bne         $s4, $zero, L_800547F4
    if (ctx->r20 != 0) {
        // nop
    
        goto L_800547F4;
    }
    // nop

    // lhu         $v1, 0x2A($s1)
    ctx->r3 = MEM_HU(0X2A, ctx->r17);
    // lhu         $v0, 0xB0($s1)
    ctx->r2 = MEM_HU(0XB0, ctx->r17);
    // lh          $a0, 0xB0($s1)
    ctx->r4 = MEM_HS(0XB0, ctx->r17);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // blez        $a0, L_800547D8
    if (SIGNED(ctx->r4) <= 0) {
        // sh          $v1, 0x2A($s1)
        MEM_H(0X2A, ctx->r17) = ctx->r3;
        goto L_800547D8;
    }
    // sh          $v1, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r3;
    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x1000
    ctx->r2 = SIGNED(ctx->r2) < 0X1000 ? 1 : 0;
    // beq         $v0, $zero, L_80054760
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x1000
        ctx->r2 = ADD32(0, 0X1000);
        goto L_80054760;
    }
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
L_800547D8:
    // bgez        $a0, L_80054804
    if (SIGNED(ctx->r4) >= 0) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80054804;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // bgez        $v0, L_80054808
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $a1, $a0, $zero
        ctx->r5 = ADD32(ctx->r4, 0);
        goto L_80054808;
    }
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // j           L_80054818
    // sh          $zero, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = 0;
    goto L_80054818;
    // sh          $zero, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = 0;
L_800547F4:
    // lbu         $v0, 0x6E18($s0)
    ctx->r2 = MEM_BU(0X6E18, ctx->r16);
    // addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // beq         $s2, $v0, L_80054818
    if (ctx->r18 == ctx->r2) {
        // addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
        goto L_80054818;
    }
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80054804:
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
L_80054808:
    // jal         0x80026DD4
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    sub_80026DD4(rdram, ctx);
    goto after_10;
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    after_10:
    // j           L_800547A4
    // nop

    goto L_800547A4;
    // nop

L_80054818:
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // jal         0x80057A3C
    // sb          $zero, 0x6E16($v0)
    MEM_B(0X6E16, ctx->r2) = 0;
    sub_80057A3C(rdram, ctx);
    goto after_11;
    // sb          $zero, 0x6E16($v0)
    MEM_B(0X6E16, ctx->r2) = 0;
    after_11:
L_80054834:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
