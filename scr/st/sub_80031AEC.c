#include "recomp.h"
#include "disable_warnings.h"

void sub_80031AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // addiu       $a2, $v0, -0x8000
    ctx->r6 = ADD32(ctx->r2, -0X8000);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x13($sp)
    do_swl(rdram, 0X13, ctx->r29, ctx->r3);
    // swr         $v1, 0x10($sp)
    do_swr(rdram, 0X10, ctx->r29, ctx->r3);
    // swl         $a0, 0x17($sp)
    do_swl(rdram, 0X17, ctx->r29, ctx->r4);
    // swr         $a0, 0x14($sp)
    do_swr(rdram, 0X14, ctx->r29, ctx->r4);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7FF8
    ctx->r6 = ADD32(ctx->r2, -0X7FF8);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // nop

    // swl         $v1, 0x1B($sp)
    do_swl(rdram, 0X1B, ctx->r29, ctx->r3);
    // swr         $v1, 0x18($sp)
    do_swr(rdram, 0X18, ctx->r29, ctx->r3);
    // jal         0x800174C4
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    sub_800174C4(rdram, ctx);
    goto after_0;
    // lui         $s0, 0x1F80
    ctx->r16 = S32(0X1F80 << 16);
    after_0:
    // addiu       $v0, $zero, 0x60
    ctx->r2 = ADD32(0, 0X60);
    // sb          $v0, 0x310($s0)
    MEM_B(0X310, ctx->r16) = ctx->r2;
    // sb          $v0, 0x300($s0)
    MEM_B(0X300, ctx->r16) = ctx->r2;
    // sb          $v0, 0x311($s0)
    MEM_B(0X311, ctx->r16) = ctx->r2;
    // sb          $v0, 0x301($s0)
    MEM_B(0X301, ctx->r16) = ctx->r2;
    // sb          $v0, 0x312($s0)
    MEM_B(0X312, ctx->r16) = ctx->r2;
    // sb          $v0, 0x302($s0)
    MEM_B(0X302, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
    // sb          $v0, 0x303($s0)
    MEM_B(0X303, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x2E4($s0)
    ctx->r2 = MEM_BU(0X2E4, ctx->r16);
    // addiu       $v1, $zero, 0x31
    ctx->r3 = ADD32(0, 0X31);
    // sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // beq         $v0, $zero, L_80031B8C
    if (ctx->r2 == 0) {
        // sb          $v1, 0x313($s0)
        MEM_B(0X313, ctx->r16) = ctx->r3;
        goto L_80031B8C;
    }
    // sb          $v1, 0x313($s0)
    MEM_B(0X313, ctx->r16) = ctx->r3;
    // lbu         $v1, 0x2E4($s0)
    ctx->r3 = MEM_BU(0X2E4, ctx->r16);
    // addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // j           L_80031B98
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    goto L_80031B98;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
L_80031B8C:
    // lbu         $v0, 0x2E4($s0)
    ctx->r2 = MEM_BU(0X2E4, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
L_80031B98:
    // sh          $v0, 0x360($s0)
    MEM_H(0X360, ctx->r16) = ctx->r2;
    // lbu         $v0, 0x360($s0)
    ctx->r2 = MEM_BU(0X360, ctx->r16);
    // lbu         $v1, 0x360($s0)
    ctx->r3 = MEM_BU(0X360, ctx->r16);
    // sb          $zero, 0x32E($s0)
    MEM_B(0X32E, ctx->r16) = 0;
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // sb          $v0, 0x32C($s0)
    MEM_B(0X32C, ctx->r16) = ctx->r2;
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // beq         $v0, $zero, L_80031BD4
    if (ctx->r2 == 0) {
        // sb          $v1, 0x32D($s0)
        MEM_B(0X32D, ctx->r16) = ctx->r3;
        goto L_80031BD4;
    }
    // sb          $v1, 0x32D($s0)
    MEM_B(0X32D, ctx->r16) = ctx->r3;
    // jal         0x800319A8
    // nop

    sub_800319A8(rdram, ctx);
    goto after_1;
    // nop

    after_1:
L_80031BD4:
    // lhu         $v0, 0x2DC($s0)
    ctx->r2 = MEM_HU(0X2DC, ctx->r16);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $v1, -0x7E52($at)
    MEM_H(-0X7E52, ctx->r1) = ctx->r3;
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80031C08
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80031C08;
    }
    // nop

    // jal         0x80030BE4
    // nop

    sub_80030BE4(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // jal         0x80030FA0
    // nop

    sub_80030FA0(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // j           L_80031C64
    // nop

    goto L_80031C64;
    // nop

L_80031C08:
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // nop

    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bgez        $v1, L_80031C24
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80031C24;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x7
    ctx->r2 = ADD32(ctx->r3, 0X7);
L_80031C24:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_80031C54
    if (ctx->r2 == 0) {
        // nop
    
        goto L_80031C54;
    }
    // nop

    // jal         0x80030BE4
    // nop

    sub_80030BE4(rdram, ctx);
    goto after_4;
    // nop

    after_4:
    // j           L_80031C5C
    // nop

    goto L_80031C5C;
    // nop

L_80031C54:
    // jal         0x80030FA0
    // nop

    sub_80030FA0(rdram, ctx);
    goto after_5;
    // nop

    after_5:
L_80031C5C:
    // jal         0x80031674
    // nop

    sub_80031674(rdram, ctx);
    goto after_6;
    // nop

    after_6:
L_80031C64:
    // lhu         $v0, 0x2E0($s0)
    ctx->r2 = MEM_HU(0X2E0, ctx->r16);
    // lui         $at, 0x8009
    ctx->r1 = S32(0X8009 << 16);
    // sh          $zero, -0x7E52($at)
    MEM_H(-0X7E52, ctx->r1) = 0;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2) >> 16;
    // bgez        $v1, L_80031C84
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_80031C84;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x7
    ctx->r2 = ADD32(ctx->r3, 0X7);
L_80031C84:
    // sra         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) >> 3;
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // beq         $v0, $zero, L_80031CB0
    if (ctx->r2 == 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_80031CB0;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // j           L_80031CB8
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    goto L_80031CB8;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
L_80031CB0:
    // addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
L_80031CB8:
    // jal         0x8002916C
    // nop

    sub_8002916C(rdram, ctx);
    goto after_7;
    // nop

    after_7:
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
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
    // jal         0x80031378
    // nop

    sub_80031378(rdram, ctx);
    goto after_9;
    // nop

    after_9:
    // jal         0x8002C9E8
    // nop

    sub_8002C9E8(rdram, ctx);
    goto after_10;
    // nop

    after_10:
    // jal         0x80017680
    // nop

    sub_80017680(rdram, ctx);
    goto after_11;
    // nop

    after_11:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
    // lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(0X20, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
