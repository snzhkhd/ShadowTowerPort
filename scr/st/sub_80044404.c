#include "recomp.h"
#include "disable_warnings.h"

void sub_80044404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // addiu       $a1, $zero, 0x1E1
    ctx->r5 = ADD32(0, 0X1E1);
    // lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // addiu       $a2, $a2, 0x43F4
    ctx->r6 = ADD32(ctx->r6, 0X43F4);
    // sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // jal         0x80045F90
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    sub_80045F90(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    after_0:
    // lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sh          $v0, 0x5920($s0)
    MEM_H(0X5920, ctx->r16) = ctx->r2;
    // addiu       $s0, $s0, 0x5920
    ctx->r16 = ADD32(ctx->r16, 0X5920);
    // lbu         $v1, 0x4($s0)
    ctx->r3 = MEM_BU(0X4, ctx->r16);
    // addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // sb          $v0, 0x13($s0)
    MEM_B(0X13, ctx->r16) = ctx->r2;
    // sb          $v0, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r2;
    // jal         0x800456F8
    // sb          $v1, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r3;
    sub_800456F8(rdram, ctx);
    goto after_1;
    // sb          $v1, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r3;
    after_1:
    // jal         0x80015AD4
    // nop

    sub_80015AD4(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // lbu         $v1, 0x9($s0)
    ctx->r3 = MEM_BU(0X9, ctx->r16);
    // addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // bne         $v1, $v0, L_800445EC
    if (ctx->r3 != ctx->r2) {
        // addiu       $v0, $zero, 0x1B
        ctx->r2 = ADD32(0, 0X1B);
        goto L_800445EC;
    }
    // addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lw          $v0, -0x31B8($v0)
    ctx->r2 = MEM_W(-0X31B8, ctx->r2);
    // nop

    // srl         $v0, $v0, 17
    ctx->r2 = S32(U32(ctx->r2) >> 17);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_80044660
    if (ctx->r2 == 0) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_80044660;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x5ED8($v0)
    ctx->r2 = MEM_W(-0X5ED8, ctx->r2);
    // addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $v1, L_80044660
    if (ctx->r2 != ctx->r3) {
        // lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
        goto L_80044660;
    }
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7F9C
    ctx->r6 = ADD32(ctx->r2, -0X7F9C);
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
    // addiu       $a2, $v0, -0x7F94
    ctx->r6 = ADD32(ctx->r2, -0X7F94);
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
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7F8C
    ctx->r6 = ADD32(ctx->r2, -0X7F8C);
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
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7F84
    ctx->r6 = ADD32(ctx->r2, -0X7F84);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x2B($sp)
    do_swl(rdram, 0X2B, ctx->r29, ctx->r3);
    // swr         $v1, 0x28($sp)
    do_swr(rdram, 0X28, ctx->r29, ctx->r3);
    // swl         $a0, 0x2F($sp)
    do_swl(rdram, 0X2F, ctx->r29, ctx->r4);
    // swr         $a0, 0x2C($sp)
    do_swr(rdram, 0X2C, ctx->r29, ctx->r4);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7F7C
    ctx->r6 = ADD32(ctx->r2, -0X7F7C);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x33($sp)
    do_swl(rdram, 0X33, ctx->r29, ctx->r3);
    // swr         $v1, 0x30($sp)
    do_swr(rdram, 0X30, ctx->r29, ctx->r3);
    // swl         $a0, 0x37($sp)
    do_swl(rdram, 0X37, ctx->r29, ctx->r4);
    // swr         $a0, 0x34($sp)
    do_swr(rdram, 0X34, ctx->r29, ctx->r4);
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7F74
    ctx->r6 = ADD32(ctx->r2, -0X7F74);
    // lwl         $v1, 0x3($a2)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X3, ctx->r6);
    // lwr         $v1, 0x0($a2)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X0, ctx->r6);
    // lwl         $a0, 0x7($a2)
    ctx->r4 = do_lwl(rdram, ctx->r4, 0X7, ctx->r6);
    // lwr         $a0, 0x4($a2)
    ctx->r4 = do_lwr(rdram, ctx->r4, 0X4, ctx->r6);
    // swl         $v1, 0x3B($sp)
    do_swl(rdram, 0X3B, ctx->r29, ctx->r3);
    // swr         $v1, 0x38($sp)
    do_swr(rdram, 0X38, ctx->r29, ctx->r3);
    // swl         $a0, 0x3F($sp)
    do_swl(rdram, 0X3F, ctx->r29, ctx->r4);
    // swr         $a0, 0x3C($sp)
    do_swr(rdram, 0X3C, ctx->r29, ctx->r4);
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    // jal         0x80079DCC
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    MoveImage(rdram, ctx);
    goto after_3;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    // jal         0x80079DCC
    // addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    MoveImage(rdram, ctx);
    goto after_4;
    // addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_4:
    // addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // addiu       $a1, $zero, 0x300
    ctx->r5 = ADD32(0, 0X300);
    // jal         0x80079DCC
    // addiu       $a2, $zero, 0xE0
    ctx->r6 = ADD32(0, 0XE0);
    MoveImage(rdram, ctx);
    goto after_5;
    // addiu       $a2, $zero, 0xE0
    ctx->r6 = ADD32(0, 0XE0);
    after_5:
    // addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // jal         0x80079DCC
    // addiu       $a2, $zero, 0x1E3
    ctx->r6 = ADD32(0, 0X1E3);
    MoveImage(rdram, ctx);
    goto after_6;
    // addiu       $a2, $zero, 0x1E3
    ctx->r6 = ADD32(0, 0X1E3);
    after_6:
    // addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // jal         0x80079DCC
    // addiu       $a2, $zero, 0x1E4
    ctx->r6 = ADD32(0, 0X1E4);
    MoveImage(rdram, ctx);
    goto after_7;
    // addiu       $a2, $zero, 0x1E4
    ctx->r6 = ADD32(0, 0X1E4);
    after_7:
    // addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // j           L_80044658
    // addiu       $a2, $zero, 0x1EA
    ctx->r6 = ADD32(0, 0X1EA);
    goto L_80044658;
    // addiu       $a2, $zero, 0x1EA
    ctx->r6 = ADD32(0, 0X1EA);
L_800445EC:
    // bne         $v1, $v0, L_80044660
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
        goto L_80044660;
    }
    // lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // lw          $v0, -0x31B8($v0)
    ctx->r2 = MEM_W(-0X31B8, ctx->r2);
    // nop

    // srl         $v0, $v0, 13
    ctx->r2 = S32(U32(ctx->r2) >> 13);
    // andi        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 & 0X1;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // bne         $v1, $v0, L_80044660
    if (ctx->r3 != ctx->r2) {
        // lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
        goto L_80044660;
    }
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // lw          $v0, -0x5ED8($v0)
    ctx->r2 = MEM_W(-0X5ED8, ctx->r2);
    // nop

    // srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // bne         $v0, $v1, L_80044660
    if (ctx->r2 != ctx->r3) {
        // lui         $v0, 0x8009
        ctx->r2 = S32(0X8009 << 16);
        goto L_80044660;
    }
    // lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // addiu       $a2, $v0, -0x7F6C
    ctx->r6 = ADD32(ctx->r2, -0X7F6C);
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
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addiu       $a2, $zero, 0x1E9
    ctx->r6 = ADD32(0, 0X1E9);
L_80044658:
    // jal         0x80079DCC
    // nop

    MoveImage(rdram, ctx);
    goto after_8;
    // nop

    after_8:
L_80044660:
    // lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(0X44, ctx->r29);
    // lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(0X40, ctx->r29);
    // addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // jr          $ra
    // nop

    return;
    // nop

;}
