#include "recomp.h"
#include "disable_warnings.h"

void sub_8001C100(uint8_t* rdram, recomp_context* ctx) 
{
    // printf("[VISIBILITY] word_801B9E12=%d word_801B9E14=%d pos=%08X/%08X/%08X\n",
        // (int16_t)MEM_H(0, 0x801B9E12),
        // (int16_t)MEM_H(0, 0x801B9E14),
        // MEM_W(0, 0x80199170),   // viewDistance / player pos X
        // MEM_W(0, 0x80199174),   // Y
        // MEM_W(0, 0x80199178));  // Z


    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // addiu       $s0, $v0, 0x5948
    ctx->r16 = ADD32(ctx->r2, 0X5948);
    // sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // jal         0x80046270
    // sh          $zero, 0x44CA($s0)
    MEM_H(0X44CA, ctx->r16) = 0;
    sub_80046270(rdram, ctx);
    goto after_0;
    // sh          $zero, 0x44CA($s0)
    MEM_H(0X44CA, ctx->r16) = 0;
    after_0:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // jal         0x80014D5C
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    sub_80014D5C(rdram, ctx);
    goto after_1;
    // addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_1:
    // lhu         $a3, 0x44CA($s0)
    ctx->r7 = MEM_HU(0X44CA, ctx->r16);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // beq         $a3, $v0, L_8001C1A0
    if (ctx->r7 == ctx->r2) {
        // lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
        goto L_8001C1A0;
    }
    // lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // addiu       $t2, $v0, -0x2930
    ctx->r10 = ADD32(ctx->r2, -0X2930);
    // addiu       $t1, $sp, 0x10
    ctx->r9 = ADD32(ctx->r29, 0X10);
    // sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7) << 1;
    // addu        $t0, $v0, $s0
    ctx->r8 = ADD32(ctx->r2, ctx->r16);
L_8001C158:
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // lhu         $v0, 0x44CE($t0)
    ctx->r2 = MEM_HU(0X44CE, ctx->r8);
    // addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
    // sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2) << 6;
    // addu        $a1, $v0, $t2
    ctx->r5 = ADD32(ctx->r2, ctx->r10);
L_8001C16C:
    // lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(0X0, ctx->r5);
    // addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(0X0, ctx->r4);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // slti        $v0, $a2, 0x10
    ctx->r2 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_8001C16C
    if (ctx->r2 != 0) {
        // addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_8001C16C;
    }
    // addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // bne         $a3, $v0, L_8001C158
    if (ctx->r7 != ctx->r2) {
        // addiu       $t0, $t0, -0x2
        ctx->r8 = ADD32(ctx->r8, -0X2);
        goto L_8001C158;
    }
    // addiu       $t0, $t0, -0x2
    ctx->r8 = ADD32(ctx->r8, -0X2);
L_8001C1A0:
    // lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // sh          $zero, -0x61EC($v0)
    MEM_H(-0X61EC, ctx->r2) = 0;
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // addiu       $t2, $t0, 0x5920
    ctx->r10 = ADD32(ctx->r8, 0X5920);
    // addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // addiu       $v1, $sp, 0x10
    ctx->r3 = ADD32(ctx->r29, 0X10);
L_8001C1C0:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // addiu       $a1, $v0, 0x5948
    ctx->r5 = ADD32(ctx->r2, 0X5948);
L_8001C1CC:
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // nop

    // andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // beq         $v0, $zero, L_8001C224
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8001C224;
    }
    // nop

    // lh          $v0, 0x5920($t0)
    ctx->r2 = MEM_HS(0X5920, ctx->r8);
    // nop

    // bne         $v0, $t1, L_8001C200
    if (ctx->r2 != ctx->r9) {
        // nop
    
        goto L_8001C200;
    }
    // nop

    // lbu         $v0, 0x1D($t2)
    ctx->r2 = MEM_BU(0X1D, ctx->r10);
    // nop

    // bne         $v0, $zero, L_8001C224
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8001C224;
    }
    // nop

L_8001C200:
    // lhu         $v0, 0x44CC($a1)
    ctx->r2 = MEM_HU(0X44CC, ctx->r5);
    // nop

    // sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) << 1;
    // addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // sh          $a3, 0x45CE($v0)
    MEM_H(0X45CE, ctx->r2) = ctx->r7;
    // lhu         $v0, 0x44CC($a1)
    ctx->r2 = MEM_HU(0X44CC, ctx->r5);
    // nop

    // addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // sh          $v0, 0x44CC($a1)
    MEM_H(0X44CC, ctx->r5) = ctx->r2;
L_8001C224:
    // lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(0X0, ctx->r3);
    // addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // slti        $v0, $a0, 0x20
    ctx->r2 = SIGNED(ctx->r4) < 0X20 ? 1 : 0;
    // bne         $v0, $zero, L_8001C1CC
    if (ctx->r2 != 0) {
        // addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
        goto L_8001C1CC;
    }
    // addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // slti        $v0, $a2, 0x10
    ctx->r2 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // bne         $v0, $zero, L_8001C1C0
    if (ctx->r2 != 0) {
        // addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
        goto L_8001C1C0;
    }
    // addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(0X64, ctx->r29);
    // lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(0X60, ctx->r29);
    // addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // jr          $ra
    // nop

    return;
    // nop

;}
