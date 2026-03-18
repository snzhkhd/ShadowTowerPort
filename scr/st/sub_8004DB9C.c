#include "recomp.h"
#include "disable_warnings.h"

void sub_8004DB9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $a0, $v0, -0x70D8
    ctx->r4 = ADD32(ctx->r2, -0X70D8);
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) << 16;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lhu         $v0, 0x26A($a0)
    ctx->r2 = MEM_HU(0X26A, ctx->r4);
    // lhu         $v1, 0x56($s1)
    ctx->r3 = MEM_HU(0X56, ctx->r17);
    // lhu         $t0, 0x2E($s1)
    ctx->r8 = MEM_HU(0X2E, ctx->r17);
    // lw          $a3, 0x40($s1)
    ctx->r7 = MEM_W(0X40, ctx->r17);
    // subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // andi        $s5, $v0, 0xFFF
    ctx->r21 = ctx->r2 & 0XFFF;
    // addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // lhu         $v1, 0x268($a0)
    ctx->r3 = MEM_HU(0X268, ctx->r4);
    // slt         $a1, $a1, $a3
    ctx->r5 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // bne         $a1, $zero, L_8004DDF4
    if (ctx->r5 != 0) {
        // andi        $s4, $v1, 0xFFF
        ctx->r20 = ctx->r3 & 0XFFF;
        goto L_8004DDF4;
    }
    // andi        $s4, $v1, 0xFFF
    ctx->r20 = ctx->r3 & 0XFFF;
    // lhu         $v0, 0x78($s1)
    ctx->r2 = MEM_HU(0X78, ctx->r17);
    // lhu         $a1, 0x24C($a0)
    ctx->r5 = MEM_HU(0X24C, ctx->r4);
    // lhu         $a0, 0x30($s1)
    ctx->r4 = MEM_HU(0X30, ctx->r17);
    // subu        $v1, $v0, $a1
    ctx->r3 = SUB32(ctx->r2, ctx->r5);
    // addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) << 16;
    // sra         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3) >> 16;
    // blez        $a0, L_8004DC60
    if (SIGNED(ctx->r4) <= 0) {
        // addu        $s3, $v0, $zero
        ctx->r19 = ADD32(ctx->r2, 0);
        goto L_8004DC60;
    }
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2) >> 16;
    // blez        $s0, L_8004DC64
    if (SIGNED(ctx->r16) <= 0) {
        // sll         $v0, $a2, 16
        ctx->r2 = S32(ctx->r6) << 16;
        goto L_8004DC64;
    }
    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
    // jal         0x80076EA4
    // subu        $a1, $a3, $t0
    ctx->r5 = SUB32(ctx->r7, ctx->r8);
    ratan2(rdram, ctx);
    goto after_0;
    // subu        $a1, $a3, $t0
    ctx->r5 = SUB32(ctx->r7, ctx->r8);
    after_0:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // lhu         $v0, 0x2E($s1)
    ctx->r2 = MEM_HU(0X2E, ctx->r17);
    // lw          $a1, 0x40($s1)
    ctx->r5 = MEM_W(0X40, ctx->r17);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // j           L_8004DCC4
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    goto L_8004DCC4;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
L_8004DC60:
    // sll         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) << 16;
L_8004DC64:
    // sra         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2) >> 16;
    // bgez        $a0, L_8004DCA4
    if (SIGNED(ctx->r4) >= 0) {
        // sll         $v0, $s3, 16
        ctx->r2 = S32(ctx->r19) << 16;
        goto L_8004DCA4;
    }
    // sll         $v0, $s3, 16
    ctx->r2 = S32(ctx->r19) << 16;
    // sra         $s0, $v0, 16
    ctx->r16 = S32(ctx->r2) >> 16;
    // bgez        $s0, L_8004DCA4
    if (SIGNED(ctx->r16) >= 0) {
        // nop
    
        goto L_8004DCA4;
    }
    // nop

    // lhu         $v0, 0x2E($s1)
    ctx->r2 = MEM_HU(0X2E, ctx->r17);
    // lw          $a1, 0x40($s1)
    ctx->r5 = MEM_W(0X40, ctx->r17);
    // jal         0x80076EA4
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    ratan2(rdram, ctx);
    goto after_1;
    // addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    after_1:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // lhu         $v0, 0x2E($s1)
    ctx->r2 = MEM_HU(0X2E, ctx->r17);
    // lw          $a1, 0x40($s1)
    ctx->r5 = MEM_W(0X40, ctx->r17);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // j           L_8004DCC4
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    goto L_8004DCC4;
    // subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
