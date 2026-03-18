#include "recomp.h"
#include "disable_warnings.h"

void sub_80028784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, 0x7F1C
    ctx->r6 = ADD32(ctx->r2, 0X7F1C);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r3);
    // swr         $v1, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r3);
    // swl         $a0, 0x1F($sp)
    do_swl(rdram, 0X1F, ctx->r29, ctx->r4);
    // swr         $a0, 0x1C($sp)
    do_swr(rdram, 0X1C, ctx->r29, ctx->r4);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // addiu       $a2, $v0, 0x7F24
    ctx->r6 = ADD32(ctx->r2, 0X7F24);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x23($sp)
    do_swl(rdram, 0X23, ctx->r29, ctx->r3);
    // swr         $v1, 0x20($sp)
    do_swr(rdram, 0X20, ctx->r29, ctx->r3);
    // swl         $a0, 0x27($sp)
    do_swl(rdram, 0X27, ctx->r29, ctx->r4);
    // swr         $a0, 0x24($sp)
    do_swr(rdram, 0X24, ctx->r29, ctx->r4);
    // addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // sh          $v0, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // addiu       $v0, $zero, 0x230
    ctx->r2 = ADD32(0, 0X230);
    // sh          $v0, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1EF
    ctx->r2 = ADD32(0, 0X1EF);
    // sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, 0x6E17($v1)
    ctx->r2 = MEM_BU(0X6E17, ctx->r3);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // bne         $v0, $a0, L_80028834
    if (ctx->r2 != ctx->r4) {
        // addiu       $v0, $zero, 0x1FF
        ctx->r2 = ADD32(0, 0X1FF);
        goto L_80028834;
    }
    // addiu       $v0, $zero, 0x1FF
    ctx->r2 = ADD32(0, 0X1FF);
    // sh          $zero, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = 0;
    // sh          $zero, 0x40($sp)
    MEM_H(0X40, ctx->r29) = 0;
    // sh          $v0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r2;
L_80028834:
    // lbu         $v0, 0x6E18($v1)
    ctx->r2 = MEM_BU(0X6E18, ctx->r3);
    // nop

    // bne         $v0, $zero, L_80028848
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80028848;
    }
    // nop

    // sb          $a0, 0x6E18($v1)
    MEM_B(0X6E18, ctx->r3) = ctx->r4;
L_80028848:
    // lbu         $v0, 0x6E16($v1)
    ctx->r2 = MEM_BU(0X6E16, ctx->r3);
    // nop

    // addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_80028C14
    if (ctx->r2 == 0) {
        // lui         $v0, 0x8001
        ctx->r2 = S32(0X8001 << 16);
        goto L_80028C14;
    }
    // lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // addiu       $v0, $v0, 0x1490
    ctx->r2 = ADD32(ctx->r2, 0X1490);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $v0
    gpr jr_addend_80028874;
    jr_addend_80028874 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x0($v1)
    // nop

    // jr          $v0
    // nop

    switch (jr_addend_80028874 >> 2) {
        case 0: goto L_8002887C; break;
        case 1: goto L_800288E0; break;
        case 2: goto L_8002897C; break;
        case 3: goto L_80028A08; break;
        case 4: goto L_80028C14; break;
        case 5: goto L_80028AB0; break;
        default: switch_error(__func__, 0x80028874, 0x80011490);
    }
    // nop

L_8002887C:
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x6E17($a0)
    ctx->r3 = MEM_BU(0X6E17, ctx->r4);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $v0, L_80028B1C
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_80028B1C;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // lbu         $v0, 0x6E19($a0)
    ctx->r2 = MEM_BU(0X6E19, ctx->r4);
    // lbu         $v1, 0x6E18($a0)
    ctx->r3 = MEM_BU(0X6E18, ctx->r4);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_800288BC
    if (ctx->r3 != 0) {
        // nop
    
        goto L_800288BC;
    }
    // nop

    // break       7
    do_break(2147649720);
L_800288BC:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_800288D4
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_800288D4;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_800288D4
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_800288D4;
    }
    // nop

    // break       6
    do_break(2147649744);
L_800288D4:
    // mflo        $v0
    ctx->r2 = lo;
    // j           L_80028B20
    // sb          $v0, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r2;
    goto L_80028B20;
    // sb          $v0, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r2;
