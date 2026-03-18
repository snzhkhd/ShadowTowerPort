#include "recomp.h"
#include "disable_warnings.h"

void sub_80033110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v1, 0x5929($v0)
    ctx->r3 = MEM_BU(0X5929, ctx->r2);
    // addiu       $a0, $a0, -0x4930
    ctx->r4 = ADD32(ctx->r4, -0X4930);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v0, 0xC($v0)
    ctx->r2 = MEM_BU(0XC, ctx->r2);
    // nop

    // andi        $s2, $v0, 0xF
    ctx->r18 = ctx->r2 & 0XF;
    // andi        $s1, $v0, 0xF0
    ctx->r17 = ctx->r2 & 0XF0;
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v1, $v1, -0x19
    ctx->r3 = ADD32(ctx->r3, -0X19);
    // sltiu       $v1, $v1, 0x2
    ctx->r3 = ctx->r3 < 0X2 ? 1 : 0;
    // bne         $v1, $zero, L_8003317C
    if (ctx->r3 != 0) {
        // lui         $v1, 0x8019
        ctx->r3 = S32(0X8019 << 16);
        goto L_8003317C;
    }
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // beq         $v1, $v0, L_80033178
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0x17
        ctx->r2 = ADD32(0, 0X17);
        goto L_80033178;
    }
    // addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
    // bne         $v1, $v0, L_80033194
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801A
        ctx->r2 = S32(0X801A << 16);
        goto L_80033194;
    }
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80033178:
    // lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
L_8003317C:
    // addiu       $v1, $v1, -0x4930
    ctx->r3 = ADD32(ctx->r3, -0X4930);
    // lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(0X4, ctx->r3);
    // sb          $zero, 0x9($v1)
    MEM_B(0X9, ctx->r3) = 0;
    // andi        $v0, $v0, 0xDF
    ctx->r2 = ctx->r2 & 0XDF;
    // sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
L_80033194:
    // lb          $v0, -0x6F11($v0)
    ctx->r2 = MEM_BS(-0X6F11, ctx->r2);
    // nop

    // bgez        $v0, L_800331C0
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800331C0;
    }
    // nop

    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, -0x4930
    ctx->r2 = ADD32(ctx->r2, -0X4930);
    // lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(0X3, ctx->r2);
    // lbu         $a0, 0x4($v0)
    ctx->r4 = MEM_BU(0X4, ctx->r2);
    // ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // j           L_800331DC
    // ori         $a0, $a0, 0x4
    ctx->r4 = ctx->r4 | 0X4;
    goto L_800331DC;
    // ori         $a0, $a0, 0x4
    ctx->r4 = ctx->r4 | 0X4;
L_800331C0:
    // blez        $v0, L_800331E4
    if (SIGNED(ctx->r2) <= 0) {
        // lui         $v0, 0x8019
        ctx->r2 = S32(0X8019 << 16);
        goto L_800331E4;
    }
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $v0, -0x4930
    ctx->r2 = ADD32(ctx->r2, -0X4930);
    // lbu         $v1, 0x3($v0)
    ctx->r3 = MEM_BU(0X3, ctx->r2);
    // lbu         $a0, 0x4($v0)
    ctx->r4 = MEM_BU(0X4, ctx->r2);
    // ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
L_800331DC:
    // sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
    // sb          $a0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r4;
L_800331E4:
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $a0, $v0, -0x4930
    ctx->r4 = ADD32(ctx->r2, -0X4930);
    // lbu         $v0, 0xA($a0)
    ctx->r2 = MEM_BU(0XA, ctx->r4);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // beq         $v0, $a2, L_800339A8
    if (ctx->r2 == ctx->r6) {
        // addiu       $a3, $zero, 0x2
        ctx->r7 = ADD32(0, 0X2);
        goto L_800339A8;
    }
    // addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // bne         $v0, $a3, L_8003320C
    if (ctx->r2 != ctx->r7) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_8003320C;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // j           L_800339A8
    // sb          $zero, 0xA($a0)
    MEM_B(0XA, ctx->r4) = 0;
    goto L_800339A8;
    // sb          $zero, 0xA($a0)
    MEM_B(0XA, ctx->r4) = 0;