L_8004DCA4:
    // sll         $a0, $a2, 16
    ctx->r4 = S32(ctx->r6) << 16;
    // lw          $a1, 0x40($s1)
    ctx->r5 = MEM_W(0X40, ctx->r17);
    // jal         0x80076EA4
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    ratan2(rdram, ctx);
    goto after_2;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    after_2:
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // sll         $a0, $s3, 16
    ctx->r4 = S32(ctx->r19) << 16;
    // lw          $a1, 0x40($s1)
    ctx->r5 = MEM_W(0X40, ctx->r17);
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
L_8004DCC4:
    // jal         0x80076EA4
    // nop

    ratan2(rdram, ctx);
    goto after_3;
    // nop

    after_3:
    // lhu         $a0, 0x2E($s1)
    ctx->r4 = MEM_HU(0X2E, ctx->r17);
    // lw          $a1, 0x40($s1)
    ctx->r5 = MEM_W(0X40, ctx->r17);
    // jal         0x80076EA4
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    ratan2(rdram, ctx);
    goto after_4;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_4:
    // addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x801
    ctx->r2 = SIGNED(ctx->r2) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_8004DCF8
    if (ctx->r2 != 0) {
        // sll         $v0, $s4, 16
        ctx->r2 = S32(ctx->r20) << 16;
        goto L_8004DCF8;
    }
    // sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20) << 16;
    // addiu       $s5, $s5, -0x1000
    ctx->r21 = ADD32(ctx->r21, -0X1000);
L_8004DCF8:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x801
    ctx->r2 = SIGNED(ctx->r2) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_8004DD0C
    if (ctx->r2 != 0) {
        // sll         $v0, $s2, 16
        ctx->r2 = S32(ctx->r18) << 16;
        goto L_8004DD0C;
    }
    // sll         $v0, $s2, 16
    ctx->r2 = S32(ctx->r18) << 16;
    // addiu       $s4, $s4, -0x1000
    ctx->r20 = ADD32(ctx->r20, -0X1000);
L_8004DD0C:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x801
    ctx->r2 = SIGNED(ctx->r2) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_8004DD28
    if (ctx->r2 != 0) {
        // sll         $v0, $s0, 16
        ctx->r2 = S32(ctx->r16) << 16;
        goto L_8004DD28;
    }
    // sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16) << 16;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // subu        $s2, $v0, $s2
    ctx->r18 = SUB32(ctx->r2, ctx->r18);
    // sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16) << 16;
L_8004DD28:
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // slti        $v0, $v0, 0x801
    ctx->r2 = SIGNED(ctx->r2) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_8004DD44
    if (ctx->r2 != 0) {
        // sll         $v0, $s4, 16
        ctx->r2 = S32(ctx->r20) << 16;
        goto L_8004DD44;
    }
    // sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20) << 16;
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // subu        $s0, $v0, $s0
    ctx->r16 = SUB32(ctx->r2, ctx->r16);
    // sll         $v0, $s4, 16
    ctx->r2 = S32(ctx->r20) << 16;
L_8004DD44:
    // sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16) << 16;
    // sra         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2) >> 16;
    // slt         $v0, $v0, $t2
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // bne         $v0, $zero, L_8004DDF8
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004DDF8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // sll         $t1, $s2, 16
    ctx->r9 = S32(ctx->r18) << 16;
    // sra         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9) >> 16;
    // slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_8004DDF8
    if (ctx->r2 != 0) {
        // addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
        goto L_8004DDF8;
    }
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // sll         $v0, $s5, 16
    ctx->r2 = S32(ctx->r21) << 16;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // bgez        $v0, L_8004DD80
    if (SIGNED(ctx->r2) >= 0) {
        // addu        $t0, $v0, $zero
        ctx->r8 = ADD32(ctx->r2, 0);
        goto L_8004DD80;
    }
    // addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
L_8004DD80:
    // sll         $a2, $v1, 16
    ctx->r6 = S32(ctx->r3) << 16;
    // sra         $v0, $a2, 16
    ctx->r2 = S32(ctx->r6) >> 16;
    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8004DDF4
    if (ctx->r2 == 0) {
        // sll         $v0, $s6, 16
        ctx->r2 = S32(ctx->r22) << 16;
        goto L_8004DDF4;
    }
    // sll         $v0, $s6, 16
    ctx->r2 = S32(ctx->r22) << 16;
    // sra         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2) >> 16;
    // lhu         $v1, 0x2E($s1)
    ctx->r3 = MEM_HU(0X2E, ctx->r17);
    // lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(0X40, ctx->r17);
    // addu        $v0, $v1, $a3
    ctx->r2 = ADD32(ctx->r3, ctx->r7);
    // slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8004DDF4
    if (ctx->r2 == 0) {
        // sra         $v0, $t2, 17
        ctx->r2 = S32(ctx->r10) >> 17;
        goto L_8004DDF4;
    }
    // sra         $v0, $t2, 17
    ctx->r2 = S32(ctx->r10) >> 17;
    // slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v0, $zero, L_8004DDF8
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8004DDF8;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sra         $v0, $t1, 17
    ctx->r2 = S32(ctx->r9) >> 17;
    // slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // bne         $v0, $zero, L_8004DDF8
    if (ctx->r2 != 0) {
        // addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
        goto L_8004DDF8;
    }
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // sra         $v0, $a2, 17
    ctx->r2 = S32(ctx->r6) >> 17;
    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8004DDEC
    if (ctx->r2 == 0) {
        // srl         $v1, $v1, 1
        ctx->r3 = S32(U32(ctx->r3) >> 1);
        goto L_8004DDEC;
    }
    // srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // slt         $v1, $a0, $v1
    ctx->r3 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // bne         $v1, $zero, L_8004DDF8
    if (ctx->r3 != 0) {
        // addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
        goto L_8004DDF8;
    }
    // addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8004DDEC:
    // j           L_8004DDF8
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    goto L_8004DDF8;
    // addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004DDF4:
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8004DDF8:
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
