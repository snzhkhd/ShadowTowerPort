#include "recomp.h"
#include "disable_warnings.h"

void sub_800456F8(uint8_t* rdram, recomp_context* ctx) 
{
    //for (int i = 0; i < 16; i++) {
    //    uint32_t entryAddr = 0x801DD228 + i * 8;
    //    uint32_t ptr = MEM_W(0, entryAddr);
    //    if (ptr && MEM_H(4, ptr) == 3) {
    //        MEM_H(4, ptr) = 0;
    //        printf("[FIX] Forced VAB slot %d status 3->0 at %08X\n", i, ptr);
    //    }
    //}


    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lh          $v1, 0x5920($v0)
    ctx->r3 = MEM_HS(0X5920, ctx->r2);
    // addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // lui         $s2, 0x8009
    ctx->r18 = S32(0X8009 << 16);
    // sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // addiu       $s1, $v0, 0x5920
    ctx->r17 = ADD32(ctx->r2, 0X5920);
    // sw          $ra, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r31;
    // sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // beq         $v1, $zero, L_80045F68
    if (ctx->r3 == 0) {
        // sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
        goto L_80045F68;
    }
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80045F68
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_80045F68;
    }
    // nop

    // lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(0X2, ctx->r17);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2) >> 16;
    // addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // beq         $s0, $v0, L_80045E14
    if (ctx->r16 == ctx->r2) {
        // slti        $v0, $s0, 0x5
        ctx->r2 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
        goto L_80045E14;
    }
    // slti        $v0, $s0, 0x5
    ctx->r2 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // beq         $v0, $zero, L_80045794
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
        goto L_80045794;
    }
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // beq         $s0, $v1, L_800458B4
    if (ctx->r16 == ctx->r3) {
        // slti        $v0, $s0, 0x2
        ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
        goto L_800458B4;
    }
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8004577C
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8004577C;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $s0, $zero, L_800457D0
    if (ctx->r16 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_800457D0;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // j           L_80045F68
    // nop

    goto L_80045F68;
    // nop

L_8004577C:
    // beq         $s0, $v0, L_80045974
    if (ctx->r16 == ctx->r2) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_80045974;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $s0, $v0, L_800459B0
    if (ctx->r16 == ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_800459B0;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // j           L_80045F68
    // nop

    goto L_80045F68;
    // nop

L_80045794:
    // beq         $s0, $v0, L_80045F60
    if (ctx->r16 == ctx->r2) {
        // slti        $v0, $s0, 0x8
        ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
        goto L_80045F60;
    }
    // slti        $v0, $s0, 0x8
    ctx->r2 = SIGNED(ctx->r16) < 0X8 ? 1 : 0;
    // beq         $v0, $zero, L_800457BC
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_800457BC;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // beq         $s0, $v0, L_80045E58
    if (ctx->r16 == ctx->r2) {
        // addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
        goto L_80045E58;
    }
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // beq         $s0, $v0, L_80045EE4
    if (ctx->r16 == ctx->r2) {
        // lui         $s2, 0x801E
        ctx->r18 = S32(0X801E << 16);
        goto L_80045EE4;
    }
    // lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
    // j           L_80045F68
    // nop

    goto L_80045F68;
    // nop

L_800457BC:
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // beq         $s0, $v0, L_80045F60
    if (ctx->r16 == ctx->r2) {
        // nop
    
        goto L_80045F60;
    }
    // nop

    // j           L_80045F68
    // nop

    goto L_80045F68;
    // nop

L_800457D0:
    // lbu         $v1, 0x10($s1)
    ctx->r3 = MEM_BU(0X10, ctx->r17);
    // nop

    // beq         $v1, $v0, L_800459AC
    if (ctx->r3 == ctx->r2) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_800459AC;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x80015EC8
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    sub_80015EC8(rdram, ctx);
    goto after_0;
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    after_0:
    // beq         $v0, $zero, L_80045818
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_80045818;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(0X10, ctx->r17);
    // lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // addiu       $a2, $a2, 0x5648
    ctx->r6 = ADD32(ctx->r6, 0X5648);
    // sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // jal         0x80045F90
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    sub_80045F90(rdram, ctx);
    goto after_1;
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    after_1:
L_80045818:
    // addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x2230
    ctx->r2 = ADD32(ctx->r2, 0X2230);
    // addiu       $s1, $zero, 0xEF
    ctx->r17 = ADD32(0, 0XEF);
    // addiu       $s4, $zero, 0xEC
    ctx->r20 = ADD32(0, 0XEC);
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
    // addiu       $s0, $v0, 0x5
    ctx->r16 = ADD32(ctx->r2, 0X5);
L_8004583C:
    // lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(0X0, ctx->r16);
    // nop

    // bne         $v0, $s4, L_8004586C
    if (ctx->r2 != ctx->r20) {
        // nop
    
        goto L_8004586C;
    }
    // nop

    // lh          $a0, 0x4F($s0)
    ctx->r4 = MEM_HS(0X4F, ctx->r16);
    // nop

    // beq         $a0, $s2, L_8004586C
    if (ctx->r4 == ctx->r18) {
        // nop
    
        goto L_8004586C;
    }
    // nop

    // lbu         $a1, 0x45($s0)
    ctx->r5 = MEM_BU(0X45, ctx->r16);
    // jal         0x8005850C
    // addiu       $a1, $a1, 0x454
    ctx->r5 = ADD32(ctx->r5, 0X454);
    sub_8005850C(rdram, ctx);
    goto after_2;
    // addiu       $a1, $a1, 0x454
    ctx->r5 = ADD32(ctx->r5, 0X454);
    after_2:
    // sh          $s2, 0x4F($s0)
    MEM_H(0X4F, ctx->r16) = ctx->r18;
L_8004586C:
    // sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s2, L_8004583C
    if (ctx->r17 != ctx->r18) {
        // addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
        goto L_8004583C;
    }
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // addiu       $a2, $a2, -0x7378
    ctx->r6 = ADD32(ctx->r6, -0X7378);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v0, 0x5930($v0)
    ctx->r2 = MEM_BU(0X5930, ctx->r2);
    // lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // addiu       $a3, $a3, 0x557C
    ctx->r7 = ADD32(ctx->r7, 0X557C);
    // sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2) << 2;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    // jal         0x80015D54
    // ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;


    sub_80015D54(rdram, ctx);

    goto after_3;
    // ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    after_3:
    // j           L_80045F68
    // nop

    goto L_80045F68;
    // nop

L_800458B4:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // addiu       $a3, $a3, 0x5594
    ctx->r7 = ADD32(ctx->r7, 0X5594);
    // lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // lw          $a2, -0x7E24($a2)
    ctx->r6 = MEM_W(-0X7E24, ctx->r6);
    // addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lbu         $v1, 0x10($s1)
    ctx->r3 = MEM_BU(0X10, ctx->r17);
    // addiu       $v0, $v0, 0x38C
    ctx->r2 = ADD32(ctx->r2, 0X38C);
    // sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3) << 2;
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    // jal         0x80015D54
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);

    sub_80015D54(rdram, ctx);
    goto after_4;
    // addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    after_4:
    // lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // addiu       $a0, $a0, -0x4130
    ctx->r4 = ADD32(ctx->r4, -0X4130);
    // addiu       $a1, $s2, -0x7378
    ctx->r5 = ADD32(ctx->r18, -0X7378);
    // addiu       $a2, $zero, 0x3E00
    ctx->r6 = ADD32(0, 0X3E00);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // sw          $zero, 0x174($v0)
    MEM_W(0X174, ctx->r2) = 0;
    // jal         0x80014CFC
    // sh          $v1, 0x178($v0)
    MEM_H(0X178, ctx->r2) = ctx->r3;
    printf("[6F8] -> before sub_80014CFC \n");
    sub_80014CFC(rdram, ctx);
    goto after_5;
    // sh          $v1, 0x178($v0)
    MEM_H(0X178, ctx->r2) = ctx->r3;
    after_5:
    // lb          $v1, 0x20($s1)
    ctx->r3 = MEM_BS(0X20, ctx->r17);
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // beq         $v1, $v0, L_80045968
    if (ctx->r3 == ctx->r2) {
        // sll         $v0, $v1, 12
        ctx->r2 = S32(ctx->r3) << 12;
        goto L_80045968;
    }
    // sll         $v0, $v1, 12
    ctx->r2 = S32(ctx->r3) << 12;
    // lb          $a0, 0x23($s1)
    ctx->r4 = MEM_BS(0X23, ctx->r17);
    // lb          $a1, 0x24($s1)
    ctx->r5 = MEM_BS(0X24, ctx->r17);
    // lb          $a2, 0x25($s1)
    ctx->r6 = MEM_BS(0X25, ctx->r17);
    // sb          $s0, 0x1C($s1)
    MEM_B(0X1C, ctx->r17) = ctx->r16;
    // sll         $a0, $a0, 7
    ctx->r4 = S32(ctx->r4) << 7;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // lb          $v0, 0x22($s1)
    ctx->r2 = MEM_BS(0X22, ctx->r17);
    // sll         $a1, $a1, 7
    ctx->r5 = S32(ctx->r5) << 7;
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // addu        $a1, $v0, $a1
    ctx->r5 = ADD32(ctx->r2, ctx->r5);
    // lb          $v0, 0x21($s1)
    ctx->r2 = MEM_BS(0X21, ctx->r17);
    // sll         $a2, $a2, 7
    ctx->r6 = S32(ctx->r6) << 7;
    // sll         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) << 12;
    // jal         0x80045010
    // addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    sub_80045010(rdram, ctx);
    goto after_6;
    // addu        $a2, $v0, $a2
    ctx->r6 = ADD32(ctx->r2, ctx->r6);
    after_6:
L_80045968:
    // lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(0X10, ctx->r17);
    // j           L_80045F68
    // sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
    goto L_80045F68;
    // sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
L_80045974:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addiu       $a2, $s2, -0x7378
    ctx->r6 = ADD32(ctx->r18, -0X7378);
    // lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // addiu       $a3, $a3, 0x55AC
    ctx->r7 = ADD32(ctx->r7, 0X55AC);
    // lbu         $v1, 0x10($s1)
    ctx->r3 = MEM_BU(0X10, ctx->r17);
    // addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3) << 2;
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    // jal         0x80015D54
    // addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    sub_80015D54(rdram, ctx);
    goto after_7;
    // addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    after_7:
    // j           L_80045F68
    // nop

    goto L_80045F68;
    // nop

L_800459AC:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_800459B0:
    // addiu       $s1, $v0, 0x5920
    ctx->r17 = ADD32(ctx->r2, 0X5920);
    // lbu         $v0, 0x11($s1)
    ctx->r2 = MEM_BU(0X11, ctx->r17);
    // addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // beq         $v0, $s2, L_80045AC0
    if (ctx->r2 == ctx->r18) {
        // lui         $s0, 0x8009
        ctx->r16 = S32(0X8009 << 16);
        goto L_80045AC0;
    }
    // lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // addiu       $s0, $s0, -0x7E00
    ctx->r16 = ADD32(ctx->r16, -0X7E00);
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // lw          $a0, 0x9F4($s0)
    ctx->r4 = MEM_W(0X9F4, ctx->r16);
    // addiu       $a3, $v0, 0x22A8
    ctx->r7 = ADD32(ctx->r2, 0X22A8);
    // lwl         $v1, 0x3($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r7);
    // lwr         $v1, 0x0($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r7);
    // lwl         $a1, 0x7($a3)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0X7, ctx->r7);
    // lwr         $a1, 0x4($a3)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0X4, ctx->r7);
    // lb          $a2, 0x8($a3)
    ctx->r6 = MEM_BS(0X8, ctx->r7);
    // swl         $v1, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r3);
    // swr         $v1, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r3);
    // swl         $a1, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r5);
    // swr         $a1, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r5);
    // sb          $a2, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r6;
    // lb          $v1, 0x9($a3)
    ctx->r3 = MEM_BS(0X9, ctx->r7);
    // lb          $a1, 0xA($a3)
    ctx->r5 = MEM_BS(0XA, ctx->r7);
    // sb          $v1, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r3;
    // sb          $a1, 0x1A($sp)
    MEM_B(0X1A, ctx->r29) = ctx->r5;
    // jal         0x800152F8
    // nop

    __builtin_delete(rdram, ctx);
    goto after_8;
    // nop

    after_8:
    // lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(0X10, ctx->r17);
    // lui         $v1, 0xCCCC
    ctx->r3 = S32(0XCCCC << 16);
    // ori         $v1, $v1, 0xCCCD
    ctx->r3 = ctx->r3 | 0XCCCD;
    // multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $t1
    ctx->r9 = hi;
    // nop

    // nop

    // multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $a3
    ctx->r7 = hi;
    // addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // nop

    // multu       $a2, $v1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // sw          $zero, 0x9F4($s0)
    MEM_W(0X9F4, ctx->r16) = 0;
    // srl         $v0, $t1, 3
    ctx->r2 = S32(U32(ctx->r9) >> 3);
    // addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // sb          $v0, 0x13($sp)
    MEM_B(0X13, ctx->r29) = ctx->r2;
    // srl         $v0, $a3, 3
    ctx->r2 = S32(U32(ctx->r7) >> 3);
    // addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // sb          $v0, 0x16($sp)
    MEM_B(0X16, ctx->r29) = ctx->r2;
    // mfhi        $v1
    ctx->r3 = hi;
    // srl         $v1, $v1, 3
    ctx->r3 = S32(U32(ctx->r3) >> 3);
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // jal         0x80016294
    // sb          $a2, 0x17($sp)
    MEM_B(0X17, ctx->r29) = ctx->r6;

    sub_80016294(rdram, ctx);

    goto after_9;
    // sb          $a2, 0x17($sp)
    MEM_B(0X17, ctx->r29) = ctx->r6;
    after_9:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // addiu       $a2, $a2, -0x3B78
    ctx->r6 = ADD32(ctx->r6, -0X3B78);
    // lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // addiu       $a3, $a3, 0x55C4
    ctx->r7 = ADD32(ctx->r7, 0X55C4);
    // lbu         $v1, 0x11($s1)
    ctx->r3 = MEM_BU(0X11, ctx->r17);
    // addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3) << 2;
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    // jal         0x80015D54
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);

    printf("[6F8] before sub_80015D54\n");
    sub_80015D54(rdram, ctx);
    goto after_10;
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_10:
L_80045AC0:
    // lbu         $v0, 0x10($s1)
    ctx->r2 = MEM_BU(0X10, ctx->r17);
    // nop

    // beq         $v0, $s2, L_80045DF8
    if (ctx->r2 == ctx->r18) {
        // lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
        goto L_80045DF8;
    }
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $s3, $v0, -0x7378
    ctx->r19 = ADD32(ctx->r2, -0X7378);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $s2, $v0, -0x5EC8
    ctx->r18 = ADD32(ctx->r2, -0X5EC8);
    // addiu       $s1, $zero, 0x3F
    ctx->r17 = ADD32(0, 0X3F);
    // addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // addiu       $s0, $s2, 0xA4
    ctx->r16 = ADD32(ctx->r18, 0XA4);