L_8003320C:
    // lbu         $a1, 0x5929($v0)
    ctx->r5 = MEM_BU(0X5929, ctx->r2);
    // lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(0X7, ctx->r4);
    // nop

    // beq         $a1, $v0, L_8003323C
    if (ctx->r5 == ctx->r2) {
        // lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
        goto L_8003323C;
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
    // sb          $a2, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r6;
    // sb          $a1, 0x7($a0)
    MEM_B(0X7, ctx->r4) = ctx->r5;
    // sb          $zero, 0x6DFE($v0)
    MEM_B(0X6DFE, ctx->r2) = 0;
L_8003323C:
    // lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(0X8, ctx->r4);
    // nop

    // bne         $v0, $a3, L_80033268
    if (ctx->r2 != ctx->r7) {
        // lui         $v0, 0x8019
        ctx->r2 = S32(0X8019 << 16);
        goto L_80033268;
    }
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // lbu         $v1, -0x6EC0($v0)
    ctx->r3 = MEM_BU(-0X6EC0, ctx->r2);
    // addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // bne         $v1, $v0, L_80033268
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x8019
        ctx->r2 = S32(0X8019 << 16);
        goto L_80033268;
    }
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
L_80033268:
    // addiu       $a0, $v0, -0x4930
    ctx->r4 = ADD32(ctx->r2, -0X4930);
    // lbu         $v0, 0x9($a0)
    ctx->r2 = MEM_BU(0X9, ctx->r4);
    // nop

    // beq         $v0, $zero, L_80033288
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801B
        ctx->r2 = S32(0X801B << 16);
        goto L_80033288;
    }
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // j           L_800332D8
    // sb          $zero, 0x9($a0)
    MEM_B(0X9, ctx->r4) = 0;
    goto L_800332D8;
    // sb          $zero, 0x9($a0)
    MEM_B(0X9, ctx->r4) = 0;
