#include "recomp.h"
#include "disable_warnings.h"

void sub_800706A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // addiu       $a1, $a1, -0x68EC
    ctx->r5 = ADD32(ctx->r5, -0X68EC);
    // addiu       $t2, $a1, -0x2
    ctx->r10 = ADD32(ctx->r5, -0X2);
    // addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // lui         $a3, 0x801F
    ctx->r7 = S32(0X801F << 16);
    // addiu       $a3, $a3, -0x6A48
    ctx->r7 = ADD32(ctx->r7, -0X6A48);
    // lbu         $v1, -0x10($a1)
    ctx->r3 = MEM_BU(-0X10, ctx->r5);
    // lh          $a2, -0x2($a1)
    ctx->r6 = MEM_HS(-0X2, ctx->r5);
    // lb          $a0, -0x15($a1)
    ctx->r4 = MEM_BS(-0X15, ctx->r5);
    // sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3) << 24;
    // sra         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3) >> 24;
    // sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6) << 3;
    // sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4) << 4;
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // sh          $v1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r3;
    // addiu       $v1, $zero, 0x7FFF
    ctx->r3 = ADD32(0, 0X7FFF);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // sh          $v1, -0x70FA($at)
    MEM_H(-0X70FA, ctx->r1) = ctx->r3;
L_80070708:
    // addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // lh          $v0, 0x0($t2)
    ctx->r2 = MEM_HS(0X0, ctx->r10);
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // sllv        $v0, $t1, $v0
    ctx->r2 = S32(ctx->r9) << (ctx->r2 & 31);
    // nor         $v0, $zero, $v0
    ctx->r2 = ~(0 | ctx->r2);
    // and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // slti        $v0, $t0, 0x10
    ctx->r2 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_80070708
    if (ctx->r2 != 0) {
        // addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
        goto L_80070708;
    }
    // addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addiu       $a0, $a0, -0x68F0
    ctx->r4 = ADD32(ctx->r4, -0X68F0);
    // lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(0X0, ctx->r4);
    // nop

    // andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // blez        $v0, L_80070780
    if (SIGNED(ctx->r2) <= 0) {
        // sll         $v0, $v1, 16
        ctx->r2 = S32(ctx->r3) << 16;
        goto L_80070780;
    }
    // sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lw          $v1, -0x691C($v1)
    ctx->r3 = MEM_W(-0X691C, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x4($a0)
    ctx->r3 = MEM_HS(0X4, ctx->r4);
    // lhu         $v0, 0xC($v0)
    ctx->r2 = MEM_HU(0XC, ctx->r2);
    // j           L_800707B0
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    goto L_800707B0;
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
L_80070780:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // lw          $v1, -0x691C($v1)
    ctx->r3 = MEM_W(-0X691C, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lh          $v1, 0x4($a0)
    ctx->r3 = MEM_HS(0X4, ctx->r4);
    // lhu         $v0, 0xE($v0)
    ctx->r2 = MEM_HU(0XE, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
L_800707B0:
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $v0, -0x6BCA($at)
    MEM_H(-0X6BCA, ctx->r1) = ctx->r2;
    // lh          $v1, 0x2($a0)
    ctx->r3 = MEM_HS(0X2, ctx->r4);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, -0x6BF0($v0)
    ctx->r2 = MEM_BU(-0X6BF0, ctx->r2);
    // nop

    // ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sb          $v0, -0x6BF0($at)
    MEM_B(-0X6BF0, ctx->r1) = ctx->r2;
    // lui         $a0, 0x801F
    ctx->r4 = S32(0X801F << 16);
    // addiu       $a0, $a0, -0x68EC
    ctx->r4 = ADD32(ctx->r4, -0X68EC);
    // lb          $v0, -0x15($a0)
    ctx->r2 = MEM_BS(-0X15, ctx->r4);
    // lb          $v1, -0x10($a0)
    ctx->r3 = MEM_BS(-0X10, ctx->r4);
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // lw          $a1, -0x6910($a1)
    ctx->r5 = MEM_W(-0X6910, ctx->r5);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lh          $v1, 0x0($a0)
    ctx->r3 = MEM_HS(0X0, ctx->r4);
    // lhu         $v0, 0x10($v0)
    ctx->r2 = MEM_HU(0X10, ctx->r2);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $v0, -0x6BC8($at)
    MEM_H(-0X6BC8, ctx->r1) = ctx->r2;
    // lb          $v0, -0x15($a0)
    ctx->r2 = MEM_BS(-0X15, ctx->r4);
    // lb          $v1, -0x10($a0)
    ctx->r3 = MEM_BS(-0X10, ctx->r4);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2) << 5;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lh          $v1, 0x0($a0)
    ctx->r3 = MEM_HS(0X0, ctx->r4);
    // lhu         $v0, 0x12($v0)
    ctx->r2 = MEM_HU(0X12, ctx->r2);
    // lui         $a1, 0x801F
    ctx->r5 = S32(0X801F << 16);
    // lhu         $a1, -0x6968($a1)
    ctx->r5 = MEM_HU(-0X6968, ctx->r5);
    // sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // sh          $v0, -0x6BC6($at)
    MEM_H(-0X6BC6, ctx->r1) = ctx->r2;
    // lh          $v1, -0x2($a0)
    ctx->r3 = MEM_HS(-0X2, ctx->r4);
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // lbu         $v0, -0x6BF0($v0)
    ctx->r2 = MEM_BU(-0X6BF0, ctx->r2);
    // nop

    // ori         $v0, $v0, 0x30
    ctx->r2 = ctx->r2 | 0X30;
    // lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // jr          $ra
    // sb          $v0, -0x6BF0($at)
    MEM_B(-0X6BF0, ctx->r1) = ctx->r2;
    return;
    // sb          $v0, -0x6BF0($at)
    MEM_B(-0X6BF0, ctx->r1) = ctx->r2;
;}