L_80045AEC:
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // nop

    // beq         $a0, $zero, L_80045B1C
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80045B1C;
    }
    // nop

    // jal         0x8003413C
    // nop

    sub_8003413C(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // nop

    // beq         $a0, $zero, L_80045B1C
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80045B1C;
    }
    // nop

    // jal         0x80035008
    // nop

    sub_80035008(rdram, ctx);
    goto after_12;
    // nop

    after_12:
L_80045B1C:
    // sb          $s5, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r21;
    // addiu       $s0, $s0, 0xD4
    ctx->r16 = ADD32(ctx->r16, 0XD4);
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s4, L_80045AEC
    if (ctx->r17 != ctx->r20) {
        // addiu       $s2, $s2, 0xD4
        ctx->r18 = ADD32(ctx->r18, 0XD4);
        goto L_80045AEC;
    }
    // addiu       $s2, $s2, 0xD4
    ctx->r18 = ADD32(ctx->r18, 0XD4);
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // addiu       $v0, $v0, 0x2230
    ctx->r2 = ADD32(ctx->r2, 0X2230);
    // addiu       $s1, $zero, 0xEF
    ctx->r17 = ADD32(0, 0XEF);
    // ori         $s4, $zero, 0xFFFF
    ctx->r20 = 0 | 0XFFFF;
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // addiu       $s0, $v0, 0xA
    ctx->r16 = ADD32(ctx->r2, 0XA);
