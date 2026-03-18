#include "recomp.h"
#include "disable_warnings.h"

void sub_8003BEB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addiu       $s3, $v0, -0x70D8
    ctx->r19 = ADD32(ctx->r2, -0X70D8);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lw          $v1, 0x248($s3)
    ctx->r3 = MEM_W(0X248, ctx->r19);
    // lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(0X4, ctx->r18);
    // nop

    // subu        $s1, $v1, $v0
    ctx->r17 = SUB32(ctx->r3, ctx->r2);
    // addiu       $v0, $s1, 0x2800
    ctx->r2 = ADD32(ctx->r17, 0X2800);
    // sltiu       $v0, $v0, 0x5001
    ctx->r2 = ctx->r2 < 0X5001 ? 1 : 0;
    // beq         $v0, $zero, L_8003BFE0
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8003BFE0;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lw          $v1, 0x250($s3)
    ctx->r3 = MEM_W(0X250, ctx->r19);
    // lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(0XC, ctx->r18);
    // nop

    // subu        $s0, $v1, $v0
    ctx->r16 = SUB32(ctx->r3, ctx->r2);
    // addiu       $v0, $s0, 0x2800
    ctx->r2 = ADD32(ctx->r16, 0X2800);
    // sltiu       $v0, $v0, 0x5001
    ctx->r2 = ctx->r2 < 0X5001 ? 1 : 0;
    // beq         $v0, $zero, L_8003BFDC
    if (ctx->r2 == 0) {
        // mult        $s1, $s1
        result = S64(S32(ctx->r17)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
        goto L_8003BFDC;
    }
    // mult        $s1, $s1
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v0
    ctx->r2 = lo;
    // nop

    // nop

    // mult        $s0, $s0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // jal         0x800746C4
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    SquareRoot0(rdram, ctx);
    goto after_0;
    // addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // jal         0x80076EA4
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    ratan2(rdram, ctx);
    goto after_1;
    // addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_1:
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // lh          $a0, 0x20($s2)
    ctx->r4 = MEM_HS(0X20, ctx->r18);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // jal         0x800744C4
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    rcos(rdram, ctx);
    goto after_2;
    // subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    after_2:
    // lh          $v1, 0x22($s2)
    ctx->r3 = MEM_HS(0X22, ctx->r18);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $v1
    ctx->r3 = lo;
    // bgez        $v1, L_8003BF74
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_8003BF74;
    }
    // nop

    // addiu       $v1, $v1, 0xFFF
    ctx->r3 = ADD32(ctx->r3, 0XFFF);
L_8003BF74:
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // lhu         $v0, 0x1C($s2)
    ctx->r2 = MEM_HU(0X1C, ctx->r18);
    // subu        $v1, $s0, $v1
    ctx->r3 = SUB32(ctx->r16, ctx->r3);
    // addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v1, $zero, L_8003BFE0
    if (ctx->r3 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8003BFE0;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lw          $a1, 0x24C($s3)
    ctx->r5 = MEM_W(0X24C, ctx->r19);
    // lw          $v1, 0x8($s2)
    ctx->r3 = MEM_W(0X8, ctx->r18);
    // addiu       $a0, $a1, 0x640
    ctx->r4 = ADD32(ctx->r5, 0X640);
    // slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // beq         $v0, $zero, L_8003BFC8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8003BFC8;
    }
    // nop

    // lhu         $v0, 0x1E($s2)
    ctx->r2 = MEM_HU(0X1E, ctx->r18);
    // nop

    // subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8003BFD4
    if (ctx->r2 == 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8003BFD4;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // j           L_8003BFE0
    // nop

    goto L_8003BFE0;
    // nop

L_8003BFC8:
    // slt         $v1, $v1, $a1
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v1, $zero, L_8003BFE0
    if (ctx->r3 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8003BFE0;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8003BFD4:
    // j           L_8003BFE0
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    goto L_8003BFE0;
    // addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8003BFDC:
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8003BFE0:
    // lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // jr          $ra
    // nop

    return;
    // nop

;}
