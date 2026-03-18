#include "recomp.h"
#include "disable_warnings.h"

void sub_8006D924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // sll         $v0, $a3, 16
    ctx->r2 = S32(ctx->r7) << 16;
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addiu       $v1, $v1, -0x79A0
    ctx->r3 = ADD32(ctx->r3, -0X79A0);
    // sra         $v0, $v0, 14
    ctx->r2 = S32(ctx->r2) >> 14;
    // sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // addu        $s3, $v0, $v1
    ctx->r19 = ADD32(ctx->r2, ctx->r3);
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
    // sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // sll         $s2, $v0, 4
    ctx->r18 = S32(ctx->r2) << 4;
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(0X0, ctx->r19);
    // addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // addu        $s0, $v1, $s2
    ctx->r16 = ADD32(ctx->r3, ctx->r18);
    // lw          $v0, 0xA0($s0)
    ctx->r2 = MEM_W(0XA0, ctx->r16);
    // addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // bgez        $v0, L_8006D9A4
    if (SIGNED(ctx->r2) >= 0) {
        // sw          $v0, 0xA0($s0)
        MEM_W(0XA0, ctx->r16) = ctx->r2;
        goto L_8006D9A4;
    }
    // sw          $v0, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->r2;
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // j           L_8006DC74
    // addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    goto L_8006DC74;
    // addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
L_8006D9A4:
    // lh          $a2, 0x4C($s0)
    ctx->r6 = MEM_HS(0X4C, ctx->r16);
    // lhu         $v1, 0x4C($s0)
    ctx->r3 = MEM_HU(0X4C, ctx->r16);
    // blez        $a2, L_8006DA88
    if (SIGNED(ctx->r6) <= 0) {
        // nop
    
        goto L_8006DA88;
    }
    // nop

    // div         $zero, $v0, $a2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r6)));
    // bne         $a2, $zero, L_8006D9C4
    if (ctx->r6 != 0) {
        // nop
    
        goto L_8006D9C4;
    }
    // nop

    // break       7
    do_break(2147932608);
L_8006D9C4:
    // addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // bne         $a2, $at, L_8006D9DC
    if (ctx->r6 != ctx->r1) {
        // lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
        goto L_8006D9DC;
    }
    // lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // bne         $v0, $at, L_8006D9DC
    if (ctx->r2 != ctx->r1) {
        // nop
    
        goto L_8006D9DC;
    }
    // nop

    // break       6
    do_break(2147932632);
L_8006D9DC:
    // mfhi        $v0
    ctx->r2 = hi;
    // bne         $v0, $zero, L_8006DC88
    if (ctx->r2 != 0) {
        // sll         $a0, $s4, 8
        ctx->r4 = S32(ctx->r20) << 8;
        goto L_8006DC88;
    }
    // sll         $a0, $s4, 8
    ctx->r4 = S32(ctx->r20) << 8;
    // lhu         $v0, 0x4A($s0)
    ctx->r2 = MEM_HU(0X4A, ctx->r16);
    // nop

    // addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // sh          $v0, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bltz        $v0, L_8006DBE4
    if (SIGNED(ctx->r2) < 0) {
        // sll         $v0, $a1, 8
        ctx->r2 = S32(ctx->r5) << 8;
        goto L_8006DBE4;
    }
    // sll         $v0, $a1, 8
    ctx->r2 = S32(ctx->r5) << 8;
    // or          $v0, $a3, $v0
    ctx->r2 = ctx->r7 | ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2) >> 16;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // jal         0x800732F8
    // addiu       $a2, $sp, 0x12
    ctx->r6 = ADD32(ctx->r29, 0X12);
    sub_800732F8(rdram, ctx);
    goto after_0;
    // addiu       $a2, $sp, 0x12
    ctx->r6 = ADD32(ctx->r29, 0X12);
    after_0:
    // lhu         $a0, 0x10($sp)
    ctx->r4 = MEM_HU(0X10, ctx->r29);
    // lh          $a2, 0x4A($s0)
    ctx->r6 = MEM_HS(0X4A, ctx->r16);
    // addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // subu        $v0, $a0, $a2
    ctx->r2 = SUB32(ctx->r4, ctx->r6);
    // slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8006DA58
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006DA58;
    }
    // nop

    // lhu         $v0, 0x12($sp)
    ctx->r2 = MEM_HU(0X12, ctx->r29);
    // nop

    // addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // subu        $v0, $v0, $a2
    ctx->r2 = SUB32(ctx->r2, ctx->r6);
    // slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // bne         $v1, $zero, L_8006DC20
    if (ctx->r3 != 0) {
        // nop
    
        goto L_8006DC20;
    }
    // nop