L_80045B48:
    // lw          $a0, 0x3A($s0)
    ctx->r4 = MEM_W(0X3A, ctx->r16);
    // nop

    // beq         $a0, $zero, L_80045B78
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80045B78;
    }
    // nop

    // jal         0x8003413C
    // nop

    sub_8003413C(rdram, ctx);
    goto after_13;
    // nop

    after_13:
    // lw          $a0, 0x3A($s0)
    ctx->r4 = MEM_W(0X3A, ctx->r16);
    // nop

    // beq         $a0, $zero, L_80045B78
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80045B78;
    }
    // nop

    // jal         0x80035008
    // nop

    sub_80035008(rdram, ctx);
    goto after_14;
    // nop

    after_14:
L_80045B78:
    // sh          $s4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r20;
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s2, L_80045B48
    if (ctx->r17 != ctx->r18) {
        // addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
        goto L_80045B48;
    }
    // addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // addiu       $s1, $zero, 0x3F
    ctx->r17 = ADD32(0, 0X3F);
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // addiu       $v0, $v0, -0x51F8
    ctx->r2 = ADD32(ctx->r2, -0X51F8);
    // addiu       $s0, $v0, 0x4
    ctx->r16 = ADD32(ctx->r2, 0X4);
L_80045B9C:
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // nop

    // beq         $a0, $zero, L_80045BCC
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80045BCC;
    }
    // nop

    // jal         0x8003413C
    // nop

    sub_8003413C(rdram, ctx);
    goto after_15;
    // nop

    after_15:
    // lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(0X0, ctx->r16);
    // nop

    // beq         $a0, $zero, L_80045BCC
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80045BCC;
    }
    // nop

    // jal         0x80035008
    // nop

    sub_80035008(rdram, ctx);
    goto after_16;
    // nop

    after_16:
