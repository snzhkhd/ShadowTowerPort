#include "recomp.h"
#include "disable_warnings.h"

void sub_8007D42C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // bgez        $s2, L_8007D4D0
    if (SIGNED(ctx->r18) >= 0) {
        // sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
        goto L_8007D4D0;
    }
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E7C($v0)
    ctx->r2 = MEM_W(0X7E7C, ctx->r2);
    // lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(0X40, ctx->r16);
    // lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x45($s0)
    MEM_B(0X45, ctx->r16) = ctx->r2;
    // nor         $v0, $zero, $s2
    ctx->r2 = ~(0 | ctx->r18);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E7C($v1)
    ctx->r3 = MEM_W(0X7E7C, ctx->r3);
    // nop

    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $zero, L_8007D4A8
    if (ctx->r2 != 0) {
        // andi        $s1, $a0, 0xFF
        ctx->r17 = ctx->r4 & 0XFF;
        goto L_8007D4A8;
    }
    // andi        $s1, $a0, 0xFF
    ctx->r17 = ctx->r4 & 0XFF;
L_8007D494:
    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8007D494
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007D494;
    }
    // nop

L_8007D4A8:
    // jal         0x8007F344
    // nop

    chkRC2wait(rdram, ctx);
    goto after_0;
    // nop

    after_0:
    // beq         $v0, $zero, L_8007D4A8
    if (ctx->r2 == 0) {
        // nor         $v0, $zero, $s2
        ctx->r2 = ~(0 | ctx->r18);
        goto L_8007D4A8;
    }
    // nor         $v0, $zero, $s2
    ctx->r2 = ~(0 | ctx->r18);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E7C($v1)
    ctx->r3 = MEM_W(0X7E7C, ctx->r3);
    // nop

    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // j           L_8007D5EC
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    goto L_8007D5EC;
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_8007D4D0:
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
    // nop

    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // sra         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) >> 4;
    // bne         $v0, $v1, L_8007D504
    if (ctx->r2 != ctx->r3) {
        // addiu       $a2, $zero, 0x88
        ctx->r6 = ADD32(0, 0X88);
        goto L_8007D504;
    }
    // addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // lbu         $v0, 0x44($s0)
    ctx->r2 = MEM_BU(0X44, ctx->r16);
    // nop

    // sltiu       $v0, $v0, 0x9
    ctx->r2 = ctx->r2 < 0X9 ? 1 : 0;
    // bne         $v0, $zero, L_8007D508
    if (ctx->r2 != 0) {
        // lui         $v0, 0x1F80
        ctx->r2 = S32(0X1F80 << 16);
        goto L_8007D508;
    }
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
    // addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
L_8007D504:
    // lui         $v0, 0x1F80
    ctx->r2 = S32(0X1F80 << 16);
L_8007D508:
    // ori         $v0, $v0, 0x1120
    ctx->r2 = ctx->r2 | 0X1120;
    // lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // lw          $a1, 0x7E7C($a1)
    ctx->r5 = MEM_W(0X7E7C, ctx->r5);
    // lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(0X0, ctx->r2);
    // lhu         $v1, 0x4($a1)
    ctx->r3 = MEM_HU(0X4, ctx->r5);
    // addiu       $v0, $zero, 0x1AE
    ctx->r2 = ADD32(0, 0X1AE);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $v0, -0x4AA4($at)
    MEM_W(-0X4AA4, ctx->r1) = ctx->r2;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // sw          $a0, -0x4AA8($at)
    MEM_W(-0X4AA8, ctx->r1) = ctx->r4;
    // andi        $v1, $v1, 0x2
    ctx->r3 = ctx->r3 & 0X2;
    // bne         $v1, $zero, L_8007D550
    if (ctx->r3 != 0) {
        // addu        $v1, $a1, $zero
        ctx->r3 = ADD32(ctx->r5, 0);
        goto L_8007D550;
    }
    // addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_8007D53C:
    // lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(0X4, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // beq         $v0, $zero, L_8007D53C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007D53C;
    }
    // nop

L_8007D550:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E7C($v0)
    ctx->r2 = MEM_W(0X7E7C, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E78($v1)
    ctx->r3 = MEM_W(0X7E78, ctx->r3);
    // lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(0X0, ctx->r2);
    // sh          $a2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r6;
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // bne         $v0, $zero, L_8007D5AC
    if (ctx->r2 != 0) {
        // andi        $s1, $a0, 0xFF
        ctx->r17 = ctx->r4 & 0XFF;
        goto L_8007D5AC;
    }
    // andi        $s1, $a0, 0xFF
    ctx->r17 = ctx->r4 & 0XFF;
L_8007D57C:
    // jal         0x8007F344
    // nop

    chkRC2wait(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // bne         $v0, $zero, L_8007D5EC
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x14
        ctx->r2 = ADD32(0, -0X14);
        goto L_8007D5EC;
    }
    // addiu       $v0, $zero, -0x14
    ctx->r2 = ADD32(0, -0X14);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E78($v0)
    ctx->r2 = MEM_W(0X7E78, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // beq         $v0, $zero, L_8007D57C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007D57C;
    }
    // nop

L_8007D5AC:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E7C($v0)
    ctx->r2 = MEM_W(0X7E7C, ctx->r2);
    // nop

    // sb          $s2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r18;
    // lbu         $v0, 0x45($s0)
    ctx->r2 = MEM_BU(0X45, ctx->r16);
    // lbu         $a0, 0x44($s0)
    ctx->r4 = MEM_BU(0X44, ctx->r16);
    // lw          $v1, 0x3C($s0)
    ctx->r3 = MEM_W(0X3C, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sb          $v0, 0x45($s0)
    MEM_B(0X45, ctx->r16) = ctx->r2;
    // sb          $s1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r17;
    // lbu         $v0, 0x44($s0)
    ctx->r2 = MEM_BU(0X44, ctx->r16);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r2;
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_8007D5EC:
    // lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