L_800288E0:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v1, -0x2EDC($v0)
    ctx->r3 = MEM_BU(-0X2EDC, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_80028914
    if (ctx->r3 == ctx->r2) {
        // lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
        goto L_80028914;
    }
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x6E17($a0)
    ctx->r3 = MEM_BU(0X6E17, ctx->r4);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_80028974
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_80028974;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80028914:
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // lbu         $v0, 0x6E19($s0)
    ctx->r2 = MEM_BU(0X6E19, ctx->r16);
    // addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sb          $v0, 0x32($sp)
    MEM_B(0X32, ctx->r29) = ctx->r2;
    // sb          $v0, 0x31($sp)
    MEM_B(0X31, ctx->r29) = ctx->r2;
    // sb          $v0, 0x30($sp)
    MEM_B(0X30, ctx->r29) = ctx->r2;
    // jal         0x80028364
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    sub_80028364(rdram, ctx);
    goto after_0;
    // sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_0:
    // lbu         $v0, 0x6E19($s0)
    ctx->r2 = MEM_BU(0X6E19, ctx->r16);
    // nop

    // sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80028B4C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
        goto L_80028B4C;
    }
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // j           L_80028B4C
    // sb          $s1, 0x6E16($s0)
    MEM_B(0X6E16, ctx->r16) = ctx->r17;
    goto L_80028B4C;
    // sb          $s1, 0x6E16($s0)
    MEM_B(0X6E16, ctx->r16) = ctx->r17;
L_80028974:
    // j           L_80028B48
    // sb          $v0, 0x6E16($a0)
    MEM_B(0X6E16, ctx->r4) = ctx->r2;
    goto L_80028B48;
    // sb          $v0, 0x6E16($a0)
    MEM_B(0X6E16, ctx->r4) = ctx->r2;