L_80045BCC:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s2, L_80045B9C
    if (ctx->r17 != ctx->r18) {
        // addiu       $s0, $s0, 0x30
        ctx->r16 = ADD32(ctx->r16, 0X30);
        goto L_80045B9C;
    }
    // addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // jal         0x80052D10
    // addiu       $s1, $zero, 0xF
    ctx->r17 = ADD32(0, 0XF);
    sub_80052D10(rdram, ctx);
    goto after_17;
    // addiu       $s1, $zero, 0xF
    ctx->r17 = ADD32(0, 0XF);
    after_17:
    // ori         $s4, $zero, 0x854C
    ctx->r20 = 0 | 0X854C;
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addiu       $s0, $v0, 0x3C
    ctx->r16 = ADD32(ctx->r2, 0X3C);
L_80045BF4:
    // addu        $v0, $s0, $s4
    ctx->r2 = ADD32(ctx->r16, ctx->r20);
    // lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(0X0, ctx->r2);
    // nop

    // beq         $a0, $zero, L_80045C10
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80045C10;
    }
    // nop

    // jal         0x80015230
    // nop

    sub_80015230(rdram, ctx);
    goto after_18;
    // nop

    after_18:
L_80045C10:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s2, L_80045BF4
    if (ctx->r17 != ctx->r18) {
        // addiu       $s0, $s0, -0x4
        ctx->r16 = ADD32(ctx->r16, -0X4);
        goto L_80045BF4;
    }
    // addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
    // addiu       $s1, $zero, 0x7F
    ctx->r17 = ADD32(0, 0X7F);
    // ori         $s4, $zero, 0x8C7C
    ctx->r20 = 0 | 0X8C7C;
    // addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addiu       $s0, $v0, 0x1FC
    ctx->r16 = ADD32(ctx->r2, 0X1FC);
