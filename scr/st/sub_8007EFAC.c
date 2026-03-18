#include "recomp.h"
#include "disable_warnings.h"

void sub_8007EFAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
    // addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // lbu         $s1, 0xE8($s0)
    ctx->r17 = MEM_BU(0XE8, ctx->r16);
    // srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // bne         $v0, $v1, L_8007EFE4
    if (ctx->r2 != ctx->r3) {
        // sb          $v0, 0xE8($s0)
        MEM_B(0XE8, ctx->r16) = ctx->r2;
        goto L_8007EFE4;
    }
    // sb          $v0, 0xE8($s0)
    MEM_B(0XE8, ctx->r16) = ctx->r2;
    // j           L_8007F044
    // sb          $s1, 0xE8($s0)
    MEM_B(0XE8, ctx->r16) = ctx->r17;
    goto L_8007F044;
    // sb          $s1, 0xE8($s0)
    MEM_B(0XE8, ctx->r16) = ctx->r17;
L_8007EFE4:
    // lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(0X30, ctx->r16);
    // nop

    // sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
    // lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(0X30, ctx->r16);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // nop

    // sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x44($s0)
    ctx->r2 = MEM_BU(0X44, ctx->r16);
    // addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8007F044
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007F044;
    }
    // nop

L_8007F018:
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
    // lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(0X30, ctx->r16);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(0X0, ctx->r2);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // lbu         $v0, 0x44($s0)
    ctx->r2 = MEM_BU(0X44, ctx->r16);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8007F018
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007F018;
    }
    // nop

L_8007F044:
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
    // nop

    // lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(0X1, ctx->r2);
    // nop

    // bne         $v0, $zero, L_8007F08C
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007F08C;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lbu         $v1, 0x46($s0)
    ctx->r3 = MEM_BU(0X46, ctx->r16);
    // nop

    // bne         $v1, $v0, L_8007F07C
    if (ctx->r3 != ctx->r2) {
        // nop
    
        goto L_8007F07C;
    }
    // nop

    // lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(0X14, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8007F08C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007F08C;
    }
    // nop

L_8007F07C:
    // lbu         $v0, 0x50($s0)
    ctx->r2 = MEM_BU(0X50, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8007F0CC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007F0CC;
    }
    // nop

L_8007F08C:
    // jal         0x8007F2EC
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8007F2EC(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // bne         $v0, $zero, L_8007F0E0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007F0E0;
    }
    // nop

    // lbu         $v0, 0x37($s0)
    ctx->r2 = MEM_BU(0X37, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8007F0E0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007F0E0;
    }
    // nop

    // lbu         $v0, 0x4A($s0)
    ctx->r2 = MEM_BU(0X4A, ctx->r16);
    // nop

    // bne         $v0, $zero, L_8007F0E0
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007F0E0;
    }
    // nop

    // lbu         $v0, 0xE8($s0)
    ctx->r2 = MEM_BU(0XE8, ctx->r16);
    // nop

    // beq         $v0, $s1, L_8007F0E0
    if (ctx->r2 == ctx->r17) {
        // nop
    
        goto L_8007F0E0;
    }
    // nop

L_8007F0CC:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E1C($v0)
    ctx->r2 = MEM_W(0X7E1C, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
L_8007F0E0:
    // lbu         $v0, 0x46($s0)
    ctx->r2 = MEM_BU(0X46, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // sltiu       $v0, $v0, 0xFC
    ctx->r2 = ctx->r2 < 0XFC ? 1 : 0;
    // beq         $v0, $zero, L_8007F128
    if (ctx->r2 == 0) {
        // sb          $zero, 0x4A($s0)
        MEM_B(0X4A, ctx->r16) = 0;
        goto L_8007F128;
    }
    // sb          $zero, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = 0;
    // lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(0X3C, ctx->r16);
    // nop

    // lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(0X0, ctx->r2);
    // addiu       $v0, $zero, 0xF3
    ctx->r2 = ADD32(0, 0XF3);
    // beq         $v1, $v0, L_8007F128
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8007F128;
    }
    // nop

    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E1C($v0)
    ctx->r2 = MEM_W(0X7E1C, ctx->r2);
    // nop

    // jalr        $v0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_2;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
L_8007F128:
    // lbu         $v1, 0x46($s0)
    ctx->r3 = MEM_BU(0X46, ctx->r16);
    // nop

    // beq         $v1, $zero, L_8007F150
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8007F150;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8007F150
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8007F150;
    }
    // nop

    // lbu         $v0, 0x36($s0)
    ctx->r2 = MEM_BU(0X36, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8007F1FC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007F1FC;
    }
    // nop

L_8007F150:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // beq         $v1, $a0, L_8007F1A8
    if (ctx->r3 == ctx->r4) {
        // slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
        goto L_8007F1A8;
    }
    // slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_8007F174
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, 0xFE
        ctx->r2 = ADD32(0, 0XFE);
        goto L_8007F174;
    }
    // addiu       $v0, $zero, 0xFE
    ctx->r2 = ADD32(0, 0XFE);
    // beq         $v1, $zero, L_8007F18C
    if (ctx->r3 == 0) {
        // nop
    
        goto L_8007F18C;
    }
    // nop

    // j           L_8007F1C4
    // nop

    goto L_8007F1C4;
    // nop

L_8007F174:
    // beq         $v1, $v0, L_8007F1BC
    if (ctx->r3 == ctx->r2) {
        // addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
        goto L_8007F1BC;
    }
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // beq         $v1, $v0, L_8007F1FC
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8007F1FC;
    }
    // nop

    // j           L_8007F1C4
    // nop

    goto L_8007F1C4;
    // nop

L_8007F18C:
    // lbu         $v0, 0xE8($s0)
    ctx->r2 = MEM_BU(0XE8, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8007F1FC
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007F1FC;
    }
    // nop

    // lbu         $v0, 0x46($s0)
    ctx->r2 = MEM_BU(0X46, ctx->r16);
    // j           L_8007F1B0
    // sb          $a0, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r4;
    goto L_8007F1B0;
    // sb          $a0, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r4;
L_8007F1A8:
    // lbu         $v0, 0x46($s0)
    ctx->r2 = MEM_BU(0X46, ctx->r16);
    // sb          $zero, 0x47($s0)
    MEM_B(0X47, ctx->r16) = 0;
L_8007F1B0:
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8007F1FC
    // sb          $v0, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r2;
    goto L_8007F1FC;
    // sb          $v0, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r2;
L_8007F1BC:
    // j           L_8007F1FC
    // sb          $v0, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r2;
    goto L_8007F1FC;
    // sb          $v0, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r2;
L_8007F1C4:
    // lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(0X18, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8007F1E4
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007F1E4;
    }
    // nop

    // jalr        $v0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
    goto after_3;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_3:
    // j           L_8007F1EC
    // nop

    goto L_8007F1EC;
    // nop

L_8007F1E4:
    // jal         0x8007D994
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8007D994(rdram, ctx);
    goto after_4;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
L_8007F1EC:
    // lbu         $v1, 0x46($s0)
    ctx->r3 = MEM_BU(0X46, ctx->r16);
    // nop

    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sb          $v1, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r3;
L_8007F1FC:
    // lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(0X18, ctx->r29);
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