L_8006DA58:
    // beq         $a0, $zero, L_8006DA70
    if (ctx->r4 == 0) {
        // nop
    
        goto L_8006DA70;
    }
    // nop

    // lhu         $a2, 0x12($sp)
    ctx->r6 = MEM_HU(0X12, ctx->r29);
    // nop

    // bne         $a2, $zero, L_8006DA7C
    if (ctx->r6 != 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8006DA7C;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_8006DA70:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // j           L_8006DBA4
    // addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    goto L_8006DBA4;
    // addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
L_8006DA7C:
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // j           L_8006DBD0
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    goto L_8006DBD0;
    // addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8006DA88:
    // bgez        $a2, L_8006DC88
    if (SIGNED(ctx->r6) >= 0) {
        // sll         $a0, $s4, 8
        ctx->r4 = S32(ctx->r20) << 8;
        goto L_8006DC88;
    }
    // sll         $a0, $s4, 8
    ctx->r4 = S32(ctx->r20) << 8;
    // lhu         $v0, 0x4A($s0)
    ctx->r2 = MEM_HU(0X4A, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // sh          $v0, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // bltz        $v0, L_8006DBE4
    if (SIGNED(ctx->r2) < 0) {
        // sll         $v0, $a1, 8
        ctx->r2 = S32(ctx->r5) << 8;
        goto L_8006DBE4;
    }
    // sll         $v0, $a1, 8
    ctx->r2 = S32(ctx->r5) << 8;
    // or          $v0, $a3, $v0
    ctx->r2 = ctx->r7 | ctx->r2;
    // sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) << 16;
    // sra         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2) >> 16;
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // jal         0x800732F8
    // addiu       $a2, $sp, 0x12
    ctx->r6 = ADD32(ctx->r29, 0X12);
    sub_800732F8(rdram, ctx);
    goto after_1;
    // addiu       $a2, $sp, 0x12
    ctx->r6 = ADD32(ctx->r29, 0X12);
    after_1:
    // lhu         $v0, 0x10($sp)
    ctx->r2 = MEM_HU(0X10, ctx->r29);
    // lh          $v1, 0x4C($s0)
    ctx->r3 = MEM_HS(0X4C, ctx->r16);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // bgtz        $v0, L_8006DB20
    if (SIGNED(ctx->r2) > 0) {
        // nop
    
        goto L_8006DB20;
    }
    // nop

    // lhu         $v0, 0x12($sp)
    ctx->r2 = MEM_HU(0X12, ctx->r29);
    // nop

    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // bgtz        $v0, L_8006DB20
    if (SIGNED(ctx->r2) > 0) {
        // addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
        goto L_8006DB20;
    }
    // addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80072D74
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _SsVmSetSeqVol(rdram, ctx);
    goto after_2;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(0X0, ctx->r19);
    // nop

    // addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // lw          $v1, 0x98($v0)
    ctx->r3 = MEM_W(0X98, ctx->r2);
    // addiu       $a0, $zero, -0x21
    ctx->r4 = ADD32(0, -0X21);
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // sw          $v1, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r3;
L_8006DB20:
    // lw          $v1, 0x9C($s0)
    ctx->r3 = MEM_W(0X9C, ctx->r16);
    // lw          $a0, 0xA0($s0)
    ctx->r4 = MEM_W(0XA0, ctx->r16);
    // lh          $v0, 0x4C($s0)
    ctx->r2 = MEM_HS(0X4C, ctx->r16);
    // subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // lh          $v0, 0x48($s0)
    ctx->r2 = MEM_HS(0X48, ctx->r16);
    // lhu         $v1, 0x4C($s0)
    ctx->r3 = MEM_HU(0X4C, ctx->r16);
    // mflo        $t0
    ctx->r8 = lo;
    // slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // beq         $v0, $zero, L_8006DC20
    if (ctx->r2 == 0) {
        // nop
    
        goto L_8006DC20;
    }
    // nop

    // lhu         $a1, 0x10($sp)
    ctx->r5 = MEM_HU(0X10, ctx->r29);
    // nop

    // beq         $a1, $zero, L_8006DB74
    if (ctx->r5 == 0) {
        // sll         $a0, $s5, 16
        ctx->r4 = S32(ctx->r21) << 16;
        goto L_8006DB74;
    }
    // sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21) << 16;
    // lhu         $a2, 0x12($sp)
    ctx->r6 = MEM_HU(0X12, ctx->r29);
    // nop

    // bne         $a2, $zero, L_8006DBB8
    if (ctx->r6 != 0) {
        // sll         $a0, $s4, 8
        ctx->r4 = S32(ctx->r20) << 8;
        goto L_8006DBB8;
    }
    // sll         $a0, $s4, 8
    ctx->r4 = S32(ctx->r20) << 8;
    // sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21) << 16;
L_8006DB74:
    // sra         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4) >> 14;
    // sll         $v1, $s4, 16
    ctx->r3 = S32(ctx->r20) << 16;
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
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lw          $v1, -0x79A0($v1)
    ctx->r3 = MEM_W(-0X79A0, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8006DBA4:
    // lw          $v1, 0x98($v0)
    ctx->r3 = MEM_W(0X98, ctx->r2);
    // addiu       $a0, $zero, -0x21
    ctx->r4 = ADD32(0, -0X21);
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // j           L_8006DC20
    // sw          $v1, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r3;
    goto L_8006DC20;
    // sw          $v1, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r3;
L_8006DBB8:
    // or          $a0, $s5, $a0
    ctx->r4 = ctx->r21 | ctx->r4;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
L_8006DBD0:
    // andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // jal         0x80072D74
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _SsVmSetSeqVol(rdram, ctx);
    goto after_3;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // j           L_8006DC20
    // nop

    goto L_8006DC20;
    // nop

L_8006DBE4:
    // sll         $a0, $a1, 8
    ctx->r4 = S32(ctx->r5) << 8;
    // or          $a0, $a3, $a0
    ctx->r4 = ctx->r7 | ctx->r4;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // jal         0x80072D74
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _SsVmSetSeqVol(rdram, ctx);
    goto after_4;
    // addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(0X0, ctx->r19);
    // nop

    // addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // lw          $v0, 0x98($v1)
    ctx->r2 = MEM_W(0X98, ctx->r3);
    // addiu       $a0, $zero, -0x21
    ctx->r4 = ADD32(0, -0X21);
    // and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // sw          $v0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->r2;
L_8006DC20:
    // lw          $v0, 0xA0($s0)
    ctx->r2 = MEM_W(0XA0, ctx->r16);
    // nop

    // beq         $v0, $zero, L_8006DC44
    if (ctx->r2 == 0) {
        // sll         $a0, $s5, 16
        ctx->r4 = S32(ctx->r21) << 16;
        goto L_8006DC44;
    }
    // sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21) << 16;
    // lh          $v0, 0x4A($s0)
    ctx->r2 = MEM_HS(0X4A, ctx->r16);
    // nop

    // bgtz        $v0, L_8006DC88
    if (SIGNED(ctx->r2) > 0) {
        // sll         $a0, $s4, 8
        ctx->r4 = S32(ctx->r20) << 8;
        goto L_8006DC88;
    }
    // sll         $a0, $s4, 8
    ctx->r4 = S32(ctx->r20) << 8;
    // sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21) << 16;
L_8006DC44:
    // sra         $a0, $a0, 14
    ctx->r4 = S32(ctx->r4) >> 14;
    // sll         $v1, $s4, 16
    ctx->r3 = S32(ctx->r20) << 16;
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
    // lui         $v1, 0x801F
    ctx->r3 = S32(0X801F << 16);
    // addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // lw          $v1, -0x79A0($v1)
    ctx->r3 = MEM_W(-0X79A0, ctx->r3);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_8006DC74:
    // lw          $v1, 0x98($v0)
    ctx->r3 = MEM_W(0X98, ctx->r2);
    // addiu       $a0, $zero, -0x21
    ctx->r4 = ADD32(0, -0X21);
    // and         $v1, $v1, $a0
    ctx->r3 = ctx->r3 & ctx->r4;
    // sw          $v1, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r3;
    // sll         $a0, $s4, 8
    ctx->r4 = S32(ctx->r20) << 8;
L_8006DC88:
    // or          $a0, $s5, $a0
    ctx->r4 = ctx->r21 | ctx->r4;
    // sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) << 16;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    // jal         0x800732F8
    // addiu       $a2, $s0, 0x5E
    ctx->r6 = ADD32(ctx->r16, 0X5E);
    sub_800732F8(rdram, ctx);
    goto after_5;
    // addiu       $a2, $s0, 0x5E
    ctx->r6 = ADD32(ctx->r16, 0X5E);
    after_5:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(0X2C, ctx->r29);
    // lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(0X28, ctx->r29);
    // lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(0X24, ctx->r29);
    // lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(0X20, ctx->r29);
    // lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(0X1C, ctx->r29);
    // lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(0X18, ctx->r29);
    // jr          $ra
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
