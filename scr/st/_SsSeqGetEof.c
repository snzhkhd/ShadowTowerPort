#include "recomp.h"
#include "disable_warnings.h"

void _SsSeqGetEof(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addiu       $v1, $v1, -0x79A0
    ctx->r3 = ADD32(ctx->r3, -0X79A0);
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // addu        $a3, $v0, $v1
    ctx->r7 = ADD32(ctx->r2, ctx->r3);
    // sll         $v1, $a1, 16
    ctx->r3 = S32(ctx->r5) << 16;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3) << 1;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) << 2;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $a2, $v0, 4
    ctx->r6 = S32(ctx->r2) << 4;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // addu        $s0, $v1, $a2
    ctx->r16 = ADD32(ctx->r3, ctx->r6);
    // lbu         $v0, 0x21($s0)
    ctx->r2 = MEM_BU(0X21, ctx->r16);
    // lb          $v1, 0x20($s0)
    ctx->r3 = MEM_BS(0X20, ctx->r16);
    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // bne         $v1, $zero, L_8006DF3C
    if (ctx->r3 != 0) {
        // sb          $v0, 0x21($s0)
        MEM_B(0X21, ctx->r16) = ctx->r2;
        goto L_8006DF3C;
    }
    // sb          $v0, 0x21($s0)
    MEM_B(0X21, ctx->r16) = ctx->r2;
    // sw          $zero, 0x88($s0)
    MEM_W(0X88, ctx->r16) = 0;
    // sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
    // sw          $zero, 0x90($s0)
    MEM_W(0X90, ctx->r16) = 0;
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lw          $v0, 0x98($v0)
    ctx->r2 = MEM_W(0X98, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // beq         $v0, $zero, L_8006DF30
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006DF30;
    }
    // nop

    // lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(0XC, ctx->r16);
    // j           L_8006E0BC
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    goto L_8006E0BC;
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_8006DF30:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // j           L_8006E0BC
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    goto L_8006E0BC;
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_8006DF3C:
    // sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) << 24;
    // sra         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2) >> 24;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8006DFA0
    if (ctx->r2 == 0) {
        // addiu       $a0, $zero, -0x2
        ctx->r4 = ADD32(0, -0X2);
        goto L_8006DFA0;
    }
    // addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    // sw          $zero, 0x88($s0)
    MEM_W(0X88, ctx->r16) = 0;
    // sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
    // sw          $zero, 0x90($s0)
    MEM_W(0X90, ctx->r16) = 0;
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lw          $v0, 0x98($v0)
    ctx->r2 = MEM_W(0X98, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // beq         $v0, $zero, L_8006DF8C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006DF8C;
    }
    // nop

    // lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(0XC, ctx->r16);
    // lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(0XC, ctx->r16);
    // j           L_8006DF98
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    goto L_8006DF98;
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_8006DF8C:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(0X4, ctx->r16);
    // sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_8006DF98:
    // j           L_8006E0BC
    // sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
    goto L_8006E0BC;
    // sw          $v1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r3;
L_8006DFA0:
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // nop

    // addu        $v1, $a2, $v1
    ctx->r3 = ADD32(ctx->r6, ctx->r3);
    // lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(0X98, ctx->r3);
    // nop

    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // nop

    // addu        $v1, $a2, $v1
    ctx->r3 = ADD32(ctx->r6, ctx->r3);
    // lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(0X98, ctx->r3);
    // addiu       $a0, $zero, -0x9
    ctx->r4 = ADD32(0, -0X9);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // nop

    // addu        $v1, $a2, $v1
    ctx->r3 = ADD32(ctx->r6, ctx->r3);
    // lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(0X98, ctx->r3);
    // addiu       $a0, $zero, -0x3
    ctx->r4 = ADD32(0, -0X3);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // nop

    // addu        $v1, $a2, $v1
    ctx->r3 = ADD32(ctx->r6, ctx->r3);
    // lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(0X98, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
    // sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
    // lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(0X0, ctx->r7);
    // nop

    // addu        $v1, $a2, $v1
    ctx->r3 = ADD32(ctx->r6, ctx->r3);
    // lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(0X98, ctx->r3);
    // nop

    // ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
    // sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    // lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(0X0, ctx->r7);
    // nop

    // addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // lw          $v0, 0x98($v0)
    ctx->r2 = MEM_W(0X98, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x400
    ctx->r2 = ctx->r2 & 0X400;
    // beq         $v0, $zero, L_8006E05C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006E05C;
    }
    // nop

    // lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(0XC, ctx->r16);
    // j           L_8006E068
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    goto L_8006E068;
    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_8006E05C:
    // lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(0X4, ctx->r16);
    // nop

    // sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_8006E068:
    // lb          $v1, 0x22($s0)
    ctx->r3 = MEM_BS(0X22, ctx->r16);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $v1, $v0, L_8006E09C
    if (ctx->r3 == ctx->r2) {
        // nop
    
        goto L_8006E09C;
    }
    // nop

    // lb          $a0, 0x22($s0)
    ctx->r4 = MEM_BS(0X22, ctx->r16);
    // lb          $a1, 0x23($s0)
    ctx->r5 = MEM_BS(0X23, ctx->r16);
    // jal         0x8006E534
    // sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    _SsSndNextSep(rdram, ctx);
    goto after_0;
    // sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    after_0:
    // sll         $a0, $s1, 8
    ctx->r4 = S32(ctx->r17) << 8;
    // or          $a0, $s2, $a0
    ctx->r4 = ctx->r18 | ctx->r4;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x800733EC
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_800733EC(rdram, ctx);
    goto after_1;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_1:
L_8006E09C:
    // sll         $a0, $s1, 8
    ctx->r4 = S32(ctx->r17) << 8;
    // or          $a0, $s2, $a0
    ctx->r4 = ctx->r18 | ctx->r4;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // jal         0x800733EC
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    sub_800733EC(rdram, ctx);
    goto after_2;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_2:
    // lh          $v0, 0x54($s0)
    ctx->r2 = MEM_HS(0X54, ctx->r16);
    // nop

    // sw          $v0, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r2;
L_8006E0BC:
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
