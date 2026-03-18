#include "recomp.h"
#include "disable_warnings.h"

void sub_8007B540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // jal         0x8007C070
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    sub_8007C070(rdram, ctx);
    goto after_0;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // lh          $a1, 0x4($s1)
    ctx->r5 = MEM_HS(0X4, ctx->r17);
    // lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(0X4, ctx->r17);
    // bltz        $a1, L_8007B59C
    if (SIGNED(ctx->r5) < 0) {
        // addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
        goto L_8007B59C;
    }
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lh          $v0, 0x7CC4($v0)
    ctx->r2 = MEM_HS(0X7CC4, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lhu         $v1, 0x7CC4($v1)
    ctx->r3 = MEM_HU(0X7CC4, ctx->r3);
    // slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // beq         $v0, $zero, L_8007B5A0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007B5A0;
    }
    // nop

    // j           L_8007B5A0
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    goto L_8007B5A0;
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
L_8007B59C:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8007B5A0:
    // lh          $a1, 0x6($s1)
    ctx->r5 = MEM_HS(0X6, ctx->r17);
    // lhu         $v1, 0x6($s1)
    ctx->r3 = MEM_HU(0X6, ctx->r17);
    // bltz        $a1, L_8007B5D8
    if (SIGNED(ctx->r5) < 0) {
        // sh          $a0, 0x4($s1)
        MEM_H(0X4, ctx->r17) = ctx->r4;
        goto L_8007B5D8;
    }
    // sh          $a0, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r4;
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lh          $v0, 0x7CC6($v0)
    ctx->r2 = MEM_HS(0X7CC6, ctx->r2);
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lhu         $v1, 0x7CC6($v1)
    ctx->r3 = MEM_HU(0X7CC6, ctx->r3);
    // slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // beq         $v0, $zero, L_8007B5E0
    if (ctx->r2 == 0) {
        // sll         $v0, $a0, 16
        ctx->r2 = S32(ctx->r4) << 16;
        goto L_8007B5E0;
    }
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
    // j           L_8007B5DC
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    goto L_8007B5DC;
    // addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
L_8007B5D8:
    // addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_8007B5DC:
    // sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4) << 16;
L_8007B5E0:
    // lh          $v1, 0x4($s1)
    ctx->r3 = MEM_HS(0X4, ctx->r17);
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sh          $a0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r4;
    // mflo        $a2
    ctx->r6 = lo;
    // addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // sra         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3) >> 1;
    // bgtz        $a0, L_8007B614
    if (SIGNED(ctx->r4) > 0) {
        // sra         $s0, $v1, 5
        ctx->r16 = S32(ctx->r3) >> 5;
        goto L_8007B614;
    }
    // sra         $s0, $v1, 5
    ctx->r16 = S32(ctx->r3) >> 5;
    // j           L_8007B7A0
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    goto L_8007B7A0;
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007B614:
    // addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3) << 4;
    // subu        $s0, $a0, $v0
    ctx->r16 = SUB32(ctx->r4, ctx->r2);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DC8($v0)
    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
    // addu        $s4, $v1, $zero
    ctx->r20 = ADD32(ctx->r3, 0);
    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8007B674
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007B674;
    }
    // nop

    // lui         $s3, 0x400
    ctx->r19 = S32(0X400 << 16);
L_8007B644:
    // jal         0x8007C0A4
    // nop

    sub_8007C0A4(rdram, ctx);
    goto after_1;
    // nop

    after_1:
    // bne         $v0, $zero, L_8007B7A0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8007B7A0;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DC8($v0)
    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // and         $v0, $v0, $s3
    ctx->r2 = ctx->r2 & ctx->r19;
    // beq         $v0, $zero, L_8007B644
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007B644;
    }
    // nop

L_8007B674:
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DC8($v1)
    ctx->r3 = MEM_W(0X7DC8, ctx->r3);
    // lui         $v0, 0x400
    ctx->r2 = S32(0X400 << 16);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DC4($v1)
    ctx->r3 = MEM_W(0X7DC4, ctx->r3);
    // lui         $v0, 0x100
    ctx->r2 = S32(0X100 << 16);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DC4($v1)
    ctx->r3 = MEM_W(0X7DC4, ctx->r3);
    // lui         $v0, 0xC000
    ctx->r2 = S32(0XC000 << 16);
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DC4($v1)
    ctx->r3 = MEM_W(0X7DC4, ctx->r3);
    // lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(0X0, ctx->r17);
    // nop

    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DC4($v1)
    ctx->r3 = MEM_W(0X7DC4, ctx->r3);
    // lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(0X4, ctx->r17);
    // nop

    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DC8($v0)
    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // bne         $v0, $zero, L_8007B720
    if (ctx->r2 != 0) {
        // nop
    
        goto L_8007B720;
    }
    // nop

    // lui         $s1, 0x800
    ctx->r17 = S32(0X800 << 16);
L_8007B6F0:
    // jal         0x8007C0A4
    // nop

    sub_8007C0A4(rdram, ctx);
    goto after_2;
    // nop

    after_2:
    // bne         $v0, $zero, L_8007B7A0
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
        goto L_8007B7A0;
    }
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DC8($v0)
    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // nop

    // and         $v0, $v0, $s1
    ctx->r2 = ctx->r2 & ctx->r17;
    // beq         $v0, $zero, L_8007B6F0
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8007B6F0;
    }
    // nop

L_8007B720:
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // beq         $s0, $v0, L_8007B750
    if (ctx->r16 == ctx->r2) {
        // addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
        goto L_8007B750;
    }
    // addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8007B730:
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DC4($v0)
    ctx->r2 = MEM_W(0X7DC4, ctx->r2);
    // nop

    // lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(0X0, ctx->r2);
    // addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // bne         $s0, $v1, L_8007B730
    if (ctx->r16 != ctx->r3) {
        // addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
        goto L_8007B730;
    }
    // addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8007B750:
    // beq         $s4, $zero, L_8007B79C
    if (ctx->r20 == 0) {
        // lui         $v1, 0x400
        ctx->r3 = S32(0X400 << 16);
        goto L_8007B79C;
    }
    // lui         $v1, 0x400
    ctx->r3 = S32(0X400 << 16);
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DC8($v0)
    ctx->r2 = MEM_W(0X7DC8, ctx->r2);
    // ori         $v1, $v1, 0x3
    ctx->r3 = ctx->r3 | 0X3;
    // sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DCC($v0)
    ctx->r2 = MEM_W(0X7DCC, ctx->r2);
    // lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20) << 16;
    // lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // lw          $v1, 0x7DD0($v1)
    ctx->r3 = MEM_W(0X7DD0, ctx->r3);
    // ori         $v0, $v0, 0x10
    ctx->r2 = ctx->r2 | 0X10;
    // sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // lw          $v0, 0x7DD4($v0)
    ctx->r2 = MEM_W(0X7DD4, ctx->r2);
    // ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_8007B79C:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007B7A0:
    // lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(0X24, ctx->r29);
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
    // jr          $ra
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
