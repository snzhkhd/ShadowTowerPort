#include "recomp.h"
#include "disable_warnings.h"

void sub_8004D804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t5, $a0, $zero
    ctx->r13 = ADD32(ctx->r4, 0);
    // addu        $t4, $a1, $zero
    ctx->r12 = ADD32(ctx->r5, 0);
    // sll         $v0, $t4, 1
    ctx->r2 = S32(ctx->r12) << 1;
    // addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $t4
    ctx->r2 = SUB32(ctx->r2, ctx->r12);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // addiu       $a0, $v1, 0x7810
    ctx->r4 = ADD32(ctx->r3, 0X7810);
    // addu        $t6, $v0, $a0
    ctx->r14 = ADD32(ctx->r2, ctx->r4);
    // lbu         $v1, 0x26($t6)
    ctx->r3 = MEM_BU(0X26, ctx->r14);
    // addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // bne         $v1, $v0, L_8004D8C4
    if (ctx->r3 != ctx->r2) {
        // addiu       $a1, $a0, -0x118
        ctx->r5 = ADD32(ctx->r4, -0X118);
        goto L_8004D8C4;
    }
    // addiu       $a1, $a0, -0x118
    ctx->r5 = ADD32(ctx->r4, -0X118);
    // lbu         $v1, 0x3($a1)
    ctx->r3 = MEM_BU(0X3, ctx->r5);
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // bne         $v1, $v0, L_8004D8A0
    if (ctx->r3 != ctx->r2) {
        // addiu       $t0, $a0, 0x3EF8
        ctx->r8 = ADD32(ctx->r4, 0X3EF8);
        goto L_8004D8A0;
    }
    // addiu       $t0, $a0, 0x3EF8
    ctx->r8 = ADD32(ctx->r4, 0X3EF8);
    // addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_8004D854:
    // addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    // addiu       $a2, $t0, 0x30
    ctx->r6 = ADD32(ctx->r8, 0X30);
    // addiu       $t1, $t0, 0x60
    ctx->r9 = ADD32(ctx->r8, 0X60);
L_8004D860:
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
    // bne         $a2, $t1, L_8004D860
    if (ctx->r6 != ctx->r9) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8004D860;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // bne         $t2, $t3, L_8004D854
    if (ctx->r10 != ctx->r11) {
        // addiu       $t0, $t0, 0x30
        ctx->r8 = ADD32(ctx->r8, 0X30);
        goto L_8004D854;
    }
    // addiu       $t0, $t0, 0x30
    ctx->r8 = ADD32(ctx->r8, 0X30);
    // j           L_8004D94C
    // sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
    goto L_8004D94C;
    // sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
L_8004D8A0:
    // lbu         $v0, 0x3($a1)
    ctx->r2 = MEM_BU(0X3, ctx->r5);
    // addiu       $a0, $a0, 0x3EF8
    ctx->r4 = ADD32(ctx->r4, 0X3EF8);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $t0, $v1, $a0
    ctx->r8 = ADD32(ctx->r3, ctx->r4);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // j           L_8004D948
    // sb          $v0, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r2;
    goto L_8004D948;
    // sb          $v0, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r2;
L_8004D8C4:
    // lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(0X2, ctx->r5);
    // addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // bne         $v1, $v0, L_8004D928
    if (ctx->r3 != ctx->r2) {
        // addiu       $t0, $a0, 0x3BF8
        ctx->r8 = ADD32(ctx->r4, 0X3BF8);
        goto L_8004D928;
    }
    // addiu       $t0, $a0, 0x3BF8
    ctx->r8 = ADD32(ctx->r4, 0X3BF8);
    // addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_8004D8DC:
    // addu        $a3, $t0, $zero
    ctx->r7 = ADD32(ctx->r8, 0);
    // addiu       $a2, $t0, 0x30
    ctx->r6 = ADD32(ctx->r8, 0X30);
    // addiu       $t1, $t0, 0x60
    ctx->r9 = ADD32(ctx->r8, 0X60);
L_8004D8E8:
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
    // bne         $a2, $t1, L_8004D8E8
    if (ctx->r6 != ctx->r9) {
        // addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
        goto L_8004D8E8;
    }
    // addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // bne         $t2, $t3, L_8004D8DC
    if (ctx->r10 != ctx->r11) {
        // addiu       $t0, $t0, 0x30
        ctx->r8 = ADD32(ctx->r8, 0X30);
        goto L_8004D8DC;
    }
    // addiu       $t0, $t0, 0x30
    ctx->r8 = ADD32(ctx->r8, 0X30);
    // j           L_8004D94C
    // sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
    goto L_8004D94C;
    // sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
L_8004D928:
    // lbu         $v0, 0x2($a1)
    ctx->r2 = MEM_BU(0X2, ctx->r5);
    // addiu       $a0, $a0, 0x3BF8
    ctx->r4 = ADD32(ctx->r4, 0X3BF8);
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $t0, $v1, $a0
    ctx->r8 = ADD32(ctx->r3, ctx->r4);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