L_80045C34:
    // addu        $v0, $s0, $s4
    ctx->r2 = ADD32(ctx->r16, ctx->r20);
    // lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(0X0, ctx->r2);
    // nop

    // beq         $a0, $zero, L_80045C50
    if (ctx->r4 == 0) {
        // nop
    
        goto L_80045C50;
    }
    // nop

    // jal         0x80015230
    // nop

    sub_80015230(rdram, ctx);
    goto after_19;
    // nop

    after_19:
L_80045C50:
    // addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // bne         $s1, $s2, L_80045C34
    if (ctx->r17 != ctx->r18) {
        // addiu       $s0, $s0, -0x4
        ctx->r16 = ADD32(ctx->r16, -0X4);
        goto L_80045C34;
    }
    // addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
    // lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // addiu       $s1, $s1, -0x29C8
    ctx->r17 = ADD32(ctx->r17, -0X29C8);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    // jal         0x80014CFC
    // addiu       $a2, $zero, 0xB00
    ctx->r6 = ADD32(0, 0XB00);
    sub_80014CFC(rdram, ctx);
    goto after_20;
    // addiu       $a2, $zero, 0xB00
    ctx->r6 = ADD32(0, 0XB00);
    after_20:
    // jal         0x8004E8EC
    // lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    sub_8004E8EC(rdram, ctx);
    goto after_21;
    // lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    after_21:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // jal         0x8004E960
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);

    sub_8004E960(rdram, ctx);
    goto after_22;
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    after_22:
    // lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // addiu       $a0, $a0, 0x1F30
    ctx->r4 = ADD32(ctx->r4, 0X1F30);
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // jal         0x80014CFC
    // addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);

    sub_80014CFC(rdram, ctx);
    goto after_23;
    // addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    after_23:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // jal         0x8004EEBC
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);

    sub_8004EEBC(rdram, ctx);

    goto after_24;
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    after_24:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // jal         0x80052F30
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);

    sub_80052F30(rdram, ctx);
    goto after_25;
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    after_25:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // jal         0x80031DE4
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);

    sub_80031DE4(rdram, ctx);
    goto after_26;
    // addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    after_26:
    // addiu       $s0, $s0, 0x5920
    ctx->r16 = ADD32(ctx->r16, 0X5920);
    // lbu         $a0, 0x10($s0)
    ctx->r4 = MEM_BU(0X10, ctx->r16);
    // jal         0x80055F9C
    // addiu       $s3, $zero, 0xF
    ctx->r19 = ADD32(0, 0XF);
    printf("[6F8] before sub_80055F9C\n");
    sub_80055F9C(rdram, ctx);
    goto after_27;
    // addiu       $s3, $zero, 0xF
    ctx->r19 = ADD32(0, 0XF);
    after_27:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v1, 0x10($s0)
    ctx->r3 = MEM_BU(0X10, ctx->r16);
    // addiu       $v0, $v0, -0x45F8
    ctx->r2 = ADD32(ctx->r2, -0X45F8);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x1478($v1)
    ctx->r2 = MEM_BU(0X1478, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x1
    ctx->r2 = ctx->r2 | 0X1;
    // sb          $v0, 0x1478($v1)
    MEM_B(0X1478, ctx->r3) = ctx->r2;
    // lw          $v0, 0x318($gp)
    ctx->r2 = MEM_W(0X318, ctx->r28);
    // jal         0x80016878
    // sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;

    sub_80016878(rdram, ctx);


    goto after_28;
    // sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    after_28:
    // lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(0XC, ctx->r16);
    // addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(0X14, ctx->r2);
    // nop

    // jalr        $v0
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    printf("[6F8] before LOOKUP_FUNC\n");
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_29;
    // addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    after_29:
    // lui         $v0, 0x801E
    ctx->r2 = S32(0X801E << 16);
    // addiu       $s0, $v0, -0x2DD8
    ctx->r16 = ADD32(ctx->r2, -0X2DD8);
    // addiu       $s2, $s0, 0x4
    ctx->r18 = ADD32(ctx->r16, 0X4);
    // addiu       $s1, $s1, -0x3500
    ctx->r17 = ADD32(ctx->r17, -0X3500);
    // addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // sb          $v0, 0x6168($s1)
    MEM_B(0X6168, ctx->r17) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sh          $v0, 0x615E($s1)
    MEM_H(0X615E, ctx->r17) = ctx->r2;
    // sh          $v0, 0x615C($s1)
    MEM_H(0X615C, ctx->r17) = ctx->r2;
    // sh          $v0, 0x615A($s1)
    MEM_H(0X615A, ctx->r17) = ctx->r2;
    // sh          $v0, 0x6158($s1)
    MEM_H(0X6158, ctx->r17) = ctx->r2;
L_80045D7C:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // beq         $v0, $zero, L_80045DD4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80045DD4;
    }
    // nop

    // lh          $v0, 0x4($v0)
    ctx->r2 = MEM_HS(0X4, ctx->r2);
    // nop

    // bne         $v0, $s5, L_80045DC0
    if (ctx->r2 != ctx->r21) {
        // nop
    
        goto L_80045DC0;
    }
    // nop

    // addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