L_80033288:
    // lbu         $v0, 0x5929($v0)
    ctx->r2 = MEM_BU(0X5929, ctx->r2);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lh          $v1, 0xC($v0)
    ctx->r3 = MEM_HS(0XC, ctx->r2);
    // addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // bne         $v1, $v0, L_800332B0
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_800332B0;
    }
    // nop

    // j           L_800332D8
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    goto L_800332D8;
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800332B0:
    // lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(0X3, ctx->r4);
    // nop

    // or          $v1, $s2, $v0
    ctx->r3 = ctx->r18 | ctx->r2;
    // andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // bne         $v0, $zero, L_800332D8
    if (ctx->r2 != 0) {
        // addiu       $s2, $zero, 0x4
        ctx->r18 = ADD32(0, 0X4);
        goto L_800332D8;
    }
    // addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // beq         $v0, $zero, L_800332D8
    if (ctx->r2 == 0) {
        // addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
        goto L_800332D8;
    }
    // addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_800332D8:
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $a0, $v0, -0x4930
    ctx->r4 = ADD32(ctx->r2, -0X4930);
    // lbu         $v1, 0x4($a0)
    ctx->r3 = MEM_BU(0X4, ctx->r4);
    // nop

    // beq         $v1, $zero, L_8003332C
    if (ctx->r3 == 0) {
        // andi        $v0, $v1, 0xE0
        ctx->r2 = ctx->r3 & 0XE0;
        goto L_8003332C;
    }
    // andi        $v0, $v1, 0xE0
    ctx->r2 = ctx->r3 & 0XE0;
    // bne         $v0, $zero, L_80033328
    if (ctx->r2 != 0) {
        // andi        $v0, $v1, 0xF
        ctx->r2 = ctx->r3 & 0XF;
        goto L_80033328;
    }
    // andi        $v0, $v1, 0xF
    ctx->r2 = ctx->r3 & 0XF;
    // bne         $v0, $zero, L_8003332C
    if (ctx->r2 != 0) {
        // addiu       $s1, $zero, 0x40
        ctx->r17 = ADD32(0, 0X40);
        goto L_8003332C;
    }
    // addiu       $s1, $zero, 0x40
    ctx->r17 = ADD32(0, 0X40);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v0, 0x5929($v0)
    ctx->r2 = MEM_BU(0X5929, ctx->r2);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lhu         $v0, 0xC($v0)
    ctx->r2 = MEM_HU(0XC, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // beq         $v0, $zero, L_8003332C
    if (ctx->r2 == 0) {
        // addiu       $s1, $zero, 0x20
        ctx->r17 = ADD32(0, 0X20);
        goto L_8003332C;
    }
    // addiu       $s1, $zero, 0x20
    ctx->r17 = ADD32(0, 0X20);
L_80033328:
    // addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
L_8003332C:
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $s0, $v0, -0x4930
    ctx->r16 = ADD32(ctx->r2, -0X4930);
    // lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(0X5, ctx->r16);
    // andi        $a1, $s2, 0xFF
    ctx->r5 = ctx->r18 & 0XFF;
    // bne         $a1, $v0, L_80033354
    if (ctx->r5 != ctx->r2) {
        // nop
    
        goto L_80033354;
    }
    // nop

    // lbu         $v0, 0x6($s0)
    ctx->r2 = MEM_BU(0X6, ctx->r16);
    // nop

    // beq         $s1, $v0, L_80033390
    if (ctx->r17 == ctx->r2) {
        // lui         $v0, 0x8019
        ctx->r2 = S32(0X8019 << 16);
        goto L_80033390;
    }
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
L_80033354:
    // lbu         $v1, 0x8($s0)
    ctx->r3 = MEM_BU(0X8, ctx->r16);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_8003336C
    if (ctx->r3 != ctx->r2) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8003336C;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // j           L_8003337C
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    goto L_8003337C;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_8003336C:
    // bne         $v1, $zero, L_80033390
    if (ctx->r3 != 0) {
        // lui         $v0, 0x8019
        ctx->r2 = S32(0X8019 << 16);
        goto L_80033390;
    }
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8003337C:
    // jal         0x80032800
    // nop

    sub_80032800(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // sb          $s2, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r18;
    // sb          $s1, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r17;
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
L_80033390:
    // addiu       $a0, $v0, -0x4930
    ctx->r4 = ADD32(ctx->r2, -0X4930);
    // lbu         $v1, 0x8($a0)
    ctx->r3 = MEM_BU(0X8, ctx->r4);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_800333D4
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x8019
        ctx->r2 = S32(0X8019 << 16);
        goto L_800333D4;
    }
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $v0, $v0, 0x5920
    ctx->r2 = ADD32(ctx->r2, 0X5920);
    // lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(0X2, ctx->r2);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x7
    ctx->r2 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // bne         $v0, $zero, L_800333D4
    if (ctx->r2 != 0) {
        // lui         $v0, 0x8019
        ctx->r2 = S32(0X8019 << 16);
        goto L_800333D4;
    }
    // lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // j           L_800333EC
    // sb          $v0, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r2;
    goto L_800333EC;
    // sb          $v0, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r2;
L_800333D4:
    // addiu       $a0, $v0, -0x4930
    ctx->r4 = ADD32(ctx->r2, -0X4930);
    // lbu         $v1, 0x8($a0)
    ctx->r3 = MEM_BU(0X8, ctx->r4);
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // bne         $v1, $v0, L_800333F0
    if (ctx->r3 != ctx->r2) {
        // lui         $v1, 0x1
        ctx->r3 = S32(0X1 << 16);
        goto L_800333F0;
    }
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // sb          $zero, 0x8($a0)
    MEM_B(0X8, ctx->r4) = 0;
L_800333EC:
    // lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
L_800333F0:
    // ori         $v1, $v1, 0x8000
    ctx->r3 = ctx->r3 | 0X8000;
    // lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // addiu       $v0, $v0, -0x2F70
    ctx->r2 = ADD32(ctx->r2, -0X2F70);
    // addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v1, 0x6DFE($a1)
    ctx->r3 = MEM_BU(0X6DFE, ctx->r5);
    // addiu       $a0, $a0, -0x4930
    ctx->r4 = ADD32(ctx->r4, -0X4930);
    // sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // beq         $v0, $zero, L_80033894
    if (ctx->r2 == 0) {
        // sb          $zero, 0x3($a0)
        MEM_B(0X3, ctx->r4) = 0;
        goto L_80033894;
    }
    // sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // andi        $a2, $v1, 0x7F
    ctx->r6 = ctx->r3 & 0X7F;
    // sltiu       $v0, $a2, 0x40
    ctx->r2 = ctx->r6 < 0X40 ? 1 : 0;
    // bne         $v0, $zero, L_80033524
    if (ctx->r2 != 0) {
        // lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
        goto L_80033524;
    }
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // lw          $t0, 0x6E08($a1)
    ctx->r8 = MEM_W(0X6E08, ctx->r5);
    // lbu         $v1, 0x6DFD($a1)
    ctx->r3 = MEM_BU(0X6DFD, ctx->r5);
    // sb          $zero, 0x6DFE($a1)
    MEM_B(0X6DFE, ctx->r5) = 0;
    // sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3) << 3;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    // addiu       $a3, $a0, 0x6C
    ctx->r7 = ADD32(ctx->r4, 0X6C);
    // or          $v0, $a3, $t0
    ctx->r2 = ctx->r7 | ctx->r8;
    // lbu         $v1, 0x6E14($a1)
    ctx->r3 = MEM_BU(0X6E14, ctx->r5);
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // beq         $v0, $zero, L_800334C0
    if (ctx->r2 == 0) {
        // sb          $v1, 0x6DFC($a1)
        MEM_B(0X6DFC, ctx->r5) = ctx->r3;
        goto L_800334C0;
    }
    // sb          $v1, 0x6DFC($a1)
    MEM_B(0X6DFC, ctx->r5) = ctx->r3;
    // addiu       $t1, $a0, 0xCC
    ctx->r9 = ADD32(ctx->r4, 0XCC);
L_8003346C:
    // lwl         $v0, 0x3($a3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r7);
    // lwr         $v0, 0x0($a3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r7);
    // lwl         $v1, 0x7($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r7);
    // lwr         $v1, 0x4($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r7);
    // lwl         $a0, 0xB($a3)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r7);
    // lwr         $a0, 0x8($a3)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r7);
    // lwl         $a1, 0xF($a3)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r7);
    // lwr         $a1, 0xC($a3)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r7);
    // swl         $v0, 0x3($t0)
    do_swl(rdram, 0X3, ctx->r8, ctx->r2);
    // swr         $v0, 0x0($t0)
    do_swr(rdram, 0X0, ctx->r8, ctx->r2);
    // swl         $v1, 0x7($t0)
    do_swl(rdram, 0X7, ctx->r8, ctx->r3);
    // swr         $v1, 0x4($t0)
    do_swr(rdram, 0X4, ctx->r8, ctx->r3);
    // swl         $a0, 0xB($t0)
    do_swl(rdram, 0XB, ctx->r8, ctx->r4);
    // swr         $a0, 0x8($t0)
    do_swr(rdram, 0X8, ctx->r8, ctx->r4);
    // swl         $a1, 0xF($t0)
    do_swl(rdram, 0XF, ctx->r8, ctx->r5);
    // swr         $a1, 0xC($t0)
    do_swr(rdram, 0XC, ctx->r8, ctx->r5);
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // bne         $a3, $t1, L_8003346C
    if (ctx->r7 != ctx->r9) {
        // addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
        goto L_8003346C;
    }
    // addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // j           L_800334F0
    // nop

    goto L_800334F0;
    // nop

L_800334C0:
    // addiu       $t1, $a0, 0xCC
    ctx->r9 = ADD32(ctx->r4, 0XCC);
L_800334C4:
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(0X4, ctx->r7);
    // lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(0X8, ctx->r7);
    // lw          $a1, 0xC($a3)
    ctx->r5 = MEM_W(0XC, ctx->r7);
    // sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // sw          $v1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r3;
    // sw          $a0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r4;
    // sw          $a1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r5;
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // bne         $a3, $t1, L_800334C4
    if (ctx->r7 != ctx->r9) {
        // addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
        goto L_800334C4;
    }
    // addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
L_800334F0:
    // lwl         $v0, 0x3($a3)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r7);
    // lwr         $v0, 0x0($a3)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r7);
    // lwl         $v1, 0x7($a3)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r7);
    // lwr         $v1, 0x4($a3)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r7);
    // lwl         $a0, 0xB($a3)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r7);
    // lwr         $a0, 0x8($a3)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r7);
    // swl         $v0, 0x3($t0)
    do_swl(rdram, 0X3, ctx->r8, ctx->r2);
    // swr         $v0, 0x0($t0)
    do_swr(rdram, 0X0, ctx->r8, ctx->r2);
    // swl         $v1, 0x7($t0)
    do_swl(rdram, 0X7, ctx->r8, ctx->r3);
    // swr         $v1, 0x4($t0)
    do_swr(rdram, 0X4, ctx->r8, ctx->r3);
    // swl         $a0, 0xB($t0)
    do_swl(rdram, 0XB, ctx->r8, ctx->r4);
    // swr         $a0, 0x8($t0)
    do_swr(rdram, 0X8, ctx->r8, ctx->r4);
    // lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
L_80033524:
    // ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
    // lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // addiu       $v1, $v1, -0x2F70
    ctx->r3 = ADD32(ctx->r3, -0X2F70);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // lw          $v0, 0x6E0C($v1)
    ctx->r2 = MEM_W(0X6E0C, ctx->r3);
    // addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // lh          $v0, 0x68($v0)
    ctx->r2 = MEM_HS(0X68, ctx->r2);
    // subu        $a1, $a1, $a2
    ctx->r5 = SUB32(ctx->r5, ctx->r6);
    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x6E10($v1)
    ctx->r2 = MEM_W(0X6E10, ctx->r3);
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x68($v0)
    ctx->r2 = MEM_HS(0X68, ctx->r2);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, 0x6E08($v1)
    ctx->r4 = MEM_W(0X6E08, ctx->r3);
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // sh          $v0, 0x68($a0)
    MEM_H(0X68, ctx->r4) = ctx->r2;
    // lw          $v0, 0x6E0C($v1)
    ctx->r2 = MEM_W(0X6E0C, ctx->r3);
    // nop

    // lh          $v0, 0x6A($v0)
    ctx->r2 = MEM_HS(0X6A, ctx->r2);
    // nop

    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x6E10($v1)
    ctx->r2 = MEM_W(0X6E10, ctx->r3);
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x6A($v0)
    ctx->r2 = MEM_HS(0X6A, ctx->r2);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, 0x6E08($v1)
    ctx->r4 = MEM_W(0X6E08, ctx->r3);
    // sra         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) >> 6;
    // sh          $v0, 0x6A($a0)
    MEM_H(0X6A, ctx->r4) = ctx->r2;
    // lw          $v0, 0x6E0C($v1)
    ctx->r2 = MEM_W(0X6E0C, ctx->r3);
    // nop

    // lh          $v0, 0x50($v0)
    ctx->r2 = MEM_HS(0X50, ctx->r2);
    // nop

    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x6E10($v1)
    ctx->r2 = MEM_W(0X6E10, ctx->r3);
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x50($v0)
    ctx->r2 = MEM_HS(0X50, ctx->r2);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, 0x6E08($v1)
    ctx->r4 = MEM_W(0X6E08, ctx->r3);
    // srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // sh          $v0, 0x50($a0)
    MEM_H(0X50, ctx->r4) = ctx->r2;
    // lw          $v0, 0x6E0C($v1)
    ctx->r2 = MEM_W(0X6E0C, ctx->r3);
    // nop

    // lh          $v0, 0x52($v0)
    ctx->r2 = MEM_HS(0X52, ctx->r2);
    // nop

    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x6E10($v1)
    ctx->r2 = MEM_W(0X6E10, ctx->r3);
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x52($v0)
    ctx->r2 = MEM_HS(0X52, ctx->r2);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, 0x6E08($v1)
    ctx->r4 = MEM_W(0X6E08, ctx->r3);
    // srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // sh          $v0, 0x52($a0)
    MEM_H(0X52, ctx->r4) = ctx->r2;
    // lw          $v0, 0x6E0C($v1)
    ctx->r2 = MEM_W(0X6E0C, ctx->r3);
    // nop

    // lh          $v0, 0x54($v0)
    ctx->r2 = MEM_HS(0X54, ctx->r2);
    // nop

    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x6E10($v1)
    ctx->r2 = MEM_W(0X6E10, ctx->r3);
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x54($v0)
    ctx->r2 = MEM_HS(0X54, ctx->r2);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, 0x6E08($v1)
    ctx->r4 = MEM_W(0X6E08, ctx->r3);
    // srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // sh          $v0, 0x54($a0)
    MEM_H(0X54, ctx->r4) = ctx->r2;
    // lw          $v0, 0x6E0C($v1)
    ctx->r2 = MEM_W(0X6E0C, ctx->r3);
    // nop

    // lh          $v0, 0x56($v0)
    ctx->r2 = MEM_HS(0X56, ctx->r2);
    // nop

    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x6E10($v1)
    ctx->r2 = MEM_W(0X6E10, ctx->r3);
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x56($v0)
    ctx->r2 = MEM_HS(0X56, ctx->r2);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, 0x6E08($v1)
    ctx->r4 = MEM_W(0X6E08, ctx->r3);
    // srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // sh          $v0, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r2;
    // lw          $v0, 0x6E0C($v1)
    ctx->r2 = MEM_W(0X6E0C, ctx->r3);
    // nop

    // lh          $v0, 0x58($v0)
    ctx->r2 = MEM_HS(0X58, ctx->r2);
    // nop

    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x6E10($v1)
    ctx->r2 = MEM_W(0X6E10, ctx->r3);
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x58($v0)
    ctx->r2 = MEM_HS(0X58, ctx->r2);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, 0x6E08($v1)
    ctx->r4 = MEM_W(0X6E08, ctx->r3);
    // srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // sh          $v0, 0x58($a0)
    MEM_H(0X58, ctx->r4) = ctx->r2;
    // lw          $v0, 0x6E0C($v1)
    ctx->r2 = MEM_W(0X6E0C, ctx->r3);
    // nop

    // lh          $v0, 0x5A($v0)
    ctx->r2 = MEM_HS(0X5A, ctx->r2);
    // nop

    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x6E10($v1)
    ctx->r2 = MEM_W(0X6E10, ctx->r3);
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x5A($v0)
    ctx->r2 = MEM_HS(0X5A, ctx->r2);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, 0x6E08($v1)
    ctx->r4 = MEM_W(0X6E08, ctx->r3);
    // srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // sh          $v0, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r2;
    // lw          $v0, 0x6E0C($v1)
    ctx->r2 = MEM_W(0X6E0C, ctx->r3);
    // nop

    // lh          $v0, 0x5C($v0)
    ctx->r2 = MEM_HS(0X5C, ctx->r2);
    // nop

    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x6E10($v1)
    ctx->r2 = MEM_W(0X6E10, ctx->r3);
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x5C($v0)
    ctx->r2 = MEM_HS(0X5C, ctx->r2);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, 0x6E08($v1)
    ctx->r4 = MEM_W(0X6E08, ctx->r3);
    // srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // sh          $v0, 0x5C($a0)
    MEM_H(0X5C, ctx->r4) = ctx->r2;
    // lw          $v0, 0x6E0C($v1)
    ctx->r2 = MEM_W(0X6E0C, ctx->r3);
    // nop

    // lh          $v0, 0x5E($v0)
    ctx->r2 = MEM_HS(0X5E, ctx->r2);
    // nop

    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x6E10($v1)
    ctx->r2 = MEM_W(0X6E10, ctx->r3);
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x5E($v0)
    ctx->r2 = MEM_HS(0X5E, ctx->r2);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, 0x6E08($v1)
    ctx->r4 = MEM_W(0X6E08, ctx->r3);
    // srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // sh          $v0, 0x5E($a0)
    MEM_H(0X5E, ctx->r4) = ctx->r2;
    // lw          $v0, 0x6E0C($v1)
    ctx->r2 = MEM_W(0X6E0C, ctx->r3);
    // nop

    // lh          $v0, 0x60($v0)
    ctx->r2 = MEM_HS(0X60, ctx->r2);
    // nop

    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x6E10($v1)
    ctx->r2 = MEM_W(0X6E10, ctx->r3);
    // mflo        $a0
    ctx->r4 = lo;
    // lh          $v0, 0x60($v0)
    ctx->r2 = MEM_HS(0X60, ctx->r2);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, 0x6E08($v1)
    ctx->r4 = MEM_W(0X6E08, ctx->r3);
    // srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // sh          $v0, 0x60($a0)
    MEM_H(0X60, ctx->r4) = ctx->r2;
    // lw          $v0, 0x6E0C($v1)
    ctx->r2 = MEM_W(0X6E0C, ctx->r3);
    // nop

    // lbu         $v0, 0x64($v0)
    ctx->r2 = MEM_BU(0X64, ctx->r2);
    // nop

    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x6E10($v1)
    ctx->r2 = MEM_W(0X6E10, ctx->r3);
    // mflo        $a0
    ctx->r4 = lo;
    // lbu         $v0, 0x64($v0)
    ctx->r2 = MEM_BU(0X64, ctx->r2);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, 0x6E08($v1)
    ctx->r4 = MEM_W(0X6E08, ctx->r3);
    // srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // sb          $v0, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r2;
    // lw          $v0, 0x6E0C($v1)
    ctx->r2 = MEM_W(0X6E0C, ctx->r3);
    // nop

    // lbu         $v0, 0x65($v0)
    ctx->r2 = MEM_BU(0X65, ctx->r2);
    // nop

    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x6E10($v1)
    ctx->r2 = MEM_W(0X6E10, ctx->r3);
    // mflo        $a0
    ctx->r4 = lo;
    // lbu         $v0, 0x65($v0)
    ctx->r2 = MEM_BU(0X65, ctx->r2);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, 0x6E08($v1)
    ctx->r4 = MEM_W(0X6E08, ctx->r3);
    // srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // sb          $v0, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r2;
    // lw          $v0, 0x6E0C($v1)
    ctx->r2 = MEM_W(0X6E0C, ctx->r3);
    // nop

    // lbu         $v0, 0x66($v0)
    ctx->r2 = MEM_BU(0X66, ctx->r2);
    // nop

    // mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v0, 0x6E10($v1)
    ctx->r2 = MEM_W(0X6E10, ctx->r3);
    // mflo        $a0
    ctx->r4 = lo;
    // lbu         $v0, 0x66($v0)
    ctx->r2 = MEM_BU(0X66, ctx->r2);
    // nop

    // mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // lw          $a0, 0x6E08($v1)
    ctx->r4 = MEM_W(0X6E08, ctx->r3);
    // srl         $v0, $v0, 6
    ctx->r2 = S32(U32(ctx->r2) >> 6);
    // sb          $v0, 0x66($a0)
    MEM_B(0X66, ctx->r4) = ctx->r2;
    // lbu         $v0, 0x6DFE($v1)
    ctx->r2 = MEM_BU(0X6DFE, ctx->r3);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_80033978
    // sb          $v0, 0x6DFE($v1)
    MEM_B(0X6DFE, ctx->r3) = ctx->r2;
    goto L_80033978;
    // sb          $v0, 0x6DFE($v1)
    MEM_B(0X6DFE, ctx->r3) = ctx->r2;
L_80033894:
    // lbu         $v0, 0x6DFD($a1)
    ctx->r2 = MEM_BU(0X6DFD, ctx->r5);
    // lw          $a3, 0x6E08($a1)
    ctx->r7 = MEM_W(0X6E08, ctx->r5);
    // sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2) << 3;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // addiu       $a2, $v1, 0x6C
    ctx->r6 = ADD32(ctx->r3, 0X6C);
    // or          $v0, $a2, $a3
    ctx->r2 = ctx->r6 | ctx->r7;
    // andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // beq         $v0, $zero, L_8003391C
    if (ctx->r2 == 0) {
        // addiu       $t0, $v1, 0xCC
        ctx->r8 = ADD32(ctx->r3, 0XCC);
        goto L_8003391C;
    }
    // addiu       $t0, $v1, 0xCC
    ctx->r8 = ADD32(ctx->r3, 0XCC);
L_800338C8:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lwl         $a0, 0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r6);
    // lwr         $a0, 0x8($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r6);
    // lwl         $a1, 0xF($a2)
    ctx->r5 = do_lwl(rdram, ctx->r5, 0XF, ctx->r6);
    // lwr         $a1, 0xC($a2)
    ctx->r5 = do_lwr(rdram, ctx->r5, 0XC, ctx->r6);
    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // swl         $v1, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r3);
    // swr         $v1, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r3);
    // swl         $a0, 0xB($a3)
    do_swl(rdram, 0XB, ctx->r7, ctx->r4);
    // swr         $a0, 0x8($a3)
    do_swr(rdram, 0X8, ctx->r7, ctx->r4);
    // swl         $a1, 0xF($a3)
    do_swl(rdram, 0XF, ctx->r7, ctx->r5);
    // swr         $a1, 0xC($a3)
    do_swr(rdram, 0XC, ctx->r7, ctx->r5);
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_800338C8
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_800338C8;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // j           L_80033948
    // nop

    goto L_80033948;
    // nop

