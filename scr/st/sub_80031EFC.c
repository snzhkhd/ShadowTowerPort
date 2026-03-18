#include "recomp.h"
#include "disable_warnings.h"

void sub_80031EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $s3, $zero
    ctx->r17 = ADD32(ctx->r19, 0);
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // addu        $s5, $s3, $zero
    ctx->r21 = ADD32(ctx->r19, 0);
    // sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80031F2C:
    // subu        $v0, $s1, $s3
    ctx->r2 = SUB32(ctx->r17, ctx->r19);
    // addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // sltu        $v0, $s4, $v0
    ctx->r2 = ctx->r20 < ctx->r2 ? 1 : 0;
    // bne         $v0, $zero, L_8003202C
    if (ctx->r2 != 0) {
        // addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
        goto L_8003202C;
    }
    // addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(0X4, ctx->r2);
    // nop

    // andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // beq         $v0, $zero, L_80031FBC
    if (ctx->r2 == 0) {
        // addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
        goto L_80031FBC;
    }
    // addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // subu        $v0, $s1, $s3
    ctx->r2 = SUB32(ctx->r17, ctx->r19);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // sltu        $v0, $s4, $v0
    ctx->r2 = ctx->r20 < ctx->r2 ? 1 : 0;
    // bne         $v0, $zero, L_8003202C
    if (ctx->r2 != 0) {
        // addu        $s2, $s1, $zero
        ctx->r18 = ADD32(ctx->r17, 0);
        goto L_8003202C;
    }
    // addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
    // lhu         $v1, 0x8($s2)
    ctx->r3 = MEM_HU(0X8, ctx->r18);
    // lhu         $v0, 0xA($s2)
    ctx->r2 = MEM_HU(0XA, ctx->r18);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // mflo        $a2
    ctx->r6 = lo;
    // sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6) << 1;
    // addiu       $v0, $a0, 0xC
    ctx->r2 = ADD32(ctx->r4, 0XC);
    // bne         $v1, $v0, L_8003202C
    if (ctx->r3 != ctx->r2) {
        // addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
        goto L_8003202C;
    }
    // addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // subu        $v0, $s1, $s3
    ctx->r2 = SUB32(ctx->r17, ctx->r19);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sltu        $v0, $s4, $v0
    ctx->r2 = ctx->r20 < ctx->r2 ? 1 : 0;
    // bne         $v0, $zero, L_8003202C
    if (ctx->r2 != 0) {
        // addu        $s0, $s1, $zero
        ctx->r16 = ADD32(ctx->r17, 0);
        goto L_8003202C;
    }
    // addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // addu        $s1, $s1, $a0
    ctx->r17 = ADD32(ctx->r17, ctx->r4);
    // jal         0x80077104
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    VSync(rdram, ctx);
    goto after_0;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // jal         0x80079D0C
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    LoadImage(rdram, ctx);
    goto after_1;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
L_80031FBC:
    // subu        $v0, $s1, $s3
    ctx->r2 = SUB32(ctx->r17, ctx->r19);
    // addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // sltu        $v0, $s4, $v0
    ctx->r2 = ctx->r20 < ctx->r2 ? 1 : 0;
    // bne         $v0, $zero, L_8003202C
    if (ctx->r2 != 0) {
        // addu        $s2, $s1, $zero
        ctx->r18 = ADD32(ctx->r17, 0);
        goto L_8003202C;
    }
    // addu        $s2, $s1, $zero
    ctx->r18 = ADD32(ctx->r17, 0);
    // lhu         $v1, 0x8($s2)
    ctx->r3 = MEM_HU(0X8, ctx->r18);
    // lhu         $v0, 0xA($s2)
    ctx->r2 = MEM_HU(0XA, ctx->r18);
    // nop

    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(0X0, ctx->r18);
    // mflo        $a2
    ctx->r6 = lo;
    // sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6) << 1;
    // addiu       $v0, $a0, 0xC
    ctx->r2 = ADD32(ctx->r4, 0XC);
    // bne         $v1, $v0, L_8003202C
    if (ctx->r3 != ctx->r2) {
        // addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
        goto L_8003202C;
    }
    // addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // subu        $v0, $s1, $s3
    ctx->r2 = SUB32(ctx->r17, ctx->r19);
    // addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // sltu        $v0, $s4, $v0
    ctx->r2 = ctx->r20 < ctx->r2 ? 1 : 0;
    // bne         $v0, $zero, L_8003202C
    if (ctx->r2 != 0) {
        // addu        $s0, $s1, $zero
        ctx->r16 = ADD32(ctx->r17, 0);
        goto L_8003202C;
    }
    // addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // addu        $s1, $s1, $a0
    ctx->r17 = ADD32(ctx->r17, ctx->r4);
    // jal         0x80077104
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    VSync(rdram, ctx);
    goto after_2;
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_2:
    // addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // jal         0x80079D0C
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    LoadImage(rdram, ctx);
    goto after_3;
    // addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_3:
    // j           L_80031F2C
    // addu        $s5, $s1, $zero
    ctx->r21 = ADD32(ctx->r17, 0);
    goto L_80031F2C;
    // addu        $s5, $s1, $zero
    ctx->r21 = ADD32(ctx->r17, 0);
L_8003202C:
    // subu        $v0, $s5, $s3
    ctx->r2 = SUB32(ctx->r21, ctx->r19);
    // lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(0X28, ctx->r29);
    // lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(0X24, ctx->r29);
    // lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(0X20, ctx->r29);
    // lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(0X1C, ctx->r29);
    // lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(0X18, ctx->r29);
    // lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(0X14, ctx->r29);
    // lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(0X10, ctx->r29);
    // addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // jr          $ra
    // nop

    return;
    // nop

;}