L_80045DA0:
    // jal         0x8001531C
    // nop
    AsyncDataLoad(rdram, ctx);
    goto after_30;
    // nop

    after_30:
    // lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(0X0, ctx->r16);
    // nop

    // lh          $v0, 0x4($v0)
    ctx->r2 = MEM_HS(0X4, ctx->r2);
    // nop

    // beq         $v0, $s1, L_80045DA0
    if (ctx->r2 == ctx->r17) {
        // nop
    
        goto L_80045DA0;
    }
    // nop

L_80045DC0:
    // lh          $a0, 0x0($s2)
    ctx->r4 = MEM_HS(0X0, ctx->r18);
    // jal         0x80073564
    // nop

    ST_SsVabClose(rdram, ctx);
    goto after_31;
    // nop

    after_31:
    // sh          $s4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r20;
    // sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_80045DD4:
    // addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // bne         $s3, $s4, L_80045D7C
    if (ctx->r19 != ctx->r20) {
        // addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_80045D7C;
    }
    // addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // sb          $v1, -0x6EBC($v0)
    MEM_B(-0X6EBC, ctx->r2) = ctx->r3;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // sb          $v1, 0x593E($v0)
    MEM_B(0X593E, ctx->r2) = ctx->r3;
L_80045DF8:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v1, 0x5931($v0)
    ctx->r3 = MEM_BU(0X5931, ctx->r2);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_80045E5C
    if (ctx->r3 == ctx->r2) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80045E5C;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // j           L_80045F68
    // nop

    goto L_80045F68;
    // nop

