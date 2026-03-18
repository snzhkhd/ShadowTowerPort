#include "recomp.h"
#include "disable_warnings.h"

void sub_8001C264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    unsigned int rounding_mode = DEFAULT_ROUNDING_MODE;
    int c1cs = 0; 
    // addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // lui         $fp, 0x1F80
    ctx->r30 = S32(0X1F80 << 16);
    // lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // addiu       $v0, $v0, -0x70D8
    ctx->r2 = ADD32(ctx->r2, -0X70D8);
    // sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
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
    // lh          $s7, 0x268($v0)
    ctx->r23 = MEM_HS(0X268, ctx->r2);
    // nop

    // slti        $v0, $s7, 0x801
    ctx->r2 = SIGNED(ctx->r23) < 0X801 ? 1 : 0;
    // bne         $v0, $zero, L_8001C2C0
    if (ctx->r2 != 0) {
        // addiu       $s2, $v1, 0x400
        ctx->r18 = ADD32(ctx->r3, 0X400);
        goto L_8001C2C0;
    }
    // addiu       $s2, $v1, 0x400
    ctx->r18 = ADD32(ctx->r3, 0X400);
    // addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // j           L_8001C2C4
    // subu        $s1, $v0, $s7
    ctx->r17 = SUB32(ctx->r2, ctx->r23);
    goto L_8001C2C4;
    // subu        $s1, $v0, $s7
    ctx->r17 = SUB32(ctx->r2, ctx->r23);
L_8001C2C0:
    // addu        $s1, $s7, $zero
    ctx->r17 = ADD32(ctx->r23, 0);
L_8001C2C4:
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
    // bgez        $v0, L_8001C2E4
    if (SIGNED(ctx->r2) >= 0) {
        // nop
    
        goto L_8001C2E4;
    }
    // nop

    // addiu       $v0, $v0, 0x3FF
    ctx->r2 = ADD32(ctx->r2, 0X3FF);
L_8001C2E4:
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
    // addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    rsin(rdram, ctx);
    goto after_1;
    // addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    after_1:
    // subu        $s0, $s2, $s1
    ctx->r16 = SUB32(ctx->r18, ctx->r17);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x800744C4
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    rcos(rdram, ctx);
    goto after_2;
    // addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    after_2:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x800743F4
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    rsin(rdram, ctx);
    goto after_3;
    // addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    after_3:
    // addu        $s0, $s2, $s1
    ctx->r16 = ADD32(ctx->r18, ctx->r17);
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x800744C4
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    rcos(rdram, ctx);
    goto after_4;
    // addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    after_4:
    // addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // jal         0x800743F4
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    rsin(rdram, ctx);
    goto after_5;
    // addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    after_5:
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // jal         0x800744C4
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    rcos(rdram, ctx);
    goto after_6;
    // addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_6:
    // addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // jal         0x800743F4
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    rsin(rdram, ctx);
    goto after_7;
    // addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_7:
    // sll         $a0, $s0, 1
    ctx->r4 = S32(ctx->r16) << 1;
    // addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4) << 2;
    // subu        $a0, $s0, $a0
    ctx->r4 = SUB32(ctx->r16, ctx->r4);
    // sra         $a0, $a0, 12
    ctx->r4 = S32(ctx->r4) >> 12;
    // mult        $a0, $s6
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a1
    ctx->r5 = lo;
    // nop

    // nop

    // mult        $a0, $s4
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a0
    ctx->r4 = lo;
    // sll         $v1, $s0, 4
    ctx->r3 = S32(ctx->r16) << 4;
    // sra         $v1, $v1, 12
    ctx->r3 = S32(ctx->r3) >> 12;
    // mult        $v1, $s5
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t0
    ctx->r8 = lo;
    // nop

    // nop

    // mult        $v1, $s3
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $a2
    ctx->r6 = lo;
    // nop

    // nop

    // mult        $v1, $s2
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t3
    ctx->r11 = lo;
    // nop

    // nop

    // mult        $v1, $s1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16) << 3;
    // mflo        $t1
    ctx->r9 = lo;
    // negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
    // sra         $s0, $s0, 12
    ctx->r16 = S32(ctx->r16) >> 12;
    // mult        $s0, $s6
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // mflo        $t4
    ctx->r12 = lo;
    // nop

    // nop

    // mult        $s0, $s4
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sll         $a3, $a0, 4
    ctx->r7 = S32(ctx->r4) << 4;
    // sra         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7) >> 16;
    // addu        $v1, $a2, $a0
    ctx->r3 = ADD32(ctx->r6, ctx->r4);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // subu        $v1, $v1, $a3
    ctx->r3 = SUB32(ctx->r3, ctx->r7);
    // sll         $a2, $a1, 4
    ctx->r6 = S32(ctx->r5) << 4;
    // sra         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6) >> 16;
    // mflo        $t5
    ctx->r13 = lo;
    // sw          $v1, 0x1F0($fp)
    MEM_W(0X1F0, ctx->r30) = ctx->r3;
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // mult        $v1, $a2
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $v1, $t0, $a1
    ctx->r3 = ADD32(ctx->r8, ctx->r5);
    // sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3) << 4;
    // mflo        $t2
    ctx->r10 = lo;
    // sra         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3) >> 16;
    // subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // mult        $v1, $a3
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a0, $t1, $a0
    ctx->r4 = ADD32(ctx->r9, ctx->r4);
    // sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4) << 4;
    // sra         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4) >> 16;
    // subu        $a0, $a0, $a3
    ctx->r4 = SUB32(ctx->r4, ctx->r7);
    // sw          $a0, 0x1F4($fp)
    MEM_W(0X1F4, ctx->r30) = ctx->r4;
    // sw          $v1, 0x1F8($fp)
    MEM_W(0X1F8, ctx->r30) = ctx->r3;
    // mflo        $t0
    ctx->r8 = lo;
    // addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // mult        $v1, $a2
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // addu        $a1, $t3, $a1
    ctx->r5 = ADD32(ctx->r11, ctx->r5);
    // sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5) << 4;
    // sra         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5) >> 16;
    // subu        $a1, $a1, $a2
    ctx->r5 = SUB32(ctx->r5, ctx->r6);
    // mflo        $a0
    ctx->r4 = lo;
    // sw          $a1, 0x1FC($fp)
    MEM_W(0X1FC, ctx->r30) = ctx->r5;
    // addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
    // mult        $v1, $a3
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // sw          $v0, 0x208($fp)
    MEM_W(0X208, ctx->r30) = ctx->r2;
    // sra         $v0, $t4, 12
    ctx->r2 = S32(ctx->r12) >> 12;
    // sh          $v0, 0x1EA($fp)
    MEM_H(0X1EA, ctx->r30) = ctx->r2;
    // sra         $v0, $t5, 12
    ctx->r2 = S32(ctx->r13) >> 12;
    // sh          $v0, 0x1EE($fp)
    MEM_H(0X1EE, ctx->r30) = ctx->r2;
    // addu        $v0, $t2, $t0
    ctx->r2 = ADD32(ctx->r10, ctx->r8);
    // sw          $v0, 0x200($fp)
    MEM_W(0X200, ctx->r30) = ctx->r2;
    // mflo        $v1
    ctx->r3 = lo;
    // addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // sw          $v0, 0x204($fp)
    MEM_W(0X204, ctx->r30) = ctx->r2;
    // lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(0X34, ctx->r29);
    // lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(0X30, ctx->r29);
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