L_8002897C:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v1, -0x2EDC($v0)
    ctx->r3 = MEM_BU(-0X2EDC, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_800289B0
    if (ctx->r3 == ctx->r2) {
        // lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
        goto L_800289B0;
    }
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
    // lbu         $v1, 0x6E17($v0)
    ctx->r3 = MEM_BU(0X6E17, ctx->r2);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_80028B4C
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
        goto L_80028B4C;
    }
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
L_800289B0:
    // lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // lhu         $v1, -0x7E70($v1)
    ctx->r3 = MEM_HU(-0X7E70, ctx->r3);
    // addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // sb          $v0, 0x32($sp)
    MEM_B(0X32, ctx->r29) = ctx->r2;
    // sb          $v0, 0x31($sp)
    MEM_B(0X31, ctx->r29) = ctx->r2;
    // sb          $v0, 0x30($sp)
    MEM_B(0X30, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
    // beq         $v1, $v0, L_800289E4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x1E
        ctx->r2 = ADD32(0, 0X1E);
        goto L_800289E4;
    }
    // addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // beq         $v1, $v0, L_800289E4
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_800289E4;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // bne         $v1, $v0, L_800289E8
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
        goto L_800289E8;
    }
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_800289E4:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800289E8:
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // jal         0x80028364
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    sub_80028364(rdram, ctx);
    goto after_1;
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_1:
    // j           L_80028B4C
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    goto L_80028B4C;
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
L_80028A08:
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lbu         $v1, -0x2EDC($v0)
    ctx->r3 = MEM_BU(-0X2EDC, ctx->r2);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $v1, $v0, L_80028A3C
    if (ctx->r3 == ctx->r2) {
        // lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
        goto L_80028A3C;
    }
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x6E17($a0)
    ctx->r3 = MEM_BU(0X6E17, ctx->r4);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_80028AA8
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
        goto L_80028AA8;
    }
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80028A3C:
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x6E19($s0)
    ctx->r3 = MEM_BU(0X6E19, ctx->r16);
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // sb          $v0, 0x32($sp)
    MEM_B(0X32, ctx->r29) = ctx->r2;
    // sb          $v0, 0x31($sp)
    MEM_B(0X31, ctx->r29) = ctx->r2;
    // sb          $v0, 0x30($sp)
    MEM_B(0X30, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // jal         0x80028364
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    sub_80028364(rdram, ctx);
    goto after_2;
    // sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // lbu         $v0, 0x6E19($s0)
    ctx->r2 = MEM_BU(0X6E19, ctx->r16);
    // nop

    // sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80028B4C
    if (ctx->r2 != 0) {
        // lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
        goto L_80028B4C;
    }
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // j           L_80028B48
    // sb          $v0, 0x6E16($s0)
    MEM_B(0X6E16, ctx->r16) = ctx->r2;
    goto L_80028B48;
    // sb          $v0, 0x6E16($s0)
    MEM_B(0X6E16, ctx->r16) = ctx->r2;
L_80028AA8:
    // j           L_80028B48
    // sb          $v0, 0x6E16($a0)
    MEM_B(0X6E16, ctx->r4) = ctx->r2;
    goto L_80028B48;
    // sb          $v0, 0x6E16($a0)
    MEM_B(0X6E16, ctx->r4) = ctx->r2;
L_80028AB0:
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x6E17($a0)
    ctx->r3 = MEM_BU(0X6E17, ctx->r4);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // beq         $v1, $v0, L_80028B1C
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_80028B1C;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // lbu         $v1, 0x6E18($a0)
    ctx->r3 = MEM_BU(0X6E18, ctx->r4);
    // lbu         $v0, 0x6E19($a0)
    ctx->r2 = MEM_BU(0X6E19, ctx->r4);
    // nop

    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // bne         $v1, $zero, L_80028AF8
    if (ctx->r3 != 0) {
        // nop
    
        goto L_80028AF8;
    }
    // nop

    // break       7
    do_break(2147650292);
L_80028AF8:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $v1, $at, L_80028B10
    if (ctx->r3 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_80028B10;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_80028B10
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_80028B10;
    }
    // nop

    // break       6
    do_break(2147650316);
L_80028B10:
    // mflo        $v0
    ctx->r2 = lo;
    // j           L_80028B20
    // sb          $v0, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r2;
    goto L_80028B20;
    // sb          $v0, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r2;
L_80028B1C:
    // sb          $v0, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r2;
L_80028B20:
    // sb          $v0, 0x29($sp)
    MEM_B(0X29, ctx->r29) = ctx->r2;
    // sb          $v0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r2;
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // jal         0x80028220
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    sub_80028220(rdram, ctx);
    goto after_3;
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_4;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_4:
L_80028B48:
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
L_80028B4C:
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lbu         $v0, 0x6E17($v1)
    ctx->r2 = MEM_BU(0X6E17, ctx->r3);
    // nop

    // bne         $v0, $zero, L_80028BB4
    if (ctx->r2 != 0) {
        // nop
    
        goto L_80028BB4;
    }
    // nop

    // lbu         $v1, 0x6E16($v1)
    ctx->r3 = MEM_BU(0X6E16, ctx->r3);
    // nop

    // sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // bne         $v0, $zero, L_80028BB4
    if (ctx->r2 != 0) {
        // sltiu       $v0, $v1, 0x6
        ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
        goto L_80028BB4;
    }
    // sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // beq         $v0, $zero, L_80028BB4
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_80028BB4;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // sb          $v0, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r2;
    // sb          $v0, 0x29($sp)
    MEM_B(0X29, ctx->r29) = ctx->r2;
    // jal         0x80028220
    // sb          $v0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r2;
    sub_80028220(rdram, ctx);
    goto after_5;
    // sb          $v0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r2;
    after_5:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_6;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_6:
L_80028BB4:
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x6E17($s0)
    ctx->r3 = MEM_BU(0X6E17, ctx->r16);
    // addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // bne         $v1, $v0, L_80028C04
    if (ctx->r3 != ctx->r2) {
        // addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
        goto L_80028C04;
    }
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r2;
    // sb          $v0, 0x29($sp)
    MEM_B(0X29, ctx->r29) = ctx->r2;
    // jal         0x80028220
    // sb          $v0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r2;
    sub_80028220(rdram, ctx);
    goto after_7;
    // sb          $v0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r2;
    after_7:
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x800286A8
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    sub_800286A8(rdram, ctx);
    goto after_8;
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_8:
L_80028C04:
    // lbu         $v0, 0x6E19($s0)
    ctx->r2 = MEM_BU(0X6E19, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x6E19($s0)
    MEM_B(0X6E19, ctx->r16) = ctx->r2;
L_80028C14:
    // lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(0X50, ctx->r29);
    // lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(0X4C, ctx->r29);
    // lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(0X48, ctx->r29);
    // addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // jr          $ra
    // nop

    return;
    // nop

;}
