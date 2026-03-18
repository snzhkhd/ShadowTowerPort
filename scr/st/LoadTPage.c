#include "recomp.h"
#include "disable_warnings.h"

void LoadTPage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(0X40, ctx->r29);
    // lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(0X44, ctx->r29);
    // lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(0X48, ctx->r29);
    // addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sh          $s1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r17;
    // sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // beq         $s0, $v0, L_800794D4
    if (ctx->r16 == ctx->r2) {
        // sh          $s3, 0x12($sp)
        MEM_H(0X12, ctx->r29) = ctx->r19;
        goto L_800794D4;
    }
    // sh          $s3, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r19;
    // slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // beq         $v0, $zero, L_800794A8
    if (ctx->r2 == 0) {
        // nop
    
        goto L_800794A8;
    }
    // nop

    // beq         $s0, $zero, L_800794BC
    if (ctx->r16 == 0) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_800794BC;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // j           L_800794F0
    // nop

    goto L_800794F0;
    // nop

L_800794A8:
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // beq         $s0, $v0, L_800794E8
    if (ctx->r16 == ctx->r2) {
        // addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
        goto L_800794E8;
    }
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // j           L_800794F0
    // nop

    goto L_800794F0;
    // nop

L_800794BC:
    // bgez        $v1, L_800794C8
    if (SIGNED(ctx->r3) >= 0) {
        // addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
        goto L_800794C8;
    }
    // addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
L_800794C8:
    // sra         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2) >> 2;
    // j           L_800794EC
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    goto L_800794EC;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
L_800794D4:
    // srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // sra         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2) >> 1;
    // j           L_800794EC
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    goto L_800794EC;
    // sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
L_800794E8:
    // sh          $v1, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r3;
L_800794EC:
    // addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_800794F0:
    // jal         0x80079D0C
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    LoadImage(rdram, ctx);
    goto after_0;
    // addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    after_0:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // jal         0x8007C704
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    GetTPage(rdram, ctx);
    goto after_1;
    // addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_1:
    // andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
