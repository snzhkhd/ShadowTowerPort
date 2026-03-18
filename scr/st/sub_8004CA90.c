#include "recomp.h"
#include "disable_warnings.h"

void sub_8004CA90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(0X40, ctx->r29);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(0X44, ctx->r29);
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // jal         0x80078AC4
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    rand_recomp(rdram, ctx);
    goto after_0;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // lui         $s1, 0x8184
    ctx->r17 = S32(0X8184 << 16);
    // ori         $s1, $s1, 0x8DA9
    ctx->r17 = ctx->r17 | 0X8DA9;
    // mult        $v0, $s1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // mfhi        $a3
    ctx->r7 = hi;
    // addu        $v1, $a3, $v0
    ctx->r3 = ADD32(ctx->r7, ctx->r2);
    // sra         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3) >> 10;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // subu        $v1, $s5, $v1
    ctx->r3 = SUB32(ctx->r21, ctx->r3);
    // jal         0x80078AC4
    // sh          $v1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r3;
    rand_recomp(rdram, ctx);
    goto after_1;
    // sh          $v1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r3;
    after_1:
    // bgez        $v0, L_8004CB08
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8004CB08;
    }
    // nop

    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
L_8004CB08:
    // sra         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) >> 10;
    // subu        $v0, $s2, $v0
    ctx->r2 = SUB32(ctx->r18, ctx->r2);
    // jal         0x80078AC4
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    rand_recomp(rdram, ctx);
    goto after_2;
    // sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    after_2:
    // mult        $v0, $s1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mfhi        $a3
    ctx->r7 = hi;
    // addu        $v1, $a3, $v0
    ctx->r3 = ADD32(ctx->r7, ctx->r2);
    // sra         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3) >> 10;
    // sra         $v0, $v0, 31
    ctx->r2 = S32(ctx->r2) >> 31;
    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // subu        $v1, $s5, $v1
    ctx->r3 = SUB32(ctx->r21, ctx->r3);
    // sh          $v1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r3;
    // lh          $v1, 0x0($s0)
    ctx->r3 = MEM_HS(0X0, ctx->r16);
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22) << 16;
    // lw          $v1, 0x4($s3)
    ctx->r3 = MEM_W(0X4, ctx->r19);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sw          $v1, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r3;
    // lh          $v1, 0x4($s0)
    ctx->r3 = MEM_HS(0X4, ctx->r16);
    // lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(0X8, ctx->r19);
    // nop

    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sw          $v0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r2;
    // lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(0X2C, ctx->r29);
    // lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(0X28, ctx->r29);
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