L_8003391C:
    // lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(0X0, ctx->r6);
    // lw          $v1, 0x4($a2)
    ctx->r3 = MEM_W(0X4, ctx->r6);
    // lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(0X8, ctx->r6);
    // lw          $a1, 0xC($a2)
    ctx->r5 = MEM_W(0XC, ctx->r6);
    // sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // sw          $a0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r4;
    // sw          $a1, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r5;
    // addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // bne         $a2, $t0, L_8003391C
    if (ctx->r6 != ctx->r8) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8003391C;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_80033948:
    // lwl         $v0, 0x3($a2)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X3, ctx->r6);
    // lwr         $v0, 0x0($a2)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X0, ctx->r6);
    // lwl         $v1, 0x7($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X7, ctx->r6);
    // lwr         $v1, 0x4($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X4, ctx->r6);
    // lwl         $a0, 0xB($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0XB, ctx->r6);
    // lwr         $a0, 0x8($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X8, ctx->r6);
    // swl         $v0, 0x3($a3)
    do_swl(rdram, 0X3, ctx->r7, ctx->r2);
    // swr         $v0, 0x0($a3)
    do_swr(rdram, 0X0, ctx->r7, ctx->r2);
    // swl         $v1, 0x7($a3)
    do_swl(rdram, 0X7, ctx->r7, ctx->r3);
    // swr         $v1, 0x4($a3)
    do_swr(rdram, 0X4, ctx->r7, ctx->r3);
    // swl         $a0, 0xB($a3)
    do_swl(rdram, 0XB, ctx->r7, ctx->r4);
    // swr         $a0, 0x8($a3)
    do_swr(rdram, 0X8, ctx->r7, ctx->r4);
L_80033978:
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
    // lw          $v1, 0x6E08($v0)
    ctx->r3 = MEM_W(0X6E08, ctx->r2);
    // nop

    // lh          $v1, 0x68($v1)
    ctx->r3 = MEM_HS(0X68, ctx->r3);
    // addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    // sw          $a0, 0x6E04($v0)
    MEM_W(0X6E04, ctx->r2) = ctx->r4;
    // addiu       $v1, $v1, -0x400
    ctx->r3 = ADD32(ctx->r3, -0X400);
    // sw          $v1, 0x6E00($v0)
    MEM_W(0X6E00, ctx->r2) = ctx->r3;
L_800339A8:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
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
