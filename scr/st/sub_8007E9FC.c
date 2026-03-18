#include "recomp.h"
#include "disable_warnings.h"

void sub_8007E9FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // lui         $s1, 0x801F
    ctx->r17 = S32(0X801F << 16);
    // addiu       $s1, $s1, -0x4C88
    ctx->r17 = ADD32(ctx->r17, -0X4C88);
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // addiu       $s3, $zero, -0x9
    ctx->r19 = ADD32(0, -0X9);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // addiu       $s2, $s2, 0x7E70
    ctx->r18 = ADD32(ctx->r18, 0X7E70);
    // sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_8007EA2C:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E58($v1)
    ctx->r3 = MEM_W(0X7E58, ctx->r3);
    // nop

    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // beq         $a1, $s3, L_8007EA70
    if (ctx->r5 == ctx->r19) {
        // addu        $s0, $v0, $s1
        ctx->r16 = ADD32(ctx->r2, ctx->r17);
        goto L_8007EA70;
    }
    // addu        $s0, $v0, $s1
    ctx->r16 = ADD32(ctx->r2, ctx->r17);
    // bne         $a1, $zero, L_8007EA60
    if (ctx->r5 != 0) {
        // sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3) << 2;
        goto L_8007EA60;
    }
    // sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3) << 2;
    // addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // j           L_8007EA70
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    goto L_8007EA70;
    // sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8007EA60:
    // jal         0x8007F210
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8007F210(rdram, ctx);
    goto after_0;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // jal         0x8007EAF0
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    sub_8007EAF0(rdram, ctx);
    goto after_1;
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
L_8007EA70:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7EB0($v0)
    ctx->r2 = MEM_W(0X7EB0, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7E58($v1)
    ctx->r3 = MEM_W(0X7E58, ctx->r3);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $zero, 0x7E5C($at)
    MEM_W(0X7E5C, ctx->r1) = 0;
    // sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7E6C($v0)
    ctx->r2 = MEM_W(0X7E6C, ctx->r2);
    // addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // sw          $v1, 0x7E58($at)
    MEM_W(0X7E58, ctx->r1) = ctx->r3;
    // slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v0, $zero, L_8007EAC8
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8007EAC8;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sll         $a0, $v1, 4
    ctx->r4 = S32(ctx->r3) << 4;
    // subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4) << 4;
    // jal         0x8007D150
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    sub_8007D150(rdram, ctx);
    goto after_2;
    // addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    after_2:
    // j           L_8007EACC
    // ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    goto L_8007EACC;
    // ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
L_8007EAC8:
    // ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
L_8007EACC:
    // beq         $v0, $zero, L_8007EA2C
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007EA2C;
    }
    // nop

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
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