L_80045E14:
    // lbu         $v1, 0x11($s1)
    ctx->r3 = MEM_BU(0X11, ctx->r17);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_80045F68
    if (ctx->r3 == ctx->r2) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_80045F68;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // addiu       $a2, $a2, 0x2C88
    ctx->r6 = ADD32(ctx->r6, 0X2C88);
    // lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // addiu       $a3, $a3, 0x55DC
    ctx->r7 = ADD32(ctx->r7, 0X55DC);
    // addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
    // sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3) << 2;
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    // jal         0x80015D54
    // addiu       $a1, $a1, 0x5
    ctx->r5 = ADD32(ctx->r5, 0X5);


    sub_80015D54(rdram, ctx);
    goto after_32;
    // addiu       $a1, $a1, 0x5
    ctx->r5 = ADD32(ctx->r5, 0X5);
    after_32:
    // j           L_80045F68
    // nop

    goto L_80045F68;
    // nop

L_80045E58:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_80045E5C:
    // addiu       $s0, $v0, 0x5920
    ctx->r16 = ADD32(ctx->r2, 0X5920);
    // lbu         $v0, 0x12($s0)
    ctx->r2 = MEM_BU(0X12, ctx->r16);
    // addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // beq         $v0, $s1, L_80045E98
    if (ctx->r2 == ctx->r17) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_80045E98;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // addiu       $a2, $a2, 0x55F4
    ctx->r6 = ADD32(ctx->r6, 0X55F4);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3) << 2;
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    // jal         0x80045F90
    // addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    sub_80045F90(rdram, ctx);
    goto after_33;
    // addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    after_33:
