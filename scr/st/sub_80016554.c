#include "recomp.h"
#include "disable_warnings.h"

void sub_80016554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // lui         $s7, 0x1F80
    ctx->r23 = S32(0X1F80 << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // lh          $v1, 0x26A($v0)
    ctx->r3 = MEM_HS(0X26A, ctx->r2);
    // lh          $s6, 0x268($v0)
    ctx->r22 = MEM_HS(0X268, ctx->r2);
    // nop

    // slti        $v0, $s6, 0x801
    ctx->r2 = SIGNED(ctx->r22) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_800165AC
    if (ctx->r2 != 0) {
        // addiu       $s2, $v1, 0x400
        ctx->r18 = ADD32(ctx->r3, 0X400);
        goto L_800165AC;
    }
    // addiu       $s2, $v1, 0x400
    ctx->r18 = ADD32(ctx->r3, 0X400);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // j           L_800165B0
    // subu        $s1, $v0, $s6
    ctx->r17 = SUB32(ctx->r2, ctx->r22);
    goto L_800165B0;
    // subu        $s1, $v0, $s6
    ctx->r17 = SUB32(ctx->r2, ctx->r22);
L_800165AC:
    // addu        $s1, $s6, $zero
    ctx->r17 = ADD32(ctx->r22, 0);
L_800165B0:
    // sll         $v0, $s1, 3
    ctx->r2 = S32(ctx->r17) << 3;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // bgez        $v0, L_800165D0
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_800165D0;
    }
    // nop

    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
L_800165D0:
    // sra         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2) >> 10;
    // addiu       $s1, $v0, 0x200
    ctx->r17 = ADD32(ctx->r2, 0X200);
    // jal         0x800744C4
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    rcos(rdram, ctx);
    goto after_0;
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // jal         0x800743F4
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    rsin(rdram, ctx);
    goto after_1;
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    after_1:
    // subu        $s0, $s2, $s1
    ctx->r16 = SUB32(ctx->r18, ctx->r17);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x800744C4
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    rcos(rdram, ctx);
    goto after_2;
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    after_2:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x800743F4
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    rsin(rdram, ctx);
    goto after_3;
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    after_3:
    // addu        $s0, $s2, $s1
    ctx->r16 = ADD32(ctx->r18, ctx->r17);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x800744C4
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    rcos(rdram, ctx);
    goto after_4;
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    after_4:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x800743F4
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    rsin(rdram, ctx);
    goto after_5;
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_5:
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // jal         0x800744C4
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    rcos(rdram, ctx);
    goto after_6;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_6:
    // sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2) << 1;
    // addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // subu        $a0, $v0, $a0
    ctx->r4 = SUB32(ctx->r2, ctx->r4);
    // sra         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4) >> 12;
    // mult        $a0, $s5
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // nop

    // nop

    // mult        $a0, $s3
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2) << 4;
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // mult        $v1, $s4
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a3
    ctx->r7 = lo;
    // nop

    // nop

    // mult        $v1, $s2
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // nop

    // nop

    // mult        $v1, $s1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t2
    ctx->r10 = lo;
    // nop

    // nop

    // mult        $v1, $s0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2) << 3;
    // mflo        $t0
    ctx->r8 = lo;
    // negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // sra         $v0, $v0, 12
    ctx->r2 = S32(ctx->r2) >> 12;
    // mult        $v0, $s5
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t7
    ctx->r15 = lo;
    // nop

    // nop

    // mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5) << 4;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // addu        $v0, $a2, $a0
    ctx->r2 = ADD32(ctx->r6, ctx->r4);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // sll         $a2, $a0, 4
    ctx->r6 = S32(ctx->r4) << 4;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // mflo        $s0
    ctx->r16 = lo;
    // subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // negu        $v0, $t6
    ctx->r2 = SUB32(0, ctx->r14);
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
    // sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2) << 4;
    // mflo        $t4
    ctx->r12 = lo;
    // sra         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2) >> 16;
    // subu        $t5, $v0, $v1
    ctx->r13 = SUB32(ctx->r2, ctx->r3);
    // mult        $t5, $a2
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $t0, $a0
    ctx->r4 = ADD32(ctx->r8, ctx->r4);
    // sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4) << 4;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // mflo        $t3
    ctx->r11 = lo;
    // subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
    // negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
    // mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a1, $t2, $a1
    ctx->r5 = ADD32(ctx->r10, ctx->r5);
    // sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5) << 4;
    // mflo        $t1
    ctx->r9 = lo;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // mult        $a1, $a2
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $t0, $t7, 12
    ctx->r8 = S32(ctx->r15) >> 12;
    // sra         $t2, $s0, 12
    ctx->r10 = S32(ctx->r16) >> 12;
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $s4, $v0, -0x70D8
    ctx->r20 = ADD32(ctx->r2, -0X70D8);
    // lw          $v1, 0xE0($s7)
    ctx->r3 = MEM_W(0XE0, ctx->r23);
    // lw          $v0, 0x248($s4)
    ctx->r2 = MEM_W(0X248, ctx->r20);
    // addu        $t3, $t4, $t3
    ctx->r11 = ADD32(ctx->r12, ctx->r11);
    // subu        $a3, $v1, $v0
    ctx->r7 = SUB32(ctx->r3, ctx->r2);
    // mflo        $a2
    ctx->r6 = lo;
    // bgez        $a3, L_80016764
    if (SIGNED(ctx->r7) >= 0) {
        // addu        $t1, $t1, $a2
        ctx->r9 = ADD32(ctx->r9, ctx->r6);
        goto L_80016764;
    }
    // addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // addiu       $a3, $a3, 0x7FF
    ctx->r7 = ADD32(ctx->r7, 0X7FF);
