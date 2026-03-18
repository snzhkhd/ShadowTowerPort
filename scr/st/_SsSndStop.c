#include "recomp.h"
#include "disable_warnings.h"

void _SsSndStop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4) << 16;
    // lui         $v0, 0x801F
    ctx->r2 = S32(0X801F << 16);
    // addiu       $v0, $v0, -0x79A0
    ctx->r2 = ADD32(ctx->r2, -0X79A0);
    // sra         $t0, $t0, 14
    ctx->r8 = S32(ctx->r8) >> 14;
    // addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2) << 1;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3) << 2;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(0X0, ctx->r8);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // lw          $v0, 0x98($s0)
    ctx->r2 = MEM_W(0X98, ctx->r16);
    // addiu       $a2, $zero, -0x2
    ctx->r6 = ADD32(0, -0X2);
    // and         $v0, $v0, $a2
    ctx->r2 = ctx->r2 & ctx->r6;
    // sw          $v0, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r2;
    // lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(0X0, ctx->r8);
    // nop

    // addu        $a2, $v1, $a2
    ctx->r6 = ADD32(ctx->r3, ctx->r6);
    // lw          $v0, 0x98($a2)
    ctx->r2 = MEM_W(0X98, ctx->r6);
    // addiu       $a3, $zero, -0x3
    ctx->r7 = ADD32(0, -0X3);
    // and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // sw          $v0, 0x98($a2)
    MEM_W(0X98, ctx->r6) = ctx->r2;
    // lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(0X0, ctx->r8);
    // sll         $a1, $a1, 8
    ctx->r5 = S32(ctx->r5) << 8;
    // addu        $a2, $v1, $a2
    ctx->r6 = ADD32(ctx->r3, ctx->r6);
    // lw          $v0, 0x98($a2)
    ctx->r2 = MEM_W(0X98, ctx->r6);
    // addiu       $a3, $zero, -0x9
    ctx->r7 = ADD32(0, -0X9);
    // and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // sw          $v0, 0x98($a2)
    MEM_W(0X98, ctx->r6) = ctx->r2;
    // lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(0X0, ctx->r8);
    // or          $a0, $a0, $a1
    ctx->r4 = ctx->r4 | ctx->r5;
    // addu        $a2, $v1, $a2
    ctx->r6 = ADD32(ctx->r3, ctx->r6);
    // lw          $v0, 0x98($a2)
    ctx->r2 = MEM_W(0X98, ctx->r6);
    // addiu       $a3, $zero, -0x401
    ctx->r7 = ADD32(0, -0X401);
    // and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // sw          $v0, 0x98($a2)
    MEM_W(0X98, ctx->r6) = ctx->r2;
    // lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(0X0, ctx->r8);
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(0X98, ctx->r3);
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // jal         0x800733EC
    // sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
    sub_800733EC(rdram, ctx);
    goto after_0;
    // sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
    after_0:
    // jal         0x80070884
    // nop

    _SsVmDamperOff(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
    // lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(0X84, ctx->r16);
    // lw          $v1, 0x8C($s0)
    ctx->r3 = MEM_W(0X8C, ctx->r16);
    // lhu         $a0, 0x56($s0)
    ctx->r4 = MEM_HU(0X56, ctx->r16);
    // lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(0X4, ctx->r16);
    // lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(0X4, ctx->r16);
    // addu        $t0, $s0, $zero
    ctx->r8 = ADD32(ctx->r16, 0);
    // sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    // sw          $zero, 0x88($s0)
    MEM_W(0X88, ctx->r16) = 0;
    // sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
    // sb          $zero, 0x18($s0)
    MEM_B(0X18, ctx->r16) = 0;
    // sb          $zero, 0x19($s0)
    MEM_B(0X19, ctx->r16) = 0;
    // sb          $zero, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = 0;
    // sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // sb          $zero, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = 0;
    // sb          $zero, 0x17($s0)
    MEM_B(0X17, ctx->r16) = 0;
    // sb          $zero, 0x21($s0)
    MEM_B(0X21, ctx->r16) = 0;
    // sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
    // sb          $zero, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = 0;
    // sb          $zero, 0x15($s0)
    MEM_B(0X15, ctx->r16) = 0;
    // sb          $zero, 0x16($s0)
    MEM_B(0X16, ctx->r16) = 0;
    // sw          $v0, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r2;
    // sw          $v1, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r3;
    // sh          $a0, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r4;
    // sw          $a1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r5;
    // sw          $a2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r6;
L_8006E7D8:
    // addu        $v0, $s0, $a3
    ctx->r2 = ADD32(ctx->r16, ctx->r7);
    // sb          $a3, 0x37($v0)
    MEM_B(0X37, ctx->r2) = ctx->r7;
    // sb          $t2, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r10;
    // sh          $t1, 0x60($t0)
    MEM_H(0X60, ctx->r8) = ctx->r9;
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // slti        $v0, $a3, 0x10
    ctx->r2 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_8006E7D8
    if (ctx->r2 != 0) {
        // addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
        goto L_8006E7D8;
    }
    // addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // sh          $v0, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r2;
    // sh          $v0, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r2;
    // lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