L_8004D948:
    // sh          $t4, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r12;
L_8004D94C:
    // lhu         $v0, 0x26($t5)
    ctx->r2 = MEM_HU(0X26, ctx->r13);
    // sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // sh          $v0, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r2;
    // lw          $v0, 0x74($t5)
    ctx->r2 = MEM_W(0X74, ctx->r13);
    // lw          $v1, 0x78($t5)
    ctx->r3 = MEM_W(0X78, ctx->r13);
    // lw          $a0, 0x7C($t5)
    ctx->r4 = MEM_W(0X7C, ctx->r13);
    // lw          $a1, 0x80($t5)
    ctx->r5 = MEM_W(0X80, ctx->r13);
    // sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // sw          $v1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r3;
    // sw          $a0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r4;
    // sw          $a1, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r5;
    // lhu         $v0, 0x30($t5)
    ctx->r2 = MEM_HU(0X30, ctx->r13);
    // lw          $v1, 0xC($t0)
    ctx->r3 = MEM_W(0XC, ctx->r8);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sw          $v1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r3;
    // lwl         $v0, 0x8F($t5)
    ctx->r2 = do_lwl(rdram, ctx->r2, 0X8F, ctx->r13);
    // lwr         $v0, 0x8C($t5)
    ctx->r2 = do_lwr(rdram, ctx->r2, 0X8C, ctx->r13);
    // lwl         $v1, 0x93($t5)
    ctx->r3 = do_lwl(rdram, ctx->r3, 0X93, ctx->r13);
    // lwr         $v1, 0x90($t5)
    ctx->r3 = do_lwr(rdram, ctx->r3, 0X90, ctx->r13);
    // swl         $v0, 0x1B($t0)
    do_swl(rdram, 0X1B, ctx->r8, ctx->r2);
    // swr         $v0, 0x18($t0)
    do_swr(rdram, 0X18, ctx->r8, ctx->r2);
    // swl         $v1, 0x1F($t0)
    do_swl(rdram, 0X1F, ctx->r8, ctx->r3);
    // swr         $v1, 0x1C($t0)
    do_swr(rdram, 0X1C, ctx->r8, ctx->r3);
    // lhu         $v1, 0x1E($t6)
    ctx->r3 = MEM_HU(0X1E, ctx->r14);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sb          $v0, 0x22($t0)
    MEM_B(0X22, ctx->r8) = ctx->r2;
    // sb          $v0, 0x23($t0)
    MEM_B(0X23, ctx->r8) = ctx->r2;
    // sb          $zero, 0x24($t0)
    MEM_B(0X24, ctx->r8) = 0;
    // sh          $v1, 0x20($t0)
    MEM_H(0X20, ctx->r8) = ctx->r3;
    // lw          $v0, 0x40($t5)
    ctx->r2 = MEM_W(0X40, ctx->r13);
    // sh          $zero, 0x26($t0)
    MEM_H(0X26, ctx->r8) = 0;
    // sb          $zero, 0x25($t0)
    MEM_B(0X25, ctx->r8) = 0;
    // sw          $v0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r2;
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // lbu         $v0, 0x5929($v0)
    ctx->r2 = MEM_BU(0X5929, ctx->r2);
    // lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // sb          $v0, 0x2C($t0)
    MEM_B(0X2C, ctx->r8) = ctx->r2;
    // lbu         $v0, 0x76F8($v1)
    ctx->r2 = MEM_BU(0X76F8, ctx->r3);
    // addu        $a0, $t4, $zero
    ctx->r4 = ADD32(ctx->r12, 0);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sb          $v0, 0x76F8($v1)
    MEM_B(0X76F8, ctx->r3) = ctx->r2;
    // bgez        $t4, L_8004DA00
    if (SIGNED(ctx->r12) >= 0) {
        // addiu       $v1, $v1, 0x76F8
        ctx->r3 = ADD32(ctx->r3, 0X76F8);
        goto L_8004DA00;
    }
    // addiu       $v1, $v1, 0x76F8
    ctx->r3 = ADD32(ctx->r3, 0X76F8);
    // addiu       $a0, $t4, 0x1F
    ctx->r4 = ADD32(ctx->r12, 0X1F);
L_8004DA00:
    // sra         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4) >> 5;
    // sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4) << 2;
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4) << 5;
    // subu        $a0, $t4, $a0
    ctx->r4 = SUB32(ctx->r12, ctx->r4);
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // lw          $v1, 0x48($a1)
    ctx->r3 = MEM_W(0X48, ctx->r5);
    // sllv        $v0, $v0, $a0
    ctx->r2 = S32(ctx->r2) << (ctx->r4 & 31);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // jr          $ra
    // sw          $v1, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r3;
    return;
    // sw          $v1, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r3;
;}