L_80045E98:
    // jal         0x80015AD4
    // nop

    AsyncStructForcedLoadSync(rdram, ctx);
    goto after_34;
    // nop

    after_34:
    // lbu         $v1, 0x13($s0)
    ctx->r3 = MEM_BU(0X13, ctx->r16);
    // sb          $zero, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = 0;
    // bne         $v1, $s1, L_80045ED0
    if (ctx->r3 != ctx->r17) {
        // sb          $zero, 0x1F($s0)
        MEM_B(0X1F, ctx->r16) = 0;
        goto L_80045ED0;
    }
    // sb          $zero, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = 0;
    // lbu         $v0, 0x14($s0)
    ctx->r2 = MEM_BU(0X14, ctx->r16);
    // nop

    // bne         $v0, $v1, L_80045ED4
    if (ctx->r2 != ctx->r3) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80045ED4;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // j           L_80045F60
    // nop

    goto L_80045F60;
    // nop

L_80045ED0:
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_80045ED4:
    // addiu       $v0, $v0, 0x5920
    ctx->r2 = ADD32(ctx->r2, 0X5920);
    // addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    // lui         $s2, 0x801E
    ctx->r18 = S32(0X801E << 16);
L_80045EE4:
    // addiu       $s1, $s2, -0x2E10
    ctx->r17 = ADD32(ctx->r18, -0X2E10);
    // lh          $a0, 0x4($s1)
    ctx->r4 = MEM_HS(0X4, ctx->r17);
    // addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // beq         $a0, $s0, L_80045F0C
    if (ctx->r4 == ctx->r16) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80045F0C;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // jal         0x80073564
    // nop

    ST_SsVabClose(rdram, ctx);
    goto after_35;
    // nop

    after_35:
    // sh          $s0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r16;
    // sw          $zero, -0x2E10($s2)
    MEM_W(-0X2E10, ctx->r18) = 0;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
L_80045F0C:
    // addiu       $s0, $v0, 0x5920
    ctx->r16 = ADD32(ctx->r2, 0X5920);
    // lbu         $v0, 0x13($s0)
    ctx->r2 = MEM_BU(0X13, ctx->r16);
    // addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // beq         $v0, $s1, L_80045F44
    if (ctx->r2 == ctx->r17) {
        // addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
        goto L_80045F44;
    }
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3) << 2;
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5) << 1;
    // jal         0x80058A0C
    // addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);

    sub_80058A0C(rdram, ctx);
    goto after_36;
    // addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    after_36:
L_80045F44:
    // lbu         $v0, 0x14($s0)
    ctx->r2 = MEM_BU(0X14, ctx->r16);
    // nop

    // beq         $v0, $s1, L_80045F60
    if (ctx->r2 == ctx->r17) {
        // addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
        goto L_80045F60;
    }
    // addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // j           L_80045F68
    // nop

    goto L_80045F68;
    // nop

L_80045F60:
    // jal         0x8004567C
    // nop

    sub_8004567C(rdram, ctx);
    goto after_37;
    // nop

    after_37:
L_80045F68:
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