L_80016764:
    // lw          $v1, 0xE8($s7)
    ctx->r3 = MEM_W(0XE8, ctx->r23);
    // lw          $v0, 0x250($s4)
    ctx->r2 = MEM_W(0X250, ctx->r20);
    // nop

    // subu        $a2, $v1, $v0
    ctx->r6 = SUB32(ctx->r3, ctx->r2);
    // sra         $v1, $a3, 11
    ctx->r3 = S32(ctx->r7) >> 11;
    // sll         $v0, $t0, 16
    ctx->r2 = S32(ctx->r8) << 16;
    // sra         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2) >> 16;
    // bgez        $a2, L_8001678C
    if (SIGNED(ctx->r6) >= 0) {
        // addu        $s1, $v1, $s3
        ctx->r17 = ADD32(ctx->r3, ctx->r19);
        goto L_8001678C;
    }
    // addu        $s1, $v1, $s3
    ctx->r17 = ADD32(ctx->r3, ctx->r19);
    // addiu       $a2, $a2, 0x7FF
    ctx->r6 = ADD32(ctx->r6, 0X7FF);
L_8001678C:
    // mult        $t6, $s1
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sra         $v1, $a2, 11
    ctx->r3 = S32(ctx->r6) >> 11;
    // sll         $v0, $t2, 16
    ctx->r2 = S32(ctx->r10) << 16;
    // mflo        $a3
    ctx->r7 = lo;
    // sra         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2) >> 16;
    // addu        $s0, $v1, $s2
    ctx->r16 = ADD32(ctx->r3, ctx->r18);
    // mult        $t5, $s0
    result = S64(S32(ctx->r13)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // nop

    // nop

    // mult        $a0, $s1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // nop

    // nop

    // mult        $a1, $s0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // subu        $v0, $a3, $a2
    ctx->r2 = SUB32(ctx->r7, ctx->r6);
    // addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // mflo        $v1
    ctx->r3 = lo;
    // subu        $v1, $a0, $v1
    ctx->r3 = SUB32(ctx->r4, ctx->r3);
    // bgtz        $v0, L_800167E8
    if (SIGNED(ctx->r2) > 0) {
        // addu        $v1, $v1, $t1
        ctx->r3 = ADD32(ctx->r3, ctx->r9);
        goto L_800167E8;
    }
    // addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // bgez        $v1, L_800167F0
    if (SIGNED(ctx->r3) >= 0) {
        // nop
    
        goto L_800167F0;
    }
    // nop

L_800167E8:
    // j           L_80016848
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    goto L_80016848;
    // addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800167F0:
    // jal         0x800743F4
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    rsin(rdram, ctx);
    goto after_7;
    // addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_7:
    // lw          $v1, 0xE4($s7)
    ctx->r3 = MEM_W(0XE4, ctx->r23);
    // lw          $v0, 0x24C($s4)
    ctx->r2 = MEM_W(0X24C, ctx->r20);
    // nop

    // subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // bgez        $v1, L_80016814
    if (SIGNED(ctx->r3) >= 0) {
        // subu        $v0, $s1, $s3
        ctx->r2 = SUB32(ctx->r17, ctx->r19);
        goto L_80016814;
    }
    // subu        $v0, $s1, $s3
    ctx->r2 = SUB32(ctx->r17, ctx->r19);
    // addiu       $v1, $v1, 0x7FF
    ctx->r3 = ADD32(ctx->r3, 0X7FF);
L_80016814:
    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // subu        $v0, $s0, $s2
    ctx->r2 = SUB32(ctx->r16, ctx->r18);
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // sra         $v0, $v1, 11
    ctx->r2 = S32(ctx->r3) >> 11;
    // nop

    // mult        $v0, $v0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // slti        $v0, $v0, 0x91
    ctx->r2 = SIGNED(ctx->r2) < 0X91 ? 1 : 0;
L_80016848:
    // lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(0X30, ctx->r29);
    // lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(0X2C, ctx->r29);
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
    // addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // jr          $ra
    // nop

    return;
    // nop

;}
